#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <math.h>

class AdHbMsgsNode {
private:
    ros::NodeHandle nh;
    ros::Publisher psi_ref_pub;
    ros::Publisher z_ref_pub;
    ros::Publisher x_lat_des_pub;
    ros::Publisher y_long_des_pub;
    ros::Publisher n_rpm_pub;
    ros::Timer timer;

    // Geographic location of the trajectory (latitude, longitude)
    const double trajectory_latitude = 51.5074; // Example latitude (London, UK)
    const double trajectory_longitude = -0.1278; // Example longitude (London, UK)
    
    // Previous x_lat_des and y_long_des values for calculating heading angle
    double prev_x_lat_des;
    double prev_y_long_des;

public:
    AdHbMsgsNode() : nh(), prev_x_lat_des(0.0), prev_y_long_des(0.0) {
        // Initialize the publishers
        psi_ref_pub = nh.advertise<std_msgs::Float64>("psi_ref_msg", 10);
        z_ref_pub = nh.advertise<std_msgs::Float64>("z_ref_msg", 10);
        x_lat_des_pub = nh.advertise<std_msgs::Float64>("x_lat_des_msg", 10);
        y_long_des_pub = nh.advertise<std_msgs::Float64>("y_long_des_msg", 10);
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

        // Calculate the desired x and y coordinates using different sine functions
        double amplitude_xy = 1.0; // Adjust this value as needed
        double frequency_xy = 1.0 / period; // Adjust this value as needed

        // Replace x_des with x_lat_des and convert meters to degrees latitude
        double x_lat_des_meters = 5.0 + amplitude_xy * sin(2 * M_PI * frequency_xy * current_time);
        double x_lat_des = trajectory_latitude + (x_lat_des_meters / 111111.0);

        // Replace y_des with y_long_des and convert meters to degrees longitude
        double y_long_des_meters = -3.0 + amplitude_xy * sin(2 * M_PI * frequency_xy * current_time);
        double y_long_des = trajectory_longitude + (y_long_des_meters / (111111.0 * cos(trajectory_latitude * M_PI / 180.0)));

        // Calculate the change in x_lat_des and y_long_des
        double delta_x_lat_des = x_lat_des - prev_x_lat_des;
        double delta_y_long_des = y_long_des - prev_y_long_des;

        // Calculate the desired heading angle (psi_ref) based on the changes in x_lat_des and y_long_des
        double psi_ref = atan2(delta_y_long_des, delta_x_lat_des);

        // Publish psi_ref, z_ref, x_lat_des, y_long_des, and n_rpm values to their respective topics
        std_msgs::Float64 psi_ref_msg;
        psi_ref_msg.data = psi_ref;
        psi_ref_pub.publish(psi_ref_msg);

        std_msgs::Float64 z_ref_msg;
        z_ref_msg.data = z_ref;
        z_ref_pub.publish(z_ref_msg);

        std_msgs::Float64 x_lat_des_msg;
        x_lat_des_msg.data = x_lat_des;
        x_lat_des_pub.publish(x_lat_des_msg);

        std_msgs::Float64 y_long_des_msg;
        y_long_des_msg.data = y_long_des;
        y_long_des_pub.publish(y_long_des_msg);

        std_msgs::Float64 n_rpm_msg;
        n_rpm_msg.data = n_rpm;
        n_rpm_pub.publish(n_rpm_msg);

        // Update the previous values for the next iteration
        prev_x_lat_des = x_lat_des;
        prev_y_long_des = y_long_des;

        ROS_INFO("We are here:");
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "ad_hb_msgs");

    AdHbMsgsNode node;

    ros::spin();

    return 0;
}
