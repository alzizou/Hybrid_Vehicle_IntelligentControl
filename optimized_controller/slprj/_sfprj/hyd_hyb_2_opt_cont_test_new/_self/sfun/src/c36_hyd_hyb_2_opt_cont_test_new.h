#ifndef __c36_hyd_hyb_2_opt_cont_test_new_h__
#define __c36_hyd_hyb_2_opt_cont_test_new_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c36_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c36_doneDoubleBufferReInit;
  boolean_T c36_isStable;
  uint8_T c36_is_active_c36_hyd_hyb_2_opt_cont_test_new;
  ChartInfoStruct chartInfo;
} SFc36_hyd_hyb_2_opt_cont_test_newInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c36_hyd_hyb_2_opt_cont_test_new_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c36_hyd_hyb_2_opt_cont_test_new_get_check_sum(mxArray *plhs[]);
extern void c36_hyd_hyb_2_opt_cont_test_new_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif