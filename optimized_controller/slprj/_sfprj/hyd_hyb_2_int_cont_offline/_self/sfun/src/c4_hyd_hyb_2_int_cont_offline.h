#ifndef __c4_hyd_hyb_2_int_cont_offline_h__
#define __c4_hyd_hyb_2_int_cont_offline_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_hyd_hyb_2_int_cont_offlineInstanceStruct
#define typedef_SFc4_hyd_hyb_2_int_cont_offlineInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_state1;
  uint8_T c4_tp_state2;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_hyd_hyb_2_int_cont_offline;
  uint8_T c4_is_c4_hyd_hyb_2_int_cont_offline;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_hyd_hyb_2_int_cont_offlineInstanceStruct;

#endif                                 /*typedef_SFc4_hyd_hyb_2_int_cont_offlineInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_hyd_hyb_2_int_cont_offline_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_hyd_hyb_2_int_cont_offline_get_check_sum(mxArray *plhs[]);
extern void c4_hyd_hyb_2_int_cont_offline_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif