//==============================================================================
// Autonomous Vehicle Library Backseat Driver Example
//
// Description: An example implementation of the backseat driver
//
// Publishers:  command_pub, action_pub, pssthrough_pub
//
// Subscribers: heartbeat_sub, response_sub, device_sub, passthrough_sub
//==============================================================================

// Node base class
#include <ros/ros.h>

// Header file
#include <bsd_example.h>

// Message Types
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <avl_bsd_translator/ActionMsg.h>
#include <avl_bsd_translator/ResponseMsg.h>
#include <avl_bsd_translator/CommandMsg.h>
#include <avl_bsd_translator/DeviceMsg.h>
#include <avl_bsd_translator/PassthroughMsg.h>



// Publisher and subscriber objects
ros::Publisher command_pub; // Command publisher
ros::Publisher action_pub; // Action publisher
ros::Publisher passthrough_pub; // Passthrough publisher

ros::Subscriber heartbeat_sub; // Heartbeat subscriber
ros::Subscriber response_sub; // Response subscriber
ros::Subscriber device_sub; // Device subscriber
ros::Subscriber passthrough_sub; // Passthrough subscriber

double int_sum_yaw=0;
double int_sum_pitch=0;
double iter_rate = 10;

//--------------------------------------------------------------------------
// Name:        send_command_msg
// Description: Send an command message to FSD
//--------------------------------------------------------------------------
void send_command_msg(){
    avl_bsd_translator::CommandMsg command_msg; // Create CommandMsg

    // Populate Command Message Fields
    command_msg.COMMAND_NAME = "MISSION";
    command_msg.NAMES = {"COMMAND"};
    command_msg.TYPES = {0x01};

    // parameter values (converted to string)
    std::string start = std::to_string(0);
    command_msg.VALUES = {start};
    command_pub.publish(command_msg); // Publish Command Message to vehicle
}

//--------------------------------------------------------------------------
// Name:        send_action_msg
// Description: Send an action message to vehicle
//--------------------------------------------------------------------------
void send_action_msg(double duration, double elevator, double rudder){
    avl_bsd_translator::ActionMsg action_msg; // Create ActionMsg

    // Populate Action Message Fields
    action_msg.ACTION_TYPE = "PRIMITIVE";
    action_msg.MODE = 0;
    action_msg.NAMES = {"DURATION", "ELEVATOR", "RUDDER", "RPM"};
    action_msg.TYPES = {0x02, 0x02, 0x02, 0x02};

    // parameter values (converted to string)
    std::string dur = std::to_string(duration);
    std::string ele = std::to_string(elevator);
    std::string rud = std::to_string(rudder);
    std::string rpm = std::to_string(1500);


    action_msg.VALUES = {dur, ele, rud, rpm};

    action_pub.publish(action_msg); // Publish Action Message to vehicle
}

