#ifndef __c7_hyd_hyb_2_int_cont_h__
#define __c7_hyd_hyb_2_int_cont_h__

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
} c7_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c7_T0;
  int32_T c7_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c7_doneDoubleBufferReInit;
  boolean_T c7_isStable;
  uint8_T c7_is_active_c7_hyd_hyb_2_int_cont;
  ChartInfoStruct chartInfo;
} SFc7_hyd_hyb_2_int_contInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_hyd_hyb_2_int_cont_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c7_hyd_hyb_2_int_cont_get_check_sum(mxArray *plhs[]);
extern void c7_hyd_hyb_2_int_cont_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif