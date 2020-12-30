#ifndef __c22_check_h__
#define __c22_check_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c22_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c22_doneDoubleBufferReInit;
  boolean_T c22_isStable;
  uint8_T c22_is_active_c22_check;
  ChartInfoStruct chartInfo;
} SFc22_checkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_check_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_check_get_check_sum(mxArray *plhs[]);
extern void c22_check_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
