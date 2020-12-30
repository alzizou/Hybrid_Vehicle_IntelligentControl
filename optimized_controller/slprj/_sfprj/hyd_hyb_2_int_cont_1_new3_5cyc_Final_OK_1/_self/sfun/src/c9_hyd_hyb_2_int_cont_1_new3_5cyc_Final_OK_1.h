#ifndef __c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_h__
#define __c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_h__

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
} c9_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c9_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c9_doneDoubleBufferReInit;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  ChartInfoStruct chartInfo;
} SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_check_sum
  (mxArray *plhs[]);
extern void c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
