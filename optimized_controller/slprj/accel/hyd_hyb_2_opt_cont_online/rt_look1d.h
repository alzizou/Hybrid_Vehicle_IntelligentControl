/*
 * rt_look1d.h
 *
 * Code generation for model "hyd_hyb_2_opt_cont_online_acc.mdl".
 *
 * Model version              : 1.2998
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Fri May 18 22:02:20 2012
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_look1d_h_
#define RTW_HEADER_rt_look1d_h_
#include "rtwtypes.h"
#include "rt_look.h"

extern real_T rt_Lookup(const real_T *x, int_T xlen, real_T u, const real_T *y);

#endif                                 /* RTW_HEADER_rt_look1d_h_ */