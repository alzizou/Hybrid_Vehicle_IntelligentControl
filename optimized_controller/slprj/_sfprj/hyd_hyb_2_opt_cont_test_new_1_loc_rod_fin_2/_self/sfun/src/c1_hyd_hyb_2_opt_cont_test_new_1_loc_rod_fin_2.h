#ifndef __c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_h__
#define __c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct
#define typedef_SFc1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_Drive;
  uint8_T c1_tp_Neutral;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2;
  uint8_T c1_is_c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct;

#endif                                 /*typedef_SFc1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_get_check_sum
  (mxArray *plhs[]);
extern void c1_hyd_hyb_2_opt_cont_test_new_1_loc_rod_fin_2_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif