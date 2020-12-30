#ifndef __c30_hyd_hyb_2_opt_cont_test_new_h__
#define __c30_hyd_hyb_2_opt_cont_test_new_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c30_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c30_doneDoubleBufferReInit;
  boolean_T c30_isStable;
  uint8_T c30_is_active_c30_hyd_hyb_2_opt_cont_test_new;
  ChartInfoStruct chartInfo;
} SFc30_hyd_hyb_2_opt_cont_test_newInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c30_hyd_hyb_2_opt_cont_test_new_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c30_hyd_hyb_2_opt_cont_test_new_get_check_sum(mxArray *plhs[]);
extern void c30_hyd_hyb_2_opt_cont_test_new_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
