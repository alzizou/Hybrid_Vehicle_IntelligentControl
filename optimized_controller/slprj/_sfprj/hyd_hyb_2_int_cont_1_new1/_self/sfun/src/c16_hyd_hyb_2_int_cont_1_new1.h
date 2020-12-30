#ifndef __c16_hyd_hyb_2_int_cont_1_new1_h__
#define __c16_hyd_hyb_2_int_cont_1_new1_h__

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
} c16_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c16_T0;
  int32_T c16_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c16_doneDoubleBufferReInit;
  boolean_T c16_isStable;
  uint8_T c16_is_active_c16_hyd_hyb_2_int_cont_1_new1;
  ChartInfoStruct chartInfo;
} SFc16_hyd_hyb_2_int_cont_1_new1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c16_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray *plhs[]);
extern void c16_hyd_hyb_2_int_cont_1_new1_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
