#ifndef __c5_hyd_hyb_2_opt_cont_test_h__
#define __c5_hyd_hyb_2_opt_cont_test_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c5_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_doneDoubleBufferReInit;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_hyd_hyb_2_opt_cont_test;
  ChartInfoStruct chartInfo;
} SFc5_hyd_hyb_2_opt_cont_testInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_hyd_hyb_2_opt_cont_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_hyd_hyb_2_opt_cont_test_get_check_sum(mxArray *plhs[]);
extern void c5_hyd_hyb_2_opt_cont_test_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
