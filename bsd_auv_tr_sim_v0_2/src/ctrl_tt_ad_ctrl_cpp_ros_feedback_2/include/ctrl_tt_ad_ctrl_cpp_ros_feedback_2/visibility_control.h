#ifndef CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2__VISIBILITY_CONTROL_H_
#define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_EXPORT __attribute__ ((dllexport))
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_IMPORT __attribute__ ((dllimport))
  #else
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_EXPORT __declspec(dllexport)
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_IMPORT __declspec(dllimport)
  #endif
  #ifdef CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_BUILDING_LIBRARY
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_EXPORT
  #else
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_IMPORT
  #endif
  #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC_TYPE CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC
  #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_LOCAL
#else
  #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_EXPORT __attribute__ ((visibility("default")))
  #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_IMPORT
  #if __GNUC__ >= 4
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC __attribute__ ((visibility("default")))
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC
    #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_LOCAL
  #endif
  #define CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2_PUBLIC_TYPE
#endif
#endif  // CTRL_TT_AD_CTRL_CPP_ROS_FEEDBACK_2__VISIBILITY_CONTROL_H_
// Generated 17-Jul-2023 11:01:13
// Copyright 2019-2020 The MathWorks, Inc.
