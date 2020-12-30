/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_opt_cont_online_sfun.h"
#include "c38_hyd_hyb_2_opt_cont_online.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_opt_cont_online_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c38_debug_family_names[27] = { "k", "sum", "dist", "num_1",
  "num_2", "sum_acc", "sum_dec", "num_acc", "num_dec", "sum_p", "dist_p", "r",
  "i", "nargin", "nargout", "t", "spdacc", "acc", "spd", "T0", "T1",
  "prc_acc_2_4", "y_avg_acc", "y_avg_dec", "prc_spdacc_0_5", "RPA", "PKE" };

/* Function Declarations */
static void initialize_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void initialize_params_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void enable_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void disable_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void c38_update_debugger_state_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void set_sim_state_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_st);
static void finalize_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void sf_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void c38_chartstep_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void initSimStructsc38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber);
static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static real_T c38_emlrt_marshallIn(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct
  *chartInstance, const mxArray *c38_PKE, const char_T *c38_identifier);
static real_T c38_b_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_info_helper(c38_ResolvedFunctionInfo c38_info[16]);
static void c38_eml_scalar_eg(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct
  *chartInstance);
static real_T c38_mpower(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct
  *chartInstance, real_T c38_a);
static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static int32_T c38_c_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static uint8_T c38_d_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_b_is_active_c38_hyd_hyb_2_opt_cont_online, const char_T *c38_identifier);
static uint8_T c38_e_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void init_dsm_address_info(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  chartInstance->c38_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c38_is_active_c38_hyd_hyb_2_opt_cont_online = 0U;
}

static void initialize_params_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  real_T c38_d0;
  real_T c38_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'T0' in the parent workspace.\n");
  sf_mex_import_named("T0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c38_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c38_T0 = c38_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T1' in the parent workspace.\n");
  sf_mex_import_named("T1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c38_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c38_T1 = c38_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c38_update_debugger_state_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  const mxArray *c38_st;
  const mxArray *c38_y = NULL;
  real_T c38_hoistedGlobal;
  real_T c38_u;
  const mxArray *c38_b_y = NULL;
  real_T c38_b_hoistedGlobal;
  real_T c38_b_u;
  const mxArray *c38_c_y = NULL;
  real_T c38_c_hoistedGlobal;
  real_T c38_c_u;
  const mxArray *c38_d_y = NULL;
  real_T c38_d_hoistedGlobal;
  real_T c38_d_u;
  const mxArray *c38_e_y = NULL;
  real_T c38_e_hoistedGlobal;
  real_T c38_e_u;
  const mxArray *c38_f_y = NULL;
  real_T c38_f_hoistedGlobal;
  real_T c38_f_u;
  const mxArray *c38_g_y = NULL;
  uint8_T c38_g_hoistedGlobal;
  uint8_T c38_g_u;
  const mxArray *c38_h_y = NULL;
  real_T *c38_PKE;
  real_T *c38_RPA;
  real_T *c38_prc_acc_2_4;
  real_T *c38_prc_spdacc_0_5;
  real_T *c38_y_avg_acc;
  real_T *c38_y_avg_dec;
  c38_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c38_RPA = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c38_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c38_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c38_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c38_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c38_st = NULL;
  c38_st = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_createcellarray(7));
  c38_hoistedGlobal = *c38_PKE;
  c38_u = c38_hoistedGlobal;
  c38_b_y = NULL;
  sf_mex_assign(&c38_b_y, sf_mex_create("y", &c38_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 0, c38_b_y);
  c38_b_hoistedGlobal = *c38_RPA;
  c38_b_u = c38_b_hoistedGlobal;
  c38_c_y = NULL;
  sf_mex_assign(&c38_c_y, sf_mex_create("y", &c38_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 1, c38_c_y);
  c38_c_hoistedGlobal = *c38_prc_acc_2_4;
  c38_c_u = c38_c_hoistedGlobal;
  c38_d_y = NULL;
  sf_mex_assign(&c38_d_y, sf_mex_create("y", &c38_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 2, c38_d_y);
  c38_d_hoistedGlobal = *c38_prc_spdacc_0_5;
  c38_d_u = c38_d_hoistedGlobal;
  c38_e_y = NULL;
  sf_mex_assign(&c38_e_y, sf_mex_create("y", &c38_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 3, c38_e_y);
  c38_e_hoistedGlobal = *c38_y_avg_acc;
  c38_e_u = c38_e_hoistedGlobal;
  c38_f_y = NULL;
  sf_mex_assign(&c38_f_y, sf_mex_create("y", &c38_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 4, c38_f_y);
  c38_f_hoistedGlobal = *c38_y_avg_dec;
  c38_f_u = c38_f_hoistedGlobal;
  c38_g_y = NULL;
  sf_mex_assign(&c38_g_y, sf_mex_create("y", &c38_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 5, c38_g_y);
  c38_g_hoistedGlobal =
    chartInstance->c38_is_active_c38_hyd_hyb_2_opt_cont_online;
  c38_g_u = c38_g_hoistedGlobal;
  c38_h_y = NULL;
  sf_mex_assign(&c38_h_y, sf_mex_create("y", &c38_g_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c38_y, 6, c38_h_y);
  sf_mex_assign(&c38_st, c38_y);
  return c38_st;
}

static void set_sim_state_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_st)
{
  const mxArray *c38_u;
  real_T *c38_PKE;
  real_T *c38_RPA;
  real_T *c38_prc_acc_2_4;
  real_T *c38_prc_spdacc_0_5;
  real_T *c38_y_avg_acc;
  real_T *c38_y_avg_dec;
  c38_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c38_RPA = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c38_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c38_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c38_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c38_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c38_doneDoubleBufferReInit = TRUE;
  c38_u = sf_mex_dup(c38_st);
  *c38_PKE = c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u,
    0)), "PKE");
  *c38_RPA = c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u,
    1)), "RPA");
  *c38_prc_acc_2_4 = c38_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c38_u, 2)), "prc_acc_2_4");
  *c38_prc_spdacc_0_5 = c38_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c38_u, 3)), "prc_spdacc_0_5");
  *c38_y_avg_acc = c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c38_u, 4)), "y_avg_acc");
  *c38_y_avg_dec = c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c38_u, 5)), "y_avg_dec");
  chartInstance->c38_is_active_c38_hyd_hyb_2_opt_cont_online =
    c38_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 6)),
    "is_active_c38_hyd_hyb_2_opt_cont_online");
  sf_mex_destroy(&c38_u);
  c38_update_debugger_state_c38_hyd_hyb_2_opt_cont_online(chartInstance);
  sf_mex_destroy(&c38_st);
}

static void finalize_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
}

static void sf_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  int32_T c38_i0;
  int32_T c38_i1;
  int32_T c38_i2;
  real_T *c38_prc_acc_2_4;
  real_T *c38_y_avg_acc;
  real_T *c38_y_avg_dec;
  real_T *c38_prc_spdacc_0_5;
  real_T *c38_RPA;
  real_T *c38_t;
  real_T *c38_PKE;
  real_T (*c38_spd)[60001];
  real_T (*c38_acc)[60001];
  real_T (*c38_spdacc)[60001];
  c38_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c38_spd = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 3);
  c38_acc = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 2);
  c38_spdacc = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 1);
  c38_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c38_RPA = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c38_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c38_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c38_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c38_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c38_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c38_prc_acc_2_4, 0U);
  _SFD_DATA_RANGE_CHECK(*c38_y_avg_acc, 1U);
  _SFD_DATA_RANGE_CHECK(*c38_y_avg_dec, 2U);
  _SFD_DATA_RANGE_CHECK(*c38_prc_spdacc_0_5, 3U);
  _SFD_DATA_RANGE_CHECK(*c38_RPA, 4U);
  _SFD_DATA_RANGE_CHECK(*c38_t, 5U);
  for (c38_i0 = 0; c38_i0 < 60001; c38_i0++) {
    _SFD_DATA_RANGE_CHECK((*c38_spdacc)[c38_i0], 6U);
  }

  for (c38_i1 = 0; c38_i1 < 60001; c38_i1++) {
    _SFD_DATA_RANGE_CHECK((*c38_acc)[c38_i1], 7U);
  }

  for (c38_i2 = 0; c38_i2 < 60001; c38_i2++) {
    _SFD_DATA_RANGE_CHECK((*c38_spd)[c38_i2], 8U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c38_T0, 9U);
  _SFD_DATA_RANGE_CHECK(*c38_PKE, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c38_T1, 11U);
  chartInstance->c38_sfEvent = CALL_EVENT;
  c38_chartstep_c38_hyd_hyb_2_opt_cont_online(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_opt_cont_onlineMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c38_chartstep_c38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
  real_T c38_hoistedGlobal;
  real_T c38_b_hoistedGlobal;
  real_T c38_c_hoistedGlobal;
  real_T c38_t;
  int32_T c38_i3;
  static real_T c38_spdacc[60001];
  int32_T c38_i4;
  static real_T c38_acc[60001];
  int32_T c38_i5;
  static real_T c38_spd[60001];
  real_T c38_b_T0;
  real_T c38_b_T1;
  uint32_T c38_debug_family_var_map[27];
  real_T c38_k;
  real_T c38_sum;
  real_T c38_dist;
  real_T c38_num_1;
  real_T c38_num_2;
  real_T c38_sum_acc;
  real_T c38_sum_dec;
  real_T c38_num_acc;
  real_T c38_num_dec;
  real_T c38_sum_p;
  real_T c38_dist_p;
  real_T c38_r;
  real_T c38_i;
  real_T c38_nargin = 6.0;
  real_T c38_nargout = 6.0;
  real_T c38_prc_acc_2_4;
  real_T c38_y_avg_acc;
  real_T c38_y_avg_dec;
  real_T c38_prc_spdacc_0_5;
  real_T c38_RPA;
  real_T c38_PKE;
  real_T c38_a;
  real_T c38_y;
  real_T c38_x;
  real_T c38_b_x;
  real_T c38_c_x;
  real_T c38_d_x;
  real_T c38_b_y;
  real_T c38_xk;
  real_T c38_yk;
  real_T c38_e_x;
  real_T c38_c_y;
  real_T c38_b_a;
  real_T c38_d_y;
  real_T c38_d2;
  real_T c38_b_i;
  real_T c38_b;
  real_T c38_e_y;
  real_T c38_b_b;
  real_T c38_f_y;
  real_T c38_c_b;
  real_T c38_g_y;
  real_T c38_A;
  real_T c38_B;
  real_T c38_f_x;
  real_T c38_h_y;
  real_T c38_g_x;
  real_T c38_i_y;
  real_T c38_h_x;
  real_T c38_j_y;
  real_T c38_b_A;
  real_T c38_b_B;
  real_T c38_i_x;
  real_T c38_k_y;
  real_T c38_j_x;
  real_T c38_l_y;
  real_T c38_k_x;
  real_T c38_m_y;
  real_T c38_c_A;
  real_T c38_c_B;
  real_T c38_l_x;
  real_T c38_n_y;
  real_T c38_m_x;
  real_T c38_o_y;
  real_T c38_n_x;
  real_T c38_p_y;
  real_T c38_d_A;
  real_T c38_d_B;
  real_T c38_o_x;
  real_T c38_q_y;
  real_T c38_p_x;
  real_T c38_r_y;
  real_T c38_q_x;
  real_T c38_s_y;
  real_T c38_c_a;
  real_T c38_t_y;
  real_T c38_e_A;
  real_T c38_e_B;
  real_T c38_r_x;
  real_T c38_u_y;
  real_T c38_s_x;
  real_T c38_v_y;
  real_T c38_t_x;
  real_T c38_w_y;
  real_T c38_d_a;
  real_T c38_x_y;
  real_T c38_f_A;
  real_T c38_f_B;
  real_T c38_u_x;
  real_T c38_y_y;
  real_T c38_v_x;
  real_T c38_ab_y;
  real_T c38_w_x;
  real_T c38_bb_y;
  real_T *c38_b_t;
  real_T *c38_b_prc_acc_2_4;
  real_T *c38_b_y_avg_acc;
  real_T *c38_b_y_avg_dec;
  real_T *c38_b_prc_spdacc_0_5;
  real_T *c38_b_RPA;
  real_T *c38_b_PKE;
  real_T (*c38_b_spd)[60001];
  real_T (*c38_b_acc)[60001];
  real_T (*c38_b_spdacc)[60001];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c38_b_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c38_b_spd = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 3);
  c38_b_acc = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 2);
  c38_b_spdacc = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 1);
  c38_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c38_b_RPA = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c38_b_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c38_b_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c38_b_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c38_b_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c38_sfEvent);
  c38_hoistedGlobal = *c38_b_t;
  c38_b_hoistedGlobal = chartInstance->c38_T0;
  c38_c_hoistedGlobal = chartInstance->c38_T1;
  c38_t = c38_hoistedGlobal;
  for (c38_i3 = 0; c38_i3 < 60001; c38_i3++) {
    c38_spdacc[c38_i3] = (*c38_b_spdacc)[c38_i3];
  }

  for (c38_i4 = 0; c38_i4 < 60001; c38_i4++) {
    c38_acc[c38_i4] = (*c38_b_acc)[c38_i4];
  }

  for (c38_i5 = 0; c38_i5 < 60001; c38_i5++) {
    c38_spd[c38_i5] = (*c38_b_spd)[c38_i5];
  }

  c38_b_T0 = c38_b_hoistedGlobal;
  c38_b_T1 = c38_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 27U, 27U, c38_debug_family_names,
    c38_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c38_k, 0U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_sum, 1U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_dist, 2U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_num_1, 3U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_num_2, 4U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_sum_acc, 5U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_sum_dec, 6U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_num_acc, 7U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_num_dec, 8U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_sum_p, 9U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_dist_p, 10U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_r, 11U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_i, 12U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_nargin, 13U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_nargout, 14U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c38_t, 15U, c38_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c38_spdacc, 16U, c38_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c38_acc, 17U, c38_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c38_spd, 18U, c38_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c38_b_T0, 19U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_b_T1, 20U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_prc_acc_2_4, 21U,
    c38_sf_marshallOut, c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_y_avg_acc, 22U,
    c38_sf_marshallOut, c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_y_avg_dec, 23U,
    c38_sf_marshallOut, c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_prc_spdacc_0_5, 24U,
    c38_sf_marshallOut, c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_RPA, 25U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_PKE, 26U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 5);
  c38_a = c38_t;
  c38_y = c38_a * 100.0;
  c38_x = c38_y + 1.0;
  c38_k = c38_x;
  c38_b_x = c38_k;
  c38_k = c38_b_x;
  c38_c_x = c38_k;
  if (muDoubleScalarAbs(c38_c_x) > 4.503599627370496E+15) {
    c38_k = c38_c_x;
  } else if (c38_c_x >= 0.5) {
    c38_k = muDoubleScalarFloor(c38_c_x + 0.5);
  } else if (c38_c_x > -0.5) {
    c38_k = c38_c_x * 0.0;
  } else {
    c38_k = muDoubleScalarCeil(c38_c_x - 0.5);
  }

  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 6);
  c38_sum = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 6);
  c38_dist = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 7);
  c38_num_1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 7);
  c38_num_2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 8);
  c38_sum_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 8);
  c38_sum_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 9);
  c38_num_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 9);
  c38_num_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 10);
  c38_y_avg_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 10);
  c38_y_avg_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 11);
  c38_RPA = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 12);
  c38_sum_p = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 12);
  c38_dist_p = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 13);
  c38_PKE = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 14);
  if (CV_EML_IF(0, 0, c38_t > c38_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 15);
    c38_d_x = c38_t;
    c38_b_y = c38_b_T1;
    c38_eml_scalar_eg(chartInstance);
    c38_xk = c38_d_x;
    c38_yk = c38_b_y;
    c38_e_x = c38_xk;
    c38_c_y = c38_yk;
    c38_r = muDoubleScalarRem(c38_e_x, c38_c_y);
    _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 16);
    if (CV_EML_IF(0, 1, c38_r < 0.01)) {
      c38_b_a = c38_b_T0;
      c38_d_y = c38_b_a * 100.0;
      c38_d2 = c38_k - c38_d_y;
      c38_i = c38_d2;
      c38_b_i = c38_d2;
      while (c38_b_i <= c38_k) {
        c38_i = c38_b_i;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 18);
        guard2 = FALSE;
        if (CV_EML_COND(0, 0, c38_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc",
              (int32_T)_SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1] <
                        0.4)) {
          if (CV_EML_COND(0, 1, c38_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc",
                (int32_T)_SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1] >
                          0.2)) {
            CV_EML_MCDC(0, 0, TRUE);
            CV_EML_IF(0, 2, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 19);
            c38_num_1++;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          CV_EML_MCDC(0, 0, FALSE);
          CV_EML_IF(0, 2, FALSE);
        }

        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 21);
        guard1 = FALSE;
        if (CV_EML_COND(0, 2, c38_spdacc[_SFD_EML_ARRAY_BOUNDS_CHECK("spdacc",
              (int32_T)_SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1] <
                        5.0)) {
          if (CV_EML_COND(0, 3, c38_spdacc[_SFD_EML_ARRAY_BOUNDS_CHECK("spdacc",
                (int32_T)_SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1] >
                          0.0)) {
            CV_EML_MCDC(0, 1, TRUE);
            CV_EML_IF(0, 3, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 22);
            c38_num_2++;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          CV_EML_MCDC(0, 1, FALSE);
          CV_EML_IF(0, 3, FALSE);
        }

        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 24);
        if (CV_EML_IF(0, 4, c38_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
              _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1] > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 25);
          c38_b = c38_spdacc[_SFD_EML_ARRAY_BOUNDS_CHECK("spdacc", (int32_T)
            _SFD_INTEGER_CHECK("i-1", c38_i - 1.0), 1, 60001, 1, 0) - 1] +
            c38_spdacc[_SFD_EML_ARRAY_BOUNDS_CHECK("spdacc", (int32_T)
            _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1];
          c38_e_y = 0.5 * c38_b;
          c38_sum += c38_e_y;
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 26);
          c38_b_b = c38_spd[_SFD_EML_ARRAY_BOUNDS_CHECK("spd", (int32_T)
            _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1];
          c38_f_y = 0.01 * c38_b_b;
          c38_dist += c38_f_y;
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 27);
          c38_sum_acc += c38_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
            _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1];
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 28);
          c38_num_acc++;
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 29);
          c38_sum_p += c38_mpower(chartInstance,
            c38_spd[_SFD_EML_ARRAY_BOUNDS_CHECK("spd", (int32_T)
            _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1]) - c38_mpower
            (chartInstance, c38_spd[_SFD_EML_ARRAY_BOUNDS_CHECK("spd", (int32_T)
              _SFD_INTEGER_CHECK("i-1", c38_i - 1.0), 1, 60001, 1, 0) - 1]);
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 30);
          c38_c_b = c38_spd[_SFD_EML_ARRAY_BOUNDS_CHECK("spd", (int32_T)
            _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1];
          c38_g_y = 0.01 * c38_c_b;
          c38_dist_p += c38_g_y;
        }

        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 32);
        if (CV_EML_IF(0, 5, c38_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
              _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1] < 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 33);
          c38_sum_dec += c38_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
            _SFD_INTEGER_CHECK("i", c38_i), 1, 60001, 1, 0) - 1];
          _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 34);
          c38_num_dec++;
        }

        c38_b_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 37);
      if (CV_EML_IF(0, 6, c38_dist > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 38);
        c38_A = c38_sum;
        c38_B = c38_dist;
        c38_f_x = c38_A;
        c38_h_y = c38_B;
        c38_g_x = c38_f_x;
        c38_i_y = c38_h_y;
        c38_h_x = c38_g_x;
        c38_j_y = c38_i_y;
        c38_RPA = c38_h_x / c38_j_y;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 40);
        c38_RPA = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 42);
      if (CV_EML_IF(0, 7, c38_num_acc > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 43);
        c38_b_A = c38_sum_acc;
        c38_b_B = c38_num_acc;
        c38_i_x = c38_b_A;
        c38_k_y = c38_b_B;
        c38_j_x = c38_i_x;
        c38_l_y = c38_k_y;
        c38_k_x = c38_j_x;
        c38_m_y = c38_l_y;
        c38_y_avg_acc = c38_k_x / c38_m_y;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 45);
        c38_y_avg_acc = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 47);
      if (CV_EML_IF(0, 8, c38_num_dec > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 48);
        c38_c_A = c38_sum_dec;
        c38_c_B = c38_num_dec;
        c38_l_x = c38_c_A;
        c38_n_y = c38_c_B;
        c38_m_x = c38_l_x;
        c38_o_y = c38_n_y;
        c38_n_x = c38_m_x;
        c38_p_y = c38_o_y;
        c38_y_avg_dec = c38_n_x / c38_p_y;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 50);
        c38_y_avg_dec = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 52);
      if (CV_EML_IF(0, 9, c38_dist_p > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 53);
        c38_d_A = c38_sum_p;
        c38_d_B = c38_dist_p;
        c38_o_x = c38_d_A;
        c38_q_y = c38_d_B;
        c38_p_x = c38_o_x;
        c38_r_y = c38_q_y;
        c38_q_x = c38_p_x;
        c38_s_y = c38_r_y;
        c38_PKE = c38_q_x / c38_s_y;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 55);
        c38_PKE = 0.0;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 59);
  c38_c_a = c38_b_T0;
  c38_t_y = c38_c_a * 100.0;
  c38_e_A = c38_num_1;
  c38_e_B = c38_t_y;
  c38_r_x = c38_e_A;
  c38_u_y = c38_e_B;
  c38_s_x = c38_r_x;
  c38_v_y = c38_u_y;
  c38_t_x = c38_s_x;
  c38_w_y = c38_v_y;
  c38_prc_acc_2_4 = c38_t_x / c38_w_y;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 60);
  c38_d_a = c38_b_T0;
  c38_x_y = c38_d_a * 100.0;
  c38_f_A = c38_num_2;
  c38_f_B = c38_x_y;
  c38_u_x = c38_f_A;
  c38_y_y = c38_f_B;
  c38_v_x = c38_u_x;
  c38_ab_y = c38_y_y;
  c38_w_x = c38_v_x;
  c38_bb_y = c38_ab_y;
  c38_prc_spdacc_0_5 = c38_w_x / c38_bb_y;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, -60);
  sf_debug_symbol_scope_pop();
  *c38_b_prc_acc_2_4 = c38_prc_acc_2_4;
  *c38_b_y_avg_acc = c38_y_avg_acc;
  *c38_b_y_avg_dec = c38_y_avg_dec;
  *c38_b_prc_spdacc_0_5 = c38_prc_spdacc_0_5;
  *c38_b_RPA = c38_RPA;
  *c38_b_PKE = c38_PKE;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c38_sfEvent);
}

