/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new3_5cyc_axor_sfun.h"
#include "c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new3_5cyc_axor_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

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
static void initialize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void initialize_params_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void enable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void disable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_st);
static void finalize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void c3_chartstep_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void initSimStructsc3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_pke, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2400]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2402]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[1201]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[22]);
static real_T c3_rem(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
                     *chartInstance, real_T c3_x, real_T c3_y);
static void c3_eml_scalar_eg
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);
static real_T c3_round(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
  *chartInstance, real_T c3_x);
static real_T c3_max(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
                     *chartInstance, real_T c3_varargin_1[1201]);
static real_T c3_mpower(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
  *chartInstance, real_T c3_a);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_b_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor, const char_T *
   c3_identifier);
static uint8_T c3_h_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_round(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
  *chartInstance, real_T *c3_x);
static void init_dsm_address_info
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor = 0U;
}

static void initialize_params_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
  real_T c3_dv0[2400];
  int32_T c3_i0;
  real_T c3_d0;
  real_T c3_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'Driving_Cycle' in the parent workspace.\n");
  sf_mex_import_named("Driving_Cycle", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), c3_dv0, 0, 0, 0U, 1, 0U, 2, 1200, 2);
  for (c3_i0 = 0; c3_i0 < 2400; c3_i0++) {
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

static void enable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
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
  sf_mex_assign(&c3_y, sf_mex_createcellarray(11));
  c3_hoistedGlobal = *c3_max_acc;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_pke;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_prc_acc_02_04;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_prc_acc_06_08;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_prc_av_0_5;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_prc_dec_02_04;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *c3_prc_dec_06_08;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *c3_prc_spd_0_10;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *c3_prc_spd_20_30;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *c3_rpa;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal =
    chartInstance->c3_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 10, c3_l_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_st)
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
  chartInstance->c3_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor =
    c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 10)),
    "is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
}

