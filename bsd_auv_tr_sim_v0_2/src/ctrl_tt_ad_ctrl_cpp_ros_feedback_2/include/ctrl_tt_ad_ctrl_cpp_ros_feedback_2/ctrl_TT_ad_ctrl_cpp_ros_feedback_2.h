//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ctrl_TT_ad_ctrl_cpp_ros_feedback_2.h
//
// Code generated for Simulink model 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2'.
//
// Model version                  : 10.24
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Jul 17 11:01:04 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_h_
#define RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ctrl_TT_ad_ctrl_cpp_ros_feedback_2_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define ctrl_TT_ad_ctrl_cpp_ros_feedback_2_M (ctrl_TT_ad_ctrl_cpp_ros_feed_M)

// Block signals (default storage)
struct B_ctrl_TT_ad_ctrl_cpp_ros_fee_T {
  real_T B[61];
  real_T T[61];
  real_T TT[61];
  real_T Ao[9];
  real_T y[9];
  real_T y_m[9];
  real_T Ao_c[9];
  real_T A2[9];
  real_T A4[9];
  real_T A6[9];
  real_T dv[9];
  real_T A4_k[9];
  real_T dv1[9];
  real_T b_a[9];
  real_T cBuffer[9];
  real_T aBuffer[9];
  real_T cBuffer_c[9];
  real_T b_x[9];
  real_T A2_b[9];
  real_T A4_p[9];
  real_T A6_c[9];
  real_T dv2[9];
  real_T A4_f[9];
  real_T dv3[9];
  real_T b_a_g[9];
  real_T cBuffer_g[9];
  real_T aBuffer_m[9];
  real_T cBuffer_n[9];
  real_T U[9];
  real_T V[9];
  real_T A6_p[9];
  real_T U_l[9];
  real_T V_j[9];
  real_T A6_d[9];
  real_T b_x_g[9];
  real_T MatrixMultiply[6];
  real_T dv4[6];
  real_T Lambda[4];
  real_T MatrixConcatenate[4];         // '<S41>/Matrix Concatenate'
  real_T MatrixMultiply1[4];           // '<S35>/Matrix Multiply1'
  real_T rtb_Divide_l[4];
  real_T A2_d[4];
  real_T A4_d[4];
  real_T A6_l[4];
  real_T U_o[4];
  real_T V_b[4];
  real_T A6_n[4];
  real_T T_b[4];
  real_T A4_l[4];
  real_T dv5[4];
  real_T b_a_h[4];
  real_T cBuffer_b[4];
  real_T aBuffer_d[4];
  real_T cBuffer_e[4];
  real_T cBuffer_bj[4];
  real_T A2_j[4];
  real_T A4_fd[4];
  real_T A6_a[4];
  real_T U_j[4];
  real_T V_jz[4];
  real_T A6_o[4];
  real_T b_a_n[4];
  real_T cBuffer_i[4];
  real_T aBuffer_o[4];
  real_T cBuffer_nv[4];
  real_T cBuffer_m[4];
  real_T T_c[4];
  real_T A4_m[4];
  real_T dv6[4];
  real_T pdp[3];                       // '<S16>/MATLAB Function2'
  real_T uTmp[3];
  real_T dv7[3];
  real_T a[3];
  real_T pd[3];
  real_T work[3];
  real_T v[3];
  real_T work_m[3];
  real_T v_j[3];
  char_T b_zeroDelimTopic[17];
  char_T b_zeroDelimTopic_h[16];
  real_T TmpSignalConversionAtNormal[2];
  real_T dv8[2];
  real_T tau[2];
  real_T tau_c[2];
  int8_T b_I[9];
  boolean_T Compare[9];                // '<S64>/Compare'
  real_T a22;
  real_T Clock;                        // '<S16>/Clock'
  real_T SquareRoot;                   // '<S41>/Square Root'
  real_T acc;
  real_T b_idx_1;
  real_T b_idx_2;
  real_T b_idx_3;
  real_T a22_tmp;
  real_T rtb_MatrixConcatenate_tmp;
  real_T exptj;
  real_T d_y;
  real_T d6;
  real_T eta1;
  real_T u0;
  real_T e;
  real_T ed2;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T exptj_c;
  real_T d_y_p;
  real_T d6_p;
  real_T eta1_a;
  real_T u0_e;
  real_T beta1;
  real_T A;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T h12;
  real_T h21s;
  real_T a__3;
  real_T a__4;
  real_T temp;
  real_T p;
  real_T bcmax;
  real_T bcmis;
  real_T scale;
  real_T z;
  real_T a_a;
  real_T b;
  real_T exptj_a;
  real_T b_y;
  real_T d_y_i;
  real_T d;
  real_T a22_l;
  real_T A6_tmp;
  real_T U_tmp;
  real_T d6_o;
  real_T eta1_o;
  real_T A4_tmp;
  real_T A4_tmp_i;
  real_T e_f;
  real_T ed2_i;
  real_T cBuffer_tmp;
  real_T cBuffer_tmp_f;
  real_T r;
  real_T exptj_g;
  real_T b_y_c;
  real_T d_y_o;
  real_T d_l;
  real_T a22_m;
  real_T A6_tmp_m;
  real_T U_tmp_c;
  real_T htmp1_f;
  real_T htmp2;
  real_T ab_p;
  real_T ba_e;
  real_T aa_o;
  real_T a__1;
  real_T a__2;
  real_T a__3_h;
  real_T d_l5;
  real_T a21;
  real_T A6_h;
  real_T beta1_m;
  real_T A_m;
  real_T xnorm;
  real_T a_h;
  real_T scale_c;
  real_T absxk;
  real_T t;
  real_T d6_k;
  real_T tst_p;
  real_T htmp1_p;
  real_T ab_p4;
  real_T ba_a;
  real_T aa_j;
  real_T h12_e;
  real_T h21s_o;
  real_T a__3_b;
  real_T a__4_a;
  real_T temp_tmp;
  real_T htmp1_g;
  real_T htmp2_e;
  real_T ab_f;
  real_T ba_h;
  real_T aa_e;
  real_T a__1_c;
  real_T temp_tmp_a;
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 In1_fi;// '<S75>/In1' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 In1_ff;// '<S74>/In1' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 In1_j;// '<S73>/In1' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 In1_l;// '<S72>/In1' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 In1_b;// '<S69>/In1' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 In1_pu;// '<S68>/In1' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 b_varargout_2;
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 BusAssignment2;// '<Root>/Bus Assignment2' 
  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 BusAssignment1;// '<Root>/Bus Assignment1' 
  int32_T blockFormat[2];
  int32_T blockFormat_d[2];
  int32_T r1;
  int32_T r2;
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T c_i;
  int32_T c_i_a;
  int32_T b_k;
  int32_T b_s;
  int32_T c_k;
  int32_T F_tmp;
  int32_T im1n;
  int32_T in;
  int32_T ix0;
  int32_T knt;
  int32_T lastc;
  int32_T g_i;
  int32_T iac;
  int32_T g;
  int32_T b_ia;
  int32_T rowleft;
  int32_T im1n_p;
  int32_T in_m;
  int32_T ix0_o;
  int32_T knt_n;
  int32_T lastc_l;
  int32_T g_i_p;
  int32_T iac_p;
  int32_T g_f;
  int32_T b_ia_i;
  int32_T rowleft_o;
  int32_T c_ia;
  int32_T b_k_k;
  int32_T b_s_i;
  int32_T c_k_o;
  int32_T F_tmp_m;
  int32_T c_ia_c;
};