static void initSimStructsc38_hyd_hyb_2_opt_cont_online
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber)
{
}

static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  real_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)
    chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(real_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c38_mxArrayOutData, c38_y);
  return c38_mxArrayOutData;
}

static real_T c38_emlrt_marshallIn(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct
  *chartInstance, const mxArray *c38_PKE, const char_T *c38_identifier)
{
  real_T c38_y;
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_PKE), &c38_thisId);
  sf_mex_destroy(&c38_PKE);
  return c38_y;
}

static real_T c38_b_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  real_T c38_y;
  real_T c38_d3;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_d3, 1, 0, 0U, 0, 0U, 0);
  c38_y = c38_d3;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_PKE;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y;
  SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)
    chartInstanceVoid;
  c38_PKE = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_PKE), &c38_thisId);
  sf_mex_destroy(&c38_PKE);
  *(real_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i6;
  static real_T c38_b_inData[60001];
  int32_T c38_i7;
  static real_T c38_u[60001];
  const mxArray *c38_y = NULL;
  SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)
    chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i6 = 0; c38_i6 < 60001; c38_i6++) {
    c38_b_inData[c38_i6] = (*(real_T (*)[60001])c38_inData)[c38_i6];
  }

  for (c38_i7 = 0; c38_i7 < 60001; c38_i7++) {
    c38_u[c38_i7] = c38_b_inData[c38_i7];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 60001));
  sf_mex_assign(&c38_mxArrayOutData, c38_y);
  return c38_mxArrayOutData;
}

