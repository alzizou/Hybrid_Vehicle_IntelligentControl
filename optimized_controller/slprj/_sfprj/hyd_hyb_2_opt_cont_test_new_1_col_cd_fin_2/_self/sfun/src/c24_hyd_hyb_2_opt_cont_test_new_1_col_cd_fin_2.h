#ifndef __c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2_h__
#define __c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2_h__

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
} c24_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c24_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c24_doneDoubleBufferReInit;
  boolean_T c24_isStable;
  uint8_T c24_is_active_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2;
  ChartInfoStruct chartInfo;
} SFc24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2_get_check_sum
  (mxArray *plhs[]);
extern void c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_fin_2_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif