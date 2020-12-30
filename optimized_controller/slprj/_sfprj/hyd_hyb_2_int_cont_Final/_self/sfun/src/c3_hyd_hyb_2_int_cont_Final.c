/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hyd_hyb_2_int_cont_Final_sfun.h"
#include "c3_hyd_hyb_2_int_cont_Final.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_Final_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[42] = { "cyc", "h", "cyc_tim",
  "sum_spd", "a", "sum_acc", "sum_dec", "dis", "dist", "num_acc", "num_dec",
  "av", "sum_av", "sum_av_p", "pke_1", "pke_dis", "num_spd_0_10",
  "num_spd_20_30", "num_acc_02_04", "num_acc_06_08", "num_dec_02_04",
  "num_dec_06_08", "num_av_0_5", "r", "i", "nargin", "nargout", "t",
  "Driving_Cycle", "T0", "T1", "mem", "prc_spd_0_10", "prc_spd_20_30", "max_acc",
  "prc_acc_02_04", "prc_acc_06_08", "prc_dec_02_04", "prc_dec_06_08", "rpa",
  "prc_av_0_5", "pke" };

/* Function Declarations */
static void initialize_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void initialize_params_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void enable_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void disable_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void set_sim_state_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void finalize_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void sf_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void c3_chartstep_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void initSimStructsc3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_pke, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2164]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2166]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[1083]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(uint32_T c3_u);
static real_T c3_rem(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance,
                     real_T c3_x, real_T c3_y);
static void c3_eml_scalar_eg(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance);
static real_T c3_round(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, real_T c3_x);
static void c3_check_forloop_overflow_error
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, boolean_T
   c3_overflow);
static real_T c3_mpower(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, real_T c3_a);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_hyd_hyb_2_int_cont_Final,
  const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_round(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, real_T *c3_x);
static void init_dsm_address_info(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_hyd_hyb_2_int_cont_Final = 0U;
}