const mxArray *sf_c38_hyd_hyb_2_opt_cont_online_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c38_nameCaptureInfo;
  c38_ResolvedFunctionInfo c38_info[16];
  const mxArray *c38_m0 = NULL;
  int32_T c38_i8;
  c38_ResolvedFunctionInfo *c38_r0;
  c38_nameCaptureInfo = NULL;
  c38_nameCaptureInfo = NULL;
  c38_info_helper(c38_info);
  sf_mex_assign(&c38_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16));
  for (c38_i8 = 0; c38_i8 < 16; c38_i8++) {
    c38_r0 = &c38_info[c38_i8];
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", c38_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c38_r0->context)), "context", "nameCaptureInfo",
                    c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", c38_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c38_r0->name)), "name", "nameCaptureInfo", c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo",
      c38_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c38_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", c38_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c38_r0->resolved)), "resolved",
                    "nameCaptureInfo", c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", &c38_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", &c38_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo",
      &c38_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c38_i8);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo",
      &c38_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c38_i8);
  }

  sf_mex_assign(&c38_nameCaptureInfo, c38_m0);
  return c38_nameCaptureInfo;
}

static void c38_info_helper(c38_ResolvedFunctionInfo c38_info[16])
{
  c38_info[0].context = "";
  c38_info[0].name = "mtimes";
  c38_info[0].dominantType = "double";
  c38_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c38_info[0].fileTimeLo = 3767347712U;
  c38_info[0].fileTimeHi = 30114278U;
  c38_info[0].mFileTimeLo = 0U;
  c38_info[0].mFileTimeHi = 0U;
  c38_info[1].context = "";
  c38_info[1].name = "round";
  c38_info[1].dominantType = "double";
  c38_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c38_info[1].fileTimeLo = 2721966592U;
  c38_info[1].fileTimeHi = 30107998U;
  c38_info[1].mFileTimeLo = 0U;
  c38_info[1].mFileTimeHi = 0U;
  c38_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c38_info[2].name = "eml_scalar_round";
  c38_info[2].dominantType = "double";
  c38_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c38_info[2].fileTimeLo = 3127347712U;
  c38_info[2].fileTimeHi = 30114278U;
  c38_info[2].mFileTimeLo = 0U;
  c38_info[2].mFileTimeHi = 0U;
  c38_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c38_info[3].name = "eps";
  c38_info[3].dominantType = "char";
  c38_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c38_info[3].fileTimeLo = 2101966592U;
  c38_info[3].fileTimeHi = 30107998U;
  c38_info[3].mFileTimeLo = 0U;
  c38_info[3].mFileTimeHi = 0U;
  c38_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c38_info[4].name = "eml_is_float_class";
  c38_info[4].dominantType = "char";
  c38_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c38_info[4].fileTimeLo = 3061966592U;
  c38_info[4].fileTimeHi = 30107998U;
  c38_info[4].mFileTimeLo = 0U;
  c38_info[4].mFileTimeHi = 0U;
  c38_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c38_info[5].name = "mrdivide";
  c38_info[5].dominantType = "double";
  c38_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c38_info[5].fileTimeLo = 2311411456U;
  c38_info[5].fileTimeHi = 30130914U;
  c38_info[5].mFileTimeLo = 3767347712U;
  c38_info[5].mFileTimeHi = 30114278U;
  c38_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c38_info[6].name = "rdivide";
  c38_info[6].dominantType = "double";
  c38_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c38_info[6].fileTimeLo = 3681966592U;
  c38_info[6].fileTimeHi = 30107998U;
  c38_info[6].mFileTimeLo = 0U;
  c38_info[6].mFileTimeHi = 0U;
  c38_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c38_info[7].name = "eml_div";
  c38_info[7].dominantType = "double";
  c38_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c38_info[7].fileTimeLo = 2221966592U;
  c38_info[7].fileTimeHi = 30107998U;
  c38_info[7].mFileTimeLo = 0U;
  c38_info[7].mFileTimeHi = 0U;
  c38_info[8].context = "";
  c38_info[8].name = "rem";
  c38_info[8].dominantType = "double";
  c38_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c38_info[8].fileTimeLo = 2721966592U;
  c38_info[8].fileTimeHi = 30107998U;
  c38_info[8].mFileTimeLo = 0U;
  c38_info[8].mFileTimeHi = 0U;
  c38_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c38_info[9].name = "eml_scalar_eg";
  c38_info[9].dominantType = "double";
  c38_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c38_info[9].fileTimeLo = 3201966592U;
  c38_info[9].fileTimeHi = 30107998U;
  c38_info[9].mFileTimeLo = 0U;
  c38_info[9].mFileTimeHi = 0U;
  c38_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c38_info[10].name = "eml_scalexp_alloc";
  c38_info[10].dominantType = "double";
  c38_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c38_info[10].fileTimeLo = 3201966592U;
  c38_info[10].fileTimeHi = 30107998U;
  c38_info[10].mFileTimeLo = 0U;
  c38_info[10].mFileTimeHi = 0U;
  c38_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c38_info[11].name = "eml_scalar_rem";
  c38_info[11].dominantType = "double";
  c38_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c38_info[11].fileTimeLo = 2561966592U;
  c38_info[11].fileTimeHi = 30107998U;
  c38_info[11].mFileTimeLo = 0U;
  c38_info[11].mFileTimeHi = 0U;
  c38_info[12].context = "";
  c38_info[12].name = "mpower";
  c38_info[12].dominantType = "double";
  c38_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c38_info[12].fileTimeLo = 3661966592U;
  c38_info[12].fileTimeHi = 30107998U;
  c38_info[12].mFileTimeLo = 0U;
  c38_info[12].mFileTimeHi = 0U;
  c38_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c38_info[13].name = "power";
  c38_info[13].dominantType = "double";
  c38_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c38_info[13].fileTimeLo = 3681966592U;
  c38_info[13].fileTimeHi = 30107998U;
  c38_info[13].mFileTimeLo = 0U;
  c38_info[13].mFileTimeHi = 0U;
  c38_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c38_info[14].name = "eml_scalar_floor";
  c38_info[14].dominantType = "double";
  c38_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c38_info[14].fileTimeLo = 2501966592U;
  c38_info[14].fileTimeHi = 30107998U;
  c38_info[14].mFileTimeLo = 0U;
  c38_info[14].mFileTimeHi = 0U;
  c38_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c38_info[15].name = "eml_error";
  c38_info[15].dominantType = "char";
  c38_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c38_info[15].fileTimeLo = 2241966592U;
  c38_info[15].fileTimeHi = 30107998U;
  c38_info[15].mFileTimeLo = 0U;
  c38_info[15].mFileTimeHi = 0U;
}

