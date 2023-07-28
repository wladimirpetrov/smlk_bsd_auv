#include <ros/ros.h>
#include <avl_bsd_translator/CommandMsg.h>
#include <avl_bsd_translator/ActionMsg.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <std_msgs/Float64.h>
#include <cmath>

class AUVNode {
public:
    AUVNode(int argc, char** argv) : rate(1.0) {
        ros::init(argc, argv, "auv_imp");

        heartbeat_pub = nh.advertise<avl_bsd_translator::HeartbeatMsg>("bsd/heartbeat", 10);
        z_pub = nh.advertise<std_msgs::Float64>("bsd/z", 10);
        command_sub = nh.subscribe("bsd/command", 10, &AUVNode::command_callback, this);
        action_sub = nh.subscribe("bsd/action", 10, &AUVNode::action_callback, this);

        elevator = 0.0;
        rudder = 0.0;
        rpm = 0.0;
        z = 250.0;  // Initial depth value
        x = 51.5074;    // Initial x position (latitude)
        y = -0.1278;    // Initial y position (longitude)
    }

    void command_callback(const avl_bsd_translator::CommandMsg::ConstPtr& command_msg) {
        ROS_INFO("command_msg received");
    }

    void action_callback(const avl_bsd_translator::ActionMsg::ConstPtr& action_msg) {
        elevator = std::stod(action_msg->VALUES[1]);
        rudder = std::stod(action_msg->VALUES[2]);
        rpm = std::stod(action_msg->VALUES[3]);
    }

    void update_heartbeat() {
        double roll = 0.0;
        double pitch = elevator; // Use the elevator angle directly as the pitch value
        double yaw = rudder;     // Use the rudder angle directly as the yaw value
        double z_value = z;      // Set the initial depth value
        double u = 0.0;
        double v = 0.0;
        double w = 0.0;
        double p = 0.0;
        double q = 0.0;
        double r = 0.0;

        double dt = 1.0; // Time step in seconds

        // Convert RPM to revolutions per second (RPS)
        double rpm_to_rps = rpm / 60.0;

        // Assuming a propeller circumference of 0.1 meters
        double prop_circumference = 0.1;

        // Calculate approximate linear speed based on propeller circumference
        double linear_speed = rpm_to_rps * prop_circumference;

        // Calculate the change in x and y positions based on the approximate linear speed, pitch, and yaw
        double x_change = linear_speed * dt * cos(pitch) * cos(yaw);
        double y_change = linear_speed * dt * cos(pitch) * sin(yaw);

        // Convert the change in meters to latitude and longitude units (approximation for small area)
        double lat_to_meter = 1.0 / 111320.0;
        double lon_to_meter = 1.0 / (111320.0 * cos(x * M_PI / 180.0));

        // Update x and y positions in latitude and longitude units
        x += x_change * lat_to_meter;
        y += y_change * lon_to_meter;

        // Calculate the depth based on elevator control
        double elevator_rad = M_PI * elevator / 180.0;
        double depth = z_value + (w * dt) + (0.5 * elevator_rad * pow(dt, 2));

        z_value = depth; // Update the depth with the new calculated value

        z = z_value; // Store the updated depth value

        // Publish depth value to additional topic
        std_msgs::Float64 depth_msg;
        depth_msg.data = z;
        z_pub.publish(depth_msg);

        avl_bsd_translator::HeartbeatMsg heartbeat_msg;
        heartbeat_msg.HEARTBEAT_STATUS = 1;
        heartbeat_msg.HEARTBEAT_ROLL = roll;
        heartbeat_msg.HEARTBEAT_PITCH = pitch;
        heartbeat_msg.HEARTBEAT_YAW = yaw;
        heartbeat_msg.HEARTBEAT_VN = u;
        heartbeat_msg.HEARTBEAT_VE = v;
        heartbeat_msg.HEARTBEAT_VD = w;
        heartbeat_msg.HEARTBEAT_DEPTH = z;
        heartbeat_msg.HEARTBEAT_HEIGHT = y;
        heartbeat_msg.HEARTBEAT_RPM = rpm;
        heartbeat_msg.HEARTBEAT_WX = p;
        heartbeat_msg.HEARTBEAT_WY = q;
        heartbeat_msg.HEARTBEAT_WZ = r;
        heartbeat_msg.HEARTBEAT_AX = 0.0;
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
        heartbeat_msg.HEARTBEAT_BSD_ACTION_PERCENT = 0;
        heartbeat_msg.HEARTBEAT_GPS_SATS = 0;
        heartbeat_msg.HEARTBEAT_GPS_LAT = x;
        heartbeat_msg.HEARTBEAT_GPS_LON = y;
        heartbeat_msg.HEARTBEAT_GPS_ALT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_LAT = 0;
        heartbeat_msg.HEARTBEAT_NAV_LON = 0;
        heartbeat_msg.HEARTBEAT_NAV_ALT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_YAW_STD = 0;
        heartbeat_msg.HEARTBEAT_NAV_AVG_POS_ERR = 0;
        heartbeat_msg.HEARTBEAT_NAV_INITIALIZED = 0;
        heartbeat_pub.publish(heartbeat_msg);
    }

    void run() {
        while (ros::ok()) {
            update_heartbeat();
            rate.sleep();
            ros::spinOnce();
        }
    }

private:
    ros::NodeHandle nh;
    ros::Publisher heartbeat_pub;
    ros::Publisher z_pub;
    ros::Subscriber command_sub;
    ros::Subscriber action_sub;
    double elevator;
    double rudder;
    double rpm;
    double z;
    double x;
    double y;
    ros::Rate rate; // Add the 'rate' member variable here
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "auv_imp_cpp");
    AUVNode auv_node(argc, argv);
    auv_node.run();
    return 0;
}
