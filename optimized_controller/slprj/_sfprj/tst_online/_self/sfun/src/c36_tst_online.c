/* Include files */

#include "blascompat32.h"
#include "tst_online_sfun.h"
#include "c36_tst_online.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "tst_online_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c36_debug_family_names[20] = { "dist1", "p", "q", "dist2",
  "u1", "r", "j", "num", "e", "k", "den", "nargin", "nargout", "x_feat", "teta",
  "init", "t", "T0", "T1", "u" };

/* Function Declarations */
static void initialize_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance);
static void initialize_params_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance);
static void enable_c36_tst_online(SFc36_tst_onlineInstanceStruct *chartInstance);
static void disable_c36_tst_online(SFc36_tst_onlineInstanceStruct *chartInstance);
static void c36_update_debugger_state_c36_tst_online
  (SFc36_tst_onlineInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c36_tst_online
  (SFc36_tst_onlineInstanceStruct *chartInstance);
static void set_sim_state_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_st);
static void finalize_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance);
static void sf_c36_tst_online(SFc36_tst_onlineInstanceStruct *chartInstance);
static void c36_chartstep_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance);
static void initSimStructsc36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct *chartInstance,
  const mxArray *c36_u, const char_T *c36_identifier, real_T c36_y[4]);
static void c36_b_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[4]);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_c_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_d_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[24]);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_eml_scalar_eg(SFc36_tst_onlineInstanceStruct *chartInstance);
static real_T c36_power(SFc36_tst_onlineInstanceStruct *chartInstance, real_T
  c36_a, real_T c36_b);
static void c36_eml_error(SFc36_tst_onlineInstanceStruct *chartInstance);
static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_e_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_f_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_b_is_active_c36_tst_online, const char_T
  *c36_identifier);
static uint8_T c36_g_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void init_dsm_address_info(SFc36_tst_onlineInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance)
{
  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c36_is_active_c36_tst_online = 0U;
}

static void initialize_params_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance)
{
  real_T c36_dv0[24];
  int32_T c36_i0;
  real_T c36_d0;
  real_T c36_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'teta' in the parent workspace.\n");
  sf_mex_import_named("teta", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      c36_dv0, 0, 0, 0U, 1, 0U, 2, 6, 4);
  for (c36_i0 = 0; c36_i0 < 24; c36_i0++) {
    chartInstance->c36_teta[c36_i0] = c36_dv0[c36_i0];
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

static void enable_c36_tst_online(SFc36_tst_onlineInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c36_tst_online(SFc36_tst_onlineInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c36_update_debugger_state_c36_tst_online
  (SFc36_tst_onlineInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c36_tst_online
  (SFc36_tst_onlineInstanceStruct *chartInstance)
{
  const mxArray *c36_st;
  const mxArray *c36_y = NULL;
  int32_T c36_i1;
  real_T c36_u[4];
  const mxArray *c36_b_y = NULL;
  uint8_T c36_hoistedGlobal;
  uint8_T c36_b_u;
  const mxArray *c36_c_y = NULL;
  real_T (*c36_c_u)[4];
  c36_c_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c36_st = NULL;
  c36_st = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_createcellarray(2));
  for (c36_i1 = 0; c36_i1 < 4; c36_i1++) {
    c36_u[c36_i1] = (*c36_c_u)[c36_i1];
  }

  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c36_y, 0, c36_b_y);
  c36_hoistedGlobal = chartInstance->c36_is_active_c36_tst_online;
  c36_b_u = c36_hoistedGlobal;
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", &c36_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c36_y, 1, c36_c_y);
  sf_mex_assign(&c36_st, c36_y);
  return c36_st;
}

static void set_sim_state_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_st)
{
  const mxArray *c36_u;
  real_T c36_dv1[4];
  int32_T c36_i2;
  real_T (*c36_b_u)[4];
  c36_b_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c36_doneDoubleBufferReInit = TRUE;
  c36_u = sf_mex_dup(c36_st);
  c36_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 0)), "u",
                       c36_dv1);
  for (c36_i2 = 0; c36_i2 < 4; c36_i2++) {
    (*c36_b_u)[c36_i2] = c36_dv1[c36_i2];
  }

  chartInstance->c36_is_active_c36_tst_online = c36_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 1)),
     "is_active_c36_tst_online");
  sf_mex_destroy(&c36_u);
  c36_update_debugger_state_c36_tst_online(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance)
{
}