static void initialize_params_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  real_T c3_dv0[2164];
  int32_T c3_i0;
  real_T c3_d0;
  real_T c3_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'Driving_Cycle' in the parent workspace.\n");
  sf_mex_import_named("Driving_Cycle", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), c3_dv0, 0, 0, 0U, 1, 0U, 2, 1082, 2);
  for (c3_i0 = 0; c3_i0 < 2164; c3_i0++) {
    chartInstance->c3_Driving_Cycle[c3_i0] = c3_dv0[c3_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T0' in the parent workspace.\n");
  sf_mex_import_named("T0", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_T0 = c3_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T1' in the parent workspace.\n");
  sf_mex_import_named("T1", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_T1 = c3_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_j_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  uint8_T c3_k_hoistedGlobal;
  uint8_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T *c3_max_acc;
  real_T *c3_pke;
  real_T *c3_prc_acc_02_04;
  real_T *c3_prc_acc_06_08;
  real_T *c3_prc_av_0_5;
  real_T *c3_prc_dec_02_04;
  real_T *c3_prc_dec_06_08;
  real_T *c3_prc_spd_0_10;
  real_T *c3_prc_spd_20_30;
  real_T *c3_rpa;
  c3_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(11), FALSE);
  c3_hoistedGlobal = *c3_max_acc;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_pke;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_prc_acc_02_04;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_prc_acc_06_08;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_prc_av_0_5;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_prc_dec_02_04;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *c3_prc_dec_06_08;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *c3_prc_spd_0_10;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *c3_prc_spd_20_30;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *c3_rpa;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = chartInstance->c3_is_active_c3_hyd_hyb_2_int_cont_Final;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_max_acc;
  real_T *c3_pke;
  real_T *c3_prc_acc_02_04;
  real_T *c3_prc_acc_06_08;
  real_T *c3_prc_av_0_5;
  real_T *c3_prc_dec_02_04;
  real_T *c3_prc_dec_06_08;
  real_T *c3_prc_spd_0_10;
  real_T *c3_prc_spd_20_30;
  real_T *c3_rpa;
  c3_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_max_acc = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "max_acc");
  *c3_pke = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "pke");
  *c3_prc_acc_02_04 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "prc_acc_02_04");
  *c3_prc_acc_06_08 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "prc_acc_06_08");
  *c3_prc_av_0_5 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 4)), "prc_av_0_5");
  *c3_prc_dec_02_04 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "prc_dec_02_04");
  *c3_prc_dec_06_08 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "prc_dec_06_08");
  *c3_prc_spd_0_10 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "prc_spd_0_10");
  *c3_prc_spd_20_30 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "prc_spd_20_30");
  *c3_rpa = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)),
    "rpa");
  chartInstance->c3_is_active_c3_hyd_hyb_2_int_cont_Final =
    c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 10)),
    "is_active_c3_hyd_hyb_2_int_cont_Final");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_hyd_hyb_2_int_cont_Final(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void sf_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  int32_T c3_i1;
  int32_T c3_i2;
  real_T *c3_t;
  real_T *c3_prc_spd_0_10;
  real_T *c3_prc_spd_20_30;
  real_T *c3_max_acc;
  real_T *c3_prc_acc_02_04;
  real_T *c3_prc_acc_06_08;
  real_T *c3_prc_dec_02_04;
  real_T *c3_prc_dec_06_08;
  real_T *c3_rpa;
  real_T *c3_prc_av_0_5;
  real_T *c3_pke;
  real_T (*c3_mem)[10];
  c3_mem = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
  c3_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_spd_0_10, 1U);
  for (c3_i1 = 0; c3_i1 < 2164; c3_i1++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Driving_Cycle[c3_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_T0, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_T1, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_spd_20_30, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_max_acc, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_acc_02_04, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_acc_06_08, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_dec_02_04, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_dec_06_08, 10U);
  _SFD_DATA_RANGE_CHECK(*c3_rpa, 11U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_av_0_5, 12U);
  _SFD_DATA_RANGE_CHECK(*c3_pke, 13U);
  for (c3_i2 = 0; c3_i2 < 10; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_mem)[c3_i2], 14U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_hyd_hyb_2_int_cont_Final(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hyd_hyb_2_int_cont_FinalMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_t;
  int32_T c3_i3;
  real_T c3_b_Driving_Cycle[2164];
  real_T c3_b_T0;
  real_T c3_b_T1;
  int32_T c3_i4;
  real_T c3_mem[10];
  uint32_T c3_debug_family_var_map[42];
  real_T c3_cyc[2164];
  real_T c3_h[2];
  real_T c3_cyc_tim;
  real_T c3_sum_spd;
  real_T c3_a[2166];
  real_T c3_sum_acc;
  real_T c3_sum_dec;
  real_T c3_dis[1083];
  real_T c3_dist;
  real_T c3_num_acc;
  real_T c3_num_dec;
  real_T c3_av[2166];
  real_T c3_sum_av;
  real_T c3_sum_av_p;
  real_T c3_pke_1;
  real_T c3_pke_dis;
  real_T c3_num_spd_0_10;
  real_T c3_num_spd_20_30;
  real_T c3_num_acc_02_04;
  real_T c3_num_acc_06_08;
  real_T c3_num_dec_02_04;
  real_T c3_num_dec_06_08;
  real_T c3_num_av_0_5;
  real_T c3_r;
  real_T c3_i;
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 10.0;
  real_T c3_prc_spd_0_10;
  real_T c3_prc_spd_20_30;
  real_T c3_max_acc;
  real_T c3_prc_acc_02_04;
  real_T c3_prc_acc_06_08;
  real_T c3_prc_dec_02_04;
  real_T c3_prc_dec_06_08;
  real_T c3_rpa;
  real_T c3_prc_av_0_5;
  real_T c3_pke;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T c3_b_t;
  int32_T c3_i10;
  int32_T c3_b_i;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_b_a;
  real_T c3_y;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  real_T c3_c_a;
  real_T c3_d10;
  real_T c3_b;
  real_T c3_c_y;
  real_T c3_d_a;
  real_T c3_d_y;
  real_T c3_d11;
  real_T c3_e_a;
  real_T c3_d12;
  real_T c3_b_b;
  real_T c3_e_y;
  real_T c3_f_a;
  real_T c3_f_y;
  real_T c3_c_b;
  real_T c3_g_y;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d15;
  real_T c3_d16;
  real_T c3_d17;
  real_T c3_g_a;
  real_T c3_h_y;
  real_T c3_b_A;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_i_y;
  real_T c3_h_a;
  real_T c3_d_b;
  real_T c3_j_y;
  real_T c3_d18;
  real_T c3_d19;
  real_T c3_c_t;
  int32_T c3_i11;
  int32_T c3_c_i;
  real_T c3_d20;
  real_T c3_d21;
  real_T c3_d22;
  real_T c3_e_b;
  real_T c3_k_y;
  real_T c3_c_A;
  real_T c3_B;
  real_T c3_e_x;
  real_T c3_l_y;
  real_T c3_f_x;
  real_T c3_m_y;
  real_T c3_f_b;
  real_T c3_n_y;
  real_T c3_d_A;
  real_T c3_b_B;
  real_T c3_g_x;
  real_T c3_o_y;
  real_T c3_h_x;
  real_T c3_p_y;
  real_T c3_d_t;
  int32_T c3_i12;
  int32_T c3_d_i;
  real_T c3_d23;
  real_T c3_g_b;
  real_T c3_q_y;
  real_T c3_i_a;
  real_T c3_r_y;
  real_T c3_e_A;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_s_y;
  real_T c3_d24;
  real_T c3_d25;
  int32_T c3_i13;
  real_T c3_varargin_1[1083];
  int32_T c3_ixstart;
  real_T c3_mtmp;
  real_T c3_k_x;
  boolean_T c3_h_b;
  int32_T c3_ix;
  int32_T c3_b_ix;
  real_T c3_l_x;
  boolean_T c3_i_b;
  int32_T c3_j_a;
  int32_T c3_i14;
  boolean_T c3_overflow;
  int32_T c3_c_ix;
  real_T c3_k_a;
  real_T c3_j_b;
  boolean_T c3_p;
  real_T c3_b_mtmp;
  real_T c3_maxval;
  real_T c3_f_A;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_e_t;
  int32_T c3_i15;
  int32_T c3_e_i;
  real_T c3_d26;
  real_T c3_d27;
  real_T c3_d28;
  real_T c3_d29;
  real_T c3_k_b;
  real_T c3_t_y;
  real_T c3_g_A;
  real_T c3_c_B;
  real_T c3_o_x;
  real_T c3_u_y;
  real_T c3_p_x;
  real_T c3_v_y;
  real_T c3_l_b;
  real_T c3_w_y;
  real_T c3_h_A;
  real_T c3_d_B;
  real_T c3_q_x;
  real_T c3_x_y;
  real_T c3_r_x;
  real_T c3_y_y;
  real_T c3_f_t;
  int32_T c3_i16;
  int32_T c3_f_i;
  real_T c3_d30;
  real_T c3_d31;
  real_T c3_d32;
  real_T c3_d33;
  real_T c3_m_b;
  real_T c3_ab_y;
  real_T c3_i_A;
  real_T c3_e_B;
  real_T c3_s_x;
  real_T c3_bb_y;
  real_T c3_t_x;
  real_T c3_cb_y;
  real_T c3_n_b;
  real_T c3_db_y;
  real_T c3_j_A;
  real_T c3_f_B;
  real_T c3_u_x;
  real_T c3_eb_y;
  real_T c3_v_x;
  real_T c3_fb_y;
  real_T c3_g_t;
  int32_T c3_i17;
  int32_T c3_g_i;
  real_T c3_d34;
  real_T c3_d35;
  real_T c3_o_b;
  real_T c3_gb_y;
  real_T c3_k_A;
  real_T c3_g_B;
  real_T c3_w_x;
  real_T c3_hb_y;
  real_T c3_x_x;
  real_T c3_ib_y;
  real_T c3_l_A;
  real_T c3_h_B;
  real_T c3_y_x;
  real_T c3_jb_y;
  real_T c3_ab_x;
  real_T c3_kb_y;
  real_T c3_lb_y;
  real_T c3_m_A;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_h_t;
  int32_T c3_i18;
  int32_T c3_h_i;
  real_T c3_d36;
  real_T c3_d37;
  real_T c3_l_a;
  real_T c3_mb_y;
  real_T c3_d38;
  real_T c3_m_a;
  real_T c3_nb_y;
  real_T c3_d39;
  real_T c3_n_a;
  real_T c3_ob_y;
  real_T c3_o_a;
  real_T c3_pb_y;
  real_T c3_n_A;
  real_T c3_i_B;
  real_T c3_db_x;
  real_T c3_qb_y;
  real_T c3_eb_x;
  real_T c3_rb_y;
  real_T c3_sb_y;
  real_T c3_o_A;
  real_T c3_fb_x;
  real_T c3_gb_x;
  real_T *c3_i_t;
  real_T *c3_b_prc_spd_0_10;
  real_T *c3_b_prc_spd_20_30;
  real_T *c3_b_max_acc;
  real_T *c3_b_prc_acc_02_04;
  real_T *c3_b_prc_acc_06_08;
  real_T *c3_b_prc_dec_02_04;
  real_T *c3_b_prc_dec_06_08;
  real_T *c3_b_rpa;
  real_T *c3_b_prc_av_0_5;
  real_T *c3_b_pke;
  real_T (*c3_b_mem)[10];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T exitg1;
  c3_b_mem = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_b_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_b_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_b_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_b_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_b_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_i_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_i_t;
  c3_b_hoistedGlobal = chartInstance->c3_T0;
  c3_c_hoistedGlobal = chartInstance->c3_T1;
  c3_t = c3_hoistedGlobal;
  for (c3_i3 = 0; c3_i3 < 2164; c3_i3++) {
    c3_b_Driving_Cycle[c3_i3] = chartInstance->c3_Driving_Cycle[c3_i3];
  }

  c3_b_T0 = c3_b_hoistedGlobal;
  c3_b_T1 = c3_c_hoistedGlobal;
  for (c3_i4 = 0; c3_i4 < 10; c3_i4++) {
    c3_mem[c3_i4] = (*c3_b_mem)[c3_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 42U, 42U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_cyc, 0U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_h, 1U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_cyc_tim, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sum_spd, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_a, 4U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sum_acc, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sum_dec, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_dis, 7U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_dist, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_acc, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_dec, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_av, 11U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sum_av, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sum_av_p, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_pke_1, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_pke_dis, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_spd_0_10, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_spd_20_30, 17U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_acc_02_04, 18U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_acc_06_08, 19U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_dec_02_04, 20U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_dec_06_08, 21U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_num_av_0_5, 22U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r, 23U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i, 24U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 25U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 26U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_t, 27U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_Driving_Cycle, 28U,
    c3_c_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_T0, 29U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_T1, 30U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mem, 31U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_spd_0_10, 32U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_spd_20_30, 33U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_max_acc, 34U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_acc_02_04, 35U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_acc_06_08, 36U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_dec_02_04, 37U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_dec_06_08, 38U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_rpa, 39U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_prc_av_0_5, 40U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_pke, 41U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i5 = 0; c3_i5 < 2164; c3_i5++) {
    c3_cyc[c3_i5] = c3_b_Driving_Cycle[c3_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_h[c3_i6] = 1082.0 + -1080.0 * (real_T)c3_i6;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_cyc_tim = 1083.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sum_spd = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i7 = 0; c3_i7 < 2166; c3_i7++) {
    c3_a[c3_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sum_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sum_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i8 = 0; c3_i8 < 1083; c3_i8++) {
    c3_dis[c3_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_dist = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_num_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_num_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i9 = 0; c3_i9 < 2166; c3_i9++) {
    c3_av[c3_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_sum_av = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_sum_av_p = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_pke_1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_pke_dis = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_num_spd_0_10 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_num_spd_20_30 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_num_acc_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_num_acc_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_num_dec_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_num_dec_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_num_av_0_5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_prc_spd_0_10 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  c3_prc_spd_20_30 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_max_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
  c3_prc_acc_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_prc_acc_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  c3_prc_dec_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_prc_dec_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_rpa = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  c3_prc_av_0_5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_pke = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  if (CV_EML_IF(0, 1, 0, c3_t >= c3_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
    c3_r = c3_rem(chartInstance, c3_t, c3_b_T1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
    if (CV_EML_IF(0, 1, 1, c3_r == 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
      c3_b_t = c3_t;
      c3_i10 = (int32_T)c3_b_t;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_b_t, mxDOUBLE_CLASS, c3_i10);
      c3_i = 1.0;
      c3_b_i = 0;
      while (c3_b_i <= c3_i10 - 1) {
        c3_i = 1.0 + (real_T)c3_b_i;
        CV_EML_FOR(0, 1, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
        c3_d2 = c3_i;
        c3_b_round(chartInstance, &c3_d2);
        c3_sum_spd += c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
          (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d2), 1, 1082, 1, 0) + 1081];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
        c3_d3 = c3_i;
        c3_b_round(chartInstance, &c3_d3);
        if (CV_EML_IF(0, 1, 2, c3_d3 > 1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
          c3_d4 = c3_i;
          c3_b_round(chartInstance, &c3_d4);
          c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("i", c3_i), 1, 1083, 1, 0) - 1] = c3_cyc[(int32_T)
            (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d4), 1, 1082, 1, 0) - 1];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
          c3_d5 = c3_i;
          c3_b_round(chartInstance, &c3_d5);
          c3_d6 = c3_i;
          c3_b_round(chartInstance, &c3_d6);
          c3_b_a = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d5), 1, 1082, 1, 0) +
            1081] - c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)-1", c3_d6 - 1.0), 1, 1082, 1,
            0) + 1081];
          c3_y = c3_b_a * 0.27777777777777779;
          c3_A = c3_y;
          c3_x = c3_A;
          c3_b_x = c3_x;
          c3_b_y = c3_b_x;
          c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("i", c3_i), 1, 1083, 1, 0) + 1082] = c3_b_y;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
        c3_d7 = c3_i;
        c3_b_round(chartInstance, &c3_d7);
        if (CV_EML_IF(0, 1, 3, c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK
                      ("a", (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d7), 1,
                       1083, 1, 0) + 1082] > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
          c3_num_acc++;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
          c3_d8 = c3_i;
          c3_b_round(chartInstance, &c3_d8);
          c3_sum_acc += c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d8), 1, 1083, 1, 0) +
            1082];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
          c3_d9 = c3_i;
          c3_b_round(chartInstance, &c3_d9);
          c3_c_a = c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d9), 1, 1083, 1, 0) +
            1082];
          c3_d10 = c3_i;
          c3_b_round(chartInstance, &c3_d10);
          c3_b = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d10), 1, 1082, 1, 0) +
            1081];
          c3_c_y = c3_c_a * c3_b;
          c3_d_a = c3_c_y;
          c3_d_y = c3_d_a * 0.27777777777777779;
          c3_d11 = c3_i;
          c3_b_round(chartInstance, &c3_d11);
          c3_e_a = c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a",
            (int32_T)_SFD_INTEGER_CHECK("round(i)+1", c3_d11 + 1.0), 1, 1083, 1,
            0) + 1082];
          c3_d12 = c3_i;
          c3_b_round(chartInstance, &c3_d12);
          c3_b_b = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)+1", c3_d12 + 1.0), 1, 1082, 1,
            0) + 1081];
          c3_e_y = c3_e_a * c3_b_b;
          c3_f_a = c3_e_y;
          c3_f_y = c3_f_a * 0.27777777777777779;
          c3_c_b = c3_d_y + c3_f_y;
          c3_g_y = 0.5 * c3_c_b;
          c3_sum_av_p += c3_g_y;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
        c3_d13 = c3_i;
        c3_b_round(chartInstance, &c3_d13);
        if (CV_EML_IF(0, 1, 4, c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK
                      ("a", (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d13), 1,
                       1083, 1, 0) + 1082] < 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
          c3_num_dec++;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
          c3_d14 = c3_i;
          c3_b_round(chartInstance, &c3_d14);
          c3_sum_dec += c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d14), 1, 1083, 1, 0) +
            1082];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
        c3_d15 = c3_i;
        c3_b_round(chartInstance, &c3_d15);
        c3_d16 = c3_i;
        c3_b_round(chartInstance, &c3_d16);
        c3_av[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d15), 1, 1083, 1, 0) - 1] = c3_cyc
          [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d16), 1, 1082, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
        c3_d17 = c3_i;
        c3_b_round(chartInstance, &c3_d17);
        c3_g_a = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
          (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d17), 1, 1082, 1, 0) + 1081];
        c3_h_y = c3_g_a * 10.0;
        c3_b_A = c3_h_y;
        c3_c_x = c3_b_A;
        c3_d_x = c3_c_x;
        c3_i_y = c3_d_x / 36.0;
        c3_h_a = c3_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
          _SFD_INTEGER_CHECK("i", c3_i), 1, 1083, 1, 0) + 1082];
        c3_d_b = c3_i_y;
        c3_j_y = c3_h_a * c3_d_b;
        c3_d18 = c3_i;
        c3_b_round(chartInstance, &c3_d18);
        c3_av[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d18), 1, 1083, 1, 0) + 1082] =
          c3_j_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
        c3_d19 = c3_i;
        c3_b_round(chartInstance, &c3_d19);
        c3_sum_av += c3_av[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("av",
          (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d19), 1, 1083, 1, 0) + 1082];
        c3_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
      c3_c_t = c3_t;
      c3_i11 = (int32_T)c3_c_t;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_c_t, mxDOUBLE_CLASS, c3_i11);
      c3_i = 1.0;
      c3_c_i = 0;
      while (c3_c_i <= c3_i11 - 1) {
        c3_i = 1.0 + (real_T)c3_c_i;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
        c3_d20 = c3_i;
        c3_b_round(chartInstance, &c3_d20);
        if (CV_EML_IF(0, 1, 5, c3_cyc[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d20), 1, 1082, 1, 0) + 1081] <
                      10.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
          c3_num_spd_0_10++;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
        c3_d21 = c3_i;
        c3_b_round(chartInstance, &c3_d21);
        guard6 = FALSE;
        if (CV_EML_COND(0, 1, 0, c3_cyc[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d21), 1, 1082, 1, 0) + 1081] <
                        30.0)) {
          c3_d22 = c3_i;
          c3_b_round(chartInstance, &c3_d22);
          if (CV_EML_COND(0, 1, 1, c3_cyc[(int32_T)(real_T)
                          _SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d22), 1, 1082, 1, 0) + 1081] >=
                          20.0)) {
            CV_EML_MCDC(0, 1, 0, TRUE);
            CV_EML_IF(0, 1, 6, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 73);
            c3_num_spd_20_30++;
          } else {
            guard6 = TRUE;
          }
        } else {
          guard6 = TRUE;
        }

        if (guard6 == TRUE) {
          CV_EML_MCDC(0, 1, 0, FALSE);
          CV_EML_IF(0, 1, 6, FALSE);
        }

        c3_c_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
      c3_e_b = c3_num_spd_0_10;
      c3_k_y = c3_e_b;
      c3_c_A = c3_k_y;
      c3_B = c3_t;
      c3_e_x = c3_c_A;
      c3_l_y = c3_B;
      c3_f_x = c3_e_x;
      c3_m_y = c3_l_y;
      c3_prc_spd_0_10 = c3_f_x / c3_m_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 87);
      c3_f_b = c3_num_spd_20_30;
      c3_n_y = c3_f_b;
      c3_d_A = c3_n_y;
      c3_b_B = c3_t;
      c3_g_x = c3_d_A;
      c3_o_y = c3_b_B;
      c3_h_x = c3_g_x;
      c3_p_y = c3_o_y;
      c3_prc_spd_20_30 = c3_h_x / c3_p_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 94);
      c3_d_t = c3_t;
      c3_i12 = (int32_T)c3_d_t;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_d_t, mxDOUBLE_CLASS, c3_i12);
      c3_i = 1.0;
      c3_d_i = 0;
      while (c3_d_i <= c3_i12 - 1) {
        c3_i = 1.0 + (real_T)c3_d_i;
        CV_EML_FOR(0, 1, 2, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 95);
        c3_d23 = c3_i;
        c3_b_round(chartInstance, &c3_d23);
        c3_g_b = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
          (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d23), 1, 1082, 1, 0) + 1081];
        c3_q_y = c3_g_b;
        c3_i_a = c3_q_y;
        c3_r_y = c3_i_a * 10.0;
        c3_e_A = c3_r_y;
        c3_i_x = c3_e_A;
        c3_j_x = c3_i_x;
        c3_s_y = c3_j_x / 36.0;
        c3_d24 = c3_i;
        c3_b_round(chartInstance, &c3_d24);
        c3_dis[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dis", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d24), 1, 1083, 1, 0) - 1] = c3_s_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
        c3_d25 = c3_i;
        c3_b_round(chartInstance, &c3_d25);
        c3_dist += c3_dis[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dis",
          (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d25), 1, 1083, 1, 0) - 1];
        c3_d_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 2, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 101);
      for (c3_i13 = 0; c3_i13 < 1083; c3_i13++) {
        c3_varargin_1[c3_i13] = c3_a[c3_i13 + 1083];
      }

      c3_ixstart = 1;
      c3_mtmp = c3_varargin_1[0];
      c3_k_x = c3_mtmp;
      c3_h_b = muDoubleScalarIsNaN(c3_k_x);
      if (c3_h_b) {
        c3_ix = 2;
        exitg1 = FALSE;
        while ((exitg1 == FALSE) && (c3_ix < 1084)) {
          c3_b_ix = c3_ix;
          c3_ixstart = c3_b_ix;
          c3_l_x = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_b_ix), 1, 1083, 1, 0) - 1];
          c3_i_b = muDoubleScalarIsNaN(c3_l_x);
          if (!c3_i_b) {
            c3_mtmp = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c3_b_ix), 1, 1083, 1, 0) - 1];
            exitg1 = TRUE;
          } else {
            c3_ix++;
          }
        }
      }

      if (c3_ixstart < 1083) {
        c3_j_a = c3_ixstart;
        c3_i14 = c3_j_a;
        c3_overflow = FALSE;
        if (c3_overflow) {
          c3_check_forloop_overflow_error(chartInstance, c3_overflow);
        }

        for (c3_c_ix = c3_i14 + 1; c3_c_ix < 1084; c3_c_ix++) {
          c3_b_ix = c3_c_ix;
          c3_k_a = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_b_ix), 1, 1083, 1, 0) - 1];
          c3_j_b = c3_mtmp;
          c3_p = (c3_k_a > c3_j_b);
          if (c3_p) {
            c3_mtmp = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c3_b_ix), 1, 1083, 1, 0) - 1];
          }
        }
      }

      c3_b_mtmp = c3_mtmp;
      c3_maxval = c3_b_mtmp;
      c3_f_A = c3_maxval;
      c3_m_x = c3_f_A;
      c3_n_x = c3_m_x;
      c3_max_acc = c3_n_x / 6.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 102);
      c3_e_t = c3_t;
      c3_i15 = (int32_T)c3_e_t;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_e_t, mxDOUBLE_CLASS, c3_i15);
      c3_i = 1.0;
      c3_e_i = 0;
      while (c3_e_i <= c3_i15 - 1) {
        c3_i = 1.0 + (real_T)c3_e_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 106);
        c3_d26 = c3_i;
        c3_b_round(chartInstance, &c3_d26);
        guard5 = FALSE;
        if (CV_EML_COND(0, 1, 2, c3_a[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d26), 1, 1083, 1, 0) + 1082] <
                        0.4)) {
          c3_d27 = c3_i;
          c3_b_round(chartInstance, &c3_d27);
          if (CV_EML_COND(0, 1, 3, c3_a[(int32_T)(real_T)
                          _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d27), 1, 1083, 1, 0) + 1082] >=
                          0.2)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 7, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 107);
            c3_num_acc_02_04++;
          } else {
            guard5 = TRUE;
          }
        } else {
          guard5 = TRUE;
        }

        if (guard5 == TRUE) {
          CV_EML_MCDC(0, 1, 1, FALSE);
          CV_EML_IF(0, 1, 7, FALSE);
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 112);
        c3_d28 = c3_i;
        c3_b_round(chartInstance, &c3_d28);
        guard4 = FALSE;
        if (CV_EML_COND(0, 1, 4, c3_a[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d28), 1, 1083, 1, 0) + 1082] <
                        0.8)) {
          c3_d29 = c3_i;
          c3_b_round(chartInstance, &c3_d29);
          if (CV_EML_COND(0, 1, 5, c3_a[(int32_T)(real_T)
                          _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d29), 1, 1083, 1, 0) + 1082] >=
                          0.6)) {
            CV_EML_MCDC(0, 1, 2, TRUE);
            CV_EML_IF(0, 1, 8, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 113);
            c3_num_acc_06_08++;
          } else {
            guard4 = TRUE;
          }
        } else {
          guard4 = TRUE;
        }

        if (guard4 == TRUE) {
          CV_EML_MCDC(0, 1, 2, FALSE);
          CV_EML_IF(0, 1, 8, FALSE);
        }

        c3_e_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 123);
      c3_k_b = c3_num_acc_02_04;
      c3_t_y = c3_k_b;
      c3_g_A = c3_t_y;
      c3_c_B = c3_num_acc;
      c3_o_x = c3_g_A;
      c3_u_y = c3_c_B;
      c3_p_x = c3_o_x;
      c3_v_y = c3_u_y;
      c3_prc_acc_02_04 = c3_p_x / c3_v_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 125);
      c3_l_b = c3_num_acc_06_08;
      c3_w_y = c3_l_b;
      c3_h_A = c3_w_y;
      c3_d_B = c3_num_acc;
      c3_q_x = c3_h_A;
      c3_x_y = c3_d_B;
      c3_r_x = c3_q_x;
      c3_y_y = c3_x_y;
      c3_prc_acc_06_08 = c3_r_x / c3_y_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 133U);
      c3_f_t = c3_t;
      c3_i16 = (int32_T)c3_f_t;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_f_t, mxDOUBLE_CLASS, c3_i16);
      c3_i = 1.0;
      c3_f_i = 0;
      while (c3_f_i <= c3_i16 - 1) {
        c3_i = 1.0 + (real_T)c3_f_i;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 137U);
        c3_d30 = c3_i;
        c3_b_round(chartInstance, &c3_d30);
        guard3 = FALSE;
        if (CV_EML_COND(0, 1, 6, c3_a[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d30), 1, 1083, 1, 0) + 1082] <
                        -0.2)) {
          c3_d31 = c3_i;
          c3_b_round(chartInstance, &c3_d31);
          if (CV_EML_COND(0, 1, 7, c3_a[(int32_T)(real_T)
                          _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d31), 1, 1083, 1, 0) + 1082] >=
                          -0.4)) {
            CV_EML_MCDC(0, 1, 3, TRUE);
            CV_EML_IF(0, 1, 9, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
            c3_num_dec_02_04++;
          } else {
            guard3 = TRUE;
          }
        } else {
          guard3 = TRUE;
        }

        if (guard3 == TRUE) {
          CV_EML_MCDC(0, 1, 3, FALSE);
          CV_EML_IF(0, 1, 9, FALSE);
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 143U);
        c3_d32 = c3_i;
        c3_b_round(chartInstance, &c3_d32);
        guard2 = FALSE;
        if (CV_EML_COND(0, 1, 8, c3_a[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d32), 1, 1083, 1, 0) + 1082] <
                        -0.6)) {
          c3_d33 = c3_i;
          c3_b_round(chartInstance, &c3_d33);
          if (CV_EML_COND(0, 1, 9, c3_a[(int32_T)(real_T)
                          _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d33), 1, 1083, 1, 0) + 1082] >=
                          -0.8)) {
            CV_EML_MCDC(0, 1, 4, TRUE);
            CV_EML_IF(0, 1, 10, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 144U);
            c3_num_dec_06_08++;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          CV_EML_MCDC(0, 1, 4, FALSE);
          CV_EML_IF(0, 1, 10, FALSE);
        }

        c3_f_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 154U);
      c3_m_b = c3_num_dec_02_04;
      c3_ab_y = c3_m_b;
      c3_i_A = c3_ab_y;
      c3_e_B = c3_num_dec;
      c3_s_x = c3_i_A;
      c3_bb_y = c3_e_B;
      c3_t_x = c3_s_x;
      c3_cb_y = c3_bb_y;
      c3_prc_dec_02_04 = c3_t_x / c3_cb_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 156U);
      c3_n_b = c3_num_dec_06_08;
      c3_db_y = c3_n_b;
      c3_j_A = c3_db_y;
      c3_f_B = c3_num_dec;
      c3_u_x = c3_j_A;
      c3_eb_y = c3_f_B;
      c3_v_x = c3_u_x;
      c3_fb_y = c3_eb_y;
      c3_prc_dec_06_08 = c3_v_x / c3_fb_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 165U);
      c3_g_t = c3_t;
      c3_i17 = (int32_T)c3_g_t;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_g_t, mxDOUBLE_CLASS, c3_i17);
      c3_i = 1.0;
      c3_g_i = 0;
      while (c3_g_i <= c3_i17 - 1) {
        c3_i = 1.0 + (real_T)c3_g_i;
        CV_EML_FOR(0, 1, 5, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 166U);
        c3_d34 = c3_i;
        c3_b_round(chartInstance, &c3_d34);
        guard1 = FALSE;
        if (CV_EML_COND(0, 1, 10, c3_av[(int32_T)(real_T)
                        _SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d34), 1, 1083, 1, 0) + 1082] <
                        5.0)) {
          c3_d35 = c3_i;
          c3_b_round(chartInstance, &c3_d35);
          if (CV_EML_COND(0, 1, 11, c3_av[(int32_T)(real_T)
                          _SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d35), 1, 1083, 1, 0) + 1082] >=
                          0.0)) {
            CV_EML_MCDC(0, 1, 5, TRUE);
            CV_EML_IF(0, 1, 11, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 167U);
            c3_num_av_0_5++;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          CV_EML_MCDC(0, 1, 5, FALSE);
          CV_EML_IF(0, 1, 11, FALSE);
        }

        c3_g_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 5, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 185U);
      c3_o_b = c3_num_av_0_5;
      c3_gb_y = c3_o_b;
      c3_k_A = c3_gb_y;
      c3_g_B = c3_t;
      c3_w_x = c3_k_A;
      c3_hb_y = c3_g_B;
      c3_x_x = c3_w_x;
      c3_ib_y = c3_hb_y;
      c3_prc_av_0_5 = c3_x_x / c3_ib_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 192U);
      c3_l_A = c3_sum_av_p;
      c3_h_B = c3_dist;
      c3_y_x = c3_l_A;
      c3_jb_y = c3_h_B;
      c3_ab_x = c3_y_x;
      c3_kb_y = c3_jb_y;
      c3_lb_y = c3_ab_x / c3_kb_y;
      c3_m_A = c3_lb_y;
      c3_bb_x = c3_m_A;
      c3_cb_x = c3_bb_x;
      c3_rpa = c3_cb_x / 0.2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 196U);
      c3_h_t = c3_t;
      c3_i18 = (int32_T)(c3_h_t + -1.0);
      _SFD_FOR_LOOP_VECTOR_CHECK(2.0, 1.0, c3_h_t, mxDOUBLE_CLASS, c3_i18);
      c3_i = 2.0;
      c3_h_i = 0;
      while (c3_h_i <= c3_i18 - 1) {
        c3_i = 2.0 + (real_T)c3_h_i;
        CV_EML_FOR(0, 1, 6, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 202U);
        c3_d36 = c3_i;
        c3_b_round(chartInstance, &c3_d36);
        if (CV_EML_IF(0, 1, 12, c3_a[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d36), 1, 1083, 1, 0) + 1082] >
                      0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 203U);
          c3_d37 = c3_i;
          c3_b_round(chartInstance, &c3_d37);
          c3_l_a = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)+1", c3_d37 + 1.0), 1, 1082, 1,
            0) + 1081];
          c3_mb_y = c3_l_a * 0.27777777777777779;
          c3_d38 = c3_i;
          c3_b_round(chartInstance, &c3_d38);
          c3_m_a = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d38), 1, 1082, 1, 0) +
            1081];
          c3_nb_y = c3_m_a * 0.27777777777777779;
          c3_pke_1 += c3_mpower(chartInstance, c3_mb_y) - c3_mpower
            (chartInstance, c3_nb_y);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 204U);
          c3_d39 = c3_i;
          c3_b_round(chartInstance, &c3_d39);
          c3_n_a = c3_cyc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d39), 1, 1082, 1, 0) +
            1081];
          c3_ob_y = c3_n_a * 0.27777777777777779;
          c3_o_a = c3_ob_y;
          c3_pb_y = c3_o_a;
          c3_pke_dis += c3_pb_y;
        }

        c3_h_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 6, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 208U);
      c3_n_A = c3_pke_1;
      c3_i_B = c3_pke_dis;
      c3_db_x = c3_n_A;
      c3_qb_y = c3_i_B;
      c3_eb_x = c3_db_x;
      c3_rb_y = c3_qb_y;
      c3_sb_y = c3_eb_x / c3_rb_y;
      c3_o_A = c3_sb_y;
      c3_fb_x = c3_o_A;
      c3_gb_x = c3_fb_x;
      c3_pke = c3_gb_x / 2.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 216U);
      c3_prc_spd_0_10 = c3_mem[0];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 217U);
      c3_prc_spd_20_30 = c3_mem[1];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 218U);
      c3_max_acc = c3_mem[2];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 219U);
      c3_prc_acc_02_04 = c3_mem[3];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 220U);
      c3_prc_acc_06_08 = c3_mem[4];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 221U);
      c3_prc_dec_02_04 = c3_mem[5];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 222U);
      c3_prc_dec_06_08 = c3_mem[6];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 223U);
      c3_rpa = c3_mem[7];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 224U);
      c3_prc_av_0_5 = c3_mem[8];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 225U);
      c3_pke = c3_mem[9];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -225);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_prc_spd_0_10 = c3_prc_spd_0_10;
  *c3_b_prc_spd_20_30 = c3_prc_spd_20_30;
  *c3_b_max_acc = c3_max_acc;
  *c3_b_prc_acc_02_04 = c3_prc_acc_02_04;
  *c3_b_prc_acc_06_08 = c3_prc_acc_06_08;
  *c3_b_prc_dec_02_04 = c3_prc_dec_02_04;
  *c3_b_prc_dec_06_08 = c3_prc_dec_06_08;
  *c3_b_rpa = c3_rpa;
  *c3_b_prc_av_0_5 = c3_prc_av_0_5;
  *c3_b_pke = c3_pke;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_hyd_hyb_2_int_cont_Final
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_pke, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_pke), &c3_thisId);
  sf_mex_destroy(&c3_pke);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d40;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d40, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d40;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_pke;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_pke = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_pke), &c3_thisId);
  sf_mex_destroy(&c3_pke);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i19;
  real_T c3_b_inData[10];
  int32_T c3_i20;
  real_T c3_u[10];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i19 = 0; c3_i19 < 10; c3_i19++) {
    c3_b_inData[c3_i19] = (*(real_T (*)[10])c3_inData)[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 10; c3_i20++) {
    c3_u[c3_i20] = c3_b_inData[c3_i20];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  real_T c3_b_inData[2164];
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_u[2164];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i21 = 0;
  for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
    for (c3_i23 = 0; c3_i23 < 1082; c3_i23++) {
      c3_b_inData[c3_i23 + c3_i21] = (*(real_T (*)[2164])c3_inData)[c3_i23 +
        c3_i21];
    }

    c3_i21 += 1082;
  }

  c3_i24 = 0;
  for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
    for (c3_i26 = 0; c3_i26 < 1082; c3_i26++) {
      c3_u[c3_i26 + c3_i24] = c3_b_inData[c3_i26 + c3_i24];
    }

    c3_i24 += 1082;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1082, 2),
                FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2164])
{
  real_T c3_dv1[2164];
  int32_T c3_i27;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 1082,
                2);
  for (c3_i27 = 0; c3_i27 < 2164; c3_i27++) {
    c3_y[c3_i27] = c3_dv1[c3_i27];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Driving_Cycle;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2164];
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_b_Driving_Cycle = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Driving_Cycle),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Driving_Cycle);
  c3_i28 = 0;
  for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
    for (c3_i30 = 0; c3_i30 < 1082; c3_i30++) {
      (*(real_T (*)[2164])c3_outData)[c3_i30 + c3_i28] = c3_y[c3_i30 + c3_i28];
    }

    c3_i28 += 1082;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  real_T c3_b_inData[2166];
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  real_T c3_u[2166];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i31 = 0;
  for (c3_i32 = 0; c3_i32 < 2; c3_i32++) {
    for (c3_i33 = 0; c3_i33 < 1083; c3_i33++) {
      c3_b_inData[c3_i33 + c3_i31] = (*(real_T (*)[2166])c3_inData)[c3_i33 +
        c3_i31];
    }

    c3_i31 += 1083;
  }

  c3_i34 = 0;
  for (c3_i35 = 0; c3_i35 < 2; c3_i35++) {
    for (c3_i36 = 0; c3_i36 < 1083; c3_i36++) {
      c3_u[c3_i36 + c3_i34] = c3_b_inData[c3_i36 + c3_i34];
    }

    c3_i34 += 1083;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1083, 2),
                FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2166])
{
  real_T c3_dv2[2166];
  int32_T c3_i37;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 1083,
                2);
  for (c3_i37 = 0; c3_i37 < 2166; c3_i37++) {
    c3_y[c3_i37] = c3_dv2[c3_i37];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_av;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2166];
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_av = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_av), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_av);
  c3_i38 = 0;
  for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
    for (c3_i40 = 0; c3_i40 < 1083; c3_i40++) {
      (*(real_T (*)[2166])c3_outData)[c3_i40 + c3_i38] = c3_y[c3_i40 + c3_i38];
    }

    c3_i38 += 1083;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i41;
  real_T c3_b_inData[1083];
  int32_T c3_i42;
  real_T c3_u[1083];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i41 = 0; c3_i41 < 1083; c3_i41++) {
    c3_b_inData[c3_i41] = (*(real_T (*)[1083])c3_inData)[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 1083; c3_i42++) {
    c3_u[c3_i42] = c3_b_inData[c3_i42];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 1083), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[1083])
{
  real_T c3_dv3[1083];
  int32_T c3_i43;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 1083);
  for (c3_i43 = 0; c3_i43 < 1083; c3_i43++) {
    c3_y[c3_i43] = c3_dv3[c3_i43];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_dis;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[1083];
  int32_T c3_i44;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_dis = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dis), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_dis);
  for (c3_i44 = 0; c3_i44 < 1083; c3_i44++) {
    (*(real_T (*)[1083])c3_outData)[c3_i44] = c3_y[c3_i44];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i45;
  real_T c3_b_inData[2];
  int32_T c3_i46;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i45 = 0; c3_i45 < 2; c3_i45++) {
    c3_b_inData[c3_i45] = (*(real_T (*)[2])c3_inData)[c3_i45];
  }

  for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
    c3_u[c3_i46] = c3_b_inData[c3_i46];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_hyd_hyb_2_int_cont_Final_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                FALSE);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rem"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1358177140U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("round"), "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704854U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1307642238U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1373297508U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1319724566U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704880U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704866U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mtimes"), "name", "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704878U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("max"), "name", "name", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1311246316U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704870U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813296U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnan"), "name", "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704858U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813378U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1346501340U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("intmax"), "name", "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1362252882U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_relop"), "name", "name",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1342442182U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mpower"), "name", "name", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704878U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("ismatrix"), "name", "name", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1331295858U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("power"), "name", "name", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704880U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1358177140U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("floor"), "name", "name", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704854U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813326U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mtimes"), "name", "name", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363704878U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
}

