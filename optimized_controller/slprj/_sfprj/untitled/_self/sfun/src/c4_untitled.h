#ifndef __c4_untitled_h__
#define __c4_untitled_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c4_setSimStateSideEffectsInfo;
  int32_T c4_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c4_isStable;
  uint8_T c4_doSetSimStateSideEffects;
  uint8_T c4_is_active_c4_untitled;
  uint8_T c4_is_c4_untitled;
  uint8_T c4_tp_state1;
  uint8_T c4_tp_state2;
  ChartInfoStruct chartInfo;
} SFc4_untitledInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_untitled_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_untitled_get_check_sum(mxArray *plhs[]);
extern void c4_untitled_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
