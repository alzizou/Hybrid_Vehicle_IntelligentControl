#ifndef __c21_check_h__
#define __c21_check_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c21_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c21_doneDoubleBufferReInit;
  boolean_T c21_isStable;
  uint8_T c21_is_active_c21_check;
  ChartInfoStruct chartInfo;
} SFc21_checkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_check_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_check_get_check_sum(mxArray *plhs[]);
extern void c21_check_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
