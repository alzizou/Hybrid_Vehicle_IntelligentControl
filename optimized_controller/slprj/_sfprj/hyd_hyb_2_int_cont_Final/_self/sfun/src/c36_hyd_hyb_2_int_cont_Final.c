/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hyd_hyb_2_int_cont_Final_sfun.h"
#include "c36_hyd_hyb_2_int_cont_Final.h"
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
static const char * c36_debug_family_names[17] = { "q", "u1", "r", "i", "k",
  "den", "nargin", "nargout", "x_feat", "teta_new_10", "init", "t", "T0", "T1",
  "mem", "u", "dist" };

/* Function Declarations */
static void initialize_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void initialize_params_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void enable_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void disable_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void c36_update_debugger_state_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void set_sim_state_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_st);
static void finalize_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void sf_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void c36_chartstep_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void initSimStructsc36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_emlrt_marshallIn(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c36_dist, const char_T *c36_identifier, real_T
  c36_y[4]);
static void c36_b_emlrt_marshallIn(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[4]);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_c_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_d_emlrt_marshallIn(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[40]);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_info_helper(const mxArray **c36_info);
static const mxArray *c36_emlrt_marshallOut(char * c36_u);
static const mxArray *c36_b_emlrt_marshallOut(uint32_T c36_u);
static real_T c36_rem(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
                      *chartInstance, real_T c36_x, real_T c36_y);
static void c36_eml_scalar_eg(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance);
static void c36_b_eml_scalar_eg(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance);
static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_e_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_f_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_b_is_active_c36_hyd_hyb_2_int_cont_Final, const char_T *c36_identifier);
static uint8_T c36_g_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void init_dsm_address_info(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c36_is_active_c36_hyd_hyb_2_int_cont_Final = 0U;
}

static void initialize_params_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  real_T c36_dv0[40];
  int32_T c36_i0;
  real_T c36_d0;
  real_T c36_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'teta_new_10' in the parent workspace.\n");
  sf_mex_import_named("teta_new_10", sf_mex_get_sfun_param(chartInstance->S, 2,
    0), c36_dv0, 0, 0, 0U, 1, 0U, 2, 10, 4);
  for (c36_i0 = 0; c36_i0 < 40; c36_i0++) {
    chartInstance->c36_teta_new_10[c36_i0] = c36_dv0[c36_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T0' in the parent workspace.\n");
  sf_mex_import_named("T0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c36_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c36_T0 = c36_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T1' in the parent workspace.\n");
  sf_mex_import_named("T1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c36_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c36_T1 = c36_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c36_update_debugger_state_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  const mxArray *c36_st;
  const mxArray *c36_y = NULL;
  int32_T c36_i1;
  real_T c36_u[4];
  const mxArray *c36_b_y = NULL;
  int32_T c36_i2;
  real_T c36_b_u[4];
  const mxArray *c36_c_y = NULL;
  uint8_T c36_hoistedGlobal;
  uint8_T c36_c_u;
  const mxArray *c36_d_y = NULL;
  real_T (*c36_d_u)[4];
  real_T (*c36_dist)[4];
  c36_dist = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c36_d_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c36_st = NULL;
  c36_st = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_createcellarray(3), FALSE);
  for (c36_i1 = 0; c36_i1 < 4; c36_i1++) {
    c36_u[c36_i1] = (*c36_dist)[c36_i1];
  }

  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c36_y, 0, c36_b_y);
  for (c36_i2 = 0; c36_i2 < 4; c36_i2++) {
    c36_b_u[c36_i2] = (*c36_d_u)[c36_i2];
  }

  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", c36_b_u, 0, 0U, 1U, 0U, 1, 4),
                FALSE);
  sf_mex_setcell(c36_y, 1, c36_c_y);
  c36_hoistedGlobal = chartInstance->c36_is_active_c36_hyd_hyb_2_int_cont_Final;
  c36_c_u = c36_hoistedGlobal;
  c36_d_y = NULL;
  sf_mex_assign(&c36_d_y, sf_mex_create("y", &c36_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c36_y, 2, c36_d_y);
  sf_mex_assign(&c36_st, c36_y, FALSE);
  return c36_st;
}

static void set_sim_state_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_st)
{
  const mxArray *c36_u;
  real_T c36_dv1[4];
  int32_T c36_i3;
  real_T c36_dv2[4];
  int32_T c36_i4;
  real_T (*c36_dist)[4];
  real_T (*c36_b_u)[4];
  c36_dist = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c36_b_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c36_doneDoubleBufferReInit = TRUE;
  c36_u = sf_mex_dup(c36_st);
  c36_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 0)),
                       "dist", c36_dv1);
  for (c36_i3 = 0; c36_i3 < 4; c36_i3++) {
    (*c36_dist)[c36_i3] = c36_dv1[c36_i3];
  }

  c36_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 1)), "u",
                       c36_dv2);
  for (c36_i4 = 0; c36_i4 < 4; c36_i4++) {
    (*c36_b_u)[c36_i4] = c36_dv2[c36_i4];
  }

  chartInstance->c36_is_active_c36_hyd_hyb_2_int_cont_Final =
    c36_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 2)),
    "is_active_c36_hyd_hyb_2_int_cont_Final");
  sf_mex_destroy(&c36_u);
  c36_update_debugger_state_c36_hyd_hyb_2_int_cont_Final(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void sf_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  int32_T c36_i5;
  int32_T c36_i6;
  int32_T c36_i7;
  int32_T c36_i8;
  int32_T c36_i9;
  int32_T c36_i10;
  real_T *c36_t;
  real_T (*c36_mem)[4];
  real_T (*c36_dist)[4];
  real_T (*c36_init)[4];
  real_T (*c36_u)[4];
  real_T (*c36_x_feat)[10];
  c36_mem = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c36_dist = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c36_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c36_init = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c36_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c36_x_feat = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c36_sfEvent);
  for (c36_i5 = 0; c36_i5 < 10; c36_i5++) {
    _SFD_DATA_RANGE_CHECK((*c36_x_feat)[c36_i5], 0U);
  }

  for (c36_i6 = 0; c36_i6 < 4; c36_i6++) {
    _SFD_DATA_RANGE_CHECK((*c36_u)[c36_i6], 1U);
  }

  for (c36_i7 = 0; c36_i7 < 40; c36_i7++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c36_teta_new_10[c36_i7], 2U);
  }

  for (c36_i8 = 0; c36_i8 < 4; c36_i8++) {
    _SFD_DATA_RANGE_CHECK((*c36_init)[c36_i8], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c36_t, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c36_T0, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c36_T1, 6U);
  for (c36_i9 = 0; c36_i9 < 4; c36_i9++) {
    _SFD_DATA_RANGE_CHECK((*c36_dist)[c36_i9], 7U);
  }

  for (c36_i10 = 0; c36_i10 < 4; c36_i10++) {
    _SFD_DATA_RANGE_CHECK((*c36_mem)[c36_i10], 8U);
  }

  chartInstance->c36_sfEvent = CALL_EVENT;
  c36_chartstep_c36_hyd_hyb_2_int_cont_Final(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hyd_hyb_2_int_cont_FinalMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c36_chartstep_c36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  real_T c36_hoistedGlobal;
  real_T c36_b_hoistedGlobal;
  real_T c36_c_hoistedGlobal;
  int32_T c36_i11;
  real_T c36_x_feat[10];
  int32_T c36_i12;
  real_T c36_b_teta_new_10[40];
  int32_T c36_i13;
  real_T c36_init[4];
  real_T c36_t;
  real_T c36_b_T0;
  real_T c36_b_T1;
  int32_T c36_i14;
  real_T c36_mem[4];
  uint32_T c36_debug_family_var_map[17];
  real_T c36_q;
  real_T c36_u1[4];
  real_T c36_r;
  real_T c36_i;
  real_T c36_k;
  real_T c36_den;
  real_T c36_nargin = 7.0;
  real_T c36_nargout = 2.0;
  real_T c36_u[4];
  real_T c36_dist[4];
  int32_T c36_i15;
  int32_T c36_i16;
  int32_T c36_i17;
  int32_T c36_b_i;
  int32_T c36_c_i;
  int32_T c36_i18;
  real_T c36_a[10];
  int32_T c36_d_i;
  int32_T c36_i19;
  real_T c36_b[10];
  real_T c36_y;
  int32_T c36_b_k;
  int32_T c36_c_k;
  int32_T c36_d_k;
  int32_T c36_b_t;
  real_T c36_A;
  real_T c36_B;
  real_T c36_x;
  real_T c36_b_y;
  real_T c36_b_x;
  real_T c36_c_y;
  real_T c36_d_y;
  real_T c36_b_a;
  real_T c36_c_a;
  real_T c36_d_a;
  real_T c36_ak;
  real_T c36_e_a;
  real_T c36_c;
  real_T c36_b_B;
  real_T c36_e_y;
  real_T c36_f_y;
  real_T c36_g_y;
  int32_T c36_i20;
  int32_T c36_i21;
  int32_T c36_i22;
  int32_T c36_i23;
  real_T *c36_c_t;
  real_T (*c36_b_u)[4];
  real_T (*c36_b_dist)[4];
  real_T (*c36_b_mem)[4];
  real_T (*c36_b_init)[4];
  real_T (*c36_b_x_feat)[10];
  c36_b_mem = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c36_b_dist = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c36_c_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c36_b_init = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c36_b_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c36_b_x_feat = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c36_sfEvent);
  c36_hoistedGlobal = *c36_c_t;
  c36_b_hoistedGlobal = chartInstance->c36_T0;
  c36_c_hoistedGlobal = chartInstance->c36_T1;
  for (c36_i11 = 0; c36_i11 < 10; c36_i11++) {
    c36_x_feat[c36_i11] = (*c36_b_x_feat)[c36_i11];
  }

  for (c36_i12 = 0; c36_i12 < 40; c36_i12++) {
    c36_b_teta_new_10[c36_i12] = chartInstance->c36_teta_new_10[c36_i12];
  }

  for (c36_i13 = 0; c36_i13 < 4; c36_i13++) {
    c36_init[c36_i13] = (*c36_b_init)[c36_i13];
  }

  c36_t = c36_hoistedGlobal;
  c36_b_T0 = c36_b_hoistedGlobal;
  c36_b_T1 = c36_c_hoistedGlobal;
  for (c36_i14 = 0; c36_i14 < 4; c36_i14++) {
    c36_mem[c36_i14] = (*c36_b_mem)[c36_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c36_debug_family_names,
    c36_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_q, 0U, c36_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_u1, 1U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_r, 2U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_i, 3U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_k, 4U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_den, 5U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargin, 6U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargout, 7U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_x_feat, 8U, c36_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_teta_new_10, 9U,
    c36_c_sf_marshallOut, c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_init, 10U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_t, 11U, c36_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_T0, 12U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_T1, 13U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_mem, 14U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_u, 15U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_dist, 16U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 2);
  c36_q = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 2);
  for (c36_i15 = 0; c36_i15 < 4; c36_i15++) {
    c36_dist[c36_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 3);
  for (c36_i16 = 0; c36_i16 < 4; c36_i16++) {
    c36_u1[c36_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 4);
  for (c36_i17 = 0; c36_i17 < 4; c36_i17++) {
    c36_u[c36_i17] = c36_init[c36_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, c36_t >= c36_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 6);
    c36_r = c36_rem(chartInstance, c36_t, c36_b_T1);
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 8);
    if (CV_EML_IF(0, 1, 1, c36_r <= 0.01)) {
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 9);
      c36_i = 1.0;
      c36_b_i = 0;
      while (c36_b_i < 4) {
        c36_i = 1.0 + (real_T)c36_b_i;
        CV_EML_FOR(0, 1, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 10);
        c36_c_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("teta_new_10",
          (int32_T)_SFD_INTEGER_CHECK("i", c36_i), 1, 4, 2, 0) - 1;
        for (c36_i18 = 0; c36_i18 < 10; c36_i18++) {
          c36_a[c36_i18] = c36_x_feat[c36_i18] - c36_b_teta_new_10[c36_i18 + 10 *
            c36_c_i];
        }

        c36_d_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("teta_new_10",
          (int32_T)_SFD_INTEGER_CHECK("i", c36_i), 1, 4, 2, 0) - 1;
        for (c36_i19 = 0; c36_i19 < 10; c36_i19++) {
          c36_b[c36_i19] = c36_x_feat[c36_i19] - c36_b_teta_new_10[c36_i19 + 10 *
            c36_d_i];
        }

        c36_b_eml_scalar_eg(chartInstance);
        c36_b_eml_scalar_eg(chartInstance);
        c36_y = 0.0;
        for (c36_b_k = 1; c36_b_k < 11; c36_b_k++) {
          c36_c_k = c36_b_k;
          c36_y += c36_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c36_c_k), 1, 10, 1, 0) - 1] *
            c36_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c36_c_k), 1, 10, 1, 0) - 1];
        }

        c36_dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dist", (int32_T)
          _SFD_INTEGER_CHECK("i", c36_i), 1, 4, 1, 0) - 1] = c36_y;
        c36_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 12);
      c36_k = 1.0;
      c36_d_k = 0;
      while (c36_d_k < 4) {
        c36_k = 1.0 + (real_T)c36_d_k;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 13);
        c36_den = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 14);
        c36_t = 1.0;
        c36_b_t = 0;
        while (c36_b_t < 4) {
          c36_t = 1.0 + (real_T)c36_b_t;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 15);
          c36_A = c36_dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dist",
            (int32_T)_SFD_INTEGER_CHECK("k", c36_k), 1, 4, 1, 0) - 1];
          c36_B = c36_dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dist",
            (int32_T)_SFD_INTEGER_CHECK("t", c36_t), 1, 4, 1, 0) - 1];
          c36_x = c36_A;
          c36_b_y = c36_B;
          c36_b_x = c36_x;
          c36_c_y = c36_b_y;
          c36_d_y = c36_b_x / c36_c_y;
          c36_b_a = c36_d_y;
          c36_c_a = c36_b_a;
          c36_d_a = c36_c_a;
          c36_eml_scalar_eg(chartInstance);
          c36_ak = c36_d_a;
          c36_e_a = c36_ak;
          c36_eml_scalar_eg(chartInstance);
          c36_c = c36_e_a;
          c36_den += c36_c;
          c36_b_t++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 17);
        c36_b_B = c36_den;
        c36_e_y = c36_b_B;
        c36_f_y = c36_e_y;
        c36_g_y = 1.0 / c36_f_y;
        c36_u1[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("u1", (int32_T)
          _SFD_INTEGER_CHECK("k", c36_k), 1, 4, 1, 0) - 1] = c36_g_y;
        c36_d_k++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 19);
      for (c36_i20 = 0; c36_i20 < 4; c36_i20++) {
        c36_u[c36_i20] = c36_u1[c36_i20];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 21);
      for (c36_i21 = 0; c36_i21 < 4; c36_i21++) {
        c36_u[c36_i21] = c36_mem[c36_i21];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c36_i22 = 0; c36_i22 < 4; c36_i22++) {
    (*c36_b_u)[c36_i22] = c36_u[c36_i22];
  }

  for (c36_i23 = 0; c36_i23 < 4; c36_i23++) {
    (*c36_b_dist)[c36_i23] = c36_dist[c36_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c36_sfEvent);
}

