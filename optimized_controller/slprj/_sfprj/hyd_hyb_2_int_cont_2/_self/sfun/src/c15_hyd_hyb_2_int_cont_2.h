#ifndef __c15_hyd_hyb_2_int_cont_2_h__
#define __c15_hyd_hyb_2_int_cont_2_h__

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
} c15_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c15_T0;
  int32_T c15_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c15_doneDoubleBufferReInit;
  boolean_T c15_isStable;
  uint8_T c15_is_active_c15_hyd_hyb_2_int_cont_2;
  ChartInfoStruct chartInfo;
} SFc15_hyd_hyb_2_int_cont_2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_hyd_hyb_2_int_cont_2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_hyd_hyb_2_int_cont_2_get_check_sum(mxArray *plhs[]);
extern void c15_hyd_hyb_2_int_cont_2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif