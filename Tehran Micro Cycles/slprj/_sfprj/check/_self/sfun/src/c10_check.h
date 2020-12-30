#ifndef __c10_check_h__
#define __c10_check_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c10_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c10_doneDoubleBufferReInit;
  boolean_T c10_isStable;
  uint8_T c10_is_active_c10_check;
  ChartInfoStruct chartInfo;
} SFc10_checkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_check_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_check_get_check_sum(mxArray *plhs[]);
extern void c10_check_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
