#include <ros/ros.h>
#include <cmath>
#include <std_msgs/Float64.h>

class HeartbeatPublisher {
private:
    ros::NodeHandle nh_;
    ros::Timer publish_timer_;
    ros::Publisher psi_ref_pub_;
    ros::Publisher z_ref_pub_;
    ros::Publisher n_rpm_pub_;

public:
    HeartbeatPublisher() : nh_("~") {
        // Create publishers with desired topic names
        psi_ref_pub_ = nh_.advertise<std_msgs::Float64>("/psi_ref_msg", 10);
        z_ref_pub_ = nh_.advertise<std_msgs::Float64>("/z_ref_msg", 10);
        n_rpm_pub_ = nh_.advertise<std_msgs::Float64>("/n_rpm_msg", 10);

        // Create a timer to publish the values periodically
        publish_timer_ = nh_.createTimer(ros::Duration(1.0), &HeartbeatPublisher::publishValues, this);
    }

    void publishValues(const ros::TimerEvent& event) {
        // Assign values to n_rpm
        double n_rpm = 1500;

        // Calculate the current time in seconds
        double currentTime = ros::Time::now().toSec();

        // Calculate the desired depth using a sine function
        double period = 20;
        double amplitude = 2.0;
        double frequency = 1.0 / period;
        double z_ref = 250 + amplitude * sin(2 * M_PI * frequency * currentTime);

        // Calculate the desired heading angle (psi_ref) based on the desired trajectory
        double psi_ref = atan2(-amplitude * frequency * 2 * M_PI * cos(2 * M_PI * frequency * currentTime), 1);

        std_msgs::Float64 psi_ref_msg;
        psi_ref_msg.data = psi_ref;
        psi_ref_pub_.publish(psi_ref_msg);

        std_msgs::Float64 z_ref_msg;
        z_ref_msg.data = z_ref;
        z_ref_pub_.publish(z_ref_msg);

        std_msgs::Float64 n_rpm_msg;
        n_rpm_msg.data = n_rpm;
        n_rpm_pub_.publish(n_rpm_msg);
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "ad_hb_msgs");

    HeartbeatPublisher heartbeatPublisher;

    ros::spin();

    return 0;
}