static void sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
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
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_prc_spd_0_10, 1U);
  for (c3_i1 = 0; c3_i1 < 2400; c3_i1++) {
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
  c3_chartstep_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new3_5cyc_axorMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_t;
  int32_T c3_i3;
  real_T c3_b_Driving_Cycle[2400];
  real_T c3_b_T0;
  real_T c3_b_T1;
  int32_T c3_i4;
  real_T c3_mem[10];
  uint32_T c3_debug_family_var_map[42];
  real_T c3_cyc[2400];
  real_T c3_h[2];
  real_T c3_cyc_tim;
  real_T c3_sum_spd;
  real_T c3_a[2402];
  real_T c3_sum_acc;
  real_T c3_sum_dec;
  real_T c3_dis[1201];
  real_T c3_dist;
  real_T c3_num_acc;
  real_T c3_num_dec;
  real_T c3_av[2402];
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
  real_T c3_loop_ub;
  real_T c3_b_i;
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
  real_T c3_c_x;
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
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_i_y;
  real_T c3_h_a;
  real_T c3_d_b;
  real_T c3_j_y;
  real_T c3_d18;
  real_T c3_d19;
  real_T c3_b_loop_ub;
  real_T c3_c_i;
  real_T c3_d20;
  real_T c3_d21;
  real_T c3_d22;
  real_T c3_e_b;
  real_T c3_k_y;
  real_T c3_c_A;
  real_T c3_B;
  real_T c3_g_x;
  real_T c3_l_y;
  real_T c3_h_x;
  real_T c3_m_y;
  real_T c3_i_x;
  real_T c3_n_y;
  real_T c3_f_b;
  real_T c3_o_y;
  real_T c3_d_A;
  real_T c3_b_B;
  real_T c3_j_x;
  real_T c3_p_y;
  real_T c3_k_x;
  real_T c3_q_y;
  real_T c3_l_x;
  real_T c3_r_y;
  real_T c3_c_loop_ub;
  real_T c3_d_i;
  real_T c3_d23;
  real_T c3_g_b;
  real_T c3_s_y;
  real_T c3_i_a;
  real_T c3_t_y;
  real_T c3_e_A;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_u_y;
  real_T c3_d24;
  real_T c3_d25;
  int32_T c3_i10;
  real_T c3_j_a[1201];
  real_T c3_f_A;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_d_loop_ub;
  real_T c3_e_i;
  real_T c3_d26;
  real_T c3_d27;
  real_T c3_d28;
  real_T c3_d29;
  real_T c3_h_b;
  real_T c3_v_y;
  real_T c3_g_A;
  real_T c3_c_B;
  real_T c3_s_x;
  real_T c3_w_y;
  real_T c3_t_x;
  real_T c3_x_y;
  real_T c3_u_x;
  real_T c3_y_y;
  real_T c3_i_b;
  real_T c3_ab_y;
  real_T c3_h_A;
  real_T c3_d_B;
  real_T c3_v_x;
  real_T c3_bb_y;
  real_T c3_w_x;
  real_T c3_cb_y;
  real_T c3_x_x;
  real_T c3_db_y;
  real_T c3_e_loop_ub;
  real_T c3_f_i;
  real_T c3_d30;
  real_T c3_d31;
  real_T c3_d32;
  real_T c3_d33;
  real_T c3_j_b;
  real_T c3_eb_y;
  real_T c3_i_A;
  real_T c3_e_B;
  real_T c3_y_x;
  real_T c3_fb_y;
  real_T c3_ab_x;
  real_T c3_gb_y;
  real_T c3_bb_x;
  real_T c3_hb_y;
  real_T c3_k_b;
  real_T c3_ib_y;
  real_T c3_j_A;
  real_T c3_f_B;
  real_T c3_cb_x;
  real_T c3_jb_y;
  real_T c3_db_x;
  real_T c3_kb_y;
  real_T c3_eb_x;
  real_T c3_lb_y;
  real_T c3_f_loop_ub;
  real_T c3_g_i;
  real_T c3_d34;
  real_T c3_d35;
  real_T c3_l_b;
  real_T c3_mb_y;
  real_T c3_k_A;
  real_T c3_g_B;
  real_T c3_fb_x;
  real_T c3_nb_y;
  real_T c3_gb_x;
  real_T c3_ob_y;
  real_T c3_hb_x;
  real_T c3_pb_y;
  real_T c3_l_A;
  real_T c3_h_B;
  real_T c3_ib_x;
  real_T c3_qb_y;
  real_T c3_jb_x;
  real_T c3_rb_y;
  real_T c3_kb_x;
  real_T c3_sb_y;
  real_T c3_tb_y;
  real_T c3_m_A;
  real_T c3_lb_x;
  real_T c3_mb_x;
  real_T c3_nb_x;
  real_T c3_g_loop_ub;
  real_T c3_h_i;
  real_T c3_d36;
  real_T c3_d37;
  real_T c3_k_a;
  real_T c3_ub_y;
  real_T c3_d38;
  real_T c3_l_a;
  real_T c3_vb_y;
  real_T c3_d39;
  real_T c3_m_a;
  real_T c3_wb_y;
  real_T c3_n_a;
  real_T c3_xb_y;
  real_T c3_n_A;
  real_T c3_i_B;
  real_T c3_ob_x;
  real_T c3_yb_y;
  real_T c3_pb_x;
  real_T c3_ac_y;
  real_T c3_qb_x;
  real_T c3_bc_y;
  real_T c3_cc_y;
  real_T c3_o_A;
  real_T c3_rb_x;
  real_T c3_sb_x;
  real_T c3_tb_x;
  real_T *c3_b_t;
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
  c3_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_t;
  c3_b_hoistedGlobal = chartInstance->c3_T0;
  c3_c_hoistedGlobal = chartInstance->c3_T1;
  c3_t = c3_hoistedGlobal;
  for (c3_i3 = 0; c3_i3 < 2400; c3_i3++) {
    c3_b_Driving_Cycle[c3_i3] = chartInstance->c3_Driving_Cycle[c3_i3];
  }

  c3_b_T0 = c3_b_hoistedGlobal;
  c3_b_T1 = c3_c_hoistedGlobal;
  for (c3_i4 = 0; c3_i4 < 10; c3_i4++) {
    c3_mem[c3_i4] = (*c3_b_mem)[c3_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 42U, 42U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c3_cyc, 0U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_h, 1U, c3_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_cyc_tim, 2U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_sum_spd, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_a, 4U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sum_acc, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sum_dec, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_dis, 7U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dist, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_acc, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_dec, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_av, 11U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sum_av, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sum_av_p, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_pke_1, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_pke_dis, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_spd_0_10, 16U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_spd_20_30, 17U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_acc_02_04, 18U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_acc_06_08, 19U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_dec_02_04, 20U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_dec_06_08, 21U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num_av_0_5, 22U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_r, 23U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_i, 24U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 25U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 26U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_t, 27U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_b_Driving_Cycle, 28U,
    c3_c_sf_marshallOut, c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b_T0, 29U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b_T1, 30U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_mem, 31U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_spd_0_10, 32U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_spd_20_30, 33U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_max_acc, 34U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_acc_02_04, 35U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_acc_06_08, 36U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_dec_02_04, 37U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_dec_06_08, 38U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_rpa, 39U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_av_0_5, 40U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_pke, 41U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i5 = 0; c3_i5 < 2400; c3_i5++) {
    c3_cyc[c3_i5] = c3_b_Driving_Cycle[c3_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_h[c3_i6] = 1200.0 + -1198.0 * (real_T)c3_i6;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_cyc_tim = 1201.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sum_spd = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i7 = 0; c3_i7 < 2402; c3_i7++) {
    c3_a[c3_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sum_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sum_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i8 = 0; c3_i8 < 1201; c3_i8++) {
    c3_dis[c3_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_dist = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_num_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_num_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i9 = 0; c3_i9 < 2402; c3_i9++) {
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
  if (CV_EML_IF(0, 0, c3_t >= c3_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
    c3_r = c3_rem(chartInstance, c3_t, c3_b_T1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
    if (CV_EML_IF(0, 1, c3_r == 0.0)) {
      c3_i = 1.0;
      c3_loop_ub = c3_t;
      c3_b_i = 1.0;
      while (c3_b_i <= c3_loop_ub) {
        c3_i = c3_b_i;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
        c3_d2 = c3_i;
        c3_b_round(chartInstance, &c3_d2);
        c3_sum_spd += c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d2), 1, 1200, 1, 0) + 1199];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
        c3_d3 = c3_i;
        c3_b_round(chartInstance, &c3_d3);
        if (CV_EML_IF(0, 2, c3_d3 > 1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
          c3_d4 = c3_i;
          c3_b_round(chartInstance, &c3_d4);
          c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK("i",
            c3_i), 1, 1201, 1, 0) - 1] = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "cyc", (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d4), 1, 1200, 1, 0)
            - 1];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
          c3_d5 = c3_i;
          c3_b_round(chartInstance, &c3_d5);
          c3_d6 = c3_i;
          c3_b_round(chartInstance, &c3_d6);
          c3_b_a = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d5), 1, 1200, 1, 0) + 1199] -
            c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)-1", c3_d6 - 1.0), 1, 1200, 1, 0) + 1199];
          c3_y = c3_b_a * 0.27777777777777779;
          c3_A = c3_y;
          c3_x = c3_A;
          c3_b_x = c3_x;
          c3_c_x = c3_b_x;
          c3_b_y = c3_c_x;
          c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK("i",
            c3_i), 1, 1201, 1, 0) + 1200] = c3_b_y;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
        c3_d7 = c3_i;
        c3_b_round(chartInstance, &c3_d7);
        if (CV_EML_IF(0, 3, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d7), 1, 1201, 1, 0) + 1200] >
                      0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
          c3_num_acc++;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
          c3_d8 = c3_i;
          c3_b_round(chartInstance, &c3_d8);
          c3_sum_acc += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d8), 1, 1201, 1, 0) + 1200];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
          c3_d9 = c3_i;
          c3_b_round(chartInstance, &c3_d9);
          c3_c_a = c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d9), 1, 1201, 1, 0) + 1200];
          c3_d10 = c3_i;
          c3_b_round(chartInstance, &c3_d10);
          c3_b = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d10), 1, 1200, 1, 0) + 1199];
          c3_c_y = c3_c_a * c3_b;
          c3_d_a = c3_c_y;
          c3_d_y = c3_d_a * 0.27777777777777779;
          c3_d11 = c3_i;
          c3_b_round(chartInstance, &c3_d11);
          c3_e_a = c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("round(i)+1", c3_d11 + 1.0), 1, 1201, 1, 0) +
            1200];
          c3_d12 = c3_i;
          c3_b_round(chartInstance, &c3_d12);
          c3_b_b = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)+1", c3_d12 + 1.0), 1, 1200, 1, 0) +
            1199];
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
        if (CV_EML_IF(0, 4, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d13), 1, 1201, 1, 0) + 1200] <
                      0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
          c3_num_dec++;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
          c3_d14 = c3_i;
          c3_b_round(chartInstance, &c3_d14);
          c3_sum_dec += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d14), 1, 1201, 1, 0) + 1200];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
        c3_d15 = c3_i;
        c3_b_round(chartInstance, &c3_d15);
        c3_d16 = c3_i;
        c3_b_round(chartInstance, &c3_d16);
        c3_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)_SFD_INTEGER_CHECK(
          "round(i)", c3_d16), 1, 1201, 1, 0) - 1] =
          c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)_SFD_INTEGER_CHECK(
          "round(i)", c3_d15), 1, 1200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
        c3_d17 = c3_i;
        c3_b_round(chartInstance, &c3_d17);
        c3_g_a = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d17), 1, 1200, 1, 0) + 1199];
        c3_h_y = c3_g_a * 10.0;
        c3_b_A = c3_h_y;
        c3_d_x = c3_b_A;
        c3_e_x = c3_d_x;
        c3_f_x = c3_e_x;
        c3_i_y = c3_f_x / 36.0;
        c3_h_a = c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
          _SFD_INTEGER_CHECK("i", c3_i), 1, 1201, 1, 0) + 1200];
        c3_d_b = c3_i_y;
        c3_j_y = c3_h_a * c3_d_b;
        c3_d18 = c3_i;
        c3_b_round(chartInstance, &c3_d18);
        c3_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)_SFD_INTEGER_CHECK(
          "round(i)", c3_d18), 1, 1201, 1, 0) + 1200] = c3_j_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
        c3_d19 = c3_i;
        c3_b_round(chartInstance, &c3_d19);
        c3_sum_av += c3_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d19), 1, 1201, 1, 0) + 1200];
        c3_b_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 0, 0);
      c3_i = 1.0;
      c3_b_loop_ub = c3_t;
      c3_c_i = 1.0;
      while (c3_c_i <= c3_b_loop_ub) {
        c3_i = c3_c_i;
        CV_EML_FOR(0, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
        c3_d20 = c3_i;
        c3_b_round(chartInstance, &c3_d20);
        if (CV_EML_IF(0, 5, c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d20), 1, 1200, 1, 0) + 1199] <
                      10.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
          c3_num_spd_0_10++;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
        c3_d21 = c3_i;
        c3_b_round(chartInstance, &c3_d21);
        guard6 = FALSE;
        if (CV_EML_COND(0, 0, c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d21), 1, 1200, 1, 0) + 1199] <
                        30.0)) {
          c3_d22 = c3_i;
          c3_b_round(chartInstance, &c3_d22);
          if (CV_EML_COND(0, 1, c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
                (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d22), 1, 1200, 1, 0)
                          + 1199] >= 20.0)) {
            CV_EML_MCDC(0, 0, TRUE);
            CV_EML_IF(0, 6, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 73);
            c3_num_spd_20_30++;
          } else {
            guard6 = TRUE;
          }
        } else {
          guard6 = TRUE;
        }

        if (guard6 == TRUE) {
          CV_EML_MCDC(0, 0, FALSE);
          CV_EML_IF(0, 6, FALSE);
        }

        c3_c_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
      c3_e_b = c3_num_spd_0_10;
      c3_k_y = c3_e_b;
      c3_c_A = c3_k_y;
      c3_B = c3_t;
      c3_g_x = c3_c_A;
      c3_l_y = c3_B;
      c3_h_x = c3_g_x;
      c3_m_y = c3_l_y;
      c3_i_x = c3_h_x;
      c3_n_y = c3_m_y;
      c3_prc_spd_0_10 = c3_i_x / c3_n_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 87);
      c3_f_b = c3_num_spd_20_30;
      c3_o_y = c3_f_b;
      c3_d_A = c3_o_y;
      c3_b_B = c3_t;
      c3_j_x = c3_d_A;
      c3_p_y = c3_b_B;
      c3_k_x = c3_j_x;
      c3_q_y = c3_p_y;
      c3_l_x = c3_k_x;
      c3_r_y = c3_q_y;
      c3_prc_spd_20_30 = c3_l_x / c3_r_y;
      c3_i = 1.0;
      c3_c_loop_ub = c3_t;
      c3_d_i = 1.0;
      while (c3_d_i <= c3_c_loop_ub) {
        c3_i = c3_d_i;
        CV_EML_FOR(0, 2, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 95);
        c3_d23 = c3_i;
        c3_b_round(chartInstance, &c3_d23);
        c3_g_b = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d23), 1, 1200, 1, 0) + 1199];
        c3_s_y = c3_g_b;
        c3_i_a = c3_s_y;
        c3_t_y = c3_i_a * 10.0;
        c3_e_A = c3_t_y;
        c3_m_x = c3_e_A;
        c3_n_x = c3_m_x;
        c3_o_x = c3_n_x;
        c3_u_y = c3_o_x / 36.0;
        c3_d24 = c3_i;
        c3_b_round(chartInstance, &c3_d24);
        c3_dis[_SFD_EML_ARRAY_BOUNDS_CHECK("dis", (int32_T)_SFD_INTEGER_CHECK(
          "round(i)", c3_d24), 1, 1201, 1, 0) - 1] = c3_u_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
        c3_d25 = c3_i;
        c3_b_round(chartInstance, &c3_d25);
        c3_dist += c3_dis[_SFD_EML_ARRAY_BOUNDS_CHECK("dis", (int32_T)
          _SFD_INTEGER_CHECK("round(i)", c3_d25), 1, 1201, 1, 0) - 1];
        c3_d_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 2, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 101);
      for (c3_i10 = 0; c3_i10 < 1201; c3_i10++) {
        c3_j_a[c3_i10] = c3_a[c3_i10 + 1201];
      }

      c3_f_A = c3_max(chartInstance, c3_j_a);
      c3_p_x = c3_f_A;
      c3_q_x = c3_p_x;
      c3_r_x = c3_q_x;
      c3_max_acc = c3_r_x / 6.0;
      c3_i = 1.0;
      c3_d_loop_ub = c3_t;
      c3_e_i = 1.0;
      while (c3_e_i <= c3_d_loop_ub) {
        c3_i = c3_e_i;
        CV_EML_FOR(0, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 106);
        c3_d26 = c3_i;
        c3_b_round(chartInstance, &c3_d26);
        guard5 = FALSE;
        if (CV_EML_COND(0, 2, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d26), 1, 1201, 1, 0) + 1200] <
                        0.4)) {
          c3_d27 = c3_i;
          c3_b_round(chartInstance, &c3_d27);
          if (CV_EML_COND(0, 3, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d27), 1, 1201, 1, 0) + 1200] >=
                          0.2)) {
            CV_EML_MCDC(0, 1, TRUE);
            CV_EML_IF(0, 7, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 107);
            c3_num_acc_02_04++;
          } else {
            guard5 = TRUE;
          }
        } else {
          guard5 = TRUE;
        }

        if (guard5 == TRUE) {
          CV_EML_MCDC(0, 1, FALSE);
          CV_EML_IF(0, 7, FALSE);
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 112);
        c3_d28 = c3_i;
        c3_b_round(chartInstance, &c3_d28);
        guard4 = FALSE;
        if (CV_EML_COND(0, 4, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d28), 1, 1201, 1, 0) + 1200] <
                        0.8)) {
          c3_d29 = c3_i;
          c3_b_round(chartInstance, &c3_d29);
          if (CV_EML_COND(0, 5, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d29), 1, 1201, 1, 0) + 1200] >=
                          0.6)) {
            CV_EML_MCDC(0, 2, TRUE);
            CV_EML_IF(0, 8, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 113);
            c3_num_acc_06_08++;
          } else {
            guard4 = TRUE;
          }
        } else {
          guard4 = TRUE;
        }

        if (guard4 == TRUE) {
          CV_EML_MCDC(0, 2, FALSE);
          CV_EML_IF(0, 8, FALSE);
        }

        c3_e_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 3, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 123);
      c3_h_b = c3_num_acc_02_04;
      c3_v_y = c3_h_b;
      c3_g_A = c3_v_y;
      c3_c_B = c3_num_acc;
      c3_s_x = c3_g_A;
      c3_w_y = c3_c_B;
      c3_t_x = c3_s_x;
      c3_x_y = c3_w_y;
      c3_u_x = c3_t_x;
      c3_y_y = c3_x_y;
      c3_prc_acc_02_04 = c3_u_x / c3_y_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 125);
      c3_i_b = c3_num_acc_06_08;
      c3_ab_y = c3_i_b;
      c3_h_A = c3_ab_y;
      c3_d_B = c3_num_acc;
      c3_v_x = c3_h_A;
      c3_bb_y = c3_d_B;
      c3_w_x = c3_v_x;
      c3_cb_y = c3_bb_y;
      c3_x_x = c3_w_x;
      c3_db_y = c3_cb_y;
      c3_prc_acc_06_08 = c3_x_x / c3_db_y;
      c3_i = 1.0;
      c3_e_loop_ub = c3_t;
      c3_f_i = 1.0;
      while (c3_f_i <= c3_e_loop_ub) {
        c3_i = c3_f_i;
        CV_EML_FOR(0, 4, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 137U);
        c3_d30 = c3_i;
        c3_b_round(chartInstance, &c3_d30);
        guard3 = FALSE;
        if (CV_EML_COND(0, 6, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d30), 1, 1201, 1, 0) + 1200] <
                        -0.2)) {
          c3_d31 = c3_i;
          c3_b_round(chartInstance, &c3_d31);
          if (CV_EML_COND(0, 7, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d31), 1, 1201, 1, 0) + 1200] >=
                          -0.4)) {
            CV_EML_MCDC(0, 3, TRUE);
            CV_EML_IF(0, 9, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
            c3_num_dec_02_04++;
          } else {
            guard3 = TRUE;
          }
        } else {
          guard3 = TRUE;
        }

        if (guard3 == TRUE) {
          CV_EML_MCDC(0, 3, FALSE);
          CV_EML_IF(0, 9, FALSE);
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 143U);
        c3_d32 = c3_i;
        c3_b_round(chartInstance, &c3_d32);
        guard2 = FALSE;
        if (CV_EML_COND(0, 8, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d32), 1, 1201, 1, 0) + 1200] <
                        -0.6)) {
          c3_d33 = c3_i;
          c3_b_round(chartInstance, &c3_d33);
          if (CV_EML_COND(0, 9, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("round(i)", c3_d33), 1, 1201, 1, 0) + 1200] >=
                          -0.8)) {
            CV_EML_MCDC(0, 4, TRUE);
            CV_EML_IF(0, 10, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 144U);
            c3_num_dec_06_08++;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          CV_EML_MCDC(0, 4, FALSE);
          CV_EML_IF(0, 10, FALSE);
        }

        c3_f_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 4, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 154U);
      c3_j_b = c3_num_dec_02_04;
      c3_eb_y = c3_j_b;
      c3_i_A = c3_eb_y;
      c3_e_B = c3_num_dec;
      c3_y_x = c3_i_A;
      c3_fb_y = c3_e_B;
      c3_ab_x = c3_y_x;
      c3_gb_y = c3_fb_y;
      c3_bb_x = c3_ab_x;
      c3_hb_y = c3_gb_y;
      c3_prc_dec_02_04 = c3_bb_x / c3_hb_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 156U);
      c3_k_b = c3_num_dec_06_08;
      c3_ib_y = c3_k_b;
      c3_j_A = c3_ib_y;
      c3_f_B = c3_num_dec;
      c3_cb_x = c3_j_A;
      c3_jb_y = c3_f_B;
      c3_db_x = c3_cb_x;
      c3_kb_y = c3_jb_y;
      c3_eb_x = c3_db_x;
      c3_lb_y = c3_kb_y;
      c3_prc_dec_06_08 = c3_eb_x / c3_lb_y;
      c3_i = 1.0;
      c3_f_loop_ub = c3_t;
      c3_g_i = 1.0;
      while (c3_g_i <= c3_f_loop_ub) {
        c3_i = c3_g_i;
        CV_EML_FOR(0, 5, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 166U);
        c3_d34 = c3_i;
        c3_b_round(chartInstance, &c3_d34);
        guard1 = FALSE;
        if (CV_EML_COND(0, 10, c3_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d34), 1, 1201, 1, 0) + 1200] <
                        5.0)) {
          c3_d35 = c3_i;
          c3_b_round(chartInstance, &c3_d35);
          if (CV_EML_COND(0, 11, c3_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av",
                (int32_T)_SFD_INTEGER_CHECK("round(i)", c3_d35), 1, 1201, 1, 0)
                          + 1200] >= 0.0)) {
            CV_EML_MCDC(0, 5, TRUE);
            CV_EML_IF(0, 11, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 167U);
            c3_num_av_0_5++;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          CV_EML_MCDC(0, 5, FALSE);
          CV_EML_IF(0, 11, FALSE);
        }

        c3_g_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 5, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 185U);
      c3_l_b = c3_num_av_0_5;
      c3_mb_y = c3_l_b;
      c3_k_A = c3_mb_y;
      c3_g_B = c3_t;
      c3_fb_x = c3_k_A;
      c3_nb_y = c3_g_B;
      c3_gb_x = c3_fb_x;
      c3_ob_y = c3_nb_y;
      c3_hb_x = c3_gb_x;
      c3_pb_y = c3_ob_y;
      c3_prc_av_0_5 = c3_hb_x / c3_pb_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 192U);
      c3_l_A = c3_sum_av_p;
      c3_h_B = c3_dist;
      c3_ib_x = c3_l_A;
      c3_qb_y = c3_h_B;
      c3_jb_x = c3_ib_x;
      c3_rb_y = c3_qb_y;
      c3_kb_x = c3_jb_x;
      c3_sb_y = c3_rb_y;
      c3_tb_y = c3_kb_x / c3_sb_y;
      c3_m_A = c3_tb_y;
      c3_lb_x = c3_m_A;
      c3_mb_x = c3_lb_x;
      c3_nb_x = c3_mb_x;
      c3_rpa = c3_nb_x / 0.2;
      c3_i = 2.0;
      c3_g_loop_ub = c3_t;
      c3_h_i = 2.0;
      while (c3_h_i <= c3_g_loop_ub) {
        c3_i = c3_h_i;
        CV_EML_FOR(0, 6, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 202U);
        c3_d36 = c3_i;
        c3_b_round(chartInstance, &c3_d36);
        if (CV_EML_IF(0, 12, c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("round(i)", c3_d36), 1, 1201, 1, 0) + 1200] >
                      0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 203U);
          c3_d37 = c3_i;
          c3_b_round(chartInstance, &c3_d37);
          c3_k_a = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)+1", c3_d37 + 1.0), 1, 1200, 1, 0) +
            1199];
          c3_ub_y = c3_k_a * 0.27777777777777779;
          c3_d38 = c3_i;
          c3_b_round(chartInstance, &c3_d38);
          c3_l_a = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d38), 1, 1200, 1, 0) + 1199];
          c3_vb_y = c3_l_a * 0.27777777777777779;
          c3_pke_1 += c3_mpower(chartInstance, c3_ub_y) - c3_mpower
            (chartInstance, c3_vb_y);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 204U);
          c3_d39 = c3_i;
          c3_b_round(chartInstance, &c3_d39);
          c3_m_a = c3_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("round(i)", c3_d39), 1, 1200, 1, 0) + 1199];
          c3_wb_y = c3_m_a * 0.27777777777777779;
          c3_n_a = c3_wb_y;
          c3_xb_y = c3_n_a;
          c3_pke_dis += c3_xb_y;
        }

        c3_h_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 6, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 208U);
      c3_n_A = c3_pke_1;
      c3_i_B = c3_pke_dis;
      c3_ob_x = c3_n_A;
      c3_yb_y = c3_i_B;
      c3_pb_x = c3_ob_x;
      c3_ac_y = c3_yb_y;
      c3_qb_x = c3_pb_x;
      c3_bc_y = c3_ac_y;
      c3_cc_y = c3_qb_x / c3_bc_y;
      c3_o_A = c3_cc_y;
      c3_rb_x = c3_o_A;
      c3_sb_x = c3_rb_x;
      c3_tb_x = c3_sb_x;
      c3_pke = c3_tb_x / 2.0;
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
  sf_debug_symbol_scope_pop();
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

