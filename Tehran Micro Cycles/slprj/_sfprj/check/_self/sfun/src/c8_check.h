#ifndef __c8_check_h__
#define __c8_check_h__

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
} c8_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c8_T0;
  int32_T c8_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c8_doneDoubleBufferReInit;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_check;
  ChartInfoStruct chartInfo;
} SFc8_checkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_check_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_check_get_check_sum(mxArray *plhs[]);
extern void c8_check_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
