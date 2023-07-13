

    

        /*
        * Model_6DOF.c
        *
                * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
        *
    * Code generation for model "Model_6DOF".
    *
    * Model version              : 9.27
    * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
        * C source code generated on : Thu Nov 17 09:41:05 2022
 * 
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
        */




    
#include "Model_6DOF.h"

#include "rtwtypes.h"

#include "Model_6DOF_types.h"

#include "Model_6DOF_private.h"

#include <string.h>

#include <math.h>

#include <stdlib.h>

#include <stddef.h>

#include "rt_nonfinite.h"


    

    

    

    

    

    

    

    

    

    

    
        /* Block signals (default storage) */
                                

            B_Model_6DOF_T Model_6DOF_B;

            
        /* Continuous states */
                

            X_Model_6DOF_T Model_6DOF_X;

    
            /* Block states (default storage) */
                                

            DW_Model_6DOF_T Model_6DOF_DW;

            
    




            
        
        
        
        
        
        

        

        
        


                /* Real-time model */
                        
                    

            static RT_MODEL_Model_6DOF_T Model_6DOF_M_;

                

            RT_MODEL_Model_6DOF_T *const Model_6DOF_M = &Model_6DOF_M_;



    

    

    /* Forward declaration for local functions */


                
                

                                 static void Model_6DOF_inv(const real_T x[9], real_T y[9]);
                                





                
                

                                 static void Model_6DOF_emxInit_real_T(emxArray_real_T_Model_6DOF_T **pEmxArray, int32_T numDimensions);
                                





                
                

                                 static void Model__emxEnsureCapacity_real_T(emxArray_real_T_Model_6DOF_T *emxArray, int32_T oldNumel);
                                





                
                

                                 static void Model_6DOF_emxFree_real_T(emxArray_real_T_Model_6DOF_T **pEmxArray);
                                





                
                

                                 static real_T Model_6DOF_norm(const real_T x[3]);
                                



/* Forward declaration for local functions */


                
                

                                 static void Model_6DOF_inv_m(const real_T x[9], real_T y[9]);
                                





                
                

                                 static real_T Model_6DOF_norm_m(const real_T x[3]);
                                





                
                

                                 static void Model_6DOF_emxInit_real_T_i(emxArray_real_T_Model_6DOF_T **pEmxArray, int32_T numDimensions);
                                





                
                

                                 static void Mode_emxEnsureCapacity_real_T_i(emxArray_real_T_Model_6DOF_T *emxArray, int32_T oldNumel);
                                





                
                

                                 static void Model_6DOF_emxFree_real_T_i(emxArray_real_T_Model_6DOF_T **pEmxArray);
                                





    

        
                         
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[], uint32_T maxIndex)
{
    real_T frac;
    real_T yL_0d0;
    uint32_T iLeft;
    /* Column-major Lookup 1-D
   Search method: 'binary'
   Use previous index: 'off'
   Interpolation method: 'Linear point-slope'
   Extrapolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u0 <= bp0[0U]) {
        iLeft = 0U;
        frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
    } else if (u0 < bp0[maxIndex]) {
        uint32_T bpIdx;
        uint32_T iRght;
        /* Binary Search */
        bpIdx = maxIndex >> 1U;
        iLeft = 0U;
        iRght = maxIndex;
        while (iRght - iLeft > 1U) {
            if (u0 < bp0[bpIdx]) {
                iRght = bpIdx;
            } else {
                iLeft = bpIdx;
            }
            bpIdx = (iRght + iLeft) >> 1U;
        }
        frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
    } else {
        iLeft = maxIndex - 1U;
        frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
    }
    /* Column-major Interpolation 1-D
   Interpolation method: 'Linear point-slope'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    yL_0d0 = table[iLeft];
    return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}
        
                 
real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
    real_T fractions[2];
    real_T frac;
    real_T yL_0d0;
    real_T yL_0d1;
    uint32_T bpIndices[2];
    uint32_T bpIdx;
    uint32_T iLeft;
    uint32_T iRght;
    /* Column-major Lookup 2-D
   Search method: 'binary'
   Use previous index: 'off'
   Interpolation method: 'Linear point-slope'
   Extrapolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u0 <= bp0[0U]) {
        iLeft = 0U;
        frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
    } else if (u0 < bp0[maxIndex[0U]]) {
        /* Binary Search */
        bpIdx = maxIndex[0U] >> 1U;
        iLeft = 0U;
        iRght = maxIndex[0U];
        while (iRght - iLeft > 1U) {
            if (u0 < bp0[bpIdx]) {
                iRght = bpIdx;
            } else {
                iLeft = bpIdx;
            }
            bpIdx = (iRght + iLeft) >> 1U;
        }
        frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
    } else {
        iLeft = maxIndex[0U] - 1U;
        frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U] - 1U]);
    }
    fractions[0U] = frac;
    bpIndices[0U] = iLeft;
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u1 <= bp1[0U]) {
        iLeft = 0U;
        frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
    } else if (u1 < bp1[maxIndex[1U]]) {
        /* Binary Search */
        bpIdx = maxIndex[1U] >> 1U;
        iLeft = 0U;
        iRght = maxIndex[1U];
        while (iRght - iLeft > 1U) {
            if (u1 < bp1[bpIdx]) {
                iRght = bpIdx;
            } else {
                iLeft = bpIdx;
            }
            bpIdx = (iRght + iLeft) >> 1U;
        }
        frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
    } else {
        iLeft = maxIndex[1U] - 1U;
        frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U] - 1U]);
    }
    /* Column-major Interpolation 2-D
   Interpolation method: 'Linear point-slope'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    bpIdx = iLeft * stride + bpIndices[0U];
    yL_0d0 = table[bpIdx];
    yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    bpIdx += stride;
    yL_0d1 = table[bpIdx];
    return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) * frac + yL_0d0;
}
        
                 
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T *fraction)
{
    uint32_T bpIndex;
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u <= bp[0U]) {
        bpIndex = 0U;
        *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
    } else if (u < bp[maxIndex]) {
        bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
        *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
    } else {
        bpIndex = maxIndex - 1U;
        *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
    }
    return bpIndex;
}
        
                 
real_T intrp3d_l_pw(const uint32_T bpIndex[], const real_T frac[], const real_T table[], const uint32_T stride[])
{
    real_T yL_0d0;
    real_T yL_1d;
    real_T yL_2d;
    uint32_T offset_0d;
    uint32_T offset_2d;
    /* Column-major Interpolation 3-D
   Interpolation method: 'Linear point-slope'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    offset_2d = (bpIndex[2U] * stride[2U] + bpIndex[1U] * stride[1U]) + bpIndex[0U];
    yL_0d0 = table[offset_2d];
    yL_1d = (table[offset_2d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
    offset_0d = offset_2d + stride[1U];
    yL_0d0 = table[offset_0d];
    yL_2d = (((table[offset_0d + 1U] - yL_0d0) * frac[0U] + yL_0d0) - yL_1d) * frac[1U] + yL_1d;
    offset_2d += stride[2U];
    yL_0d0 = table[offset_2d];
    yL_1d = (table[offset_2d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
    offset_0d = offset_2d + stride[1U];
    yL_0d0 = table[offset_0d];
    return (((((table[offset_0d + 1U] - yL_0d0) * frac[0U] + yL_0d0) - yL_1d) * frac[1U] + yL_1d) - yL_2d) * frac[2U] + yL_2d;
}
        
                 
uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex, uint32_T maxIndex)
{
    uint32_T bpIdx;
    uint32_T bpIndex;
    uint32_T iRght;
    /* Binary Search */
    bpIdx = startIndex;
    bpIndex = 0U;
    iRght = maxIndex;
    while (iRght - bpIndex > 1U) {
        if (u < bp[bpIdx]) {
            iRght = bpIdx;
        } else {
            bpIndex = bpIdx;
        }
        bpIdx = (iRght + bpIndex) >> 1U;
    }
    return bpIndex;
}
        
    








    /* 
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */

        static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
    {
        

            /* Solver Matrices */
            static const real_T rt_ODE3_A[3] = {
                1.0/2.0, 3.0/4.0, 1.0
            };
            static const real_T rt_ODE3_B[3][3] = {
                { 1.0/2.0,     0.0,     0.0 },
                {     0.0, 3.0/4.0,     0.0 },
                { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
            };

            time_T    t     = rtsiGetT(si);
            time_T    tnew  = rtsiGetSolverStopTime(si);
            time_T    h     = rtsiGetStepSize(si);
            real_T    *x    = rtsiGetContStates(si);
            ODE3_IntgData  *id  =  (ODE3_IntgData *)rtsiGetSolverData(si);
            real_T    *y    = id->y;
            real_T    *f0   = id->f[0];
            real_T    *f1   = id->f[1];
            real_T    *f2   = id->f[2];
            real_T    hB[3];
            int_T     i;
            int_T     nXc   = 12;


            rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
            

            /* Save the state values at time t in y, we'll use x as ynew. */
            (void) memcpy(y, x,
(uint_T)nXc*sizeof(real_T));

            /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
            /* f0 = f(t,y) */
            rtsiSetdX(si, f0);

                        Model_6DOF_derivatives();

            /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
            hB[0] = h * rt_ODE3_B[0][0];
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (f0[i]*hB[0]);
            }
            rtsiSetT(si, t + h*rt_ODE3_A[0]);
            rtsiSetdX(si, f1);
            
            


            Model_6DOF_step();


                        Model_6DOF_derivatives();

            

            /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
            for (i = 0; i <= 1; i++) {
                hB[i] = h * rt_ODE3_B[1][i];
            }
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
            }
            rtsiSetT(si, t + h*rt_ODE3_A[1]);
            rtsiSetdX(si, f2);
            
            


            Model_6DOF_step();


                        Model_6DOF_derivatives();

            

            /* tnew = t + hA(3);
            ynew = y + f*hB(:,3); */
            for (i = 0; i <= 2; i++) {
                hB[i] = h * rt_ODE3_B[2][i];
            }
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
            }
            rtsiSetT(si, tnew);





            rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
            

    }
    

    
    

                
        
        
        
        
        
        
        
        
        
        
        
        
        
        
                    

                        


        /* Function for MATLAB Function: '<S39>/MATLAB Function4' */

            
                    
        static void Model_6DOF_inv(const real_T x[9], real_T y[9])
        {
            real_T b_x[9];
real_T absx11;
real_T absx21;
real_T absx31;
int32_T p1;
int32_T p2;
int32_T p3;
memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
p1 = 0;
p2 = 3;
p3 = 6;
absx11 = fabs(x[0]);
absx21 = fabs(x[1]);
absx31 = fabs(x[2]);
if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
} else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    b_x[0] = x[2];
    b_x[2] = x[0];
    b_x[3] = x[5];
    b_x[5] = x[3];
    b_x[6] = x[8];
    b_x[8] = x[6];
}
b_x[1] /= b_x[0];
b_x[2] /= b_x[0];
b_x[4] -= b_x[1] * b_x[3];
b_x[5] -= b_x[2] * b_x[3];
b_x[7] -= b_x[1] * b_x[6];
b_x[8] -= b_x[2] * b_x[6];
if (fabs(b_x[5]) > fabs(b_x[4])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = absx11;
    absx11 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx11;
    absx11 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx11;
}
b_x[5] /= b_x[4];
b_x[8] -= b_x[5] * b_x[7];
absx11 = (b_x[1] * b_x[5] - b_x[2]) / b_x[8];
absx21 = -(b_x[7] * absx11 + b_x[1]) / b_x[4];
y[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
y[p1 + 1] = absx21;
y[p1 + 2] = absx11;
absx11 = -b_x[5] / b_x[8];
absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
y[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
y[p2 + 1] = absx21;
y[p2 + 2] = absx11;
absx11 = 1.0 / b_x[8];
absx21 = -b_x[7] * absx11 / b_x[4];
y[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
y[p3 + 1] = absx21;
y[p3 + 2] = absx11;


        }
            

            





                        


         

            
                    
        static void Model_6DOF_emxInit_real_T(emxArray_real_T_Model_6DOF_T **pEmxArray, int32_T numDimensions)
        {
            emxArray_real_T_Model_6DOF_T *emxArray;
int32_T i;
*pEmxArray = (emxArray_real_T_Model_6DOF_T *)malloc(sizeof(emxArray_real_T_Model_6DOF_T));
emxArray = *pEmxArray;
emxArray->data = (real_T *)NULL;
emxArray->numDimensions = numDimensions;
emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
emxArray->allocatedSize = 0;
emxArray->canFreeData = true;
for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
}


        }
            

            





                        


         

            
                    
        static void Model__emxEnsureCapacity_real_T(emxArray_real_T_Model_6DOF_T *emxArray, int32_T oldNumel)
        {
            int32_T i;
int32_T newNumel;
void *newData;
if (oldNumel < 0) {
    oldNumel = 0;
}
newNumel = 1;
for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
}
if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
        i = 16;
    }
    while (i < newNumel) {
        if (i > 1073741823) {
            i = MAX_int32_T;
        } else {
            i <<= 1;
        }
    }
    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
        memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
        if (emxArray->canFreeData) {
            free(emxArray->data);
        }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
}


        }
            

            





                        


         

            
                    
        static void Model_6DOF_emxFree_real_T(emxArray_real_T_Model_6DOF_T **pEmxArray)
        {
            if (*pEmxArray != (emxArray_real_T_Model_6DOF_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Model_6DOF_T *)NULL;
}


        }
            

            





                        


        /* Function for MATLAB Function: '<S39>/MATLAB Function4' */

            
                    
        static real_T Model_6DOF_norm(const real_T x[3])
        {
            real_T absxk;
real_T scale;
real_T t;
real_T y;
scale = 3.3121686421112381E-170;
absxk = fabs(x[0]);
if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


        }
            

            

            
        
            
        


                    /* 
 * Output and update for atomic system:
 *    '<S39>/MATLAB Function4'
 *    '<S40>/MATLAB Function4'
 *    '<S41>/MATLAB Function1'
 *    '<S41>/MATLAB Function4'
 *    '<S42>/MATLAB Function1'
 *    '<S42>/MATLAB Function4'
 */

            
                            

        


          void Model_6DOF_MATLABFunction4(real_T rtu_time, const real_T rtu_Xearth[6], const real_T rtu_vert1[600], const real_T rtu_vert2[600], const real_T rtu_vert3[600], const real_T rtu_dA[200], real_T rtu_ntri, real_T rtu_A_wave, real_T rtu_k_wave, real_T rtu_w_wave, real_T rtu_rho, real_T rtu_g, real_T rtu_Zb, const real_T rtu_EAX[3], real_T rtu_dX, const real_T rtu_origin[3], const real_T rtu_xcg[3], B_MATLABFunction4_Model_6DOF_T *localB)
    {
    
                                            
            
emxArray_real_T_Model_6DOF_T *mp1;
emxArray_real_T_Model_6DOF_T *mp2;
emxArray_real_T_Model_6DOF_T *mp3;
emxArray_real_T_Model_6DOF_T *nA;
emxArray_real_T_Model_6DOF_T *r1;
emxArray_real_T_Model_6DOF_T *r2;
emxArray_real_T_Model_6DOF_T *r3;
real_T RMATD[9];
real_T RMATX[9];
real_T RMat[9];
real_T dM_tmp[9];
real_T MP1[3];
real_T MP2[3];
real_T RMATD_0[3];
real_T dM[3];
real_T dM_tmp_0[3];
real_T vert3[3];
real_T x_e_0[3];
real_T x_e_1[3];
real_T x_e_2[3];
real_T RMat_tmp;
real_T RMat_tmp_0;
real_T RMat_tmp_1;
real_T p1;
real_T p1_tmp;
real_T p2;
real_T p3;
real_T x_e;
real_T y_e;
real_T z_e;
int32_T d_i;
int32_T i;

            
        




                                                            
        




                                                    
                                    























memcpy(&localB->vert1[0], &rtu_vert1[0], 600U * sizeof(real_T));
memcpy(&localB->vert2[0], &rtu_vert2[0], 600U * sizeof(real_T));
memcpy(&localB->vert3[0], &rtu_vert3[0], 600U * sizeof(real_T));
RMat_tmp = cos(rtu_Xearth[5]);
RMat_tmp_0 = sin(rtu_Xearth[3]);
RMat_tmp_1 = sin(rtu_Xearth[5]);
p1 = cos(rtu_Xearth[3]);
p2 = sin(rtu_Xearth[4]);
p3 = cos(rtu_Xearth[4]);
RMat[0] = p3 * RMat_tmp;
RMat[3] = RMat_tmp_0 * p2 * RMat_tmp + -p1 * RMat_tmp_1;
RMat[6] = p1 * p2 * RMat_tmp + RMat_tmp_0 * RMat_tmp_1;
RMat[1] = p3 * RMat_tmp_1;
RMat[4] = sin(rtu_Xearth[3]) * sin(rtu_Xearth[4]) * RMat_tmp_1 + p1 * RMat_tmp;
RMat[7] = cos(rtu_Xearth[3]) * sin(rtu_Xearth[4]) * RMat_tmp_1 + -RMat_tmp_0 * RMat_tmp;
RMat[2] = -p2;
RMat[5] = RMat_tmp_0 * p3;
RMat[8] = p1 * p3;
RMat_tmp = cos(rtu_EAX[2]);
RMat_tmp_0 = sin(rtu_EAX[0]);
RMat_tmp_1 = sin(rtu_EAX[2]);
p1 = cos(rtu_EAX[0]);
p2 = sin(rtu_EAX[1]);
p3 = cos(rtu_EAX[1]);
RMATX[0] = p3 * RMat_tmp;
RMATX[3] = RMat_tmp_0 * p2 * RMat_tmp + -p1 * RMat_tmp_1;
RMATX[6] = p1 * p2 * RMat_tmp + RMat_tmp_0 * RMat_tmp_1;
RMATX[1] = p3 * RMat_tmp_1;
RMATX[4] = sin(rtu_EAX[0]) * sin(rtu_EAX[1]) * RMat_tmp_1 + p1 * RMat_tmp;
RMATX[7] = cos(rtu_EAX[0]) * sin(rtu_EAX[1]) * RMat_tmp_1 + -RMat_tmp_0 * RMat_tmp;
RMATX[2] = -p2;
RMATX[5] = RMat_tmp_0 * p3;
RMATX[8] = p1 * p3;
RMat_tmp = sin(rtu_dX);
RMat_tmp_0 = cos(rtu_dX);
RMATD[0] = RMat_tmp_0;
RMATD[3] = 0.0 * RMat_tmp_0 + -RMat_tmp;
RMATD[6] = 0.0 * RMat_tmp + 0.0 * cos(rtu_dX);
RMATD[1] = RMat_tmp;
RMATD[4] = 0.0 * sin(rtu_dX) + RMat_tmp_0;
RMATD[7] = -0.0 * RMat_tmp_0 + 0.0 * sin(rtu_dX);
RMATD[2] = 0.0;
RMATD[5] = 0.0;
RMATD[8] = 1.0;
if ((int32_T)rtu_ntri - 1 >= 0) {
    Model_6DOF_inv(RMATX, dM_tmp);
}
for (i = 0; i < (int32_T)rtu_ntri; i++) {
    RMat_tmp = (localB->vert1[i] - rtu_origin[0] * 70.2) + rtu_xcg[0];
    RMat_tmp_0 = (localB->vert1[i + 200] - rtu_origin[1] * 70.2) + rtu_xcg[1];
    RMat_tmp_1 = (localB->vert1[i + 400] - rtu_origin[2] * 70.2) + rtu_xcg[2];
    for (d_i = 0; d_i < 3; d_i++) {
        dM_tmp_0[d_i] = (dM_tmp[d_i + 3] * RMat_tmp_0 + dM_tmp[d_i] * RMat_tmp) + dM_tmp[d_i + 6] * RMat_tmp_1;
    }
    for (d_i = 0; d_i < 3; d_i++) {
        RMATD_0[d_i] = (RMATD[d_i + 3] * dM_tmp_0[1] + RMATD[d_i] * dM_tmp_0[0]) + RMATD[d_i + 6] * dM_tmp_0[2];
    }
    dM_tmp_0[0] = localB->vert2[i];
    dM_tmp_0[1] = localB->vert2[i + 200];
    dM_tmp_0[2] = localB->vert2[i + 400];
    for (d_i = 0; d_i < 3; d_i++) {
        MP1[d_i] = (dM_tmp_0[d_i] - rtu_origin[d_i] * 70.2) + rtu_xcg[d_i];
        dM[d_i] = (RMATX[d_i + 3] * RMATD_0[1] + RMATX[d_i] * RMATD_0[0]) + RMATX[d_i + 6] * RMATD_0[2];
    }
    for (d_i = 0; d_i < 3; d_i++) {
        dM_tmp_0[d_i] = (dM_tmp[d_i + 3] * MP1[1] + dM_tmp[d_i] * MP1[0]) + dM_tmp[d_i + 6] * MP1[2];
    }
    for (d_i = 0; d_i < 3; d_i++) {
        RMATD_0[d_i] = (RMATD[d_i + 3] * dM_tmp_0[1] + RMATD[d_i] * dM_tmp_0[0]) + RMATD[d_i + 6] * dM_tmp_0[2];
    }
    dM_tmp_0[0] = localB->vert3[i];
    dM_tmp_0[1] = localB->vert3[i + 200];
    dM_tmp_0[2] = localB->vert3[i + 400];
    for (d_i = 0; d_i < 3; d_i++) {
        vert3[d_i] = (dM_tmp_0[d_i] - rtu_origin[d_i] * 70.2) + rtu_xcg[d_i];
        MP1[d_i] = (RMATX[d_i + 3] * RMATD_0[1] + RMATX[d_i] * RMATD_0[0]) + RMATX[d_i + 6] * RMATD_0[2];
    }
    for (d_i = 0; d_i < 3; d_i++) {
        dM_tmp_0[d_i] = (dM_tmp[d_i + 3] * vert3[1] + dM_tmp[d_i] * vert3[0]) + dM_tmp[d_i + 6] * vert3[2];
    }
    for (d_i = 0; d_i < 3; d_i++) {
        RMATD_0[d_i] = (RMATD[d_i + 3] * dM_tmp_0[1] + RMATD[d_i] * dM_tmp_0[0]) + RMATD[d_i + 6] * dM_tmp_0[2];
    }
    for (d_i = 0; d_i < 3; d_i++) {
        int32_T vert1_tmp;
        vert1_tmp = 200 * d_i + i;
        localB->vert1[vert1_tmp] = (rtu_origin[d_i] * 70.2 + dM[d_i]) - rtu_xcg[d_i];
        localB->vert2[vert1_tmp] = (rtu_origin[d_i] * 70.2 + MP1[d_i]) - rtu_xcg[d_i];
        localB->vert3[vert1_tmp] = (((RMATX[d_i + 3] * RMATD_0[1] + RMATX[d_i] * RMATD_0[0]) + RMATX[d_i + 6] * RMATD_0[2]) + rtu_origin[d_i] * 70.2) - rtu_xcg[d_i];
    }
}
Model_6DOF_emxInit_real_T(&mp1, 2);
Model_6DOF_emxInit_real_T(&mp2, 2);
Model_6DOF_emxInit_real_T(&mp3, 2);
Model_6DOF_emxInit_real_T(&nA, 2);
Model_6DOF_emxInit_real_T(&r1, 2);
Model_6DOF_emxInit_real_T(&r2, 2);
Model_6DOF_emxInit_real_T(&r3, 2);
d_i = mp1->size[0] * mp1->size[1];
mp1->size[0] = (int32_T)rtu_ntri;
mp1->size[1] = 3;
Model__emxEnsureCapacity_real_T(mp1, d_i);
d_i = mp2->size[0] * mp2->size[1];
mp2->size[0] = (int32_T)rtu_ntri;
mp2->size[1] = 3;
Model__emxEnsureCapacity_real_T(mp2, d_i);
d_i = mp3->size[0] * mp3->size[1];
mp3->size[0] = (int32_T)rtu_ntri;
mp3->size[1] = 3;
Model__emxEnsureCapacity_real_T(mp3, d_i);
d_i = nA->size[0] * nA->size[1];
nA->size[0] = (int32_T)rtu_ntri;
nA->size[1] = 3;
Model__emxEnsureCapacity_real_T(nA, d_i);
d_i = r1->size[0] * r1->size[1];
r1->size[0] = (int32_T)rtu_ntri;
r1->size[1] = 3;
Model__emxEnsureCapacity_real_T(r1, d_i);
d_i = r2->size[0] * r2->size[1];
r2->size[0] = (int32_T)rtu_ntri;
r2->size[1] = 3;
Model__emxEnsureCapacity_real_T(r2, d_i);
d_i = r3->size[0] * r3->size[1];
r3->size[0] = (int32_T)rtu_ntri;
r3->size[1] = 3;
Model__emxEnsureCapacity_real_T(r3, d_i);
for (i = 0; i < (int32_T)rtu_ntri; i++) {
    dM[0] = localB->vert2[i] - localB->vert1[i];
    RMat_tmp = localB->vert1[i + 200];
    RMat_tmp_0 = localB->vert2[i + 200];
    dM[1] = RMat_tmp_0 - RMat_tmp;
    RMat_tmp_1 = localB->vert1[i + 400];
    x_e = localB->vert2[i + 400];
    dM[2] = x_e - RMat_tmp_1;
    MP1[0] = localB->vert3[i] - localB->vert1[i];
    y_e = localB->vert3[i + 200];
    MP1[1] = y_e - RMat_tmp;
    z_e = localB->vert3[i + 400];
    MP1[2] = z_e - RMat_tmp_1;
    p1 = dM[1] * MP1[2] - MP1[1] * dM[2];
    MP2[0] = p1;
    p2 = MP1[0] * dM[2] - dM[0] * MP1[2];
    MP2[1] = p2;
    p3 = dM[0] * MP1[1] - MP1[0] * dM[1];
    MP2[2] = p3;
    p1_tmp = Model_6DOF_norm(MP2);
    nA->data[i] = p1 / p1_tmp * rtu_dA[i];
    r1->data[i] = (localB->vert1[i] + localB->vert2[i]) * 0.5;
    r2->data[i] = (localB->vert1[i] + localB->vert3[i]) * 0.5;
    r3->data[i] = (localB->vert2[i] + localB->vert3[i]) * 0.5;
    nA->data[i + nA->size[0]] = p2 / p1_tmp * rtu_dA[i];
    r1->data[i + r1->size[0]] = (RMat_tmp + RMat_tmp_0) * 0.5;
    r2->data[i + r2->size[0]] = (RMat_tmp + y_e) * 0.5;
    r3->data[i + r3->size[0]] = (RMat_tmp_0 + y_e) * 0.5;
    nA->data[i + (nA->size[0] << 1)] = p3 / p1_tmp * rtu_dA[i];
    r1->data[i + (r1->size[0] << 1)] = (RMat_tmp_1 + x_e) * 0.5;
    r2->data[i + (r2->size[0] << 1)] = (RMat_tmp_1 + z_e) * 0.5;
    r3->data[i + (r3->size[0] << 1)] = (x_e + z_e) * 0.5;
}
if ((int32_T)rtu_ntri - 1 >= 0) {
    x_e_0[0] = rtu_Xearth[0];
    x_e_0[1] = rtu_Xearth[1];
    x_e_0[2] = rtu_Xearth[2];
    x_e_1[0] = rtu_Xearth[0];
    x_e_1[1] = rtu_Xearth[1];
    x_e_1[2] = rtu_Xearth[2];
    x_e_2[0] = rtu_Xearth[0];
    x_e_2[1] = rtu_Xearth[1];
    x_e_2[2] = rtu_Xearth[2];
}
for (i = 0; i < (int32_T)rtu_ntri; i++) {
    real_T r3_idx_2;
    RMat_tmp_1 = r1->data[i];
    x_e = r1->data[i + r1->size[0]];
    y_e = r1->data[(r1->size[0] << 1) + i];
    z_e = r2->data[i];
    p1 = r2->data[i + r2->size[0]];
    p2 = r2->data[(r2->size[0] << 1) + i];
    p3 = r3->data[i];
    p1_tmp = r3->data[i + r3->size[0]];
    r3_idx_2 = r3->data[(r3->size[0] << 1) + i];
    for (d_i = 0; d_i < 3; d_i++) {
        RMat_tmp = RMat[d_i + 3];
        RMat_tmp_0 = RMat[d_i + 6];
        mp1->data[i + mp1->size[0] * d_i] = ((RMat_tmp * x_e + RMat[d_i] * RMat_tmp_1) + RMat_tmp_0 * y_e) + x_e_0[d_i];
        mp2->data[i + mp2->size[0] * d_i] = ((RMat_tmp * p1 + RMat[d_i] * z_e) + RMat_tmp_0 * p2) + x_e_1[d_i];
        mp3->data[i + mp3->size[0] * d_i] = ((RMat_tmp * p1_tmp + RMat[d_i] * p3) + RMat_tmp_0 * r3_idx_2) + x_e_2[d_i];
    }
}
x_e = 0.0;
y_e = 0.0;
z_e = 0.0;
RMat_tmp = 0.0;
RMat_tmp_0 = 0.0;
RMat_tmp_1 = 0.0;
for (d_i = 0; d_i < (int32_T)rtu_ntri; d_i++) {
    p3 = rtu_w_wave * rtu_time;
    p1_tmp = -rtu_rho * rtu_g;
    p1 = (mp1->data[(mp1->size[0] << 1) + d_i] - exp(mp1->data[(mp1->size[0] << 1) + d_i] * rtu_k_wave) * rtu_A_wave * sin(rtu_k_wave * mp1->data[d_i] - p3)) * p1_tmp;
    p2 = (mp2->data[(mp2->size[0] << 1) + d_i] - exp(mp2->data[(mp2->size[0] << 1) + d_i] * rtu_k_wave) * rtu_A_wave * sin(rtu_k_wave * mp2->data[d_i] - p3)) * p1_tmp;
    p3 = (mp3->data[(mp3->size[0] << 1) + d_i] - exp(mp3->data[(mp3->size[0] << 1) + d_i] * rtu_k_wave) * rtu_A_wave * sin(rtu_k_wave * mp3->data[d_i] - p3)) * p1_tmp;
    MP1[0] = (-p1 * r1->data[d_i] - p2 * r2->data[d_i]) - p3 * r3->data[d_i];
    MP1[1] = (r1->data[d_i + r1->size[0]] * -p1 - r2->data[d_i + r2->size[0]] * p2) - r3->data[d_i + r3->size[0]] * p3;
    MP1[2] = ((r1->data[(r1->size[0] << 1) + d_i] - rtu_Zb) * -p1 - (r2->data[(r2->size[0] << 1) + d_i] - rtu_Zb) * p2) - (r3->data[(r3->size[0] << 1) + d_i] - rtu_Zb) * p3;
    MP2[0] = nA->data[d_i];
    MP2[1] = nA->data[d_i + nA->size[0]];
    MP2[2] = nA->data[(nA->size[0] << 1) + d_i];
    p1 = (p1 + p2) + p3;
    x_e += p1 * -nA->data[d_i] / 3.0;
    y_e += -nA->data[d_i + nA->size[0]] * p1 / 3.0;
    z_e += -nA->data[(nA->size[0] << 1) + d_i] * p1 / 3.0;
    RMat_tmp += (MP1[1] * MP2[2] - MP2[1] * MP1[2]) / 3.0;
    RMat_tmp_0 += (MP2[0] * MP1[2] - MP1[0] * MP2[2]) / 3.0;
    RMat_tmp_1 += (MP1[0] * MP2[1] - MP2[0] * MP1[1]) / 3.0;
}
Model_6DOF_emxFree_real_T(&r3);
Model_6DOF_emxFree_real_T(&r2);
Model_6DOF_emxFree_real_T(&r1);
Model_6DOF_emxFree_real_T(&nA);
Model_6DOF_emxFree_real_T(&mp3);
Model_6DOF_emxFree_real_T(&mp2);
Model_6DOF_emxFree_real_T(&mp1);
localB->Fx_total = x_e;
localB->Fy_total = y_e;
localB->Fz_total = z_e;
localB->Mx_total = RMat_tmp;
localB->My_total = RMat_tmp_0;
localB->Mz_total = RMat_tmp_1;





        



                        
        
            
                    }
            



                                





        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

    

                        


        /* Function for MATLAB Function: '<S39>/MATLAB Function1' */

            
                    
        static void Model_6DOF_inv_m(const real_T x[9], real_T y[9])
        {
            real_T b_x[9];
real_T absx11;
real_T absx21;
real_T absx31;
int32_T p1;
int32_T p2;
int32_T p3;
memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
p1 = 0;
p2 = 3;
p3 = 6;
absx11 = fabs(x[0]);
absx21 = fabs(x[1]);
absx31 = fabs(x[2]);
if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
} else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    b_x[0] = x[2];
    b_x[2] = x[0];
    b_x[3] = x[5];
    b_x[5] = x[3];
    b_x[6] = x[8];
    b_x[8] = x[6];
}
b_x[1] /= b_x[0];
b_x[2] /= b_x[0];
b_x[4] -= b_x[1] * b_x[3];
b_x[5] -= b_x[2] * b_x[3];
b_x[7] -= b_x[1] * b_x[6];
b_x[8] -= b_x[2] * b_x[6];
if (fabs(b_x[5]) > fabs(b_x[4])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = absx11;
    absx11 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx11;
    absx11 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx11;
}
b_x[5] /= b_x[4];
b_x[8] -= b_x[5] * b_x[7];
absx11 = (b_x[1] * b_x[5] - b_x[2]) / b_x[8];
absx21 = -(b_x[7] * absx11 + b_x[1]) / b_x[4];
y[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
y[p1 + 1] = absx21;
y[p1 + 2] = absx11;
absx11 = -b_x[5] / b_x[8];
absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
y[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
y[p2 + 1] = absx21;
y[p2 + 2] = absx11;
absx11 = 1.0 / b_x[8];
absx21 = -b_x[7] * absx11 / b_x[4];
y[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
y[p3 + 1] = absx21;
y[p3 + 2] = absx11;


        }
            

            





                        


        /* Function for MATLAB Function: '<S9>/MATLAB Function' */

            
                    
        static real_T Model_6DOF_norm_m(const real_T x[3])
        {
            real_T absxk;
real_T scale;
real_T t;
real_T y;
scale = 3.3121686421112381E-170;
absxk = fabs(x[0]);
if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


        }
            

            





                        


         

            
                    
        static void Model_6DOF_emxInit_real_T_i(emxArray_real_T_Model_6DOF_T **pEmxArray, int32_T numDimensions)
        {
            emxArray_real_T_Model_6DOF_T *emxArray;
int32_T i;
*pEmxArray = (emxArray_real_T_Model_6DOF_T *)malloc(sizeof(emxArray_real_T_Model_6DOF_T));
emxArray = *pEmxArray;
emxArray->data = (real_T *)NULL;
emxArray->numDimensions = numDimensions;
emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
emxArray->allocatedSize = 0;
emxArray->canFreeData = true;
for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
}


        }
            

            





                        


         

            
                    
        static void Mode_emxEnsureCapacity_real_T_i(emxArray_real_T_Model_6DOF_T *emxArray, int32_T oldNumel)
        {
            int32_T i;
int32_T newNumel;
void *newData;
if (oldNumel < 0) {
    oldNumel = 0;
}
newNumel = 1;
for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
}
if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
        i = 16;
    }
    while (i < newNumel) {
        if (i > 1073741823) {
            i = MAX_int32_T;
        } else {
            i <<= 1;
        }
    }
    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
        memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
        if (emxArray->canFreeData) {
            free(emxArray->data);
        }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
}


        }
            

            





                        


         

            
                    
        static void Model_6DOF_emxFree_real_T_i(emxArray_real_T_Model_6DOF_T **pEmxArray)
        {
            if (*pEmxArray != (emxArray_real_T_Model_6DOF_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Model_6DOF_T *)NULL;
}


        }
            

            



                        




        /* Model step function */
        
                    
        void Model_6DOF_step(void) 
        {
            


        

                
                            /* local block i/o variables */
                                        

                                real_T rtb_Clock;


                        

                                real_T rtb_DifferenceInputs2;

        

                                real_T rtb_DifferenceInputs2_c;

        

                                real_T rtb_DifferenceInputs2_d;

        

                                real_T rtb_DifferenceInputs2_m;

        

                                real_T rtb_DifferenceInputs2_g;

        

                                real_T rtb_DifferenceInputs2_k;

        

                                real_T rtb_DifferenceInputs2_i;

        

                                real_T rtb_DifferenceInputs2_f;

        

                                real_T rtb_n;

        

                                real_T rtb_dX[5];





        

        




                
            

            if (rtmIsMajorTimeStep(Model_6DOF_M)) {
        
            /* set solver stop time */
        if (!(Model_6DOF_M->Timing.clockTick0+1)) {
            rtsiSetSolverStopTime(&Model_6DOF_M->solverInfo, ((Model_6DOF_M->Timing.clockTickH0 + 1) * Model_6DOF_M->Timing.stepSize0 * 4294967296.0));
        } else {
            rtsiSetSolverStopTime(&Model_6DOF_M->solverInfo, ((Model_6DOF_M->Timing.clockTick0  + 1) * Model_6DOF_M->Timing.stepSize0 + Model_6DOF_M->Timing.clockTickH0 * Model_6DOF_M->Timing.stepSize0 * 4294967296.0));
        }


    

        } /* end MajorTimeStep */
        /* Update absolute time of base rate at minor time step */
        if (rtmIsMinorTimeStep(Model_6DOF_M)) {
            Model_6DOF_M->Timing.t[0] = rtsiGetT(&Model_6DOF_M->solverInfo);
        }
        





        




                            {
            
emxArray_real_T_Model_6DOF_T *mp1;
emxArray_real_T_Model_6DOF_T *mp1_0;
emxArray_real_T_Model_6DOF_T *mp1_1;
emxArray_real_T_Model_6DOF_T *mp1_2;
emxArray_real_T_Model_6DOF_T *mp1_3;
emxArray_real_T_Model_6DOF_T *mp1_4;
emxArray_real_T_Model_6DOF_T *mp1_5;
emxArray_real_T_Model_6DOF_T *mp1_6;
emxArray_real_T_Model_6DOF_T *mp2;
emxArray_real_T_Model_6DOF_T *mp2_0;
emxArray_real_T_Model_6DOF_T *mp2_1;
emxArray_real_T_Model_6DOF_T *mp2_2;
emxArray_real_T_Model_6DOF_T *mp2_3;
emxArray_real_T_Model_6DOF_T *mp2_4;
emxArray_real_T_Model_6DOF_T *mp2_5;
emxArray_real_T_Model_6DOF_T *mp2_6;
emxArray_real_T_Model_6DOF_T *mp3;
emxArray_real_T_Model_6DOF_T *mp3_0;
emxArray_real_T_Model_6DOF_T *mp3_1;
emxArray_real_T_Model_6DOF_T *mp3_2;
emxArray_real_T_Model_6DOF_T *mp3_3;
emxArray_real_T_Model_6DOF_T *mp3_4;
emxArray_real_T_Model_6DOF_T *mp3_5;
emxArray_real_T_Model_6DOF_T *mp3_6;
emxArray_real_T_Model_6DOF_T *nA;
emxArray_real_T_Model_6DOF_T *nA_0;
emxArray_real_T_Model_6DOF_T *nA_1;
emxArray_real_T_Model_6DOF_T *nA_2;
emxArray_real_T_Model_6DOF_T *nA_3;
emxArray_real_T_Model_6DOF_T *nA_4;
emxArray_real_T_Model_6DOF_T *nA_5;
emxArray_real_T_Model_6DOF_T *nA_6;
emxArray_real_T_Model_6DOF_T *r1;
emxArray_real_T_Model_6DOF_T *r1_0;
emxArray_real_T_Model_6DOF_T *r1_1;
emxArray_real_T_Model_6DOF_T *r1_2;
emxArray_real_T_Model_6DOF_T *r1_3;
emxArray_real_T_Model_6DOF_T *r1_4;
emxArray_real_T_Model_6DOF_T *r1_5;
emxArray_real_T_Model_6DOF_T *r1_6;
emxArray_real_T_Model_6DOF_T *r2;
emxArray_real_T_Model_6DOF_T *r2_0;
emxArray_real_T_Model_6DOF_T *r2_1;
emxArray_real_T_Model_6DOF_T *r2_2;
emxArray_real_T_Model_6DOF_T *r2_3;
emxArray_real_T_Model_6DOF_T *r2_4;
emxArray_real_T_Model_6DOF_T *r2_5;
emxArray_real_T_Model_6DOF_T *r2_6;
emxArray_real_T_Model_6DOF_T *r3;
emxArray_real_T_Model_6DOF_T *r3_0;
emxArray_real_T_Model_6DOF_T *r3_1;
emxArray_real_T_Model_6DOF_T *r3_2;
emxArray_real_T_Model_6DOF_T *r3_3;
emxArray_real_T_Model_6DOF_T *r3_4;
emxArray_real_T_Model_6DOF_T *r3_5;
emxArray_real_T_Model_6DOF_T *r3_6;
real_T rtb_Rs[45];
real_T rtb_Uws[45];
real_T rtb_Xce[45];
real_T (*lastU)[45];
real_T A[36];
real_T a[36];
real_T RMATD[9];
real_T RMATX[9];
real_T RMat_tmp[9];
real_T b_x[9];
real_T dXiuq_0[6];
real_T rtb_TmpSignalConversionAtSFun_b[6];
real_T tmp_4[6];
real_T IP[5];
real_T rtb_aX[5];
real_T Omega_s[3];
real_T Vr_earth[3];
real_T Vx_earth[3];
real_T X1e[3];
real_T X2e[3];
real_T X3e[3];
real_T X4e[3];
real_T XBe[3];
real_T fractions[3];
real_T fractions_0[3];
real_T fractions_1[3];
real_T fractions_2[3];
real_T fractions_3[3];
real_T fractions_4[3];
real_T fractions_5[3];
real_T fractions_6[3];
real_T fractions_7[3];
real_T np4[3];
real_T npB[3];
real_T rtb_Add[3];
real_T tmp[3];
real_T tmp_0[3];
real_T tmp_1[3];
real_T tmp_2[3];
real_T tmp_3[3];
real_T u_ship[3];
real_T w_ship[3];
real_T x_e_0[3];
real_T x_e_1[3];
real_T x_e_2[3];
real_T x_e_3[3];
real_T x_e_4[3];
real_T x_e_5[3];
real_T x_e_6[3];
real_T x_e_7[3];
real_T x_e_8[3];
real_T x_e_9[3];
real_T x_e_a[3];
real_T x_e_b[3];
real_T x_e_c[3];
real_T x_e_d[3];
real_T x_e_e[3];
real_T x_e_f[3];
real_T x_e_g[3];
real_T x_e_h[3];
real_T x_e_i[3];
real_T x_e_j[3];
real_T x_e_k[3];
real_T x_e_l[3];
real_T x_e_m[3];
real_T x_e_n[3];
real_T Fx_total;
real_T Fx_total_0;
real_T Fx_total_1;
real_T Fx_total_2;
real_T Fy_total;
real_T Fy_total_0;
real_T Fy_total_1;
real_T Fz_total;
real_T Fz_total_0;
real_T Fz_total_1;
real_T Mx_total;
real_T Mx_total_0;
real_T Mx_total_1;
real_T My_total;
real_T My_total_0;
real_T My_total_1;
real_T My_total_2;
real_T Mz_total;
real_T RMATD_0;
real_T RMATX_tmp;
real_T RMATX_tmp_0;
real_T RMATX_tmp_tmp;
real_T RMATX_tmp_tmp_0;
real_T RMat_tmp_tmp;
real_T RMat_tmp_tmp_0;
real_T RMat_tmp_tmp_1;
real_T RMat_tmp_tmp_2;
real_T RMat_tmp_tmp_3;
real_T absx31;
real_T absxk;
real_T arg1;
real_T arg2;
real_T arg3;
real_T arg4;
real_T arg5;
real_T dXiuq;
real_T dh;
real_T dv;
real_T p1;
real_T p2;
real_T p3_0;
real_T psierr;
real_T psierr_tmp;
real_T psierr_tmp_tmp;
real_T psierrint;
real_T rtb_Add_l_idx_0;
real_T rtb_Add_l_idx_1;
real_T rtb_Add_l_idx_2;
real_T rtb_Add_l_idx_3;
real_T rtb_Add_l_idx_4;
real_T rtb_Add_l_idx_5;
real_T rtb_Product3_a;
real_T rtb_Sign1_hb;
real_T rtb_Sign_o;
real_T rtb_UkYk1_l;
real_T rtb_deltafalllimit_h;
real_T rtb_dpeth;
real_T thetaerr;
real_T thetaerrint;
real_T tmp_5;
real_T tmp_6;
real_T tmp_7;
real_T tmp_8;
real_T tmp_9;
real_T tmp_a;
real_T x_e;
real_T y_e;
real_T z_e;
real_T zerr;
real_T zerrint;
real_T zerrint_tmp;
int32_T b_k;
int32_T c_ix;
int32_T i;
int32_T ijA;
int32_T itmp;
int32_T p1_0;
int32_T p3;
uint32_T bpIndices[3];
uint32_T bpIndices_0[3];
uint32_T bpIndices_1[3];
uint32_T bpIndices_2[3];
uint32_T bpIndices_3[3];
uint32_T bpIndices_4[3];
uint32_T bpIndices_5[3];
uint32_T bpIndices_6[3];
uint32_T bpIndices_7[3];
uint32_T bpIndices_8[3];
uint32_T bpIndices_9[3];
int8_T ipiv[6];
int8_T p[6];

                                    
                
                                    











for (i = 0; i < 6; i++) {
    /* {S!d44}Integrator: '<S65>/Integrator' */
    Model_6DOF_B.Integrator[i] = Model_6DOF_X.Integrator_CSTATE[i];
}
for (i = 0; i < 5; i++) {
    /* {S!d46}Gain: '<S65>/Gain2' */
    Model_6DOF_B.Gain2[i] = Model_6DOF_B.Integrator[i + 1] * Model_6DOF_P.Gain2_Gain;
}
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d48}Scope: '<Root>/BV' */
                                if (rtmIsMajorTimeStep(Model_6DOF_M))
            {
                StructLogVar *svar = (StructLogVar *)Model_6DOF_DW.BV_PWORK.LoggedData[0];
                LogVar       *var  = svar->signals.values;

                    /* time */
                    {
                        double locTime =         (((Model_6DOF_M->Timing.clockTick1+Model_6DOF_M->Timing.clockTickH1* 4294967296.0))  * 0.05)
;
                            rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);

                    }

                /* signals */
                    {

                        real_T up0[1];

                                    up0[0] = Model_6DOF_B.Integrator[0];
                            rt_UpdateLogVar((LogVar *)var, up0, 0);

                            var = var->next;
                    }
                    {

                        real_T up1[1];

                                    up1[0] = Model_6DOF_B.Gain2[0];
                            rt_UpdateLogVar((LogVar *)var, up1, 0);

                            var = var->next;
                    }
                    {

                        real_T up2[1];

                                    up2[0] = Model_6DOF_B.Gain2[1];
                            rt_UpdateLogVar((LogVar *)var, up2, 0);

                            var = var->next;
                    }
                    {

                        real_T up3[1];

                                    up3[0] = Model_6DOF_B.Gain2[2];
                            rt_UpdateLogVar((LogVar *)var, up3, 0);

                            var = var->next;
                    }
                    {

                        real_T up4[1];

                                    up4[0] = Model_6DOF_B.Gain2[3];
                            rt_UpdateLogVar((LogVar *)var, up4, 0);

                            var = var->next;
                    }
                    {

                        real_T up5[1];

                                    up5[0] = Model_6DOF_B.Gain2[4];
                            rt_UpdateLogVar((LogVar *)var, up5, 0);

                    }
            }

 

}
for (i = 0; i < 6; i++) {
    /* {S!d50}Integrator: '<S64>/Integrator' */
    Model_6DOF_B.Integrator_d[i] = Model_6DOF_X.Integrator_CSTATE_h[i];
}
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d52}Scope: '<Root>/BX' */
                                if (rtmIsMajorTimeStep(Model_6DOF_M))
            {
                StructLogVar *svar = (StructLogVar *)Model_6DOF_DW.BX_PWORK.LoggedData[0];
                LogVar       *var  = svar->signals.values;

                    /* time */
                    {
                        double locTime =         (((Model_6DOF_M->Timing.clockTick1+Model_6DOF_M->Timing.clockTickH1* 4294967296.0))  * 0.05)
;
                            rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);

                    }

                /* signals */
                    {

                        real_T up0[1];

                                    up0[0] = Model_6DOF_B.Integrator_d[0];
                            rt_UpdateLogVar((LogVar *)var, up0, 0);

                            var = var->next;
                    }
                    {

                        real_T up1[1];

                                    up1[0] = Model_6DOF_B.Integrator_d[1];
                            rt_UpdateLogVar((LogVar *)var, up1, 0);

                            var = var->next;
                    }
                    {

                        real_T up2[1];

                                    up2[0] = Model_6DOF_B.Integrator_d[2];
                            rt_UpdateLogVar((LogVar *)var, up2, 0);

                            var = var->next;
                    }
                    {

                        real_T up3[1];

                                    up3[0] = Model_6DOF_B.Integrator_d[3];
                            rt_UpdateLogVar((LogVar *)var, up3, 0);

                            var = var->next;
                    }
                    {

                        real_T up4[1];

                                    up4[0] = Model_6DOF_B.Integrator_d[4];
                            rt_UpdateLogVar((LogVar *)var, up4, 0);

                            var = var->next;
                    }
                    {

                        real_T up5[1];

                                    up5[0] = Model_6DOF_B.Integrator_d[5];
                            rt_UpdateLogVar((LogVar *)var, up5, 0);

                    }
            }

 

    /* {S!d54}MATLAB Function: '<S1>/pf_controller1' incorporates:
 *  Constant: '<S1>/Constant2'
 */
    rtb_n = -Model_6DOF_P.v_ref / 4.0;
    /* {S!d58}MATLAB Function: '<S1>/pf_controller' incorporates:
 *  Constant: '<S1>/Constant3'
 *  Constant: '<S1>/Constant4'
 */
    zerr = Model_6DOF_P.z_ref - Model_6DOF_B.Integrator_d[2];
    zerrint = zerr * Model_6DOF_P.Ts + Model_6DOF_DW.zerr_int_prev;
    thetaerr = (0.0 - Model_6DOF_B.Integrator_d[4]) * 180.0 / 3.1415926535897931;
    thetaerrint = thetaerr * Model_6DOF_P.Ts + Model_6DOF_DW.thetaerr_int_prev;
    dv = ((zerr - Model_6DOF_DW.zerr_prev) / Model_6DOF_P.Ts * 3.0 + (3.0 * zerr + 0.1044 * zerrint)) + ((thetaerr - Model_6DOF_DW.thetaerr_prev) / Model_6DOF_P.Ts * 3.0 + (3.0 * thetaerr + 0.1466 * thetaerrint));
    psierr = (Model_6DOF_P.psi_ref - Model_6DOF_B.Integrator_d[5]) * 180.0 / 3.1415926535897931;
    psierrint = psierr * Model_6DOF_P.Ts + Model_6DOF_DW.psierr_int_prev;
    dh = (psierr - Model_6DOF_DW.psierr_prev) / Model_6DOF_P.Ts * 12.199 + (3.0 * psierr + 0.0 * psierrint);
    rtb_dX[0] = -dv + dh;
    rtb_dX[1] = -dv - dh;
    rtb_dX[2] = dv - dh;
    rtb_dX[3] = dv + dh;
    rtb_dX[4] = dv;
    Model_6DOF_DW.zerr_prev = zerr;
    Model_6DOF_DW.zerr_int_prev = zerrint;
    Model_6DOF_DW.thetaerr_prev = thetaerr;
    Model_6DOF_DW.thetaerr_int_prev = thetaerrint;
    Model_6DOF_DW.psierr_prev = psierr;
    Model_6DOF_DW.psierr_int_prev = psierrint;
    /* {S!d66}Product: '<S86>/delta rise limit' incorporates:
 *  Constant: '<S71>/Constant2'
 *  SampleTimeMath: '<S86>/sample time'
 *
 * About '<S86>/sample time':
 *  y = K where K = ( w * Ts )
 */
    dh = Model_6DOF_P.Constant2_Value_l * Model_6DOF_P.sampletime_WtEt;
    /* {S!d68}Sum: '<S86>/Difference Inputs1' incorporates:
 *  Constant: '<S1>/Constant1'
 *  UnitDelay: '<S86>/Delay Input2'
 */
    zerr = Model_6DOF_P.Constant1_Value - Model_6DOF_DW.DelayInput2_DSTATE;
    /* {S!d74}Switch: '<S87>/Switch2' incorporates:
 *  RelationalOperator: '<S87>/LowerRelop1'
 */
    if (!(zerr > dh)) {
        /* {S!d70}Product: '<S86>/delta fall limit' incorporates:
 *  Constant: '<S71>/Constant3'
 *  SampleTimeMath: '<S86>/sample time'
 *
 * About '<S86>/sample time':
 *  y = K where K = ( w * Ts )
 */
        zerrint = Model_6DOF_P.Constant3_Value * Model_6DOF_P.sampletime_WtEt;
        /* {S!d72}Switch: '<S87>/Switch' incorporates:
 *  RelationalOperator: '<S87>/UpperRelop'
 */
        if (zerr < zerrint) {
            dh = zerrint;
        } else {
            dh = zerr;
        }
        /* {E!d72}End of Switch: '<S87>/Switch' */
    }
    /* {E!d74}End of Switch: '<S87>/Switch2' */

    /* {S!d76}Sum: '<S86>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S86>/Delay Input2'
 */
    rtb_DifferenceInputs2 = dh + Model_6DOF_DW.DelayInput2_DSTATE;
    /* {S!d84}Saturate: '<S71>/Max Mass Change' */
    if (rtb_DifferenceInputs2 > Model_6DOF_P.MaxMassChange_UpperSat) {
        /* {S!d78}Saturate: '<S71>/Max Mass Change' */
        Model_6DOF_B.dmasskg = Model_6DOF_P.MaxMassChange_UpperSat;
    } else if (rtb_DifferenceInputs2 < Model_6DOF_P.MaxMassChange_LowerSat) {
        /* {S!d80}Saturate: '<S71>/Max Mass Change' */
        Model_6DOF_B.dmasskg = Model_6DOF_P.MaxMassChange_LowerSat;
    } else {
        /* {S!d82}Saturate: '<S71>/Max Mass Change' */
        Model_6DOF_B.dmasskg = rtb_DifferenceInputs2;
    }
    /* {E!d84}End of Saturate: '<S71>/Max Mass Change' */
}
/* {S!d88}SignalConversion generated from: '<S20>/ SFunction ' incorporates:
 *  MATLAB Function: '<S9>/MATLAB Function1'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d88}End of SignalConversion generated from: '<S20>/ SFunction ' */