static void initSimStructsc3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
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
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_pke, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_pke), &c3_thisId);
  sf_mex_destroy(&c3_pke);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
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
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
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
  int32_T c3_i11;
  real_T c3_b_inData[10];
  int32_T c3_i12;
  real_T c3_u[10];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i11 = 0; c3_i11 < 10; c3_i11++) {
    c3_b_inData[c3_i11] = (*(real_T (*)[10])c3_inData)[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 10; c3_i12++) {
    c3_u[c3_i12] = c3_b_inData[c3_i12];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 10));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  real_T c3_b_inData[2400];
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  real_T c3_u[2400];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i13 = 0;
  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    for (c3_i15 = 0; c3_i15 < 1200; c3_i15++) {
      c3_b_inData[c3_i15 + c3_i13] = (*(real_T (*)[2400])c3_inData)[c3_i15 +
        c3_i13];
    }

    c3_i13 += 1200;
  }

  c3_i16 = 0;
  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    for (c3_i18 = 0; c3_i18 < 1200; c3_i18++) {
      c3_u[c3_i18 + c3_i16] = c3_b_inData[c3_i18 + c3_i16];
    }

    c3_i16 += 1200;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1200, 2));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2400])
{
  real_T c3_dv1[2400];
  int32_T c3_i19;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 1200,
                2);
  for (c3_i19 = 0; c3_i19 < 2400; c3_i19++) {
    c3_y[c3_i19] = c3_dv1[c3_i19];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Driving_Cycle;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2400];
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_b_Driving_Cycle = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Driving_Cycle),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Driving_Cycle);
  c3_i20 = 0;
  for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
    for (c3_i22 = 0; c3_i22 < 1200; c3_i22++) {
      (*(real_T (*)[2400])c3_outData)[c3_i22 + c3_i20] = c3_y[c3_i22 + c3_i20];
    }

    c3_i20 += 1200;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_b_inData[2402];
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  real_T c3_u[2402];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i23 = 0;
  for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
    for (c3_i25 = 0; c3_i25 < 1201; c3_i25++) {
      c3_b_inData[c3_i25 + c3_i23] = (*(real_T (*)[2402])c3_inData)[c3_i25 +
        c3_i23];
    }

    c3_i23 += 1201;
  }

  c3_i26 = 0;
  for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
    for (c3_i28 = 0; c3_i28 < 1201; c3_i28++) {
      c3_u[c3_i28 + c3_i26] = c3_b_inData[c3_i28 + c3_i26];
    }

    c3_i26 += 1201;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1201, 2));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2402])
{
  real_T c3_dv2[2402];
  int32_T c3_i29;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 1201,
                2);
  for (c3_i29 = 0; c3_i29 < 2402; c3_i29++) {
    c3_y[c3_i29] = c3_dv2[c3_i29];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_av;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2402];
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_av = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_av), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_av);
  c3_i30 = 0;
  for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
    for (c3_i32 = 0; c3_i32 < 1201; c3_i32++) {
      (*(real_T (*)[2402])c3_outData)[c3_i32 + c3_i30] = c3_y[c3_i32 + c3_i30];
    }

    c3_i30 += 1201;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i33;
  real_T c3_b_inData[1201];
  int32_T c3_i34;
  real_T c3_u[1201];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i33 = 0; c3_i33 < 1201; c3_i33++) {
    c3_b_inData[c3_i33] = (*(real_T (*)[1201])c3_inData)[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 1201; c3_i34++) {
    c3_u[c3_i34] = c3_b_inData[c3_i34];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 1201));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[1201])
{
  real_T c3_dv3[1201];
  int32_T c3_i35;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 1201);
  for (c3_i35 = 0; c3_i35 < 1201; c3_i35++) {
    c3_y[c3_i35] = c3_dv3[c3_i35];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_dis;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[1201];
  int32_T c3_i36;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_dis = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dis), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_dis);
  for (c3_i36 = 0; c3_i36 < 1201; c3_i36++) {
    (*(real_T (*)[1201])c3_outData)[c3_i36] = c3_y[c3_i36];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i37;
  real_T c3_b_inData[2];
  int32_T c3_i38;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i37 = 0; c3_i37 < 2; c3_i37++) {
    c3_b_inData[c3_i37] = (*(real_T (*)[2])c3_inData)[c3_i37];
  }

  for (c3_i38 = 0; c3_i38 < 2; c3_i38++) {
    c3_u[c3_i38] = c3_b_inData[c3_i38];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

const mxArray
  *sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[22];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i39;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22));
  for (c3_i39 = 0; c3_i39 < 22; c3_i39++) {
    c3_r0 = &c3_info[c3_i39];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i39);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i39);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[22])
{
  c3_info[0].context = "";
  c3_info[0].name = "rem";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c3_info[0].fileTimeLo = 2721966592U;
  c3_info[0].fileTimeHi = 30107998U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c3_info[1].name = "eml_scalar_eg";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[1].fileTimeLo = 3201966592U;
  c3_info[1].fileTimeHi = 30107998U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c3_info[2].name = "eml_scalexp_alloc";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[2].fileTimeLo = 3201966592U;
  c3_info[2].fileTimeHi = 30107998U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c3_info[3].name = "eml_scalar_rem";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c3_info[3].fileTimeLo = 2561966592U;
  c3_info[3].fileTimeHi = 30107998U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "";
  c3_info[4].name = "round";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c3_info[4].fileTimeLo = 2721966592U;
  c3_info[4].fileTimeHi = 30107998U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c3_info[5].name = "eml_scalar_round";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c3_info[5].fileTimeLo = 3127347712U;
  c3_info[5].fileTimeHi = 30114278U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c3_info[6].name = "eps";
  c3_info[6].dominantType = "char";
  c3_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[6].fileTimeLo = 2101966592U;
  c3_info[6].fileTimeHi = 30107998U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[7].name = "eml_is_float_class";
  c3_info[7].dominantType = "char";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[7].fileTimeLo = 3061966592U;
  c3_info[7].fileTimeHi = 30107998U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c3_info[8].name = "mrdivide";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[8].fileTimeLo = 2311411456U;
  c3_info[8].fileTimeHi = 30130914U;
  c3_info[8].mFileTimeLo = 3767347712U;
  c3_info[8].mFileTimeHi = 30114278U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[9].name = "rdivide";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[9].fileTimeLo = 3681966592U;
  c3_info[9].fileTimeHi = 30107998U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[10].name = "eml_div";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[10].fileTimeLo = 2221966592U;
  c3_info[10].fileTimeHi = 30107998U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "";
  c3_info[11].name = "mtimes";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[11].fileTimeLo = 3767347712U;
  c3_info[11].fileTimeHi = 30114278U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "";
  c3_info[12].name = "max";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[12].fileTimeLo = 2181966592U;
  c3_info[12].fileTimeHi = 30107998U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[13].name = "eml_min_or_max";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[13].fileTimeLo = 3121966592U;
  c3_info[13].fileTimeHi = 30107998U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[14].name = "eml_const_nonsingleton_dim";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c3_info[14].fileTimeLo = 2201966592U;
  c3_info[14].fileTimeHi = 30107998U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[15].name = "eml_index_class";
  c3_info[15].dominantType = "";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[15].fileTimeLo = 3021966592U;
  c3_info[15].fileTimeHi = 30107998U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[16].name = "isnan";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[16].fileTimeLo = 2841966592U;
  c3_info[16].fileTimeHi = 30107998U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[17].name = "eml_index_plus";
  c3_info[17].dominantType = "int32";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[17].fileTimeLo = 3021966592U;
  c3_info[17].fileTimeHi = 30107998U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context = "";
  c3_info[18].name = "mpower";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[18].fileTimeLo = 3661966592U;
  c3_info[18].fileTimeHi = 30107998U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[19].name = "power";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[19].fileTimeLo = 3681966592U;
  c3_info[19].fileTimeHi = 30107998U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[20].name = "eml_scalar_floor";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[20].fileTimeLo = 2501966592U;
  c3_info[20].fileTimeHi = 30107998U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[21].name = "eml_error";
  c3_info[21].dominantType = "char";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[21].fileTimeLo = 2241966592U;
  c3_info[21].fileTimeHi = 30107998U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
}

