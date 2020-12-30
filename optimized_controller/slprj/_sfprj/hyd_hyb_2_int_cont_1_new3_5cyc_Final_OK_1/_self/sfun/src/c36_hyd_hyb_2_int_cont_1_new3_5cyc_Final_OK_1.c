/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_sfun.h"
#include "c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c36_debug_family_names[17] = { "q", "u1", "r", "i", "k",
  "den", "nargin", "nargout", "x_feat", "teta_new_10", "init", "t", "T0", "T1",
  "mem", "u", "dist" };

/* Function Declarations */
static void initialize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void initialize_params_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void enable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void disable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void c36_update_debugger_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Fin
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static const mxArray
  *get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_st);
static void finalize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void c36_chartstep_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void initSimStructsc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_dist, const char_T *c36_identifier, real_T c36_y[4]);
static void c36_b_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[4]);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_c_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_d_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[40]);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_info_helper(c36_ResolvedFunctionInfo c36_info[19]);
static void c36_eml_scalar_eg
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void c36_b_eml_scalar_eg
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static real_T c36_ceval_xdot
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   int32_T c36_n, real_T c36_x[10], int32_T c36_ix0, int32_T c36_incx, real_T
   c36_y[10], int32_T c36_iy0, int32_T c36_incy);
static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_e_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_f_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_b_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1,
   const char_T *c36_identifier);
static uint8_T c36_g_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void init_dsm_address_info
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c36_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1 =
    0U;
}

static void initialize_params_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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

static void enable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c36_update_debugger_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Fin
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static const mxArray
  *get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  sf_mex_assign(&c36_y, sf_mex_createcellarray(3));
  for (c36_i1 = 0; c36_i1 < 4; c36_i1++) {
    c36_u[c36_i1] = (*c36_dist)[c36_i1];
  }

  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c36_y, 0, c36_b_y);
  for (c36_i2 = 0; c36_i2 < 4; c36_i2++) {
    c36_b_u[c36_i2] = (*c36_d_u)[c36_i2];
  }

  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", c36_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c36_y, 1, c36_c_y);
  c36_hoistedGlobal =
    chartInstance->c36_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  c36_c_u = c36_hoistedGlobal;
  c36_d_y = NULL;
  sf_mex_assign(&c36_d_y, sf_mex_create("y", &c36_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c36_y, 2, c36_d_y);
  sf_mex_assign(&c36_st, c36_y);
  return c36_st;
}

static void set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_st)
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

  chartInstance->c36_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1 =
    c36_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 2)),
    "is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1");
  sf_mex_destroy(&c36_u);
  c36_update_debugger_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Fin(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static void sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c36_sfEvent);
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
  c36_chartstep_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c36_chartstep_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  real_T c36_x;
  real_T c36_y;
  real_T c36_xk;
  real_T c36_yk;
  real_T c36_b_x;
  real_T c36_b_y;
  real_T c36_b_i;
  int32_T c36_c_i;
  int32_T c36_i18;
  real_T c36_a[10];
  int32_T c36_d_i;
  int32_T c36_i19;
  real_T c36_b[10];
  int32_T c36_i20;
  real_T c36_b_a[10];
  int32_T c36_i21;
  real_T c36_b_b[10];
  real_T c36_c_y;
  real_T c36_b_k;
  real_T c36_b_t;
  real_T c36_A;
  real_T c36_B;
  real_T c36_c_x;
  real_T c36_d_y;
  real_T c36_d_x;
  real_T c36_e_y;
  real_T c36_e_x;
  real_T c36_f_y;
  real_T c36_g_y;
  real_T c36_c_a;
  real_T c36_d_a;
  real_T c36_ak;
  real_T c36_c;
  real_T c36_b_B;
  real_T c36_h_y;
  real_T c36_i_y;
  real_T c36_j_y;
  real_T c36_k_y;
  int32_T c36_i22;
  int32_T c36_i23;
  int32_T c36_i24;
  int32_T c36_i25;
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
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c36_sfEvent);
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

  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c36_debug_family_names,
    c36_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c36_q, 0U, c36_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c36_u1, 1U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_r, 2U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_i, 3U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_k, 4U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_den, 5U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_nargin, 6U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_nargout, 7U,
    c36_b_sf_marshallOut, c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c36_x_feat, 8U, c36_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c36_b_teta_new_10, 9U,
    c36_c_sf_marshallOut, c36_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c36_init, 10U, c36_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c36_t, 11U, c36_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c36_b_T0, 12U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c36_b_T1, 13U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c36_mem, 14U, c36_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c36_u, 15U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c36_dist, 16U, c36_sf_marshallOut,
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
  if (CV_EML_IF(0, 0, c36_t >= c36_b_T0)) {
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 6);
    c36_x = c36_t;
    c36_y = c36_b_T1;
    c36_eml_scalar_eg(chartInstance);
    c36_xk = c36_x;
    c36_yk = c36_y;
    c36_b_x = c36_xk;
    c36_b_y = c36_yk;
    c36_r = muDoubleScalarRem(c36_b_x, c36_b_y);
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 8);
    if (CV_EML_IF(0, 1, c36_r <= 0.01)) {
      c36_i = 1.0;
      c36_b_i = 1.0;
      while (c36_b_i <= 4.0) {
        c36_i = c36_b_i;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 10);
        c36_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("teta_new_10", (int32_T)
          _SFD_INTEGER_CHECK("i", c36_i), 1, 4, 2, 0) - 1;
        for (c36_i18 = 0; c36_i18 < 10; c36_i18++) {
          c36_a[c36_i18] = c36_x_feat[c36_i18] - c36_b_teta_new_10[c36_i18 + 10 *
            c36_c_i];
        }

        c36_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("teta_new_10", (int32_T)
          _SFD_INTEGER_CHECK("i", c36_i), 1, 4, 2, 0) - 1;
        for (c36_i19 = 0; c36_i19 < 10; c36_i19++) {
          c36_b[c36_i19] = c36_x_feat[c36_i19] - c36_b_teta_new_10[c36_i19 + 10 *
            c36_d_i];
        }

        c36_b_eml_scalar_eg(chartInstance);
        for (c36_i20 = 0; c36_i20 < 10; c36_i20++) {
          c36_b_a[c36_i20] = c36_a[c36_i20];
        }

        for (c36_i21 = 0; c36_i21 < 10; c36_i21++) {
          c36_b_b[c36_i21] = c36_b[c36_i21];
        }

        c36_c_y = c36_ceval_xdot(chartInstance, 10, c36_b_a, 1, 1, c36_b_b, 1, 1);
        c36_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("dist", (int32_T)_SFD_INTEGER_CHECK
          ("i", c36_i), 1, 4, 1, 0) - 1] = c36_c_y;
        c36_b_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 0, 0);
      c36_k = 1.0;
      c36_b_k = 1.0;
      while (c36_b_k <= 4.0) {
        c36_k = c36_b_k;
        CV_EML_FOR(0, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 13);
        c36_den = 0.0;
        c36_t = 1.0;
        c36_b_t = 1.0;
        while (c36_b_t <= 4.0) {
          c36_t = c36_b_t;
          CV_EML_FOR(0, 2, 1);
          _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 15);
          c36_A = c36_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("dist", (int32_T)
            _SFD_INTEGER_CHECK("k", c36_k), 1, 4, 1, 0) - 1];
          c36_B = c36_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("dist", (int32_T)
            _SFD_INTEGER_CHECK("t", c36_t), 1, 4, 1, 0) - 1];
          c36_c_x = c36_A;
          c36_d_y = c36_B;
          c36_d_x = c36_c_x;
          c36_e_y = c36_d_y;
          c36_e_x = c36_d_x;
          c36_f_y = c36_e_y;
          c36_g_y = c36_e_x / c36_f_y;
          c36_c_a = c36_g_y;
          c36_d_a = c36_c_a;
          c36_eml_scalar_eg(chartInstance);
          c36_ak = c36_d_a;
          c36_c = muDoubleScalarPower(c36_ak, 1.0);
          c36_den += c36_c;
          c36_b_t++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_EML_FOR(0, 2, 0);
        _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 17);
        c36_b_B = c36_den;
        c36_h_y = c36_b_B;
        c36_i_y = c36_h_y;
        c36_j_y = c36_i_y;
        c36_k_y = 1.0 / c36_j_y;
        c36_u1[_SFD_EML_ARRAY_BOUNDS_CHECK("u1", (int32_T)_SFD_INTEGER_CHECK("k",
          c36_k), 1, 4, 1, 0) - 1] = c36_k_y;
        c36_b_k++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 19);
      for (c36_i22 = 0; c36_i22 < 4; c36_i22++) {
        c36_u[c36_i22] = c36_u1[c36_i22];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 21);
      for (c36_i23 = 0; c36_i23 < 4; c36_i23++) {
        c36_u[c36_i23] = c36_mem[c36_i23];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  for (c36_i24 = 0; c36_i24 < 4; c36_i24++) {
    (*c36_b_u)[c36_i24] = c36_u[c36_i24];
  }

  for (c36_i25 = 0; c36_i25 < 4; c36_i25++) {
    (*c36_b_dist)[c36_i25] = c36_dist[c36_i25];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c36_sfEvent);
}

