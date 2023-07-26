#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ctrl_TT_ad_ctrl_cpp_ros";

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45555;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45560;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe10
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45606;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe11
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45611;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45565;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45570;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe4
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45575;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe5
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45581;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45586;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe7
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45591;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe8
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45596;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe9
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45601;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_45530;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_45539;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_45545;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

