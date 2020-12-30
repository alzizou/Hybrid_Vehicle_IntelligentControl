#ifndef __c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor_h__
#define __c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c5_setSimStateSideEffectsInfo;
  real_T c5_Twait_aux;
  real_T c5_Twait_aux2;
  real_T c5_aux1;
  real_T c5_aux2;
  int32_T c5_sfEvent;
  uint32_T c5_elapsedTicks;
  uint32_T c5_presentTicks;
  uint32_T c5_previousTicks;
  uint32_T c5_temporalCounter_i1;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_isStable;
  uint8_T c5_doSetSimStateSideEffects;
  uint8_T c5_is_active_c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  uint8_T c5_is_c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  uint8_T c5_tp_state1;
  uint8_T c5_tp_state2;
  uint8_T c5_tp_state3;
  uint8_T c5_tp_state4;
  ChartInfoStruct chartInfo;
} SFc5_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor_get_check_sum(mxArray
  *plhs[]);
extern void c5_hyd_hyb_2_int_cont_1_new3_5cyc_axor_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