static void c38_eml_scalar_eg(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct
  *chartInstance)
{
}

static real_T c38_mpower(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct
  *chartInstance, real_T c38_a)
{
  real_T c38_b_a;
  real_T c38_ak;
  c38_b_a = c38_a;
  c38_eml_scalar_eg(chartInstance);
  c38_ak = c38_b_a;
  return muDoubleScalarPower(c38_ak, 2.0);
}

static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)
    chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(int32_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c38_mxArrayOutData, c38_y);
  return c38_mxArrayOutData;
}

static int32_T c38_c_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  int32_T c38_y;
  int32_T c38_i9;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_i9, 1, 6, 0U, 0, 0U, 0);
  c38_y = c38_i9;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_b_sfEvent;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  int32_T c38_y;
  SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)
    chartInstanceVoid;
  c38_b_sfEvent = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_sfEvent),
    &c38_thisId);
  sf_mex_destroy(&c38_b_sfEvent);
  *(int32_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static uint8_T c38_d_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_b_is_active_c38_hyd_hyb_2_opt_cont_online, const char_T *c38_identifier)
{
  uint8_T c38_y;
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c38_b_is_active_c38_hyd_hyb_2_opt_cont_online), &c38_thisId);
  sf_mex_destroy(&c38_b_is_active_c38_hyd_hyb_2_opt_cont_online);
  return c38_y;
}