static void initSimStructsc36_hyd_hyb_2_int_cont_Final
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber)
{
}

static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i24;
  real_T c36_b_inData[4];
  int32_T c36_i25;
  real_T c36_u[4];
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i24 = 0; c36_i24 < 4; c36_i24++) {
    c36_b_inData[c36_i24] = (*(real_T (*)[4])c36_inData)[c36_i24];
  }

  for (c36_i25 = 0; c36_i25 < 4; c36_i25++) {
    c36_u[c36_i25] = c36_b_inData[c36_i25];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, FALSE);
  return c36_mxArrayOutData;
}

static void c36_emlrt_marshallIn(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance, const mxArray *c36_dist, const char_T *c36_identifier, real_T
  c36_y[4])
{
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_dist), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_dist);
}

static void c36_b_emlrt_marshallIn(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[4])
{
  real_T c36_dv3[4];
  int32_T c36_i26;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c36_i26 = 0; c36_i26 < 4; c36_i26++) {
    c36_y[c36_i26] = c36_dv3[c36_i26];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_dist;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[4];
  int32_T c36_i27;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_dist = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_dist), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_dist);
  for (c36_i27 = 0; c36_i27 < 4; c36_i27++) {
    (*(real_T (*)[4])c36_outData)[c36_i27] = c36_y[c36_i27];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, FALSE);
  return c36_mxArrayOutData;
}

