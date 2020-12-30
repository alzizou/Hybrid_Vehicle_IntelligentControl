/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * conv_906_eng_hydr_new_acc.c
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
#include <math.h>
#include "conv_906_eng_hydr_new_acc.h"
#include "conv_906_eng_hydr_new_acc_private.h"
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

/*
 * Initial conditions for enable system:
 *    '<S101>/Enabled Subsystem1'
 *    '<S101>/Enabled Subsystem2'
 *    '<S101>/Enabled Subsystem3'
 *    '<S101>/Enabled Subsystem4'
 */
void conv_906_eng_hydr_new_EnabledSubsystem1_Init(SimStruct *const S,
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new *localX)
{
  /* InitializeConditions for TransferFcn: '<S110>/Clutch A Actuator' */
  localX->ClutchAActuator_CSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S101>/Enabled Subsystem1'
 *    '<S101>/Enabled Subsystem2'
 *    '<S101>/Enabled Subsystem3'
 *    '<S101>/Enabled Subsystem4'
 */
void conv_906_eng_hydr_new_EnabledSubsystem1_Disable(SimStruct *const S,
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new *localB,
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new *localDW,
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new *localP)
{
  localB->B_8_0_0 = localP->P_0;
  localDW->EnabledSubsystem1_MODE = FALSE;
}

/*
 * Derivatives for enable system:
 *    '<S101>/Enabled Subsystem1'
 *    '<S101>/Enabled Subsystem2'
 *    '<S101>/Enabled Subsystem3'
 *    '<S101>/Enabled Subsystem4'
 */
void conv_906_eng_hydr_new_EnabledSubsystem1_Deriv(SimStruct *const S,
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new *localB,
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new *localDW,
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new *localP,
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new *localX,
  rtXdot_EnabledSubsystem1_conv_906_eng_hydr_new *localXdot)
{
  if (localDW->EnabledSubsystem1_MODE) {
    /* Derivatives for TransferFcn: '<S110>/Clutch A Actuator' */
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
 *    '<S101>/Enabled Subsystem1'
 *    '<S101>/Enabled Subsystem2'
 *    '<S101>/Enabled Subsystem3'
 *    '<S101>/Enabled Subsystem4'
 */
void conv_906_eng_hydr_new_EnabledSubsystem1(SimStruct *const S, real_T rtu_0,
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new *localB,
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new *localDW,
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new *localP,
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new *localX)
{
  if (ssIsSampleHit(S, 1, 0) && ssIsMajorTimeStep(S)) {
    if (rtu_0 > 0.0) {
      if (!localDW->EnabledSubsystem1_MODE) {
        conv_906_eng_hydr_new_EnabledSubsystem1_Init(S, localX);
        localDW->EnabledSubsystem1_MODE = TRUE;
      }
    } else {
      if (localDW->EnabledSubsystem1_MODE) {
        conv_906_eng_hydr_new_EnabledSubsystem1_Disable(S, localB, localDW,
          localP);
      }
    }
  }

  if (localDW->EnabledSubsystem1_MODE) {
    /* TransferFcn: '<S110>/Clutch A Actuator' */
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
  /* local block i/o variables */
  real_T B_20_217_0;
  real_T B_20_213_0;
  real_T B_20_240_0;
  real_T B_20_57_0;
  real_T B_20_503_0;
  real_T B_20_194_0;
  real_T B_20_497_0;
  real_T B_20_245_0;
  real_T B_20_246_0;
  real_T B_20_247_0;
  real_T B_6_2_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput;
    ssCallAccelRunBlock(S, 20, 1, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_17_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_40;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_18_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_41;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_19_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_42;
  }

  /* FromWorkspace: '<Root>/drive cycle' */

  /* Call into Simulink for From Workspace */
  ssCallAccelRunBlock(S, 20, 20, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_20_21_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_20_0 >= ((Parameters *) ssGetDefaultParam(S))->P_43 ? ((Parameters *)
    ssGetDefaultParam(S))->P_43 : ((BlockIO *) _ssGetBlockIO(S))->B_20_20_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_44 ? ((Parameters *)
    ssGetDefaultParam(S))->P_44 : ((BlockIO *) _ssGetBlockIO(S))->B_20_20_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_22_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_i;
    ssCallAccelRunBlock(S, 20, 23, SS_CALL_MDL_OUTPUTS);
    B_20_240_0 = ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_25_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_b;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_26_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory1_PreviousInput - ((BlockIO *) _ssGetBlockIO(S))->B_20_25_0;
    ssCallAccelRunBlock(S, 20, 27, SS_CALL_MDL_OUTPUTS);
  }

  /* TransferFcn: '<S32>/Clutch  Actuator' */
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_50*((ContinuousStates *)
    ssGetContStates(S))->ClutchActuator_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_29_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_53 * B_20_213_0;
  ssCallAccelRunBlock(S, 20, 30, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S89>/Clutch  Actuator' */
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_56*((ContinuousStates *)
    ssGetContStates(S))->ClutchActuator_CSTATE_n;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_32_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_59 * B_20_213_0;
  ssCallAccelRunBlock(S, 20, 33, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S89>/Clutch  Actuator1' */
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_62*((ContinuousStates *)
    ssGetContStates(S))->ClutchActuator1_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_35_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_65 * B_20_213_0;
  ssCallAccelRunBlock(S, 20, 36, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S89>/Clutch  Actuator2' */
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_68*((ContinuousStates *)
    ssGetContStates(S))->ClutchActuator2_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_38_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_71 * B_20_213_0;
  ssCallAccelRunBlock(S, 20, 39, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S89>/Clutch  Actuator3' */
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_74*((ContinuousStates *)
    ssGetContStates(S))->ClutchActuator3_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_41_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_77 * B_20_213_0;
  ssCallAccelRunBlock(S, 20, 42, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S33>/Clutch  Actuator' */
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_80*((ContinuousStates *)
    ssGetContStates(S))->ClutchActuator_CSTATE_e;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_44_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_83 * B_20_213_0;
  ssCallAccelRunBlock(S, 20, 45, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S5>/Pressure controller time constant//1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_20_46_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_86*((ContinuousStates *) ssGetContStates(S))
    ->Pressurecontrollertimeconstant1_CSTATE;
  ssCallAccelRunBlock(S, 20, 47, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 20, 48, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 20, 49, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_50_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_89 * ((BlockIO *) _ssGetBlockIO(S))->B_20_66_0;
    B_20_240_0 = ((Parameters *) ssGetDefaultParam(S))->P_90 * ((BlockIO *)
      _ssGetBlockIO(S))->B_20_50_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_52_0 = B_20_240_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_91 ? ((Parameters *) ssGetDefaultParam(S))->P_91 :
      B_20_240_0 <= ((Parameters *) ssGetDefaultParam(S))->P_92 ? ((Parameters *)
      ssGetDefaultParam(S))->P_92 : B_20_240_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_53_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_21_0 - ((BlockIO *) _ssGetBlockIO(S))->B_20_52_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_54_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_93 * ((BlockIO *) _ssGetBlockIO(S))->B_20_53_0;

  /* Derivative: '<S139>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      B_20_213_0 = 0.0;
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
      B_20_213_0 = (((BlockIO *) _ssGetBlockIO(S))->B_20_54_0 - *lastU++) /
        deltaT;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_56_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_94 * B_20_213_0;
  B_20_57_0 = ((Parameters *) ssGetDefaultParam(S))->P_95 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_54_0;

  /* Integrator: '<S139>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE,
                       ((BlockIO *) _ssGetBlockIO(S))->B_20_52_0);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_96;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  B_20_213_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_59_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_97 * B_20_213_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_60_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_20_56_0 + B_20_57_0) + ((BlockIO *) _ssGetBlockIO(S))->B_20_59_0;
  B_20_213_0 = ((Parameters *) ssGetDefaultParam(S))->P_98 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_60_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_62_0 = B_20_213_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_99 ? ((Parameters *) ssGetDefaultParam(S))->P_99 :
    B_20_213_0 <= ((Parameters *) ssGetDefaultParam(S))->P_100 ? ((Parameters *)
    ssGetDefaultParam(S))->P_100 : B_20_213_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_63_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_101 * ((BlockIO *) _ssGetBlockIO(S))->B_20_62_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_64_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_102;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_20_63_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_103) {
    B_20_213_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_19_0;
  } else {
    B_20_213_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_64_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 20, 66, SS_CALL_MDL_OUTPUTS);
    B_20_240_0 = ((Parameters *) ssGetDefaultParam(S))->P_104 * ((BlockIO *)
      _ssGetBlockIO(S))->B_20_66_0;
    if (B_20_240_0 > ((Parameters *) ssGetDefaultParam(S))->P_105) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_70_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_7;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_70_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_6;
    }
  }

  B_20_213_0 *= ((BlockIO *) _ssGetBlockIO(S))->B_20_70_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_72_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_106;
  }

  if (B_20_213_0 > ((Parameters *) ssGetDefaultParam(S))->P_107) {
    B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_18_0;
  } else {
    B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_72_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_74_0 = B_20_217_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_17_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_75_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_108;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_76_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_109;
  }

  if (B_20_213_0 > ((Parameters *) ssGetDefaultParam(S))->P_110) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_77_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_20_75_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_77_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_20_76_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_78_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_111 * ((BlockIO *) _ssGetBlockIO(S))->B_20_66_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_79_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_112 * ((BlockIO *) _ssGetBlockIO(S))->B_20_78_0;
    B_20_57_0 = ((Parameters *) ssGetDefaultParam(S))->P_113 * ((BlockIO *)
      _ssGetBlockIO(S))->B_20_66_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_81_0 = B_20_57_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_114 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_114 : B_20_57_0 <= ((Parameters *) ssGetDefaultParam(S))->P_115 ?
      ((Parameters *) ssGetDefaultParam(S))->P_115 : B_20_57_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_82_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_116, 3, ((BlockIO *)
      _ssGetBlockIO(S))->B_20_81_0, (const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_117);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_434_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_118, 18, ((BlockIO *)
      _ssGetBlockIO(S))->B_20_81_0, (const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_119);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_84_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_20_434_0 >= ((Parameters *) ssGetDefaultParam(S))->P_120 ?
      ((Parameters *) ssGetDefaultParam(S))->P_120 : ((BlockIO *) _ssGetBlockIO
      (S))->B_20_434_0 <= ((Parameters *) ssGetDefaultParam(S))->P_121 ?
      ((Parameters *) ssGetDefaultParam(S))->P_121 : ((BlockIO *) _ssGetBlockIO
      (S))->B_20_434_0;
    B_20_503_0 = ((Parameters *) ssGetDefaultParam(S))->P_122 - B_20_240_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_87_0 = look1_binlxpw(B_20_503_0,
      ((Parameters *) ssGetDefaultParam(S))->P_124, ((Parameters *)
      ssGetDefaultParam(S))->P_123, 2U);
  }

  B_20_213_0 *= ((BlockIO *) _ssGetBlockIO(S))->B_20_87_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_90_0 = (B_20_213_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_125 ? ((Parameters *) ssGetDefaultParam(S))->P_125 :
    B_20_213_0 <= ((Parameters *) ssGetDefaultParam(S))->P_126 ? ((Parameters *)
    ssGetDefaultParam(S))->P_126 : B_20_213_0) + ((BlockIO *) _ssGetBlockIO(S)
    )->B_20_63_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_91_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_225;

    /* S-Function (sfblk_manswitch): '<S29>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_20_92_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_20_91_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_399_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_127;
    ssCallAccelRunBlock(S, 20, 94, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_95_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_90_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_94_0;
  B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_95_0 + ((BlockIO *)
    _ssGetBlockIO(S))->B_20_25_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_97_0 = B_20_217_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_128 ? ((Parameters *) ssGetDefaultParam(S))->P_128 :
    B_20_217_0 <= ((Parameters *) ssGetDefaultParam(S))->P_129 ? ((Parameters *)
    ssGetDefaultParam(S))->P_129 : B_20_217_0;
  B_20_217_0 = muDoubleScalarMin(((BlockIO *) _ssGetBlockIO(S))->B_20_84_0,
    ((BlockIO *) _ssGetBlockIO(S))->B_20_97_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_20_99_0 = B_20_217_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_130 ? ((Parameters *) ssGetDefaultParam(S))->P_130 :
    B_20_217_0 <= ((Parameters *) ssGetDefaultParam(S))->P_131 ? ((Parameters *)
    ssGetDefaultParam(S))->P_131 : B_20_217_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_20_81_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_132) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_100_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_82_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_100_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_99_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_101_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_100_0 >= ((Parameters *) ssGetDefaultParam(S))->P_133 ? ((Parameters *)
    ssGetDefaultParam(S))->P_133 : ((BlockIO *) _ssGetBlockIO(S))->B_20_100_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_134 ? ((Parameters *)
    ssGetDefaultParam(S))->P_134 : ((BlockIO *) _ssGetBlockIO(S))->B_20_100_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_103_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_79_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_101_0 * ((Parameters *)
    ssGetDefaultParam(S))->P_135;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_104_0 = rt_Lookup2D_Normal((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_136, 39, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_137, 17, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_138, ((BlockIO *) _ssGetBlockIO(S)
    )->B_20_103_0, ((BlockIO *) _ssGetBlockIO(S))->B_20_78_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_20_105_0 = rt_Lookup((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_139, 28, ((BlockIO *) _ssGetBlockIO
    (S))->B_20_103_0, (const real_T *)((Parameters *) ssGetDefaultParam(S))
    ->P_140);
  ((BlockIO *) _ssGetBlockIO(S))->B_20_106_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_141 * ((BlockIO *) _ssGetBlockIO(S))->B_20_105_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_144;
    B_20_503_0 = ((Parameters *) ssGetDefaultParam(S))->P_142 - ((Parameters *)
      ssGetDefaultParam(S))->P_144;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_112_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_20_78_0 - ((Parameters *) ssGetDefaultParam(S))->P_142) *
      ((Parameters *) ssGetDefaultParam(S))->P_143 / B_20_503_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_113_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_106_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_112_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_116_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_20_78_0 - B_6_2_0) * ((Parameters *) ssGetDefaultParam(S))->P_145 /
      B_20_503_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_117_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_104_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_116_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_118_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_113_0 + ((BlockIO *) _ssGetBlockIO(S))->B_20_117_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_20_78_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_146) {
    B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_104_0;
  } else {
    B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_118_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_120_0 = B_20_217_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_147 ? ((Parameters *) ssGetDefaultParam(S))->P_147 :
    B_20_217_0 <= ((Parameters *) ssGetDefaultParam(S))->P_148 ? ((Parameters *)
    ssGetDefaultParam(S))->P_148 : B_20_217_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_121_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_77_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_17_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_120_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_122_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_74_0 + ((BlockIO *) _ssGetBlockIO(S))->B_20_121_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S8>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 123, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S8>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 124, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S8>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 125, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S8>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 126, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S8>/To Workspace' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 20, 127, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S8>/To Workspace1' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 20, 128, SS_CALL_MDL_OUTPUTS);
  }

  B_20_217_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_130_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_150 * B_20_217_0;
  B_20_217_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator3_CSTATE;
  B_20_217_0 *= ((Parameters *) ssGetDefaultParam(S))->P_152;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_133_0 = B_20_217_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_153 ? ((Parameters *) ssGetDefaultParam(S))->P_153 :
    B_20_217_0 <= ((Parameters *) ssGetDefaultParam(S))->P_154 ? ((Parameters *)
    ssGetDefaultParam(S))->P_154 : B_20_217_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_135_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_130_0 / ((BlockIO *) _ssGetBlockIO(S))->B_20_133_0 * ((Parameters *)
    ssGetDefaultParam(S))->P_155;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S8>/cons1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 136, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S8>/cons2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 137, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_138_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_156;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_139_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_122_0 / ((BlockIO *) _ssGetBlockIO(S))->B_20_138_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S14>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 140, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S14>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 141, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S14>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 142, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_143_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_157;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_20_100_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_158) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_144_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_100_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_144_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_143_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S11>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 145, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S11>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 146, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S11>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 147, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S11>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 148, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_20_81_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_159) {
      B_20_57_0 = ((Parameters *) ssGetDefaultParam(S))->P_1 * ((BlockIO *)
        _ssGetBlockIO(S))->B_20_81_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_20_151_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_4 / (B_20_57_0 >= ((Parameters *)
        ssGetDefaultParam(S))->P_2 ? ((Parameters *) ssGetDefaultParam(S))->P_2 :
        B_20_57_0 <= ((Parameters *) ssGetDefaultParam(S))->P_3 ? ((Parameters *)
        ssGetDefaultParam(S))->P_3 : B_20_57_0) * ((Parameters *)
        ssGetDefaultParam(S))->P_5;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_151_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_0;
    }

    B_20_240_0 = B_20_240_0 >= ((Parameters *) ssGetDefaultParam(S))->P_160 ?
      ((Parameters *) ssGetDefaultParam(S))->P_160 : B_20_240_0 <= ((Parameters *)
      ssGetDefaultParam(S))->P_161 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_161 : B_20_240_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_399_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_162 * B_20_240_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_434_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_165 * rt_Lookup((const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_163, 63, B_20_240_0, (const real_T *)((Parameters
      *) ssGetDefaultParam(S))->P_164);
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_166;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_175_0 = 1.0 / ((BlockIO *)
      _ssGetBlockIO(S))->B_20_399_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_434_0
      * ((Parameters *) ssGetDefaultParam(S))->P_166 * ((Parameters *)
      ssGetDefaultParam(S))->P_167;

    /* Scope: '<S12>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 159, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 160, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 20, 175, SS_CALL_MDL_OUTPUTS);
  }

  B_20_217_0 = ((Parameters *) ssGetDefaultParam(S))->P_168 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_60_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_192_0 = (B_20_217_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_169 ? ((Parameters *) ssGetDefaultParam(S))->P_169 :
    B_20_217_0 <= ((Parameters *) ssGetDefaultParam(S))->P_170 ? ((Parameters *)
    ssGetDefaultParam(S))->P_170 : B_20_217_0) * ((Parameters *)
    ssGetDefaultParam(S))->P_171 * ((Parameters *) ssGetDefaultParam(S))->P_172;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 193, SS_CALL_MDL_OUTPUTS);
  }

  B_20_194_0 = ((Parameters *) ssGetDefaultParam(S))->P_173 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_192_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Level2 S-Function Block: '<S138>/B_16_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 19, 0, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S6>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 196, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S6>/driver' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 197, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_198_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator3_CSTATE_b;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_199_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator4_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_200_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator5_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S141>/error a<0' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 201, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_202_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_p;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_203_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_e;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_204_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S141>/error a>=0' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 205, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_206_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator6_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_207_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator7_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_20_208_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator8_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S141>/error1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 209, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/total error' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 210, SS_CALL_MDL_OUTPUTS);
  }

  /* Derivative: '<S6>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      B_20_217_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))
            ->Derivative_RWORK_c.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_c.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      B_20_217_0 = (((BlockIO *) _ssGetBlockIO(S))->B_20_21_0 - *lastU++) /
        deltaT;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_212_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_183;
  }

  if (B_20_217_0 >= ((Parameters *) ssGetDefaultParam(S))->P_184) {
    B_20_213_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_53_0;
  } else {
    B_20_213_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_212_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_214_0 = muDoubleScalarAbs(B_20_213_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_216_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_186;
  }

  if (((Parameters *) ssGetDefaultParam(S))->P_185 * B_20_217_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_187) {
    B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_53_0;
  } else {
    B_20_217_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_216_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_218_0 = muDoubleScalarAbs(B_20_217_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_20_219_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_20_53_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_220_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_188;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_221_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_189;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_222_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_190;
  }

  B_20_57_0 = ((Parameters *) ssGetDefaultParam(S))->P_191 * B_20_213_0;
  B_20_240_0 = ((Parameters *) ssGetDefaultParam(S))->P_192 * B_20_217_0;
  B_20_503_0 = ((Parameters *) ssGetDefaultParam(S))->P_193 * ((BlockIO *)
    _ssGetBlockIO(S))->B_20_53_0;
  if (B_20_213_0 >= ((Parameters *) ssGetDefaultParam(S))->P_194) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_226_0 = B_20_213_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_226_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_220_0;
  }

  if (B_20_57_0 >= ((Parameters *) ssGetDefaultParam(S))->P_195) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_227_0 = B_20_57_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_227_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_220_0;
  }

  if (B_20_217_0 >= ((Parameters *) ssGetDefaultParam(S))->P_196) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_228_0 = B_20_217_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_228_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_221_0;
  }

  if (B_20_240_0 >= ((Parameters *) ssGetDefaultParam(S))->P_197) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_229_0 = B_20_240_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_229_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_221_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_20_53_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_198) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_230_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_53_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_230_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_222_0;
  }

  if (B_20_503_0 >= ((Parameters *) ssGetDefaultParam(S))->P_199) {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_231_0 = B_20_503_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_20_231_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_222_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S139>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 232, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S4>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 233, SS_CALL_MDL_OUTPUTS);
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_200;
    B_20_503_0 = ((Parameters *) ssGetDefaultParam(S))->P_201;
    B_20_240_0 = ((Parameters *) ssGetDefaultParam(S))->P_202;
    B_20_497_0 = ((Parameters *) ssGetDefaultParam(S))->P_203;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_242_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_204 * ((BlockIO *) _ssGetBlockIO(S))->B_20_66_0;

    /* Level2 S-Function Block: '<S114>/B_9_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 12, 0, SS_CALL_MDL_OUTPUTS);
    B_20_57_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_6_2_0;
    B_20_245_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_20_503_0;
    B_20_246_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_20_240_0;
    B_20_247_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_20_497_0;
    B_20_497_0 = ((Parameters *) ssGetDefaultParam(S))->P_205;
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_206;
    if (B_20_57_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_250_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_205;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_250_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_206;
    }
  }

  conv_906_eng_hydr_new_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_250_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem1, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem1,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem1, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem1);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_20_245_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_252_0 = B_20_497_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_252_0 = B_6_2_0;
    }
  }

  conv_906_eng_hydr_new_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_252_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem2, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem2,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem2, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem2);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_20_246_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_254_0 = B_20_497_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_254_0 = B_6_2_0;
    }
  }

  conv_906_eng_hydr_new_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_254_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem3, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem3,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem3, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem3);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_20_247_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_256_0 = B_20_497_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_256_0 = B_6_2_0;
    }
  }

  conv_906_eng_hydr_new_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_256_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem4, &((D_Work *)
    ssGetRootDWork(S))->EnabledSubsystem4,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem4, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem4);
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S33>/T' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 309, SS_CALL_MDL_OUTPUTS);
    B_20_497_0 = ((Parameters *) ssGetDefaultParam(S))->P_207;
    ssCallAccelRunBlock(S, 20, 328, SS_CALL_MDL_OUTPUTS);
    B_20_497_0 = 1.0 / B_20_497_0 * (((Parameters *) ssGetDefaultParam(S))
      ->P_208 * ((BlockIO *) _ssGetBlockIO(S))->B_20_328_0);
    ssCallAccelRunBlock(S, 20, 331, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_20_328_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_209) {
      B_6_2_0 = 1.0 / muDoubleScalarMax(((BlockIO *) _ssGetBlockIO(S))
        ->B_20_328_0, ((Parameters *) ssGetDefaultParam(S))->P_11) * ((BlockIO *)
        _ssGetBlockIO(S))->B_20_331_0;
    } else {
      if (((BlockIO *) _ssGetBlockIO(S))->B_20_331_0 >= ((Parameters *)
           ssGetDefaultParam(S))->P_10) {
        B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_9;
      } else {
        B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_8;
      }
    }

    B_20_497_0 = B_20_497_0 * B_20_497_0 * rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_210, 173, B_6_2_0, (const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_211);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_338_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_212 * B_20_497_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_340_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_213, 173, B_6_2_0, (const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_214) * B_20_497_0;

    /* Scope: '<S66>/T1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 341, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 20, 399, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S34>/control indictor' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 430, SS_CALL_MDL_OUTPUTS);

    /* MATLABFcn: '<S34>/gear shift' */

    /* Call into Simulink to run the Matlab Fcn block. */
    ssCallAccelRunBlock(S, 20, 431, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S34>/control indictor1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 432, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S34>/engine speed' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 433, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 20, 434, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 20, 449, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_491_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory1_PreviousInput_p;
    ((BlockIO *) _ssGetBlockIO(S))->B_20_493_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_20_491_0 - ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput;

    /* Scope: '<S5>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 494, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_20_50_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_217) {
      B_20_497_0 = ((BlockIO *) _ssGetBlockIO(S))->B_20_50_0 * ((BlockIO *)
        _ssGetBlockIO(S))->B_20_50_0 * ((Parameters *) ssGetDefaultParam(S))
        ->P_31;
    } else {
      B_20_497_0 = ((Parameters *) ssGetDefaultParam(S))->P_30;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_20_50_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_218) {
      B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_38 * ((Parameters *)
        ssGetDefaultParam(S))->P_37;
    } else {
      B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_36;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_20_50_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_219) {
      B_20_503_0 = muDoubleScalarSin(((Parameters *) ssGetDefaultParam(S))->P_34
        * ((Parameters *) ssGetDefaultParam(S))->P_33) * ((Parameters *)
        ssGetDefaultParam(S))->P_35;
    } else {
      B_20_503_0 = ((Parameters *) ssGetDefaultParam(S))->P_32;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_20_505_0 = ((B_20_497_0 + B_6_2_0) +
      B_20_503_0) * ((Parameters *) ssGetDefaultParam(S))->P_220;

    /* Scope: '<S5>/T1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 506, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 20, 507, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_20_509_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_20_507_0 >= ((Parameters *) ssGetDefaultParam(S))->P_221 ?
      ((Parameters *) ssGetDefaultParam(S))->P_221 : ((BlockIO *) _ssGetBlockIO
      (S))->B_20_507_0 <= ((Parameters *) ssGetDefaultParam(S))->P_222 ?
      ((Parameters *) ssGetDefaultParam(S))->P_222 : ((BlockIO *) _ssGetBlockIO
      (S))->B_20_507_0) * ((Parameters *) ssGetDefaultParam(S))->P_223;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_510_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_224 * B_20_194_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S5>/T2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 511, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S5>/To Workspace' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 20, 512, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_20_513_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_20_510_0 - ((BlockIO *) _ssGetBlockIO(S))->B_20_509_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 20, 562, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 563, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 564, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 565, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 566, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 20, 567, SS_CALL_MDL_OUTPUTS);
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
      _ssGetBlockIO(S))->B_20_144_0;
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_i = ((BlockIO *)
      _ssGetBlockIO(S))->B_20_340_0;
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_20_338_0;
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_b = ((BlockIO *)
      _ssGetBlockIO(S))->B_20_151_0;
  }

  /* Update for Derivative: '<S139>/Derivative' */
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
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_20_54_0;
  }

  /* Update for Derivative: '<S6>/Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_c.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_c.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_c.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_c.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_c.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_20_21_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_p = ((BlockIO *)
      _ssGetBlockIO(S))->B_20_513_0;
    ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_20_505_0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* Derivatives for TransferFcn: '<S32>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_48)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_49*((BlockIO *) _ssGetBlockIO(S))->B_12_0_2;
  }

  /* Derivatives for TransferFcn: '<S89>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_n = (((Parameters *)
      ssGetDefaultParam(S))->P_54)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE_n;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_n += ((Parameters *)
      ssGetDefaultParam(S))->P_55*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem1.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S89>/Clutch  Actuator1' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator1_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_60)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator1_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator1_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_61*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem2.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S89>/Clutch  Actuator2' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator2_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_66)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator2_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator2_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_67*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem3.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S89>/Clutch  Actuator3' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator3_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_72)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator3_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator3_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_73*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem4.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S33>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_e = (((Parameters *)
      ssGetDefaultParam(S))->P_78)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE_e;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_e += ((Parameters *)
      ssGetDefaultParam(S))->P_79*((BlockIO *) _ssGetBlockIO(S))->B_19_0_1;
  }

  /* Derivatives for TransferFcn: '<S5>/Pressure controller time constant//1' */
  {
    ((StateDerivatives *) ssGetdX(S))->Pressurecontrollertimeconstant1_CSTATE =
      (((Parameters *) ssGetDefaultParam(S))->P_84)*((ContinuousStates *)
      ssGetContStates(S))->Pressurecontrollertimeconstant1_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->Pressurecontrollertimeconstant1_CSTATE +=
      ((Parameters *) ssGetDefaultParam(S))->P_85*((BlockIO *) _ssGetBlockIO(S)
      )->B_20_493_0;
  }

  /* Derivatives for Integrator: '<S139>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_20_54_0;
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_139_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator3_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_50_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator3_CSTATE_b = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_228_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator4_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_229_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator5_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_218_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_p = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_226_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_e = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_227_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_214_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator6_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_230_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator7_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_231_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator8_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_20_219_0;
  conv_906_eng_hydr_new_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S))
    ->EnabledSubsystem1, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem1,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem1, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem1, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem1);
  conv_906_eng_hydr_new_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S))
    ->EnabledSubsystem2, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem2,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem2, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem2, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem2);
  conv_906_eng_hydr_new_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S))
    ->EnabledSubsystem3, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem3,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem3, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem3, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem3);
  conv_906_eng_hydr_new_EnabledSubsystem1_Deriv(S, &((BlockIO *) _ssGetBlockIO(S))
    ->EnabledSubsystem4, &((D_Work *) ssGetRootDWork(S))->EnabledSubsystem4,
    (rtP_EnabledSubsystem1_conv_906_eng_hydr_new *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem4, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem4, &((StateDerivatives *) ssGetdX(S))
    ->EnabledSubsystem4);
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 2544241005U);
  ssSetChecksumVal(S, 1, 2661050162U);
  ssSetChecksumVal(S, 2, 489634314U);
  ssSetChecksumVal(S, 3, 839453981U);

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
  ((Parameters *) ssGetDefaultParam(S))->P_43 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_91 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_114 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_120 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_128 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_130 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_133 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_147 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_153 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_160 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_221 = rtInf;
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* register function-calls */
  {
    SimStruct *childS;
    SysOutputFcn *callSysFcns;

    /* Level2 S-Function Block: '<S114>/B_9_0' (stateflow) */
    childS = ssGetSFunction(S, 0);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S138>/B_16_0' (stateflow) */
    childS = ssGetSFunction(S, 1);
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
