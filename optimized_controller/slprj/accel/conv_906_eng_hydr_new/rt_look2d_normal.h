/*
 * rt_look2d_normal.h
 *
 * Code generation for model "conv_906_eng_hydr_new_acc.mdl".
 *
 * Model version              : 1.1483
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Tue Aug 21 00:14:16 2012
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_look2d_normal_h_
#define RTW_HEADER_rt_look2d_normal_h_
#include "rtwtypes.h"
#include "rt_look.h"

extern real_T rt_Lookup2D_Normal (const real_T *xVals, const int_T numX,
  const real_T *yVals, const int_T numY,
  const real_T *zVals,
  const real_T x, const real_T y);

#endif                                 /* RTW_HEADER_rt_look2d_normal_h_ */