static real_T c3_rem(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
                     *chartInstance, real_T c3_x, real_T c3_y)
{
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_b_x;
  real_T c3_b_y;
  c3_eml_scalar_eg(chartInstance);
  c3_xk = c3_x;
  c3_yk = c3_y;
  c3_b_x = c3_xk;
  c3_b_y = c3_yk;
  return muDoubleScalarRem(c3_b_x, c3_b_y);
}

static void c3_eml_scalar_eg
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
}

static real_T c3_round(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
  *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_round(chartInstance, &c3_b_x);
  return c3_b_x;
}

static real_T c3_max(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
                     *chartInstance, real_T c3_varargin_1[1201])
{
  real_T c3_mtmp;
  int32_T c3_itmp;
  int32_T c3_ix;
  real_T c3_x;
  boolean_T c3_b;
  boolean_T c3_searchingForNonNaN;
  int32_T c3_k;
  int32_T c3_b_k;
  int32_T c3_a;
  real_T c3_b_x;
  boolean_T c3_b_b;
  int32_T c3_b_a;
  int32_T c3_i40;
  int32_T c3_b_ix;
  real_T c3_b_mtmp;
  boolean_T guard1 = FALSE;
  boolean_T exitg1;
  c3_mtmp = c3_varargin_1[0];
  c3_itmp = 2;
  c3_ix = 1;
  c3_x = c3_mtmp;
  c3_b = muDoubleScalarIsNaN(c3_x);
  guard1 = FALSE;
  if (c3_b) {
    c3_searchingForNonNaN = TRUE;
    c3_k = 2;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (c3_k < 1202)) {
      c3_b_k = c3_k;
      c3_a = c3_ix + 1;
      c3_ix = c3_a;
      c3_b_x = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c3_ix), 1, 1201, 1, 0) - 1];
      c3_b_b = muDoubleScalarIsNaN(c3_b_x);
      if (!c3_b_b) {
        c3_mtmp = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_ix), 1, 1201, 1, 0) - 1];
        c3_itmp = c3_b_k + 1;
        c3_searchingForNonNaN = FALSE;
        exitg1 = 1U;
      } else {
        c3_k++;
      }
    }

    if (c3_searchingForNonNaN) {
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c3_b_a = c3_itmp;
    c3_i40 = c3_b_a;
    for (c3_b_ix = c3_i40; c3_b_ix < 1202; c3_b_ix++) {
      c3_ix = c3_b_ix;
      if (c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ix), 1, 1201, 1, 0) - 1] > c3_mtmp)
      {
        c3_mtmp = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_ix), 1, 1201, 1, 0) - 1];
      }
    }
  }

  c3_b_mtmp = c3_mtmp;
  return c3_b_mtmp;
}

