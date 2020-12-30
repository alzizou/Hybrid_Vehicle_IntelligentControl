#ifndef __c3_hyd_hyb_2_h__
#define __c3_hyd_hyb_2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_hyd_hyb_2InstanceStruct
#define typedef_SFc3_hyd_hyb_2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_state1;
  uint8_T c3_tp_state2;
  uint8_T c3_b_tp_state2;
  uint8_T c3_tp_state3;
  uint8_T c3_b_tp_state1;
  uint8_T c3_b_tp_state3;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_hyd_hyb_2;
  uint8_T c3_is_c3_hyd_hyb_2;
  uint8_T c3_is_state2;
  real_T c3_T_0;
  real_T c3_T_1;
  real_T c3_soc_1;
  real_T c3_soc_2;
  real_T c3_t_wait_1;
  real_T c3_t_wait_2;
  real_T c3_t_wait_3;
  real_T c3_veh_spd_0;
  real_T c3_T_2;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_hyd_hyb_2InstanceStruct;

#endif                                 /*typedef_SFc3_hyd_hyb_2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_hyd_hyb_2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_hyd_hyb_2_get_check_sum(mxArray *plhs[]);
extern void c3_hyd_hyb_2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
