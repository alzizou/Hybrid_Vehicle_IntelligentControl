#ifndef __c22_hyd_hyb_2_opt_cont_test_new_1_h__
#define __c22_hyd_hyb_2_opt_cont_test_new_1_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c22_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c22_doneDoubleBufferReInit;
  boolean_T c22_isStable;
  uint8_T c22_is_active_c22_hyd_hyb_2_opt_cont_test_new_1;
  ChartInfoStruct chartInfo;
} SFc22_hyd_hyb_2_opt_cont_test_new_1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c22_hyd_hyb_2_opt_cont_test_new_1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_hyd_hyb_2_opt_cont_test_new_1_get_check_sum(mxArray *plhs[]);
extern void c22_hyd_hyb_2_opt_cont_test_new_1_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif