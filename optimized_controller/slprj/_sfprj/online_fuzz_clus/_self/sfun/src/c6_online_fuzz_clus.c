/* Include files */

#include "blascompat32.h"
#include "online_fuzz_clus_sfun.h"
#include "c6_online_fuzz_clus.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "online_fuzz_clus_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[15] = { "dist1", "p", "q", "dist2",
  "j", "num", "e", "k", "den", "t", "nargin", "nargout", "x_feat", "teta", "u" };

/* Function Declarations */
static void initialize_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initialize_params_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance);
static void enable_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance);
static void disable_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance);
static void set_sim_state_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c6_st);
static void finalize_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance);
static void sf_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initSimStructsc6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const char_T *c6_identifier, real_T c6_y
  [4]);
static void c6_b_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[24]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_d_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static real_T c6_power(SFc6_online_fuzz_clusInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_b);
static void c6_eml_error(SFc6_online_fuzz_clusInstanceStruct *chartInstance);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_online_fuzz_clus, const
  char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_online_fuzz_clus = 0U;
}

static void initialize_params_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance)
{
  real_T c6_dv0[24];
  int32_T c6_i0;
  sf_set_error_prefix_string(
    "Error evaluating data 'teta' in the parent workspace.\n");
  sf_mex_import_named("teta", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c6_dv0, 0, 0, 0U, 1, 0U, 2, 6, 4);
  for (c6_i0 = 0; c6_i0 < 24; c6_i0++) {
    chartInstance->c6_teta[c6_i0] = c6_dv0[c6_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i1;
  real_T c6_u[4];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_c_u)[4];
  c6_c_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i1 = 0; c6_i1 < 4; c6_i1++) {
    c6_u[c6_i1] = (*c6_c_u)[c6_i1];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_online_fuzz_clus;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv1[4];
  int32_T c6_i2;
  real_T (*c6_b_u)[4];
  c6_b_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "u",
                      c6_dv1);
  for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
    (*c6_b_u)[c6_i2] = c6_dv1[c6_i2];
  }

  chartInstance->c6_is_active_c6_online_fuzz_clus = c6_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_online_fuzz_clus");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_online_fuzz_clus(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

static void sf_c6_online_fuzz_clus(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  real_T c6_x_feat[6];
  int32_T c6_i7;
  real_T c6_b_teta[24];
  uint32_T c6_debug_family_var_map[15];
  real_T c6_dist1[4];
  real_T c6_p;
  real_T c6_q;
  real_T c6_dist2[4];
  real_T c6_j;
  real_T c6_num;
  real_T c6_e;
  real_T c6_k;
  real_T c6_den;
  real_T c6_t;
  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  real_T c6_u[4];
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  real_T c6_b_j;
  real_T c6_b_e;
  real_T c6_A;
  real_T c6_B;
  real_T c6_x;
  real_T c6_y;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_d_y;
  real_T c6_a;
  real_T c6_c;
  real_T c6_b_a;
  real_T c6_b_c;
  real_T c6_b_k;
  real_T c6_b_t;
  real_T c6_b_A;
  real_T c6_b_B;
  real_T c6_d_x;
  real_T c6_e_y;
  real_T c6_e_x;
  real_T c6_f_y;
  real_T c6_f_x;
  real_T c6_g_y;
  real_T c6_h_y;
  real_T c6_c_a;
  real_T c6_c_c;
  real_T c6_c_B;
  real_T c6_i_y;
  real_T c6_j_y;
  real_T c6_k_y;
  real_T c6_l_y;
  int32_T c6_i11;
  real_T (*c6_b_u)[4];
  real_T (*c6_b_x_feat)[6];
  c6_b_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_x_feat = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i3 = 0; c6_i3 < 6; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_x_feat)[c6_i3], 0U);
  }

  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_u)[c6_i4], 1U);
  }

  for (c6_i5 = 0; c6_i5 < 24; c6_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_teta[c6_i5], 2U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i6 = 0; c6_i6 < 6; c6_i6++) {
    c6_x_feat[c6_i6] = (*c6_b_x_feat)[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 24; c6_i7++) {
    c6_b_teta[c6_i7] = chartInstance->c6_teta[c6_i7];
  }

  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c6_dist1, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_p, 1U, c6_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_q, 2U, c6_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_dist2, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_j, 4U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_num, 5U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_e, 6U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_k, 7U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_den, 8U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_t, 9U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 10U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 11U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c6_x_feat, 12U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_b_teta, 13U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_u, 14U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 2);
  for (c6_i8 = 0; c6_i8 < 4; c6_i8++) {
    c6_dist1[c6_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 2);
  for (c6_i9 = 0; c6_i9 < 4; c6_i9++) {
    c6_u[c6_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_p = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_q = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
    c6_dist2[c6_i10] = 0.0;
  }

  c6_j = 1.0;
  c6_b_j = 1.0;
  while (c6_b_j <= 4.0) {
    c6_j = c6_b_j;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
    c6_num = 0.0;
    c6_e = 1.0;
    c6_b_e = 1.0;
    while (c6_b_e <= 6.0) {
      c6_e = c6_b_e;
      CV_EML_FOR(0, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
      c6_num++;
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
      c6_A = c6_x_feat[_SFD_EML_ARRAY_BOUNDS_CHECK("x_feat", (int32_T)
        _SFD_INTEGER_CHECK("e", c6_e), 1, 6, 1, 0) - 1] - c6_b_teta
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("teta", (int32_T)_SFD_INTEGER_CHECK("e",
            c6_e), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("teta",
            (int32_T)_SFD_INTEGER_CHECK("j", c6_j), 1, 4, 2, 0) - 1)) - 1];
      c6_B = c6_b_teta[(_SFD_EML_ARRAY_BOUNDS_CHECK("teta", (int32_T)
        _SFD_INTEGER_CHECK("e", c6_e), 1, 6, 1, 0) + 6 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("teta", (int32_T)
        _SFD_INTEGER_CHECK("j", c6_j), 1, 4, 2, 0) - 1)) - 1];
      c6_x = c6_A;
      c6_y = c6_B;
      c6_b_x = c6_x;
      c6_b_y = c6_y;
      c6_c_x = c6_b_x;
      c6_c_y = c6_b_y;
      c6_d_y = c6_c_x / c6_c_y;
      c6_a = c6_d_y;
      c6_c = c6_power(chartInstance, c6_a, 4.0);
      c6_dist1[_SFD_EML_ARRAY_BOUNDS_CHECK("dist1", (int32_T)_SFD_INTEGER_CHECK(
        "j", c6_j), 1, 4, 1, 0) - 1] = c6_dist1[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "dist1", (int32_T)_SFD_INTEGER_CHECK("j", c6_j), 1, 4, 1, 0) - 1] + c6_c;
      c6_b_e++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
    c6_b_a = c6_dist1[_SFD_EML_ARRAY_BOUNDS_CHECK("dist1", (int32_T)
      _SFD_INTEGER_CHECK("j", c6_j), 1, 4, 1, 0) - 1];
    c6_b_c = c6_power(chartInstance, c6_b_a, 0.25);
    c6_dist2[_SFD_EML_ARRAY_BOUNDS_CHECK("dist2", (int32_T)_SFD_INTEGER_CHECK(
      "j", c6_j), 1, 4, 1, 0) - 1] = c6_b_c;
    c6_b_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 0, 0);
  c6_k = 1.0;
  c6_b_k = 1.0;
  while (c6_b_k <= 4.0) {
    c6_k = c6_b_k;
    CV_EML_FOR(0, 2, 1);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
    c6_den = 0.0;
    c6_t = 1.0;
    c6_b_t = 1.0;
    while (c6_b_t <= 4.0) {
      c6_t = c6_b_t;
      CV_EML_FOR(0, 3, 1);
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
      c6_b_A = c6_dist2[_SFD_EML_ARRAY_BOUNDS_CHECK("dist2", (int32_T)
        _SFD_INTEGER_CHECK("k", c6_k), 1, 4, 1, 0) - 1];
      c6_b_B = c6_dist2[_SFD_EML_ARRAY_BOUNDS_CHECK("dist2", (int32_T)
        _SFD_INTEGER_CHECK("t", c6_t), 1, 4, 1, 0) - 1];
      c6_d_x = c6_b_A;
      c6_e_y = c6_b_B;
      c6_e_x = c6_d_x;
      c6_f_y = c6_e_y;
      c6_f_x = c6_e_x;
      c6_g_y = c6_f_y;
      c6_h_y = c6_f_x / c6_g_y;
      c6_c_a = c6_h_y;
      c6_c_c = c6_power(chartInstance, c6_c_a, 1.0);
      c6_den += c6_c_c;
      c6_b_t++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 3, 0);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
    c6_c_B = c6_den;
    c6_i_y = c6_c_B;
    c6_j_y = c6_i_y;
    c6_k_y = c6_j_y;
    c6_l_y = 1.0 / c6_k_y;
    c6_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)_SFD_INTEGER_CHECK("k", c6_k),
      1, 4, 1, 0) - 1] = c6_l_y;
    c6_b_k++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 2, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -17);
  sf_debug_symbol_scope_pop();
  for (c6_i11 = 0; c6_i11 < 4; c6_i11++) {
    (*c6_b_u)[c6_i11] = c6_u[c6_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  sf_debug_check_for_state_inconsistency(_online_fuzz_clusMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_online_fuzz_clus
  (SFc6_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i12;
  real_T c6_b_inData[4];
  int32_T c6_i13;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i12 = 0; c6_i12 < 4; c6_i12++) {
    c6_b_inData[c6_i12] = (*(real_T (*)[4])c6_inData)[c6_i12];
  }

  for (c6_i13 = 0; c6_i13 < 4; c6_i13++) {
    c6_u[c6_i13] = c6_b_inData[c6_i13];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const char_T *c6_identifier, real_T c6_y
  [4])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_u), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_u);
}

static void c6_b_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4])
{
  real_T c6_dv2[4];
  int32_T c6_i14;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c6_i14 = 0; c6_i14 < 4; c6_i14++) {
    c6_y[c6_i14] = c6_dv2[c6_i14];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_u;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i15;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_u = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_u), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_u);
  for (c6_i15 = 0; c6_i15 < 4; c6_i15++) {
    (*(real_T (*)[4])c6_outData)[c6_i15] = c6_y[c6_i15];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  real_T c6_b_inData[24];
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  real_T c6_u[24];
  const mxArray *c6_y = NULL;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i16 = 0;
  for (c6_i17 = 0; c6_i17 < 4; c6_i17++) {
    for (c6_i18 = 0; c6_i18 < 6; c6_i18++) {
      c6_b_inData[c6_i18 + c6_i16] = (*(real_T (*)[24])c6_inData)[c6_i18 +
        c6_i16];
    }

    c6_i16 += 6;
  }

  c6_i19 = 0;
  for (c6_i20 = 0; c6_i20 < 4; c6_i20++) {
    for (c6_i21 = 0; c6_i21 < 6; c6_i21++) {
      c6_u[c6_i21 + c6_i19] = c6_b_inData[c6_i21 + c6_i19];
    }

    c6_i19 += 6;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[24])
{
  real_T c6_dv3[24];
  int32_T c6_i22;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv3, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c6_i22 = 0; c6_i22 < 24; c6_i22++) {
    c6_y[c6_i22] = c6_dv3[c6_i22];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_teta;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[24];
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_b_teta = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_teta), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_teta);
  c6_i23 = 0;
  for (c6_i24 = 0; c6_i24 < 4; c6_i24++) {
    for (c6_i25 = 0; c6_i25 < 6; c6_i25++) {
      (*(real_T (*)[24])c6_outData)[c6_i25 + c6_i23] = c6_y[c6_i25 + c6_i23];
    }

    c6_i23 += 6;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i26;
  real_T c6_b_inData[6];
  int32_T c6_i27;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i26 = 0; c6_i26 < 6; c6_i26++) {
    c6_b_inData[c6_i26] = (*(real_T (*)[6])c6_inData)[c6_i26];
  }

  for (c6_i27 = 0; c6_i27 < 6; c6_i27++) {
    c6_u[c6_i27] = c6_b_inData[c6_i27];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static real_T c6_d_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_online_fuzz_clus_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[9];
  c6_ResolvedFunctionInfo (*c6_b_info)[9];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i28;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[9])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "mrdivide";
  (*c6_b_info)[0].dominantType = "double";
  (*c6_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c6_b_info)[0].fileTimeLo = 2311411456U;
  (*c6_b_info)[0].fileTimeHi = 30130914U;
  (*c6_b_info)[0].mFileTimeLo = 3767347712U;
  (*c6_b_info)[0].mFileTimeHi = 30114278U;
  (*c6_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c6_b_info)[1].name = "rdivide";
  (*c6_b_info)[1].dominantType = "double";
  (*c6_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[1].fileTimeLo = 3681966592U;
  (*c6_b_info)[1].fileTimeHi = 30107998U;
  (*c6_b_info)[1].mFileTimeLo = 0U;
  (*c6_b_info)[1].mFileTimeHi = 0U;
  (*c6_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[2].name = "eml_div";
  (*c6_b_info)[2].dominantType = "double";
  (*c6_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c6_b_info)[2].fileTimeLo = 2221966592U;
  (*c6_b_info)[2].fileTimeHi = 30107998U;
  (*c6_b_info)[2].mFileTimeLo = 0U;
  (*c6_b_info)[2].mFileTimeHi = 0U;
  (*c6_b_info)[3].context = "";
  (*c6_b_info)[3].name = "mpower";
  (*c6_b_info)[3].dominantType = "double";
  (*c6_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c6_b_info)[3].fileTimeLo = 3661966592U;
  (*c6_b_info)[3].fileTimeHi = 30107998U;
  (*c6_b_info)[3].mFileTimeLo = 0U;
  (*c6_b_info)[3].mFileTimeHi = 0U;
  (*c6_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c6_b_info)[4].name = "power";
  (*c6_b_info)[4].dominantType = "double";
  (*c6_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[4].fileTimeLo = 3681966592U;
  (*c6_b_info)[4].fileTimeHi = 30107998U;
  (*c6_b_info)[4].mFileTimeLo = 0U;
  (*c6_b_info)[4].mFileTimeHi = 0U;
  (*c6_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[5].name = "eml_scalar_eg";
  (*c6_b_info)[5].dominantType = "double";
  (*c6_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c6_b_info)[5].fileTimeLo = 3201966592U;
  (*c6_b_info)[5].fileTimeHi = 30107998U;
  (*c6_b_info)[5].mFileTimeLo = 0U;
  (*c6_b_info)[5].mFileTimeHi = 0U;
  (*c6_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[6].name = "eml_scalexp_alloc";
  (*c6_b_info)[6].dominantType = "double";
  (*c6_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c6_b_info)[6].fileTimeLo = 3201966592U;
  (*c6_b_info)[6].fileTimeHi = 30107998U;
  (*c6_b_info)[6].mFileTimeLo = 0U;
  (*c6_b_info)[6].mFileTimeHi = 0U;
  (*c6_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[7].name = "eml_scalar_floor";
  (*c6_b_info)[7].dominantType = "double";
  (*c6_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c6_b_info)[7].fileTimeLo = 2501966592U;
  (*c6_b_info)[7].fileTimeHi = 30107998U;
  (*c6_b_info)[7].mFileTimeLo = 0U;
  (*c6_b_info)[7].mFileTimeHi = 0U;
  (*c6_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[8].name = "eml_error";
  (*c6_b_info)[8].dominantType = "char";
  (*c6_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c6_b_info)[8].fileTimeLo = 2241966592U;
  (*c6_b_info)[8].fileTimeHi = 30107998U;
  (*c6_b_info)[8].mFileTimeLo = 0U;
  (*c6_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9));
  for (c6_i28 = 0; c6_i28 < 9; c6_i28++) {
    c6_r0 = &c6_info[c6_i28];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i28);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i28);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static real_T c6_power(SFc6_online_fuzz_clusInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_b)
{
  real_T c6_ak;
  real_T c6_bk;
  real_T c6_x;
  real_T c6_b_x;
  c6_ak = c6_a;
  c6_bk = c6_b;
  if (c6_ak < 0.0) {
    c6_x = c6_bk;
    c6_b_x = c6_x;
    c6_b_x = muDoubleScalarFloor(c6_b_x);
    if (c6_b_x != c6_bk) {
      c6_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c6_ak, c6_bk);
}

static void c6_eml_error(SFc6_online_fuzz_clusInstanceStruct *chartInstance)
{
  int32_T c6_i29;
  static char_T c6_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[31];
  const mxArray *c6_y = NULL;
  for (c6_i29 = 0; c6_i29 < 31; c6_i29++) {
    c6_u[c6_i29] = c6_varargin_1[c6_i29];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i30;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i30, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i30;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_online_fuzz_clus, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_online_fuzz_clus), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_online_fuzz_clus);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_online_fuzz_clus_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3533532452U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4081344761U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3255168589U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1565771604U);
}

mxArray *sf_c6_online_fuzz_clus_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(37490709U);
    pr[1] = (double)(4086219540U);
    pr[2] = (double)(788903539U);
    pr[3] = (double)(3291491354U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c6_online_fuzz_clus(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c6_online_fuzz_clus\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_online_fuzz_clus_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_online_fuzz_clusInstanceStruct *chartInstance;
    chartInstance = (SFc6_online_fuzz_clusInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_online_fuzz_clusMachineNumber_,
           6,
           1,
           1,
           3,
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
          init_script_number_translation(_online_fuzz_clusMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_online_fuzz_clusMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_online_fuzz_clusMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x_feat");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u");
          _SFD_SET_DATA_PROPS(2,10,0,0,"teta");
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
        _SFD_CV_INIT_EML(0,1,0,0,0,4,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,367);
        _SFD_CV_INIT_EML_FOR(0,0,88,98,249);
        _SFD_CV_INIT_EML_FOR(0,1,113,123,214);
        _SFD_CV_INIT_EML_FOR(0,2,250,260,363);
        _SFD_CV_INIT_EML_FOR(0,3,275,285,341);
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
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        {
          real_T (*c6_x_feat)[6];
          real_T (*c6_u)[4];
          c6_u = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_x_feat = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_x_feat);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_u);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c6_teta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_online_fuzz_clusMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_online_fuzz_clus(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_online_fuzz_clusInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
  initialize_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_online_fuzz_clus(void *chartInstanceVar)
{
  enable_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_online_fuzz_clus(void *chartInstanceVar)
{
  disable_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_online_fuzz_clus(void *chartInstanceVar)
{
  sf_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_online_fuzz_clus(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_online_fuzz_clus
    ((SFc6_online_fuzz_clusInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_online_fuzz_clus();/* state var info */
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

extern void sf_internal_set_sim_state_c6_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_online_fuzz_clus();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_online_fuzz_clus(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_online_fuzz_clus(S);
}

static void sf_opaque_set_sim_state_c6_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_online_fuzz_clus(S, st);
}

static void sf_opaque_terminate_c6_online_fuzz_clus(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_online_fuzz_clusInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_online_fuzz_clus(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_online_fuzz_clus((SFc6_online_fuzz_clusInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_online_fuzz_clus(SimStruct *S)
{
  /* Actual parameters from chart:
     teta
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for teta*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"online_fuzz_clus","online_fuzz_clus",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus","online_fuzz_clus",6,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus",
      "online_fuzz_clus",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"online_fuzz_clus",
        "online_fuzz_clus",6,1);
      sf_mark_chart_reusable_outputs(S,"online_fuzz_clus","online_fuzz_clus",6,1);
    }

    sf_set_rtw_dwork_info(S,"online_fuzz_clus","online_fuzz_clus",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4194599815U));
  ssSetChecksum1(S,(2665775554U));
  ssSetChecksum2(S,(775484543U));
  ssSetChecksum3(S,(4156309264U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "online_fuzz_clus", "online_fuzz_clus",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_online_fuzz_clus(SimStruct *S)
{
  SFc6_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc6_online_fuzz_clusInstanceStruct *)malloc(sizeof
    (SFc6_online_fuzz_clusInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_online_fuzz_clusInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_online_fuzz_clus;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_online_fuzz_clus;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_online_fuzz_clus;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_online_fuzz_clus;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_online_fuzz_clus;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_online_fuzz_clus;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_online_fuzz_clus;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_online_fuzz_clus;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_online_fuzz_clus;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_online_fuzz_clus;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_online_fuzz_clus;
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

void c6_online_fuzz_clus_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_online_fuzz_clus(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_online_fuzz_clus_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
