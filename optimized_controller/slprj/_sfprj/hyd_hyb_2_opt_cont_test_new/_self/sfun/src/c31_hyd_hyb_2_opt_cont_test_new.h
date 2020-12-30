#ifndef __c31_hyd_hyb_2_opt_cont_test_new_h__
#define __c31_hyd_hyb_2_opt_cont_test_new_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c31_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c31_doneDoubleBufferReInit;
  boolean_T c31_isStable;
  uint8_T c31_is_active_c31_hyd_hyb_2_opt_cont_test_new;
  ChartInfoStruct chartInfo;
} SFc31_hyd_hyb_2_opt_cont_test_newInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c31_hyd_hyb_2_opt_cont_test_new_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_hyd_hyb_2_opt_cont_test_new_get_check_sum(mxArray *plhs[]);
extern void c31_hyd_hyb_2_opt_cont_test_new_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
