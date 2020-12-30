#ifndef __c5_hyd_hyb_2_fst_con_h__
#define __c5_hyd_hyb_2_fst_con_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c5_setSimStateSideEffectsInfo;
  int32_T c5_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_isStable;
  uint8_T c5_doSetSimStateSideEffects;
  uint8_T c5_is_active_c5_hyd_hyb_2_fst_con;
  uint8_T c5_is_c5_hyd_hyb_2_fst_con;
  uint8_T c5_tp_state1;
  uint8_T c5_tp_state2;
  uint8_T c5_tp_state3;
  ChartInfoStruct chartInfo;
} SFc5_hyd_hyb_2_fst_conInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_hyd_hyb_2_fst_con_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_hyd_hyb_2_fst_con_get_check_sum(mxArray *plhs[]);
extern void c5_hyd_hyb_2_fst_con_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
