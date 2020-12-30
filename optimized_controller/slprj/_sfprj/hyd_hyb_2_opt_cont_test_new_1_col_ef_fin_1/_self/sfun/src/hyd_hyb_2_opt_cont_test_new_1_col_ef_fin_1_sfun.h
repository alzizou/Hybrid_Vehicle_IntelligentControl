#ifndef __hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_1_sfun_h__
#define __hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_1_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "sfcdebug.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */
extern uint32_T _hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_1MachineNumber_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
extern void hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_1_initializer(void);
extern void hyd_hyb_2_opt_cont_test_new_1_col_ef_fin_1_terminator(void);

/* Function Definitions */
#endif
