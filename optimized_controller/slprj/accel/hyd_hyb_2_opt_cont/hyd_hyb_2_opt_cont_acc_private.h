/*
 * hyd_hyb_2_opt_cont_acc_private.h
 *
 * Code generation for model "hyd_hyb_2_opt_cont_acc.mdl".
 *
 * Model version              : 1.2955
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Fri Jun 01 10:37:24 2012
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_hyd_hyb_2_opt_cont_acc_private_h_
#define RTW_HEADER_hyd_hyb_2_opt_cont_acc_private_h_
#include "rtwtypes.h"
#ifndef RTW_COMMON_DEFINES_
# define RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 }
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers delcare free without const! */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif                                 /* RTW_COMMON_DEFINES_ */

/* Used by FromWorkspace Block: '<Root>/B_66_29' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? muDoubleScalarFloor((v) + 0.5) : muDoubleScalarCeil((v) - 0.5) )
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
void hyd_hyb_2_opt_cont_EnabledSubsystem1_Init(SimStruct *const S,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont *localX);
void hyd_hyb_2_opt_cont_EnabledSubsystem1_Deriv(SimStruct *const S,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *localP,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont *localX,
  rtXdot_EnabledSubsystem1_hyd_hyb_2_opt_cont *localXdot);
void hyd_hyb_2_opt_cont_EnabledSubsystem1_Disable(SimStruct *const S,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *localP);
void hyd_hyb_2_opt_cont_EnabledSubsystem1(SimStruct *const S, real_T rtu_0,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *localP,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont *localX);

#endif                                 /* RTW_HEADER_hyd_hyb_2_opt_cont_acc_private_h_ */
