#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "ctrl_TT_ad_ctrl_cpp_ros_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45555;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45560;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe10
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45606;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe11
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45611;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45565;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45570;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe4
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45575;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe5
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45581;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45586;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe7
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45591;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe8
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45596;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Subscribe9
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_45601;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_45530;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_45539;

// For Block ctrl_TT_ad_ctrl_cpp_ros/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_45545;

void slros_node_init(int argc, char** argv);

#endif