static real_T c3_mpower(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
  *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_b_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i41;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i41, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i41;
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
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
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

static uint8_T c3_g_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_b_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor, const char_T *
   c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_round(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct
  *chartInstance, real_T *c3_x)
{
  real_T c3_b_x;
  c3_b_x = *c3_x;
  if (muDoubleScalarAbs(c3_b_x) > 4.503599627370496E+15) {
  } else if (c3_b_x >= 0.5) {
    *c3_x = muDoubleScalarFloor(c3_b_x + 0.5);
  } else if (c3_b_x > -0.5) {
    *c3_x = c3_b_x * 0.0;
  } else {
    *c3_x = muDoubleScalarCeil(c3_b_x - 0.5);
  }
}

static void init_dsm_address_info
  (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1117427425U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2232679884U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4251725488U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1945645529U);
}

mxArray *sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2447566976U);
    pr[1] = (double)(1203042954U);
    pr[2] = (double)(1563101051U);
    pr[3] = (double)(1478845341U);
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
      pr[0] = (double)(1200);
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

static const mxArray
  *sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[13],T\"max_acc\",},{M[1],M[20],T\"pke\",},{M[1],M[14],T\"prc_acc_02_04\",},{M[1],M[15],T\"prc_acc_06_08\",},{M[1],M[19],T\"prc_av_0_5\",},{M[1],M[16],T\"prc_dec_02_04\",},{M[1],M[17],T\"prc_dec_06_08\",},{M[1],M[5],T\"prc_spd_0_10\",},{M[1],M[12],T\"prc_spd_20_30\",},{M[1],M[18],T\"rpa\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
    chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new3_5cyc_axorMachineNumber_,
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
          init_script_number_translation
            (_hyd_hyb_2_int_cont_1_new3_5cyc_axorMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_cont_1_new3_5cyc_axorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_int_cont_1_new3_5cyc_axorMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,13,0,0,7,0,12,6);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,9230);
        _SFD_CV_INIT_EML_IF(0,0,1262,1270,-1,9226);
        _SFD_CV_INIT_EML_IF(0,1,1292,1299,8931,9214);
        _SFD_CV_INIT_EML_IF(0,2,1407,1420,-1,1558);
        _SFD_CV_INIT_EML_IF(0,3,1575,1593,-1,1868);
        _SFD_CV_INIT_EML_IF(0,4,1885,1903,-1,2013);
        _SFD_CV_INIT_EML_IF(0,5,2407,2428,-1,2497);
        _SFD_CV_INIT_EML_IF(0,6,2638,2682,-1,2753);
        _SFD_CV_INIT_EML_IF(0,7,4146,4188,-1,4259);
        _SFD_CV_INIT_EML_IF(0,8,4398,4440,-1,4511);
        _SFD_CV_INIT_EML_IF(0,9,5532,5576,-1,5647);
        _SFD_CV_INIT_EML_IF(0,10,5788,5832,-1,5903);
        _SFD_CV_INIT_EML_IF(0,11,6830,6870,-1,6935);
        _SFD_CV_INIT_EML_IF(0,12,8353,8371,-1,8554);
        _SFD_CV_INIT_EML_FOR(0,0,1332,1342,2186);
        _SFD_CV_INIT_EML_FOR(0,1,2381,2391,3126);
        _SFD_CV_INIT_EML_FOR(0,2,3679,3689,3803);
        _SFD_CV_INIT_EML_FOR(0,3,4003,4013,4749);
        _SFD_CV_INIT_EML_FOR(0,4,5387,5397,6143);
        _SFD_CV_INIT_EML_FOR(0,5,6804,6814,7514);
        _SFD_CV_INIT_EML_FOR(0,6,8161,8171,8570);

        {
          static int condStart[] = { 2641, 2663 };

          static int condEnd[] = { 2659, 2682 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,2641,2682,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4149, 4170 };

          static int condEnd[] = { 4166, 4188 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4149,4188,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4401, 4422 };

          static int condEnd[] = { 4418, 4440 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,2,4401,4440,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5535, 5557 };

          static int condEnd[] = { 5553, 5576 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,3,5535,5576,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5791, 5813 };

          static int condEnd[] = { 5809, 5832 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,4,5791,5832,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6833, 6853 };

          static int condEnd[] = { 6849, 6870 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,5,6833,6870,2,10,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1200;
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
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new3_5cyc_axorMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar);
  initialize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(void
  *chartInstanceVar)
{
  enable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(void
  *chartInstanceVar)
{
  disable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(void
  *chartInstanceVar)
{
  sf_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor();/* state var info */
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

extern void sf_internal_set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(S);
}

static void sf_opaque_set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(S, st);
}

static void sf_opaque_terminate_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
      ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
    ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor
      ((SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(SimStruct *S)
{
  /* Actual parameters from chart:
     Driving_Cycle T0 T1
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Driving_Cycle*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new3_5cyc_axor",
      "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_int_cont_1_new3_5cyc_axor",
                "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new3_5cyc_axor",
      "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "hyd_hyb_2_int_cont_1_new3_5cyc_axor",
        "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3,2);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_int_cont_1_new3_5cyc_axor",
        "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3,10);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new3_5cyc_axor",
                          "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2704425582U));
  ssSetChecksum1(S,(2393651801U));
  ssSetChecksum2(S,(100124884U));
  ssSetChecksum3(S,(551974469U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new3_5cyc_axor",
      "hyd_hyb_2_int_cont_1_new3_5cyc_axor",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(SimStruct *S)
{
  SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct *)
    malloc(sizeof(SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_hyd_hyb_2_int_cont_1_new3_5cyc_axorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor;
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

void c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_hyd_hyb_2_int_cont_1_new3_5cyc_axor_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