// Block states (default storage) for system '<Root>'
struct DW_ctrl_TT_ad_ctrl_cpp_ros_fe_T {
  ros_slroscpp_internal_block_P_T obj; // '<S19>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_l;// '<S18>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_f;// '<S17>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S31>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_lk;// '<S30>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_fs;// '<S29>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S28>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S27>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_i;// '<S26>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_fr;// '<S25>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_a;// '<S24>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_ln;// '<S23>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_jw;// '<S22>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S21>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_au;// '<S20>/SourceBlock'
  real_T xu[3];                        // '<S16>/l1 aug - heading'
  real_T xd[2];                        // '<S16>/l1 aug - heading'
  real_T xu_g[3];                      // '<S16>/l1 aug - depth'
  real_T xd_p[2];                      // '<S16>/l1 aug - depth'
  real_T zerr_int_prev;                // '<S16>/Marin PID'
  real_T thetaerr_int_prev;            // '<S16>/Marin PID'
  real_T psierr_int_prev;              // '<S16>/Marin PID'
  boolean_T xu_not_empty;              // '<S16>/l1 aug - heading'
  boolean_T xu_not_empty_o;            // '<S16>/l1 aug - depth'
};

// Parameters (default storage)
struct P_ctrl_TT_ad_ctrl_cpp_ros_fee_T_ {
  struct_rPo2eGiZDF2rfpzHq7PtkG L1;    // Variable: L1
                                          //  Referenced by:
                                          //    '<S16>/l1 aug - depth'
                                          //    '<S16>/l1 aug - heading'