static uint8_T c38_e_emlrt_marshallIn
  (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance, const mxArray
   *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  uint8_T c38_y;
  uint8_T c38_u0;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_u0, 1, 3, 0U, 0, 0U, 0);
  c38_y = c38_u0;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void init_dsm_address_info(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c38_hyd_hyb_2_opt_cont_online_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3278444700U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4196603482U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2433567669U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1237707679U);
}

mxArray *sf_c38_hyd_hyb_2_opt_cont_online_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3648692562U);
    pr[1] = (double)(32904014U);
    pr[2] = (double)(4179388551U);
    pr[3] = (double)(1336099328U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(60001);
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
      pr[0] = (double)(60001);
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
      pr[0] = (double)(60001);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c38_hyd_hyb_2_opt_cont_online(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[17],T\"PKE\",},{M[1],M[5],T\"RPA\",},{M[1],M[13],T\"prc_acc_2_4\",},{M[1],M[16],T\"prc_spdacc_0_5\",},{M[1],M[14],T\"y_avg_acc\",},{M[1],M[15],T\"y_avg_dec\",},{M[8],M[0],T\"is_active_c38_hyd_hyb_2_opt_cont_online\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c38_hyd_hyb_2_opt_cont_online_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
    chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_opt_cont_onlineMachineNumber_,
           38,
           1,
           1,
           12,
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
            (_hyd_hyb_2_opt_cont_onlineMachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_opt_cont_onlineMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_opt_cont_onlineMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"prc_acc_2_4");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y_avg_acc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y_avg_dec");
          _SFD_SET_DATA_PROPS(3,2,0,1,"prc_spdacc_0_5");
          _SFD_SET_DATA_PROPS(4,2,0,1,"RPA");
          _SFD_SET_DATA_PROPS(5,1,1,0,"t");
          _SFD_SET_DATA_PROPS(6,1,1,0,"spdacc");
          _SFD_SET_DATA_PROPS(7,1,1,0,"acc");
          _SFD_SET_DATA_PROPS(8,1,1,0,"spd");
          _SFD_SET_DATA_PROPS(9,10,0,0,"T0");
          _SFD_SET_DATA_PROPS(10,2,0,1,"PKE");
          _SFD_SET_DATA_PROPS(11,10,0,0,"T1");
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
        _SFD_CV_INIT_EML(0,1,10,0,0,1,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1512);
        _SFD_CV_INIT_EML_IF(0,0,356,363,-1,1449);
        _SFD_CV_INIT_EML_IF(0,1,385,394,-1,1445);
        _SFD_CV_INIT_EML_IF(0,2,434,461,-1,508);
        _SFD_CV_INIT_EML_IF(0,3,521,550,-1,597);
        _SFD_CV_INIT_EML_IF(0,4,610,621,-1,908);
        _SFD_CV_INIT_EML_IF(0,5,921,932,-1,1023);
        _SFD_CV_INIT_EML_IF(0,6,1044,1053,1088,1123);
        _SFD_CV_INIT_EML_IF(0,7,1132,1144,1192,1233);
        _SFD_CV_INIT_EML_IF(0,8,1242,1254,1302,1343);
        _SFD_CV_INIT_EML_IF(0,9,1352,1363,1402,1437);
        _SFD_CV_INIT_EML_FOR(0,0,403,422,1035);

        {
          static int condStart[] = { 437, 451 };

          static int condEnd[] = { 447, 461 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,437,461,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 524, 539 };

          static int condEnd[] = { 535, 550 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,524,550,2,2,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
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
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 60001;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 60001;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 60001;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)c38_sf_marshallIn);

        {
          real_T *c38_prc_acc_2_4;
          real_T *c38_y_avg_acc;
          real_T *c38_y_avg_dec;
          real_T *c38_prc_spdacc_0_5;
          real_T *c38_RPA;
          real_T *c38_t;
          real_T *c38_PKE;
          real_T (*c38_spdacc)[60001];
          real_T (*c38_acc)[60001];
          real_T (*c38_spd)[60001];
          c38_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c38_spd = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 3);
          c38_acc = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S, 2);
          c38_spdacc = (real_T (*)[60001])ssGetInputPortSignal(chartInstance->S,
            1);
          c38_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c38_RPA = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c38_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            4);
          c38_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c38_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c38_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c38_prc_acc_2_4);
          _SFD_SET_DATA_VALUE_PTR(1U, c38_y_avg_acc);
          _SFD_SET_DATA_VALUE_PTR(2U, c38_y_avg_dec);
          _SFD_SET_DATA_VALUE_PTR(3U, c38_prc_spdacc_0_5);
          _SFD_SET_DATA_VALUE_PTR(4U, c38_RPA);
          _SFD_SET_DATA_VALUE_PTR(5U, c38_t);
          _SFD_SET_DATA_VALUE_PTR(6U, *c38_spdacc);
          _SFD_SET_DATA_VALUE_PTR(7U, *c38_acc);
          _SFD_SET_DATA_VALUE_PTR(8U, *c38_spd);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c38_T0);
          _SFD_SET_DATA_VALUE_PTR(10U, c38_PKE);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c38_T1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_opt_cont_onlineMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c38_hyd_hyb_2_opt_cont_online(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
  initialize_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c38_hyd_hyb_2_opt_cont_online(void
  *chartInstanceVar)
{
  enable_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c38_hyd_hyb_2_opt_cont_online(void
  *chartInstanceVar)
{
  disable_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c38_hyd_hyb_2_opt_cont_online(void
  *chartInstanceVar)
{
  sf_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c38_hyd_hyb_2_opt_cont_online
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c38_hyd_hyb_2_opt_cont_online();/* state var info */
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

extern void sf_internal_set_sim_state_c38_hyd_hyb_2_opt_cont_online(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c38_hyd_hyb_2_opt_cont_online();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c38_hyd_hyb_2_opt_cont_online
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c38_hyd_hyb_2_opt_cont_online(S);
}

static void sf_opaque_set_sim_state_c38_hyd_hyb_2_opt_cont_online(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c38_hyd_hyb_2_opt_cont_online(S, st);
}

static void sf_opaque_terminate_c38_hyd_hyb_2_opt_cont_online(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c38_hyd_hyb_2_opt_cont_online
      ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc38_hyd_hyb_2_opt_cont_online
    ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c38_hyd_hyb_2_opt_cont_online(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c38_hyd_hyb_2_opt_cont_online
      ((SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c38_hyd_hyb_2_opt_cont_online(SimStruct *S)
{
  /* Actual parameters from chart:
     T0 T1
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_opt_cont_online",
      "hyd_hyb_2_opt_cont_online",38);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_online",
                "hyd_hyb_2_opt_cont_online",38,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_opt_cont_online","hyd_hyb_2_opt_cont_online",38,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_opt_cont_online",
        "hyd_hyb_2_opt_cont_online",38,4);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_opt_cont_online",
        "hyd_hyb_2_opt_cont_online",38,6);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_opt_cont_online",
                          "hyd_hyb_2_opt_cont_online",38);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(979226478U));
  ssSetChecksum1(S,(4136645999U));
  ssSetChecksum2(S,(298229718U));
  ssSetChecksum3(S,(3327954901U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c38_hyd_hyb_2_opt_cont_online(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_opt_cont_online",
      "hyd_hyb_2_opt_cont_online",38);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c38_hyd_hyb_2_opt_cont_online(SimStruct *S)
{
  SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct *)malloc(sizeof
    (SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc38_hyd_hyb_2_opt_cont_onlineInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.mdlStart = mdlStart_c38_hyd_hyb_2_opt_cont_online;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c38_hyd_hyb_2_opt_cont_online;
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

void c38_hyd_hyb_2_opt_cont_online_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c38_hyd_hyb_2_opt_cont_online(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c38_hyd_hyb_2_opt_cont_online(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c38_hyd_hyb_2_opt_cont_online(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c38_hyd_hyb_2_opt_cont_online_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
