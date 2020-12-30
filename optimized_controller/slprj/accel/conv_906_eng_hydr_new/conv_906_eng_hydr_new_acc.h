/*
 * conv_906_eng_hydr_new_acc.h
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
#ifndef RTW_HEADER_conv_906_eng_hydr_new_acc_h_
#define RTW_HEADER_conv_906_eng_hydr_new_acc_h_
#ifndef conv_906_eng_hydr_new_acc_COMMON_INCLUDES_
# define conv_906_eng_hydr_new_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwmathutil.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_look2d_normal.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#endif                                 /* conv_906_eng_hydr_new_acc_COMMON_INCLUDES_ */

#include "conv_906_eng_hydr_new_acc_types.h"

/* Block signals for system '<S101>/B_17_90' */
typedef struct {
  real_T B_8_0_0;                      /* '<S110>/Clutch A Actuator' */
  real_T B_8_1_0;                      /* '<S110>/engage' */
} rtB_EnabledSubsystem1_conv_906_eng_hydr_new;

/* Block states (auto storage) for system '<S101>/B_17_90' */
typedef struct {
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<S101>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S101>/Enabled Subsystem1' */
  char pad_EnabledSubsystem1_MODE[6];
} rtDW_EnabledSubsystem1_conv_906_eng_hydr_new;

/* Continuous states for system '<S101>/B_17_90' */
typedef struct {
  real_T ClutchAActuator_CSTATE;       /* '<S110>/Clutch A Actuator' */
} rtX_EnabledSubsystem1_conv_906_eng_hydr_new;

/* State derivatives for system '<S101>/B_17_90' */
typedef struct {
  real_T ClutchAActuator_CSTATE;       /* '<S110>/Clutch A Actuator' */
} rtXdot_EnabledSubsystem1_conv_906_eng_hydr_new;

/* State Disabled for system '<S101>/B_17_90' */
typedef struct {
  boolean_T ClutchAActuator_CSTATE;    /* '<S110>/Clutch A Actuator' */
} rtXdis_EnabledSubsystem1_conv_906_eng_hydr_new;

