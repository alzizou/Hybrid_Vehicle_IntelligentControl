/* Include files */

#include "blascompat32.h"
#include "check_1_sfun.h"
#include "c2_check_1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "check_1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[41] = { "cyc", "h", "cyc_tim",
  "sum_spd", "a", "sum_acc", "sum_dec", "dis", "dist", "num_acc", "num_dec",
  "av", "sum_av", "sum_av_p", "pke_1", "pke_dis", "num_spd_0_10",
  "num_spd_20_30", "num_acc_02_04", "num_acc_06_08", "num_dec_02_04",
  "num_dec_06_08", "num_av_0_5", "r", "i", "nargin", "nargout", "t",
  "nur_70_170", "T0", "T1", "prc_spd_0_10", "prc_spd_20_30", "max_acc",
  "prc_acc_02_04", "prc_acc_06_08", "prc_dec_02_04", "prc_dec_06_08", "rpa",
  "prc_av_0_5", "pke" };

/* Function Declarations */
static void initialize_c2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void initialize_params_c2_check_1(SFc2_check_1InstanceStruct
  *chartInstance);
static void enable_c2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void disable_c2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_check_1(SFc2_check_1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_check_1(SFc2_check_1InstanceStruct
  *chartInstance);
static void set_sim_state_c2_check_1(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void sf_c2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void c2_chartstep_c2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void initSimStructsc2_check_1(SFc2_check_1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_pke, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[202]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[101]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static real_T c2_rem(SFc2_check_1InstanceStruct *chartInstance, real_T c2_x,
                     real_T c2_y);
static void c2_eml_scalar_eg(SFc2_check_1InstanceStruct *chartInstance);
static real_T c2_max(SFc2_check_1InstanceStruct *chartInstance, real_T
                     c2_varargin_1[101]);
static real_T c2_mpower(SFc2_check_1InstanceStruct *chartInstance, real_T c2_a);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_check_1, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_check_1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_check_1 = 0U;
}

static void initialize_params_c2_check_1(SFc2_check_1InstanceStruct
  *chartInstance)
{
  real_T c2_dv0[202];
  int32_T c2_i0;
  real_T c2_d0;
  real_T c2_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'nur_70_170' in the parent workspace.\n");
  sf_mex_import_named("nur_70_170", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      c2_dv0, 0, 0, 0U, 1, 0U, 2, 101, 2);
  for (c2_i0 = 0; c2_i0 < 202; c2_i0++) {
    chartInstance->c2_nur_70_170[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T0' in the parent workspace.\n");
  sf_mex_import_named("T0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_T0 = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T1' in the parent workspace.\n");
  sf_mex_import_named("T1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c2_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_T1 = c2_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_check_1(SFc2_check_1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_check_1(SFc2_check_1InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_j_hoistedGlobal;
  real_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  uint8_T c2_k_hoistedGlobal;
  uint8_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  real_T *c2_max_acc;
  real_T *c2_pke;
  real_T *c2_prc_acc_02_04;
  real_T *c2_prc_acc_06_08;
  real_T *c2_prc_av_0_5;
  real_T *c2_prc_dec_02_04;
  real_T *c2_prc_dec_06_08;
  real_T *c2_prc_spd_0_10;
  real_T *c2_prc_spd_20_30;
  real_T *c2_rpa;
  c2_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(11));
  c2_hoistedGlobal = *c2_max_acc;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_pke;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_prc_acc_02_04;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_prc_acc_06_08;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *c2_prc_av_0_5;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *c2_prc_dec_02_04;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *c2_prc_dec_06_08;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = *c2_prc_spd_0_10;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = *c2_prc_spd_20_30;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = *c2_rpa;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_k_hoistedGlobal = chartInstance->c2_is_active_c2_check_1;
  c2_k_u = c2_k_hoistedGlobal;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 10, c2_l_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_check_1(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_max_acc;
  real_T *c2_pke;
  real_T *c2_prc_acc_02_04;
  real_T *c2_prc_acc_06_08;
  real_T *c2_prc_av_0_5;
  real_T *c2_prc_dec_02_04;
  real_T *c2_prc_dec_06_08;
  real_T *c2_prc_spd_0_10;
  real_T *c2_prc_spd_20_30;
  real_T *c2_rpa;
  c2_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_max_acc = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "max_acc");
  *c2_pke = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "pke");
  *c2_prc_acc_02_04 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "prc_acc_02_04");
  *c2_prc_acc_06_08 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "prc_acc_06_08");
  *c2_prc_av_0_5 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 4)), "prc_av_0_5");
  *c2_prc_dec_02_04 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "prc_dec_02_04");
  *c2_prc_dec_06_08 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 6)), "prc_dec_06_08");
  *c2_prc_spd_0_10 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 7)), "prc_spd_0_10");
  *c2_prc_spd_20_30 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "prc_spd_20_30");
  *c2_rpa = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 9)),
    "rpa");
  chartInstance->c2_is_active_c2_check_1 = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 10)), "is_active_c2_check_1");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_check_1(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
}