static const mxArray *c3_emlrt_marshallOut(char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), FALSE);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c3_y;
}

static real_T c3_rem(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance,
                     real_T c3_x, real_T c3_y)
{
  real_T c3_xk;
  real_T c3_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_xk = c3_x;
  c3_yk = c3_y;
  return muDoubleScalarRem(c3_xk, c3_yk);
}

static void c3_eml_scalar_eg(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance)
{
}

static real_T c3_round(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_round(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_check_forloop_overflow_error
  (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, boolean_T
   c3_overflow)
{
  int32_T c3_i47;
  static char_T c3_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c3_u[34];
  const mxArray *c3_y = NULL;
  int32_T c3_i48;
  static char_T c3_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c3_b_u[23];
  const mxArray *c3_b_y = NULL;
  if (!c3_overflow) {
  } else {
    for (c3_i47 = 0; c3_i47 < 34; c3_i47++) {
      c3_u[c3_i47] = c3_cv0[c3_i47];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c3_i48 = 0; c3_i48 < 23; c3_i48++) {
      c3_b_u[c3_i48] = c3_cv1[c3_i48];
    }

    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c3_y, 14, c3_b_y));
  }
}

static real_T c3_mpower(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_e_a;
  real_T c3_b;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  c3_e_a = c3_d_a;
  c3_b = c3_d_a;
  return c3_e_a * c3_b;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i49;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i49, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i49;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_hyd_hyb_2_int_cont_Final,
  const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_hyd_hyb_2_int_cont_Final), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_hyd_hyb_2_int_cont_Final);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_round(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, real_T *c3_x)
{
  *c3_x = muDoubleScalarRound(*c3_x);
}

