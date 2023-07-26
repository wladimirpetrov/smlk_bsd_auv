//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ctrl_TT_ad_ctrl_cpp_ros_feedback_2.cpp
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
#include "ctrl_TT_ad_ctrl_cpp_ros_feedback_2.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_assert.h"
#include "ctrl_TT_ad_ctrl_cpp_ros_feedback_2_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"

// Block signals (default storage)
B_ctrl_TT_ad_ctrl_cpp_ros_fee_T ctrl_TT_ad_ctrl_cpp_ros_feedb_B;

// Block states (default storage)
DW_ctrl_TT_ad_ctrl_cpp_ros_fe_T ctrl_TT_ad_ctrl_cpp_ros_feed_DW;

// Real-time model
RT_MODEL_ctrl_TT_ad_ctrl_cpp__T ctrl_TT_ad_ctrl_cpp_ros_feed_M_ =
  RT_MODEL_ctrl_TT_ad_ctrl_cpp__T();
RT_MODEL_ctrl_TT_ad_ctrl_cpp__T *const ctrl_TT_ad_ctrl_cpp_ros_feed_M =
  &ctrl_TT_ad_ctrl_cpp_ros_feed_M_;

// Forward declaration for local functions
static void ctrl_TT_ad_ctrl_c_BernsteinPoly(const real_T b_Cp[183], real_T t,
  real_T t0, real_T tf, real_T poly_t[3]);
static real_T ctrl_TT_ad_ctrl_cpp_ros_fee_inv(real_T x);
static real_T ctrl_TT_ad_ctrl_cpp_ros_fe_norm(const real_T x[4]);
static void ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(const real_T x[4], real_T y[4]);
static void ctrl_TT_ad_ctrl_cpp_ros__mpower(const real_T a[4], real_T b, real_T
  c[4]);
static real_T ctrl_TT_ad_ctrl_cpp_ros_fe_log2(real_T x);
static void ctrl_TT_ad_ctrl_c_getExpmParams(const real_T A[4], real_T A2[4],
  real_T A4[4], real_T A6[4], int32_T *m, real_T *s);
static void ctrl_TT_ad_c_recomputeBlockDiag(const real_T A[4], real_T F[4],
  int32_T blockFormat);
static real_T ctrl_TT_ad_ctrl_cpp_ros__xgehrd(void);
static real_T ctrl_TT_ad_ctrl_c_rt_hypotd_snf(real_T u0, real_T u1);
static void ctrl_TT_ad_ctrl_cpp_ros_xdlanv2(real_T *a, real_T *b, real_T *c,
  real_T *d, real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs,
  real_T *sn);
static int32_T ctrl_TT_ad_ctrl_cpp_ros__xhseqr(real_T h[4], real_T z[4]);
static void ctrl_TT_ad_ctrl_cpp_ros_f_schur(const real_T A[4], real_T V[4],
  real_T T[4]);
static void ctrl_TT_ad_ctrl_cpp_ros_fe_expm(real_T A[4], real_T F[4]);
static real_T ctrl_TT_ad_ctrl_cpp_ros__norm_b(const real_T x[9]);
static void ctrl_TT_ad_ctrl_cpp_ros__inv_jg(const real_T x[9], real_T y[9]);
static void ctrl_TT_ad_ctrl_cpp_ro_mpower_f(const real_T a[9], real_T b, real_T
  c[9]);
static void ctrl_TT_ad_ct_padeApproximation(const real_T A[9], const real_T A2[9],
  const real_T A4[9], const real_T A6[9], int32_T m, real_T F[9]);
static void ctrl_TT_ad_recomputeBlockDiag_b(const real_T A[9], real_T F[9],
  const int32_T blockFormat[2]);
static real_T ctrl_TT_ad_ctrl_cpp_ros_xnrm2_l(int32_T n, const real_T x[9],
  int32_T ix0);
static void ctrl_TT_ad_ctrl_cpp_ros__xzlarf(int32_T m, int32_T n, int32_T iv0,
  real_T tau, real_T C[9], int32_T ic0, real_T work[3]);
static real_T ctrl_TT_ad_ctrl_cpp_ros_f_xnrm2(int32_T n, const real_T x[3]);
static real_T ctrl_TT_ad_ctrl_cpp_ros_xzlarfg(int32_T n, real_T *alpha1, real_T
  x[3]);
static void ctrl_TT_ad_ctrl_cpp_ros_fe_xrot(int32_T n, real_T x[9], int32_T ix0,
  int32_T iy0, real_T c, real_T s);
static int32_T ctrl_TT_ad_ctrl_cpp_ro_xhseqr_d(real_T h[9], real_T z[9]);
static void ctrl_TT_ad_ctrl_cpp_ros_schur_c(const real_T A[9], real_T V[9],
  real_T T[9]);
static void ctrl_TT_ad_ctrl_cpp_ros__expm_f(real_T A[9], real_T F[9]);
int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator)
{
  uint32_T absDenominator;
  uint32_T absNumerator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  absNumerator = numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
    static_cast<uint32_T>(numerator);
  absDenominator = denominator < 0 ? ~static_cast<uint32_T>(denominator) + 1U :
    static_cast<uint32_T>(denominator);
  quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
  tempAbsQuotient = absNumerator / absDenominator;
  if (quotientNeedsNegation) {
    absNumerator %= absDenominator;
    if (absNumerator > 0U) {
      tempAbsQuotient++;
    }
  }

  return quotientNeedsNegation ? -static_cast<int32_T>(tempAbsQuotient) :
    static_cast<int32_T>(tempAbsQuotient);
}