static void sf_c36_tst_online(SFc36_tst_onlineInstanceStruct *chartInstance)
{
  int32_T c36_i3;
  int32_T c36_i4;
  int32_T c36_i5;
  int32_T c36_i6;
  real_T *c36_t;
  real_T (*c36_init)[4];
  real_T (*c36_u)[4];
  real_T (*c36_x_feat)[6];
  c36_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c36_init = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c36_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c36_x_feat = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c36_sfEvent);
  for (c36_i3 = 0; c36_i3 < 6; c36_i3++) {
    _SFD_DATA_RANGE_CHECK((*c36_x_feat)[c36_i3], 0U);
  }

  for (c36_i4 = 0; c36_i4 < 4; c36_i4++) {
    _SFD_DATA_RANGE_CHECK((*c36_u)[c36_i4], 1U);
  }

  for (c36_i5 = 0; c36_i5 < 24; c36_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c36_teta[c36_i5], 2U);
  }

  for (c36_i6 = 0; c36_i6 < 4; c36_i6++) {
    _SFD_DATA_RANGE_CHECK((*c36_init)[c36_i6], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c36_t, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c36_T0, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c36_T1, 6U);
  chartInstance->c36_sfEvent = CALL_EVENT;
  c36_chartstep_c36_tst_online(chartInstance);
  sf_debug_check_for_state_inconsistency(_tst_onlineMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c36_chartstep_c36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance)
{
  real_T c36_hoistedGlobal;
  real_T c36_b_hoistedGlobal;
  real_T c36_c_hoistedGlobal;
  int32_T c36_i7;
  real_T c36_x_feat[6];
  int32_T c36_i8;
  real_T c36_b_teta[24];
  int32_T c36_i9;
  real_T c36_init[4];
  real_T c36_t;
  real_T c36_b_T0;
  real_T c36_b_T1;
  uint32_T c36_debug_family_var_map[20];
  real_T c36_dist1[4];
  real_T c36_p;
  real_T c36_q;
  real_T c36_dist2[4];
  real_T c36_u1[4];
  real_T c36_r;
  real_T c36_j;
  real_T c36_num;
  real_T c36_e;
  real_T c36_k;
  real_T c36_den;
  real_T c36_nargin = 6.0;
  real_T c36_nargout = 1.0;
  real_T c36_u[4];
  int32_T c36_i10;
  int32_T c36_i11;
  int32_T c36_i12;
  int32_T c36_i13;
  real_T c36_x;
  real_T c36_y;
  real_T c36_xk;
  real_T c36_yk;
  real_T c36_b_x;
  real_T c36_b_y;
  real_T c36_b_j;
  real_T c36_b_e;
  real_T c36_A;
  real_T c36_B;
  real_T c36_c_x;
  real_T c36_c_y;
  real_T c36_d_x;
  real_T c36_d_y;
  real_T c36_e_x;
  real_T c36_e_y;
  real_T c36_f_y;
  real_T c36_a;
  real_T c36_c;
  real_T c36_b_a;
  real_T c36_b_c;
  real_T c36_b_k;
  real_T c36_b_t;
  real_T c36_b_A;
  real_T c36_b_B;
  real_T c36_f_x;
  real_T c36_g_y;
  real_T c36_g_x;
  real_T c36_h_y;
  real_T c36_h_x;
  real_T c36_i_y;
  real_T c36_j_y;
  real_T c36_c_a;
  real_T c36_c_c;
  real_T c36_c_B;
  real_T c36_k_y;
  real_T c36_l_y;
  real_T c36_m_y;
  real_T c36_n_y;
  int32_T c36_i14;
  int32_T c36_i15;
  real_T *c36_c_t;
  real_T (*c36_b_u)[4];
  real_T (*c36_b_init)[4];
  real_T (*c36_b_x_feat)[6];
  c36_c_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c36_b_init = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c36_b_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c36_b_x_feat = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c36_sfEvent);
  c36_hoistedGlobal = *c36_c_t;
  c36_b_hoistedGlobal = chartInstance->c36_T0;
  c36_c_hoistedGlobal = chartInstance->c36_T1;
  for (c36_i7 = 0; c36_i7 < 6; c36_i7++) {
    c36_x_feat[c36_i7] = (*c36_b_x_feat)[c36_i7];
  }

  for (c36_i8 = 0; c36_i8 < 24; c36_i8++) {
    c36_b_teta[c36_i8] = chartInstance->c36_teta[c36_i8];
  }

  for (c36_i9 = 0; c36_i9 < 4; c36_i9++) {
    c36_init[c36_i9] = (*c36_b_init)[c36_i9];
  }

  c36_t = c36_hoistedGlobal;
  c36_b_T0 = c36_b_hoistedGlobal;
  c36_b_T1 = c36_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c36_debug_family_names,
    c36_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c36_dist1, 0U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c36_p, 1U, c36_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c36_q, 2U, c36_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c36_dist2, 3U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c36_u1, 4U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_r, 5U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_j, 6U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_num, 7U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_e, 8U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_k, 9U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_den, 10U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_nargin, 11U,
    c36_b_sf_marshallOut, c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_nargout, 12U,
    c36_b_sf_marshallOut, c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c36_x_feat, 13U, c36_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c36_b_teta, 14U, c36_c_sf_marshallOut,
    c36_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c36_init, 15U, c36_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c36_t, 16U, c36_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c36_b_T0, 17U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_b_T1, 18U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c36_u, 19U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 2);
  for (c36_i10 = 0; c36_i10 < 4; c36_i10++) {
    c36_dist1[c36_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 3);
  c36_p = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 3);
  c36_q = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 3);
  for (c36_i11 = 0; c36_i11 < 4; c36_i11++) {
    c36_dist2[c36_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 4);
  for (c36_i12 = 0; c36_i12 < 4; c36_i12++) {
    c36_u1[c36_i12] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 5);
  for (c36_i13 = 0; c36_i13 < 4; c36_i13++) {
    c36_u[c36_i13] = c36_init[c36_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 6);
  if (CV_EML_IF(0, 0, c36_t > c36_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 7);
    c36_x = c36_t;
    c36_y = c36_b_T1;
    c36_eml_scalar_eg(chartInstance);
    c36_xk = c36_x;
    c36_yk = c36_y;
    c36_b_x = c36_xk;
    c36_b_y = c36_yk;
    c36_r = muDoubleScalarRem(c36_b_x, c36_b_y);
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 8);
    if (CV_EML_IF(0, 1, c36_r < 0.01)) {
      c36_j = 1.0;
      c36_b_j = 1.0;
      while (c36_b_j <= 4.0) {
        c36_j = c36_b_j;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 10);
        c36_num = 0.0;
        c36_e = 1.0;
        c36_b_e = 1.0;
        while (c36_b_e <= 6.0) {
          c36_e = c36_b_e;
          CV_EML_FOR(0, 1, 1);
          _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 12);
          c36_num++;
          _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 13);
          c36_A = c36_x_feat[_SFD_EML_ARRAY_BOUNDS_CHECK("x_feat", (int32_T)
            _SFD_INTEGER_CHECK("e", c36_e), 1, 6, 1, 0) - 1] - c36_b_teta
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("teta", (int32_T)_SFD_INTEGER_CHECK(
                "e", c36_e), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "teta", (int32_T)_SFD_INTEGER_CHECK("j", c36_j), 1, 4, 2, 0) - 1))
            - 1];
          c36_B = c36_b_teta[(_SFD_EML_ARRAY_BOUNDS_CHECK("teta", (int32_T)
            _SFD_INTEGER_CHECK("e", c36_e), 1, 6, 1, 0) + 6 *
                              (_SFD_EML_ARRAY_BOUNDS_CHECK("teta", (int32_T)
            _SFD_INTEGER_CHECK("j", c36_j), 1, 4, 2, 0) - 1)) - 1];
          c36_c_x = c36_A;
          c36_c_y = c36_B;
          c36_d_x = c36_c_x;
          c36_d_y = c36_c_y;
          c36_e_x = c36_d_x;
          c36_e_y = c36_d_y;
          c36_f_y = c36_e_x / c36_e_y;
          c36_a = c36_f_y;
          c36_c = c36_power(chartInstance, c36_a, 4.0);
          c36_dist1[_SFD_EML_ARRAY_BOUNDS_CHECK("dist1", (int32_T)
            _SFD_INTEGER_CHECK("j", c36_j), 1, 4, 1, 0) - 1] =
            c36_dist1[_SFD_EML_ARRAY_BOUNDS_CHECK("dist1", (int32_T)
            _SFD_INTEGER_CHECK("j", c36_j), 1, 4, 1, 0) - 1] + c36_c;
          c36_b_e++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 0);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 15);
        c36_b_a = c36_dist1[_SFD_EML_ARRAY_BOUNDS_CHECK("dist1", (int32_T)
          _SFD_INTEGER_CHECK("j", c36_j), 1, 4, 1, 0) - 1];
        c36_b_c = c36_power(chartInstance, c36_b_a, 0.25);
        c36_dist2[_SFD_EML_ARRAY_BOUNDS_CHECK("dist2", (int32_T)
          _SFD_INTEGER_CHECK("j", c36_j), 1, 4, 1, 0) - 1] = c36_b_c;
        c36_b_j++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 0, 0);
      c36_k = 1.0;
      c36_b_k = 1.0;
      while (c36_b_k <= 4.0) {
        c36_k = c36_b_k;
        CV_EML_FOR(0, 2, 1);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 18);
        c36_den = 0.0;
        c36_t = 1.0;
        c36_b_t = 1.0;
        while (c36_b_t <= 4.0) {
          c36_t = c36_b_t;
          CV_EML_FOR(0, 3, 1);
          _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 20);
          c36_b_A = c36_dist2[_SFD_EML_ARRAY_BOUNDS_CHECK("dist2", (int32_T)
            _SFD_INTEGER_CHECK("k", c36_k), 1, 4, 1, 0) - 1];
          c36_b_B = c36_dist2[_SFD_EML_ARRAY_BOUNDS_CHECK("dist2", (int32_T)
            _SFD_INTEGER_CHECK("t", c36_t), 1, 4, 1, 0) - 1];
          c36_f_x = c36_b_A;
          c36_g_y = c36_b_B;
          c36_g_x = c36_f_x;
          c36_h_y = c36_g_y;
          c36_h_x = c36_g_x;
          c36_i_y = c36_h_y;
          c36_j_y = c36_h_x / c36_i_y;
          c36_c_a = c36_j_y;
          c36_c_c = c36_power(chartInstance, c36_c_a, 1.0);
          c36_den += c36_c_c;
          c36_b_t++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_EML_FOR(0, 3, 0);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 22);
        c36_c_B = c36_den;
        c36_k_y = c36_c_B;
        c36_l_y = c36_k_y;
        c36_m_y = c36_l_y;
        c36_n_y = 1.0 / c36_m_y;
        c36_u1[_SFD_EML_ARRAY_BOUNDS_CHECK("u1", (int32_T)_SFD_INTEGER_CHECK("k",
          c36_k), 1, 4, 1, 0) - 1] = c36_n_y;
        c36_b_k++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 2, 0);
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 24);
      for (c36_i14 = 0; c36_i14 < 4; c36_i14++) {
        c36_u[c36_i14] = c36_u1[c36_i14];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -24);
  sf_debug_symbol_scope_pop();
  for (c36_i15 = 0; c36_i15 < 4; c36_i15++) {
    (*c36_b_u)[c36_i15] = c36_u[c36_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c36_sfEvent);
}

static void initSimStructsc36_tst_online(SFc36_tst_onlineInstanceStruct
  *chartInstance)
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
  int32_T c36_i16;
  real_T c36_b_inData[4];
  int32_T c36_i17;
  real_T c36_u[4];
  const mxArray *c36_y = NULL;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i16 = 0; c36_i16 < 4; c36_i16++) {
    c36_b_inData[c36_i16] = (*(real_T (*)[4])c36_inData)[c36_i16];
  }

  for (c36_i17 = 0; c36_i17 < 4; c36_i17++) {
    c36_u[c36_i17] = c36_b_inData[c36_i17];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static void c36_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct *chartInstance,
  const mxArray *c36_u, const char_T *c36_identifier, real_T c36_y[4])
{
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_u), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_u);
}

static void c36_b_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[4])
{
  real_T c36_dv2[4];
  int32_T c36_i18;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c36_i18 = 0; c36_i18 < 4; c36_i18++) {
    c36_y[c36_i18] = c36_dv2[c36_i18];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_u;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[4];
  int32_T c36_i19;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_u = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_u), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_u);
  for (c36_i19 = 0; c36_i19 < 4; c36_i19++) {
    (*(real_T (*)[4])c36_outData)[c36_i19] = c36_y[c36_i19];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static real_T c36_c_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
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
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
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
  int32_T c36_i20;
  int32_T c36_i21;
  int32_T c36_i22;
  real_T c36_b_inData[24];
  int32_T c36_i23;
  int32_T c36_i24;
  int32_T c36_i25;
  real_T c36_u[24];
  const mxArray *c36_y = NULL;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_i20 = 0;
  for (c36_i21 = 0; c36_i21 < 4; c36_i21++) {
    for (c36_i22 = 0; c36_i22 < 6; c36_i22++) {
      c36_b_inData[c36_i22 + c36_i20] = (*(real_T (*)[24])c36_inData)[c36_i22 +
        c36_i20];
    }

    c36_i20 += 6;
  }

  c36_i23 = 0;
  for (c36_i24 = 0; c36_i24 < 4; c36_i24++) {
    for (c36_i25 = 0; c36_i25 < 6; c36_i25++) {
      c36_u[c36_i25 + c36_i23] = c36_b_inData[c36_i25 + c36_i23];
    }

    c36_i23 += 6;
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static void c36_d_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[24])
{
  real_T c36_dv3[24];
  int32_T c36_i26;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv3, 1, 0, 0U, 1, 0U, 2, 6,
                4);
  for (c36_i26 = 0; c36_i26 < 24; c36_i26++) {
    c36_y[c36_i26] = c36_dv3[c36_i26];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_teta;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[24];
  int32_T c36_i27;
  int32_T c36_i28;
  int32_T c36_i29;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_b_teta = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_teta), &c36_thisId,
    c36_y);
  sf_mex_destroy(&c36_b_teta);
  c36_i27 = 0;
  for (c36_i28 = 0; c36_i28 < 4; c36_i28++) {
    for (c36_i29 = 0; c36_i29 < 6; c36_i29++) {
      (*(real_T (*)[24])c36_outData)[c36_i29 + c36_i27] = c36_y[c36_i29 +
        c36_i27];
    }

    c36_i27 += 6;
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i30;
  real_T c36_b_inData[6];
  int32_T c36_i31;
  real_T c36_u[6];
  const mxArray *c36_y = NULL;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i30 = 0; c36_i30 < 6; c36_i30++) {
    c36_b_inData[c36_i30] = (*(real_T (*)[6])c36_inData)[c36_i30];
  }

  for (c36_i31 = 0; c36_i31 < 6; c36_i31++) {
    c36_u[c36_i31] = c36_b_inData[c36_i31];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

const mxArray *sf_c36_tst_online_get_eml_resolved_functions_info(void)
{
  const mxArray *c36_nameCaptureInfo;
  c36_ResolvedFunctionInfo c36_info[11];
  c36_ResolvedFunctionInfo (*c36_b_info)[11];
  const mxArray *c36_m0 = NULL;
  int32_T c36_i32;
  c36_ResolvedFunctionInfo *c36_r0;
  c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  c36_b_info = (c36_ResolvedFunctionInfo (*)[11])c36_info;
  (*c36_b_info)[0].context = "";
  (*c36_b_info)[0].name = "rem";
  (*c36_b_info)[0].dominantType = "double";
  (*c36_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c36_b_info)[0].fileTimeLo = 2721966592U;
  (*c36_b_info)[0].fileTimeHi = 30107998U;
  (*c36_b_info)[0].mFileTimeLo = 0U;
  (*c36_b_info)[0].mFileTimeHi = 0U;
  (*c36_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c36_b_info)[1].name = "eml_scalar_eg";
  (*c36_b_info)[1].dominantType = "double";
  (*c36_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c36_b_info)[1].fileTimeLo = 3201966592U;
  (*c36_b_info)[1].fileTimeHi = 30107998U;
  (*c36_b_info)[1].mFileTimeLo = 0U;
  (*c36_b_info)[1].mFileTimeHi = 0U;
  (*c36_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c36_b_info)[2].name = "eml_scalexp_alloc";
  (*c36_b_info)[2].dominantType = "double";
  (*c36_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c36_b_info)[2].fileTimeLo = 3201966592U;
  (*c36_b_info)[2].fileTimeHi = 30107998U;
  (*c36_b_info)[2].mFileTimeLo = 0U;
  (*c36_b_info)[2].mFileTimeHi = 0U;
  (*c36_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c36_b_info)[3].name = "eml_scalar_rem";
  (*c36_b_info)[3].dominantType = "double";
  (*c36_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  (*c36_b_info)[3].fileTimeLo = 2561966592U;
  (*c36_b_info)[3].fileTimeHi = 30107998U;
  (*c36_b_info)[3].mFileTimeLo = 0U;
  (*c36_b_info)[3].mFileTimeHi = 0U;
  (*c36_b_info)[4].context = "";
  (*c36_b_info)[4].name = "mrdivide";
  (*c36_b_info)[4].dominantType = "double";
  (*c36_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c36_b_info)[4].fileTimeLo = 2311411456U;
  (*c36_b_info)[4].fileTimeHi = 30130914U;
  (*c36_b_info)[4].mFileTimeLo = 3767347712U;
  (*c36_b_info)[4].mFileTimeHi = 30114278U;
  (*c36_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c36_b_info)[5].name = "rdivide";
  (*c36_b_info)[5].dominantType = "double";
  (*c36_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c36_b_info)[5].fileTimeLo = 3681966592U;
  (*c36_b_info)[5].fileTimeHi = 30107998U;
  (*c36_b_info)[5].mFileTimeLo = 0U;
  (*c36_b_info)[5].mFileTimeHi = 0U;
  (*c36_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c36_b_info)[6].name = "eml_div";
  (*c36_b_info)[6].dominantType = "double";
  (*c36_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c36_b_info)[6].fileTimeLo = 2221966592U;
  (*c36_b_info)[6].fileTimeHi = 30107998U;
  (*c36_b_info)[6].mFileTimeLo = 0U;
  (*c36_b_info)[6].mFileTimeHi = 0U;
  (*c36_b_info)[7].context = "";
  (*c36_b_info)[7].name = "mpower";
  (*c36_b_info)[7].dominantType = "double";
  (*c36_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c36_b_info)[7].fileTimeLo = 3661966592U;
  (*c36_b_info)[7].fileTimeHi = 30107998U;
  (*c36_b_info)[7].mFileTimeLo = 0U;
  (*c36_b_info)[7].mFileTimeHi = 0U;
  (*c36_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c36_b_info)[8].name = "power";
  (*c36_b_info)[8].dominantType = "double";
  (*c36_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c36_b_info)[8].fileTimeLo = 3681966592U;
  (*c36_b_info)[8].fileTimeHi = 30107998U;
  (*c36_b_info)[8].mFileTimeLo = 0U;
  (*c36_b_info)[8].mFileTimeHi = 0U;
  (*c36_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c36_b_info)[9].name = "eml_scalar_floor";
  (*c36_b_info)[9].dominantType = "double";
  (*c36_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c36_b_info)[9].fileTimeLo = 2501966592U;
  (*c36_b_info)[9].fileTimeHi = 30107998U;
  (*c36_b_info)[9].mFileTimeLo = 0U;
  (*c36_b_info)[9].mFileTimeHi = 0U;
  (*c36_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c36_b_info)[10].name = "eml_error";
  (*c36_b_info)[10].dominantType = "char";
  (*c36_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c36_b_info)[10].fileTimeLo = 2241966592U;
  (*c36_b_info)[10].fileTimeHi = 30107998U;
  (*c36_b_info)[10].mFileTimeLo = 0U;
  (*c36_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c36_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11));
  for (c36_i32 = 0; c36_i32 < 11; c36_i32++) {
    c36_r0 = &c36_info[c36_i32];
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", c36_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c36_r0->context)), "context", "nameCaptureInfo",
                    c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", c36_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c36_r0->name)), "name", "nameCaptureInfo",
                    c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo",
      c36_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c36_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", c36_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c36_r0->resolved)), "resolved",
                    "nameCaptureInfo", c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", &c36_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", &c36_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo",
      &c36_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c36_i32);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo",
      &c36_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c36_i32);
  }

  sf_mex_assign(&c36_nameCaptureInfo, c36_m0);
  return c36_nameCaptureInfo;
}

static void c36_eml_scalar_eg(SFc36_tst_onlineInstanceStruct *chartInstance)
{
}

static real_T c36_power(SFc36_tst_onlineInstanceStruct *chartInstance, real_T
  c36_a, real_T c36_b)
{
  real_T c36_ak;
  real_T c36_bk;
  real_T c36_x;
  real_T c36_b_x;
  c36_eml_scalar_eg(chartInstance);
  c36_ak = c36_a;
  c36_bk = c36_b;
  if (c36_ak < 0.0) {
    c36_x = c36_bk;
    c36_b_x = c36_x;
    c36_b_x = muDoubleScalarFloor(c36_b_x);
    if (c36_b_x != c36_bk) {
      c36_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c36_ak, c36_bk);
}

static void c36_eml_error(SFc36_tst_onlineInstanceStruct *chartInstance)
{
  int32_T c36_i33;
  static char_T c36_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c36_u[31];
  const mxArray *c36_y = NULL;
  for (c36_i33 = 0; c36_i33 < 31; c36_i33++) {
    c36_u[c36_i33] = c36_varargin_1[c36_i33];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c36_y));
}

static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static int32_T c36_e_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i34;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_i34, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i34;
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
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)chartInstanceVoid;
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

static uint8_T c36_f_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_b_is_active_c36_tst_online, const char_T
  *c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_tst_online), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_tst_online);
  return c36_y;
}

static uint8_T c36_g_emlrt_marshallIn(SFc36_tst_onlineInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void init_dsm_address_info(SFc36_tst_onlineInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c36_tst_online_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(335176471U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4038251044U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2036822918U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(358057766U);
}

mxArray *sf_c36_tst_online_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4289661796U);
    pr[1] = (double)(770340312U);
    pr[2] = (double)(1488235117U);
    pr[3] = (double)(3678797304U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c36_tst_online(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c36_tst_online\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_tst_online_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_tst_onlineInstanceStruct *chartInstance;
    chartInstance = (SFc36_tst_onlineInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_tst_onlineMachineNumber_,
           36,
           1,
           1,
           7,
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
          init_script_number_translation(_tst_onlineMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_tst_onlineMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_tst_onlineMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x_feat");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u");
          _SFD_SET_DATA_PROPS(2,10,0,0,"teta");
          _SFD_SET_DATA_PROPS(3,1,1,0,"init");
          _SFD_SET_DATA_PROPS(4,1,1,0,"t");
          _SFD_SET_DATA_PROPS(5,10,0,0,"T0");
          _SFD_SET_DATA_PROPS(6,10,0,0,"T1");
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
        _SFD_CV_INIT_EML(0,1,2,0,0,4,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,576);
        _SFD_CV_INIT_EML_IF(0,0,112,119,-1,572);
        _SFD_CV_INIT_EML_IF(0,1,141,150,-1,568);
        _SFD_CV_INIT_EML_FOR(0,0,159,169,376);
        _SFD_CV_INIT_EML_FOR(0,1,200,210,325);
        _SFD_CV_INIT_EML_FOR(0,2,385,395,547);
        _SFD_CV_INIT_EML_FOR(0,3,426,436,508);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
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
          dimVector[0]= 6;
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
          real_T *c36_t;
          real_T (*c36_x_feat)[6];
          real_T (*c36_u)[4];
          real_T (*c36_init)[4];
          c36_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c36_init = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c36_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c36_x_feat = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c36_x_feat);
          _SFD_SET_DATA_VALUE_PTR(1U, *c36_u);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c36_teta);
          _SFD_SET_DATA_VALUE_PTR(3U, *c36_init);
          _SFD_SET_DATA_VALUE_PTR(4U, c36_t);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c36_T0);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c36_T1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_tst_onlineMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c36_tst_online(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc36_tst_onlineInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c36_tst_online((SFc36_tst_onlineInstanceStruct*)
    chartInstanceVar);
  initialize_c36_tst_online((SFc36_tst_onlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c36_tst_online(void *chartInstanceVar)
{
  enable_c36_tst_online((SFc36_tst_onlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c36_tst_online(void *chartInstanceVar)
{
  disable_c36_tst_online((SFc36_tst_onlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c36_tst_online(void *chartInstanceVar)
{
  sf_c36_tst_online((SFc36_tst_onlineInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c36_tst_online(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c36_tst_online
    ((SFc36_tst_onlineInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c36_tst_online();/* state var info */
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

extern void sf_internal_set_sim_state_c36_tst_online(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c36_tst_online();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c36_tst_online((SFc36_tst_onlineInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c36_tst_online(SimStruct* S)
{
  return sf_internal_get_sim_state_c36_tst_online(S);
}

static void sf_opaque_set_sim_state_c36_tst_online(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c36_tst_online(S, st);
}

static void sf_opaque_terminate_c36_tst_online(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc36_tst_onlineInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c36_tst_online((SFc36_tst_onlineInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc36_tst_online((SFc36_tst_onlineInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_tst_online(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c36_tst_online((SFc36_tst_onlineInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c36_tst_online(SimStruct *S)
{
  /* Actual parameters from chart:
     T0 T1 teta
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for teta*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"tst_online","tst_online",36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"tst_online","tst_online",36,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"tst_online",
      "tst_online",36,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"tst_online","tst_online",36,3);
      sf_mark_chart_reusable_outputs(S,"tst_online","tst_online",36,1);
    }

    sf_set_rtw_dwork_info(S,"tst_online","tst_online",36);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3237938155U));
  ssSetChecksum1(S,(414986259U));
  ssSetChecksum2(S,(2607956330U));
  ssSetChecksum3(S,(2554489841U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c36_tst_online(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "tst_online", "tst_online",36);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_tst_online(SimStruct *S)
{
  SFc36_tst_onlineInstanceStruct *chartInstance;
  chartInstance = (SFc36_tst_onlineInstanceStruct *)malloc(sizeof
    (SFc36_tst_onlineInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc36_tst_onlineInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c36_tst_online;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c36_tst_online;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c36_tst_online;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c36_tst_online;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c36_tst_online;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c36_tst_online;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c36_tst_online;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c36_tst_online;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c36_tst_online;
  chartInstance->chartInfo.mdlStart = mdlStart_c36_tst_online;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c36_tst_online;
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

void c36_tst_online_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_tst_online(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_tst_online(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_tst_online(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_tst_online_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}