//--------------------------------------------------------------------------
// Name:        device_callback
// Description: Callback for device message
// Arguments:   - Message: DEVICE message received.
//--------------------------------------------------------------------------
void device_callback(avl_bsd_translator::DeviceMsg device_msg){
    // Print out data from device packet
    printf("================================================================================\n");
    printf("Received DEVICE packet\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("DEVICE NAME: %s \n", device_msg.DEVICE_NAME.c_str());
    printf("PARAMETERS: \n");
    for (uint8_t i = 0; i < device_msg.TYPES.size(); i++){
        printf("Name: %s \n", device_msg.NAMES[i].c_str());
        printf("Type: %u \n", device_msg.TYPES[i]);
        printf("Value: %s \n", device_msg.VALUES[i].c_str());
    }
    printf("================================================================================\n");

}

//--------------------------------------------------------------------------
// Name:        send_passthrough_msg
// Description: Send a passthrough message to vehicle
//--------------------------------------------------------------------------
void send_passthrough_msg(){
    avl_bsd_translator::PassthroughMsg passthrough_msg; // Create PassthroughMsg
    // Populate Passthrough Message Fields
    passthrough_msg.TARGET_ID = 0x00;
    passthrough_msg.CHANNEL = 0x01;
    passthrough_msg.INTERFACE = 0x02;
    passthrough_msg.DATA = "39493";
    passthrough_pub.publish(passthrough_msg); // Publish Passthrough Message
}

//--------------------------------------------------------------------------
// Name:        heartbeat_callback
// Description: Called when an AVL HEARTBEAT packet is received
// Arguments:   - Message: HEARTBEAT message received.
//--------------------------------------------------------------------------
void heartbeat_callback(const avl_bsd_translator::HeartbeatMsg msg)
{
    uint8_t HEARTBEAT_STATUS = msg.HEARTBEAT_STATUS; // Get HEARTBEAT_STATUS from message
    printf("HEARTBEAT_STATUS %u \n", HEARTBEAT_STATUS);
    std::cout<<"BSD pitch: "<<msg.HEARTBEAT_PITCH<<std::endl;
    std::cout<<"BSD pitch rate"<<msg.HEARTBEAT_WY<<std::endl;
    std::cout<<"BSD yaw: "<<msg.HEARTBEAT_YAW<<std::endl;
    std::cout<<"BSD yaw rate"<<msg.HEARTBEAT_WZ<<std::endl;
    // Perform Action
    //inner loop attitude control: simple pid control example with pre-defined setpoints
    double yaw_setpoint = 3.14159; //~ 180 deg
    double pitch_setpoint = 0.0;
    double kp_yaw = 3.0;
    double kd_yaw = 3.0;
    double ki_yaw = 0.005;

    double kp_pitch = 4.5;
    double kd_pitch = 7.0;
    double ki_pitch = 0.2;

    //rudder calculation
    double rudder = kp_yaw*(yaw_setpoint-msg.HEARTBEAT_YAW*M_PI/180.0)+kd_yaw*(0-msg.HEARTBEAT_WZ*M_PI/180.0);
    int_sum_yaw=int_sum_yaw+ki_yaw*(yaw_setpoint-msg.HEARTBEAT_YAW*M_PI/180.0)/iter_rate;
    //limits integral component to 5 deg
    if(std::abs(int_sum_yaw)<=5*M_PI/180)
    {
        if(int_sum_yaw<0)
            int_sum_yaw=-5*M_PI/180;
        else
            int_sum_yaw = 5*M_PI/180;
    }
    rudder = (rudder+ int_sum_yaw)*180/M_PI;
    //Overall control surface output is limited to 20 deg
    //These checks are also performed on the front seat driver
    if (std::abs(rudder) >= 20)
    {
        if(rudder<0)
        {
            rudder = -20;
        }
        else
        {
            rudder = 20;
        }
    }
    
    // elevator calculation
    double elevator = kp_pitch*(pitch_setpoint-msg.HEARTBEAT_PITCH*M_PI/180.0)+kd_pitch*(0-msg.HEARTBEAT_WY*M_PI/180.0);
    int_sum_pitch=int_sum_pitch+ki_pitch*(pitch_setpoint-msg.HEARTBEAT_PITCH*M_PI/180.0)/iter_rate;
    if(std::abs(int_sum_pitch)<=5*M_PI/180)
    {
        if(int_sum_pitch<0)
            int_sum_pitch=-5*M_PI/180;
        else
            int_sum_pitch = 5*M_PI/180;
    }

    elevator = (elevator+int_sum_pitch)*180/M_PI;

    if (std::abs(elevator) >= 20)
    {
        if(elevator<0)
        {
            elevator = -20;
        }
        else
        {
            elevator = 20;
        }
    }
    //sends the elevator and rudder to the FSD which actuates the control surfaces
    send_action_msg(2.0,elevator,rudder);

    send_command_msg();
}

//--------------------------------------------------------------------------
// Name:        response_callback
// Description: Called when an AVL response message is received by the
//              communication architecture.
// Arguments:   - Message: RESPONSE message received.
//--------------------------------------------------------------------------
void response_callback(const avl_bsd_translator::ResponseMsg msg)
{
    // Get passthrough fields
    std::uint8_t desc = msg.DESC;
    std::string name = msg.NAME;
    std::uint64_t source = msg.SOURCE;
    bool result = msg.RESULT;
    std::string data = msg.DATA;
    if(result){
        printf("Received response from %lu: SUCCESSFUL \n", source);
    } else {
        printf("Received response from %lu: NOT SUCCESSFUL \n", source);
    }
    switch (desc) {
        case COMMAND:
        {

            if(!result)
            {

                printf("Command %s Failed (%s) \n", name.c_str(),
                data.c_str());

            }
            break;

        }
        case ACTION:
        {

            if(!result)
            {

                printf("Action %s Failed (%s) \n", name.c_str(),
                data.c_str());

            }
            break;

        }
    }
    return;
}

//--------------------------------------------------------------------------
// Name:        passthrough_callback
// Description: Called when an AVL passthrough message is received by the
//              communication architecture.
// Arguments:   - Message: PASSTHROUGH message received.
//--------------------------------------------------------------------------
void passthrough_callback(const avl_bsd_translator::PassthroughMsg msg)
{
    // Print info from passthrough packet
    printf("================================================================================\n");
    printf("Received PASSTHROUGH packet\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("TARGET_ID: %u\n",  msg.TARGET_ID);
    printf("CHANNEL:        %u\n", msg.CHANNEL);
    printf("INTERFACE:      %u\n",  msg.INTERFACE);
    printf("================================================================================\n");
}


int main(int argc, char** argv)

{

    // Initialize the ROS node
    ros::init(argc, argv, "bsd_example");

    // Create the publisher and subscriber
    ros::NodeHandle nh;

    // Initialize publishers and subscribers
    action_pub = nh.advertise<avl_bsd_translator::ActionMsg>("bsd/action", 10);
    command_pub = nh.advertise<avl_bsd_translator::CommandMsg>("bsd/command", 10);
    passthrough_pub = nh.advertise<avl_bsd_translator::PassthroughMsg>("bsd/passthrough", 10);
    heartbeat_sub = nh.subscribe("bsd/heartbeat", 1000, heartbeat_callback);
    response_sub = nh.subscribe("bsd/response", 10, response_callback);
    device_sub = nh.subscribe("bsd/device", 10, device_callback);
    passthrough_sub = nh.subscribe("bsd/passthrough_sub", 10, passthrough_callback);

    // Spin the node to keep it running
    ros::spin();

    return 0;

}
