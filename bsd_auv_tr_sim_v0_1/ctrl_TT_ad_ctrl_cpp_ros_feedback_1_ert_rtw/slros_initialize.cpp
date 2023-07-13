#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ctrl_TT_ad_ctrl_cpp_ros_feedback_1";

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45555;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45560;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe10
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45606;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe11
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45611;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45565;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45570;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe4
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45575;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe5
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45581;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45586;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe7
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45591;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe8
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45596;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Subscribe9
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45601;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45530;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45539;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_1/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_45545;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

