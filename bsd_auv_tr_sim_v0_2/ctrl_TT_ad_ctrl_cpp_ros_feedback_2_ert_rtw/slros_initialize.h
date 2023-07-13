#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "ctrl_TT_ad_ctrl_cpp_ros_feedback_2_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45555;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45560;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe10
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45606;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe11
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45611;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45565;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45570;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe4
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45575;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe5
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45581;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45586;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe7
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45591;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe8
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45596;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe9
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45601;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45530;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45539;

// For Block ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64> Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45545;

void slros_node_init(int argc, char** argv);

#endif