/* {S!d90}MATLAB Function: '<S9>/MATLAB Function1' */
u_ship[0] = rtb_TmpSignalConversionAtSFun_b[0];
u_ship[1] = rtb_TmpSignalConversionAtSFun_b[1];
u_ship[2] = rtb_TmpSignalConversionAtSFun_b[2];
/* {S!d92}Clock: '<S30>/Clock' incorporates:
 *  Derivative: '<S15>/Derivative1'
 */
absx31 = Model_6DOF_M->Timing.t[0];
/* {S!d94}Clock: '<S30>/Clock' */
rtb_Clock = absx31;
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d96}MATLAB Function: '<S30>/Wave Properties' incorporates:
 *  Constant: '<S3>/Constant1'
 */
    if (Model_6DOF_P.Seastate == 2.0) {
        zerr = 87.8;
        Model_6DOF_B.A_wave = 0.15;
        zerrint = 6.2831853071795862 / zerr;
    } else if (Model_6DOF_P.Seastate == 3.0) {
        zerr = 87.8;
        Model_6DOF_B.A_wave = 0.44;
        zerrint = 6.2831853071795862 / zerr;
    } else if (Model_6DOF_P.Seastate == 4.0) {
        zerr = 120.9;
        Model_6DOF_B.A_wave = 0.94;
        zerrint = 6.2831853071795862 / zerr;
    } else if (Model_6DOF_P.Seastate == 5.0) {
        zerr = 140.9;
        Model_6DOF_B.A_wave = 1.625;
        zerrint = 6.2831853071795862 / zerr;
    } else if (Model_6DOF_P.Seastate == 6.0) {
        zerr = 240.1;
        Model_6DOF_B.A_wave = 2.5;
        zerrint = 6.2831853071795862 / zerr;
    } else if (Model_6DOF_P.Seastate == 7.0) {
        zerr = 351.3;
        Model_6DOF_B.A_wave = 3.75;
        zerrint = 6.2831853071795862 / zerr;
    } else {
        zerr = 0.0;
        Model_6DOF_B.A_wave = 0.0;
        zerrint = 0.0;
    }
    Model_6DOF_B.w_wave = 9.81 * zerrint;
    Model_6DOF_B.w_wave = sqrt(Model_6DOF_B.w_wave);
    Model_6DOF_B.L_wave = zerr;
    Model_6DOF_B.k_wave = zerrint;
    /* {E!d96}End of MATLAB Function: '<S30>/Wave Properties' */
}
/* {S!d98}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' incorporates:
 *  Constant: '<S15>/beta_wave'
 *  Constant: '<S15>/phi_wave'
 *  Constant: '<S30>/X_SP1'
 *  Constant: '<S30>/X_SP2'
 *  Constant: '<S30>/X_SP3'
 *  Constant: '<S30>/X_SP4'
 *  Constant: '<S30>/X_XB'
 *  MATLAB Function: '<S30>/Sectional Position Vectors'
 *  MATLAB Function: '<S30>/Sectional Wave Particle & Rigid Body Velocities'
 *  MATLAB Function: '<S30>/Wave particle velocity at hull CG'
 *  MATLAB Function: '<S38>/MATLAB Function1'
 *  MATLAB Function: '<S38>/MATLAB Function3'
 *  MATLAB Function: '<S38>/MATLAB Function4'
 *  MATLAB Function: '<S38>/MATLAB Function5'
 *  MATLAB Function: '<S39>/MATLAB Function1'
 *  MATLAB Function: '<S40>/MATLAB Function1'
 *  MATLAB Function: '<S43>/MATLAB Function1'
 *  MATLAB Function: '<S43>/MATLAB Function4'
 *  MATLAB Function: '<S64>/MATLAB Function2'
 */