/* Block signals (auto storage) */
typedef struct {
  real_T B_20_0_0;                     /* '<S9>/Memory' */
  real_T B_20_1_0[4];                  /* '<S19>/EXEC_BLOCK' */
  real_T B_20_17_0;                    /* '<S1>/Constant' */
  real_T B_20_18_0;                    /* '<S8>/hour2 second4' */
  real_T B_20_19_0;                    /* '<S13>/hour2 second' */
  real_T B_20_21_0;                    /* '<S6>/0 to inf1' */
  real_T B_20_22_0;                    /* '<S66>/Memory' */
  real_T B_20_23_0[4];                 /* '<S85>/EXEC_BLOCK' */
  real_T B_20_25_0;                    /* '<S11>/Memory' */
  real_T B_20_26_0;                    /* '<S57>/Add' */
  real_T B_20_27_0[4];                 /* '<S86>/EXEC_BLOCK' */
  real_T B_20_29_0;                    /* '<S32>/Gain' */
  real_T B_20_30_0[4];                 /* '<S58>/EXEC_BLOCK' */
  real_T B_20_32_0;                    /* '<S89>/Gain' */
  real_T B_20_33_0[4];                 /* '<S106>/EXEC_BLOCK' */
  real_T B_20_35_0;                    /* '<S89>/Gain1' */
  real_T B_20_36_0[4];                 /* '<S107>/EXEC_BLOCK' */
  real_T B_20_38_0;                    /* '<S89>/Gain2' */
  real_T B_20_39_0[4];                 /* '<S108>/EXEC_BLOCK' */
  real_T B_20_41_0;                    /* '<S89>/Gain3' */
  real_T B_20_42_0[4];                 /* '<S109>/EXEC_BLOCK' */
  real_T B_20_44_0;                    /* '<S33>/Gain' */
  real_T B_20_45_0[4];                 /* '<S92>/EXEC_BLOCK' */
  real_T B_20_46_0;                    /* '<S5>/Pressure controller time constant//1' */
  real_T B_20_47_0[4];                 /* '<S136>/EXEC_BLOCK' */
  real_T B_20_48_0[81];                /* '<S137>/EXEC_BLOCK' */
  real_T B_20_50_0;                    /* '<S5>/Rw' */
  real_T B_20_52_0;                    /* '<S6>/0 to inf2' */
  real_T B_20_53_0;                    /* '<S6>/Sum' */
  real_T B_20_54_0;                    /* '<S139>/Gain' */
  real_T B_20_56_0;                    /* '<S139>/Gain3' */
  real_T B_20_59_0;                    /* '<S139>/Gain2' */
  real_T B_20_60_0;                    /* '<S139>/Sum' */
  real_T B_20_62_0;                    /* '<S140>/T_pos' */
  real_T B_20_63_0;                    /* '<S2>/convert T to acc. pedal' */
  real_T B_20_64_0;                    /* '<S13>/hour2 second1' */
  real_T B_20_70_0;                    /* '<S13>/check idle spd' */
  real_T B_20_72_0;                    /* '<S8>/hour2 second3' */
  real_T B_20_74_0;                    /* '<S8>/Divide3' */
  real_T B_20_75_0;                    /* '<S8>/hour2 second2' */
  real_T B_20_76_0;                    /* '<S8>/hour2 second1' */
  real_T B_20_77_0;                    /* '<S8>/check pedal' */
  real_T B_20_78_0;                    /* '<S1>/rasps2rpm' */
  real_T B_20_79_0;                    /* '<S8>/Gain2' */
  real_T B_20_81_0;                    /* '<S11>/0 to inf3' */
  real_T B_20_82_0;                    /* '<S11>/Overload Torque (Nm)' */
  real_T B_20_84_0;                    /* '<S11>/0 to inf4' */
  real_T B_20_87_0;                    /* '<S13>/1-D Lookup Table' */
  real_T B_20_90_0;                    /* '<S13>/Sum' */
  real_T B_20_94_0;                    /* '<S29>/SwitchControl' */
  real_T B_20_95_0;                    /* '<S13>/Product3' */
  real_T B_20_97_0;                    /* '<S11>/0 to inf1' */
  real_T B_20_99_0;                    /* '<S11>/0 to inf5' */
  real_T B_20_100_0;                   /* '<S11>/check max speed' */
  real_T B_20_101_0;                   /* '<S8>/1' */
  real_T B_20_103_0;                   /* '<S8>/Gain3' */
  real_T B_20_104_0;                   /* '<S8>/ICE_906_205' */
  real_T B_20_105_0;                   /* '<S14>/sec_eng_sfc_map (906)' */
  real_T B_20_106_0;                   /* '<S14>/Gain2' */
  real_T B_20_112_0;                   /* '<S14>/Product' */
  real_T B_20_113_0;                   /* '<S14>/Product2' */
  real_T B_20_116_0;                   /* '<S14>/Product1' */
  real_T B_20_117_0;                   /* '<S14>/Product3' */
  real_T B_20_118_0;                   /* '<S14>/Sum3' */
  real_T B_20_120_0;                   /* '<S8>/solve devide  by zero problem1' */
  real_T B_20_121_0;                   /* '<S8>/Divide2' */
  real_T B_20_122_0;                   /* '<S8>/Sum' */
  real_T B_20_130_0;                   /* '<S8>/g2lit' */
  real_T B_20_133_0;                   /* '<S8>/solve devide  by zero problem' */
  real_T B_20_135_0;                   /* '<S8>/g 2 liter1' */
  real_T B_20_138_0;                   /* '<S8>/hour2 second' */
  real_T B_20_139_0;                   /* '<S8>/Divide4' */
  real_T B_20_143_0;                   /* '<S11>/slope1' */
  real_T B_20_144_0;                   /* '<S11>/Switch' */
  real_T B_20_151_0;                   /* '<S11>/Switch1' */
  real_T B_20_192_0;                   /* '<S2>/convert T to brake pedal' */
  real_T B_20_198_0;                   /* '<S141>/Integrator3' */
  real_T B_20_199_0;                   /* '<S141>/Integrator4' */
  real_T B_20_200_0;                   /* '<S141>/Integrator5' */
  real_T B_20_202_0;                   /* '<S141>/Integrator' */
  real_T B_20_203_0;                   /* '<S141>/Integrator1' */
  real_T B_20_204_0;                   /* '<S141>/Integrator2' */
  real_T B_20_206_0;                   /* '<S141>/Integrator6' */
  real_T B_20_207_0;                   /* '<S141>/Integrator7' */
  real_T B_20_208_0;                   /* '<S141>/Integrator8' */
  real_T B_20_212_0;                   /* '<S141>/Constant1' */
  real_T B_20_214_0;                   /* '<S141>/Abs' */
  real_T B_20_216_0;                   /* '<S141>/Constant3' */
  real_T B_20_218_0;                   /* '<S141>/Abs1' */
  real_T B_20_219_0;                   /* '<S141>/Abs2' */
  real_T B_20_220_0;                   /* '<S141>/Constant' */
  real_T B_20_221_0;                   /* '<S141>/Constant2' */
  real_T B_20_222_0;                   /* '<S141>/Constant4' */
  real_T B_20_226_0;                   /* '<S141>/Switch' */
  real_T B_20_227_0;                   /* '<S141>/Switch1' */
  real_T B_20_228_0;                   /* '<S141>/Switch3' */
  real_T B_20_229_0;                   /* '<S141>/Switch4' */
  real_T B_20_230_0;                   /* '<S141>/Switch6' */
  real_T B_20_231_0;                   /* '<S141>/Switch7' */
  real_T B_20_242_0;                   /* '<S4>/Gain' */
  real_T B_20_250_0;                   /* '<S101>/selector1' */
  real_T B_20_252_0;                   /* '<S101>/selector2' */
  real_T B_20_254_0;                   /* '<S101>/selector3' */
  real_T B_20_256_0;                   /* '<S101>/selector4' */
  real_T B_20_328_0;                   /* '<S72>/EXEC_BLOCK' */
  real_T B_20_331_0;                   /* '<S81>/EXEC_BLOCK' */
  real_T B_20_338_0;                   /* '<S66>/Gain1' */
  real_T B_20_340_0;                   /* '<S66>/T_t' */
  real_T B_20_493_0;                   /* '<S5>/Sum3' */
  real_T B_20_505_0;                   /* '<S5>/Tire 1//m1' */
  real_T B_20_509_0;                   /* '<S5>/etta' */
  real_T B_20_510_0;                   /* '<S5>/etta1' */
  real_T B_20_513_0;                   /* '<S5>/Sum1' */
  real_T B_19_0_1;                     /* '<S6>/Chart' */
  real_T B_12_0_1;                     /* '<S34>/Chart1' */
  real_T B_12_0_2;                     /* '<S34>/Chart1' */
  real_T B_20_20_0;                    /* '<Root>/drive cycle' */
  real_T B_20_449_0;                   /* '<S43>/EXEC_BLOCK' */
  real_T B_20_491_0;                   /* '<S5>/Memory1' */
  real_T B_20_507_0;                   /* '<S135>/EXEC_BLOCK' */
  real_T B_20_66_0;                    /* '<S25>/EXEC_BLOCK' */
  real_T B_20_175_0;                   /* '<S28>/EXEC_BLOCK' */
  real_T B_20_399_0;                   /* '<S84>/EXEC_BLOCK' */
  real_T B_20_434_0;                   /* '<S40>/EXEC_BLOCK' */
  uint8_T B_20_91_0;                   /* '<S29>/Constant' */
  uint8_T B_20_92_0;                   /* '<S29>/S-Function' */
  char pad_B_20_92_0[6];
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem4;/* '<S101>/B_17_93' */
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem3;/* '<S101>/B_17_92' */
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem2;/* '<S101>/B_17_91' */
  rtB_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem1;/* '<S101>/B_17_90' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T EXEC_BLOCK_DSTATE;            /* '<S19>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_j;          /* '<S85>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_a;          /* '<S86>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_m;          /* '<S58>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_o;          /* '<S106>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_aa;         /* '<S107>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_n;          /* '<S108>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_ob;         /* '<S109>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_h;          /* '<S92>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_hc;         /* '<S136>/EXEC_BLOCK' */
  real_T EXEC_BLOCK_DSTATE_a4[165];    /* '<S137>/EXEC_BLOCK' */
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T Memory_PreviousInput_i;       /* '<S66>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S66>/Memory1' */
  real_T Memory_PreviousInput_b;       /* '<S11>/Memory' */
  real_T Memory1_PreviousInput_p;      /* '<S5>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S139>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_c;                /* '<S6>/Derivative' */

  void *EXEC_BLOCK_PWORK[5];           /* '<S19>/EXEC_BLOCK' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } drivecycle_PWORK;                  /* '<Root>/drive cycle' */

  void *EXEC_BLOCK_PWORK_a[5];         /* '<S85>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_l[5];         /* '<S86>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_n[5];         /* '<S58>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_o[5];         /* '<S106>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_i[5];         /* '<S107>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_h[5];         /* '<S108>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_iw[5];        /* '<S109>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_ld[5];        /* '<S92>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_k[5];         /* '<S136>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_o5[5];        /* '<S137>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_n3[5];        /* '<S132>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_ir[5];        /* '<S25>/EXEC_BLOCK' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S8>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S8>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S8>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S8>/Scope4' */

  void *ToWorkspace_PWORK;             /* '<S8>/To Workspace' */
  void *ToWorkspace1_PWORK;            /* '<S8>/To Workspace1' */
  struct {
    void *LoggedData;
  } cons1_PWORK;                       /* '<S8>/cons1' */

  struct {
    void *LoggedData;
  } cons2_PWORK;                       /* '<S8>/cons2' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S14>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_l;                    /* '<S14>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_h;                    /* '<S14>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_j;                    /* '<S11>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_m;                    /* '<S11>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_c;                    /* '<S11>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S12>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S13>/Scope' */

  void *EXEC_BLOCK_PWORK_lb[5];        /* '<S28>/EXEC_BLOCK' */
  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } T_PWORK;                           /* '<S6>/T' */

  struct {
    void *LoggedData;
  } driver_PWORK;                      /* '<S6>/driver' */

  struct {
    void *LoggedData;
  } errora0_PWORK;                     /* '<S141>/error a<0' */

  struct {
    void *LoggedData;
  } errora0_PWORK_e;                   /* '<S141>/error a>=0' */

  struct {
    void *LoggedData;
  } error1_PWORK;                      /* '<S141>/error1' */

  struct {
    void *LoggedData;
  } totalerror_PWORK;                  /* '<S141>/total error' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h3;                    /* '<S139>/Scope' */

  struct {
    void *LoggedData;
  } T_PWORK_h;                         /* '<S4>/T' */

  struct {
    void *LoggedData;
  } T_PWORK_a;                         /* '<S33>/T' */

  void *EXEC_BLOCK_PWORK_ae[5];        /* '<S72>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_a1[5];        /* '<S81>/EXEC_BLOCK' */
  struct {
    void *LoggedData;
  } T1_PWORK;                          /* '<S66>/T1' */

  void *EXEC_BLOCK_PWORK_oj[5];        /* '<S84>/EXEC_BLOCK' */
  struct {
    void *LoggedData;
  } controlindictor_PWORK;             /* '<S34>/control indictor' */

  struct {
    void *LoggedData;
  } controlindictor1_PWORK;            /* '<S34>/control indictor1' */

  struct {
    void *LoggedData;
  } enginespeed_PWORK;                 /* '<S34>/engine speed' */

  void *EXEC_BLOCK_PWORK_ll[5];        /* '<S40>/EXEC_BLOCK' */
  void *EXEC_BLOCK_PWORK_nd[5];        /* '<S43>/EXEC_BLOCK' */
  struct {
    void *LoggedData;
  } T_PWORK_l;                         /* '<S5>/T' */

  struct {
    void *LoggedData;
  } T1_PWORK_i;                        /* '<S5>/T1' */

  void *EXEC_BLOCK_PWORK_d[5];         /* '<S135>/EXEC_BLOCK' */
  struct {
    void *LoggedData;
  } T2_PWORK;                          /* '<S5>/T2' */

  void *ToWorkspace_PWORK_g;           /* '<S5>/To Workspace' */
  struct {
    void *LoggedData;
  } Scope2_PWORK_mt;                   /* '<S7>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_mt;                    /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;                    /* '<S7>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_k;                    /* '<S7>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_d;                    /* '<S7>/Scope4' */

  struct {
    int_T PrevIndex;
  } drivecycle_IWORK;                  /* '<Root>/drive cycle' */

  int_T EXEC_BLOCK_MODE[18];           /* '<S137>/EXEC_BLOCK' */
  char pad_EXEC_BLOCK_MODE[4];
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem4;/* '<S101>/B_17_93' */
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem3;/* '<S101>/B_17_92' */
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem2;/* '<S101>/B_17_91' */
  rtDW_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem1;/* '<S101>/B_17_90' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T ClutchActuator_CSTATE;        /* '<S32>/Clutch  Actuator' */
  real_T ClutchActuator_CSTATE_n;      /* '<S89>/Clutch  Actuator' */
  real_T ClutchActuator1_CSTATE;       /* '<S89>/Clutch  Actuator1' */
  real_T ClutchActuator2_CSTATE;       /* '<S89>/Clutch  Actuator2' */
  real_T ClutchActuator3_CSTATE;       /* '<S89>/Clutch  Actuator3' */
  real_T ClutchActuator_CSTATE_e;      /* '<S33>/Clutch  Actuator' */
  real_T Pressurecontrollertimeconstant1_CSTATE;/* '<S5>/Pressure controller time constant//1' */
  real_T Integrator_CSTATE;            /* '<S139>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S5>/Integrator3' */
  real_T Integrator3_CSTATE_b;         /* '<S141>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S141>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S141>/Integrator5' */
  real_T Integrator_CSTATE_p;          /* '<S141>/Integrator' */
  real_T Integrator1_CSTATE_e;         /* '<S141>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S141>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S141>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S141>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S141>/Integrator8' */
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem4;/* '<S101>/B_17_90' */
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem3;/* '<S101>/B_17_90' */
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem2;/* '<S101>/B_17_90' */
  rtX_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem1;/* '<S101>/B_17_90' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T ClutchActuator_CSTATE;        /* '<S32>/Clutch  Actuator' */
  real_T ClutchActuator_CSTATE_n;      /* '<S89>/Clutch  Actuator' */
  real_T ClutchActuator1_CSTATE;       /* '<S89>/Clutch  Actuator1' */
  real_T ClutchActuator2_CSTATE;       /* '<S89>/Clutch  Actuator2' */
  real_T ClutchActuator3_CSTATE;       /* '<S89>/Clutch  Actuator3' */
  real_T ClutchActuator_CSTATE_e;      /* '<S33>/Clutch  Actuator' */
  real_T Pressurecontrollertimeconstant1_CSTATE;/* '<S5>/Pressure controller time constant//1' */
  real_T Integrator_CSTATE;            /* '<S139>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S5>/Integrator3' */
  real_T Integrator3_CSTATE_b;         /* '<S141>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S141>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S141>/Integrator5' */
  real_T Integrator_CSTATE_p;          /* '<S141>/Integrator' */
  real_T Integrator1_CSTATE_e;         /* '<S141>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S141>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S141>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S141>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S141>/Integrator8' */
  rtXdot_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem4;/* '<S101>/B_17_90' */
  rtXdot_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem3;/* '<S101>/B_17_90' */
  rtXdot_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem2;/* '<S101>/B_17_90' */
  rtXdot_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem1;/* '<S101>/B_17_90' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T ClutchActuator_CSTATE;     /* '<S32>/Clutch  Actuator' */
  boolean_T ClutchActuator_CSTATE_n;   /* '<S89>/Clutch  Actuator' */
  boolean_T ClutchActuator1_CSTATE;    /* '<S89>/Clutch  Actuator1' */
  boolean_T ClutchActuator2_CSTATE;    /* '<S89>/Clutch  Actuator2' */
  boolean_T ClutchActuator3_CSTATE;    /* '<S89>/Clutch  Actuator3' */
  boolean_T ClutchActuator_CSTATE_e;   /* '<S33>/Clutch  Actuator' */
  boolean_T Pressurecontrollertimeconstant1_CSTATE;/* '<S5>/Pressure controller time constant//1' */
  boolean_T Integrator_CSTATE;         /* '<S139>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S8>/Integrator1' */
  boolean_T Integrator3_CSTATE;        /* '<S5>/Integrator3' */
  boolean_T Integrator3_CSTATE_b;      /* '<S141>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S141>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S141>/Integrator5' */
  boolean_T Integrator_CSTATE_p;       /* '<S141>/Integrator' */
  boolean_T Integrator1_CSTATE_e;      /* '<S141>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S141>/Integrator2' */
  boolean_T Integrator6_CSTATE;        /* '<S141>/Integrator6' */
  boolean_T Integrator7_CSTATE;        /* '<S141>/Integrator7' */
  boolean_T Integrator8_CSTATE;        /* '<S141>/Integrator8' */
  rtXdis_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem4;/* '<S101>/B_17_90' */
  rtXdis_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem3;/* '<S101>/B_17_90' */
  rtXdis_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem2;/* '<S101>/B_17_90' */
  rtXdis_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem1;/* '<S101>/B_17_90' */
} StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S139>/Integrator' */
} PrevZCSigStates;