int32_T div_nzp_s32(int32_T numerator, int32_T denominator)
{
  uint32_T tempAbsQuotient;
  tempAbsQuotient = (numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
                     static_cast<uint32_T>(numerator)) / (denominator < 0 ? ~
    static_cast<uint32_T>(denominator) + 1U : static_cast<uint32_T>(denominator));
  return (numerator < 0) != (denominator < 0) ? -static_cast<int32_T>
    (tempAbsQuotient) : static_cast<int32_T>(tempAbsQuotient);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S16>/MATLAB Function2'
static void ctrl_TT_ad_ctrl_c_BernsteinPoly(const real_T b_Cp[183], real_T t,
  real_T t0, real_T tf, real_T poly_t[3])
{
  real_T tp;
  real_T ttp;
  for (int32_T i = 0; i < 61; i++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i] = 1.0;
  }

  for (int32_T i = 0; i < 30; i++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i + 1] = (61.0 - (static_cast<real_T>(i) +
      1.0)) * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i] / (static_cast<real_T>(i) +
      1.0);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[59 - i] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i + 1];
  }

  for (int32_T i = 0; i < 61; i++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T[i] = 1.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TT[i] = 1.0;
  }

  tp = t - t0;
  ttp = tf - t;
  for (int32_T i = 0; i < 60; i++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T[i + 1] = tp *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T[i];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T[i] *= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TT[59 - i] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TT[60 - i] * ttp;
  }

  tp = rt_powd_snf(tf - t0, 60.0);
  for (int32_T i = 0; i < 61; i++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T[i] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TT[i] / tp;
  }

  for (int32_T i = 0; i < 3; i++) {
    poly_t[i] = 0.0;
    for (int32_T i_0 = 0; i_0 < 61; i_0++) {
      poly_t[i] += b_Cp[3 * i_0 + i] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.B[i_0];
    }
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros_fee_inv(real_T x)
{
  return 1.0 / x;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros_fe_norm(const real_T x[4])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    real_T s;
    int32_T s_tmp;
    s_tmp = j << 1;
    s = fabs(x[s_tmp + 1]) + fabs(x[s_tmp]);
    if (rtIsNaN(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(const real_T x[4], real_T y[4])
{
  if (fabs(x[1]) > fabs(x[0])) {
    real_T t;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r = x[0] / x[1];
    t = 1.0 / (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r * x[3] - x[2]);
    y[0] = x[3] / x[1] * t;
    y[1] = -t;
    y[2] = -x[2] / x[1] * t;
    y[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r * t;
  } else {
    real_T t;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r = x[1] / x[0];
    t = 1.0 / (x[3] - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r * x[2]);
    y[0] = x[3] / x[0] * t;
    y[1] = -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r * t;
    y[2] = -x[2] / x[0] * t;
    y[3] = t;
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros__mpower(const real_T a[4], real_T b, real_T
  c[4])
{
  if (floor(b) == b) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f = fabs(b);
    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f <= 2.147483647E+9) {
      int32_T b_n;
      int32_T n;
      int32_T nb;
      int32_T nbitson;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0] = a[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1] = a[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2] = a[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3] = a[3];
      n = static_cast<int32_T>(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f);
      b_n = n;
      nbitson = 0;
      nb = -2;
      while (b_n > 0) {
        nb++;
        if ((static_cast<uint32_T>(b_n) & 1U) != 0U) {
          nbitson++;
        }

        b_n >>= 1;
      }

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f <= 2.0) {
        if (b == 2.0) {
          for (b_n = 0; b_n < 2; b_n++) {
            n = b_n << 1;
            c[n] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f = a[n];
            c[n] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f * a[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i = a[n + 1];
            c[n] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i * a[2];
            c[n + 1] = 0.0;
            c[n + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f * a[1];
            c[n + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i * a[3];
          }
        } else if (b == 1.0) {
          c[0] = a[0];
          c[1] = a[1];
          c[2] = a[2];
          c[3] = a[3];
        } else if (b == -1.0) {
          ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(a, c);
        } else if (b == -2.0) {
          for (b_n = 0; b_n < 2; b_n++) {
            n = b_n << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f = a[n];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f * a[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i = a[n + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i * a[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f * a[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i * a[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h,
            c);
        } else {
          boolean_T firstmult;
          firstmult = rtIsNaN(a[0]);
          if (!firstmult) {
            firstmult = rtIsNaN(a[1]);
          }

          if (!firstmult) {
            firstmult = rtIsNaN(a[2]);
          }

          if (!firstmult) {
            firstmult = rtIsNaN(a[3]);
          }

          if (firstmult) {
            c[0] = (rtNaN);
            c[1] = (rtNaN);
            c[2] = (rtNaN);
            c[3] = (rtNaN);
          } else {
            c[1] = 0.0;
            c[2] = 0.0;
            c[0] = 1.0;
            c[3] = 1.0;
          }
        }
      } else {
        boolean_T aBufferInUse;
        boolean_T firstmult;
        boolean_T lsb;
        firstmult = true;
        aBufferInUse = false;
        lsb = ((static_cast<uint32_T>(nbitson) & 1U) != 0U);
        lsb = ((lsb && (b < 0.0)) || ((!lsb) && (b >= 0.0)));
        for (nbitson = 0; nbitson <= nb; nbitson++) {
          if ((static_cast<uint32_T>(n) & 1U) != 0U) {
            if (firstmult) {
              firstmult = false;
              if (lsb) {
                if (aBufferInUse) {
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[0] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[1] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[2] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[3] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
                } else {
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[0] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[1] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[2] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[3] =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
                }
              } else if (aBufferInUse) {
                c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
                c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
                c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
                c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
              } else {
                c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
                c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
                c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
                c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
              }
            } else {
              if (aBufferInUse) {
                if (lsb) {
                  for (b_n = 0; b_n < 2; b_n++) {
                    c[b_n] = 0.0;
                    c[b_n] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f =
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2];
                    c[b_n] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
                    c[b_n + 2] = 0.0;
                    c[b_n + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n]
                      * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
                    c[b_n + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
                  }
                } else {
                  for (b_n = 0; b_n < 2; b_n++) {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] = 0.0;
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] += c[b_n] *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f = c[b_n + 2];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] +=
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] = 0.0;
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] += c[b_n]
                      * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] +=
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
                  }
                }
              } else if (lsb) {
                for (b_n = 0; b_n < 2; b_n++) {
                  c[b_n] = 0.0;
                  c[b_n] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f =
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2];
                  c[b_n] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
                  c[b_n + 2] = 0.0;
                  c[b_n + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
                  c[b_n + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
                }
              } else {
                for (b_n = 0; b_n < 2; b_n++) {
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] = 0.0;
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] += c[b_n] *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f = c[b_n + 2];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] +=
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] = 0.0;
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] += c[b_n] *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] +=
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
                }
              }

              lsb = !lsb;
            }
          }

          n >>= 1;
          if (aBufferInUse) {
            for (b_n = 0; b_n < 2; b_n++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n + 2] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n + 2] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n + 2] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
            }
          } else {
            for (b_n = 0; b_n < 2; b_n++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n + 2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
            }
          }

          aBufferInUse = !aBufferInUse;
        }

        if (firstmult) {
          if (b < 0.0) {
            if (aBufferInUse) {
              ctrl_TT_ad_ctrl_cpp_ros_f_inv_j
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d, c);
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_f_inv_j
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h, c);
            }
          } else if (aBufferInUse) {
            c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
            c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
            c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
            c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
          } else {
            c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
            c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
            c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
            c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
          }
        } else if (b < 0.0) {
          for (b_n = 0; b_n < 2; b_n++) {
            n = b_n << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[n] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[n];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f * c[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i * c[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[n + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp * c[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp_f =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp_f * c[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[n + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f * c[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i * c[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp * c[3];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp_f * c[3];
          }

          if (aBufferInUse) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[0] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[1] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[2] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[3] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[3];
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[0] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[1] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[2] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[3] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_f_inv_j
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e, c);
        } else {
          for (b_n = 0; b_n < 2; b_n++) {
            n = b_n << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[n] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[n];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[n + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp_f =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[n + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp_f *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[n + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[3];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[n + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_tmp_f *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[3];
          }

          if (aBufferInUse) {
            c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[0];
            c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[1];
            c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[2];
            c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_e[3];
          } else {
            c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[0];
            c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[1];
            c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[2];
            c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_bj[3];
          }
        }
      }
    } else {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0] = a[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1] = a[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2] = a[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3] = a[3];
      if (!rtIsInf(b)) {
        boolean_T firstmult;
        firstmult = true;
        int32_T exitg1;
        do {
          exitg1 = 0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i = floor
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f / 2.0);
          if (2.0 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i !=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f) {
            if (firstmult) {
              c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
              c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
              c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
              c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
              firstmult = false;
            } else {
              for (int32_T b_n = 0; b_n < 2; b_n++) {
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] = 0.0;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] += c[b_n] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f = c[b_n + 2];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] = 0.0;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] += c[b_n] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[b_n + 2] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
              }

              c[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[0];
              c[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[1];
              c[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[2];
              c[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_b[3];
            }
          }

          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i == 0.0) {
            exitg1 = 1;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e_f =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i;
            for (int32_T b_n = 0; b_n < 2; b_n++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n + 2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[b_n + 2] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2_i *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3];
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[0] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[1] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[2] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[3] =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer_d[3];
          }
        } while (exitg1 == 0);

        if (b < 0.0) {
          for (int32_T b_n = 0; b_n < 4; b_n++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h[b_n] = c[b_n];
          }

          ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a_h,
            c);
        }
      } else {
        c[0] = (rtNaN);
        c[1] = (rtNaN);
        c[2] = (rtNaN);
        c[3] = (rtNaN);
      }
    }
  } else {
    c[0] = (rtNaN);
    c[1] = (rtNaN);
    c[2] = (rtNaN);
    c[3] = (rtNaN);
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros_fe_log2(real_T x)
{
  real_T f;
  int32_T inte;
  if (x == 0.0) {
    f = (rtMinusInf);
  } else if (x < 0.0) {
    f = (rtNaN);
  } else if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    real_T t;
    t = frexp(x, &inte);
    if (t == 0.5) {
      f = static_cast<real_T>(inte) - 1.0;
    } else if ((inte == 1) && (t < 0.75)) {
      f = log(2.0 * t) / 0.69314718055994529;
    } else {
      f = log(t) / 0.69314718055994529 + static_cast<real_T>(inte);
    }
  } else {
    f = x;
  }

  return f;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_c_getExpmParams(const real_T A[4], real_T A2[4],
  real_T A4[4], real_T A6[4], int32_T *m, real_T *s)
{
  int32_T A2_tmp;
  int32_T b_s;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  *s = 0.0;
  for (int32_T i = 0; i < 2; i++) {
    A2_tmp = i << 1;
    A2[A2_tmp] = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o = A[A2_tmp];
    A2[A2_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o * A[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = A[A2_tmp + 1];
    A2[A2_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o * A[2];
    A2[A2_tmp + 1] = 0.0;
    A2[A2_tmp + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o * A[1];
    A2[A2_tmp + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o * A[3];
  }

  for (int32_T i = 0; i < 2; i++) {
    A4[i] = 0.0;
    A4[i] += A2[i] * A2[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = A2[i + 2];
    A4[i] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp * A2[1];
    A4[i + 2] = 0.0;
    A4[i + 2] += A2[i] * A2[2];
    A4[i + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp * A2[3];
    A6[i] = 0.0;
    A6[i] += A4[i] * A2[0];
    A6[i] += A4[i + 2] * A2[1];
    A6[i + 2] = 0.0;
    A6[i + 2] += A4[i] * A2[2];
    A6[i + 2] += A4[i + 2] * A2[3];
  }

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o = rt_powd_snf
    (ctrl_TT_ad_ctrl_cpp_ros_fe_norm(A6), 0.16666666666666666);
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = rt_powd_snf
    (ctrl_TT_ad_ctrl_cpp_ros_fe_norm(A4), 0.25);
  if ((!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o >=
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o)) && (!rtIsNaN
       (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o))) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o;
  }

  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o <= 0.01495585217958292) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[0] = 0.19285012468241128 * fabs(A[0]);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[1] = 0.19285012468241128 * fabs(A[1]);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[2] = 0.19285012468241128 * fabs(A[2]);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[3] = 0.19285012468241128 * fabs(A[3]);
    ctrl_TT_ad_ctrl_cpp_ros__mpower(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l, 7.0,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = ceil
      (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_fe_norm
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5) / ctrl_TT_ad_ctrl_cpp_ros_fe_norm
        (A) * 2.0 / 2.2204460492503131E-16) / 6.0);
    if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp >= 0.0)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = 0.0;
    }

    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp == 0.0) {
      *m = 3;
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4) {
    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o <= 0.253939833006323) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[0] = 0.12321872304378752 * fabs(A[0]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[1] = 0.12321872304378752 * fabs(A[1]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[2] = 0.12321872304378752 * fabs(A[2]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[3] = 0.12321872304378752 * fabs(A[3]);
      ctrl_TT_ad_ctrl_cpp_ros__mpower(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l, 11.0,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = ceil
        (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_fe_norm
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5) /
          ctrl_TT_ad_ctrl_cpp_ros_fe_norm(A) * 2.0 / 2.2204460492503131E-16) /
         10.0);
      if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp >= 0.0)) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = 0.0;
      }

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp == 0.0) {
        *m = 5;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }

  if (guard3) {
    ctrl_TT_ad_ctrl_cpp_ros__mpower(A4, 2.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = rt_powd_snf
      (ctrl_TT_ad_ctrl_cpp_ros_fe_norm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5),
       0.125);
    if ((!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o >=
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o)) && (!rtIsNaN
         (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o))) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o;
    }

    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o <= 0.95041789961629319) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[0] = 0.090475336558796943 * fabs(A[0]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[1] = 0.090475336558796943 * fabs(A[1]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[2] = 0.090475336558796943 * fabs(A[2]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[3] = 0.090475336558796943 * fabs(A[3]);
      ctrl_TT_ad_ctrl_cpp_ros__mpower(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l, 15.0,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = ceil
        (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_fe_norm
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5) /
          ctrl_TT_ad_ctrl_cpp_ros_fe_norm(A) * 2.0 / 2.2204460492503131E-16) /
         14.0);
      if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp >= 0.0)) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = 0.0;
      }

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp == 0.0) {
        *m = 7;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
  }

  if (guard2) {
    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o <= 2.097847961257068) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[0] = 0.071467735648795785 * fabs(A[0]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[1] = 0.071467735648795785 * fabs(A[1]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[2] = 0.071467735648795785 * fabs(A[2]);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[3] = 0.071467735648795785 * fabs(A[3]);
      ctrl_TT_ad_ctrl_cpp_ros__mpower(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l, 19.0,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = ceil
        (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_fe_norm
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5) /
          ctrl_TT_ad_ctrl_cpp_ros_fe_norm(A) * 2.0 / 2.2204460492503131E-16) /
         18.0);
      if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp >= 0.0)) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = 0.0;
      }

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp == 0.0) {
        *m = 9;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (int32_T i = 0; i < 2; i++) {
      A2_tmp = i << 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[A2_tmp] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = A6[A2_tmp];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[A2_tmp] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp * A4[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp_i = A6[A2_tmp + 1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[A2_tmp] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp_i * A4[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[A2_tmp + 1] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[A2_tmp + 1] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp * A4[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[A2_tmp + 1] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp_i * A4[3];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = rt_powd_snf
      (ctrl_TT_ad_ctrl_cpp_ros_fe_norm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l),
       0.1);
    if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o >=
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp) || rtIsNaN
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o;
    }

    if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o <=
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp) || rtIsNaN
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = ceil
      (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp /
        5.3719203511481517));
    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp >= 0.0) {
      *s = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o = rt_powd_snf(2.0, *s);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = A[0] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[0] = 0.05031554467093536 * fabs
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T_b[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = A[1] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[1] = 0.05031554467093536 * fabs
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T_b[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = A[2] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[2] = 0.05031554467093536 * fabs
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T_b[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o = A[3] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l[3] = 0.05031554467093536 * fabs
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T_b[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1_o;
    ctrl_TT_ad_ctrl_cpp_ros__mpower(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_l, 27.0,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = ceil
      (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_fe_norm
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv5) / ctrl_TT_ad_ctrl_cpp_ros_fe_norm
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.T_b) * 2.0 / 2.2204460492503131E-16) /
       26.0);
    if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp >= 0.0)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp = 0.0;
    }

    *s += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_tmp;
    if (rtIsInf(*s)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o = ctrl_TT_ad_ctrl_cpp_ros_fe_norm(A) /
        5.3719203511481517;
      if ((!rtIsInf(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o)) && (!rtIsNaN
           (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o))) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o = frexp
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o, &b_s);
      } else {
        b_s = 0;
      }

      *s = b_s;
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6_o == 0.5) {
        *s = static_cast<real_T>(b_s) - 1.0;
      }
    }

    *m = 13;
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_c_recomputeBlockDiag(const real_T A[4], real_T F[4],
  int32_T blockFormat)
{
  switch (blockFormat) {
   case 0:
    break;

   case 1:
    {
      real_T avg;
      real_T expa11;
      real_T expa22;
      real_T u1;
      expa11 = exp(A[0]);
      expa22 = exp(A[3]);
      avg = (A[0] + A[3]) / 2.0;
      u1 = fabs(A[0] - A[3]) / 2.0;
      if ((avg >= u1) || rtIsNaN(u1)) {
        u1 = avg;
      }

      if (u1 < 709.782712893384) {
        u1 = (A[3] - A[0]) / 2.0;
        if (u1 == 0.0) {
          u1 = 1.0;
        } else {
          u1 = sinh(u1) / u1;
        }

        F[2] = A[2] * exp(avg) * u1;
      } else {
        F[2] = (expa22 - expa11) * A[2] / (A[3] - A[0]);
      }

      F[0] = expa11;
      F[3] = expa22;
    }
    break;

   case 2:
    {
      real_T avg;
      real_T expa11;
      real_T expa22;
      expa11 = sqrt(fabs(A[1] * A[2]));
      expa22 = exp(A[0]);
      if (expa11 == 0.0) {
        avg = 1.0;
      } else {
        avg = sin(expa11) / expa11;
      }

      F[0] = expa22 * cos(expa11);
      F[1] = expa22 * A[1] * avg;
      F[2] = expa22 * A[2] * avg;
      F[3] = F[0];
    }
    break;
  }

  if (blockFormat == 0) {
    F[3] = exp(A[3]);
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros__xgehrd(void)
{
  return 0.0;
}

static real_T ctrl_TT_ad_ctrl_c_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a = fabs(u0);
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b = fabs(u1);
  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a < ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b;
    y = sqrt(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a *
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a + 1.0) *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b;
  } else if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a >
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a;
    y = sqrt(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b *
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b + 1.0) *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a;
  } else if (rtIsNaN(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b)) {
    y = (rtNaN);
  } else {
    y = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros_xdlanv2(real_T *a, real_T *b, real_T *c,
  real_T *d, real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs,
  real_T *sn)
{
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = *d;
    *d = *a;
    *a = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
    *b = -*c;
    *c = 0.0;
  } else {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = *a - *d;
    if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp == 0.0) && ((*b < 0.0) != (*c <
          0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      int32_T count;
      int32_T tmp;
      boolean_T tmp_0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p = 0.5 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = fabs(*b);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis = fabs(*c);
      tmp_0 = rtIsNaN(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis);
      if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale >=
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis) || tmp_0) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale;
      } else {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis;
      }

      if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale <=
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis) || tmp_0) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale;
      }

      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }

      if (!(*c < 0.0)) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis * static_cast<real_T>(count) *
        static_cast<real_T>(tmp);
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = fabs
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p);
      if ((!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale >=
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax)) && (!rtIsNaN
           (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax))) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
      }

      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p /
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax /
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis;
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z >= 8.8817841970012523E-16) {
        if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p < 0.0)) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = sqrt
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale) * sqrt
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z);
        } else {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = -(sqrt
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale) * sqrt
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z));
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
        *a = *d + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z;
        *d -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = ctrl_TT_ad_ctrl_c_rt_hypotd_snf(*
          c, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z);
        *cs = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.z /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
        *sn = *c / ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p = *b + *c;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = fabs
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp);
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = fabs
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p);
        if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax >=
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale) || rtIsNaN
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale)) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
        }

        count = 0;
        while ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale >= 7.4428285367870146E+137)
               && (count <= 20)) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p *= 1.3435752215134178E-138;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp *= 1.3435752215134178E-138;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p);
          if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax >=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale) || rtIsNaN
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
          }

          count++;
        }

        while ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale <= 1.3435752215134178E-138)
               && (count <= 20)) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p *= 7.4428285367870146E+137;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp *= 7.4428285367870146E+137;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p);
          if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax >=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale) || rtIsNaN
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
          }

          count++;
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = ctrl_TT_ad_ctrl_c_rt_hypotd_snf
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p,
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp);
        *cs = sqrt((fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p) /
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax + 1.0) * 0.5);
        if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }

        *sn = -(0.5 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp /
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax * *cs)) *
          static_cast<real_T>(count);
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = *a * *cs + *b * *sn;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p = -*a * *sn + *b * *cs;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = *c * *cs + *d * *sn;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = -*c * *sn + *d * *cs;
        *b = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p * *cs +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale * *sn;
        *c = -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp * *sn +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax * *cs;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp =
          ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp * *cs +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax * *sn) +
           (-ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p * *sn +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale * *cs)) * 0.5;
        *a = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
        *d = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis = sqrt(fabs(*b));
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale = sqrt(fabs(*c));
              if (!(*c < 0.0)) {
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p =
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale;
              } else {
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p =
                  -(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis *
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale);
              }

              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p;
              *d = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p;
              *b -= *c;
              *c = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmis *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax *=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = *cs *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p - *sn *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax;
              *sn = *cs * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.bcmax + *sn *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.p;
              *cs = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp = *cs;
            *cs = -*sn;
            *sn = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static int32_T ctrl_TT_ad_ctrl_cpp_ros__xhseqr(real_T h[4], real_T z[4])
{
  real_T a__4;
  int32_T info;
  int32_T k;
  info = 0;
  for (int32_T i = 1; i + 1 >= 1; i = k - 2) {
    boolean_T exitg1;
    k = i + 1;
    exitg1 = false;
    while ((!exitg1) && (k > 1)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p = fabs(h[1]);
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p <= 2.0041683600089728E-292) {
        exitg1 = true;
      } else {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o = fabs(h[3]);
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p <= (fabs(h[0]) +
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o) * 2.2204460492503131E-16) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f = fabs(h[1]);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2 = fabs(h[2]);
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f >
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2 = fabs(h[0] - h[3]);
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o >
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2 =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f * 2.2204460492503131E-16;
          if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f <=
               2.0041683600089728E-292) || rtIsNaN
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f = 2.0041683600089728E-292;
          }

          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p /
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e <=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f) {
            exitg1 = true;
          } else {
            k = 1;
          }
        } else {
          k = 1;
        }
      }
    }

    if (k > 1) {
      h[1] = 0.0;
    }

    if ((i + 1 != k) && (k == i)) {
      int32_T b_tmp;
      int32_T b_tmp_tmp;
      int32_T c_tmp;
      int32_T c_tmp_tmp;
      b_tmp_tmp = i << 1;
      b_tmp = b_tmp_tmp + i;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f = h[b_tmp - 1];
      c_tmp_tmp = (i - 1) << 1;
      c_tmp = c_tmp_tmp + i;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o = h[c_tmp];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2 = h[b_tmp];
      ctrl_TT_ad_ctrl_cpp_ros_xdlanv2(&h[(i + ((i - 1) << 1)) - 1],
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a__1,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a__2,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a__3_h, &a__4,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p,
        &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e);
      h[b_tmp - 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f;
      h[c_tmp] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o;
      h[b_tmp] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp2;
      if (i + 1 < 2) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p * h[1] +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e * h[2];
        h[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p * h[2] -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e * h[1];
        h[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f;
      }

      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p * z[c_tmp_tmp] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e * z[b_tmp_tmp];
      z[b_tmp_tmp] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p * z[b_tmp_tmp] -
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e * z[c_tmp_tmp];
      z[c_tmp_tmp] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f = z[b_tmp_tmp + 1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o = z[c_tmp_tmp + 1];
      z[b_tmp_tmp + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p -
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e;
      z[c_tmp_tmp + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa_o *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab_p +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1_f *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba_e;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros_f_schur(const real_T A[4], real_T V[4],
  real_T T[4])
{
  boolean_T p;
  p = true;
  if (rtIsInf(A[0]) || rtIsNaN(A[0])) {
    p = false;
  }

  if (p && (rtIsInf(A[1]) || rtIsNaN(A[1]))) {
    p = false;
  }

  if (p && (rtIsInf(A[2]) || rtIsNaN(A[2]))) {
    p = false;
  }

  if (p && (rtIsInf(A[3]) || rtIsNaN(A[3]))) {
    p = false;
  }

  if (!p) {
    V[0] = (rtNaN);
    V[2] = (rtNaN);
    V[3] = (rtNaN);
    V[1] = 0.0;
    T[0] = (rtNaN);
    T[1] = (rtNaN);
    T[2] = (rtNaN);
    T[3] = (rtNaN);
  } else {
    T[0] = A[0];
    T[1] = A[1];
    T[2] = A[2];
    T[3] = A[3];
    V[2] = 0.0;
    V[1] = 0.0;
    V[0] = 1.0;
    V[3] = 1.0 - ctrl_TT_ad_ctrl_cpp_ros__xgehrd();
    ctrl_TT_ad_ctrl_cpp_ros__xhseqr(T, V);
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros_fe_expm(real_T A[4], real_T F[4])
{
  int32_T r1;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  if (rtIsInf(A[0]) || rtIsNaN(A[0])) {
    recomputeDiags = false;
  }

  if (recomputeDiags && (rtIsInf(A[1]) || rtIsNaN(A[1]))) {
    recomputeDiags = false;
  }

  if (recomputeDiags && (rtIsInf(A[2]) || rtIsNaN(A[2]))) {
    recomputeDiags = false;
  }

  if (recomputeDiags && (rtIsInf(A[3]) || rtIsNaN(A[3]))) {
    recomputeDiags = false;
  }

  if (!recomputeDiags) {
    F[0] = (rtNaN);
    F[1] = (rtNaN);
    F[2] = (rtNaN);
    F[3] = (rtNaN);
  } else {
    int32_T blockFormat;
    int32_T exitg1;
    boolean_T exitg2;
    recomputeDiags = true;
    blockFormat = 0;
    exitg2 = false;
    while ((!exitg2) && (blockFormat < 2)) {
      r1 = 0;
      do {
        exitg1 = 0;
        if (r1 < 2) {
          if ((r1 != blockFormat) && (!(A[(blockFormat << 1) + r1] == 0.0))) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            r1++;
          }
        } else {
          blockFormat++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (recomputeDiags) {
      F[1] = 0.0;
      F[2] = 0.0;
      F[0] = exp(A[0]);
      F[3] = exp(A[3]);
    } else {
      recomputeDiags = true;
      blockFormat = 0;
      exitg2 = false;
      while ((!exitg2) && (blockFormat < 2)) {
        r1 = 0;
        do {
          exitg1 = 0;
          if (r1 <= blockFormat) {
            if (!(A[(blockFormat << 1) + r1] == A[(r1 << 1) + blockFormat])) {
              recomputeDiags = false;
              exitg1 = 1;
            } else {
              r1++;
            }
          } else {
            blockFormat++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (recomputeDiags) {
        ctrl_TT_ad_ctrl_cpp_ros_f_schur(A, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d);
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a = exp
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0]);
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0] =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1] =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a = exp
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3]);
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2] =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3] =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a;
        for (r1 = 0; r1 < 2; r1++) {
          F[r1] = 0.0;
          F[r1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1 + 2];
          F[r1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2];
          F[r1 + 2] = 0.0;
          F[r1 + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1];
          F[r1 + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3];
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a = (F[1] + F[2]) / 2.0;
        F[3] = (F[3] + F[3]) / 2.0;
        F[0] = (F[0] + F[0]) / 2.0;
        F[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a;
        F[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a;
      } else {
        int32_T r2;
        recomputeDiags = true;
        if (A[1] != 0.0) {
          if (rtIsNaN(A[1])) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a = (rtNaN);
          } else if (A[1] < 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a = -1.0;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a = (A[1] > 0.0);
          }

          if (rtIsNaN(A[2])) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = (rtNaN);
          } else if (A[2] < 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = -1.0;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = (A[2] > 0.0);
          }

          recomputeDiags = ((!(A[0] != A[3])) &&
                            (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a *
                               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d != -1.0)));
        }

        ctrl_TT_ad_ctrl_c_getExpmParams(A, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l, &r1,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a);
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a != 0.0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = rt_powd_snf(2.0,
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y = rt_powd_snf(2.0, 2.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l = rt_powd_snf(2.0, 4.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i = rt_powd_snf(2.0, 6.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a);
          A[0] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i;
          A[1] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i;
          A[2] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i;
          A[3] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i;
        }

        if (recomputeDiags) {
          if (A[1] == 0.0) {
            blockFormat = 1;
          } else {
            blockFormat = 2;
          }
        }

        switch (r1) {
         case 3:
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0] + 60.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3] + 60.0;
          for (r1 = 0; r1 < 2; r1++) {
            r2 = r1 << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] = 12.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1] = 12.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2] = 12.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] = 12.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = 120.0;
          break;

         case 5:
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] = 420.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] = 420.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] = 420.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] = 420.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] += 15120.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] += 15120.0;
          for (r1 = 0; r1 < 2; r1++) {
            r2 = r1 << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] = 30.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0] + 3360.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1] = 30.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1] + 3360.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2] = 30.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2] + 3360.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] = 30.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3] + 3360.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = 30240.0;
          break;

         case 7:
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] = (1512.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0]) + 277200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] = (1512.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1]) + 277200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] = (1512.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2]) + 277200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] = (1512.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3]) + 277200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] += 8.64864E+6;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] += 8.64864E+6;
          for (r1 = 0; r1 < 2; r1++) {
            r2 = r1 << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] = (56.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0] + 25200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0]) + 1.99584E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1] = (56.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1] + 25200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1]) + 1.99584E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2] = (56.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2] + 25200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2]) + 1.99584E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] = (56.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3] + 25200.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3]) + 1.99584E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = 1.729728E+7;
          break;

         case 9:
          for (r1 = 0; r1 < 2; r1++) {
            r2 = r1 << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[r2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[r2 + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2 + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] = ((3960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0]) + 2.16216E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0]) + 3.027024E+8 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] = ((3960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1]) + 2.16216E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1]) + 3.027024E+8 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] = ((3960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2]) + 2.16216E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2]) + 3.027024E+8 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] = ((3960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3]) + 2.16216E+6 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3]) + 3.027024E+8 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] += 8.8216128E+9;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] += 8.8216128E+9;
          for (r1 = 0; r1 < 2; r1++) {
            r2 = r1 << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d * A[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * A[3];
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] = ((90.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] + 110880.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0]) + 3.027024E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0]) + 2.0756736E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1] = ((90.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1] + 110880.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1]) + 3.027024E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1]) + 2.0756736E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2] = ((90.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2] + 110880.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2]) + 3.027024E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2]) + 2.0756736E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] = ((90.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] + 110880.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3]) + 3.027024E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3]) + 2.0756736E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = 1.76432256E+10;
          break;

         default:
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] = (3.352212864E+10 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0] + 1.05594705216E+13 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0]) + 1.1873537964288E+15 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] = (3.352212864E+10 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1] + 1.05594705216E+13 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1]) + 1.1873537964288E+15 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] = (3.352212864E+10 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2] + 1.05594705216E+13 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2]) + 1.1873537964288E+15 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] = (3.352212864E+10 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3] + 1.05594705216E+13 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3]) + 1.1873537964288E+15 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] += 3.238237626624E+16;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] += 3.238237626624E+16;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = (16380.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0]) + 4.08408E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y = (16380.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1]) + 4.08408E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l = (16380.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2]) + 4.08408E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i = (16380.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3]) + 4.08408E+7 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          for (r1 = 0; r1 < 2; r1++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1 + 2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r1] =
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp *
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y +
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1] *
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d) +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r1 + 2] =
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp *
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i +
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1] *
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l) +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r1 + 2];
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = (182.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[0] + 960960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0]) + 1.32324192E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y = (182.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[1] + 960960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1]) + 1.32324192E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l = (182.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[2] + 960960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2]) + 1.32324192E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[2];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i = (182.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[3] + 960960.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3]) + 1.32324192E+9 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[3];
          for (r1 = 0; r1 < 2; r1++) {
            r2 = r1 << 1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp * A[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_n[r2 + 1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_tmp * A[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp * A[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_tmp * A[3];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1 + 2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r1] =
              (((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp *
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y +
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1] *
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d) + 6.704425728E+11 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1]) + 1.29060195264E+14 *
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1]) + 7.7717703038976E+15 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[r1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r1 + 2] =
              (((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp *
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i +
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_l[r1] *
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l) +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_tmp * 6.704425728E+11) +
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1 + 2] * 1.29060195264E+14)
              + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2_d[r1 + 2] *
              7.7717703038976E+15;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d = 6.476475253248E+16;
          break;
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] =
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0] +
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d) -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[0] *= 2.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1] -=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[1] *= 2.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[2] -=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[2] *= 2.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] =
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[3] +
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d) -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[3] *= 2.0;
        if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[1]) > fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[0])) {
          r1 = 1;
          r2 = 0;
        } else {
          r1 = 0;
          r2 = 1;
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2] /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r1];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r1 + 2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r2 + 2] -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d;
        F[1] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2] -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r1] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d) /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l;
        F[0] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r1] -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * F[1]) /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r1];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i =
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r1 + 2];
        F[3] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U_o[r2 + 2] -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d) /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_l;
        F[2] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_y * F[3]) /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V_b[r1];
        F[0]++;
        F[3]++;
        if (recomputeDiags) {
          ctrl_TT_ad_c_recomputeBlockDiag(A, F, blockFormat);
        }

        r2 = static_cast<int32_T>(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj_a);
        for (int32_T k = 0; k < r2; k++) {
          for (r1 = 0; r1 < 2; r1++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1] += F[r1] * F[0];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i = F[r1 + 2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i * F[1];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1 + 2] = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1 + 2] += F[r1] * F[2];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[r1 + 2] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y_i * F[3];
          }

          F[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[0];
          F[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[1];
          F[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[2];
          F[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_d[3];
          if (recomputeDiags) {
            A[0] *= 2.0;
            A[1] *= 2.0;
            A[2] *= 2.0;
            A[3] *= 2.0;
            ctrl_TT_ad_c_recomputeBlockDiag(A, F, blockFormat);
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros__norm_b(const real_T x[9])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    real_T s;
    s = (fabs(x[3 * j + 1]) + fabs(x[3 * j])) + fabs(x[3 * j + 2]);
    if (rtIsNaN(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros__inv_jg(const real_T x[9], real_T y[9])
{
  int32_T p1;
  int32_T p2;
  int32_T p3;
  memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 = fabs(x[0]);
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 = fabs(x[1]);
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx31 = fabs(x[2]);
  if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 >
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11) &&
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 >
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx31)) {
    p1 = 3;
    p2 = 0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[0] = x[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[1] = x[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3] = x[4];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4] = x[3];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6] = x[7];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7] = x[6];
  } else if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx31 >
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11) {
    p1 = 6;
    p3 = 0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[0] = x[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[2] = x[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3] = x[5];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5] = x[3];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6] = x[8];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8] = x[6];
  }

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[1] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [0];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[2] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [0];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [2] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [2] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6];
  if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5]) > fabs
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11;
  }

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [4];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [5] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[5] -
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[2]) /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 =
    -(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 +
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[1]) /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4];
  y[p1] = ((1.0 - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21) -
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6] *
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11) /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[0];
  y[p1 + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21;
  y[p1 + 2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 = -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [5] / ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 = (1.0 -
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[7] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11) /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4];
  y[p2] = -(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11) /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[0];
  y[p2 + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21;
  y[p2 + 2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 = 1.0 /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[8];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 = -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x
    [7] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11 /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[4];
  y[p3] = -(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[3] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21 +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[6] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11) /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_x[0];
  y[p3 + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx21;
  y[p3 + 2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absx11;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ro_mpower_f(const real_T a[9], real_T b, real_T
  c[9])
{
  if (floor(b) == b) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e = fabs(b);
    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e <= 2.147483647E+9) {
      int32_T b_n;
      int32_T n;
      int32_T nb;
      int32_T nbitson;
      memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], &a[0], 9U * sizeof(real_T));
      n = static_cast<int32_T>(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e);
      b_n = n;
      nbitson = 0;
      nb = -2;
      while (b_n > 0) {
        nb++;
        if ((static_cast<uint32_T>(b_n) & 1U) != 0U) {
          nbitson++;
        }

        b_n >>= 1;
      }

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e <= 2.0) {
        if (b == 2.0) {
          for (b_n = 0; b_n < 3; b_n++) {
            for (nbitson = 0; nbitson < 3; nbitson++) {
              int32_T c_tmp;
              c_tmp = 3 * b_n + nbitson;
              c[c_tmp] = 0.0;
              c[c_tmp] += a[3 * b_n] * a[nbitson];
              c[c_tmp] += a[3 * b_n + 1] * a[nbitson + 3];
              c[c_tmp] += a[3 * b_n + 2] * a[nbitson + 6];
            }
          }
        } else if (b == 1.0) {
          memcpy(&c[0], &a[0], 9U * sizeof(real_T));
        } else if (b == -1.0) {
          ctrl_TT_ad_ctrl_cpp_ros__inv_jg(a, c);
        } else if (b == -2.0) {
          for (b_n = 0; b_n < 3; b_n++) {
            for (nbitson = 0; nbitson < 3; nbitson++) {
              n = 3 * b_n + nbitson;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] += a[3 * b_n] * a[nbitson];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] += a[3 * b_n + 1] *
                a[nbitson + 3];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] += a[3 * b_n + 2] *
                a[nbitson + 6];
            }
          }

          ctrl_TT_ad_ctrl_cpp_ros__inv_jg(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a, c);
        } else {
          boolean_T firstmult;
          firstmult = false;
          for (b_n = 0; b_n < 9; b_n++) {
            if (!firstmult) {
              firstmult = rtIsNaN(a[b_n]);
            }
          }

          if (firstmult) {
            for (b_n = 0; b_n < 9; b_n++) {
              c[b_n] = (rtNaN);
            }
          } else {
            memset(&c[0], 0, 9U * sizeof(real_T));
            c[0] = 1.0;
            c[4] = 1.0;
            c[8] = 1.0;
          }
        }
      } else {
        int32_T c_tmp;
        boolean_T aBufferInUse;
        boolean_T firstmult;
        boolean_T lsb;
        firstmult = true;
        aBufferInUse = false;
        lsb = ((static_cast<uint32_T>(nbitson) & 1U) != 0U);
        lsb = ((lsb && (b < 0.0)) || ((!lsb) && (b >= 0.0)));
        for (int32_T k = 0; k <= nb; k++) {
          if ((static_cast<uint32_T>(n) & 1U) != 0U) {
            if (firstmult) {
              firstmult = false;
              if (lsb) {
                if (aBufferInUse) {
                  memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[0],
                         &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[0], 9U *
                         sizeof(real_T));
                } else {
                  memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[0],
                         &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], 9U * sizeof
                         (real_T));
                }
              } else if (aBufferInUse) {
                memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[0], 9U *
                       sizeof(real_T));
              } else {
                memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], 9U *
                       sizeof(real_T));
              }
            } else {
              if (aBufferInUse) {
                if (lsb) {
                  for (b_n = 0; b_n < 3; b_n++) {
                    for (nbitson = 0; nbitson < 3; nbitson++) {
                      c_tmp = 3 * nbitson + b_n;
                      c[c_tmp] = 0.0;
                      c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 *
                        nbitson] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[b_n];
                      c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 *
                        nbitson + 1] *
                        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[b_n + 3];
                      c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 *
                        nbitson + 2] *
                        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[b_n + 6];
                    }
                  }
                } else {
                  for (b_n = 0; b_n < 3; b_n++) {
                    for (nbitson = 0; nbitson < 3; nbitson++) {
                      c_tmp = 3 * nbitson + b_n;
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] = 0.0;
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * nbitson] *
                        c[b_n];
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * nbitson + 1]
                        * c[b_n + 3];
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * nbitson + 2]
                        * c[b_n + 6];
                    }
                  }
                }
              } else if (lsb) {
                for (b_n = 0; b_n < 3; b_n++) {
                  for (nbitson = 0; nbitson < 3; nbitson++) {
                    c_tmp = 3 * nbitson + b_n;
                    c[c_tmp] = 0.0;
                    c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson]
                      * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[b_n];
                    c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson
                      + 1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[b_n + 3];
                    c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson
                      + 2] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[b_n + 6];
                  }
                }
              } else {
                for (b_n = 0; b_n < 3; b_n++) {
                  for (nbitson = 0; nbitson < 3; nbitson++) {
                    c_tmp = 3 * nbitson + b_n;
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] = 0.0;
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson] * c[b_n];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 1] *
                      c[b_n + 3];
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 2] *
                      c[b_n + 6];
                  }
                }
              }

              lsb = !lsb;
            }
          }

          n >>= 1;
          if (aBufferInUse) {
            for (b_n = 0; b_n < 3; b_n++) {
              for (nbitson = 0; nbitson < 3; nbitson++) {
                c_tmp = 3 * nbitson + b_n;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[c_tmp] = 0.0;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * nbitson] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[b_n];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * nbitson + 1] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[b_n + 3];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * nbitson + 2] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[b_n + 6];
              }
            }
          } else {
            for (b_n = 0; b_n < 3; b_n++) {
              for (nbitson = 0; nbitson < 3; nbitson++) {
                c_tmp = 3 * nbitson + b_n;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] = 0.0;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[b_n];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 1] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[b_n + 3];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 2] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[b_n + 6];
              }
            }
          }

          aBufferInUse = !aBufferInUse;
        }

        if (firstmult) {
          if (b < 0.0) {
            if (aBufferInUse) {
              ctrl_TT_ad_ctrl_cpp_ros__inv_jg
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer, c);
            } else {
              ctrl_TT_ad_ctrl_cpp_ros__inv_jg
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a, c);
            }
          } else if (aBufferInUse) {
            memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[0], 9U *
                   sizeof(real_T));
          } else {
            memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], 9U * sizeof
                   (real_T));
          }
        } else if (b < 0.0) {
          for (b_n = 0; b_n < 3; b_n++) {
            for (nbitson = 0; nbitson < 3; nbitson++) {
              c_tmp = 3 * b_n + nbitson;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e = c[nbitson];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e = c[nbitson + 3];
              n = 3 * b_n + 1;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e = c[nbitson + 6];
              n = 3 * b_n + 2;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
            }
          }

          if (aBufferInUse) {
            memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0],
                   &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[0], 9U * sizeof
                   (real_T));
          } else {
            memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0],
                   &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[0], 9U * sizeof
                   (real_T));
          }

          ctrl_TT_ad_ctrl_cpp_ros__inv_jg(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a, c);
        } else {
          for (b_n = 0; b_n < 3; b_n++) {
            for (nbitson = 0; nbitson < 3; nbitson++) {
              c_tmp = 3 * b_n + nbitson;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] = 0.0;
              c[c_tmp] = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[nbitson];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[3 * b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * b_n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[nbitson + 3];
              n = 3 * b_n + 1;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[nbitson + 6];
              n = 3 * b_n + 2;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[c_tmp] +=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
              c[c_tmp] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[n] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e;
            }
          }

          if (aBufferInUse) {
            memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer_c[0], 9U *
                   sizeof(real_T));
          }
        }
      }
    } else {
      memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], &a[0], 9U * sizeof(real_T));
      if (!rtIsInf(b)) {
        boolean_T firstmult;
        firstmult = true;
        int32_T exitg1;
        do {
          int32_T c_tmp;
          exitg1 = 0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2 = floor
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e / 2.0);
          if (2.0 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2 !=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e) {
            if (firstmult) {
              memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], 9U * sizeof
                     (real_T));
              firstmult = false;
            } else {
              for (int32_T b_n = 0; b_n < 3; b_n++) {
                for (int32_T nbitson = 0; nbitson < 3; nbitson++) {
                  c_tmp = 3 * nbitson + b_n;
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] = 0.0;
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson] * c[b_n];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 1] * c[b_n
                    + 3];
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[c_tmp] +=
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 2] * c[b_n
                    + 6];
                }
              }

              memcpy(&c[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.cBuffer[0], 9U *
                     sizeof(real_T));
            }
          }

          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2 == 0.0) {
            exitg1 = 1;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.e =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ed2;
            for (int32_T b_n = 0; b_n < 3; b_n++) {
              for (int32_T nbitson = 0; nbitson < 3; nbitson++) {
                c_tmp = 3 * nbitson + b_n;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] = 0.0;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[b_n];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 1] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[b_n + 3];
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[c_tmp] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[3 * nbitson + 2] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[b_n + 6];
              }
            }

            memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0],
                   &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aBuffer[0], 9U * sizeof
                   (real_T));
          }
        } while (exitg1 == 0);

        if (b < 0.0) {
          memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a[0], &c[0], 9U * sizeof
                 (real_T));
          ctrl_TT_ad_ctrl_cpp_ros__inv_jg(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_a, c);
        }
      } else {
        for (int32_T b_n = 0; b_n < 9; b_n++) {
          c[b_n] = (rtNaN);
        }
      }
    }
  } else {
    for (int32_T b_n = 0; b_n < 9; b_n++) {
      c[b_n] = (rtNaN);
    }
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ct_padeApproximation(const real_T A[9], const real_T A2[9],
  const real_T A4[9], const real_T A6[9], int32_T m, real_T F[9])
{
  real_T F_tmp;
  real_T F_tmp_0;
  real_T F_tmp_1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  switch (m) {
   case 3:
    memcpy(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[0], &A2[0], 9U * sizeof(real_T));
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[0] += 60.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[4] += 60.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[8] += 60.0;
    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r1 + r2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] = 0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1] * A[r2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 1] * A[r2 + 3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 2] * A[r2 + 6];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] = 12.0 * A2[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = 120.0;
    break;

   case 5:
    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] = 420.0 * A2[r1] + A4[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[0] += 15120.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[4] += 15120.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[8] += 15120.0;
    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r1 + r2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] = 0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1] * A[r2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 1] * A[r2 + 3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 2] * A[r2 + 6];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] = 30.0 * A4[r1] + 3360.0 * A2[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = 30240.0;
    break;

   case 7:
    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] = (1512.0 * A4[r1] + A6[r1]) +
        277200.0 * A2[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[0] += 8.64864E+6;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[4] += 8.64864E+6;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[8] += 8.64864E+6;
    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r1 + r2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] = 0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1] * A[r2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 1] * A[r2 + 3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 2] * A[r2 + 6];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] = (56.0 * A6[r1] + 25200.0 * A4[r1])
        + 1.99584E+6 * A2[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = 1.729728E+7;
    break;

   case 9:
    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r1 + r2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3] = 0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3] += A2[3 * r1] * A6[r2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3] += A2[3 * r1 + 1] * A6[r2 + 3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3] += A2[3 * r1 + 2] * A6[r2 + 6];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] = ((3960.0 * A6[r1] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1]) + 2.16216E+6 * A4[r1]) +
        3.027024E+8 * A2[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[0] += 8.8216128E+9;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[4] += 8.8216128E+9;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[8] += 8.8216128E+9;
    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r1 + r2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] = 0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1] * A[r2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 1] * A[r2 + 3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[3 * r1 + 2] * A[r2 + 6];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] = ((90.0 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] + 110880.0 * A6[r1]) + 3.027024E+7
        * A4[r1]) + 2.0756736E+9 * A2[r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = 1.76432256E+10;
    break;

   default:
    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = A2[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21 = A4[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h = A6[r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] = (3.352212864E+10 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h + 1.05594705216E+13 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21) + 1.1873537964288E+15 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] = (16380.0 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21 +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h) + 4.08408E+7 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[0] += 3.238237626624E+16;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[4] += 3.238237626624E+16;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[8] += 3.238237626624E+16;
    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r2 + r1;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r3] =
          ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[3 * r2 + 1] * A6[r1 + 3] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[3 * r2] * A6[r1]) +
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[3 * r2 + 2] * A6[r1 + 6]) +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3];
      }
    }

    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r1 + r2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3] = 0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[3 * r1] * A[r2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[3 * r1 + 1] * A[r2 + 3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[3 * r1 + 2] * A[r2 + 6];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[r1] = (182.0 * A6[r1] + 960960.0 *
        A4[r1]) + 1.32324192E+9 * A2[r1];
    }

    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r2 + r1;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3] =
          ((((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[3 * r2 + 1] * A6[r1 + 3] +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[3 * r2] * A6[r1]) +
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_p[3 * r2 + 2] * A6[r1 + 6]) +
            A6[r3] * 6.704425728E+11) + A4[r3] * 1.29060195264E+14) + A2[r3] *
          7.7717703038976E+15;
      }
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = 6.476475253248E+16;
    break;
  }

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[0] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[4] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[8] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
  for (r1 = 0; r1 < 9; r1++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1] -=
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1] = 2.0 *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5;
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V
    [0]);
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21 = fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[1]);
  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21 > ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5)
  {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[2]) >
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 3] -=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1 + 3] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 3] -=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1 + 3] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 6] -=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1 + 6] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 6] -=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1 + 6] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3];
  if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 3]) > fabs
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 3] /=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 3];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 6] -=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 3] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 6];
  F[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1];
  F[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r2] - F[0] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 +
    3];
  F[2] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3] - F[0] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3]) -
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 * F[1];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3 + 6];
  F[2] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1 +
    6];
  F[0] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h * F[2];
  F_tmp = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 6];
  F[1] -= F_tmp * F[2];
  F_tmp_0 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2 + 3];
  F[1] /= F_tmp_0;
  F_tmp_1 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1 + 3];
  F[0] -= F_tmp_1 * F[1];
  F[0] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1];
  F[3] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1 + 3];
  F[4] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r2 + 3] - F[3] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2];
  F[5] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3 + 3] - F[3] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3]) -
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 * F[4];
  F[5] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21;
  F[3] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h * F[5];
  F[4] -= F_tmp * F[5];
  F[4] /= F_tmp_0;
  F[3] -= F_tmp_1 * F[4];
  F[3] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1];
  F[6] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r1 + 6];
  F[7] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r2 + 6] - F[6] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r2];
  F[8] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.U[r3 + 6] - F[6] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r3]) -
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_l5 * F[7];
  F[8] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a21;
  F[6] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6_h * F[8];
  F[7] -= F_tmp * F[8];
  F[7] /= F_tmp_0;
  F[6] -= F_tmp_1 * F[7];
  F[6] /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.V[r1];
  F[0]++;
  F[4]++;
  F[8]++;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_recomputeBlockDiag_b(const real_T A[9], real_T F[9],
  const int32_T blockFormat[2])
{
  real_T avg;
  real_T expa11;
  real_T expa22;
  real_T u1;
  switch (blockFormat[0]) {
   case 0:
    break;

   case 1:
    expa11 = exp(A[0]);
    expa22 = exp(A[4]);
    avg = (A[0] + A[4]) / 2.0;
    u1 = fabs(A[0] - A[4]) / 2.0;
    if ((avg >= u1) || rtIsNaN(u1)) {
      u1 = avg;
    }

    if (u1 < 709.782712893384) {
      u1 = (A[4] - A[0]) / 2.0;
      if (u1 == 0.0) {
        u1 = 1.0;
      } else {
        u1 = sinh(u1) / u1;
      }

      avg = A[3] * exp(avg) * u1;
    } else {
      avg = (expa22 - expa11) * A[3] / (A[4] - A[0]);
    }

    F[0] = expa11;
    F[3] = avg;
    F[4] = expa22;
    break;

   case 2:
    expa11 = sqrt(fabs(A[1] * A[3]));
    expa22 = exp(A[0]);
    if (expa11 == 0.0) {
      avg = 1.0;
    } else {
      avg = sin(expa11) / expa11;
    }

    F[0] = expa22 * cos(expa11);
    F[1] = expa22 * A[1] * avg;
    F[3] = expa22 * A[3] * avg;
    F[4] = F[0];
    break;
  }

  switch (blockFormat[1]) {
   case 0:
    break;

   case 1:
    expa11 = exp(A[4]);
    expa22 = exp(A[8]);
    avg = (A[4] + A[8]) / 2.0;
    u1 = fabs(A[4] - A[8]) / 2.0;
    if ((avg >= u1) || rtIsNaN(u1)) {
      u1 = avg;
    }

    if (u1 < 709.782712893384) {
      u1 = (A[8] - A[4]) / 2.0;
      if (u1 == 0.0) {
        u1 = 1.0;
      } else {
        u1 = sinh(u1) / u1;
      }

      avg = A[7] * exp(avg) * u1;
    } else {
      avg = (expa22 - expa11) * A[7] / (A[8] - A[4]);
    }

    F[4] = expa11;
    F[7] = avg;
    F[8] = expa22;
    break;

   case 2:
    expa11 = sqrt(fabs(A[5] * A[7]));
    expa22 = exp(A[4]);
    if (expa11 == 0.0) {
      avg = 1.0;
    } else {
      avg = sin(expa11) / expa11;
    }

    F[4] = expa22 * cos(expa11);
    F[5] = expa22 * A[5] * avg;
    F[7] = expa22 * A[7] * avg;
    F[8] = F[4];
    break;
  }

  if (blockFormat[1] == 0) {
    F[8] = exp(A[8]);
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros_xnrm2_l(int32_T n, const real_T x[9],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros__xzlarf(int32_T m, int32_T n, int32_T iv0,
  real_T tau, real_T C[9], int32_T ic0, real_T work[3])
{
  int32_T b_ia;
  int32_T coltop;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = (lastc - 1) * 3 + ic0;
      b_ia = coltop;
      do {
        exitg1 = 0;
        if (b_ia <= (coltop + lastv) - 1) {
          if (C[b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    lastc--;
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T jA;
    if (lastc + 1 != 0) {
      if (lastc >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof(real_T));
      }

      jA = 3 * lastc + ic0;
      for (coltop = ic0; coltop <= jA; coltop += 3) {
        c = 0.0;
        d = coltop + lastv;
        for (b_ia = coltop; b_ia < d; b_ia++) {
          c += C[((iv0 + b_ia) - coltop) - 1] * C[b_ia - 1];
        }

        b_ia = div_nzp_s32_floor(coltop - ic0, 3);
        work[b_ia] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      for (coltop = 0; coltop <= lastc; coltop++) {
        if (work[coltop] != 0.0) {
          c = work[coltop] * -tau;
          d = lastv + jA;
          for (b_ia = jA; b_ia < d; b_ia++) {
            C[b_ia - 1] += C[((iv0 + b_ia) - jA) - 1] * c;
          }
        }

        jA += 3;
      }
    }
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros_f_xnrm2(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale_c = 3.3121686421112381E-170;
      for (int32_T k = 2; k <= n + 1; k++) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absxk = fabs(x[k - 1]);
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absxk >
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale_c) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.t =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale_c /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absxk;
          y = y * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.t *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.t + 1.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale_c =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absxk;
        } else {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.t =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.absxk /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale_c;
          y += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.t *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.t;
        }
      }

      y = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.scale_c * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static real_T ctrl_TT_ad_ctrl_cpp_ros_xzlarfg(int32_T n, real_T *alpha1, real_T
  x[3])
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm = ctrl_TT_ad_ctrl_cpp_ros_f_xnrm2(n -
      1, x);
    if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm != 0.0) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm = ctrl_TT_ad_ctrl_c_rt_hypotd_snf
        (*alpha1, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm);
      if (*alpha1 >= 0.0) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm =
          -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm;
      }

      if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm) < 1.0020841800044864E-292)
      {
        int32_T knt;
        knt = 0;
        do {
          knt++;
          for (int32_T b_k = 2; b_k <= n; b_k++) {
            x[b_k - 1] *= 9.9792015476736E+291;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm) <
                  1.0020841800044864E-292) && (knt < 20));

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm = ctrl_TT_ad_ctrl_c_rt_hypotd_snf(*
          alpha1, ctrl_TT_ad_ctrl_cpp_ros_f_xnrm2(n - 1, x));
        if (*alpha1 >= 0.0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm =
            -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm;
        }

        tau = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm - *alpha1) /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_h = 1.0 / (*alpha1 -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm);
        for (int32_T b_k = 2; b_k <= n; b_k++) {
          x[b_k - 1] *= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_h;
        }

        for (int32_T b_k = 0; b_k < knt; b_k++) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm;
      } else {
        tau = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm - *alpha1) /
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_h = 1.0 / (*alpha1 -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm);
        for (int32_T knt = 2; knt <= n; knt++) {
          x[knt - 1] *= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a_h;
        }

        *alpha1 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros_fe_xrot(int32_T n, real_T x[9], int32_T ix0,
  int32_T iy0, real_T c, real_T s)
{
  if (n >= 1) {
    for (int32_T k = 0; k < n; k++) {
      int32_T temp_tmp;
      int32_T temp_tmp_0;
      temp_tmp = (iy0 + k) - 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp_tmp = x[temp_tmp];
      temp_tmp_0 = (ix0 + k) - 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp_tmp_a = x[temp_tmp_0];
      x[temp_tmp] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp_tmp * c -
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp_tmp_a * s;
      x[temp_tmp_0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp_tmp_a * c +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.temp_tmp * s;
    }
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static int32_T ctrl_TT_ad_ctrl_cpp_ro_xhseqr_d(real_T h[9], real_T z[9])
{
  int32_T i;
  int32_T info;
  int32_T kdefl;
  boolean_T exitg1;
  info = 0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[0] = 0.0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[1] = 0.0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[2] = 0.0;
  h[2] = 0.0;
  kdefl = 0;
  i = 2;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T L;
    int32_T its;
    int32_T j;
    int32_T k;
    int32_T nr;
    boolean_T exitg2;
    boolean_T goto150;
    L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      boolean_T exitg3;
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        j = (k - 1) * 3 + k;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = fabs(h[j]);
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 <= 3.0062525400134592E-292) {
          exitg3 = true;
        } else {
          nr = 3 * k + k;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = fabs(h[j - 1]) + fabs(h[nr]);
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst == 0.0) {
            if (k - 1 >= 1) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = fabs(h[((k - 2) * 3 + k) - 1]);
            }

            if (k + 2 <= 3) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst += fabs(h[nr + 1]);
            }
          }

          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 <= 2.2204460492503131E-16 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = fabs(h[j]);
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = fabs(h[nr - 1]);
            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 >
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1;
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = h[nr];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = fabs
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst);
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = fabs(h[j - 1] -
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst);
            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 >
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa /
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 * 2.2204460492503131E-16;
            if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 <=
                 3.0062525400134592E-292) || rtIsNaN
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1)) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = 3.0062525400134592E-292;
            }

            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab /
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba <=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + 3 * (k - 1)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        kdefl++;
        if (kdefl - div_nzp_s32(kdefl, 20) * 20 == 0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = fabs(h[((i - 2) * 3 + i) - 1]) +
            fabs(h[(i - 1) * 3 + i]);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = h[3 * i + i] + 0.75 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 = -0.4375 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
        } else if (kdefl - div_nzp_s32(kdefl, 10) * 10 == 0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = fabs(h[1]) + fabs(h[5]);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = 0.75 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst + h[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 = -0.4375 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
        } else {
          k = (i - 1) * 3 + i;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = h[k - 1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = h[k];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 = h[(3 * i + i) - 1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab = h[3 * i + i];
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = ((fabs
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba) + fabs
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12)) + fabs
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa)) + fabs
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab);
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst == 0.0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = 0.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab = 0.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = 0.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = 0.0;
        } else {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 =
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba +
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab) / 2.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba -
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1) *
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab -
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1) -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst *
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa /
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = sqrt(fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba));
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba >= 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa =
              -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 -=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
            if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba -
                     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab) <= fabs
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 -
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab)) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1;
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = 0.0;
          }
        }

        if (i - 1 >= 1) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 = h[0] -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = (fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12) + fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa)) + fabs(h[1]);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h21s = h[1] /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[0] =
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 /
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst * (h[0] -
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba) +
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h21s * h[3]) -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[1] = (((h[0] + h[4]) -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba) -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1) *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h21s;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[2] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h21s * h[5];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = (fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[0]) + fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[1])) + fabs
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[2]);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[0] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[1] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[2] /=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
        }

        for (k = i - 1; k <= i; k++) {
          int32_T hoffset;
          nr = (i - k) + 2;
          if (nr >= 3) {
            nr = 3;
          }

          if (k > i - 1) {
            hoffset = ((k - 2) * 3 + k) - 1;
            for (j = 0; j < nr; j++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[j] = h[j + hoffset];
            }
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[0];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst = ctrl_TT_ad_ctrl_cpp_ros_xzlarfg
            (nr, &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab,
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[0] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
          if (k > i - 1) {
            h[(k + 3 * (k - 2)) - 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
            j = (k - 2) * 3 + k;
            h[j] = 0.0;
            if (k < i) {
              h[j + 1] = 0.0;
            }
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[1];
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[1];
          switch (nr) {
           case 3:
            {
              int32_T e;
              int32_T sum1_tmp;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[2];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12 =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.v[2];
              for (nr = k; nr < 4; nr++) {
                j = (nr - 1) * 3 + k;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = (h[j - 1] + h[j] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab) + h[j + 1] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
                h[j - 1] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
                h[j] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
                h[j + 1] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12;
              }

              if (k + 3 <= i + 1) {
                e = k + 3;
              } else {
                e = i + 1;
              }

              for (hoffset = 0; hoffset < e; hoffset++) {
                j = (k - 1) * 3 + hoffset;
                nr = 3 * k + hoffset;
                sum1_tmp = (k + 1) * 3 + hoffset;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = (h[nr] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab + h[j]) + h[sum1_tmp] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
                h[j] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
                h[nr] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
                h[sum1_tmp] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12;
              }

              for (hoffset = 0; hoffset < 3; hoffset++) {
                j = (k - 1) * 3 + hoffset;
                nr = 3 * k + hoffset;
                sum1_tmp = (k + 1) * 3 + hoffset;
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = (z[nr] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab + z[j]) + z[sum1_tmp] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
                z[j] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
                z[nr] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
                z[sum1_tmp] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12;
              }
            }
            break;

           case 2:
            for (nr = k; nr < 4; nr++) {
              j = (nr - 1) * 3 + k;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = h[j - 1];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = h[j] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
              h[j - 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
              h[j] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
            }

            for (hoffset = 0; hoffset <= i; hoffset++) {
              j = (k - 1) * 3 + hoffset;
              nr = 3 * k + hoffset;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = h[nr] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab + h[j];
              h[j] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
              h[nr] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
            }

            for (hoffset = 0; hoffset < 3; hoffset++) {
              j = (k - 1) * 3 + hoffset;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = z[j];
              nr = 3 * k + hoffset;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = z[nr] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
              z[j] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst;
              z[nr] -= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
            }
            break;
          }
        }

        its++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((i + 1 != L) && (L == i)) {
        its = 3 * i + i;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = h[its - 1];
        kdefl = (i - 1) * 3;
        k = kdefl + i;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = h[k];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa = h[its];
        ctrl_TT_ad_ctrl_cpp_ros_xdlanv2(&h[(i + 3 * (i - 1)) - 1],
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h12,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.h21s,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a__3,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a__4,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst,
          &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab);
        h[its - 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
        h[k] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1;
        h[its] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.aa;
        if (i + 1 < 3) {
          k = 2 - i;
          j = (i + 1) * 3 + i;
          for (its = 0; its < k; its++) {
            nr = its * 3 + j;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = h[nr];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = h[nr - 1];
            h[nr] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst -
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
            h[nr - 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
          }
        }

        ctrl_TT_ad_ctrl_cpp_ros_fe_xrot(i - 1, h, (i - 1) * 3 + 1, i * 3 + 1,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab);
        i *= 3;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst
          * z[kdefl] + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab * z[i];
        z[i] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst * z[i] -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab * z[kdefl];
        z[kdefl] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = z[i + 1];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = z[kdefl + 1];
        z[i + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
        z[kdefl + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba = z[i + 2];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 = z[kdefl + 2];
        z[i + 2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
        z[kdefl + 2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.htmp1 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tst +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ba *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ab;
      }

      kdefl = 0;
      i = L - 2;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros_schur_c(const real_T A[9], real_T V[9],
  real_T T[9])
{
  boolean_T p;
  p = true;
  for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 0;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i < 9;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A = A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i];
    if (p && (rtIsInf(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A) || rtIsNaN
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A))) {
      p = false;
    }
  }

  if (!p) {
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i++) {
      V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i] = (rtNaN);
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 2;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n++) {
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i <= 3) {
        memset(&V[(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n * 3 +
                   ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i) + -1], 0,
               static_cast<uint32_T>(-ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i + 4) *
               sizeof(real_T));
      }

      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i++;
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i++) {
      T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i] = (rtNaN);
    }
  } else {
    memcpy(&T[0], &A[0], 9U * sizeof(real_T));
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[0] = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[1] = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[2] = 0.0;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i++) {
      int32_T alpha1_tmp;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i
        * 3 + 2;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i
        + 1) * 3;
      alpha1_tmp = (3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i +
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i) + 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A = T[alpha1_tmp];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i *
        3 + 3;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i] =
        0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 = ctrl_TT_ad_ctrl_cpp_ros_xnrm2_l(1
        - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i, T,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0);
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 != 0.0) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 = ctrl_TT_ad_ctrl_c_rt_hypotd_snf
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A,
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1);
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A >= 0.0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 =
            -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
        }

        if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1) <
            1.0020841800044864E-292) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt = 0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i;
          do {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt++;
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft =
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft <=
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft++) {
              T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft - 1] *=
                9.9792015476736E+291;
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 *= 9.9792015476736E+291;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A *= 9.9792015476736E+291;
          } while ((fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1) <
                    1.0020841800044864E-292) &&
                   (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt < 20));

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 =
            ctrl_TT_ad_ctrl_c_rt_hypotd_snf(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A,
            ctrl_TT_ad_ctrl_cpp_ros_xnrm2_l(1 -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i, T,
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0));
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A >= 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 =
              -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i]
            = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 -
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A) /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A = 1.0 /
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A -
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1);
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft =
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft <=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft++) {
            T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft - 1] *=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A;
          }

          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 <
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 *= 1.0020841800044864E-292;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
        } else {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i]
            = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 -
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A) /
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A = 1.0 /
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A -
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i;
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc =
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc <=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc++) {
            T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc - 1] *=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
        }
      }

      T[alpha1_tmp] = 1.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 = (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i
        + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n) - 1;
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i]
          != 0.0) {
        boolean_T exitg2;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt = 1 -
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc =
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 -
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i) + 1;
        while ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt + 1 > 0) &&
               (T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc] == 0.0)) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt--;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc--;
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc = 3;
        exitg2 = false;
        while ((!exitg2) && (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc > 0)) {
          int32_T exitg1;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft;
          do {
            exitg1 = 0;
            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c <=
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt * 3 +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft) {
              if (T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c += 3;
              }
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt = -1;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc = 0;
      }

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt + 1 > 0) {
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc != 0) {
          memset(&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[0], 0, static_cast<
                 uint32_T>(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc) * sizeof
                 (real_T));
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c = (3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in) + 1;
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac =
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in + 1;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac <=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac += 3) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc;
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_ia =
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_ia <
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_ia++) {
              int32_T work_tmp;
              work_tmp = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_ia -
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[work_tmp] +=
                T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_ia - 1] *
                T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft];
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft++;
          }
        }

        if (!(-ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i]
              == 0.0)) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in;
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c <=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.knt;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 =
              T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.ix0 +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_ia_c];
            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 != 0.0) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1 *=
                -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac =
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.lastc +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft;
              for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g =
                   ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft + 1;
                   ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g <=
                   ctrl_TT_ad_ctrl_cpp_ros_feedb_B.iac;
                   ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g++) {
                T[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g - 1] +=
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work
                  [(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g -
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft) - 1] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.beta1;
              }
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rowleft += 3;
          }
        }
      }

      ctrl_TT_ad_ctrl_cpp_ros__xzlarf(2 - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i, 2
        - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i],
        T, (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in) + 2,
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work);
      T[alpha1_tmp] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A;
    }

    memcpy(&V[0], &T[0], 9U * sizeof(real_T));
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 1;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i >= 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i--) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n =
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i + 1) * 3;
      for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in = 0;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in <=
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in++) {
        V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in] = 0.0;
      }

      for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in =
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i + 3;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in < 4;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in++) {
        V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n + 2] =
          V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n - 1];
      }
    }

    V[1] = 0.0;
    V[2] = 0.0;
    V[0] = 1.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[0] = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[1] = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work[2] = 0.0;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i = 1;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i >= 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i--) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n =
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i * 3 +
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i) + 6;
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i + 1 < 2) {
        V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n - 2] = 1.0;
        ctrl_TT_ad_ctrl_cpp_ros__xzlarf(2, 1,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n - 1,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i],
          V, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n + 2,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.work);
        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in =
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in <=
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in++) {
          V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.in - 1] *=
            -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i];
        }
      }

      V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n - 2] = 1.0 -
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.tau[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i];
      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.g_i - 1 >= 0) {
        V[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.im1n - 3] = 0.0;
      }
    }

    ctrl_TT_ad_ctrl_cpp_ro_xhseqr_d(T, V);
  }
}

