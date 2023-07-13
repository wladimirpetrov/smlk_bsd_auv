#include <ros/ros.h>
#include <cmath>
#include <std_msgs/Float64.h>
#include <avl_bsd_translator/HeartbeatMsg.h>

// Define global variables
double n_rpm = 1500;

void heartbeatCallback(const avl_bsd_translator::HeartbeatMsg& msg) {
    // Calculate the current time in seconds
    double current_time = ros::Time::now().toSec();

    // Calculate the desired depth using a sine function
    double period = 20;
    double amplitude = 2.0;
    double frequency = 1.0 / period;
    double z_ref = 250 + amplitude * std::sin(2 * M_PI * frequency * current_time);

    // Calculate the desired heading angle (psi_ref) based on the desired trajectory
    double psi_ref = std::atan2(-amplitude * frequency * 2 * M_PI * std::cos(2 * M_PI * frequency * current_time), 1);

    // Create ROS publishers for psi_ref, z_ref, and n_rpm values
    ros::NodeHandle nh;
    ros::Publisher psi_ref_pub = nh.advertise<std_msgs::Float64>("psi_ref_msg", 10);
    ros::Publisher z_ref_pub = nh.advertise<std_msgs::Float64>("z_ref_msg", 10);
    ros::Publisher n_rpm_pub = nh.advertise<std_msgs::Float64>("n_rpm_msg", 10);

    // Publish psi_ref, z_ref, and n_rpm values to their respective topics
    std_msgs::Float64 psi_ref_msg;
    psi_ref_msg.data = psi_ref;
    psi_ref_pub.publish(psi_ref_msg);

    std_msgs::Float64 z_ref_msg;
    z_ref_msg.data = z_ref;
    z_ref_pub.publish(z_ref_msg);

    std_msgs::Float64 n_rpm_msg;
    n_rpm_msg.data = n_rpm;
    n_rpm_pub.publish(n_rpm_msg);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "ad_hb_msgs");
    ros::NodeHandle nh;

    // Subscribe to the heartbeat message
    ros::Subscriber heartbeat_sub = nh.subscribe("/bsd/heartbeat", 10, heartbeatCallback);

    ros::spin();

    return 0;
}
