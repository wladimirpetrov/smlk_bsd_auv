#ifndef CTRL_TT_AD_CTRL_CPP_ROS__VISIBILITY_CONTROL_H_
#define CTRL_TT_AD_CTRL_CPP_ROS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CTRL_TT_AD_CTRL_CPP_ROS_EXPORT __attribute__ ((dllexport))
    #define CTRL_TT_AD_CTRL_CPP_ROS_IMPORT __attribute__ ((dllimport))
  #else
    #define CTRL_TT_AD_CTRL_CPP_ROS_EXPORT __declspec(dllexport)
    #define CTRL_TT_AD_CTRL_CPP_ROS_IMPORT __declspec(dllimport)
  #endif
  #ifdef CTRL_TT_AD_CTRL_CPP_ROS_BUILDING_LIBRARY
    #define CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC CTRL_TT_AD_CTRL_CPP_ROS_EXPORT
  #else
    #define CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC CTRL_TT_AD_CTRL_CPP_ROS_IMPORT
  #endif
  #define CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC_TYPE CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC
  #define CTRL_TT_AD_CTRL_CPP_ROS_LOCAL
#else
  #define CTRL_TT_AD_CTRL_CPP_ROS_EXPORT __attribute__ ((visibility("default")))
  #define CTRL_TT_AD_CTRL_CPP_ROS_IMPORT
  #if __GNUC__ >= 4
    #define CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC __attribute__ ((visibility("default")))
    #define CTRL_TT_AD_CTRL_CPP_ROS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC
    #define CTRL_TT_AD_CTRL_CPP_ROS_LOCAL
  #endif
  #define CTRL_TT_AD_CTRL_CPP_ROS_PUBLIC_TYPE
#endif
#endif  // CTRL_TT_AD_CTRL_CPP_ROS__VISIBILITY_CONTROL_H_
// Generated 30-Jun-2023 11:16:50
// Copyright 2019-2020 The MathWorks, Inc.
