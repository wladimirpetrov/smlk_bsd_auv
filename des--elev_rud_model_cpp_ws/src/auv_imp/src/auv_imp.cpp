#include <ros/ros.h>
#include <avl_bsd_translator/CommandMsg.h>
#include <avl_bsd_translator/ActionMsg.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <std_msgs/Float64.h>
#include <math.h>

class AUVNode {
public:
    AUVNode() {
        // Initialize ROS node
        ros::NodeHandle nh;

        // Initialize control variables
        elevator = 0.0;
        rudder = 0.0;
        rpm = 0.0;
        z = 250.0;

        // Set publishing frequency
        ros::Rate rate(1);

        // Create publisher for heartbeat messages
        heartbeat_pub = nh.advertise<avl_bsd_translator::HeartbeatMsg>("bsd/heartbeat", 10);

        // Create publisher for z topic
        z_pub = nh.advertise<std_msgs::Float64>("bsd/z", 10);

        // Create subscribers for command and action topics
        command_sub = nh.subscribe("bsd/command", 10, &AUVNode::command_callback, this);
        action_sub = nh.subscribe("bsd/action", 10, &AUVNode::action_callback, this);

        update_heartbeat();
    }

    void command_callback(const avl_bsd_translator::CommandMsg::ConstPtr& msg) {
        ROS_INFO("Command message received");
    }

    void action_callback(const avl_bsd_translator::ActionMsg::ConstPtr& msg) {
        elevator = std::stod(msg->VALUES[1]);
        rudder = std::stod(msg->VALUES[2]);
        rpm = std::stod(msg->VALUES[3]);

        ROS_INFO("Action message received");
    }

    void update_heartbeat() {
        double roll = 0.0;
        double pitch = 0.0;
        double yaw = 0.0;
        double x = 0.0;
        double y = 0.0;
        double z = this->z;
        double u = this->elevator;
        double v = this->rudder;
        double w = 0.0;
        double p = 0.0;
        double q = 0.0;
        double r = 0.0;

        double dt = 1.0;

        double elevator_rad = M_PI / 180.0 * this->elevator;
        double rudder_rad = M_PI / 180.0 * this->rudder;

        double depth = z + (w * dt) + (0.5 * elevator_rad * pow(dt, 2));
        x += u * dt;
        y += v * dt;
        this->z = depth;

        avl_bsd_translator::HeartbeatMsg heartbeat_msg;
        heartbeat_msg.HEARTBEAT_STATUS = 1;
        heartbeat_msg.HEARTBEAT_ROLL = roll;
        heartbeat_msg.HEARTBEAT_PITCH = pitch;
        heartbeat_msg.HEARTBEAT_YAW = yaw;
        heartbeat_msg.HEARTBEAT_VN = u;
        heartbeat_msg.HEARTBEAT_VE = v;
        heartbeat_msg.HEARTBEAT_VD = w;
        heartbeat_msg.HEARTBEAT_DEPTH = this->z;
        heartbeat_msg.HEARTBEAT_HEIGHT = y;
        heartbeat_msg.HEARTBEAT_RPM = this->rpm;
        heartbeat_msg.HEARTBEAT_WX = p;
        heartbeat_msg.HEARTBEAT_WY = q;
        heartbeat_msg.HEARTBEAT_WZ = r;
        heartbeat_msg.HEARTBEAT_AX= 0.0;
        heartbeat_msg.HEARTBEAT_AY = 0.0;
        heartbeat_msg.HEARTBEAT_AZ = 0.0;
        heartbeat_msg.HEARTBEAT_VOLTAGE = 0.0;
        heartbeat_msg.HEARTBEAT_UMODEM_SYNC = 0;
        heartbeat_msg.HEARTBEAT_MISSION_MODE = 0;
        heartbeat_msg.HEARTBEAT_FSD_MISSION_STATE = 0;
        heartbeat_msg.HEARTBEAT_FSD_CURRENT_ACTION = 0;
        heartbeat_msg.HEARTBEAT_FSD_TOTAL_ACTIONS = 0;
        heartbeat_msg.HEARTBEAT_FSD_ACTION_PERCENT = 0.0;
        heartbeat_msg.HEARTBEAT_BSD_MISSION_STATE = 0;
        heartbeat_msg.HEARTBEAT_BSD_CURRENT_ACTION = 0;
        heartbeat_msg.HEARTBEAT_BSD_TOTAL_ACTIONS = 0;
        heartbeat_msg.HEARTBEAT_BSD_ACTION_PERCENT = 0.0;
        heartbeat_msg.HEARTBEAT_GPS_SATS = 0;
        heartbeat_msg.HEARTBEAT_GPS_LAT = 0.0;
        heartbeat_msg.HEARTBEAT_GPS_LON = 0.0;
        heartbeat_msg.HEARTBEAT_GPS_ALT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_LAT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_LON = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_ALT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_YAW_STD = 0;
        heartbeat_msg.HEARTBEAT_NAV_AVG_POS_ERR = 0;
        heartbeat_msg.HEARTBEAT_NAV_INITIALIZED = 0;

        // Check if the publisher is valid before publishing
        if (heartbeat_pub.getNumSubscribers() > 0 && ros::ok()) {
            heartbeat_pub.publish(heartbeat_msg);
        }

        // Publish z value
        std_msgs::Float64 z_msg;
        z_msg.data = this->z;
        z_pub.publish(z_msg);
    }

private:
    double elevator;
    double rudder;
    double rpm;
    double z;
    ros::Publisher heartbeat_pub;
    ros::Publisher z_pub;
    ros::Subscriber command_sub;
    ros::Subscriber action_sub;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "auv_node");

    AUVNode node;

    ros::spin();

    return 0;
}