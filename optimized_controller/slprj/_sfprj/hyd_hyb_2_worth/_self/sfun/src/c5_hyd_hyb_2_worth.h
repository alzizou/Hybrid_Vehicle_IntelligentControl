#ifndef __c5_hyd_hyb_2_worth_h__
#define __c5_hyd_hyb_2_worth_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c5_setSimStateSideEffectsInfo;
  real_T c5_T_0;
  real_T c5_T_1;
  real_T c5_soc_1;
  real_T c5_soc_2;
  real_T c5_t_wait_1;
  real_T c5_t_wait_2;
  real_T c5_t_wait_3;
  real_T c5_veh_spd_0;
  int32_T c5_sfEvent;
  uint32_T c5_elapsedTicks;
  uint32_T c5_presentTicks;
  uint32_T c5_previousTicks;
  uint32_T c5_temporalCounter_i1;
  uint32_T c5_temporalCounter_i2;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_isStable;
  uint8_T c5_b_tp_state1;
  uint8_T c5_b_tp_state2;
  uint8_T c5_b_tp_state3;
  uint8_T c5_c_tp_state1;
  uint8_T c5_c_tp_state2;
  uint8_T c5_c_tp_state3;
  uint8_T c5_d_tp_state1;
  uint8_T c5_d_tp_state2;
  uint8_T c5_doSetSimStateSideEffects;
  uint8_T c5_e_tp_state1;
  uint8_T c5_e_tp_state2;
  uint8_T c5_is_active_c5_hyd_hyb_2_worth;
  uint8_T c5_is_c5_hyd_hyb_2_worth;
  uint8_T c5_is_state1;
  uint8_T c5_is_state2;
  uint8_T c5_is_state3;
  uint8_T c5_is_state4;
  uint8_T c5_tp_state1;
  uint8_T c5_tp_state2;
  uint8_T c5_tp_state3;
  uint8_T c5_tp_state4;
  ChartInfoStruct chartInfo;
} SFc5_hyd_hyb_2_worthInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_hyd_hyb_2_worth_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_hyd_hyb_2_worth_get_check_sum(mxArray *plhs[]);
extern void c5_hyd_hyb_2_worth_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