/* Parameters for system: '<S101>/B_17_90' */
struct rtP_EnabledSubsystem1_conv_906_eng_hydr_new_ {
  real_T P_0;                          /* Expression: [0]
                                        * Referenced by: '<S110>/clutch release'
                                        */
  real_T P_1;                          /* Computed Parameter: P_1
                                        * Referenced by: '<S110>/Clutch A Actuator'
                                        */
  real_T P_2;                          /* Computed Parameter: P_2
                                        * Referenced by: '<S110>/Clutch A Actuator'
                                        */
  real_T P_3;                          /* Computed Parameter: P_3
                                        * Referenced by: '<S110>/Clutch A Actuator'
                                        */
  real_T P_6;                          /* Expression: 1
                                        * Referenced by: '<S110>/engage'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_ {
  real_T P_0;                          /* Expression: 0
                                        * Referenced by: '<S11>/slope'
                                        */
  real_T P_1;                          /* Expression: pi/30
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T P_2;                          /* Expression: inf
                                        * Referenced by: '<S11>/0 to inf2'
                                        */
  real_T P_3;                          /* Expression: eps
                                        * Referenced by: '<S11>/0 to inf2'
                                        */
  real_T P_4;                          /* Expression: 7.5
                                        * Referenced by: '<Root>/Aux. Load Power (kW)'
                                        */
  real_T P_5;                          /* Expression: 1000
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T P_6;                          /* Expression: 1
                                        * Referenced by: '<S13>/hour2 second2'
                                        */
  real_T P_7;                          /* Expression: 0
                                        * Referenced by: '<S13>/hour2 second3'
                                        */
  real_T P_8;                          /* Expression: 1
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T P_9;                          /* Expression: TC_spd_ratio_max
                                        * Referenced by: '<S66>/Constant6'
                                        */
  real_T P_10;                         /* Expression: 0.1
                                        * Referenced by: '<S66>/check turb spd=0'
                                        */
  real_T P_11;                         /* Expression: eps
                                        * Referenced by: '<S66>/Constant2'
                                        */
  real_T P_12[2];                      /* Computed Parameter: P_12
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_13;                         /* Expression: Twait
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_14[2];                      /* Computed Parameter: P_14
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_15;                         /* Expression: down_spd_2
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_16[2];                      /* Computed Parameter: P_16
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_17;                         /* Expression: down_spd_3
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_18[2];                      /* Computed Parameter: P_18
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_19;                         /* Expression: down_spd_4
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_20[2];                      /* Computed Parameter: P_20
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_21;                         /* Expression: down_spd_c
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_22[2];                      /* Computed Parameter: P_22
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_23;                         /* Expression: up_spd_1
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_24[2];                      /* Computed Parameter: P_24
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_25;                         /* Expression: up_spd_2
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_26[2];                      /* Computed Parameter: P_26
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_27;                         /* Expression: up_spd_3
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_28[2];                      /* Computed Parameter: P_28
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_29;                         /* Expression: up_spd_c
                                        * Referenced by: '<S34>/Chart1'
                                        */
  real_T P_30;                         /* Expression: 0
                                        * Referenced by: '<S124>/Constant1'
                                        */
  real_T P_31;                         /* Expression: 0.5*Cd*den*Af
                                        * Referenced by: '<S124>/0.5*Cd*den*Ar'
                                        */
  real_T P_32;                         /* Expression: 0
                                        * Referenced by: '<S125>/Constant1'
                                        */
  real_T P_33;                         /* Expression: 0
                                        * Referenced by: '<Root>/slope'
                                        */
  real_T P_34;                         /* Expression: pi/180
                                        * Referenced by: '<S125>/degree 2 rad'
                                        */
  real_T P_35;                         /* Expression: M1_906*9.81
                                        * Referenced by: '<S125>/Mg'
                                        */
  real_T P_36;                         /* Expression: 0
                                        * Referenced by: '<S126>/Constant1'
                                        */
  real_T P_37;                         /* Expression: M1_906*9.81
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T P_38;                         /* Expression: fr
                                        * Referenced by: '<S126>/fr'
                                        */
  real_T P_39;                         /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T P_40;                         /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T P_41;                         /* Expression: 2
                                        * Referenced by: '<S8>/hour2 second4'
                                        */
  real_T P_42;                         /* Expression: 0
                                        * Referenced by: '<S13>/hour2 second'
                                        */
  real_T P_43;                         /* Expression: inf
                                        * Referenced by: '<S6>/0 to inf1'
                                        */
  real_T P_44;                         /* Expression: 0
                                        * Referenced by: '<S6>/0 to inf1'
                                        */
  real_T P_45;                         /* Expression: 0
                                        * Referenced by: '<S66>/Memory'
                                        */
  real_T P_46;                         /* Expression: 0
                                        * Referenced by: '<S66>/Memory1'
                                        */
  real_T P_47;                         /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  real_T P_48;                         /* Computed Parameter: P_48
                                        * Referenced by: '<S32>/Clutch  Actuator'
                                        */
  real_T P_49;                         /* Computed Parameter: P_49
                                        * Referenced by: '<S32>/Clutch  Actuator'
                                        */
  real_T P_50;                         /* Computed Parameter: P_50
                                        * Referenced by: '<S32>/Clutch  Actuator'
                                        */
  real_T P_53;                         /* Expression: 10e6
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T P_54;                         /* Computed Parameter: P_54
                                        * Referenced by: '<S89>/Clutch  Actuator'
                                        */
  real_T P_55;                         /* Computed Parameter: P_55
                                        * Referenced by: '<S89>/Clutch  Actuator'
                                        */
  real_T P_56;                         /* Computed Parameter: P_56
                                        * Referenced by: '<S89>/Clutch  Actuator'
                                        */
  real_T P_59;                         /* Expression: 10e6
                                        * Referenced by: '<S89>/Gain'
                                        */
  real_T P_60;                         /* Computed Parameter: P_60
                                        * Referenced by: '<S89>/Clutch  Actuator1'
                                        */
  real_T P_61;                         /* Computed Parameter: P_61
                                        * Referenced by: '<S89>/Clutch  Actuator1'
                                        */
  real_T P_62;                         /* Computed Parameter: P_62
                                        * Referenced by: '<S89>/Clutch  Actuator1'
                                        */
  real_T P_65;                         /* Expression: 10e6
                                        * Referenced by: '<S89>/Gain1'
                                        */
  real_T P_66;                         /* Computed Parameter: P_66
                                        * Referenced by: '<S89>/Clutch  Actuator2'
                                        */
  real_T P_67;                         /* Computed Parameter: P_67
                                        * Referenced by: '<S89>/Clutch  Actuator2'
                                        */
  real_T P_68;                         /* Computed Parameter: P_68
                                        * Referenced by: '<S89>/Clutch  Actuator2'
                                        */
  real_T P_71;                         /* Expression: 10e6
                                        * Referenced by: '<S89>/Gain2'
                                        */
  real_T P_72;                         /* Computed Parameter: P_72
                                        * Referenced by: '<S89>/Clutch  Actuator3'
                                        */
  real_T P_73;                         /* Computed Parameter: P_73
                                        * Referenced by: '<S89>/Clutch  Actuator3'
                                        */
  real_T P_74;                         /* Computed Parameter: P_74
                                        * Referenced by: '<S89>/Clutch  Actuator3'
                                        */
  real_T P_77;                         /* Expression: 10e6
                                        * Referenced by: '<S89>/Gain3'
                                        */
  real_T P_78;                         /* Computed Parameter: P_78
                                        * Referenced by: '<S33>/Clutch  Actuator'
                                        */
  real_T P_79;                         /* Computed Parameter: P_79
                                        * Referenced by: '<S33>/Clutch  Actuator'
                                        */
  real_T P_80;                         /* Computed Parameter: P_80
                                        * Referenced by: '<S33>/Clutch  Actuator'
                                        */
  real_T P_83;                         /* Expression: 10e6
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T P_84;                         /* Computed Parameter: P_84
                                        * Referenced by: '<S5>/Pressure controller time constant//1'
                                        */
  real_T P_85;                         /* Computed Parameter: P_85
                                        * Referenced by: '<S5>/Pressure controller time constant//1'
                                        */
  real_T P_86;                         /* Computed Parameter: P_86
                                        * Referenced by: '<S5>/Pressure controller time constant//1'
                                        */
  real_T P_89;                         /* Expression: Rw
                                        * Referenced by: '<S5>/Rw'
                                        */
  real_T P_90;                         /* Expression: 3.6
                                        * Referenced by: '<S5>/m//s 2 km//h'
                                        */
  real_T P_91;                         /* Expression: inf
                                        * Referenced by: '<S6>/0 to inf2'
                                        */
  real_T P_92;                         /* Expression: 0
                                        * Referenced by: '<S6>/0 to inf2'
                                        */
  real_T P_93;                         /* Expression: 100
                                        * Referenced by: '<S139>/Gain'
                                        */
  real_T P_94;                         /* Expression: 0
                                        * Referenced by: '<S139>/Gain3'
                                        */
  real_T P_95;                         /* Expression: 2
                                        * Referenced by: '<S139>/Gain1'
                                        */
  real_T P_96;                         /* Expression: 0
                                        * Referenced by: '<S139>/Integrator'
                                        */
  real_T P_97;                         /* Expression: 0.5
                                        * Referenced by: '<S139>/Gain2'
                                        */
  real_T P_98;                         /* Expression: 100/T_max_906
                                        * Referenced by: '<S140>/convert T to acc. pedal'
                                        */
  real_T P_99;                         /* Expression: 100
                                        * Referenced by: '<S140>/T_pos'
                                        */
  real_T P_100;                        /* Expression: 0
                                        * Referenced by: '<S140>/T_pos'
                                        */
  real_T P_101;                        /* Expression: T_max_906/100
                                        * Referenced by: '<S2>/convert T to acc. pedal'
                                        */
  real_T P_102;                        /* Expression: 1
                                        * Referenced by: '<S13>/hour2 second1'
                                        */
  real_T P_103;                        /* Expression: 0
                                        * Referenced by: '<S13>/check idle P'
                                        */
  real_T P_104;                        /* Expression: 30/pi
                                        * Referenced by: '<S1>/rasps2rpm2'
                                        */
  real_T P_105;                        /* Expression: Idle_spd_eng_906
                                        * Referenced by: '<S13>/check idle spd'
                                        */
  real_T P_106;                        /* Expression: 0
                                        * Referenced by: '<S8>/hour2 second3'
                                        */
  real_T P_107;                        /* Expression: 0
                                        * Referenced by: '<S8>/idel cons'
                                        */
  real_T P_108;                        /* Expression: 0
                                        * Referenced by: '<S8>/hour2 second2'
                                        */
  real_T P_109;                        /* Expression: 1
                                        * Referenced by: '<S8>/hour2 second1'
                                        */
  real_T P_110;                        /* Expression: 0
                                        * Referenced by: '<S8>/check pedal'
                                        */
  real_T P_111;                        /* Expression: 30/pi
                                        * Referenced by: '<S1>/rasps2rpm'
                                        */
  real_T P_112;                        /* Expression: 2*pi/60
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T P_113;                        /* Expression: 30/pi
                                        * Referenced by: '<S1>/rasps2rpm1'
                                        */
  real_T P_114;                        /* Expression: inf
                                        * Referenced by: '<S11>/0 to inf3'
                                        */
  real_T P_115;                        /* Expression: 0
                                        * Referenced by: '<S11>/0 to inf3'
                                        */
  real_T P_116[3];                     /* Expression: [2600 2900 3000]
                                        * Referenced by: '<S11>/Overload Torque (Nm)'
                                        */
  real_T P_117[3];                     /* Expression: [650 0 0]
                                        * Referenced by: '<S11>/Overload Torque (Nm)'
                                        */
  real_T P_118[18];                    /* Expression: [1000,1070,1130,1200,1280,1500,1590,1680,1760,1850,1930,2010,2070,2150,2240,2320,2380,2500]
                                        * Referenced by: '<S11>/PeakTorque -906 - 205(Nm)'
                                        */
  real_T P_119[18];                    /* Expression: [982,1040,1080,1100,1110,1110,1100,1080,1060,1020,994,963,940,909,872,838,804,751]
                                        * Referenced by: '<S11>/PeakTorque -906 - 205(Nm)'
                                        */
  real_T P_120;                        /* Expression: inf
                                        * Referenced by: '<S11>/0 to inf4'
                                        */
  real_T P_121;                        /* Expression: 0
                                        * Referenced by: '<S11>/0 to inf4'
                                        */
  real_T P_122;                        /* Expression: Idle_spd_eng_906
                                        * Referenced by: '<S13>/hour2 second4'
                                        */
  real_T P_123[3];                     /* Expression: [0 0 T_max_906/2]
                                        * Referenced by: '<S13>/1-D Lookup Table'
                                        */
  real_T P_124[3];                     /* Expression: [0 Idle_spd_eng_906*0.025 Idle_spd_eng_906]
                                        * Referenced by: '<S13>/1-D Lookup Table'
                                        */
  real_T P_125;                        /* Expression: T_max_906/5
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T P_126;                        /* Expression: 0
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T P_127;                        /* Expression: 1
                                        * Referenced by: '<S13>/hour2 second5'
                                        */
  real_T P_128;                        /* Expression: inf
                                        * Referenced by: '<S11>/0 to inf1'
                                        */
  real_T P_129;                        /* Expression: 0
                                        * Referenced by: '<S11>/0 to inf1'
                                        */
  real_T P_130;                        /* Expression: inf
                                        * Referenced by: '<S11>/0 to inf5'
                                        */
  real_T P_131;                        /* Expression: 0
                                        * Referenced by: '<S11>/0 to inf5'
                                        */
  real_T P_132;                        /* Expression: 2600
                                        * Referenced by: '<S11>/check max speed'
                                        */
  real_T P_133;                        /* Expression: inf
                                        * Referenced by: '<S8>/1'
                                        */
  real_T P_134;                        /* Expression: 0
                                        * Referenced by: '<S8>/1'
                                        */
  real_T P_135;                        /* Expression: .001
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T P_136[39];                    /* Expression: p_906_205
                                        * Referenced by: '<S8>/ICE_906_205'
                                        */
  real_T P_137[17];                    /* Expression: w_906_205
                                        * Referenced by: '<S8>/ICE_906_205'
                                        */
  real_T P_138[663];                   /* Expression: BSFC_906_205
                                        * Referenced by: '<S8>/ICE_906_205'
                                        */
  real_T P_139[28];                    /* Expression: sec_eng_sfc_map(:,1)
                                        * Referenced by: '<S14>/sec_eng_sfc_map (906)'
                                        */
  real_T P_140[28];                    /* Expression: sec_eng_sfc_map(:,2)
                                        * Referenced by: '<S14>/sec_eng_sfc_map (906)'
                                        */
  real_T P_141;                        /* Expression: 1
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T P_142;                        /* Expression: 1000
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T P_143;                        /* Expression: -1
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T P_144;                        /* Expression: Idle_spd_eng_906
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T P_145;                        /* Expression: 1
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T P_146;                        /* Expression: 1000
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T P_147;                        /* Expression: inf
                                        * Referenced by: '<S8>/solve devide  by zero problem1'
                                        */
  real_T P_148;                        /* Expression: 0
                                        * Referenced by: '<S8>/solve devide  by zero problem1'
                                        */
  real_T P_149;                        /* Expression: 0
                                        * Referenced by: '<S8>/Integrator1'
                                        */
  real_T P_150;                        /* Expression: 1/fuel_density*1000
                                        * Referenced by: '<S8>/g2lit'
                                        */
  real_T P_151;                        /* Expression: 0
                                        * Referenced by: '<S5>/Integrator3'
                                        */
  real_T P_152;                        /* Expression: .001
                                        * Referenced by: '<S5>/m 2 km'
                                        */
  real_T P_153;                        /* Expression: inf
                                        * Referenced by: '<S8>/solve devide  by zero problem'
                                        */
  real_T P_154;                        /* Expression: eps
                                        * Referenced by: '<S8>/solve devide  by zero problem'
                                        */
  real_T P_155;                        /* Expression: 100
                                        * Referenced by: '<S8>/g 2 liter1'
                                        */
  real_T P_156;                        /* Expression: 3600
                                        * Referenced by: '<S8>/hour2 second'
                                        */
  real_T P_157;                        /* Expression: 0
                                        * Referenced by: '<S11>/slope1'
                                        */
  real_T P_158;                        /* Expression: 0.1
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T P_159;                        /* Expression: Idle_spd_eng_906*0.75
                                        * Referenced by: '<S11>/Switch1'
                                        */
  real_T P_160;                        /* Expression: inf
                                        * Referenced by: '<S12>/0 to inf2'
                                        */
  real_T P_161;                        /* Expression: eps
                                        * Referenced by: '<S12>/0 to inf2'
                                        */
  real_T P_162;                        /* Expression: (pi)/30
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T P_163[63];                    /* Expression: [-10,eps,802.567507746791,824.568393094289,846.879150066401,868.8800354139,890.880920761399,912.881806108898,935.192563081009,957.193448428508,979.194333776007,1001.19521912351,1023.196104471,1045.1969898185,1067.197875166,1089.50863213811,1111.50951748561,1133.51040283311,1155.51128818061,1177.51217352811,1199.51305887561,1221.51394422311,1243.51482957061,1265.51571491811,1287.5166002656,1309.5174856131,1331.5183709606,1353.5192563081,1375.21027003099,1397.21115537849,1418.90216910137,1440.90305444887,1462.90393979637,1484.59495351926,1506.59583886676,1528.59672421425,1550.59760956175,1572.28862328464,1593.66976538291,1615.3607791058,1637.3616644533,1659.05267817618,1680.74369189907,1702.43470562196,1724.12571934484,1745.81673306773,1767.50774679062,1789.1987605135,1810.57990261178,1831.96104471005,1853.65205843294,1875.34307215582,1897.03408587871,1918.10535635237,1939.17662682603,1960.86764054892,1982.24878264719,2003.62992474546,2025.63081009296,2047.32182381585,2068.70296591412,2090.08410801239,3000]
                                        * Referenced by: '<S12>/engine_drag_power (kw)'
                                        */
  real_T P_164[63];                    /* Expression: [0,0,8.89504100832017,9.50127747975726,9.88870415102495,10.2762179627945,10.7512208384311,11.1824791821341,11.6136503853353,12.0449087290384,12.4761670727414,12.9074254164445,13.294939228214,13.7261975719171,14.1137113836866,14.5448825868878,15.0636299944579,15.5386328700944,15.9698912137975,16.357405025567,16.7449188373366,17.1761771810396,17.6074355247427,17.9949493365122,18.4699522121488,18.9886996197188,19.4637024953554,20.026194434859,20.5887735148644,21.1950099863015,21.757589066307,22.2325919419435,22.7075948175801,23.2701738975855,23.8764103690226,24.4826468404597,25.0451387799633,25.7389514557692,26.5203403359441,27.21415301175,27.8641340151206,28.5579466909266,29.3392484305996,30.076805638339,30.858107378012,31.639409117685,32.420710857358,33.202012597031,34.1146350730063,35.0710020809152,35.9397928844552,36.7210946241282,37.5461408957346,38.4151059802784,39.3278155967556,40.1966064002956,41.0654843443374,41.8906177564458,42.6280878236834,43.4093895633564,44.2345229754647,45.1034009195066,45.1034009195066]
                                        * Referenced by: '<S12>/engine_drag_power (kw)'
                                        */
  real_T P_165;                        /* Expression: 1000
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T P_166;                        /* Expression: -1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T P_167;                        /* Expression: 1
                                        * Referenced by: '<S12>/no engine drag ( if we want )'
                                        */
  real_T P_168;                        /* Expression: 100/T_min
                                        * Referenced by: '<S140>/convert T to brake pedal'
                                        */
  real_T P_169;                        /* Expression: 0
                                        * Referenced by: '<S140>/T_neg'
                                        */
  real_T P_170;                        /* Expression: -100
                                        * Referenced by: '<S140>/T_neg'
                                        */
  real_T P_171;                        /* Expression: -1
                                        * Referenced by: '<S140>/covert T to brake pedal1'
                                        */
  real_T P_172;                        /* Expression: -T_min/100
                                        * Referenced by: '<S2>/convert T to brake pedal'
                                        */
  real_T P_173;                        /* Expression: 13
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T P_174;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator3'
                                        */
  real_T P_175;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator4'
                                        */
  real_T P_176;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator5'
                                        */
  real_T P_177;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator'
                                        */
  real_T P_178;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator1'
                                        */
  real_T P_179;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator2'
                                        */
  real_T P_180;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator6'
                                        */
  real_T P_181;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator7'
                                        */
  real_T P_182;                        /* Expression: 0
                                        * Referenced by: '<S141>/Integrator8'
                                        */
  real_T P_183;                        /* Expression: 0
                                        * Referenced by: '<S141>/Constant1'
                                        */
  real_T P_184;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch2'
                                        */
  real_T P_185;                        /* Expression: -1
                                        * Referenced by: '<S141>/Gain2'
                                        */
  real_T P_186;                        /* Expression: 0
                                        * Referenced by: '<S141>/Constant3'
                                        */
  real_T P_187;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch5'
                                        */
  real_T P_188;                        /* Expression: 0
                                        * Referenced by: '<S141>/Constant'
                                        */
  real_T P_189;                        /* Expression: 0
                                        * Referenced by: '<S141>/Constant2'
                                        */
  real_T P_190;                        /* Expression: 0
                                        * Referenced by: '<S141>/Constant4'
                                        */
  real_T P_191;                        /* Expression: -1
                                        * Referenced by: '<S141>/Gain'
                                        */
  real_T P_192;                        /* Expression: -1
                                        * Referenced by: '<S141>/Gain1'
                                        */
  real_T P_193;                        /* Expression: -1
                                        * Referenced by: '<S141>/Gain3'
                                        */
  real_T P_194;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch'
                                        */
  real_T P_195;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch1'
                                        */
  real_T P_196;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch3'
                                        */
  real_T P_197;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch4'
                                        */
  real_T P_198;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch6'
                                        */
  real_T P_199;                        /* Expression: 0
                                        * Referenced by: '<S141>/Switch7'
                                        */
  real_T P_200;                        /* Expression: 1
                                        * Referenced by: '<S101>/1'
                                        */
  real_T P_201;                        /* Expression: 2
                                        * Referenced by: '<S101>/2'
                                        */
  real_T P_202;                        /* Expression: 3
                                        * Referenced by: '<S101>/3'
                                        */
  real_T P_203;                        /* Expression: 4
                                        * Referenced by: '<S101>/4'
                                        */
  real_T P_204;                        /* Expression: 30/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T P_205;                        /* Expression: -1
                                        * Referenced by: '<S101>/disengahe'
                                        */
  real_T P_206;                        /* Expression: 1
                                        * Referenced by: '<S101>/engage'
                                        */
  real_T P_207;                        /* Expression: 1000
                                        * Referenced by: '<S66>/Ref_spd (rpm)'
                                        */
  real_T P_208;                        /* Expression: 60/(2*pi)
                                        * Referenced by: '<S66>/rad//s 2 rpm'
                                        */
  real_T P_209;                        /* Expression: 0.1
                                        * Referenced by: '<S66>/check pump spd=0'
                                        */
  real_T P_210[173];                   /* Expression: torque_convertor(:,1)
                                        * Referenced by: '<S66>/pump T'
                                        */
  real_T P_211[173];                   /* Expression: torque_convertor(:,3)
                                        * Referenced by: '<S66>/pump T'
                                        */
  real_T P_212;                        /* Expression: -1
                                        * Referenced by: '<S66>/Gain1'
                                        */
  real_T P_213[173];                   /* Expression: torque_convertor(:,1)
                                        * Referenced by: '<S66>/Mu'
                                        */
  real_T P_214[173];                   /* Expression: torque_convertor(:,2)
                                        * Referenced by: '<S66>/Mu'
                                        */
  real_T P_215;                        /* Expression: 0
                                        * Referenced by: '<S5>/Memory1'
                                        */
  real_T P_216;                        /* Expression: 0
                                        * Referenced by: '<S5>/Memory2'
                                        */
  real_T P_217;                        /* Expression: 0
                                        * Referenced by: '<S124>/check  v=0'
                                        */
  real_T P_218;                        /* Expression: 0
                                        * Referenced by: '<S126>/check  v=0'
                                        */
  real_T P_219;                        /* Expression: 0
                                        * Referenced by: '<S125>/check  v=0'
                                        */
  real_T P_220;                        /* Expression: Rw
                                        * Referenced by: '<S5>/Tire 1//m1'
                                        */
  real_T P_221;                        /* Expression: inf
                                        * Referenced by: '<S5>/0-inf'
                                        */
  real_T P_222;                        /* Expression: eps
                                        * Referenced by: '<S5>/0-inf'
                                        */
  real_T P_223;                        /* Expression: (1-.9)
                                        * Referenced by: '<S5>/etta'
                                        */
  real_T P_224;                        /* Expression: 1
                                        * Referenced by: '<S5>/etta1'
                                        */
  uint8_T P_225;                       /* Expression: uint8(1)
                                        * Referenced by: '<S29>/Constant'
                                        */
  uint8_T P_226;                       /* Expression: uint8(1)
                                        * Referenced by: '<S29>/SwitchControl'
                                        */
  char pad_P_226[6];
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem4;/* '<S101>/B_17_93' */
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem3;/* '<S101>/B_17_92' */
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem2;/* '<S101>/B_17_91' */
  rtP_EnabledSubsystem1_conv_906_eng_hydr_new EnabledSubsystem1;/* '<S101>/B_17_90' */
};

extern Parameters rtDefaultParameters; /* parameters */

#endif                                 /* RTW_HEADER_conv_906_eng_hydr_new_acc_h_ */
