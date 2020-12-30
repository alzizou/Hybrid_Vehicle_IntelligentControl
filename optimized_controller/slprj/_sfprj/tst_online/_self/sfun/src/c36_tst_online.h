#ifndef __c36_tst_online_h__
#define __c36_tst_online_h__

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
} c36_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c36_T0;
  real_T c36_T1;
  real_T c36_teta[24];
  int32_T c36_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c36_doneDoubleBufferReInit;
  boolean_T c36_isStable;
  uint8_T c36_is_active_c36_tst_online;
  ChartInfoStruct chartInfo;
} SFc36_tst_onlineInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_tst_online_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c36_tst_online_get_check_sum(mxArray *plhs[]);
extern void c36_tst_online_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
