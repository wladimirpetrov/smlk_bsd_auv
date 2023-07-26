//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ctrl_TT_ad_ctrl_cpp_ros_private.h
//
// Code generated for Simulink model 'ctrl_TT_ad_ctrl_cpp_ros'.
//
// Model version                  : 10.21
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Jun 30 11:16:41 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_private_h_
#define RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_private_h_
#include "rtwtypes.h"
#include "ctrl_TT_ad_ctrl_cpp_ros_types.h"
#include "ctrl_TT_ad_ctrl_cpp_ros.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator);
extern int32_T div_nzp_s32(int32_T numerator, int32_T denominator);

#endif                         // RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