static void sf_c2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
  int32_T c2_i1;
  real_T *c2_t;
  real_T *c2_prc_spd_0_10;
  real_T *c2_prc_spd_20_30;
  real_T *c2_max_acc;
  real_T *c2_prc_acc_02_04;
  real_T *c2_prc_acc_06_08;
  real_T *c2_prc_dec_02_04;
  real_T *c2_prc_dec_06_08;
  real_T *c2_rpa;
  real_T *c2_prc_av_0_5;
  real_T *c2_pke;
  c2_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_spd_0_10, 1U);
  for (c2_i1 = 0; c2_i1 < 202; c2_i1++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_nur_70_170[c2_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_T0, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_T1, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_spd_20_30, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_max_acc, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_acc_02_04, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_acc_06_08, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_dec_02_04, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_dec_06_08, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_rpa, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_prc_av_0_5, 12U);
  _SFD_DATA_RANGE_CHECK(*c2_pke, 13U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_check_1(chartInstance);
  sf_debug_check_for_state_inconsistency(_check_1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_t;
  int32_T c2_i2;
  real_T c2_b_nur_70_170[202];
  real_T c2_b_T0;
  real_T c2_b_T1;
  uint32_T c2_debug_family_var_map[41];
  real_T c2_cyc[202];
  real_T c2_h[2];
  real_T c2_cyc_tim;
  real_T c2_sum_spd;
  real_T c2_a[202];
  real_T c2_sum_acc;
  real_T c2_sum_dec;
  real_T c2_dis[101];
  real_T c2_dist;
  real_T c2_num_acc;
  real_T c2_num_dec;
  real_T c2_av[202];
  real_T c2_sum_av;
  real_T c2_sum_av_p;
  real_T c2_pke_1;
  real_T c2_pke_dis;
  real_T c2_num_spd_0_10;
  real_T c2_num_spd_20_30;
  real_T c2_num_acc_02_04;
  real_T c2_num_acc_06_08;
  real_T c2_num_dec_02_04;
  real_T c2_num_dec_06_08;
  real_T c2_num_av_0_5;
  real_T c2_r;
  real_T c2_i;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 10.0;
  real_T c2_prc_spd_0_10;
  real_T c2_prc_spd_20_30;
  real_T c2_max_acc;
  real_T c2_prc_acc_02_04;
  real_T c2_prc_acc_06_08;
  real_T c2_prc_dec_02_04;
  real_T c2_prc_dec_06_08;
  real_T c2_rpa;
  real_T c2_prc_av_0_5;
  real_T c2_pke;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  real_T c2_b_i;
  real_T c2_b_a;
  real_T c2_y;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_c_a;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_d_a;
  real_T c2_d_y;
  real_T c2_e_a;
  real_T c2_b_b;
  real_T c2_e_y;
  real_T c2_f_a;
  real_T c2_f_y;
  real_T c2_c_b;
  real_T c2_g_y;
  real_T c2_g_a;
  real_T c2_h_y;
  real_T c2_b_A;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_i_y;
  real_T c2_h_a;
  real_T c2_d_b;
  real_T c2_j_y;
  real_T c2_c_i;
  real_T c2_e_b;
  real_T c2_k_y;
  real_T c2_c_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_f_b;
  real_T c2_l_y;
  real_T c2_d_A;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_d_i;
  real_T c2_g_b;
  real_T c2_m_y;
  real_T c2_i_a;
  real_T c2_n_y;
  real_T c2_e_A;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_o_y;
  int32_T c2_i8;
  real_T c2_j_a[101];
  real_T c2_f_A;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_i;
  real_T c2_h_b;
  real_T c2_p_y;
  real_T c2_g_A;
  real_T c2_B;
  real_T c2_s_x;
  real_T c2_q_y;
  real_T c2_t_x;
  real_T c2_r_y;
  real_T c2_u_x;
  real_T c2_s_y;
  real_T c2_i_b;
  real_T c2_t_y;
  real_T c2_h_A;
  real_T c2_b_B;
  real_T c2_v_x;
  real_T c2_u_y;
  real_T c2_w_x;
  real_T c2_v_y;
  real_T c2_x_x;
  real_T c2_w_y;
  real_T c2_f_i;
  real_T c2_j_b;
  real_T c2_x_y;
  real_T c2_i_A;
  real_T c2_c_B;
  real_T c2_y_x;
  real_T c2_y_y;
  real_T c2_ab_x;
  real_T c2_ab_y;
  real_T c2_bb_x;
  real_T c2_bb_y;
  real_T c2_k_b;
  real_T c2_cb_y;
  real_T c2_j_A;
  real_T c2_d_B;
  real_T c2_cb_x;
  real_T c2_db_y;
  real_T c2_db_x;
  real_T c2_eb_y;
  real_T c2_eb_x;
  real_T c2_fb_y;
  real_T c2_g_i;
  real_T c2_l_b;
  real_T c2_gb_y;
  real_T c2_k_A;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_l_A;
  real_T c2_e_B;
  real_T c2_ib_x;
  real_T c2_hb_y;
  real_T c2_jb_x;
  real_T c2_ib_y;
  real_T c2_kb_x;
  real_T c2_jb_y;
  real_T c2_kb_y;
  real_T c2_m_A;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_h_i;
  real_T c2_k_a;
  real_T c2_lb_y;
  real_T c2_l_a;
  real_T c2_mb_y;
  real_T c2_m_a;
  real_T c2_nb_y;
  real_T c2_n_a;
  real_T c2_ob_y;
  real_T c2_n_A;
  real_T c2_f_B;
  real_T c2_ob_x;
  real_T c2_pb_y;
  real_T c2_pb_x;
  real_T c2_qb_y;
  real_T c2_qb_x;
  real_T c2_rb_y;
  real_T c2_sb_y;
  real_T c2_o_A;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_tb_x;
  real_T *c2_b_t;
  real_T *c2_b_prc_spd_0_10;
  real_T *c2_b_prc_spd_20_30;
  real_T *c2_b_max_acc;
  real_T *c2_b_prc_acc_02_04;
  real_T *c2_b_prc_acc_06_08;
  real_T *c2_b_prc_dec_02_04;
  real_T *c2_b_prc_dec_06_08;
  real_T *c2_b_rpa;
  real_T *c2_b_prc_av_0_5;
  real_T *c2_b_pke;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  c2_b_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_b_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_b_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_b_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_b_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_b_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_t;
  c2_b_hoistedGlobal = chartInstance->c2_T0;
  c2_c_hoistedGlobal = chartInstance->c2_T1;
  c2_t = c2_hoistedGlobal;
  for (c2_i2 = 0; c2_i2 < 202; c2_i2++) {
    c2_b_nur_70_170[c2_i2] = chartInstance->c2_nur_70_170[c2_i2];
  }

  c2_b_T0 = c2_b_hoistedGlobal;
  c2_b_T1 = c2_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 41U, 41U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_cyc, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_h, 1U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_cyc_tim, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_sum_spd, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_a, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_sum_acc, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_sum_dec, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_dis, 7U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_dist, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_acc, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_dec, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_av, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_sum_av, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_sum_av_p, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pke_1, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pke_dis, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_spd_0_10, 16U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_spd_20_30, 17U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_acc_02_04, 18U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_acc_06_08, 19U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_dec_02_04, 20U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_dec_06_08, 21U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num_av_0_5, 22U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r, 23U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_i, 24U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 26U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_t, 27U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_b_nur_70_170, 28U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_T0, 29U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_T1, 30U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_spd_0_10, 31U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_spd_20_30, 32U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_max_acc, 33U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_acc_02_04, 34U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_acc_06_08, 35U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_dec_02_04, 36U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_dec_06_08, 37U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_rpa, 38U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_av_0_5, 39U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pke, 40U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i3 = 0; c2_i3 < 202; c2_i3++) {
    c2_cyc[c2_i3] = c2_b_nur_70_170[c2_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_h[c2_i4] = 101.0 + -99.0 * (real_T)c2_i4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_cyc_tim = 101.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_sum_spd = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i5 = 0; c2_i5 < 202; c2_i5++) {
    c2_a[c2_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_sum_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_sum_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i6 = 0; c2_i6 < 101; c2_i6++) {
    c2_dis[c2_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_dist = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_num_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_num_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i7 = 0; c2_i7 < 202; c2_i7++) {
    c2_av[c2_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_sum_av = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_sum_av_p = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_pke_1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_pke_dis = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_num_spd_0_10 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_num_spd_20_30 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_num_acc_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_num_acc_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_num_dec_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_num_dec_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_num_av_0_5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_prc_spd_0_10 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_prc_spd_20_30 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_max_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_prc_acc_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_prc_acc_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_prc_dec_02_04 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_prc_dec_06_08 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_rpa = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_prc_av_0_5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_pke = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  if (CV_EML_IF(0, 0, c2_t >= c2_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
    c2_r = c2_rem(chartInstance, c2_t, c2_b_T1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
    if (CV_EML_IF(0, 1, c2_r == 0.0)) {
      c2_i = 1.0;
      c2_b_i = 1.0;
      while (c2_b_i <= 101.0) {
        c2_i = c2_b_i;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
        c2_sum_spd += c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
        if (CV_EML_IF(0, 2, c2_i > 1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
          c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK("i",
            c2_i), 1, 101, 1, 0) - 1] = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
            (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) - 1];
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
          c2_b_a = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] -
            c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i-1", c2_i - 1.0), 1, 101, 1, 0) + 100];
          c2_y = c2_b_a * 0.27777777777777779;
          c2_A = c2_y;
          c2_x = c2_A;
          c2_b_x = c2_x;
          c2_c_x = c2_b_x;
          c2_b_y = c2_c_x;
          c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK("i",
            c2_i), 1, 101, 1, 0) + 100] = c2_b_y;
        }

        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
        if (CV_EML_IF(0, 3, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
          c2_num_acc++;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
          c2_sum_acc += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
          c2_c_a = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
          c2_b = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
          c2_c_y = c2_c_a * c2_b;
          c2_d_a = c2_c_y;
          c2_d_y = c2_d_a * 0.27777777777777779;
          c2_e_a = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("i+1", c2_i + 1.0), 1, 101, 1, 0) + 100];
          c2_b_b = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i+1", c2_i + 1.0), 1, 101, 1, 0) + 100];
          c2_e_y = c2_e_a * c2_b_b;
          c2_f_a = c2_e_y;
          c2_f_y = c2_f_a * 0.27777777777777779;
          c2_c_b = c2_d_y + c2_f_y;
          c2_g_y = 0.5 * c2_c_b;
          c2_sum_av_p += c2_g_y;
        }

        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
        if (CV_EML_IF(0, 4, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
          c2_num_dec++;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
          c2_sum_dec += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
        }

        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
        c2_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)_SFD_INTEGER_CHECK("i",
          c2_i), 1, 101, 1, 0) - 1] = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
          (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
        c2_g_a = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
        c2_h_y = c2_g_a * 10.0;
        c2_b_A = c2_h_y;
        c2_d_x = c2_b_A;
        c2_e_x = c2_d_x;
        c2_f_x = c2_e_x;
        c2_i_y = c2_f_x / 36.0;
        c2_h_a = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
        c2_d_b = c2_i_y;
        c2_j_y = c2_h_a * c2_d_b;
        c2_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)_SFD_INTEGER_CHECK("i",
          c2_i), 1, 101, 1, 0) + 100] = c2_j_y;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
        c2_sum_av += c2_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
        c2_b_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 0, 0);
      c2_i = 1.0;
      c2_c_i = 1.0;
      while (c2_c_i <= 101.0) {
        c2_i = c2_c_i;
        CV_EML_FOR(0, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
        if (CV_EML_IF(0, 5, c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < 10.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
          c2_num_spd_0_10++;
        }

        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
        guard6 = FALSE;
        if (CV_EML_COND(0, 0, c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < 30.0)) {
          if (CV_EML_COND(0, 1, c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc",
                (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] >=
                          20.0)) {
            CV_EML_MCDC(0, 0, TRUE);
            CV_EML_IF(0, 6, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
            c2_num_spd_20_30++;
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

        c2_c_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 85);
      c2_e_b = c2_num_spd_0_10;
      c2_k_y = c2_e_b;
      c2_c_A = c2_k_y;
      c2_g_x = c2_c_A;
      c2_h_x = c2_g_x;
      c2_i_x = c2_h_x;
      c2_prc_spd_0_10 = c2_i_x / 101.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
      c2_f_b = c2_num_spd_20_30;
      c2_l_y = c2_f_b;
      c2_d_A = c2_l_y;
      c2_j_x = c2_d_A;
      c2_k_x = c2_j_x;
      c2_l_x = c2_k_x;
      c2_prc_spd_20_30 = c2_l_x / 101.0;
      c2_i = 1.0;
      c2_d_i = 1.0;
      while (c2_d_i <= 101.0) {
        c2_i = c2_d_i;
        CV_EML_FOR(0, 2, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
        c2_g_b = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
        c2_m_y = c2_g_b;
        c2_i_a = c2_m_y;
        c2_n_y = c2_i_a * 10.0;
        c2_e_A = c2_n_y;
        c2_m_x = c2_e_A;
        c2_n_x = c2_m_x;
        c2_o_x = c2_n_x;
        c2_o_y = c2_o_x / 36.0;
        c2_dis[_SFD_EML_ARRAY_BOUNDS_CHECK("dis", (int32_T)_SFD_INTEGER_CHECK(
          "i", c2_i), 1, 101, 1, 0) - 1] = c2_o_y;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 96);
        c2_dist += c2_dis[_SFD_EML_ARRAY_BOUNDS_CHECK("dis", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) - 1];
        c2_d_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 2, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
      for (c2_i8 = 0; c2_i8 < 101; c2_i8++) {
        c2_j_a[c2_i8] = c2_a[c2_i8 + 101];
      }

      c2_f_A = c2_max(chartInstance, c2_j_a);
      c2_p_x = c2_f_A;
      c2_q_x = c2_p_x;
      c2_r_x = c2_q_x;
      c2_max_acc = c2_r_x / 6.0;
      c2_i = 1.0;
      c2_e_i = 1.0;
      while (c2_e_i <= 101.0) {
        c2_i = c2_e_i;
        CV_EML_FOR(0, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 106);
        guard5 = FALSE;
        if (CV_EML_COND(0, 2, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < 0.4)) {
          if (CV_EML_COND(0, 3, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] >= 0.2)) {
            CV_EML_MCDC(0, 1, TRUE);
            CV_EML_IF(0, 7, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
            c2_num_acc_02_04++;
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

        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 112);
        guard4 = FALSE;
        if (CV_EML_COND(0, 4, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < 0.8)) {
          if (CV_EML_COND(0, 5, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] >= 0.6)) {
            CV_EML_MCDC(0, 2, TRUE);
            CV_EML_IF(0, 8, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 113);
            c2_num_acc_06_08++;
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

        c2_e_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 3, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 123);
      c2_h_b = c2_num_acc_02_04;
      c2_p_y = c2_h_b;
      c2_g_A = c2_p_y;
      c2_B = c2_num_acc;
      c2_s_x = c2_g_A;
      c2_q_y = c2_B;
      c2_t_x = c2_s_x;
      c2_r_y = c2_q_y;
      c2_u_x = c2_t_x;
      c2_s_y = c2_r_y;
      c2_prc_acc_02_04 = c2_u_x / c2_s_y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 125);
      c2_i_b = c2_num_acc_06_08;
      c2_t_y = c2_i_b;
      c2_h_A = c2_t_y;
      c2_b_B = c2_num_acc;
      c2_v_x = c2_h_A;
      c2_u_y = c2_b_B;
      c2_w_x = c2_v_x;
      c2_v_y = c2_u_y;
      c2_x_x = c2_w_x;
      c2_w_y = c2_v_y;
      c2_prc_acc_06_08 = c2_x_x / c2_w_y;
      c2_i = 1.0;
      c2_f_i = 1.0;
      while (c2_f_i <= 101.0) {
        c2_i = c2_f_i;
        CV_EML_FOR(0, 4, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 137U);
        guard3 = FALSE;
        if (CV_EML_COND(0, 6, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < -0.2)) {
          if (CV_EML_COND(0, 7, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] >= -0.4)) {
            CV_EML_MCDC(0, 3, TRUE);
            CV_EML_IF(0, 9, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 138U);
            c2_num_dec_02_04++;
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

        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 143U);
        guard2 = FALSE;
        if (CV_EML_COND(0, 8, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < -0.6)) {
          if (CV_EML_COND(0, 9, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
                _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] >= -0.8)) {
            CV_EML_MCDC(0, 4, TRUE);
            CV_EML_IF(0, 10, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 144U);
            c2_num_dec_06_08++;
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

        c2_f_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 4, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 154U);
      c2_j_b = c2_num_dec_02_04;
      c2_x_y = c2_j_b;
      c2_i_A = c2_x_y;
      c2_c_B = c2_num_dec;
      c2_y_x = c2_i_A;
      c2_y_y = c2_c_B;
      c2_ab_x = c2_y_x;
      c2_ab_y = c2_y_y;
      c2_bb_x = c2_ab_x;
      c2_bb_y = c2_ab_y;
      c2_prc_dec_02_04 = c2_bb_x / c2_bb_y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 156U);
      c2_k_b = c2_num_dec_06_08;
      c2_cb_y = c2_k_b;
      c2_j_A = c2_cb_y;
      c2_d_B = c2_num_dec;
      c2_cb_x = c2_j_A;
      c2_db_y = c2_d_B;
      c2_db_x = c2_cb_x;
      c2_eb_y = c2_db_y;
      c2_eb_x = c2_db_x;
      c2_fb_y = c2_eb_y;
      c2_prc_dec_06_08 = c2_eb_x / c2_fb_y;
      c2_i = 1.0;
      c2_g_i = 1.0;
      while (c2_g_i <= 101.0) {
        c2_i = c2_g_i;
        CV_EML_FOR(0, 5, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 166U);
        guard1 = FALSE;
        if (CV_EML_COND(0, 10, c2_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] < 5.0)) {
          if (CV_EML_COND(0, 11, c2_av[_SFD_EML_ARRAY_BOUNDS_CHECK("av",
                (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] >=
                          0.0)) {
            CV_EML_MCDC(0, 5, TRUE);
            CV_EML_IF(0, 11, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 167U);
            c2_num_av_0_5++;
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

        c2_g_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 5, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 185U);
      c2_l_b = c2_num_av_0_5;
      c2_gb_y = c2_l_b;
      c2_k_A = c2_gb_y;
      c2_fb_x = c2_k_A;
      c2_gb_x = c2_fb_x;
      c2_hb_x = c2_gb_x;
      c2_prc_av_0_5 = c2_hb_x / 101.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 192U);
      c2_l_A = c2_sum_av_p;
      c2_e_B = c2_dist;
      c2_ib_x = c2_l_A;
      c2_hb_y = c2_e_B;
      c2_jb_x = c2_ib_x;
      c2_ib_y = c2_hb_y;
      c2_kb_x = c2_jb_x;
      c2_jb_y = c2_ib_y;
      c2_kb_y = c2_kb_x / c2_jb_y;
      c2_m_A = c2_kb_y;
      c2_lb_x = c2_m_A;
      c2_mb_x = c2_lb_x;
      c2_nb_x = c2_mb_x;
      c2_rpa = c2_nb_x / 0.2;
      c2_i = 2.0;
      c2_h_i = 2.0;
      while (c2_h_i <= 101.0) {
        c2_i = c2_h_i;
        CV_EML_FOR(0, 6, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 202U);
        if (CV_EML_IF(0, 12, c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
              _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100] > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 203U);
          c2_k_a = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i+1", c2_i + 1.0), 1, 101, 1, 0) + 100];
          c2_lb_y = c2_k_a * 0.27777777777777779;
          c2_l_a = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
          c2_mb_y = c2_l_a * 0.27777777777777779;
          c2_pke_1 += c2_mpower(chartInstance, c2_lb_y) - c2_mpower
            (chartInstance, c2_mb_y);
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 204U);
          c2_m_a = c2_cyc[_SFD_EML_ARRAY_BOUNDS_CHECK("cyc", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 101, 1, 0) + 100];
          c2_nb_y = c2_m_a * 0.27777777777777779;
          c2_n_a = c2_nb_y;
          c2_ob_y = c2_n_a;
          c2_pke_dis += c2_ob_y;
        }

        c2_h_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 6, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 208U);
      c2_n_A = c2_pke_1;
      c2_f_B = c2_pke_dis;
      c2_ob_x = c2_n_A;
      c2_pb_y = c2_f_B;
      c2_pb_x = c2_ob_x;
      c2_qb_y = c2_pb_y;
      c2_qb_x = c2_pb_x;
      c2_rb_y = c2_qb_y;
      c2_sb_y = c2_qb_x / c2_rb_y;
      c2_o_A = c2_sb_y;
      c2_rb_x = c2_o_A;
      c2_sb_x = c2_rb_x;
      c2_tb_x = c2_sb_x;
      c2_pke = c2_tb_x / 2.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -208);
  sf_debug_symbol_scope_pop();
  *c2_b_prc_spd_0_10 = c2_prc_spd_0_10;
  *c2_b_prc_spd_20_30 = c2_prc_spd_20_30;
  *c2_b_max_acc = c2_max_acc;
  *c2_b_prc_acc_02_04 = c2_prc_acc_02_04;
  *c2_b_prc_acc_06_08 = c2_prc_acc_06_08;
  *c2_b_prc_dec_02_04 = c2_prc_dec_02_04;
  *c2_b_prc_dec_06_08 = c2_prc_dec_06_08;
  *c2_b_rpa = c2_rpa;
  *c2_b_prc_av_0_5 = c2_prc_av_0_5;
  *c2_b_pke = c2_pke;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_check_1(SFc2_check_1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_pke, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_pke), &c2_thisId);
  sf_mex_destroy(&c2_pke);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_pke;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_pke = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_pke), &c2_thisId);
  sf_mex_destroy(&c2_pke);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  real_T c2_b_inData[202];
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  real_T c2_u[202];
  const mxArray *c2_y = NULL;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    for (c2_i11 = 0; c2_i11 < 101; c2_i11++) {
      c2_b_inData[c2_i11 + c2_i9] = (*(real_T (*)[202])c2_inData)[c2_i11 + c2_i9];
    }

    c2_i9 += 101;
  }

  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
    for (c2_i14 = 0; c2_i14 < 101; c2_i14++) {
      c2_u[c2_i14 + c2_i12] = c2_b_inData[c2_i14 + c2_i12];
    }

    c2_i12 += 101;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 101, 2));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[202])
{
  real_T c2_dv1[202];
  int32_T c2_i15;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 101,
                2);
  for (c2_i15 = 0; c2_i15 < 202; c2_i15++) {
    c2_y[c2_i15] = c2_dv1[c2_i15];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_nur_70_170;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[202];
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_b_nur_70_170 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_nur_70_170), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_nur_70_170);
  c2_i16 = 0;
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    for (c2_i18 = 0; c2_i18 < 101; c2_i18++) {
      (*(real_T (*)[202])c2_outData)[c2_i18 + c2_i16] = c2_y[c2_i18 + c2_i16];
    }

    c2_i16 += 101;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i19;
  real_T c2_b_inData[101];
  int32_T c2_i20;
  real_T c2_u[101];
  const mxArray *c2_y = NULL;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i19 = 0; c2_i19 < 101; c2_i19++) {
    c2_b_inData[c2_i19] = (*(real_T (*)[101])c2_inData)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 101; c2_i20++) {
    c2_u[c2_i20] = c2_b_inData[c2_i20];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 101));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[101])
{
  real_T c2_dv2[101];
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 101);
  for (c2_i21 = 0; c2_i21 < 101; c2_i21++) {
    c2_y[c2_i21] = c2_dv2[c2_i21];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_dis;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[101];
  int32_T c2_i22;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_dis = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dis), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_dis);
  for (c2_i22 = 0; c2_i22 < 101; c2_i22++) {
    (*(real_T (*)[101])c2_outData)[c2_i22] = c2_y[c2_i22];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i23;
  real_T c2_b_inData[2];
  int32_T c2_i24;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    c2_b_inData[c2_i23] = (*(real_T (*)[2])c2_inData)[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_u[c2_i24] = c2_b_inData[c2_i24];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_check_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i25;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18));
  for (c2_i25 = 0; c2_i25 < 18; c2_i25++) {
    c2_r0 = &c2_info[c2_i25];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i25);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "rem";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[0].fileTimeLo = 2721966592U;
  c2_info[0].fileTimeHi = 30107998U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[1].name = "eml_scalar_eg";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[1].fileTimeLo = 3201966592U;
  c2_info[1].fileTimeHi = 30107998U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[2].name = "eml_scalexp_alloc";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[2].fileTimeLo = 3201966592U;
  c2_info[2].fileTimeHi = 30107998U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[3].name = "eml_scalar_rem";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c2_info[3].fileTimeLo = 2561966592U;
  c2_info[3].fileTimeHi = 30107998U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mrdivide";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[4].fileTimeLo = 2311411456U;
  c2_info[4].fileTimeHi = 30130914U;
  c2_info[4].mFileTimeLo = 3767347712U;
  c2_info[4].mFileTimeHi = 30114278U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].name = "rdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[5].fileTimeLo = 3681966592U;
  c2_info[5].fileTimeHi = 30107998U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].name = "eml_div";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[6].fileTimeLo = 2221966592U;
  c2_info[6].fileTimeHi = 30107998U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "mtimes";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].fileTimeLo = 3767347712U;
  c2_info[7].fileTimeHi = 30114278U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "max";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[8].fileTimeLo = 2181966592U;
  c2_info[8].fileTimeHi = 30107998U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[9].name = "eml_min_or_max";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[9].fileTimeLo = 3121966592U;
  c2_info[9].fileTimeHi = 30107998U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[10].name = "eml_const_nonsingleton_dim";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[10].fileTimeLo = 2201966592U;
  c2_info[10].fileTimeHi = 30107998U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[11].name = "eml_index_class";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[11].fileTimeLo = 3021966592U;
  c2_info[11].fileTimeHi = 30107998U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[12].name = "isnan";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[12].fileTimeLo = 2841966592U;
  c2_info[12].fileTimeHi = 30107998U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[13].name = "eml_index_plus";
  c2_info[13].dominantType = "int32";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[13].fileTimeLo = 3021966592U;
  c2_info[13].fileTimeHi = 30107998U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "mpower";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[14].fileTimeLo = 3661966592U;
  c2_info[14].fileTimeHi = 30107998U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[15].name = "power";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[15].fileTimeLo = 3681966592U;
  c2_info[15].fileTimeHi = 30107998U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[16].name = "eml_scalar_floor";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[16].fileTimeLo = 2501966592U;
  c2_info[16].fileTimeHi = 30107998U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[17].name = "eml_error";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[17].fileTimeLo = 2241966592U;
  c2_info[17].fileTimeHi = 30107998U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
}