zerr = cos(Model_6DOF_B.Integrator_d[5]);
zerrint = sin(Model_6DOF_B.Integrator_d[3]);
psierr_tmp_tmp = sin(Model_6DOF_B.Integrator_d[5]);
thetaerrint = cos(Model_6DOF_B.Integrator_d[3]);
zerrint_tmp = sin(Model_6DOF_B.Integrator_d[4]);
thetaerr = cos(Model_6DOF_B.Integrator_d[4]);
RMat_tmp[0] = thetaerr * zerr;
RMat_tmp[3] = zerrint * zerrint_tmp * zerr + -thetaerrint * psierr_tmp_tmp;
RMat_tmp[6] = thetaerrint * zerrint_tmp * zerr + zerrint * psierr_tmp_tmp;
RMat_tmp[1] = thetaerr * psierr_tmp_tmp;
RMat_tmp_tmp_1 = zerrint * zerrint_tmp;
RMat_tmp[4] = RMat_tmp_tmp_1 * psierr_tmp_tmp + thetaerrint * zerr;
RMat_tmp_tmp_2 = thetaerrint * zerrint_tmp;
RMat_tmp[7] = RMat_tmp_tmp_2 * psierr_tmp_tmp + -zerrint * zerr;
RMat_tmp[2] = -zerrint_tmp;
RMat_tmp_tmp_3 = zerrint * thetaerr;
RMat_tmp[5] = RMat_tmp_tmp_3;
RMat_tmp[8] = thetaerrint * thetaerr;
Omega_s[0] = Model_6DOF_B.Integrator_d[0];
Omega_s[1] = Model_6DOF_B.Integrator_d[1];
Omega_s[2] = Model_6DOF_B.Integrator_d[2];
for (c_ix = 0; c_ix < 3; c_ix++) {
    dv = Omega_s[c_ix];
    rtb_UkYk1_l = RMat_tmp[c_ix];
    psierr_tmp = rtb_UkYk1_l * Model_6DOF_P.X_SP1_Value_c[0];
    psierrint = rtb_UkYk1_l * Model_6DOF_P.X_SP2_Value_j[0];
    arg5 = rtb_UkYk1_l * Model_6DOF_P.X_SP3_Value_n[0];
    Mz_total = rtb_UkYk1_l * Model_6DOF_P.X_SP4_Value_f[0];
    My_total = rtb_UkYk1_l * Model_6DOF_P.X_XB_Value_i[0];
    rtb_UkYk1_l = RMat_tmp[c_ix + 3];
    psierr_tmp += rtb_UkYk1_l * Model_6DOF_P.X_SP1_Value_c[1];
    psierrint += rtb_UkYk1_l * Model_6DOF_P.X_SP2_Value_j[1];
    arg5 += rtb_UkYk1_l * Model_6DOF_P.X_SP3_Value_n[1];
    Mz_total += rtb_UkYk1_l * Model_6DOF_P.X_SP4_Value_f[1];
    My_total += rtb_UkYk1_l * Model_6DOF_P.X_XB_Value_i[1];
    rtb_UkYk1_l = RMat_tmp[c_ix + 6];
    X1e[c_ix] = (rtb_UkYk1_l * Model_6DOF_P.X_SP1_Value_c[2] + psierr_tmp) + dv;
    X2e[c_ix] = (rtb_UkYk1_l * Model_6DOF_P.X_SP2_Value_j[2] + psierrint) + dv;
    X3e[c_ix] = (rtb_UkYk1_l * Model_6DOF_P.X_SP3_Value_n[2] + arg5) + dv;
    X4e[c_ix] = (rtb_UkYk1_l * Model_6DOF_P.X_SP4_Value_f[2] + Mz_total) + dv;
    XBe[c_ix] = (rtb_UkYk1_l * Model_6DOF_P.X_XB_Value_i[2] + My_total) + dv;
}
dv = exp(Model_6DOF_B.k_wave * X1e[2]);
rtb_Add_l_idx_0 = Model_6DOF_B.w_wave * rtb_Clock;
psierr_tmp = (Model_6DOF_B.k_wave * X1e[0] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
psierr = cos(psierr_tmp);
rtb_UkYk1_l = cos(3.1415926535897931 * Model_6DOF_P.beta_wave_Value);
rtb_deltafalllimit_h = sin(3.1415926535897931 * Model_6DOF_P.beta_wave_Value);
Model_6DOF_inv_m(RMat_tmp, RMATD);
/* {S!d100}MATLAB Function: '<S9>/MATLAB Function1' incorporates:
 *  Constant: '<S9>/X_SP1'
 */
tmp[0] = Model_6DOF_P.X_SP1_Value[1] * rtb_TmpSignalConversionAtSFun_b[5] - Model_6DOF_P.X_SP1_Value[2] * rtb_TmpSignalConversionAtSFun_b[4];
tmp[1] = Model_6DOF_P.X_SP1_Value[2] * rtb_TmpSignalConversionAtSFun_b[3] - Model_6DOF_P.X_SP1_Value[0] * rtb_TmpSignalConversionAtSFun_b[5];
tmp[2] = Model_6DOF_P.X_SP1_Value[0] * rtb_TmpSignalConversionAtSFun_b[4] - Model_6DOF_P.X_SP1_Value[1] * rtb_TmpSignalConversionAtSFun_b[3];
/* {S!d102}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' incorporates:
 *  Constant: '<S15>/phi_wave'
 *  MATLAB Function: '<S30>/Sectional Wave Particle & Rigid Body Velocities'
 *  MATLAB Function: '<S30>/Wave particle velocity at hull CG'
 */
tmp_a = -Model_6DOF_B.A_wave * Model_6DOF_B.w_wave;
tmp_5 = tmp_a * dv * psierr * rtb_UkYk1_l;
tmp_9 = Model_6DOF_B.A_wave * Model_6DOF_B.w_wave;
arg4 = tmp_9 * dv * psierr * rtb_deltafalllimit_h;
tmp_6 = tmp_a * dv * sin(psierr_tmp);
dv = exp(Model_6DOF_B.k_wave * X2e[2]);
psierr_tmp = (Model_6DOF_B.k_wave * X2e[0] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
psierr = cos(psierr_tmp);
/* {S!d104}MATLAB Function: '<S9>/MATLAB Function1' incorporates:
 *  Constant: '<S9>/X_SP2'
 */
tmp_0[0] = Model_6DOF_P.X_SP2_Value[1] * rtb_TmpSignalConversionAtSFun_b[5] - Model_6DOF_P.X_SP2_Value[2] * rtb_TmpSignalConversionAtSFun_b[4];
tmp_0[1] = Model_6DOF_P.X_SP2_Value[2] * rtb_TmpSignalConversionAtSFun_b[3] - Model_6DOF_P.X_SP2_Value[0] * rtb_TmpSignalConversionAtSFun_b[5];
tmp_0[2] = Model_6DOF_P.X_SP2_Value[0] * rtb_TmpSignalConversionAtSFun_b[4] - Model_6DOF_P.X_SP2_Value[1] * rtb_TmpSignalConversionAtSFun_b[3];
/* {S!d106}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' incorporates:
 *  Constant: '<S15>/phi_wave'
 */
dh = tmp_a * dv * psierr * rtb_UkYk1_l;
absxk = tmp_9 * dv * psierr * rtb_deltafalllimit_h;
arg1 = -Model_6DOF_B.A_wave * Model_6DOF_B.w_wave * exp(Model_6DOF_B.k_wave * X2e[2]) * sin(psierr_tmp);
dv = exp(Model_6DOF_B.k_wave * X3e[2]);
psierr_tmp = (Model_6DOF_B.k_wave * X3e[0] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
psierr = cos(psierr_tmp);
/* {S!d108}MATLAB Function: '<S9>/MATLAB Function1' incorporates:
 *  Constant: '<S9>/X_SP3'
 */
tmp_1[0] = Model_6DOF_P.X_SP3_Value[1] * rtb_TmpSignalConversionAtSFun_b[5] - Model_6DOF_P.X_SP3_Value[2] * rtb_TmpSignalConversionAtSFun_b[4];
tmp_1[1] = Model_6DOF_P.X_SP3_Value[2] * rtb_TmpSignalConversionAtSFun_b[3] - Model_6DOF_P.X_SP3_Value[0] * rtb_TmpSignalConversionAtSFun_b[5];
tmp_1[2] = Model_6DOF_P.X_SP3_Value[0] * rtb_TmpSignalConversionAtSFun_b[4] - Model_6DOF_P.X_SP3_Value[1] * rtb_TmpSignalConversionAtSFun_b[3];
/* {S!d110}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' incorporates:
 *  Constant: '<S15>/phi_wave'
 */
arg2 = tmp_a * dv * psierr * rtb_UkYk1_l;
arg3 = tmp_9 * dv * psierr * rtb_deltafalllimit_h;
tmp_7 = -Model_6DOF_B.A_wave * Model_6DOF_B.w_wave * exp(Model_6DOF_B.k_wave * X3e[2]) * sin(psierr_tmp);
dv = exp(Model_6DOF_B.k_wave * X4e[2]);
psierr_tmp = (Model_6DOF_B.k_wave * X4e[0] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
psierr = cos(psierr_tmp);
/* {S!d112}MATLAB Function: '<S9>/MATLAB Function1' incorporates:
 *  Constant: '<S9>/X_SP4'
 */
tmp_2[0] = Model_6DOF_P.X_SP4_Value[1] * rtb_TmpSignalConversionAtSFun_b[5] - Model_6DOF_P.X_SP4_Value[2] * rtb_TmpSignalConversionAtSFun_b[4];
tmp_2[1] = Model_6DOF_P.X_SP4_Value[2] * rtb_TmpSignalConversionAtSFun_b[3] - Model_6DOF_P.X_SP4_Value[0] * rtb_TmpSignalConversionAtSFun_b[5];
tmp_2[2] = Model_6DOF_P.X_SP4_Value[0] * rtb_TmpSignalConversionAtSFun_b[4] - Model_6DOF_P.X_SP4_Value[1] * rtb_TmpSignalConversionAtSFun_b[3];
/* {S!d114}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' incorporates:
 *  Constant: '<S15>/phi_wave'
 */
rtb_Sign1_hb = tmp_a * dv * psierr * rtb_UkYk1_l;
rtb_dpeth = tmp_9 * dv * psierr * rtb_deltafalllimit_h;
tmp_8 = -Model_6DOF_B.A_wave * Model_6DOF_B.w_wave * exp(Model_6DOF_B.k_wave * X4e[2]) * sin(psierr_tmp);
dv = exp(Model_6DOF_B.k_wave * XBe[2]);
psierr_tmp = (Model_6DOF_B.k_wave * XBe[0] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
psierr = cos(psierr_tmp);
/* {S!d116}MATLAB Function: '<S9>/MATLAB Function1' incorporates:
 *  Constant: '<S9>/X_XB'
 */
tmp_3[0] = Model_6DOF_P.X_XB_Value[1] * rtb_TmpSignalConversionAtSFun_b[5] - Model_6DOF_P.X_XB_Value[2] * rtb_TmpSignalConversionAtSFun_b[4];
tmp_3[1] = Model_6DOF_P.X_XB_Value[2] * rtb_TmpSignalConversionAtSFun_b[3] - Model_6DOF_P.X_XB_Value[0] * rtb_TmpSignalConversionAtSFun_b[5];
tmp_3[2] = Model_6DOF_P.X_XB_Value[0] * rtb_TmpSignalConversionAtSFun_b[4] - Model_6DOF_P.X_XB_Value[1] * rtb_TmpSignalConversionAtSFun_b[3];
/* {S!d118}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' */
rtb_Product3_a = tmp_a * dv * psierr * rtb_UkYk1_l;
psierr = tmp_9 * dv * psierr * rtb_deltafalllimit_h;
rtb_Sign_o = -Model_6DOF_B.A_wave * Model_6DOF_B.w_wave * exp(Model_6DOF_B.k_wave * XBe[2]) * sin(psierr_tmp);
/* {S!d120}MATLAB Function: '<S9>/MATLAB Function' */
dXiuq = 0.0;
dv = 0.0;
for (p1_0 = 0; p1_0 < 3; p1_0++) {
    /* {S!d122}MATLAB Function: '<S9>/MATLAB Function1' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    rtb_Add_l_idx_5 = u_ship[p1_0];
    /* {S!d124}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' */
    RMATD_0 = RMATD[p1_0];
    /* {S!d126}Sum: '<S9>/Add' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    psierr_tmp = RMATD_0 * tmp_5;
    /* {S!d128}Sum: '<S9>/Add1' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    psierrint = RMATD_0 * dh;
    /* {S!d130}Sum: '<S9>/Add2' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    arg5 = RMATD_0 * arg2;
    /* {S!d132}Sum: '<S9>/Add3' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    Mz_total = RMATD_0 * rtb_Sign1_hb;
    /* {S!d134}Sum: '<S9>/Add4' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    My_total = RMATD_0 * rtb_Product3_a;
    /* {S!d136}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' */
    RMATD_0 = RMATD[p1_0 + 3];
    /* {S!d138}Sum: '<S9>/Add' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    psierr_tmp += RMATD_0 * arg4;
    /* {S!d140}Sum: '<S9>/Add1' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    psierrint += RMATD_0 * absxk;
    /* {S!d142}Sum: '<S9>/Add2' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    arg5 += RMATD_0 * arg3;
    /* {S!d144}Sum: '<S9>/Add3' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    Mz_total += RMATD_0 * rtb_dpeth;
    /* {S!d146}Sum: '<S9>/Add4' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    My_total += RMATD_0 * psierr;
    /* {S!d148}MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages' */
    RMATD_0 = RMATD[p1_0 + 6];
    /* {S!d150}Sum: '<S9>/Add' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 *  MATLAB Function: '<S9>/MATLAB Function1'
 */
    psierr_tmp = (RMATD_0 * tmp_6 + psierr_tmp) + (-rtb_Add_l_idx_5 + tmp[p1_0]);
    /* {S!d152}Sum: '<S9>/Add1' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 *  MATLAB Function: '<S9>/MATLAB Function1'
 */
    X1e[p1_0] = (RMATD_0 * arg1 + psierrint) + (-rtb_Add_l_idx_5 + tmp_0[p1_0]);
    /* {S!d154}Sum: '<S9>/Add2' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 *  MATLAB Function: '<S9>/MATLAB Function1'
 */
    X2e[p1_0] = (RMATD_0 * tmp_7 + arg5) + (-rtb_Add_l_idx_5 + tmp_1[p1_0]);
    /* {S!d156}Sum: '<S9>/Add3' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 *  MATLAB Function: '<S9>/MATLAB Function1'
 */
    X3e[p1_0] = (RMATD_0 * tmp_8 + Mz_total) + (-rtb_Add_l_idx_5 + tmp_2[p1_0]);
    /* {S!d158}Sum: '<S9>/Add4' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 *  MATLAB Function: '<S9>/MATLAB Function1'
 */
    X4e[p1_0] = (RMATD_0 * rtb_Sign_o + My_total) + (-rtb_Add_l_idx_5 + tmp_3[p1_0]);
    /* {S!d160}MATLAB Function: '<S9>/MATLAB Function' incorporates:
 *  Constant: '<S9>/n1'
 *  Constant: '<S9>/nh'
 */
    dXiuq += Model_6DOF_P.nh_Value[p1_0] * psierr_tmp;
    dv += Model_6DOF_P.n1_Value[p1_0] * psierr_tmp;
    /* {S!d162}Sum: '<S9>/Add' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
    rtb_Add[p1_0] = psierr_tmp;
}
/* {S!d164}MATLAB Function: '<S9>/MATLAB Function' incorporates:
 *  Constant: '<S9>/n1'
 *  Constant: '<S9>/n2'
 *  Constant: '<S9>/n3'
 *  Constant: '<S9>/n4'
 *  Constant: '<S9>/n5'
 *  Constant: '<S9>/nh'
 */
u_ship[0] = dXiuq * Model_6DOF_P.nh_Value[0] + dv * Model_6DOF_P.n1_Value[0];
u_ship[1] = dXiuq * Model_6DOF_P.nh_Value[1] + dv * Model_6DOF_P.n1_Value[1];
u_ship[2] = dXiuq * Model_6DOF_P.nh_Value[2] + dv * Model_6DOF_P.n1_Value[2];
dv = (Model_6DOF_P.nh_Value[0] * X1e[0] + Model_6DOF_P.nh_Value[1] * X1e[1]) + Model_6DOF_P.nh_Value[2] * X1e[2];
psierr = (Model_6DOF_P.n2_Value[0] * X1e[0] + Model_6DOF_P.n2_Value[1] * X1e[1]) + Model_6DOF_P.n2_Value[2] * X1e[2];
w_ship[0] = dv * Model_6DOF_P.nh_Value[0] + psierr * Model_6DOF_P.n2_Value[0];
w_ship[1] = dv * Model_6DOF_P.nh_Value[1] + psierr * Model_6DOF_P.n2_Value[1];
w_ship[2] = dv * Model_6DOF_P.nh_Value[2] + psierr * Model_6DOF_P.n2_Value[2];
dv = (Model_6DOF_P.nh_Value[0] * X2e[0] + Model_6DOF_P.nh_Value[1] * X2e[1]) + Model_6DOF_P.nh_Value[2] * X2e[2];
psierr = (Model_6DOF_P.n3_Value[0] * X2e[0] + Model_6DOF_P.n3_Value[1] * X2e[1]) + Model_6DOF_P.n3_Value[2] * X2e[2];
i = 3;
XBe[0] = dv * Model_6DOF_P.nh_Value[0] + psierr * Model_6DOF_P.n3_Value[0];
XBe[1] = dv * Model_6DOF_P.nh_Value[1] + psierr * Model_6DOF_P.n3_Value[1];
XBe[2] = dv * Model_6DOF_P.nh_Value[2] + psierr * Model_6DOF_P.n3_Value[2];
dv = (Model_6DOF_P.nh_Value[0] * X3e[0] + Model_6DOF_P.nh_Value[1] * X3e[1]) + Model_6DOF_P.nh_Value[2] * X3e[2];
psierr = (Model_6DOF_P.n4_Value[0] * X3e[0] + Model_6DOF_P.n4_Value[1] * X3e[1]) + Model_6DOF_P.n4_Value[2] * X3e[2];
np4[0] = dv * Model_6DOF_P.nh_Value[0] + psierr * Model_6DOF_P.n4_Value[0];
np4[1] = dv * Model_6DOF_P.nh_Value[1] + psierr * Model_6DOF_P.n4_Value[1];
np4[2] = dv * Model_6DOF_P.nh_Value[2] + psierr * Model_6DOF_P.n4_Value[2];
dv = (Model_6DOF_P.nh_Value[0] * X4e[0] + Model_6DOF_P.nh_Value[1] * X4e[1]) + Model_6DOF_P.nh_Value[2] * X4e[2];
psierr = (Model_6DOF_P.n5_Value[0] * X4e[0] + Model_6DOF_P.n5_Value[1] * X4e[1]) + Model_6DOF_P.n5_Value[2] * X4e[2];
npB[0] = dv * Model_6DOF_P.nh_Value[0] + psierr * Model_6DOF_P.n5_Value[0];
npB[1] = dv * Model_6DOF_P.nh_Value[1] + psierr * Model_6DOF_P.n5_Value[1];
npB[2] = dv * Model_6DOF_P.nh_Value[2] + psierr * Model_6DOF_P.n5_Value[2];
dv = Model_6DOF_norm_m(rtb_Add);
arg1 = ((u_ship[0] * rtb_Add[0] + u_ship[1] * rtb_Add[1]) + u_ship[2] * rtb_Add[2]) / (Model_6DOF_norm_m(u_ship) * dv);
psierr = Model_6DOF_norm_m(X1e);
arg2 = ((w_ship[0] * X1e[0] + w_ship[1] * X1e[1]) + w_ship[2] * X1e[2]) / (Model_6DOF_norm_m(w_ship) * psierr);
psierrint = Model_6DOF_norm_m(X2e);
arg3 = ((XBe[0] * X2e[0] + XBe[1] * X2e[1]) + XBe[2] * X2e[2]) / (Model_6DOF_norm_m(XBe) * psierrint);
dh = Model_6DOF_norm_m(X3e);
arg4 = ((np4[0] * X3e[0] + np4[1] * X3e[1]) + np4[2] * X3e[2]) / (Model_6DOF_norm_m(np4) * dh);
absxk = Model_6DOF_norm_m(X4e);
arg5 = ((npB[0] * X4e[0] + npB[1] * X4e[1]) + npB[2] * X4e[2]) / (Model_6DOF_norm_m(npB) * absxk);
if (arg1 >= 1.0) {
    rtb_aX[0] = 0.0;
} else {
    rtb_aX[0] = acos(arg1) * 180.0 / 3.1415926535897931 * 1.4142135623730951;
}
if (arg2 >= 1.0) {
    rtb_aX[1] = 0.0;
} else {
    rtb_aX[1] = acos(arg2) * 180.0 / 3.1415926535897931 * 1.4142135623730951;
}
if (arg3 >= 1.0) {
    rtb_aX[2] = 0.0;
} else {
    rtb_aX[2] = acos(arg3) * 180.0 / 3.1415926535897931 * 1.4142135623730951;
}
if (arg4 >= 1.0) {
    rtb_aX[3] = 0.0;
} else {
    rtb_aX[3] = acos(arg4) * 180.0 / 3.1415926535897931 * 1.4142135623730951;
}
if (arg5 >= 1.0) {
    rtb_aX[4] = 0.0;
} else {
    rtb_aX[4] = acos(arg5) * 180.0 / 3.1415926535897931;
}
IP[0] = ((Model_6DOF_P.n1_Value[1] * Model_6DOF_P.nh_Value[2] - Model_6DOF_P.nh_Value[1] * Model_6DOF_P.n1_Value[2]) * rtb_Add[0] + (Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n1_Value[2] - Model_6DOF_P.n1_Value[0] * Model_6DOF_P.nh_Value[2]) * rtb_Add[1]) + (Model_6DOF_P.n1_Value[0] * Model_6DOF_P.nh_Value[1] - Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n1_Value[1]) * rtb_Add[2];
IP[1] = ((Model_6DOF_P.n2_Value[1] * Model_6DOF_P.nh_Value[2] - Model_6DOF_P.nh_Value[1] * Model_6DOF_P.n2_Value[2]) * X1e[0] + (Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n2_Value[2] - Model_6DOF_P.n2_Value[0] * Model_6DOF_P.nh_Value[2]) * X1e[1]) + (Model_6DOF_P.n2_Value[0] * Model_6DOF_P.nh_Value[1] - Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n2_Value[1]) * X1e[2];
IP[2] = ((Model_6DOF_P.n3_Value[1] * Model_6DOF_P.nh_Value[2] - Model_6DOF_P.nh_Value[1] * Model_6DOF_P.n3_Value[2]) * X2e[0] + (Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n3_Value[2] - Model_6DOF_P.n3_Value[0] * Model_6DOF_P.nh_Value[2]) * X2e[1]) + (Model_6DOF_P.n3_Value[0] * Model_6DOF_P.nh_Value[1] - Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n3_Value[1]) * X2e[2];
IP[3] = ((Model_6DOF_P.n4_Value[1] * Model_6DOF_P.nh_Value[2] - Model_6DOF_P.nh_Value[1] * Model_6DOF_P.n4_Value[2]) * X3e[0] + (Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n4_Value[2] - Model_6DOF_P.n4_Value[0] * Model_6DOF_P.nh_Value[2]) * X3e[1]) + (Model_6DOF_P.n4_Value[0] * Model_6DOF_P.nh_Value[1] - Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n4_Value[1]) * X3e[2];
IP[4] = ((Model_6DOF_P.n5_Value[1] * Model_6DOF_P.nh_Value[2] - Model_6DOF_P.nh_Value[1] * Model_6DOF_P.n5_Value[2]) * X4e[0] + (Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n5_Value[2] - Model_6DOF_P.n5_Value[0] * Model_6DOF_P.nh_Value[2]) * X4e[1]) + (Model_6DOF_P.n5_Value[0] * Model_6DOF_P.nh_Value[1] - Model_6DOF_P.nh_Value[0] * Model_6DOF_P.n5_Value[1]) * X4e[2];
for (b_k = 0; b_k < 5; b_k++) {
    dXiuq = rtb_aX[b_k];
    if (IP[b_k] < 0.0) {
        dXiuq = -dXiuq;
    }
    rtb_aX[b_k] = dXiuq;
}
IP[0] = dv;
IP[1] = psierr;
IP[2] = psierrint;
IP[3] = dh;
IP[4] = absxk;
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d166}Product: '<S84>/delta rise limit' incorporates:
 *  Constant: '<S70>/Upper Rate limit'
 *  SampleTimeMath: '<S84>/sample time'
 *
 * About '<S84>/sample time':
 *  y = K where K = ( w * Ts )
 */
    dh = Model_6DOF_P.UpperRatelimit_Value * Model_6DOF_P.sampletime_WtEt_l;
    /* {S!d168}Sum: '<S84>/Difference Inputs1' incorporates:
 *  Constant: '<S1>/Constant1'
 *  UnitDelay: '<S84>/Delay Input2'
 */
    dv = Model_6DOF_P.Constant1_Value - Model_6DOF_DW.DelayInput2_DSTATE_o;
    /* {S!d174}Switch: '<S85>/Switch2' incorporates:
 *  RelationalOperator: '<S85>/LowerRelop1'
 */
    if (!(dv > dh)) {
        /* {S!d170}Product: '<S84>/delta fall limit' incorporates:
 *  Constant: '<S70>/Lower Rate limit'
 *  SampleTimeMath: '<S84>/sample time'
 *
 * About '<S84>/sample time':
 *  y = K where K = ( w * Ts )
 */
        psierr = Model_6DOF_P.LowerRatelimit_Value * Model_6DOF_P.sampletime_WtEt_l;
        /* {S!d172}Switch: '<S85>/Switch' incorporates:
 *  RelationalOperator: '<S85>/UpperRelop'
 */
        if (dv < psierr) {
            dh = psierr;
        } else {
            dh = dv;
        }
        /* {E!d172}End of Switch: '<S85>/Switch' */
    }
    /* {E!d174}End of Switch: '<S85>/Switch2' */

    /* {S!d176}Sum: '<S84>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S84>/Delay Input2'
 */
    rtb_DifferenceInputs2_c = dh + Model_6DOF_DW.DelayInput2_DSTATE_o;
    /* {S!d184}Saturate: '<S70>/ LCG Change Saturation' */
    if (rtb_DifferenceInputs2_c > Model_6DOF_P.LCGChangeSaturation_UpperSat) {
        /* {S!d178}Saturate: '<S70>/ LCG Change Saturation' */
        Model_6DOF_B.dLCGm = Model_6DOF_P.LCGChangeSaturation_UpperSat;
    } else if (rtb_DifferenceInputs2_c < Model_6DOF_P.LCGChangeSaturation_LowerSat) {
        /* {S!d180}Saturate: '<S70>/ LCG Change Saturation' */
        Model_6DOF_B.dLCGm = Model_6DOF_P.LCGChangeSaturation_LowerSat;
    } else {
        /* {S!d182}Saturate: '<S70>/ LCG Change Saturation' */
        Model_6DOF_B.dLCGm = rtb_DifferenceInputs2_c;
    }
    /* {E!d184}End of Saturate: '<S70>/ LCG Change Saturation' */
}
/* {S!d186}MATLAB Function: '<S30>/Wave particle velocity at hull CG' incorporates:
 *  Constant: '<S15>/phi_wave'
 *  MATLAB Function: '<S30>/Sectional Wave Particle & Rigid Body Velocities'
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
memcpy(&b_x[0], &RMat_tmp[0], 9U * sizeof(real_T));
p1_0 = 0;
p3 = 6;
dXiuq = fabs(RMat_tmp[0]);
tmp_7 = fabs(RMat_tmp[1]);
rtb_Sign1_hb = fabs(-zerrint_tmp);
if ((tmp_7 > dXiuq) && (tmp_7 > rtb_Sign1_hb)) {
    p1_0 = 3;
    i = 0;
    b_x[0] = RMat_tmp[1];
    b_x[1] = RMat_tmp[0];
    b_x[3] = RMat_tmp[4];
    b_x[4] = RMat_tmp[3];
    b_x[6] = RMat_tmp[7];
    b_x[7] = RMat_tmp[6];
} else if (rtb_Sign1_hb > dXiuq) {
    p1_0 = 6;
    p3 = 0;
    b_x[0] = -zerrint_tmp;
    b_x[2] = RMat_tmp[0];
    b_x[3] = RMat_tmp_tmp_3;
    b_x[5] = RMat_tmp[3];
    b_x[6] = RMat_tmp[8];
    b_x[8] = RMat_tmp[6];
}
b_x[1] /= b_x[0];
b_x[2] /= b_x[0];
b_x[4] -= b_x[1] * b_x[3];
b_x[5] -= b_x[2] * b_x[3];
b_x[7] -= b_x[1] * b_x[6];
b_x[8] -= b_x[2] * b_x[6];
if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = i;
    i = p3;
    p3 = itmp;
    arg4 = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = arg4;
    arg4 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = arg4;
    arg4 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = arg4;
}
b_x[5] /= b_x[4];
b_x[8] -= b_x[5] * b_x[7];
arg4 = (b_x[1] * b_x[5] - b_x[2]) / b_x[8];
arg5 = -(b_x[7] * arg4 + b_x[1]) / b_x[4];
RMATD[p1_0] = ((1.0 - b_x[3] * arg5) - b_x[6] * arg4) / b_x[0];
RMATD[p1_0 + 1] = arg5;
RMATD[p1_0 + 2] = arg4;
arg4 = -b_x[5] / b_x[8];
arg5 = (1.0 - b_x[7] * arg4) / b_x[4];
RMATD[i] = -(b_x[3] * arg5 + b_x[6] * arg4) / b_x[0];
RMATD[i + 1] = arg5;
RMATD[i + 2] = arg4;
arg4 = 1.0 / b_x[8];
arg5 = -b_x[7] * arg4 / b_x[4];
RMATD[p3] = -(b_x[3] * arg5 + b_x[6] * arg4) / b_x[0];
RMATD[p3 + 1] = arg5;
RMATD[p3 + 2] = arg4;
dv = exp(Model_6DOF_B.k_wave * Model_6DOF_B.Integrator_d[2]);
psierr_tmp = (Model_6DOF_B.k_wave * Model_6DOF_B.Integrator_d[0] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
psierr = cos(psierr_tmp);
tmp_5 = tmp_a * dv * psierr * rtb_UkYk1_l;
arg4 = tmp_9 * dv * psierr * rtb_deltafalllimit_h;
tmp_6 = -Model_6DOF_B.A_wave * Model_6DOF_B.w_wave * exp(Model_6DOF_B.k_wave * Model_6DOF_B.Integrator_d[2]) * sin(psierr_tmp);
for (c_ix = 0; c_ix < 3; c_ix++) {
    rtb_Add[c_ix] = (RMATD[c_ix + 3] * arg4 + RMATD[c_ix] * tmp_5) + RMATD[c_ix + 6] * tmp_6;
}
/* {S!d188}SignalConversion generated from: '<S21>/ SFunction ' incorporates:
 *  MATLAB Function: '<S9>/MATLAB Function2'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d188}End of SignalConversion generated from: '<S21>/ SFunction ' */

/* {S!d190}MATLAB Function: '<S9>/MATLAB Function2' */
psierr = rtb_Add[0] - rtb_TmpSignalConversionAtSFun_b[0];
psierrint = rtb_Add[1] - rtb_TmpSignalConversionAtSFun_b[1];
dh = rtb_Add[2] - rtb_TmpSignalConversionAtSFun_b[2];
Omega_s[0] = psierr;
Omega_s[1] = psierrint;
Omega_s[2] = dh;
if (fabs(psierr) <= 1.0E-8) {
    psierr = 90.0;
    dv = 90.0;
    if (psierrint < 0.0) {
        dv = -90.0;
    }
    if (dh < 0.0) {
        psierr = -90.0;
    }
} else {
    dv = -atan(psierrint / psierr) * 180.0 / 3.1415926535897931;
    psierr = atan(dh / psierr) * 180.0 / 3.1415926535897931;
}
dh = 3.3121686421112381E-170;
absxk = fabs(Omega_s[0]);
if (absxk > 3.3121686421112381E-170) {
    psierrint = 1.0;
    dh = absxk;
} else {
    arg1 = absxk / 3.3121686421112381E-170;
    psierrint = arg1 * arg1;
}
absxk = fabs(Omega_s[1]);
if (absxk > dh) {
    arg1 = dh / absxk;
    psierrint = psierrint * arg1 * arg1 + 1.0;
    dh = absxk;
} else {
    arg1 = absxk / dh;
    psierrint += arg1 * arg1;
}
absxk = fabs(Omega_s[2]);
if (absxk > dh) {
    arg1 = dh / absxk;
    psierrint = psierrint * arg1 * arg1 + 1.0;
    dh = absxk;
} else {
    arg1 = absxk / dh;
    psierrint += arg1 * arg1;
}
psierrint = dh * sqrt(psierrint);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d192}Product: '<S72>/delta rise limit' incorporates:
 *  Constant: '<S68>/Constant'
 *  SampleTimeMath: '<S72>/sample time'
 *
 * About '<S72>/sample time':
 *  y = K where K = ( w * Ts )
 */
    dh = Model_6DOF_P.Constant_Value * Model_6DOF_P.sampletime_WtEt_m;
    /* {S!d194}Sum: '<S72>/Difference Inputs1' incorporates:
 *  UnitDelay: '<S72>/Delay Input2'
 */
    absxk = rtb_dX[0] - Model_6DOF_DW.DelayInput2_DSTATE_a;
    /* {S!d200}Switch: '<S77>/Switch2' incorporates:
 *  RelationalOperator: '<S77>/LowerRelop1'
 */
    if (!(absxk > dh)) {
        /* {S!d196}Product: '<S72>/delta fall limit' incorporates:
 *  Constant: '<S68>/Constant2'
 *  SampleTimeMath: '<S72>/sample time'
 *
 * About '<S72>/sample time':
 *  y = K where K = ( w * Ts )
 */
        dh = Model_6DOF_P.Constant2_Value * Model_6DOF_P.sampletime_WtEt_m;
        /* {S!d198}Switch: '<S77>/Switch' incorporates:
 *  RelationalOperator: '<S77>/UpperRelop'
 */
        if (!(absxk < dh)) {
            dh = absxk;
        }
        /* {E!d198}End of Switch: '<S77>/Switch' */
    }
    /* {E!d200}End of Switch: '<S77>/Switch2' */

    /* {S!d202}Sum: '<S72>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S72>/Delay Input2'
 */
    rtb_DifferenceInputs2_d = dh + Model_6DOF_DW.DelayInput2_DSTATE_a;
    /* {S!d204}Saturate: '<S68>/Max Deflection' */
    if (rtb_DifferenceInputs2_d > Model_6DOF_P.MaxDeflection_UpperSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection_UpperSat;
    } else if (rtb_DifferenceInputs2_d < Model_6DOF_P.MaxDeflection_LowerSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection_LowerSat;
    } else {
        psierr_tmp = rtb_DifferenceInputs2_d;
    }
    /* {E!d204}End of Saturate: '<S68>/Max Deflection' */

    /* {S!d206}Gain: '<S68>/I-Pitch3' */
    Model_6DOF_B.IPitch3 = Model_6DOF_P.IPitch3_Gain * psierr_tmp;
    /* {S!d208}Product: '<S73>/delta rise limit' incorporates:
 *  Constant: '<S68>/Constant3'
 *  SampleTimeMath: '<S73>/sample time'
 *
 * About '<S73>/sample time':
 *  y = K where K = ( w * Ts )
 */
    arg4 = Model_6DOF_P.Constant3_Value_a * Model_6DOF_P.sampletime_WtEt_f;
    /* {S!d210}Sum: '<S73>/Difference Inputs1' incorporates:
 *  UnitDelay: '<S73>/Delay Input2'
 */
    absxk = rtb_dX[1] - Model_6DOF_DW.DelayInput2_DSTATE_i;
    /* {S!d216}Switch: '<S78>/Switch2' incorporates:
 *  RelationalOperator: '<S78>/LowerRelop1'
 */
    if (!(absxk > arg4)) {
        /* {S!d212}Product: '<S73>/delta fall limit' incorporates:
 *  Constant: '<S68>/Constant4'
 *  SampleTimeMath: '<S73>/sample time'
 *
 * About '<S73>/sample time':
 *  y = K where K = ( w * Ts )
 */
        arg1 = Model_6DOF_P.Constant4_Value * Model_6DOF_P.sampletime_WtEt_f;
        /* {S!d214}Switch: '<S78>/Switch' incorporates:
 *  RelationalOperator: '<S78>/UpperRelop'
 */
        if (absxk < arg1) {
            arg4 = arg1;
        } else {
            arg4 = absxk;
        }
        /* {E!d214}End of Switch: '<S78>/Switch' */
    }
    /* {E!d216}End of Switch: '<S78>/Switch2' */

    /* {S!d218}Sum: '<S73>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S73>/Delay Input2'
 */
    rtb_DifferenceInputs2_m = arg4 + Model_6DOF_DW.DelayInput2_DSTATE_i;
    /* {S!d220}Saturate: '<S68>/Max Deflection1' */
    if (rtb_DifferenceInputs2_m > Model_6DOF_P.MaxDeflection1_UpperSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection1_UpperSat;
    } else if (rtb_DifferenceInputs2_m < Model_6DOF_P.MaxDeflection1_LowerSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection1_LowerSat;
    } else {
        psierr_tmp = rtb_DifferenceInputs2_m;
    }
    /* {E!d220}End of Saturate: '<S68>/Max Deflection1' */

    /* {S!d222}Gain: '<S68>/I-Pitch1' */
    Model_6DOF_B.IPitch1 = Model_6DOF_P.IPitch1_Gain * psierr_tmp;
}
/* {S!d224}Sum: '<S10>/Add' */
dh = Model_6DOF_B.IPitch3 + rtb_aX[0];
/* {S!d226}Sum: '<S10>/Add1' */
absxk = Model_6DOF_B.IPitch1 + rtb_aX[1];
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d228}Product: '<S74>/delta rise limit' incorporates:
 *  Constant: '<S68>/Constant5'
 *  SampleTimeMath: '<S74>/sample time'
 *
 * About '<S74>/sample time':
 *  y = K where K = ( w * Ts )
 */
    arg4 = Model_6DOF_P.Constant5_Value * Model_6DOF_P.sampletime_WtEt_g;
    /* {S!d230}Sum: '<S74>/Difference Inputs1' incorporates:
 *  UnitDelay: '<S74>/Delay Input2'
 */
    arg1 = rtb_dX[2] - Model_6DOF_DW.DelayInput2_DSTATE_f;
    /* {S!d236}Switch: '<S79>/Switch2' incorporates:
 *  RelationalOperator: '<S79>/LowerRelop1'
 */
    if (!(arg1 > arg4)) {
        /* {S!d232}Product: '<S74>/delta fall limit' incorporates:
 *  Constant: '<S68>/Constant6'
 *  SampleTimeMath: '<S74>/sample time'
 *
 * About '<S74>/sample time':
 *  y = K where K = ( w * Ts )
 */
        arg2 = Model_6DOF_P.Constant6_Value * Model_6DOF_P.sampletime_WtEt_g;
        /* {S!d234}Switch: '<S79>/Switch' incorporates:
 *  RelationalOperator: '<S79>/UpperRelop'
 */
        if (arg1 < arg2) {
            arg4 = arg2;
        } else {
            arg4 = arg1;
        }
        /* {E!d234}End of Switch: '<S79>/Switch' */
    }
    /* {E!d236}End of Switch: '<S79>/Switch2' */

    /* {S!d238}Sum: '<S74>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S74>/Delay Input2'
 */
    rtb_DifferenceInputs2_g = arg4 + Model_6DOF_DW.DelayInput2_DSTATE_f;
    /* {S!d240}Saturate: '<S68>/Max Deflection2' */
    if (rtb_DifferenceInputs2_g > Model_6DOF_P.MaxDeflection2_UpperSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection2_UpperSat;
    } else if (rtb_DifferenceInputs2_g < Model_6DOF_P.MaxDeflection2_LowerSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection2_LowerSat;
    } else {
        psierr_tmp = rtb_DifferenceInputs2_g;
    }
    /* {E!d240}End of Saturate: '<S68>/Max Deflection2' */

    /* {S!d242}Gain: '<S68>/I-Pitch2' */
    Model_6DOF_B.IPitch2 = Model_6DOF_P.IPitch2_Gain * psierr_tmp;
    /* {S!d244}Product: '<S75>/delta rise limit' incorporates:
 *  Constant: '<S68>/Constant7'
 *  SampleTimeMath: '<S75>/sample time'
 *
 * About '<S75>/sample time':
 *  y = K where K = ( w * Ts )
 */
    arg4 = Model_6DOF_P.Constant7_Value * Model_6DOF_P.sampletime_WtEt_k;
    /* {S!d246}Sum: '<S75>/Difference Inputs1' incorporates:
 *  UnitDelay: '<S75>/Delay Input2'
 */
    arg2 = rtb_dX[3] - Model_6DOF_DW.DelayInput2_DSTATE_g;
    /* {S!d252}Switch: '<S80>/Switch2' incorporates:
 *  RelationalOperator: '<S80>/LowerRelop1'
 */
    if (!(arg2 > arg4)) {
        /* {S!d248}Product: '<S75>/delta fall limit' incorporates:
 *  Constant: '<S68>/Constant8'
 *  SampleTimeMath: '<S75>/sample time'
 *
 * About '<S75>/sample time':
 *  y = K where K = ( w * Ts )
 */
        arg3 = Model_6DOF_P.Constant8_Value * Model_6DOF_P.sampletime_WtEt_k;
        /* {S!d250}Switch: '<S80>/Switch' incorporates:
 *  RelationalOperator: '<S80>/UpperRelop'
 */
        if (arg2 < arg3) {
            arg4 = arg3;
        } else {
            arg4 = arg2;
        }
        /* {E!d250}End of Switch: '<S80>/Switch' */
    }
    /* {E!d252}End of Switch: '<S80>/Switch2' */

    /* {S!d254}Sum: '<S75>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S75>/Delay Input2'
 */
    rtb_DifferenceInputs2_k = arg4 + Model_6DOF_DW.DelayInput2_DSTATE_g;
    /* {S!d256}Saturate: '<S68>/Max Deflection3' */
    if (rtb_DifferenceInputs2_k > Model_6DOF_P.MaxDeflection3_UpperSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection3_UpperSat;
    } else if (rtb_DifferenceInputs2_k < Model_6DOF_P.MaxDeflection3_LowerSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection3_LowerSat;
    } else {
        psierr_tmp = rtb_DifferenceInputs2_k;
    }
    /* {E!d256}End of Saturate: '<S68>/Max Deflection3' */

    /* {S!d258}Gain: '<S68>/I-Pitch4' */
    Model_6DOF_B.IPitch4 = Model_6DOF_P.IPitch4_Gain * psierr_tmp;
}
/* {S!d260}Sum: '<S10>/Add2' */
arg1 = Model_6DOF_B.IPitch2 + rtb_aX[2];
/* {S!d262}Sum: '<S10>/Add3' */
arg2 = Model_6DOF_B.IPitch4 + rtb_aX[3];
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d264}Product: '<S76>/delta rise limit' incorporates:
 *  Constant: '<S68>/Constant9'
 *  SampleTimeMath: '<S76>/sample time'
 *
 * About '<S76>/sample time':
 *  y = K where K = ( w * Ts )
 */
    arg4 = Model_6DOF_P.Constant9_Value * Model_6DOF_P.sampletime_WtEt_o;
    /* {S!d266}Sum: '<S76>/Difference Inputs1' incorporates:
 *  UnitDelay: '<S76>/Delay Input2'
 */
    arg3 = rtb_dX[4] - Model_6DOF_DW.DelayInput2_DSTATE_j;
    /* {S!d272}Switch: '<S81>/Switch2' incorporates:
 *  RelationalOperator: '<S81>/LowerRelop1'
 */
    if (!(arg3 > arg4)) {
        /* {S!d268}Product: '<S76>/delta fall limit' incorporates:
 *  Constant: '<S68>/Constant10'
 *  SampleTimeMath: '<S76>/sample time'
 *
 * About '<S76>/sample time':
 *  y = K where K = ( w * Ts )
 */
        arg4 = Model_6DOF_P.Constant10_Value * Model_6DOF_P.sampletime_WtEt_o;
        /* {S!d270}Switch: '<S81>/Switch' incorporates:
 *  RelationalOperator: '<S81>/UpperRelop'
 */
        if (!(arg3 < arg4)) {
            arg4 = arg3;
        }
        /* {E!d270}End of Switch: '<S81>/Switch' */
    }
    /* {E!d272}End of Switch: '<S81>/Switch2' */

    /* {S!d274}Sum: '<S76>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S76>/Delay Input2'
 */
    rtb_DifferenceInputs2_i = arg4 + Model_6DOF_DW.DelayInput2_DSTATE_j;
    /* {S!d276}Saturate: '<S68>/Max Deflection4' */
    if (rtb_DifferenceInputs2_i > Model_6DOF_P.MaxDeflection4_UpperSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection4_UpperSat;
    } else if (rtb_DifferenceInputs2_i < Model_6DOF_P.MaxDeflection4_LowerSat) {
        psierr_tmp = Model_6DOF_P.MaxDeflection4_LowerSat;
    } else {
        psierr_tmp = rtb_DifferenceInputs2_i;
    }
    /* {E!d276}End of Saturate: '<S68>/Max Deflection4' */

    /* {S!d278}Gain: '<S68>/I-Pitch5' */
    Model_6DOF_B.IPitch5 = Model_6DOF_P.IPitch5_Gain * psierr_tmp;
}
/* {S!d280}Sum: '<S10>/Add4' */
arg3 = Model_6DOF_B.IPitch5 + rtb_aX[4];
/* {S!d282}Saturate: '<S11>/Saturation4' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation4_UpperSat) {
    arg4 = Model_6DOF_P.Saturation4_UpperSat;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation4_LowerSat) {
    arg4 = Model_6DOF_P.Saturation4_LowerSat;
} else {
    arg4 = Model_6DOF_B.Integrator_d[2];
}
/* {E!d282}End of Saturate: '<S11>/Saturation4' */

/* {S!d284}Lookup_n-D: '<S11>/K'uvw' incorporates:
 *  Abs: '<S11>/Abs2'
 *  Lookup_n-D: '<S27>/NdX2'
 */
bpIndices[0U] = plook_binx(fabs(dv), Model_6DOF_P.Kuvw_bp01Data, 3U, &tmp_8);
Vx_earth[0U] = tmp_8;
bpIndices[1U] = plook_binx(Model_6DOF_B.Integrator[0], Model_6DOF_P.Kuvw_bp02Data, 2U, &tmp_8);
Vx_earth[1U] = tmp_8;
bpIndices[2U] = plook_binx(arg4, Model_6DOF_P.Kuvw_bp03Data, 3U, &tmp_8);
Vx_earth[2U] = tmp_8;
/* {S!d286}Lookup_n-D: '<S22>/KdX1' incorporates:
 *  Lookup_n-D: '<S27>/NdX2'
 *  Sum: '<S10>/Add'
 */
bpIndices_0[0U] = plook_binx(dh, Model_6DOF_P.KdX1_bp01Data, 2U, &tmp_8);
Vr_earth[0U] = tmp_8;
bpIndices_0[1U] = plook_binx(arg4, Model_6DOF_P.KdX1_bp02Data, 3U, &tmp_8);
Vr_earth[1U] = tmp_8;
bpIndices_0[2U] = plook_binx(IP[0], Model_6DOF_P.KdX1_bp03Data, 2U, &tmp_8);
Vr_earth[2U] = tmp_8;
/* {S!d288}Lookup_n-D: '<S22>/KdX2' incorporates:
 *  Lookup_n-D: '<S27>/NdX2'
 *  Sum: '<S10>/Add1'
 */
bpIndices_1[0U] = plook_binx(absxk, Model_6DOF_P.KdX2_bp01Data, 2U, &tmp_8);
fractions[0U] = tmp_8;
bpIndices_1[1U] = plook_binx(arg4, Model_6DOF_P.KdX2_bp02Data, 3U, &tmp_8);
fractions[1U] = tmp_8;
bpIndices_1[2U] = plook_binx(IP[1], Model_6DOF_P.KdX2_bp03Data, 2U, &tmp_8);
fractions[2U] = tmp_8;
/* {S!d290}Lookup_n-D: '<S22>/KdX3' incorporates:
 *  Lookup_n-D: '<S27>/NdX2'
 *  Sum: '<S10>/Add2'
 */
bpIndices_2[0U] = plook_binx(arg1, Model_6DOF_P.KdX3_bp01Data, 2U, &tmp_8);
fractions_0[0U] = tmp_8;
bpIndices_2[1U] = plook_binx(arg4, Model_6DOF_P.KdX3_bp02Data, 3U, &tmp_8);
fractions_0[1U] = tmp_8;
bpIndices_2[2U] = plook_binx(IP[2], Model_6DOF_P.KdX3_bp03Data, 2U, &tmp_8);
fractions_0[2U] = tmp_8;
/* {S!d292}Lookup_n-D: '<S22>/KdX4' incorporates:
 *  Lookup_n-D: '<S27>/NdX2'
 *  Sum: '<S10>/Add3'
 */
bpIndices_3[0U] = plook_binx(arg2, Model_6DOF_P.KdX4_bp01Data, 2U, &tmp_8);
fractions_1[0U] = tmp_8;
bpIndices_3[1U] = plook_binx(arg4, Model_6DOF_P.KdX4_bp02Data, 3U, &tmp_8);
fractions_1[1U] = tmp_8;
bpIndices_3[2U] = plook_binx(IP[3], Model_6DOF_P.KdX4_bp03Data, 2U, &tmp_8);
fractions_1[2U] = tmp_8;
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    for (i = 0; i < 6; i++) {
        /* {S!d294}Memory: '<S65>/Memory1' */
        Model_6DOF_B.Memory1[i] = Model_6DOF_DW.Memory1_PreviousInput[i];
    }
}
/* {S!d296}MATLAB Function: '<S30>/Sectional Position Vectors' incorporates:
 *  Constant: '<S15>/CG'
 *  Constant: '<S15>/CGi'
 */
for (i = 0; i < 3; i++) {
    for (b_k = 0; b_k < 15; b_k++) {
        p1_0 = 15 * i + b_k;
        rtb_Rs[p1_0] = Model_6DOF_P.CGi_Value[p1_0] - Model_6DOF_P.Xcg[i];
    }
}
for (p1_0 = 0; p1_0 < 15; p1_0++) {
    arg4 = rtb_Rs[p1_0];
    tmp_5 = rtb_Rs[p1_0 + 15];
    psierr_tmp = rtb_Rs[p1_0 + 30];
    for (i = 0; i < 3; i++) {
        for (c_ix = 0; c_ix < 3; c_ix++) {
            X2e[c_ix] = (RMat_tmp[c_ix + 3] * tmp_5 + RMat_tmp[c_ix] * arg4) + RMat_tmp[c_ix + 6] * psierr_tmp;
        }
        rtb_Xce[p1_0 + 15 * i] = Model_6DOF_B.Integrator_d[i] + X2e[i];
    }
}
/* {S!d298}SignalConversion generated from: '<S34>/ SFunction ' incorporates:
 *  MATLAB Function: '<S30>/Sectional Wave Particle & Rigid Body Velocities'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d298}End of SignalConversion generated from: '<S34>/ SFunction ' */