static real_T c36_c_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  real_T c36_y;
  real_T c36_d2;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_d2, 1, 0, 0U, 0, 0U, 0);
  c36_y = c36_d2;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_T1;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_b_T1 = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_T1),
    &c36_thisId);
  sf_mex_destroy(&c36_b_T1);
  *(real_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i28;
  int32_T c36_i29;
  int32_T c36_i30;
  real_T c36_b_inData[40];
  int32_T c36_i31;
  int32_T c36_i32;
  int32_T c36_i33;
  real_T c36_u[40];
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_i28 = 0;
  for (c36_i29 = 0; c36_i29 < 4; c36_i29++) {
    for (c36_i30 = 0; c36_i30 < 10; c36_i30++) {
      c36_b_inData[c36_i30 + c36_i28] = (*(real_T (*)[40])c36_inData)[c36_i30 +
        c36_i28];
    }

    c36_i28 += 10;
  }

  c36_i31 = 0;
  for (c36_i32 = 0; c36_i32 < 4; c36_i32++) {
    for (c36_i33 = 0; c36_i33 < 10; c36_i33++) {
      c36_u[c36_i33 + c36_i31] = c36_b_inData[c36_i33 + c36_i31];
    }

    c36_i31 += 10;
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 10, 4),
                FALSE);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, FALSE);
  return c36_mxArrayOutData;
}

