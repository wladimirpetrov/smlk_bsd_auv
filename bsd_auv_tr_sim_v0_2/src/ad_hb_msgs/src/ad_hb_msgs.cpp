#include <ros/ros.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <std_msgs/Float64.h>
#include <cmath>

class HeartbeatTranslator {
public:
    HeartbeatTranslator() {
        x_origin_ = y_origin_ = depth_origin_ = 0.0;

        ros::NodeHandle nh;

        x_hb_pub_ = nh.advertise<std_msgs::Float64>("/x_hb_msg", 10);
        y_hb_pub_ = nh.advertise<std_msgs::Float64>("/y_hb_msg", 10);
        depth_hb_pub_ = nh.advertise<std_msgs::Float64>("/z_hb_msg", 10);

        roll_hb_pub_ = nh.advertise<std_msgs::Float64>("/roll_hb_msg", 10);
        pitch_hb_pub_ = nh.advertise<std_msgs::Float64>("/pitch_hb_msg", 10);
        yaw_hb_pub_ = nh.advertise<std_msgs::Float64>("/yaw_hb_msg", 10);

        u_vel_hb_pub_ = nh.advertise<std_msgs::Float64>("/u_vel_x_hb_msg", 10);
        v_vel_hb_pub_ = nh.advertise<std_msgs::Float64>("/v_vel_y_hb_msg", 10);
        w_vel_hb_pub_ = nh.advertise<std_msgs::Float64>("/w_vel_z_hb_msg", 10);

        p_avel_hb_pub_ = nh.advertise<std_msgs::Float64>("/p_avel_x_hb_msg", 10);
        q_avel_hb_pub_ = nh.advertise<std_msgs::Float64>("/q_avel_y_hb_msg", 10);
        r_avel_hb_pub_ = nh.advertise<std_msgs::Float64>("/r_avel_z_hb_msg", 10);

        heartbeat_sub_ = nh.subscribe("/bsd/heartbeat", 10, &HeartbeatTranslator::heartbeatCallback, this);
    }

    void heartbeatCallback(const avl_bsd_translator::HeartbeatMsg::ConstPtr& msg) {
        if (x_origin_ == 0.0 && y_origin_ == 0.0 && depth_origin_ == 0.0) {
            x_origin_ = msg->HEARTBEAT_GPS_LAT;
            y_origin_ = msg->HEARTBEAT_GPS_LON;
            depth_origin_ = msg->HEARTBEAT_DEPTH;
        }

        double roll = msg->HEARTBEAT_ROLL;
        double pitch = msg->HEARTBEAT_PITCH;
        double yaw = msg->HEARTBEAT_YAW;

        double v_north = msg->HEARTBEAT_VN;
        double v_east = msg->HEARTBEAT_VE;
        double v_depth = msg->HEARTBEAT_VD;

        double p_avel = msg->HEARTBEAT_WX;
        double q_avel = msg->HEARTBEAT_WY;
        double r_avel = msg->HEARTBEAT_WZ;

        double gps_lat = msg->HEARTBEAT_GPS_LAT;
        double gps_lon = msg->HEARTBEAT_GPS_LON;
        double depth = msg->HEARTBEAT_DEPTH;

        double x = gps_lat - x_origin_;
        double y = gps_lon - y_origin_;
        double relative_depth = depth - depth_origin_;

        double roll_rad = roll * M_PI / 180.0;
        double pitch_rad = pitch * M_PI / 180.0;
        double yaw_rad = yaw * M_PI / 180.0;

        double p_avel_rad_sec = p_avel * M_PI / 180.0;
        double q_avel_rad_sec = q_avel * M_PI / 180.0;
        double r_avel_rad_sec = r_avel * M_PI / 180.0;

        double u = v_north * cos(pitch) * cos(yaw) + v_east * (
                sin(roll) * sin(pitch) * cos(yaw) - cos(roll) * sin(yaw)) + v_depth * (
                         cos(roll) * sin(pitch) * cos(yaw) + sin(roll) * sin(yaw));
        double v = v_north * cos(pitch) * sin(yaw) + v_east * (
                sin(roll) * sin(pitch) * sin(yaw) + cos(roll) * cos(yaw)) + v_depth * (
                         cos(roll) * sin(pitch) * sin(yaw) - sin(roll) * cos(yaw));
        double w = -v_north * sin(pitch) + v_east * sin(roll) * cos(pitch) + v_depth * cos(
                roll) * cos(pitch);

        double p = p_avel_rad_sec - q_avel * sin(roll) * tan(pitch) + r_avel * cos(roll) * tan(pitch);
        double q = q_avel_rad_sec * cos(roll) - r_avel * sin(roll);
        double r = q_avel_rad_sec * sin(roll) / cos(pitch) + r_avel * cos(roll) / cos(pitch);

        std_msgs::Float64 x_msg;
        x_msg.data = x;
        x_hb_pub_.publish(x_msg);

        std_msgs::Float64 y_msg;
        y_msg.data = y;
        y_hb_pub_.publish(y_msg);

        std_msgs::Float64 depth_msg;
        depth_msg.data = relative_depth;
        depth_hb_pub_.publish(depth_msg);

        std_msgs::Float64 roll_msg;
        roll_msg.data = roll_rad;
        roll_hb_pub_.publish(roll_msg);

        std_msgs::Float64 pitch_msg;
        pitch_msg.data = pitch_rad;
        pitch_hb_pub_.publish(pitch_msg);

        std_msgs::Float64 yaw_msg;
        yaw_msg.data = yaw_rad;
        yaw_hb_pub_.publish(yaw_msg);

        std_msgs::Float64 u_vel_msg;
        u_vel_msg.data = u;
        u_vel_hb_pub_.publish(u_vel_msg);

        std_msgs::Float64 v_vel_msg;
        v_vel_msg.data = v;
        v_vel_hb_pub_.publish(v_vel_msg);

        std_msgs::Float64 w_vel_msg;
        w_vel_msg.data = w;
        w_vel_hb_pub_.publish(w_vel_msg);

        std_msgs::Float64 p_avel_msg;
        p_avel_msg.data = p;
        p_avel_hb_pub_.publish(p_avel_msg);

        std_msgs::Float64 q_avel_msg;
        q_avel_msg.data = q;
        q_avel_hb_pub_.publish(q_avel_msg);

        std_msgs::Float64 r_avel_msg;
        r_avel_msg.data = r;
        r_avel_hb_pub_.publish(r_avel_msg);
    }

    void run() {
        ros::spin();
    }

private:
    double x_origin_;
    double y_origin_;
    double depth_origin_;

    ros::Publisher x_hb_pub_;
    ros::Publisher y_hb_pub_;
    ros::Publisher depth_hb_pub_;

    ros::Publisher roll_hb_pub_;
    ros::Publisher pitch_hb_pub_;
    ros::Publisher yaw_hb_pub_;

    ros::Publisher u_vel_hb_pub_;
    ros::Publisher v_vel_hb_pub_;
    ros::Publisher w_vel_hb_pub_;

    ros::Publisher p_avel_hb_pub_;
    ros::Publisher q_avel_hb_pub_;
    ros::Publisher r_avel_hb_pub_;

    ros::Subscriber heartbeat_sub_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "ad_hb_msgs");

    HeartbeatTranslator hb_translator;
    hb_translator.run();

    return 0;
}