static void init_dsm_address_info(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_hyd_hyb_2_int_cont_Final_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2629921259U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2816641958U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(852924678U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1139576951U);
}

mxArray *sf_c3_hyd_hyb_2_int_cont_Final_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sOq59Ex7LlkB3mZSCyNbCD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1082);
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_hyd_hyb_2_int_cont_Final_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_hyd_hyb_2_int_cont_Final_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_Final(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[13],T\"max_acc\",},{M[1],M[20],T\"pke\",},{M[1],M[14],T\"prc_acc_02_04\",},{M[1],M[15],T\"prc_acc_06_08\",},{M[1],M[19],T\"prc_av_0_5\",},{M[1],M[16],T\"prc_dec_02_04\",},{M[1],M[17],T\"prc_dec_06_08\",},{M[1],M[5],T\"prc_spd_0_10\",},{M[1],M[12],T\"prc_spd_20_30\",},{M[1],M[18],T\"rpa\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_hyd_hyb_2_int_cont_Final\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_hyd_hyb_2_int_cont_Final_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
    chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hyd_hyb_2_int_cont_FinalMachineNumber_,
           3,
           1,
           1,
           15,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_hyd_hyb_2_int_cont_FinalMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_hyd_hyb_2_int_cont_FinalMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _hyd_hyb_2_int_cont_FinalMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"prc_spd_0_10");
          _SFD_SET_DATA_PROPS(2,10,0,0,"Driving_Cycle");
          _SFD_SET_DATA_PROPS(3,10,0,0,"T0");
          _SFD_SET_DATA_PROPS(4,10,0,0,"T1");
          _SFD_SET_DATA_PROPS(5,2,0,1,"prc_spd_20_30");
          _SFD_SET_DATA_PROPS(6,2,0,1,"max_acc");
          _SFD_SET_DATA_PROPS(7,2,0,1,"prc_acc_02_04");
          _SFD_SET_DATA_PROPS(8,2,0,1,"prc_acc_06_08");
          _SFD_SET_DATA_PROPS(9,2,0,1,"prc_dec_02_04");
          _SFD_SET_DATA_PROPS(10,2,0,1,"prc_dec_06_08");
          _SFD_SET_DATA_PROPS(11,2,0,1,"rpa");
          _SFD_SET_DATA_PROPS(12,2,0,1,"prc_av_0_5");
          _SFD_SET_DATA_PROPS(13,2,0,1,"pke");
          _SFD_SET_DATA_PROPS(14,1,1,0,"mem");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,13,0,0,0,7,0,12,6);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,9230);
        _SFD_CV_INIT_EML_IF(0,1,0,1262,1270,-1,9226);
        _SFD_CV_INIT_EML_IF(0,1,1,1292,1299,8931,9214);
        _SFD_CV_INIT_EML_IF(0,1,2,1407,1420,-1,1558);
        _SFD_CV_INIT_EML_IF(0,1,3,1575,1593,-1,1868);
        _SFD_CV_INIT_EML_IF(0,1,4,1885,1903,-1,2013);
        _SFD_CV_INIT_EML_IF(0,1,5,2407,2428,-1,2497);
        _SFD_CV_INIT_EML_IF(0,1,6,2638,2682,-1,2753);
        _SFD_CV_INIT_EML_IF(0,1,7,4146,4188,-1,4259);
        _SFD_CV_INIT_EML_IF(0,1,8,4398,4440,-1,4511);
        _SFD_CV_INIT_EML_IF(0,1,9,5532,5576,-1,5647);
        _SFD_CV_INIT_EML_IF(0,1,10,5788,5832,-1,5903);
        _SFD_CV_INIT_EML_IF(0,1,11,6830,6870,-1,6935);
        _SFD_CV_INIT_EML_IF(0,1,12,8353,8371,-1,8554);
        _SFD_CV_INIT_EML_FOR(0,1,0,1332,1342,2186);
        _SFD_CV_INIT_EML_FOR(0,1,1,2381,2391,3126);
        _SFD_CV_INIT_EML_FOR(0,1,2,3679,3689,3803);
        _SFD_CV_INIT_EML_FOR(0,1,3,4003,4013,4749);
        _SFD_CV_INIT_EML_FOR(0,1,4,5387,5397,6143);
        _SFD_CV_INIT_EML_FOR(0,1,5,6804,6814,7514);
        _SFD_CV_INIT_EML_FOR(0,1,6,8161,8171,8570);

        {
          static int condStart[] = { 2641, 2663 };

          static int condEnd[] = { 2659, 2682 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,2641,2682,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4149, 4170 };

          static int condEnd[] = { 4166, 4188 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,4149,4188,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4401, 4422 };

          static int condEnd[] = { 4418, 4440 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,4401,4440,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5535, 5557 };

          static int condEnd[] = { 5553, 5576 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,5535,5576,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5791, 5813 };

          static int condEnd[] = { 5809, 5832 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,5791,5832,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6833, 6853 };

          static int condEnd[] = { 6849, 6870 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,5,6833,6870,2,10,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1082;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c3_t;
          real_T *c3_prc_spd_0_10;
          real_T *c3_prc_spd_20_30;
          real_T *c3_max_acc;
          real_T *c3_prc_acc_02_04;
          real_T *c3_prc_acc_06_08;
          real_T *c3_prc_dec_02_04;
          real_T *c3_prc_dec_06_08;
          real_T *c3_rpa;
          real_T *c3_prc_av_0_5;
          real_T *c3_pke;
          real_T (*c3_mem)[10];
          c3_mem = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
          c3_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c3_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c3_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c3_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c3_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c3_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_t);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_prc_spd_0_10);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_Driving_Cycle);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c3_T0);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c3_T1);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_prc_spd_20_30);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_max_acc);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_prc_acc_02_04);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_prc_acc_06_08);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_prc_dec_02_04);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_prc_dec_06_08);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_rpa);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_prc_av_0_5);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_pke);
          _SFD_SET_DATA_VALUE_PTR(14U, *c3_mem);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _hyd_hyb_2_int_cont_FinalMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3eFmekpXcSlzk3H2lrXz6C";
}

