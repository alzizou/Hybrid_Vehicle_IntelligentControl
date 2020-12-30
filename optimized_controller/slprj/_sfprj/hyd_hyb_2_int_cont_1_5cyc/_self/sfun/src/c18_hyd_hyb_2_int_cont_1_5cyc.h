#ifndef __c18_hyd_hyb_2_int_cont_1_5cyc_h__
#define __c18_hyd_hyb_2_int_cont_1_5cyc_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc18_hyd_hyb_2_int_cont_1_5cycInstanceStruct
#define typedef_SFc18_hyd_hyb_2_int_cont_1_5cycInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c18_sfEvent;
  boolean_T c18_isStable;
  boolean_T c18_doneDoubleBufferReInit;
  uint8_T c18_is_active_c18_hyd_hyb_2_int_cont_1_5cyc;
  real_T c18_T0;
} SFc18_hyd_hyb_2_int_cont_1_5cycInstanceStruct;

#endif                                 /*typedef_SFc18_hyd_hyb_2_int_cont_1_5cycInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray *plhs[]);
extern void c18_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