/* {S!d300}MATLAB Function: '<S30>/Sectional Wave Particle & Rigid Body Velocities' incorporates:
 *  Constant: '<S15>/phi_wave'
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
Omega_s[0] = rtb_TmpSignalConversionAtSFun_b[3];
Omega_s[1] = rtb_TmpSignalConversionAtSFun_b[4];
Omega_s[2] = rtb_TmpSignalConversionAtSFun_b[5];
rtb_Add[0] = rtb_TmpSignalConversionAtSFun_b[0];
rtb_Add[1] = rtb_TmpSignalConversionAtSFun_b[1];
rtb_Add[2] = rtb_TmpSignalConversionAtSFun_b[2];
for (b_k = 0; b_k < 15; b_k++) {
    memcpy(&RMATD[0], &RMat_tmp[0], 9U * sizeof(real_T));
    p1_0 = 0;
    i = 3;
    p3 = 6;
    if ((tmp_7 > dXiuq) && (tmp_7 > rtb_Sign1_hb)) {
        p1_0 = 3;
        i = 0;
        RMATD[0] = RMat_tmp[1];
        RMATD[1] = RMat_tmp[0];
        RMATD[3] = RMat_tmp[4];
        RMATD[4] = RMat_tmp[3];
        RMATD[6] = RMat_tmp[7];
        RMATD[7] = RMat_tmp[6];
    } else if (rtb_Sign1_hb > dXiuq) {
        p1_0 = 6;
        p3 = 0;
        RMATD[0] = -zerrint_tmp;
        RMATD[2] = RMat_tmp[0];
        RMATD[3] = RMat_tmp_tmp_3;
        RMATD[5] = RMat_tmp[3];
        RMATD[6] = RMat_tmp[8];
        RMATD[8] = RMat_tmp[6];
    }
    RMATD[1] /= RMATD[0];
    RMATD[2] /= RMATD[0];
    RMATD[4] -= RMATD[1] * RMATD[3];
    RMATD[5] -= RMATD[2] * RMATD[3];
    RMATD[7] -= RMATD[1] * RMATD[6];
    RMATD[8] -= RMATD[2] * RMATD[6];
    if (fabs(RMATD[5]) > fabs(RMATD[4])) {
        itmp = i;
        i = p3;
        p3 = itmp;
        arg4 = RMATD[1];
        RMATD[1] = RMATD[2];
        RMATD[2] = arg4;
        arg4 = RMATD[4];
        RMATD[4] = RMATD[5];
        RMATD[5] = arg4;
        arg4 = RMATD[7];
        RMATD[7] = RMATD[8];
        RMATD[8] = arg4;
    }
    RMATD[5] /= RMATD[4];
    RMATD[8] -= RMATD[5] * RMATD[7];
    arg4 = (RMATD[1] * RMATD[5] - RMATD[2]) / RMATD[8];
    arg5 = -(RMATD[7] * arg4 + RMATD[1]) / RMATD[4];
    b_x[p1_0] = ((1.0 - RMATD[3] * arg5) - RMATD[6] * arg4) / RMATD[0];
    b_x[p1_0 + 1] = arg5;
    b_x[p1_0 + 2] = arg4;
    arg4 = -RMATD[5] / RMATD[8];
    arg5 = (1.0 - RMATD[7] * arg4) / RMATD[4];
    b_x[i] = -(RMATD[3] * arg5 + RMATD[6] * arg4) / RMATD[0];
    b_x[i + 1] = arg5;
    b_x[i + 2] = arg4;
    arg4 = 1.0 / RMATD[8];
    arg5 = -RMATD[7] * arg4 / RMATD[4];
    b_x[p3] = -(RMATD[3] * arg5 + RMATD[6] * arg4) / RMATD[0];
    b_x[p3 + 1] = arg5;
    b_x[p3 + 2] = arg4;
    arg4 = exp(rtb_Xce[b_k + 30] * Model_6DOF_B.k_wave);
    psierr_tmp = (Model_6DOF_B.k_wave * rtb_Xce[b_k] - rtb_Add_l_idx_0) + Model_6DOF_P.phi_wave_Value;
    arg5 = cos(psierr_tmp);
    tmp_5 = tmp_a * arg4 * arg5 * rtb_UkYk1_l;
    arg4 = tmp_9 * arg4 * arg5 * rtb_deltafalllimit_h;
    tmp_6 = exp(rtb_Xce[b_k + 30] * Model_6DOF_B.k_wave) * (-Model_6DOF_B.A_wave * Model_6DOF_B.w_wave) * sin(psierr_tmp);
    for (c_ix = 0; c_ix < 3; c_ix++) {
        rtb_Uws[b_k + 15 * c_ix] = (b_x[c_ix + 3] * arg4 + b_x[c_ix] * tmp_5) + b_x[c_ix + 6] * tmp_6;
    }
}
for (p1_0 = 0; p1_0 < 15; p1_0++) {
    X1e[0] = rtb_Rs[p1_0];
    X1e[1] = rtb_Rs[p1_0 + 15];
    X1e[2] = rtb_Rs[p1_0 + 30];
    rtb_Xce[p1_0] = (Omega_s[1] * X1e[2] - X1e[1] * Omega_s[2]) + rtb_Add[0];
    rtb_Xce[p1_0 + 15] = (X1e[0] * Omega_s[2] - Omega_s[0] * X1e[2]) + rtb_Add[1];
    rtb_Xce[p1_0 + 30] = (Omega_s[0] * X1e[1] - X1e[0] * Omega_s[1]) + rtb_Add[2];
}
for (i = 0; i < 45; i++) {
    /* {S!d302}Sum: '<S15>/Add' */
    Model_6DOF_B.Add[i] = rtb_Uws[i] - rtb_Xce[i];
}
/* {S!d304}Derivative: '<S15>/Derivative1' incorporates:
 *  Sum: '<S15>/Add'
 */
if ((Model_6DOF_DW.TimeStampA >= absx31) && (Model_6DOF_DW.TimeStampB >= absx31)) {
    memset(&rtb_Uws[0], 0, 45U * sizeof(real_T));
} else {
    rtb_UkYk1_l = Model_6DOF_DW.TimeStampA;
    lastU = &Model_6DOF_DW.LastUAtTimeA;
    if (Model_6DOF_DW.TimeStampA < Model_6DOF_DW.TimeStampB) {
        if (Model_6DOF_DW.TimeStampB < absx31) {
            rtb_UkYk1_l = Model_6DOF_DW.TimeStampB;
            lastU = &Model_6DOF_DW.LastUAtTimeB;
        }
    } else if (Model_6DOF_DW.TimeStampA >= absx31) {
        rtb_UkYk1_l = Model_6DOF_DW.TimeStampB;
        lastU = &Model_6DOF_DW.LastUAtTimeB;
    }
    rtb_UkYk1_l = absx31 - rtb_UkYk1_l;
    for (c_ix = 0; c_ix < 45; c_ix++) {
        rtb_Uws[c_ix] = (Model_6DOF_B.Add[c_ix] - (*lastU)[c_ix]) / rtb_UkYk1_l;
    }
}
/* {S!d306}MATLAB Function: '<S15>/MATLAB Function' incorporates:
 *  Constant: '<S15>/Cvm*dm'
 *  Derivative: '<S15>/Derivative1'
 */
memset(&rtb_Xce[0], 0, 45U * sizeof(real_T));
Omega_s[0] = 0.0;
rtb_Add[0] = 0.0;
Omega_s[1] = 0.0;
rtb_Add[1] = 0.0;
Omega_s[2] = 0.0;
rtb_Add[2] = 0.0;
for (b_k = 0; b_k < 15; b_k++) {
    rtb_UkYk1_l = Model_6DOF_P.Cvmdm_Value[b_k] * rtb_Uws[b_k];
    rtb_Xce[b_k] = rtb_UkYk1_l;
    Omega_s[0] += rtb_UkYk1_l;
    rtb_UkYk1_l = Model_6DOF_P.Cvmdm_Value[b_k + 15] * rtb_Uws[b_k + 15];
    rtb_Xce[b_k + 15] = rtb_UkYk1_l;
    Omega_s[1] += rtb_UkYk1_l;
    rtb_UkYk1_l = Model_6DOF_P.Cvmdm_Value[b_k + 30] * rtb_Uws[b_k + 30];
    rtb_Xce[b_k + 30] = rtb_UkYk1_l;
    Omega_s[2] += rtb_UkYk1_l;
    X3e[0] = rtb_Rs[b_k];
    X3e[1] = rtb_Rs[b_k + 15];
    X3e[2] = rtb_Rs[b_k + 30];
    X1e[0] = rtb_Xce[b_k];
    X1e[1] = rtb_Xce[b_k + 15];
    X1e[2] = rtb_Xce[b_k + 30];
    rtb_Add[0] += X3e[1] * X1e[2] - X1e[1] * X3e[2];
    rtb_Add[1] += X1e[0] * X3e[2] - X3e[0] * X1e[2];
    rtb_Add[2] += X3e[0] * X1e[1] - X1e[0] * X3e[1];
}
/* {E!d306}End of MATLAB Function: '<S15>/MATLAB Function' */
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d308}Sum: '<S30>/Add' incorporates:
 *  Constant: '<S30>/Constant1'
 *  Constant: '<S30>/Constant2'
 */
    Model_6DOF_B.Add_p = Model_6DOF_P.Constant2_Value_l5 - Model_6DOF_P.Zb;
}
Model_6DOF_emxInit_real_T_i(&mp1, 2);
Model_6DOF_emxInit_real_T_i(&mp2, 2);
Model_6DOF_emxInit_real_T_i(&mp3, 2);
Model_6DOF_emxInit_real_T_i(&nA, 2);
Model_6DOF_emxInit_real_T_i(&r1, 2);
Model_6DOF_emxInit_real_T_i(&r2, 2);
Model_6DOF_emxInit_real_T_i(&r3, 2);
/* {S!d310}MATLAB Function: '<S38>/MATLAB Function5' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant102'
 *  Constant: '<S31>/Constant103'
 *  Constant: '<S31>/Constant104'
 *  Constant: '<S31>/Constant105'
 *  Constant: '<S31>/Constant106'
 *  Constant: '<S31>/Constant107'
 */
i = mp1->size[0] * mp1->size[1];
mp1->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
mp1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1, i);
i = mp2->size[0] * mp2->size[1];
mp2->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
mp2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2, i);
i = mp3->size[0] * mp3->size[1];
mp3->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
mp3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3, i);
i = nA->size[0] * nA->size[1];
nA->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
nA->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA, i);
i = r1->size[0] * r1->size[1];
r1->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
r1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1, i);
i = r2->size[0] * r2->size[1];
r2->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
r2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2, i);
i = r3->size[0] * r3->size[1];
r3->size[0] = (int32_T)Model_6DOF_P.nt_SProot;
r3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3, i);
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_SProot; b_k++) {
    nA->data[b_k] = Model_6DOF_P.dA_SProot[b_k] * Model_6DOF_P.n_SProot[b_k];
    r1->data[b_k] = (Model_6DOF_P.vt1_SProot[b_k] + Model_6DOF_P.vt2_SProot[b_k]) * 0.5;
    r2->data[b_k] = (Model_6DOF_P.vt1_SProot[b_k] + Model_6DOF_P.vt3_SProot[b_k]) * 0.5;
    r3->data[b_k] = (Model_6DOF_P.vt2_SProot[b_k] + Model_6DOF_P.vt3_SProot[b_k]) * 0.5;
    nA->data[b_k + nA->size[0]] = Model_6DOF_P.n_SProot[b_k + 904] * Model_6DOF_P.dA_SProot[b_k];
    psierr_tmp = Model_6DOF_P.vt1_SProot[b_k + 904];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_SProot[b_k + 904];
    r1->data[b_k + r1->size[0]] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_SProot[b_k + 904];
    r2->data[b_k + r2->size[0]] = (psierr_tmp + RMATD_0) * 0.5;
    r3->data[b_k + r3->size[0]] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
    nA->data[b_k + (nA->size[0] << 1)] = Model_6DOF_P.n_SProot[b_k + 1808] * Model_6DOF_P.dA_SProot[b_k];
    psierr_tmp = Model_6DOF_P.vt1_SProot[b_k + 1808];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_SProot[b_k + 1808];
    r1->data[b_k + (r1->size[0] << 1)] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_SProot[b_k + 1808];
    r2->data[b_k + (r2->size[0] << 1)] = (psierr_tmp + RMATD_0) * 0.5;
    r3->data[b_k + (r3->size[0] << 1)] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_SProot - 1 >= 0) {
    x_e_0[0] = Model_6DOF_B.Integrator_d[0];
    x_e_0[1] = Model_6DOF_B.Integrator_d[1];
    x_e_0[2] = Model_6DOF_B.Integrator_d[2];
    x_e_1[0] = Model_6DOF_B.Integrator_d[0];
    x_e_1[1] = Model_6DOF_B.Integrator_d[1];
    x_e_1[2] = Model_6DOF_B.Integrator_d[2];
    x_e_2[0] = Model_6DOF_B.Integrator_d[0];
    x_e_2[1] = Model_6DOF_B.Integrator_d[1];
    x_e_2[2] = Model_6DOF_B.Integrator_d[2];
}
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_SProot; p1_0++) {
    psierr_tmp = r1->data[p1_0];
    RMATX_tmp_0 = r1->data[p1_0 + r1->size[0]];
    RMATX_tmp = r1->data[(r1->size[0] << 1) + p1_0];
    p1 = r2->data[p1_0];
    p2 = r2->data[p1_0 + r2->size[0]];
    z_e = r2->data[(r2->size[0] << 1) + p1_0];
    p3_0 = r3->data[p1_0];
    y_e = r3->data[p1_0 + r3->size[0]];
    x_e = r3->data[(r3->size[0] << 1) + p1_0];
    for (b_k = 0; b_k < 3; b_k++) {
        RMat_tmp_tmp = RMat_tmp[b_k + 3];
        RMat_tmp_tmp_0 = RMat_tmp[b_k + 6];
        mp1->data[p1_0 + mp1->size[0] * b_k] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[b_k] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_0[b_k];
        mp2->data[p1_0 + mp2->size[0] * b_k] = ((RMat_tmp_tmp * p2 + RMat_tmp[b_k] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_1[b_k];
        mp3->data[p1_0 + mp3->size[0] * b_k] = ((RMat_tmp_tmp * y_e + RMat_tmp[b_k] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_2[b_k];
    }
}
rtb_UkYk1_l = 0.0;
rtb_deltafalllimit_h = 0.0;
arg4 = 0.0;
arg5 = 0.0;
absx31 = 0.0;
tmp_a = 0.0;
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_SProot; p3++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1->data[(mp1->size[0] << 1) + p3] - exp(mp1->data[(mp1->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2->data[(mp2->size[0] << 1) + p3] - exp(mp2->data[(mp2->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3->data[(mp3->size[0] << 1) + p3] - exp(mp3->data[(mp3->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3->data[p3] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1->data[p3] - p2 * r2->data[p3]) - p3_0 * r3->data[p3];
    X1e[1] = (r1->data[p3 + r1->size[0]] * -p1 - r2->data[p3 + r2->size[0]] * p2) - r3->data[p3 + r3->size[0]] * p3_0;
    X1e[2] = ((r1->data[(r1->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * -p1 - (r2->data[(r2->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p2) - (r3->data[(r3->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA->data[p3];
    X2e[1] = nA->data[p3 + nA->size[0]];
    X2e[2] = nA->data[(nA->size[0] << 1) + p3];
    dXiuq = (p1 + p2) + p3_0;
    rtb_UkYk1_l += dXiuq * -nA->data[p3] / 3.0;
    rtb_deltafalllimit_h += -nA->data[p3 + nA->size[0]] * dXiuq / 3.0;
    arg4 += -nA->data[(nA->size[0] << 1) + p3] * dXiuq / 3.0;
    arg5 += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    absx31 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    tmp_a += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3);
Model_6DOF_emxFree_real_T_i(&r2);
Model_6DOF_emxFree_real_T_i(&r1);
Model_6DOF_emxFree_real_T_i(&nA);
Model_6DOF_emxFree_real_T_i(&mp3);
Model_6DOF_emxFree_real_T_i(&mp2);
Model_6DOF_emxFree_real_T_i(&mp1);
Model_6DOF_emxInit_real_T_i(&mp1_0, 2);
Model_6DOF_emxInit_real_T_i(&mp2_0, 2);
Model_6DOF_emxInit_real_T_i(&mp3_0, 2);
Model_6DOF_emxInit_real_T_i(&nA_0, 2);
Model_6DOF_emxInit_real_T_i(&r1_0, 2);
Model_6DOF_emxInit_real_T_i(&r2_0, 2);
Model_6DOF_emxInit_real_T_i(&r3_0, 2);
/* {S!d312}MATLAB Function: '<S38>/MATLAB Function1' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant90'
 *  Constant: '<S31>/Constant91'
 *  Constant: '<S31>/Constant92'
 *  Constant: '<S31>/Constant93'
 *  Constant: '<S31>/Constant94'
 *  Constant: '<S31>/Constant95'
 */
i = mp1_0->size[0] * mp1_0->size[1];
mp1_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
mp1_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_0, i);
i = mp2_0->size[0] * mp2_0->size[1];
mp2_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
mp2_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_0, i);
i = mp3_0->size[0] * mp3_0->size[1];
mp3_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
mp3_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_0, i);
i = nA_0->size[0] * nA_0->size[1];
nA_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
nA_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_0, i);
i = r1_0->size[0] * r1_0->size[1];
r1_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
r1_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_0, i);
i = r2_0->size[0] * r2_0->size[1];
r2_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
r2_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_0, i);
i = r3_0->size[0] * r3_0->size[1];
r3_0->size[0] = (int32_T)Model_6DOF_P.nt_Sail;
r3_0->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_0, i);
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_Sail; b_k++) {
    nA_0->data[b_k] = Model_6DOF_P.dA_Sail[b_k] * Model_6DOF_P.n_Sail[b_k];
    r1_0->data[b_k] = (Model_6DOF_P.vt1_Sail[b_k] + Model_6DOF_P.vt2_Sail[b_k]) * 0.5;
    r2_0->data[b_k] = (Model_6DOF_P.vt1_Sail[b_k] + Model_6DOF_P.vt3_Sail[b_k]) * 0.5;
    r3_0->data[b_k] = (Model_6DOF_P.vt2_Sail[b_k] + Model_6DOF_P.vt3_Sail[b_k]) * 0.5;
    nA_0->data[b_k + nA_0->size[0]] = Model_6DOF_P.n_Sail[b_k + 564] * Model_6DOF_P.dA_Sail[b_k];
    psierr_tmp = Model_6DOF_P.vt1_Sail[b_k + 564];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_Sail[b_k + 564];
    r1_0->data[b_k + r1_0->size[0]] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_Sail[b_k + 564];
    r2_0->data[b_k + r2_0->size[0]] = (psierr_tmp + RMATD_0) * 0.5;
    r3_0->data[b_k + r3_0->size[0]] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
    nA_0->data[b_k + (nA_0->size[0] << 1)] = Model_6DOF_P.n_Sail[b_k + 1128] * Model_6DOF_P.dA_Sail[b_k];
    psierr_tmp = Model_6DOF_P.vt1_Sail[b_k + 1128];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_Sail[b_k + 1128];
    r1_0->data[b_k + (r1_0->size[0] << 1)] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_Sail[b_k + 1128];
    r2_0->data[b_k + (r2_0->size[0] << 1)] = (psierr_tmp + RMATD_0) * 0.5;
    r3_0->data[b_k + (r3_0->size[0] << 1)] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_Sail - 1 >= 0) {
    x_e_3[0] = Model_6DOF_B.Integrator_d[0];
    x_e_3[1] = Model_6DOF_B.Integrator_d[1];
    x_e_3[2] = Model_6DOF_B.Integrator_d[2];
    x_e_4[0] = Model_6DOF_B.Integrator_d[0];
    x_e_4[1] = Model_6DOF_B.Integrator_d[1];
    x_e_4[2] = Model_6DOF_B.Integrator_d[2];
    x_e_5[0] = Model_6DOF_B.Integrator_d[0];
    x_e_5[1] = Model_6DOF_B.Integrator_d[1];
    x_e_5[2] = Model_6DOF_B.Integrator_d[2];
}
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_Sail; p1_0++) {
    psierr_tmp = r1_0->data[p1_0];
    RMATX_tmp_0 = r1_0->data[p1_0 + r1_0->size[0]];
    RMATX_tmp = r1_0->data[(r1_0->size[0] << 1) + p1_0];
    p1 = r2_0->data[p1_0];
    p2 = r2_0->data[p1_0 + r2_0->size[0]];
    z_e = r2_0->data[(r2_0->size[0] << 1) + p1_0];
    p3_0 = r3_0->data[p1_0];
    y_e = r3_0->data[p1_0 + r3_0->size[0]];
    x_e = r3_0->data[(r3_0->size[0] << 1) + p1_0];
    for (b_k = 0; b_k < 3; b_k++) {
        RMat_tmp_tmp = RMat_tmp[b_k + 3];
        RMat_tmp_tmp_0 = RMat_tmp[b_k + 6];
        mp1_0->data[p1_0 + mp1_0->size[0] * b_k] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[b_k] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_3[b_k];
        mp2_0->data[p1_0 + mp2_0->size[0] * b_k] = ((RMat_tmp_tmp * p2 + RMat_tmp[b_k] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_4[b_k];
        mp3_0->data[p1_0 + mp3_0->size[0] * b_k] = ((RMat_tmp_tmp * y_e + RMat_tmp[b_k] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_5[b_k];
    }
}
tmp_5 = 0.0;
dXiuq = 0.0;
tmp_6 = 0.0;
tmp_7 = 0.0;
tmp_8 = 0.0;
tmp_9 = 0.0;
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_Sail; p3++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_0->data[(mp1_0->size[0] << 1) + p3] - exp(mp1_0->data[(mp1_0->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_0->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_0->data[(mp2_0->size[0] << 1) + p3] - exp(mp2_0->data[(mp2_0->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_0->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_0->data[(mp3_0->size[0] << 1) + p3] - exp(mp3_0->data[(mp3_0->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_0->data[p3] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_0->data[p3] - p2 * r2_0->data[p3]) - p3_0 * r3_0->data[p3];
    X1e[1] = (r1_0->data[p3 + r1_0->size[0]] * -p1 - r2_0->data[p3 + r2_0->size[0]] * p2) - r3_0->data[p3 + r3_0->size[0]] * p3_0;
    X1e[2] = ((r1_0->data[(r1_0->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * -p1 - (r2_0->data[(r2_0->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p2) - (r3_0->data[(r3_0->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_0->data[p3];
    X2e[1] = nA_0->data[p3 + nA_0->size[0]];
    X2e[2] = nA_0->data[(nA_0->size[0] << 1) + p3];
    RMATX_tmp_0 = (p1 + p2) + p3_0;
    tmp_5 += RMATX_tmp_0 * -nA_0->data[p3] / 3.0;
    dXiuq += -nA_0->data[p3 + nA_0->size[0]] * RMATX_tmp_0 / 3.0;
    tmp_6 += -nA_0->data[(nA_0->size[0] << 1) + p3] * RMATX_tmp_0 / 3.0;
    tmp_7 += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    tmp_8 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    tmp_9 += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_0);
Model_6DOF_emxFree_real_T_i(&r2_0);
Model_6DOF_emxFree_real_T_i(&r1_0);
Model_6DOF_emxFree_real_T_i(&nA_0);
Model_6DOF_emxFree_real_T_i(&mp3_0);
Model_6DOF_emxFree_real_T_i(&mp2_0);
Model_6DOF_emxFree_real_T_i(&mp1_0);
Model_6DOF_emxInit_real_T_i(&mp1_1, 2);
Model_6DOF_emxInit_real_T_i(&mp2_1, 2);
Model_6DOF_emxInit_real_T_i(&mp3_1, 2);
Model_6DOF_emxInit_real_T_i(&nA_1, 2);
Model_6DOF_emxInit_real_T_i(&r1_1, 2);
Model_6DOF_emxInit_real_T_i(&r2_1, 2);
Model_6DOF_emxInit_real_T_i(&r3_1, 2);
/* {S!d314}MATLAB Function: '<S38>/MATLAB Function3' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant100'
 *  Constant: '<S31>/Constant101'
 *  Constant: '<S31>/Constant96'
 *  Constant: '<S31>/Constant97'
 *  Constant: '<S31>/Constant98'
 *  Constant: '<S31>/Constant99'
 */
i = mp1_1->size[0] * mp1_1->size[1];
mp1_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
mp1_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_1, i);
i = mp2_1->size[0] * mp2_1->size[1];
mp2_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
mp2_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_1, i);
i = mp3_1->size[0] * mp3_1->size[1];
mp3_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
mp3_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_1, i);
i = nA_1->size[0] * nA_1->size[1];
nA_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
nA_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_1, i);
i = r1_1->size[0] * r1_1->size[1];
r1_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
r1_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_1, i);
i = r2_1->size[0] * r2_1->size[1];
r2_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
r2_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_1, i);
i = r3_1->size[0] * r3_1->size[1];
r3_1->size[0] = (int32_T)Model_6DOF_P.nt_PH;
r3_1->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_1, i);
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_PH; b_k++) {
    nA_1->data[b_k] = Model_6DOF_P.dA_PH[b_k] * Model_6DOF_P.n_PH[b_k];
    r1_1->data[b_k] = (Model_6DOF_P.vt1_PH[b_k] + Model_6DOF_P.vt2_PH[b_k]) * 0.5;
    r2_1->data[b_k] = (Model_6DOF_P.vt1_PH[b_k] + Model_6DOF_P.vt3_PH[b_k]) * 0.5;
    r3_1->data[b_k] = (Model_6DOF_P.vt2_PH[b_k] + Model_6DOF_P.vt3_PH[b_k]) * 0.5;
    nA_1->data[b_k + nA_1->size[0]] = Model_6DOF_P.n_PH[b_k + 550] * Model_6DOF_P.dA_PH[b_k];
    psierr_tmp = Model_6DOF_P.vt1_PH[b_k + 550];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_PH[b_k + 550];
    r1_1->data[b_k + r1_1->size[0]] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_PH[b_k + 550];
    r2_1->data[b_k + r2_1->size[0]] = (psierr_tmp + RMATD_0) * 0.5;
    r3_1->data[b_k + r3_1->size[0]] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
    nA_1->data[b_k + (nA_1->size[0] << 1)] = Model_6DOF_P.n_PH[b_k + 1100] * Model_6DOF_P.dA_PH[b_k];
    psierr_tmp = Model_6DOF_P.vt1_PH[b_k + 1100];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_PH[b_k + 1100];
    r1_1->data[b_k + (r1_1->size[0] << 1)] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_PH[b_k + 1100];
    r2_1->data[b_k + (r2_1->size[0] << 1)] = (psierr_tmp + RMATD_0) * 0.5;
    r3_1->data[b_k + (r3_1->size[0] << 1)] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_PH - 1 >= 0) {
    x_e_6[0] = Model_6DOF_B.Integrator_d[0];
    x_e_6[1] = Model_6DOF_B.Integrator_d[1];
    x_e_6[2] = Model_6DOF_B.Integrator_d[2];
    x_e_7[0] = Model_6DOF_B.Integrator_d[0];
    x_e_7[1] = Model_6DOF_B.Integrator_d[1];
    x_e_7[2] = Model_6DOF_B.Integrator_d[2];
    x_e_8[0] = Model_6DOF_B.Integrator_d[0];
    x_e_8[1] = Model_6DOF_B.Integrator_d[1];
    x_e_8[2] = Model_6DOF_B.Integrator_d[2];
}
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_PH; p1_0++) {
    psierr_tmp = r1_1->data[p1_0];
    RMATX_tmp_0 = r1_1->data[p1_0 + r1_1->size[0]];
    RMATX_tmp = r1_1->data[(r1_1->size[0] << 1) + p1_0];
    p1 = r2_1->data[p1_0];
    p2 = r2_1->data[p1_0 + r2_1->size[0]];
    z_e = r2_1->data[(r2_1->size[0] << 1) + p1_0];
    p3_0 = r3_1->data[p1_0];
    y_e = r3_1->data[p1_0 + r3_1->size[0]];
    x_e = r3_1->data[(r3_1->size[0] << 1) + p1_0];
    for (b_k = 0; b_k < 3; b_k++) {
        RMat_tmp_tmp = RMat_tmp[b_k + 3];
        RMat_tmp_tmp_0 = RMat_tmp[b_k + 6];
        mp1_1->data[p1_0 + mp1_1->size[0] * b_k] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[b_k] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_6[b_k];
        mp2_1->data[p1_0 + mp2_1->size[0] * b_k] = ((RMat_tmp_tmp * p2 + RMat_tmp[b_k] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_7[b_k];
        mp3_1->data[p1_0 + mp3_1->size[0] * b_k] = ((RMat_tmp_tmp * y_e + RMat_tmp[b_k] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_8[b_k];
    }
}
rtb_Sign1_hb = 0.0;
rtb_Product3_a = 0.0;
rtb_dpeth = 0.0;
rtb_Sign_o = 0.0;
My_total = 0.0;
Mz_total = 0.0;
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_PH; p3++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_1->data[(mp1_1->size[0] << 1) + p3] - exp(mp1_1->data[(mp1_1->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_1->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_1->data[(mp2_1->size[0] << 1) + p3] - exp(mp2_1->data[(mp2_1->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_1->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_1->data[(mp3_1->size[0] << 1) + p3] - exp(mp3_1->data[(mp3_1->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_1->data[p3] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_1->data[p3] - p2 * r2_1->data[p3]) - p3_0 * r3_1->data[p3];
    X1e[1] = (r1_1->data[p3 + r1_1->size[0]] * -p1 - r2_1->data[p3 + r2_1->size[0]] * p2) - r3_1->data[p3 + r3_1->size[0]] * p3_0;
    X1e[2] = ((r1_1->data[(r1_1->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * -p1 - (r2_1->data[(r2_1->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p2) - (r3_1->data[(r3_1->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_1->data[p3];
    X2e[1] = nA_1->data[p3 + nA_1->size[0]];
    X2e[2] = nA_1->data[(nA_1->size[0] << 1) + p3];
    psierr_tmp = (p1 + p2) + p3_0;
    rtb_Sign1_hb += psierr_tmp * -nA_1->data[p3] / 3.0;
    rtb_Product3_a += -nA_1->data[p3 + nA_1->size[0]] * psierr_tmp / 3.0;
    rtb_dpeth += -nA_1->data[(nA_1->size[0] << 1) + p3] * psierr_tmp / 3.0;
    rtb_Sign_o += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    My_total += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    Mz_total += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_1);
Model_6DOF_emxFree_real_T_i(&r2_1);
Model_6DOF_emxFree_real_T_i(&r1_1);
Model_6DOF_emxFree_real_T_i(&nA_1);
Model_6DOF_emxFree_real_T_i(&mp3_1);
Model_6DOF_emxFree_real_T_i(&mp2_1);
Model_6DOF_emxFree_real_T_i(&mp1_1);
Model_6DOF_emxInit_real_T_i(&mp1_2, 2);
Model_6DOF_emxInit_real_T_i(&mp2_2, 2);
Model_6DOF_emxInit_real_T_i(&mp3_2, 2);
Model_6DOF_emxInit_real_T_i(&nA_2, 2);
Model_6DOF_emxInit_real_T_i(&r1_2, 2);
Model_6DOF_emxInit_real_T_i(&r2_2, 2);
Model_6DOF_emxInit_real_T_i(&r3_2, 2);
/* {S!d316}MATLAB Function: '<S38>/MATLAB Function4' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant1'
 *  Constant: '<S31>/Constant2'
 *  Constant: '<S31>/Constant3'
 *  Constant: '<S31>/Constant4'
 *  Constant: '<S31>/Constant5'
 *  Constant: '<S31>/Constant8'
 */
i = mp1_2->size[0] * mp1_2->size[1];
mp1_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
mp1_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_2, i);
i = mp2_2->size[0] * mp2_2->size[1];
mp2_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
mp2_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_2, i);
i = mp3_2->size[0] * mp3_2->size[1];
mp3_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
mp3_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_2, i);
i = nA_2->size[0] * nA_2->size[1];
nA_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
nA_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_2, i);
i = r1_2->size[0] * r1_2->size[1];
r1_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
r1_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_2, i);
i = r2_2->size[0] * r2_2->size[1];
r2_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
r2_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_2, i);
i = r3_2->size[0] * r3_2->size[1];
r3_2->size[0] = (int32_T)Model_6DOF_P.nt_Hull;
r3_2->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_2, i);
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_Hull; b_k++) {
    nA_2->data[b_k] = Model_6DOF_P.dA_Hull[b_k] * Model_6DOF_P.n_Hull[b_k];
    r1_2->data[b_k] = (Model_6DOF_P.vt1_Hull[b_k] + Model_6DOF_P.vt2_Hull[b_k]) * 0.5;
    r2_2->data[b_k] = (Model_6DOF_P.vt1_Hull[b_k] + Model_6DOF_P.vt3_Hull[b_k]) * 0.5;
    r3_2->data[b_k] = (Model_6DOF_P.vt2_Hull[b_k] + Model_6DOF_P.vt3_Hull[b_k]) * 0.5;
    nA_2->data[b_k + nA_2->size[0]] = Model_6DOF_P.n_Hull[b_k + 2914] * Model_6DOF_P.dA_Hull[b_k];
    psierr_tmp = Model_6DOF_P.vt1_Hull[b_k + 2914];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_Hull[b_k + 2914];
    r1_2->data[b_k + r1_2->size[0]] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_Hull[b_k + 2914];
    r2_2->data[b_k + r2_2->size[0]] = (psierr_tmp + RMATD_0) * 0.5;
    r3_2->data[b_k + r3_2->size[0]] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
    nA_2->data[b_k + (nA_2->size[0] << 1)] = Model_6DOF_P.n_Hull[b_k + 5828] * Model_6DOF_P.dA_Hull[b_k];
    psierr_tmp = Model_6DOF_P.vt1_Hull[b_k + 5828];
    rtb_Add_l_idx_5 = Model_6DOF_P.vt2_Hull[b_k + 5828];
    r1_2->data[b_k + (r1_2->size[0] << 1)] = (psierr_tmp + rtb_Add_l_idx_5) * 0.5;
    RMATD_0 = Model_6DOF_P.vt3_Hull[b_k + 5828];
    r2_2->data[b_k + (r2_2->size[0] << 1)] = (psierr_tmp + RMATD_0) * 0.5;
    r3_2->data[b_k + (r3_2->size[0] << 1)] = (rtb_Add_l_idx_5 + RMATD_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_Hull - 1 >= 0) {
    x_e_9[0] = Model_6DOF_B.Integrator_d[0];
    x_e_9[1] = Model_6DOF_B.Integrator_d[1];
    x_e_9[2] = Model_6DOF_B.Integrator_d[2];
    x_e_a[0] = Model_6DOF_B.Integrator_d[0];
    x_e_a[1] = Model_6DOF_B.Integrator_d[1];
    x_e_a[2] = Model_6DOF_B.Integrator_d[2];
    x_e_b[0] = Model_6DOF_B.Integrator_d[0];
    x_e_b[1] = Model_6DOF_B.Integrator_d[1];
    x_e_b[2] = Model_6DOF_B.Integrator_d[2];
}
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_Hull; p1_0++) {
    psierr_tmp = r1_2->data[p1_0];
    RMATX_tmp_0 = r1_2->data[p1_0 + r1_2->size[0]];
    RMATX_tmp = r1_2->data[(r1_2->size[0] << 1) + p1_0];
    p1 = r2_2->data[p1_0];
    p2 = r2_2->data[p1_0 + r2_2->size[0]];
    z_e = r2_2->data[(r2_2->size[0] << 1) + p1_0];
    p3_0 = r3_2->data[p1_0];
    y_e = r3_2->data[p1_0 + r3_2->size[0]];
    x_e = r3_2->data[(r3_2->size[0] << 1) + p1_0];
    for (b_k = 0; b_k < 3; b_k++) {
        RMat_tmp_tmp = RMat_tmp[b_k + 3];
        RMat_tmp_tmp_0 = RMat_tmp[b_k + 6];
        mp1_2->data[p1_0 + mp1_2->size[0] * b_k] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[b_k] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_9[b_k];
        mp2_2->data[p1_0 + mp2_2->size[0] * b_k] = ((RMat_tmp_tmp * p2 + RMat_tmp[b_k] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_a[b_k];
        mp3_2->data[p1_0 + mp3_2->size[0] * b_k] = ((RMat_tmp_tmp * y_e + RMat_tmp[b_k] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_b[b_k];
    }
}
Fx_total = 0.0;
rtb_Add_l_idx_1 = 0.0;
rtb_Add_l_idx_2 = 0.0;
rtb_Add_l_idx_3 = 0.0;
rtb_Add_l_idx_4 = 0.0;
rtb_Add_l_idx_5 = 0.0;
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_Hull; p3++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_2->data[(mp1_2->size[0] << 1) + p3] - exp(mp1_2->data[(mp1_2->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_2->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_2->data[(mp2_2->size[0] << 1) + p3] - exp(mp2_2->data[(mp2_2->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_2->data[p3] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_2->data[(mp3_2->size[0] << 1) + p3] - exp(mp3_2->data[(mp3_2->size[0] << 1) + p3] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_2->data[p3] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_2->data[p3] - p2 * r2_2->data[p3]) - p3_0 * r3_2->data[p3];
    X1e[1] = (r1_2->data[p3 + r1_2->size[0]] * -p1 - r2_2->data[p3 + r2_2->size[0]] * p2) - r3_2->data[p3 + r3_2->size[0]] * p3_0;
    X1e[2] = ((r1_2->data[(r1_2->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * -p1 - (r2_2->data[(r2_2->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p2) - (r3_2->data[(r3_2->size[0] << 1) + p3] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_2->data[p3];
    X2e[1] = nA_2->data[p3 + nA_2->size[0]];
    X2e[2] = nA_2->data[(nA_2->size[0] << 1) + p3];
    RMATX_tmp_tmp_0 = (p1 + p2) + p3_0;
    Fx_total += RMATX_tmp_tmp_0 * -nA_2->data[p3] / 3.0;
    rtb_Add_l_idx_1 += -nA_2->data[p3 + nA_2->size[0]] * RMATX_tmp_tmp_0 / 3.0;
    rtb_Add_l_idx_2 += -nA_2->data[(nA_2->size[0] << 1) + p3] * RMATX_tmp_tmp_0 / 3.0;
    rtb_Add_l_idx_3 += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    rtb_Add_l_idx_4 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    rtb_Add_l_idx_5 += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_2);
Model_6DOF_emxFree_real_T_i(&r2_2);
Model_6DOF_emxFree_real_T_i(&r1_2);
Model_6DOF_emxFree_real_T_i(&nA_2);
Model_6DOF_emxFree_real_T_i(&mp3_2);
Model_6DOF_emxFree_real_T_i(&mp2_2);
Model_6DOF_emxFree_real_T_i(&mp1_2);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d318}Gain: '<S31>/Gain9' incorporates:
 *  Constant: '<S31>/Constant77'
 */
    Model_6DOF_B.Gain9[0] = Model_6DOF_P.Gain9_Gain * Model_6DOF_P.Constant77_Value[0];
    Model_6DOF_B.Gain9[1] = Model_6DOF_P.Gain9_Gain * Model_6DOF_P.Constant77_Value[1];
    Model_6DOF_B.Gain9[2] = Model_6DOF_P.Gain9_Gain * Model_6DOF_P.Constant77_Value[2];
    /* {S!d320}Gain: '<S31>/Gain10' */
    Model_6DOF_B.Gain10 = Model_6DOF_P.Gain10_Gain * Model_6DOF_B.IPitch5;
}
/* {S!d322}MATLAB Function: '<S43>/MATLAB Function4' incorporates:
 *  Constant: '<S31>/Constant10'
 *  Constant: '<S31>/Constant11'
 *  Constant: '<S31>/Constant12'
 *  Constant: '<S31>/Constant76'
 *  Constant: '<S31>/Constant9'
 *  Constant: '<S43>/CG'
 *  MATLAB Function: '<S43>/MATLAB Function1'
 */
memcpy(&Model_6DOF_B.vert1[0], &Model_6DOF_P.vt1_BP1[0], 1848U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert2[0], &Model_6DOF_P.vt2_BP1[0], 1848U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert3[0], &Model_6DOF_P.vt3_BP1[0], 1848U * sizeof(real_T));
RMATX_tmp = cos(Model_6DOF_B.Gain9[2]);
RMATX_tmp_0 = sin(Model_6DOF_B.Gain9[0]);
psierr_tmp = sin(Model_6DOF_B.Gain9[2]);
p1 = cos(Model_6DOF_B.Gain9[0]);
p2 = sin(Model_6DOF_B.Gain9[1]);
p3_0 = cos(Model_6DOF_B.Gain9[1]);
RMATX[0] = p3_0 * RMATX_tmp;
RMATX[3] = RMATX_tmp_0 * p2 * RMATX_tmp + -p1 * psierr_tmp;
RMATX[6] = p1 * p2 * RMATX_tmp + RMATX_tmp_0 * psierr_tmp;
RMATX[1] = p3_0 * psierr_tmp;
RMATX[4] = sin(Model_6DOF_B.Gain9[0]) * sin(Model_6DOF_B.Gain9[1]) * psierr_tmp + p1 * RMATX_tmp;
RMATX[7] = cos(Model_6DOF_B.Gain9[0]) * sin(Model_6DOF_B.Gain9[1]) * psierr_tmp + -RMATX_tmp_0 * RMATX_tmp;
RMATX[2] = -p2;
RMATX[5] = RMATX_tmp_0 * p3_0;
RMATX[8] = p1 * p3_0;
RMATX_tmp_tmp_0 = sin(Model_6DOF_B.Gain10);
RMATX_tmp_tmp = cos(Model_6DOF_B.Gain10);
RMATD[0] = RMATX_tmp_tmp;
RMATD[3] = 0.0 * RMATX_tmp_tmp + -RMATX_tmp_tmp_0;
RMATD[6] = 0.0 * RMATX_tmp_tmp_0 + 0.0 * cos(Model_6DOF_B.Gain10);
RMATD[1] = RMATX_tmp_tmp_0;
RMATD[4] = 0.0 * sin(Model_6DOF_B.Gain10) + RMATX_tmp_tmp;
RMATD[7] = -0.0 * RMATX_tmp_tmp + 0.0 * sin(Model_6DOF_B.Gain10);
RMATD[2] = 0.0;
RMATD[5] = 0.0;
RMATD[8] = 1.0;
if ((int32_T)Model_6DOF_P.nt_BP1 - 1 >= 0) {
    Model_6DOF_inv_m(RMATX, b_x);
}
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_BP1; b_k++) {
    psierr_tmp = (Model_6DOF_B.vert1[b_k] - Model_6DOF_P.Constant76_Value[0] * 70.2) + Model_6DOF_P.CG_Value[0];
    RMATX_tmp_0 = (Model_6DOF_B.vert1[b_k + 616] - Model_6DOF_P.Constant76_Value[1] * 70.2) + Model_6DOF_P.CG_Value[1];
    RMATX_tmp = (Model_6DOF_B.vert1[b_k + 1232] - Model_6DOF_P.Constant76_Value[2] * 70.2) + Model_6DOF_P.CG_Value[2];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * RMATX_tmp_0 + b_x[c_ix] * psierr_tmp) + b_x[c_ix + 6] * RMATX_tmp;
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert2[b_k];
    x_e_1[1] = Model_6DOF_B.vert2[b_k + 616];
    x_e_1[2] = Model_6DOF_B.vert2[b_k + 1232];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        X1e[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant76_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value[c_ix];
        X3e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * X1e[1] + b_x[c_ix] * X1e[0]) + b_x[c_ix + 6] * X1e[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert3[b_k];
    x_e_1[1] = Model_6DOF_B.vert3[b_k + 616];
    x_e_1[2] = Model_6DOF_B.vert3[b_k + 1232];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_2[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant76_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value[c_ix];
        X1e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * x_e_2[1] + b_x[c_ix] * x_e_2[0]) + b_x[c_ix + 6] * x_e_2[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    for (i = 0; i < 3; i++) {
        p1_0 = 616 * i + b_k;
        Model_6DOF_B.vert1[p1_0] = (Model_6DOF_P.Constant76_Value[i] * 70.2 + X3e[i]) - Model_6DOF_P.CG_Value[i];
        Model_6DOF_B.vert2[p1_0] = (Model_6DOF_P.Constant76_Value[i] * 70.2 + X1e[i]) - Model_6DOF_P.CG_Value[i];
        Model_6DOF_B.vert3[p1_0] = (((RMATX[i + 3] * x_e_0[1] + RMATX[i] * x_e_0[0]) + RMATX[i + 6] * x_e_0[2]) + Model_6DOF_P.Constant76_Value[i] * 70.2) - Model_6DOF_P.CG_Value[i];
    }
}
Model_6DOF_emxInit_real_T_i(&mp1_3, 2);
Model_6DOF_emxInit_real_T_i(&mp2_3, 2);
Model_6DOF_emxInit_real_T_i(&mp3_3, 2);
Model_6DOF_emxInit_real_T_i(&nA_3, 2);
Model_6DOF_emxInit_real_T_i(&r1_3, 2);
Model_6DOF_emxInit_real_T_i(&r2_3, 2);
Model_6DOF_emxInit_real_T_i(&r3_3, 2);
/* {S!d324}MATLAB Function: '<S43>/MATLAB Function4' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant12'
 *  Constant: '<S31>/Constant14'
 */
i = mp1_3->size[0] * mp1_3->size[1];
mp1_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
mp1_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_3, i);
i = mp2_3->size[0] * mp2_3->size[1];
mp2_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
mp2_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_3, i);
i = mp3_3->size[0] * mp3_3->size[1];
mp3_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
mp3_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_3, i);
i = nA_3->size[0] * nA_3->size[1];
nA_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
nA_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_3, i);
i = r1_3->size[0] * r1_3->size[1];
r1_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
r1_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_3, i);
i = r2_3->size[0] * r2_3->size[1];
r2_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
r2_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_3, i);
i = r3_3->size[0] * r3_3->size[1];
r3_3->size[0] = (int32_T)Model_6DOF_P.nt_BP1;
r3_3->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_3, i);
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_BP1; p1_0++) {
    X3e[0] = Model_6DOF_B.vert2[p1_0] - Model_6DOF_B.vert1[p1_0];
    RMATX_tmp_0 = Model_6DOF_B.vert1[p1_0 + 616];
    RMATX_tmp = Model_6DOF_B.vert2[p1_0 + 616];
    X3e[1] = RMATX_tmp - RMATX_tmp_0;
    p1 = Model_6DOF_B.vert1[p1_0 + 1232];
    p2 = Model_6DOF_B.vert2[p1_0 + 1232];
    X3e[2] = p2 - p1;
    X1e[0] = Model_6DOF_B.vert3[p1_0] - Model_6DOF_B.vert1[p1_0];
    z_e = Model_6DOF_B.vert3[p1_0 + 616];
    X1e[1] = z_e - RMATX_tmp_0;
    p3_0 = Model_6DOF_B.vert3[p1_0 + 1232];
    X1e[2] = p3_0 - p1;
    y_e = X3e[1] * X1e[2] - X1e[1] * X3e[2];
    X2e[0] = y_e;
    x_e = X1e[0] * X3e[2] - X3e[0] * X1e[2];
    X2e[1] = x_e;
    RMat_tmp_tmp = X3e[0] * X1e[1] - X1e[0] * X3e[1];
    X2e[2] = RMat_tmp_tmp;
    psierr_tmp = Model_6DOF_norm_m(X2e);
    nA_3->data[p1_0] = y_e / psierr_tmp * Model_6DOF_P.dA_BP1[p1_0];
    r1_3->data[p1_0] = (Model_6DOF_B.vert1[p1_0] + Model_6DOF_B.vert2[p1_0]) * 0.5;
    r2_3->data[p1_0] = (Model_6DOF_B.vert1[p1_0] + Model_6DOF_B.vert3[p1_0]) * 0.5;
    r3_3->data[p1_0] = (Model_6DOF_B.vert2[p1_0] + Model_6DOF_B.vert3[p1_0]) * 0.5;
    nA_3->data[p1_0 + nA_3->size[0]] = x_e / psierr_tmp * Model_6DOF_P.dA_BP1[p1_0];
    r1_3->data[p1_0 + r1_3->size[0]] = (RMATX_tmp_0 + RMATX_tmp) * 0.5;
    r2_3->data[p1_0 + r2_3->size[0]] = (RMATX_tmp_0 + z_e) * 0.5;
    r3_3->data[p1_0 + r3_3->size[0]] = (RMATX_tmp + z_e) * 0.5;
    nA_3->data[p1_0 + (nA_3->size[0] << 1)] = RMat_tmp_tmp / psierr_tmp * Model_6DOF_P.dA_BP1[p1_0];
    r1_3->data[p1_0 + (r1_3->size[0] << 1)] = (p1 + p2) * 0.5;
    r2_3->data[p1_0 + (r2_3->size[0] << 1)] = (p1 + p3_0) * 0.5;
    r3_3->data[p1_0 + (r3_3->size[0] << 1)] = (p2 + p3_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_BP1 - 1 >= 0) {
    x_e_c[0] = Model_6DOF_B.Integrator_d[0];
    x_e_c[1] = Model_6DOF_B.Integrator_d[1];
    x_e_c[2] = Model_6DOF_B.Integrator_d[2];
    x_e_d[0] = Model_6DOF_B.Integrator_d[0];
    x_e_d[1] = Model_6DOF_B.Integrator_d[1];
    x_e_d[2] = Model_6DOF_B.Integrator_d[2];
    x_e_e[0] = Model_6DOF_B.Integrator_d[0];
    x_e_e[1] = Model_6DOF_B.Integrator_d[1];
    x_e_e[2] = Model_6DOF_B.Integrator_d[2];
}
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_BP1; p3++) {
    psierr_tmp = r1_3->data[p3];
    RMATX_tmp_0 = r1_3->data[p3 + r1_3->size[0]];
    RMATX_tmp = r1_3->data[(r1_3->size[0] << 1) + p3];
    p1 = r2_3->data[p3];
    p2 = r2_3->data[p3 + r2_3->size[0]];
    z_e = r2_3->data[(r2_3->size[0] << 1) + p3];
    p3_0 = r3_3->data[p3];
    y_e = r3_3->data[p3 + r3_3->size[0]];
    x_e = r3_3->data[(r3_3->size[0] << 1) + p3];
    for (i = 0; i < 3; i++) {
        RMat_tmp_tmp = RMat_tmp[i + 3];
        RMat_tmp_tmp_0 = RMat_tmp[i + 6];
        mp1_3->data[p3 + mp1_3->size[0] * i] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[i] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_c[i];
        mp2_3->data[p3 + mp2_3->size[0] * i] = ((RMat_tmp_tmp * p2 + RMat_tmp[i] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_d[i];
        mp3_3->data[p3 + mp3_3->size[0] * i] = ((RMat_tmp_tmp * y_e + RMat_tmp[i] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_e[i];
    }
}
Fx_total_0 = 0.0;
Fy_total = 0.0;
Fz_total = 0.0;
Mx_total = 0.0;
My_total_0 = 0.0;
RMATD_0 = 0.0;
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_BP1; b_k++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_3->data[(mp1_3->size[0] << 1) + b_k] - exp(mp1_3->data[(mp1_3->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_3->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_3->data[(mp2_3->size[0] << 1) + b_k] - exp(mp2_3->data[(mp2_3->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_3->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_3->data[(mp3_3->size[0] << 1) + b_k] - exp(mp3_3->data[(mp3_3->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_3->data[b_k] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_3->data[b_k] - p2 * r2_3->data[b_k]) - p3_0 * r3_3->data[b_k];
    X1e[1] = (r1_3->data[b_k + r1_3->size[0]] * -p1 - r2_3->data[b_k + r2_3->size[0]] * p2) - r3_3->data[b_k + r3_3->size[0]] * p3_0;
    X1e[2] = ((r1_3->data[(r1_3->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * -p1 - (r2_3->data[(r2_3->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p2) - (r3_3->data[(r3_3->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_3->data[b_k];
    X2e[1] = nA_3->data[b_k + nA_3->size[0]];
    X2e[2] = nA_3->data[(nA_3->size[0] << 1) + b_k];
    RMATX_tmp_0 = (p1 + p2) + p3_0;
    Fx_total_0 += RMATX_tmp_0 * -nA_3->data[b_k] / 3.0;
    Fy_total += -nA_3->data[b_k + nA_3->size[0]] * RMATX_tmp_0 / 3.0;
    Fz_total += -nA_3->data[(nA_3->size[0] << 1) + b_k] * RMATX_tmp_0 / 3.0;
    Mx_total += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    My_total_0 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    RMATD_0 += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_3);
Model_6DOF_emxFree_real_T_i(&r2_3);
Model_6DOF_emxFree_real_T_i(&r1_3);
Model_6DOF_emxFree_real_T_i(&nA_3);
Model_6DOF_emxFree_real_T_i(&mp3_3);
Model_6DOF_emxFree_real_T_i(&mp2_3);
Model_6DOF_emxFree_real_T_i(&mp1_3);
/* {S!d326}MATLAB Function: '<S43>/MATLAB Function1' incorporates:
 *  Constant: '<S31>/Constant16'
 *  Constant: '<S31>/Constant65'
 *  Constant: '<S31>/Constant66'
 *  Constant: '<S31>/Constant69'
 *  Constant: '<S31>/Constant76'
 *  Constant: '<S43>/CG'
 */
memcpy(&Model_6DOF_B.vert1[0], &Model_6DOF_P.vt1_BP2[0], 1848U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert2[0], &Model_6DOF_P.vt2_BP2[0], 1848U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert3[0], &Model_6DOF_P.vt3_BP2[0], 1848U * sizeof(real_T));
RMATD[0] = RMATX_tmp_tmp;
RMATD[3] = 0.0 * cos(Model_6DOF_B.Gain10) + -sin(Model_6DOF_B.Gain10);
RMATD[6] = 0.0 * sin(Model_6DOF_B.Gain10) + 0.0 * cos(Model_6DOF_B.Gain10);
RMATD[1] = RMATX_tmp_tmp_0;
RMATD[4] = 0.0 * sin(Model_6DOF_B.Gain10) + cos(Model_6DOF_B.Gain10);
RMATD[7] = -0.0 * cos(Model_6DOF_B.Gain10) + 0.0 * sin(Model_6DOF_B.Gain10);
RMATD[2] = 0.0;
RMATD[5] = 0.0;
RMATD[8] = 1.0;
if ((int32_T)Model_6DOF_P.nt_BP2 - 1 >= 0) {
    Model_6DOF_inv_m(RMATX, b_x);
}
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_BP2; b_k++) {
    psierr_tmp = (Model_6DOF_B.vert1[b_k] - Model_6DOF_P.Constant76_Value[0] * 70.2) + Model_6DOF_P.CG_Value[0];
    RMATX_tmp_0 = (Model_6DOF_B.vert1[b_k + 616] - Model_6DOF_P.Constant76_Value[1] * 70.2) + Model_6DOF_P.CG_Value[1];
    RMATX_tmp = (Model_6DOF_B.vert1[b_k + 1232] - Model_6DOF_P.Constant76_Value[2] * 70.2) + Model_6DOF_P.CG_Value[2];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * RMATX_tmp_0 + b_x[c_ix] * psierr_tmp) + b_x[c_ix + 6] * RMATX_tmp;
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert2[b_k];
    x_e_1[1] = Model_6DOF_B.vert2[b_k + 616];
    x_e_1[2] = Model_6DOF_B.vert2[b_k + 1232];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        X1e[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant76_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value[c_ix];
        X3e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * X1e[1] + b_x[c_ix] * X1e[0]) + b_x[c_ix + 6] * X1e[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert3[b_k];
    x_e_1[1] = Model_6DOF_B.vert3[b_k + 616];
    x_e_1[2] = Model_6DOF_B.vert3[b_k + 1232];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_2[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant76_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value[c_ix];
        X1e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * x_e_2[1] + b_x[c_ix] * x_e_2[0]) + b_x[c_ix + 6] * x_e_2[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    for (i = 0; i < 3; i++) {
        p1_0 = 616 * i + b_k;
        Model_6DOF_B.vert1[p1_0] = (Model_6DOF_P.Constant76_Value[i] * 70.2 + X3e[i]) - Model_6DOF_P.CG_Value[i];
        Model_6DOF_B.vert2[p1_0] = (Model_6DOF_P.Constant76_Value[i] * 70.2 + X1e[i]) - Model_6DOF_P.CG_Value[i];
        Model_6DOF_B.vert3[p1_0] = (((RMATX[i + 3] * x_e_0[1] + RMATX[i] * x_e_0[0]) + RMATX[i + 6] * x_e_0[2]) + Model_6DOF_P.Constant76_Value[i] * 70.2) - Model_6DOF_P.CG_Value[i];
    }
}
Model_6DOF_emxInit_real_T_i(&mp1_4, 2);
Model_6DOF_emxInit_real_T_i(&mp2_4, 2);
Model_6DOF_emxInit_real_T_i(&mp3_4, 2);
Model_6DOF_emxInit_real_T_i(&nA_4, 2);
Model_6DOF_emxInit_real_T_i(&r1_4, 2);
Model_6DOF_emxInit_real_T_i(&r2_4, 2);
Model_6DOF_emxInit_real_T_i(&r3_4, 2);
/* {S!d328}MATLAB Function: '<S43>/MATLAB Function1' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant66'
 *  Constant: '<S31>/Constant68'
 */
i = mp1_4->size[0] * mp1_4->size[1];
mp1_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
mp1_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_4, i);
i = mp2_4->size[0] * mp2_4->size[1];
mp2_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
mp2_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_4, i);
i = mp3_4->size[0] * mp3_4->size[1];
mp3_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
mp3_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_4, i);
i = nA_4->size[0] * nA_4->size[1];
nA_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
nA_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_4, i);
i = r1_4->size[0] * r1_4->size[1];
r1_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
r1_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_4, i);
i = r2_4->size[0] * r2_4->size[1];
r2_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
r2_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_4, i);
i = r3_4->size[0] * r3_4->size[1];
r3_4->size[0] = (int32_T)Model_6DOF_P.nt_BP2;
r3_4->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_4, i);
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_BP2; p1_0++) {
    X3e[0] = Model_6DOF_B.vert2[p1_0] - Model_6DOF_B.vert1[p1_0];
    RMATX_tmp_0 = Model_6DOF_B.vert1[p1_0 + 616];
    RMATX_tmp = Model_6DOF_B.vert2[p1_0 + 616];
    X3e[1] = RMATX_tmp - RMATX_tmp_0;
    p1 = Model_6DOF_B.vert1[p1_0 + 1232];
    p2 = Model_6DOF_B.vert2[p1_0 + 1232];
    X3e[2] = p2 - p1;
    X1e[0] = Model_6DOF_B.vert3[p1_0] - Model_6DOF_B.vert1[p1_0];
    z_e = Model_6DOF_B.vert3[p1_0 + 616];
    X1e[1] = z_e - RMATX_tmp_0;
    p3_0 = Model_6DOF_B.vert3[p1_0 + 1232];
    X1e[2] = p3_0 - p1;
    y_e = X3e[1] * X1e[2] - X1e[1] * X3e[2];
    X2e[0] = y_e;
    x_e = X1e[0] * X3e[2] - X3e[0] * X1e[2];
    X2e[1] = x_e;
    RMat_tmp_tmp = X3e[0] * X1e[1] - X1e[0] * X3e[1];
    X2e[2] = RMat_tmp_tmp;
    psierr_tmp = Model_6DOF_norm_m(X2e);
    nA_4->data[p1_0] = y_e / psierr_tmp * Model_6DOF_P.dA_BP2[p1_0];
    r1_4->data[p1_0] = (Model_6DOF_B.vert1[p1_0] + Model_6DOF_B.vert2[p1_0]) * 0.5;
    r2_4->data[p1_0] = (Model_6DOF_B.vert1[p1_0] + Model_6DOF_B.vert3[p1_0]) * 0.5;
    r3_4->data[p1_0] = (Model_6DOF_B.vert2[p1_0] + Model_6DOF_B.vert3[p1_0]) * 0.5;
    nA_4->data[p1_0 + nA_4->size[0]] = x_e / psierr_tmp * Model_6DOF_P.dA_BP2[p1_0];
    r1_4->data[p1_0 + r1_4->size[0]] = (RMATX_tmp_0 + RMATX_tmp) * 0.5;
    r2_4->data[p1_0 + r2_4->size[0]] = (RMATX_tmp_0 + z_e) * 0.5;
    r3_4->data[p1_0 + r3_4->size[0]] = (RMATX_tmp + z_e) * 0.5;
    nA_4->data[p1_0 + (nA_4->size[0] << 1)] = RMat_tmp_tmp / psierr_tmp * Model_6DOF_P.dA_BP2[p1_0];
    r1_4->data[p1_0 + (r1_4->size[0] << 1)] = (p1 + p2) * 0.5;
    r2_4->data[p1_0 + (r2_4->size[0] << 1)] = (p1 + p3_0) * 0.5;
    r3_4->data[p1_0 + (r3_4->size[0] << 1)] = (p2 + p3_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_BP2 - 1 >= 0) {
    x_e_f[0] = Model_6DOF_B.Integrator_d[0];
    x_e_f[1] = Model_6DOF_B.Integrator_d[1];
    x_e_f[2] = Model_6DOF_B.Integrator_d[2];
    x_e_g[0] = Model_6DOF_B.Integrator_d[0];
    x_e_g[1] = Model_6DOF_B.Integrator_d[1];
    x_e_g[2] = Model_6DOF_B.Integrator_d[2];
    x_e_h[0] = Model_6DOF_B.Integrator_d[0];
    x_e_h[1] = Model_6DOF_B.Integrator_d[1];
    x_e_h[2] = Model_6DOF_B.Integrator_d[2];
}
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_BP2; p3++) {
    psierr_tmp = r1_4->data[p3];
    RMATX_tmp_0 = r1_4->data[p3 + r1_4->size[0]];
    RMATX_tmp = r1_4->data[(r1_4->size[0] << 1) + p3];
    p1 = r2_4->data[p3];
    p2 = r2_4->data[p3 + r2_4->size[0]];
    z_e = r2_4->data[(r2_4->size[0] << 1) + p3];
    p3_0 = r3_4->data[p3];
    y_e = r3_4->data[p3 + r3_4->size[0]];
    x_e = r3_4->data[(r3_4->size[0] << 1) + p3];
    for (i = 0; i < 3; i++) {
        RMat_tmp_tmp = RMat_tmp[i + 3];
        RMat_tmp_tmp_0 = RMat_tmp[i + 6];
        mp1_4->data[p3 + mp1_4->size[0] * i] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[i] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_f[i];
        mp2_4->data[p3 + mp2_4->size[0] * i] = ((RMat_tmp_tmp * p2 + RMat_tmp[i] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_g[i];
        mp3_4->data[p3 + mp3_4->size[0] * i] = ((RMat_tmp_tmp * y_e + RMat_tmp[i] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_h[i];
    }
}
Fx_total_1 = 0.0;
Fy_total_0 = 0.0;
Fz_total_0 = 0.0;
Mx_total_0 = 0.0;
My_total_1 = 0.0;
RMATX_tmp_tmp_0 = 0.0;
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_BP2; b_k++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_4->data[(mp1_4->size[0] << 1) + b_k] - exp(mp1_4->data[(mp1_4->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_4->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_4->data[(mp2_4->size[0] << 1) + b_k] - exp(mp2_4->data[(mp2_4->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_4->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_4->data[(mp3_4->size[0] << 1) + b_k] - exp(mp3_4->data[(mp3_4->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_4->data[b_k] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_4->data[b_k] - p2 * r2_4->data[b_k]) - p3_0 * r3_4->data[b_k];
    X1e[1] = (r1_4->data[b_k + r1_4->size[0]] * -p1 - r2_4->data[b_k + r2_4->size[0]] * p2) - r3_4->data[b_k + r3_4->size[0]] * p3_0;
    X1e[2] = ((r1_4->data[(r1_4->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * -p1 - (r2_4->data[(r2_4->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p2) - (r3_4->data[(r3_4->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_4->data[b_k];
    X2e[1] = nA_4->data[b_k + nA_4->size[0]];
    X2e[2] = nA_4->data[(nA_4->size[0] << 1) + b_k];
    RMATX_tmp_0 = (p1 + p2) + p3_0;
    Fx_total_1 += RMATX_tmp_0 * -nA_4->data[b_k] / 3.0;
    Fy_total_0 += -nA_4->data[b_k + nA_4->size[0]] * RMATX_tmp_0 / 3.0;
    Fz_total_0 += -nA_4->data[(nA_4->size[0] << 1) + b_k] * RMATX_tmp_0 / 3.0;
    Mx_total_0 += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    My_total_1 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    RMATX_tmp_tmp_0 += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_4);
Model_6DOF_emxFree_real_T_i(&r2_4);
Model_6DOF_emxFree_real_T_i(&r1_4);
Model_6DOF_emxFree_real_T_i(&nA_4);
Model_6DOF_emxFree_real_T_i(&mp3_4);
Model_6DOF_emxFree_real_T_i(&mp2_4);
Model_6DOF_emxFree_real_T_i(&mp1_4);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d330}Gain: '<S31>/Gain1' incorporates:
 *  Constant: '<S31>/Constant6'
 */
    Model_6DOF_B.Gain1[0] = Model_6DOF_P.Gain1_Gain * Model_6DOF_P.Constant6_Value_h[0];
    Model_6DOF_B.Gain1[1] = Model_6DOF_P.Gain1_Gain * Model_6DOF_P.Constant6_Value_h[1];
    Model_6DOF_B.Gain1[2] = Model_6DOF_P.Gain1_Gain * Model_6DOF_P.Constant6_Value_h[2];
    /* {S!d332}Gain: '<S31>/Gain2' */
    Model_6DOF_B.Gain2_f = Model_6DOF_P.Gain2_Gain_n * Model_6DOF_B.IPitch3;
}
/* {S!d334}MATLAB Function: '<S39>/MATLAB Function4' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant15'
 *  Constant: '<S31>/Constant17'
 *  Constant: '<S31>/Constant18'
 *  Constant: '<S31>/Constant19'
 *  Constant: '<S31>/Constant21'
 *  Constant: '<S31>/Constant23'
 *  Constant: '<S39>/CG'
 */


        Model_6DOF_MATLABFunction4(rtb_Clock, Model_6DOF_B.Integrator_d, Model_6DOF_P.vt1_X1a, Model_6DOF_P.vt2_X1a, Model_6DOF_P.vt3_X1a, Model_6DOF_P.dA_X1a, Model_6DOF_P.nt_X1a, Model_6DOF_B.A_wave, Model_6DOF_B.k_wave, Model_6DOF_B.w_wave, Model_6DOF_P.Constant6_Value_a, Model_6DOF_P.Constant7_Value_i, Model_6DOF_B.Add_p, Model_6DOF_B.Gain1, Model_6DOF_B.Gain2_f, Model_6DOF_P.Constant15_Value, Model_6DOF_P.CG_Value_n, &Model_6DOF_B.sf_MATLABFunction4_f);

/* {S!d336}MATLAB Function: '<S39>/MATLAB Function1' incorporates:
 *  Constant: '<S31>/Constant15'
 *  Constant: '<S31>/Constant24'
 *  Constant: '<S31>/Constant25'
 *  Constant: '<S31>/Constant26'
 *  Constant: '<S31>/Constant30'
 *  Constant: '<S39>/CG'
 */
memcpy(&Model_6DOF_B.vert1_m[0], &Model_6DOF_P.vt1_X1b[0], 600U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert2_c[0], &Model_6DOF_P.vt2_X1b[0], 600U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert3_k[0], &Model_6DOF_P.vt3_X1b[0], 600U * sizeof(real_T));
RMATX_tmp = cos(Model_6DOF_B.Gain1[2]);
RMATX_tmp_0 = sin(Model_6DOF_B.Gain1[0]);
psierr_tmp = sin(Model_6DOF_B.Gain1[2]);
p1 = cos(Model_6DOF_B.Gain1[0]);
p2 = sin(Model_6DOF_B.Gain1[1]);
p3_0 = cos(Model_6DOF_B.Gain1[1]);
RMATX[0] = p3_0 * RMATX_tmp;
RMATX[3] = RMATX_tmp_0 * p2 * RMATX_tmp + -p1 * psierr_tmp;
RMATX[6] = p1 * p2 * RMATX_tmp + RMATX_tmp_0 * psierr_tmp;
RMATX[1] = p3_0 * psierr_tmp;
RMATX[4] = sin(Model_6DOF_B.Gain1[0]) * sin(Model_6DOF_B.Gain1[1]) * psierr_tmp + p1 * RMATX_tmp;
RMATX[7] = cos(Model_6DOF_B.Gain1[0]) * sin(Model_6DOF_B.Gain1[1]) * psierr_tmp + -RMATX_tmp_0 * RMATX_tmp;
RMATX[2] = -p2;
RMATX[5] = RMATX_tmp_0 * p3_0;
RMATX[8] = p1 * p3_0;
RMATX_tmp = sin(Model_6DOF_B.Gain2_f);
RMATX_tmp_0 = cos(Model_6DOF_B.Gain2_f);
RMATD[0] = RMATX_tmp_0;
RMATD[3] = 0.0 * RMATX_tmp_0 + -RMATX_tmp;
RMATD[6] = 0.0 * RMATX_tmp + 0.0 * cos(Model_6DOF_B.Gain2_f);
RMATD[1] = RMATX_tmp;
RMATD[4] = 0.0 * sin(Model_6DOF_B.Gain2_f) + RMATX_tmp_0;
RMATD[7] = -0.0 * RMATX_tmp_0 + 0.0 * sin(Model_6DOF_B.Gain2_f);
RMATD[2] = 0.0;
RMATD[5] = 0.0;
RMATD[8] = 1.0;
if ((int32_T)Model_6DOF_P.nt_X1b - 1 >= 0) {
    Model_6DOF_inv_m(RMATX, b_x);
}
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_X1b; b_k++) {
    psierr_tmp = (Model_6DOF_B.vert1_m[b_k] - Model_6DOF_P.Constant15_Value[0] * 70.2) + Model_6DOF_P.CG_Value_n[0];
    RMATX_tmp_0 = (Model_6DOF_B.vert1_m[b_k + 200] - Model_6DOF_P.Constant15_Value[1] * 70.2) + Model_6DOF_P.CG_Value_n[1];
    RMATX_tmp = (Model_6DOF_B.vert1_m[b_k + 400] - Model_6DOF_P.Constant15_Value[2] * 70.2) + Model_6DOF_P.CG_Value_n[2];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * RMATX_tmp_0 + b_x[c_ix] * psierr_tmp) + b_x[c_ix + 6] * RMATX_tmp;
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert2_c[b_k];
    x_e_1[1] = Model_6DOF_B.vert2_c[b_k + 200];
    x_e_1[2] = Model_6DOF_B.vert2_c[b_k + 400];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        X1e[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant15_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value_n[c_ix];
        X3e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * X1e[1] + b_x[c_ix] * X1e[0]) + b_x[c_ix + 6] * X1e[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert3_k[b_k];
    x_e_1[1] = Model_6DOF_B.vert3_k[b_k + 200];
    x_e_1[2] = Model_6DOF_B.vert3_k[b_k + 400];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_2[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant15_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value_n[c_ix];
        X1e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * x_e_2[1] + b_x[c_ix] * x_e_2[0]) + b_x[c_ix + 6] * x_e_2[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    for (i = 0; i < 3; i++) {
        p1_0 = 200 * i + b_k;
        Model_6DOF_B.vert1_m[p1_0] = (Model_6DOF_P.Constant15_Value[i] * 70.2 + X3e[i]) - Model_6DOF_P.CG_Value_n[i];
        Model_6DOF_B.vert2_c[p1_0] = (Model_6DOF_P.Constant15_Value[i] * 70.2 + X1e[i]) - Model_6DOF_P.CG_Value_n[i];
        Model_6DOF_B.vert3_k[p1_0] = (((RMATX[i + 3] * x_e_0[1] + RMATX[i] * x_e_0[0]) + RMATX[i + 6] * x_e_0[2]) + Model_6DOF_P.Constant15_Value[i] * 70.2) - Model_6DOF_P.CG_Value_n[i];
    }
}
Model_6DOF_emxInit_real_T_i(&mp1_5, 2);
Model_6DOF_emxInit_real_T_i(&mp2_5, 2);
Model_6DOF_emxInit_real_T_i(&mp3_5, 2);
Model_6DOF_emxInit_real_T_i(&nA_5, 2);
Model_6DOF_emxInit_real_T_i(&r1_5, 2);
Model_6DOF_emxInit_real_T_i(&r2_5, 2);
Model_6DOF_emxInit_real_T_i(&r3_5, 2);
/* {S!d338}MATLAB Function: '<S39>/MATLAB Function1' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant26'
 *  Constant: '<S31>/Constant28'
 */
i = mp1_5->size[0] * mp1_5->size[1];
mp1_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
mp1_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_5, i);
i = mp2_5->size[0] * mp2_5->size[1];
mp2_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
mp2_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_5, i);
i = mp3_5->size[0] * mp3_5->size[1];
mp3_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
mp3_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_5, i);
i = nA_5->size[0] * nA_5->size[1];
nA_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
nA_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_5, i);
i = r1_5->size[0] * r1_5->size[1];
r1_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
r1_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_5, i);
i = r2_5->size[0] * r2_5->size[1];
r2_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
r2_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_5, i);
i = r3_5->size[0] * r3_5->size[1];
r3_5->size[0] = (int32_T)Model_6DOF_P.nt_X1b;
r3_5->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_5, i);
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_X1b; p1_0++) {
    X3e[0] = Model_6DOF_B.vert2_c[p1_0] - Model_6DOF_B.vert1_m[p1_0];
    RMATX_tmp_0 = Model_6DOF_B.vert1_m[p1_0 + 200];
    RMATX_tmp = Model_6DOF_B.vert2_c[p1_0 + 200];
    X3e[1] = RMATX_tmp - RMATX_tmp_0;
    p1 = Model_6DOF_B.vert1_m[p1_0 + 400];
    p2 = Model_6DOF_B.vert2_c[p1_0 + 400];
    X3e[2] = p2 - p1;
    X1e[0] = Model_6DOF_B.vert3_k[p1_0] - Model_6DOF_B.vert1_m[p1_0];
    z_e = Model_6DOF_B.vert3_k[p1_0 + 200];
    X1e[1] = z_e - RMATX_tmp_0;
    p3_0 = Model_6DOF_B.vert3_k[p1_0 + 400];
    X1e[2] = p3_0 - p1;
    y_e = X3e[1] * X1e[2] - X1e[1] * X3e[2];
    X2e[0] = y_e;
    x_e = X1e[0] * X3e[2] - X3e[0] * X1e[2];
    X2e[1] = x_e;
    RMat_tmp_tmp = X3e[0] * X1e[1] - X1e[0] * X3e[1];
    X2e[2] = RMat_tmp_tmp;
    psierr_tmp = Model_6DOF_norm_m(X2e);
    nA_5->data[p1_0] = y_e / psierr_tmp * Model_6DOF_P.dA_X1b[p1_0];
    r1_5->data[p1_0] = (Model_6DOF_B.vert1_m[p1_0] + Model_6DOF_B.vert2_c[p1_0]) * 0.5;
    r2_5->data[p1_0] = (Model_6DOF_B.vert1_m[p1_0] + Model_6DOF_B.vert3_k[p1_0]) * 0.5;
    r3_5->data[p1_0] = (Model_6DOF_B.vert2_c[p1_0] + Model_6DOF_B.vert3_k[p1_0]) * 0.5;
    nA_5->data[p1_0 + nA_5->size[0]] = x_e / psierr_tmp * Model_6DOF_P.dA_X1b[p1_0];
    r1_5->data[p1_0 + r1_5->size[0]] = (RMATX_tmp_0 + RMATX_tmp) * 0.5;
    r2_5->data[p1_0 + r2_5->size[0]] = (RMATX_tmp_0 + z_e) * 0.5;
    r3_5->data[p1_0 + r3_5->size[0]] = (RMATX_tmp + z_e) * 0.5;
    nA_5->data[p1_0 + (nA_5->size[0] << 1)] = RMat_tmp_tmp / psierr_tmp * Model_6DOF_P.dA_X1b[p1_0];
    r1_5->data[p1_0 + (r1_5->size[0] << 1)] = (p1 + p2) * 0.5;
    r2_5->data[p1_0 + (r2_5->size[0] << 1)] = (p1 + p3_0) * 0.5;
    r3_5->data[p1_0 + (r3_5->size[0] << 1)] = (p2 + p3_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_X1b - 1 >= 0) {
    x_e_i[0] = Model_6DOF_B.Integrator_d[0];
    x_e_i[1] = Model_6DOF_B.Integrator_d[1];
    x_e_i[2] = Model_6DOF_B.Integrator_d[2];
    x_e_j[0] = Model_6DOF_B.Integrator_d[0];
    x_e_j[1] = Model_6DOF_B.Integrator_d[1];
    x_e_j[2] = Model_6DOF_B.Integrator_d[2];
    x_e_k[0] = Model_6DOF_B.Integrator_d[0];
    x_e_k[1] = Model_6DOF_B.Integrator_d[1];
    x_e_k[2] = Model_6DOF_B.Integrator_d[2];
}
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_X1b; p3++) {
    psierr_tmp = r1_5->data[p3];
    RMATX_tmp_0 = r1_5->data[p3 + r1_5->size[0]];
    RMATX_tmp = r1_5->data[(r1_5->size[0] << 1) + p3];
    p1 = r2_5->data[p3];
    p2 = r2_5->data[p3 + r2_5->size[0]];
    z_e = r2_5->data[(r2_5->size[0] << 1) + p3];
    p3_0 = r3_5->data[p3];
    y_e = r3_5->data[p3 + r3_5->size[0]];
    x_e = r3_5->data[(r3_5->size[0] << 1) + p3];
    for (i = 0; i < 3; i++) {
        RMat_tmp_tmp = RMat_tmp[i + 3];
        RMat_tmp_tmp_0 = RMat_tmp[i + 6];
        mp1_5->data[p3 + mp1_5->size[0] * i] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[i] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_i[i];
        mp2_5->data[p3 + mp2_5->size[0] * i] = ((RMat_tmp_tmp * p2 + RMat_tmp[i] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_j[i];
        mp3_5->data[p3 + mp3_5->size[0] * i] = ((RMat_tmp_tmp * y_e + RMat_tmp[i] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_k[i];
    }
}
Fx_total_2 = 0.0;
Fy_total_1 = 0.0;
Fz_total_1 = 0.0;
Mx_total_1 = 0.0;
My_total_2 = 0.0;
RMATX_tmp_tmp = 0.0;
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_X1b; b_k++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_5->data[(mp1_5->size[0] << 1) + b_k] - exp(mp1_5->data[(mp1_5->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_5->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_5->data[(mp2_5->size[0] << 1) + b_k] - exp(mp2_5->data[(mp2_5->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_5->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_5->data[(mp3_5->size[0] << 1) + b_k] - exp(mp3_5->data[(mp3_5->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_5->data[b_k] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_5->data[b_k] - p2 * r2_5->data[b_k]) - p3_0 * r3_5->data[b_k];
    X1e[1] = (r1_5->data[b_k + r1_5->size[0]] * -p1 - r2_5->data[b_k + r2_5->size[0]] * p2) - r3_5->data[b_k + r3_5->size[0]] * p3_0;
    X1e[2] = ((r1_5->data[(r1_5->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * -p1 - (r2_5->data[(r2_5->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p2) - (r3_5->data[(r3_5->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_5->data[b_k];
    X2e[1] = nA_5->data[b_k + nA_5->size[0]];
    X2e[2] = nA_5->data[(nA_5->size[0] << 1) + b_k];
    RMATX_tmp_0 = (p1 + p2) + p3_0;
    Fx_total_2 += RMATX_tmp_0 * -nA_5->data[b_k] / 3.0;
    Fy_total_1 += -nA_5->data[b_k + nA_5->size[0]] * RMATX_tmp_0 / 3.0;
    Fz_total_1 += -nA_5->data[(nA_5->size[0] << 1) + b_k] * RMATX_tmp_0 / 3.0;
    Mx_total_1 += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    My_total_2 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    RMATX_tmp_tmp += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_5);
Model_6DOF_emxFree_real_T_i(&r2_5);
Model_6DOF_emxFree_real_T_i(&r1_5);
Model_6DOF_emxFree_real_T_i(&nA_5);
Model_6DOF_emxFree_real_T_i(&mp3_5);
Model_6DOF_emxFree_real_T_i(&mp2_5);
Model_6DOF_emxFree_real_T_i(&mp1_5);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d340}Gain: '<S31>/Gain3' incorporates:
 *  Constant: '<S31>/Constant70'
 */
    Model_6DOF_B.Gain3[0] = Model_6DOF_P.Gain3_Gain * Model_6DOF_P.Constant70_Value[0];
    Model_6DOF_B.Gain3[1] = Model_6DOF_P.Gain3_Gain * Model_6DOF_P.Constant70_Value[1];
    Model_6DOF_B.Gain3[2] = Model_6DOF_P.Gain3_Gain * Model_6DOF_P.Constant70_Value[2];
    /* {S!d342}Gain: '<S31>/Gain4' */
    Model_6DOF_B.Gain4 = Model_6DOF_P.Gain4_Gain * Model_6DOF_B.IPitch1;
}
/* {S!d344}MATLAB Function: '<S40>/MATLAB Function4' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant22'
 *  Constant: '<S31>/Constant29'
 *  Constant: '<S31>/Constant31'
 *  Constant: '<S31>/Constant33'
 *  Constant: '<S31>/Constant34'
 *  Constant: '<S31>/Constant71'
 *  Constant: '<S40>/CG'
 */


        Model_6DOF_MATLABFunction4(rtb_Clock, Model_6DOF_B.Integrator_d, Model_6DOF_P.vt1_X2a, Model_6DOF_P.vt2_X2a, Model_6DOF_P.vt3_X2a, Model_6DOF_P.dA_X2a, Model_6DOF_P.nt_X2a, Model_6DOF_B.A_wave, Model_6DOF_B.k_wave, Model_6DOF_B.w_wave, Model_6DOF_P.Constant6_Value_a, Model_6DOF_P.Constant7_Value_i, Model_6DOF_B.Add_p, Model_6DOF_B.Gain3, Model_6DOF_B.Gain4, Model_6DOF_P.Constant71_Value, Model_6DOF_P.CG_Value_h, &Model_6DOF_B.sf_MATLABFunction4_m);

/* {S!d346}MATLAB Function: '<S40>/MATLAB Function1' incorporates:
 *  Constant: '<S31>/Constant35'
 *  Constant: '<S31>/Constant36'
 *  Constant: '<S31>/Constant37'
 *  Constant: '<S31>/Constant40'
 *  Constant: '<S31>/Constant71'
 *  Constant: '<S40>/CG'
 */
memcpy(&Model_6DOF_B.vert1_m[0], &Model_6DOF_P.vt1_X2b[0], 600U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert2_c[0], &Model_6DOF_P.vt2_X2b[0], 600U * sizeof(real_T));
memcpy(&Model_6DOF_B.vert3_k[0], &Model_6DOF_P.vt3_X2b[0], 600U * sizeof(real_T));
RMATX_tmp = cos(Model_6DOF_B.Gain3[2]);
RMATX_tmp_0 = sin(Model_6DOF_B.Gain3[0]);
psierr_tmp = sin(Model_6DOF_B.Gain3[2]);
p1 = cos(Model_6DOF_B.Gain3[0]);
p2 = sin(Model_6DOF_B.Gain3[1]);
p3_0 = cos(Model_6DOF_B.Gain3[1]);
RMATX[0] = p3_0 * RMATX_tmp;
RMATX[3] = RMATX_tmp_0 * p2 * RMATX_tmp + -p1 * psierr_tmp;
RMATX[6] = p1 * p2 * RMATX_tmp + RMATX_tmp_0 * psierr_tmp;
RMATX[1] = p3_0 * psierr_tmp;
RMATX[4] = sin(Model_6DOF_B.Gain3[0]) * sin(Model_6DOF_B.Gain3[1]) * psierr_tmp + p1 * RMATX_tmp;
RMATX[7] = cos(Model_6DOF_B.Gain3[0]) * sin(Model_6DOF_B.Gain3[1]) * psierr_tmp + -RMATX_tmp_0 * RMATX_tmp;
RMATX[2] = -p2;
RMATX[5] = RMATX_tmp_0 * p3_0;
RMATX[8] = p1 * p3_0;
RMATX_tmp = sin(Model_6DOF_B.Gain4);
RMATX_tmp_0 = cos(Model_6DOF_B.Gain4);
RMATD[0] = RMATX_tmp_0;
RMATD[3] = 0.0 * RMATX_tmp_0 + -RMATX_tmp;
RMATD[6] = 0.0 * RMATX_tmp + 0.0 * cos(Model_6DOF_B.Gain4);
RMATD[1] = RMATX_tmp;
RMATD[4] = 0.0 * sin(Model_6DOF_B.Gain4) + RMATX_tmp_0;
RMATD[7] = -0.0 * RMATX_tmp_0 + 0.0 * sin(Model_6DOF_B.Gain4);
RMATD[2] = 0.0;
RMATD[5] = 0.0;
RMATD[8] = 1.0;
if ((int32_T)Model_6DOF_P.nt_X2b - 1 >= 0) {
    Model_6DOF_inv_m(RMATX, b_x);
}
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_X2b; b_k++) {
    psierr_tmp = (Model_6DOF_B.vert1_m[b_k] - Model_6DOF_P.Constant71_Value[0] * 70.2) + Model_6DOF_P.CG_Value_h[0];
    RMATX_tmp_0 = (Model_6DOF_B.vert1_m[b_k + 200] - Model_6DOF_P.Constant71_Value[1] * 70.2) + Model_6DOF_P.CG_Value_h[1];
    RMATX_tmp = (Model_6DOF_B.vert1_m[b_k + 400] - Model_6DOF_P.Constant71_Value[2] * 70.2) + Model_6DOF_P.CG_Value_h[2];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * RMATX_tmp_0 + b_x[c_ix] * psierr_tmp) + b_x[c_ix + 6] * RMATX_tmp;
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert2_c[b_k];
    x_e_1[1] = Model_6DOF_B.vert2_c[b_k + 200];
    x_e_1[2] = Model_6DOF_B.vert2_c[b_k + 400];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        X1e[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant71_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value_h[c_ix];
        X3e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * X1e[1] + b_x[c_ix] * X1e[0]) + b_x[c_ix + 6] * X1e[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    x_e_1[0] = Model_6DOF_B.vert3_k[b_k];
    x_e_1[1] = Model_6DOF_B.vert3_k[b_k + 200];
    x_e_1[2] = Model_6DOF_B.vert3_k[b_k + 400];
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_2[c_ix] = (x_e_1[c_ix] - Model_6DOF_P.Constant71_Value[c_ix] * 70.2) + Model_6DOF_P.CG_Value_h[c_ix];
        X1e[c_ix] = (RMATX[c_ix + 3] * x_e_0[1] + RMATX[c_ix] * x_e_0[0]) + RMATX[c_ix + 6] * x_e_0[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_1[c_ix] = (b_x[c_ix + 3] * x_e_2[1] + b_x[c_ix] * x_e_2[0]) + b_x[c_ix + 6] * x_e_2[2];
    }
    for (c_ix = 0; c_ix < 3; c_ix++) {
        x_e_0[c_ix] = (RMATD[c_ix + 3] * x_e_1[1] + RMATD[c_ix] * x_e_1[0]) + RMATD[c_ix + 6] * x_e_1[2];
    }
    for (i = 0; i < 3; i++) {
        p1_0 = 200 * i + b_k;
        Model_6DOF_B.vert1_m[p1_0] = (Model_6DOF_P.Constant71_Value[i] * 70.2 + X3e[i]) - Model_6DOF_P.CG_Value_h[i];
        Model_6DOF_B.vert2_c[p1_0] = (Model_6DOF_P.Constant71_Value[i] * 70.2 + X1e[i]) - Model_6DOF_P.CG_Value_h[i];
        Model_6DOF_B.vert3_k[p1_0] = (((RMATX[i + 3] * x_e_0[1] + RMATX[i] * x_e_0[0]) + RMATX[i + 6] * x_e_0[2]) + Model_6DOF_P.Constant71_Value[i] * 70.2) - Model_6DOF_P.CG_Value_h[i];
    }
}
Model_6DOF_emxInit_real_T_i(&mp1_6, 2);
Model_6DOF_emxInit_real_T_i(&mp2_6, 2);
Model_6DOF_emxInit_real_T_i(&mp3_6, 2);
Model_6DOF_emxInit_real_T_i(&nA_6, 2);
Model_6DOF_emxInit_real_T_i(&r1_6, 2);
Model_6DOF_emxInit_real_T_i(&r2_6, 2);
Model_6DOF_emxInit_real_T_i(&r3_6, 2);
/* {S!d348}MATLAB Function: '<S40>/MATLAB Function1' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant37'
 *  Constant: '<S31>/Constant39'
 */
i = mp1_6->size[0] * mp1_6->size[1];
mp1_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
mp1_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp1_6, i);
i = mp2_6->size[0] * mp2_6->size[1];
mp2_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
mp2_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp2_6, i);
i = mp3_6->size[0] * mp3_6->size[1];
mp3_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
mp3_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(mp3_6, i);
i = nA_6->size[0] * nA_6->size[1];
nA_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
nA_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(nA_6, i);
i = r1_6->size[0] * r1_6->size[1];
r1_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
r1_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r1_6, i);
i = r2_6->size[0] * r2_6->size[1];
r2_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
r2_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r2_6, i);
i = r3_6->size[0] * r3_6->size[1];
r3_6->size[0] = (int32_T)Model_6DOF_P.nt_X2b;
r3_6->size[1] = 3;
Mode_emxEnsureCapacity_real_T_i(r3_6, i);
for (p1_0 = 0; p1_0 < (int32_T)Model_6DOF_P.nt_X2b; p1_0++) {
    X3e[0] = Model_6DOF_B.vert2_c[p1_0] - Model_6DOF_B.vert1_m[p1_0];
    RMATX_tmp_0 = Model_6DOF_B.vert1_m[p1_0 + 200];
    RMATX_tmp = Model_6DOF_B.vert2_c[p1_0 + 200];
    X3e[1] = RMATX_tmp - RMATX_tmp_0;
    p1 = Model_6DOF_B.vert1_m[p1_0 + 400];
    p2 = Model_6DOF_B.vert2_c[p1_0 + 400];
    X3e[2] = p2 - p1;
    X1e[0] = Model_6DOF_B.vert3_k[p1_0] - Model_6DOF_B.vert1_m[p1_0];
    z_e = Model_6DOF_B.vert3_k[p1_0 + 200];
    X1e[1] = z_e - RMATX_tmp_0;
    p3_0 = Model_6DOF_B.vert3_k[p1_0 + 400];
    X1e[2] = p3_0 - p1;
    y_e = X3e[1] * X1e[2] - X1e[1] * X3e[2];
    X2e[0] = y_e;
    x_e = X1e[0] * X3e[2] - X3e[0] * X1e[2];
    X2e[1] = x_e;
    RMat_tmp_tmp = X3e[0] * X1e[1] - X1e[0] * X3e[1];
    X2e[2] = RMat_tmp_tmp;
    psierr_tmp = Model_6DOF_norm_m(X2e);
    nA_6->data[p1_0] = y_e / psierr_tmp * Model_6DOF_P.dA_X2b[p1_0];
    r1_6->data[p1_0] = (Model_6DOF_B.vert1_m[p1_0] + Model_6DOF_B.vert2_c[p1_0]) * 0.5;
    r2_6->data[p1_0] = (Model_6DOF_B.vert1_m[p1_0] + Model_6DOF_B.vert3_k[p1_0]) * 0.5;
    r3_6->data[p1_0] = (Model_6DOF_B.vert2_c[p1_0] + Model_6DOF_B.vert3_k[p1_0]) * 0.5;
    nA_6->data[p1_0 + nA_6->size[0]] = x_e / psierr_tmp * Model_6DOF_P.dA_X2b[p1_0];
    r1_6->data[p1_0 + r1_6->size[0]] = (RMATX_tmp_0 + RMATX_tmp) * 0.5;
    r2_6->data[p1_0 + r2_6->size[0]] = (RMATX_tmp_0 + z_e) * 0.5;
    r3_6->data[p1_0 + r3_6->size[0]] = (RMATX_tmp + z_e) * 0.5;
    nA_6->data[p1_0 + (nA_6->size[0] << 1)] = RMat_tmp_tmp / psierr_tmp * Model_6DOF_P.dA_X2b[p1_0];
    r1_6->data[p1_0 + (r1_6->size[0] << 1)] = (p1 + p2) * 0.5;
    r2_6->data[p1_0 + (r2_6->size[0] << 1)] = (p1 + p3_0) * 0.5;
    r3_6->data[p1_0 + (r3_6->size[0] << 1)] = (p2 + p3_0) * 0.5;
}
if ((int32_T)Model_6DOF_P.nt_X2b - 1 >= 0) {
    x_e_l[0] = Model_6DOF_B.Integrator_d[0];
    x_e_l[1] = Model_6DOF_B.Integrator_d[1];
    x_e_l[2] = Model_6DOF_B.Integrator_d[2];
    x_e_m[0] = Model_6DOF_B.Integrator_d[0];
    x_e_m[1] = Model_6DOF_B.Integrator_d[1];
    x_e_m[2] = Model_6DOF_B.Integrator_d[2];
    x_e_n[0] = Model_6DOF_B.Integrator_d[0];
    x_e_n[1] = Model_6DOF_B.Integrator_d[1];
    x_e_n[2] = Model_6DOF_B.Integrator_d[2];
}
for (p3 = 0; p3 < (int32_T)Model_6DOF_P.nt_X2b; p3++) {
    psierr_tmp = r1_6->data[p3];
    RMATX_tmp_0 = r1_6->data[p3 + r1_6->size[0]];
    RMATX_tmp = r1_6->data[(r1_6->size[0] << 1) + p3];
    p1 = r2_6->data[p3];
    p2 = r2_6->data[p3 + r2_6->size[0]];
    z_e = r2_6->data[(r2_6->size[0] << 1) + p3];
    p3_0 = r3_6->data[p3];
    y_e = r3_6->data[p3 + r3_6->size[0]];
    x_e = r3_6->data[(r3_6->size[0] << 1) + p3];
    for (i = 0; i < 3; i++) {
        RMat_tmp_tmp = RMat_tmp[i + 3];
        RMat_tmp_tmp_0 = RMat_tmp[i + 6];
        mp1_6->data[p3 + mp1_6->size[0] * i] = ((RMat_tmp_tmp * RMATX_tmp_0 + RMat_tmp[i] * psierr_tmp) + RMat_tmp_tmp_0 * RMATX_tmp) + x_e_l[i];
        mp2_6->data[p3 + mp2_6->size[0] * i] = ((RMat_tmp_tmp * p2 + RMat_tmp[i] * p1) + RMat_tmp_tmp_0 * z_e) + x_e_m[i];
        mp3_6->data[p3 + mp3_6->size[0] * i] = ((RMat_tmp_tmp * y_e + RMat_tmp[i] * p3_0) + RMat_tmp_tmp_0 * x_e) + x_e_n[i];
    }
}
x_e = 0.0;
y_e = 0.0;
z_e = 0.0;
RMATX_tmp = 0.0;
RMATX_tmp_0 = 0.0;
psierr_tmp = 0.0;
for (b_k = 0; b_k < (int32_T)Model_6DOF_P.nt_X2b; b_k++) {
    p3_0 = -Model_6DOF_P.Constant6_Value_a * Model_6DOF_P.Constant7_Value_i;
    p1 = (mp1_6->data[(mp1_6->size[0] << 1) + b_k] - exp(mp1_6->data[(mp1_6->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp1_6->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p2 = (mp2_6->data[(mp2_6->size[0] << 1) + b_k] - exp(mp2_6->data[(mp2_6->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp2_6->data[b_k] - rtb_Add_l_idx_0)) * p3_0;
    p3_0 *= mp3_6->data[(mp3_6->size[0] << 1) + b_k] - exp(mp3_6->data[(mp3_6->size[0] << 1) + b_k] * Model_6DOF_B.k_wave) * Model_6DOF_B.A_wave * sin(Model_6DOF_B.k_wave * mp3_6->data[b_k] - rtb_Add_l_idx_0);
    X1e[0] = (-p1 * r1_6->data[b_k] - p2 * r2_6->data[b_k]) - p3_0 * r3_6->data[b_k];
    X1e[1] = (r1_6->data[b_k + r1_6->size[0]] * -p1 - r2_6->data[b_k + r2_6->size[0]] * p2) - r3_6->data[b_k + r3_6->size[0]] * p3_0;
    X1e[2] = ((r1_6->data[(r1_6->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * -p1 - (r2_6->data[(r2_6->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p2) - (r3_6->data[(r3_6->size[0] << 1) + b_k] - Model_6DOF_B.Add_p) * p3_0;
    X2e[0] = nA_6->data[b_k];
    X2e[1] = nA_6->data[b_k + nA_6->size[0]];
    X2e[2] = nA_6->data[(nA_6->size[0] << 1) + b_k];
    p1 = (p1 + p2) + p3_0;
    x_e += p1 * -nA_6->data[b_k] / 3.0;
    y_e += -nA_6->data[b_k + nA_6->size[0]] * p1 / 3.0;
    z_e += -nA_6->data[(nA_6->size[0] << 1) + b_k] * p1 / 3.0;
    RMATX_tmp += (X1e[1] * X2e[2] - X2e[1] * X1e[2]) / 3.0;
    RMATX_tmp_0 += (X2e[0] * X1e[2] - X1e[0] * X2e[2]) / 3.0;
    psierr_tmp += (X1e[0] * X2e[1] - X2e[0] * X1e[1]) / 3.0;
}
Model_6DOF_emxFree_real_T_i(&r3_6);
Model_6DOF_emxFree_real_T_i(&r2_6);
Model_6DOF_emxFree_real_T_i(&r1_6);
Model_6DOF_emxFree_real_T_i(&nA_6);
Model_6DOF_emxFree_real_T_i(&mp3_6);
Model_6DOF_emxFree_real_T_i(&mp2_6);
Model_6DOF_emxFree_real_T_i(&mp1_6);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d350}Gain: '<S31>/Gain5' incorporates:
 *  Constant: '<S31>/Constant72'
 */
    Model_6DOF_B.Gain5[0] = Model_6DOF_P.Gain5_Gain * Model_6DOF_P.Constant72_Value[0];
    Model_6DOF_B.Gain5[1] = Model_6DOF_P.Gain5_Gain * Model_6DOF_P.Constant72_Value[1];
    Model_6DOF_B.Gain5[2] = Model_6DOF_P.Gain5_Gain * Model_6DOF_P.Constant72_Value[2];
    /* {S!d352}Gain: '<S31>/Gain6' */
    Model_6DOF_B.Gain6 = Model_6DOF_P.Gain6_Gain * Model_6DOF_B.IPitch2;
}
/* {S!d354}MATLAB Function: '<S41>/MATLAB Function4' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant41'
 *  Constant: '<S31>/Constant42'
 *  Constant: '<S31>/Constant43'
 *  Constant: '<S31>/Constant45'
 *  Constant: '<S31>/Constant46'
 *  Constant: '<S31>/Constant73'
 *  Constant: '<S41>/CG'
 */


        Model_6DOF_MATLABFunction4(rtb_Clock, Model_6DOF_B.Integrator_d, Model_6DOF_P.vt1_X3a, Model_6DOF_P.vt2_X3a, Model_6DOF_P.vt3_X3a, Model_6DOF_P.dA_X3a, Model_6DOF_P.nt_X3a, Model_6DOF_B.A_wave, Model_6DOF_B.k_wave, Model_6DOF_B.w_wave, Model_6DOF_P.Constant6_Value_a, Model_6DOF_P.Constant7_Value_i, Model_6DOF_B.Add_p, Model_6DOF_B.Gain5, Model_6DOF_B.Gain6, Model_6DOF_P.Constant73_Value, Model_6DOF_P.CG_Value_nc, &Model_6DOF_B.sf_MATLABFunction4_p);

/* {S!d356}MATLAB Function: '<S41>/MATLAB Function1' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant47'
 *  Constant: '<S31>/Constant48'
 *  Constant: '<S31>/Constant49'
 *  Constant: '<S31>/Constant51'
 *  Constant: '<S31>/Constant52'
 *  Constant: '<S31>/Constant73'
 *  Constant: '<S41>/CG'
 */


        Model_6DOF_MATLABFunction4(rtb_Clock, Model_6DOF_B.Integrator_d, Model_6DOF_P.vt1_X3b, Model_6DOF_P.vt2_X3b, Model_6DOF_P.vt3_X3b, Model_6DOF_P.dA_X3b, Model_6DOF_P.nt_X3b, Model_6DOF_B.A_wave, Model_6DOF_B.k_wave, Model_6DOF_B.w_wave, Model_6DOF_P.Constant6_Value_a, Model_6DOF_P.Constant7_Value_i, Model_6DOF_B.Add_p, Model_6DOF_B.Gain5, Model_6DOF_B.Gain6, Model_6DOF_P.Constant73_Value, Model_6DOF_P.CG_Value_nc, &Model_6DOF_B.sf_MATLABFunction1_p);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d358}Gain: '<S31>/Gain7' incorporates:
 *  Constant: '<S31>/Constant74'
 */
    Model_6DOF_B.Gain7[0] = Model_6DOF_P.Gain7_Gain * Model_6DOF_P.Constant74_Value[0];
    Model_6DOF_B.Gain7[1] = Model_6DOF_P.Gain7_Gain * Model_6DOF_P.Constant74_Value[1];
    Model_6DOF_B.Gain7[2] = Model_6DOF_P.Gain7_Gain * Model_6DOF_P.Constant74_Value[2];
    /* {S!d360}Gain: '<S31>/Gain8' */
    Model_6DOF_B.Gain8 = Model_6DOF_P.Gain8_Gain * Model_6DOF_B.IPitch4;
}
/* {S!d362}MATLAB Function: '<S42>/MATLAB Function4' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant53'
 *  Constant: '<S31>/Constant54'
 *  Constant: '<S31>/Constant55'
 *  Constant: '<S31>/Constant57'
 *  Constant: '<S31>/Constant58'
 *  Constant: '<S31>/Constant75'
 *  Constant: '<S42>/CG'
 */


        Model_6DOF_MATLABFunction4(rtb_Clock, Model_6DOF_B.Integrator_d, Model_6DOF_P.vt1_X4a, Model_6DOF_P.vt2_X4a, Model_6DOF_P.vt3_X4a, Model_6DOF_P.dA_X4a, Model_6DOF_P.nt_X4a, Model_6DOF_B.A_wave, Model_6DOF_B.k_wave, Model_6DOF_B.w_wave, Model_6DOF_P.Constant6_Value_a, Model_6DOF_P.Constant7_Value_i, Model_6DOF_B.Add_p, Model_6DOF_B.Gain7, Model_6DOF_B.Gain8, Model_6DOF_P.Constant75_Value, Model_6DOF_P.CG_Value_nd, &Model_6DOF_B.sf_MATLABFunction4_c);

/* {S!d364}MATLAB Function: '<S42>/MATLAB Function1' incorporates:
 *  Constant: '<S30>/Constant6'
 *  Constant: '<S30>/Constant7'
 *  Constant: '<S31>/Constant59'
 *  Constant: '<S31>/Constant60'
 *  Constant: '<S31>/Constant61'
 *  Constant: '<S31>/Constant63'
 *  Constant: '<S31>/Constant64'
 *  Constant: '<S31>/Constant75'
 *  Constant: '<S42>/CG'
 */


        Model_6DOF_MATLABFunction4(rtb_Clock, Model_6DOF_B.Integrator_d, Model_6DOF_P.vt1_X4b, Model_6DOF_P.vt2_X4b, Model_6DOF_P.vt3_X4b, Model_6DOF_P.dA_X4b, Model_6DOF_P.nt_X4b, Model_6DOF_B.A_wave, Model_6DOF_B.k_wave, Model_6DOF_B.w_wave, Model_6DOF_P.Constant6_Value_a, Model_6DOF_P.Constant7_Value_i, Model_6DOF_B.Add_p, Model_6DOF_B.Gain7, Model_6DOF_B.Gain8, Model_6DOF_P.Constant75_Value, Model_6DOF_P.CG_Value_nd, &Model_6DOF_B.sf_MATLABFunction1_h);

/* {S!d366}Sum: '<S31>/Add' incorporates:
 *  MATLAB Function: '<S38>/MATLAB Function1'
 *  MATLAB Function: '<S38>/MATLAB Function3'
 *  MATLAB Function: '<S38>/MATLAB Function4'
 *  MATLAB Function: '<S38>/MATLAB Function5'
 *  MATLAB Function: '<S39>/MATLAB Function1'
 *  MATLAB Function: '<S40>/MATLAB Function1'
 *  MATLAB Function: '<S43>/MATLAB Function1'
 *  MATLAB Function: '<S43>/MATLAB Function4'
 *  Sum: '<S38>/Add1'
 *  Sum: '<S39>/Add1'
 *  Sum: '<S40>/Add1'
 *  Sum: '<S41>/Add1'
 *  Sum: '<S42>/Add1'
 *  Sum: '<S43>/Add1'
 */
rtb_Add_l_idx_0 = (((((((rtb_UkYk1_l + tmp_5) + rtb_Sign1_hb) + Fx_total) + (Fx_total_0 + Fx_total_1)) + (Model_6DOF_B.sf_MATLABFunction4_f.Fx_total + Fx_total_2)) + (Model_6DOF_B.sf_MATLABFunction4_m.Fx_total + x_e)) + (Model_6DOF_B.sf_MATLABFunction4_p.Fx_total + Model_6DOF_B.sf_MATLABFunction1_p.Fx_total)) + (Model_6DOF_B.sf_MATLABFunction4_c.Fx_total + Model_6DOF_B.sf_MATLABFunction1_h.Fx_total);
rtb_Add_l_idx_1 = (((((((rtb_deltafalllimit_h + dXiuq) + rtb_Product3_a) + rtb_Add_l_idx_1) + (Fy_total + Fy_total_0)) + (Model_6DOF_B.sf_MATLABFunction4_f.Fy_total + Fy_total_1)) + (Model_6DOF_B.sf_MATLABFunction4_m.Fy_total + y_e)) + (Model_6DOF_B.sf_MATLABFunction4_p.Fy_total + Model_6DOF_B.sf_MATLABFunction1_p.Fy_total)) + (Model_6DOF_B.sf_MATLABFunction4_c.Fy_total + Model_6DOF_B.sf_MATLABFunction1_h.Fy_total);
rtb_Add_l_idx_2 = (((((((arg4 + tmp_6) + rtb_dpeth) + rtb_Add_l_idx_2) + (Fz_total + Fz_total_0)) + (Model_6DOF_B.sf_MATLABFunction4_f.Fz_total + Fz_total_1)) + (Model_6DOF_B.sf_MATLABFunction4_m.Fz_total + z_e)) + (Model_6DOF_B.sf_MATLABFunction4_p.Fz_total + Model_6DOF_B.sf_MATLABFunction1_p.Fz_total)) + (Model_6DOF_B.sf_MATLABFunction4_c.Fz_total + Model_6DOF_B.sf_MATLABFunction1_h.Fz_total);
rtb_Add_l_idx_3 = (((((((arg5 + tmp_7) + rtb_Sign_o) + rtb_Add_l_idx_3) + (Mx_total + Mx_total_0)) + (Model_6DOF_B.sf_MATLABFunction4_f.Mx_total + Mx_total_1)) + (Model_6DOF_B.sf_MATLABFunction4_m.Mx_total + RMATX_tmp)) + (Model_6DOF_B.sf_MATLABFunction4_p.Mx_total + Model_6DOF_B.sf_MATLABFunction1_p.Mx_total)) + (Model_6DOF_B.sf_MATLABFunction4_c.Mx_total + Model_6DOF_B.sf_MATLABFunction1_h.Mx_total);
rtb_Add_l_idx_4 = (((((((absx31 + tmp_8) + My_total) + rtb_Add_l_idx_4) + (My_total_0 + My_total_1)) + (Model_6DOF_B.sf_MATLABFunction4_f.My_total + My_total_2)) + (Model_6DOF_B.sf_MATLABFunction4_m.My_total + RMATX_tmp_0)) + (Model_6DOF_B.sf_MATLABFunction4_p.My_total + Model_6DOF_B.sf_MATLABFunction1_p.My_total)) + (Model_6DOF_B.sf_MATLABFunction4_c.My_total + Model_6DOF_B.sf_MATLABFunction1_h.My_total);
rtb_Add_l_idx_5 = (((((((tmp_a + tmp_9) + Mz_total) + rtb_Add_l_idx_5) + (RMATD_0 + RMATX_tmp_tmp_0)) + (Model_6DOF_B.sf_MATLABFunction4_f.Mz_total + RMATX_tmp_tmp)) + (Model_6DOF_B.sf_MATLABFunction4_m.Mz_total + psierr_tmp)) + (Model_6DOF_B.sf_MATLABFunction4_p.Mz_total + Model_6DOF_B.sf_MATLABFunction1_p.Mz_total)) + (Model_6DOF_B.sf_MATLABFunction4_c.Mz_total + Model_6DOF_B.sf_MATLABFunction1_h.Mz_total);
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d368}Product: '<S82>/delta rise limit' incorporates:
 *  Constant: '<S69>/Rate Max'
 *  SampleTimeMath: '<S82>/sample time'
 *
 * About '<S82>/sample time':
 *  y = K where K = ( w * Ts )
 */
    arg4 = Model_6DOF_P.RateMax_Value * Model_6DOF_P.sampletime_WtEt_d;
    /* {S!d370}Sum: '<S82>/Difference Inputs1' incorporates:
 *  UnitDelay: '<S82>/Delay Input2'
 */
    rtb_UkYk1_l = rtb_n - Model_6DOF_DW.DelayInput2_DSTATE_m;
    /* {S!d376}Switch: '<S83>/Switch2' incorporates:
 *  RelationalOperator: '<S83>/LowerRelop1'
 */
    if (!(rtb_UkYk1_l > arg4)) {
        /* {S!d372}Product: '<S82>/delta fall limit' incorporates:
 *  Constant: '<S69>/Rate Min'
 *  SampleTimeMath: '<S82>/sample time'
 *
 * About '<S82>/sample time':
 *  y = K where K = ( w * Ts )
 */
        rtb_deltafalllimit_h = Model_6DOF_P.RateMin_Value * Model_6DOF_P.sampletime_WtEt_d;
        /* {S!d374}Switch: '<S83>/Switch' incorporates:
 *  RelationalOperator: '<S83>/UpperRelop'
 */
        if (rtb_UkYk1_l < rtb_deltafalllimit_h) {
            arg4 = rtb_deltafalllimit_h;
        } else {
            arg4 = rtb_UkYk1_l;
        }
        /* {E!d374}End of Switch: '<S83>/Switch' */
    }
    /* {E!d376}End of Switch: '<S83>/Switch2' */

    /* {S!d378}Sum: '<S82>/Difference Inputs2' incorporates:
 *  UnitDelay: '<S82>/Delay Input2'
 */
    rtb_DifferenceInputs2_f = arg4 + Model_6DOF_DW.DelayInput2_DSTATE_m;
    /* {S!d386}Saturate: '<S69>/Saturation6' */
    if (rtb_DifferenceInputs2_f > Model_6DOF_P.Saturation6_UpperSat) {
        /* {S!d380}Saturate: '<S69>/Saturation6' */
        Model_6DOF_B.Saturation6 = Model_6DOF_P.Saturation6_UpperSat;
    } else if (rtb_DifferenceInputs2_f < Model_6DOF_P.Saturation6_LowerSat) {
        /* {S!d382}Saturate: '<S69>/Saturation6' */
        Model_6DOF_B.Saturation6 = Model_6DOF_P.Saturation6_LowerSat;
    } else {
        /* {S!d384}Saturate: '<S69>/Saturation6' */
        Model_6DOF_B.Saturation6 = rtb_DifferenceInputs2_f;
    }
    /* {E!d386}End of Saturate: '<S69>/Saturation6' */
}
/* {S!d388}MATLAB Function: '<S14>/Tprop' incorporates:
 *  Gain: '<S14>/Gain20'
 */
rtb_UkYk1_l = Model_6DOF_P.Gain20_Gain * Model_6DOF_B.Integrator[0] / (Model_6DOF_B.Saturation6 * 5.0);
/* {S!d390}SignalConversion generated from: '<S23>/ SFunction ' incorporates:
 *  MATLAB Function: '<S11>/Mx'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d390}End of SignalConversion generated from: '<S23>/ SFunction ' */

/* {S!d392}Lookup_n-D: '<S22>/KdX1' */
RMATD_0 = intrp3d_l_pw(bpIndices_0, Vr_earth, Model_6DOF_P.KdX1_tableData, Model_6DOF_P.KdX1_dimSizes);
/* {S!d394}MATLAB Function: '<S11>/Mx' */
rtb_deltafalllimit_h = -0.10622 * rtb_TmpSignalConversionAtSFun_b[3] * fabs(rtb_TmpSignalConversionAtSFun_b[3]) * 3.5459711820000005E+8;
/* {S!d402}Signum: '<S11>/Sign1' */
if (rtIsNaN(dv)) {
    /* {S!d396}Signum: '<S13>/Sign1' incorporates:
 *  Signum: '<S17>/Sign'
 */
    tmp_9 = dv;
} else if (dv < 0.0) {
    /* {S!d398}Signum: '<S13>/Sign1' incorporates:
 *  Signum: '<S17>/Sign'
 */
    tmp_9 = -1.0;
} else {
    /* {S!d400}Signum: '<S13>/Sign1' incorporates:
 *  Signum: '<S17>/Sign'
 */
    tmp_9 = (dv > 0.0);
}
/* {S!d404}MATLAB Function: '<S11>/Mx' incorporates:
 *  Lookup_n-D: '<S11>/K'uvw'
 *  MATLAB Function: '<S12>/My'
 *  MATLAB Function: '<S13>/Mz'
 *  MATLAB Function: '<S16>/Fx'
 *  MATLAB Function: '<S17>/Fy'
 *  MATLAB Function: '<S18>/Fz'
 *  Product: '<S11>/Product2'
 *  Signum: '<S11>/Sign1'
 */
dXiuq = rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[0];
Fx_total_0 = psierrint * psierrint;
arg4 = ((-0.00029648 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[3] * -3.5459711820000005E+8 * dXiuq + tmp_9 * intrp3d_l_pw(bpIndices, Vx_earth, Model_6DOF_P.Kuvw_tableData, Model_6DOF_P.Kuvw_dimSizes) * 1.7729855910000002E+8 * Fx_total_0) + -5.6192E-5 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[5] * 3.5459711820000005E+8 * dXiuq) + rtb_deltafalllimit_h;
/* {S!d406}Saturate: '<S12>/Saturation4' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation4_UpperSat_a) {
    absx31 = Model_6DOF_P.Saturation4_UpperSat_a;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation4_LowerSat_d) {
    absx31 = Model_6DOF_P.Saturation4_LowerSat_d;
} else {
    absx31 = Model_6DOF_B.Integrator_d[2];
}
/* {E!d406}End of Saturate: '<S12>/Saturation4' */

/* {S!d408}Lookup_n-D: '<S12>/M_uvwa' incorporates:
 *  Lookup_n-D: '<S27>/NdX1'
 */
bpIndices_4[0U] = plook_binx(psierr, Model_6DOF_P.M_uvwa_bp01Data, 6U, &tmp_8);
fractions_2[0U] = tmp_8;
bpIndices_4[1U] = plook_binx(Model_6DOF_B.Integrator[0], Model_6DOF_P.M_uvwa_bp02Data, 2U, &tmp_8);
fractions_2[1U] = tmp_8;
bpIndices_4[2U] = plook_binx(absx31, Model_6DOF_P.M_uvwa_bp03Data, 3U, &tmp_8);
fractions_2[2U] = tmp_8;
/* {S!d410}Lookup_n-D: '<S24>/ZudX1 q+1' incorporates:
 *  Lookup_n-D: '<S27>/NdX1'
 *  Sum: '<S10>/Add'
 */
psierr_tmp = look2_binlxpw(dh, absx31, Model_6DOF_P.ZudX1q1_bp01Data, Model_6DOF_P.ZudX1q1_bp02Data, Model_6DOF_P.ZudX1q1_tableData, Model_6DOF_P.ZudX1q1_maxIndex, 7U);
/* {S!d412}Lookup_n-D: '<S24>/ZudX1 q+2' incorporates:
 *  Lookup_n-D: '<S27>/NdX1'
 *  Sum: '<S10>/Add1'
 */
psierrint = look2_binlxpw(absxk, absx31, Model_6DOF_P.ZudX1q2_bp01Data, Model_6DOF_P.ZudX1q2_bp02Data, Model_6DOF_P.ZudX1q2_tableData, Model_6DOF_P.ZudX1q2_maxIndex, 7U);
/* {S!d414}Lookup_n-D: '<S24>/ZudX1 q+3' incorporates:
 *  Lookup_n-D: '<S27>/NdX1'
 *  Sum: '<S10>/Add2'
 */
arg5 = look2_binlxpw(arg1, absx31, Model_6DOF_P.ZudX1q3_bp01Data, Model_6DOF_P.ZudX1q3_bp02Data, Model_6DOF_P.ZudX1q3_tableData, Model_6DOF_P.ZudX1q3_maxIndex, 7U);
/* {S!d416}Lookup_n-D: '<S24>/ZudX1 q+4' incorporates:
 *  Lookup_n-D: '<S27>/NdX1'
 *  Sum: '<S10>/Add3'
 */
Mz_total = look2_binlxpw(arg2, absx31, Model_6DOF_P.ZudX1q4_bp01Data, Model_6DOF_P.ZudX1q4_bp02Data, Model_6DOF_P.ZudX1q4_tableData, Model_6DOF_P.ZudX1q4_maxIndex, 7U);
/* {S!d418}Lookup_n-D: '<S24>/ZudX1 q+5' incorporates:
 *  Lookup_n-D: '<S27>/NdX1'
 *  Sum: '<S10>/Add4'
 */
My_total = look2_binlxpw(arg3, absx31, Model_6DOF_P.ZudX1q5_bp01Data, Model_6DOF_P.ZudX1q5_bp02Data, Model_6DOF_P.ZudX1q5_tableData, Model_6DOF_P.ZudX1q5_maxIndex, 7U);
/* {S!d420}SignalConversion generated from: '<S25>/ SFunction ' incorporates:
 *  MATLAB Function: '<S12>/My'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d420}End of SignalConversion generated from: '<S25>/ SFunction ' */

/* {S!d422}MATLAB Function: '<S12>/My' incorporates:
 *  Gain: '<S12>/Gain'
 *  Lookup_n-D: '<S12>/M'prop'
 *  Lookup_n-D: '<S12>/M_uvwa'
 */
absx31 = -2.4892717697640003E+10 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[4] * look1_binlxpw(Model_6DOF_B.Integrator[0], Model_6DOF_P.Mprop_bp01Data, Model_6DOF_P.Mprop_tableData, 2U);
tmp_a = 1.2446358848820002E+10 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[4] * 0.0019444 * 1.1 + Model_6DOF_P.Gain_Gain * intrp3d_l_pw(bpIndices_4, fractions_2, Model_6DOF_P.M_uvwa_tableData, Model_6DOF_P.M_uvwa_dimSizes) * 1.7729855910000002E+8 * Fx_total_0;
/* {S!d424}Lookup_n-D: '<S13>/N'uvw' incorporates:
 *  Abs: '<S13>/Abs2'
 */
bpIndices_5[0U] = plook_binx(fabs(dv), Model_6DOF_P.Nuvw_bp01Data, 3U, &tmp_8);
fractions_3[0U] = tmp_8;
bpIndices_5[1U] = plook_binx(Model_6DOF_B.Integrator[0], Model_6DOF_P.Nuvw_bp02Data, 2U, &tmp_8);
fractions_3[1U] = tmp_8;
/* {S!d426}Saturate: '<S13>/Saturation4' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation4_UpperSat_d) {
    tmp_7 = Model_6DOF_P.Saturation4_UpperSat_d;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation4_LowerSat_o) {
    tmp_7 = Model_6DOF_P.Saturation4_LowerSat_o;
} else {
    tmp_7 = Model_6DOF_B.Integrator_d[2];
}
/* {E!d426}End of Saturate: '<S13>/Saturation4' */

/* {S!d428}Lookup_n-D: '<S13>/N'uvw' */
bpIndices_5[2U] = plook_binx(tmp_7, Model_6DOF_P.Nuvw_bp03Data, 3U, &tmp_8);
fractions_3[2U] = tmp_8;
/* {S!d430}SignalConversion generated from: '<S26>/ SFunction ' incorporates:
 *  MATLAB Function: '<S13>/Mz'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d430}End of SignalConversion generated from: '<S26>/ SFunction ' */

/* {S!d438}Signum: '<S13>/Sign2' */
if (rtIsNaN(Model_6DOF_B.Gain2[4])) {
    /* {S!d432}Signum: '<S13>/Sign3' */
    tmp_5 = Model_6DOF_B.Gain2[4];
} else if (Model_6DOF_B.Gain2[4] < 0.0) {
    /* {S!d434}Signum: '<S13>/Sign3' */
    tmp_5 = -1.0;
} else {
    /* {S!d436}Signum: '<S13>/Sign3' */
    tmp_5 = (Model_6DOF_B.Gain2[4] > 0.0);
}
/* {S!d440}MATLAB Function: '<S13>/Mz' */
RMATX_tmp_0 = rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[0];
/* {S!d442}Product: '<S13>/Product4' incorporates:
 *  Product: '<S17>/Product1'
 */
rtb_Sign_o = Model_6DOF_B.Gain2[0] * Model_6DOF_B.Gain2[4];
/* {S!d444}MATLAB Function: '<S13>/Mz' incorporates:
 *  Abs: '<S13>/Abs'
 *  Abs: '<S13>/Abs3'
 *  Gain: '<S13>/Gain'
 *  Gain: '<S13>/Gain3'
 *  Gain: '<S13>/Gain4'
 *  Lookup_n-D: '<S13>/N'r|r|'
 *  Lookup_n-D: '<S13>/N'uvw'
 *  Lookup_n-D: '<S13>/N'vr'
 *  Product: '<S13>/Product2'
 *  Product: '<S13>/Product3'
 *  Product: '<S13>/Product4'
 *  Product: '<S13>/Product5'
 *  Product: '<S13>/Product6'
 *  Signum: '<S13>/Sign2'
 */
tmp_5 = ((0.0061236 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[5] * 1.7729855910000002E+8 * RMATX_tmp_0 * 0.5 + tmp_9 * intrp3d_l_pw(bpIndices_5, fractions_3, Model_6DOF_P.Nuvw_tableData, Model_6DOF_P.Nuvw_dimSizes) * Model_6DOF_P.Gain_Gain_i * 1.7729855910000002E+8 * Fx_total_0) + look1_binlxpw(fabs(rtb_Sign_o), Model_6DOF_P.Nvr_bp01Data, Model_6DOF_P.Nvr_tableData, 4U) * tmp_5 * Model_6DOF_P.Gain4_Gain_h * 1.7729855910000002E+8 * RMATX_tmp_0) + look1_binlxpw(fabs(Model_6DOF_B.Gain2[4] * Model_6DOF_B.Gain2[4]), Model_6DOF_P.Nrr_bp01Data, Model_6DOF_P.Nrr_tableData, 5U) * tmp_5 * Model_6DOF_P.Gain3_Gain_d * -1.7729855910000002E+8 * (rtb_TmpSignalConversionAtSFun_b[5] * rtb_TmpSignalConversionAtSFun_b[5]) * RMATX_tmp_0;
/* {S!d446}Lookup_n-D: '<S16>/X'uvwH' incorporates:
 *  Abs: '<S16>/Abs1'
 */
bpIndices_6[0U] = plook_binx(fabs(dv), Model_6DOF_P.XuvwH_bp01Data, 3U, &tmp_8);
fractions_4[0U] = tmp_8;
/* {S!d448}Saturate: '<S16>/Saturation1' */
if (Model_6DOF_B.Integrator[0] > Model_6DOF_P.Saturation1_UpperSat) {
    tmp_7 = Model_6DOF_P.Saturation1_UpperSat;
} else if (Model_6DOF_B.Integrator[0] < Model_6DOF_P.Saturation1_LowerSat) {
    tmp_7 = Model_6DOF_P.Saturation1_LowerSat;
} else {
    tmp_7 = Model_6DOF_B.Integrator[0];
}
/* {E!d448}End of Saturate: '<S16>/Saturation1' */

/* {S!d450}Lookup_n-D: '<S16>/X'uvwH' */
bpIndices_6[1U] = plook_binx(tmp_7, Model_6DOF_P.XuvwH_bp02Data, 2U, &tmp_8);
fractions_4[1U] = tmp_8;
/* {S!d452}Saturate: '<S16>/Saturation4' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation4_UpperSat_b) {
    tmp_7 = Model_6DOF_P.Saturation4_UpperSat_b;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation4_LowerSat_f) {
    tmp_7 = Model_6DOF_P.Saturation4_LowerSat_f;
} else {
    tmp_7 = Model_6DOF_B.Integrator_d[2];
}
/* {E!d452}End of Saturate: '<S16>/Saturation4' */

/* {S!d454}Lookup_n-D: '<S16>/X'uvwH' */
bpIndices_6[2U] = plook_binx(tmp_7, Model_6DOF_P.XuvwH_bp03Data, 3U, &tmp_8);
fractions_4[2U] = tmp_8;
/* {S!d456}SignalConversion generated from: '<S58>/ SFunction ' incorporates:
 *  MATLAB Function: '<S16>/Fx'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    /* {S!d458}Gain: '<S59>/Gain' */
    dXiuq = Model_6DOF_P.Gain_Gain_g * IP[i];
    /* {S!d460}Saturate: '<S59>/Saturation6' */
    if (dXiuq > Model_6DOF_P.Saturation6_UpperSat_d) {
        rtb_aX[i] = Model_6DOF_P.Saturation6_UpperSat_d;
    } else if (dXiuq < Model_6DOF_P.Saturation6_LowerSat_io) {
        rtb_aX[i] = Model_6DOF_P.Saturation6_LowerSat_io;
    } else {
        rtb_aX[i] = dXiuq;
    }
    /* {E!d460}End of Saturate: '<S59>/Saturation6' */

    /* {S!d462}SignalConversion generated from: '<S58>/ SFunction ' incorporates:
 *  MATLAB Function: '<S16>/Fx'
 */
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {S!d464}Lookup_n-D: '<S59>/XudX1' incorporates:
 *  Sum: '<S10>/Add'
 */
tmp_7 = look2_binlxpw(dh, rtb_aX[0], Model_6DOF_P.XudX1_bp01Data, Model_6DOF_P.XudX1_bp02Data, Model_6DOF_P.XudX1_tableData, Model_6DOF_P.XudX1_maxIndex, 7U);
/* {S!d466}Lookup_n-D: '<S59>/XudX2' incorporates:
 *  Sum: '<S10>/Add1'
 */
rtb_Sign1_hb = look2_binlxpw(absxk, rtb_aX[1], Model_6DOF_P.XudX2_bp01Data, Model_6DOF_P.XudX2_bp02Data, Model_6DOF_P.XudX2_tableData, Model_6DOF_P.XudX2_maxIndex, 7U);
/* {S!d468}Lookup_n-D: '<S59>/XudX3' incorporates:
 *  Sum: '<S10>/Add2'
 */
tmp_6 = look2_binlxpw(arg1, rtb_aX[2], Model_6DOF_P.XudX3_bp01Data, Model_6DOF_P.XudX3_bp02Data, Model_6DOF_P.XudX3_tableData, Model_6DOF_P.XudX3_maxIndex, 7U);
/* {S!d470}Lookup_n-D: '<S59>/XudX4' incorporates:
 *  Sum: '<S10>/Add3'
 */
rtb_dpeth = look2_binlxpw(arg2, rtb_aX[3], Model_6DOF_P.XudX4_bp01Data, Model_6DOF_P.XudX4_bp02Data, Model_6DOF_P.XudX4_tableData, Model_6DOF_P.XudX4_maxIndex, 7U);
/* {S!d472}Lookup_n-D: '<S59>/XudXB' incorporates:
 *  Sum: '<S10>/Add4'
 */
tmp_8 = look2_binlxpw(arg3, rtb_aX[4], Model_6DOF_P.XudXB_bp01Data, Model_6DOF_P.XudXB_bp02Data, Model_6DOF_P.XudXB_tableData, Model_6DOF_P.XudXB_maxIndex, 7U);
/* {S!d474}MATLAB Function: '<S16>/Fx' incorporates:
 *  Gain: '<S59>/Gain4'
 *  Gain: '<S59>/Gain5'
 *  Gain: '<S59>/Gain6'
 *  Gain: '<S59>/Gain7'
 *  Lookup_n-D: '<S59>/XudX1'
 *  Lookup_n-D: '<S59>/XudX2'
 *  Lookup_n-D: '<S59>/XudX3'
 *  Lookup_n-D: '<S59>/XudX4'
 *  Lookup_n-D: '<S59>/XudXB'
 *  MATLAB Function: '<S11>/Mx'
 *  MATLAB Function: '<S12>/My'
 *  MATLAB Function: '<S13>/Mz'
 *  MATLAB Function: '<S17>/Fy'
 *  MATLAB Function: '<S18>/Fz'
 */
My_total_0 = rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[4];
dXiuq = My_total_0 * My_total_0 * 0.0044603 - My_total_0 * 7.3687E-6;
My_total_0 = IP[0] * IP[0];
Mx_total = IP[1] * IP[1];
RMATX_tmp_tmp_0 = IP[2] * IP[2];
RMATX_tmp_tmp = IP[3] * IP[3];
Fz_total = IP[4] * IP[4];
dXiuq = ((((Model_6DOF_P.Gain4_Gain_e * tmp_7 + dXiuq) * 2.5256205E+6 * My_total_0 + (Model_6DOF_P.Gain6_Gain_c * rtb_Sign1_hb + dXiuq) * 2.5256205E+6 * Mx_total) + (Model_6DOF_P.Gain5_Gain_m * tmp_6 + dXiuq) * 2.5256205E+6 * RMATX_tmp_tmp_0) + (Model_6DOF_P.Gain7_Gain_b * rtb_dpeth + dXiuq) * 2.5256205E+6 * RMATX_tmp_tmp) + 4928.04 * tmp_8 * Fz_total * 512.5;
/* {S!d476}Saturate: '<S16>/Saturation2' */
if (psierr > Model_6DOF_P.Saturation2_UpperSat_i) {
    tmp_6 = Model_6DOF_P.Saturation2_UpperSat_i;
} else if (psierr < Model_6DOF_P.Saturation2_LowerSat_e) {
    tmp_6 = Model_6DOF_P.Saturation2_LowerSat_e;
} else {
    tmp_6 = psierr;
}
/* {E!d476}End of Saturate: '<S16>/Saturation2' */

/* {S!d478}Saturate: '<S16>/Saturation6' */
if (Model_6DOF_B.Integrator[0] > Model_6DOF_P.Saturation6_UpperSat_f) {
    tmp_7 = Model_6DOF_P.Saturation6_UpperSat_f;
} else if (Model_6DOF_B.Integrator[0] < Model_6DOF_P.Saturation6_LowerSat_i) {
    tmp_7 = Model_6DOF_P.Saturation6_LowerSat_i;
} else {
    tmp_7 = Model_6DOF_B.Integrator[0];
}
/* {E!d478}End of Saturate: '<S16>/Saturation6' */

/* {S!d480}MATLAB Function: '<S16>/Fx' incorporates:
 *  Abs: '<S16>/Abs'
 *  Lookup_n-D: '<S16>/X'uvwH'
 *  Lookup_n-D: '<S16>/X'uvwV'
 *  Lookup_n-D: '<S16>/Xqq'
 */
tmp_6 = (((look2_binlxpw(tmp_6, tmp_7, Model_6DOF_P.XuvwV_bp01Data, Model_6DOF_P.XuvwV_bp02Data, Model_6DOF_P.XuvwV_tableData, Model_6DOF_P.XuvwV_maxIndex, 7U) + intrp3d_l_pw(bpIndices_6, fractions_4, Model_6DOF_P.XuvwH_tableData, Model_6DOF_P.XuvwH_dimSizes)) * -2.5256205E+6 * Fx_total_0 * rtb_TmpSignalConversionAtSFun_b[0] / fabs(rtb_TmpSignalConversionAtSFun_b[0]) + rtb_TmpSignalConversionAtSFun_b[4] * rtb_TmpSignalConversionAtSFun_b[4] * 1.2446358848820002E+10 * look1_binlxpw(fabs(Model_6DOF_B.Gain2[3]), Model_6DOF_P.Xqq_bp01Data, Model_6DOF_P.Xqq_tableData, 15U)) + -0.0033124286 * rtb_TmpSignalConversionAtSFun_b[2] * rtb_TmpSignalConversionAtSFun_b[4] * 3.5459711820000005E+8) + -0.0033124286 * rtb_TmpSignalConversionAtSFun_b[1] * rtb_TmpSignalConversionAtSFun_b[5] * 3.5459711820000005E+8 * 0.0;
/* {S!d482}Saturate: '<S14>/Saturation5' */
if (Model_6DOF_B.Integrator[0] > Model_6DOF_P.Saturation5_UpperSat) {
    tmp_7 = Model_6DOF_P.Saturation5_UpperSat;
} else if (Model_6DOF_B.Integrator[0] < Model_6DOF_P.Saturation5_LowerSat) {
    tmp_7 = Model_6DOF_P.Saturation5_LowerSat;
} else {
    tmp_7 = Model_6DOF_B.Integrator[0];
}
/* {E!d482}End of Saturate: '<S14>/Saturation5' */

/* {S!d484}Saturate: '<S14>/Saturation7' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation7_UpperSat) {
    rtb_Sign1_hb = Model_6DOF_P.Saturation7_UpperSat;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation7_LowerSat) {
    rtb_Sign1_hb = Model_6DOF_P.Saturation7_LowerSat;
} else {
    rtb_Sign1_hb = Model_6DOF_B.Integrator_d[2];
}
/* {E!d484}End of Saturate: '<S14>/Saturation7' */

/* {S!d486}MATLAB Function: '<S14>/Tprop' incorporates:
 *  MATLAB Function: '<S11>/Mx'
 */
My_total_1 = rtb_UkYk1_l * rtb_UkYk1_l;
My_total_2 = Model_6DOF_B.Saturation6 * Model_6DOF_B.Saturation6;
/* {S!d488}MATLAB Function: '<S16>/Fx' incorporates:
 *  Lookup_n-D: '<S14>/Thrust Deduction, 25m1'
 *  MATLAB Function: '<S14>/Tprop'
 */
tmp_7 = (((My_total_1 * -0.0923 - 0.3652 * rtb_UkYk1_l) + 0.4786) * (1.0 - look2_binlxpw(tmp_7, rtb_Sign1_hb, Model_6DOF_P.ThrustDeduction25m1_bp01Data, Model_6DOF_P.ThrustDeduction25m1_bp02Data, Model_6DOF_P.ThrustDeduction25m1_tableData, Model_6DOF_P.ThrustDeduction25m1_maxIndex, 4U)) * (My_total_2 * 1025.0 * 625.0) + 0.0036594 * rtb_TmpSignalConversionAtSFun_b[2] * rtb_TmpSignalConversionAtSFun_b[4] * 1.7729855910000002E+8) + 0.0036594 * rtb_TmpSignalConversionAtSFun_b[1] * rtb_TmpSignalConversionAtSFun_b[5] * 1.7729855910000002E+8 * 0.0;
/* {S!d490}Product: '<S17>/Product3' */
rtb_Product3_a = Model_6DOF_B.Integrator[0] * Model_6DOF_B.Gain2[4];
/* {S!d492}Signum: '<S17>/Sign1' */
if (rtIsNaN(rtb_Product3_a)) {
    rtb_Sign1_hb = rtb_Product3_a;
} else if (rtb_Product3_a < 0.0) {
    rtb_Sign1_hb = -1.0;
} else {
    rtb_Sign1_hb = (rtb_Product3_a > 0.0);
}
/* {E!d492}End of Signum: '<S17>/Sign1' */

/* {S!d494}Lookup_n-D: '<S17>/Y'ur' incorporates:
 *  Abs: '<S17>/Abs2'
 */
rtb_dpeth = look1_binlxpw(fabs(rtb_Product3_a), Model_6DOF_P.Yur_bp01Data, Model_6DOF_P.Yur_tableData, 3U);
/* {S!d496}Saturate: '<S17>/Saturation4' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation4_UpperSat_e) {
    rtb_Product3_a = Model_6DOF_P.Saturation4_UpperSat_e;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation4_LowerSat_ou) {
    rtb_Product3_a = Model_6DOF_P.Saturation4_LowerSat_ou;
} else {
    rtb_Product3_a = Model_6DOF_B.Integrator_d[2];
}
/* {E!d496}End of Saturate: '<S17>/Saturation4' */

/* {S!d498}Lookup_n-D: '<S17>/Y'uvw' incorporates:
 *  Abs: '<S17>/Abs1'
 *  Product: '<S18>/Product3'
 */
bpIndices_7[0U] = plook_binx(fabs(dv), Model_6DOF_P.Yuvw_bp01Data, 3U, &tmp_8);
fractions_5[0U] = tmp_8;
bpIndices_7[1U] = plook_binx(Model_6DOF_B.Integrator[0], Model_6DOF_P.Yuvw_bp02Data, 2U, &tmp_8);
fractions_5[1U] = tmp_8;
bpIndices_7[2U] = plook_binx(rtb_Product3_a, Model_6DOF_P.Yuvw_bp03Data, 3U, &tmp_8);
fractions_5[2U] = tmp_8;
/* {S!d500}SignalConversion generated from: '<S60>/ SFunction ' incorporates:
 *  MATLAB Function: '<S17>/Fy'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d500}End of SignalConversion generated from: '<S60>/ SFunction ' */

/* {S!d502}Lookup_n-D: '<S61>/YdX1' incorporates:
 *  Product: '<S18>/Product3'
 *  Sum: '<S10>/Add'
 */
Fy_total = look2_binlxpw(dh, rtb_Product3_a, Model_6DOF_P.YdX1_bp01Data, Model_6DOF_P.YdX1_bp02Data, Model_6DOF_P.YdX1_tableData, Model_6DOF_P.YdX1_maxIndex, 3U);
/* {S!d504}Lookup_n-D: '<S61>/YdX2' incorporates:
 *  Product: '<S18>/Product3'
 *  Sum: '<S10>/Add1'
 */
Mx_total_0 = look2_binlxpw(absxk, rtb_Product3_a, Model_6DOF_P.YdX2_bp01Data, Model_6DOF_P.YdX2_bp02Data, Model_6DOF_P.YdX2_tableData, Model_6DOF_P.YdX2_maxIndex, 3U);
/* {S!d506}Lookup_n-D: '<S61>/YdX3' incorporates:
 *  Product: '<S18>/Product3'
 *  Sum: '<S10>/Add2'
 */
Mx_total_1 = look2_binlxpw(arg1, rtb_Product3_a, Model_6DOF_P.YdX3_bp01Data, Model_6DOF_P.YdX3_bp02Data, Model_6DOF_P.YdX3_tableData, Model_6DOF_P.YdX3_maxIndex, 3U);
/* {S!d508}Lookup_n-D: '<S61>/YdX4' incorporates:
 *  Product: '<S18>/Product3'
 *  Sum: '<S10>/Add3'
 */
Fx_total = look2_binlxpw(arg2, rtb_Product3_a, Model_6DOF_P.YdX4_bp01Data, Model_6DOF_P.YdX4_bp02Data, Model_6DOF_P.YdX4_tableData, Model_6DOF_P.YdX4_maxIndex, 3U);
/* {S!d510}MATLAB Function: '<S17>/Fy' incorporates:
 *  Gain: '<S17>/Gain2'
 *  Lookup_n-D: '<S17>/Y'uvw'
 *  Lookup_n-D: '<S17>/Y'|v|r'
 *  Product: '<S17>/Product'
 *  Product: '<S17>/Product2'
 */
tmp_8 = rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[0];
tmp_9 = ((0.00738774 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[5] * -5.051241E+6 * tmp_8 * 2.0 + tmp_9 * intrp3d_l_pw(bpIndices_7, fractions_5, Model_6DOF_P.Yuvw_tableData, Model_6DOF_P.Yuvw_dimSizes) * Model_6DOF_P.Gain2_Gain_l * 2.5256205E+6 * Fx_total_0) + rtb_Sign1_hb * rtb_dpeth * 1.7729855910000002E+8 * tmp_8 * 0.0) + look1_binlxpw(rtb_Sign_o, Model_6DOF_P.Yvr_bp01Data, Model_6DOF_P.Yvr_tableData, 11U) * 1.2446358848820002E+10 * rtb_TmpSignalConversionAtSFun_b[4] * fabs(rtb_TmpSignalConversionAtSFun_b[4]) * 0.0;
/* {S!d512}Saturate: '<S18>/Saturation3' */
if (Model_6DOF_B.Gain2[3] > Model_6DOF_P.Saturation3_UpperSat_b) {
    rtb_Sign1_hb = Model_6DOF_P.Saturation3_UpperSat_b;
} else if (Model_6DOF_B.Gain2[3] < Model_6DOF_P.Saturation3_LowerSat_k) {
    rtb_Sign1_hb = Model_6DOF_P.Saturation3_LowerSat_k;
} else {
    rtb_Sign1_hb = Model_6DOF_B.Gain2[3];
}
/* {E!d512}End of Saturate: '<S18>/Saturation3' */

/* {S!d514}Signum: '<S18>/Sign' */
if (rtIsNaN(rtb_Sign1_hb)) {
    rtb_Sign_o = rtb_Sign1_hb;
} else if (rtb_Sign1_hb < 0.0) {
    rtb_Sign_o = -1.0;
} else {
    rtb_Sign_o = (rtb_Sign1_hb > 0.0);
}
/* {E!d514}End of Signum: '<S18>/Sign' */

/* {S!d516}Lookup_n-D: '<S18>/Zqq' incorporates:
 *  Abs: '<S18>/Abs1'
 */
rtb_Product3_a = look1_binlxpw(fabs(rtb_Sign1_hb), Model_6DOF_P.Zqq_bp01Data, Model_6DOF_P.Zqq_tableData, 4U);
/* {S!d518}Saturate: '<S18>/Saturation5' */
if (Model_6DOF_B.Integrator[0] > Model_6DOF_P.Saturation5_UpperSat_i) {
    rtb_Sign1_hb = Model_6DOF_P.Saturation5_UpperSat_i;
} else if (Model_6DOF_B.Integrator[0] < Model_6DOF_P.Saturation5_LowerSat_d) {
    rtb_Sign1_hb = Model_6DOF_P.Saturation5_LowerSat_d;
} else {
    rtb_Sign1_hb = Model_6DOF_B.Integrator[0];
}
/* {E!d518}End of Saturate: '<S18>/Saturation5' */

/* {S!d520}Saturate: '<S18>/Saturation4' */
if (Model_6DOF_B.Integrator_d[2] > Model_6DOF_P.Saturation4_UpperSat_p) {
    rtb_dpeth = Model_6DOF_P.Saturation4_UpperSat_p;
} else if (Model_6DOF_B.Integrator_d[2] < Model_6DOF_P.Saturation4_LowerSat_b) {
    rtb_dpeth = Model_6DOF_P.Saturation4_LowerSat_b;
} else {
    rtb_dpeth = Model_6DOF_B.Integrator_d[2];
}
/* {E!d520}End of Saturate: '<S18>/Saturation4' */

/* {S!d522}Lookup_n-D: '<S18>/Z'uvw(a)' incorporates:
 *  Saturate: '<S18>/Saturation4'
 *  Saturate: '<S18>/Saturation5'
 */
bpIndices_8[0U] = plook_binx(psierr, Model_6DOF_P.Zuvwa_bp01Data, 6U, &tmp_8);
fractions_6[0U] = tmp_8;
bpIndices_8[1U] = plook_binx(rtb_Sign1_hb, Model_6DOF_P.Zuvwa_bp02Data, 2U, &tmp_8);
fractions_6[1U] = tmp_8;
bpIndices_8[2U] = plook_binx(rtb_dpeth, Model_6DOF_P.Zuvwa_bp03Data, 3U, &tmp_8);
fractions_6[2U] = tmp_8;
/* {S!d524}Lookup_n-D: '<S18>/Z'uvw(b)' incorporates:
 *  Saturate: '<S18>/Saturation4'
 *  Saturate: '<S18>/Saturation5'
 */
bpIndices_9[0U] = plook_binx(dv, Model_6DOF_P.Zuvwb_bp01Data, 3U, &tmp_8);
fractions_7[0U] = tmp_8;
bpIndices_9[1U] = plook_binx(rtb_Sign1_hb, Model_6DOF_P.Zuvwb_bp02Data, 2U, &tmp_8);
fractions_7[1U] = tmp_8;
bpIndices_9[2U] = plook_binx(rtb_dpeth, Model_6DOF_P.Zuvwb_bp03Data, 3U, &tmp_8);
fractions_7[2U] = tmp_8;
/* {S!d526}SignalConversion generated from: '<S62>/ SFunction ' incorporates:
 *  MATLAB Function: '<S18>/Fz'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d526}End of SignalConversion generated from: '<S62>/ SFunction ' */

/* {S!d528}MATLAB Function: '<S18>/Fz' incorporates:
 *  Lookup_n-D: '<S18>/Z'uvw(a)'
 *  Lookup_n-D: '<S18>/Z'uvw(b)'
 *  Product: '<S18>/Product'
 */
dv = (-0.01066 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[4] * 0.5 * 345948.40800000005 * 1025.0 * 0.6 + ((intrp3d_l_pw(bpIndices_9, fractions_7, Model_6DOF_P.Zuvwb_tableData, Model_6DOF_P.Zuvwb_dimSizes) * 2.0 + intrp3d_l_pw(bpIndices_8, fractions_6, Model_6DOF_P.Zuvwa_tableData, Model_6DOF_P.Zuvwa_dimSizes)) * 2.5256205E+6 * Fx_total_0 + rtb_Sign_o * rtb_Product3_a * 1.2446358848820002E+10 * (rtb_TmpSignalConversionAtSFun_b[4] * rtb_TmpSignalConversionAtSFun_b[4]) * 26.46485136)) + 0.0015483 * rtb_TmpSignalConversionAtSFun_b[0] * rtb_TmpSignalConversionAtSFun_b[5] * 4928.04 * 1025.0 * 26.46485136;
/* {S!d530}SignalConversion generated from: '<S66>/ SFunction ' incorporates:
 *  MATLAB Function: '<S64>/MATLAB Function2'
 */
rtb_TmpSignalConversionAtSFun_b[0] = Model_6DOF_B.Integrator[0];
for (i = 0; i < 5; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 1] = Model_6DOF_B.Gain2[i];
}
/* {E!d530}End of SignalConversion generated from: '<S66>/ SFunction ' */

/* {S!d532}MATLAB Function: '<S64>/MATLAB Function2' incorporates:
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 */
RMat_tmp[0] = cos(Model_6DOF_B.Integrator_d[4]) * cos(Model_6DOF_B.Integrator_d[5]);
RMat_tmp[3] = RMat_tmp_tmp_1 * zerr + -cos(Model_6DOF_B.Integrator_d[3]) * sin(Model_6DOF_B.Integrator_d[5]);
RMat_tmp[6] = RMat_tmp_tmp_2 * zerr + zerrint * psierr_tmp_tmp;
RMat_tmp[1] = cos(Model_6DOF_B.Integrator_d[4]) * sin(Model_6DOF_B.Integrator_d[5]);
RMat_tmp[4] = zerrint * zerrint_tmp * psierr_tmp_tmp + cos(Model_6DOF_B.Integrator_d[3]) * cos(Model_6DOF_B.Integrator_d[5]);
RMat_tmp[7] = thetaerrint * zerrint_tmp * psierr_tmp_tmp + -zerrint * zerr;
RMat_tmp[2] = -zerrint_tmp;
RMat_tmp[5] = RMat_tmp_tmp_3;
RMat_tmp[8] = cos(Model_6DOF_B.Integrator_d[3]) * cos(Model_6DOF_B.Integrator_d[4]);
zerr = rtb_TmpSignalConversionAtSFun_b[0];
psierr = rtb_TmpSignalConversionAtSFun_b[1];
RMat_tmp_tmp_1 = rtb_TmpSignalConversionAtSFun_b[2];
for (c_ix = 0; c_ix < 3; c_ix++) {
    Vx_earth[c_ix] = (RMat_tmp[c_ix + 3] * psierr + RMat_tmp[c_ix] * zerr) + RMat_tmp[c_ix + 6] * RMat_tmp_tmp_1;
}
psierr = tan(Model_6DOF_B.Integrator_d[4]);
RMat_tmp[0] = 1.0;
RMat_tmp[3] = psierr * zerrint;
RMat_tmp[6] = psierr * thetaerrint;
RMat_tmp[1] = 0.0;
RMat_tmp[4] = thetaerrint;
RMat_tmp[7] = -zerrint;
RMat_tmp[2] = 0.0;
RMat_tmp[5] = zerrint / thetaerr;
RMat_tmp[8] = thetaerrint / thetaerr;
zerr = rtb_TmpSignalConversionAtSFun_b[3];
psierr = rtb_TmpSignalConversionAtSFun_b[4];
RMat_tmp_tmp_1 = rtb_TmpSignalConversionAtSFun_b[5];
for (c_ix = 0; c_ix < 3; c_ix++) {
    Vr_earth[c_ix] = (RMat_tmp[c_ix + 3] * psierr + RMat_tmp[c_ix] * zerr) + RMat_tmp[c_ix + 6] * RMat_tmp_tmp_1;
}
Model_6DOF_B.out_f[0] = Vx_earth[0];
Model_6DOF_B.out_f[1] = Vx_earth[1];
Model_6DOF_B.out_f[2] = Vx_earth[2];
Model_6DOF_B.out_f[3] = Vr_earth[0];
Model_6DOF_B.out_f[4] = Vr_earth[1];
Model_6DOF_B.out_f[5] = Vr_earth[2];
/* {S!d534}MATLAB Function: '<S65>/MATLAB Function2' */
A[0] = Model_6DOF_P.Mb;
A[6] = 0.0;
A[12] = 0.0;
A[18] = 0.0;
thetaerrint = Model_6DOF_P.Mb * Model_6DOF_P.Zg;
A[24] = thetaerrint;
zerr = -Model_6DOF_P.Mb * Model_6DOF_P.Yg;
A[30] = zerr;
A[1] = 0.0;
A[7] = Model_6DOF_P.Mb;
A[13] = 0.0;
psierr = -Model_6DOF_P.Mb * Model_6DOF_P.Zg;
A[19] = psierr;
A[25] = 0.0;
A[31] = Model_6DOF_P.Mb * Model_6DOF_P.Xg;
A[2] = 0.0;
A[8] = 0.0;
A[14] = Model_6DOF_P.Mb;
RMat_tmp_tmp_1 = Model_6DOF_P.Mb * Model_6DOF_P.Yg;
A[20] = RMat_tmp_tmp_1;
RMat_tmp_tmp_2 = -Model_6DOF_P.Mb * Model_6DOF_P.Xg;
A[26] = RMat_tmp_tmp_2;
A[32] = 0.0;
A[3] = 0.0;
A[9] = psierr;
A[15] = RMat_tmp_tmp_1;
A[21] = Model_6DOF_P.Ixx;
A[27] = -Model_6DOF_P.Ixy;
A[33] = -Model_6DOF_P.Ixz;
A[4] = thetaerrint;
A[10] = 0.0;
A[16] = RMat_tmp_tmp_2;
A[22] = -Model_6DOF_P.Ixy;
A[28] = Model_6DOF_P.Iyy;
A[34] = -Model_6DOF_P.Iyz;
A[5] = zerr;
A[11] = thetaerrint;
A[17] = 0.0;
A[23] = -Model_6DOF_P.Ixz;
A[29] = -Model_6DOF_P.Iyz;
A[35] = Model_6DOF_P.Izz;
memset(&a[0], 0, 36U * sizeof(real_T));
for (c_ix = 0; c_ix < 6; c_ix++) {
    ipiv[c_ix] = (int8_T)(c_ix + 1);
}
for (b_k = 0; b_k < 5; b_k++) {
    p1_0 = b_k * 7;
    p3 = 0;
    itmp = p1_0;
    thetaerrint = fabs(A[p1_0]);
    for (i = 2; i <= 6 - b_k; i++) {
        itmp++;
        psierr = fabs(A[itmp]);
        if (psierr > thetaerrint) {
            p3 = i - 1;
            thetaerrint = psierr;
        }
    }
    if (A[p1_0 + p3] != 0.0) {
        if (p3 != 0) {
            p3 += b_k;
            ipiv[b_k] = (int8_T)(p3 + 1);
            for (i = 0; i < 6; i++) {
                thetaerrint = A[i * 6 + b_k];
                A[b_k + i * 6] = A[i * 6 + p3];
                A[p3 + i * 6] = thetaerrint;
            }
        }
        i = (p1_0 - b_k) + 6;
        for (p3 = p1_0 + 1; p3 < i; p3++) {
            A[p3] /= A[p1_0];
        }
    }
    p3 = p1_0;
    itmp = p1_0 + 6;
    for (i = 0; i <= 4 - b_k; i++) {
        if (A[itmp] != 0.0) {
            int32_T d;
            thetaerrint = -A[itmp];
            c_ix = p1_0 + 1;
            ijA = p3 + 7;
            d = (p3 - b_k) + 12;
            while (ijA + 1 <= d) {
                A[ijA] += A[c_ix] * thetaerrint;
                c_ix++;
                ijA++;
            }
        }
        itmp += 6;
        p3 += 6;
    }
}
for (c_ix = 0; c_ix < 6; c_ix++) {
    p[c_ix] = (int8_T)(c_ix + 1);
}
for (b_k = 0; b_k < 5; b_k++) {
    int8_T ipiv_0;
    ipiv_0 = ipiv[b_k];
    if (ipiv_0 > b_k + 1) {
        p1_0 = p[ipiv_0 - 1];
        p[ipiv_0 - 1] = p[b_k];
        p[b_k] = (int8_T)p1_0;
    }
}
for (p1_0 = 0; p1_0 < 6; p1_0++) {
    p3 = p[p1_0] - 1;
    a[p1_0 + 6 * (p[p1_0] - 1)] = 1.0;
    for (i = p1_0; i + 1 < 7; i++) {
        if (a[6 * p3 + i] != 0.0) {
            for (b_k = i + 1; b_k + 1 < 7; b_k++) {
                ijA = 6 * p3 + b_k;
                a[ijA] -= a[6 * p3 + i] * A[6 * i + b_k];
            }
        }
    }
}
/* {S!d536}MATLAB Function: '<S16>/Fx' incorporates:
 *  MATLAB Function: '<S11>/Mx'
 *  MATLAB Function: '<S17>/Fy'
 */
thetaerrint = Model_6DOF_P.Mb + Model_6DOF_B.dmasskg;
zerr = thetaerrint * 9.81;
/* {S!d538}MATLAB Function: '<S65>/MATLAB Function2' incorporates:
 *  Gain: '<S12>/Gain1'
 *  Gain: '<S13>/Gain1'
 *  Gain: '<S24>/Gain'
 *  Gain: '<S24>/Gain1'
 *  Gain: '<S24>/Gain2'
 *  Gain: '<S24>/Gain3'
 *  Gain: '<S24>/Gain4'
 *  Lookup_n-D: '<S18>/Z'uq Prop'
 *  Lookup_n-D: '<S22>/KdX1'
 *  Lookup_n-D: '<S22>/KdX2'
 *  Lookup_n-D: '<S22>/KdX3'
 *  Lookup_n-D: '<S22>/KdX4'
 *  Lookup_n-D: '<S24>/ZudX1 q+1'
 *  Lookup_n-D: '<S24>/ZudX1 q+2'
 *  Lookup_n-D: '<S24>/ZudX1 q+3'
 *  Lookup_n-D: '<S24>/ZudX1 q+4'
 *  Lookup_n-D: '<S24>/ZudX1 q+5'
 *  Lookup_n-D: '<S27>/NdX1'
 *  Lookup_n-D: '<S27>/NdX2'
 *  Lookup_n-D: '<S27>/NdX3'
 *  Lookup_n-D: '<S27>/NdX4'
 *  Lookup_n-D: '<S61>/YdX1'
 *  Lookup_n-D: '<S61>/YdX2'
 *  Lookup_n-D: '<S61>/YdX3'
 *  Lookup_n-D: '<S61>/YdX4'
 *  Lookup_n-D: '<S63>/ZudX1 q+10'
 *  Lookup_n-D: '<S63>/ZudX1 q+6'
 *  Lookup_n-D: '<S63>/ZudX1 q+7'
 *  Lookup_n-D: '<S63>/ZudX1 q+8'
 *  Lookup_n-D: '<S63>/ZudX1 q+9'
 *  MATLAB Function: '<S11>/Mx'
 *  MATLAB Function: '<S12>/My'
 *  MATLAB Function: '<S13>/Mz'
 *  MATLAB Function: '<S14>/Tprop'
 *  MATLAB Function: '<S16>/Fx'
 *  MATLAB Function: '<S17>/Fy'
 *  MATLAB Function: '<S18>/Fz'
 *  MATLAB Function: '<S30>/Wave particle velocity at the center of Appendages'
 *  Product: '<S18>/Product3'
 *  Saturate: '<S18>/Saturation4'
 *  Saturate: '<S18>/Saturation5'
 *  Sum: '<S10>/Add'
 *  Sum: '<S10>/Add1'
 *  Sum: '<S10>/Add2'
 *  Sum: '<S10>/Add3'
 *  Sum: '<S10>/Add4'
 */
rtb_TmpSignalConversionAtSFun_b[0] = (((zerr * zerrint_tmp + rtb_Add_l_idx_0) + (dXiuq + tmp_6)) - tmp_7) + Omega_s[0];
rtb_TmpSignalConversionAtSFun_b[1] = (((((5.051241E+6 * Fy_total * My_total_0 + 5.051241E+6 * Mx_total_0 * Mx_total) + 5.051241E+6 * Mx_total_1 * RMATX_tmp_tmp_0) + 5.051241E+6 * Fx_total * RMATX_tmp_tmp) + (zerr * thetaerr * zerrint - rtb_Add_l_idx_1)) + tmp_9) + Omega_s[1];
rtb_TmpSignalConversionAtSFun_b[2] = (((((((2.5256205E+6 * look2_binlxpw(dh, rtb_dpeth, Model_6DOF_P.ZudX1q6_bp01Data, Model_6DOF_P.ZudX1q6_bp02Data, Model_6DOF_P.ZudX1q6_tableData, Model_6DOF_P.ZudX1q6_maxIndex, 7U) * My_total_0 + 2.5256205E+6 * look2_binlxpw(absxk, rtb_dpeth, Model_6DOF_P.ZudX1q7_bp01Data, Model_6DOF_P.ZudX1q7_bp02Data, Model_6DOF_P.ZudX1q7_tableData, Model_6DOF_P.ZudX1q7_maxIndex, 7U) * Mx_total) + 2.5256205E+6 * look2_binlxpw(arg1, rtb_dpeth, Model_6DOF_P.ZudX1q8_bp01Data, Model_6DOF_P.ZudX1q8_bp02Data, Model_6DOF_P.ZudX1q8_tableData, Model_6DOF_P.ZudX1q8_maxIndex, 7U) * RMATX_tmp_tmp_0) + 2.5256205E+6 * look2_binlxpw(arg2, rtb_dpeth, Model_6DOF_P.ZudX1q9_bp01Data, Model_6DOF_P.ZudX1q9_bp02Data, Model_6DOF_P.ZudX1q9_tableData, Model_6DOF_P.ZudX1q9_maxIndex, 7U) * RMATX_tmp_tmp) + 2.5256205E+6 * look2_binlxpw(arg3, rtb_dpeth, Model_6DOF_P.ZudX1q10_bp01Data, Model_6DOF_P.ZudX1q10_bp02Data, Model_6DOF_P.ZudX1q10_tableData, Model_6DOF_P.ZudX1q10_maxIndex, 7U) * Fz_total) + (rtb_Add_l_idx_2 - (Model_6DOF_P.Mb + Model_6DOF_B.dmasskg) * 9.81 * cos(Model_6DOF_B.Integrator_d[4]))) + dv) + look2_binlxpw(Model_6DOF_B.Gain2[3] * rtb_Sign1_hb, rtb_Sign1_hb, Model_6DOF_P.ZuqProp_bp01Data, Model_6DOF_P.ZuqProp_bp02Data, Model_6DOF_P.ZuqProp_tableData, Model_6DOF_P.ZuqProp_maxIndex, 9U) * 1.7729855910000002E+8) + Omega_s[2];
rtb_TmpSignalConversionAtSFun_b[3] = (((((((3.5459711820000005E+8 * RMATD_0 * My_total_0 + 3.5459711820000005E+8 * intrp3d_l_pw(bpIndices_1, fractions, Model_6DOF_P.KdX2_tableData, Model_6DOF_P.KdX2_dimSizes) * Mx_total) + 3.5459711820000005E+8 * intrp3d_l_pw(bpIndices_2, fractions_0, Model_6DOF_P.KdX3_tableData, Model_6DOF_P.KdX3_dimSizes) * RMATX_tmp_tmp_0) + 3.5459711820000005E+8 * intrp3d_l_pw(bpIndices_3, fractions_1, Model_6DOF_P.KdX4_tableData, Model_6DOF_P.KdX4_dimSizes) * RMATX_tmp_tmp) + arg4) + (thetaerrint * Model_6DOF_P.Xg * thetaerr * zerrint + rtb_Add_l_idx_3)) + rtb_Add[0]) + rtb_deltafalllimit_h) + ((My_total_1 * -0.021064 - 0.03247 * rtb_UkYk1_l) + 0.063982) * 1025.0 * My_total_2 * 3125.0;
rtb_TmpSignalConversionAtSFun_b[4] = (((((((Model_6DOF_P.Gain_Gain_j * psierr_tmp * Model_6DOF_P.Gain1_Gain_a * 1.7729855910000002E+8 * My_total_0 + Model_6DOF_P.Gain3_Gain_c * psierrint * Model_6DOF_P.Gain1_Gain_a * 1.7729855910000002E+8 * Mx_total) + Model_6DOF_P.Gain2_Gain_nk * arg5 * Model_6DOF_P.Gain1_Gain_a * 1.7729855910000002E+8 * RMATX_tmp_tmp_0) + Model_6DOF_P.Gain1_Gain_c * Mz_total * Model_6DOF_P.Gain1_Gain_a * 1.7729855910000002E+8 * RMATX_tmp_tmp) + Model_6DOF_P.Gain4_Gain_l * My_total * Model_6DOF_P.Gain1_Gain_a * 1.7729855910000002E+8 * Fz_total) + rtb_Add_l_idx_4) + absx31) + tmp_a) + rtb_Add[1];
rtb_TmpSignalConversionAtSFun_b[5] = (((((Model_6DOF_P.Gain1_Gain_i * look2_binlxpw(dh, Model_6DOF_B.Integrator_d[2], Model_6DOF_P.NdX1_bp01Data, Model_6DOF_P.NdX1_bp02Data, Model_6DOF_P.NdX1_tableData, Model_6DOF_P.NdX1_maxIndex, 3U) * 3.5459711820000005E+8 * My_total_0 + Model_6DOF_P.Gain1_Gain_i * look2_binlxpw(absxk, Model_6DOF_B.Integrator_d[2], Model_6DOF_P.NdX2_bp01Data, Model_6DOF_P.NdX2_bp02Data, Model_6DOF_P.NdX2_tableData, Model_6DOF_P.NdX2_maxIndex, 3U) * 3.5459711820000005E+8 * Mx_total) + Model_6DOF_P.Gain1_Gain_i * look2_binlxpw(arg1, Model_6DOF_B.Integrator_d[2], Model_6DOF_P.NdX3_bp01Data, Model_6DOF_P.NdX3_bp02Data, Model_6DOF_P.NdX3_tableData, Model_6DOF_P.NdX3_maxIndex, 3U) * 3.5459711820000005E+8 * RMATX_tmp_tmp_0) + Model_6DOF_P.Gain1_Gain_i * look2_binlxpw(arg2, Model_6DOF_B.Integrator_d[2], Model_6DOF_P.NdX4_bp01Data, Model_6DOF_P.NdX4_bp02Data, Model_6DOF_P.NdX4_tableData, Model_6DOF_P.NdX4_maxIndex, 3U) * 3.5459711820000005E+8 * RMATX_tmp_tmp) + tmp_5) + rtb_Add_l_idx_5) + rtb_Add[2];
psierr_tmp = Model_6DOF_B.Integrator[5] * Model_6DOF_B.Integrator[5];
psierrint = Model_6DOF_B.Integrator[4] * Model_6DOF_B.Integrator[4];
arg5 = Model_6DOF_B.Integrator[2] * Model_6DOF_B.Integrator[4] - Model_6DOF_B.Integrator[1] * Model_6DOF_B.Integrator[5];
tmp_4[0] = (((arg5 - (psierrint + psierr_tmp) * Model_6DOF_P.Xg) + Model_6DOF_P.Yg * Model_6DOF_B.Integrator[3] * Model_6DOF_B.Integrator[4]) + Model_6DOF_P.Zg * Model_6DOF_B.Integrator[3] * Model_6DOF_B.Integrator[5]) * Model_6DOF_P.Mb;
Mz_total = Model_6DOF_B.Integrator[3] * Model_6DOF_B.Integrator[3];
My_total = Model_6DOF_B.Integrator[0] * Model_6DOF_B.Integrator[5] - Model_6DOF_B.Integrator[2] * Model_6DOF_B.Integrator[3];
tmp_4[1] = (((My_total - (psierr_tmp + Mz_total) * Model_6DOF_P.Yg) + Model_6DOF_P.Zg * Model_6DOF_B.Integrator[4] * Model_6DOF_B.Integrator[5]) + Model_6DOF_P.Xg * Model_6DOF_B.Integrator[3] * Model_6DOF_B.Integrator[4]) * Model_6DOF_P.Mb;
psierr_tmp = Model_6DOF_B.Integrator[1] * Model_6DOF_B.Integrator[3] - Model_6DOF_B.Integrator[0] * Model_6DOF_B.Integrator[4];
tmp_4[2] = (((psierr_tmp - (Mz_total + psierrint) * Model_6DOF_P.Zg) + Model_6DOF_P.Xg * Model_6DOF_B.Integrator[5] * Model_6DOF_B.Integrator[3]) + Model_6DOF_P.Yg * Model_6DOF_B.Integrator[5] * Model_6DOF_B.Integrator[4]) * Model_6DOF_P.Mb;
tmp_4[3] = (psierr_tmp * Model_6DOF_P.Yg - My_total * Model_6DOF_P.Zg) * Model_6DOF_P.Mb + (Model_6DOF_P.Ixx - Model_6DOF_P.Iyy) * Model_6DOF_B.Integrator[4] * Model_6DOF_B.Integrator[5];
tmp_4[4] = (arg5 * Model_6DOF_P.Zg - psierr_tmp * Model_6DOF_P.Xg) * Model_6DOF_P.Mb + (Model_6DOF_P.Ixx - Model_6DOF_P.Izz) * Model_6DOF_B.Integrator[5] * Model_6DOF_B.Integrator[3];
tmp_4[5] = (My_total * Model_6DOF_P.Xg - arg5 * Model_6DOF_P.Yg) * Model_6DOF_P.Mb + (Model_6DOF_P.Iyy - Model_6DOF_P.Ixx) * Model_6DOF_B.Integrator[3] * Model_6DOF_B.Integrator[4];
for (i = 0; i < 6; i++) {
    p3 = 6 * i;
    for (b_k = 5; b_k >= 0; b_k--) {
        itmp = 6 * b_k;
        c_ix = b_k + p3;
        psierr_tmp = a[c_ix];
        if (psierr_tmp != 0.0) {
            a[c_ix] = psierr_tmp / A[b_k + itmp];
            for (p1_0 = 0; p1_0 < b_k; p1_0++) {
                ijA = p1_0 + p3;
                a[ijA] -= A[p1_0 + itmp] * a[c_ix];
            }
        }
    }
    dXiuq_0[i] = rtb_TmpSignalConversionAtSFun_b[i] - tmp_4[i];
    Model_6DOF_B.out[i] = 0.0;
}
for (c_ix = 0; c_ix < 6; c_ix++) {
    for (i = 0; i < 6; i++) {
        Model_6DOF_B.out[i] += a[6 * c_ix + i] * dXiuq_0[c_ix];
    }
}
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
}






            }
        



                
                    if (rtmIsMajorTimeStep(Model_6DOF_M)) {
                        /* Matfile logging */
            
    rt_UpdateTXYLogVars(Model_6DOF_M->rtwLogInfo, (Model_6DOF_M->Timing.t));

                } /* end MajorTimeStep */




                    if (rtmIsMajorTimeStep(Model_6DOF_M)) {
                        




                            
real_T (*lastU)[45];
int32_T i;

                                    
                                    







if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d542}Update for UnitDelay: '<S86>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE = rtb_DifferenceInputs2;
    /* {S!d544}Update for UnitDelay: '<S84>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_o = rtb_DifferenceInputs2_c;
    /* {S!d546}Update for UnitDelay: '<S72>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_a = rtb_DifferenceInputs2_d;
    /* {S!d548}Update for UnitDelay: '<S73>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_i = rtb_DifferenceInputs2_m;
    /* {S!d550}Update for UnitDelay: '<S74>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_f = rtb_DifferenceInputs2_g;
    /* {S!d552}Update for UnitDelay: '<S75>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_g = rtb_DifferenceInputs2_k;
    /* {S!d554}Update for UnitDelay: '<S76>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_j = rtb_DifferenceInputs2_i;
    /* {S!d556}Update for Memory: '<S65>/Memory1' */
    for (i = 0; i < 6; i++) {
        Model_6DOF_DW.Memory1_PreviousInput[i] = Model_6DOF_B.out[i];
    }
    /* {E!d556}End of Update for Memory: '<S65>/Memory1' */
}
/* {S!d558}Update for Derivative: '<S15>/Derivative1' incorporates:
 *  Sum: '<S15>/Add'
 */
if (Model_6DOF_DW.TimeStampA == (rtInf)) {
    Model_6DOF_DW.TimeStampA = Model_6DOF_M->Timing.t[0];
    lastU = &Model_6DOF_DW.LastUAtTimeA;
} else if (Model_6DOF_DW.TimeStampB == (rtInf)) {
    Model_6DOF_DW.TimeStampB = Model_6DOF_M->Timing.t[0];
    lastU = &Model_6DOF_DW.LastUAtTimeB;
} else if (Model_6DOF_DW.TimeStampA < Model_6DOF_DW.TimeStampB) {
    Model_6DOF_DW.TimeStampA = Model_6DOF_M->Timing.t[0];
    lastU = &Model_6DOF_DW.LastUAtTimeA;
} else {
    Model_6DOF_DW.TimeStampB = Model_6DOF_M->Timing.t[0];
    lastU = &Model_6DOF_DW.LastUAtTimeB;
}
for (i = 0; i < 45; i++) {
    (*lastU)[i] = Model_6DOF_B.Add[i];
}
/* {E!d558}End of Update for Derivative: '<S15>/Derivative1' */
if (rtmIsMajorTimeStep(Model_6DOF_M)) {
    /* {S!d560}Update for UnitDelay: '<S82>/Delay Input2' */
    Model_6DOF_DW.DelayInput2_DSTATE_m = rtb_DifferenceInputs2_f;
}





                




                
            } /* end MajorTimeStep */

                    

        if (rtmIsMajorTimeStep(Model_6DOF_M)) {


        
            /* signal main to stop simulation */
            { /* Sample time: [0.0s, 0.0s] */
            if ( (rtmGetTFinal(Model_6DOF_M)!=-1) &&
            !((rtmGetTFinal(Model_6DOF_M)-(((Model_6DOF_M->Timing.clockTick1+Model_6DOF_M->Timing.clockTickH1* 4294967296.0))  * 0.05)) > (((Model_6DOF_M->Timing.clockTick1+Model_6DOF_M->Timing.clockTickH1* 4294967296.0))  * 0.05) * (DBL_EPSILON))) {
                rtmSetErrorStatus(Model_6DOF_M, "Simulation finished");
            }
            }

                rt_ertODEUpdateContinuousStates(&Model_6DOF_M->solverInfo);

                        /* Update absolute time for base rate */
                        /* The "clockTick0" counts the number of times the code of this task has
        * been executed. The absolute time is the multiplication of "clockTick0"
        * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
        * overflow during the application lifespan selected.
            * Timer of this task consists of two 32 bit unsigned integers.
            * The two integers represent the low bits Timing.clockTick0 and the high bits
            * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
        */

        if(!(++Model_6DOF_M->Timing.clockTick0)) {
 ++Model_6DOF_M->Timing.clockTickH0; 
}  Model_6DOF_M->Timing.t[0] = rtsiGetSolverStopTime(&Model_6DOF_M->solverInfo);


                {
            /* Update absolute timer for sample time: [0.05s, 0.0s] */
                        /* The "clockTick1" counts the number of times the code of this task has
        * been executed. The resolution of this integer timer is 0.05, which is the step size
        * of the task. Size of "clockTick1" ensures timer will not overflow during the
        * application lifespan selected.
            * Timer of this task consists of two 32 bit unsigned integers.
            * The two integers represent the low bits Timing.clockTick1 and the high bits
            * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
        */

        Model_6DOF_M->Timing.clockTick1++;
 if (!Model_6DOF_M->Timing.clockTick1) {
 Model_6DOF_M->Timing.clockTickH1++; 
}

        }

            





        

    } /* end MajorTimeStep */


            


        
        



                


        } 
        
                                    /* Derivatives for root system: '<Root>' */
                
        void Model_6DOF_derivatives(void)
        {

            

            
    
XDot_Model_6DOF_T *_rtXdot;
int32_T i;

    




                                
        
    




                                                
                                    _rtXdot = ((XDot_Model_6DOF_T *) Model_6DOF_M->derivs);
for (i = 0; i < 6; i++) {
    /* {S!d562}Derivatives for Integrator: '<S65>/Integrator' */
    _rtXdot->Integrator_CSTATE[i] = Model_6DOF_B.out[i];
    /* {S!d564}Derivatives for Integrator: '<S64>/Integrator' */
    _rtXdot->Integrator_CSTATE_h[i] = Model_6DOF_B.out_f[i];
}





    




                
        
            }
            



















    /* Model initialize function */
    
            void Model_6DOF_initialize(void)
    {
            


    




    
        



            /* Registration code */
                
    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    
        


                        
                        /* initialize real-time model */
                        (void) memset((void *)Model_6DOF_M, 0,
sizeof(RT_MODEL_Model_6DOF_T));
                        
                        



            
            
        {
            /* Setup solver object */

                rtsiSetSimTimeStepPtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->Timing.simTimeStep);
            rtsiSetTPtr(&Model_6DOF_M->solverInfo, &rtmGetTPtr(Model_6DOF_M));
                rtsiSetStepSizePtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->Timing.stepSize0);
                rtsiSetdXPtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->derivs);
                rtsiSetContStatesPtr(&Model_6DOF_M->solverInfo, (real_T **) &Model_6DOF_M->contStates);
                rtsiSetNumContStatesPtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->Sizes.numContStates);
                    rtsiSetNumPeriodicContStatesPtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->Sizes.numPeriodicContStates);
                    rtsiSetPeriodicContStateIndicesPtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->periodicContStateIndices);
                    rtsiSetPeriodicContStateRangesPtr(&Model_6DOF_M->solverInfo, &Model_6DOF_M->periodicContStateRanges);


            rtsiSetErrorStatusPtr(&Model_6DOF_M->solverInfo, (&rtmGetErrorStatus(Model_6DOF_M)));


            rtsiSetRTModelPtr(&Model_6DOF_M->solverInfo, Model_6DOF_M);
        }
            rtsiSetSimTimeStep(&Model_6DOF_M->solverInfo, MAJOR_TIME_STEP);
                    Model_6DOF_M->intgData.y = Model_6DOF_M->odeY;
                    Model_6DOF_M->intgData.f[0] = Model_6DOF_M->odeF[0];
                    Model_6DOF_M->intgData.f[1] = Model_6DOF_M->odeF[1];
                    Model_6DOF_M->intgData.f[2] = Model_6DOF_M->odeF[2];
                
                Model_6DOF_M->contStates = ((X_Model_6DOF_T *) &Model_6DOF_X);


                rtsiSetSolverData(&Model_6DOF_M->solverInfo, (void *)&Model_6DOF_M->intgData);
                rtsiSetIsMinorTimeStepWithModeChange(&Model_6DOF_M->solverInfo, false);
        rtsiSetSolverName(&Model_6DOF_M->solverInfo,"ode3");





            rtmSetTPtr(Model_6DOF_M, &Model_6DOF_M->Timing.tArray[0]);







                            rtmSetTFinal(Model_6DOF_M, 5000.0);
                                Model_6DOF_M->Timing.stepSize0  = 0.05;


                    






                    
        /* Setup for data logging */
        {
                static RTWLogInfo rt_DataLoggingInfo;
                rt_DataLoggingInfo.loggingInterval = (NULL);

                        Model_6DOF_M->rtwLogInfo = &rt_DataLoggingInfo;

        }


    /* Setup for data logging */
    {
                        rtliSetLogXSignalInfo(Model_6DOF_M->rtwLogInfo, (NULL));

                        rtliSetLogXSignalPtrs(Model_6DOF_M->rtwLogInfo, (NULL));


                    rtliSetLogT(Model_6DOF_M->rtwLogInfo, "tout");

                    rtliSetLogX(Model_6DOF_M->rtwLogInfo, "");

                    rtliSetLogXFinal(Model_6DOF_M->rtwLogInfo, "");

                    rtliSetLogVarNameModifier(Model_6DOF_M->rtwLogInfo, "rt_");

                    rtliSetLogFormat(Model_6DOF_M->rtwLogInfo, 4);

                    rtliSetLogMaxRows(Model_6DOF_M->rtwLogInfo, 0);

                    rtliSetLogDecimation(Model_6DOF_M->rtwLogInfo, 1);





                        rtliSetLogY(Model_6DOF_M->rtwLogInfo, "");


                        rtliSetLogYSignalInfo(Model_6DOF_M->rtwLogInfo, (NULL));

                        rtliSetLogYSignalPtrs(Model_6DOF_M->rtwLogInfo, (NULL));

    }









        




        /* block I/O */
        
        


                
                (void) memset(((void *) &Model_6DOF_B), 0,
sizeof(B_Model_6DOF_T));
                

                





        























        



            /* states (continuous) */
            {
                
                (void) memset((void *)&Model_6DOF_X, 0,
sizeof(X_Model_6DOF_T));


            }



        /* states (dwork) */
        
        



                                        (void) memset((void *)&Model_6DOF_DW,  0,
 sizeof(DW_Model_6DOF_T));






        
    


        
        
        


        




        







        

    
            
    
        




        /* Matfile logging */
        
    rt_StartDataLoggingWithStartTime(Model_6DOF_M->rtwLogInfo, 0.0, rtmGetTFinal(Model_6DOF_M), Model_6DOF_M->Timing.stepSize0, (&rtmGetErrorStatus(Model_6DOF_M)));









            
        




                        




                
                                    
                                    /* SetupRuntimeResources for Scope: '<Root>/BV' */
                    

































            {

                RTWLogSignalInfo rt_ScopeSignalInfo;
                static  int_T  rt_ScopeSignalWidths[]        = {1, 1, 1, 1, 1, 1};
                static  int_T  rt_ScopeSignalNumDimensions[] = {1, 1, 1, 1, 1, 1};
                static  int_T  rt_ScopeSignalDimensions[]    = {1, 1, 1, 1, 1, 1};
                static  void *rt_ScopeCurrSigDims[] = {(NULL), (NULL), (NULL), (NULL), (NULL), (NULL)};
                static  int_T  rt_ScopeCurrSigDimsSize[]     = {4, 4, 4, 4, 4, 4};
                static  const char_T *rt_ScopeSignalLabels[] = {"", 
"", 
"", 
"", 
"", 
""};
                static  char_T rt_ScopeSignalTitles[]        = "X1X2X3X4X5X6";
                static  int_T  rt_ScopeSignalTitleLengths[]  = {2, 2, 2, 2, 2, 2};
                static  boolean_T rt_ScopeSignalIsVarDims[]  = {0, 0, 0, 0, 0, 0};
                    static  int_T  rt_ScopeSignalPlotStyles[]  = {0, 0, 0, 0, 0, 0};
                BuiltInDTypeId dTypes[6] = {SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE};
                static  char_T rt_ScopeBlockName[]          = "Model_6DOF/BV";
                    static  int_T rt_ScopeFrameData[] = {0, 0, 0, 0, 0, 0};
                static  RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =                 {
                    (NULL), (NULL), (NULL), (NULL), (NULL), (NULL)
                };

                rt_ScopeSignalInfo.numSignals       = 6;
                rt_ScopeSignalInfo.numCols          = rt_ScopeSignalWidths;
                rt_ScopeSignalInfo.numDims          = rt_ScopeSignalNumDimensions;
                rt_ScopeSignalInfo.dims             = rt_ScopeSignalDimensions;
                rt_ScopeSignalInfo.isVarDims        = rt_ScopeSignalIsVarDims;
                rt_ScopeSignalInfo.currSigDims      = rt_ScopeCurrSigDims;
                rt_ScopeSignalInfo.currSigDimsSize  = rt_ScopeCurrSigDimsSize;
                rt_ScopeSignalInfo.dataTypes        = dTypes;
                    rt_ScopeSignalInfo.complexSignals   = (NULL);
                    rt_ScopeSignalInfo.frameData      = rt_ScopeFrameData;
                rt_ScopeSignalInfo.preprocessingPtrs = rt_ScopeSignalLoggingPreprocessingFcnPtrs;
                rt_ScopeSignalInfo.labels.cptr      = rt_ScopeSignalLabels;
                rt_ScopeSignalInfo.titles           = rt_ScopeSignalTitles;
                rt_ScopeSignalInfo.titleLengths     = rt_ScopeSignalTitleLengths;
                    rt_ScopeSignalInfo.plotStyles     = rt_ScopeSignalPlotStyles;
                rt_ScopeSignalInfo.blockNames.cptr  = (NULL);
                rt_ScopeSignalInfo.stateNames.cptr  = (NULL);
                rt_ScopeSignalInfo.crossMdlRef      = (NULL);
                rt_ScopeSignalInfo.dataTypeConvert  = (NULL);

                

    Model_6DOF_DW.BV_PWORK.LoggedData[0] = rt_CreateStructLogVar(
    Model_6DOF_M->rtwLogInfo,
    0.0,
    rtmGetTFinal(Model_6DOF_M),
    Model_6DOF_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Model_6DOF_M)),
    "Bv",
    1,
    0,
    1,
    0.05,
    &rt_ScopeSignalInfo,
    rt_ScopeBlockName);

                if (Model_6DOF_DW.BV_PWORK.LoggedData[0] == (NULL)) return;
            }
 /* SetupRuntimeResources for Scope: '<Root>/BX' */
                    

































            {

                RTWLogSignalInfo rt_ScopeSignalInfo;
                static  int_T  rt_ScopeSignalWidths[]        = {1, 1, 1, 1, 1, 1};
                static  int_T  rt_ScopeSignalNumDimensions[] = {1, 1, 1, 1, 1, 1};
                static  int_T  rt_ScopeSignalDimensions[]    = {1, 1, 1, 1, 1, 1};
                static  void *rt_ScopeCurrSigDims[] = {(NULL), (NULL), (NULL), (NULL), (NULL), (NULL)};
                static  int_T  rt_ScopeCurrSigDimsSize[]     = {4, 4, 4, 4, 4, 4};
                static  const char_T *rt_ScopeSignalLabels[] = {"", 
"", 
"", 
"", 
"", 
""};
                static  char_T rt_ScopeSignalTitles[]        = "X1X2X3X4X5X6";
                static  int_T  rt_ScopeSignalTitleLengths[]  = {2, 2, 2, 2, 2, 2};
                static  boolean_T rt_ScopeSignalIsVarDims[]  = {0, 0, 0, 0, 0, 0};
                    static  int_T  rt_ScopeSignalPlotStyles[]  = {0, 0, 0, 0, 0, 0};
                BuiltInDTypeId dTypes[6] = {SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE};
                static  char_T rt_ScopeBlockName[]          = "Model_6DOF/BX";
                    static  int_T rt_ScopeFrameData[] = {0, 0, 0, 0, 0, 0};
                static  RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =                 {
                    (NULL), (NULL), (NULL), (NULL), (NULL), (NULL)
                };

                rt_ScopeSignalInfo.numSignals       = 6;
                rt_ScopeSignalInfo.numCols          = rt_ScopeSignalWidths;
                rt_ScopeSignalInfo.numDims          = rt_ScopeSignalNumDimensions;
                rt_ScopeSignalInfo.dims             = rt_ScopeSignalDimensions;
                rt_ScopeSignalInfo.isVarDims        = rt_ScopeSignalIsVarDims;
                rt_ScopeSignalInfo.currSigDims      = rt_ScopeCurrSigDims;
                rt_ScopeSignalInfo.currSigDimsSize  = rt_ScopeCurrSigDimsSize;
                rt_ScopeSignalInfo.dataTypes        = dTypes;
                    rt_ScopeSignalInfo.complexSignals   = (NULL);
                    rt_ScopeSignalInfo.frameData      = rt_ScopeFrameData;
                rt_ScopeSignalInfo.preprocessingPtrs = rt_ScopeSignalLoggingPreprocessingFcnPtrs;
                rt_ScopeSignalInfo.labels.cptr      = rt_ScopeSignalLabels;
                rt_ScopeSignalInfo.titles           = rt_ScopeSignalTitles;
                rt_ScopeSignalInfo.titleLengths     = rt_ScopeSignalTitleLengths;
                    rt_ScopeSignalInfo.plotStyles     = rt_ScopeSignalPlotStyles;
                rt_ScopeSignalInfo.blockNames.cptr  = (NULL);
                rt_ScopeSignalInfo.stateNames.cptr  = (NULL);
                rt_ScopeSignalInfo.crossMdlRef      = (NULL);
                rt_ScopeSignalInfo.dataTypeConvert  = (NULL);

                

    Model_6DOF_DW.BX_PWORK.LoggedData[0] = rt_CreateStructLogVar(
    Model_6DOF_M->rtwLogInfo,
    0.0,
    rtmGetTFinal(Model_6DOF_M),
    Model_6DOF_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Model_6DOF_M)),
    "Bx",
    1,
    0,
    1,
    0.05,
    &rt_ScopeSignalInfo,
    rt_ScopeBlockName);

                if (Model_6DOF_DW.BX_PWORK.LoggedData[0] == (NULL)) return;
            }
 



        




                



            {
    
int32_T i;






                




                                                
                                    

/* {S!d18}InitializeConditions for UnitDelay: '<S86>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE = Model_6DOF_P.DelayInput2_InitialCondition;
/* {S!d20}InitializeConditions for UnitDelay: '<S84>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_o = Model_6DOF_P.DelayInput2_InitialCondition_c;
/* {S!d22}InitializeConditions for UnitDelay: '<S72>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_a = Model_6DOF_P.DelayInput2_InitialCondition_n;
/* {S!d24}InitializeConditions for UnitDelay: '<S73>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_i = Model_6DOF_P.DelayInput2_InitialCondition_g;
/* {S!d26}InitializeConditions for UnitDelay: '<S74>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_f = Model_6DOF_P.DelayInput2_InitialCondition_m;
/* {S!d28}InitializeConditions for UnitDelay: '<S75>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_g = Model_6DOF_P.DelayInput2_InitialCondition_j;
/* {S!d30}InitializeConditions for UnitDelay: '<S76>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_j = Model_6DOF_P.DelayInput2_InitialCondition_jw;
for (i = 0; i < 6; i++) {
    /* {S!d32}InitializeConditions for Integrator: '<S65>/Integrator' */
    Model_6DOF_X.Integrator_CSTATE[i] = Model_6DOF_P.Bv_0[i];
    /* {S!d34}InitializeConditions for Integrator: '<S64>/Integrator' */
    Model_6DOF_X.Integrator_CSTATE_h[i] = Model_6DOF_P.Bx_0[i];
    /* {S!d36}InitializeConditions for Memory: '<S65>/Memory1' */
    Model_6DOF_DW.Memory1_PreviousInput[i] = Model_6DOF_P.Ba_0[i];
}
/* {S!d38}InitializeConditions for Derivative: '<S15>/Derivative1' */
Model_6DOF_DW.TimeStampA = (rtInf);
Model_6DOF_DW.TimeStampB = (rtInf);
/* {S!d40}InitializeConditions for UnitDelay: '<S82>/Delay Input2' */
Model_6DOF_DW.DelayInput2_DSTATE_m = Model_6DOF_P.DelayInput2_InitialCondition_e;
/* {S!d42}SystemInitialize for MATLAB Function: '<S1>/pf_controller' */
Model_6DOF_DW.zerr_prev = 0.0;
Model_6DOF_DW.zerr_int_prev = 0.0;
Model_6DOF_DW.thetaerr_prev = 0.0;
Model_6DOF_DW.thetaerr_int_prev = 0.0;
Model_6DOF_DW.psierr_prev = 0.0;
Model_6DOF_DW.psierr_int_prev = 0.0;












                        }


    





        



    }        





        




        
        /* Model terminate function */
                    void Model_6DOF_terminate(void)

        {
            
            /* (no terminate code required) */



                


        }
            





    




    

    

    

    