static void c36_d_emlrt_marshallIn(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[40])
{
  real_T c36_dv4[40];
  int32_T c36_i34;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv4, 1, 0, 0U, 1, 0U, 2, 10,
                4);
  for (c36_i34 = 0; c36_i34 < 40; c36_i34++) {
    c36_y[c36_i34] = c36_dv4[c36_i34];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_teta_new_10;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[40];
  int32_T c36_i35;
  int32_T c36_i36;
  int32_T c36_i37;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_b_teta_new_10 = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_teta_new_10),
    &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_teta_new_10);
  c36_i35 = 0;
  for (c36_i36 = 0; c36_i36 < 4; c36_i36++) {
    for (c36_i37 = 0; c36_i37 < 10; c36_i37++) {
      (*(real_T (*)[40])c36_outData)[c36_i37 + c36_i35] = c36_y[c36_i37 +
        c36_i35];
    }

    c36_i35 += 10;
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i38;
  real_T c36_b_inData[10];
  int32_T c36_i39;
  real_T c36_u[10];
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i38 = 0; c36_i38 < 10; c36_i38++) {
    c36_b_inData[c36_i38] = (*(real_T (*)[10])c36_inData)[c36_i38];
  }

  for (c36_i39 = 0; c36_i39 < 10; c36_i39++) {
    c36_u[c36_i39] = c36_b_inData[c36_i39];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, FALSE);
  return c36_mxArrayOutData;
}

const mxArray *sf_c36_hyd_hyb_2_int_cont_Final_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  sf_mex_assign(&c36_nameCaptureInfo, sf_mex_createstruct("structure", 2, 41, 1),
                FALSE);
  c36_info_helper(&c36_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c36_nameCaptureInfo);
  return c36_nameCaptureInfo;
}

