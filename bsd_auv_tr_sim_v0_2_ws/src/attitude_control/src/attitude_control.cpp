#include <ros/ros.h>

#include <std_msgs/Float64.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <avl_bsd_translator/CommandMsg.h>
#include <avl_bsd_translator/ActionMsg.h>

class AttitudeControl {
public:
    AttitudeControl() {
        ros::NodeHandle nh;
        
        command_pub = nh.advertise<avl_bsd_translator::CommandMsg>("bsd/command", 10);
        action_pub = nh.advertise<avl_bsd_translator::ActionMsg>("bsd/action", 10);
        z_ref_sub = nh.subscribe("z_ref_msg", 10, &AttitudeControl::z_ref_callback, this);
        psi_ref_sub = nh.subscribe("psi_ref_msg", 10, &AttitudeControl::psi_ref_callback, this);
        rpm_sub = nh.subscribe("n_rpm_msg", 10, &AttitudeControl::rpm_callback, this);
        heartbeat_sub = nh.subscribe("bsd/heartbeat", 10, &AttitudeControl::heartbeat_callback, this);

        //z_ref = 0.0;
        //psi_ref = 0.0;
        //rpm = 0.0;
        Ts = 0.05;

        // Variables for saving previous error and integral terms
        zerr_prev = 0.0;
        zerrint_prev = 0.0;
        thetaerr_prev = 0.0;
        thetaerrint_prev = 0.0;
        psierr_prev = 0.0;
        psierrint_prev = 0.0;
    }

    void send_command_msg() {
        avl_bsd_translator::CommandMsg command_msg;
        command_msg.COMMAND_NAME = "MISSION";
        command_msg.NAMES = {"COMMAND"};
        command_msg.TYPES = {0x01};
        command_msg.VALUES = {std::to_string(0)};
        command_pub.publish(command_msg);
    }

    void send_action_msg(double duration, double elevator, double rudder, double rpm) {
        avl_bsd_translator::ActionMsg action_msg;
        action_msg.ACTION_TYPE = "PRIMITIVE";
        action_msg.MODE = 0;
        action_msg.NAMES = {"DURATION", "ELEVATOR", "RUDDER", "RPM"};
        action_msg.TYPES = {0x02, 0x02, 0x02, 0x02};
        action_msg.VALUES = {std::to_string(duration), std::to_string(elevator), std::to_string(rudder), std::to_string(rpm)};
        action_pub.publish(action_msg);
    }

    void z_ref_callback(const std_msgs::Float64::ConstPtr& msg) {
        z_ref = fabs(msg->data); // Absolute value of message data
    }

    void psi_ref_callback(const std_msgs::Float64::ConstPtr& msg) {
        psi_ref = msg->data;
    }

    void rpm_callback(const std_msgs::Float64::ConstPtr& msg) {
        rpm = msg->data;
    }

    void heartbeat_callback(const avl_bsd_translator::HeartbeatMsg::ConstPtr& msg) {
        double HEARTBEAT_STATUS = msg->HEARTBEAT_STATUS;
        ROS_INFO_STREAM("HEARTBEAT_STATUS: " << HEARTBEAT_STATUS);
        ROS_INFO_STREAM("BSD pitch: " << msg->HEARTBEAT_PITCH);
        ROS_INFO_STREAM("BSD yaw: " << msg->HEARTBEAT_YAW);
        ROS_INFO_STREAM("BSD depth: " << msg->HEARTBEAT_DEPTH);

        // Perform Action
        double KP_APz = 3.0;
        double KI_APz = 0.0 * 0.1044;
        double KD_APz = 3.0;
        double KP_APtheta = 3.0;
        double KI_APtheta = 0.0 * 0.1466;
        double KD_APtheta = 3.0;
        double KP_APpsi = 3.0;
        double KI_APpsi = 0.0;
        double KD_APpsi = 12.199;

        double psi = msg->HEARTBEAT_YAW;
        double theta = msg->HEARTBEAT_PITCH;
        double z = msg->HEARTBEAT_DEPTH;

        // calculating elevator
        double zerr = z_ref - z;
        double zerrint = zerr * Ts + zerrint_prev;
        double zerrdot = (zerr - zerr_prev) / Ts;
        double dvz = KP_APz * zerr + KI_APz * zerrint + KD_APz * zerrdot;

        double thetaerr = 0.0 - theta;
        double thetaerrint = thetaerr * Ts + thetaerrint_prev;
        double thetaerrdot = (thetaerr - thetaerr_prev) / Ts;
        double dvtheta = KP_APtheta * thetaerr + KI_APtheta * thetaerrint + KD_APtheta * thetaerrdot;

        double elevator = dvz + dvtheta;
        
        // Limit elevator value
        if (elevator >= 20.0)
        elevator = 20.0;
        else if (elevator <= -20.0)
        elevator = -20.0;       

        // calculating rudder
        double psierr = psi_ref - psi;
        double psierrint = psierr * Ts + psierrint_prev;
        double psierrdot = (psierr - psierr_prev) / Ts;
        double rudder = KP_APpsi * psierr + KI_APpsi * psierrint + KD_APpsi * psierrdot;
        
        // Limit rudder value
        if (rudder >= 20.0)
        rudder = 20.0;
        else if (rudder <= -20.0)
        rudder = -20.0;
        
        send_action_msg(2.0, elevator, rudder, rpm);
        send_command_msg();

        zerr_prev = zerr;
        zerrint_prev = zerrint;
        thetaerr_prev = thetaerr;
        thetaerrint_prev = thetaerrint;
        psierr_prev = psierr;
        psierrint_prev = psierrint;
    }

    void run() {
        ros::spin();
    }

private:
    ros::Publisher command_pub;
    ros::Publisher action_pub;
    ros::Subscriber z_ref_sub;
    ros::Subscriber psi_ref_sub;
    ros::Subscriber rpm_sub;
    ros::Subscriber heartbeat_sub;

    double z_ref;
    double psi_ref;
    double rpm;
    double Ts;

    double zerr_prev;
    double zerrint_prev;
    double thetaerr_prev;
    double thetaerrint_prev;
    double psierr_prev;
    double psierrint_prev;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "attitude_control");
    AttitudeControl attitude_control;
    attitude_control.run();
    return 0;
}