static real_T c2_rem(SFc2_check_1InstanceStruct *chartInstance, real_T c2_x,
                     real_T c2_y)
{
  real_T c2_xk;
  real_T c2_yk;
  real_T c2_b_x;
  real_T c2_b_y;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_x;
  c2_yk = c2_y;
  c2_b_x = c2_xk;
  c2_b_y = c2_yk;
  return muDoubleScalarRem(c2_b_x, c2_b_y);
}

static void c2_eml_scalar_eg(SFc2_check_1InstanceStruct *chartInstance)
{
}

static real_T c2_max(SFc2_check_1InstanceStruct *chartInstance, real_T
                     c2_varargin_1[101])
{
  real_T c2_mtmp;
  int32_T c2_itmp;
  int32_T c2_ix;
  real_T c2_x;
  boolean_T c2_b;
  boolean_T c2_searchingForNonNaN;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_a;
  real_T c2_b_x;
  boolean_T c2_b_b;
  int32_T c2_b_a;
  int32_T c2_i26;
  int32_T c2_b_ix;
  real_T c2_b_mtmp;
  boolean_T guard1 = FALSE;
  boolean_T exitg1;
  c2_mtmp = c2_varargin_1[0];
  c2_itmp = 2;
  c2_ix = 1;
  c2_x = c2_mtmp;
  c2_b = muDoubleScalarIsNaN(c2_x);
  guard1 = FALSE;
  if (c2_b) {
    c2_searchingForNonNaN = TRUE;
    c2_k = 2;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (c2_k < 102)) {
      c2_b_k = c2_k;
      c2_a = c2_ix + 1;
      c2_ix = c2_a;
      c2_b_x = c2_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 101, 1, 0) - 1];
      c2_b_b = muDoubleScalarIsNaN(c2_b_x);
      if (!c2_b_b) {
        c2_mtmp = c2_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 101, 1, 0) - 1];
        c2_itmp = c2_b_k + 1;
        c2_searchingForNonNaN = FALSE;
        exitg1 = 1U;
      } else {
        c2_k++;
      }
    }

    if (c2_searchingForNonNaN) {
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c2_b_a = c2_itmp;
    c2_i26 = c2_b_a;
    for (c2_b_ix = c2_i26; c2_b_ix < 102; c2_b_ix++) {
      c2_ix = c2_b_ix;
      if (c2_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 101, 1, 0) - 1] > c2_mtmp)
      {
        c2_mtmp = c2_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 101, 1, 0) - 1];
      }
    }
  }

  c2_b_mtmp = c2_mtmp;
  return c2_b_mtmp;
}