static void initSimStructsc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  int32_T c36_i26;
  real_T c36_b_inData[4];
  int32_T c36_i27;
  real_T c36_u[4];
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i26 = 0; c36_i26 < 4; c36_i26++) {
    c36_b_inData[c36_i26] = (*(real_T (*)[4])c36_inData)[c36_i26];
  }

  for (c36_i27 = 0; c36_i27 < 4; c36_i27++) {
    c36_u[c36_i27] = c36_b_inData[c36_i27];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static void c36_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_dist, const char_T *c36_identifier, real_T c36_y[4])
{
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_dist), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_dist);
}

static void c36_b_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[4])
{
  real_T c36_dv3[4];
  int32_T c36_i28;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c36_i28 = 0; c36_i28 < 4; c36_i28++) {
    c36_y[c36_i28] = c36_dv3[c36_i28];
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
  int32_T c36_i29;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_dist = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_dist), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_dist);
  for (c36_i29 = 0; c36_i29 < 4; c36_i29++) {
    (*(real_T (*)[4])c36_outData)[c36_i29] = c36_y[c36_i29];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static real_T c36_c_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
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
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
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
  int32_T c36_i30;
  int32_T c36_i31;
  int32_T c36_i32;
  real_T c36_b_inData[40];
  int32_T c36_i33;
  int32_T c36_i34;
  int32_T c36_i35;
  real_T c36_u[40];
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_i30 = 0;
  for (c36_i31 = 0; c36_i31 < 4; c36_i31++) {
    for (c36_i32 = 0; c36_i32 < 10; c36_i32++) {
      c36_b_inData[c36_i32 + c36_i30] = (*(real_T (*)[40])c36_inData)[c36_i32 +
        c36_i30];
    }

    c36_i30 += 10;
  }

  c36_i33 = 0;
  for (c36_i34 = 0; c36_i34 < 4; c36_i34++) {
    for (c36_i35 = 0; c36_i35 < 10; c36_i35++) {
      c36_u[c36_i35 + c36_i33] = c36_b_inData[c36_i35 + c36_i33];
    }

    c36_i33 += 10;
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 10, 4));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static void c36_d_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[40])
{
  real_T c36_dv4[40];
  int32_T c36_i36;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv4, 1, 0, 0U, 1, 0U, 2, 10,
                4);
  for (c36_i36 = 0; c36_i36 < 40; c36_i36++) {
    c36_y[c36_i36] = c36_dv4[c36_i36];
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
  int32_T c36_i37;
  int32_T c36_i38;
  int32_T c36_i39;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_b_teta_new_10 = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_teta_new_10),
    &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_teta_new_10);
  c36_i37 = 0;
  for (c36_i38 = 0; c36_i38 < 4; c36_i38++) {
    for (c36_i39 = 0; c36_i39 < 10; c36_i39++) {
      (*(real_T (*)[40])c36_outData)[c36_i39 + c36_i37] = c36_y[c36_i39 +
        c36_i37];
    }

    c36_i37 += 10;
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i40;
  real_T c36_b_inData[10];
  int32_T c36_i41;
  real_T c36_u[10];
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i40 = 0; c36_i40 < 10; c36_i40++) {
    c36_b_inData[c36_i40] = (*(real_T (*)[10])c36_inData)[c36_i40];
  }

  for (c36_i41 = 0; c36_i41 < 10; c36_i41++) {
    c36_u[c36_i41] = c36_b_inData[c36_i41];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 10));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