// Function for MATLAB Function: '<S16>/l1 aug - depth'
static void ctrl_TT_ad_ctrl_cpp_ros__expm_f(real_T A[9], real_T F[9])
{
  boolean_T recomputeDiags;
  recomputeDiags = true;
  for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj =
      A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o];
    if (recomputeDiags && (rtIsInf(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj) ||
                           rtIsNaN(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj))) {
      recomputeDiags = false;
    }
  }

  if (!recomputeDiags) {
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
      F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] = (rtNaN);
    }
  } else {
    int32_T exitg1;
    boolean_T exitg2;
    recomputeDiags = true;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
    exitg2 = false;
    while ((!exitg2) && (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3)) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
      do {
        exitg1 = 0;
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3) {
          if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i !=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o) && (!(A[3 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i] == 0.0))) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++;
          }
        } else {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (recomputeDiags) {
      memset(&F[0], 0, 9U * sizeof(real_T));
      F[0] = exp(A[0]);
      F[4] = exp(A[4]);
      F[8] = exp(A[8]);
    } else {
      recomputeDiags = true;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
      exitg2 = false;
      while ((!exitg2) && (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3)) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
        do {
          exitg1 = 0;
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i <=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o) {
            if (!(A[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o +
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i] == A[3 *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i +
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o])) {
              recomputeDiags = false;
              exitg1 = 1;
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++;
            }
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (recomputeDiags) {
        ctrl_TT_ad_ctrl_cpp_ros_schur_c(A, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k);
        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 0;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i < 3;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i++) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj = exp
            (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k[3 *
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i +
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i]);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i] =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i + 1;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
            =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
            * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i + 2;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
            =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
            * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj;
        }

        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m = 3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o;
            F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m] = 0.0;
            F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i];
            F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o
              + 3] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i
              + 3];
            F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m] +=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o
              + 6] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i
              + 6];
          }
        }

        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] = (F[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] +
            F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]) / 2.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m = 3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 1;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]
            = (F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 3] +
               F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]) / 2.0;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m = 3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 2;
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]
            = (F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 6] +
               F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]) / 2.0;
        }

        memcpy(&F[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[0], 9U * sizeof(real_T));
      } else {
        boolean_T guard1 = false;
        boolean_T guard2 = false;
        boolean_T guard3 = false;
        boolean_T guard4 = false;
        recomputeDiags = (A[2] == 0.0);
        if (recomputeDiags) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k = 0;
          exitg2 = false;
          while ((!exitg2) && (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k < 2)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 =
              A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 1];
            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 != 0.0) {
              if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k + 1 != 2) && (A[5] !=
                   0.0)) {
                recomputeDiags = false;
                exitg2 = true;
              } else {
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i =
                  (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k + 1) * 3 +
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k;
                if (A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 1] !=
                    A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]) {
                  recomputeDiags = false;
                  exitg2 = true;
                } else {
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj =
                    A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i];
                  if (rtIsNaN(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6)) {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = (rtNaN);
                  } else if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 < 0.0) {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = -1.0;
                  } else {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 =
                      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 > 0.0);
                  }

                  if (rtIsNaN(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj)) {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj = (rtNaN);
                  } else if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj < 0.0) {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj = -1.0;
                  } else {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj =
                      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj > 0.0);
                  }

                  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 *
                      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj != -1.0) {
                    recomputeDiags = false;
                    exitg2 = true;
                  } else {
                    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k++;
                  }
                }
              }
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k++;
            }
          }
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj = 0.0;
        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k = 3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += A[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] *
              A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += A[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 1] *
              A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 3];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += A[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 2] *
              A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 6];
          }
        }

        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k = 3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 1] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o
              + 3];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 2] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o
              + 6];
          }

          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k = 3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i +
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              = 0.0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 1] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o
              + 3];
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
              += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[3 *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 2] *
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o
              + 6];
          }
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = rt_powd_snf
          (ctrl_TT_ad_ctrl_cpp_ros__norm_b(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6),
           0.16666666666666666);
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 = rt_powd_snf
          (ctrl_TT_ad_ctrl_cpp_ros__norm_b(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4),
           0.25);
        if ((!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 >=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6)) && (!rtIsNaN
             (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6))) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 =
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 <= 0.01495585217958292) {
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              = 0.19285012468241128 * fabs
              (A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]);
          }

          ctrl_TT_ad_ctrl_cpp_ro_mpower_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv,
            7.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = ceil
            (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros__norm_b
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1) /
              ctrl_TT_ad_ctrl_cpp_ros__norm_b(A) * 2.0 / 2.2204460492503131E-16)
             / 6.0);
          if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 >= 0.0)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = 0.0;
          }

          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 == 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 3;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4) {
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 <= 0.253939833006323) {
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
                = 0.12321872304378752 * fabs
                (A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]);
            }

            ctrl_TT_ad_ctrl_cpp_ro_mpower_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv,
              11.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1);
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = ceil
              (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros__norm_b
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1) /
                ctrl_TT_ad_ctrl_cpp_ros__norm_b(A) * 2.0 /
                2.2204460492503131E-16) / 10.0);
            if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 >= 0.0)) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = 0.0;
            }

            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 == 0.0) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 5;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3) {
          ctrl_TT_ad_ctrl_cpp_ro_mpower_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4,
            2.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 = rt_powd_snf
            (ctrl_TT_ad_ctrl_cpp_ros__norm_b(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv),
             0.125);
          if ((!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 >=
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1)) && (!rtIsNaN
               (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1))) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1;
          }

          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 <= 0.95041789961629319) {
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
                = 0.090475336558796943 * fabs
                (A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]);
            }

            ctrl_TT_ad_ctrl_cpp_ro_mpower_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv,
              15.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1);
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = ceil
              (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros__norm_b
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1) /
                ctrl_TT_ad_ctrl_cpp_ros__norm_b(A) * 2.0 /
                2.2204460492503131E-16) / 14.0);
            if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 >= 0.0)) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = 0.0;
            }

            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 == 0.0) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 7;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 <= 2.097847961257068) {
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
                = 0.071467735648795785 * fabs
                (A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]);
            }

            ctrl_TT_ad_ctrl_cpp_ro_mpower_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv,
              19.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1);
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = ceil
              (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros__norm_b
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1) /
                ctrl_TT_ad_ctrl_cpp_ros__norm_b(A) * 2.0 /
                2.2204460492503131E-16) / 18.0);
            if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 >= 0.0)) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = 0.0;
            }

            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 == 0.0) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 9;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k = 3 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
                = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
                += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[3 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
                += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[3 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 1] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i
                + 3];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k]
                += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[3 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 2] *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i
                + 6];
            }
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = rt_powd_snf
            (ctrl_TT_ad_ctrl_cpp_ros__norm_b
             (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k), 0.1);
          if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 >=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0) || rtIsNaN
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1;
          }

          if ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 <=
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0) || rtIsNaN
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = ceil
            (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 /
              5.3719203511481517));
          if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 >= 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = rt_powd_snf(2.0,
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj);
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 =
              A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] /
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              = 0.05031554467093536 * fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0);
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0;
          }

          ctrl_TT_ad_ctrl_cpp_ro_mpower_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv,
            27.0, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = ceil
            (ctrl_TT_ad_ctrl_cpp_ros_fe_log2(ctrl_TT_ad_ctrl_cpp_ros__norm_b
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv1) /
              ctrl_TT_ad_ctrl_cpp_ros__norm_b
              (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4_k) * 2.0 /
              2.2204460492503131E-16) / 26.0);
          if (!(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 >= 0.0)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = 0.0;
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj +=
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0;
          if (rtIsInf(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj)) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = ctrl_TT_ad_ctrl_cpp_ros__norm_b
              (A) / 5.3719203511481517;
            if ((!rtIsInf(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6)) && (!rtIsNaN
                 (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6))) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = frexp
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6,
                 &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i);
            } else {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 0;
            }

            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj =
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i;
            if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 == 0.5) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj = static_cast<real_T>
                (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i) - 1.0;
            }
          }

          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = 13;
        }

        if (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj != 0.0) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6 = rt_powd_snf(2.0,
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0 = rt_powd_snf(2.0, 2.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1 = rt_powd_snf(2.0, 4.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj);
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y = rt_powd_snf(2.0, 6.0 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj);
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
            A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] /=
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d6;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.u0;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.eta1;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o]
              /= ctrl_TT_ad_ctrl_cpp_ros_feedb_B.d_y;
          }
        }

        if (recomputeDiags) {
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[1] = 0;
          if (A[1] != 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[0] = 2;
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[1] = 0;
          } else if (A[5] == 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[0] = 1;
          } else {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[0] = 0;
          }

          if (A[5] != 0.0) {
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[1] = 2;
          } else {
            switch (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[0]) {
             case 0:
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[1] = 1;
              break;

             case 1:
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat[1] = 1;
              break;
            }
          }
        }

        ctrl_TT_ad_ct_padeApproximation(A, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A4, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A6,
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i, F);
        if (recomputeDiags) {
          ctrl_TT_ad_recomputeBlockDiag_b(A, F,
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat);
        }

        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i = static_cast<int32_T>
          (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.exptj);
        for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k = 0;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k <
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_s_i;
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_k_k++) {
          for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 3;
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i = 0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i < 3;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i++) {
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m = 3 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i +
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]
                = 0.0;
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]
                += F[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i] *
                F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]
                += F[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 1] *
                F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 3];
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.F_tmp_m]
                += F[3 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_i + 2] *
                F[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o + 6];
            }
          }

          memcpy(&F[0], &ctrl_TT_ad_ctrl_cpp_ros_feedb_B.A2[0], 9U * sizeof
                 (real_T));
          if (recomputeDiags) {
            for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o = 0;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o < 9;
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o++) {
              A[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.c_k_o] *= 2.0;
            }

            ctrl_TT_ad_recomputeBlockDiag_b(A, F,
              ctrl_TT_ad_ctrl_cpp_ros_feedb_B.blockFormat);
          }
        }
      }
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void ctrl_TT_ad_ctrl_cpp_ros_feedback_2_step(void)
{
  boolean_T tmp;

  // Clock: '<S16>/Clock'
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock =
    ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.t[0];

  // MATLAB Function: '<S16>/MATLAB Function2'
  ctrl_TT_ad_ctrl_c_BernsteinPoly(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Cp,
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock, 0.0,
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Tf, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd);
  ctrl_TT_ad_ctrl_c_BernsteinPoly(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Cp_prime,
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock, 0.0,
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Tf, ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp);

  // S-Function (sdsp2norm2): '<S41>/Normalization' incorporates:
  //   S-Function (sdsp2norm2): '<S41>/Normalization1'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[0]
    * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[0];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc = 1.0 / (sqrt
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[1] *
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[1] +
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock) +
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Normalization_Bias);

  // SignalConversion generated from: '<S41>/Normalization1' incorporates:
  //   Gain: '<S41>/Gain'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[0] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Gain_Gain *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[1];

  // S-Function (sdsp2norm2): '<S41>/Normalization'
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[0] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[0] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[1] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;

  // S-Function (sdsp2norm2): '<S41>/Normalization1' incorporates:
  //   SignalConversion generated from: '<S41>/Normalization1'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc = 1.0 / (sqrt
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[0] *
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[0] +
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock) +
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Normalization1_Bias);
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[0] *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[0] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S20>/SourceBlock'
  tmp = Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45555.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S68>/Enable'

  if (tmp) {
    // SignalConversion generated from: '<S68>/In1'
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_pu =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S20>/SourceBlock'
  // End of Outputs for SubSystem: '<S20>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S21>/SourceBlock'
  tmp = Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45560.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S69>/Enable'

  if (tmp) {
    // SignalConversion generated from: '<S69>/In1'
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_b =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S21>/SourceBlock'
  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S24>/SourceBlock'
  tmp = Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45565.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S72>/Enable'

  if (tmp) {
    // SignalConversion generated from: '<S72>/In1'
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_l =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S24>/SourceBlock'
  // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S25>/SourceBlock'
  tmp = Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45570.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S73>/Enable'

  if (tmp) {
    // SignalConversion generated from: '<S73>/In1'
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_j =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S25>/SourceBlock'
  // End of Outputs for SubSystem: '<S25>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S26>/SourceBlock'
  tmp = Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45575.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S74>/Enable'

  if (tmp) {
    // SignalConversion generated from: '<S74>/In1'
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_ff =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S26>/SourceBlock'
  // End of Outputs for SubSystem: '<S26>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe5'
  // MATLABSystem: '<S27>/SourceBlock'
  tmp = Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45581.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S27>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S75>/Enable'

  if (tmp) {
    // SignalConversion generated from: '<S75>/In1'
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_fi =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S27>/SourceBlock'
  // End of Outputs for SubSystem: '<S27>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe5'

  // SignalConversion generated from: '<S16>/Matrix Multiply' incorporates:
  //   BusAssignment: '<Root>/Bus Assignment4'
  //   BusAssignment: '<Root>/Bus Assignment5'
  //   BusAssignment: '<Root>/Bus Assignment6'
  //   BusAssignment: '<Root>/Bus Assignment7'
  //   BusAssignment: '<Root>/Bus Assignment8'
  //   BusAssignment: '<Root>/Bus Assignment9'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[0] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_pu.Data;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[1] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_b.Data;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[2] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_l.Data;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[3] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_j.Data;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[4] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_ff.Data;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[5] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_fi.Data;
  for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 6;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
    // Product: '<S16>/Matrix Multiply' incorporates:
    //   Constant: '<S16>/Constant'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
      = 0.0;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp < 6;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Constant_Value_gf[6 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp];
    }

    // End of Product: '<S16>/Matrix Multiply'
  }

  // Product: '<S41>/pT_' incorporates:
  //   Concatenate: '<S41>/Matrix Concatenate'
  //   Math: '<S41>/Transpose'
  //   Sum: '<S41>/Add1'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc =
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[0] -
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd[0]) *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2] +
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[1] -
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd[1]) *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3];

  // Sqrt: '<S41>/Square Root' incorporates:
  //   Constant: '<S41>/Constant3'
  //   Math: '<S41>/Square'
  //   Math: '<S41>/Square1'
  //   Sum: '<S41>/Add'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot = sqrt
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.d * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.d +
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc);

  // Product: '<S41>/Divide' incorporates:
  //   Constant: '<S41>/Constant3'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock = ctrl_TT_ad_ctrl_cpp_ros_feedb_P.d /
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;

  // Product: '<S41>/Divide1'
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc /=
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;

  // MATLAB Function: '<S41>/MATLAB Function'
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
    -ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock;

  // Product: '<S35>/Matrix Multiply1' incorporates:
  //   Concatenate: '<S41>/Matrix Concatenate'

  for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 << 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] = 0.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3];
  }

  // End of Product: '<S35>/Matrix Multiply1'

  // MATLAB Function: '<S35>/MATLAB Function' incorporates:
  //   Product: '<S35>/Matrix Multiply1'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[0] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[0];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[2];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[6] = 0.0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[1] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[1];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[4] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[3];
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[7] = 0.0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[2] = 0.0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[5] = 0.0;
  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[8] = 1.0;

  // If: '<S46>/If1' incorporates:
  //   Constant: '<S46>/Constant'

  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotation != 1.0) {
    // Outputs for IfAction SubSystem: '<S46>/If Warning//Error' incorporates:
    //   ActionPort: '<S55>/if'

    // Bias: '<S58>/Bias1' incorporates:
    //   Math: '<S58>/Math Function'
    //   Product: '<S58>/Product'

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 3;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp = 0;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp < 3;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp++) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] =
          ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 1] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp + 1] +
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3 *
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]) +
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3 *
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 2] *
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[3 *
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp + 2]) +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Bias1_Bias[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2];
      }
    }

    // End of Bias: '<S58>/Bias1'

    // RelationalOperator: '<S64>/Compare' incorporates:
    //   Abs: '<S58>/Abs2'
    //   Constant: '<S64>/Constant'

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Compare[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        = (fabs
           (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1])
           > ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotati_a);
    }

    // End of RelationalOperator: '<S64>/Compare'

    // Logic: '<S58>/Logical Operator1' incorporates:
    //   RelationalOperator: '<S64>/Compare'

    tmp = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Compare[0];
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 8;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      tmp = (tmp ||
             ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Compare[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
             + 1]);
    }

    // If: '<S55>/If' incorporates:
    //   Abs: '<S59>/Abs1'
    //   Bias: '<S59>/Bias'
    //   Constant: '<S66>/Constant'
    //   Logic: '<S58>/Logical Operator1'
    //   MATLAB Function: '<S35>/MATLAB Function'
    //   Product: '<S35>/Matrix Multiply1'
    //   Product: '<S65>/Product'
    //   Product: '<S65>/Product1'
    //   Product: '<S65>/Product2'
    //   Product: '<S65>/Product3'
    //   Product: '<S65>/Product4'
    //   Product: '<S65>/Product5'
    //   RelationalOperator: '<S66>/Compare'
    //   Sum: '<S65>/Sum'

    if (fabs((((((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[0] *
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[3] -
                  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[0] * 0.0 * 0.0)
                 - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[1] *
                 ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[2]) + 0.0 *
                ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[2] * 0.0) +
               ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[1] * 0.0 * 0.0) -
              0.0 * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[3] * 0.0) +
             ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Bias_Bias) >
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotati_a) {
      // Outputs for IfAction SubSystem: '<S55>/If Not Proper' incorporates:
      //   ActionPort: '<S57>/Action Port'

      // If: '<S57>/If' incorporates:
      //   Constant: '<S57>/Constant'

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotation == 2.0)
      {
        // Outputs for IfAction SubSystem: '<S57>/Warning' incorporates:
        //   ActionPort: '<S63>/Action Port'

        // Assertion: '<S63>/Assertion' incorporates:
        //   Constant: '<S57>/Constant1'

        utAssert(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S57>/Warning'
      } else if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotation
                 == 3.0) {
        // Outputs for IfAction SubSystem: '<S57>/Error' incorporates:
        //   ActionPort: '<S62>/Action Port'

        // Assertion: '<S62>/Assertion' incorporates:
        //   Constant: '<S57>/Constant1'

        utAssert(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S57>/Error'
      }

      // End of If: '<S57>/If'
      // End of Outputs for SubSystem: '<S55>/If Not Proper'
    } else if (tmp) {
      // Outputs for IfAction SubSystem: '<S55>/Else If Not Orthogonal' incorporates:
      //   ActionPort: '<S56>/Action Port'

      // If: '<S56>/If' incorporates:
      //   Constant: '<S56>/Constant'

      if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotation == 2.0)
      {
        // Outputs for IfAction SubSystem: '<S56>/Warning' incorporates:
        //   ActionPort: '<S61>/Action Port'

        // Assertion: '<S61>/Assertion' incorporates:
        //   Constant: '<S56>/Constant1'

        utAssert(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Constant1_Value_e != 0.0);

        // End of Outputs for SubSystem: '<S56>/Warning'
      } else if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.DirectionCosineMatrixtoRotation
                 == 3.0) {
        // Outputs for IfAction SubSystem: '<S56>/Error' incorporates:
        //   ActionPort: '<S60>/Action Port'

        // Assertion: '<S60>/Assertion' incorporates:
        //   Constant: '<S56>/Constant1'

        utAssert(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Constant1_Value_e != 0.0);

        // End of Outputs for SubSystem: '<S56>/Error'
      }

      // End of If: '<S56>/If'
      // End of Outputs for SubSystem: '<S55>/Else If Not Orthogonal'
    }

    // End of If: '<S55>/If'
    // End of Outputs for SubSystem: '<S46>/If Warning//Error'
  }

  // End of If: '<S46>/If1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
  // MATLABSystem: '<S28>/SourceBlock'
  Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45586.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe6'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe7'
  // MATLABSystem: '<S29>/SourceBlock'
  Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45591.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe7'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe8'
  // MATLABSystem: '<S30>/SourceBlock'
  Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45596.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe8'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe9'
  // MATLABSystem: '<S31>/SourceBlock'
  Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45601.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe9'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe10'
  // MATLABSystem: '<S22>/SourceBlock'
  Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45606.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe10'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe11'
  // MATLABSystem: '<S23>/SourceBlock'
  Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45611.getLatestMessage
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_varargout_2);

  // End of Outputs for SubSystem: '<Root>/Subscribe11'

  // MATLAB Function: '<S16>/l1 aug - depth'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_not_empty_o) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_not_empty_o = true;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot = ctrl_TT_ad_ctrl_cpp_ros_fee_inv
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1]);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[2];
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[2];
  }

  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.adap != 0.0) {
    if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[1]) > fabs
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[0])) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 0;
    } else {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 1;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2]
      /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
      + 2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2
      + 2] - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 << 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      = ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[0] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 <<= 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[2] -
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
       * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp) /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      -=
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2]
      * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[1] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 +
      1] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[3] -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
            + 1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp) /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] -=
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2
      + 1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 << 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[3];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate,
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[0] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[1]) -
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[3];
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        =
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
         + 2] * 0.0 + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1) *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Aoz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    }

    ctrl_TT_ad_ctrl_cpp_ros__expm_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m);
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        0;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[0] = 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[4] = 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[8] = 1;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Aoz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    }

    ctrl_TT_ad_ctrl_cpp_ros__expm_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[2] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[3] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros__inv_jg(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Aoz,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y);
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] -
        static_cast<real_T>
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]);
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 3;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Boz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Boz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 3];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 3]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 3]
        +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Boz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 3]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3];
      for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp = 0;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp < 3;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp++) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] =
          0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp + 1] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
          3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp + 2] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
          6];
      }

      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
        3] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[1] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
         + 3] * ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[1] +
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
         * ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[0]) +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
        6] * ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[2];
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 3;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
          + 3] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[1] +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
          * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[0]) +
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
         6] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[2]) +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock = -ctrl_TT_ad_ctrl_cpp_ros_fee_inv
      ((ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[0] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[1]) *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Bmz[0] +
       (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3]) *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Bmz[1]) *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd[2] -
      ((ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Coz[0] *
        ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[0] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Coz[1] *
        ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[1]) +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Coz[2] *
       ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[2]);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[2] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[3] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[0] +
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1] +
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0] - 1.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3] - 1.0;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixConcatenate_tmp =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixConcatenate_tmp *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixConcatenate_tmp *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Bmz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[0] =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[0] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2]) +
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd_p[1] =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3]) +
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp;
  } else {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[2];
  }

  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[0] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[0];
  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[1] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[1];
  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_g[2] =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[2];

  // Outputs for IfAction SubSystem: '<S38>/AxisRotDefault' incorporates:
  //   ActionPort: '<S43>/Action Port'

  // If: '<S38>/If' incorporates:
  //   Fcn: '<S43>/Fcn1'
  //   Gain: '<S35>/Gain'
  //   Gain: '<S45>/Gain1'
  //   MATLAB Function: '<S35>/MATLAB Function'
  //   Product: '<S35>/Matrix Multiply1'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc = rt_atan2d_snf
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Gain1_Gain[0] *
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[2],
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[0] *
     ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Gain1_Gain[1]) *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Gain_Gain_o;

  // End of Outputs for SubSystem: '<S38>/AxisRotDefault'

  // MATLAB Function: '<S16>/l1 aug - heading'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_not_empty) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu_not_empty = true;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot = ctrl_TT_ad_ctrl_cpp_ros_fee_inv
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1]);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[5];
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[5];
  }

  if (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.adap != 0.0) {
    if (fabs(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[1]) > fabs
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[0])) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 0;
    } else {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 1;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2]
      /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
      + 2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2
      + 2] - ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 << 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      = ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[0] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 <<= 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[2] -
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
       * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp) /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
      -=
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2]
      * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[1] /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 +
      1] = (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[3] -
            ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
            + 1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp) /
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
      + 1] -=
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2
      + 1] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 << 1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp
        + 1] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Lambdaz[3];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate,
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[0] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[1]) -
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[5];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Phiinvz[3];
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        =
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
         + 2] * 0.0 + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1) *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Aoz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    }

    ctrl_TT_ad_ctrl_cpp_ros__expm_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m);
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        0;
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[0] = 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[4] = 1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[8] = 1;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Aoz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    }

    ctrl_TT_ad_ctrl_cpp_ros__expm_f(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[2] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      -ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[3] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros__inv_jg(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Aoz,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y);
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 9;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] -
        static_cast<real_T>
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_I[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]);
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 3;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Boz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Boz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 3];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 3]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 3]
        +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Boz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 + 3]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3];
      for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp = 0;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp < 3;
           ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp++) {
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2 = 3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] =
          0.0;
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp + 1] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
          3];
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r2] +=
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao_c[3 *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixMultiply1_tmp + 2] *
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
          6];
      }

      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
        3] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[1] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv4[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[0];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
         + 3] * ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[1] +
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
         * ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[0]) +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.y_m[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
        6] * ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[2];
    }

    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 3;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
          + 3] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[1] +
          ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
          * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[0]) +
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Ao[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 +
         6] * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv7[2]) +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_f_inv_j(ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc = -ctrl_TT_ad_ctrl_cpp_ros_fee_inv
      ((ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[0] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[1]) *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Bmz[0] +
       (ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[0] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[2] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Cmz[1] *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[3]) *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Bmz[1]) *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc -
      ((ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Coz[0] *
        ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[0] +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Coz[1] *
        ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[1]) +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Coz[2] *
       ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[2]);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[2] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Amz[3] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[0] +
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[0] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1] +
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[1] *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3] =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3;
    ctrl_TT_ad_ctrl_cpp_ros_fe_expm(ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l,
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda);
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[0] - 1.0;
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[2];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3 =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Lambda[3] - 1.0;
    for (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 = 0;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1 < 2;
         ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixConcatenate_tmp =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2];
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixConcatenate_tmp *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_1;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] = 0.0;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] +=
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixConcatenate[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_2;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1
        + 2] += ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_MatrixConcatenate_tmp *
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_idx_3;
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1] =
        ctrl_TT_ad_ctrl_cpp_ros_feedb_P.L1.Bmz[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1]
        * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc +
        ctrl_TT_ad_ctrl_cpp_ros_feedb_B.TmpSignalConversionAtNormal[ctrl_TT_ad_ctrl_cpp_ros_feedb_B.r1];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[0] =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[0] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[2]) +
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.SquareRoot;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xd[1] =
      (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[0] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[1] +
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.dv8[1] *
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.rtb_Divide_l[3]) +
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.a22_tmp;
  } else {
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[0] =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[0];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[1] =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[1];
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[2] =
      ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[2];
  }

  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[0] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[0];
  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[1] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[1];
  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.xu[2] = ctrl_TT_ad_ctrl_cpp_ros_feedb_B.uTmp[2];

  // MATLAB Function: '<S16>/Marin PID' incorporates:
  //   MATLAB Function: '<S16>/l1 aug - depth'
  //   MATLAB Function: '<S16>/l1 aug - heading'

  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.zerr_int_prev +=
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock -
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[2]) *
    ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.thetaerr_int_prev += (0.0 -
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[4]) * 180.0 /
    3.1415926535897931 * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;
  ctrl_TT_ad_ctrl_cpp_ros_feed_DW.psierr_int_prev +=
    (ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc -
     ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[5]) * 180.0 /
    3.1415926535897931 * ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Ts;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   DotProduct: '<S35>/Dot Product1'
  //   Gain: '<S35>/Gain1'
  //   MATLAB Function: '<S16>/FF velocity ctrl'
  //   Product: '<S35>/Matrix Multiply1'
  //   Selector: '<S35>/1,1'
  //   Selector: '<S35>/2,1'
  //   Sum: '<S35>/Add1'
  //   Sum: '<S35>/Sum'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.BusAssignment.Data =
    (((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd[0] -
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[0]) *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Kp + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[0])
     * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[0] +
     ((ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pd[1] -
       ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply[1]) *
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Kp + ctrl_TT_ad_ctrl_cpp_ros_feedb_B.pdp[1])
     * ctrl_TT_ad_ctrl_cpp_ros_feedb_B.MatrixMultiply1[1]) / 4.0;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S17>/SinkBlock'
  Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45530.publish
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   MATLAB Function: '<S16>/l1 aug - heading'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.BusAssignment2.Data =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.acc;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S19>/SinkBlock'
  Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45545.publish
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   MATLAB Function: '<S16>/l1 aug - depth'

  ctrl_TT_ad_ctrl_cpp_ros_feedb_B.BusAssignment1.Data =
    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.Clock;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S18>/SinkBlock'
  Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45539.publish
    (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.t[0] =
    ((time_T)(++ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.clockTick0)) *
    ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.05s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.05, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.clockTick1++;
  }
}

