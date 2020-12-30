#ifndef __c2_hyd_hyb_2_int_cont_1_new1_h__
#define __c2_hyd_hyb_2_int_cont_1_new1_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c2_setSimStateSideEffectsInfo;
  real_T c2_Twait;
  real_T c2_down_spd_2;
  real_T c2_down_spd_3;
  real_T c2_down_spd_4;
  real_T c2_down_spd_c;
  real_T c2_up_spd_1;
  real_T c2_up_spd_2;
  real_T c2_up_spd_3;
  real_T c2_up_spd_c;
  int32_T c2_sfEvent;
  uint32_T c2_temporalCounter_i1;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_isStable;
  uint8_T c2_doSetSimStateSideEffects;
  uint8_T c2_is_active_c2_hyd_hyb_2_int_cont_1_new1;
  uint8_T c2_is_c2_hyd_hyb_2_int_cont_1_new1;
  uint8_T c2_tp_first;
  uint8_T c2_tp_firstc;
  uint8_T c2_tp_fourth;
  uint8_T c2_tp_second;
  uint8_T c2_tp_third;
  ChartInfoStruct chartInfo;
} SFc2_hyd_hyb_2_int_cont_1_new1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray *plhs[]);
extern void c2_hyd_hyb_2_int_cont_1_new1_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