static real_T c2_mpower(SFc2_check_1InstanceStruct *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i27;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i27, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i27;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_check_1, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_check_1), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_check_1);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_check_1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_check_1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_check_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(952311617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4073292635U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3323081173U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3995972353U);
}

mxArray *sf_c2_check_1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1293757485U);
    pr[1] = (double)(1682640044U);
    pr[2] = (double)(3520962836U);
    pr[3] = (double)(3374928782U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(101);
      pr[1] = (double)(2);
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

static const mxArray *sf_get_sim_state_info_c2_check_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[13],T\"max_acc\",},{M[1],M[20],T\"pke\",},{M[1],M[14],T\"prc_acc_02_04\",},{M[1],M[15],T\"prc_acc_06_08\",},{M[1],M[19],T\"prc_av_0_5\",},{M[1],M[16],T\"prc_dec_02_04\",},{M[1],M[17],T\"prc_dec_06_08\",},{M[1],M[5],T\"prc_spd_0_10\",},{M[1],M[12],T\"prc_spd_20_30\",},{M[1],M[18],T\"rpa\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_check_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_check_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_check_1InstanceStruct *chartInstance;
    chartInstance = (SFc2_check_1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_check_1MachineNumber_,
          2,
          1,
          1,
          14,
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
          init_script_number_translation(_check_1MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_check_1MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_check_1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"prc_spd_0_10");
          _SFD_SET_DATA_PROPS(2,10,0,0,"nur_70_170");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,8952);
        _SFD_CV_INIT_EML_IF(0,0,1478,1486,-1,8948);
        _SFD_CV_INIT_EML_IF(0,1,1508,1515,-1,8944);
        _SFD_CV_INIT_EML_IF(0,2,1622,1628,-1,1745);
        _SFD_CV_INIT_EML_IF(0,3,1762,1773,-1,2013);
        _SFD_CV_INIT_EML_IF(0,4,2030,2041,-1,2144);
        _SFD_CV_INIT_EML_IF(0,5,2509,2523,-1,2592);
        _SFD_CV_INIT_EML_IF(0,6,2733,2763,-1,2834);
        _SFD_CV_INIT_EML_IF(0,7,4230,4258,-1,4329);
        _SFD_CV_INIT_EML_IF(0,8,4468,4496,-1,4567);
        _SFD_CV_INIT_EML_IF(0,9,5594,5624,-1,5695);
        _SFD_CV_INIT_EML_IF(0,10,5836,5866,-1,5937);
        _SFD_CV_INIT_EML_IF(0,11,6870,6896,-1,6961);
        _SFD_CV_INIT_EML_IF(0,12,8391,8402,-1,8564);
        _SFD_CV_INIT_EML_FOR(0,0,1548,1564,2282);
        _SFD_CV_INIT_EML_FOR(0,1,2477,2493,3207);
        _SFD_CV_INIT_EML_FOR(0,2,3772,3788,3881);
        _SFD_CV_INIT_EML_FOR(0,3,4081,4097,4805);
        _SFD_CV_INIT_EML_FOR(0,4,5443,5459,6177);
        _SFD_CV_INIT_EML_FOR(0,5,6838,6854,7540);
        _SFD_CV_INIT_EML_FOR(0,6,8193,8209,8580);

        {
          static int condStart[] = { 2736, 2751 };

          static int condEnd[] = { 2747, 2763 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,2736,2763,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4233, 4247 };

          static int condEnd[] = { 4243, 4258 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4233,4258,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4471, 4485 };

          static int condEnd[] = { 4481, 4496 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,2,4471,4496,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5597, 5612 };

          static int condEnd[] = { 5608, 5624 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,3,5597,5624,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5839, 5854 };

          static int condEnd[] = { 5850, 5866 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,4,5839,5866,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6873, 6886 };

          static int condEnd[] = { 6882, 6896 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,5,6873,6896,2,10,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 101;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_t;
          real_T *c2_prc_spd_0_10;
          real_T *c2_prc_spd_20_30;
          real_T *c2_max_acc;
          real_T *c2_prc_acc_02_04;
          real_T *c2_prc_acc_06_08;
          real_T *c2_prc_dec_02_04;
          real_T *c2_prc_dec_06_08;
          real_T *c2_rpa;
          real_T *c2_prc_av_0_5;
          real_T *c2_pke;
          c2_pke = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c2_prc_av_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c2_rpa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c2_prc_dec_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c2_prc_dec_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c2_prc_acc_06_08 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c2_prc_acc_02_04 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_max_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_prc_spd_20_30 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_prc_spd_0_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_prc_spd_0_10);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_nur_70_170);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_T0);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c2_T1);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_prc_spd_20_30);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_max_acc);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_prc_acc_02_04);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_prc_acc_06_08);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_prc_dec_02_04);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_prc_dec_06_08);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_rpa);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_prc_av_0_5);
          _SFD_SET_DATA_VALUE_PTR(13U, c2_pke);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_check_1MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_check_1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_check_1InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
  initialize_c2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_check_1(void *chartInstanceVar)
{
  enable_c2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_check_1(void *chartInstanceVar)
{
  disable_c2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_check_1(void *chartInstanceVar)
{
  sf_c2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_check_1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_check_1((SFc2_check_1InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_check_1();/* state var info */
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

extern void sf_internal_set_sim_state_c2_check_1(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_check_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_check_1((SFc2_check_1InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_check_1(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_check_1(S);
}

static void sf_opaque_set_sim_state_c2_check_1(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_check_1(S, st);
}

static void sf_opaque_terminate_c2_check_1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_check_1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_check_1((SFc2_check_1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_check_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_check_1((SFc2_check_1InstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_check_1(SimStruct *S)
{
  /* Actual parameters from chart:
     T0 T1 nur_70_170
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for nur_70_170*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"check_1","check_1",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"check_1","check_1",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"check_1","check_1",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"check_1","check_1",2,1);
      sf_mark_chart_reusable_outputs(S,"check_1","check_1",2,10);
    }

    sf_set_rtw_dwork_info(S,"check_1","check_1",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1921273225U));
  ssSetChecksum1(S,(3541841808U));
  ssSetChecksum2(S,(317237950U));
  ssSetChecksum3(S,(3752220303U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_check_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "check_1", "check_1",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_check_1(SimStruct *S)
{
  SFc2_check_1InstanceStruct *chartInstance;
  chartInstance = (SFc2_check_1InstanceStruct *)malloc(sizeof
    (SFc2_check_1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_check_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_check_1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_check_1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_check_1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_check_1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_check_1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_check_1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_check_1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_check_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_check_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_check_1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_check_1;
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

void c2_check_1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_check_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_check_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_check_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_check_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