static void c36_info_helper(const mxArray **c36_info)
{
  const mxArray *c36_rhs0 = NULL;
  const mxArray *c36_lhs0 = NULL;
  const mxArray *c36_rhs1 = NULL;
  const mxArray *c36_lhs1 = NULL;
  const mxArray *c36_rhs2 = NULL;
  const mxArray *c36_lhs2 = NULL;
  const mxArray *c36_rhs3 = NULL;
  const mxArray *c36_lhs3 = NULL;
  const mxArray *c36_rhs4 = NULL;
  const mxArray *c36_lhs4 = NULL;
  const mxArray *c36_rhs5 = NULL;
  const mxArray *c36_lhs5 = NULL;
  const mxArray *c36_rhs6 = NULL;
  const mxArray *c36_lhs6 = NULL;
  const mxArray *c36_rhs7 = NULL;
  const mxArray *c36_lhs7 = NULL;
  const mxArray *c36_rhs8 = NULL;
  const mxArray *c36_lhs8 = NULL;
  const mxArray *c36_rhs9 = NULL;
  const mxArray *c36_lhs9 = NULL;
  const mxArray *c36_rhs10 = NULL;
  const mxArray *c36_lhs10 = NULL;
  const mxArray *c36_rhs11 = NULL;
  const mxArray *c36_lhs11 = NULL;
  const mxArray *c36_rhs12 = NULL;
  const mxArray *c36_lhs12 = NULL;
  const mxArray *c36_rhs13 = NULL;
  const mxArray *c36_lhs13 = NULL;
  const mxArray *c36_rhs14 = NULL;
  const mxArray *c36_lhs14 = NULL;
  const mxArray *c36_rhs15 = NULL;
  const mxArray *c36_lhs15 = NULL;
  const mxArray *c36_rhs16 = NULL;
  const mxArray *c36_lhs16 = NULL;
  const mxArray *c36_rhs17 = NULL;
  const mxArray *c36_lhs17 = NULL;
  const mxArray *c36_rhs18 = NULL;
  const mxArray *c36_lhs18 = NULL;
  const mxArray *c36_rhs19 = NULL;
  const mxArray *c36_lhs19 = NULL;
  const mxArray *c36_rhs20 = NULL;
  const mxArray *c36_lhs20 = NULL;
  const mxArray *c36_rhs21 = NULL;
  const mxArray *c36_lhs21 = NULL;
  const mxArray *c36_rhs22 = NULL;
  const mxArray *c36_lhs22 = NULL;
  const mxArray *c36_rhs23 = NULL;
  const mxArray *c36_lhs23 = NULL;
  const mxArray *c36_rhs24 = NULL;
  const mxArray *c36_lhs24 = NULL;
  const mxArray *c36_rhs25 = NULL;
  const mxArray *c36_lhs25 = NULL;
  const mxArray *c36_rhs26 = NULL;
  const mxArray *c36_lhs26 = NULL;
  const mxArray *c36_rhs27 = NULL;
  const mxArray *c36_lhs27 = NULL;
  const mxArray *c36_rhs28 = NULL;
  const mxArray *c36_lhs28 = NULL;
  const mxArray *c36_rhs29 = NULL;
  const mxArray *c36_lhs29 = NULL;
  const mxArray *c36_rhs30 = NULL;
  const mxArray *c36_lhs30 = NULL;
  const mxArray *c36_rhs31 = NULL;
  const mxArray *c36_lhs31 = NULL;
  const mxArray *c36_rhs32 = NULL;
  const mxArray *c36_lhs32 = NULL;
  const mxArray *c36_rhs33 = NULL;
  const mxArray *c36_lhs33 = NULL;
  const mxArray *c36_rhs34 = NULL;
  const mxArray *c36_lhs34 = NULL;
  const mxArray *c36_rhs35 = NULL;
  const mxArray *c36_lhs35 = NULL;
  const mxArray *c36_rhs36 = NULL;
  const mxArray *c36_lhs36 = NULL;
  const mxArray *c36_rhs37 = NULL;
  const mxArray *c36_lhs37 = NULL;
  const mxArray *c36_rhs38 = NULL;
  const mxArray *c36_lhs38 = NULL;
  const mxArray *c36_rhs39 = NULL;
  const mxArray *c36_lhs39 = NULL;
  const mxArray *c36_rhs40 = NULL;
  const mxArray *c36_lhs40 = NULL;
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("rem"), "name", "name", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c36_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c36_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c36_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1358177140U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c36_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("mtimes"), "name", "name", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704878U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c36_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c36_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c36_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c36_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704870U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c36_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1299067768U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c36_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_xdot"), "name", "name",
                  10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704868U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c36_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1299067768U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c36_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c36_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1299067772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c36_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1360273350U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c36_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c36_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c36_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813378U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c36_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c36_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813380U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c36_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c36_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813378U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c36_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323161578U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c36_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1346501340U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c36_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmax"), "name", "name", 24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362252882U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c36_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("mrdivide"), "name", "name",
                  25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1373297508U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1319724566U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c36_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("rdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704880U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c36_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c36_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c36_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_div"), "name", "name",
                  29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704866U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c36_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("mpower"), "name", "name", 30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704878U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c36_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c36_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("ismatrix"), "name", "name",
                  32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1331295858U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c36_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("power"), "name", "name", 33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704880U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c36_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c36_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 35);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 35);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c36_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 36);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 36);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1358177140U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c36_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 37);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("floor"), "name", "name", 37);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363704854U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c36_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 38);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c36_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 39);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813326U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c36_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 40);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 40);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c36_rhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c36_lhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs40), "lhs", "lhs",
                  40);
  sf_mex_destroy(&c36_rhs0);
  sf_mex_destroy(&c36_lhs0);
  sf_mex_destroy(&c36_rhs1);
  sf_mex_destroy(&c36_lhs1);
  sf_mex_destroy(&c36_rhs2);
  sf_mex_destroy(&c36_lhs2);
  sf_mex_destroy(&c36_rhs3);
  sf_mex_destroy(&c36_lhs3);
  sf_mex_destroy(&c36_rhs4);
  sf_mex_destroy(&c36_lhs4);
  sf_mex_destroy(&c36_rhs5);
  sf_mex_destroy(&c36_lhs5);
  sf_mex_destroy(&c36_rhs6);
  sf_mex_destroy(&c36_lhs6);
  sf_mex_destroy(&c36_rhs7);
  sf_mex_destroy(&c36_lhs7);
  sf_mex_destroy(&c36_rhs8);
  sf_mex_destroy(&c36_lhs8);
  sf_mex_destroy(&c36_rhs9);
  sf_mex_destroy(&c36_lhs9);
  sf_mex_destroy(&c36_rhs10);
  sf_mex_destroy(&c36_lhs10);
  sf_mex_destroy(&c36_rhs11);
  sf_mex_destroy(&c36_lhs11);
  sf_mex_destroy(&c36_rhs12);
  sf_mex_destroy(&c36_lhs12);
  sf_mex_destroy(&c36_rhs13);
  sf_mex_destroy(&c36_lhs13);
  sf_mex_destroy(&c36_rhs14);
  sf_mex_destroy(&c36_lhs14);
  sf_mex_destroy(&c36_rhs15);
  sf_mex_destroy(&c36_lhs15);
  sf_mex_destroy(&c36_rhs16);
  sf_mex_destroy(&c36_lhs16);
  sf_mex_destroy(&c36_rhs17);
  sf_mex_destroy(&c36_lhs17);
  sf_mex_destroy(&c36_rhs18);
  sf_mex_destroy(&c36_lhs18);
  sf_mex_destroy(&c36_rhs19);
  sf_mex_destroy(&c36_lhs19);
  sf_mex_destroy(&c36_rhs20);
  sf_mex_destroy(&c36_lhs20);
  sf_mex_destroy(&c36_rhs21);
  sf_mex_destroy(&c36_lhs21);
  sf_mex_destroy(&c36_rhs22);
  sf_mex_destroy(&c36_lhs22);
  sf_mex_destroy(&c36_rhs23);
  sf_mex_destroy(&c36_lhs23);
  sf_mex_destroy(&c36_rhs24);
  sf_mex_destroy(&c36_lhs24);
  sf_mex_destroy(&c36_rhs25);
  sf_mex_destroy(&c36_lhs25);
  sf_mex_destroy(&c36_rhs26);
  sf_mex_destroy(&c36_lhs26);
  sf_mex_destroy(&c36_rhs27);
  sf_mex_destroy(&c36_lhs27);
  sf_mex_destroy(&c36_rhs28);
  sf_mex_destroy(&c36_lhs28);
  sf_mex_destroy(&c36_rhs29);
  sf_mex_destroy(&c36_lhs29);
  sf_mex_destroy(&c36_rhs30);
  sf_mex_destroy(&c36_lhs30);
  sf_mex_destroy(&c36_rhs31);
  sf_mex_destroy(&c36_lhs31);
  sf_mex_destroy(&c36_rhs32);
  sf_mex_destroy(&c36_lhs32);
  sf_mex_destroy(&c36_rhs33);
  sf_mex_destroy(&c36_lhs33);
  sf_mex_destroy(&c36_rhs34);
  sf_mex_destroy(&c36_lhs34);
  sf_mex_destroy(&c36_rhs35);
  sf_mex_destroy(&c36_lhs35);
  sf_mex_destroy(&c36_rhs36);
  sf_mex_destroy(&c36_lhs36);
  sf_mex_destroy(&c36_rhs37);
  sf_mex_destroy(&c36_lhs37);
  sf_mex_destroy(&c36_rhs38);
  sf_mex_destroy(&c36_lhs38);
  sf_mex_destroy(&c36_rhs39);
  sf_mex_destroy(&c36_lhs39);
  sf_mex_destroy(&c36_rhs40);
  sf_mex_destroy(&c36_lhs40);
}

