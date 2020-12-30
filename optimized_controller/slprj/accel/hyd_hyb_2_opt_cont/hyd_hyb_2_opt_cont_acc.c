/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * hyd_hyb_2_opt_cont_acc.c
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
#include <math.h>
#include "hyd_hyb_2_opt_cont_acc.h"
#include "hyd_hyb_2_opt_cont_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
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

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
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
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
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
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  fractions[1U] = frac;
  bpIndices[1U] = iLeft;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = bpIndices[1U] * stride + bpIndices[0U];
  frac = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          frac) * fractions[1U] + frac;
}

/*
 * Initial conditions for enable system:
 *    '<S103>/Enabled Subsystem1'
 *    '<S103>/Enabled Subsystem2'
 *    '<S103>/Enabled Subsystem3'
 *    '<S103>/Enabled Subsystem4'
 */
void hyd_hyb_2_opt_cont_EnabledSubsystem1_Init(SimStruct *const S,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont *localX)
{
  /* InitializeConditions for TransferFcn: '<S112>/Clutch A Actuator' */
  localX->ClutchAActuator_CSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S103>/Enabled Subsystem1'
 *    '<S103>/Enabled Subsystem2'
 *    '<S103>/Enabled Subsystem3'
 *    '<S103>/Enabled Subsystem4'
 */
void hyd_hyb_2_opt_cont_EnabledSubsystem1_Disable(SimStruct *const S,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *localP)
{
  localB->B_8_0_0 = localP->P_0;
  localDW->EnabledSubsystem1_MODE = FALSE;
}

/*
 * Derivatives for enable system:
 *    '<S103>/Enabled Subsystem1'
 *    '<S103>/Enabled Subsystem2'
 *    '<S103>/Enabled Subsystem3'
 *    '<S103>/Enabled Subsystem4'
 */
void hyd_hyb_2_opt_cont_EnabledSubsystem1_Deriv(SimStruct *const S,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *localP,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont *localX,
  rtXdot_EnabledSubsystem1_hyd_hyb_2_opt_cont *localXdot)
{
  if (localDW->EnabledSubsystem1_MODE) {
    /* Derivatives for TransferFcn: '<S112>/Clutch A Actuator' */
    {
      localXdot->ClutchAActuator_CSTATE = (localP->P_1)*
        localX->ClutchAActuator_CSTATE;
      localXdot->ClutchAActuator_CSTATE += localP->P_2*localB->B_8_1_0;
    }
  } else {
    localXdot->ClutchAActuator_CSTATE = 0.0;
  }
}

/*
 * Output and update for enable system:
 *    '<S103>/Enabled Subsystem1'
 *    '<S103>/Enabled Subsystem2'
 *    '<S103>/Enabled Subsystem3'
 *    '<S103>/Enabled Subsystem4'
 */
void hyd_hyb_2_opt_cont_EnabledSubsystem1(SimStruct *const S, real_T rtu_0,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *localP,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont *localX)
{
  if (ssIsSampleHit(S, 1, 0) && ssIsMajorTimeStep(S)) {
    if (rtu_0 > 0.0) {
      if (!localDW->EnabledSubsystem1_MODE) {
        hyd_hyb_2_opt_cont_EnabledSubsystem1_Init(S, localX);
        localDW->EnabledSubsystem1_MODE = TRUE;
      }
    } else {
      if (localDW->EnabledSubsystem1_MODE) {
        hyd_hyb_2_opt_cont_EnabledSubsystem1_Disable(S, localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem1_MODE) {
    /* TransferFcn: '<S112>/Clutch A Actuator' */
    localB->B_8_0_0 = localP->P_3*localX->ClutchAActuator_CSTATE;
    if (ssIsSampleHit(S, 1, 0)) {
      localB->B_8_1_0 = localP->P_6;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(localDW->EnabledSubsystem1_SubsysRanBC);
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T B_69_551_0;
  int8_T rtAction;
  int8_T rtPrevAction;
  real_T B_69_817_0;
  boolean_T B_69_172_0;
  real_T B_69_811_0;
  real_T B_69_556_0;
  real_T B_69_557_0;
  real_T B_69_558_0;
  real_T B_6_2_0;
  real_T B_62_0_0;
  int32_T i;
  real_T tmp[10];
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T tmp_7;
  real_T tmp_8;
  real_T tmp_9;
  real_T tmp_a;
  real_T tmp_b;
  real_T tmp_c;
  real_T tmp_d;
  real_T tmp_e[15];
  real_T tmp_f[30];
  real_T tmp_g;
  real_T tmp_h;
  real_T tmp_i;
  real_T tmp_j;
  real_T tmp_k;
  real_T tmp_l;
  real_T tmp_m;
  real_T tmp_n;
  real_T tmp_o;
  real_T tmp_p;
  real_T tmp_q;
  real_T tmp_r;
  real_T tmp_s;
  real_T tmp_t;
  real_T tmp_u;
  real_T tmp_v;
  real_T tmp_w;
  real_T tmp_x;
  real_T tmp_y;
  real_T tmp_z;
  real_T tmp_10;
  real_T tmp_11;
  real_T tmp_12;
  real_T tmp_13;
  real_T tmp_14;
  real_T tmp_15[40];
  real_T tmp_16[5];
  real_T tmp_17[20];
  real_T tmp_18;
  real_T tmp_19;
  real_T tmp_1a;
  real_T tmp_1b;
  real_T tmp_1c;
  real_T tmp_1d;
  real_T tmp_1e;
  real_T tmp_1f;
  real_T tmp_1g;
  real_T tmp_1h;
  real_T tmp_1i;
  real_T tmp_1j;
  real_T tmp_1k;
  real_T tmp_1l;
  real_T tmp_1m;
  real_T tmp_1n;
  real_T tmp_1o;
  real_T tmp_1p;
  real_T tmp_1q;
  real_T tmp_1r;
  real_T tmp_1s[60];
  real_T tmp_1t[35];
  real_T tmp_1u[45];
  real_T tmp_1v;
  real_T tmp_1w;
  real_T tmp_1x;
  real_T tmp_1y;
  real_T tmp_1z;
  real_T tmp_20[65];
  real_T tmp_21[50];
  real_T tmp_22[25];
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_0_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput;
    ssCallAccelRunBlock(S, 69, 1, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_17_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory1_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_19_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1975 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1974;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_20_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1976;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_22_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1978 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1977;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_24_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1980 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1979;
    B_69_551_0 = ((Parameters *) ssGetDefaultParam(S))->P_1981;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1982 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1981;
  }

  rtAction = -1;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_20_0 == 5.0) {
      rtAction = 0;
    }

    ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_66_0_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_22_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1944, ((Parameters *)
        ssGetDefaultParam(S))->P_1945, ((Parameters *) ssGetDefaultParam(S))
        ->P_1943, ((Parameters *) ssGetDefaultParam(S))->P_2258, 51U);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_66_1_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1946 * ((BlockIO *) _ssGetBlockIO(S))->B_66_0_0;
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_66_2_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_24_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1948, ((Parameters *)
        ssGetDefaultParam(S))->P_1949, ((Parameters *) ssGetDefaultParam(S))
        ->P_1947, ((Parameters *) ssGetDefaultParam(S))->P_2259, 51U);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_66_3_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1950 * ((BlockIO *) _ssGetBlockIO(S))->B_66_2_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S2107>/Scope' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 66, 4, SS_CALL_MDL_OUTPUTS);

      /* Scope: '<S2107>/Scope1' */

      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 66, 5, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_66_6_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1951;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->for5galaccumulator_SubsysRanBC);
    }
  }

  rtAction = -1;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_20_0 == 10.0) {
      rtAction = 0;
    }

    ((D_Work *) ssGetRootDWork(S))->If1_ActiveSubsystem = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If1_ActiveSubsystem;
  }

  if (rtAction == 0) {
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_67_0_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_22_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1954, ((Parameters *)
        ssGetDefaultParam(S))->P_1955, ((Parameters *) ssGetDefaultParam(S))
        ->P_1953, ((Parameters *) ssGetDefaultParam(S))->P_2260, 51U);
      ((BlockIO *) _ssGetBlockIO(S))->B_67_1_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_24_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1957, ((Parameters *)
        ssGetDefaultParam(S))->P_1958, ((Parameters *) ssGetDefaultParam(S))
        ->P_1956, ((Parameters *) ssGetDefaultParam(S))->P_2261, 51U);

      /* Scope: '<S2105>/Scope' */

      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 67, 2, SS_CALL_MDL_OUTPUTS);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_67_3_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1959 * ((BlockIO *) _ssGetBlockIO(S))->B_67_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_67_4_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1960 * ((BlockIO *) _ssGetBlockIO(S))->B_67_1_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S2105>/Scope1' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 67, 5, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_67_6_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1961;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->for10galaccumulator_SubsysRanBC);
    }
  }

  rtAction = -1;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_20_0 == 15.0) {
      rtAction = 0;
    }

    ((D_Work *) ssGetRootDWork(S))->If2_ActiveSubsystem = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If2_ActiveSubsystem;
  }

  if (rtAction == 0) {
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_68_0_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_22_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1964, ((Parameters *)
        ssGetDefaultParam(S))->P_1965, ((Parameters *) ssGetDefaultParam(S))
        ->P_1963, ((Parameters *) ssGetDefaultParam(S))->P_2262, 51U);
      ((BlockIO *) _ssGetBlockIO(S))->B_68_1_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_24_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1967, ((Parameters *)
        ssGetDefaultParam(S))->P_1968, ((Parameters *) ssGetDefaultParam(S))
        ->P_1966, ((Parameters *) ssGetDefaultParam(S))->P_2263, 51U);

      /* Scope: '<S2106>/Scope' */

      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 68, 2, SS_CALL_MDL_OUTPUTS);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_68_3_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1969 * ((BlockIO *) _ssGetBlockIO(S))->B_68_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_68_4_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1970 * ((BlockIO *) _ssGetBlockIO(S))->B_68_1_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S2106>/Scope1' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 68, 5, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_68_6_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1971;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))
                 ->for15galaccumulator1_SubsysRanBC);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_33_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_66_3_0 + ((BlockIO *) _ssGetBlockIO(S))->B_67_4_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_68_4_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_34_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1983;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_35_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_19_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_33_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_34_0;

  /* Integrator: '<S7>/v(lit)' */
  if (((D_Work *) ssGetRootDWork(S))->vlit_IWORK.IcNeedsLoading) {
    ((ContinuousStates *) ssGetContStates(S))->vlit_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_35_0;
    ((D_Work *) ssGetRootDWork(S))->vlit_IWORK.IcNeedsLoading = 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_36_0 = ((ContinuousStates *)
    ssGetContStates(S))->vlit_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_37_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_36_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_34_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_38_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_37_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_33_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_39_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_1984 * ((BlockIO *) _ssGetBlockIO(S))->B_69_38_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_1985 * ((BlockIO *) _ssGetBlockIO(S))->B_69_39_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_69_551_0 = ((D_Work *) ssGetRootDWork(S))->Memory3_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_42_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1987 * ((D_Work *) ssGetRootDWork(S))
      ->Memory3_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_43_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1988 * ((BlockIO *) _ssGetBlockIO(S))->B_69_17_0;
  }

  rtPrevAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_l;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 <= 0.5) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_l;
  }

  if (rtPrevAction != rtAction) {
    switch (rtPrevAction) {
     case 0:
      /* Level2 S-Function Block: '<S151>/B_18_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 21, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S152>/B_19_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 22, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S153>/B_20_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 23, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S154>/B_21_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 24, 0, SS_CALL_RTW_GENERATED_DISABLE);
      break;

     case 1:
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_i = -1;

      /* Level2 S-Function Block: '<S512>/B_30_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 33, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S509>/B_27_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 30, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S510>/B_28_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 31, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S511>/B_29_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 32, 0, SS_CALL_RTW_GENERATED_DISABLE);
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h = -1;

      /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S512>/B_30_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 33, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S509>/B_27_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 30, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S510>/B_28_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 31, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S511>/B_29_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 32, 0, SS_CALL_RTW_GENERATED_DISABLE);
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h = -1;

      /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

      /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);
      break;
    }
  }

  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* Level2 S-Function Block: '<S151>/B_18_0' (stateflow) */

      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 21, 0, SS_CALL_RTW_GENERATED_ENABLE);

      /* Level2 S-Function Block: '<S152>/B_19_0' (stateflow) */

      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 22, 0, SS_CALL_RTW_GENERATED_ENABLE);

      /* Level2 S-Function Block: '<S153>/B_20_0' (stateflow) */

      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 23, 0, SS_CALL_RTW_GENERATED_ENABLE);

      /* Level2 S-Function Block: '<S154>/B_21_0' (stateflow) */

      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 24, 0, SS_CALL_RTW_GENERATED_ENABLE);
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_0_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_82, 15U * sizeof(real_T));
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_1_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_83, 10U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_84[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_84[1];
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_29_3_0[0] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_85[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_29_3_0[1] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_85[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_29_4_0[0] = ((Parameters *)
      ssGetDefaultParam(S))->P_86[0] * ((BlockIO *) _ssGetBlockIO(S))->B_29_3_0
      [0];
    ((BlockIO *) _ssGetBlockIO(S))->B_29_4_0[1] = ((Parameters *)
      ssGetDefaultParam(S))->P_86[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_3_0
      [1];
    ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[0] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_29_4_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_87;
    ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_29_4_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_87;
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_7_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_88[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_7_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_88[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_9_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_89[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_9_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_89[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_11_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_90[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_11_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_90[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_13_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_91[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_13_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_91[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_15_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_92[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_15_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_92[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_17_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_93[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_17_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_93[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_19_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_94[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_19_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_94[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_21_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_95[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_21_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_95[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_23_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_96[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_23_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_96[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_25_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_97, 10U * sizeof(real_T));
    }

    tmp[0] = ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0
      [1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[1] = ((BlockIO *) _ssGetBlockIO(S))->B_29_7_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->B_29_7_0
      [1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[2] = ((BlockIO *) _ssGetBlockIO(S))->B_29_9_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->B_29_9_0
      [1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[3] = ((BlockIO *) _ssGetBlockIO(S))->B_29_11_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[4] = ((BlockIO *) _ssGetBlockIO(S))->B_29_13_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[5] = ((BlockIO *) _ssGetBlockIO(S))->B_29_15_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[6] = ((BlockIO *) _ssGetBlockIO(S))->B_29_17_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[7] = ((BlockIO *) _ssGetBlockIO(S))->B_29_19_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[8] = ((BlockIO *) _ssGetBlockIO(S))->B_29_21_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    tmp[9] = ((BlockIO *) _ssGetBlockIO(S))->B_29_23_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_29_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_29_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_5_0[1];
    for (i = 0; i < 10; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_26_0[i] = tmp[i] + ((BlockIO *)
        _ssGetBlockIO(S))->B_29_25_0[i];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_27_0[i] = ((Parameters *)
        ssGetDefaultParam(S))->P_98 * ((BlockIO *) _ssGetBlockIO(S))->
        B_29_26_0[i];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_29_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_99;
    }

    for (i = 0; i < 10; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_30_0[i] = muDoubleScalarExp(((BlockIO
        *) _ssGetBlockIO(S))->B_29_27_0[i]) + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_29_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_32_0[i] = 1.0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_29_30_0[i] * ((Parameters *) ssGetDefaultParam(S)
        )->P_100;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_33_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_101;
    }

    for (i = 0; i < 10; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_34_0[i] = ((BlockIO *) _ssGetBlockIO
        (S))->B_29_32_0[i] - ((BlockIO *) _ssGetBlockIO(S))->B_29_33_0;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_36_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_102, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_38_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_103, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_40_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_104, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_42_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_105, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_44_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_106, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_46_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_107, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_48_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_108, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_50_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_109, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_52_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_110, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_54_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_111, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_56_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_112, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_58_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_113, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_60_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_114, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_62_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_115, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_64_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_116, 15U * sizeof(real_T));
    }

    B_62_0_0 = 0.0;
    tmp_0 = 0.0;
    tmp_1 = 0.0;
    tmp_2 = 0.0;
    tmp_3 = 0.0;
    tmp_4 = 0.0;
    tmp_5 = 0.0;
    tmp_6 = 0.0;
    tmp_7 = 0.0;
    tmp_8 = 0.0;
    tmp_9 = 0.0;
    tmp_a = 0.0;
    tmp_b = 0.0;
    tmp_c = 0.0;
    tmp_d = 0.0;
    for (i = 0; i < 10; i++) {
      B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_1_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_36_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_29_38_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_29_40_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_29_42_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_29_44_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_29_46_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_29_48_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_29_50_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_29_52_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_29_54_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_29_56_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_29_58_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_29_60_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
      tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_29_62_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_34_0[i];
    }

    tmp_e[0] = B_62_0_0;
    tmp_e[1] = tmp_0;
    tmp_e[2] = tmp_1;
    tmp_e[3] = tmp_2;
    tmp_e[4] = tmp_3;
    tmp_e[5] = tmp_4;
    tmp_e[6] = tmp_5;
    tmp_e[7] = tmp_6;
    tmp_e[8] = tmp_7;
    tmp_e[9] = tmp_8;
    tmp_e[10] = tmp_9;
    tmp_e[11] = tmp_a;
    tmp_e[12] = tmp_b;
    tmp_e[13] = tmp_c;
    tmp_e[14] = tmp_d;
    for (i = 0; i < 15; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_65_0[i] = tmp_e[i] + ((BlockIO *)
        _ssGetBlockIO(S))->B_29_64_0[i];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_66_0[i] = ((Parameters *)
        ssGetDefaultParam(S))->P_117 * ((BlockIO *) _ssGetBlockIO(S))->
        B_29_65_0[i];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_68_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_118;
    }

    for (i = 0; i < 15; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_69_0[i] = muDoubleScalarExp(((BlockIO
        *) _ssGetBlockIO(S))->B_29_66_0[i]) + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_68_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_71_0[i] = 1.0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_29_69_0[i] * ((Parameters *) ssGetDefaultParam(S)
        )->P_119;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_72_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_120;
    }

    for (i = 0; i < 15; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_73_0[i] = ((BlockIO *) _ssGetBlockIO
        (S))->B_29_71_0[i] - ((BlockIO *) _ssGetBlockIO(S))->B_29_72_0;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_75_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_121;
    }

    B_62_0_0 = 0.0;
    for (i = 0; i < 15; i++) {
      B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_0_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_73_0[i];
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_29_76_0 = B_62_0_0 + ((BlockIO *)
      _ssGetBlockIO(S))->B_29_75_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_29_77_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_76_0 + ((Parameters *) ssGetDefaultParam(S))->P_122;
    ((BlockIO *) _ssGetBlockIO(S))->B_29_78_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_123 * ((BlockIO *) _ssGetBlockIO(S))->B_29_77_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_29_79_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_78_0 + ((Parameters *) ssGetDefaultParam(S))->P_124;
    ((BlockIO *) _ssGetBlockIO(S))->B_29_80_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_79_0 >= ((Parameters *) ssGetDefaultParam(S))->P_125 ? ((Parameters
      *) ssGetDefaultParam(S))->P_125 : ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_79_0 <= ((Parameters *) ssGetDefaultParam(S))->P_126 ? ((Parameters
      *) ssGetDefaultParam(S))->P_126 : ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_79_0;

    /* Clock: '<S142>/Clock' */
    ((BlockIO *) _ssGetBlockIO(S))->B_29_81_0 = ssGetT(S);
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_82_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_127, 24U * sizeof(real_T));
    }

    /* Level2 S-Function Block: '<S151>/B_18_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 21, 0, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_29_84_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_80_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_0_1;
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_85_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_128;
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_86_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_129, 24U * sizeof(real_T));
    }

    /* Level2 S-Function Block: '<S152>/B_19_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 22, 0, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_29_88_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_85_0 * ((BlockIO *) _ssGetBlockIO(S))->B_22_0_1;
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_89_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_130, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_91_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_132[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_91_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_132[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_92_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_133[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_92_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_133[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_93_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_134[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_93_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_134[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_94_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_135[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_94_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_135[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_95_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_136[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_95_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_136[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_96_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_137[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_96_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_137[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_97_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_138[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_97_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_138[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_98_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_139[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_98_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_139[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_99_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_140[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_99_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_140[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_100_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_141[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_100_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_141[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_101_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_142[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_101_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_142[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_102_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_143[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_102_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_143[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_103_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_144[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_103_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_144[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_104_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_145[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_104_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_145[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_105_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_146[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_105_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_146[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_106_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_147[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_106_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_147[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_107_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_148[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_107_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_148[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_108_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_149[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_108_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_149[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_109_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_150[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_109_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_150[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_110_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_151[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_110_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_151[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_111_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_152[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_111_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_152[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_112_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_153[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_112_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_153[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_113_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_154[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_113_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_154[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_114_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_155[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_114_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_155[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_115_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_156[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_115_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_156[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_116_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_157[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_116_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_157[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_117_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_158[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_117_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_158[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_118_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_159[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_118_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_159[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_119_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_160[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_119_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_160[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_120_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_161[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_120_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_161[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_122_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_163;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_123_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_164;
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_29_90_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_131[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_121_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_162[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_124_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_165[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_125_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_166[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_126_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_167[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_127_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_168[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_128_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_169[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_129_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_170[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_130_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_171[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_131_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_172[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_132_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_173[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_133_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_174[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_134_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_175[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_135_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_176[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_136_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_177[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_137_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_178[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_138_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_179[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_139_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_180[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_140_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_181[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_141_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_182[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_142_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_183[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_143_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_184[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_144_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_185[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_145_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_186[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_146_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_187[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_147_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_188[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_148_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_189[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_149_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_190[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_150_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_191[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_151_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_192[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_152_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_193[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_153_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_194[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_154_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_195[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_155_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_196[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_156_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_197[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_157_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_198[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_158_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_199[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_159_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_200[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_160_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_201[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_161_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_202[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_162_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_203[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_29_164_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_205;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_165_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_206;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_166_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_207;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_29_163_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_204[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_167_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_208[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_29_169_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_210[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_169_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_210[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_170_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_211[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_170_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_211[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_171_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_212[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_171_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_212[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_172_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_213[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_172_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_213[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_173_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_214[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_173_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_214[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_174_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_215[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_174_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_215[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_175_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_216[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_175_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_216[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_176_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_217[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_176_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_217[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_177_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_218[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_177_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_218[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_178_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_219[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_178_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_219[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_179_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_220[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_179_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_220[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_180_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_221[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_180_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_221[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_181_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_222[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_181_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_222[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_182_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_223[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_182_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_223[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_183_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_224[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_183_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_224[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_184_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_225[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_184_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_225[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_185_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_226[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_185_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_226[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_186_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_227[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_186_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_227[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_187_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_228[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_187_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_228[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_188_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_229[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_188_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_229[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_189_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_230[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_189_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_230[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_190_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_231[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_190_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_231[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_191_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_232[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_191_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_232[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_192_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_233[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_192_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_233[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_193_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_234[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_193_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_234[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_194_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_235[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_194_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_235[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_195_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_236[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_195_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_236[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_196_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_237[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_196_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_237[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_197_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_238[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_197_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_238[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_198_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_239[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_198_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_239[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_200_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_241;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_201_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_242;
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_29_168_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_209[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_199_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_240[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_202_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_243[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_203_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_244[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_204_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_245[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_205_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_246[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_206_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_247[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_207_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_248[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_208_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_249[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_209_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_250[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_210_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_251[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_211_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_252[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_212_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_253[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_213_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_254[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_214_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_255[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_215_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_256[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_216_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_257[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_217_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_258[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_218_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_259[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_219_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_260[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_220_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_261[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_221_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_262[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_222_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_263[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_223_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_264[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_224_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_265[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_225_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_266[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_226_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_267[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_227_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_268[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_228_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_269[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_229_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_270[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_230_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_271[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_231_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_272[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_232_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_273[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_233_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_274[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_234_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_275[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_235_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_276[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_236_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_277[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_237_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_278[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_238_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_279[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_239_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_280[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_240_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_281[i];
      }

      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_241_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_282, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_242_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_283;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_243_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_284;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_244_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_285;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_286) {
      ((BlockIO *) _ssGetBlockIO(S))->B_26_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_52[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_26_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_52[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_26_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_53[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_26_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_26_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_53[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_26_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_26_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_54;
      ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_26_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_54;
      tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_29_91_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_91_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_29_92_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_92_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_29_93_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_93_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_29_94_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_94_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_29_95_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_95_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_29_96_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_96_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_29_97_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_97_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_29_98_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_98_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_29_99_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_99_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_29_100_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_100_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_29_101_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_101_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_29_102_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_102_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_29_103_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_103_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_29_104_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_104_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_29_105_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_105_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_29_106_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_106_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_29_107_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_107_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_29_108_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_108_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_29_109_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_109_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_29_110_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_110_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_29_111_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_111_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_29_112_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_112_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_29_113_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_113_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_29_114_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_114_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_29_115_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_115_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_29_116_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_116_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_29_117_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_117_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_29_118_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_118_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_29_119_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_119_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_29_120_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_26_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_120_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_26_2_0[1];
      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      tmp_9 = 0.0;
      tmp_a = 0.0;
      tmp_b = 0.0;
      tmp_c = 0.0;
      tmp_d = 0.0;
      tmp_g = 0.0;
      tmp_h = 0.0;
      tmp_i = 0.0;
      tmp_j = 0.0;
      tmp_k = 0.0;
      tmp_l = 0.0;
      tmp_m = 0.0;
      tmp_n = 0.0;
      tmp_o = 0.0;
      tmp_p = 0.0;
      tmp_q = 0.0;
      tmp_r = 0.0;
      tmp_s = 0.0;
      tmp_t = 0.0;
      tmp_u = 0.0;
      tmp_v = 0.0;
      tmp_w = 0.0;
      tmp_x = 0.0;
      tmp_y = 0.0;
      tmp_z = 0.0;
      tmp_10 = 0.0;
      tmp_11 = 0.0;
      tmp_12 = 0.0;
      tmp_13 = 0.0;
      tmp_14 = 0.0;
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_26_33_0[i] = tmp_f[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_121_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_26_34_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_55 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_26_33_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_26_36_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_26_34_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_122_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_26_38_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_26_36_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_56;
        ((BlockIO *) _ssGetBlockIO(S))->B_26_39_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_26_38_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_123_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_90_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_124_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_29_125_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_29_126_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_29_127_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_29_128_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_29_129_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_29_130_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_29_131_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_29_132_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_29_133_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_29_134_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_29_135_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_29_136_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_29_137_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_29_138_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_29_139_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_29_140_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_29_141_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_29_142_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_29_143_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_29_144_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_29_145_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_29_146_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_29_147_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_29_148_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_29_149_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_29_150_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_29_151_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_29_152_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_29_153_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_29_154_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_29_155_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_29_156_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_29_157_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_29_158_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_29_159_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_29_160_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_29_161_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_29_162_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_39_0[i];
      }

      tmp_15[0] = B_62_0_0;
      tmp_15[1] = tmp_0;
      tmp_15[2] = tmp_1;
      tmp_15[3] = tmp_2;
      tmp_15[4] = tmp_3;
      tmp_15[5] = tmp_4;
      tmp_15[6] = tmp_5;
      tmp_15[7] = tmp_6;
      tmp_15[8] = tmp_7;
      tmp_15[9] = tmp_8;
      tmp_15[10] = tmp_9;
      tmp_15[11] = tmp_a;
      tmp_15[12] = tmp_b;
      tmp_15[13] = tmp_c;
      tmp_15[14] = tmp_d;
      tmp_15[15] = tmp_g;
      tmp_15[16] = tmp_h;
      tmp_15[17] = tmp_i;
      tmp_15[18] = tmp_j;
      tmp_15[19] = tmp_k;
      tmp_15[20] = tmp_l;
      tmp_15[21] = tmp_m;
      tmp_15[22] = tmp_n;
      tmp_15[23] = tmp_o;
      tmp_15[24] = tmp_p;
      tmp_15[25] = tmp_q;
      tmp_15[26] = tmp_r;
      tmp_15[27] = tmp_s;
      tmp_15[28] = tmp_t;
      tmp_15[29] = tmp_u;
      tmp_15[30] = tmp_v;
      tmp_15[31] = tmp_w;
      tmp_15[32] = tmp_x;
      tmp_15[33] = tmp_y;
      tmp_15[34] = tmp_z;
      tmp_15[35] = tmp_10;
      tmp_15[36] = tmp_11;
      tmp_15[37] = tmp_12;
      tmp_15[38] = tmp_13;
      tmp_15[39] = tmp_14;
      B_62_0_0 = 0.0;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_26_80_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_163_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_26_81_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_57 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_26_80_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_26_83_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_26_81_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_164_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_26_85_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_26_83_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_58;
        ((BlockIO *) _ssGetBlockIO(S))->B_26_86_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_26_85_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_165_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_89_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_26_86_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_26_88_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_29_166_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_26_89_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_26_88_0 + ((Parameters *) ssGetDefaultParam(S))->P_59;
      ((BlockIO *) _ssGetBlockIO(S))->B_26_90_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_60 * ((BlockIO *) _ssGetBlockIO(S))->B_26_89_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_26_91_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_26_90_0 + ((Parameters *) ssGetDefaultParam(S))->P_61;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_247_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_26_91_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_25_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_42[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_25_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_42[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_25_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_43[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_25_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_25_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_43[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_25_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_25_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_44;
      ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_25_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_44;
      tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_29_169_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_169_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_29_170_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_170_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_29_171_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_171_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_29_172_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_172_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_29_173_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_173_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_29_174_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_174_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_29_175_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_175_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_29_176_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_176_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_29_177_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_177_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_29_178_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_178_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_29_179_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_179_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_29_180_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_180_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_29_181_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_181_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_29_182_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_182_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_29_183_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_183_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_29_184_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_184_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_29_185_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_185_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_29_186_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_186_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_29_187_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_187_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_29_188_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_188_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_29_189_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_189_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_29_190_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_190_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_29_191_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_191_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_29_192_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_192_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_29_193_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_193_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_29_194_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_194_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_29_195_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_195_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_29_196_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_196_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_29_197_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_197_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_29_198_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_25_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_198_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_25_2_0[1];
      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      tmp_9 = 0.0;
      tmp_a = 0.0;
      tmp_b = 0.0;
      tmp_c = 0.0;
      tmp_d = 0.0;
      tmp_g = 0.0;
      tmp_h = 0.0;
      tmp_i = 0.0;
      tmp_j = 0.0;
      tmp_k = 0.0;
      tmp_l = 0.0;
      tmp_m = 0.0;
      tmp_n = 0.0;
      tmp_o = 0.0;
      tmp_p = 0.0;
      tmp_q = 0.0;
      tmp_r = 0.0;
      tmp_s = 0.0;
      tmp_t = 0.0;
      tmp_u = 0.0;
      tmp_v = 0.0;
      tmp_w = 0.0;
      tmp_x = 0.0;
      tmp_y = 0.0;
      tmp_z = 0.0;
      tmp_10 = 0.0;
      tmp_11 = 0.0;
      tmp_12 = 0.0;
      tmp_13 = 0.0;
      tmp_14 = 0.0;
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_25_33_0[i] = tmp_f[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_199_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_25_34_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_45 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_25_33_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_25_36_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_25_34_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_200_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_25_38_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_25_36_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_46;
        ((BlockIO *) _ssGetBlockIO(S))->B_25_39_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_25_38_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_201_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_168_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_202_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_29_203_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_29_204_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_29_205_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_29_206_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_29_207_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_29_208_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_29_209_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_29_210_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_29_211_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_29_212_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_29_213_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_29_214_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_29_215_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_29_216_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_29_217_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_29_218_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_29_219_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_29_220_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_29_221_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_29_222_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_29_223_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_29_224_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_29_225_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_29_226_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_29_227_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_29_228_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_29_229_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_29_230_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_29_231_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_29_232_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_29_233_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_29_234_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_29_235_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_29_236_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_29_237_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_29_238_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_29_239_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_29_240_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_39_0[i];
      }

      tmp_15[0] = B_62_0_0;
      tmp_15[1] = tmp_0;
      tmp_15[2] = tmp_1;
      tmp_15[3] = tmp_2;
      tmp_15[4] = tmp_3;
      tmp_15[5] = tmp_4;
      tmp_15[6] = tmp_5;
      tmp_15[7] = tmp_6;
      tmp_15[8] = tmp_7;
      tmp_15[9] = tmp_8;
      tmp_15[10] = tmp_9;
      tmp_15[11] = tmp_a;
      tmp_15[12] = tmp_b;
      tmp_15[13] = tmp_c;
      tmp_15[14] = tmp_d;
      tmp_15[15] = tmp_g;
      tmp_15[16] = tmp_h;
      tmp_15[17] = tmp_i;
      tmp_15[18] = tmp_j;
      tmp_15[19] = tmp_k;
      tmp_15[20] = tmp_l;
      tmp_15[21] = tmp_m;
      tmp_15[22] = tmp_n;
      tmp_15[23] = tmp_o;
      tmp_15[24] = tmp_p;
      tmp_15[25] = tmp_q;
      tmp_15[26] = tmp_r;
      tmp_15[27] = tmp_s;
      tmp_15[28] = tmp_t;
      tmp_15[29] = tmp_u;
      tmp_15[30] = tmp_v;
      tmp_15[31] = tmp_w;
      tmp_15[32] = tmp_x;
      tmp_15[33] = tmp_y;
      tmp_15[34] = tmp_z;
      tmp_15[35] = tmp_10;
      tmp_15[36] = tmp_11;
      tmp_15[37] = tmp_12;
      tmp_15[38] = tmp_13;
      tmp_15[39] = tmp_14;
      B_62_0_0 = 0.0;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_25_80_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_241_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_25_81_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_47 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_25_80_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_25_83_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_25_81_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_242_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_25_85_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_25_83_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_48;
        ((BlockIO *) _ssGetBlockIO(S))->B_25_86_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_25_85_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_243_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_167_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_25_86_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_25_88_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_29_244_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_25_89_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_25_88_0 + ((Parameters *) ssGetDefaultParam(S))->P_49;
      ((BlockIO *) _ssGetBlockIO(S))->B_25_90_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_50 * ((BlockIO *) _ssGetBlockIO(S))->B_25_89_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_25_91_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_25_90_0 + ((Parameters *) ssGetDefaultParam(S))->P_51;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_247_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_25_91_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_29_248_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_29_247_0 >= ((Parameters *) ssGetDefaultParam(S))->P_287 ?
      ((Parameters *) ssGetDefaultParam(S))->P_287 : ((BlockIO *) _ssGetBlockIO
      (S))->B_29_247_0 <= ((Parameters *) ssGetDefaultParam(S))->P_288 ?
      ((Parameters *) ssGetDefaultParam(S))->P_288 : ((BlockIO *) _ssGetBlockIO
      (S))->B_29_247_0;
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_249_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_289, 24U * sizeof(real_T));
    }

    /* Level2 S-Function Block: '<S153>/B_20_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 23, 0, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_29_251_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_29_248_0 * ((BlockIO *) _ssGetBlockIO(S))->B_23_0_1;
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_252_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_290, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_254_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_292[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_254_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_292[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_255_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_293[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_255_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_293[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_256_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_294[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_256_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_294[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_257_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_295[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_257_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_295[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_258_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_296[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_258_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_296[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_259_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_297[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_259_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_297[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_260_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_298[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_260_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_298[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_261_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_299[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_261_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_299[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_262_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_300[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_262_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_300[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_263_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_301[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_263_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_301[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_264_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_302[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_264_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_302[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_265_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_303[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_265_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_303[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_266_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_304[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_266_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_304[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_267_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_305[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_267_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_305[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_268_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_306[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_268_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_306[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_269_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_307[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_269_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_307[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_270_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_308[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_270_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_308[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_271_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_309[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_271_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_309[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_272_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_310[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_272_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_310[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_273_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_311[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_273_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_311[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_275_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_313;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_276_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_314;
      for (i = 0; i < 20; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_29_253_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_291[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_274_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_312[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_277_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_315[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_278_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_316[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_279_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_317[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_280_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_318[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_281_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_319[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_282_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_320[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_283_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_321[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_284_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_322[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_285_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_323[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_286_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_324[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_287_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_325[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_288_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_326[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_289_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_327[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_290_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_328[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_291_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_329[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_292_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_330[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_293_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_331[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_294_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_332[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_295_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_333[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_296_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_334[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_297_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_335[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_298_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_336[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_299_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_337[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_300_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_338[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_301_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_339[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_302_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_340[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_303_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_341[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_304_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_342[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_305_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_343[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_306_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_344[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_307_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_345[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_308_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_346[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_309_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_347[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_310_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_348[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_311_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_349[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_312_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_350[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_313_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_351[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_314_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_352[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_315_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_353[i];
      }

      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_316_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_354, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_317_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_355;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_318_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_356;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_319_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_357;
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_320_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_358, 10U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_322_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_360[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_322_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_360[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_323_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_361[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_323_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_361[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_324_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_362[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_324_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_362[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_325_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_363[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_325_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_363[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_326_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_364[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_326_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_364[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_328_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_366;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_329_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_367;
      for (i = 0; i < 5; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_29_321_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_359[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_327_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_365[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_330_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_368[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_331_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_369[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_332_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_370[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_333_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_371[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_334_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_372[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_335_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_373[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_336_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_374[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_337_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_375[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_338_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_376[i];
      }

      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_339_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_377, 10U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_29_340_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_378;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_341_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_379;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_342_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_380;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_381) {
      ((BlockIO *) _ssGetBlockIO(S))->B_28_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_72[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_72[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_73[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_73[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_74;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_74;
      tmp_17[0] = ((BlockIO *) _ssGetBlockIO(S))->B_29_254_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_254_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[1] = ((BlockIO *) _ssGetBlockIO(S))->B_29_255_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_255_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[2] = ((BlockIO *) _ssGetBlockIO(S))->B_29_256_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_256_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[3] = ((BlockIO *) _ssGetBlockIO(S))->B_29_257_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_257_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[4] = ((BlockIO *) _ssGetBlockIO(S))->B_29_258_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_258_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[5] = ((BlockIO *) _ssGetBlockIO(S))->B_29_259_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_259_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[6] = ((BlockIO *) _ssGetBlockIO(S))->B_29_260_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_260_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[7] = ((BlockIO *) _ssGetBlockIO(S))->B_29_261_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_261_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[8] = ((BlockIO *) _ssGetBlockIO(S))->B_29_262_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_262_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[9] = ((BlockIO *) _ssGetBlockIO(S))->B_29_263_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_263_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[10] = ((BlockIO *) _ssGetBlockIO(S))->B_29_264_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_264_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[11] = ((BlockIO *) _ssGetBlockIO(S))->B_29_265_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_265_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[12] = ((BlockIO *) _ssGetBlockIO(S))->B_29_266_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_266_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[13] = ((BlockIO *) _ssGetBlockIO(S))->B_29_267_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_267_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[14] = ((BlockIO *) _ssGetBlockIO(S))->B_29_268_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_268_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[15] = ((BlockIO *) _ssGetBlockIO(S))->B_29_269_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_269_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[16] = ((BlockIO *) _ssGetBlockIO(S))->B_29_270_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_270_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[17] = ((BlockIO *) _ssGetBlockIO(S))->B_29_271_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_271_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[18] = ((BlockIO *) _ssGetBlockIO(S))->B_29_272_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_272_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_17[19] = ((BlockIO *) _ssGetBlockIO(S))->B_29_273_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_273_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      tmp_9 = 0.0;
      tmp_a = 0.0;
      tmp_b = 0.0;
      tmp_c = 0.0;
      tmp_d = 0.0;
      tmp_g = 0.0;
      tmp_h = 0.0;
      tmp_i = 0.0;
      tmp_j = 0.0;
      tmp_k = 0.0;
      tmp_l = 0.0;
      tmp_m = 0.0;
      tmp_n = 0.0;
      tmp_o = 0.0;
      tmp_p = 0.0;
      tmp_q = 0.0;
      tmp_r = 0.0;
      tmp_s = 0.0;
      tmp_t = 0.0;
      tmp_u = 0.0;
      tmp_v = 0.0;
      tmp_w = 0.0;
      tmp_x = 0.0;
      tmp_y = 0.0;
      tmp_z = 0.0;
      tmp_10 = 0.0;
      tmp_11 = 0.0;
      tmp_12 = 0.0;
      tmp_13 = 0.0;
      tmp_14 = 0.0;
      for (i = 0; i < 20; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_28_23_0[i] = tmp_17[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_274_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_24_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_75 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_28_23_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_26_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_28_24_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_275_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_28_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_28_26_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_76;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_29_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_28_28_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_276_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_253_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_277_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_29_278_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_29_279_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_29_280_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_29_281_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_29_282_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_29_283_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_29_284_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_29_285_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_29_286_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_29_287_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_29_288_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_29_289_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_29_290_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_29_291_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_29_292_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_29_293_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_29_294_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_29_295_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_29_296_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_29_297_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_29_298_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_29_299_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_29_300_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_29_301_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_29_302_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_29_303_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_29_304_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_29_305_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_29_306_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_29_307_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_29_308_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_29_309_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_29_310_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_29_311_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_29_312_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_29_313_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_29_314_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_29_315_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_29_0[i];
      }

      tmp_15[0] = B_62_0_0;
      tmp_15[1] = tmp_0;
      tmp_15[2] = tmp_1;
      tmp_15[3] = tmp_2;
      tmp_15[4] = tmp_3;
      tmp_15[5] = tmp_4;
      tmp_15[6] = tmp_5;
      tmp_15[7] = tmp_6;
      tmp_15[8] = tmp_7;
      tmp_15[9] = tmp_8;
      tmp_15[10] = tmp_9;
      tmp_15[11] = tmp_a;
      tmp_15[12] = tmp_b;
      tmp_15[13] = tmp_c;
      tmp_15[14] = tmp_d;
      tmp_15[15] = tmp_g;
      tmp_15[16] = tmp_h;
      tmp_15[17] = tmp_i;
      tmp_15[18] = tmp_j;
      tmp_15[19] = tmp_k;
      tmp_15[20] = tmp_l;
      tmp_15[21] = tmp_m;
      tmp_15[22] = tmp_n;
      tmp_15[23] = tmp_o;
      tmp_15[24] = tmp_p;
      tmp_15[25] = tmp_q;
      tmp_15[26] = tmp_r;
      tmp_15[27] = tmp_s;
      tmp_15[28] = tmp_t;
      tmp_15[29] = tmp_u;
      tmp_15[30] = tmp_v;
      tmp_15[31] = tmp_w;
      tmp_15[32] = tmp_x;
      tmp_15[33] = tmp_y;
      tmp_15[34] = tmp_z;
      tmp_15[35] = tmp_10;
      tmp_15[36] = tmp_11;
      tmp_15[37] = tmp_12;
      tmp_15[38] = tmp_13;
      tmp_15[39] = tmp_14;
      B_62_0_0 = 0.0;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_28_70_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_316_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_71_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_77 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_28_70_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_73_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_28_71_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_317_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_75_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_28_73_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_78;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_76_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_28_75_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_318_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_252_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_76_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_28_78_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_29_319_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_79_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_28_78_0 + ((Parameters *) ssGetDefaultParam(S))->P_79;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_80_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_80 * ((BlockIO *) _ssGetBlockIO(S))->B_28_79_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_81_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_28_80_0 + ((Parameters *) ssGetDefaultParam(S))->P_81;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_345_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_81_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_27_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_62[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_62[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_63[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_63[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_64;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_64;
      tmp_16[0] = ((BlockIO *) _ssGetBlockIO(S))->B_29_322_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_322_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_16[1] = ((BlockIO *) _ssGetBlockIO(S))->B_29_323_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_323_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_16[2] = ((BlockIO *) _ssGetBlockIO(S))->B_29_324_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_324_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_16[3] = ((BlockIO *) _ssGetBlockIO(S))->B_29_325_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_325_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_16[4] = ((BlockIO *) _ssGetBlockIO(S))->B_29_326_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_326_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      for (i = 0; i < 5; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_27_8_0[i] = tmp_16[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_327_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_9_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_65 * ((BlockIO *) _ssGetBlockIO(S))->
          B_27_8_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_11_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_27_9_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_328_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_13_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_27_11_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_66;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_14_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_27_13_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_329_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_321_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_330_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_29_331_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_29_332_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_29_333_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_29_334_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_29_335_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_29_336_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_29_337_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_29_338_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_14_0[i];
      }

      tmp[0] = B_62_0_0;
      tmp[1] = tmp_0;
      tmp[2] = tmp_1;
      tmp[3] = tmp_2;
      tmp[4] = tmp_3;
      tmp[5] = tmp_4;
      tmp[6] = tmp_5;
      tmp[7] = tmp_6;
      tmp[8] = tmp_7;
      tmp[9] = tmp_8;
      B_62_0_0 = 0.0;
      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_27_25_0[i] = tmp[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_339_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_26_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_67 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_27_25_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_28_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_27_26_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_29_340_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_30_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_27_28_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_68;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_31_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_27_30_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_341_0;
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_29_320_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_31_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_27_33_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_29_342_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_34_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_27_33_0 + ((Parameters *) ssGetDefaultParam(S))->P_69;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_35_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_70 * ((BlockIO *) _ssGetBlockIO(S))->B_27_34_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_36_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_27_35_0 + ((Parameters *) ssGetDefaultParam(S))->P_71;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_345_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_36_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_29_346_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_29_345_0 >= ((Parameters *) ssGetDefaultParam(S))->P_382 ?
      ((Parameters *) ssGetDefaultParam(S))->P_382 : ((BlockIO *) _ssGetBlockIO
      (S))->B_29_345_0 <= ((Parameters *) ssGetDefaultParam(S))->P_383 ?
      ((Parameters *) ssGetDefaultParam(S))->P_383 : ((BlockIO *) _ssGetBlockIO
      (S))->B_29_345_0;
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_29_347_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_384, 24U * sizeof(real_T));
    }

    /* Level2 S-Function Block: '<S154>/B_21_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 24, 0, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_29_349_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_29_346_0 * ((BlockIO *) _ssGetBlockIO(S))->B_24_0_1;
    ((BlockIO *) _ssGetBlockIO(S))->B_29_350_0 = ((((BlockIO *) _ssGetBlockIO(S))
      ->B_29_84_0 + ((BlockIO *) _ssGetBlockIO(S))->B_29_88_0) + ((BlockIO *)
      _ssGetBlockIO(S))->B_29_251_0) + ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_349_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S142>/Scope' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 29, 351, SS_CALL_MDL_OUTPUTS);
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder05_SubsysRanBC);
    }
    break;

   case 1:
    rtPrevAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_i;
    if (ssIsMajorTimeStep(S)) {
      if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 <= 0.6) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_i = rtAction;
    } else {
      rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_i;
    }

    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Level2 S-Function Block: '<S512>/B_30_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 33, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S509>/B_27_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 30, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S510>/B_28_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 31, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S511>/B_29_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 32, 0, SS_CALL_RTW_GENERATED_DISABLE);
        break;

       case 1:
        ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h = -1;

        /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
        ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

        /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
        ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

        /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

        /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);
        break;
      }
    }

    switch (rtAction) {
     case 0:
      if (rtAction != rtPrevAction) {
        /* Level2 S-Function Block: '<S512>/B_30_0' (stateflow) */

        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 33, 0, SS_CALL_RTW_GENERATED_ENABLE);

        /* Level2 S-Function Block: '<S509>/B_27_0' (stateflow) */

        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 30, 0, SS_CALL_RTW_GENERATED_ENABLE);

        /* Level2 S-Function Block: '<S510>/B_28_0' (stateflow) */

        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 31, 0, SS_CALL_RTW_GENERATED_ENABLE);

        /* Level2 S-Function Block: '<S511>/B_29_0' (stateflow) */

        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 32, 0, SS_CALL_RTW_GENERATED_ENABLE);
      }

      /* Clock: '<S499>/Clock' */
      ((BlockIO *) _ssGetBlockIO(S))->B_34_0_0 = ssGetT(S);
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_1_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_385, 60U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_2_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_386, 40U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_34_3_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_387[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_3_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_387[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_4_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_388[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_4_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_388[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_389[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_4_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_389[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_4_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_5_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_390;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_5_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_390;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_8_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_391[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_8_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_391[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_10_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_392[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_10_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_392[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_12_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_393[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_12_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_393[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_14_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_394[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_14_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_394[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_16_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_395[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_16_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_395[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_18_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_396[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_18_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_396[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_20_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_397[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_20_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_397[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_22_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_398[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_22_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_398[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_24_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_399[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_24_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_399[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_26_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_400[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_26_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_400[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_28_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_401[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_28_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_401[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_30_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_402[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_30_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_402[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_32_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_403[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_32_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_403[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_34_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_404[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_34_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_404[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_36_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_405[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_36_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_405[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_38_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_406[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_38_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_406[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_40_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_407[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_40_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_407[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_42_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_408[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_42_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_408[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_44_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_409[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_44_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_409[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_46_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_410[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_46_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_410[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_48_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_411[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_48_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_411[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_50_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_412[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_50_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_412[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_52_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_413[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_52_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_413[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_54_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_414[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_54_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_414[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_56_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_415[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_56_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_415[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_58_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_416[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_58_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_416[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_60_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_417[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_60_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_417[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_62_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_418[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_62_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_418[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_64_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_419[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_64_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_419[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_66_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_420[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_66_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_420[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_68_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_421[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_68_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_421[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_70_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_422[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_70_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_422[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_72_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_423[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_72_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_423[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_74_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_424[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_74_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_424[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_76_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_425[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_76_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_425[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_78_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_426[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_78_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_426[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_80_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_427[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_80_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_427[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_82_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_428[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_82_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_428[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_84_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_429[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_84_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_429[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_86_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_430, 40U * sizeof(real_T));
      }

      tmp_15[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_3_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_3_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_8_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_8_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_10_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_10_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_12_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_12_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_14_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_14_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_16_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_16_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_18_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_18_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_20_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_20_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_22_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_22_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_24_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_24_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_26_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_26_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_28_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_28_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_30_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_30_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_32_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_32_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_34_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_34_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_36_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_36_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_38_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_38_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_40_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_40_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_42_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_42_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_44_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_44_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_46_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_46_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_48_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_48_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_50_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_50_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_52_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_52_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_54_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_54_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_56_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_56_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_58_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_58_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_60_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_60_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_62_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_62_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_64_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_64_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[30] = ((BlockIO *) _ssGetBlockIO(S))->B_34_66_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_66_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[31] = ((BlockIO *) _ssGetBlockIO(S))->B_34_68_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_68_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[32] = ((BlockIO *) _ssGetBlockIO(S))->B_34_70_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_70_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[33] = ((BlockIO *) _ssGetBlockIO(S))->B_34_72_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_72_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[34] = ((BlockIO *) _ssGetBlockIO(S))->B_34_74_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_74_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[35] = ((BlockIO *) _ssGetBlockIO(S))->B_34_76_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_76_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[36] = ((BlockIO *) _ssGetBlockIO(S))->B_34_78_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_78_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[37] = ((BlockIO *) _ssGetBlockIO(S))->B_34_80_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_80_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[38] = ((BlockIO *) _ssGetBlockIO(S))->B_34_82_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_82_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      tmp_15[39] = ((BlockIO *) _ssGetBlockIO(S))->B_34_84_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_6_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_84_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_6_0[1];
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_87_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_86_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_88_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_431 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_87_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_90_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_432;
      }

      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_91_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_88_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_90_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_93_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_91_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_433;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_94_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_434;
      }

      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_95_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_93_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_94_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_97_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_435, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_99_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_436, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_101_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_437, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_103_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_438, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_105_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_439, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_107_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_440, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_109_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_441, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_111_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_442, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_113_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_443, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_115_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_444, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_117_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_445, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_119_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_446, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_121_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_447, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_123_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_448, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_125_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_449, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_127_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_450, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_129_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_451, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_131_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_452, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_133_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_453, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_135_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_454, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_137_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_455, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_139_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_456, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_141_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_457, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_143_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_458, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_145_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_459, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_147_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_460, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_149_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_461, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_151_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_462, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_153_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_463, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_155_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_464, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_157_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_465, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_159_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_466, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_161_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_467, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_163_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_468, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_165_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_469, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_167_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_470, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_169_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_471, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_171_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_472, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_173_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_473, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_175_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_474, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_177_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_475, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_179_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_476, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_181_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_477, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_183_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_478, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_185_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_479, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_187_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_480, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_189_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_481, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_191_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_482, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_193_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_483, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_195_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_484, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_197_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_485, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_199_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_486, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_201_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_487, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_203_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_488, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_205_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_489, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_207_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_490, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_209_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_491, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_211_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_492, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_213_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_493, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_215_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_494, 60U * sizeof(real_T));
      }

      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      tmp_9 = 0.0;
      tmp_a = 0.0;
      tmp_b = 0.0;
      tmp_c = 0.0;
      tmp_d = 0.0;
      tmp_g = 0.0;
      tmp_h = 0.0;
      tmp_i = 0.0;
      tmp_j = 0.0;
      tmp_k = 0.0;
      tmp_l = 0.0;
      tmp_m = 0.0;
      tmp_n = 0.0;
      tmp_o = 0.0;
      tmp_p = 0.0;
      tmp_q = 0.0;
      tmp_r = 0.0;
      tmp_s = 0.0;
      tmp_t = 0.0;
      tmp_u = 0.0;
      tmp_v = 0.0;
      tmp_w = 0.0;
      tmp_x = 0.0;
      tmp_y = 0.0;
      tmp_z = 0.0;
      tmp_10 = 0.0;
      tmp_11 = 0.0;
      tmp_12 = 0.0;
      tmp_13 = 0.0;
      tmp_14 = 0.0;
      tmp_18 = 0.0;
      tmp_19 = 0.0;
      tmp_1a = 0.0;
      tmp_1b = 0.0;
      tmp_1c = 0.0;
      tmp_1d = 0.0;
      tmp_1e = 0.0;
      tmp_1f = 0.0;
      tmp_1g = 0.0;
      tmp_1h = 0.0;
      tmp_1i = 0.0;
      tmp_1j = 0.0;
      tmp_1k = 0.0;
      tmp_1l = 0.0;
      tmp_1m = 0.0;
      tmp_1n = 0.0;
      tmp_1o = 0.0;
      tmp_1p = 0.0;
      tmp_1q = 0.0;
      tmp_1r = 0.0;
      for (i = 0; i < 40; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_2_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_97_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_99_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_101_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_103_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_105_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_107_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_109_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_111_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_113_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_34_115_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_34_117_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_34_119_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_34_121_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_34_123_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_34_125_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_34_127_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_34_129_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_34_131_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_34_133_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_34_135_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_34_137_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_34_139_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_34_141_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_34_143_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_34_145_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_34_147_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_34_149_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_34_151_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_34_153_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_34_155_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_34_157_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_34_159_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_34_161_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_34_163_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_34_165_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_34_167_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_34_169_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_34_171_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_34_173_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_34_175_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_34_177_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_34_179_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_34_181_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_34_183_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_34_185_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_34_187_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_34_189_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_34_191_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_34_193_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1i += ((BlockIO *) _ssGetBlockIO(S))->B_34_195_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1j += ((BlockIO *) _ssGetBlockIO(S))->B_34_197_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1k += ((BlockIO *) _ssGetBlockIO(S))->B_34_199_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1l += ((BlockIO *) _ssGetBlockIO(S))->B_34_201_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1m += ((BlockIO *) _ssGetBlockIO(S))->B_34_203_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1n += ((BlockIO *) _ssGetBlockIO(S))->B_34_205_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1o += ((BlockIO *) _ssGetBlockIO(S))->B_34_207_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1p += ((BlockIO *) _ssGetBlockIO(S))->B_34_209_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1q += ((BlockIO *) _ssGetBlockIO(S))->B_34_211_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
        tmp_1r += ((BlockIO *) _ssGetBlockIO(S))->B_34_213_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_95_0[i];
      }

      tmp_1s[0] = B_62_0_0;
      tmp_1s[1] = tmp_0;
      tmp_1s[2] = tmp_1;
      tmp_1s[3] = tmp_2;
      tmp_1s[4] = tmp_3;
      tmp_1s[5] = tmp_4;
      tmp_1s[6] = tmp_5;
      tmp_1s[7] = tmp_6;
      tmp_1s[8] = tmp_7;
      tmp_1s[9] = tmp_8;
      tmp_1s[10] = tmp_9;
      tmp_1s[11] = tmp_a;
      tmp_1s[12] = tmp_b;
      tmp_1s[13] = tmp_c;
      tmp_1s[14] = tmp_d;
      tmp_1s[15] = tmp_g;
      tmp_1s[16] = tmp_h;
      tmp_1s[17] = tmp_i;
      tmp_1s[18] = tmp_j;
      tmp_1s[19] = tmp_k;
      tmp_1s[20] = tmp_l;
      tmp_1s[21] = tmp_m;
      tmp_1s[22] = tmp_n;
      tmp_1s[23] = tmp_o;
      tmp_1s[24] = tmp_p;
      tmp_1s[25] = tmp_q;
      tmp_1s[26] = tmp_r;
      tmp_1s[27] = tmp_s;
      tmp_1s[28] = tmp_t;
      tmp_1s[29] = tmp_u;
      tmp_1s[30] = tmp_v;
      tmp_1s[31] = tmp_w;
      tmp_1s[32] = tmp_x;
      tmp_1s[33] = tmp_y;
      tmp_1s[34] = tmp_z;
      tmp_1s[35] = tmp_10;
      tmp_1s[36] = tmp_11;
      tmp_1s[37] = tmp_12;
      tmp_1s[38] = tmp_13;
      tmp_1s[39] = tmp_14;
      tmp_1s[40] = tmp_18;
      tmp_1s[41] = tmp_19;
      tmp_1s[42] = tmp_1a;
      tmp_1s[43] = tmp_1b;
      tmp_1s[44] = tmp_1c;
      tmp_1s[45] = tmp_1d;
      tmp_1s[46] = tmp_1e;
      tmp_1s[47] = tmp_1f;
      tmp_1s[48] = tmp_1g;
      tmp_1s[49] = tmp_1h;
      tmp_1s[50] = tmp_1i;
      tmp_1s[51] = tmp_1j;
      tmp_1s[52] = tmp_1k;
      tmp_1s[53] = tmp_1l;
      tmp_1s[54] = tmp_1m;
      tmp_1s[55] = tmp_1n;
      tmp_1s[56] = tmp_1o;
      tmp_1s[57] = tmp_1p;
      tmp_1s[58] = tmp_1q;
      tmp_1s[59] = tmp_1r;
      for (i = 0; i < 60; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_216_0[i] = tmp_1s[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_215_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_495 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_216_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_219_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_496;
      }

      for (i = 0; i < 60; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_220_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_219_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_222_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_220_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_497;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_223_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_498;
      }

      for (i = 0; i < 60; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_224_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_222_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_223_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_226_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_499;
      }

      B_62_0_0 = 0.0;
      for (i = 0; i < 60; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_1_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_224_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_227_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_34_226_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_228_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_227_0 + ((Parameters *) ssGetDefaultParam(S))->P_500;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_229_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_501 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_228_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_230_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_229_0 + ((Parameters *) ssGetDefaultParam(S))->P_502;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_231_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_230_0 >= ((Parameters *) ssGetDefaultParam(S))->P_503 ?
        ((Parameters *) ssGetDefaultParam(S))->P_503 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_230_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_504 ? ((Parameters *) ssGetDefaultParam(S))->P_504 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_230_0;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_232_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_505, 24U * sizeof(real_T));
      }

      /* Level2 S-Function Block: '<S512>/B_30_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 33, 0, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_34_234_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_231_0 * ((BlockIO *) _ssGetBlockIO(S))->B_33_0_1;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_235_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_506, 10U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_236_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_507, 15U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_34_237_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_508[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_237_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_508[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_238_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_509[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_238_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_509[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_239_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_510[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_238_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_239_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_510[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_238_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_34_239_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_511;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_34_239_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_511;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_242_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_512[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_242_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_512[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_244_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_513[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_244_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_513[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_246_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_514[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_246_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_514[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_248_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_515[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_248_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_515[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_250_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_516[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_250_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_516[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_252_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_517[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_252_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_517[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_254_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_518[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_254_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_518[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_256_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_519[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_256_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_519[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_258_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_520[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_258_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_520[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_260_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_521[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_260_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_521[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_262_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_522[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_262_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_522[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_264_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_523[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_264_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_523[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_266_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_524[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_266_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_524[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_268_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_525[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_268_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_525[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_270_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_526, 15U * sizeof(real_T));
      }

      tmp_e[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_237_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_237_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_242_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_242_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_244_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_244_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_246_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_246_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_248_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_248_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_250_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_250_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_252_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_252_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_254_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_254_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_256_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_256_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_258_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_258_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_260_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_260_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_262_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_262_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_264_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_264_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_266_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_266_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      tmp_e[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_268_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_240_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_268_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_240_0[1];
      for (i = 0; i < 15; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_271_0[i] = tmp_e[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_270_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_272_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_527 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_271_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_274_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_528;
      }

      for (i = 0; i < 15; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_275_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_272_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_274_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_277_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_275_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_529;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_278_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_530;
      }

      for (i = 0; i < 15; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_279_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_277_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_278_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_281_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_531, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_283_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_532, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_285_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_533, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_287_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_534, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_289_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_535, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_291_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_536, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_293_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_537, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_295_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_538, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_297_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_539, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_299_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_540, 10U * sizeof(real_T));
      }

      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      for (i = 0; i < 15; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_236_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_281_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_283_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_285_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_287_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_289_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_291_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_293_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_295_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_297_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_279_0[i];
      }

      tmp[0] = B_62_0_0;
      tmp[1] = tmp_0;
      tmp[2] = tmp_1;
      tmp[3] = tmp_2;
      tmp[4] = tmp_3;
      tmp[5] = tmp_4;
      tmp[6] = tmp_5;
      tmp[7] = tmp_6;
      tmp[8] = tmp_7;
      tmp[9] = tmp_8;
      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_300_0[i] = tmp[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_299_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_301_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_541 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_300_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_303_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_542;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_304_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_301_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_303_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_306_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_304_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_543;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_307_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_544;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_308_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_306_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_307_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_310_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_545;
      }

      B_62_0_0 = 0.0;
      for (i = 0; i < 10; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_235_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_308_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_311_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_34_310_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_312_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_311_0 + ((Parameters *) ssGetDefaultParam(S))->P_546;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_313_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_547 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_312_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_314_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_313_0 + ((Parameters *) ssGetDefaultParam(S))->P_548;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_315_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_314_0 >= ((Parameters *) ssGetDefaultParam(S))->P_549 ?
        ((Parameters *) ssGetDefaultParam(S))->P_549 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_314_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_550 ? ((Parameters *) ssGetDefaultParam(S))->P_550 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_314_0;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_316_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_551, 24U * sizeof(real_T));
      }

      /* Level2 S-Function Block: '<S509>/B_27_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 30, 0, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_34_318_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_315_0 * ((BlockIO *) _ssGetBlockIO(S))->B_30_0_1;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_319_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_552, 45U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_320_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_553, 35U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_34_321_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_554[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_321_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_554[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_322_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_555[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_322_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_555[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_323_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_556[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_322_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_323_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_556[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_322_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_34_323_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_557;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_34_323_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_557;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_326_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_558[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_326_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_558[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_328_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_559[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_328_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_559[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_330_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_560[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_330_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_560[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_332_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_561[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_332_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_561[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_334_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_562[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_334_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_562[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_336_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_563[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_336_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_563[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_338_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_564[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_338_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_564[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_340_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_565[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_340_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_565[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_342_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_566[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_342_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_566[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_344_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_567[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_344_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_567[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_346_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_568[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_346_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_568[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_348_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_569[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_348_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_569[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_350_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_570[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_350_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_570[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_352_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_571[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_352_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_571[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_354_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_572[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_354_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_572[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_356_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_573[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_356_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_573[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_358_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_574[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_358_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_574[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_360_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_575[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_360_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_575[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_362_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_576[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_362_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_576[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_364_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_577[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_364_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_577[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_366_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_578[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_366_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_578[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_368_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_579[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_368_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_579[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_370_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_580[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_370_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_580[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_372_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_581[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_372_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_581[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_374_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_582[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_374_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_582[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_376_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_583[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_376_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_583[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_378_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_584[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_378_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_584[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_380_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_585[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_380_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_585[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_382_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_586[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_382_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_586[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_384_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_587[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_384_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_587[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_386_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_588[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_386_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_588[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_388_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_589[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_388_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_589[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_390_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_590[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_390_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_590[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_392_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_591[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_392_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_591[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_394_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_592, 35U * sizeof(real_T));
      }

      tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_321_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_321_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_326_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_326_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_328_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_328_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_330_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_330_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_332_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_332_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_334_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_334_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_336_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_336_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_338_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_338_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_340_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_340_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_342_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_342_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_344_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_344_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_346_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_346_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_348_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_348_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_350_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_350_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_352_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_352_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_354_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_354_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_356_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_356_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_358_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_358_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_360_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_360_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_362_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_362_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_364_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_364_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_366_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_366_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_368_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_368_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_370_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_370_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_372_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_372_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_374_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_374_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_376_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_376_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_378_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_378_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_380_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_380_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_382_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_382_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_34_384_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_384_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_34_386_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_386_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_34_388_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_388_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_34_390_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_390_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_34_392_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_324_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_392_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[1];
      for (i = 0; i < 35; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_395_0[i] = tmp_1t[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_394_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_396_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_593 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_395_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_398_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_594;
      }

      for (i = 0; i < 35; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_399_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_396_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_398_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_401_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_399_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_595;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_402_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_596;
      }

      for (i = 0; i < 35; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_403_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_401_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_402_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_405_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_597, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_407_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_598, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_599, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_411_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_600, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_413_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_601, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_415_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_602, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_417_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_603, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_419_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_604, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_421_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_605, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_423_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_606, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_425_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_607, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_427_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_608, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_429_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_609, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_431_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_610, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_433_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_611, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_435_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_612, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_437_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_613, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_439_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_614, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_441_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_615, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_443_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_616, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_445_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_617, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_447_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_618, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_449_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_619, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_451_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_620, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_453_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_621, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_455_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_622, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_457_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_623, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_459_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_624, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_461_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_625, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_463_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_626, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_465_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_627, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_467_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_628, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_469_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_629, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_471_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_630, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_473_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_631, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_475_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_632, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_477_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_633, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_479_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_634, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_481_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_635, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_483_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_636, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_485_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_637, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_487_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_638, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_489_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_639, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_491_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_640, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_493_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_641, 45U * sizeof(real_T));
      }

      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      tmp_9 = 0.0;
      tmp_a = 0.0;
      tmp_b = 0.0;
      tmp_c = 0.0;
      tmp_d = 0.0;
      tmp_g = 0.0;
      tmp_h = 0.0;
      tmp_i = 0.0;
      tmp_j = 0.0;
      tmp_k = 0.0;
      tmp_l = 0.0;
      tmp_m = 0.0;
      tmp_n = 0.0;
      tmp_o = 0.0;
      tmp_p = 0.0;
      tmp_q = 0.0;
      tmp_r = 0.0;
      tmp_s = 0.0;
      tmp_t = 0.0;
      tmp_u = 0.0;
      tmp_v = 0.0;
      tmp_w = 0.0;
      tmp_x = 0.0;
      tmp_y = 0.0;
      tmp_z = 0.0;
      tmp_10 = 0.0;
      tmp_11 = 0.0;
      tmp_12 = 0.0;
      tmp_13 = 0.0;
      tmp_14 = 0.0;
      tmp_18 = 0.0;
      tmp_19 = 0.0;
      tmp_1a = 0.0;
      tmp_1b = 0.0;
      tmp_1c = 0.0;
      for (i = 0; i < 35; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_320_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_405_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_407_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_411_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_413_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_415_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_417_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_419_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_421_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_34_423_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_34_425_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_34_427_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_34_429_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_34_431_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_34_433_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_34_435_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_34_437_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_34_439_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_34_441_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_34_443_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_34_445_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_34_447_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_34_449_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_34_451_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_34_453_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_34_455_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_34_457_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_34_459_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_34_461_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_34_463_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_34_465_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_34_467_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_34_469_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_34_471_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_34_473_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_34_475_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_34_477_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_34_479_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_34_481_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_34_483_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_34_485_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_34_487_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_34_489_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
        tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_34_491_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_403_0[i];
      }

      tmp_1u[0] = B_62_0_0;
      tmp_1u[1] = tmp_0;
      tmp_1u[2] = tmp_1;
      tmp_1u[3] = tmp_2;
      tmp_1u[4] = tmp_3;
      tmp_1u[5] = tmp_4;
      tmp_1u[6] = tmp_5;
      tmp_1u[7] = tmp_6;
      tmp_1u[8] = tmp_7;
      tmp_1u[9] = tmp_8;
      tmp_1u[10] = tmp_9;
      tmp_1u[11] = tmp_a;
      tmp_1u[12] = tmp_b;
      tmp_1u[13] = tmp_c;
      tmp_1u[14] = tmp_d;
      tmp_1u[15] = tmp_g;
      tmp_1u[16] = tmp_h;
      tmp_1u[17] = tmp_i;
      tmp_1u[18] = tmp_j;
      tmp_1u[19] = tmp_k;
      tmp_1u[20] = tmp_l;
      tmp_1u[21] = tmp_m;
      tmp_1u[22] = tmp_n;
      tmp_1u[23] = tmp_o;
      tmp_1u[24] = tmp_p;
      tmp_1u[25] = tmp_q;
      tmp_1u[26] = tmp_r;
      tmp_1u[27] = tmp_s;
      tmp_1u[28] = tmp_t;
      tmp_1u[29] = tmp_u;
      tmp_1u[30] = tmp_v;
      tmp_1u[31] = tmp_w;
      tmp_1u[32] = tmp_x;
      tmp_1u[33] = tmp_y;
      tmp_1u[34] = tmp_z;
      tmp_1u[35] = tmp_10;
      tmp_1u[36] = tmp_11;
      tmp_1u[37] = tmp_12;
      tmp_1u[38] = tmp_13;
      tmp_1u[39] = tmp_14;
      tmp_1u[40] = tmp_18;
      tmp_1u[41] = tmp_19;
      tmp_1u[42] = tmp_1a;
      tmp_1u[43] = tmp_1b;
      tmp_1u[44] = tmp_1c;
      for (i = 0; i < 45; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_494_0[i] = tmp_1u[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_493_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_495_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_642 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_494_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_497_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_643;
      }

      for (i = 0; i < 45; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_498_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_495_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_497_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_500_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_498_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_644;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_501_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_645;
      }

      for (i = 0; i < 45; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_502_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_500_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_501_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_504_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_646;
      }

      B_62_0_0 = 0.0;
      for (i = 0; i < 45; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_319_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_502_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_505_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_34_504_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_506_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_505_0 + ((Parameters *) ssGetDefaultParam(S))->P_647;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_507_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_648 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_506_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_508_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_507_0 + ((Parameters *) ssGetDefaultParam(S))->P_649;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_509_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_508_0 >= ((Parameters *) ssGetDefaultParam(S))->P_650 ?
        ((Parameters *) ssGetDefaultParam(S))->P_650 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_508_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_651 ? ((Parameters *) ssGetDefaultParam(S))->P_651 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_508_0;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_510_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_652, 24U * sizeof(real_T));
      }

      /* Level2 S-Function Block: '<S510>/B_28_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 31, 0, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_34_512_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_509_0 * ((BlockIO *) _ssGetBlockIO(S))->B_31_0_1;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_513_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_653, 10U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_514_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_654, 30U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_34_515_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_655[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_515_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_655[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_516_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_656[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_516_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_656[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_517_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_657[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_516_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_517_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_657[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_516_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_34_517_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_658;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_34_517_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_658;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_520_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_659[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_520_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_659[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_522_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_660[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_522_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_660[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_524_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_661[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_524_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_661[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_526_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_662[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_526_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_662[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_528_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_663[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_528_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_663[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_530_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_664[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_530_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_664[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_532_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_665[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_532_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_665[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_534_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_666[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_534_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_666[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_536_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_667[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_536_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_667[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_538_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_668[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_538_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_668[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_540_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_669[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_540_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_669[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_542_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_670[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_542_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_670[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_544_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_671[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_544_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_671[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_546_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_672[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_546_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_672[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_548_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_673[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_548_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_673[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_550_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_674[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_550_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_674[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_552_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_675[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_552_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_675[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_554_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_676[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_554_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_676[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_556_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_677[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_556_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_677[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_558_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_678[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_558_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_678[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_560_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_679[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_560_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_679[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_562_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_680[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_562_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_680[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_564_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_681[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_564_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_681[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_566_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_682[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_566_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_682[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_568_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_683[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_568_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_683[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_570_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_684[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_570_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_684[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_572_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_685[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_572_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_685[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_574_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_686[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_574_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_686[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_576_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_687[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_576_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_687[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_578_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_688, 30U * sizeof(real_T));
      }

      tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_515_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_515_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_520_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_520_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_522_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_522_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_524_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_524_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_526_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_526_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_528_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_528_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_530_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_530_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_532_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_532_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_534_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_534_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_536_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_536_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_538_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_538_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_540_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_540_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_542_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_542_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_544_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_544_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_546_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_546_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_548_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_548_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_550_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_550_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_552_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_552_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_554_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_554_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_556_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_556_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_558_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_558_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_560_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_560_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_562_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_562_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_564_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_564_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_566_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_566_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_568_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_568_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_570_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_570_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_572_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_572_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_574_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_574_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_576_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_34_518_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_576_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[1];
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_579_0[i] = tmp_f[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_578_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_580_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_689 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_579_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_582_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_690;
      }

      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_583_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_580_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_582_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_585_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_583_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_691;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_586_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_692;
      }

      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_587_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_585_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_586_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_589_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_693, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_591_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_694, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_593_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_695, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_595_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_696, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_597_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_697, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_599_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_698, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_601_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_699, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_603_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_700, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_605_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_701, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_607_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_702, 10U * sizeof(real_T));
      }

      B_62_0_0 = 0.0;
      tmp_0 = 0.0;
      tmp_1 = 0.0;
      tmp_2 = 0.0;
      tmp_3 = 0.0;
      tmp_4 = 0.0;
      tmp_5 = 0.0;
      tmp_6 = 0.0;
      tmp_7 = 0.0;
      tmp_8 = 0.0;
      for (i = 0; i < 30; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_514_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_589_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_591_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_593_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_595_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_597_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_599_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_601_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_603_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_605_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_587_0[i];
      }

      tmp[0] = B_62_0_0;
      tmp[1] = tmp_0;
      tmp[2] = tmp_1;
      tmp[3] = tmp_2;
      tmp[4] = tmp_3;
      tmp[5] = tmp_4;
      tmp[6] = tmp_5;
      tmp[7] = tmp_6;
      tmp[8] = tmp_7;
      tmp[9] = tmp_8;
      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_608_0[i] = tmp[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_607_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_34_609_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_703 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_608_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_704;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_612_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_34_609_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_34_611_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_34_614_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_34_612_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_705;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_615_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_706;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_616_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_34_614_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_34_615_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_34_618_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_707;
      }

      B_62_0_0 = 0.0;
      for (i = 0; i < 10; i++) {
        B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_513_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_34_616_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_34_619_0 = B_62_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_34_618_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_620_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_619_0 + ((Parameters *) ssGetDefaultParam(S))->P_708;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_621_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_709 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_620_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_622_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_621_0 + ((Parameters *) ssGetDefaultParam(S))->P_710;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_623_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_622_0 >= ((Parameters *) ssGetDefaultParam(S))->P_711 ?
        ((Parameters *) ssGetDefaultParam(S))->P_711 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_622_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_712 ? ((Parameters *) ssGetDefaultParam(S))->P_712 : ((BlockIO *)
        _ssGetBlockIO(S))->B_34_622_0;
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_624_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_713, 24U * sizeof(real_T));
      }

      /* Level2 S-Function Block: '<S511>/B_29_0' (stateflow) */
      /* Call into Simulink for MEX-version of S-function */
      ssCallAccelRunBlock(S, 32, 0, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_34_626_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_34_623_0 * ((BlockIO *) _ssGetBlockIO(S))->B_32_0_1;
      ((BlockIO *) _ssGetBlockIO(S))->B_34_627_0 = ((((BlockIO *) _ssGetBlockIO
        (S))->B_34_234_0 + ((BlockIO *) _ssGetBlockIO(S))->B_34_318_0) +
        ((BlockIO *) _ssGetBlockIO(S))->B_34_512_0) + ((BlockIO *) _ssGetBlockIO
        (S))->B_34_626_0;
      if (ssIsMajorTimeStep(S)) {
        srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder06_SubsysRanBC);
      }
      break;

     case 1:
      rtPrevAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h;
      if (ssIsMajorTimeStep(S)) {
        if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 <= 0.7) {
          rtAction = 0;
        } else {
          rtAction = 1;
        }

        ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h = rtAction;
      } else {
        rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h;
      }

      if (rtPrevAction != rtAction) {
        switch (rtPrevAction) {
         case 0:
          /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_DISABLE);
          break;

         case 1:
          ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = -1;

          /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

          /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);
          break;
        }
      }

      switch (rtAction) {
       case 0:
        if (rtAction != rtPrevAction) {
          /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */

          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 35, 0, SS_CALL_RTW_GENERATED_ENABLE);

          /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */

          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 36, 0, SS_CALL_RTW_GENERATED_ENABLE);

          /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */

          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 37, 0, SS_CALL_RTW_GENERATED_ENABLE);

          /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */

          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 38, 0, SS_CALL_RTW_GENERATED_ENABLE);
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_0_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_714, 65U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_1_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_715, 40U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_39_2_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_716[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_2_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_716[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_3_0[0] = ((BlockIO *) _ssGetBlockIO
          (S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_717[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_3_0[1] = ((BlockIO *) _ssGetBlockIO
          (S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_717[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_4_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_718[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_3_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_4_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_718[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_3_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[0] = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_4_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_719;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1] = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_4_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_719;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_7_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_720[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_7_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_720[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_9_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_721[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_9_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_721[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_11_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_722[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_11_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_722[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_13_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_723[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_13_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_723[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_15_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_724[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_15_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_724[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_17_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_725[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_17_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_725[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_19_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_726[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_19_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_726[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_21_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_727[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_21_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_727[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_23_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_728[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_23_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_728[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_25_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_729[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_25_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_729[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_27_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_730[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_27_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_730[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_29_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_731[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_29_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_731[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_31_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_732[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_31_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_732[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_33_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_733[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_33_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_733[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_35_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_734[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_35_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_734[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_37_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_735[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_37_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_735[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_39_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_736[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_39_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_736[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_41_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_737[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_41_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_737[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_43_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_738[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_43_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_738[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_45_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_739[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_45_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_739[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_47_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_740[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_47_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_740[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_49_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_741[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_49_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_741[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_51_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_742[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_51_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_742[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_53_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_743[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_53_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_743[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_55_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_744[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_55_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_744[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_57_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_745[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_57_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_745[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_59_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_746[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_59_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_746[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_61_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_747[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_61_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_747[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_63_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_748[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_63_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_748[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_65_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_749[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_65_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_749[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_67_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_750[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_67_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_750[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_69_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_751[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_69_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_751[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_71_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_752[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_71_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_752[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_73_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_753[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_73_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_753[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_75_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_754[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_75_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_754[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_77_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_755[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_77_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_755[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_79_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_756[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_79_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_756[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_81_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_757[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_81_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_757[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_83_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_758[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_83_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_758[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_85_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_759, 40U * sizeof
                 (real_T));
        }

        tmp_15[0] = ((BlockIO *) _ssGetBlockIO(S))->B_39_2_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[1] = ((BlockIO *) _ssGetBlockIO(S))->B_39_7_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[2] = ((BlockIO *) _ssGetBlockIO(S))->B_39_9_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[3] = ((BlockIO *) _ssGetBlockIO(S))->B_39_11_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[4] = ((BlockIO *) _ssGetBlockIO(S))->B_39_13_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[5] = ((BlockIO *) _ssGetBlockIO(S))->B_39_15_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[6] = ((BlockIO *) _ssGetBlockIO(S))->B_39_17_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[7] = ((BlockIO *) _ssGetBlockIO(S))->B_39_19_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[8] = ((BlockIO *) _ssGetBlockIO(S))->B_39_21_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[9] = ((BlockIO *) _ssGetBlockIO(S))->B_39_23_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[10] = ((BlockIO *) _ssGetBlockIO(S))->B_39_25_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[11] = ((BlockIO *) _ssGetBlockIO(S))->B_39_27_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[12] = ((BlockIO *) _ssGetBlockIO(S))->B_39_29_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[13] = ((BlockIO *) _ssGetBlockIO(S))->B_39_31_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[14] = ((BlockIO *) _ssGetBlockIO(S))->B_39_33_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[15] = ((BlockIO *) _ssGetBlockIO(S))->B_39_35_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[16] = ((BlockIO *) _ssGetBlockIO(S))->B_39_37_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[17] = ((BlockIO *) _ssGetBlockIO(S))->B_39_39_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[18] = ((BlockIO *) _ssGetBlockIO(S))->B_39_41_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[19] = ((BlockIO *) _ssGetBlockIO(S))->B_39_43_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[20] = ((BlockIO *) _ssGetBlockIO(S))->B_39_45_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[21] = ((BlockIO *) _ssGetBlockIO(S))->B_39_47_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[22] = ((BlockIO *) _ssGetBlockIO(S))->B_39_49_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[23] = ((BlockIO *) _ssGetBlockIO(S))->B_39_51_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[24] = ((BlockIO *) _ssGetBlockIO(S))->B_39_53_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[25] = ((BlockIO *) _ssGetBlockIO(S))->B_39_55_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_55_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[26] = ((BlockIO *) _ssGetBlockIO(S))->B_39_57_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_57_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[27] = ((BlockIO *) _ssGetBlockIO(S))->B_39_59_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_59_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[28] = ((BlockIO *) _ssGetBlockIO(S))->B_39_61_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_61_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[29] = ((BlockIO *) _ssGetBlockIO(S))->B_39_63_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_63_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[30] = ((BlockIO *) _ssGetBlockIO(S))->B_39_65_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_65_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[31] = ((BlockIO *) _ssGetBlockIO(S))->B_39_67_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_67_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[32] = ((BlockIO *) _ssGetBlockIO(S))->B_39_69_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_69_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[33] = ((BlockIO *) _ssGetBlockIO(S))->B_39_71_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_71_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[34] = ((BlockIO *) _ssGetBlockIO(S))->B_39_73_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_73_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[35] = ((BlockIO *) _ssGetBlockIO(S))->B_39_75_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_75_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[36] = ((BlockIO *) _ssGetBlockIO(S))->B_39_77_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_77_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[37] = ((BlockIO *) _ssGetBlockIO(S))->B_39_79_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_79_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[38] = ((BlockIO *) _ssGetBlockIO(S))->B_39_81_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_81_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        tmp_15[39] = ((BlockIO *) _ssGetBlockIO(S))->B_39_83_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_83_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_5_0[1];
        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_86_0[i] = tmp_15[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_85_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_87_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_760 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_86_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_89_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_761;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_90_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_87_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_89_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_92_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_90_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_762;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_93_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_763;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_94_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_92_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_93_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_96_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_764, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_98_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_765, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_100_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_766, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_102_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_767, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_104_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_768, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_106_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_769, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_108_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_770, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_110_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_771, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_112_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_772, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_114_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_773, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_116_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_774, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_118_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_775, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_120_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_776, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_122_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_777, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_124_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_778, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_126_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_779, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_128_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_780, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_130_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_781, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_132_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_782, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_134_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_783, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_136_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_784, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_138_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_785, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_140_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_786, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_142_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_787, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_144_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_788, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_146_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_789, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_148_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_790, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_150_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_791, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_152_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_792, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_154_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_793, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_156_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_794, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_158_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_795, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_160_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_796, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_162_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_797, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_164_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_798, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_166_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_799, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_168_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_800, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_170_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_801, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_172_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_802, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_174_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_803, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_176_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_804, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_178_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_805, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_180_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_806, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_182_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_807, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_184_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_808, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_186_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_809, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_188_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_810, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_190_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_811, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_192_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_812, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_194_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_813, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_196_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_814, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_198_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_815, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_200_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_816, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_202_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_817, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_204_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_818, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_206_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_819, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_208_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_820, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_210_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_821, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_212_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_822, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_214_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_823, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_216_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_824, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_218_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_825, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_220_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_826, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_222_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_827, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_224_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_828, 65U * sizeof
                 (real_T));
        }

        B_62_0_0 = 0.0;
        tmp_0 = 0.0;
        tmp_1 = 0.0;
        tmp_2 = 0.0;
        tmp_3 = 0.0;
        tmp_4 = 0.0;
        tmp_5 = 0.0;
        tmp_6 = 0.0;
        tmp_7 = 0.0;
        tmp_8 = 0.0;
        tmp_9 = 0.0;
        tmp_a = 0.0;
        tmp_b = 0.0;
        tmp_c = 0.0;
        tmp_d = 0.0;
        tmp_g = 0.0;
        tmp_h = 0.0;
        tmp_i = 0.0;
        tmp_j = 0.0;
        tmp_k = 0.0;
        tmp_l = 0.0;
        tmp_m = 0.0;
        tmp_n = 0.0;
        tmp_o = 0.0;
        tmp_p = 0.0;
        tmp_q = 0.0;
        tmp_r = 0.0;
        tmp_s = 0.0;
        tmp_t = 0.0;
        tmp_u = 0.0;
        tmp_v = 0.0;
        tmp_w = 0.0;
        tmp_x = 0.0;
        tmp_y = 0.0;
        tmp_z = 0.0;
        tmp_10 = 0.0;
        tmp_11 = 0.0;
        tmp_12 = 0.0;
        tmp_13 = 0.0;
        tmp_14 = 0.0;
        tmp_18 = 0.0;
        tmp_19 = 0.0;
        tmp_1a = 0.0;
        tmp_1b = 0.0;
        tmp_1c = 0.0;
        tmp_1d = 0.0;
        tmp_1e = 0.0;
        tmp_1f = 0.0;
        tmp_1g = 0.0;
        tmp_1h = 0.0;
        tmp_1i = 0.0;
        tmp_1j = 0.0;
        tmp_1k = 0.0;
        tmp_1l = 0.0;
        tmp_1m = 0.0;
        tmp_1n = 0.0;
        tmp_1o = 0.0;
        tmp_1p = 0.0;
        tmp_1q = 0.0;
        tmp_1r = 0.0;
        tmp_1v = 0.0;
        tmp_1w = 0.0;
        tmp_1x = 0.0;
        tmp_1y = 0.0;
        tmp_1z = 0.0;
        for (i = 0; i < 40; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_1_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_96_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_39_98_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_39_100_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_39_102_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_39_104_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_39_106_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_39_108_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_39_110_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_39_112_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_39_114_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_39_116_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_39_118_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_39_120_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_39_122_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_39_124_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_39_126_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_39_128_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_39_130_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_39_132_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_39_134_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_39_136_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_39_138_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_39_140_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_39_142_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_39_144_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_39_146_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_39_148_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_39_150_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_39_152_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_39_154_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_39_156_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_39_158_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_39_160_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_39_162_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_39_164_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_39_166_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_39_168_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_39_170_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_39_172_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_39_174_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_39_176_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_39_178_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_39_180_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_39_182_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_39_184_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_39_186_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_39_188_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_39_190_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_39_192_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1i += ((BlockIO *) _ssGetBlockIO(S))->B_39_194_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1j += ((BlockIO *) _ssGetBlockIO(S))->B_39_196_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1k += ((BlockIO *) _ssGetBlockIO(S))->B_39_198_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1l += ((BlockIO *) _ssGetBlockIO(S))->B_39_200_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1m += ((BlockIO *) _ssGetBlockIO(S))->B_39_202_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1n += ((BlockIO *) _ssGetBlockIO(S))->B_39_204_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1o += ((BlockIO *) _ssGetBlockIO(S))->B_39_206_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1p += ((BlockIO *) _ssGetBlockIO(S))->B_39_208_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1q += ((BlockIO *) _ssGetBlockIO(S))->B_39_210_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1r += ((BlockIO *) _ssGetBlockIO(S))->B_39_212_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1v += ((BlockIO *) _ssGetBlockIO(S))->B_39_214_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1w += ((BlockIO *) _ssGetBlockIO(S))->B_39_216_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1x += ((BlockIO *) _ssGetBlockIO(S))->B_39_218_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1y += ((BlockIO *) _ssGetBlockIO(S))->B_39_220_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
          tmp_1z += ((BlockIO *) _ssGetBlockIO(S))->B_39_222_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_94_0[i];
        }

        tmp_20[0] = B_62_0_0;
        tmp_20[1] = tmp_0;
        tmp_20[2] = tmp_1;
        tmp_20[3] = tmp_2;
        tmp_20[4] = tmp_3;
        tmp_20[5] = tmp_4;
        tmp_20[6] = tmp_5;
        tmp_20[7] = tmp_6;
        tmp_20[8] = tmp_7;
        tmp_20[9] = tmp_8;
        tmp_20[10] = tmp_9;
        tmp_20[11] = tmp_a;
        tmp_20[12] = tmp_b;
        tmp_20[13] = tmp_c;
        tmp_20[14] = tmp_d;
        tmp_20[15] = tmp_g;
        tmp_20[16] = tmp_h;
        tmp_20[17] = tmp_i;
        tmp_20[18] = tmp_j;
        tmp_20[19] = tmp_k;
        tmp_20[20] = tmp_l;
        tmp_20[21] = tmp_m;
        tmp_20[22] = tmp_n;
        tmp_20[23] = tmp_o;
        tmp_20[24] = tmp_p;
        tmp_20[25] = tmp_q;
        tmp_20[26] = tmp_r;
        tmp_20[27] = tmp_s;
        tmp_20[28] = tmp_t;
        tmp_20[29] = tmp_u;
        tmp_20[30] = tmp_v;
        tmp_20[31] = tmp_w;
        tmp_20[32] = tmp_x;
        tmp_20[33] = tmp_y;
        tmp_20[34] = tmp_z;
        tmp_20[35] = tmp_10;
        tmp_20[36] = tmp_11;
        tmp_20[37] = tmp_12;
        tmp_20[38] = tmp_13;
        tmp_20[39] = tmp_14;
        tmp_20[40] = tmp_18;
        tmp_20[41] = tmp_19;
        tmp_20[42] = tmp_1a;
        tmp_20[43] = tmp_1b;
        tmp_20[44] = tmp_1c;
        tmp_20[45] = tmp_1d;
        tmp_20[46] = tmp_1e;
        tmp_20[47] = tmp_1f;
        tmp_20[48] = tmp_1g;
        tmp_20[49] = tmp_1h;
        tmp_20[50] = tmp_1i;
        tmp_20[51] = tmp_1j;
        tmp_20[52] = tmp_1k;
        tmp_20[53] = tmp_1l;
        tmp_20[54] = tmp_1m;
        tmp_20[55] = tmp_1n;
        tmp_20[56] = tmp_1o;
        tmp_20[57] = tmp_1p;
        tmp_20[58] = tmp_1q;
        tmp_20[59] = tmp_1r;
        tmp_20[60] = tmp_1v;
        tmp_20[61] = tmp_1w;
        tmp_20[62] = tmp_1x;
        tmp_20[63] = tmp_1y;
        tmp_20[64] = tmp_1z;
        for (i = 0; i < 65; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_225_0[i] = tmp_20[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_224_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_226_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_829 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_225_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_228_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_830;
        }

        for (i = 0; i < 65; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_229_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_226_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_228_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_231_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_229_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_831;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_232_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_832;
        }

        for (i = 0; i < 65; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_233_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_231_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_232_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_235_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_833;
        }

        B_62_0_0 = 0.0;
        for (i = 0; i < 65; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_0_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_233_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_236_0 = B_62_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_39_235_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_237_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_236_0 + ((Parameters *) ssGetDefaultParam(S))->P_834;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_238_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_835 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_237_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_239_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_238_0 + ((Parameters *) ssGetDefaultParam(S))->P_836;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_240_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_239_0 >= ((Parameters *) ssGetDefaultParam(S))->P_837 ?
          ((Parameters *) ssGetDefaultParam(S))->P_837 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_239_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_838 ? ((Parameters *) ssGetDefaultParam(S))->P_838 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_239_0;

        /* Clock: '<S838>/Clock' */
        ((BlockIO *) _ssGetBlockIO(S))->B_39_241_0 = ssGetT(S);
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_242_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_839, 24U * sizeof
                 (real_T));
        }

        /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 35, 0, SS_CALL_MDL_OUTPUTS);
        ((BlockIO *) _ssGetBlockIO(S))->B_39_244_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_240_0 * ((BlockIO *) _ssGetBlockIO(S))->B_35_0_1;
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_245_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_840, 20U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_246_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_841, 15U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_39_247_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_842[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_247_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_842[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_248_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_843[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_248_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_843[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_249_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_844[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_248_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_249_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_844[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_248_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_39_249_0[0] + ((Parameters *) ssGetDefaultParam(S))
          ->P_845;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_39_249_0[1] + ((Parameters *) ssGetDefaultParam(S))
          ->P_845;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_252_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_846[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_252_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_846[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_254_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_847[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_254_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_847[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_256_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_848[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_256_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_848[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_258_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_849[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_258_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_849[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_260_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_850[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_260_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_850[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_262_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_851[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_262_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_851[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_264_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_852[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_264_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_852[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_266_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_853[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_266_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_853[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_268_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_854[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_268_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_854[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_270_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_855[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_270_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_855[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_272_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_856[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_272_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_856[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_274_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_857[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_274_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_857[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_276_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_858[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_276_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_858[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_278_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_859[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_278_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_859[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_280_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_860, 15U * sizeof
                 (real_T));
        }

        tmp_e[0] = ((BlockIO *) _ssGetBlockIO(S))->B_39_247_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_247_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[1] = ((BlockIO *) _ssGetBlockIO(S))->B_39_252_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_252_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[2] = ((BlockIO *) _ssGetBlockIO(S))->B_39_254_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_254_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[3] = ((BlockIO *) _ssGetBlockIO(S))->B_39_256_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_256_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[4] = ((BlockIO *) _ssGetBlockIO(S))->B_39_258_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_258_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[5] = ((BlockIO *) _ssGetBlockIO(S))->B_39_260_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_260_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[6] = ((BlockIO *) _ssGetBlockIO(S))->B_39_262_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_262_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[7] = ((BlockIO *) _ssGetBlockIO(S))->B_39_264_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_264_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[8] = ((BlockIO *) _ssGetBlockIO(S))->B_39_266_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_266_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[9] = ((BlockIO *) _ssGetBlockIO(S))->B_39_268_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_268_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[10] = ((BlockIO *) _ssGetBlockIO(S))->B_39_270_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_270_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[11] = ((BlockIO *) _ssGetBlockIO(S))->B_39_272_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_272_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[12] = ((BlockIO *) _ssGetBlockIO(S))->B_39_274_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_274_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[13] = ((BlockIO *) _ssGetBlockIO(S))->B_39_276_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_276_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        tmp_e[14] = ((BlockIO *) _ssGetBlockIO(S))->B_39_278_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_250_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_278_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_250_0[1];
        for (i = 0; i < 15; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_281_0[i] = tmp_e[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_280_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_282_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_861 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_281_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_284_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_862;
        }

        for (i = 0; i < 15; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_285_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_282_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_284_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_287_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_285_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_863;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_288_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_864;
        }

        for (i = 0; i < 15; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_289_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_287_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_288_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_291_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_865, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_293_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_866, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_295_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_867, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_297_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_868, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_299_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_869, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_301_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_870, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_303_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_871, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_305_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_872, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_307_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_873, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_309_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_874, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_311_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_875, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_313_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_876, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_315_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_877, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_317_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_878, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_319_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_879, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_321_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_880, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_323_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_881, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_325_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_882, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_327_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_883, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_329_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_884, 20U * sizeof
                 (real_T));
        }

        B_62_0_0 = 0.0;
        tmp_0 = 0.0;
        tmp_1 = 0.0;
        tmp_2 = 0.0;
        tmp_3 = 0.0;
        tmp_4 = 0.0;
        tmp_5 = 0.0;
        tmp_6 = 0.0;
        tmp_7 = 0.0;
        tmp_8 = 0.0;
        tmp_9 = 0.0;
        tmp_a = 0.0;
        tmp_b = 0.0;
        tmp_c = 0.0;
        tmp_d = 0.0;
        tmp_g = 0.0;
        tmp_h = 0.0;
        tmp_i = 0.0;
        tmp_j = 0.0;
        tmp_k = 0.0;
        for (i = 0; i < 15; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_246_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_291_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_39_293_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_39_295_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_39_297_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_39_299_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_39_301_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_39_303_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_39_305_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_39_307_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_39_309_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_39_311_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_39_313_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_39_315_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_39_317_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_39_319_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_39_321_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_39_323_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_39_325_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_39_327_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_289_0[i];
        }

        tmp_17[0] = B_62_0_0;
        tmp_17[1] = tmp_0;
        tmp_17[2] = tmp_1;
        tmp_17[3] = tmp_2;
        tmp_17[4] = tmp_3;
        tmp_17[5] = tmp_4;
        tmp_17[6] = tmp_5;
        tmp_17[7] = tmp_6;
        tmp_17[8] = tmp_7;
        tmp_17[9] = tmp_8;
        tmp_17[10] = tmp_9;
        tmp_17[11] = tmp_a;
        tmp_17[12] = tmp_b;
        tmp_17[13] = tmp_c;
        tmp_17[14] = tmp_d;
        tmp_17[15] = tmp_g;
        tmp_17[16] = tmp_h;
        tmp_17[17] = tmp_i;
        tmp_17[18] = tmp_j;
        tmp_17[19] = tmp_k;
        for (i = 0; i < 20; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_330_0[i] = tmp_17[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_329_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_331_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_885 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_330_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_333_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_886;
        }

        for (i = 0; i < 20; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_334_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_331_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_333_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_336_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_334_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_887;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_337_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_888;
        }

        for (i = 0; i < 20; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_338_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_336_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_337_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_340_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_889;
        }

        B_62_0_0 = 0.0;
        for (i = 0; i < 20; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_245_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_338_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_341_0 = B_62_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_39_340_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_342_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_341_0 + ((Parameters *) ssGetDefaultParam(S))->P_890;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_343_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_891 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_342_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_344_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_343_0 + ((Parameters *) ssGetDefaultParam(S))->P_892;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_345_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_344_0 >= ((Parameters *) ssGetDefaultParam(S))->P_893 ?
          ((Parameters *) ssGetDefaultParam(S))->P_893 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_344_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_894 ? ((Parameters *) ssGetDefaultParam(S))->P_894 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_344_0;
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_346_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_895, 24U * sizeof
                 (real_T));
        }

        /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 36, 0, SS_CALL_MDL_OUTPUTS);
        ((BlockIO *) _ssGetBlockIO(S))->B_39_348_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_345_0 * ((BlockIO *) _ssGetBlockIO(S))->B_36_0_1;
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_349_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_896, 45U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_350_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_897, 35U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_39_351_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_898[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_351_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_898[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_352_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_899[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_352_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_899[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_353_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_900[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_352_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_353_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_900[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_352_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_39_353_0[0] + ((Parameters *) ssGetDefaultParam(S))
          ->P_901;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_39_353_0[1] + ((Parameters *) ssGetDefaultParam(S))
          ->P_901;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_356_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_902[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_356_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_902[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_358_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_903[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_358_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_903[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_360_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_904[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_360_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_904[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_362_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_905[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_362_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_905[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_364_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_906[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_364_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_906[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_366_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_907[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_366_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_907[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_368_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_908[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_368_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_908[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_370_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_909[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_370_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_909[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_372_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_910[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_372_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_910[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_374_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_911[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_374_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_911[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_376_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_912[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_376_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_912[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_378_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_913[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_378_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_913[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_380_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_914[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_380_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_914[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_382_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_915[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_382_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_915[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_384_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_916[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_384_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_916[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_386_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_917[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_386_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_917[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_388_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_918[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_388_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_918[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_390_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_919[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_390_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_919[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_392_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_920[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_392_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_920[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_394_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_921[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_394_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_921[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_396_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_922[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_396_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_922[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_398_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_923[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_398_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_923[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_400_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_924[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_400_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_924[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_402_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_925[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_402_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_925[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_404_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_926[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_404_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_926[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_406_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_927[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_406_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_927[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_408_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_928[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_408_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_928[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_410_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_929[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_410_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_929[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_412_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_930[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_412_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_930[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_414_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_931[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_414_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_931[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_416_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_932[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_416_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_932[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_418_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_933[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_418_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_933[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_420_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_934[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_420_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_934[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_422_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_935[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_422_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_935[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_424_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_936, 35U * sizeof
                 (real_T));
        }

        tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_39_351_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_351_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_39_356_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_356_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_39_358_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_358_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_39_360_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_360_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_39_362_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_362_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_39_364_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_364_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_39_366_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_366_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_39_368_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_368_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_39_370_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_370_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_39_372_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_372_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_39_374_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_374_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_39_376_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_376_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_39_378_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_378_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_39_380_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_380_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_39_382_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_382_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_39_384_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_384_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_39_386_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_386_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_39_388_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_388_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_39_390_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_390_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_39_392_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_392_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_39_394_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_394_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_39_396_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_396_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_39_398_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_398_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_39_400_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_400_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_39_402_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_402_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_39_404_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_404_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_39_406_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_406_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_39_408_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_408_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_39_410_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_410_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_39_412_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_412_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_39_414_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_414_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_39_416_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_416_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_39_418_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_418_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_39_420_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_420_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_39_422_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_354_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_422_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_354_0[1];
        for (i = 0; i < 35; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_425_0[i] = tmp_1t[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_424_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_426_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_937 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_425_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_428_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_938;
        }

        for (i = 0; i < 35; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_429_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_426_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_428_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_431_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_429_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_939;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_432_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_940;
        }

        for (i = 0; i < 35; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_433_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_431_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_432_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_435_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_941, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_437_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_942, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_439_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_943, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_441_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_944, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_443_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_945, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_445_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_946, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_447_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_947, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_449_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_948, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_451_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_949, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_453_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_950, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_455_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_951, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_457_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_952, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_459_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_953, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_461_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_954, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_463_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_955, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_465_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_956, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_467_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_957, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_469_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_958, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_471_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_959, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_473_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_960, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_475_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_961, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_477_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_962, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_479_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_963, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_481_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_964, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_483_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_965, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_485_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_966, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_487_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_967, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_489_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_968, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_491_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_969, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_493_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_970, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_495_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_971, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_497_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_972, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_499_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_973, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_501_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_974, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_503_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_975, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_505_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_976, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_507_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_977, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_509_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_978, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_511_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_979, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_513_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_980, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_515_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_981, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_517_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_982, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_519_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_983, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_521_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_984, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_523_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_985, 45U * sizeof
                 (real_T));
        }

        B_62_0_0 = 0.0;
        tmp_0 = 0.0;
        tmp_1 = 0.0;
        tmp_2 = 0.0;
        tmp_3 = 0.0;
        tmp_4 = 0.0;
        tmp_5 = 0.0;
        tmp_6 = 0.0;
        tmp_7 = 0.0;
        tmp_8 = 0.0;
        tmp_9 = 0.0;
        tmp_a = 0.0;
        tmp_b = 0.0;
        tmp_c = 0.0;
        tmp_d = 0.0;
        tmp_g = 0.0;
        tmp_h = 0.0;
        tmp_i = 0.0;
        tmp_j = 0.0;
        tmp_k = 0.0;
        tmp_l = 0.0;
        tmp_m = 0.0;
        tmp_n = 0.0;
        tmp_o = 0.0;
        tmp_p = 0.0;
        tmp_q = 0.0;
        tmp_r = 0.0;
        tmp_s = 0.0;
        tmp_t = 0.0;
        tmp_u = 0.0;
        tmp_v = 0.0;
        tmp_w = 0.0;
        tmp_x = 0.0;
        tmp_y = 0.0;
        tmp_z = 0.0;
        tmp_10 = 0.0;
        tmp_11 = 0.0;
        tmp_12 = 0.0;
        tmp_13 = 0.0;
        tmp_14 = 0.0;
        tmp_18 = 0.0;
        tmp_19 = 0.0;
        tmp_1a = 0.0;
        tmp_1b = 0.0;
        tmp_1c = 0.0;
        for (i = 0; i < 35; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_350_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_435_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_39_437_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_39_439_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_39_441_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_39_443_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_39_445_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_39_447_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_39_449_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_39_451_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_39_453_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_39_455_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_39_457_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_39_459_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_39_461_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_39_463_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_39_465_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_39_467_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_39_469_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_39_471_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_39_473_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_39_475_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_39_477_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_39_479_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_39_481_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_39_483_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_39_485_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_39_487_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_39_489_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_39_491_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_39_493_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_39_495_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_39_497_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_39_499_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_39_501_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_39_503_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_39_505_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_39_507_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_39_509_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_39_511_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_39_513_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_39_515_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_39_517_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_39_519_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
          tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_39_521_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_433_0[i];
        }

        tmp_1u[0] = B_62_0_0;
        tmp_1u[1] = tmp_0;
        tmp_1u[2] = tmp_1;
        tmp_1u[3] = tmp_2;
        tmp_1u[4] = tmp_3;
        tmp_1u[5] = tmp_4;
        tmp_1u[6] = tmp_5;
        tmp_1u[7] = tmp_6;
        tmp_1u[8] = tmp_7;
        tmp_1u[9] = tmp_8;
        tmp_1u[10] = tmp_9;
        tmp_1u[11] = tmp_a;
        tmp_1u[12] = tmp_b;
        tmp_1u[13] = tmp_c;
        tmp_1u[14] = tmp_d;
        tmp_1u[15] = tmp_g;
        tmp_1u[16] = tmp_h;
        tmp_1u[17] = tmp_i;
        tmp_1u[18] = tmp_j;
        tmp_1u[19] = tmp_k;
        tmp_1u[20] = tmp_l;
        tmp_1u[21] = tmp_m;
        tmp_1u[22] = tmp_n;
        tmp_1u[23] = tmp_o;
        tmp_1u[24] = tmp_p;
        tmp_1u[25] = tmp_q;
        tmp_1u[26] = tmp_r;
        tmp_1u[27] = tmp_s;
        tmp_1u[28] = tmp_t;
        tmp_1u[29] = tmp_u;
        tmp_1u[30] = tmp_v;
        tmp_1u[31] = tmp_w;
        tmp_1u[32] = tmp_x;
        tmp_1u[33] = tmp_y;
        tmp_1u[34] = tmp_z;
        tmp_1u[35] = tmp_10;
        tmp_1u[36] = tmp_11;
        tmp_1u[37] = tmp_12;
        tmp_1u[38] = tmp_13;
        tmp_1u[39] = tmp_14;
        tmp_1u[40] = tmp_18;
        tmp_1u[41] = tmp_19;
        tmp_1u[42] = tmp_1a;
        tmp_1u[43] = tmp_1b;
        tmp_1u[44] = tmp_1c;
        for (i = 0; i < 45; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_524_0[i] = tmp_1u[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_523_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_525_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_986 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_524_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_527_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_987;
        }

        for (i = 0; i < 45; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_528_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_525_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_527_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_530_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_528_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_988;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_531_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_989;
        }

        for (i = 0; i < 45; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_532_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_530_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_531_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_534_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_990;
        }

        B_62_0_0 = 0.0;
        for (i = 0; i < 45; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_349_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_532_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_535_0 = B_62_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_39_534_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_536_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_535_0 + ((Parameters *) ssGetDefaultParam(S))->P_991;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_537_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_992 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_536_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_538_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_537_0 + ((Parameters *) ssGetDefaultParam(S))->P_993;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_539_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_538_0 >= ((Parameters *) ssGetDefaultParam(S))->P_994 ?
          ((Parameters *) ssGetDefaultParam(S))->P_994 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_538_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_995 ? ((Parameters *) ssGetDefaultParam(S))->P_995 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_538_0;
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_540_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_996, 24U * sizeof
                 (real_T));
        }

        /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 37, 0, SS_CALL_MDL_OUTPUTS);
        ((BlockIO *) _ssGetBlockIO(S))->B_39_542_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_539_0 * ((BlockIO *) _ssGetBlockIO(S))->B_37_0_1;
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_543_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_997, 50U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_544_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_998, 40U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_39_545_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_999[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_545_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_999[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_546_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_1000[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_546_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_1000[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_547_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_1001[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_546_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_547_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_1001[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_546_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_39_547_0[0] + ((Parameters *) ssGetDefaultParam(S))
          ->P_1002;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_39_547_0[1] + ((Parameters *) ssGetDefaultParam(S))
          ->P_1002;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_550_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1003[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_550_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1003[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_552_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1004[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_552_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1004[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_554_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1005[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_554_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1005[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_556_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1006[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_556_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1006[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_558_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1007[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_558_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1007[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_560_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1008[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_560_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1008[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_562_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1009[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_562_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1009[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_564_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1010[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_564_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1010[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_566_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1011[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_566_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1011[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_568_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1012[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_568_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1012[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_570_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1013[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_570_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1013[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_572_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1014[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_572_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1014[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_574_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1015[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_574_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1015[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_576_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1016[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_576_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1016[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_578_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1017[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_578_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1017[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_580_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1018[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_580_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1018[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_582_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1019[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_582_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1019[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_584_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1020[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_584_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1020[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_586_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1021[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_586_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1021[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_588_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1022[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_588_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1022[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_590_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1023[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_590_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1023[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_592_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1024[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_592_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1024[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_594_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1025[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_594_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1025[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_596_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1026[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_596_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1026[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_598_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1027[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_598_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1027[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_600_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1028[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_600_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1028[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_602_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1029[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_602_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1029[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_604_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1030[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_604_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1030[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_606_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1031[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_606_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1031[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_608_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1032[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_608_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1032[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_610_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1033[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_610_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1033[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_612_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1034[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_612_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1034[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_614_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1035[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_614_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1035[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_616_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1036[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_616_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1036[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_618_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1037[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_618_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1037[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_620_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1038[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_620_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1038[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_622_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1039[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_622_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1039[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_624_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1040[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_624_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1040[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_626_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1041[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_626_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1041[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_628_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1042, 40U * sizeof
                 (real_T));
        }

        tmp_15[0] = ((BlockIO *) _ssGetBlockIO(S))->B_39_545_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_545_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[1] = ((BlockIO *) _ssGetBlockIO(S))->B_39_550_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_550_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[2] = ((BlockIO *) _ssGetBlockIO(S))->B_39_552_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_552_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[3] = ((BlockIO *) _ssGetBlockIO(S))->B_39_554_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_554_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[4] = ((BlockIO *) _ssGetBlockIO(S))->B_39_556_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_556_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[5] = ((BlockIO *) _ssGetBlockIO(S))->B_39_558_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_558_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[6] = ((BlockIO *) _ssGetBlockIO(S))->B_39_560_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_560_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[7] = ((BlockIO *) _ssGetBlockIO(S))->B_39_562_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_562_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[8] = ((BlockIO *) _ssGetBlockIO(S))->B_39_564_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_564_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[9] = ((BlockIO *) _ssGetBlockIO(S))->B_39_566_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_566_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[10] = ((BlockIO *) _ssGetBlockIO(S))->B_39_568_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_568_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[11] = ((BlockIO *) _ssGetBlockIO(S))->B_39_570_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_570_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[12] = ((BlockIO *) _ssGetBlockIO(S))->B_39_572_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_572_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[13] = ((BlockIO *) _ssGetBlockIO(S))->B_39_574_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_574_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[14] = ((BlockIO *) _ssGetBlockIO(S))->B_39_576_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_576_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[15] = ((BlockIO *) _ssGetBlockIO(S))->B_39_578_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_578_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[16] = ((BlockIO *) _ssGetBlockIO(S))->B_39_580_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_580_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[17] = ((BlockIO *) _ssGetBlockIO(S))->B_39_582_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_582_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[18] = ((BlockIO *) _ssGetBlockIO(S))->B_39_584_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_584_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[19] = ((BlockIO *) _ssGetBlockIO(S))->B_39_586_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_586_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[20] = ((BlockIO *) _ssGetBlockIO(S))->B_39_588_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_588_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[21] = ((BlockIO *) _ssGetBlockIO(S))->B_39_590_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_590_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[22] = ((BlockIO *) _ssGetBlockIO(S))->B_39_592_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_592_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[23] = ((BlockIO *) _ssGetBlockIO(S))->B_39_594_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_594_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[24] = ((BlockIO *) _ssGetBlockIO(S))->B_39_596_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_596_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[25] = ((BlockIO *) _ssGetBlockIO(S))->B_39_598_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_598_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[26] = ((BlockIO *) _ssGetBlockIO(S))->B_39_600_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_600_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[27] = ((BlockIO *) _ssGetBlockIO(S))->B_39_602_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_602_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[28] = ((BlockIO *) _ssGetBlockIO(S))->B_39_604_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_604_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[29] = ((BlockIO *) _ssGetBlockIO(S))->B_39_606_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_606_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[30] = ((BlockIO *) _ssGetBlockIO(S))->B_39_608_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_608_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[31] = ((BlockIO *) _ssGetBlockIO(S))->B_39_610_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_610_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[32] = ((BlockIO *) _ssGetBlockIO(S))->B_39_612_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_612_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[33] = ((BlockIO *) _ssGetBlockIO(S))->B_39_614_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_614_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[34] = ((BlockIO *) _ssGetBlockIO(S))->B_39_616_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_616_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[35] = ((BlockIO *) _ssGetBlockIO(S))->B_39_618_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_618_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[36] = ((BlockIO *) _ssGetBlockIO(S))->B_39_620_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_620_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[37] = ((BlockIO *) _ssGetBlockIO(S))->B_39_622_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_622_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[38] = ((BlockIO *) _ssGetBlockIO(S))->B_39_624_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_624_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        tmp_15[39] = ((BlockIO *) _ssGetBlockIO(S))->B_39_626_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_39_548_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_626_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_39_548_0[1];
        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_629_0[i] = tmp_15[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_628_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_630_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_1043 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_629_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_632_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1044;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_633_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_630_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_632_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_635_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_633_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_1045;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_636_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1046;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_637_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_635_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_636_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_639_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1047, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_641_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1048, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_643_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1049, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_645_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1050, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_647_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1051, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_649_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1052, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_651_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1053, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_653_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1054, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_655_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1055, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_657_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1056, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_659_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1057, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_661_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1058, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_663_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1059, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_665_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1060, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_667_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1061, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_669_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1062, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_671_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1063, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_673_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1064, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_675_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1065, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_677_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1066, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_679_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1067, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_681_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1068, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_683_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1069, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_685_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1070, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_687_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1071, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_689_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1072, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_691_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1073, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_693_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1074, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_695_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1075, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_697_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1076, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_699_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1077, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_701_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1078, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_703_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1079, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_705_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1080, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_707_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1081, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_709_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1082, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_711_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1083, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_713_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1084, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_715_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1085, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_717_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1086, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_719_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1087, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_721_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1088, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_723_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1089, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_725_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1090, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_727_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1091, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_729_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1092, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_731_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1093, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_733_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1094, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_735_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1095, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_737_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1096, 50U * sizeof
                 (real_T));
        }

        B_62_0_0 = 0.0;
        tmp_0 = 0.0;
        tmp_1 = 0.0;
        tmp_2 = 0.0;
        tmp_3 = 0.0;
        tmp_4 = 0.0;
        tmp_5 = 0.0;
        tmp_6 = 0.0;
        tmp_7 = 0.0;
        tmp_8 = 0.0;
        tmp_9 = 0.0;
        tmp_a = 0.0;
        tmp_b = 0.0;
        tmp_c = 0.0;
        tmp_d = 0.0;
        tmp_g = 0.0;
        tmp_h = 0.0;
        tmp_i = 0.0;
        tmp_j = 0.0;
        tmp_k = 0.0;
        tmp_l = 0.0;
        tmp_m = 0.0;
        tmp_n = 0.0;
        tmp_o = 0.0;
        tmp_p = 0.0;
        tmp_q = 0.0;
        tmp_r = 0.0;
        tmp_s = 0.0;
        tmp_t = 0.0;
        tmp_u = 0.0;
        tmp_v = 0.0;
        tmp_w = 0.0;
        tmp_x = 0.0;
        tmp_y = 0.0;
        tmp_z = 0.0;
        tmp_10 = 0.0;
        tmp_11 = 0.0;
        tmp_12 = 0.0;
        tmp_13 = 0.0;
        tmp_14 = 0.0;
        tmp_18 = 0.0;
        tmp_19 = 0.0;
        tmp_1a = 0.0;
        tmp_1b = 0.0;
        tmp_1c = 0.0;
        tmp_1d = 0.0;
        tmp_1e = 0.0;
        tmp_1f = 0.0;
        tmp_1g = 0.0;
        tmp_1h = 0.0;
        for (i = 0; i < 40; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_544_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_639_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_39_641_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_39_643_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_39_645_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_39_647_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_39_649_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_39_651_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_39_653_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_39_655_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_39_657_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_39_659_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_39_661_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_39_663_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_39_665_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_39_667_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_39_669_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_39_671_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_39_673_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_39_675_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_39_677_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_39_679_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_39_681_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_39_683_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_39_685_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_39_687_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_39_689_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_39_691_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_39_693_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_39_695_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_39_697_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_39_699_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_39_701_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_39_703_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_39_705_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_39_707_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_39_709_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_39_711_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_39_713_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_39_715_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_39_717_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_39_719_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_39_721_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_39_723_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_39_725_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_39_727_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_39_729_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_39_731_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_39_733_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
          tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_39_735_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_637_0[i];
        }

        tmp_21[0] = B_62_0_0;
        tmp_21[1] = tmp_0;
        tmp_21[2] = tmp_1;
        tmp_21[3] = tmp_2;
        tmp_21[4] = tmp_3;
        tmp_21[5] = tmp_4;
        tmp_21[6] = tmp_5;
        tmp_21[7] = tmp_6;
        tmp_21[8] = tmp_7;
        tmp_21[9] = tmp_8;
        tmp_21[10] = tmp_9;
        tmp_21[11] = tmp_a;
        tmp_21[12] = tmp_b;
        tmp_21[13] = tmp_c;
        tmp_21[14] = tmp_d;
        tmp_21[15] = tmp_g;
        tmp_21[16] = tmp_h;
        tmp_21[17] = tmp_i;
        tmp_21[18] = tmp_j;
        tmp_21[19] = tmp_k;
        tmp_21[20] = tmp_l;
        tmp_21[21] = tmp_m;
        tmp_21[22] = tmp_n;
        tmp_21[23] = tmp_o;
        tmp_21[24] = tmp_p;
        tmp_21[25] = tmp_q;
        tmp_21[26] = tmp_r;
        tmp_21[27] = tmp_s;
        tmp_21[28] = tmp_t;
        tmp_21[29] = tmp_u;
        tmp_21[30] = tmp_v;
        tmp_21[31] = tmp_w;
        tmp_21[32] = tmp_x;
        tmp_21[33] = tmp_y;
        tmp_21[34] = tmp_z;
        tmp_21[35] = tmp_10;
        tmp_21[36] = tmp_11;
        tmp_21[37] = tmp_12;
        tmp_21[38] = tmp_13;
        tmp_21[39] = tmp_14;
        tmp_21[40] = tmp_18;
        tmp_21[41] = tmp_19;
        tmp_21[42] = tmp_1a;
        tmp_21[43] = tmp_1b;
        tmp_21[44] = tmp_1c;
        tmp_21[45] = tmp_1d;
        tmp_21[46] = tmp_1e;
        tmp_21[47] = tmp_1f;
        tmp_21[48] = tmp_1g;
        tmp_21[49] = tmp_1h;
        for (i = 0; i < 50; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_738_0[i] = tmp_21[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_737_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_39_739_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_1097 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_738_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_741_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1098;
        }

        for (i = 0; i < 50; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_742_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_39_739_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_39_741_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_39_744_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_39_742_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_1099;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_745_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1100;
        }

        for (i = 0; i < 50; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_746_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_39_744_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_39_745_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_39_748_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1101;
        }

        B_62_0_0 = 0.0;
        for (i = 0; i < 50; i++) {
          B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_39_543_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_39_746_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_39_749_0 = B_62_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_39_748_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_750_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_749_0 + ((Parameters *) ssGetDefaultParam(S))->P_1102;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_751_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_1103 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_750_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_752_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_751_0 + ((Parameters *) ssGetDefaultParam(S))->P_1104;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_753_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_752_0 >= ((Parameters *) ssGetDefaultParam(S))->P_1105 ?
          ((Parameters *) ssGetDefaultParam(S))->P_1105 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_752_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_1106 ? ((Parameters *) ssGetDefaultParam(S))->P_1106 : ((BlockIO *)
          _ssGetBlockIO(S))->B_39_752_0;
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_39_754_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1107, 24U * sizeof
                 (real_T));
        }

        /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
        /* Call into Simulink for MEX-version of S-function */
        ssCallAccelRunBlock(S, 38, 0, SS_CALL_MDL_OUTPUTS);
        ((BlockIO *) _ssGetBlockIO(S))->B_39_756_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_39_753_0 * ((BlockIO *) _ssGetBlockIO(S))->B_38_0_1;
        ((BlockIO *) _ssGetBlockIO(S))->B_39_757_0 = ((((BlockIO *)
          _ssGetBlockIO(S))->B_39_244_0 + ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_348_0) + ((BlockIO *) _ssGetBlockIO(S))->B_39_542_0) +
          ((BlockIO *) _ssGetBlockIO(S))->B_39_756_0;
        if (ssIsSampleHit(S, 1, 0)) {
          /* Scope: '<S838>/Scope' */
          /* Call into Simulink for Scope */
          ssCallAccelRunBlock(S, 39, 758, SS_CALL_MDL_OUTPUTS);
        }

        if (ssIsMajorTimeStep(S)) {
          srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder07_SubsysRanBC);
        }
        break;

       case 1:
        rtPrevAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c;
        if (ssIsMajorTimeStep(S)) {
          if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 <= 0.8) {
            rtAction = 0;
          } else {
            rtAction = 1;
          }

          ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c = rtAction;
        } else {
          rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_c;
        }

        if (rtPrevAction != rtAction) {
          switch (rtPrevAction) {
           case 0:
            /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_DISABLE);

            /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_DISABLE);

            /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_DISABLE);

            /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_DISABLE);
            break;

           case 1:
            /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_DISABLE);

            /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_DISABLE);

            /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_DISABLE);

            /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_DISABLE);
            break;
          }
        }

        switch (rtAction) {
         case 0:
          if (rtAction != rtPrevAction) {
            /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 40, 0, SS_CALL_RTW_GENERATED_ENABLE);

            /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 41, 0, SS_CALL_RTW_GENERATED_ENABLE);

            /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 42, 0, SS_CALL_RTW_GENERATED_ENABLE);

            /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 43, 0, SS_CALL_RTW_GENERATED_ENABLE);
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_0_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1108, 60U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_1_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1109, 30U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_44_2_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1110[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_2_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1110[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_3_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1111[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_3_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1111[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_4_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1112[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_3_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_4_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1112[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_3_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_4_0[0] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1113;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_4_0[1] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1113;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_7_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1114[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_7_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1114[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_9_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1115[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_9_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1115[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_11_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1116[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_11_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1116[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_13_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1117[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_13_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1117[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_15_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1118[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_15_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1118[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_17_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1119[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_17_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1119[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_19_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1120[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_19_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1120[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_21_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1121[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_21_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1121[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_23_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1122[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_23_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1122[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_25_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1123[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_25_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1123[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_27_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1124[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_27_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1124[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_29_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1125[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_29_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1125[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_31_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1126[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_31_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1126[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_33_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1127[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_33_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1127[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_35_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1128[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_35_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1128[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_37_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1129[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_37_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1129[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_39_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1130[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_39_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1130[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_41_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1131[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_41_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1131[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_43_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1132[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_43_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1132[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_45_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1133[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_45_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1133[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_47_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1134[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_47_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1134[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_49_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1135[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_49_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1135[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_51_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1136[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_51_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1136[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_53_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1137[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_53_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1137[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_55_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1138[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_55_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1138[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_57_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1139[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_57_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1139[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_59_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1140[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_59_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1140[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_61_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1141[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_61_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1141[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_63_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1142[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_63_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1142[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_65_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1143, 30U *
                   sizeof(real_T));
          }

          tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_44_2_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_44_7_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_44_9_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_44_11_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_44_13_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_44_15_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_44_17_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_44_19_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_44_21_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_44_23_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_44_25_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_44_27_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_44_29_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_44_31_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_44_33_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_44_35_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_44_37_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_44_39_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_44_41_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_44_43_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_44_45_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_44_47_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_44_49_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_44_51_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_44_53_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_44_55_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_55_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_44_57_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_57_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_44_59_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_59_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_44_61_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_61_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_44_63_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_63_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_5_0[1];
          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_66_0[i] = tmp_f[i] + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_65_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_67_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1144 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_66_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_69_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1145;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_70_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_67_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_69_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_72_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_70_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1146;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_73_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1147;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_74_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_72_0[i] - ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_73_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_76_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1148, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_78_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1149, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_80_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1150, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_82_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1151, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_84_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1152, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_86_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1153, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_88_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1154, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_90_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1155, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_92_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1156, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_94_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1157, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_96_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1158, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_98_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1159, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_100_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1160, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_102_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1161, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_104_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1162, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_106_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1163, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_108_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1164, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_110_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1165, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_112_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1166, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_114_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1167, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_116_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1168, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_118_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1169, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_120_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1170, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_122_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1171, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_124_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1172, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_126_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1173, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_128_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1174, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_130_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1175, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_132_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1176, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_134_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1177, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_136_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1178, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_138_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1179, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_140_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1180, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_142_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1181, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_144_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1182, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_146_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1183, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_148_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1184, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_150_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1185, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_152_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1186, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_154_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1187, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_156_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1188, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_158_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1189, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_160_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1190, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_162_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1191, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_164_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1192, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_166_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1193, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_168_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1194, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_170_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1195, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_172_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1196, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_174_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1197, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_176_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1198, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_178_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1199, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_180_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1200, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_182_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1201, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_184_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1202, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_186_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1203, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_188_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1204, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_190_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1205, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_192_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1206, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_194_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1207, 60U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          tmp_18 = 0.0;
          tmp_19 = 0.0;
          tmp_1a = 0.0;
          tmp_1b = 0.0;
          tmp_1c = 0.0;
          tmp_1d = 0.0;
          tmp_1e = 0.0;
          tmp_1f = 0.0;
          tmp_1g = 0.0;
          tmp_1h = 0.0;
          tmp_1i = 0.0;
          tmp_1j = 0.0;
          tmp_1k = 0.0;
          tmp_1l = 0.0;
          tmp_1m = 0.0;
          tmp_1n = 0.0;
          tmp_1o = 0.0;
          tmp_1p = 0.0;
          tmp_1q = 0.0;
          tmp_1r = 0.0;
          for (i = 0; i < 30; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_1_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_76_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_44_78_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_44_80_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_44_82_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_44_84_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_44_86_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_44_88_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_44_90_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_44_92_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_44_94_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_44_96_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_44_98_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_44_100_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_44_102_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_44_104_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_44_106_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_44_108_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_44_110_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_44_112_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_44_114_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_44_116_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_44_118_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_44_120_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_44_122_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_44_124_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_44_126_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_44_128_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_44_130_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_44_132_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_44_134_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_44_136_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_44_138_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_44_140_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_44_142_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_44_144_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_44_146_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_44_148_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_44_150_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_44_152_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_44_154_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_44_156_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_44_158_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_44_160_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_44_162_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_44_164_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_44_166_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_44_168_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_44_170_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_44_172_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1i += ((BlockIO *) _ssGetBlockIO(S))->B_44_174_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1j += ((BlockIO *) _ssGetBlockIO(S))->B_44_176_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1k += ((BlockIO *) _ssGetBlockIO(S))->B_44_178_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1l += ((BlockIO *) _ssGetBlockIO(S))->B_44_180_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1m += ((BlockIO *) _ssGetBlockIO(S))->B_44_182_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1n += ((BlockIO *) _ssGetBlockIO(S))->B_44_184_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1o += ((BlockIO *) _ssGetBlockIO(S))->B_44_186_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1p += ((BlockIO *) _ssGetBlockIO(S))->B_44_188_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1q += ((BlockIO *) _ssGetBlockIO(S))->B_44_190_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
            tmp_1r += ((BlockIO *) _ssGetBlockIO(S))->B_44_192_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_74_0[i];
          }

          tmp_1s[0] = B_62_0_0;
          tmp_1s[1] = tmp_0;
          tmp_1s[2] = tmp_1;
          tmp_1s[3] = tmp_2;
          tmp_1s[4] = tmp_3;
          tmp_1s[5] = tmp_4;
          tmp_1s[6] = tmp_5;
          tmp_1s[7] = tmp_6;
          tmp_1s[8] = tmp_7;
          tmp_1s[9] = tmp_8;
          tmp_1s[10] = tmp_9;
          tmp_1s[11] = tmp_a;
          tmp_1s[12] = tmp_b;
          tmp_1s[13] = tmp_c;
          tmp_1s[14] = tmp_d;
          tmp_1s[15] = tmp_g;
          tmp_1s[16] = tmp_h;
          tmp_1s[17] = tmp_i;
          tmp_1s[18] = tmp_j;
          tmp_1s[19] = tmp_k;
          tmp_1s[20] = tmp_l;
          tmp_1s[21] = tmp_m;
          tmp_1s[22] = tmp_n;
          tmp_1s[23] = tmp_o;
          tmp_1s[24] = tmp_p;
          tmp_1s[25] = tmp_q;
          tmp_1s[26] = tmp_r;
          tmp_1s[27] = tmp_s;
          tmp_1s[28] = tmp_t;
          tmp_1s[29] = tmp_u;
          tmp_1s[30] = tmp_v;
          tmp_1s[31] = tmp_w;
          tmp_1s[32] = tmp_x;
          tmp_1s[33] = tmp_y;
          tmp_1s[34] = tmp_z;
          tmp_1s[35] = tmp_10;
          tmp_1s[36] = tmp_11;
          tmp_1s[37] = tmp_12;
          tmp_1s[38] = tmp_13;
          tmp_1s[39] = tmp_14;
          tmp_1s[40] = tmp_18;
          tmp_1s[41] = tmp_19;
          tmp_1s[42] = tmp_1a;
          tmp_1s[43] = tmp_1b;
          tmp_1s[44] = tmp_1c;
          tmp_1s[45] = tmp_1d;
          tmp_1s[46] = tmp_1e;
          tmp_1s[47] = tmp_1f;
          tmp_1s[48] = tmp_1g;
          tmp_1s[49] = tmp_1h;
          tmp_1s[50] = tmp_1i;
          tmp_1s[51] = tmp_1j;
          tmp_1s[52] = tmp_1k;
          tmp_1s[53] = tmp_1l;
          tmp_1s[54] = tmp_1m;
          tmp_1s[55] = tmp_1n;
          tmp_1s[56] = tmp_1o;
          tmp_1s[57] = tmp_1p;
          tmp_1s[58] = tmp_1q;
          tmp_1s[59] = tmp_1r;
          for (i = 0; i < 60; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_195_0[i] = tmp_1s[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_44_194_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_196_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1208 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_195_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_198_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1209;
          }

          for (i = 0; i < 60; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_199_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_196_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_198_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_201_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_199_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1210;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_202_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1211;
          }

          for (i = 0; i < 60; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_203_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_201_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_202_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_205_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1212;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 60; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_0_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_203_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_206_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_44_205_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_207_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_206_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1213;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_208_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1214 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_207_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_209_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_208_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1215;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_210_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_209_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1216 ? ((Parameters *) ssGetDefaultParam(S))->P_1216 : ((BlockIO
            *) _ssGetBlockIO(S))->B_44_209_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1217 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1217 : ((BlockIO *) _ssGetBlockIO(S))->B_44_209_0;

          /* Clock: '<S1242>/Clock' */
          ((BlockIO *) _ssGetBlockIO(S))->B_44_211_0 = ssGetT(S);
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_212_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1218, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 40, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_44_214_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_210_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_40_0_1;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_215_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1219, 45U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_216_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1220, 35U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_44_217_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1221[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_217_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1221[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_218_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1222[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_218_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1222[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_219_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1223[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_218_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_219_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1223[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_218_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_219_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1224;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_219_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1224;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_222_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1225[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_222_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1225[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_224_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1226[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_224_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1226[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_226_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1227[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_226_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1227[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_228_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1228[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_228_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1228[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_230_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1229[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_230_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1229[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_232_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1230[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_232_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1230[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_234_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1231[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_234_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1231[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_236_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1232[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_236_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1232[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_238_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1233[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_238_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1233[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_240_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1234[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_240_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1234[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_242_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1235[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_242_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1235[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_244_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1236[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_244_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1236[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_246_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1237[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_246_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1237[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_248_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1238[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_248_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1238[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_250_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1239[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_250_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1239[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_252_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1240[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_252_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1240[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_254_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1241[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_254_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1241[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_256_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1242[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_256_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1242[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_258_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1243[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_258_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1243[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_260_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1244[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_260_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1244[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_262_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1245[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_262_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1245[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_264_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1246[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_264_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1246[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_266_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1247[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_266_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1247[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_268_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1248[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_268_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1248[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_270_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1249[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_270_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1249[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_272_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1250[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_272_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1250[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_274_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1251[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_274_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1251[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_276_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1252[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_276_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1252[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_278_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1253[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_278_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1253[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_280_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1254[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_280_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1254[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_282_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1255[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_282_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1255[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_284_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1256[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_284_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1256[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_286_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1257[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_286_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1257[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_288_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1258[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_288_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1258[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_290_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1259, 35U *
                   sizeof(real_T));
          }

          tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_44_217_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_217_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_44_222_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_222_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_44_224_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_224_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_44_226_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_226_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_44_228_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_228_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_44_230_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_230_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_44_232_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_232_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_44_234_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_234_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_44_236_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_236_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_44_238_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_238_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_44_240_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_240_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_44_242_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_242_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_44_244_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_244_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_44_246_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_246_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_44_248_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_248_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_44_250_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_250_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_44_252_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_252_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_44_254_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_254_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_44_256_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_256_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_44_258_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_258_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_44_260_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_260_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_44_262_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_262_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_44_264_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_264_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_44_266_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_266_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_44_268_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_268_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_44_270_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_270_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_44_272_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_272_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_44_274_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_274_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_44_276_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_276_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_44_278_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_278_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_44_280_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_280_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_44_282_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_282_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_44_284_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_284_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_44_286_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_286_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_44_288_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_220_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_288_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_220_0[1];
          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_291_0[i] = tmp_1t[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_44_290_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_292_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1260 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_291_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_294_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1261;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_295_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_292_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_294_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_297_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_295_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1262;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_298_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1263;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_299_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_297_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_298_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_301_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1264, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_303_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1265, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_305_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1266, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_307_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1267, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_309_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1268, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_311_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1269, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_313_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1270, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_315_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1271, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_317_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1272, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_319_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1273, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_321_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1274, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_323_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1275, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_325_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1276, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_327_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1277, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_329_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1278, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_331_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1279, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_333_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1280, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_335_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1281, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_337_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1282, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_339_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1283, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_341_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1284, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_343_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1285, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_345_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1286, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_347_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1287, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_349_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1288, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_351_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1289, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_353_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1290, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_355_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1291, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_357_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1292, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_359_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1293, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_361_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1294, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_363_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1295, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_365_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1296, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_367_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1297, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_369_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1298, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_371_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1299, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_373_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1300, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_375_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1301, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_377_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1302, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_379_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1303, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_381_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1304, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_383_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1305, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_385_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1306, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_387_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1307, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_389_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1308, 45U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          tmp_18 = 0.0;
          tmp_19 = 0.0;
          tmp_1a = 0.0;
          tmp_1b = 0.0;
          tmp_1c = 0.0;
          for (i = 0; i < 35; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_216_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_301_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_44_303_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_44_305_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_44_307_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_44_309_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_44_311_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_44_313_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_44_315_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_44_317_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_44_319_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_44_321_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_44_323_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_44_325_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_44_327_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_44_329_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_44_331_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_44_333_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_44_335_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_44_337_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_44_339_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_44_341_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_44_343_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_44_345_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_44_347_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_44_349_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_44_351_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_44_353_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_44_355_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_44_357_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_44_359_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_44_361_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_44_363_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_44_365_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_44_367_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_44_369_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_44_371_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_44_373_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_44_375_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_44_377_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_44_379_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_44_381_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_44_383_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_44_385_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_44_387_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_299_0[i];
          }

          tmp_1u[0] = B_62_0_0;
          tmp_1u[1] = tmp_0;
          tmp_1u[2] = tmp_1;
          tmp_1u[3] = tmp_2;
          tmp_1u[4] = tmp_3;
          tmp_1u[5] = tmp_4;
          tmp_1u[6] = tmp_5;
          tmp_1u[7] = tmp_6;
          tmp_1u[8] = tmp_7;
          tmp_1u[9] = tmp_8;
          tmp_1u[10] = tmp_9;
          tmp_1u[11] = tmp_a;
          tmp_1u[12] = tmp_b;
          tmp_1u[13] = tmp_c;
          tmp_1u[14] = tmp_d;
          tmp_1u[15] = tmp_g;
          tmp_1u[16] = tmp_h;
          tmp_1u[17] = tmp_i;
          tmp_1u[18] = tmp_j;
          tmp_1u[19] = tmp_k;
          tmp_1u[20] = tmp_l;
          tmp_1u[21] = tmp_m;
          tmp_1u[22] = tmp_n;
          tmp_1u[23] = tmp_o;
          tmp_1u[24] = tmp_p;
          tmp_1u[25] = tmp_q;
          tmp_1u[26] = tmp_r;
          tmp_1u[27] = tmp_s;
          tmp_1u[28] = tmp_t;
          tmp_1u[29] = tmp_u;
          tmp_1u[30] = tmp_v;
          tmp_1u[31] = tmp_w;
          tmp_1u[32] = tmp_x;
          tmp_1u[33] = tmp_y;
          tmp_1u[34] = tmp_z;
          tmp_1u[35] = tmp_10;
          tmp_1u[36] = tmp_11;
          tmp_1u[37] = tmp_12;
          tmp_1u[38] = tmp_13;
          tmp_1u[39] = tmp_14;
          tmp_1u[40] = tmp_18;
          tmp_1u[41] = tmp_19;
          tmp_1u[42] = tmp_1a;
          tmp_1u[43] = tmp_1b;
          tmp_1u[44] = tmp_1c;
          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_390_0[i] = tmp_1u[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_44_389_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_391_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1309 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_390_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_393_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1310;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_394_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_391_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_393_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_396_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_394_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1311;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_397_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1312;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_398_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_396_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_397_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_400_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1313;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 45; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_215_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_44_398_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_401_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_44_400_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_402_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_401_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1314;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_403_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1315 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_402_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_404_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_403_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1316;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_405_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_404_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1317 ? ((Parameters *) ssGetDefaultParam(S))->P_1317 : ((BlockIO
            *) _ssGetBlockIO(S))->B_44_404_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1318 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1318 : ((BlockIO *) _ssGetBlockIO(S))->B_44_404_0;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_406_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1319, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 41, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_44_408_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_405_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_41_0_1;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_409_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1320, 50U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_410_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1321, 35U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_44_411_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1322[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_411_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1322[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_412_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1323[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_412_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1323[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_413_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1324[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_412_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_413_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1324[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_412_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_413_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1325;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_413_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1325;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_416_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1326[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_416_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1326[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_418_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1327[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_418_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1327[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_420_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1328[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_420_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1328[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_422_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1329[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_422_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1329[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_424_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1330[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_424_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1330[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_426_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1331[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_426_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1331[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_428_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1332[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_428_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1332[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_430_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1333[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_430_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1333[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_432_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1334[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_432_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1334[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_434_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1335[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_434_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1335[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_436_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1336[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_436_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1336[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_438_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1337[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_438_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1337[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_440_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1338[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_440_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1338[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_442_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1339[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_442_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1339[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_444_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1340[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_444_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1340[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_446_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1341[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_446_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1341[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_448_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1342[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_448_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1342[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_450_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1343[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_450_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1343[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_452_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1344[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_452_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1344[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_454_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1345[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_454_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1345[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_456_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1346[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_456_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1346[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_458_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1347[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_458_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1347[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_460_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1348[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_460_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1348[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_462_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1349[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_462_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1349[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_464_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1350[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_464_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1350[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_466_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1351[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_466_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1351[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_468_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1352[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_468_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1352[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_470_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1353[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_470_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1353[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_472_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1354[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_472_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1354[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_474_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1355[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_474_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1355[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_476_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1356[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_476_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1356[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_478_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1357[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_478_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1357[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_480_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1358[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_480_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1358[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_482_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1359[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_482_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1359[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_484_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1360, 35U *
                   sizeof(real_T));
          }

          tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_44_411_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_411_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_44_416_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_416_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_44_418_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_418_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_44_420_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_420_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_44_422_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_422_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_44_424_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_424_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_44_426_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_426_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_44_428_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_428_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_44_430_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_430_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_44_432_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_432_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_44_434_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_434_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_44_436_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_436_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_44_438_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_438_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_44_440_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_440_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_44_442_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_442_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_44_444_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_444_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_44_446_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_446_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_44_448_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_448_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_44_450_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_450_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_44_452_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_452_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_44_454_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_454_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_44_456_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_456_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_44_458_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_458_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_44_460_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_460_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_44_462_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_462_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_44_464_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_464_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_44_466_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_466_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_44_468_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_468_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_44_470_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_470_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_44_472_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_472_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_44_474_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_474_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_44_476_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_476_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_44_478_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_478_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_44_480_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_480_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_44_482_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_44_414_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_44_482_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_414_0[1];
          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_485_0[i] = tmp_1t[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_44_484_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_486_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1361 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_485_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_488_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1362;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_489_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_486_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_488_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_491_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_489_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1363;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_492_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1364;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_493_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_491_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_492_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_495_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1365, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_497_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1366, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_499_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1367, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_501_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1368, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_503_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1369, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_505_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1370, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_507_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1371, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_509_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1372, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_511_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1373, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_513_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1374, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_515_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1375, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_517_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1376, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_519_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1377, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_521_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1378, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_523_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1379, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_525_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1380, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_527_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1381, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_529_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1382, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_531_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1383, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_533_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1384, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_535_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1385, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_537_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1386, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_539_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1387, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_541_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1388, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_543_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1389, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_545_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1390, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_547_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1391, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_549_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1392, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_551_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1393, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_553_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1394, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_555_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1395, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_557_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1396, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_559_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1397, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_561_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1398, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_563_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1399, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_565_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1400, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_567_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1401, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_569_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1402, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_571_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1403, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_573_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1404, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_575_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1405, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_577_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1406, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_579_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1407, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_581_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1408, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_583_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1409, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_585_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1410, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_587_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1411, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_589_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1412, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_591_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1413, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_593_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1414, 50U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          tmp_18 = 0.0;
          tmp_19 = 0.0;
          tmp_1a = 0.0;
          tmp_1b = 0.0;
          tmp_1c = 0.0;
          tmp_1d = 0.0;
          tmp_1e = 0.0;
          tmp_1f = 0.0;
          tmp_1g = 0.0;
          tmp_1h = 0.0;
          for (i = 0; i < 35; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_410_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_495_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_44_497_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_44_499_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_44_501_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_44_503_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_44_505_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_44_507_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_44_509_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_44_511_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_44_513_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_44_515_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_44_517_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_44_519_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_44_521_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_44_523_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_44_525_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_44_527_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_44_529_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_44_531_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_44_533_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_44_535_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_44_537_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_44_539_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_44_541_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_44_543_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_44_545_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_44_547_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_44_549_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_44_551_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_44_553_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_44_555_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_44_557_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_44_559_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_44_561_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_44_563_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_44_565_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_44_567_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_44_569_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_44_571_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_44_573_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_44_575_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_44_577_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_44_579_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_44_581_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_44_583_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_44_585_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_44_587_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_44_589_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_44_591_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_493_0[i];
          }

          tmp_21[0] = B_62_0_0;
          tmp_21[1] = tmp_0;
          tmp_21[2] = tmp_1;
          tmp_21[3] = tmp_2;
          tmp_21[4] = tmp_3;
          tmp_21[5] = tmp_4;
          tmp_21[6] = tmp_5;
          tmp_21[7] = tmp_6;
          tmp_21[8] = tmp_7;
          tmp_21[9] = tmp_8;
          tmp_21[10] = tmp_9;
          tmp_21[11] = tmp_a;
          tmp_21[12] = tmp_b;
          tmp_21[13] = tmp_c;
          tmp_21[14] = tmp_d;
          tmp_21[15] = tmp_g;
          tmp_21[16] = tmp_h;
          tmp_21[17] = tmp_i;
          tmp_21[18] = tmp_j;
          tmp_21[19] = tmp_k;
          tmp_21[20] = tmp_l;
          tmp_21[21] = tmp_m;
          tmp_21[22] = tmp_n;
          tmp_21[23] = tmp_o;
          tmp_21[24] = tmp_p;
          tmp_21[25] = tmp_q;
          tmp_21[26] = tmp_r;
          tmp_21[27] = tmp_s;
          tmp_21[28] = tmp_t;
          tmp_21[29] = tmp_u;
          tmp_21[30] = tmp_v;
          tmp_21[31] = tmp_w;
          tmp_21[32] = tmp_x;
          tmp_21[33] = tmp_y;
          tmp_21[34] = tmp_z;
          tmp_21[35] = tmp_10;
          tmp_21[36] = tmp_11;
          tmp_21[37] = tmp_12;
          tmp_21[38] = tmp_13;
          tmp_21[39] = tmp_14;
          tmp_21[40] = tmp_18;
          tmp_21[41] = tmp_19;
          tmp_21[42] = tmp_1a;
          tmp_21[43] = tmp_1b;
          tmp_21[44] = tmp_1c;
          tmp_21[45] = tmp_1d;
          tmp_21[46] = tmp_1e;
          tmp_21[47] = tmp_1f;
          tmp_21[48] = tmp_1g;
          tmp_21[49] = tmp_1h;
          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_594_0[i] = tmp_21[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_44_593_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_595_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1415 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_594_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_597_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1416;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_598_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_595_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_597_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_600_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_598_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1417;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_601_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1418;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_602_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_600_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_601_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_604_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1419;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 50; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_409_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_44_602_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_605_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_44_604_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_606_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_605_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1420;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_607_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1421 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_606_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_608_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_607_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1422;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_609_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_608_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1423 ? ((Parameters *) ssGetDefaultParam(S))->P_1423 : ((BlockIO
            *) _ssGetBlockIO(S))->B_44_608_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1424 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1424 : ((BlockIO *) _ssGetBlockIO(S))->B_44_608_0;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_610_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1425, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 42, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_44_612_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_609_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_42_0_1;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_613_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1426, 50U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_614_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1427, 30U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_44_615_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1428[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_615_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1428[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_616_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1429[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_616_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1429[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_617_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1430[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_616_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_617_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1430[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_616_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_617_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1431;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_617_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1431;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_620_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1432[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_620_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1432[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_622_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1433[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_622_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1433[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_624_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1434[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_624_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1434[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_626_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1435[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_626_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1435[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_628_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1436[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_628_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1436[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_630_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1437[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_630_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1437[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_632_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1438[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_632_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1438[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_634_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1439[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_634_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1439[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_636_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1440[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_636_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1440[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_638_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1441[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_638_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1441[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_640_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1442[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_640_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1442[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_642_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1443[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_642_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1443[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_644_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1444[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_644_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1444[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_646_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1445[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_646_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1445[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_648_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1446[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_648_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1446[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_650_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1447[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_650_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1447[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_652_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1448[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_652_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1448[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_654_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1449[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_654_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1449[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_656_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1450[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_656_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1450[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_658_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1451[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_658_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1451[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_660_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1452[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_660_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1452[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_662_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1453[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_662_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1453[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_664_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1454[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_664_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1454[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_666_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1455[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_666_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1455[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_668_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1456[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_668_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1456[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_670_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1457[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_670_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1457[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_672_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1458[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_672_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1458[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_674_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1459[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_674_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1459[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_676_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1460[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_676_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1460[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_678_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1461, 30U *
                   sizeof(real_T));
          }

          tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_44_615_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_615_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_44_620_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_620_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_44_622_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_622_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_44_624_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_624_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_44_626_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_626_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_44_628_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_628_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_44_630_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_630_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_44_632_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_632_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_44_634_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_634_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_44_636_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_636_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_44_638_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_638_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_44_640_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_640_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_44_642_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_642_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_44_644_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_644_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_44_646_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_646_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_44_648_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_648_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_44_650_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_650_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_44_652_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_652_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_44_654_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_654_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_44_656_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_656_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_44_658_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_658_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_44_660_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_660_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_44_662_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_662_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_44_664_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_664_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_44_666_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_666_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_44_668_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_668_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_44_670_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_670_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_44_672_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_672_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_44_674_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_674_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_44_676_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_44_618_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_676_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_44_618_0[1];
          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_679_0[i] = tmp_f[i] + ((BlockIO
              *) _ssGetBlockIO(S))->B_44_678_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_680_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1462 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_679_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_682_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1463;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_683_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_680_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_682_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_685_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_683_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1464;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_686_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1465;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_687_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_685_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_686_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_689_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1466, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_691_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1467, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_693_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1468, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_695_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1469, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_697_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1470, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_699_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1471, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_701_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1472, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_703_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1473, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_705_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1474, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_707_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1475, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_709_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1476, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_711_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1477, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_713_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1478, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_715_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1479, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_717_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1480, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_719_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1481, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_721_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1482, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_723_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1483, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_725_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1484, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_727_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1485, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_729_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1486, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_731_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1487, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_733_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1488, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_735_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1489, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_737_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1490, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_739_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1491, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_741_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1492, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_743_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1493, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_745_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1494, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_747_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1495, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_749_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1496, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_751_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1497, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_753_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1498, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_755_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1499, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_757_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1500, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_759_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1501, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_761_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1502, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_763_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1503, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_765_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1504, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_767_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1505, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_769_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1506, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_771_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1507, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_773_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1508, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_775_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1509, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_777_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1510, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_779_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1511, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_781_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1512, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_783_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1513, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_785_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1514, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_787_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1515, 50U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          tmp_18 = 0.0;
          tmp_19 = 0.0;
          tmp_1a = 0.0;
          tmp_1b = 0.0;
          tmp_1c = 0.0;
          tmp_1d = 0.0;
          tmp_1e = 0.0;
          tmp_1f = 0.0;
          tmp_1g = 0.0;
          tmp_1h = 0.0;
          for (i = 0; i < 30; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_614_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_689_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_44_691_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_44_693_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_44_695_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_44_697_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_44_699_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_44_701_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_44_703_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_44_705_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_44_707_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_44_709_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_44_711_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_44_713_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_44_715_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_44_717_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_44_719_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_44_721_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_44_723_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_44_725_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_44_727_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_44_729_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_44_731_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_44_733_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_44_735_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_44_737_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_44_739_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_44_741_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_44_743_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_44_745_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_44_747_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_44_749_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_44_751_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_44_753_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_44_755_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_44_757_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_44_759_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_44_761_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_44_763_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_44_765_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_44_767_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_44_769_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_44_771_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_44_773_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_44_775_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_44_777_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_44_779_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_44_781_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_44_783_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_44_785_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_44_687_0[i];
          }

          tmp_21[0] = B_62_0_0;
          tmp_21[1] = tmp_0;
          tmp_21[2] = tmp_1;
          tmp_21[3] = tmp_2;
          tmp_21[4] = tmp_3;
          tmp_21[5] = tmp_4;
          tmp_21[6] = tmp_5;
          tmp_21[7] = tmp_6;
          tmp_21[8] = tmp_7;
          tmp_21[9] = tmp_8;
          tmp_21[10] = tmp_9;
          tmp_21[11] = tmp_a;
          tmp_21[12] = tmp_b;
          tmp_21[13] = tmp_c;
          tmp_21[14] = tmp_d;
          tmp_21[15] = tmp_g;
          tmp_21[16] = tmp_h;
          tmp_21[17] = tmp_i;
          tmp_21[18] = tmp_j;
          tmp_21[19] = tmp_k;
          tmp_21[20] = tmp_l;
          tmp_21[21] = tmp_m;
          tmp_21[22] = tmp_n;
          tmp_21[23] = tmp_o;
          tmp_21[24] = tmp_p;
          tmp_21[25] = tmp_q;
          tmp_21[26] = tmp_r;
          tmp_21[27] = tmp_s;
          tmp_21[28] = tmp_t;
          tmp_21[29] = tmp_u;
          tmp_21[30] = tmp_v;
          tmp_21[31] = tmp_w;
          tmp_21[32] = tmp_x;
          tmp_21[33] = tmp_y;
          tmp_21[34] = tmp_z;
          tmp_21[35] = tmp_10;
          tmp_21[36] = tmp_11;
          tmp_21[37] = tmp_12;
          tmp_21[38] = tmp_13;
          tmp_21[39] = tmp_14;
          tmp_21[40] = tmp_18;
          tmp_21[41] = tmp_19;
          tmp_21[42] = tmp_1a;
          tmp_21[43] = tmp_1b;
          tmp_21[44] = tmp_1c;
          tmp_21[45] = tmp_1d;
          tmp_21[46] = tmp_1e;
          tmp_21[47] = tmp_1f;
          tmp_21[48] = tmp_1g;
          tmp_21[49] = tmp_1h;
          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_788_0[i] = tmp_21[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_44_787_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_44_789_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1516 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_44_788_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_791_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1517;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_792_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_44_789_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_44_791_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_44_794_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_44_792_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1518;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_795_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1519;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_796_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_44_794_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_44_795_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_44_798_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1520;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 50; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_44_613_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_44_796_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_44_799_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_44_798_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_800_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_799_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1521;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_801_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1522 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_800_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_802_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_801_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1523;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_803_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_802_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1524 ? ((Parameters *) ssGetDefaultParam(S))->P_1524 : ((BlockIO
            *) _ssGetBlockIO(S))->B_44_802_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1525 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1525 : ((BlockIO *) _ssGetBlockIO(S))->B_44_802_0;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_44_804_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1526, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 43, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_44_806_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_44_803_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_43_0_1;
          ((BlockIO *) _ssGetBlockIO(S))->B_44_807_0 = ((((BlockIO *)
            _ssGetBlockIO(S))->B_44_214_0 + ((BlockIO *) _ssGetBlockIO(S))
            ->B_44_408_0) + ((BlockIO *) _ssGetBlockIO(S))->B_44_612_0) +
            ((BlockIO *) _ssGetBlockIO(S))->B_44_806_0;
          if (ssIsSampleHit(S, 1, 0)) {
            /* Scope: '<S1242>/Scope' */
            /* Call into Simulink for Scope */
            ssCallAccelRunBlock(S, 44, 808, SS_CALL_MDL_OUTPUTS);
          }

          if (ssIsMajorTimeStep(S)) {
            srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder08_SubsysRanBC);
          }
          break;

         case 1:
          if (rtAction != rtPrevAction) {
            /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 45, 0, SS_CALL_RTW_GENERATED_ENABLE);

            /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 46, 0, SS_CALL_RTW_GENERATED_ENABLE);

            /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 47, 0, SS_CALL_RTW_GENERATED_ENABLE);

            /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */

            /* Call into Simulink for MEX-version of S-function */
            ssCallAccelRunBlock(S, 48, 0, SS_CALL_RTW_GENERATED_ENABLE);
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_0_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1527, 40U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_1_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1528, 25U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_49_2_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1529[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_2_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1529[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_3_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1530[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_3_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1530[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_4_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1531[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_3_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_4_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1531[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_3_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_4_0[0] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1532;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_4_0[1] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1532;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_7_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1533[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_7_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1533[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_9_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1534[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_9_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1534[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_11_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1535[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_11_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1535[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_13_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1536[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_13_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1536[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_15_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1537[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_15_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1537[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_17_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1538[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_17_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1538[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_19_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1539[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_19_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1539[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_21_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1540[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_21_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1540[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_23_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1541[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_23_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1541[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_25_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1542[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_25_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1542[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_27_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1543[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_27_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1543[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_29_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1544[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_29_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1544[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_31_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1545[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_31_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1545[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_33_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1546[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_33_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1546[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_35_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1547[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_35_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1547[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_37_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1548[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_37_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1548[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_39_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1549[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_39_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1549[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_41_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1550[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_41_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1550[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_43_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1551[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_43_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1551[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_45_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1552[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_45_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1552[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_47_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1553[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_47_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1553[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_49_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1554[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_49_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1554[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_51_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1555[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_51_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1555[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_53_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1556[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_53_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1556[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_55_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1557, 25U *
                   sizeof(real_T));
          }

          tmp_22[0] = ((BlockIO *) _ssGetBlockIO(S))->B_49_2_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[1] = ((BlockIO *) _ssGetBlockIO(S))->B_49_7_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[2] = ((BlockIO *) _ssGetBlockIO(S))->B_49_9_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[3] = ((BlockIO *) _ssGetBlockIO(S))->B_49_11_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[4] = ((BlockIO *) _ssGetBlockIO(S))->B_49_13_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[5] = ((BlockIO *) _ssGetBlockIO(S))->B_49_15_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[6] = ((BlockIO *) _ssGetBlockIO(S))->B_49_17_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[7] = ((BlockIO *) _ssGetBlockIO(S))->B_49_19_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[8] = ((BlockIO *) _ssGetBlockIO(S))->B_49_21_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[9] = ((BlockIO *) _ssGetBlockIO(S))->B_49_23_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[10] = ((BlockIO *) _ssGetBlockIO(S))->B_49_25_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[11] = ((BlockIO *) _ssGetBlockIO(S))->B_49_27_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[12] = ((BlockIO *) _ssGetBlockIO(S))->B_49_29_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[13] = ((BlockIO *) _ssGetBlockIO(S))->B_49_31_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[14] = ((BlockIO *) _ssGetBlockIO(S))->B_49_33_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[15] = ((BlockIO *) _ssGetBlockIO(S))->B_49_35_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[16] = ((BlockIO *) _ssGetBlockIO(S))->B_49_37_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[17] = ((BlockIO *) _ssGetBlockIO(S))->B_49_39_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[18] = ((BlockIO *) _ssGetBlockIO(S))->B_49_41_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[19] = ((BlockIO *) _ssGetBlockIO(S))->B_49_43_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[20] = ((BlockIO *) _ssGetBlockIO(S))->B_49_45_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[21] = ((BlockIO *) _ssGetBlockIO(S))->B_49_47_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[22] = ((BlockIO *) _ssGetBlockIO(S))->B_49_49_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[23] = ((BlockIO *) _ssGetBlockIO(S))->B_49_51_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          tmp_22[24] = ((BlockIO *) _ssGetBlockIO(S))->B_49_53_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_5_0[1];
          for (i = 0; i < 25; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_56_0[i] = tmp_22[i] + ((BlockIO
              *) _ssGetBlockIO(S))->B_49_55_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_57_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1558 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_56_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_59_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1559;
          }

          for (i = 0; i < 25; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_60_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_57_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_59_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_62_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_60_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1560;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_63_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1561;
          }

          for (i = 0; i < 25; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_64_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_62_0[i] - ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_63_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_66_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1562, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_68_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1563, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_70_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1564, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_72_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1565, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_74_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1566, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_76_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1567, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_78_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1568, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_80_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1569, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_82_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1570, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_84_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1571, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_86_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1572, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_88_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1573, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_90_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1574, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_92_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1575, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_94_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1576, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_96_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1577, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_98_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1578, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_100_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1579, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_102_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1580, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_104_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1581, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_106_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1582, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_108_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1583, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_110_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1584, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_112_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1585, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_114_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1586, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_116_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1587, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_118_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1588, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_120_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1589, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_122_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1590, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_124_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1591, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_126_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1592, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_128_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1593, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_130_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1594, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_132_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1595, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_134_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1596, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_136_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1597, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_138_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1598, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_140_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1599, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_142_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1600, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_144_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1601, 40U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          for (i = 0; i < 25; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_1_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_66_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_49_68_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_49_70_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_49_72_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_49_74_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_49_76_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_49_78_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_49_80_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_49_82_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_49_84_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_49_86_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_49_88_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_49_90_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_49_92_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_49_94_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_49_96_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_49_98_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_49_100_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_49_102_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_49_104_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_49_106_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_49_108_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_49_110_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_49_112_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_49_114_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_49_116_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_49_118_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_49_120_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_49_122_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_49_124_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_49_126_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_49_128_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_49_130_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_49_132_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_49_134_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_49_136_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_49_138_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_49_140_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_49_142_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_64_0[i];
          }

          tmp_15[0] = B_62_0_0;
          tmp_15[1] = tmp_0;
          tmp_15[2] = tmp_1;
          tmp_15[3] = tmp_2;
          tmp_15[4] = tmp_3;
          tmp_15[5] = tmp_4;
          tmp_15[6] = tmp_5;
          tmp_15[7] = tmp_6;
          tmp_15[8] = tmp_7;
          tmp_15[9] = tmp_8;
          tmp_15[10] = tmp_9;
          tmp_15[11] = tmp_a;
          tmp_15[12] = tmp_b;
          tmp_15[13] = tmp_c;
          tmp_15[14] = tmp_d;
          tmp_15[15] = tmp_g;
          tmp_15[16] = tmp_h;
          tmp_15[17] = tmp_i;
          tmp_15[18] = tmp_j;
          tmp_15[19] = tmp_k;
          tmp_15[20] = tmp_l;
          tmp_15[21] = tmp_m;
          tmp_15[22] = tmp_n;
          tmp_15[23] = tmp_o;
          tmp_15[24] = tmp_p;
          tmp_15[25] = tmp_q;
          tmp_15[26] = tmp_r;
          tmp_15[27] = tmp_s;
          tmp_15[28] = tmp_t;
          tmp_15[29] = tmp_u;
          tmp_15[30] = tmp_v;
          tmp_15[31] = tmp_w;
          tmp_15[32] = tmp_x;
          tmp_15[33] = tmp_y;
          tmp_15[34] = tmp_z;
          tmp_15[35] = tmp_10;
          tmp_15[36] = tmp_11;
          tmp_15[37] = tmp_12;
          tmp_15[38] = tmp_13;
          tmp_15[39] = tmp_14;
          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_145_0[i] = tmp_15[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_49_144_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_146_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1602 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_145_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_148_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1603;
          }

          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_149_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_146_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_148_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_152_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1604;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 40; i++) {
            B_62_0_0 += 1.0 / ((BlockIO *) _ssGetBlockIO(S))->B_49_149_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_0_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_153_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_49_152_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_154_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_153_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1605;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_155_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1606 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_154_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_156_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_155_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1607;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_157_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_156_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1608 ? ((Parameters *) ssGetDefaultParam(S))->P_1608 : ((BlockIO
            *) _ssGetBlockIO(S))->B_49_156_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1609 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1609 : ((BlockIO *) _ssGetBlockIO(S))->B_49_156_0;

          /* Clock: '<S1243>/Clock' */
          ((BlockIO *) _ssGetBlockIO(S))->B_49_158_0 = ssGetT(S);
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_159_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1610, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 45, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_49_161_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_157_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_45_0_1;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_162_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1611, 45U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_163_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1612, 35U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_49_164_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1613[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_164_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1613[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_165_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1614[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_165_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1614[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_166_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1615[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_165_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_166_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1615[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_165_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_166_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1616;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_166_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1616;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_169_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1617[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_169_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1617[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_171_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1618[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_171_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1618[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_173_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1619[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_173_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1619[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_175_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1620[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_175_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1620[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_177_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1621[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_177_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1621[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_179_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1622[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_179_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1622[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_181_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1623[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_181_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1623[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_183_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1624[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_183_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1624[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_185_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1625[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_185_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1625[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_187_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1626[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_187_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1626[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_189_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1627[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_189_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1627[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_191_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1628[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_191_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1628[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_193_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1629[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_193_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1629[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_195_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1630[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_195_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1630[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_197_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1631[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_197_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1631[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_199_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1632[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_199_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1632[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_201_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1633[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_201_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1633[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_203_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1634[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_203_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1634[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_205_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1635[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_205_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1635[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_207_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1636[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_207_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1636[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_209_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1637[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_209_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1637[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_211_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1638[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_211_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1638[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_213_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1639[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_213_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1639[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_215_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1640[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_215_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1640[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_217_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1641[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_217_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1641[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_219_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1642[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_219_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1642[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_221_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1643[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_221_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1643[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_223_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1644[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_223_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1644[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_225_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1645[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_225_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1645[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_227_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1646[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_227_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1646[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_229_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1647[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_229_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1647[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_231_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1648[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_231_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1648[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_233_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1649[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_233_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1649[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_235_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1650[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_235_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1650[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_237_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1651, 35U *
                   sizeof(real_T));
          }

          tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_49_164_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_164_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_49_169_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_169_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_49_171_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_171_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_49_173_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_173_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_49_175_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_175_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_49_177_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_177_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_49_179_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_179_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_49_181_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_181_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_49_183_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_183_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_49_185_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_185_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_49_187_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_187_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_49_189_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_189_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_49_191_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_191_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_49_193_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_193_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_49_195_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_195_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_49_197_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_197_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_49_199_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_199_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_49_201_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_201_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_49_203_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_203_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_49_205_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_205_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_49_207_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_207_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_49_209_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_209_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_49_211_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_211_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_49_213_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_213_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_49_215_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_215_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_49_217_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_217_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_49_219_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_219_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_49_221_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_221_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_49_223_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_223_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_49_225_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_225_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_49_227_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_227_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_49_229_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_229_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_49_231_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_231_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_49_233_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_233_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_49_235_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_167_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_235_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_167_0[1];
          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_238_0[i] = tmp_1t[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_49_237_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_239_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1652 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_238_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_241_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1653;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_242_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_239_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_241_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_244_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_242_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1654;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_245_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1655;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_246_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_244_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_49_245_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_248_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1656, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_250_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1657, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_252_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1658, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_254_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1659, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_256_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1660, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_258_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1661, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_260_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1662, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_262_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1663, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_264_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1664, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_266_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1665, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_268_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1666, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_270_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1667, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_272_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1668, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_274_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1669, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_276_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1670, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_278_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1671, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_280_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1672, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_282_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1673, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_284_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1674, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_286_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1675, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_288_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1676, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_290_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1677, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_292_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1678, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_294_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1679, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_296_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1680, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_298_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1681, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_300_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1682, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_302_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1683, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_304_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1684, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_306_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1685, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_308_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1686, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_310_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1687, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_312_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1688, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_314_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1689, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_316_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1690, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_318_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1691, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_320_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1692, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_322_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1693, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_324_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1694, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_326_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1695, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_328_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1696, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_330_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1697, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_332_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1698, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_334_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1699, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_336_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1700, 45U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          tmp_18 = 0.0;
          tmp_19 = 0.0;
          tmp_1a = 0.0;
          tmp_1b = 0.0;
          tmp_1c = 0.0;
          for (i = 0; i < 35; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_163_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_248_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_49_250_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_49_252_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_49_254_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_49_256_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_49_258_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_49_260_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_49_262_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_49_264_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_49_266_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_49_268_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_49_270_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_49_272_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_49_274_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_49_276_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_49_278_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_49_280_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_49_282_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_49_284_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_49_286_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_49_288_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_49_290_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_49_292_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_49_294_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_49_296_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_49_298_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_49_300_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_49_302_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_49_304_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_49_306_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_49_308_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_49_310_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_49_312_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_49_314_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_49_316_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_49_318_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_49_320_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_49_322_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_49_324_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_49_326_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_49_328_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_49_330_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_49_332_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_49_334_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_246_0[i];
          }

          tmp_1u[0] = B_62_0_0;
          tmp_1u[1] = tmp_0;
          tmp_1u[2] = tmp_1;
          tmp_1u[3] = tmp_2;
          tmp_1u[4] = tmp_3;
          tmp_1u[5] = tmp_4;
          tmp_1u[6] = tmp_5;
          tmp_1u[7] = tmp_6;
          tmp_1u[8] = tmp_7;
          tmp_1u[9] = tmp_8;
          tmp_1u[10] = tmp_9;
          tmp_1u[11] = tmp_a;
          tmp_1u[12] = tmp_b;
          tmp_1u[13] = tmp_c;
          tmp_1u[14] = tmp_d;
          tmp_1u[15] = tmp_g;
          tmp_1u[16] = tmp_h;
          tmp_1u[17] = tmp_i;
          tmp_1u[18] = tmp_j;
          tmp_1u[19] = tmp_k;
          tmp_1u[20] = tmp_l;
          tmp_1u[21] = tmp_m;
          tmp_1u[22] = tmp_n;
          tmp_1u[23] = tmp_o;
          tmp_1u[24] = tmp_p;
          tmp_1u[25] = tmp_q;
          tmp_1u[26] = tmp_r;
          tmp_1u[27] = tmp_s;
          tmp_1u[28] = tmp_t;
          tmp_1u[29] = tmp_u;
          tmp_1u[30] = tmp_v;
          tmp_1u[31] = tmp_w;
          tmp_1u[32] = tmp_x;
          tmp_1u[33] = tmp_y;
          tmp_1u[34] = tmp_z;
          tmp_1u[35] = tmp_10;
          tmp_1u[36] = tmp_11;
          tmp_1u[37] = tmp_12;
          tmp_1u[38] = tmp_13;
          tmp_1u[39] = tmp_14;
          tmp_1u[40] = tmp_18;
          tmp_1u[41] = tmp_19;
          tmp_1u[42] = tmp_1a;
          tmp_1u[43] = tmp_1b;
          tmp_1u[44] = tmp_1c;
          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_337_0[i] = tmp_1u[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_49_336_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_338_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1701 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_337_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_340_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1702;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_341_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_338_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_340_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_343_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_341_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1703;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_344_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1704;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_345_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_343_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_49_344_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_347_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1705;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 45; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_162_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_345_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_348_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_49_347_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_349_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_348_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1706;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_350_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1707 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_349_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_351_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_350_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1708;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_352_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_351_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1709 ? ((Parameters *) ssGetDefaultParam(S))->P_1709 : ((BlockIO
            *) _ssGetBlockIO(S))->B_49_351_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1710 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1710 : ((BlockIO *) _ssGetBlockIO(S))->B_49_351_0;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_353_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1711, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 46, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_49_355_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_352_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_46_0_1;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_356_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1712, 40U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_357_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1713, 30U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_49_358_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1714[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_358_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1714[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_359_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1715[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_359_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1715[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_360_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1716[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_359_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_360_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1716[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_359_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_360_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1717;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_360_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1717;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_363_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1718[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_363_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1718[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_365_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1719[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_365_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1719[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_367_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1720[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_367_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1720[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_369_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1721[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_369_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1721[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_371_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1722[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_371_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1722[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_373_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1723[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_373_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1723[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_375_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1724[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_375_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1724[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_377_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1725[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_377_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1725[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_379_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1726[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_379_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1726[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_381_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1727[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_381_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1727[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_383_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1728[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_383_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1728[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_385_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1729[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_385_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1729[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_387_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1730[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_387_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1730[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_389_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1731[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_389_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1731[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_391_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1732[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_391_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1732[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_393_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1733[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_393_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1733[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_395_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1734[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_395_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1734[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_397_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1735[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_397_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1735[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_399_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1736[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_399_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1736[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_401_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1737[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_401_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1737[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_403_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1738[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_403_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1738[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_405_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1739[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_405_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1739[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_407_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1740[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_407_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1740[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_409_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1741[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_409_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1741[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_411_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1742[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_411_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1742[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_413_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1743[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_413_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1743[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_415_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1744[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_415_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1744[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_417_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1745[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_417_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1745[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_419_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1746[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_419_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1746[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_421_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1747, 30U *
                   sizeof(real_T));
          }

          tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_49_358_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_358_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_49_363_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_363_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_49_365_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_365_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_49_367_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_367_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_49_369_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_369_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_49_371_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_371_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_49_373_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_373_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_49_375_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_375_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_49_377_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_377_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_49_379_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_379_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_49_381_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_381_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_49_383_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_383_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_49_385_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_385_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_49_387_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_387_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_49_389_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_389_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_49_391_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_391_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_49_393_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_393_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_49_395_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_395_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_49_397_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_397_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_49_399_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_399_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_49_401_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_401_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_49_403_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_403_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_49_405_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_405_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_49_407_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_407_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_49_409_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_409_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_49_411_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_411_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_49_413_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_413_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_49_415_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_415_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_49_417_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_417_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_49_419_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_361_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_419_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_361_0[1];
          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_422_0[i] = tmp_f[i] + ((BlockIO
              *) _ssGetBlockIO(S))->B_49_421_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_423_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1748 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_422_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_425_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1749;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_426_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_423_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_425_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_428_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_426_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1750;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_429_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1751;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_430_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_428_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_49_429_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_432_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1752, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_434_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1753, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_436_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1754, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_438_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1755, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_440_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1756, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_442_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1757, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_444_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1758, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_446_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1759, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_448_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1760, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_450_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1761, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_452_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1762, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_454_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1763, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_456_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1764, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_458_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1765, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_460_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1766, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_462_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1767, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_464_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1768, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_466_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1769, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_468_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1770, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_470_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1771, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_472_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1772, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_474_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1773, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_476_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1774, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_478_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1775, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_480_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1776, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_482_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1777, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_484_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1778, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_486_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1779, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_488_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1780, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_490_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1781, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_492_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1782, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_494_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1783, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_496_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1784, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_498_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1785, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_500_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1786, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_502_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1787, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_504_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1788, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_506_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1789, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_508_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1790, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_510_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1791, 40U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          for (i = 0; i < 30; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_357_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_432_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_49_434_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_49_436_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_49_438_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_49_440_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_49_442_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_49_444_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_49_446_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_49_448_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_49_450_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_49_452_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_49_454_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_49_456_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_49_458_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_49_460_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_49_462_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_49_464_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_49_466_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_49_468_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_49_470_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_49_472_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_49_474_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_49_476_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_49_478_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_49_480_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_49_482_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_49_484_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_49_486_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_49_488_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_49_490_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_49_492_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_49_494_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_49_496_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_49_498_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_49_500_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_49_502_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_49_504_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_49_506_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_49_508_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_430_0[i];
          }

          tmp_15[0] = B_62_0_0;
          tmp_15[1] = tmp_0;
          tmp_15[2] = tmp_1;
          tmp_15[3] = tmp_2;
          tmp_15[4] = tmp_3;
          tmp_15[5] = tmp_4;
          tmp_15[6] = tmp_5;
          tmp_15[7] = tmp_6;
          tmp_15[8] = tmp_7;
          tmp_15[9] = tmp_8;
          tmp_15[10] = tmp_9;
          tmp_15[11] = tmp_a;
          tmp_15[12] = tmp_b;
          tmp_15[13] = tmp_c;
          tmp_15[14] = tmp_d;
          tmp_15[15] = tmp_g;
          tmp_15[16] = tmp_h;
          tmp_15[17] = tmp_i;
          tmp_15[18] = tmp_j;
          tmp_15[19] = tmp_k;
          tmp_15[20] = tmp_l;
          tmp_15[21] = tmp_m;
          tmp_15[22] = tmp_n;
          tmp_15[23] = tmp_o;
          tmp_15[24] = tmp_p;
          tmp_15[25] = tmp_q;
          tmp_15[26] = tmp_r;
          tmp_15[27] = tmp_s;
          tmp_15[28] = tmp_t;
          tmp_15[29] = tmp_u;
          tmp_15[30] = tmp_v;
          tmp_15[31] = tmp_w;
          tmp_15[32] = tmp_x;
          tmp_15[33] = tmp_y;
          tmp_15[34] = tmp_z;
          tmp_15[35] = tmp_10;
          tmp_15[36] = tmp_11;
          tmp_15[37] = tmp_12;
          tmp_15[38] = tmp_13;
          tmp_15[39] = tmp_14;
          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_511_0[i] = tmp_15[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_49_510_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_512_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1792 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_511_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_514_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1793;
          }

          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_515_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_512_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_514_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_517_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_515_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1794;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_518_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1795;
          }

          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_519_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_517_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_49_518_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_521_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1796;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 40; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_356_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_519_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_522_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_49_521_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_523_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_522_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1797;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_524_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1798 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_523_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_525_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_524_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1799;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_526_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_525_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1800 ? ((Parameters *) ssGetDefaultParam(S))->P_1800 : ((BlockIO
            *) _ssGetBlockIO(S))->B_49_525_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1801 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1801 : ((BlockIO *) _ssGetBlockIO(S))->B_49_525_0;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_527_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1802, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 47, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_49_529_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_526_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_47_0_1;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_530_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1803, 50U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_531_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1804, 45U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_49_532_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1805[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_532_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1805[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_533_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1806[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_533_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_69_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1806[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_534_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1807[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_533_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_534_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1807[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_533_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_534_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1808;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_534_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1808;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_537_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1809[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_537_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1809[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_539_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1810[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_539_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1810[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_541_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1811[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_541_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1811[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_543_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1812[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_543_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1812[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_545_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1813[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_545_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1813[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_547_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1814[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_547_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1814[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_549_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1815[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_549_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1815[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_551_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1816[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_551_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1816[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_553_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1817[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_553_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1817[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_555_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1818[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_555_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1818[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_557_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1819[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_557_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1819[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_559_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1820[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_559_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1820[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_561_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1821[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_561_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1821[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_563_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1822[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_563_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1822[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_565_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1823[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_565_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1823[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_567_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1824[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_567_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1824[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_569_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1825[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_569_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1825[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_571_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1826[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_571_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1826[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_573_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1827[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_573_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1827[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_575_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1828[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_575_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1828[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_577_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1829[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_577_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1829[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_579_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1830[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_579_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1830[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_581_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1831[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_581_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1831[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_583_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1832[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_583_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1832[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_585_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1833[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_585_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1833[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_587_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1834[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_587_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1834[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_589_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1835[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_589_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1835[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_591_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1836[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_591_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1836[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_593_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1837[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_593_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1837[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_595_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1838[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_595_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1838[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_597_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1839[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_597_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1839[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_599_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1840[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_599_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1840[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_601_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1841[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_601_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1841[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_603_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1842[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_603_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1842[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_605_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1843[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_605_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1843[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_607_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1844[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_607_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1844[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_609_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1845[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_609_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1845[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_611_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1846[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_611_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1846[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_613_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1847[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_613_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1847[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_615_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1848[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_615_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1848[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_617_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1849[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_617_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1849[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_619_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1850[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_619_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1850[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_621_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1851[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_621_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1851[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_623_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1852[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_623_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1852[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_625_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1853, 45U *
                   sizeof(real_T));
          }

          tmp_1u[0] = ((BlockIO *) _ssGetBlockIO(S))->B_49_532_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_532_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[1] = ((BlockIO *) _ssGetBlockIO(S))->B_49_537_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_537_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[2] = ((BlockIO *) _ssGetBlockIO(S))->B_49_539_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_539_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[3] = ((BlockIO *) _ssGetBlockIO(S))->B_49_541_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_541_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[4] = ((BlockIO *) _ssGetBlockIO(S))->B_49_543_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_543_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[5] = ((BlockIO *) _ssGetBlockIO(S))->B_49_545_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_545_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[6] = ((BlockIO *) _ssGetBlockIO(S))->B_49_547_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_547_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[7] = ((BlockIO *) _ssGetBlockIO(S))->B_49_549_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_549_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[8] = ((BlockIO *) _ssGetBlockIO(S))->B_49_551_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_551_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[9] = ((BlockIO *) _ssGetBlockIO(S))->B_49_553_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_553_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[10] = ((BlockIO *) _ssGetBlockIO(S))->B_49_555_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_555_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[11] = ((BlockIO *) _ssGetBlockIO(S))->B_49_557_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_557_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[12] = ((BlockIO *) _ssGetBlockIO(S))->B_49_559_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_559_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[13] = ((BlockIO *) _ssGetBlockIO(S))->B_49_561_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_561_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[14] = ((BlockIO *) _ssGetBlockIO(S))->B_49_563_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_563_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[15] = ((BlockIO *) _ssGetBlockIO(S))->B_49_565_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_565_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[16] = ((BlockIO *) _ssGetBlockIO(S))->B_49_567_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_567_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[17] = ((BlockIO *) _ssGetBlockIO(S))->B_49_569_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_569_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[18] = ((BlockIO *) _ssGetBlockIO(S))->B_49_571_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_571_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[19] = ((BlockIO *) _ssGetBlockIO(S))->B_49_573_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_573_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[20] = ((BlockIO *) _ssGetBlockIO(S))->B_49_575_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_575_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[21] = ((BlockIO *) _ssGetBlockIO(S))->B_49_577_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_577_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[22] = ((BlockIO *) _ssGetBlockIO(S))->B_49_579_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_579_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[23] = ((BlockIO *) _ssGetBlockIO(S))->B_49_581_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_581_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[24] = ((BlockIO *) _ssGetBlockIO(S))->B_49_583_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_583_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[25] = ((BlockIO *) _ssGetBlockIO(S))->B_49_585_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_585_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[26] = ((BlockIO *) _ssGetBlockIO(S))->B_49_587_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_587_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[27] = ((BlockIO *) _ssGetBlockIO(S))->B_49_589_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_589_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[28] = ((BlockIO *) _ssGetBlockIO(S))->B_49_591_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_591_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[29] = ((BlockIO *) _ssGetBlockIO(S))->B_49_593_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_593_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[30] = ((BlockIO *) _ssGetBlockIO(S))->B_49_595_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_595_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[31] = ((BlockIO *) _ssGetBlockIO(S))->B_49_597_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_597_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[32] = ((BlockIO *) _ssGetBlockIO(S))->B_49_599_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_599_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[33] = ((BlockIO *) _ssGetBlockIO(S))->B_49_601_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_601_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[34] = ((BlockIO *) _ssGetBlockIO(S))->B_49_603_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_603_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[35] = ((BlockIO *) _ssGetBlockIO(S))->B_49_605_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_605_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[36] = ((BlockIO *) _ssGetBlockIO(S))->B_49_607_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_607_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[37] = ((BlockIO *) _ssGetBlockIO(S))->B_49_609_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_609_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[38] = ((BlockIO *) _ssGetBlockIO(S))->B_49_611_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_611_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[39] = ((BlockIO *) _ssGetBlockIO(S))->B_49_613_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_613_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[40] = ((BlockIO *) _ssGetBlockIO(S))->B_49_615_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_615_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[41] = ((BlockIO *) _ssGetBlockIO(S))->B_49_617_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_617_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[42] = ((BlockIO *) _ssGetBlockIO(S))->B_49_619_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_619_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[43] = ((BlockIO *) _ssGetBlockIO(S))->B_49_621_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_621_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          tmp_1u[44] = ((BlockIO *) _ssGetBlockIO(S))->B_49_623_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_49_535_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_49_623_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_49_535_0[1];
          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_626_0[i] = tmp_1u[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_49_625_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_627_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1854 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_626_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_629_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1855;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_630_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_627_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_629_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_632_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_630_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1856;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_633_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1857;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_634_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_632_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_49_633_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_636_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1858, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_638_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1859, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_640_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1860, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_642_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1861, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_644_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1862, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_646_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1863, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_648_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1864, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_650_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1865, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_652_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1866, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_654_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1867, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_656_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1868, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_658_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1869, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_660_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1870, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_662_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1871, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_664_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1872, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_666_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1873, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_668_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1874, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_670_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1875, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_672_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1876, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_674_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1877, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_676_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1878, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_678_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1879, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_680_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1880, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_682_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1881, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_684_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1882, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_686_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1883, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_688_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1884, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_690_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1885, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_692_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1886, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_694_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1887, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_696_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1888, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_698_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1889, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_700_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1890, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_702_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1891, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_704_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1892, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_706_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1893, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_708_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1894, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_710_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1895, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_712_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1896, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_714_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1897, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_716_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1898, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_718_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1899, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_720_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1900, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_722_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1901, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_724_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1902, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_726_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1903, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_728_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1904, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_730_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1905, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_732_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1906, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_734_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1907, 50U *
                   sizeof(real_T));
          }

          B_62_0_0 = 0.0;
          tmp_0 = 0.0;
          tmp_1 = 0.0;
          tmp_2 = 0.0;
          tmp_3 = 0.0;
          tmp_4 = 0.0;
          tmp_5 = 0.0;
          tmp_6 = 0.0;
          tmp_7 = 0.0;
          tmp_8 = 0.0;
          tmp_9 = 0.0;
          tmp_a = 0.0;
          tmp_b = 0.0;
          tmp_c = 0.0;
          tmp_d = 0.0;
          tmp_g = 0.0;
          tmp_h = 0.0;
          tmp_i = 0.0;
          tmp_j = 0.0;
          tmp_k = 0.0;
          tmp_l = 0.0;
          tmp_m = 0.0;
          tmp_n = 0.0;
          tmp_o = 0.0;
          tmp_p = 0.0;
          tmp_q = 0.0;
          tmp_r = 0.0;
          tmp_s = 0.0;
          tmp_t = 0.0;
          tmp_u = 0.0;
          tmp_v = 0.0;
          tmp_w = 0.0;
          tmp_x = 0.0;
          tmp_y = 0.0;
          tmp_z = 0.0;
          tmp_10 = 0.0;
          tmp_11 = 0.0;
          tmp_12 = 0.0;
          tmp_13 = 0.0;
          tmp_14 = 0.0;
          tmp_18 = 0.0;
          tmp_19 = 0.0;
          tmp_1a = 0.0;
          tmp_1b = 0.0;
          tmp_1c = 0.0;
          tmp_1d = 0.0;
          tmp_1e = 0.0;
          tmp_1f = 0.0;
          tmp_1g = 0.0;
          tmp_1h = 0.0;
          for (i = 0; i < 45; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_531_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_636_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_49_638_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_49_640_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_49_642_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_49_644_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_49_646_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_49_648_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_49_650_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_49_652_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_49_654_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_49_656_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_49_658_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_49_660_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_49_662_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_49_664_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_49_666_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_49_668_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_49_670_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_49_672_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_49_674_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_49_676_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_49_678_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_49_680_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_49_682_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_49_684_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_49_686_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_49_688_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_49_690_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_49_692_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_49_694_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_49_696_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_49_698_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_49_700_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_49_702_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_49_704_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_49_706_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_49_708_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_49_710_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_49_712_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_49_714_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_49_716_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_49_718_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_49_720_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_49_722_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_49_724_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_49_726_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_49_728_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_49_730_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_49_732_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_49_634_0[i];
          }

          tmp_21[0] = B_62_0_0;
          tmp_21[1] = tmp_0;
          tmp_21[2] = tmp_1;
          tmp_21[3] = tmp_2;
          tmp_21[4] = tmp_3;
          tmp_21[5] = tmp_4;
          tmp_21[6] = tmp_5;
          tmp_21[7] = tmp_6;
          tmp_21[8] = tmp_7;
          tmp_21[9] = tmp_8;
          tmp_21[10] = tmp_9;
          tmp_21[11] = tmp_a;
          tmp_21[12] = tmp_b;
          tmp_21[13] = tmp_c;
          tmp_21[14] = tmp_d;
          tmp_21[15] = tmp_g;
          tmp_21[16] = tmp_h;
          tmp_21[17] = tmp_i;
          tmp_21[18] = tmp_j;
          tmp_21[19] = tmp_k;
          tmp_21[20] = tmp_l;
          tmp_21[21] = tmp_m;
          tmp_21[22] = tmp_n;
          tmp_21[23] = tmp_o;
          tmp_21[24] = tmp_p;
          tmp_21[25] = tmp_q;
          tmp_21[26] = tmp_r;
          tmp_21[27] = tmp_s;
          tmp_21[28] = tmp_t;
          tmp_21[29] = tmp_u;
          tmp_21[30] = tmp_v;
          tmp_21[31] = tmp_w;
          tmp_21[32] = tmp_x;
          tmp_21[33] = tmp_y;
          tmp_21[34] = tmp_z;
          tmp_21[35] = tmp_10;
          tmp_21[36] = tmp_11;
          tmp_21[37] = tmp_12;
          tmp_21[38] = tmp_13;
          tmp_21[39] = tmp_14;
          tmp_21[40] = tmp_18;
          tmp_21[41] = tmp_19;
          tmp_21[42] = tmp_1a;
          tmp_21[43] = tmp_1b;
          tmp_21[44] = tmp_1c;
          tmp_21[45] = tmp_1d;
          tmp_21[46] = tmp_1e;
          tmp_21[47] = tmp_1f;
          tmp_21[48] = tmp_1g;
          tmp_21[49] = tmp_1h;
          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_735_0[i] = tmp_21[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_49_734_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_49_736_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1908 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_49_735_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_738_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1909;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_739_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_49_736_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_49_738_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_49_741_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_49_739_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1910;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_742_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1911;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_743_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_49_741_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_49_742_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_49_745_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1912;
          }

          B_62_0_0 = 0.0;
          for (i = 0; i < 50; i++) {
            B_62_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_49_530_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_49_743_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_49_746_0 = B_62_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_49_745_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_747_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_746_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1913;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_748_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1914 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_747_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_749_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_748_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1915;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_750_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_749_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1916 ? ((Parameters *) ssGetDefaultParam(S))->P_1916 : ((BlockIO
            *) _ssGetBlockIO(S))->B_49_749_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1917 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1917 : ((BlockIO *) _ssGetBlockIO(S))->B_49_749_0;
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_49_751_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1918, 24U *
                   sizeof(real_T));
          }

          /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 48, 0, SS_CALL_MDL_OUTPUTS);
          ((BlockIO *) _ssGetBlockIO(S))->B_49_753_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_49_750_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_48_0_1;
          ((BlockIO *) _ssGetBlockIO(S))->B_49_754_0 = ((((BlockIO *)
            _ssGetBlockIO(S))->B_49_161_0 + ((BlockIO *) _ssGetBlockIO(S))
            ->B_49_355_0) + ((BlockIO *) _ssGetBlockIO(S))->B_49_529_0) +
            ((BlockIO *) _ssGetBlockIO(S))->B_49_753_0;
          if (ssIsSampleHit(S, 1, 0)) {
            /* Scope: '<S1243>/Scope' */
            /* Call into Simulink for Scope */
            ssCallAccelRunBlock(S, 49, 755, SS_CALL_MDL_OUTPUTS);
          }

          if (ssIsMajorTimeStep(S)) {
            srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper08_SubsysRanBC);
          }
          break;
        }

        if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 > ((Parameters *)
             ssGetDefaultParam(S))->P_1919) {
          ((BlockIO *) _ssGetBlockIO(S))->B_50_3_0 = ((BlockIO *) _ssGetBlockIO
            (S))->B_49_754_0;
        } else {
          ((BlockIO *) _ssGetBlockIO(S))->B_50_3_0 = ((BlockIO *) _ssGetBlockIO
            (S))->B_44_807_0;
        }

        if (ssIsMajorTimeStep(S)) {
          srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper07_SubsysRanBC);
        }
        break;
      }

      if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 > ((Parameters *)
           ssGetDefaultParam(S))->P_1920) {
        ((BlockIO *) _ssGetBlockIO(S))->B_51_3_0 = ((BlockIO *) _ssGetBlockIO(S))
          ->B_50_3_0;
      } else {
        ((BlockIO *) _ssGetBlockIO(S))->B_51_3_0 = ((BlockIO *) _ssGetBlockIO(S))
          ->B_39_757_0;
      }

      if (ssIsMajorTimeStep(S)) {
        srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper06_SubsysRanBC);
      }
      break;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_1921) {
      ((BlockIO *) _ssGetBlockIO(S))->B_52_3_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_51_3_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_52_3_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_34_627_0;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper05_SubsysRanBC);
    }
    break;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_40_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_1989) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_47_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_52_3_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_47_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_29_350_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_48_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_47_0 >= ((Parameters *) ssGetDefaultParam(S))->P_1990 ? ((Parameters *)
    ssGetDefaultParam(S))->P_1990 : ((BlockIO *) _ssGetBlockIO(S))->B_69_47_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_1991 ? ((Parameters *)
    ssGetDefaultParam(S))->P_1991 : ((BlockIO *) _ssGetBlockIO(S))->B_69_47_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_49_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1992;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_50_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1993;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_17_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_1994) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_48_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_41) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_69_48_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_69_49_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_20_1_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_17_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_52_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_20_1_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_52_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_50_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_53_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_l;
    ssCallAccelRunBlock(S, 69, 54, SS_CALL_MDL_OUTPUTS);
    B_69_817_0 = ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_e;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_56_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_lc;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_57_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory1_PreviousInput_e - ((BlockIO *) _ssGetBlockIO(S))->B_69_56_0;
    ssCallAccelRunBlock(S, 69, 58, SS_CALL_MDL_OUTPUTS);
  }

  /* TransferFcn: '<S34>/Clutch  Actuator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_59_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2000*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_60_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2003 * ((BlockIO *) _ssGetBlockIO(S))->B_69_59_0;
  ssCallAccelRunBlock(S, 69, 61, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_62_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2006*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator_CSTATE_b;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_63_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2009 * ((BlockIO *) _ssGetBlockIO(S))->B_69_62_0;
  ssCallAccelRunBlock(S, 69, 64, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_65_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2012*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator1_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_66_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2015 * ((BlockIO *) _ssGetBlockIO(S))->B_69_65_0;
  ssCallAccelRunBlock(S, 69, 67, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator2' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_68_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2018*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator2_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_69_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2021 * ((BlockIO *) _ssGetBlockIO(S))->B_69_68_0;
  ssCallAccelRunBlock(S, 69, 70, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator3' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_71_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2024*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator3_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_72_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2027 * ((BlockIO *) _ssGetBlockIO(S))->B_69_71_0;
  ssCallAccelRunBlock(S, 69, 73, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S35>/Clutch  Actuator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_74_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2030*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator_CSTATE_o;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_75_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2033 * ((BlockIO *) _ssGetBlockIO(S))->B_69_74_0;
  ssCallAccelRunBlock(S, 69, 76, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S4>/Pressure controller time constant//1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_77_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2036*((ContinuousStates *) ssGetContStates(S))
    ->Pressurecontrollertimeconstant1_CSTATE;
  ssCallAccelRunBlock(S, 69, 78, SS_CALL_MDL_OUTPUTS);

  /* FromWorkspace: '<Root>/drive cycle' */

  /* Call into Simulink for From Workspace */
  ssCallAccelRunBlock(S, 69, 79, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_80_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_79_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2039 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2039 : ((BlockIO *) _ssGetBlockIO(S))->B_69_79_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_2040 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2040 : ((BlockIO *) _ssGetBlockIO(S))->B_69_79_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_81_0 = B_69_551_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_2041 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_2041 : B_69_551_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2042 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2042 : B_69_551_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_82_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_80_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_81_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_83_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2043 * ((BlockIO *) _ssGetBlockIO(S))->B_69_82_0;

  /* Derivative: '<S2074>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_84_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      ((BlockIO *) _ssGetBlockIO(S))->B_69_84_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_69_83_0 - *lastU++) / deltaT;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_85_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2044 * ((BlockIO *) _ssGetBlockIO(S))->B_69_84_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_86_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2045 * ((BlockIO *) _ssGetBlockIO(S))->B_69_83_0;

  /* Integrator: '<S2074>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE,
                       ((BlockIO *) _ssGetBlockIO(S))->B_69_81_0);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_2046;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_87_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_88_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2047 * ((BlockIO *) _ssGetBlockIO(S))->B_69_87_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_89_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_69_85_0 + ((BlockIO *) _ssGetBlockIO(S))->B_69_86_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_69_88_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_90_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2048 * ((BlockIO *) _ssGetBlockIO(S))->B_69_89_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_91_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_90_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2049 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2049 : ((BlockIO *) _ssGetBlockIO(S))->B_69_90_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_2050 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2050 : ((BlockIO *) _ssGetBlockIO(S))->B_69_90_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_92_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2051 * ((BlockIO *) _ssGetBlockIO(S))->B_69_91_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_93_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2052 * ((BlockIO *) _ssGetBlockIO(S))->B_69_92_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_94_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2053 * ((BlockIO *) _ssGetBlockIO(S))->B_69_93_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_95_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2054;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_96_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2055;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_97_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2056;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_98_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_n;
    if (B_69_551_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2058) {
      B_62_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_69_97_0 * ((BlockIO *)
        _ssGetBlockIO(S))->B_69_98_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_69_101_0 = B_62_0_0 >= ((Parameters *)
        ssGetDefaultParam(S))->P_1924 ? ((Parameters *) ssGetDefaultParam(S))
        ->P_1924 : B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_1925 ?
        ((Parameters *) ssGetDefaultParam(S))->P_1925 : B_62_0_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_101_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1923;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_69_102_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2059;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_94_0 != 0.0) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_103_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_101_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_103_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_102_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_104_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_94_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_103_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_105_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_104_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2060 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2060 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_104_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2061 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2061 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_104_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_106_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_94_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_105_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_107_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_106_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_108_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2062;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_107_0 != 0.0) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_39_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_1922) {
      ((BlockIO *) _ssGetBlockIO(S))->B_53_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_69_95_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_53_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_69_96_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_53_1_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_94_0 * ((BlockIO *) _ssGetBlockIO(S))->B_53_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_53_2_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_53_1_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_97_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_110_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_53_2_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_110_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_108_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_17_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2063) {
    ((BlockIO *) _ssGetBlockIO(S))->B_19_0_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_17_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_52_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_112_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_19_0_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_112_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_110_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_113_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory2_PreviousInput;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_114_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_112_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_113_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_115_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2065 * ((BlockIO *) _ssGetBlockIO(S))->B_69_114_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_116_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2066 * ((BlockIO *) _ssGetBlockIO(S))->B_69_115_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_117_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_n;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_118_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2068 * ((BlockIO *) _ssGetBlockIO(S))->B_69_115_0;

  /* Derivative: '<S2116>/Ideal Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_119_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))
            ->IdealDerivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))
          ->IdealDerivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      ((BlockIO *) _ssGetBlockIO(S))->B_69_119_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_69_118_0 - *lastU++) / deltaT;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_120_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_69_116_0 + ((BlockIO *) _ssGetBlockIO(S))->B_69_117_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_69_119_0;

  /* TransferFcn: '<S2081>/Transfer Fcn' */
  ((BlockIO *) _ssGetBlockIO(S))->B_69_121_0 = (((Parameters *)
    ssGetDefaultParam(S))->P_2071)*((ContinuousStates *) ssGetContStates(S))
    ->TransferFcn_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_121_0 += ((Parameters *)
    ssGetDefaultParam(S))->P_2072*((BlockIO *) _ssGetBlockIO(S))->B_69_120_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_122_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_121_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2074 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2074 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_121_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2075 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2075 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_121_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_123_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2076;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_122_0 != 0.0) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_122_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_123_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_125_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2077 * ((BlockIO *) _ssGetBlockIO(S))->B_69_37_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_69_20_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2078) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_128_0 = look2_binlxpw(((BlockIO *)
      _ssGetBlockIO(S))->B_69_125_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
      ((Parameters *) ssGetDefaultParam(S))->P_1940, ((Parameters *)
      ssGetDefaultParam(S))->P_1941, ((Parameters *) ssGetDefaultParam(S))
      ->P_1939, ((Parameters *) ssGetDefaultParam(S))->P_2257, 47U);
  } else {
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_20_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_1938) {
      ((BlockIO *) _ssGetBlockIO(S))->B_64_2_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_125_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1936, ((Parameters *)
        ssGetDefaultParam(S))->P_1937, ((Parameters *) ssGetDefaultParam(S))
        ->P_1935, ((Parameters *) ssGetDefaultParam(S))->P_2256, 47U);
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_64_2_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_69_125_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1933, ((Parameters *)
        ssGetDefaultParam(S))->P_1934, ((Parameters *) ssGetDefaultParam(S))
        ->P_1932, ((Parameters *) ssGetDefaultParam(S))->P_2255, 47U);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_69_128_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_64_2_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_129_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2079 * ((BlockIO *) _ssGetBlockIO(S))->B_69_128_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_130_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2080;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_131_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_129_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_130_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_132_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory_PreviousInput_k;
  }

  B_62_0_0 = rt_Lookup2D_Normal((const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2082, 36, (const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2083, 11, (const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2084, ((BlockIO *) _ssGetBlockIO(S))->B_69_131_0,
                                ((BlockIO *) _ssGetBlockIO(S))->B_69_132_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_134_0 = B_62_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2085 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2085 : B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2086 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2086 : B_62_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_135_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_124_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_136_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2087;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_137_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_134_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_135_0 / ((BlockIO *)
    _ssGetBlockIO(S))->B_69_136_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_138_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_137_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2088 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2088 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_137_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2089 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2089 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_137_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_140_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_138_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_131_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_141_0 = rt_Lookup2D_Normal((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2090, 36, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2091, 11, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2092, ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_131_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_132_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_142_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_141_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_135_0 / ((BlockIO *)
    _ssGetBlockIO(S))->B_69_136_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_143_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2093;
  }

  B_62_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_69_142_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_143_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_145_0 = B_62_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2094 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2094 : B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2095 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2095 : B_62_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_146_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_140_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_145_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_147_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_138_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_148_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2096;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_147_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2097) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_149_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_146_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_149_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_148_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_150_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2098;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_152_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_138_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_150_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_153_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_132_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2099 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2099 : ((BlockIO *) _ssGetBlockIO
      (S))->B_69_132_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2100 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2100 : ((BlockIO *) _ssGetBlockIO
      (S))->B_69_132_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_155_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_153_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_124_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_157_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_152_0 / (((BlockIO *) _ssGetBlockIO(S))->B_69_155_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2101 ? ((Parameters *) ssGetDefaultParam(S))
                    ->P_2101 : ((BlockIO *) _ssGetBlockIO(S))->B_69_155_0 <=
                    ((Parameters *) ssGetDefaultParam(S))->P_2102 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2102 : ((BlockIO *) _ssGetBlockIO(S))
                    ->B_69_155_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_159_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2103;
  }

  if (muDoubleScalarAbs(((BlockIO *) _ssGetBlockIO(S))->B_69_138_0) >=
      ((Parameters *) ssGetDefaultParam(S))->P_2104) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_160_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_157_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_160_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_159_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_161_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2105;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_153_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2106) {
    B_62_0_0 = (((BlockIO *) _ssGetBlockIO(S))->B_69_149_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_1928 ? ((Parameters *) ssGetDefaultParam(S))
                ->P_1928 : ((BlockIO *) _ssGetBlockIO(S))->B_69_149_0 <=
                ((Parameters *) ssGetDefaultParam(S))->P_1929 ? ((Parameters *)
      ssGetDefaultParam(S))->P_1929 : ((BlockIO *) _ssGetBlockIO(S))->B_69_149_0)
      / (((BlockIO *) _ssGetBlockIO(S))->B_69_160_0 >= ((Parameters *)
          ssGetDefaultParam(S))->P_1926 ? ((Parameters *) ssGetDefaultParam(S)
         )->P_1926 : ((BlockIO *) _ssGetBlockIO(S))->B_69_160_0 <= ((Parameters *)
          ssGetDefaultParam(S))->P_1927 ? ((Parameters *) ssGetDefaultParam(S)
         )->P_1927 : ((BlockIO *) _ssGetBlockIO(S))->B_69_160_0);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_163_0 = B_62_0_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_1930 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_1930 : B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_1931 ?
      ((Parameters *) ssGetDefaultParam(S))->P_1931 : B_62_0_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_163_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_161_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_164_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2107;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2108) {
    B_62_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 * ((BlockIO *)
      _ssGetBlockIO(S))->B_69_131_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_163_0
      / ((BlockIO *) _ssGetBlockIO(S))->B_69_164_0;
  } else {
    B_62_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 * ((BlockIO *)
      _ssGetBlockIO(S))->B_69_131_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_163_0
      / ((BlockIO *) _ssGetBlockIO(S))->B_69_164_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_168_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2109;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_170_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2110;
  }

  B_69_172_0 = !((((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 < ((BlockIO *)
    _ssGetBlockIO(S))->B_69_168_0) && (((BlockIO *) _ssGetBlockIO(S))->B_69_39_0
    >= ((BlockIO *) _ssGetBlockIO(S))->B_69_170_0));
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_173_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2111;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_175_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_66_1_0 + ((BlockIO *) _ssGetBlockIO(S))->B_67_3_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_68_3_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_176_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_175_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_33_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_177_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2112 * ((BlockIO *) _ssGetBlockIO(S))->B_69_176_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_179_0 = !((((BlockIO *) _ssGetBlockIO(S)
    )->B_69_124_0 > ((BlockIO *) _ssGetBlockIO(S))->B_69_173_0) && (((BlockIO *)
    _ssGetBlockIO(S))->B_69_39_0 <= ((BlockIO *) _ssGetBlockIO(S))->B_69_177_0));
  ((BlockIO *) _ssGetBlockIO(S))->B_69_180_0 = B_62_0_0 * (real_T)B_69_172_0 *
    (real_T)((BlockIO *) _ssGetBlockIO(S))->B_69_179_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_181_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2113;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_122_0 != 0.0) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_182_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_180_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_182_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_181_0;
  }

  ssCallAccelRunBlock(S, 69, 183, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 69, 184, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 185, SS_CALL_MDL_OUTPUTS);
    B_69_817_0 = ((Parameters *) ssGetDefaultParam(S))->P_2114 * ((BlockIO *)
      _ssGetBlockIO(S))->B_69_185_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_187_0 = B_69_817_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_2115 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_2115 : B_69_817_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2116 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2116 : B_69_817_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_188_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2117, 3, ((BlockIO *)
      _ssGetBlockIO(S))->B_69_187_0, (const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_2118);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_470_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2119, 18, ((BlockIO *)
      _ssGetBlockIO(S))->B_69_187_0, (const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_2120);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_190_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_470_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2121 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2121 : ((BlockIO *) _ssGetBlockIO
      (S))->B_69_470_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2122 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2122 : ((BlockIO *) _ssGetBlockIO
      (S))->B_69_470_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_191_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2123;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_192_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2124;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_52_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2125) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_193_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_191_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_193_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_192_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    B_69_817_0 = ((Parameters *) ssGetDefaultParam(S))->P_2126 * ((BlockIO *)
      _ssGetBlockIO(S))->B_69_185_0;
    if (B_69_817_0 > ((Parameters *) ssGetDefaultParam(S))->P_2127) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_197_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_7;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_197_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_6;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_198_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_193_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_197_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_69_551_0 = ((Parameters *) ssGetDefaultParam(S))->P_2128 - B_69_817_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_201_0 = look1_binlxpw(B_69_551_0,
      ((Parameters *) ssGetDefaultParam(S))->P_2130, ((Parameters *)
      ssGetDefaultParam(S))->P_2129, 2U);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_202_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_198_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_201_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_203_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_202_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2131 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2131 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_202_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2132 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2132 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_202_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_204_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_52_0 + ((BlockIO *) _ssGetBlockIO(S))->B_69_203_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_205_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2133;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_206_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2264;

    /* S-Function (sfblk_manswitch): '<S31>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_69_207_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_206_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_455_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2134;
    ssCallAccelRunBlock(S, 69, 209, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_210_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_204_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_209_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_211_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_210_0 + ((BlockIO *) _ssGetBlockIO(S))->B_69_56_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_212_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_211_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2135 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2135 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_211_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2136 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2136 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_211_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_213_0 = muDoubleScalarMin(((BlockIO *)
    _ssGetBlockIO(S))->B_69_190_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_212_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_214_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_213_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2137 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2137 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_213_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2138 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2138 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_213_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_69_187_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2139) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_215_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_188_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_215_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_214_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_216_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2140;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_215_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2141) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_217_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_215_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_217_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_216_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S1>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 218, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_219_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2142;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_220_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2143;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_198_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2144) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_221_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_219_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_221_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_220_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_222_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_221_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_205_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_223_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2145;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_224_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2146;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_198_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2147) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_225_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_223_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_225_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_224_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_226_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2148 * ((BlockIO *) _ssGetBlockIO(S))->B_69_185_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_227_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2149 * ((BlockIO *) _ssGetBlockIO(S))->B_69_226_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_228_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_215_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2150 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2150 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_215_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2151 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2151 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_215_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_229_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_227_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_228_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_230_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2152 * ((BlockIO *) _ssGetBlockIO(S))->B_69_229_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_232_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2156;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_233_0 = rt_Lookup2D_Normal((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2153, 32, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2154, 16, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2155, ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_230_0, ((BlockIO *) _ssGetBlockIO(S))->B_69_226_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_230_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_232_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_234_0 = rt_Lookup((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2157, 28, ((BlockIO *)
    _ssGetBlockIO(S))->B_69_230_0, (const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2158);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_235_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2159 * ((BlockIO *) _ssGetBlockIO(S))->B_69_234_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2162;
    B_69_551_0 = ((Parameters *) ssGetDefaultParam(S))->P_2160 - ((Parameters *)
      ssGetDefaultParam(S))->P_2162;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_241_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_69_226_0 - ((Parameters *) ssGetDefaultParam(S))->P_2160) *
      ((Parameters *) ssGetDefaultParam(S))->P_2161 / B_69_551_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_242_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_235_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_241_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_245_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_69_226_0 - B_6_2_0) * ((Parameters *) ssGetDefaultParam(S))->P_2163 /
      B_69_551_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_246_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_233_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_245_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_247_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_242_0 + ((BlockIO *) _ssGetBlockIO(S))->B_69_246_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_69_226_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2164) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_248_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_233_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_248_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_247_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_249_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_248_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2165 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2165 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_248_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2166 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2166 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_248_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_250_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_225_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_205_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_249_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_251_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_222_0 + ((BlockIO *) _ssGetBlockIO(S))->B_69_250_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S10>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 252, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S10>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 253, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_254_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2167;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_255_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_251_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_254_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* ToWorkspace: '<S10>/To Workspace' */
    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 256, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_257_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_258_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2169 * ((BlockIO *) _ssGetBlockIO(S))->B_69_257_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_259_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator3_CSTATE;
  B_62_0_0 = ((Parameters *) ssGetDefaultParam(S))->P_2171 * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_259_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_261_0 = B_62_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2172 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2172 : B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2173 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2173 : B_62_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_263_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_258_0 / ((BlockIO *) _ssGetBlockIO(S))->B_69_261_0 * ((Parameters *)
    ssGetDefaultParam(S))->P_2174;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S10>/cons1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 264, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S16>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 265, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S16>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 266, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S16>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 267, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 268, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 269, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 270, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 271, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_187_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_2175) {
      B_62_0_0 = ((Parameters *) ssGetDefaultParam(S))->P_1 * ((BlockIO *)
        _ssGetBlockIO(S))->B_69_187_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_69_274_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_4 / (B_62_0_0 >= ((Parameters *)
        ssGetDefaultParam(S))->P_2 ? ((Parameters *) ssGetDefaultParam(S))->P_2 :
        B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_3 ? ((Parameters *)
        ssGetDefaultParam(S))->P_3 : B_62_0_0) * ((Parameters *)
        ssGetDefaultParam(S))->P_5;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_274_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_0;
    }

    B_69_817_0 = B_69_817_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2176 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2176 : B_69_817_0 <= ((Parameters
      *) ssGetDefaultParam(S))->P_2177 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_2177 : B_69_817_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_455_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2178 * B_69_817_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_470_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2181 * rt_Lookup((const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_2179, 63, B_69_817_0, (const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2180);
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2182;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_298_0 = 1.0 / ((BlockIO *)
      _ssGetBlockIO(S))->B_69_455_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_470_0
      * ((Parameters *) ssGetDefaultParam(S))->P_2182 * ((Parameters *)
      ssGetDefaultParam(S))->P_2183;

    /* Scope: '<S14>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 282, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S15>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 283, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 298, SS_CALL_MDL_OUTPUTS);
  }

  B_62_0_0 = ((Parameters *) ssGetDefaultParam(S))->P_2184 * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_89_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_313_0 = B_62_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2185 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2185 : B_62_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2186 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2186 : B_62_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_314_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2187 * ((BlockIO *) _ssGetBlockIO(S))->B_69_313_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 315, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S5>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 316, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S5>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 317, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S5>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 318, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S140>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 319, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 320, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 321, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 322, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 323, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 324, SS_CALL_MDL_OUTPUTS);

    /* Level2 S-Function Block: '<S2073>/B_53_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 56, 0, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S6>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 326, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S6>/driver' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 327, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_328_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator3_CSTATE_e;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_329_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator4_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_330_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator5_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2076>/error a<0' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 331, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_332_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_i;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_333_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_l;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_334_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2076>/error a>=0' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 335, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_336_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator6_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_337_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator7_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_338_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator8_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2076>/error1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 339, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2076>/total error' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 340, SS_CALL_MDL_OUTPUTS);
  }

  /* Derivative: '<S6>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_341_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))
            ->Derivative_RWORK_p.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_p.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      ((BlockIO *) _ssGetBlockIO(S))->B_69_341_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_69_80_0 - *lastU++) / deltaT;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_342_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2197;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_341_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2198) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_343_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_82_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_343_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_342_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_344_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_343_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_345_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2199 * ((BlockIO *) _ssGetBlockIO(S))->B_69_341_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_346_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2200;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_345_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2201) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_347_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_82_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_347_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_346_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_348_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_347_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_69_349_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_82_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_350_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2202;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_351_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2203;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_352_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2204;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_353_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2205 * ((BlockIO *) _ssGetBlockIO(S))->B_69_343_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_354_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2206 * ((BlockIO *) _ssGetBlockIO(S))->B_69_347_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_355_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2207 * ((BlockIO *) _ssGetBlockIO(S))->B_69_82_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_69_343_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2208) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_356_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_343_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_356_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_350_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_353_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2209) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_357_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_353_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_357_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_350_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_347_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2210) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_358_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_347_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_358_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_351_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_354_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2211) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_359_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_354_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_359_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_351_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_82_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2212) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_360_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_82_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_360_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_352_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_355_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2213) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_361_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_355_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_361_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_352_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2074>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 362, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_363_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2214;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_124_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2215) {
    ((BlockIO *) _ssGetBlockIO(S))->B_57_0_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_363_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_137_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_365_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_57_0_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_365_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_137_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_366_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2216;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_367_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_69_124_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_368_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2217;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_69_367_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2218) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_369_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_366_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_369_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_368_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_370_0 = (real_T)B_69_172_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_69_365_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_369_0 *
    (real_T)((BlockIO *) _ssGetBlockIO(S))->B_69_179_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_371_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2219;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_372_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_370_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_371_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_69_373_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_372_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2220 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2220 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_372_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2221 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2221 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_372_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S7>/SOC' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 374, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/SOC1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 375, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 376, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 377, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 378, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 379, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_380_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2222 * ((BlockIO *) _ssGetBlockIO(S))->B_69_373_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S7>/Scope5' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 381, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_383_0 = ((((BlockIO *) _ssGetBlockIO(S))
      ->B_66_6_0 + ((BlockIO *) _ssGetBlockIO(S))->B_67_6_0) + ((BlockIO *)
      _ssGetBlockIO(S))->B_68_6_0) * ((BlockIO *) _ssGetBlockIO(S))->B_69_34_0;

    /* Scope: '<S7>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 384, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2082>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 385, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2086>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 386, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2086>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 387, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2086>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 388, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2086>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 389, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2087>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 390, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2087>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 391, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2087>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 392, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2087>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 393, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2087>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 394, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 395, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope12' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 396, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope14' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 397, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope15' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 398, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_399_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2223;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_400_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2224;

    /* Level2 S-Function Block: '<S2088>/B_55_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 58, 0, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_402_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_399_0 * ((BlockIO *) _ssGetBlockIO(S))->B_69_400_0 / ((BlockIO *)
    _ssGetBlockIO(S))->B_69_131_0 * ((BlockIO *) _ssGetBlockIO(S))->B_58_0_1;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2084>/Scope16' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 403, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 404, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 405, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 406, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 407, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2084>/Scope9' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 408, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2085>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 409, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2085>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 410, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2101>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 411, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2101>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 412, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2102>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 413, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2102>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 414, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2102>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 415, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2102>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 416, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2103>/Scope10' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 417, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2103>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 418, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2103>/Scope7' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 419, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2104>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 420, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2104>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 421, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2104>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 422, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 423, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2080>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 424, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_426_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2225 * ((BlockIO *) _ssGetBlockIO(S))->B_69_455_0;

    /* Scope: '<S2080>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 427, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_452_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2226 * ((BlockIO *) _ssGetBlockIO(S))->B_69_115_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2081>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 453, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_454_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2227 * ((BlockIO *) _ssGetBlockIO(S))->B_69_182_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 69, 455, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 470, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 484, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 503, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 518, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S3>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 544, SS_CALL_MDL_OUTPUTS);
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2228;
    B_69_817_0 = ((Parameters *) ssGetDefaultParam(S))->P_2229;
    B_69_551_0 = ((Parameters *) ssGetDefaultParam(S))->P_2230;
    B_69_811_0 = ((Parameters *) ssGetDefaultParam(S))->P_2231;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_553_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2232 * ((BlockIO *) _ssGetBlockIO(S))->B_69_185_0;

    /* Level2 S-Function Block: '<S116>/B_9_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 12, 0, SS_CALL_MDL_OUTPUTS);
    B_62_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_6_2_0;
    B_69_556_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_69_817_0;
    B_69_557_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_69_551_0;
    B_69_558_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_69_811_0;
    B_69_811_0 = ((Parameters *) ssGetDefaultParam(S))->P_2233;
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2234;
    if (B_62_0_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_561_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_2233;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_561_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_2234;
    }
  }

  hyd_hyb_2_opt_cont_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_561_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem1, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem1,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem1, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem1);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_69_556_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_563_0 = B_69_811_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_563_0 = B_6_2_0;
    }
  }

  hyd_hyb_2_opt_cont_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_563_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem2, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem2,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem2, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem2);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_69_557_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_565_0 = B_69_811_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_565_0 = B_6_2_0;
    }
  }

  hyd_hyb_2_opt_cont_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_565_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem3, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem3,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem3, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem3);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_69_558_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_567_0 = B_69_811_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_69_567_0 = B_6_2_0;
    }
  }

  hyd_hyb_2_opt_cont_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_567_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem4, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem4,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem4, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem4);
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S35>/T' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 620, SS_CALL_MDL_OUTPUTS);
    B_69_811_0 = ((Parameters *) ssGetDefaultParam(S))->P_2235;
    ssCallAccelRunBlock(S, 69, 639, SS_CALL_MDL_OUTPUTS);
    B_69_811_0 = 1.0 / B_69_811_0 * (((Parameters *) ssGetDefaultParam(S))
      ->P_2236 * ((BlockIO *) _ssGetBlockIO(S))->B_69_639_0);
    ssCallAccelRunBlock(S, 69, 642, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_639_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_2237) {
      B_6_2_0 = 1.0 / muDoubleScalarMax(((BlockIO *) _ssGetBlockIO(S))
        ->B_69_639_0, ((Parameters *) ssGetDefaultParam(S))->P_11) * ((BlockIO *)
        _ssGetBlockIO(S))->B_69_642_0;
    } else {
      if (((BlockIO *) _ssGetBlockIO(S))->B_69_642_0 >= ((Parameters *)
           ssGetDefaultParam(S))->P_10) {
        B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_9;
      } else {
        B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_8;
      }
    }

    B_69_811_0 = B_69_811_0 * B_69_811_0 * rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2238, 173, B_6_2_0, (const real_T
      *)((Parameters *) ssGetDefaultParam(S))->P_2239);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_649_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2240 * B_69_811_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_651_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2241, 173, B_6_2_0, (const real_T
      *)((Parameters *) ssGetDefaultParam(S))->P_2242) * B_69_811_0;

    /* Scope: '<S68>/T1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 652, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 710, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S36>/To Workspace' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 741, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S36>/control indictor' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 742, SS_CALL_MDL_OUTPUTS);

    /* MATLABFcn: '<S36>/gear shift' */

    /* Call into Simulink to run the Matlab Fcn block. */
    ssCallAccelRunBlock(S, 69, 743, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S36>/control indictor1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 744, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S36>/engine speed' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 745, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 746, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 761, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_803_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory1_PreviousInput_ep;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_805_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_69_803_0 - ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput_l;

    /* Scope: '<S4>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 806, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 807, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_808_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2245 * ((BlockIO *) _ssGetBlockIO(S))->B_69_821_0;
    if (((BlockIO *) _ssGetBlockIO(S))->B_69_808_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_2246) {
      B_69_811_0 = ((BlockIO *) _ssGetBlockIO(S))->B_69_808_0 * ((BlockIO *)
        _ssGetBlockIO(S))->B_69_808_0 * ((Parameters *) ssGetDefaultParam(S))
        ->P_31;
    } else {
      B_69_811_0 = ((Parameters *) ssGetDefaultParam(S))->P_30;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_69_808_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_2247) {
      B_6_2_0 = (((BlockIO *) _ssGetBlockIO(S))->B_69_383_0 + ((Parameters *)
                  ssGetDefaultParam(S))->P_38) * ((Parameters *)
        ssGetDefaultParam(S))->P_39 * ((Parameters *) ssGetDefaultParam(S))
        ->P_40;
    } else {
      B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_37;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_69_808_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_2248) {
      B_69_817_0 = (((BlockIO *) _ssGetBlockIO(S))->B_69_383_0 + ((Parameters *)
        ssGetDefaultParam(S))->P_35) * ((Parameters *) ssGetDefaultParam(S))
        ->P_36 * muDoubleScalarSin(((Parameters *) ssGetDefaultParam(S))->P_34 *
                                   ((Parameters *) ssGetDefaultParam(S))->P_33);
    } else {
      B_69_817_0 = ((Parameters *) ssGetDefaultParam(S))->P_32;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_69_819_0 = ((B_69_811_0 + B_6_2_0) +
      B_69_817_0) * ((Parameters *) ssGetDefaultParam(S))->P_2249;

    /* Scope: '<S4>/T1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 820, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 69, 821, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_823_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_69_821_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2250 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2250 : ((BlockIO *) _ssGetBlockIO
      (S))->B_69_821_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2251 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2251 : ((BlockIO *) _ssGetBlockIO
      (S))->B_69_821_0) * ((Parameters *) ssGetDefaultParam(S))->P_2252;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_824_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2253 * ((BlockIO *) _ssGetBlockIO(S))->B_69_105_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S4>/T2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 825, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S4>/To Workspace' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 826, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_69_827_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_69_824_0 - ((BlockIO *) _ssGetBlockIO(S))->B_69_823_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_69_828_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2254 * ((BlockIO *) _ssGetBlockIO(S))->B_69_808_0;
    ssCallAccelRunBlock(S, 69, 877, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 878, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S9>/To Workspace1' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 879, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_69_880_0[0] = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_80_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_69_880_0[1] = ((BlockIO *) _ssGetBlockIO(S))
      ->B_69_81_0;

    /* ToWorkspace: '<S9>/To Workspace2' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 881, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 882, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S9>/To Workspace' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 883, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 884, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 885, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 886, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 887, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S9>/To Workspace3' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 69, 888, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 889, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope7' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 69, 890, SS_CALL_MDL_OUTPUTS);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_217_0;
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_314_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory3_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_828_0;
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_l = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_651_0;
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_e = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_649_0;
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_lc = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_274_0;
  }

  /* Update for Derivative: '<S2074>/Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_69_83_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_n = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_484_0;
    ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_454_0;
  }

  /* Update for Derivative: '<S2116>/Ideal Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->IdealDerivative_RWORK.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))
          ->IdealDerivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->IdealDerivative_RWORK.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))
          ->IdealDerivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_69_118_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_k = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_426_0;
  }

  /* Update for Derivative: '<S6>/Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_p.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_p.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_p.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_p.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_p.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_69_80_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_ep = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_827_0;
    ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput_l = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_819_0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* Derivatives for Integrator: '<S7>/v(lit)' */
  {
    ((StateDerivatives *) ssGetdX(S))->vlit_CSTATE = ((BlockIO *) _ssGetBlockIO
      (S))->B_69_380_0;
  }

  /* Derivatives for TransferFcn: '<S34>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_1998)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_1999*((BlockIO *) _ssGetBlockIO(S))->B_12_0_2;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_b = (((Parameters *)
      ssGetDefaultParam(S))->P_2004)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE_b;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_b += ((Parameters *)
      ssGetDefaultParam(S))->P_2005*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem1.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator1' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator1_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2010)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator1_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator1_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2011*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem2.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator2' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator2_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2016)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator2_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator2_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2017*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem3.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator3' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator3_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2022)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator3_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator3_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2023*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem4.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S35>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_o = (((Parameters *)
      ssGetDefaultParam(S))->P_2028)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE_o;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_o += ((Parameters *)
      ssGetDefaultParam(S))->P_2029*((BlockIO *) _ssGetBlockIO(S))->B_56_0_1;
  }

  /* Derivatives for TransferFcn: '<S4>/Pressure controller time constant//1' */
  {
    ((StateDerivatives *) ssGetdX(S))->Pressurecontrollertimeconstant1_CSTATE =
      (((Parameters *) ssGetDefaultParam(S))->P_2034)*((ContinuousStates *)
      ssGetContStates(S))->Pressurecontrollertimeconstant1_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->Pressurecontrollertimeconstant1_CSTATE +=
      ((Parameters *) ssGetDefaultParam(S))->P_2035*((BlockIO *) _ssGetBlockIO(S))
      ->B_69_805_0;
  }

  /* Derivatives for Integrator: '<S2074>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_69_83_0;
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_n = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_452_0;

  /* Derivatives for TransferFcn: '<S2081>/Transfer Fcn' */
  {
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2069)*((ContinuousStates *) ssGetContStates(S))
      ->TransferFcn_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2070*((BlockIO *) _ssGetBlockIO(S))->B_69_120_0;
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_255_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator3_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_808_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator3_CSTATE_e = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_358_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator4_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_359_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator5_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_348_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_i = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_356_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_l = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_357_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_344_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator6_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_360_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator7_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_361_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator8_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_69_349_0;
  hyd_hyb_2_opt_cont_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S)
    )->EnabledSubsystem1, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem1,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem1, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem1, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem1);
  hyd_hyb_2_opt_cont_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S)
    )->EnabledSubsystem2, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem2,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem2, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem2, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem2);
  hyd_hyb_2_opt_cont_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S)
    )->EnabledSubsystem3, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem3,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem3, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem3, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem3);
  hyd_hyb_2_opt_cont_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S)
    )->EnabledSubsystem4, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem4,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem4, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem4, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem4);
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 525757503U);
  ssSetChecksumVal(S, 1, 4084201708U);
  ssSetChecksumVal(S, 2, 2560554744U);
  ssSetChecksumVal(S, 3, 1825857704U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ((Parameters *) ssGetDefaultParam(S))->P_2 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_1925 = rtMinusInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2039 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2041 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2061 = rtMinusInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2085 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2094 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2099 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2101 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2115 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2121 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2135 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2137 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2150 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2165 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2172 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2176 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2250 = rtInf;
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* register function-calls */
  {
    SimStruct *childS;
    SysOutputFcn *callSysFcns;

    /* Level2 S-Function Block: '<S116>/B_9_0' (stateflow) */
    childS = ssGetSFunction(S, 0);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S151>/B_18_0' (stateflow) */
    childS = ssGetSFunction(S, 1);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S152>/B_19_0' (stateflow) */
    childS = ssGetSFunction(S, 2);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S153>/B_20_0' (stateflow) */
    childS = ssGetSFunction(S, 3);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S154>/B_21_0' (stateflow) */
    childS = ssGetSFunction(S, 4);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S509>/B_27_0' (stateflow) */
    childS = ssGetSFunction(S, 5);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S510>/B_28_0' (stateflow) */
    childS = ssGetSFunction(S, 6);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S511>/B_29_0' (stateflow) */
    childS = ssGetSFunction(S, 7);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S512>/B_30_0' (stateflow) */
    childS = ssGetSFunction(S, 8);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S848>/B_32_0' (stateflow) */
    childS = ssGetSFunction(S, 9);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S849>/B_33_0' (stateflow) */
    childS = ssGetSFunction(S, 10);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S850>/B_34_0' (stateflow) */
    childS = ssGetSFunction(S, 11);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S851>/B_35_0' (stateflow) */
    childS = ssGetSFunction(S, 12);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1252>/B_37_0' (stateflow) */
    childS = ssGetSFunction(S, 13);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1253>/B_38_0' (stateflow) */
    childS = ssGetSFunction(S, 14);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1254>/B_39_0' (stateflow) */
    childS = ssGetSFunction(S, 15);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1255>/B_40_0' (stateflow) */
    childS = ssGetSFunction(S, 16);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1679>/B_42_0' (stateflow) */
    childS = ssGetSFunction(S, 17);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1680>/B_43_0' (stateflow) */
    childS = ssGetSFunction(S, 18);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1681>/B_44_0' (stateflow) */
    childS = ssGetSFunction(S, 19);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S1682>/B_45_0' (stateflow) */
    childS = ssGetSFunction(S, 20);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S2073>/B_53_0' (stateflow) */
    childS = ssGetSFunction(S, 21);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S2088>/B_55_0' (stateflow) */
    childS = ssGetSFunction(S, 22);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
  }
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
