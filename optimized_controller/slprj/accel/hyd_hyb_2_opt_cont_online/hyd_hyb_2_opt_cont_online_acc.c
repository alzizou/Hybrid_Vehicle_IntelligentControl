/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * hyd_hyb_2_opt_cont_online_acc.c
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
#include <math.h>
#include "hyd_hyb_2_opt_cont_online_acc.h"
#include "hyd_hyb_2_opt_cont_online_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function
#ifndef __RTW_UTFREE__

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif

/* Buffer management routine for variable delay block */
boolean_T hyd_hyb_2_opt_cont_online_acc_rt_TDelayUpdateTailOrGrowBuf(
  int_T *bufSzPtr,                     /* in/out - circular buffer size                 */
  int_T *tailPtr,                      /* in/out - tail of circular buffer              */
  int_T *headPtr,                      /* in/out - head of circular buffer              */
  int_T *lastPtr,                      /* in/out - same logical 'last' referenced index */
  real_T tMinusDelay,                  /* in     - last point we are looking at   */
  real_T **tBufPtr,                    /* in/out - larger buffer for time         */
  real_T **uBufPtr,                    /* in/out - larger buffer for input        */
  real_T **xBufPtr,                    /* in/out - larger buffer for state        */
  boolean_T isfixedbuf,                /* in     - fixed buffer size enable       */
  boolean_T istransportdelay,          /* in     - block acts as transport dela y */
  int_T *maxNewBufSzPtr)
{
  int_T testIdx;
  int_T tail = *tailPtr;
  int_T bufSz = *bufSzPtr;
  real_T *tBuf = *tBufPtr;
  real_T *xBuf = (NULL);
  int_T numBuffer = 2;
  if (istransportdelay) {
    numBuffer = 3 ;
    xBuf= *xBufPtr;
  }

  /*    Get testIdx, the index of the second oldest data point and
   *    see if this is older than current sim time minus applied delay,
   *    used to see if we can move tail forward
   */
  testIdx = (tail < (bufSz - 1)) ? (tail + 1) : 0;
  if ((tMinusDelay <= tBuf[testIdx]) && !isfixedbuf) {
    int_T j;
    real_T *tempT;
    real_T *tempU;
    real_T *tempX = (NULL);
    real_T *uBuf = *uBufPtr;
    int_T newBufSz = bufSz + 1024;
    if (newBufSz > *maxNewBufSzPtr) {
      *maxNewBufSzPtr = newBufSz;      /* save for warning*/
    }

    tempU = (real_T*)utMalloc(numBuffer*newBufSz*sizeof(real_T));
    if (tempU == (NULL)) {
      return (false);
    }

    tempT = tempU + newBufSz;
    if (istransportdelay)
      tempX = tempT + newBufSz;
    for (j = tail; j < bufSz; j++) {
      tempT[j - tail] = tBuf[j];
      tempU[j - tail] = uBuf[j];
      if (istransportdelay)
        tempX[j - tail] = xBuf[j];
    }

    for (j = 0; j < tail; j++) {
      tempT[j + bufSz - tail] = tBuf[j];
      tempU[j + bufSz - tail] = uBuf[j];
      if (istransportdelay)
        tempX[j + bufSz - tail] = xBuf[j];
    }

    if (*lastPtr> tail) {
      *lastPtr -= tail;
    } else {
      *lastPtr += (bufSz - tail);
    }

    *tailPtr= 0;
    *headPtr = bufSz;
    utFree(uBuf);
    *bufSzPtr = newBufSz;
    *tBufPtr = tempT;
    *uBufPtr = tempU;
    if (istransportdelay)
      *xBufPtr = tempX;
  } else {
    *tailPtr = testIdx;                /* move tail forward */
  }

  return(true);
}

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T hyd_hyb_2_opt_cont_online_acc_rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * muDoubleScalarAbs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

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
void hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Init(SimStruct *const S,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localX)
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
void hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Disable(SimStruct *const S,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localP)
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
void hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Deriv(SimStruct *const S,
  rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localP,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localX,
  rtXdot_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localXdot)
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
void hyd_hyb_2_opt_cont_online_EnabledSubsystem1(SimStruct *const S, real_T
  rtu_0, rtB_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localB,
  rtDW_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localDW,
  rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localP,
  rtX_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *localX)
{
  if (ssIsSampleHit(S, 1, 0) && ssIsMajorTimeStep(S)) {
    if (rtu_0 > 0.0) {
      if (!localDW->EnabledSubsystem1_MODE) {
        hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Init(S, localX);
        localDW->EnabledSubsystem1_MODE = TRUE;
      }
    } else {
      if (localDW->EnabledSubsystem1_MODE) {
        hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Disable(S, localB, localDW,
          localP);
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
  real_T B_55_625_0;
  int8_T rtAction;
  real_T B_55_889_0;
  boolean_T B_55_205_0;
  real_T B_55_883_0;
  real_T B_55_629_0;
  real_T B_55_630_0;
  real_T B_55_631_0;
  real_T B_6_2_0;
  real_T B_48_0_0;
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
    ((BlockIO *) _ssGetBlockIO(S))->B_55_0_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput;
    ssCallAccelRunBlock(S, 55, 1, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_17_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory1_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_19_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1969 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1968;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_20_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1970;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_22_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1972 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1971;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_24_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1974 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1973;
    B_55_625_0 = ((Parameters *) ssGetDefaultParam(S))->P_1975;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1976 * ((Parameters *) ssGetDefaultParam(S))
      ->P_1975;
  }

  rtAction = -1;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_20_0 == 5.0) {
      rtAction = 0;
    }

    ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_52_0_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_22_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1938, ((Parameters *)
        ssGetDefaultParam(S))->P_1939, ((Parameters *) ssGetDefaultParam(S))
        ->P_1937, ((Parameters *) ssGetDefaultParam(S))->P_2295, 51U);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_52_1_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1940 * ((BlockIO *) _ssGetBlockIO(S))->B_52_0_0;
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_52_2_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_24_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1942, ((Parameters *)
        ssGetDefaultParam(S))->P_1943, ((Parameters *) ssGetDefaultParam(S))
        ->P_1941, ((Parameters *) ssGetDefaultParam(S))->P_2296, 51U);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_52_3_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1944 * ((BlockIO *) _ssGetBlockIO(S))->B_52_2_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S2082>/Scope' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 52, 4, SS_CALL_MDL_OUTPUTS);

      /* Scope: '<S2082>/Scope1' */

      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 52, 5, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_52_6_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1945;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->for5galaccumulator_SubsysRanBC);
    }
  }

  rtAction = -1;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_20_0 == 10.0) {
      rtAction = 0;
    }

    ((D_Work *) ssGetRootDWork(S))->If1_ActiveSubsystem = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If1_ActiveSubsystem;
  }

  if (rtAction == 0) {
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_53_0_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_22_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1948, ((Parameters *)
        ssGetDefaultParam(S))->P_1949, ((Parameters *) ssGetDefaultParam(S))
        ->P_1947, ((Parameters *) ssGetDefaultParam(S))->P_2297, 51U);
      ((BlockIO *) _ssGetBlockIO(S))->B_53_1_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_24_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1951, ((Parameters *)
        ssGetDefaultParam(S))->P_1952, ((Parameters *) ssGetDefaultParam(S))
        ->P_1950, ((Parameters *) ssGetDefaultParam(S))->P_2298, 51U);

      /* Scope: '<S2080>/Scope' */

      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 53, 2, SS_CALL_MDL_OUTPUTS);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_53_3_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1953 * ((BlockIO *) _ssGetBlockIO(S))->B_53_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_53_4_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1954 * ((BlockIO *) _ssGetBlockIO(S))->B_53_1_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S2080>/Scope1' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 53, 5, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_53_6_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1955;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->for10galaccumulator_SubsysRanBC);
    }
  }

  rtAction = -1;
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_20_0 == 15.0) {
      rtAction = 0;
    }

    ((D_Work *) ssGetRootDWork(S))->If2_ActiveSubsystem = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If2_ActiveSubsystem;
  }

  if (rtAction == 0) {
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_54_0_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_22_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1958, ((Parameters *)
        ssGetDefaultParam(S))->P_1959, ((Parameters *) ssGetDefaultParam(S))
        ->P_1957, ((Parameters *) ssGetDefaultParam(S))->P_2299, 51U);
      ((BlockIO *) _ssGetBlockIO(S))->B_54_1_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_24_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1961, ((Parameters *)
        ssGetDefaultParam(S))->P_1962, ((Parameters *) ssGetDefaultParam(S))
        ->P_1960, ((Parameters *) ssGetDefaultParam(S))->P_2300, 51U);

      /* Scope: '<S2081>/Scope' */

      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 54, 2, SS_CALL_MDL_OUTPUTS);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_54_3_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1963 * ((BlockIO *) _ssGetBlockIO(S))->B_54_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_54_4_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1964 * ((BlockIO *) _ssGetBlockIO(S))->B_54_1_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S2081>/Scope1' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 54, 5, SS_CALL_MDL_OUTPUTS);
      ((BlockIO *) _ssGetBlockIO(S))->B_54_6_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1965;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))
                 ->for15galaccumulator1_SubsysRanBC);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_33_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_52_3_0 + ((BlockIO *) _ssGetBlockIO(S))->B_53_4_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_54_4_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_34_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1977;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_35_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_19_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_33_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_34_0;

  /* Integrator: '<S7>/v(lit)' */
  if (((D_Work *) ssGetRootDWork(S))->vlit_IWORK.IcNeedsLoading) {
    ((ContinuousStates *) ssGetContStates(S))->vlit_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_35_0;
    ((D_Work *) ssGetRootDWork(S))->vlit_IWORK.IcNeedsLoading = 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_36_0 = ((ContinuousStates *)
    ssGetContStates(S))->vlit_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_37_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_36_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_34_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_38_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_37_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_33_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_39_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_1978 * ((BlockIO *) _ssGetBlockIO(S))->B_55_38_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_1979 * ((BlockIO *) _ssGetBlockIO(S))->B_55_39_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_55_625_0 = ((D_Work *) ssGetRootDWork(S))->Memory3_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_42_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1981 * ((D_Work *) ssGetRootDWork(S))
      ->Memory3_PreviousInput;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_43_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1982 * ((BlockIO *) _ssGetBlockIO(S))->B_55_17_0;
  }

  /* Clock: '<S151>/Clock' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_44_0 = ssGetT(S);

  /* Level2 S-Function Block: '<S156>/B_23_0' (stateflow) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 26, 0, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S151>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE,
                       ((BlockIO *) _ssGetBlockIO(S))->B_26_0_1);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_1983;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_46_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_47_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1984;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_48_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_46_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_47_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_49_0 = ((ContinuousStates *)
    ssGetContStates(S))->integrator_CSTATE;

  /* TransportDelay: '<S148>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = ssGetT(S);
    real_T tMinusDelay = simTime - ((Parameters *) ssGetDefaultParam(S))->P_1986;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_50_0 =
      hyd_hyb_2_opt_cont_online_acc_rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.CircularBufSize,
      &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Last,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Tail,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Head,
      ((Parameters *) ssGetDefaultParam(S))->P_1987,
      0,
      (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_51_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_49_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_50_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_52_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_1988 * ((BlockIO *) _ssGetBlockIO(S))->B_55_51_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_53_0 = ((ContinuousStates *)
    ssGetContStates(S))->integrator_CSTATE_n;

  /* TransportDelay: '<S149>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_p.TUbufferPtrs[1];
    real_T simTime = ssGetT(S);
    real_T tMinusDelay = simTime - ((Parameters *) ssGetDefaultParam(S))->P_1990;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_54_0 =
      hyd_hyb_2_opt_cont_online_acc_rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.CircularBufSize,
      &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Last,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Tail,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head,
      ((Parameters *) ssGetDefaultParam(S))->P_1991,
      0,
      (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_55_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_53_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_54_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_56_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_1992 * ((BlockIO *) _ssGetBlockIO(S))->B_55_55_0;

  /* Clock: '<S150>/Clock1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_57_0 = ssGetT(S);

  /* Level2 S-Function Block: '<S155>/B_22_0' (stateflow) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 25, 0, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S150>/Integrator1' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator1_Reset_ZCE,
                       ((BlockIO *) _ssGetBlockIO(S))->B_25_0_1);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_1993;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_59_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_60_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_1994;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_61_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_59_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_60_0;

  /* Clock: '<S147>/Clock1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_62_0 = ssGetT(S);

  /* Level2 S-Function Block: '<S154>/B_21_0' (stateflow) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 24, 0, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S147>/Integrator1' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator1_Reset_ZCE_l,
                       ((BlockIO *) _ssGetBlockIO(S))->B_24_0_1);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_d =
        ((Parameters *) ssGetDefaultParam(S))->P_1995;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_64_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_d;

  /* Integrator: '<S147>/Integrator2' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator2_Reset_ZCE,
                       ((BlockIO *) _ssGetBlockIO(S))->B_24_0_1);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator2_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_1996;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_65_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_66_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_65_0 >= ((Parameters *) ssGetDefaultParam(S))->P_1997 ? ((Parameters *)
    ssGetDefaultParam(S))->P_1997 : ((BlockIO *) _ssGetBlockIO(S))->B_55_65_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_1998 ? ((Parameters *)
    ssGetDefaultParam(S))->P_1998 : ((BlockIO *) _ssGetBlockIO(S))->B_55_65_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_67_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_64_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_66_0;

  /* Clock: '<S146>/Clock1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_68_0 = ssGetT(S);

  /* Level2 S-Function Block: '<S152>/B_19_0' (stateflow) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 22, 0, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S146>/Integrator1' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator1_Reset_ZCE_ls,
                       ((BlockIO *) _ssGetBlockIO(S))->B_22_0_1);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_o =
        ((Parameters *) ssGetDefaultParam(S))->P_1999;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_70_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_o;

  /* Integrator: '<S146>/Integrator2' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator2_Reset_ZCE_c,
                       ((BlockIO *) _ssGetBlockIO(S))->B_22_0_1);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator2_CSTATE_a =
        ((Parameters *) ssGetDefaultParam(S))->P_2000;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_71_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE_a;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_72_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_71_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2001 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2001 : ((BlockIO *) _ssGetBlockIO(S))->B_55_71_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_2002 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2002 : ((BlockIO *) _ssGetBlockIO(S))->B_55_71_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_73_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_70_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_72_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_74_0[0] = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_j[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_55_74_0[1] = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_j[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_55_74_0[2] = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_j[2];
    ((BlockIO *) _ssGetBlockIO(S))->B_55_74_0[3] = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_j[3];
  }

  /* Clock: '<S143>/Clock3' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_75_0 = ssGetT(S);
  ((BlockIO *) _ssGetBlockIO(S))->B_21_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_48_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_21_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_52_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_21_0_0[2] = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_56_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_21_0_0[3] = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_61_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_21_0_0[4] = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_67_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_21_0_0[5] = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_73_0;

  /* Level2 S-Function Block: '<S144>/B_18_0' (stateflow) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 21, 1, SS_CALL_MDL_OUTPUTS);
  if (ssIsMajorTimeStep(S)) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 <= 0.5) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h = rtAction;
  } else {
    rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_h;
  }

  switch (rtAction) {
   case 0:
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_0_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_96, 15U * sizeof(real_T));
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_1_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_97, 10U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_2_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_98[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_2_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_98[1];
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_31_3_0[0] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_99[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_31_3_0[1] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_99[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_31_4_0[0] = ((Parameters *)
      ssGetDefaultParam(S))->P_100[0] * ((BlockIO *) _ssGetBlockIO(S))->
      B_31_3_0[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_31_4_0[1] = ((Parameters *)
      ssGetDefaultParam(S))->P_100[1] * ((BlockIO *) _ssGetBlockIO(S))->
      B_31_3_0[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[0] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_31_4_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_101;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1] = ((BlockIO *) _ssGetBlockIO(S)
      )->B_31_4_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_101;
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_7_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_102[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_7_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_102[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_9_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_103[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_9_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_103[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_11_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_104[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_11_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_104[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_13_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_105[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_13_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_105[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_15_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_106[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_15_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_106[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_17_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_107[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_17_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_107[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_19_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_108[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_19_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_108[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_21_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_109[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_21_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_109[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_23_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_110[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_23_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_110[1];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_25_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_111, 10U * sizeof(real_T));
    }

    tmp[0] = ((BlockIO *) _ssGetBlockIO(S))->B_31_2_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->B_31_2_0
      [1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[1] = ((BlockIO *) _ssGetBlockIO(S))->B_31_7_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->B_31_7_0
      [1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[2] = ((BlockIO *) _ssGetBlockIO(S))->B_31_9_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->B_31_9_0
      [1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[3] = ((BlockIO *) _ssGetBlockIO(S))->B_31_11_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[4] = ((BlockIO *) _ssGetBlockIO(S))->B_31_13_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[5] = ((BlockIO *) _ssGetBlockIO(S))->B_31_15_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[6] = ((BlockIO *) _ssGetBlockIO(S))->B_31_17_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[7] = ((BlockIO *) _ssGetBlockIO(S))->B_31_19_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[8] = ((BlockIO *) _ssGetBlockIO(S))->B_31_21_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    tmp[9] = ((BlockIO *) _ssGetBlockIO(S))->B_31_23_0[0] * ((BlockIO *)
      _ssGetBlockIO(S))->B_31_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))->
      B_31_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_31_5_0[1];
    for (i = 0; i < 10; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_26_0[i] = tmp[i] + ((BlockIO *)
        _ssGetBlockIO(S))->B_31_25_0[i];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_27_0[i] = ((Parameters *)
        ssGetDefaultParam(S))->P_112 * ((BlockIO *) _ssGetBlockIO(S))->
        B_31_26_0[i];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_29_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_113;
    }

    for (i = 0; i < 10; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_30_0[i] = muDoubleScalarExp(((BlockIO
        *) _ssGetBlockIO(S))->B_31_27_0[i]) + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_29_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_32_0[i] = 1.0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_31_30_0[i] * ((Parameters *) ssGetDefaultParam(S)
        )->P_114;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_33_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_115;
    }

    for (i = 0; i < 10; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_34_0[i] = ((BlockIO *) _ssGetBlockIO
        (S))->B_31_32_0[i] - ((BlockIO *) _ssGetBlockIO(S))->B_31_33_0;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_36_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_116, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_38_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_117, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_40_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_118, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_42_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_119, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_44_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_120, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_46_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_121, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_48_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_122, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_50_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_123, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_52_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_124, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_54_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_125, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_56_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_126, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_58_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_127, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_60_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_128, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_62_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_129, 10U * sizeof(real_T));
    }

    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_64_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_130, 15U * sizeof(real_T));
    }

    B_48_0_0 = 0.0;
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
      B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_1_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_36_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_31_38_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_31_40_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_31_42_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_31_44_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_31_46_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_31_48_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_31_50_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_31_52_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_31_54_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_31_56_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_31_58_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_31_60_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
      tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_31_62_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_34_0[i];
    }

    tmp_e[0] = B_48_0_0;
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
      ((BlockIO *) _ssGetBlockIO(S))->B_31_65_0[i] = tmp_e[i] + ((BlockIO *)
        _ssGetBlockIO(S))->B_31_64_0[i];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_66_0[i] = ((Parameters *)
        ssGetDefaultParam(S))->P_131 * ((BlockIO *) _ssGetBlockIO(S))->
        B_31_65_0[i];
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_68_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_132;
    }

    for (i = 0; i < 15; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_69_0[i] = muDoubleScalarExp(((BlockIO
        *) _ssGetBlockIO(S))->B_31_66_0[i]) + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_68_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_71_0[i] = 1.0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_31_69_0[i] * ((Parameters *) ssGetDefaultParam(S)
        )->P_133;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_72_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_134;
    }

    for (i = 0; i < 15; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_73_0[i] = ((BlockIO *) _ssGetBlockIO
        (S))->B_31_71_0[i] - ((BlockIO *) _ssGetBlockIO(S))->B_31_72_0;
    }

    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_75_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_135;
    }

    B_48_0_0 = 0.0;
    for (i = 0; i < 15; i++) {
      B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_0_0[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_31_73_0[i];
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_31_76_0 = B_48_0_0 + ((BlockIO *)
      _ssGetBlockIO(S))->B_31_75_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_77_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_76_0 + ((Parameters *) ssGetDefaultParam(S))->P_136;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_78_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_137 * ((BlockIO *) _ssGetBlockIO(S))->B_31_77_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_79_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_78_0 + ((Parameters *) ssGetDefaultParam(S))->P_138;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_80_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_79_0 >= ((Parameters *) ssGetDefaultParam(S))->P_139 ? ((Parameters
      *) ssGetDefaultParam(S))->P_139 : ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_79_0 <= ((Parameters *) ssGetDefaultParam(S))->P_140 ? ((Parameters
      *) ssGetDefaultParam(S))->P_140 : ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_79_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_81_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_80_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[3];
    if (ssIsSampleHit(S, 1, 0)) {
      ((BlockIO *) _ssGetBlockIO(S))->B_31_82_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_141;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_31_83_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_82_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[0];
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_84_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_142, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_86_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_144[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_86_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_144[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_87_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_145[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_87_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_145[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_88_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_146[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_88_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_146[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_89_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_147[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_89_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_147[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_90_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_148[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_90_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_148[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_91_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_149[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_91_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_149[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_92_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_150[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_92_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_150[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_93_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_151[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_93_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_151[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_94_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_152[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_94_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_152[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_95_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_153[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_95_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_153[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_96_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_154[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_96_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_154[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_97_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_155[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_97_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_155[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_98_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_156[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_98_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_156[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_99_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_157[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_99_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_157[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_100_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_158[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_100_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_158[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_101_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_159[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_101_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_159[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_102_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_160[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_102_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_160[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_103_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_161[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_103_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_161[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_104_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_162[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_104_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_162[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_105_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_163[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_105_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_163[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_106_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_164[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_106_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_164[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_107_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_165[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_107_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_165[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_108_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_166[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_108_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_166[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_109_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_167[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_109_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_167[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_110_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_168[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_110_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_168[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_111_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_169[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_111_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_169[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_112_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_170[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_112_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_170[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_113_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_171[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_113_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_171[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_114_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_172[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_114_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_172[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_115_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_173[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_115_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_173[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_117_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_175;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_118_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_176;
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_31_85_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_143[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_116_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_174[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_119_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_177[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_120_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_178[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_121_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_179[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_122_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_180[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_123_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_181[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_124_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_182[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_125_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_183[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_126_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_184[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_127_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_185[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_128_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_186[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_129_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_187[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_130_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_188[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_131_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_189[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_132_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_190[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_133_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_191[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_134_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_192[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_135_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_193[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_136_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_194[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_137_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_195[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_138_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_196[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_139_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_197[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_140_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_198[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_141_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_199[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_142_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_200[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_143_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_201[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_144_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_202[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_145_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_203[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_146_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_204[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_147_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_205[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_148_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_206[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_149_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_207[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_150_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_208[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_151_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_209[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_152_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_210[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_153_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_211[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_154_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_212[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_155_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_213[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_156_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_214[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_157_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_215[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_31_159_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_217;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_160_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_218;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_161_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_219;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_31_158_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_216[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_162_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_220[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_31_164_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_222[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_164_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_222[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_165_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_223[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_165_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_223[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_166_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_224[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_166_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_224[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_167_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_225[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_167_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_225[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_168_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_226[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_168_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_226[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_169_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_227[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_169_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_227[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_170_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_228[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_170_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_228[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_171_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_229[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_171_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_229[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_172_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_230[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_172_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_230[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_173_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_231[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_173_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_231[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_174_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_232[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_174_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_232[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_175_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_233[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_175_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_233[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_176_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_234[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_176_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_234[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_177_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_235[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_177_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_235[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_178_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_236[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_178_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_236[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_179_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_237[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_179_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_237[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_180_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_238[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_180_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_238[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_181_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_239[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_181_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_239[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_182_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_240[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_182_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_240[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_183_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_241[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_183_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_241[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_184_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_242[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_184_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_242[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_185_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_243[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_185_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_243[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_186_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_244[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_186_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_244[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_187_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_245[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_187_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_245[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_188_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_246[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_188_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_246[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_189_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_247[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_189_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_247[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_190_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_248[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_190_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_248[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_191_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_249[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_191_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_249[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_192_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_250[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_192_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_250[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_193_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_251[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_193_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_251[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_195_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_253;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_196_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_254;
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_31_163_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_221[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_194_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_252[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_197_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_255[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_198_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_256[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_199_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_257[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_200_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_258[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_201_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_259[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_202_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_260[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_203_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_261[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_204_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_262[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_205_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_263[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_206_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_264[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_207_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_265[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_208_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_266[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_209_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_267[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_210_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_268[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_211_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_269[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_212_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_270[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_213_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_271[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_214_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_272[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_215_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_273[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_216_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_274[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_217_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_275[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_218_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_276[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_219_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_277[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_220_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_278[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_221_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_279[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_222_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_280[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_223_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_281[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_224_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_282[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_225_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_283[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_226_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_284[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_227_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_285[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_228_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_286[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_229_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_287[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_230_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_288[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_231_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_289[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_232_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_290[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_233_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_291[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_234_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_292[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_235_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_293[i];
      }

      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_236_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_294, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_237_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_295;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_238_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_296;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_239_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_297;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_298) {
      ((BlockIO *) _ssGetBlockIO(S))->B_28_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_66[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_66[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_67[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_67[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_68;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_68;
      tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_31_86_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_86_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_31_87_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_87_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_31_88_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_88_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_31_89_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_89_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_31_90_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_90_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_31_91_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_91_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_31_92_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_92_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_31_93_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_93_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_31_94_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_94_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_31_95_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_95_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_31_96_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_96_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_31_97_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_97_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_31_98_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_98_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_31_99_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_99_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_31_100_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_100_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_31_101_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_101_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_31_102_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_102_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_31_103_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_103_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_31_104_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_104_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_31_105_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_105_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_31_106_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_106_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_31_107_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_107_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_31_108_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_108_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_31_109_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_109_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_31_110_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_110_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_31_111_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_111_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_31_112_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_112_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_31_113_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_113_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_31_114_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_114_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_31_115_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_28_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_115_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_28_2_0[1];
      B_48_0_0 = 0.0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_28_33_0[i] = tmp_f[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_116_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_34_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_69 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_28_33_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_36_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_28_34_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_117_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_38_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_28_36_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_70;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_39_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_28_38_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_118_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_85_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_119_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_31_120_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_31_121_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_31_122_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_31_123_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_31_124_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_31_125_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_31_126_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_31_127_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_31_128_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_31_129_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_31_130_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_31_131_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_31_132_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_31_133_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_31_134_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_31_135_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_31_136_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_31_137_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_31_138_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_31_139_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_31_140_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_31_141_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_31_142_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_31_143_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_31_144_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_31_145_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_31_146_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_31_147_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_31_148_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_31_149_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_31_150_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_31_151_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_31_152_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_31_153_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_31_154_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_31_155_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_31_156_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_31_157_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_39_0[i];
      }

      tmp_15[0] = B_48_0_0;
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
      B_48_0_0 = 0.0;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_28_80_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_158_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_81_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_71 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_28_80_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_28_83_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_28_81_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_159_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_85_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_28_83_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_72;
        ((BlockIO *) _ssGetBlockIO(S))->B_28_86_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_28_85_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_160_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_84_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_28_86_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_28_88_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_31_161_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_89_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_28_88_0 + ((Parameters *) ssGetDefaultParam(S))->P_73;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_90_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_74 * ((BlockIO *) _ssGetBlockIO(S))->B_28_89_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_28_91_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_28_90_0 + ((Parameters *) ssGetDefaultParam(S))->P_75;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_242_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_28_91_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_27_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_56[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_56[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_57[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_57[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_58;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_58;
      tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_31_164_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_164_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_31_165_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_165_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_31_166_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_166_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_31_167_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_167_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_31_168_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_168_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_31_169_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_169_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_31_170_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_170_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_31_171_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_171_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_31_172_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_172_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_31_173_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_173_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_31_174_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_174_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_31_175_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_175_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_31_176_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_176_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_31_177_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_177_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_31_178_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_178_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_31_179_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_179_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_31_180_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_180_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_31_181_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_181_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_31_182_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_182_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_31_183_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_183_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_31_184_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_184_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_31_185_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_185_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_31_186_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_186_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_31_187_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_187_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_31_188_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_188_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_31_189_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_189_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_31_190_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_190_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_31_191_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_191_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_31_192_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_192_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_31_193_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_27_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_193_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_27_2_0[1];
      B_48_0_0 = 0.0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_27_33_0[i] = tmp_f[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_194_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_34_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_59 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_27_33_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_36_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_27_34_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_195_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_38_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_27_36_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_60;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_39_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_27_38_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_196_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_163_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_197_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_31_198_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_31_199_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_31_200_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_31_201_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_31_202_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_31_203_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_31_204_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_31_205_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_31_206_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_31_207_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_31_208_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_31_209_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_31_210_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_31_211_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_31_212_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_31_213_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_31_214_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_31_215_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_31_216_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_31_217_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_31_218_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_31_219_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_31_220_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_31_221_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_31_222_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_31_223_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_31_224_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_31_225_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_31_226_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_31_227_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_31_228_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_31_229_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_31_230_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_31_231_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_31_232_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_31_233_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_31_234_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_31_235_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_39_0[i];
      }

      tmp_15[0] = B_48_0_0;
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
      B_48_0_0 = 0.0;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_27_80_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_236_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_81_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_61 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_27_80_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_27_83_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_27_81_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_237_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_85_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_27_83_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_62;
        ((BlockIO *) _ssGetBlockIO(S))->B_27_86_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_27_85_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_238_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_162_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_27_86_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_27_88_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_31_239_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_89_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_27_88_0 + ((Parameters *) ssGetDefaultParam(S))->P_63;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_90_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_64 * ((BlockIO *) _ssGetBlockIO(S))->B_27_89_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_27_91_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_27_90_0 + ((Parameters *) ssGetDefaultParam(S))->P_65;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_242_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_27_91_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_31_243_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_31_242_0 >= ((Parameters *) ssGetDefaultParam(S))->P_299 ?
      ((Parameters *) ssGetDefaultParam(S))->P_299 : ((BlockIO *) _ssGetBlockIO
      (S))->B_31_242_0 <= ((Parameters *) ssGetDefaultParam(S))->P_300 ?
      ((Parameters *) ssGetDefaultParam(S))->P_300 : ((BlockIO *) _ssGetBlockIO
      (S))->B_31_242_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_244_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_31_243_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[1];
    if (ssIsSampleHit(S, 1, 0)) {
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_245_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_301, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_247_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_303[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_247_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_303[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_248_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_304[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_248_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_304[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_249_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_305[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_249_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_305[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_250_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_306[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_250_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_306[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_251_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_307[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_251_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_307[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_252_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_308[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_252_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_308[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_253_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_309[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_253_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_309[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_254_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_310[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_254_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_310[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_255_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_311[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_255_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_311[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_256_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_312[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_256_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_312[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_257_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_313[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_257_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_313[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_258_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_314[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_258_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_314[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_259_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_315[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_259_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_315[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_260_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_316[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_260_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_316[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_261_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_317[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_261_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_317[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_262_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_318[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_262_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_318[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_263_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_319[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_263_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_319[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_264_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_320[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_264_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_320[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_265_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_321[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_265_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_321[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_266_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_322[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_266_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_322[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_268_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_324;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_269_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_325;
      for (i = 0; i < 20; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_31_246_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_302[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_267_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_323[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_270_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_326[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_271_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_327[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_272_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_328[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_273_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_329[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_274_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_330[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_275_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_331[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_276_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_332[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_277_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_333[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_278_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_334[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_279_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_335[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_280_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_336[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_281_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_337[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_282_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_338[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_283_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_339[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_284_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_340[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_285_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_341[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_286_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_342[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_287_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_343[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_288_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_344[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_289_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_345[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_290_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_346[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_291_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_347[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_292_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_348[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_293_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_349[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_294_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_350[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_295_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_351[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_296_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_352[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_297_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_353[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_298_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_354[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_299_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_355[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_300_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_356[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_301_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_357[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_302_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_358[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_303_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_359[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_304_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_360[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_305_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_361[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_306_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_362[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_307_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_363[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_308_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_364[i];
      }

      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_309_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_365, 40U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_310_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_366;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_311_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_367;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_312_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_368;
      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_313_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_369, 10U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_315_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_371[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_315_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_371[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_316_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_372[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_316_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_372[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_317_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_373[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_317_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_373[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_318_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_374[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_318_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_374[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_319_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_375[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_319_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_375[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_31_321_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_377;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_322_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_378;
      for (i = 0; i < 5; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_31_314_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_370[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_320_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_376[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_323_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_379[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_324_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_380[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_325_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_381[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_326_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_382[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_327_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_383[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_328_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_384[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_329_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_385[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_330_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_386[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_31_331_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_387[i];
      }

      memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_31_332_0[0]), (void *)
             ((Parameters *) ssGetDefaultParam(S))->P_388, 10U * sizeof(real_T));
      ((BlockIO *) _ssGetBlockIO(S))->B_31_333_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_389;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_334_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_390;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_335_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_391;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_392) {
      ((BlockIO *) _ssGetBlockIO(S))->B_30_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_86[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_30_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_86[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_30_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_87[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_30_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_30_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_87[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_30_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_30_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_88;
      ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_30_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_88;
      tmp_17[0] = ((BlockIO *) _ssGetBlockIO(S))->B_31_247_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_247_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[1] = ((BlockIO *) _ssGetBlockIO(S))->B_31_248_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_248_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[2] = ((BlockIO *) _ssGetBlockIO(S))->B_31_249_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_249_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[3] = ((BlockIO *) _ssGetBlockIO(S))->B_31_250_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_250_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[4] = ((BlockIO *) _ssGetBlockIO(S))->B_31_251_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_251_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[5] = ((BlockIO *) _ssGetBlockIO(S))->B_31_252_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_252_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[6] = ((BlockIO *) _ssGetBlockIO(S))->B_31_253_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_253_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[7] = ((BlockIO *) _ssGetBlockIO(S))->B_31_254_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_254_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[8] = ((BlockIO *) _ssGetBlockIO(S))->B_31_255_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_255_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[9] = ((BlockIO *) _ssGetBlockIO(S))->B_31_256_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_256_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[10] = ((BlockIO *) _ssGetBlockIO(S))->B_31_257_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_257_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[11] = ((BlockIO *) _ssGetBlockIO(S))->B_31_258_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_258_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[12] = ((BlockIO *) _ssGetBlockIO(S))->B_31_259_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_259_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[13] = ((BlockIO *) _ssGetBlockIO(S))->B_31_260_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_260_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[14] = ((BlockIO *) _ssGetBlockIO(S))->B_31_261_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_261_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[15] = ((BlockIO *) _ssGetBlockIO(S))->B_31_262_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_262_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[16] = ((BlockIO *) _ssGetBlockIO(S))->B_31_263_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_263_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[17] = ((BlockIO *) _ssGetBlockIO(S))->B_31_264_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_264_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[18] = ((BlockIO *) _ssGetBlockIO(S))->B_31_265_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_265_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      tmp_17[19] = ((BlockIO *) _ssGetBlockIO(S))->B_31_266_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_30_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_266_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_30_2_0[1];
      B_48_0_0 = 0.0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_30_23_0[i] = tmp_17[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_267_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_30_24_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_89 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_30_23_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_30_26_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_30_24_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_268_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_30_28_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_30_26_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_90;
        ((BlockIO *) _ssGetBlockIO(S))->B_30_29_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_30_28_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_269_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_246_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_270_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_31_271_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_31_272_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_31_273_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_31_274_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_31_275_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_31_276_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_31_277_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_31_278_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_31_279_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_31_280_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_31_281_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_31_282_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_31_283_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_31_284_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_31_285_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_31_286_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_31_287_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_31_288_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_31_289_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_31_290_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_31_291_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_31_292_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_31_293_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_31_294_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_31_295_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_31_296_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_31_297_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_31_298_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_31_299_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_31_300_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_31_301_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_31_302_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_31_303_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_31_304_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_31_305_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_31_306_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_31_307_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_31_308_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_29_0[i];
      }

      tmp_15[0] = B_48_0_0;
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
      B_48_0_0 = 0.0;
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_30_70_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_309_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_30_71_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_91 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_30_70_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_30_73_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_30_71_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_310_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_30_75_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_30_73_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_92;
        ((BlockIO *) _ssGetBlockIO(S))->B_30_76_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_30_75_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_311_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_245_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_30_76_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_30_78_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_31_312_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_30_79_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_30_78_0 + ((Parameters *) ssGetDefaultParam(S))->P_93;
      ((BlockIO *) _ssGetBlockIO(S))->B_30_80_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_94 * ((BlockIO *) _ssGetBlockIO(S))->B_30_79_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_30_81_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_30_80_0 + ((Parameters *) ssGetDefaultParam(S))->P_95;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_338_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_30_81_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_29_0_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_76[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_0_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_76[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_1_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_77[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_0_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_1_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_77[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_0_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_1_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_78;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_1_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_78;
      tmp_16[0] = ((BlockIO *) _ssGetBlockIO(S))->B_31_315_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_315_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1];
      tmp_16[1] = ((BlockIO *) _ssGetBlockIO(S))->B_31_316_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_316_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1];
      tmp_16[2] = ((BlockIO *) _ssGetBlockIO(S))->B_31_317_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_317_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1];
      tmp_16[3] = ((BlockIO *) _ssGetBlockIO(S))->B_31_318_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_318_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1];
      tmp_16[4] = ((BlockIO *) _ssGetBlockIO(S))->B_31_319_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_29_2_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_31_319_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_29_2_0[1];
      B_48_0_0 = 0.0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_29_8_0[i] = tmp_16[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_320_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_9_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_79 * ((BlockIO *) _ssGetBlockIO(S))->
          B_29_8_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_11_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_29_9_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_321_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_29_13_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_29_11_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_80;
        ((BlockIO *) _ssGetBlockIO(S))->B_29_14_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_29_13_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_322_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_314_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_323_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_31_324_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_31_325_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_31_326_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_31_327_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_31_328_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_31_329_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_31_330_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_31_331_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_14_0[i];
      }

      tmp[0] = B_48_0_0;
      tmp[1] = tmp_0;
      tmp[2] = tmp_1;
      tmp[3] = tmp_2;
      tmp[4] = tmp_3;
      tmp[5] = tmp_4;
      tmp[6] = tmp_5;
      tmp[7] = tmp_6;
      tmp[8] = tmp_7;
      tmp[9] = tmp_8;
      B_48_0_0 = 0.0;
      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_29_25_0[i] = tmp[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_332_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_26_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_81 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_29_25_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_29_28_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_29_26_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_31_333_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_29_30_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_29_28_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_82;
        ((BlockIO *) _ssGetBlockIO(S))->B_29_31_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_29_30_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_31_334_0;
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_31_313_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_29_31_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_29_33_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_31_335_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_34_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_29_33_0 + ((Parameters *) ssGetDefaultParam(S))->P_83;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_35_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_84 * ((BlockIO *) _ssGetBlockIO(S))->B_29_34_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_29_36_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_29_35_0 + ((Parameters *) ssGetDefaultParam(S))->P_85;
      ((BlockIO *) _ssGetBlockIO(S))->B_31_338_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_29_36_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_31_339_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_31_338_0 >= ((Parameters *) ssGetDefaultParam(S))->P_393 ?
      ((Parameters *) ssGetDefaultParam(S))->P_393 : ((BlockIO *) _ssGetBlockIO
      (S))->B_31_338_0 <= ((Parameters *) ssGetDefaultParam(S))->P_394 ?
      ((Parameters *) ssGetDefaultParam(S))->P_394 : ((BlockIO *) _ssGetBlockIO
      (S))->B_31_338_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_31_340_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_31_339_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[2];
    ((BlockIO *) _ssGetBlockIO(S))->B_31_341_0 = ((((BlockIO *) _ssGetBlockIO(S))
      ->B_31_81_0 + ((BlockIO *) _ssGetBlockIO(S))->B_31_83_0) + ((BlockIO *)
      _ssGetBlockIO(S))->B_31_244_0) + ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_340_0;
    if (ssIsSampleHit(S, 1, 0)) {
      /* Scope: '<S157>/Scope' */
      /* Call into Simulink for Scope */
      ssCallAccelRunBlock(S, 31, 342, SS_CALL_MDL_OUTPUTS);
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder05_SubsysRanBC);
    }
    break;

   case 1:
    if (ssIsMajorTimeStep(S)) {
      if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 <= 0.6) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_j = rtAction;
    } else {
      rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_j;
    }

    switch (rtAction) {
     case 0:
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_0_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_395, 60U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_1_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_396, 40U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_32_2_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_397[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_2_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_397[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_3_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_398[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_3_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_398[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_4_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_399[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_3_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_4_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_399[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_3_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[0] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_4_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_400;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_4_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_400;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_7_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_401[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_7_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_401[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_9_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_402[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_9_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_402[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_11_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_403[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_11_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_403[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_13_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_404[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_13_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_404[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_15_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_405[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_15_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_405[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_17_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_406[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_17_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_406[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_19_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_407[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_19_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_407[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_21_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_408[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_21_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_408[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_23_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_409[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_23_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_409[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_25_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_410[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_25_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_410[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_27_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_411[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_27_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_411[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_29_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_412[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_29_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_412[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_31_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_413[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_31_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_413[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_33_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_414[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_33_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_414[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_35_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_415[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_35_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_415[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_37_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_416[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_37_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_416[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_39_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_417[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_39_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_417[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_41_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_418[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_41_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_418[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_43_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_419[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_43_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_419[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_45_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_420[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_45_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_420[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_47_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_421[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_47_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_421[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_49_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_422[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_49_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_422[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_51_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_423[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_51_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_423[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_53_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_424[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_53_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_424[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_55_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_425[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_55_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_425[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_57_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_426[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_57_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_426[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_59_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_427[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_59_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_427[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_61_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_428[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_61_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_428[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_63_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_429[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_63_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_429[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_65_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_430[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_65_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_430[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_67_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_431[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_67_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_431[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_69_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_432[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_69_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_432[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_71_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_433[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_71_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_433[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_73_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_434[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_73_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_434[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_75_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_435[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_75_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_435[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_77_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_436[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_77_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_436[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_79_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_437[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_79_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_437[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_81_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_438[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_81_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_438[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_83_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_439[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_83_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_439[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_85_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_440, 40U * sizeof(real_T));
      }

      tmp_15[0] = ((BlockIO *) _ssGetBlockIO(S))->B_32_2_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[1] = ((BlockIO *) _ssGetBlockIO(S))->B_32_7_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[2] = ((BlockIO *) _ssGetBlockIO(S))->B_32_9_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[3] = ((BlockIO *) _ssGetBlockIO(S))->B_32_11_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[4] = ((BlockIO *) _ssGetBlockIO(S))->B_32_13_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[5] = ((BlockIO *) _ssGetBlockIO(S))->B_32_15_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[6] = ((BlockIO *) _ssGetBlockIO(S))->B_32_17_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[7] = ((BlockIO *) _ssGetBlockIO(S))->B_32_19_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[8] = ((BlockIO *) _ssGetBlockIO(S))->B_32_21_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[9] = ((BlockIO *) _ssGetBlockIO(S))->B_32_23_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[10] = ((BlockIO *) _ssGetBlockIO(S))->B_32_25_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[11] = ((BlockIO *) _ssGetBlockIO(S))->B_32_27_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[12] = ((BlockIO *) _ssGetBlockIO(S))->B_32_29_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[13] = ((BlockIO *) _ssGetBlockIO(S))->B_32_31_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[14] = ((BlockIO *) _ssGetBlockIO(S))->B_32_33_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[15] = ((BlockIO *) _ssGetBlockIO(S))->B_32_35_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[16] = ((BlockIO *) _ssGetBlockIO(S))->B_32_37_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[17] = ((BlockIO *) _ssGetBlockIO(S))->B_32_39_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[18] = ((BlockIO *) _ssGetBlockIO(S))->B_32_41_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[19] = ((BlockIO *) _ssGetBlockIO(S))->B_32_43_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[20] = ((BlockIO *) _ssGetBlockIO(S))->B_32_45_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[21] = ((BlockIO *) _ssGetBlockIO(S))->B_32_47_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[22] = ((BlockIO *) _ssGetBlockIO(S))->B_32_49_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[23] = ((BlockIO *) _ssGetBlockIO(S))->B_32_51_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[24] = ((BlockIO *) _ssGetBlockIO(S))->B_32_53_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[25] = ((BlockIO *) _ssGetBlockIO(S))->B_32_55_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_55_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[26] = ((BlockIO *) _ssGetBlockIO(S))->B_32_57_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_57_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[27] = ((BlockIO *) _ssGetBlockIO(S))->B_32_59_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_59_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[28] = ((BlockIO *) _ssGetBlockIO(S))->B_32_61_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_61_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[29] = ((BlockIO *) _ssGetBlockIO(S))->B_32_63_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_63_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[30] = ((BlockIO *) _ssGetBlockIO(S))->B_32_65_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_65_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[31] = ((BlockIO *) _ssGetBlockIO(S))->B_32_67_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_67_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[32] = ((BlockIO *) _ssGetBlockIO(S))->B_32_69_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_69_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[33] = ((BlockIO *) _ssGetBlockIO(S))->B_32_71_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_71_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[34] = ((BlockIO *) _ssGetBlockIO(S))->B_32_73_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_73_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[35] = ((BlockIO *) _ssGetBlockIO(S))->B_32_75_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_75_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[36] = ((BlockIO *) _ssGetBlockIO(S))->B_32_77_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_77_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[37] = ((BlockIO *) _ssGetBlockIO(S))->B_32_79_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_79_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[38] = ((BlockIO *) _ssGetBlockIO(S))->B_32_81_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_81_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      tmp_15[39] = ((BlockIO *) _ssGetBlockIO(S))->B_32_83_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_83_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_5_0[1];
      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_86_0[i] = tmp_15[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_85_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_87_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_441 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_86_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_89_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_442;
      }

      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_90_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_87_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_89_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_92_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_90_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_443;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_93_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_444;
      }

      for (i = 0; i < 40; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_94_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_92_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_93_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_96_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_445, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_98_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_446, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_100_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_447, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_102_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_448, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_104_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_449, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_106_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_450, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_108_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_451, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_110_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_452, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_112_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_453, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_114_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_454, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_116_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_455, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_118_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_456, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_120_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_457, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_122_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_458, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_124_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_459, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_126_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_460, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_128_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_461, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_130_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_462, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_132_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_463, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_134_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_464, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_136_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_465, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_138_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_466, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_140_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_467, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_142_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_468, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_144_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_469, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_146_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_470, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_148_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_471, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_150_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_472, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_152_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_473, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_154_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_474, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_156_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_475, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_158_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_476, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_160_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_477, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_162_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_478, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_164_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_479, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_166_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_480, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_168_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_481, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_170_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_482, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_172_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_483, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_174_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_484, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_176_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_485, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_178_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_486, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_180_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_487, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_182_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_488, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_184_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_489, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_186_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_490, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_188_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_491, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_190_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_492, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_192_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_493, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_194_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_494, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_196_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_495, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_198_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_496, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_200_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_497, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_202_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_498, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_204_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_499, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_206_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_500, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_208_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_501, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_210_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_502, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_212_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_503, 40U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_214_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_504, 60U * sizeof(real_T));
      }

      B_48_0_0 = 0.0;
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
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_1_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_96_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_32_98_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_32_100_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_32_102_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_32_104_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_32_106_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_32_108_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_32_110_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_32_112_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_32_114_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_32_116_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_32_118_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_32_120_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_32_122_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_32_124_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_32_126_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_32_128_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_32_130_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_32_132_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_32_134_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_32_136_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_32_138_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_32_140_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_32_142_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_32_144_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_32_146_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_32_148_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_32_150_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_32_152_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_32_154_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_32_156_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_32_158_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_32_160_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_32_162_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_32_164_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_32_166_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_32_168_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_32_170_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_32_172_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_32_174_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_32_176_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_32_178_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_32_180_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_32_182_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_32_184_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_32_186_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_32_188_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_32_190_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_32_192_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1i += ((BlockIO *) _ssGetBlockIO(S))->B_32_194_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1j += ((BlockIO *) _ssGetBlockIO(S))->B_32_196_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1k += ((BlockIO *) _ssGetBlockIO(S))->B_32_198_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1l += ((BlockIO *) _ssGetBlockIO(S))->B_32_200_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1m += ((BlockIO *) _ssGetBlockIO(S))->B_32_202_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1n += ((BlockIO *) _ssGetBlockIO(S))->B_32_204_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1o += ((BlockIO *) _ssGetBlockIO(S))->B_32_206_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1p += ((BlockIO *) _ssGetBlockIO(S))->B_32_208_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1q += ((BlockIO *) _ssGetBlockIO(S))->B_32_210_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
        tmp_1r += ((BlockIO *) _ssGetBlockIO(S))->B_32_212_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_94_0[i];
      }

      tmp_1s[0] = B_48_0_0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_32_215_0[i] = tmp_1s[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_214_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_216_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_505 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_215_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_218_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_506;
      }

      for (i = 0; i < 60; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_219_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_216_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_218_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_221_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_219_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_507;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_222_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_508;
      }

      for (i = 0; i < 60; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_223_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_221_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_222_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_225_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_509;
      }

      B_48_0_0 = 0.0;
      for (i = 0; i < 60; i++) {
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_0_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_223_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_226_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_32_225_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_227_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_226_0 + ((Parameters *) ssGetDefaultParam(S))->P_510;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_228_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_511 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_227_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_229_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_228_0 + ((Parameters *) ssGetDefaultParam(S))->P_512;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_230_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_229_0 >= ((Parameters *) ssGetDefaultParam(S))->P_513 ?
        ((Parameters *) ssGetDefaultParam(S))->P_513 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_229_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_514 ? ((Parameters *) ssGetDefaultParam(S))->P_514 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_229_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_231_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_230_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[3];
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_232_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_515, 10U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_233_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_516, 15U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_32_234_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_517[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_234_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_517[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_235_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_518[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_235_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_518[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_236_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_519[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_235_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_236_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_519[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_235_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_32_236_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_520;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_32_236_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_520;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_239_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_521[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_239_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_521[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_241_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_522[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_241_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_522[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_243_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_523[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_243_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_523[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_245_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_524[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_245_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_524[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_247_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_525[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_247_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_525[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_249_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_526[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_249_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_526[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_251_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_527[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_251_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_527[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_253_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_528[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_253_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_528[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_255_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_529[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_255_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_529[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_257_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_530[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_257_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_530[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_259_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_531[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_259_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_531[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_261_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_532[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_261_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_532[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_263_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_533[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_263_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_533[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_265_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_534[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_265_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_534[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_267_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_535, 15U * sizeof(real_T));
      }

      tmp_e[0] = ((BlockIO *) _ssGetBlockIO(S))->B_32_234_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_234_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[1] = ((BlockIO *) _ssGetBlockIO(S))->B_32_239_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_239_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[2] = ((BlockIO *) _ssGetBlockIO(S))->B_32_241_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_241_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[3] = ((BlockIO *) _ssGetBlockIO(S))->B_32_243_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_243_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[4] = ((BlockIO *) _ssGetBlockIO(S))->B_32_245_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_245_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[5] = ((BlockIO *) _ssGetBlockIO(S))->B_32_247_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_247_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[6] = ((BlockIO *) _ssGetBlockIO(S))->B_32_249_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_249_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[7] = ((BlockIO *) _ssGetBlockIO(S))->B_32_251_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_251_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[8] = ((BlockIO *) _ssGetBlockIO(S))->B_32_253_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_253_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[9] = ((BlockIO *) _ssGetBlockIO(S))->B_32_255_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_255_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[10] = ((BlockIO *) _ssGetBlockIO(S))->B_32_257_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_257_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[11] = ((BlockIO *) _ssGetBlockIO(S))->B_32_259_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_259_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[12] = ((BlockIO *) _ssGetBlockIO(S))->B_32_261_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_261_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[13] = ((BlockIO *) _ssGetBlockIO(S))->B_32_263_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_263_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      tmp_e[14] = ((BlockIO *) _ssGetBlockIO(S))->B_32_265_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_237_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_265_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_237_0[1];
      for (i = 0; i < 15; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_268_0[i] = tmp_e[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_267_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_269_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_536 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_268_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_271_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_537;
      }

      for (i = 0; i < 15; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_272_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_269_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_271_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_274_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_272_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_538;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_275_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_539;
      }

      for (i = 0; i < 15; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_276_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_274_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_275_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_278_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_540, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_280_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_541, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_282_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_542, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_284_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_543, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_286_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_544, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_288_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_545, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_290_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_546, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_292_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_547, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_294_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_548, 15U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_296_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_549, 10U * sizeof(real_T));
      }

      B_48_0_0 = 0.0;
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
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_233_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_278_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_32_280_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_32_282_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_32_284_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_32_286_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_32_288_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_32_290_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_32_292_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_32_294_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_276_0[i];
      }

      tmp[0] = B_48_0_0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_32_297_0[i] = tmp[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_296_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_298_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_550 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_297_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_300_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_551;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_301_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_298_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_300_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_303_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_301_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_552;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_304_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_553;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_305_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_303_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_304_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_307_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_554;
      }

      B_48_0_0 = 0.0;
      for (i = 0; i < 10; i++) {
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_232_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_305_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_308_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_32_307_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_309_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_308_0 + ((Parameters *) ssGetDefaultParam(S))->P_555;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_310_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_556 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_309_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_311_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_310_0 + ((Parameters *) ssGetDefaultParam(S))->P_557;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_312_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_311_0 >= ((Parameters *) ssGetDefaultParam(S))->P_558 ?
        ((Parameters *) ssGetDefaultParam(S))->P_558 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_311_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_559 ? ((Parameters *) ssGetDefaultParam(S))->P_559 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_311_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_313_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_312_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[0];
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_314_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_560, 45U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_315_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_561, 35U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_32_316_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_562[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_316_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_562[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_317_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_563[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_317_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_563[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_318_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_564[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_317_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_318_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_564[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_317_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_32_318_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_565;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_32_318_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_565;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_321_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_566[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_321_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_566[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_323_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_567[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_323_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_567[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_325_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_568[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_325_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_568[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_327_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_569[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_327_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_569[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_329_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_570[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_329_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_570[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_331_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_571[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_331_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_571[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_333_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_572[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_333_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_572[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_335_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_573[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_335_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_573[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_337_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_574[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_337_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_574[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_339_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_575[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_339_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_575[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_341_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_576[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_341_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_576[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_343_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_577[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_343_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_577[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_345_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_578[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_345_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_578[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_347_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_579[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_347_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_579[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_349_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_580[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_349_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_580[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_351_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_581[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_351_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_581[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_353_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_582[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_353_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_582[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_355_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_583[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_355_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_583[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_357_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_584[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_357_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_584[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_359_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_585[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_359_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_585[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_361_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_586[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_361_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_586[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_363_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_587[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_363_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_587[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_365_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_588[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_365_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_588[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_367_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_589[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_367_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_589[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_369_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_590[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_369_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_590[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_371_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_591[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_371_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_591[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_373_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_592[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_373_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_592[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_375_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_593[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_375_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_593[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_377_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_594[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_377_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_594[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_379_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_595[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_379_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_595[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_381_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_596[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_381_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_596[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_383_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_597[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_383_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_597[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_385_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_598[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_385_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_598[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_387_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_599[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_387_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_599[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_389_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_600, 35U * sizeof(real_T));
      }

      tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_32_316_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_316_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_32_321_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_321_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_32_323_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_323_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_32_325_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_325_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_32_327_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_327_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_32_329_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_329_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_32_331_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_331_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_32_333_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_333_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_32_335_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_335_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_32_337_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_337_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_32_339_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_339_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_32_341_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_341_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_32_343_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_343_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_32_345_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_345_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_32_347_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_347_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_32_349_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_349_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_32_351_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_351_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_32_353_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_353_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_32_355_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_355_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_32_357_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_357_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_32_359_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_359_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_32_361_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_361_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_32_363_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_363_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_32_365_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_365_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_32_367_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_367_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_32_369_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_369_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_32_371_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_371_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_32_373_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_373_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_32_375_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_375_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_32_377_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_377_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_32_379_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_379_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_32_381_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_381_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_32_383_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_383_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_32_385_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_385_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_32_387_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_319_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_387_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_319_0[1];
      for (i = 0; i < 35; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_390_0[i] = tmp_1t[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_389_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_391_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_601 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_390_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_393_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_602;
      }

      for (i = 0; i < 35; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_394_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_391_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_393_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_396_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_394_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_603;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_397_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_604;
      }

      for (i = 0; i < 35; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_398_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_396_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_397_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_400_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_605, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_402_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_606, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_404_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_607, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_406_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_608, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_408_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_609, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_410_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_610, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_412_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_611, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_414_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_612, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_416_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_613, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_418_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_614, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_420_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_615, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_422_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_616, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_424_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_617, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_426_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_618, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_428_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_619, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_430_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_620, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_432_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_621, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_434_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_622, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_436_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_623, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_438_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_624, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_440_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_625, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_442_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_626, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_444_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_627, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_446_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_628, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_448_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_629, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_450_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_630, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_452_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_631, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_454_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_632, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_456_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_633, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_458_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_634, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_460_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_635, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_462_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_636, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_464_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_637, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_466_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_638, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_468_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_639, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_470_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_640, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_472_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_641, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_474_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_642, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_476_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_643, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_478_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_644, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_480_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_645, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_482_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_646, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_484_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_647, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_486_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_648, 35U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_488_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_649, 45U * sizeof(real_T));
      }

      B_48_0_0 = 0.0;
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
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_315_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_400_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_32_402_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_32_404_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_32_406_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_32_408_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_32_410_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_32_412_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_32_414_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_32_416_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_32_418_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_32_420_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_32_422_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_32_424_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_32_426_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_32_428_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_32_430_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_32_432_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_32_434_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_32_436_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_32_438_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_32_440_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_32_442_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_32_444_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_32_446_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_32_448_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_32_450_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_32_452_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_32_454_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_32_456_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_32_458_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_32_460_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_32_462_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_32_464_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_32_466_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_32_468_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_32_470_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_32_472_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_32_474_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_32_476_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_32_478_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_32_480_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_32_482_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_32_484_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
        tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_32_486_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_398_0[i];
      }

      tmp_1u[0] = B_48_0_0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_32_489_0[i] = tmp_1u[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_488_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_490_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_650 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_489_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_492_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_651;
      }

      for (i = 0; i < 45; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_493_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_490_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_492_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_495_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_493_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_652;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_496_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_653;
      }

      for (i = 0; i < 45; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_497_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_495_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_496_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_499_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_654;
      }

      B_48_0_0 = 0.0;
      for (i = 0; i < 45; i++) {
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_314_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_497_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_500_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_32_499_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_501_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_500_0 + ((Parameters *) ssGetDefaultParam(S))->P_655;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_502_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_656 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_501_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_503_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_502_0 + ((Parameters *) ssGetDefaultParam(S))->P_657;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_504_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_503_0 >= ((Parameters *) ssGetDefaultParam(S))->P_658 ?
        ((Parameters *) ssGetDefaultParam(S))->P_658 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_503_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_659 ? ((Parameters *) ssGetDefaultParam(S))->P_659 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_503_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_505_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_504_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[1];
      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_506_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_660, 10U * sizeof(real_T));
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_507_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_661, 30U * sizeof(real_T));
        ((BlockIO *) _ssGetBlockIO(S))->B_32_508_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_662[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_508_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_662[1];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_509_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_663[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_509_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_663[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_510_0[0] = ((Parameters *)
        ssGetDefaultParam(S))->P_664[0] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_509_0[0];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_510_0[1] = ((Parameters *)
        ssGetDefaultParam(S))->P_664[1] * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_509_0[1];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[0] = ((BlockIO *) _ssGetBlockIO
        (S))->B_32_510_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_665;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1] = ((BlockIO *) _ssGetBlockIO
        (S))->B_32_510_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_665;
      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_513_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_666[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_513_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_666[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_515_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_667[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_515_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_667[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_517_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_668[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_517_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_668[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_519_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_669[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_519_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_669[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_521_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_670[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_521_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_670[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_523_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_671[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_523_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_671[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_525_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_672[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_525_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_672[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_527_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_673[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_527_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_673[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_529_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_674[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_529_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_674[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_531_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_675[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_531_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_675[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_533_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_676[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_533_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_676[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_535_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_677[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_535_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_677[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_537_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_678[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_537_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_678[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_539_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_679[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_539_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_679[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_541_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_680[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_541_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_680[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_543_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_681[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_543_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_681[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_545_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_682[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_545_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_682[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_547_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_683[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_547_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_683[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_549_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_684[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_549_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_684[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_551_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_685[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_551_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_685[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_553_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_686[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_553_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_686[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_555_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_687[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_555_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_687[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_557_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_688[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_557_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_688[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_559_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_689[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_559_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_689[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_561_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_690[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_561_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_690[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_563_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_691[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_563_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_691[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_565_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_692[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_565_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_692[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_567_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_693[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_567_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_693[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_569_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_694[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_569_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_694[1];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_571_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_695, 30U * sizeof(real_T));
      }

      tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_32_508_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_508_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_32_513_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_513_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_32_515_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_515_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_32_517_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_517_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_32_519_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_519_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_32_521_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_521_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_32_523_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_523_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_32_525_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_525_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_32_527_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_527_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_32_529_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_529_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_32_531_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_531_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_32_533_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_533_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_32_535_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_535_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_32_537_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_537_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_32_539_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_539_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_32_541_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_541_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_32_543_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_543_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_32_545_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_545_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_32_547_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_547_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_32_549_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_549_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_32_551_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_551_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_32_553_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_553_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_32_555_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_555_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_32_557_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_557_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_32_559_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_559_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_32_561_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_561_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_32_563_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_563_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_32_565_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_565_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_32_567_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_567_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_32_569_0[0] * ((BlockIO *)
        _ssGetBlockIO(S))->B_32_511_0[0] + ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_569_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_32_511_0[1];
      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_572_0[i] = tmp_f[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_571_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_573_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_696 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_572_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_575_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_697;
      }

      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_576_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_573_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_575_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_578_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_576_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_698;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_579_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_699;
      }

      for (i = 0; i < 30; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_580_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_578_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_579_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_582_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_700, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_584_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_701, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_586_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_702, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_588_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_703, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_590_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_704, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_592_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_705, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_594_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_706, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_596_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_707, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_598_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_708, 30U * sizeof(real_T));
      }

      if (ssIsSampleHit(S, 1, 0)) {
        memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_32_600_0[0]), (void *)
               ((Parameters *) ssGetDefaultParam(S))->P_709, 10U * sizeof(real_T));
      }

      B_48_0_0 = 0.0;
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
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_507_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_582_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_32_584_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_32_586_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_32_588_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_32_590_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_32_592_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_32_594_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_32_596_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
        tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_32_598_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_580_0[i];
      }

      tmp[0] = B_48_0_0;
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
        ((BlockIO *) _ssGetBlockIO(S))->B_32_601_0[i] = tmp[i] + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_600_0[i];
        ((BlockIO *) _ssGetBlockIO(S))->B_32_602_0[i] = ((Parameters *)
          ssGetDefaultParam(S))->P_710 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_601_0[i];
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_604_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_711;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_605_0[i] = muDoubleScalarExp
          (((BlockIO *) _ssGetBlockIO(S))->B_32_602_0[i]) + ((BlockIO *)
          _ssGetBlockIO(S))->B_32_604_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_32_607_0[i] = 1.0 / ((BlockIO *)
          _ssGetBlockIO(S))->B_32_605_0[i] * ((Parameters *) ssGetDefaultParam(S))
          ->P_712;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_608_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_713;
      }

      for (i = 0; i < 10; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_609_0[i] = ((BlockIO *)
          _ssGetBlockIO(S))->B_32_607_0[i] - ((BlockIO *) _ssGetBlockIO(S))
          ->B_32_608_0;
      }

      if (ssIsSampleHit(S, 1, 0)) {
        ((BlockIO *) _ssGetBlockIO(S))->B_32_611_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_714;
      }

      B_48_0_0 = 0.0;
      for (i = 0; i < 10; i++) {
        B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_32_506_0[i] * ((BlockIO *)
          _ssGetBlockIO(S))->B_32_609_0[i];
      }

      ((BlockIO *) _ssGetBlockIO(S))->B_32_612_0 = B_48_0_0 + ((BlockIO *)
        _ssGetBlockIO(S))->B_32_611_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_613_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_612_0 + ((Parameters *) ssGetDefaultParam(S))->P_715;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_614_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_716 * ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_613_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_615_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_614_0 + ((Parameters *) ssGetDefaultParam(S))->P_717;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_616_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_615_0 >= ((Parameters *) ssGetDefaultParam(S))->P_718 ?
        ((Parameters *) ssGetDefaultParam(S))->P_718 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_615_0 <= ((Parameters *) ssGetDefaultParam(S))
        ->P_719 ? ((Parameters *) ssGetDefaultParam(S))->P_719 : ((BlockIO *)
        _ssGetBlockIO(S))->B_32_615_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_32_617_0 = ((BlockIO *) _ssGetBlockIO(S))
        ->B_32_616_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[2];
      ((BlockIO *) _ssGetBlockIO(S))->B_32_618_0 = ((((BlockIO *) _ssGetBlockIO
        (S))->B_32_231_0 + ((BlockIO *) _ssGetBlockIO(S))->B_32_313_0) +
        ((BlockIO *) _ssGetBlockIO(S))->B_32_505_0) + ((BlockIO *) _ssGetBlockIO
        (S))->B_32_617_0;
      if (ssIsMajorTimeStep(S)) {
        srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder06_SubsysRanBC);
      }
      break;

     case 1:
      if (ssIsMajorTimeStep(S)) {
        if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 <= 0.7) {
          rtAction = 0;
        } else {
          rtAction = 1;
        }

        ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_i = rtAction;
      } else {
        rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_i;
      }

      switch (rtAction) {
       case 0:
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_0_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_720, 65U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_1_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_721, 40U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_33_2_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_722[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_2_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_722[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_3_0[0] = ((BlockIO *) _ssGetBlockIO
          (S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))->P_723[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_3_0[1] = ((BlockIO *) _ssGetBlockIO
          (S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))->P_723[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_4_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_724[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_3_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_4_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_724[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_3_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[0] = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_4_0[0] + ((Parameters *) ssGetDefaultParam(S))->P_725;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1] = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_4_0[1] + ((Parameters *) ssGetDefaultParam(S))->P_725;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_7_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_726[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_7_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_726[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_9_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_727[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_9_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_727[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_11_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_728[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_11_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_728[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_13_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_729[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_13_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_729[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_15_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_730[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_15_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_730[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_17_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_731[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_17_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_731[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_19_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_732[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_19_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_732[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_21_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_733[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_21_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_733[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_23_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_734[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_23_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_734[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_25_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_735[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_25_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_735[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_27_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_736[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_27_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_736[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_29_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_737[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_29_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_737[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_31_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_738[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_31_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_738[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_33_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_739[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_33_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_739[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_35_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_740[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_35_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_740[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_37_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_741[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_37_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_741[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_39_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_742[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_39_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_742[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_41_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_743[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_41_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_743[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_43_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_744[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_43_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_744[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_45_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_745[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_45_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_745[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_47_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_746[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_47_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_746[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_49_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_747[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_49_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_747[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_51_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_748[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_51_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_748[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_53_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_749[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_53_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_749[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_55_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_750[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_55_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_750[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_57_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_751[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_57_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_751[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_59_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_752[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_59_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_752[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_61_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_753[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_61_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_753[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_63_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_754[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_63_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_754[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_65_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_755[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_65_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_755[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_67_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_756[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_67_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_756[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_69_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_757[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_69_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_757[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_71_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_758[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_71_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_758[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_73_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_759[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_73_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_759[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_75_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_760[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_75_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_760[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_77_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_761[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_77_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_761[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_79_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_762[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_79_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_762[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_81_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_763[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_81_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_763[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_83_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_764[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_83_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_764[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_85_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_765, 40U * sizeof
                 (real_T));
        }

        tmp_15[0] = ((BlockIO *) _ssGetBlockIO(S))->B_33_2_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[1] = ((BlockIO *) _ssGetBlockIO(S))->B_33_7_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[2] = ((BlockIO *) _ssGetBlockIO(S))->B_33_9_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[3] = ((BlockIO *) _ssGetBlockIO(S))->B_33_11_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[4] = ((BlockIO *) _ssGetBlockIO(S))->B_33_13_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[5] = ((BlockIO *) _ssGetBlockIO(S))->B_33_15_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[6] = ((BlockIO *) _ssGetBlockIO(S))->B_33_17_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[7] = ((BlockIO *) _ssGetBlockIO(S))->B_33_19_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[8] = ((BlockIO *) _ssGetBlockIO(S))->B_33_21_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[9] = ((BlockIO *) _ssGetBlockIO(S))->B_33_23_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[10] = ((BlockIO *) _ssGetBlockIO(S))->B_33_25_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[11] = ((BlockIO *) _ssGetBlockIO(S))->B_33_27_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[12] = ((BlockIO *) _ssGetBlockIO(S))->B_33_29_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[13] = ((BlockIO *) _ssGetBlockIO(S))->B_33_31_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[14] = ((BlockIO *) _ssGetBlockIO(S))->B_33_33_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[15] = ((BlockIO *) _ssGetBlockIO(S))->B_33_35_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[16] = ((BlockIO *) _ssGetBlockIO(S))->B_33_37_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[17] = ((BlockIO *) _ssGetBlockIO(S))->B_33_39_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[18] = ((BlockIO *) _ssGetBlockIO(S))->B_33_41_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[19] = ((BlockIO *) _ssGetBlockIO(S))->B_33_43_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[20] = ((BlockIO *) _ssGetBlockIO(S))->B_33_45_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[21] = ((BlockIO *) _ssGetBlockIO(S))->B_33_47_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[22] = ((BlockIO *) _ssGetBlockIO(S))->B_33_49_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[23] = ((BlockIO *) _ssGetBlockIO(S))->B_33_51_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[24] = ((BlockIO *) _ssGetBlockIO(S))->B_33_53_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[25] = ((BlockIO *) _ssGetBlockIO(S))->B_33_55_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_55_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[26] = ((BlockIO *) _ssGetBlockIO(S))->B_33_57_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_57_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[27] = ((BlockIO *) _ssGetBlockIO(S))->B_33_59_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_59_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[28] = ((BlockIO *) _ssGetBlockIO(S))->B_33_61_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_61_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[29] = ((BlockIO *) _ssGetBlockIO(S))->B_33_63_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_63_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[30] = ((BlockIO *) _ssGetBlockIO(S))->B_33_65_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_65_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[31] = ((BlockIO *) _ssGetBlockIO(S))->B_33_67_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_67_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[32] = ((BlockIO *) _ssGetBlockIO(S))->B_33_69_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_69_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[33] = ((BlockIO *) _ssGetBlockIO(S))->B_33_71_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_71_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[34] = ((BlockIO *) _ssGetBlockIO(S))->B_33_73_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_73_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[35] = ((BlockIO *) _ssGetBlockIO(S))->B_33_75_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_75_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[36] = ((BlockIO *) _ssGetBlockIO(S))->B_33_77_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_77_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[37] = ((BlockIO *) _ssGetBlockIO(S))->B_33_79_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_79_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[38] = ((BlockIO *) _ssGetBlockIO(S))->B_33_81_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_81_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        tmp_15[39] = ((BlockIO *) _ssGetBlockIO(S))->B_33_83_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_83_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_5_0[1];
        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_86_0[i] = tmp_15[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_85_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_87_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_766 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_86_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_89_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_767;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_90_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_87_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_89_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_92_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_90_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_768;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_93_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_769;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_94_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_92_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_93_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_96_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_770, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_98_0[0]), (void *)
                 ((Parameters *) ssGetDefaultParam(S))->P_771, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_100_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_772, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_102_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_773, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_104_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_774, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_106_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_775, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_108_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_776, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_110_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_777, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_112_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_778, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_114_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_779, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_116_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_780, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_118_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_781, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_120_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_782, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_122_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_783, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_124_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_784, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_126_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_785, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_128_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_786, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_130_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_787, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_132_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_788, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_134_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_789, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_136_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_790, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_138_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_791, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_140_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_792, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_142_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_793, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_144_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_794, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_146_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_795, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_148_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_796, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_150_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_797, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_152_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_798, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_154_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_799, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_156_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_800, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_158_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_801, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_160_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_802, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_162_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_803, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_164_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_804, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_166_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_805, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_168_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_806, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_170_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_807, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_172_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_808, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_174_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_809, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_176_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_810, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_178_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_811, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_180_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_812, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_182_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_813, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_184_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_814, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_186_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_815, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_188_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_816, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_190_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_817, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_192_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_818, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_194_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_819, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_196_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_820, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_198_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_821, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_200_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_822, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_202_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_823, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_204_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_824, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_206_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_825, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_208_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_826, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_210_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_827, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_212_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_828, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_214_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_829, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_216_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_830, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_218_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_831, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_220_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_832, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_222_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_833, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_224_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_834, 65U * sizeof
                 (real_T));
        }

        B_48_0_0 = 0.0;
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
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_1_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_96_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_33_98_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_33_100_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_33_102_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_33_104_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_33_106_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_33_108_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_33_110_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_33_112_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_33_114_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_33_116_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_33_118_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_33_120_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_33_122_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_33_124_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_33_126_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_33_128_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_33_130_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_33_132_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_33_134_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_33_136_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_33_138_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_33_140_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_33_142_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_33_144_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_33_146_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_33_148_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_33_150_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_33_152_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_33_154_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_33_156_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_33_158_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_33_160_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_33_162_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_33_164_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_33_166_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_33_168_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_33_170_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_33_172_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_33_174_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_33_176_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_33_178_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_33_180_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_33_182_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_33_184_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_33_186_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_33_188_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_33_190_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_33_192_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1i += ((BlockIO *) _ssGetBlockIO(S))->B_33_194_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1j += ((BlockIO *) _ssGetBlockIO(S))->B_33_196_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1k += ((BlockIO *) _ssGetBlockIO(S))->B_33_198_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1l += ((BlockIO *) _ssGetBlockIO(S))->B_33_200_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1m += ((BlockIO *) _ssGetBlockIO(S))->B_33_202_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1n += ((BlockIO *) _ssGetBlockIO(S))->B_33_204_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1o += ((BlockIO *) _ssGetBlockIO(S))->B_33_206_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1p += ((BlockIO *) _ssGetBlockIO(S))->B_33_208_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1q += ((BlockIO *) _ssGetBlockIO(S))->B_33_210_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1r += ((BlockIO *) _ssGetBlockIO(S))->B_33_212_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1v += ((BlockIO *) _ssGetBlockIO(S))->B_33_214_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1w += ((BlockIO *) _ssGetBlockIO(S))->B_33_216_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1x += ((BlockIO *) _ssGetBlockIO(S))->B_33_218_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1y += ((BlockIO *) _ssGetBlockIO(S))->B_33_220_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
          tmp_1z += ((BlockIO *) _ssGetBlockIO(S))->B_33_222_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_94_0[i];
        }

        tmp_20[0] = B_48_0_0;
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
          ((BlockIO *) _ssGetBlockIO(S))->B_33_225_0[i] = tmp_20[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_224_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_226_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_835 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_225_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_228_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_836;
        }

        for (i = 0; i < 65; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_229_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_226_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_228_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_231_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_229_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_837;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_232_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_838;
        }

        for (i = 0; i < 65; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_233_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_231_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_232_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_235_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_839;
        }

        B_48_0_0 = 0.0;
        for (i = 0; i < 65; i++) {
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_0_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_233_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_236_0 = B_48_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_33_235_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_237_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_236_0 + ((Parameters *) ssGetDefaultParam(S))->P_840;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_238_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_841 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_237_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_239_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_238_0 + ((Parameters *) ssGetDefaultParam(S))->P_842;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_240_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_239_0 >= ((Parameters *) ssGetDefaultParam(S))->P_843 ?
          ((Parameters *) ssGetDefaultParam(S))->P_843 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_239_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_844 ? ((Parameters *) ssGetDefaultParam(S))->P_844 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_239_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_241_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_240_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[3];
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_242_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_845, 20U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_243_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_846, 15U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_33_244_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_847[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_244_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_847[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_245_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_848[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_245_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_848[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_246_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_849[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_245_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_246_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_849[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_245_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_33_246_0[0] + ((Parameters *) ssGetDefaultParam(S))
          ->P_850;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_33_246_0[1] + ((Parameters *) ssGetDefaultParam(S))
          ->P_850;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_249_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_851[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_249_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_851[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_251_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_852[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_251_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_852[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_253_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_853[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_253_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_853[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_255_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_854[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_255_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_854[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_257_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_855[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_257_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_855[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_259_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_856[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_259_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_856[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_261_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_857[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_261_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_857[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_263_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_858[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_263_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_858[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_265_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_859[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_265_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_859[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_267_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_860[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_267_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_860[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_269_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_861[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_269_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_861[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_271_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_862[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_271_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_862[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_273_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_863[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_273_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_863[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_275_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_864[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_275_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_864[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_277_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_865, 15U * sizeof
                 (real_T));
        }

        tmp_e[0] = ((BlockIO *) _ssGetBlockIO(S))->B_33_244_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_244_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[1] = ((BlockIO *) _ssGetBlockIO(S))->B_33_249_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_249_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[2] = ((BlockIO *) _ssGetBlockIO(S))->B_33_251_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_251_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[3] = ((BlockIO *) _ssGetBlockIO(S))->B_33_253_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_253_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[4] = ((BlockIO *) _ssGetBlockIO(S))->B_33_255_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_255_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[5] = ((BlockIO *) _ssGetBlockIO(S))->B_33_257_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_257_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[6] = ((BlockIO *) _ssGetBlockIO(S))->B_33_259_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_259_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[7] = ((BlockIO *) _ssGetBlockIO(S))->B_33_261_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_261_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[8] = ((BlockIO *) _ssGetBlockIO(S))->B_33_263_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_263_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[9] = ((BlockIO *) _ssGetBlockIO(S))->B_33_265_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_265_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[10] = ((BlockIO *) _ssGetBlockIO(S))->B_33_267_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_267_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[11] = ((BlockIO *) _ssGetBlockIO(S))->B_33_269_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_269_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[12] = ((BlockIO *) _ssGetBlockIO(S))->B_33_271_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_271_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[13] = ((BlockIO *) _ssGetBlockIO(S))->B_33_273_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_273_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        tmp_e[14] = ((BlockIO *) _ssGetBlockIO(S))->B_33_275_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_247_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_275_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_247_0[1];
        for (i = 0; i < 15; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_278_0[i] = tmp_e[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_277_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_279_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_866 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_278_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_281_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_867;
        }

        for (i = 0; i < 15; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_282_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_279_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_281_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_284_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_282_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_868;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_285_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_869;
        }

        for (i = 0; i < 15; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_286_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_284_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_285_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_288_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_870, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_290_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_871, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_292_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_872, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_294_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_873, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_296_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_874, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_298_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_875, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_300_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_876, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_302_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_877, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_304_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_878, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_306_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_879, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_308_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_880, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_310_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_881, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_312_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_882, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_314_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_883, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_316_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_884, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_318_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_885, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_320_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_886, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_322_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_887, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_324_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_888, 15U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_326_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_889, 20U * sizeof
                 (real_T));
        }

        B_48_0_0 = 0.0;
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
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_243_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_288_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_33_290_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_33_292_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_33_294_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_33_296_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_33_298_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_33_300_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_33_302_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_33_304_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_33_306_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_33_308_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_33_310_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_33_312_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_33_314_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_33_316_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_33_318_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_33_320_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_33_322_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_33_324_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_286_0[i];
        }

        tmp_17[0] = B_48_0_0;
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
          ((BlockIO *) _ssGetBlockIO(S))->B_33_327_0[i] = tmp_17[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_326_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_328_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_890 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_327_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_330_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_891;
        }

        for (i = 0; i < 20; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_331_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_328_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_330_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_333_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_331_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_892;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_334_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_893;
        }

        for (i = 0; i < 20; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_335_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_333_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_334_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_337_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_894;
        }

        B_48_0_0 = 0.0;
        for (i = 0; i < 20; i++) {
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_242_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_335_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_338_0 = B_48_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_33_337_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_339_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_338_0 + ((Parameters *) ssGetDefaultParam(S))->P_895;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_340_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_896 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_339_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_341_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_340_0 + ((Parameters *) ssGetDefaultParam(S))->P_897;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_342_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_341_0 >= ((Parameters *) ssGetDefaultParam(S))->P_898 ?
          ((Parameters *) ssGetDefaultParam(S))->P_898 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_341_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_899 ? ((Parameters *) ssGetDefaultParam(S))->P_899 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_341_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_343_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_342_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[0];
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_344_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_900, 45U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_345_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_901, 35U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_33_346_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_902[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_346_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_902[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_347_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_903[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_347_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_903[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_348_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_904[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_347_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_348_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_904[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_347_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_33_348_0[0] + ((Parameters *) ssGetDefaultParam(S))
          ->P_905;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_33_348_0[1] + ((Parameters *) ssGetDefaultParam(S))
          ->P_905;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_351_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_906[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_351_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_906[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_353_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_907[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_353_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_907[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_355_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_908[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_355_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_908[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_357_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_909[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_357_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_909[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_359_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_910[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_359_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_910[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_361_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_911[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_361_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_911[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_363_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_912[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_363_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_912[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_365_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_913[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_365_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_913[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_367_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_914[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_367_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_914[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_369_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_915[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_369_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_915[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_371_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_916[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_371_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_916[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_373_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_917[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_373_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_917[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_375_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_918[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_375_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_918[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_377_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_919[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_377_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_919[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_379_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_920[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_379_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_920[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_381_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_921[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_381_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_921[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_383_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_922[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_383_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_922[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_385_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_923[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_385_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_923[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_387_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_924[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_387_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_924[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_389_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_925[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_389_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_925[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_391_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_926[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_391_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_926[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_393_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_927[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_393_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_927[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_395_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_928[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_395_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_928[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_397_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_929[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_397_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_929[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_399_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_930[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_399_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_930[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_401_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_931[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_401_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_931[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_403_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_932[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_403_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_932[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_405_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_933[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_405_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_933[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_407_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_934[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_407_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_934[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_409_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_935[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_409_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_935[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_411_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_936[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_411_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_936[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_413_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_937[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_413_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_937[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_415_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_938[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_415_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_938[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_417_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_939[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_417_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_939[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_419_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_940, 35U * sizeof
                 (real_T));
        }

        tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_33_346_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_346_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_33_351_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_351_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_33_353_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_353_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_33_355_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_355_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_33_357_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_357_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_33_359_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_359_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_33_361_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_361_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_33_363_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_363_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_33_365_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_365_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_33_367_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_367_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_33_369_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_369_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_33_371_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_371_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_33_373_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_373_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_33_375_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_375_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_33_377_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_377_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_33_379_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_379_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_33_381_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_381_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_33_383_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_383_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_33_385_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_385_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_33_387_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_387_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_33_389_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_389_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_33_391_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_391_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_33_393_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_393_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_33_395_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_395_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_33_397_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_397_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_33_399_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_399_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_33_401_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_401_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_33_403_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_403_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_33_405_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_405_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_33_407_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_407_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_33_409_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_409_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_33_411_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_411_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_33_413_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_413_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_33_415_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_415_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_33_417_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_349_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_417_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_349_0[1];
        for (i = 0; i < 35; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_420_0[i] = tmp_1t[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_419_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_421_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_941 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_420_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_423_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_942;
        }

        for (i = 0; i < 35; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_424_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_421_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_423_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_426_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_424_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_943;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_427_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_944;
        }

        for (i = 0; i < 35; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_428_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_426_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_427_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_430_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_945, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_432_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_946, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_434_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_947, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_436_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_948, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_438_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_949, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_440_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_950, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_442_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_951, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_444_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_952, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_446_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_953, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_448_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_954, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_450_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_955, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_452_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_956, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_454_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_957, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_456_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_958, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_458_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_959, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_460_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_960, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_462_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_961, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_464_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_962, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_466_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_963, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_468_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_964, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_470_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_965, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_472_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_966, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_474_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_967, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_476_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_968, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_478_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_969, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_480_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_970, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_482_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_971, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_484_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_972, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_486_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_973, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_488_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_974, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_490_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_975, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_492_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_976, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_494_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_977, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_496_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_978, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_498_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_979, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_500_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_980, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_502_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_981, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_504_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_982, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_506_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_983, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_508_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_984, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_510_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_985, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_512_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_986, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_514_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_987, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_516_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_988, 35U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_518_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_989, 45U * sizeof
                 (real_T));
        }

        B_48_0_0 = 0.0;
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
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_345_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_430_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_33_432_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_33_434_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_33_436_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_33_438_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_33_440_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_33_442_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_33_444_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_33_446_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_33_448_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_33_450_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_33_452_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_33_454_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_33_456_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_33_458_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_33_460_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_33_462_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_33_464_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_33_466_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_33_468_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_33_470_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_33_472_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_33_474_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_33_476_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_33_478_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_33_480_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_33_482_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_33_484_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_33_486_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_33_488_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_33_490_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_33_492_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_33_494_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_33_496_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_33_498_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_33_500_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_33_502_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_33_504_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_33_506_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_33_508_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_33_510_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_33_512_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_33_514_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
          tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_33_516_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_428_0[i];
        }

        tmp_1u[0] = B_48_0_0;
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
          ((BlockIO *) _ssGetBlockIO(S))->B_33_519_0[i] = tmp_1u[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_518_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_520_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_990 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_519_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_522_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_991;
        }

        for (i = 0; i < 45; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_523_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_520_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_522_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_525_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_523_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_992;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_526_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_993;
        }

        for (i = 0; i < 45; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_527_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_525_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_526_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_529_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_994;
        }

        B_48_0_0 = 0.0;
        for (i = 0; i < 45; i++) {
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_344_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_527_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_530_0 = B_48_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_33_529_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_531_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_530_0 + ((Parameters *) ssGetDefaultParam(S))->P_995;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_532_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_996 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_531_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_533_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_532_0 + ((Parameters *) ssGetDefaultParam(S))->P_997;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_534_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_533_0 >= ((Parameters *) ssGetDefaultParam(S))->P_998 ?
          ((Parameters *) ssGetDefaultParam(S))->P_998 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_533_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_999 ? ((Parameters *) ssGetDefaultParam(S))->P_999 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_533_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_535_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_534_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[1];
        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_536_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1000, 50U * sizeof
                 (real_T));
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_537_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1001, 40U * sizeof
                 (real_T));
          ((BlockIO *) _ssGetBlockIO(S))->B_33_538_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1002[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_538_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1002[1];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_539_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_1003[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_539_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S))
          ->P_1003[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_540_0[0] = ((Parameters *)
          ssGetDefaultParam(S))->P_1004[0] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_539_0[0];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_540_0[1] = ((Parameters *)
          ssGetDefaultParam(S))->P_1004[1] * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_539_0[1];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[0] = ((BlockIO *)
          _ssGetBlockIO(S))->B_33_540_0[0] + ((Parameters *) ssGetDefaultParam(S))
          ->P_1005;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1] = ((BlockIO *)
          _ssGetBlockIO(S))->B_33_540_0[1] + ((Parameters *) ssGetDefaultParam(S))
          ->P_1005;
        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_543_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1006[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_543_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1006[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_545_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1007[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_545_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1007[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_547_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1008[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_547_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1008[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_549_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1009[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_549_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1009[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_551_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1010[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_551_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1010[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_553_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1011[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_553_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1011[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_555_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1012[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_555_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1012[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_557_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1013[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_557_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1013[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_559_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1014[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_559_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1014[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_561_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1015[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_561_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1015[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_563_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1016[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_563_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1016[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_565_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1017[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_565_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1017[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_567_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1018[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_567_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1018[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_569_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1019[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_569_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1019[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_571_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1020[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_571_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1020[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_573_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1021[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_573_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1021[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_575_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1022[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_575_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1022[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_577_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1023[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_577_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1023[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_579_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1024[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_579_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1024[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_581_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1025[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_581_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1025[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_583_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1026[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_583_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1026[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_585_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1027[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_585_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1027[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_587_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1028[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_587_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1028[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_589_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1029[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_589_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1029[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_591_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1030[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_591_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1030[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_593_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1031[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_593_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1031[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_595_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1032[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_595_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1032[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_597_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1033[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_597_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1033[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_599_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1034[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_599_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1034[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_601_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1035[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_601_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1035[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_603_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1036[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_603_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1036[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_605_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1037[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_605_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1037[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_607_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1038[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_607_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1038[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_609_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1039[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_609_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1039[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_611_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1040[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_611_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1040[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_613_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1041[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_613_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1041[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_615_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1042[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_615_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1042[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_617_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1043[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_617_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1043[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_619_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1044[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_619_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1044[1];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_621_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1045, 40U * sizeof
                 (real_T));
        }

        tmp_15[0] = ((BlockIO *) _ssGetBlockIO(S))->B_33_538_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_538_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[1] = ((BlockIO *) _ssGetBlockIO(S))->B_33_543_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_543_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[2] = ((BlockIO *) _ssGetBlockIO(S))->B_33_545_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_545_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[3] = ((BlockIO *) _ssGetBlockIO(S))->B_33_547_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_547_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[4] = ((BlockIO *) _ssGetBlockIO(S))->B_33_549_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_549_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[5] = ((BlockIO *) _ssGetBlockIO(S))->B_33_551_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_551_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[6] = ((BlockIO *) _ssGetBlockIO(S))->B_33_553_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_553_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[7] = ((BlockIO *) _ssGetBlockIO(S))->B_33_555_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_555_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[8] = ((BlockIO *) _ssGetBlockIO(S))->B_33_557_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_557_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[9] = ((BlockIO *) _ssGetBlockIO(S))->B_33_559_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_559_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[10] = ((BlockIO *) _ssGetBlockIO(S))->B_33_561_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_561_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[11] = ((BlockIO *) _ssGetBlockIO(S))->B_33_563_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_563_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[12] = ((BlockIO *) _ssGetBlockIO(S))->B_33_565_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_565_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[13] = ((BlockIO *) _ssGetBlockIO(S))->B_33_567_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_567_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[14] = ((BlockIO *) _ssGetBlockIO(S))->B_33_569_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_569_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[15] = ((BlockIO *) _ssGetBlockIO(S))->B_33_571_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_571_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[16] = ((BlockIO *) _ssGetBlockIO(S))->B_33_573_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_573_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[17] = ((BlockIO *) _ssGetBlockIO(S))->B_33_575_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_575_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[18] = ((BlockIO *) _ssGetBlockIO(S))->B_33_577_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_577_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[19] = ((BlockIO *) _ssGetBlockIO(S))->B_33_579_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_579_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[20] = ((BlockIO *) _ssGetBlockIO(S))->B_33_581_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_581_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[21] = ((BlockIO *) _ssGetBlockIO(S))->B_33_583_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_583_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[22] = ((BlockIO *) _ssGetBlockIO(S))->B_33_585_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_585_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[23] = ((BlockIO *) _ssGetBlockIO(S))->B_33_587_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_587_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[24] = ((BlockIO *) _ssGetBlockIO(S))->B_33_589_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_589_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[25] = ((BlockIO *) _ssGetBlockIO(S))->B_33_591_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_591_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[26] = ((BlockIO *) _ssGetBlockIO(S))->B_33_593_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_593_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[27] = ((BlockIO *) _ssGetBlockIO(S))->B_33_595_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_595_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[28] = ((BlockIO *) _ssGetBlockIO(S))->B_33_597_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_597_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[29] = ((BlockIO *) _ssGetBlockIO(S))->B_33_599_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_599_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[30] = ((BlockIO *) _ssGetBlockIO(S))->B_33_601_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_601_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[31] = ((BlockIO *) _ssGetBlockIO(S))->B_33_603_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_603_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[32] = ((BlockIO *) _ssGetBlockIO(S))->B_33_605_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_605_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[33] = ((BlockIO *) _ssGetBlockIO(S))->B_33_607_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_607_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[34] = ((BlockIO *) _ssGetBlockIO(S))->B_33_609_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_609_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[35] = ((BlockIO *) _ssGetBlockIO(S))->B_33_611_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_611_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[36] = ((BlockIO *) _ssGetBlockIO(S))->B_33_613_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_613_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[37] = ((BlockIO *) _ssGetBlockIO(S))->B_33_615_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_615_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[38] = ((BlockIO *) _ssGetBlockIO(S))->B_33_617_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_617_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        tmp_15[39] = ((BlockIO *) _ssGetBlockIO(S))->B_33_619_0[0] * ((BlockIO *)
          _ssGetBlockIO(S))->B_33_541_0[0] + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_619_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_33_541_0[1];
        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_622_0[i] = tmp_15[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_621_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_623_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_1046 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_622_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_625_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1047;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_626_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_623_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_625_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_628_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_626_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_1048;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_629_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1049;
        }

        for (i = 0; i < 40; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_630_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_628_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_629_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_632_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1050, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_634_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1051, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_636_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1052, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_638_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1053, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_640_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1054, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_642_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1055, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_644_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1056, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_646_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1057, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_648_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1058, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_650_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1059, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_652_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1060, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_654_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1061, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_656_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1062, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_658_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1063, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_660_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1064, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_662_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1065, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_664_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1066, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_666_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1067, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_668_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1068, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_670_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1069, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_672_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1070, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_674_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1071, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_676_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1072, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_678_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1073, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_680_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1074, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_682_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1075, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_684_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1076, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_686_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1077, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_688_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1078, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_690_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1079, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_692_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1080, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_694_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1081, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_696_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1082, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_698_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1083, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_700_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1084, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_702_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1085, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_704_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1086, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_706_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1087, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_708_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1088, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_710_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1089, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_712_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1090, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_714_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1091, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_716_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1092, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_718_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1093, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_720_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1094, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_722_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1095, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_724_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1096, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_726_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1097, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_728_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1098, 40U * sizeof
                 (real_T));
        }

        if (ssIsSampleHit(S, 1, 0)) {
          memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_33_730_0[0]), (void
                  *)((Parameters *) ssGetDefaultParam(S))->P_1099, 50U * sizeof
                 (real_T));
        }

        B_48_0_0 = 0.0;
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
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_537_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_632_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_33_634_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_33_636_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_33_638_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_33_640_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_33_642_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_33_644_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_33_646_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_33_648_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_33_650_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_33_652_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_33_654_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_33_656_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_33_658_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_33_660_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_33_662_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_33_664_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_33_666_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_33_668_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_33_670_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_33_672_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_33_674_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_33_676_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_33_678_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_33_680_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_33_682_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_33_684_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_33_686_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_33_688_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_33_690_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_33_692_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_33_694_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_33_696_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_33_698_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_33_700_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_33_702_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_33_704_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_33_706_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_33_708_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_33_710_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_33_712_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_33_714_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_33_716_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_33_718_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_33_720_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_33_722_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_33_724_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_33_726_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
          tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_33_728_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_630_0[i];
        }

        tmp_21[0] = B_48_0_0;
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
          ((BlockIO *) _ssGetBlockIO(S))->B_33_731_0[i] = tmp_21[i] + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_730_0[i];
          ((BlockIO *) _ssGetBlockIO(S))->B_33_732_0[i] = ((Parameters *)
            ssGetDefaultParam(S))->P_1100 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_731_0[i];
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_734_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1101;
        }

        for (i = 0; i < 50; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_735_0[i] = muDoubleScalarExp
            (((BlockIO *) _ssGetBlockIO(S))->B_33_732_0[i]) + ((BlockIO *)
            _ssGetBlockIO(S))->B_33_734_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_33_737_0[i] = 1.0 / ((BlockIO *)
            _ssGetBlockIO(S))->B_33_735_0[i] * ((Parameters *) ssGetDefaultParam
            (S))->P_1102;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_738_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1103;
        }

        for (i = 0; i < 50; i++) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_739_0[i] = ((BlockIO *)
            _ssGetBlockIO(S))->B_33_737_0[i] - ((BlockIO *) _ssGetBlockIO(S))
            ->B_33_738_0;
        }

        if (ssIsSampleHit(S, 1, 0)) {
          ((BlockIO *) _ssGetBlockIO(S))->B_33_741_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1104;
        }

        B_48_0_0 = 0.0;
        for (i = 0; i < 50; i++) {
          B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_33_536_0[i] * ((BlockIO *)
            _ssGetBlockIO(S))->B_33_739_0[i];
        }

        ((BlockIO *) _ssGetBlockIO(S))->B_33_742_0 = B_48_0_0 + ((BlockIO *)
          _ssGetBlockIO(S))->B_33_741_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_743_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_742_0 + ((Parameters *) ssGetDefaultParam(S))->P_1105;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_744_0 = ((Parameters *)
          ssGetDefaultParam(S))->P_1106 * ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_743_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_745_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_744_0 + ((Parameters *) ssGetDefaultParam(S))->P_1107;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_746_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_745_0 >= ((Parameters *) ssGetDefaultParam(S))->P_1108 ?
          ((Parameters *) ssGetDefaultParam(S))->P_1108 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_745_0 <= ((Parameters *) ssGetDefaultParam(S)
          )->P_1109 ? ((Parameters *) ssGetDefaultParam(S))->P_1109 : ((BlockIO *)
          _ssGetBlockIO(S))->B_33_745_0;
        ((BlockIO *) _ssGetBlockIO(S))->B_33_747_0 = ((BlockIO *) _ssGetBlockIO
          (S))->B_33_746_0 * ((BlockIO *) _ssGetBlockIO(S))->B_21_1_1[2];
        ((BlockIO *) _ssGetBlockIO(S))->B_33_748_0 = ((((BlockIO *)
          _ssGetBlockIO(S))->B_33_241_0 + ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_343_0) + ((BlockIO *) _ssGetBlockIO(S))->B_33_535_0) +
          ((BlockIO *) _ssGetBlockIO(S))->B_33_747_0;
        if (ssIsSampleHit(S, 1, 0)) {
          /* Scope: '<S837>/Scope' */
          /* Call into Simulink for Scope */
          ssCallAccelRunBlock(S, 33, 749, SS_CALL_MDL_OUTPUTS);
        }

        if (ssIsMajorTimeStep(S)) {
          srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder07_SubsysRanBC);
        }
        break;

       case 1:
        if (ssIsMajorTimeStep(S)) {
          if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 <= 0.8) {
            rtAction = 0;
          } else {
            rtAction = 1;
          }

          ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_b = rtAction;
        } else {
          rtAction = ((D_Work *) ssGetRootDWork(S))->If_ActiveSubsystem_b;
        }

        switch (rtAction) {
         case 0:
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_0_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1110, 60U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_1_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1111, 30U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_34_2_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1112[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_2_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1112[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_3_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1113[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_3_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1113[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_4_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1114[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_3_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_4_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1114[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_3_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_4_0[0] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1115;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_4_0[1] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1115;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_7_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1116[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_7_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1116[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_9_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1117[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_9_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1117[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_11_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1118[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_11_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1118[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_13_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1119[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_13_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1119[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_15_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1120[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_15_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1120[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_17_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1121[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_17_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1121[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_19_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1122[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_19_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1122[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_21_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1123[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_21_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1123[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_23_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1124[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_23_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1124[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_25_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1125[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_25_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1125[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_27_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1126[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_27_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1126[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_29_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1127[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_29_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1127[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_31_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1128[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_31_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1128[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_33_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1129[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_33_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1129[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_35_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1130[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_35_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1130[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_37_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1131[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_37_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1131[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_39_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1132[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_39_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1132[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_41_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1133[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_41_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1133[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_43_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1134[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_43_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1134[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_45_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1135[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_45_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1135[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_47_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1136[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_47_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1136[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_49_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1137[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_49_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1137[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_51_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1138[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_51_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1138[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_53_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1139[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_53_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1139[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_55_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1140[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_55_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1140[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_57_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1141[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_57_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1141[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_59_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1142[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_59_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1142[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_61_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1143[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_61_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1143[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_63_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1144[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_63_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1144[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_65_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1145, 30U *
                   sizeof(real_T));
          }

          tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_2_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_7_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_9_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_11_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_13_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_15_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_17_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_19_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_21_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_23_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_25_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_27_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_29_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_31_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_33_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_35_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_37_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_39_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_41_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_43_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_45_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_47_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_49_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_51_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_53_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_55_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_55_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_57_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_57_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_59_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_59_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_61_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_61_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_63_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_63_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_5_0[1];
          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_66_0[i] = tmp_f[i] + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_65_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_67_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1146 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_66_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_69_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1147;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_70_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_67_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_69_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_72_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_70_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1148;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_73_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1149;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_74_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_72_0[i] - ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_73_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_76_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1150, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_78_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1151, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_80_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1152, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_82_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1153, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_84_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1154, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_86_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1155, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_88_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1156, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_90_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1157, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_92_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1158, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_94_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1159, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_96_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1160, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_98_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1161, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_100_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1162, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_102_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1163, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_104_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1164, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_106_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1165, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_108_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1166, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_110_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1167, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_112_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1168, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_114_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1169, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_116_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1170, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_118_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1171, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_120_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1172, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_122_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1173, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_124_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1174, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_126_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1175, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_128_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1176, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_130_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1177, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_132_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1178, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_134_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1179, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_136_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1180, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_138_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1181, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_140_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1182, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_142_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1183, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_144_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1184, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_146_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1185, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_148_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1186, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_150_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1187, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_152_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1188, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_154_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1189, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_156_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1190, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_158_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1191, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_160_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1192, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_162_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1193, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_164_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1194, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_166_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1195, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_168_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1196, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_170_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1197, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_172_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1198, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_174_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1199, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_176_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1200, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_178_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1201, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_180_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1202, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_182_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1203, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_184_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1204, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_186_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1205, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_188_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1206, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_190_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1207, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_192_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1208, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_194_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1209, 60U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_1_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_76_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_78_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_80_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_82_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_84_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_86_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_88_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_90_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_92_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_34_94_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_34_96_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_34_98_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_34_100_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_34_102_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_34_104_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_34_106_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_34_108_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_34_110_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_34_112_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_34_114_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_34_116_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_34_118_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_34_120_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_34_122_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_34_124_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_34_126_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_34_128_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_34_130_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_34_132_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_34_134_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_34_136_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_34_138_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_34_140_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_34_142_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_34_144_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_34_146_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_34_148_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_34_150_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_34_152_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_34_154_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_34_156_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_34_158_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_34_160_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_34_162_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_34_164_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_34_166_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_34_168_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_34_170_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_34_172_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1i += ((BlockIO *) _ssGetBlockIO(S))->B_34_174_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1j += ((BlockIO *) _ssGetBlockIO(S))->B_34_176_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1k += ((BlockIO *) _ssGetBlockIO(S))->B_34_178_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1l += ((BlockIO *) _ssGetBlockIO(S))->B_34_180_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1m += ((BlockIO *) _ssGetBlockIO(S))->B_34_182_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1n += ((BlockIO *) _ssGetBlockIO(S))->B_34_184_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1o += ((BlockIO *) _ssGetBlockIO(S))->B_34_186_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1p += ((BlockIO *) _ssGetBlockIO(S))->B_34_188_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1q += ((BlockIO *) _ssGetBlockIO(S))->B_34_190_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
            tmp_1r += ((BlockIO *) _ssGetBlockIO(S))->B_34_192_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_74_0[i];
          }

          tmp_1s[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_34_195_0[i] = tmp_1s[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_34_194_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_196_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1210 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_195_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_198_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1211;
          }

          for (i = 0; i < 60; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_199_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_196_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_198_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_201_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_199_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1212;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_202_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1213;
          }

          for (i = 0; i < 60; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_203_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_201_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_202_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_205_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1214;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 60; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_0_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_203_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_206_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_34_205_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_207_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_206_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1215;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_208_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1216 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_207_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_209_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_208_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1217;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_210_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_209_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1218 ? ((Parameters *) ssGetDefaultParam(S))->P_1218 : ((BlockIO
            *) _ssGetBlockIO(S))->B_34_209_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1219 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1219 : ((BlockIO *) _ssGetBlockIO(S))->B_34_209_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_211_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_210_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[3];
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_212_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1220, 45U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_213_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1221, 35U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_34_214_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1222[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_214_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1222[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_215_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1223[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_215_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1223[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_216_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1224[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_215_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_216_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1224[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_215_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_216_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1225;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_216_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1225;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_219_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1226[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_219_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1226[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_221_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1227[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_221_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1227[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_223_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1228[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_223_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1228[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_225_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1229[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_225_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1229[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_227_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1230[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_227_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1230[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_229_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1231[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_229_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1231[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_231_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1232[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_231_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1232[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_233_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1233[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_233_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1233[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_235_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1234[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_235_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1234[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_237_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1235[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_237_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1235[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_239_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1236[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_239_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1236[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_241_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1237[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_241_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1237[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_243_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1238[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_243_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1238[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_245_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1239[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_245_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1239[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_247_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1240[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_247_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1240[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_249_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1241[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_249_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1241[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_251_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1242[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_251_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1242[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_253_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1243[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_253_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1243[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_255_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1244[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_255_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1244[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_257_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1245[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_257_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1245[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_259_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1246[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_259_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1246[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_261_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1247[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_261_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1247[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_263_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1248[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_263_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1248[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_265_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1249[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_265_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1249[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_267_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1250[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_267_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1250[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_269_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1251[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_269_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1251[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_271_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1252[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_271_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1252[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_273_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1253[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_273_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1253[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_275_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1254[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_275_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1254[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_277_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1255[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_277_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1255[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_279_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1256[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_279_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1256[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_281_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1257[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_281_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1257[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_283_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1258[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_283_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1258[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_285_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1259[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_285_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1259[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_287_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1260, 35U *
                   sizeof(real_T));
          }

          tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_214_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_214_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_219_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_219_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_221_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_221_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_223_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_223_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_225_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_225_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_227_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_227_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_229_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_229_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_231_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_231_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_233_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_233_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_235_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_235_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_237_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_237_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_239_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_239_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_241_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_241_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_243_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_243_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_245_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_245_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_247_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_247_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_249_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_249_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_251_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_251_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_253_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_253_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_255_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_255_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_257_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_257_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_259_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_259_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_261_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_261_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_263_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_263_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_265_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_265_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_267_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_267_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_269_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_269_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_271_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_271_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_273_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_273_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_275_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_275_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_34_277_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_277_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_34_279_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_279_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_34_281_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_281_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_34_283_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_283_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_34_285_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_217_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_285_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_217_0[1];
          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_288_0[i] = tmp_1t[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_34_287_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_289_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1261 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_288_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_291_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1262;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_292_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_289_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_291_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_294_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_292_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1263;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_295_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1264;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_296_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_294_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_295_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_298_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1265, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_300_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1266, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_302_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1267, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_304_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1268, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_306_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1269, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_308_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1270, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_310_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1271, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_312_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1272, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_314_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1273, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_316_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1274, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_318_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1275, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_320_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1276, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_322_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1277, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1278, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_326_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1279, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_328_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1280, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_330_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1281, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_332_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1282, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_334_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1283, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_336_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1284, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_338_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1285, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_340_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1286, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_342_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1287, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_344_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1288, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_346_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1289, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_348_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1290, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_350_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1291, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_352_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1292, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_354_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1293, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_356_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1294, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_358_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1295, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_360_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1296, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_362_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1297, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_364_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1298, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_366_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1299, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_368_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1300, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_370_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1301, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_372_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1302, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_374_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1303, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_376_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1304, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_378_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1305, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_380_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1306, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_382_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1307, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_384_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1308, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_386_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1309, 45U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_213_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_298_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_300_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_302_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_304_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_306_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_308_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_310_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_312_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_314_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_34_316_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_34_318_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_34_320_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_34_322_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_34_324_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_34_326_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_34_328_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_34_330_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_34_332_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_34_334_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_34_336_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_34_338_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_34_340_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_34_342_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_34_344_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_34_346_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_34_348_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_34_350_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_34_352_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_34_354_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_34_356_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_34_358_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_34_360_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_34_362_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_34_364_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_34_366_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_34_368_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_34_370_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_34_372_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_34_374_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_34_376_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_34_378_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_34_380_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_34_382_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_34_384_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_296_0[i];
          }

          tmp_1u[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_34_387_0[i] = tmp_1u[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_34_386_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_388_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1310 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_387_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_390_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1311;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_391_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_388_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_390_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_393_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_391_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1312;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_394_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1313;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_395_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_393_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_394_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_397_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1314;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 45; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_212_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_34_395_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_398_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_34_397_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_399_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_398_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1315;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_400_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1316 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_399_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_401_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_400_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1317;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_402_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_401_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1318 ? ((Parameters *) ssGetDefaultParam(S))->P_1318 : ((BlockIO
            *) _ssGetBlockIO(S))->B_34_401_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1319 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1319 : ((BlockIO *) _ssGetBlockIO(S))->B_34_401_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_403_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_402_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[0];
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_404_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1320, 50U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_405_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1321, 35U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_34_406_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1322[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_406_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1322[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_407_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1323[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_407_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1323[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_408_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1324[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_407_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_408_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1324[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_407_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_408_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1325;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_408_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1325;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_411_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1326[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_411_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1326[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_413_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1327[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_413_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1327[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_415_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1328[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_415_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1328[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_417_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1329[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_417_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1329[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_419_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1330[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_419_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1330[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_421_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1331[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_421_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1331[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_423_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1332[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_423_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1332[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_425_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1333[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_425_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1333[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_427_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1334[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_427_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1334[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_429_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1335[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_429_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1335[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_431_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1336[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_431_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1336[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_433_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1337[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_433_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1337[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_435_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1338[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_435_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1338[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_437_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1339[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_437_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1339[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_439_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1340[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_439_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1340[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_441_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1341[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_441_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1341[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_443_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1342[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_443_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1342[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_445_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1343[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_445_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1343[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_447_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1344[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_447_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1344[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_449_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1345[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_449_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1345[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_451_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1346[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_451_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1346[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_453_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1347[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_453_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1347[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_455_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1348[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_455_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1348[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_457_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1349[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_457_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1349[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_459_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1350[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_459_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1350[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_461_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1351[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_461_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1351[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_463_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1352[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_463_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1352[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_465_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1353[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_465_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1353[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_467_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1354[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_467_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1354[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_469_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1355[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_469_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1355[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_471_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1356[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_471_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1356[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_473_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1357[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_473_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1357[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_475_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1358[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_475_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1358[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_477_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1359[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_477_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1359[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_479_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1360, 35U *
                   sizeof(real_T));
          }

          tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_406_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_406_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_411_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_411_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_413_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_413_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_415_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_415_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_417_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_417_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_419_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_419_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_421_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_421_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_423_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_423_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_425_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_425_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_427_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_427_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_429_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_429_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_431_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_431_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_433_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_433_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_435_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_435_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_437_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_437_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_439_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_439_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_441_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_441_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_443_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_443_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_445_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_445_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_447_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_447_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_449_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_449_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_451_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_451_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_453_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_453_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_455_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_455_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_457_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_457_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_459_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_459_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_461_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_461_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_463_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_463_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_465_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_465_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_467_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_467_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_34_469_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_469_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_34_471_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_471_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_34_473_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_473_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_34_475_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_475_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_34_477_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_34_409_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_34_477_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_409_0[1];
          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_480_0[i] = tmp_1t[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_34_479_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_481_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1361 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_480_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_483_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1362;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_484_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_481_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_483_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_486_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_484_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1363;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_487_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1364;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_488_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_486_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_487_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_490_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1365, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_492_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1366, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_494_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1367, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_496_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1368, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_498_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1369, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_500_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1370, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_502_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1371, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_504_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1372, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_506_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1373, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_508_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1374, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_510_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1375, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_512_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1376, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_514_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1377, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_516_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1378, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1379, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_520_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1380, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_522_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1381, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_524_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1382, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_526_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1383, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_528_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1384, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_530_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1385, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_532_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1386, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_534_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1387, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_536_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1388, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_538_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1389, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_540_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1390, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_542_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1391, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_544_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1392, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_546_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1393, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_548_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1394, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_550_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1395, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_552_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1396, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_554_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1397, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_556_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1398, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_558_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1399, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_560_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1400, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_562_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1401, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_564_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1402, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_566_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1403, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_568_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1404, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_570_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1405, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_572_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1406, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_574_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1407, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_576_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1408, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_578_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1409, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_580_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1410, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_582_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1411, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_584_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1412, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_586_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1413, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_588_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1414, 50U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_405_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_490_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_492_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_494_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_496_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_498_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_500_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_502_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_504_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_506_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_34_508_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_34_510_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_34_512_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_34_514_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_34_516_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_34_518_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_34_520_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_34_522_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_34_524_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_34_526_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_34_528_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_34_530_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_34_532_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_34_534_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_34_536_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_34_538_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_34_540_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_34_542_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_34_544_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_34_546_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_34_548_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_34_550_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_34_552_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_34_554_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_34_556_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_34_558_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_34_560_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_34_562_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_34_564_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_34_566_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_34_568_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_34_570_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_34_572_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_34_574_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_34_576_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_34_578_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_34_580_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_34_582_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_34_584_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_34_586_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_488_0[i];
          }

          tmp_21[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_34_589_0[i] = tmp_21[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_34_588_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_590_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1415 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_589_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_592_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1416;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_593_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_590_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_592_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_595_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_593_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1417;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_596_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1418;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_597_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_595_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_596_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_599_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1419;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 50; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_404_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_34_597_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_600_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_34_599_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_601_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_600_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1420;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_602_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1421 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_601_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_603_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_602_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1422;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_604_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_603_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1423 ? ((Parameters *) ssGetDefaultParam(S))->P_1423 : ((BlockIO
            *) _ssGetBlockIO(S))->B_34_603_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1424 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1424 : ((BlockIO *) _ssGetBlockIO(S))->B_34_603_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_605_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_604_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[1];
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_606_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1425, 50U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_607_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1426, 30U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_34_608_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1427[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_608_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1427[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_609_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1428[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_609_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1428[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_610_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1429[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_609_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_610_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1429[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_609_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_610_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1430;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_610_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1430;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_613_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1431[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_613_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1431[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_615_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1432[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_615_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1432[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_617_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1433[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_617_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1433[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_619_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1434[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_619_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1434[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_621_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1435[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_621_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1435[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_623_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1436[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_623_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1436[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_625_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1437[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_625_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1437[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_627_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1438[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_627_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1438[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_629_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1439[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_629_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1439[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_631_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1440[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_631_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1440[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_633_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1441[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_633_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1441[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_635_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1442[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_635_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1442[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_637_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1443[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_637_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1443[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_639_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1444[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_639_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1444[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_641_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1445[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_641_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1445[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_643_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1446[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_643_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1446[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_645_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1447[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_645_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1447[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_647_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1448[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_647_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1448[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_649_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1449[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_649_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1449[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_651_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1450[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_651_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1450[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_653_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1451[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_653_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1451[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_655_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1452[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_655_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1452[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_657_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1453[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_657_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1453[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_659_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1454[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_659_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1454[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_661_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1455[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_661_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1455[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_663_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1456[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_663_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1456[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_665_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1457[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_665_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1457[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_667_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1458[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_667_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1458[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_669_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1459[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_669_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1459[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_671_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1460, 30U *
                   sizeof(real_T));
          }

          tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_34_608_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_608_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_34_613_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_613_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_34_615_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_615_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_34_617_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_617_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_34_619_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_619_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_34_621_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_621_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_34_623_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_623_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_34_625_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_625_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_34_627_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_627_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_34_629_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_629_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_34_631_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_631_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_34_633_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_633_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_34_635_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_635_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_34_637_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_637_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_34_639_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_639_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_34_641_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_641_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_34_643_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_643_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_34_645_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_645_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_34_647_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_647_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_34_649_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_649_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_34_651_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_651_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_34_653_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_653_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_34_655_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_655_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_34_657_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_657_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_34_659_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_659_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_34_661_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_661_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_34_663_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_663_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_34_665_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_665_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_34_667_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_667_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_34_669_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_34_611_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_669_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_34_611_0[1];
          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_672_0[i] = tmp_f[i] + ((BlockIO
              *) _ssGetBlockIO(S))->B_34_671_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_673_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1461 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_672_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_675_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1462;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_676_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_673_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_675_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_678_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_676_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1463;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_679_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1464;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_680_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_678_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_679_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_682_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1465, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_684_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1466, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_686_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1467, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_688_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1468, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_690_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1469, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_692_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1470, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_694_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1471, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_696_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1472, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_698_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1473, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_700_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1474, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_702_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1475, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_704_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1476, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_706_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1477, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_708_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1478, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_710_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1479, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_712_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1480, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_714_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1481, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_716_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1482, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_718_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1483, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_720_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1484, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_722_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1485, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_724_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1486, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_726_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1487, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_728_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1488, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_730_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1489, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_732_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1490, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_734_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1491, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_736_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1492, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_738_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1493, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_740_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1494, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_742_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1495, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_744_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1496, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_746_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1497, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_748_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1498, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_750_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1499, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_752_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1500, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_754_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1501, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_756_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1502, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_758_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1503, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_760_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1504, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_762_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1505, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_764_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1506, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_766_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1507, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_768_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1508, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_770_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1509, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_772_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1510, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_774_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1511, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_776_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1512, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_778_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1513, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_34_780_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1514, 50U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_607_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_682_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_34_684_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_34_686_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_34_688_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_34_690_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_34_692_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_34_694_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_34_696_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_34_698_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_34_700_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_34_702_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_34_704_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_34_706_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_34_708_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_34_710_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_34_712_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_34_714_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_34_716_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_34_718_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_34_720_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_34_722_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_34_724_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_34_726_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_34_728_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_34_730_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_34_732_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_34_734_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_34_736_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_34_738_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_34_740_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_34_742_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_34_744_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_34_746_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_34_748_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_34_750_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_34_752_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_34_754_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_34_756_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_34_758_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_34_760_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_34_762_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_34_764_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_34_766_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_34_768_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_34_770_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_34_772_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_34_774_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_34_776_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_34_778_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_34_680_0[i];
          }

          tmp_21[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_34_781_0[i] = tmp_21[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_34_780_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_34_782_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1515 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_34_781_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_784_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1516;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_785_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_34_782_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_34_784_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_34_787_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_34_785_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1517;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_788_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1518;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_789_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_34_787_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_34_788_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_34_791_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1519;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 50; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_34_606_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_34_789_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_34_792_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_34_791_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_793_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_792_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1520;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_794_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1521 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_793_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_795_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_794_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1522;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_796_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_795_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1523 ? ((Parameters *) ssGetDefaultParam(S))->P_1523 : ((BlockIO
            *) _ssGetBlockIO(S))->B_34_795_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1524 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1524 : ((BlockIO *) _ssGetBlockIO(S))->B_34_795_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_34_797_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_34_796_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[2];
          ((BlockIO *) _ssGetBlockIO(S))->B_34_798_0 = ((((BlockIO *)
            _ssGetBlockIO(S))->B_34_211_0 + ((BlockIO *) _ssGetBlockIO(S))
            ->B_34_403_0) + ((BlockIO *) _ssGetBlockIO(S))->B_34_605_0) +
            ((BlockIO *) _ssGetBlockIO(S))->B_34_797_0;
          if (ssIsSampleHit(S, 1, 0)) {
            /* Scope: '<S1233>/Scope' */
            /* Call into Simulink for Scope */
            ssCallAccelRunBlock(S, 34, 799, SS_CALL_MDL_OUTPUTS);
          }

          if (ssIsMajorTimeStep(S)) {
            srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCunder08_SubsysRanBC);
          }
          break;

         case 1:
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_0_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1525, 40U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_1_0[0]), (void
                    *)((Parameters *) ssGetDefaultParam(S))->P_1526, 25U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_35_2_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1527[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_2_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1527[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_3_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1528[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_3_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1528[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_4_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1529[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_3_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_4_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1529[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_3_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_4_0[0] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1530;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_4_0[1] + ((Parameters *) ssGetDefaultParam(S))
            ->P_1530;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_7_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1531[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_7_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1531[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_9_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1532[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_9_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1532[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_11_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1533[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_11_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1533[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_13_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1534[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_13_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1534[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_15_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1535[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_15_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1535[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_17_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1536[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_17_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1536[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_19_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1537[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_19_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1537[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_21_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1538[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_21_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1538[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_23_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1539[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_23_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1539[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_25_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1540[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_25_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1540[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_27_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1541[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_27_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1541[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_29_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1542[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_29_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1542[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_31_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1543[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_31_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1543[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_33_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1544[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_33_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1544[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_35_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1545[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_35_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1545[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_37_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1546[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_37_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1546[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_39_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1547[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_39_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1547[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_41_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1548[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_41_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1548[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_43_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1549[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_43_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1549[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_45_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1550[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_45_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1550[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_47_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1551[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_47_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1551[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_49_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1552[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_49_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1552[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_51_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1553[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_51_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1553[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_53_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1554[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_53_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1554[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_55_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1555, 25U *
                   sizeof(real_T));
          }

          tmp_22[0] = ((BlockIO *) _ssGetBlockIO(S))->B_35_2_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_2_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[1] = ((BlockIO *) _ssGetBlockIO(S))->B_35_7_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_7_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[2] = ((BlockIO *) _ssGetBlockIO(S))->B_35_9_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_9_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[3] = ((BlockIO *) _ssGetBlockIO(S))->B_35_11_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_11_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[4] = ((BlockIO *) _ssGetBlockIO(S))->B_35_13_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_13_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[5] = ((BlockIO *) _ssGetBlockIO(S))->B_35_15_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_15_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[6] = ((BlockIO *) _ssGetBlockIO(S))->B_35_17_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_17_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[7] = ((BlockIO *) _ssGetBlockIO(S))->B_35_19_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_19_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[8] = ((BlockIO *) _ssGetBlockIO(S))->B_35_21_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_21_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[9] = ((BlockIO *) _ssGetBlockIO(S))->B_35_23_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_23_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[10] = ((BlockIO *) _ssGetBlockIO(S))->B_35_25_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_25_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[11] = ((BlockIO *) _ssGetBlockIO(S))->B_35_27_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_27_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[12] = ((BlockIO *) _ssGetBlockIO(S))->B_35_29_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_29_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[13] = ((BlockIO *) _ssGetBlockIO(S))->B_35_31_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_31_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[14] = ((BlockIO *) _ssGetBlockIO(S))->B_35_33_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_33_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[15] = ((BlockIO *) _ssGetBlockIO(S))->B_35_35_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_35_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[16] = ((BlockIO *) _ssGetBlockIO(S))->B_35_37_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_37_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[17] = ((BlockIO *) _ssGetBlockIO(S))->B_35_39_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_39_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[18] = ((BlockIO *) _ssGetBlockIO(S))->B_35_41_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_41_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[19] = ((BlockIO *) _ssGetBlockIO(S))->B_35_43_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_43_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[20] = ((BlockIO *) _ssGetBlockIO(S))->B_35_45_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_45_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[21] = ((BlockIO *) _ssGetBlockIO(S))->B_35_47_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_47_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[22] = ((BlockIO *) _ssGetBlockIO(S))->B_35_49_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_49_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[23] = ((BlockIO *) _ssGetBlockIO(S))->B_35_51_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_51_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          tmp_22[24] = ((BlockIO *) _ssGetBlockIO(S))->B_35_53_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_5_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_53_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_5_0[1];
          for (i = 0; i < 25; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_56_0[i] = tmp_22[i] + ((BlockIO
              *) _ssGetBlockIO(S))->B_35_55_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_57_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1556 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_56_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_59_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1557;
          }

          for (i = 0; i < 25; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_60_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_57_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_59_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_62_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_60_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1558;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_63_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1559;
          }

          for (i = 0; i < 25; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_64_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_62_0[i] - ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_63_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_66_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1560, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_68_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1561, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_70_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1562, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_72_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1563, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_74_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1564, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_76_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1565, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_78_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1566, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_80_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1567, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_82_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1568, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_84_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1569, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_86_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1570, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_88_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1571, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_90_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1572, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_92_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1573, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_94_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1574, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_96_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1575, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_98_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1576, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_100_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1577, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_102_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1578, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_104_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1579, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_106_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1580, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_108_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1581, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_110_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1582, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_112_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1583, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_114_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1584, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_116_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1585, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_118_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1586, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_120_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1587, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_122_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1588, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_124_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1589, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_126_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1590, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_128_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1591, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_130_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1592, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_132_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1593, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_134_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1594, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_136_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1595, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_138_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1596, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_140_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1597, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_142_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1598, 25U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_144_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1599, 40U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_1_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_66_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_35_68_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_35_70_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_35_72_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_35_74_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_35_76_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_35_78_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_35_80_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_35_82_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_35_84_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_35_86_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_35_88_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_35_90_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_35_92_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_35_94_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_35_96_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_35_98_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_35_100_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_35_102_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_35_104_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_35_106_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_35_108_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_35_110_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_35_112_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_35_114_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_35_116_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_35_118_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_35_120_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_35_122_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_35_124_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_35_126_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_35_128_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_35_130_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_35_132_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_35_134_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_35_136_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_35_138_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_35_140_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_35_142_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_64_0[i];
          }

          tmp_15[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_35_145_0[i] = tmp_15[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_35_144_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_146_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1600 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_145_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_148_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1601;
          }

          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_149_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_146_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_148_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_152_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1602;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 40; i++) {
            B_48_0_0 += 1.0 / ((BlockIO *) _ssGetBlockIO(S))->B_35_149_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_0_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_153_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_35_152_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_154_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_153_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1603;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_155_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1604 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_154_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_156_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_155_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1605;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_157_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_156_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1606 ? ((Parameters *) ssGetDefaultParam(S))->P_1606 : ((BlockIO
            *) _ssGetBlockIO(S))->B_35_156_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1607 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1607 : ((BlockIO *) _ssGetBlockIO(S))->B_35_156_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_158_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_157_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[3];
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_159_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1608, 45U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_160_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1609, 35U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_35_161_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1610[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_161_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1610[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_162_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1611[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_162_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1611[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_163_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1612[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_162_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_163_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1612[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_162_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_163_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1613;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_163_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1613;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_166_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1614[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_166_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1614[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_168_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1615[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_168_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1615[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_170_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1616[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_170_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1616[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_172_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1617[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_172_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1617[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_174_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1618[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_174_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1618[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_176_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1619[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_176_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1619[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_178_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1620[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_178_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1620[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_180_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1621[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_180_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1621[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_182_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1622[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_182_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1622[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_184_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1623[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_184_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1623[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_186_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1624[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_186_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1624[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_188_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1625[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_188_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1625[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_190_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1626[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_190_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1626[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_192_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1627[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_192_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1627[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_194_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1628[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_194_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1628[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_196_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1629[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_196_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1629[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_198_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1630[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_198_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1630[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_200_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1631[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_200_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1631[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_202_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1632[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_202_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1632[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_204_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1633[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_204_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1633[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_206_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1634[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_206_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1634[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_208_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1635[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_208_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1635[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_210_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1636[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_210_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1636[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_212_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1637[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_212_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1637[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_214_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1638[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_214_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1638[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_216_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1639[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_216_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1639[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_218_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1640[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_218_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1640[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_220_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1641[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_220_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1641[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_222_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1642[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_222_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1642[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_224_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1643[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_224_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1643[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_226_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1644[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_226_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1644[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_228_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1645[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_228_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1645[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_230_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1646[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_230_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1646[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_232_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1647[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_232_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1647[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_234_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1648, 35U *
                   sizeof(real_T));
          }

          tmp_1t[0] = ((BlockIO *) _ssGetBlockIO(S))->B_35_161_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_161_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[1] = ((BlockIO *) _ssGetBlockIO(S))->B_35_166_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_166_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[2] = ((BlockIO *) _ssGetBlockIO(S))->B_35_168_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_168_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[3] = ((BlockIO *) _ssGetBlockIO(S))->B_35_170_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_170_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[4] = ((BlockIO *) _ssGetBlockIO(S))->B_35_172_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_172_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[5] = ((BlockIO *) _ssGetBlockIO(S))->B_35_174_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_174_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[6] = ((BlockIO *) _ssGetBlockIO(S))->B_35_176_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_176_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[7] = ((BlockIO *) _ssGetBlockIO(S))->B_35_178_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_178_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[8] = ((BlockIO *) _ssGetBlockIO(S))->B_35_180_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_180_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[9] = ((BlockIO *) _ssGetBlockIO(S))->B_35_182_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_182_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[10] = ((BlockIO *) _ssGetBlockIO(S))->B_35_184_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_184_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[11] = ((BlockIO *) _ssGetBlockIO(S))->B_35_186_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_186_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[12] = ((BlockIO *) _ssGetBlockIO(S))->B_35_188_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_188_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[13] = ((BlockIO *) _ssGetBlockIO(S))->B_35_190_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_190_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[14] = ((BlockIO *) _ssGetBlockIO(S))->B_35_192_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_192_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[15] = ((BlockIO *) _ssGetBlockIO(S))->B_35_194_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_194_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[16] = ((BlockIO *) _ssGetBlockIO(S))->B_35_196_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_196_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[17] = ((BlockIO *) _ssGetBlockIO(S))->B_35_198_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_198_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[18] = ((BlockIO *) _ssGetBlockIO(S))->B_35_200_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_200_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[19] = ((BlockIO *) _ssGetBlockIO(S))->B_35_202_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_202_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[20] = ((BlockIO *) _ssGetBlockIO(S))->B_35_204_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_204_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[21] = ((BlockIO *) _ssGetBlockIO(S))->B_35_206_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_206_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[22] = ((BlockIO *) _ssGetBlockIO(S))->B_35_208_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_208_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[23] = ((BlockIO *) _ssGetBlockIO(S))->B_35_210_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_210_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[24] = ((BlockIO *) _ssGetBlockIO(S))->B_35_212_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_212_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[25] = ((BlockIO *) _ssGetBlockIO(S))->B_35_214_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_214_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[26] = ((BlockIO *) _ssGetBlockIO(S))->B_35_216_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_216_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[27] = ((BlockIO *) _ssGetBlockIO(S))->B_35_218_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_218_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[28] = ((BlockIO *) _ssGetBlockIO(S))->B_35_220_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_220_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[29] = ((BlockIO *) _ssGetBlockIO(S))->B_35_222_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_222_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[30] = ((BlockIO *) _ssGetBlockIO(S))->B_35_224_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_224_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[31] = ((BlockIO *) _ssGetBlockIO(S))->B_35_226_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_226_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[32] = ((BlockIO *) _ssGetBlockIO(S))->B_35_228_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_228_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[33] = ((BlockIO *) _ssGetBlockIO(S))->B_35_230_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_230_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          tmp_1t[34] = ((BlockIO *) _ssGetBlockIO(S))->B_35_232_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_164_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_232_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_164_0[1];
          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_235_0[i] = tmp_1t[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_35_234_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_236_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1649 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_235_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_238_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1650;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_239_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_236_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_238_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_241_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_239_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1651;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_242_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1652;
          }

          for (i = 0; i < 35; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_243_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_241_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_35_242_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_245_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1653, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_247_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1654, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_249_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1655, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_251_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1656, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_253_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1657, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_255_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1658, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_257_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1659, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_259_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1660, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_261_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1661, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_263_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1662, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_265_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1663, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_267_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1664, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_269_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1665, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_271_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1666, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_273_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1667, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_275_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1668, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_277_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1669, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_279_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1670, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_281_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1671, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_283_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1672, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_285_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1673, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_287_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1674, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_289_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1675, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_291_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1676, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_293_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1677, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_295_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1678, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_297_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1679, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_299_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1680, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_301_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1681, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_303_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1682, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_305_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1683, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_307_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1684, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_309_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1685, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_311_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1686, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_313_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1687, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_315_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1688, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_317_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1689, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_319_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1690, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_321_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1691, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_323_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1692, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_325_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1693, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_327_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1694, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_329_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1695, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_331_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1696, 35U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_333_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1697, 45U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_160_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_245_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_35_247_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_35_249_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_35_251_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_35_253_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_35_255_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_35_257_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_35_259_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_35_261_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_35_263_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_35_265_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_35_267_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_35_269_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_35_271_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_35_273_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_35_275_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_35_277_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_35_279_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_35_281_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_35_283_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_35_285_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_35_287_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_35_289_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_35_291_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_35_293_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_35_295_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_35_297_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_35_299_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_35_301_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_35_303_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_35_305_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_35_307_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_35_309_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_35_311_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_35_313_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_35_315_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_35_317_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_35_319_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_35_321_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_35_323_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_35_325_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_35_327_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_35_329_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_35_331_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_243_0[i];
          }

          tmp_1u[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_35_334_0[i] = tmp_1u[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_35_333_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_335_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1698 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_334_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_337_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1699;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_338_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_335_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_337_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_340_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_338_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1700;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_341_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1701;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_342_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_340_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_35_341_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_344_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1702;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 45; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_159_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_342_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_345_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_35_344_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_346_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_345_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1703;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_347_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1704 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_346_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_348_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_347_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1705;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_349_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_348_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1706 ? ((Parameters *) ssGetDefaultParam(S))->P_1706 : ((BlockIO
            *) _ssGetBlockIO(S))->B_35_348_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1707 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1707 : ((BlockIO *) _ssGetBlockIO(S))->B_35_348_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_350_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_349_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[0];
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_351_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1708, 40U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_352_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1709, 30U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_35_353_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1710[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_353_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1710[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_354_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1711[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_354_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1711[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_355_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1712[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_354_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_355_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1712[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_354_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_355_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1713;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_355_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1713;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_358_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1714[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_358_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1714[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_360_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1715[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_360_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1715[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_362_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1716[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_362_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1716[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_364_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1717[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_364_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1717[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_366_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1718[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_366_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1718[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_368_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1719[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_368_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1719[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_370_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1720[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_370_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1720[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_372_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1721[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_372_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1721[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_374_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1722[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_374_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1722[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_376_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1723[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_376_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1723[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_378_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1724[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_378_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1724[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_380_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1725[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_380_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1725[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_382_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1726[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_382_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1726[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_384_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1727[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_384_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1727[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_386_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1728[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_386_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1728[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_388_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1729[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_388_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1729[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_390_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1730[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_390_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1730[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_392_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1731[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_392_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1731[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_394_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1732[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_394_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1732[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_396_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1733[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_396_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1733[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_398_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1734[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_398_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1734[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_400_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1735[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_400_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1735[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_402_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1736[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_402_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1736[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_404_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1737[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_404_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1737[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_406_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1738[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_406_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1738[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_408_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1739[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_408_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1739[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_410_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1740[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_410_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1740[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_412_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1741[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_412_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1741[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_414_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1742[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_414_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1742[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_416_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1743, 30U *
                   sizeof(real_T));
          }

          tmp_f[0] = ((BlockIO *) _ssGetBlockIO(S))->B_35_353_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_353_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[1] = ((BlockIO *) _ssGetBlockIO(S))->B_35_358_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_358_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[2] = ((BlockIO *) _ssGetBlockIO(S))->B_35_360_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_360_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[3] = ((BlockIO *) _ssGetBlockIO(S))->B_35_362_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_362_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[4] = ((BlockIO *) _ssGetBlockIO(S))->B_35_364_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_364_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[5] = ((BlockIO *) _ssGetBlockIO(S))->B_35_366_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_366_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[6] = ((BlockIO *) _ssGetBlockIO(S))->B_35_368_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_368_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[7] = ((BlockIO *) _ssGetBlockIO(S))->B_35_370_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_370_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[8] = ((BlockIO *) _ssGetBlockIO(S))->B_35_372_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_372_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[9] = ((BlockIO *) _ssGetBlockIO(S))->B_35_374_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_374_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[10] = ((BlockIO *) _ssGetBlockIO(S))->B_35_376_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_376_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[11] = ((BlockIO *) _ssGetBlockIO(S))->B_35_378_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_378_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[12] = ((BlockIO *) _ssGetBlockIO(S))->B_35_380_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_380_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[13] = ((BlockIO *) _ssGetBlockIO(S))->B_35_382_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_382_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[14] = ((BlockIO *) _ssGetBlockIO(S))->B_35_384_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_384_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[15] = ((BlockIO *) _ssGetBlockIO(S))->B_35_386_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_386_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[16] = ((BlockIO *) _ssGetBlockIO(S))->B_35_388_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_388_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[17] = ((BlockIO *) _ssGetBlockIO(S))->B_35_390_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_390_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[18] = ((BlockIO *) _ssGetBlockIO(S))->B_35_392_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_392_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[19] = ((BlockIO *) _ssGetBlockIO(S))->B_35_394_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_394_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[20] = ((BlockIO *) _ssGetBlockIO(S))->B_35_396_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_396_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[21] = ((BlockIO *) _ssGetBlockIO(S))->B_35_398_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_398_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[22] = ((BlockIO *) _ssGetBlockIO(S))->B_35_400_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_400_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[23] = ((BlockIO *) _ssGetBlockIO(S))->B_35_402_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_402_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[24] = ((BlockIO *) _ssGetBlockIO(S))->B_35_404_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_404_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[25] = ((BlockIO *) _ssGetBlockIO(S))->B_35_406_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_406_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[26] = ((BlockIO *) _ssGetBlockIO(S))->B_35_408_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_408_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[27] = ((BlockIO *) _ssGetBlockIO(S))->B_35_410_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_410_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[28] = ((BlockIO *) _ssGetBlockIO(S))->B_35_412_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_412_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          tmp_f[29] = ((BlockIO *) _ssGetBlockIO(S))->B_35_414_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_356_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_414_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_356_0[1];
          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_417_0[i] = tmp_f[i] + ((BlockIO
              *) _ssGetBlockIO(S))->B_35_416_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_418_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1744 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_417_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_420_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1745;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_421_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_418_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_420_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_423_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_421_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1746;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_424_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1747;
          }

          for (i = 0; i < 30; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_425_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_423_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_35_424_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_427_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1748, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_429_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1749, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_431_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1750, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_433_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1751, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_435_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1752, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_437_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1753, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_439_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1754, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_441_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1755, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_443_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1756, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_445_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1757, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_447_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1758, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_449_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1759, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_451_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1760, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_453_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1761, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_455_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1762, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_457_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1763, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_459_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1764, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_461_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1765, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_463_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1766, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_465_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1767, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_467_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1768, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_469_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1769, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_471_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1770, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_473_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1771, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_475_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1772, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_477_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1773, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_479_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1774, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_481_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1775, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_483_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1776, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_485_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1777, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_487_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1778, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_489_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1779, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_491_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1780, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_493_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1781, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_495_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1782, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_497_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1783, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_499_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1784, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_501_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1785, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_503_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1786, 30U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_505_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1787, 40U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_352_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_427_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_35_429_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_35_431_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_35_433_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_35_435_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_35_437_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_35_439_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_35_441_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_35_443_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_35_445_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_35_447_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_35_449_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_35_451_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_35_453_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_35_455_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_35_457_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_35_459_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_35_461_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_35_463_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_35_465_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_35_467_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_35_469_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_35_471_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_35_473_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_35_475_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_35_477_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_35_479_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_35_481_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_35_483_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_35_485_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_35_487_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_35_489_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_35_491_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_35_493_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_35_495_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_35_497_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_35_499_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_35_501_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_35_503_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_425_0[i];
          }

          tmp_15[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_35_506_0[i] = tmp_15[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_35_505_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_507_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1788 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_506_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_509_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1789;
          }

          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_510_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_507_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_509_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_512_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_510_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1790;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_513_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1791;
          }

          for (i = 0; i < 40; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_514_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_512_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_35_513_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_516_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1792;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 40; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_351_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_514_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_517_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_35_516_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_518_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_517_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1793;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_519_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1794 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_518_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_520_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_519_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1795;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_521_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_520_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1796 ? ((Parameters *) ssGetDefaultParam(S))->P_1796 : ((BlockIO
            *) _ssGetBlockIO(S))->B_35_520_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1797 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1797 : ((BlockIO *) _ssGetBlockIO(S))->B_35_520_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_522_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_521_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[1];
          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_523_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1798, 50U *
                   sizeof(real_T));
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_524_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1799, 45U *
                   sizeof(real_T));
            ((BlockIO *) _ssGetBlockIO(S))->B_35_525_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1800[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_525_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1800[1];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_526_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_43_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1801[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_526_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_55_42_0 + ((Parameters *) ssGetDefaultParam(S)
            )->P_1801[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_527_0[0] = ((Parameters *)
            ssGetDefaultParam(S))->P_1802[0] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_526_0[0];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_527_0[1] = ((Parameters *)
            ssGetDefaultParam(S))->P_1802[1] * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_526_0[1];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[0] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_527_0[0] + ((Parameters *) ssGetDefaultParam
            (S))->P_1803;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1] = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_527_0[1] + ((Parameters *) ssGetDefaultParam
            (S))->P_1803;
          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_530_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1804[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_530_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1804[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_532_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1805[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_532_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1805[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_534_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1806[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_534_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1806[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_536_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1807[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_536_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1807[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_538_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1808[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_538_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1808[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_540_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1809[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_540_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1809[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_542_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1810[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_542_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1810[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_544_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1811[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_544_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1811[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_546_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1812[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_546_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1812[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_548_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1813[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_548_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1813[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_550_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1814[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_550_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1814[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_552_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1815[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_552_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1815[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_554_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1816[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_554_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1816[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_556_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1817[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_556_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1817[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_558_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1818[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_558_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1818[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_560_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1819[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_560_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1819[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_562_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1820[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_562_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1820[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_564_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1821[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_564_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1821[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_566_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1822[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_566_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1822[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_568_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1823[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_568_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1823[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_570_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1824[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_570_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1824[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_572_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1825[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_572_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1825[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_574_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1826[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_574_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1826[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_576_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1827[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_576_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1827[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_578_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1828[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_578_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1828[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_580_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1829[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_580_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1829[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_582_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1830[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_582_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1830[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_584_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1831[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_584_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1831[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_586_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1832[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_586_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1832[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_588_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1833[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_588_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1833[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_590_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1834[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_590_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1834[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_592_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1835[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_592_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1835[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_594_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1836[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_594_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1836[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_596_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1837[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_596_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1837[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_598_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1838[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_598_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1838[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_600_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1839[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_600_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1839[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_602_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1840[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_602_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1840[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_604_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1841[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_604_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1841[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_606_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1842[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_606_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1842[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_608_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1843[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_608_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1843[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_610_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1844[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_610_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1844[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_612_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1845[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_612_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1845[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_614_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1846[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_614_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1846[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_616_0[0] = ((Parameters *)
              ssGetDefaultParam(S))->P_1847[0];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_616_0[1] = ((Parameters *)
              ssGetDefaultParam(S))->P_1847[1];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_618_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1848, 45U *
                   sizeof(real_T));
          }

          tmp_1u[0] = ((BlockIO *) _ssGetBlockIO(S))->B_35_525_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_525_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[1] = ((BlockIO *) _ssGetBlockIO(S))->B_35_530_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_530_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[2] = ((BlockIO *) _ssGetBlockIO(S))->B_35_532_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_532_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[3] = ((BlockIO *) _ssGetBlockIO(S))->B_35_534_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_534_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[4] = ((BlockIO *) _ssGetBlockIO(S))->B_35_536_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_536_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[5] = ((BlockIO *) _ssGetBlockIO(S))->B_35_538_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_538_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[6] = ((BlockIO *) _ssGetBlockIO(S))->B_35_540_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_540_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[7] = ((BlockIO *) _ssGetBlockIO(S))->B_35_542_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_542_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[8] = ((BlockIO *) _ssGetBlockIO(S))->B_35_544_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_544_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[9] = ((BlockIO *) _ssGetBlockIO(S))->B_35_546_0[0] * ((BlockIO *)
            _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_546_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[10] = ((BlockIO *) _ssGetBlockIO(S))->B_35_548_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_548_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[11] = ((BlockIO *) _ssGetBlockIO(S))->B_35_550_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_550_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[12] = ((BlockIO *) _ssGetBlockIO(S))->B_35_552_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_552_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[13] = ((BlockIO *) _ssGetBlockIO(S))->B_35_554_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_554_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[14] = ((BlockIO *) _ssGetBlockIO(S))->B_35_556_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_556_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[15] = ((BlockIO *) _ssGetBlockIO(S))->B_35_558_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_558_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[16] = ((BlockIO *) _ssGetBlockIO(S))->B_35_560_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_560_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[17] = ((BlockIO *) _ssGetBlockIO(S))->B_35_562_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_562_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[18] = ((BlockIO *) _ssGetBlockIO(S))->B_35_564_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_564_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[19] = ((BlockIO *) _ssGetBlockIO(S))->B_35_566_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_566_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[20] = ((BlockIO *) _ssGetBlockIO(S))->B_35_568_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_568_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[21] = ((BlockIO *) _ssGetBlockIO(S))->B_35_570_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_570_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[22] = ((BlockIO *) _ssGetBlockIO(S))->B_35_572_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_572_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[23] = ((BlockIO *) _ssGetBlockIO(S))->B_35_574_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_574_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[24] = ((BlockIO *) _ssGetBlockIO(S))->B_35_576_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_576_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[25] = ((BlockIO *) _ssGetBlockIO(S))->B_35_578_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_578_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[26] = ((BlockIO *) _ssGetBlockIO(S))->B_35_580_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_580_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[27] = ((BlockIO *) _ssGetBlockIO(S))->B_35_582_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_582_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[28] = ((BlockIO *) _ssGetBlockIO(S))->B_35_584_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_584_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[29] = ((BlockIO *) _ssGetBlockIO(S))->B_35_586_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_586_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[30] = ((BlockIO *) _ssGetBlockIO(S))->B_35_588_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_588_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[31] = ((BlockIO *) _ssGetBlockIO(S))->B_35_590_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_590_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[32] = ((BlockIO *) _ssGetBlockIO(S))->B_35_592_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_592_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[33] = ((BlockIO *) _ssGetBlockIO(S))->B_35_594_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_594_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[34] = ((BlockIO *) _ssGetBlockIO(S))->B_35_596_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_596_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[35] = ((BlockIO *) _ssGetBlockIO(S))->B_35_598_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_598_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[36] = ((BlockIO *) _ssGetBlockIO(S))->B_35_600_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_600_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[37] = ((BlockIO *) _ssGetBlockIO(S))->B_35_602_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_602_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[38] = ((BlockIO *) _ssGetBlockIO(S))->B_35_604_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_604_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[39] = ((BlockIO *) _ssGetBlockIO(S))->B_35_606_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_606_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[40] = ((BlockIO *) _ssGetBlockIO(S))->B_35_608_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_608_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[41] = ((BlockIO *) _ssGetBlockIO(S))->B_35_610_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_610_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[42] = ((BlockIO *) _ssGetBlockIO(S))->B_35_612_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_612_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[43] = ((BlockIO *) _ssGetBlockIO(S))->B_35_614_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_614_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          tmp_1u[44] = ((BlockIO *) _ssGetBlockIO(S))->B_35_616_0[0] * ((BlockIO
            *) _ssGetBlockIO(S))->B_35_528_0[0] + ((BlockIO *) _ssGetBlockIO(S)
            )->B_35_616_0[1] * ((BlockIO *) _ssGetBlockIO(S))->B_35_528_0[1];
          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_619_0[i] = tmp_1u[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_35_618_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_620_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1849 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_619_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_622_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1850;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_623_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_620_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_622_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_625_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_623_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1851;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_626_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1852;
          }

          for (i = 0; i < 45; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_627_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_625_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_35_626_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_629_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1853, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_631_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1854, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_633_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1855, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_635_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1856, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_637_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1857, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_639_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1858, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_641_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1859, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_643_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1860, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_645_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1861, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_647_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1862, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_649_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1863, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_651_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1864, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_653_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1865, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_655_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1866, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_657_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1867, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_659_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1868, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_661_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1869, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_663_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1870, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_665_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1871, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_667_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1872, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_669_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1873, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_671_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1874, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_673_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1875, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_675_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1876, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_677_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1877, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_679_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1878, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_681_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1879, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_683_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1880, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_685_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1881, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_687_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1882, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_689_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1883, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_691_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1884, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_693_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1885, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_695_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1886, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_697_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1887, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_699_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1888, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_701_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1889, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_703_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1890, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_705_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1891, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_707_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1892, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_709_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1893, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_711_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1894, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_713_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1895, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_715_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1896, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_717_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1897, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_719_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1898, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_721_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1899, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_723_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1900, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_725_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1901, 45U *
                   sizeof(real_T));
          }

          if (ssIsSampleHit(S, 1, 0)) {
            memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_35_727_0[0]),
                   (void *)((Parameters *) ssGetDefaultParam(S))->P_1902, 50U *
                   sizeof(real_T));
          }

          B_48_0_0 = 0.0;
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
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_524_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_629_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1 += ((BlockIO *) _ssGetBlockIO(S))->B_35_631_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_2 += ((BlockIO *) _ssGetBlockIO(S))->B_35_633_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_3 += ((BlockIO *) _ssGetBlockIO(S))->B_35_635_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_4 += ((BlockIO *) _ssGetBlockIO(S))->B_35_637_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_5 += ((BlockIO *) _ssGetBlockIO(S))->B_35_639_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_6 += ((BlockIO *) _ssGetBlockIO(S))->B_35_641_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_7 += ((BlockIO *) _ssGetBlockIO(S))->B_35_643_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_8 += ((BlockIO *) _ssGetBlockIO(S))->B_35_645_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_9 += ((BlockIO *) _ssGetBlockIO(S))->B_35_647_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_a += ((BlockIO *) _ssGetBlockIO(S))->B_35_649_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_b += ((BlockIO *) _ssGetBlockIO(S))->B_35_651_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_c += ((BlockIO *) _ssGetBlockIO(S))->B_35_653_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_d += ((BlockIO *) _ssGetBlockIO(S))->B_35_655_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_g += ((BlockIO *) _ssGetBlockIO(S))->B_35_657_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_h += ((BlockIO *) _ssGetBlockIO(S))->B_35_659_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_i += ((BlockIO *) _ssGetBlockIO(S))->B_35_661_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_j += ((BlockIO *) _ssGetBlockIO(S))->B_35_663_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_k += ((BlockIO *) _ssGetBlockIO(S))->B_35_665_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_l += ((BlockIO *) _ssGetBlockIO(S))->B_35_667_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_m += ((BlockIO *) _ssGetBlockIO(S))->B_35_669_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_n += ((BlockIO *) _ssGetBlockIO(S))->B_35_671_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_o += ((BlockIO *) _ssGetBlockIO(S))->B_35_673_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_p += ((BlockIO *) _ssGetBlockIO(S))->B_35_675_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_q += ((BlockIO *) _ssGetBlockIO(S))->B_35_677_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_r += ((BlockIO *) _ssGetBlockIO(S))->B_35_679_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_s += ((BlockIO *) _ssGetBlockIO(S))->B_35_681_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_t += ((BlockIO *) _ssGetBlockIO(S))->B_35_683_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_u += ((BlockIO *) _ssGetBlockIO(S))->B_35_685_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_v += ((BlockIO *) _ssGetBlockIO(S))->B_35_687_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_w += ((BlockIO *) _ssGetBlockIO(S))->B_35_689_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_x += ((BlockIO *) _ssGetBlockIO(S))->B_35_691_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_y += ((BlockIO *) _ssGetBlockIO(S))->B_35_693_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_z += ((BlockIO *) _ssGetBlockIO(S))->B_35_695_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_10 += ((BlockIO *) _ssGetBlockIO(S))->B_35_697_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_11 += ((BlockIO *) _ssGetBlockIO(S))->B_35_699_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_12 += ((BlockIO *) _ssGetBlockIO(S))->B_35_701_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_13 += ((BlockIO *) _ssGetBlockIO(S))->B_35_703_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_14 += ((BlockIO *) _ssGetBlockIO(S))->B_35_705_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_18 += ((BlockIO *) _ssGetBlockIO(S))->B_35_707_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_19 += ((BlockIO *) _ssGetBlockIO(S))->B_35_709_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1a += ((BlockIO *) _ssGetBlockIO(S))->B_35_711_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1b += ((BlockIO *) _ssGetBlockIO(S))->B_35_713_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1c += ((BlockIO *) _ssGetBlockIO(S))->B_35_715_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1d += ((BlockIO *) _ssGetBlockIO(S))->B_35_717_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1e += ((BlockIO *) _ssGetBlockIO(S))->B_35_719_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1f += ((BlockIO *) _ssGetBlockIO(S))->B_35_721_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1g += ((BlockIO *) _ssGetBlockIO(S))->B_35_723_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
            tmp_1h += ((BlockIO *) _ssGetBlockIO(S))->B_35_725_0[i] * ((BlockIO *)
              _ssGetBlockIO(S))->B_35_627_0[i];
          }

          tmp_21[0] = B_48_0_0;
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
            ((BlockIO *) _ssGetBlockIO(S))->B_35_728_0[i] = tmp_21[i] +
              ((BlockIO *) _ssGetBlockIO(S))->B_35_727_0[i];
            ((BlockIO *) _ssGetBlockIO(S))->B_35_729_0[i] = ((Parameters *)
              ssGetDefaultParam(S))->P_1903 * ((BlockIO *) _ssGetBlockIO(S))
              ->B_35_728_0[i];
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_731_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1904;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_732_0[i] = muDoubleScalarExp
              (((BlockIO *) _ssGetBlockIO(S))->B_35_729_0[i]) + ((BlockIO *)
              _ssGetBlockIO(S))->B_35_731_0;
            ((BlockIO *) _ssGetBlockIO(S))->B_35_734_0[i] = 1.0 / ((BlockIO *)
              _ssGetBlockIO(S))->B_35_732_0[i] * ((Parameters *)
              ssGetDefaultParam(S))->P_1905;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_735_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1906;
          }

          for (i = 0; i < 50; i++) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_736_0[i] = ((BlockIO *)
              _ssGetBlockIO(S))->B_35_734_0[i] - ((BlockIO *) _ssGetBlockIO(S)
              )->B_35_735_0;
          }

          if (ssIsSampleHit(S, 1, 0)) {
            ((BlockIO *) _ssGetBlockIO(S))->B_35_738_0 = ((Parameters *)
              ssGetDefaultParam(S))->P_1907;
          }

          B_48_0_0 = 0.0;
          for (i = 0; i < 50; i++) {
            B_48_0_0 += ((BlockIO *) _ssGetBlockIO(S))->B_35_523_0[i] *
              ((BlockIO *) _ssGetBlockIO(S))->B_35_736_0[i];
          }

          ((BlockIO *) _ssGetBlockIO(S))->B_35_739_0 = B_48_0_0 + ((BlockIO *)
            _ssGetBlockIO(S))->B_35_738_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_740_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_739_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1908;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_741_0 = ((Parameters *)
            ssGetDefaultParam(S))->P_1909 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_740_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_742_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_741_0 + ((Parameters *) ssGetDefaultParam(S))
            ->P_1910;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_743_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_742_0 >= ((Parameters *) ssGetDefaultParam(S))
            ->P_1911 ? ((Parameters *) ssGetDefaultParam(S))->P_1911 : ((BlockIO
            *) _ssGetBlockIO(S))->B_35_742_0 <= ((Parameters *)
            ssGetDefaultParam(S))->P_1912 ? ((Parameters *) ssGetDefaultParam(S))
            ->P_1912 : ((BlockIO *) _ssGetBlockIO(S))->B_35_742_0;
          ((BlockIO *) _ssGetBlockIO(S))->B_35_744_0 = ((BlockIO *)
            _ssGetBlockIO(S))->B_35_743_0 * ((BlockIO *) _ssGetBlockIO(S))
            ->B_21_1_1[2];
          ((BlockIO *) _ssGetBlockIO(S))->B_35_745_0 = ((((BlockIO *)
            _ssGetBlockIO(S))->B_35_158_0 + ((BlockIO *) _ssGetBlockIO(S))
            ->B_35_350_0) + ((BlockIO *) _ssGetBlockIO(S))->B_35_522_0) +
            ((BlockIO *) _ssGetBlockIO(S))->B_35_744_0;
          if (ssIsSampleHit(S, 1, 0)) {
            /* Scope: '<S1234>/Scope' */
            /* Call into Simulink for Scope */
            ssCallAccelRunBlock(S, 35, 746, SS_CALL_MDL_OUTPUTS);
          }

          if (ssIsMajorTimeStep(S)) {
            srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper08_SubsysRanBC);
          }
          break;
        }

        if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 > ((Parameters *)
             ssGetDefaultParam(S))->P_1913) {
          ((BlockIO *) _ssGetBlockIO(S))->B_36_3_0 = ((BlockIO *) _ssGetBlockIO
            (S))->B_35_745_0;
        } else {
          ((BlockIO *) _ssGetBlockIO(S))->B_36_3_0 = ((BlockIO *) _ssGetBlockIO
            (S))->B_34_798_0;
        }

        if (ssIsMajorTimeStep(S)) {
          srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper07_SubsysRanBC);
        }
        break;
      }

      if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 > ((Parameters *)
           ssGetDefaultParam(S))->P_1914) {
        ((BlockIO *) _ssGetBlockIO(S))->B_37_3_0 = ((BlockIO *) _ssGetBlockIO(S))
          ->B_36_3_0;
      } else {
        ((BlockIO *) _ssGetBlockIO(S))->B_37_3_0 = ((BlockIO *) _ssGetBlockIO(S))
          ->B_33_748_0;
      }

      if (ssIsMajorTimeStep(S)) {
        srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper06_SubsysRanBC);
      }
      break;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_1915) {
      ((BlockIO *) _ssGetBlockIO(S))->B_38_3_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_37_3_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_38_3_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_32_618_0;
    }

    if (ssIsMajorTimeStep(S)) {
      srUpdateBC(((D_Work *) ssGetRootDWork(S))->SOCupper05_SubsysRanBC);
    }
    break;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_40_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2004) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_80_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_38_3_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_80_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_31_341_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_81_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_80_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2005 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2005 : ((BlockIO *) _ssGetBlockIO(S))->B_55_80_0 <=
    ((Parameters *) ssGetDefaultParam(S))->P_2006 ? ((Parameters *)
    ssGetDefaultParam(S))->P_2006 : ((BlockIO *) _ssGetBlockIO(S))->B_55_80_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_82_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2007;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_83_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2008;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_17_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2009) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_81_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_41) {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_55_81_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_55_82_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_20_1_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_17_0 * ((BlockIO *) _ssGetBlockIO(S))->B_20_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_85_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_20_1_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_85_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_83_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_86_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_f;
    ssCallAccelRunBlock(S, 55, 87, SS_CALL_MDL_OUTPUTS);
    B_55_889_0 = ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_c;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_89_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory_PreviousInput_b;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_90_0 = ((D_Work *) ssGetRootDWork(S))
      ->Memory1_PreviousInput_c - ((BlockIO *) _ssGetBlockIO(S))->B_55_89_0;
    ssCallAccelRunBlock(S, 55, 91, SS_CALL_MDL_OUTPUTS);
  }

  /* TransferFcn: '<S34>/Clutch  Actuator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_92_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2015*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_93_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2018 * ((BlockIO *) _ssGetBlockIO(S))->B_55_92_0;
  ssCallAccelRunBlock(S, 55, 94, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_95_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2021*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator_CSTATE_k;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_96_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2024 * ((BlockIO *) _ssGetBlockIO(S))->B_55_95_0;
  ssCallAccelRunBlock(S, 55, 97, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_98_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2027*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator1_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_99_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2030 * ((BlockIO *) _ssGetBlockIO(S))->B_55_98_0;
  ssCallAccelRunBlock(S, 55, 100, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator2' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_101_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2033*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator2_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_102_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2036 * ((BlockIO *) _ssGetBlockIO(S))->B_55_101_0;
  ssCallAccelRunBlock(S, 55, 103, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S91>/Clutch  Actuator3' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_104_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2039*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator3_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_105_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2042 * ((BlockIO *) _ssGetBlockIO(S))->B_55_104_0;
  ssCallAccelRunBlock(S, 55, 106, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S35>/Clutch  Actuator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_107_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2045*((ContinuousStates *) ssGetContStates(S))
    ->ClutchActuator_CSTATE_kf;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_108_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2048 * ((BlockIO *) _ssGetBlockIO(S))->B_55_107_0;
  ssCallAccelRunBlock(S, 55, 109, SS_CALL_MDL_OUTPUTS);

  /* TransferFcn: '<S4>/Pressure controller time constant//1' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_110_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2051*((ContinuousStates *) ssGetContStates(S))
    ->Pressurecontrollertimeconstant1_CSTATE;
  ssCallAccelRunBlock(S, 55, 111, SS_CALL_MDL_OUTPUTS);

  /* FromWorkspace: '<Root>/drive cycle' */

  /* Call into Simulink for From Workspace */
  ssCallAccelRunBlock(S, 55, 112, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_113_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_112_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2054 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2054 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_112_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2055 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2055 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_112_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_114_0 = B_55_625_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_2056 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_2056 : B_55_625_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2057 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2057 : B_55_625_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_115_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_113_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_114_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_116_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2058 * ((BlockIO *) _ssGetBlockIO(S))->B_55_115_0;

  /* Derivative: '<S2049>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_117_0 = 0.0;
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
      ((BlockIO *) _ssGetBlockIO(S))->B_55_117_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_55_116_0 - *lastU++) / deltaT;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_118_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2059 * ((BlockIO *) _ssGetBlockIO(S))->B_55_117_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_119_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2060 * ((BlockIO *) _ssGetBlockIO(S))->B_55_116_0;

  /* Integrator: '<S2049>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,&((PrevZCSigStates *)
      _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE_b,
                       ((BlockIO *) _ssGetBlockIO(S))->B_55_114_0);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_g =
        ((Parameters *) ssGetDefaultParam(S))->P_2061;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_120_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_g;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_121_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2062 * ((BlockIO *) _ssGetBlockIO(S))->B_55_120_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_122_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_55_118_0 + ((BlockIO *) _ssGetBlockIO(S))->B_55_119_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_55_121_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_123_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2063 * ((BlockIO *) _ssGetBlockIO(S))->B_55_122_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_124_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_123_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2064 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2064 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_123_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2065 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2065 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_123_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_125_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2066 * ((BlockIO *) _ssGetBlockIO(S))->B_55_124_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_126_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2067 * ((BlockIO *) _ssGetBlockIO(S))->B_55_125_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_127_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2068 * ((BlockIO *) _ssGetBlockIO(S))->B_55_126_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_128_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2069;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_129_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2070;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_130_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2071;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_131_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory_PreviousInput_p;
    if (B_55_625_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2073) {
      B_48_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_55_130_0 * ((BlockIO *)
        _ssGetBlockIO(S))->B_55_131_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_55_134_0 = B_48_0_0 >= ((Parameters *)
        ssGetDefaultParam(S))->P_1918 ? ((Parameters *) ssGetDefaultParam(S))
        ->P_1918 : B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_1919 ?
        ((Parameters *) ssGetDefaultParam(S))->P_1919 : B_48_0_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_134_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_1917;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_55_135_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2074;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_127_0 != 0.0) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_136_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_134_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_136_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_135_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_137_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_127_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_136_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_138_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_137_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2075 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2075 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_137_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2076 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2076 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_137_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_139_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_127_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_138_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_140_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_139_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_141_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2077;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_140_0 != 0.0) {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_39_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_1916) {
      ((BlockIO *) _ssGetBlockIO(S))->B_39_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_55_128_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_39_0_0 = ((BlockIO *) _ssGetBlockIO(S)
        )->B_55_129_0;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_39_1_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_127_0 * ((BlockIO *) _ssGetBlockIO(S))->B_39_0_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_39_2_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_39_1_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_130_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_143_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_39_2_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_143_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_141_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_17_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2078) {
    ((BlockIO *) _ssGetBlockIO(S))->B_19_0_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_17_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_85_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_145_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_19_0_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_145_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_143_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_146_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory2_PreviousInput;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_147_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_145_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_146_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_148_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2080 * ((BlockIO *) _ssGetBlockIO(S))->B_55_147_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_149_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2081 * ((BlockIO *) _ssGetBlockIO(S))->B_55_148_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_150_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_b;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_151_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2083 * ((BlockIO *) _ssGetBlockIO(S))->B_55_148_0;

  /* Derivative: '<S2091>/Ideal Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->IdealDerivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_152_0 = 0.0;
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
      ((BlockIO *) _ssGetBlockIO(S))->B_55_152_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_55_151_0 - *lastU++) / deltaT;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_153_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_55_149_0 + ((BlockIO *) _ssGetBlockIO(S))->B_55_150_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_55_152_0;

  /* TransferFcn: '<S2056>/Transfer Fcn' */
  ((BlockIO *) _ssGetBlockIO(S))->B_55_154_0 = (((Parameters *)
    ssGetDefaultParam(S))->P_2086)*((ContinuousStates *) ssGetContStates(S))
    ->TransferFcn_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_154_0 += ((Parameters *)
    ssGetDefaultParam(S))->P_2087*((BlockIO *) _ssGetBlockIO(S))->B_55_153_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_155_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_154_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2089 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2089 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_154_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2090 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2090 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_154_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_156_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2091;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_155_0 != 0.0) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_155_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_156_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_158_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2092 * ((BlockIO *) _ssGetBlockIO(S))->B_55_37_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_55_20_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2093) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_161_0 = look2_binlxpw(((BlockIO *)
      _ssGetBlockIO(S))->B_55_158_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
      ((Parameters *) ssGetDefaultParam(S))->P_1934, ((Parameters *)
      ssGetDefaultParam(S))->P_1935, ((Parameters *) ssGetDefaultParam(S))
      ->P_1933, ((Parameters *) ssGetDefaultParam(S))->P_2294, 47U);
  } else {
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_20_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_1932) {
      ((BlockIO *) _ssGetBlockIO(S))->B_50_2_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_158_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1930, ((Parameters *)
        ssGetDefaultParam(S))->P_1931, ((Parameters *) ssGetDefaultParam(S))
        ->P_1929, ((Parameters *) ssGetDefaultParam(S))->P_2293, 47U);
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_50_2_0 = look2_binlxpw(((BlockIO *)
        _ssGetBlockIO(S))->B_55_158_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_26_0,
        ((Parameters *) ssGetDefaultParam(S))->P_1927, ((Parameters *)
        ssGetDefaultParam(S))->P_1928, ((Parameters *) ssGetDefaultParam(S))
        ->P_1926, ((Parameters *) ssGetDefaultParam(S))->P_2292, 47U);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_55_161_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_50_2_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_162_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2094 * ((BlockIO *) _ssGetBlockIO(S))->B_55_161_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_163_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2095;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_164_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_162_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_163_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_165_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory_PreviousInput_c;
  }

  B_48_0_0 = rt_Lookup2D_Normal((const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2097, 36, (const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2098, 11, (const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2099, ((BlockIO *) _ssGetBlockIO(S))->B_55_164_0,
                                ((BlockIO *) _ssGetBlockIO(S))->B_55_165_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_167_0 = B_48_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2100 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2100 : B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2101 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2101 : B_48_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_168_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_157_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_169_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2102;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_170_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_167_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_168_0 / ((BlockIO *)
    _ssGetBlockIO(S))->B_55_169_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_171_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_170_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2103 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2103 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_170_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2104 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2104 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_170_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_173_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_171_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_164_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_174_0 = rt_Lookup2D_Normal((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2105, 36, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2106, 11, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2107, ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_164_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_165_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_175_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_174_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_168_0 / ((BlockIO *)
    _ssGetBlockIO(S))->B_55_169_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_176_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2108;
  }

  B_48_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_55_175_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_176_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_178_0 = B_48_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2109 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2109 : B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2110 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2110 : B_48_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_179_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_173_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_178_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_180_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_171_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_181_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2111;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_180_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2112) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_182_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_179_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_182_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_181_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_183_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2113;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_185_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_171_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_183_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_186_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_165_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2114 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2114 : ((BlockIO *) _ssGetBlockIO
      (S))->B_55_165_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2115 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2115 : ((BlockIO *) _ssGetBlockIO
      (S))->B_55_165_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_188_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_186_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_157_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_190_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_185_0 / (((BlockIO *) _ssGetBlockIO(S))->B_55_188_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2116 ? ((Parameters *) ssGetDefaultParam(S))
                    ->P_2116 : ((BlockIO *) _ssGetBlockIO(S))->B_55_188_0 <=
                    ((Parameters *) ssGetDefaultParam(S))->P_2117 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2117 : ((BlockIO *) _ssGetBlockIO(S))
                    ->B_55_188_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_192_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2118;
  }

  if (muDoubleScalarAbs(((BlockIO *) _ssGetBlockIO(S))->B_55_171_0) >=
      ((Parameters *) ssGetDefaultParam(S))->P_2119) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_193_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_190_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_193_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_192_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_194_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2120;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_186_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2121) {
    B_48_0_0 = (((BlockIO *) _ssGetBlockIO(S))->B_55_182_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_1922 ? ((Parameters *) ssGetDefaultParam(S))
                ->P_1922 : ((BlockIO *) _ssGetBlockIO(S))->B_55_182_0 <=
                ((Parameters *) ssGetDefaultParam(S))->P_1923 ? ((Parameters *)
      ssGetDefaultParam(S))->P_1923 : ((BlockIO *) _ssGetBlockIO(S))->B_55_182_0)
      / (((BlockIO *) _ssGetBlockIO(S))->B_55_193_0 >= ((Parameters *)
          ssGetDefaultParam(S))->P_1920 ? ((Parameters *) ssGetDefaultParam(S)
         )->P_1920 : ((BlockIO *) _ssGetBlockIO(S))->B_55_193_0 <= ((Parameters *)
          ssGetDefaultParam(S))->P_1921 ? ((Parameters *) ssGetDefaultParam(S)
         )->P_1921 : ((BlockIO *) _ssGetBlockIO(S))->B_55_193_0);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_196_0 = B_48_0_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_1924 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_1924 : B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_1925 ?
      ((Parameters *) ssGetDefaultParam(S))->P_1925 : B_48_0_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_196_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_194_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_197_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2122;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2123) {
    B_48_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 * ((BlockIO *)
      _ssGetBlockIO(S))->B_55_164_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_196_0
      / ((BlockIO *) _ssGetBlockIO(S))->B_55_197_0;
  } else {
    B_48_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 * ((BlockIO *)
      _ssGetBlockIO(S))->B_55_164_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_196_0
      / ((BlockIO *) _ssGetBlockIO(S))->B_55_197_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_201_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2124;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_203_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2125;
  }

  B_55_205_0 = !((((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 < ((BlockIO *)
    _ssGetBlockIO(S))->B_55_201_0) && (((BlockIO *) _ssGetBlockIO(S))->B_55_39_0
    >= ((BlockIO *) _ssGetBlockIO(S))->B_55_203_0));
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_206_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2126;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_208_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_52_1_0 + ((BlockIO *) _ssGetBlockIO(S))->B_53_3_0) + ((BlockIO *)
    _ssGetBlockIO(S))->B_54_3_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_209_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_208_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_33_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_210_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2127 * ((BlockIO *) _ssGetBlockIO(S))->B_55_209_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_212_0 = !((((BlockIO *) _ssGetBlockIO(S)
    )->B_55_157_0 > ((BlockIO *) _ssGetBlockIO(S))->B_55_206_0) && (((BlockIO *)
    _ssGetBlockIO(S))->B_55_39_0 <= ((BlockIO *) _ssGetBlockIO(S))->B_55_210_0));
  ((BlockIO *) _ssGetBlockIO(S))->B_55_213_0 = B_48_0_0 * (real_T)B_55_205_0 *
    (real_T)((BlockIO *) _ssGetBlockIO(S))->B_55_212_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_214_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2128;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_155_0 != 0.0) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_215_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_213_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_215_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_214_0;
  }

  ssCallAccelRunBlock(S, 55, 216, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 55, 217, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 218, SS_CALL_MDL_OUTPUTS);
    B_55_889_0 = ((Parameters *) ssGetDefaultParam(S))->P_2129 * ((BlockIO *)
      _ssGetBlockIO(S))->B_55_218_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_220_0 = B_55_889_0 >= ((Parameters *)
      ssGetDefaultParam(S))->P_2130 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_2130 : B_55_889_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2131 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2131 : B_55_889_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_221_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2132, 3, ((BlockIO *)
      _ssGetBlockIO(S))->B_55_220_0, (const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_2133);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_543_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2134, 18, ((BlockIO *)
      _ssGetBlockIO(S))->B_55_220_0, (const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_2135);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_223_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_543_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2136 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2136 : ((BlockIO *) _ssGetBlockIO
      (S))->B_55_543_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2137 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2137 : ((BlockIO *) _ssGetBlockIO
      (S))->B_55_543_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_224_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2138;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_225_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2139;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_85_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2140) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_226_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_224_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_226_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_225_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    B_55_889_0 = ((Parameters *) ssGetDefaultParam(S))->P_2141 * ((BlockIO *)
      _ssGetBlockIO(S))->B_55_218_0;
    if (B_55_889_0 > ((Parameters *) ssGetDefaultParam(S))->P_2142) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_230_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_7;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_230_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_6;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_231_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_226_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_230_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2143 - B_55_889_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_234_0 = look1_binlxpw(B_6_2_0,
      ((Parameters *) ssGetDefaultParam(S))->P_2145, ((Parameters *)
      ssGetDefaultParam(S))->P_2144, 2U);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_235_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_231_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_234_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_236_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_235_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2146 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2146 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_235_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2147 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2147 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_235_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_237_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_85_0 + ((BlockIO *) _ssGetBlockIO(S))->B_55_236_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_238_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2148;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_239_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2301;

    /* S-Function (sfblk_manswitch): '<S31>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_55_240_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_239_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_528_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2149;
    ssCallAccelRunBlock(S, 55, 242, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_243_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_237_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_242_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_244_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_243_0 + ((BlockIO *) _ssGetBlockIO(S))->B_55_89_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_245_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_244_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2150 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2150 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_244_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2151 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2151 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_244_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_246_0 = muDoubleScalarMin(((BlockIO *)
    _ssGetBlockIO(S))->B_55_223_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_245_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_247_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_246_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2152 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2152 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_246_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2153 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2153 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_246_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_55_220_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2154) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_248_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_221_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_248_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_247_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_249_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2155;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_248_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2156) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_250_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_248_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_250_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_249_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S1>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 251, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_252_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2157;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_253_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2158;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_231_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2159) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_254_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_252_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_254_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_253_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_255_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_254_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_238_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_256_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2160;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_257_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2161;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_231_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2162) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_258_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_256_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_258_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_257_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_259_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2163 * ((BlockIO *) _ssGetBlockIO(S))->B_55_218_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_260_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2164 * ((BlockIO *) _ssGetBlockIO(S))->B_55_259_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_261_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_248_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2165 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2165 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_248_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2166 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2166 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_248_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_262_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_260_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_261_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_263_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2167 * ((BlockIO *) _ssGetBlockIO(S))->B_55_262_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_265_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2171;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_266_0 = rt_Lookup2D_Normal((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2168, 32, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2169, 16, (const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2170, ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_263_0, ((BlockIO *) _ssGetBlockIO(S))->B_55_259_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_263_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_265_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_267_0 = rt_Lookup((const real_T *)
    ((Parameters *) ssGetDefaultParam(S))->P_2172, 28, ((BlockIO *)
    _ssGetBlockIO(S))->B_55_263_0, (const real_T *)((Parameters *)
    ssGetDefaultParam(S))->P_2173);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_268_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2174 * ((BlockIO *) _ssGetBlockIO(S))->B_55_267_0;
  if (ssIsSampleHit(S, 1, 0)) {
    B_55_883_0 = ((Parameters *) ssGetDefaultParam(S))->P_2177;
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2175 - ((Parameters *)
      ssGetDefaultParam(S))->P_2177;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_274_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_55_259_0 - ((Parameters *) ssGetDefaultParam(S))->P_2175) *
      ((Parameters *) ssGetDefaultParam(S))->P_2176 / B_6_2_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_275_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_268_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_274_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_278_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_55_259_0 - B_55_883_0) * ((Parameters *) ssGetDefaultParam(S))
      ->P_2178 / B_6_2_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_279_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_266_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_278_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_280_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_275_0 + ((BlockIO *) _ssGetBlockIO(S))->B_55_279_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_55_259_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2179) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_281_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_266_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_281_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_280_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_282_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_281_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2180 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2180 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_281_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2181 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2181 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_281_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_283_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_258_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_238_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_282_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_284_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_255_0 + ((BlockIO *) _ssGetBlockIO(S))->B_55_283_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S10>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 285, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S10>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 286, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_287_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_e;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_288_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2183 * ((BlockIO *) _ssGetBlockIO(S))->B_55_287_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_289_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator3_CSTATE;
  B_48_0_0 = ((Parameters *) ssGetDefaultParam(S))->P_2185 * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_289_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_291_0 = B_48_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2186 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2186 : B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2187 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2187 : B_48_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_293_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_288_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_291_0 * ((Parameters *)
    ssGetDefaultParam(S))->P_2188;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S10>/cons1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 294, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_295_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2189;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_296_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_284_0 / ((BlockIO *) _ssGetBlockIO(S))->B_55_295_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S16>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 297, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S16>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 298, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S16>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 299, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 300, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 301, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 302, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S13>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 303, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_220_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_2190) {
      B_48_0_0 = ((Parameters *) ssGetDefaultParam(S))->P_1 * ((BlockIO *)
        _ssGetBlockIO(S))->B_55_220_0;
      ((BlockIO *) _ssGetBlockIO(S))->B_55_306_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_4 / (B_48_0_0 >= ((Parameters *)
        ssGetDefaultParam(S))->P_2 ? ((Parameters *) ssGetDefaultParam(S))->P_2 :
        B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_3 ? ((Parameters *)
        ssGetDefaultParam(S))->P_3 : B_48_0_0) * ((Parameters *)
        ssGetDefaultParam(S))->P_5;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_306_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_0;
    }

    B_55_889_0 = B_55_889_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2191 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2191 : B_55_889_0 <= ((Parameters
      *) ssGetDefaultParam(S))->P_2192 ? ((Parameters *) ssGetDefaultParam(S))
      ->P_2192 : B_55_889_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_528_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2193 * B_55_889_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_543_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2196 * rt_Lookup((const real_T *)((Parameters *)
      ssGetDefaultParam(S))->P_2194, 63, B_55_889_0, (const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2195);
    B_55_883_0 = ((Parameters *) ssGetDefaultParam(S))->P_2197;
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2198;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_330_0 = 1.0 / ((BlockIO *)
      _ssGetBlockIO(S))->B_55_528_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_543_0
      * ((Parameters *) ssGetDefaultParam(S))->P_2197 * ((Parameters *)
      ssGetDefaultParam(S))->P_2198;

    /* Scope: '<S14>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 314, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S15>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 315, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 330, SS_CALL_MDL_OUTPUTS);
  }

  B_48_0_0 = ((Parameters *) ssGetDefaultParam(S))->P_2199 * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_122_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_345_0 = B_48_0_0 >= ((Parameters *)
    ssGetDefaultParam(S))->P_2200 ? ((Parameters *) ssGetDefaultParam(S))
    ->P_2200 : B_48_0_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2201 ?
    ((Parameters *) ssGetDefaultParam(S))->P_2201 : B_48_0_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_346_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2202 * ((BlockIO *) _ssGetBlockIO(S))->B_55_345_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 347, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S5>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 348, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S5>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 349, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S5>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 350, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_351_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2203 * B_55_625_0;

    /* Scope: '<S143>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 352, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S143>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 353, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S145>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 354, SS_CALL_MDL_OUTPUTS);
  }

  /* Derivative: '<S145>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))
            ->Derivative_RWORK_h.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_h.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      ((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_55_351_0 - *lastU++) / deltaT;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S145>/Scope7' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 356, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_357_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2204;

    /* Scope: '<S146>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 358, SS_CALL_MDL_OUTPUTS);
  }

  /* TransportDelay: '<S146>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_o.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_o.TUbufferPtrs[1];
    real_T simTime = ssGetT(S);
    real_T tMinusDelay = simTime - ((Parameters *) ssGetDefaultParam(S))->P_2205;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_359_0 =
      hyd_hyb_2_opt_cont_online_acc_rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.CircularBufSize,
      &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Last,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Tail,
      ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head,
      ((Parameters *) ssGetDefaultParam(S))->P_2206,
      1,
      (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));
  }

  /* Level2 S-Function Block: '<S153>/B_20_0' (stateflow) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 23, 0, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_361_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2207;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2208) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_362_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_23_0_1;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_362_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_361_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S146>/Scope2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 363, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_364_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2209;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2210) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_365_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_351_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_365_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_364_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S146>/Scope3' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 366, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S146>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 367, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S146>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 368, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_369_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_351_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_355_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S147>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 370, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_371_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2211;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2212) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_372_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_369_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_372_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_371_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S147>/Scope2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 373, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_374_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2213;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2214) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_375_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_351_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_375_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_374_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S147>/Scope3' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 376, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S147>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 377, SS_CALL_MDL_OUTPUTS);
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2215) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_378_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_355_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_378_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_357_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2216) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_379_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_357_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_379_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_355_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_380_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2217;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_381_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2218;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_369_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2219) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_382_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_380_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_382_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_381_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_369_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2220) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_383_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_381_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_383_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_380_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_384_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_382_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_383_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S150>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 385, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_386_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2221;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_387_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2222;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2223) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_388_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_386_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_388_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_387_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_355_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2224) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_389_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_387_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_389_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_386_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_390_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_388_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_389_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S151>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 391, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S141>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 392, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S142>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 393, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S142>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 394, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S142>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 395, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S142>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 396, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S142>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 397, SS_CALL_MDL_OUTPUTS);

    /* Level2 S-Function Block: '<S2048>/B_39_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 42, 0, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S6>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 399, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S6>/driver' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 400, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_401_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator3_CSTATE_i;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_402_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator4_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_403_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator5_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2051>/error a<0' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 404, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_405_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_j;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_406_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_a;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_407_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE_m;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2051>/error a>=0' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 408, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_409_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator6_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_410_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator7_CSTATE;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_411_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator8_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2051>/error1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 412, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2051>/total error' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 413, SS_CALL_MDL_OUTPUTS);
  }

  /* Derivative: '<S6>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_414_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))
            ->Derivative_RWORK_e.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_e.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      ((BlockIO *) _ssGetBlockIO(S))->B_55_414_0 = (((BlockIO *) _ssGetBlockIO(S))
        ->B_55_113_0 - *lastU++) / deltaT;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_415_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2234;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_414_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2235) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_416_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_115_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_416_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_415_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_417_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_416_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_418_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2236 * ((BlockIO *) _ssGetBlockIO(S))->B_55_414_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_419_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2237;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_418_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2238) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_420_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_115_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_420_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_419_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_421_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_420_0);
  ((BlockIO *) _ssGetBlockIO(S))->B_55_422_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_115_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_423_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2239;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_424_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2240;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_425_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2241;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_426_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2242 * ((BlockIO *) _ssGetBlockIO(S))->B_55_416_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_427_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2243 * ((BlockIO *) _ssGetBlockIO(S))->B_55_420_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_428_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2244 * ((BlockIO *) _ssGetBlockIO(S))->B_55_115_0;
  if (((BlockIO *) _ssGetBlockIO(S))->B_55_416_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2245) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_429_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_416_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_429_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_423_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_426_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2246) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_430_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_426_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_430_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_423_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_420_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2247) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_431_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_420_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_431_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_424_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_427_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2248) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_432_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_427_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_432_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_424_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_115_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2249) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_433_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_115_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_433_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_425_0;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_428_0 >= ((Parameters *)
       ssGetDefaultParam(S))->P_2250) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_434_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_428_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_434_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_425_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2049>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 435, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_436_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2251;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_157_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2252) {
    ((BlockIO *) _ssGetBlockIO(S))->B_43_0_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_436_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_170_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_438_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_43_0_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_438_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_170_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_439_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2253;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_440_0 = muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_55_157_0);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_441_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2254;
  }

  if (((BlockIO *) _ssGetBlockIO(S))->B_55_440_0 > ((Parameters *)
       ssGetDefaultParam(S))->P_2255) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_442_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_439_0;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_442_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_441_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_443_0 = (real_T)B_55_205_0 * ((BlockIO *)
    _ssGetBlockIO(S))->B_55_438_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_442_0 *
    (real_T)((BlockIO *) _ssGetBlockIO(S))->B_55_212_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_444_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2256;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_445_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_443_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_444_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_55_446_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_445_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2257 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2257 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_445_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2258 ? ((Parameters
    *) ssGetDefaultParam(S))->P_2258 : ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_445_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S7>/SOC' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 447, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/SOC1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 448, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 449, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 450, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 451, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S7>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 452, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_453_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2259 * ((BlockIO *) _ssGetBlockIO(S))->B_55_446_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S7>/Scope5' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 454, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_456_0 = ((((BlockIO *) _ssGetBlockIO(S))
      ->B_52_6_0 + ((BlockIO *) _ssGetBlockIO(S))->B_53_6_0) + ((BlockIO *)
      _ssGetBlockIO(S))->B_54_6_0) * ((BlockIO *) _ssGetBlockIO(S))->B_55_34_0;

    /* Scope: '<S7>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 457, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2057>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 458, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2061>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 459, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2061>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 460, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2061>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 461, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2061>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 462, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2062>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 463, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2062>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 464, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2062>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 465, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2062>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 466, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2062>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 467, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 468, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope12' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 469, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope14' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 470, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope15' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 471, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_472_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2260;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_473_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2261;

    /* Level2 S-Function Block: '<S2063>/B_41_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 44, 0, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_475_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_472_0 * ((BlockIO *) _ssGetBlockIO(S))->B_55_473_0 / ((BlockIO *)
    _ssGetBlockIO(S))->B_55_164_0 * ((BlockIO *) _ssGetBlockIO(S))->B_44_0_1;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2059>/Scope16' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 476, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 477, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 478, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 479, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 480, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2059>/Scope9' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 481, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2060>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 482, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2060>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 483, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2076>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 484, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2076>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 485, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2077>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 486, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2077>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 487, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2077>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 488, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2077>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 489, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2078>/Scope10' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 490, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2078>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 491, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2078>/Scope7' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 492, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2079>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 493, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2079>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 494, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2079>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 495, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 496, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S2055>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 497, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_499_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2262 * ((BlockIO *) _ssGetBlockIO(S))->B_55_528_0;

    /* Scope: '<S2055>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 500, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_525_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2263 * ((BlockIO *) _ssGetBlockIO(S))->B_55_148_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S2056>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 526, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_527_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2264 * ((BlockIO *) _ssGetBlockIO(S))->B_55_215_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 55, 528, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 543, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 557, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 576, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 591, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S3>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 617, SS_CALL_MDL_OUTPUTS);
    B_55_883_0 = ((Parameters *) ssGetDefaultParam(S))->P_2265;
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2266;
    B_55_889_0 = ((Parameters *) ssGetDefaultParam(S))->P_2267;
    B_55_625_0 = ((Parameters *) ssGetDefaultParam(S))->P_2268;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_626_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2269 * ((BlockIO *) _ssGetBlockIO(S))->B_55_218_0;

    /* Level2 S-Function Block: '<S116>/B_9_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 12, 0, SS_CALL_MDL_OUTPUTS);
    B_48_0_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_55_883_0;
    B_55_629_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_6_2_0;
    B_55_630_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_55_889_0;
    B_55_631_0 = ((BlockIO *) _ssGetBlockIO(S))->B_12_0_1 - B_55_625_0;
    B_55_883_0 = ((Parameters *) ssGetDefaultParam(S))->P_2270;
    B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_2271;
    if (B_48_0_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_634_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_2270;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_634_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_2271;
    }
  }

  hyd_hyb_2_opt_cont_online_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S)
    )->B_55_634_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem1, &((D_Work
    *) ssGetRootDWork(S))->EnabledSubsystem1,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem1, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem1);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_55_629_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_636_0 = B_55_883_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_636_0 = B_6_2_0;
    }
  }

  hyd_hyb_2_opt_cont_online_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S)
    )->B_55_636_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem2, &((D_Work
    *) ssGetRootDWork(S))->EnabledSubsystem2,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem2, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem2);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_55_630_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_638_0 = B_55_883_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_638_0 = B_6_2_0;
    }
  }

  hyd_hyb_2_opt_cont_online_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S)
    )->B_55_638_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem3, &((D_Work
    *) ssGetRootDWork(S))->EnabledSubsystem3,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem3, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem3);
  if (ssIsSampleHit(S, 1, 0)) {
    if (B_55_631_0 != 0.0) {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_640_0 = B_55_883_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_55_640_0 = B_6_2_0;
    }
  }

  hyd_hyb_2_opt_cont_online_EnabledSubsystem1(S, ((BlockIO *) _ssGetBlockIO(S)
    )->B_55_640_0, &((BlockIO *) _ssGetBlockIO(S))->EnabledSubsystem4, &((D_Work
    *) ssGetRootDWork(S))->EnabledSubsystem4,
    (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *) &((Parameters *)
    ssGetDefaultParam(S))->EnabledSubsystem4, &((ContinuousStates *)
    ssGetContStates(S))->EnabledSubsystem4);
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S35>/T' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 693, SS_CALL_MDL_OUTPUTS);
    B_55_883_0 = ((Parameters *) ssGetDefaultParam(S))->P_2272;
    ssCallAccelRunBlock(S, 55, 712, SS_CALL_MDL_OUTPUTS);
    B_55_883_0 = 1.0 / B_55_883_0 * (((Parameters *) ssGetDefaultParam(S))
      ->P_2273 * ((BlockIO *) _ssGetBlockIO(S))->B_55_712_0);
    ssCallAccelRunBlock(S, 55, 715, SS_CALL_MDL_OUTPUTS);
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_712_0 >= ((Parameters *)
         ssGetDefaultParam(S))->P_2274) {
      B_6_2_0 = 1.0 / muDoubleScalarMax(((BlockIO *) _ssGetBlockIO(S))
        ->B_55_712_0, ((Parameters *) ssGetDefaultParam(S))->P_11) * ((BlockIO *)
        _ssGetBlockIO(S))->B_55_715_0;
    } else {
      if (((BlockIO *) _ssGetBlockIO(S))->B_55_715_0 >= ((Parameters *)
           ssGetDefaultParam(S))->P_10) {
        B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_9;
      } else {
        B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_8;
      }
    }

    B_55_883_0 = B_55_883_0 * B_55_883_0 * rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2275, 173, B_6_2_0, (const real_T
      *)((Parameters *) ssGetDefaultParam(S))->P_2276);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_722_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2277 * B_55_883_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_724_0 = rt_Lookup((const real_T *)
      ((Parameters *) ssGetDefaultParam(S))->P_2278, 173, B_6_2_0, (const real_T
      *)((Parameters *) ssGetDefaultParam(S))->P_2279) * B_55_883_0;

    /* Scope: '<S68>/T1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 725, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 783, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S36>/control indictor' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 814, SS_CALL_MDL_OUTPUTS);

    /* MATLABFcn: '<S36>/gear shift' */

    /* Call into Simulink to run the Matlab Fcn block. */
    ssCallAccelRunBlock(S, 55, 815, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S36>/control indictor1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 816, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S36>/engine speed' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 817, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 818, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 833, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_875_0 = ((D_Work *) ssGetRootDWork(S)
      )->Memory1_PreviousInput_b;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_877_0 = ((BlockIO *) _ssGetBlockIO(S)
      )->B_55_875_0 - ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput_g;

    /* Scope: '<S4>/T' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 878, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 879, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_880_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2282 * ((BlockIO *) _ssGetBlockIO(S))->B_55_893_0;
    if (((BlockIO *) _ssGetBlockIO(S))->B_55_880_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_2283) {
      B_55_883_0 = ((BlockIO *) _ssGetBlockIO(S))->B_55_880_0 * ((BlockIO *)
        _ssGetBlockIO(S))->B_55_880_0 * ((Parameters *) ssGetDefaultParam(S))
        ->P_31;
    } else {
      B_55_883_0 = ((Parameters *) ssGetDefaultParam(S))->P_30;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_55_880_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_2284) {
      B_6_2_0 = (((BlockIO *) _ssGetBlockIO(S))->B_55_456_0 + ((Parameters *)
                  ssGetDefaultParam(S))->P_38) * ((Parameters *)
        ssGetDefaultParam(S))->P_39 * ((Parameters *) ssGetDefaultParam(S))
        ->P_40;
    } else {
      B_6_2_0 = ((Parameters *) ssGetDefaultParam(S))->P_37;
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_55_880_0 > ((Parameters *)
         ssGetDefaultParam(S))->P_2285) {
      B_55_889_0 = (((BlockIO *) _ssGetBlockIO(S))->B_55_456_0 + ((Parameters *)
        ssGetDefaultParam(S))->P_35) * ((Parameters *) ssGetDefaultParam(S))
        ->P_36 * muDoubleScalarSin(((Parameters *) ssGetDefaultParam(S))->P_34 *
                                   ((Parameters *) ssGetDefaultParam(S))->P_33);
    } else {
      B_55_889_0 = ((Parameters *) ssGetDefaultParam(S))->P_32;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_55_891_0 = ((B_55_883_0 + B_6_2_0) +
      B_55_889_0) * ((Parameters *) ssGetDefaultParam(S))->P_2286;

    /* Scope: '<S4>/T1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 892, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 893, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_895_0 = (((BlockIO *) _ssGetBlockIO(S)
      )->B_55_893_0 >= ((Parameters *) ssGetDefaultParam(S))->P_2287 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2287 : ((BlockIO *) _ssGetBlockIO
      (S))->B_55_893_0 <= ((Parameters *) ssGetDefaultParam(S))->P_2288 ?
      ((Parameters *) ssGetDefaultParam(S))->P_2288 : ((BlockIO *) _ssGetBlockIO
      (S))->B_55_893_0) * ((Parameters *) ssGetDefaultParam(S))->P_2289;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_896_0 = ((Parameters *) ssGetDefaultParam
    (S))->P_2290 * ((BlockIO *) _ssGetBlockIO(S))->B_55_138_0;
  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<S4>/T2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 897, SS_CALL_MDL_OUTPUTS);
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_55_898_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_55_896_0 - ((BlockIO *) _ssGetBlockIO(S))->B_55_895_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_55_899_0 = ((Parameters *)
      ssGetDefaultParam(S))->P_2291 * ((BlockIO *) _ssGetBlockIO(S))->B_55_880_0;
    ssCallAccelRunBlock(S, 55, 948, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope2' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 949, SS_CALL_MDL_OUTPUTS);

    /* ToWorkspace: '<S9>/To Workspace1' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 55, 950, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_55_951_0[0] = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_113_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_55_951_0[1] = ((BlockIO *) _ssGetBlockIO(S))
      ->B_55_114_0;

    /* ToWorkspace: '<S9>/To Workspace2' */

    /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 55, 952, SS_CALL_MDL_OUTPUTS);
    ssCallAccelRunBlock(S, 55, 953, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope8' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 954, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 955, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 956, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope3' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 957, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope4' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 958, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope5' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 959, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope6' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 960, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<S9>/Scope7' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 55, 961, SS_CALL_MDL_OUTPUTS);
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
      _ssGetBlockIO(S))->B_55_250_0;
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_346_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory3_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_899_0;
  }

  /* Update for TransportDelay: '<S148>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = ssGetT(S);
    ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Head = ((((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK.Head < (((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK.CircularBufSize-1)) ? (((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK.Head+1) : 0);
    if (((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Head == ((D_Work *)
         ssGetRootDWork(S))->TransportDelay_IWORK.Tail) {
      if (!hyd_hyb_2_opt_cont_online_acc_rt_TDelayUpdateTailOrGrowBuf( &((D_Work
             *) ssGetRootDWork(S))->TransportDelay_IWORK.CircularBufSize,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Tail, &((D_Work
             *) ssGetRootDWork(S))->TransportDelay_IWORK.Head, &((D_Work *)
            ssGetRootDWork(S))->TransportDelay_IWORK.Last, simTime -
           ((Parameters *) ssGetDefaultParam(S))->P_1986, tBuffer, uBuffer,
           (NULL), (boolean_T)0, FALSE, &((D_Work *) ssGetRootDWork(S))
           ->TransportDelay_IWORK.MaxNewBufSize)) {
        ssSetErrorStatus(S, "tdelay memory allocation error");
        return;
      }
    }

    (*tBuffer)[((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Head] =
      simTime;
    (*uBuffer)[((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK.Head] =
      ((BlockIO *) _ssGetBlockIO(S))->B_55_49_0;
  }

  /* Update for TransportDelay: '<S149>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_p.TUbufferPtrs[1];
    real_T simTime = ssGetT(S);
    ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head = ((((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK_e.Head < (((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK_e.CircularBufSize-1)) ? (((D_Work
      *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head+1) : 0);
    if (((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head == ((D_Work *)
         ssGetRootDWork(S))->TransportDelay_IWORK_e.Tail) {
      if (!hyd_hyb_2_opt_cont_online_acc_rt_TDelayUpdateTailOrGrowBuf( &((D_Work
             *) ssGetRootDWork(S))->TransportDelay_IWORK_e.CircularBufSize,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Tail,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Last, simTime
           - ((Parameters *) ssGetDefaultParam(S))->P_1990, tBuffer, uBuffer,
           (NULL), (boolean_T)0, FALSE, &((D_Work *) ssGetRootDWork(S))
           ->TransportDelay_IWORK_e.MaxNewBufSize)) {
        ssSetErrorStatus(S, "tdelay memory allocation error");
        return;
      }
    }

    (*tBuffer)[((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head] =
      simTime;
    (*uBuffer)[((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_e.Head] =
      ((BlockIO *) _ssGetBlockIO(S))->B_55_53_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_j[0] = ((BlockIO *)
      _ssGetBlockIO(S))->B_21_1_1[0];
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_j[1] = ((BlockIO *)
      _ssGetBlockIO(S))->B_21_1_1[1];
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_j[2] = ((BlockIO *)
      _ssGetBlockIO(S))->B_21_1_1[2];
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_j[3] = ((BlockIO *)
      _ssGetBlockIO(S))->B_21_1_1[3];
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_f = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_724_0;
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_c = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_722_0;
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_b = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_306_0;
  }

  /* Update for Derivative: '<S2049>/Derivative' */
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
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_55_116_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_p = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_557_0;
    ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_527_0;
  }

  /* Update for Derivative: '<S2091>/Ideal Derivative' */
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
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_55_151_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory_PreviousInput_c = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_499_0;
  }

  /* Update for Derivative: '<S145>/Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_h.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_h.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_h.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_h.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_h.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_55_351_0;
  }

  /* Update for TransportDelay: '<S146>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_o.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&((D_Work *) ssGetRootDWork(S))
      ->TransportDelay_PWORK_o.TUbufferPtrs[1];
    real_T simTime = ssGetT(S);
    ((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head = ((((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head < (((D_Work *)
      ssGetRootDWork(S))->TransportDelay_IWORK_eb.CircularBufSize-1)) ?
      (((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head+1) : 0);
    if (((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head == ((D_Work
          *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Tail) {
      if (!hyd_hyb_2_opt_cont_online_acc_rt_TDelayUpdateTailOrGrowBuf( &((D_Work
             *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.CircularBufSize,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Tail,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head,
           &((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Last,
           simTime - ((Parameters *) ssGetDefaultParam(S))->P_2205, tBuffer,
           uBuffer, (NULL), (boolean_T)0, FALSE, &((D_Work *) ssGetRootDWork(S)
           )->TransportDelay_IWORK_eb.MaxNewBufSize)) {
        ssSetErrorStatus(S, "tdelay memory allocation error");
        return;
      }
    }

    (*tBuffer)[((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head] =
      simTime;
    (*uBuffer)[((D_Work *) ssGetRootDWork(S))->TransportDelay_IWORK_eb.Head] =
      ((BlockIO *) _ssGetBlockIO(S))->B_55_351_0;
  }

  /* Update for Derivative: '<S6>/Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK_e.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_e.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_e.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))
          ->Derivative_RWORK_e.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK_e.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_55_113_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((D_Work *) ssGetRootDWork(S))->Memory1_PreviousInput_b = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_898_0;
    ((D_Work *) ssGetRootDWork(S))->Memory2_PreviousInput_g = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_891_0;
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
      (S))->B_55_453_0;
  }

  /* Derivatives for Integrator: '<S151>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_390_0;
  }

  ((StateDerivatives *) ssGetdX(S))->integrator_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_378_0;
  ((StateDerivatives *) ssGetdX(S))->integrator_CSTATE_n = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_379_0;

  /* Derivatives for Integrator: '<S150>/Integrator1' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_384_0;
  }

  /* Derivatives for Integrator: '<S147>/Integrator1' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_d = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_372_0;
  }

  /* Derivatives for Integrator: '<S147>/Integrator2' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_375_0;
  }

  /* Derivatives for Integrator: '<S146>/Integrator1' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_o = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_362_0;
  }

  /* Derivatives for Integrator: '<S146>/Integrator2' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE_a = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_365_0;
  }

  /* Derivatives for TransferFcn: '<S34>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2013)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2014*((BlockIO *) _ssGetBlockIO(S))->B_12_0_2;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_k = (((Parameters *)
      ssGetDefaultParam(S))->P_2019)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE_k;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_k += ((Parameters *)
      ssGetDefaultParam(S))->P_2020*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem1.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator1' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator1_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2025)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator1_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator1_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2026*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem2.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator2' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator2_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2031)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator2_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator2_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2032*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem3.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S91>/Clutch  Actuator3' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator3_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2037)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator3_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator3_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2038*((BlockIO *) _ssGetBlockIO(S))
      ->EnabledSubsystem4.B_8_0_0;
  }

  /* Derivatives for TransferFcn: '<S35>/Clutch  Actuator' */
  {
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_kf = (((Parameters *)
      ssGetDefaultParam(S))->P_2043)*((ContinuousStates *) ssGetContStates(S))
      ->ClutchActuator_CSTATE_kf;
    ((StateDerivatives *) ssGetdX(S))->ClutchActuator_CSTATE_kf += ((Parameters *)
      ssGetDefaultParam(S))->P_2044*((BlockIO *) _ssGetBlockIO(S))->B_42_0_1;
  }

  /* Derivatives for TransferFcn: '<S4>/Pressure controller time constant//1' */
  {
    ((StateDerivatives *) ssGetdX(S))->Pressurecontrollertimeconstant1_CSTATE =
      (((Parameters *) ssGetDefaultParam(S))->P_2049)*((ContinuousStates *)
      ssGetContStates(S))->Pressurecontrollertimeconstant1_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->Pressurecontrollertimeconstant1_CSTATE +=
      ((Parameters *) ssGetDefaultParam(S))->P_2050*((BlockIO *) _ssGetBlockIO(S))
      ->B_55_877_0;
  }

  /* Derivatives for Integrator: '<S2049>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_g = ((BlockIO *)
      _ssGetBlockIO(S))->B_55_116_0;
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_b = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_525_0;

  /* Derivatives for TransferFcn: '<S2056>/Transfer Fcn' */
  {
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_2084)*((ContinuousStates *) ssGetContStates(S))
      ->TransferFcn_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_2085*((BlockIO *) _ssGetBlockIO(S))->B_55_153_0;
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_e = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_296_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator3_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_880_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator3_CSTATE_i = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_431_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator4_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_432_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator5_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_421_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_j = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_429_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_a = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_430_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE_m = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_417_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator6_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_433_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator7_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_434_0;
  ((StateDerivatives *) ssGetdX(S))->Integrator8_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_55_422_0;
  hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Deriv(S, &((BlockIO *)
    _ssGetBlockIO(S))->EnabledSubsystem1, &((D_Work *) ssGetRootDWork(S))
    ->EnabledSubsystem1, (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *)
    &((Parameters *) ssGetDefaultParam(S))->EnabledSubsystem1,
    &((ContinuousStates *) ssGetContStates(S))->EnabledSubsystem1,
    &((StateDerivatives *) ssGetdX(S))->EnabledSubsystem1);
  hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Deriv(S, &((BlockIO *)
    _ssGetBlockIO(S))->EnabledSubsystem2, &((D_Work *) ssGetRootDWork(S))
    ->EnabledSubsystem2, (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *)
    &((Parameters *) ssGetDefaultParam(S))->EnabledSubsystem2,
    &((ContinuousStates *) ssGetContStates(S))->EnabledSubsystem2,
    &((StateDerivatives *) ssGetdX(S))->EnabledSubsystem2);
  hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Deriv(S, &((BlockIO *)
    _ssGetBlockIO(S))->EnabledSubsystem3, &((D_Work *) ssGetRootDWork(S))
    ->EnabledSubsystem3, (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *)
    &((Parameters *) ssGetDefaultParam(S))->EnabledSubsystem3,
    &((ContinuousStates *) ssGetContStates(S))->EnabledSubsystem3,
    &((StateDerivatives *) ssGetdX(S))->EnabledSubsystem3);
  hyd_hyb_2_opt_cont_online_EnabledSubsystem1_Deriv(S, &((BlockIO *)
    _ssGetBlockIO(S))->EnabledSubsystem4, &((D_Work *) ssGetRootDWork(S))
    ->EnabledSubsystem4, (rtP_EnabledSubsystem1_hyd_hyb_2_opt_cont_online *)
    &((Parameters *) ssGetDefaultParam(S))->EnabledSubsystem4,
    &((ContinuousStates *) ssGetContStates(S))->EnabledSubsystem4,
    &((StateDerivatives *) ssGetdX(S))->EnabledSubsystem4);
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 1671102375U);
  ssSetChecksumVal(S, 1, 3759244638U);
  ssSetChecksumVal(S, 2, 2272765558U);
  ssSetChecksumVal(S, 3, 2105332287U);

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
  ((Parameters *) ssGetDefaultParam(S))->P_1919 = rtMinusInf;
  ((Parameters *) ssGetDefaultParam(S))->P_1997 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2001 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2054 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2056 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2076 = rtMinusInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2100 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2109 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2114 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2116 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2130 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2136 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2150 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2152 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2165 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2180 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2186 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2191 = rtInf;
  ((Parameters *) ssGetDefaultParam(S))->P_2287 = rtInf;
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

    /* Level2 S-Function Block: '<S144>/B_18_0' (stateflow) */
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

    /* Level2 S-Function Block: '<S155>/B_22_0' (stateflow) */
    childS = ssGetSFunction(S, 5);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S156>/B_23_0' (stateflow) */
    childS = ssGetSFunction(S, 6);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S2048>/B_39_0' (stateflow) */
    childS = ssGetSFunction(S, 7);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);

    /* Level2 S-Function Block: '<S2063>/B_41_0' (stateflow) */
    childS = ssGetSFunction(S, 8);
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
