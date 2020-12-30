#ifndef __c37_hyd_hyb_2_opt_cont_test_new_1_h__
#define __c37_hyd_hyb_2_opt_cont_test_new_1_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c37_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c37_doneDoubleBufferReInit;
  boolean_T c37_isStable;
  uint8_T c37_is_active_c37_hyd_hyb_2_opt_cont_test_new_1;
  ChartInfoStruct chartInfo;
} SFc37_hyd_hyb_2_opt_cont_test_new_1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c37_hyd_hyb_2_opt_cont_test_new_1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c37_hyd_hyb_2_opt_cont_test_new_1_get_check_sum(mxArray *plhs[]);
extern void c37_hyd_hyb_2_opt_cont_test_new_1_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