const mxArray
  *sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c36_nameCaptureInfo;
  c36_ResolvedFunctionInfo c36_info[19];
  const mxArray *c36_m0 = NULL;
  int32_T c36_i42;
  c36_ResolvedFunctionInfo *c36_r0;
  c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  c36_info_helper(c36_info);
  sf_mex_assign(&c36_m0, sf_mex_createstruct("nameCaptureInfo", 1, 19));
  for (c36_i42 = 0; c36_i42 < 19; c36_i42++) {
    c36_r0 = &c36_info[c36_i42];
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", c36_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c36_r0->context)), "context", "nameCaptureInfo",
                    c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", c36_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c36_r0->name)), "name", "nameCaptureInfo",
                    c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo",
      c36_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c36_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", c36_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c36_r0->resolved)), "resolved",
                    "nameCaptureInfo", c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", &c36_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo", &c36_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo",
      &c36_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c36_i42);
    sf_mex_addfield(c36_m0, sf_mex_create("nameCaptureInfo",
      &c36_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c36_i42);
  }

  sf_mex_assign(&c36_nameCaptureInfo, c36_m0);
  return c36_nameCaptureInfo;
}

static void c36_info_helper(c36_ResolvedFunctionInfo c36_info[19])
{
  c36_info[0].context = "";
  c36_info[0].name = "rem";
  c36_info[0].dominantType = "double";
  c36_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c36_info[0].fileTimeLo = 2721966592U;
  c36_info[0].fileTimeHi = 30107998U;
  c36_info[0].mFileTimeLo = 0U;
  c36_info[0].mFileTimeHi = 0U;
  c36_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c36_info[1].name = "eml_scalar_eg";
  c36_info[1].dominantType = "double";
  c36_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c36_info[1].fileTimeLo = 3201966592U;
  c36_info[1].fileTimeHi = 30107998U;
  c36_info[1].mFileTimeLo = 0U;
  c36_info[1].mFileTimeHi = 0U;
  c36_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c36_info[2].name = "eml_scalexp_alloc";
  c36_info[2].dominantType = "double";
  c36_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c36_info[2].fileTimeLo = 3201966592U;
  c36_info[2].fileTimeHi = 30107998U;
  c36_info[2].mFileTimeLo = 0U;
  c36_info[2].mFileTimeHi = 0U;
  c36_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c36_info[3].name = "eml_scalar_rem";
  c36_info[3].dominantType = "double";
  c36_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  c36_info[3].fileTimeLo = 2561966592U;
  c36_info[3].fileTimeHi = 30107998U;
  c36_info[3].mFileTimeLo = 0U;
  c36_info[3].mFileTimeHi = 0U;
  c36_info[4].context = "";
  c36_info[4].name = "mtimes";
  c36_info[4].dominantType = "double";
  c36_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c36_info[4].fileTimeLo = 3767347712U;
  c36_info[4].fileTimeHi = 30114278U;
  c36_info[4].mFileTimeLo = 0U;
  c36_info[4].mFileTimeHi = 0U;
  c36_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c36_info[5].name = "eml_index_class";
  c36_info[5].dominantType = "";
  c36_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c36_info[5].fileTimeLo = 3021966592U;
  c36_info[5].fileTimeHi = 30107998U;
  c36_info[5].mFileTimeLo = 0U;
  c36_info[5].mFileTimeHi = 0U;
  c36_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c36_info[6].name = "eml_xdotu";
  c36_info[6].dominantType = "int32";
  c36_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c36_info[6].fileTimeLo = 2321966592U;
  c36_info[6].fileTimeHi = 30107998U;
  c36_info[6].mFileTimeLo = 0U;
  c36_info[6].mFileTimeHi = 0U;
  c36_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c36_info[7].name = "eml_xdot";
  c36_info[7].dominantType = "int32";
  c36_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c36_info[7].fileTimeLo = 2321966592U;
  c36_info[7].fileTimeHi = 30107998U;
  c36_info[7].mFileTimeLo = 0U;
  c36_info[7].mFileTimeHi = 0U;
  c36_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c36_info[8].name = "eml_refblas_xdot";
  c36_info[8].dominantType = "int32";
  c36_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c36_info[8].fileTimeLo = 3041966592U;
  c36_info[8].fileTimeHi = 30107998U;
  c36_info[8].mFileTimeLo = 0U;
  c36_info[8].mFileTimeHi = 0U;
  c36_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c36_info[9].name = "eml_refblas_xdotx";
  c36_info[9].dominantType = "int32";
  c36_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c36_info[9].fileTimeLo = 3061966592U;
  c36_info[9].fileTimeHi = 30107998U;
  c36_info[9].mFileTimeLo = 0U;
  c36_info[9].mFileTimeHi = 0U;
  c36_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c36_info[10].name = "eml_index_minus";
  c36_info[10].dominantType = "int32";
  c36_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c36_info[10].fileTimeLo = 3021966592U;
  c36_info[10].fileTimeHi = 30107998U;
  c36_info[10].mFileTimeLo = 0U;
  c36_info[10].mFileTimeHi = 0U;
  c36_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c36_info[11].name = "eml_index_plus";
  c36_info[11].dominantType = "int32";
  c36_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c36_info[11].fileTimeLo = 3021966592U;
  c36_info[11].fileTimeHi = 30107998U;
  c36_info[11].mFileTimeLo = 0U;
  c36_info[11].mFileTimeHi = 0U;
  c36_info[12].context = "";
  c36_info[12].name = "mrdivide";
  c36_info[12].dominantType = "double";
  c36_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c36_info[12].fileTimeLo = 2311411456U;
  c36_info[12].fileTimeHi = 30130914U;
  c36_info[12].mFileTimeLo = 3767347712U;
  c36_info[12].mFileTimeHi = 30114278U;
  c36_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c36_info[13].name = "rdivide";
  c36_info[13].dominantType = "double";
  c36_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c36_info[13].fileTimeLo = 3681966592U;
  c36_info[13].fileTimeHi = 30107998U;
  c36_info[13].mFileTimeLo = 0U;
  c36_info[13].mFileTimeHi = 0U;
  c36_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c36_info[14].name = "eml_div";
  c36_info[14].dominantType = "double";
  c36_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c36_info[14].fileTimeLo = 2221966592U;
  c36_info[14].fileTimeHi = 30107998U;
  c36_info[14].mFileTimeLo = 0U;
  c36_info[14].mFileTimeHi = 0U;
  c36_info[15].context = "";
  c36_info[15].name = "mpower";
  c36_info[15].dominantType = "double";
  c36_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c36_info[15].fileTimeLo = 3661966592U;
  c36_info[15].fileTimeHi = 30107998U;
  c36_info[15].mFileTimeLo = 0U;
  c36_info[15].mFileTimeHi = 0U;
  c36_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c36_info[16].name = "power";
  c36_info[16].dominantType = "double";
  c36_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c36_info[16].fileTimeLo = 3681966592U;
  c36_info[16].fileTimeHi = 30107998U;
  c36_info[16].mFileTimeLo = 0U;
  c36_info[16].mFileTimeHi = 0U;
  c36_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c36_info[17].name = "eml_scalar_floor";
  c36_info[17].dominantType = "double";
  c36_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c36_info[17].fileTimeLo = 2501966592U;
  c36_info[17].fileTimeHi = 30107998U;
  c36_info[17].mFileTimeLo = 0U;
  c36_info[17].mFileTimeHi = 0U;
  c36_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c36_info[18].name = "eml_error";
  c36_info[18].dominantType = "char";
  c36_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c36_info[18].fileTimeLo = 2241966592U;
  c36_info[18].fileTimeHi = 30107998U;
  c36_info[18].mFileTimeLo = 0U;
  c36_info[18].mFileTimeHi = 0U;
}

