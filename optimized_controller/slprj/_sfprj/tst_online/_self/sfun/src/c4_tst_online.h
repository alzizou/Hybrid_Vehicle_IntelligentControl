#ifndef __c4_tst_online_h__
#define __c4_tst_online_h__

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
} c4_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c4_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c4_doneDoubleBufferReInit;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_tst_online;
  ChartInfoStruct chartInfo;
} SFc4_tst_onlineInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_tst_online_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_tst_online_get_check_sum(mxArray *plhs[]);
extern void c4_tst_online_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
