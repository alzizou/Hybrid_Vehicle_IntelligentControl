#ifndef __c3_hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_h__
#define __c3_hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c3_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c3_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_doneDoubleBufferReInit;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_hyd_hyb_2_opt_cont_test_new_1_col_ef_fin;
  ChartInfoStruct chartInfo;
} SFc3_hyd_hyb_2_opt_cont_test_new_1_col_ef_finInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_get_check_sum(mxArray
  *plhs[]);
extern void c3_hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
