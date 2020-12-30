/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_sfun.h"
#include "c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[12] = { "U", "U_max", "nargin",
  "nargout", "u1", "u2", "u3", "u4", "y1", "y2", "y3", "y4" };

/* Function Declarations */
static void initialize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void initialize_params_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void enable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void disable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_st);
static void finalize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void c9_chartstep_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void initSimStructsc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_y4, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[4]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_d_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_e_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_b_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK,
   const char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK = 0U;
}

static void initialize_params_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
}

static void enable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  uint8_T c9_e_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T *c9_y1;
  real_T *c9_y2;
  real_T *c9_y3;
  real_T *c9_y4;
  c9_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(5));
  c9_hoistedGlobal = *c9_y1;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_y2;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_y3;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *c9_y4;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal =
    chartInstance->c9_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 4, c9_f_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_y1;
  real_T *c9_y2;
  real_T *c9_y3;
  real_T *c9_y4;
  c9_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_y1 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
    "y1");
  *c9_y2 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "y2");
  *c9_y3 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
    "y3");
  *c9_y4 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
    "y4");
  chartInstance->c9_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK =
    c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 4)),
    "is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
}

static void sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
  real_T *c9_u1;
  real_T *c9_y1;
  real_T *c9_u2;
  real_T *c9_u3;
  real_T *c9_u4;
  real_T *c9_y2;
  real_T *c9_y3;
  real_T *c9_y4;
  c9_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_u4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_u1, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_y1, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_u2, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_u3, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_u4, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_y2, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_y3, 6U);
  _SFD_DATA_RANGE_CHECK(*c9_y4, 7U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_u1;
  real_T c9_u2;
  real_T c9_u3;
  real_T c9_u4;
  uint32_T c9_debug_family_var_map[12];
  real_T c9_U[4];
  real_T c9_U_max;
  real_T c9_nargin = 4.0;
  real_T c9_nargout = 4.0;
  real_T c9_y1;
  real_T c9_y2;
  real_T c9_y3;
  real_T c9_y4;
  int32_T c9_i0;
  real_T c9_varargin_1[4];
  real_T c9_mtmp;
  int32_T c9_itmp;
  int32_T c9_ix;
  real_T c9_x;
  boolean_T c9_b;
  boolean_T c9_searchingForNonNaN;
  int32_T c9_k;
  int32_T c9_b_k;
  int32_T c9_a;
  real_T c9_b_x;
  boolean_T c9_b_b;
  int32_T c9_b_a;
  int32_T c9_i1;
  int32_T c9_b_ix;
  real_T c9_b_mtmp;
  real_T *c9_b_y4;
  real_T *c9_b_y3;
  real_T *c9_b_y2;
  real_T *c9_b_y1;
  real_T *c9_b_u4;
  real_T *c9_b_u3;
  real_T *c9_b_u2;
  real_T *c9_b_u1;
  boolean_T guard1 = FALSE;
  boolean_T exitg1;
  c9_b_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_b_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_u4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_u1;
  c9_b_hoistedGlobal = *c9_b_u2;
  c9_c_hoistedGlobal = *c9_b_u3;
  c9_d_hoistedGlobal = *c9_b_u4;
  c9_u1 = c9_hoistedGlobal;
  c9_u2 = c9_b_hoistedGlobal;
  c9_u3 = c9_c_hoistedGlobal;
  c9_u4 = c9_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c9_U, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_U_max, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_u1, 4U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_u2, 5U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_u3, 6U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_u4, 7U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_y1, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_y2, 9U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_y3, 10U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_y4, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 2);
  c9_U[0] = c9_u1;
  c9_U[1] = c9_u2;
  c9_U[2] = c9_u3;
  c9_U[3] = c9_u4;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  for (c9_i0 = 0; c9_i0 < 4; c9_i0++) {
    c9_varargin_1[c9_i0] = c9_U[c9_i0];
  }

  c9_mtmp = c9_varargin_1[0];
  c9_itmp = 2;
  c9_ix = 1;
  c9_x = c9_mtmp;
  c9_b = muDoubleScalarIsNaN(c9_x);
  guard1 = FALSE;
  if (c9_b) {
    c9_searchingForNonNaN = TRUE;
    c9_k = 2;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (c9_k < 5)) {
      c9_b_k = c9_k;
      c9_a = c9_ix + 1;
      c9_ix = c9_a;
      c9_b_x = c9_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c9_ix), 1, 4, 1, 0) - 1];
      c9_b_b = muDoubleScalarIsNaN(c9_b_x);
      if (!c9_b_b) {
        c9_mtmp = c9_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_ix), 1, 4, 1, 0) - 1];
        c9_itmp = c9_b_k + 1;
        c9_searchingForNonNaN = FALSE;
        exitg1 = 1U;
      } else {
        c9_k++;
      }
    }

    if (c9_searchingForNonNaN) {
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c9_b_a = c9_itmp;
    c9_i1 = c9_b_a;
    for (c9_b_ix = c9_i1; c9_b_ix < 5; c9_b_ix++) {
      c9_ix = c9_b_ix;
      if (c9_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c9_ix), 1, 4, 1, 0) - 1] > c9_mtmp) {
        c9_mtmp = c9_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_ix), 1, 4, 1, 0) - 1];
      }
    }
  }

  c9_b_mtmp = c9_mtmp;
  c9_U_max = c9_b_mtmp;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  if (CV_EML_IF(0, 0, c9_U_max == c9_u1)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
    c9_y1 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
    c9_y2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
    c9_y3 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
    c9_y4 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
    if (CV_EML_IF(0, 1, c9_U_max == c9_u2)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
      c9_y1 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
      c9_y2 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
      c9_y3 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
      c9_y4 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
      if (CV_EML_IF(0, 2, c9_U_max == c9_u3)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
        c9_y1 = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
        c9_y2 = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 17);
        c9_y3 = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
        c9_y4 = 0.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 20);
        c9_y1 = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
        c9_y2 = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
        c9_y3 = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 23);
        c9_y4 = 1.0;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -23);
  sf_debug_symbol_scope_pop();
  *c9_b_y1 = c9_y1;
  *c9_b_y2 = c9_y2;
  *c9_b_y3 = c9_y3;
  *c9_b_y4 = c9_y4;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_y4, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_y4), &c9_thisId);
  sf_mex_destroy(&c9_y4);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_y4;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    chartInstanceVoid;
  c9_y4 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_y4), &c9_thisId);
  sf_mex_destroy(&c9_y4);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i2;
  real_T c9_b_inData[4];
  int32_T c9_i3;
  real_T c9_u[4];
  const mxArray *c9_y = NULL;
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i2 = 0; c9_i2 < 4; c9_i2++) {
    c9_b_inData[c9_i2] = (*(real_T (*)[4])c9_inData)[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 4; c9_i3++) {
    c9_u[c9_i3] = c9_b_inData[c9_i3];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[4])
{
  real_T c9_dv0[4];
  int32_T c9_i4;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c9_i4 = 0; c9_i4 < 4; c9_i4++) {
    c9_y[c9_i4] = c9_dv0[c9_i4];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_U;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[4];
  int32_T c9_i5;
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    chartInstanceVoid;
  c9_U = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_U), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_U);
  for (c9_i5 = 0; c9_i5 < 4; c9_i5++) {
    (*(real_T (*)[4])c9_outData)[c9_i5] = c9_y[c9_i5];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray
  *sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[7];
  c9_ResolvedFunctionInfo (*c9_b_info)[7];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i6;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_b_info = (c9_ResolvedFunctionInfo (*)[7])c9_info;
  (*c9_b_info)[0].context = "";
  (*c9_b_info)[0].name = "max";
  (*c9_b_info)[0].dominantType = "double";
  (*c9_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  (*c9_b_info)[0].fileTimeLo = 2181966592U;
  (*c9_b_info)[0].fileTimeHi = 30107998U;
  (*c9_b_info)[0].mFileTimeLo = 0U;
  (*c9_b_info)[0].mFileTimeHi = 0U;
  (*c9_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  (*c9_b_info)[1].name = "eml_min_or_max";
  (*c9_b_info)[1].dominantType = "char";
  (*c9_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c9_b_info)[1].fileTimeLo = 3121966592U;
  (*c9_b_info)[1].fileTimeHi = 30107998U;
  (*c9_b_info)[1].mFileTimeLo = 0U;
  (*c9_b_info)[1].mFileTimeHi = 0U;
  (*c9_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c9_b_info)[2].name = "eml_const_nonsingleton_dim";
  (*c9_b_info)[2].dominantType = "double";
  (*c9_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  (*c9_b_info)[2].fileTimeLo = 2201966592U;
  (*c9_b_info)[2].fileTimeHi = 30107998U;
  (*c9_b_info)[2].mFileTimeLo = 0U;
  (*c9_b_info)[2].mFileTimeHi = 0U;
  (*c9_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c9_b_info)[3].name = "eml_scalar_eg";
  (*c9_b_info)[3].dominantType = "double";
  (*c9_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c9_b_info)[3].fileTimeLo = 3201966592U;
  (*c9_b_info)[3].fileTimeHi = 30107998U;
  (*c9_b_info)[3].mFileTimeLo = 0U;
  (*c9_b_info)[3].mFileTimeHi = 0U;
  (*c9_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c9_b_info)[4].name = "eml_index_class";
  (*c9_b_info)[4].dominantType = "";
  (*c9_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c9_b_info)[4].fileTimeLo = 3021966592U;
  (*c9_b_info)[4].fileTimeHi = 30107998U;
  (*c9_b_info)[4].mFileTimeLo = 0U;
  (*c9_b_info)[4].mFileTimeHi = 0U;
  (*c9_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c9_b_info)[5].name = "isnan";
  (*c9_b_info)[5].dominantType = "double";
  (*c9_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  (*c9_b_info)[5].fileTimeLo = 2841966592U;
  (*c9_b_info)[5].fileTimeHi = 30107998U;
  (*c9_b_info)[5].mFileTimeLo = 0U;
  (*c9_b_info)[5].mFileTimeHi = 0U;
  (*c9_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c9_b_info)[6].name = "eml_index_plus";
  (*c9_b_info)[6].dominantType = "int32";
  (*c9_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c9_b_info)[6].fileTimeLo = 3021966592U;
  (*c9_b_info)[6].fileTimeHi = 30107998U;
  (*c9_b_info)[6].mFileTimeLo = 0U;
  (*c9_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7));
  for (c9_i6 = 0; c9_i6 < 7; c9_i6++) {
    c9_r0 = &c9_info[c9_i6];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i6);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static int32_T c9_d_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i7;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i7, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i7;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_e_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_b_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK,
   const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info
  (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4112668894U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1983564271U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1071903448U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3342898700U);
}

mxArray *sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2969713751U);
    pr[1] = (double)(2973952313U);
    pr[2] = (double)(3689342912U);
    pr[3] = (double)(2979773432U);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray
  *sf_get_sim_state_info_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"y1\",},{M[1],M[9],T\"y2\",},{M[1],M[10],T\"y3\",},{M[1],M[11],T\"y4\",},{M[8],M[0],T\"is_active_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
    chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKMachineNumber_,
           9,
           1,
           1,
           8,
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
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"u4");
          _SFD_SET_DATA_PROPS(5,2,0,1,"y2");
          _SFD_SET_DATA_PROPS(6,2,0,1,"y3");
          _SFD_SET_DATA_PROPS(7,2,0,1,"y4");
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,330);
        _SFD_CV_INIT_EML_IF(0,0,77,91,140,330);
        _SFD_CV_INIT_EML_IF(0,1,140,158,207,330);
        _SFD_CV_INIT_EML_IF(0,2,207,225,274,330);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          real_T *c9_u1;
          real_T *c9_y1;
          real_T *c9_u2;
          real_T *c9_u3;
          real_T *c9_u4;
          real_T *c9_y2;
          real_T *c9_y3;
          real_T *c9_y4;
          c9_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c9_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_u4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_y1);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_u2);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_u3);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_u4);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_y2);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_y3);
          _SFD_SET_DATA_VALUE_PTR(7U, c9_y4);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInstanceVar);
  initialize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(void
  *chartInstanceVar)
{
  enable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(void
  *chartInstanceVar)
{
  disable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(void
  *chartInstanceVar)
{
  sf_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK();/* state var info */
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

extern void sf_internal_set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
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
    sf_get_sim_state_info_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(S);
}

static void sf_opaque_set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(S, st);
}

static void sf_opaque_terminate_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(void *
  chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
      ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
    ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
      ((SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,
                "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
                "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9,4);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9,4);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
                          "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3431246522U));
  ssSetChecksum1(S,(1510142428U));
  ssSetChecksum2(S,(3481427287U));
  ssSetChecksum3(S,(74981060U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(SimStruct *S)
{
  SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct *)
    malloc(sizeof(SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OKInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK;
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

void c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
