#include <ros/ros.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <std_msgs/Float64.h>
#include <cmath>

// Initialize origin coordinates and depth
double x_origin = 0.0;
double y_origin = 0.0;
double depth_origin = 0.0;

void heartbeatCallback(const avl_bsd_translator::HeartbeatMsg& msg) {
    // Check if origin has been assigned
    if (x_origin == 0.0 && y_origin == 0.0 && depth_origin == 0.0) {
        // Assign origin based on the first heartbeat message
        x_origin = msg.HEARTBEAT_GPS_LAT;
        y_origin = msg.HEARTBEAT_GPS_LON;
        depth_origin = msg.HEARTBEAT_DEPTH;
    }

    // Extract roll, pitch, and yaw values from the HeartbeatMsg
    double roll = msg.HEARTBEAT_ROLL;
    double pitch = msg.HEARTBEAT_PITCH;
    double yaw = msg.HEARTBEAT_YAW;

    // Extract u, v, and w velocities from the HeartbeatMsg
    double v_north = msg.HEARTBEAT_VN;
    double v_east = msg.HEARTBEAT_VE;
    double v_depth = msg.HEARTBEAT_VD;

    // Extract p, q, and r angular velocities from the HeartbeatMsg
    double p_avel = msg.HEARTBEAT_WX;
    double q_avel = msg.HEARTBEAT_WY;
    double r_avel = msg.HEARTBEAT_WZ;

    // Extract GPS latitude, longitude, and depth values from the HeartbeatMsg
    double gps_lat = msg.HEARTBEAT_GPS_LAT;
    double gps_lon = msg.HEARTBEAT_GPS_LON;
    double depth = msg.HEARTBEAT_DEPTH;

    // Calculate relative x, y, and depth coordinates
    double x = gps_lat - x_origin;
    double y = gps_lon - y_origin;
    double relative_depth = depth - depth_origin;

    // Calculate u, v, and w velocities in AUV coordinate system
    double u = v_north * std::cos(pitch) * std::cos(yaw) + v_east * (std::sin(roll) * std::sin(pitch) * std::cos(yaw) - std::cos(roll) * std::sin(yaw)) + v_depth * (std::cos(roll) * std::sin(pitch) * std::cos(yaw) + std::sin(roll) * std::sin(yaw));
    double v = v_north * std::cos(pitch) * std::sin(yaw) + v_east * (std::sin(roll) * std::sin(pitch) * std::sin(yaw) + std::cos(roll) * std::cos(yaw)) + v_depth * (std::cos(roll) * std::sin(pitch) * std::sin(yaw) - std::sin(roll) * std::cos(yaw));
    double w = -v_north * std::sin(pitch) + v_east * std::sin(roll) * std::cos(pitch) + v_depth * std::cos(roll) * std::cos(pitch);

    // Calculate p, q, and r angular velocities in AUV coordinate system
    double p = p_avel - q_avel * std::sin(roll) * std::tan(pitch) + r_avel * std::cos(roll) * std::tan(pitch);
    double q = q_avel * std::cos(roll) - r_avel * std::sin(roll);
    double r = q_avel * std::sin(roll) / std::cos(pitch) + r_avel * std::cos(roll) / std::cos(pitch);

    // Create ROS publishers for x, y, and depth heartbeat values
    ros::NodeHandle nh;
    ros::Publisher x_hb_pub = nh.advertise<std_msgs::Float64>("/x_hb_msg", 10);
    ros::Publisher y_hb_pub = nh.advertise<std_msgs::Float64>("/y_hb_msg", 10);
    ros::Publisher depth_hb_pub = nh.advertise<std_msgs::Float64>("/depth_hb_msg", 10);

    // Create ROS publishers for roll, pitch, and yaw heartbeat values
    ros::Publisher roll_hb_pub = nh.advertise<std_msgs::Float64>("/roll_hb_msg", 10);
    ros::Publisher pitch_hb_pub = nh.advertise<std_msgs::Float64>("/pitch_hb_msg", 10);
    ros::Publisher yaw_hb_pub = nh.advertise<std_msgs::Float64>("/yaw_hb_msg", 10);

    // Create ROS publishers for u, v, w velocity heartbeat values
    ros::Publisher u_vel_hb_pub = nh.advertise<std_msgs::Float64>("/u_vel_hb_msg", 10);
    ros::Publisher v_vel_hb_pub = nh.advertise<std_msgs::Float64>("/v_vel_hb_msg", 10);
    ros::Publisher w_vel_hb_pub = nh.advertise<std_msgs::Float64>("/w_vel_hb_msg", 10);

    // Create ROS publishers for p, q, r angular velocity heartbeat values
    ros::Publisher p_avel_hb_pub = nh.advertise<std_msgs::Float64>("/p_avel_hb_msg", 10);
    ros::Publisher q_avel_hb_pub = nh.advertise<std_msgs::Float64>("/q_avel_hb_msg", 10);
    ros::Publisher r_avel_hb_pub = nh.advertise<std_msgs::Float64>("/r_avel_hb_msg", 10);

    // Publish x, y, and depth values to separate topics
    std_msgs::Float64 x_msg;
    x_msg.data = x;
    x_hb_pub.publish(x_msg);

    std_msgs::Float64 y_msg;
    y_msg.data = y;
    y_hb_pub.publish(y_msg);

    std_msgs::Float64 depth_msg;
    depth_msg.data = relative_depth;
    depth_hb_pub.publish(depth_msg);

    // Publish roll, pitch, yaw, u, v, w, p, q, and r values to their respective topics
    std_msgs::Float64 roll_msg;
    roll_msg.data = roll;
    roll_hb_pub.publish(roll_msg);

    std_msgs::Float64 pitch_msg;
    pitch_msg.data = pitch;
    pitch_hb_pub.publish(pitch_msg);

    std_msgs::Float64 yaw_msg;
    yaw_msg.data = yaw;
    yaw_hb_pub.publish(yaw_msg);

    std_msgs::Float64 u_vel_msg;
    u_vel_msg.data = u;
    u_vel_hb_pub.publish(u_vel_msg);

    std_msgs::Float64 v_vel_msg;
    v_vel_msg.data = v;
    v_vel_hb_pub.publish(v_vel_msg);

    std_msgs::Float64 w_vel_msg;
    w_vel_msg.data = w;
    w_vel_hb_pub.publish(w_vel_msg);

    std_msgs::Float64 p_avel_msg;
    p_avel_msg.data = p;
    p_avel_hb_pub.publish(p_avel_msg);

    std_msgs::Float64 q_avel_msg;
    q_avel_msg.data = q;
    q_avel_hb_pub.publish(q_avel_msg);

    std_msgs::Float64 r_avel_msg;
    r_avel_msg.data = r;
    r_avel_hb_pub.publish(r_avel_msg);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "ad_hb_msgs");
    ros::NodeHandle nh;

    // Subscribe to the HeartbeatMsg topic
    ros::Subscriber heartbeat_sub = nh.subscribe("/bsd/heartbeat", 10, heartbeatCallback);

    ros::spin();

    return 0;
}