static const mxArray *c36_emlrt_marshallOut(char * c36_u)
{
  const mxArray *c36_y = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c36_u)), FALSE);
  return c36_y;
}

static const mxArray *c36_b_emlrt_marshallOut(uint32_T c36_u)
{
  const mxArray *c36_y = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c36_y;
}

static real_T c36_rem(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
                      *chartInstance, real_T c36_x, real_T c36_y)
{
  real_T c36_xk;
  real_T c36_yk;
  c36_eml_scalar_eg(chartInstance);
  c36_xk = c36_x;
  c36_yk = c36_y;
  return muDoubleScalarRem(c36_xk, c36_yk);
}

static void c36_eml_scalar_eg(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance)
{
}

static void c36_b_eml_scalar_eg(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance)
{
}

static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, FALSE);
  return c36_mxArrayOutData;
}

static int32_T c36_e_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i40;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_i40, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i40;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_sfEvent;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  int32_T c36_y;
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c36_b_sfEvent = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_sfEvent),
    &c36_thisId);
  sf_mex_destroy(&c36_b_sfEvent);
  *(int32_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static uint8_T c36_f_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_b_is_active_c36_hyd_hyb_2_int_cont_Final, const char_T *c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_hyd_hyb_2_int_cont_Final), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_hyd_hyb_2_int_cont_Final);
  return c36_y;
}

static uint8_T c36_g_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void init_dsm_address_info(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct
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

void sf_c36_hyd_hyb_2_int_cont_Final_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4104198478U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1651947893U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3817268193U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4017994607U);
}