// Model initialize function
void ctrl_TT_ad_ctrl_cpp_ros_feedback_2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo,
                          &ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo, &rtmGetTPtr
                (ctrl_TT_ad_ctrl_cpp_ros_feed_M));
    rtsiSetStepSizePtr(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo,
                       &ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo,
                          (&rtmGetErrorStatus(ctrl_TT_ad_ctrl_cpp_ros_feed_M)));
    rtsiSetRTModelPtr(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo,
                      ctrl_TT_ad_ctrl_cpp_ros_feed_M);
  }

  rtsiSetSimTimeStep(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&ctrl_TT_ad_ctrl_cpp_ros_feed_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(ctrl_TT_ad_ctrl_cpp_ros_feed_M,
             &ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.tArray[0]);
  ctrl_TT_ad_ctrl_cpp_ros_feed_M->Timing.stepSize0 = 0.05;

  {
    char_T b_zeroDelimTopic_1[14];
    char_T b_zeroDelimTopic_0[13];
    char_T b_zeroDelimTopic_2[12];
    char_T b_zeroDelimTopic_3[11];
    char_T b_zeroDelimTopic[10];
    static const char_T tmp[9] = { '/', 'x', '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_0[9] = { '/', 'y', '_', 'h', 'b', '_', 'm', 's', 'g'
    };

    static const char_T tmp_1[9] = { '/', 'z', '_', 'h', 'b', '_', 'm', 's', 'g'
    };

    static const char_T tmp_2[12] = { '/', 'r', 'o', 'l', 'l', '_', 'h', 'b',
      '_', 'm', 's', 'g' };

    static const char_T tmp_3[13] = { '/', 'p', 'i', 't', 'c', 'h', '_', 'h',
      'b', '_', 'm', 's', 'g' };

    static const char_T tmp_4[11] = { '/', 'y', 'a', 'w', '_', 'h', 'b', '_',
      'm', 's', 'g' };

    static const char_T tmp_5[15] = { '/', 'u', '_', 'v', 'e', 'l', '_', 'x',
      '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_6[15] = { '/', 'v', '_', 'v', 'e', 'l', '_', 'y',
      '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_7[15] = { '/', 'w', '_', 'v', 'e', 'l', '_', 'z',
      '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_8[16] = { '/', 'p', '_', 'a', 'v', 'e', 'l', '_',
      'x', '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_9[16] = { '/', 'q', '_', 'a', 'v', 'e', 'l', '_',
      'y', '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_a[16] = { '/', 'r', '_', 'a', 'v', 'e', 'l', '_',
      'z', '_', 'h', 'b', '_', 'm', 's', 'g' };

    static const char_T tmp_b[10] = { '/', 'n', '_', 'r', 'p', 'm', '_', 'm',
      's', 'g' };

    static const char_T tmp_c[12] = { '/', 'p', 's', 'i', '_', 'r', 'e', 'f',
      '_', 'm', 's', 'g' };

    static const char_T tmp_d[10] = { '/', 'z', '_', 'r', 'e', 'f', '_', 'm',
      's', 'g' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S68>/In1' incorporates:
    //   Outport: '<S68>/Out1'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_pu =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem'

    // Start for MATLABSystem: '<S20>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_au.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_au.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[9] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45555.createSubscriber
      (&b_zeroDelimTopic[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_au.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S20>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S69>/In1' incorporates:
    //   Outport: '<S69>/Out1'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_b =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // Start for MATLABSystem: '<S21>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_g.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic[i] = tmp_0[i];
    }

    b_zeroDelimTopic[9] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45560.createSubscriber
      (&b_zeroDelimTopic[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S21>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S72>/In1' incorporates:
    //   Outport: '<S72>/Out1'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_l =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // Start for MATLABSystem: '<S24>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_a.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_a.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic[i] = tmp_1[i];
    }

    b_zeroDelimTopic[9] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45565.createSubscriber
      (&b_zeroDelimTopic[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S24>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S73>/In1' incorporates:
    //   Outport: '<S73>/Out1'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_j =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Out1_Y0_gg;

    // End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem'

    // Start for MATLABSystem: '<S25>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fr.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fr.isInitialized = 1;
    for (int32_T i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_2[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45570.createSubscriber
      (&b_zeroDelimTopic_0[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fr.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S25>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S74>/In1' incorporates:
    //   Outport: '<S74>/Out1'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_ff =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem'

    // Start for MATLABSystem: '<S26>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_i.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_i.isInitialized = 1;
    for (int32_T i = 0; i < 13; i++) {
      b_zeroDelimTopic_1[i] = tmp_3[i];
    }

    b_zeroDelimTopic_1[13] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45575.createSubscriber
      (&b_zeroDelimTopic_1[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S26>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe5'
    // SystemInitialize for Enabled SubSystem: '<S27>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S75>/In1' incorporates:
    //   Outport: '<S75>/Out1'

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.In1_fi =
      ctrl_TT_ad_ctrl_cpp_ros_feedb_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S27>/Enabled Subsystem'

    // Start for MATLABSystem: '<S27>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_o.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_o.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_2[i] = tmp_4[i];
    }

    b_zeroDelimTopic_2[11] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45581.createSubscriber
      (&b_zeroDelimTopic_2[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S27>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe5'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // Start for MATLABSystem: '<S28>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_p.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[i] = tmp_5[i];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[15] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45586.createSubscriber
      (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S28>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe7'
    // Start for MATLABSystem: '<S29>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fs.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fs.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[i] = tmp_6[i];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[15] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45591.createSubscriber
      (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fs.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S29>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe7'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe8'
    // Start for MATLABSystem: '<S30>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_lk.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_lk.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[i] = tmp_7[i];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[15] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45596.createSubscriber
      (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic_h[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_lk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S30>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe8'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe9'
    // Start for MATLABSystem: '<S31>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_j.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_j.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[i] = tmp_8[i];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[16] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45601.createSubscriber
      (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S31>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe9'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe10'
    // Start for MATLABSystem: '<S22>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_jw.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_jw.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[i] = tmp_9[i];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[16] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45606.createSubscriber
      (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_jw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S22>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe10'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe11'
    // Start for MATLABSystem: '<S23>/SourceBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_ln.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_ln.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[i] = tmp_a[i];
    }

    ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[16] = '\x00';
    Sub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45611.createSubscriber
      (&ctrl_TT_ad_ctrl_cpp_ros_feedb_B.b_zeroDelimTopic[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_ln.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S23>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe11'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S17>/SinkBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_f.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_f.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic_3[i] = tmp_b[i];
    }

    b_zeroDelimTopic_3[10] = '\x00';
    Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45530.createPublisher
      (&b_zeroDelimTopic_3[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S17>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S19>/SinkBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_c[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45545.createPublisher
      (&b_zeroDelimTopic_0[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S19>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S18>/SinkBlock'
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_l.matlabCodegenIsDeleted = false;
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic_3[i] = tmp_d[i];
    }

    b_zeroDelimTopic_3[10] = '\x00';
    Pub_ctrl_TT_ad_ctrl_cpp_ros_feedback_2_45539.createPublisher
      (&b_zeroDelimTopic_3[0], 1);
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S18>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void ctrl_TT_ad_ctrl_cpp_ros_feedback_2_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S20>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_au.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_au.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_g.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S24>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_a.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S25>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fr.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S25>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S26>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_i.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe5'
  // Terminate for MATLABSystem: '<S27>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_o.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe5'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S28>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_p.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe7'
  // Terminate for MATLABSystem: '<S29>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fs.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_fs.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe7'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe8'
  // Terminate for MATLABSystem: '<S30>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_lk.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_lk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe8'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe9'
  // Terminate for MATLABSystem: '<S31>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_j.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe9'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe10'
  // Terminate for MATLABSystem: '<S22>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_jw.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_jw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe10'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe11'
  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_ln.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_ln.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe11'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S17>/SinkBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_f.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S19>/SinkBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S18>/SinkBlock'
  if (!ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_l.matlabCodegenIsDeleted) {
    ctrl_TT_ad_ctrl_cpp_ros_feed_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
