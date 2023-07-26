#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <math.h>

class AdHbMsgsNode {
private:
    ros::NodeHandle nh;
    ros::Publisher psi_ref_pub;
    ros::Publisher z_ref_pub;
    ros::Publisher x_des_pub;
    ros::Publisher y_des_pub;
    ros::Publisher n_rpm_pub;
    ros::Timer timer;

public:
    AdHbMsgsNode() : nh() {
        // Initialize the publishers
        psi_ref_pub = nh.advertise<std_msgs::Float64>("psi_ref_msg", 10);
        z_ref_pub = nh.advertise<std_msgs::Float64>("z_ref_msg", 10);
        x_des_pub = nh.advertise<std_msgs::Float64>("x_des_msg", 10);
        y_des_pub = nh.advertise<std_msgs::Float64>("y_des_msg", 10);
        n_rpm_pub = nh.advertise<std_msgs::Float64>("n_rpm_msg", 10);

        // Start the timer to trigger the calculations at a fixed rate
        timer = nh.createTimer(ros::Duration(1.0), &AdHbMsgsNode::calculateAndPublishValues, this);
    }

    void calculateAndPublishValues(const ros::TimerEvent& event) {
        // Assign values to n_rpm
        double n_rpm = 1500;

        // Calculate the current time in seconds
        double current_time = ros::Time::now().toSec();

        // Calculate the desired depth using a sine function
        double period = 40;
        double amplitude_z = 1.0;
        double frequency_z = 1.0 / period;
        double z_ref = 250 + amplitude_z * sin(2 * M_PI * frequency_z * current_time);

        // Calculate the desired heading angle (psi_ref) based on the desired trajectory
        double amplitude_psi = 0.2; // Adjust this value as needed
        double frequency_psi = 1.0 / period; // Adjust this value as needed
        double psi_ref = atan2(-amplitude_psi * frequency_psi * 2 * M_PI * cos(2 * M_PI * frequency_psi * current_time), 1);

        // Calculate the desired x and y coordinates using different sine functions
        double amplitude_xy = 1.0; // Adjust this value as needed
        double frequency_xy = 1.0 / period; // Adjust this value as needed
        double x_des = 5.0 + amplitude_xy * sin(2 * M_PI * frequency_xy * current_time); // Replace 5.0 with the desired x-coordinate value for the trajectory
        double y_des = -3.0 + amplitude_xy * sin(2 * M_PI * frequency_xy * current_time); // Replace -3.0 with the desired y-coordinate value for the trajectory

        // Publish psi_ref, z_ref, x_des, y_des, and n_rpm values to their respective topics
        std_msgs::Float64 psi_ref_msg;
        psi_ref_msg.data = psi_ref;
        psi_ref_pub.publish(psi_ref_msg);

        std_msgs::Float64 z_ref_msg;
        z_ref_msg.data = z_ref;
        z_ref_pub.publish(z_ref_msg);

        std_msgs::Float64 x_des_msg;
        x_des_msg.data = x_des;
        x_des_pub.publish(x_des_msg);

        std_msgs::Float64 y_des_msg;
        y_des_msg.data = y_des;
        y_des_pub.publish(y_des_msg);

        std_msgs::Float64 n_rpm_msg;
        n_rpm_msg.data = n_rpm;
        n_rpm_pub.publish(n_rpm_msg);

        ROS_INFO("We are here:");
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "ad_hb_msgs");

    AdHbMsgsNode node;

    ros::spin();

    return 0;
}