  real_T Cp[183];                      // Variable: Cp
                                          //  Referenced by: '<S16>/MATLAB Function2'

  real_T Cp_prime[183];                // Variable: Cp_prime
                                          //  Referenced by: '<S16>/MATLAB Function2'

  real_T Kp;                           // Variable: Kp
                                          //  Referenced by: '<S35>/Gain1'

  real_T Tf;                           // Variable: Tf
                                          //  Referenced by: '<S16>/MATLAB Function2'

  real_T Ts;                           // Variable: Ts
                                          //  Referenced by:
                                          //    '<S16>/Marin PID'
                                          //    '<S16>/l1 aug - depth'
                                          //    '<S16>/l1 aug - heading'

  real_T adap;                         // Variable: adap
                                          //  Referenced by:
                                          //    '<S16>/l1 aug - depth'
                                          //    '<S16>/l1 aug - heading'

  real_T d;                            // Variable: d
                                          //  Referenced by: '<S41>/Constant3'

  real_T Normalization_Bias;           // Mask Parameter: Normalization_Bias
                                          //  Referenced by: '<S41>/Normalization'

  real_T Normalization1_Bias;          // Mask Parameter: Normalization1_Bias
                                          //  Referenced by: '<S41>/Normalization1'

  real_T DirectionCosineMatrixtoRotation;
                              // Mask Parameter: DirectionCosineMatrixtoRotation
                                 //  Referenced by:
                                 //    '<S46>/Constant'
                                 //    '<S56>/Constant'
                                 //    '<S57>/Constant'

  real_T DirectionCosineMatrixtoRotati_a;
                              // Mask Parameter: DirectionCosineMatrixtoRotati_a
                                 //  Referenced by:
                                 //    '<S64>/Constant'
                                 //    '<S66>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S1>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                      //  Referenced by: '<S2>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                                      //  Referenced by: '<S3>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                      //  Referenced by: '<S4>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                      //  Referenced by: '<S5>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_ly;// Computed Parameter: Constant_Value_ly
                                                                      //  Referenced by: '<S6>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_lj;// Computed Parameter: Constant_Value_lj
                                                                      //  Referenced by: '<S7>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                                      //  Referenced by: '<S8>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                      //  Referenced by: '<S9>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                      //  Referenced by: '<S10>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_b0;// Computed Parameter: Constant_Value_b0
                                                                      //  Referenced by: '<S11>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                      //  Referenced by: '<S12>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                      //  Referenced by: '<S13>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                      //  Referenced by: '<S14>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_ba;// Computed Parameter: Constant_Value_ba
                                                                      //  Referenced by: '<S15>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                                      //  Referenced by: '<S68>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                      //  Referenced by: '<S20>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_n;// Computed Parameter: Out1_Y0_n
                                                                      //  Referenced by: '<S69>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_dn;// Computed Parameter: Constant_Value_dn
                                                                      //  Referenced by: '<S21>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                                      //  Referenced by: '<S70>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_c3;// Computed Parameter: Constant_Value_c3
                                                                      //  Referenced by: '<S22>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                                      //  Referenced by: '<S71>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_aq;// Computed Parameter: Constant_Value_aq
                                                                      //  Referenced by: '<S23>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                                      //  Referenced by: '<S72>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_m1;// Computed Parameter: Constant_Value_m1
                                                                      //  Referenced by: '<S24>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_gg;// Computed Parameter: Out1_Y0_gg
                                                                      //  Referenced by: '<S73>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                      //  Referenced by: '<S25>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                                      //  Referenced by: '<S74>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_hm;// Computed Parameter: Constant_Value_hm
                                                                      //  Referenced by: '<S26>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_l;// Computed Parameter: Out1_Y0_l
                                                                      //  Referenced by: '<S75>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_pp;// Computed Parameter: Constant_Value_pp
                                                                      //  Referenced by: '<S27>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_hk;// Computed Parameter: Out1_Y0_hk
                                                                      //  Referenced by: '<S76>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_cp;// Computed Parameter: Constant_Value_cp
                                                                      //  Referenced by: '<S28>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                                      //  Referenced by: '<S77>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                      //  Referenced by: '<S29>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_gu;// Computed Parameter: Out1_Y0_gu
                                                                      //  Referenced by: '<S78>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                      //  Referenced by: '<S30>/Constant'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Out1_Y0_lg;// Computed Parameter: Out1_Y0_lg
                                                                      //  Referenced by: '<S79>/Out1'