mxArray *sf_c36_hyd_hyb_2_int_cont_Final_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fsEVfX8isenFSS3HfdNiUE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(10);
      pr[1] = (double)(4);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c36_hyd_hyb_2_int_cont_Final_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c36_hyd_hyb_2_int_cont_Final_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_Final(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"dist\",},{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c36_hyd_hyb_2_int_cont_Final\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_hyd_hyb_2_int_cont_Final_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
    chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hyd_hyb_2_int_cont_FinalMachineNumber_,
           36,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x_feat");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u");
          _SFD_SET_DATA_PROPS(2,10,0,0,"teta_new_10");
          _SFD_SET_DATA_PROPS(3,1,1,0,"init");
          _SFD_SET_DATA_PROPS(4,1,1,0,"t");
          _SFD_SET_DATA_PROPS(5,10,0,0,"T0");
          _SFD_SET_DATA_PROPS(6,10,0,0,"T1");
          _SFD_SET_DATA_PROPS(7,2,0,1,"dist");
          _SFD_SET_DATA_PROPS(8,1,1,0,"mem");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",1,-1,531);
        _SFD_CV_INIT_EML_IF(0,1,0,109,117,-1,527);
        _SFD_CV_INIT_EML_IF(0,1,1,159,171,496,523);
        _SFD_CV_INIT_EML_FOR(0,1,0,189,199,284);
        _SFD_CV_INIT_EML_FOR(0,1,1,309,319,469);
        _SFD_CV_INIT_EML_FOR(0,1,2,350,360,430);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)
            c36_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 10;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_c_sf_marshallOut,(MexInFcnForType)
            c36_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_b_sf_marshallOut,(MexInFcnForType)
          c36_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_b_sf_marshallOut,(MexInFcnForType)
          c36_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)
            c36_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c36_t;
          real_T (*c36_x_feat)[10];
          real_T (*c36_u)[4];
          real_T (*c36_init)[4];
          real_T (*c36_dist)[4];
          real_T (*c36_mem)[4];
          c36_mem = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
          c36_dist = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c36_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c36_init = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c36_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c36_x_feat = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c36_x_feat);
          _SFD_SET_DATA_VALUE_PTR(1U, *c36_u);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c36_teta_new_10);
          _SFD_SET_DATA_VALUE_PTR(3U, *c36_init);
          _SFD_SET_DATA_VALUE_PTR(4U, c36_t);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c36_T0);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c36_T1);
          _SFD_SET_DATA_VALUE_PTR(7U, *c36_dist);
          _SFD_SET_DATA_VALUE_PTR(8U, *c36_mem);
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
  return "hzPpD8VWHYTRtGyWgRXtBG";
}

static void sf_opaque_initialize_c36_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
  initialize_c36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c36_hyd_hyb_2_int_cont_Final(void *chartInstanceVar)
{
  enable_c36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c36_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  disable_c36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c36_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  sf_c36_hyd_hyb_2_int_cont_Final((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c36_hyd_hyb_2_int_cont_Final
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_Final();/* state var info */
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

extern void sf_internal_set_sim_state_c36_hyd_hyb_2_int_cont_Final(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_Final();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c36_hyd_hyb_2_int_cont_Final
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c36_hyd_hyb_2_int_cont_Final(S);
}

static void sf_opaque_set_sim_state_c36_hyd_hyb_2_int_cont_Final(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c36_hyd_hyb_2_int_cont_Final(S, st);
}

static void sf_opaque_terminate_c36_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hyd_hyb_2_int_cont_Final_optimization_info();
    }

    finalize_c36_hyd_hyb_2_int_cont_Final
      ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc36_hyd_hyb_2_int_cont_Final
    ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c36_hyd_hyb_2_int_cont_Final
      ((SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c36_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  /* Actual parameters from chart:
     T0 T1 teta_new_10
   */
  const char_T *rtParamNames[] = { "T0", "T1", "teta_new_10" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for teta_new_10*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hyd_hyb_2_int_cont_Final_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,36,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,36,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,36);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,36,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,36,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,36);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4025259543U));
  ssSetChecksum1(S,(305058177U));
  ssSetChecksum2(S,(2565538112U));
  ssSetChecksum3(S,(1997051811U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c36_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct *)utMalloc
    (sizeof(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc36_hyd_hyb_2_int_cont_FinalInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.mdlStart = mdlStart_c36_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c36_hyd_hyb_2_int_cont_Final;
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

void c36_hyd_hyb_2_int_cont_Final_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_hyd_hyb_2_int_cont_Final(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_hyd_hyb_2_int_cont_Final(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_hyd_hyb_2_int_cont_Final(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_hyd_hyb_2_int_cont_Final_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