static void c36_eml_scalar_eg
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static void c36_b_eml_scalar_eg
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static real_T c36_ceval_xdot
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   int32_T c36_n, real_T c36_x[10], int32_T c36_ix0, int32_T c36_incx, real_T
   c36_y[10], int32_T c36_iy0, int32_T c36_incy)
{
  real_T c36_d;
  c36_d = 0.0;
  if ((real_T)c36_n > 0.0) {
    c36_d = ddot32(&c36_n, &c36_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c36_ix0), 1, 10, 1, 0) - 1], &c36_incx,
                   &c36_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c36_iy0), 1, 10, 1, 0) - 1], &c36_incy);
  }

  return c36_d;
}

static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c36_mxArrayOutData, c36_y);
  return c36_mxArrayOutData;
}

static int32_T c36_e_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i43;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_i43, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i43;
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
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
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
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_b_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1,
   const char_T *c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1);
  return c36_y;
}

static uint8_T c36_g_emlrt_marshallIn
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void init_dsm_address_info
  (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2446186649U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2828188716U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2733540411U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2510591872U);
}

mxArray
  *sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4059375234U);
    pr[1] = (double)(696778438U);
    pr[2] = (double)(1591300608U);
    pr[3] = (double)(1195417040U);
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

static const mxArray
  *sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"dist\",},{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
    chartInstance =
      (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
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
          init_script_number_translation
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,2,0,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",1,-1,531);
        _SFD_CV_INIT_EML_IF(0,0,109,117,-1,527);
        _SFD_CV_INIT_EML_IF(0,1,159,171,496,523);
        _SFD_CV_INIT_EML_FOR(0,0,189,199,284);
        _SFD_CV_INIT_EML_FOR(0,1,309,319,469);
        _SFD_CV_INIT_EML_FOR(0,2,350,360,430);
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
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
  initialize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void *
  chartInstanceVar)
{
  enable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void
  *chartInstanceVar)
{
  disable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void
  *chartInstanceVar)
{
  sf_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*)
    get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1();/* state var info */
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

extern void
  sf_internal_set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
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
    sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    (S);
}

static void
  sf_opaque_set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S, st);
}

static void sf_opaque_terminate_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
      ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
      ((SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct *S)
{
  /* Actual parameters from chart:
     T0 T1 teta_new_10
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for teta_new_10*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,
                "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
                "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36,4);
      sf_mark_chart_reusable_outputs(S,
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36,2);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
                          "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1786259345U));
  ssSetChecksum1(S,(2479347539U));
  ssSetChecksum2(S,(1131110754U));
  ssSetChecksum3(S,(2376120980U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",36);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(SimStruct *S)
{
  SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)malloc(sizeof
    (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
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

void c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