static void sf_opaque_initialize_c3_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
  initialize_c3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_hyd_hyb_2_int_cont_Final(void *chartInstanceVar)
{
  enable_c3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_hyd_hyb_2_int_cont_Final(void *chartInstanceVar)
{
  disable_c3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_hyd_hyb_2_int_cont_Final(void *chartInstanceVar)
{
  sf_c3_hyd_hyb_2_int_cont_Final((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_hyd_hyb_2_int_cont_Final
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_Final();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_hyd_hyb_2_int_cont_Final(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_Final();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_hyd_hyb_2_int_cont_Final
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_hyd_hyb_2_int_cont_Final(S);
}

static void sf_opaque_set_sim_state_c3_hyd_hyb_2_int_cont_Final(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_hyd_hyb_2_int_cont_Final(S, st);
}

static void sf_opaque_terminate_c3_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hyd_hyb_2_int_cont_Final_optimization_info();
    }

    finalize_c3_hyd_hyb_2_int_cont_Final
      ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_hyd_hyb_2_int_cont_Final
    ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_hyd_hyb_2_int_cont_Final
      ((SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  /* Actual parameters from chart:
     Driving_Cycle T0 T1
   */
  const char_T *rtParamNames[] = { "Driving_Cycle", "T0", "T1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Driving_Cycle*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hyd_hyb_2_int_cont_Final_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,10);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=10; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3449097755U));
  ssSetChecksum1(S,(1877726528U));
  ssSetChecksum2(S,(1590846642U));
  ssSetChecksum3(S,(3906540727U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct *)utMalloc(sizeof
    (SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_hyd_hyb_2_int_cont_FinalInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_hyd_hyb_2_int_cont_Final_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_hyd_hyb_2_int_cont_Final(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_hyd_hyb_2_int_cont_Final(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_hyd_hyb_2_int_cont_Final(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_hyd_hyb_2_int_cont_Final_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
