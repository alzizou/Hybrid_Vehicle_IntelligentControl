#ifndef __c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_h__
#define __c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c13_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c13_doneDoubleBufferReInit;
  boolean_T c13_isStable;
  uint8_T c13_is_active_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd;
  ChartInfoStruct chartInfo;
} SFc13_hyd_hyb_2_opt_cont_test_new_1_col_cdInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(mxArray
  *plhs[]);
extern void c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
