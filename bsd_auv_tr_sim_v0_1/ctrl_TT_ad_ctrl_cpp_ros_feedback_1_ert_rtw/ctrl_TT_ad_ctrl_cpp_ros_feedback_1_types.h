//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ctrl_TT_ad_ctrl_cpp_ros_feedback_1_types.h
//
// Code generated for Simulink model 'ctrl_TT_ad_ctrl_cpp_ros_feedback_1'.
//
// Model version                  : 10.23
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Jun 19 10:52:17 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_types_h_
#define RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_rPo2eGiZDF2rfpzHq7PtkG_
#define DEFINED_TYPEDEF_FOR_struct_rPo2eGiZDF2rfpzHq7PtkG_

struct struct_rPo2eGiZDF2rfpzHq7PtkG
{
  real_T Amz[4];
  real_T Bmz[2];
  real_T Cmz[2];
  real_T Dmz;
  real_T Aoz[9];
  real_T Boz[6];
  real_T Coz[3];
  real_T Doz[2];
  real_T Lambdaz[4];
  real_T Phiinvz[4];
  real_T Ampsi[4];
  real_T Bmpsi[2];
  real_T Cmpsi[2];
  real_T Dmpsi;
  real_T Aopsi[9];
  real_T Bopsi[6];
  real_T Copsi[3];
  real_T Dopsi[2];
  real_T Lambdapsi[4];
  real_T Phiinvpsi[4];
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_ctrl_TT_ad_ctrl_cpp_ros_fee_T_ P_ctrl_TT_ad_ctrl_cpp_ros_fee_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ctrl_TT_ad_ctrl_cpp_r_T RT_MODEL_ctrl_TT_ad_ctrl_cpp__T;

#endif                // RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_feedback_1_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