  SL_Bus_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_std_msgs_Float64 Constant_Value_gp;// Computed Parameter: Constant_Value_gp
                                                                      //  Referenced by: '<S31>/Constant'

  real_T Constant_Value_h2;            // Expression: 1
                                          //  Referenced by: '<S52>/Constant'

  real_T Constant_Value_cg;            // Expression: 1
                                          //  Referenced by: '<S53>/Constant'

  real_T Constant_Value_h2t;           // Expression: 1
                                          //  Referenced by: '<S48>/Constant'

  real_T Constant_Value_am;            // Expression: 1
                                          //  Referenced by: '<S49>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S57>/Constant1'

  real_T Constant1_Value_e;            // Expression: 0
                                          //  Referenced by: '<S56>/Constant1'

  real_T Bias1_Bias[9];                // Expression: -eye(3)
                                          //  Referenced by: '<S58>/Bias1'

  real_T Bias_Bias;                    // Expression: -1
                                          //  Referenced by: '<S59>/Bias'

  real_T Constant_Value_gf[36];
  // Expression: [-1 0 0 0 0 0; 0 -1 0 0 0 0; 0 0 1 0 0 0; 0 0 0 1 0 0; 0 0 0 0 1 0; 0 0 0 0 0 1]
     //  Referenced by: '<S16>/Constant'

  real_T Constant2_Value[36];
  // Expression: [-1 0 0 0 0 0; 0 -1 0 0 0 0; 0 0 1 0 0 0; 0 0 0 1 0 0; 0 0 0 0 1 0; 0 0 0 0 0 1]
     //  Referenced by: '<S16>/Constant2'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S41>/Gain'

  real_T Gain1_Gain[3];                // Expression: [1 1 -1]
                                          //  Referenced by: '<S45>/Gain1'

  real_T Gain2_Gain[2];                // Expression: [1 1]
                                          //  Referenced by: '<S45>/Gain2'

  real_T Gain3_Gain[2];                // Expression: [-1 1]
                                          //  Referenced by: '<S45>/Gain3'

