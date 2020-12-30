#ifndef __c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_h__
#define __c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct
#define typedef_SFc2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_fourth;
  uint8_T c2_tp_third;
  uint8_T c2_tp_second;
  uint8_T c2_tp_first;
  uint8_T c2_tp_firstc;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2;
  uint8_T c2_is_c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2;
  real_T c2_down_spd_4;
  real_T c2_down_spd_2;
  real_T c2_down_spd_3;
  real_T c2_up_spd_1;
  real_T c2_up_spd_2;
  real_T c2_up_spd_3;
  real_T c2_down_spd_c;
  real_T c2_up_spd_c;
  real_T c2_Twait;
  uint32_T c2_temporalCounter_i1;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct;

#endif                                 /*typedef_SFc2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_get_check_sum
  (mxArray *plhs[]);
extern void c2_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
