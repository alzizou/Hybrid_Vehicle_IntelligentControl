#ifndef __c1_conv_906_eng_hydr_new_h__
#define __c1_conv_906_eng_hydr_new_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c1_setSimStateSideEffectsInfo;
  int32_T c1_sfEvent;
  uint32_T c1_elapsedTicks;
  uint32_T c1_presentTicks;
  uint32_T c1_previousTicks;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_isStable;
  uint8_T c1_doSetSimStateSideEffects;
  uint8_T c1_is_active_c1_conv_906_eng_hydr_new;
  uint8_T c1_is_c1_conv_906_eng_hydr_new;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_tp_Drive;
  uint8_T c1_tp_Neutral;
  ChartInfoStruct chartInfo;
} SFc1_conv_906_eng_hydr_newInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_conv_906_eng_hydr_new_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_conv_906_eng_hydr_new_get_check_sum(mxArray *plhs[]);
extern void c1_conv_906_eng_hydr_new_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif