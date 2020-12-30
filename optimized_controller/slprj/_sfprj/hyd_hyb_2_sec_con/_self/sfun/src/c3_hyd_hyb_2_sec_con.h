#ifndef __c3_hyd_hyb_2_sec_con_h__
#define __c3_hyd_hyb_2_sec_con_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T c3_T_0;
  real_T c3_T_1;
  real_T c3_T_2;
  real_T c3_soc_1;
  real_T c3_soc_2;
  real_T c3_t_wait_1;
  real_T c3_t_wait_2;
  real_T c3_t_wait_3;
  real_T c3_veh_spd_0;
  int32_T c3_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_isStable;
  uint8_T c3_b_tp_state1;
  uint8_T c3_b_tp_state2;
  uint8_T c3_b_tp_state3;
  uint8_T c3_c_tp_state1;
  uint8_T c3_c_tp_state2;
  uint8_T c3_doSetSimStateSideEffects;
  uint8_T c3_is_active_c3_hyd_hyb_2_sec_con;
  uint8_T c3_is_c3_hyd_hyb_2_sec_con;
  uint8_T c3_is_state2;
  uint8_T c3_is_state3;
  uint8_T c3_tp_state1;
  uint8_T c3_tp_state2;
  uint8_T c3_tp_state3;
  ChartInfoStruct chartInfo;
} SFc3_hyd_hyb_2_sec_conInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_hyd_hyb_2_sec_con_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_hyd_hyb_2_sec_con_get_check_sum(mxArray *plhs[]);
extern void c3_hyd_hyb_2_sec_con_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