  real_T Gain_Gain_o;                  // Expression: -1
                                          //  Referenced by: '<S35>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_ctrl_TT_ad_ctrl_cpp_r_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_ctrl_TT_ad_ctrl_cpp_ros_fee_T ctrl_TT_ad_ctrl_cpp_ros_feedb_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_ctrl_TT_ad_ctrl_cpp_ros_fee_T ctrl_TT_ad_ctrl_cpp_ros_feedb_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_ctrl_TT_ad_ctrl_cpp_ros_fe_T ctrl_TT_ad_ctrl_cpp_ros_feed_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void ctrl_TT_ad_ctrl_cpp_ros_feedback_2_initialize(void);
  extern void ctrl_TT_ad_ctrl_cpp_ros_feedback_2_step(void);
  extern void ctrl_TT_ad_ctrl_cpp_ros_feedback_2_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_ctrl_TT_ad_ctrl_cpp__T *const ctrl_TT_ad_ctrl_cpp_ros_feed_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S16>/Constant1' : Unused code path elimination
//  Block '<S35>/Derivative' : Unused code path elimination
//  Block '<S35>/Display' : Unused code path elimination
//  Block '<S35>/Display1' : Unused code path elimination
//  Block '<S35>/Display2' : Unused code path elimination
//  Block '<S35>/Display3' : Unused code path elimination
//  Block '<S35>/Display4' : Unused code path elimination
//  Block '<S35>/Display5' : Unused code path elimination
//  Block '<S35>/Display6' : Unused code path elimination
//  Block '<S35>/Display7' : Unused code path elimination
//  Block '<S35>/Scope' : Unused code path elimination
//  Block '<S35>/Scope1' : Unused code path elimination
//  Block '<S40>/Add' : Unused code path elimination
//  Block '<S40>/Sqrt' : Unused code path elimination
//  Block '<S40>/Square' : Unused code path elimination
//  Block '<S40>/Square1' : Unused code path elimination
//  Block '<S40>/Square2' : Unused code path elimination
//  Block '<S41>/Display' : Unused code path elimination
//  Block '<S41>/Display1' : Unused code path elimination
//  Block '<S41>/Display2' : Unused code path elimination
//  Block '<S41>/Display8' : Unused code path elimination
//  Block '<S41>/xT' : Unused code path elimination
//  Block '<S41>/yT' : Unused code path elimination
//  Block '<S42>/Add' : Unused code path elimination
//  Block '<S42>/Sqrt' : Unused code path elimination
//  Block '<S42>/Square' : Unused code path elimination
//  Block '<S42>/Square1' : Unused code path elimination
//  Block '<S42>/Square2' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination
//  Block '<S45>/Reshape' : Reshape block reduction
//  Block '<S45>/Reshape1' : Reshape block reduction
//  Block '<S45>/Reshape2' : Reshape block reduction
//  Block '<S58>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2'
//  '<S1>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message'
//  '<S2>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message1'
//  '<S3>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message10'
//  '<S4>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message11'
//  '<S5>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message12'
//  '<S6>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message13'
//  '<S7>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message14'
//  '<S8>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message15'
//  '<S9>'   : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message2'
//  '<S10>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message4'
//  '<S11>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message5'
//  '<S12>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message6'
//  '<S13>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message7'
//  '<S14>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message8'
//  '<S15>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Blank Message9'
//  '<S16>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller'
//  '<S17>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Publish'
//  '<S18>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Publish1'
//  '<S19>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Publish2'
//  '<S20>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe'
//  '<S21>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe1'
//  '<S22>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe10'
//  '<S23>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe11'
//  '<S24>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe2'
//  '<S25>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe3'
//  '<S26>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe4'
//  '<S27>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe5'
//  '<S28>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe6'
//  '<S29>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe7'
//  '<S30>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe8'
//  '<S31>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe9'
//  '<S32>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/FF velocity ctrl'
//  '<S33>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/MATLAB Function2'
//  '<S34>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Marin PID'
//  '<S35>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1'
//  '<S36>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/l1 aug - depth'
//  '<S37>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/l1 aug - heading'
//  '<S38>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles'
//  '<S39>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/MATLAB Function'
//  '<S40>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Subsystem1'
//  '<S41>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Subsystem2'
//  '<S42>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Subsystem3'
//  '<S43>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotDefault'
//  '<S44>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3'
//  '<S45>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Get DCM Values'
//  '<S46>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM'
//  '<S47>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotDefault/Protect asincos input'
//  '<S48>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotDefault/Protect asincos input/If Action Subsystem'
//  '<S49>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotDefault/Protect asincos input/If Action Subsystem1'
//  '<S50>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotDefault/Protect asincos input/If Action Subsystem2'
//  '<S51>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3/Protect asincos input'
//  '<S52>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3/Protect asincos input/If Action Subsystem'
//  '<S53>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3/Protect asincos input/If Action Subsystem1'
//  '<S54>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3/Protect asincos input/If Action Subsystem2'
//  '<S55>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error'
//  '<S56>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S57>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/If Not Proper'
//  '<S58>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S59>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/isNotProper'
//  '<S60>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S61>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S62>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S63>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S64>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S65>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S66>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Direction Cosine Matrix to Rotation Angles/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S67>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Controller/Subsystem1/Subsystem2/MATLAB Function'
//  '<S68>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe/Enabled Subsystem'
//  '<S69>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe1/Enabled Subsystem'
//  '<S70>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe10/Enabled Subsystem'
//  '<S71>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe11/Enabled Subsystem'
//  '<S72>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe2/Enabled Subsystem'
//  '<S73>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe3/Enabled Subsystem'
//  '<S74>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe4/Enabled Subsystem'
//  '<S75>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe5/Enabled Subsystem'
//  '<S76>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe6/Enabled Subsystem'
//  '<S77>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe7/Enabled Subsystem'
//  '<S78>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe8/Enabled Subsystem'
//  '<S79>'  : 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2/Subscribe9/Enabled Subsystem'

#endif                      // RTW_HEADER_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_h_

//
// File trailer for generated code.
//
// [EOF]
//
