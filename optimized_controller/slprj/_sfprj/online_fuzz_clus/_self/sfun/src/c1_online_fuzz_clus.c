/* Include files */

#include "blascompat32.h"
#include "online_fuzz_clus_sfun.h"
#include "c1_online_fuzz_clus.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "online_fuzz_clus_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[12] = { "k", "sum_acc", "sum_dec",
  "num_acc", "num_dec", "i", "nargin", "nargout", "acc", "t", "y_avg_acc",
  "y_avg_dec" };

/* Function Declarations */
static void initialize_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initialize_params_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance);
static void enable_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance);
static void disable_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance);
static void set_sim_state_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance);
static void sf_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initSimStructsc1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_y_avg_dec, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_online_fuzz_clus, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_online_fuzz_clus = 0U;
}

static void initialize_params_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void enable_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_y_avg_acc;
  real_T *c1_y_avg_dec;
  c1_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3));
  c1_hoistedGlobal = *c1_y_avg_acc;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_y_avg_dec;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_online_fuzz_clus;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_y_avg_acc;
  real_T *c1_y_avg_dec;
  c1_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_y_avg_acc = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "y_avg_acc");
  *c1_y_avg_dec = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "y_avg_dec");
  chartInstance->c1_is_active_c1_online_fuzz_clus = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_online_fuzz_clus");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_online_fuzz_clus(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

static void sf_c1_online_fuzz_clus(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  real_T c1_hoistedGlobal;
  int32_T c1_i1;
  real_T c1_acc[1001];
  real_T c1_t;
  uint32_T c1_debug_family_var_map[12];
  real_T c1_k;
  real_T c1_sum_acc;
  real_T c1_sum_dec;
  real_T c1_num_acc;
  real_T c1_num_dec;
  real_T c1_i;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 2.0;
  real_T c1_y_avg_acc;
  real_T c1_y_avg_dec;
  real_T c1_a;
  real_T c1_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d0;
  real_T c1_b_i;
  real_T c1_A;
  real_T c1_B;
  real_T c1_d_x;
  real_T c1_b_y;
  real_T c1_e_x;
  real_T c1_c_y;
  real_T c1_f_x;
  real_T c1_d_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_g_x;
  real_T c1_e_y;
  real_T c1_h_x;
  real_T c1_f_y;
  real_T c1_i_x;
  real_T c1_g_y;
  real_T *c1_b_y_avg_acc;
  real_T *c1_b_t;
  real_T *c1_b_y_avg_dec;
  real_T (*c1_b_acc)[1001];
  c1_b_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_acc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_y_avg_acc, 0U);
  for (c1_i0 = 0; c1_i0 < 1001; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_acc)[c1_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_t, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_y_avg_dec, 3U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_t;
  for (c1_i1 = 0; c1_i1 < 1001; c1_i1++) {
    c1_acc[c1_i1] = (*c1_b_acc)[c1_i1];
  }

  c1_t = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_k, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_sum_acc, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_sum_dec, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_num_acc, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_num_dec, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_i, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_acc, 8U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_y_avg_acc, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_y_avg_dec, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_a = c1_t;
  c1_y = c1_a * 100.0;
  c1_x = c1_y + 1.0;
  c1_k = c1_x;
  c1_b_x = c1_k;
  c1_k = c1_b_x;
  c1_c_x = c1_k;
  if (muDoubleScalarAbs(c1_c_x) > 4.503599627370496E+15) {
    c1_k = c1_c_x;
  } else if (c1_c_x >= 0.5) {
    c1_k = muDoubleScalarFloor(c1_c_x + 0.5);
  } else if (c1_c_x > -0.5) {
    c1_k = c1_c_x * 0.0;
  } else {
    c1_k = muDoubleScalarCeil(c1_c_x - 0.5);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_sum_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_sum_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_num_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_num_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_y_avg_acc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_y_avg_dec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  if (CV_EML_IF(0, 0, c1_t > 2.0)) {
    c1_d0 = c1_k - 200.0;
    c1_i = c1_d0;
    c1_b_i = c1_d0;
    while (c1_b_i <= c1_k) {
      c1_i = c1_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
      if (CV_EML_IF(0, 1, c1_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
            _SFD_INTEGER_CHECK("i", c1_i), 1, 1001, 1, 0) - 1] > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
        c1_sum_acc += c1_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 1001, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
        c1_num_acc++;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
      if (CV_EML_IF(0, 2, c1_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
            _SFD_INTEGER_CHECK("i", c1_i), 1, 1001, 1, 0) - 1] < 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
        c1_sum_dec += c1_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 1001, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
        c1_num_dec++;
      }

      c1_b_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    c1_A = c1_sum_acc;
    c1_B = c1_num_acc;
    c1_d_x = c1_A;
    c1_b_y = c1_B;
    c1_e_x = c1_d_x;
    c1_c_y = c1_b_y;
    c1_f_x = c1_e_x;
    c1_d_y = c1_c_y;
    c1_y_avg_acc = c1_f_x / c1_d_y;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_b_A = c1_sum_dec;
    c1_b_B = c1_num_dec;
    c1_g_x = c1_b_A;
    c1_e_y = c1_b_B;
    c1_h_x = c1_g_x;
    c1_f_y = c1_e_y;
    c1_i_x = c1_h_x;
    c1_g_y = c1_f_y;
    c1_y_avg_dec = c1_i_x / c1_g_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -18);
  sf_debug_symbol_scope_pop();
  *c1_b_y_avg_acc = c1_y_avg_acc;
  *c1_b_y_avg_dec = c1_y_avg_dec;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_online_fuzz_clusMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_online_fuzz_clus
  (SFc1_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc1_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_y_avg_dec, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y_avg_dec),
    &c1_thisId);
  sf_mex_destroy(&c1_y_avg_dec);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y_avg_dec;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc1_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c1_y_avg_dec = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y_avg_dec),
    &c1_thisId);
  sf_mex_destroy(&c1_y_avg_dec);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i2;
  real_T c1_b_inData[1001];
  int32_T c1_i3;
  real_T c1_u[1001];
  const mxArray *c1_y = NULL;
  SFc1_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc1_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i2 = 0; c1_i2 < 1001; c1_i2++) {
    c1_b_inData[c1_i2] = (*(real_T (*)[1001])c1_inData)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 1001; c1_i3++) {
    c1_u[c1_i3] = c1_b_inData[c1_i3];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 1001));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_online_fuzz_clus_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[8];
  c1_ResolvedFunctionInfo (*c1_b_info)[8];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i4;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[8])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 3767347712U;
  (*c1_b_info)[0].fileTimeHi = 30114278U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "round";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c1_b_info)[1].fileTimeLo = 2721966592U;
  (*c1_b_info)[1].fileTimeHi = 30107998U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c1_b_info)[2].name = "eml_scalar_round";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c1_b_info)[2].fileTimeLo = 3127347712U;
  (*c1_b_info)[2].fileTimeHi = 30114278U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c1_b_info)[3].name = "eps";
  (*c1_b_info)[3].dominantType = "char";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c1_b_info)[3].fileTimeLo = 2101966592U;
  (*c1_b_info)[3].fileTimeHi = 30107998U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c1_b_info)[4].name = "eml_is_float_class";
  (*c1_b_info)[4].dominantType = "char";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c1_b_info)[4].fileTimeLo = 3061966592U;
  (*c1_b_info)[4].fileTimeHi = 30107998U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c1_b_info)[5].name = "mrdivide";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[5].fileTimeLo = 2311411456U;
  (*c1_b_info)[5].fileTimeHi = 30130914U;
  (*c1_b_info)[5].mFileTimeLo = 3767347712U;
  (*c1_b_info)[5].mFileTimeHi = 30114278U;
  (*c1_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[6].name = "rdivide";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[6].fileTimeLo = 3681966592U;
  (*c1_b_info)[6].fileTimeHi = 30107998U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[7].name = "eml_div";
  (*c1_b_info)[7].dominantType = "double";
  (*c1_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[7].fileTimeLo = 2221966592U;
  (*c1_b_info)[7].fileTimeHi = 30107998U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8));
  for (c1_i4 = 0; c1_i4 < 8; c1_i4++) {
    c1_r0 = &c1_info[c1_i4];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i4);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc1_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i5;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i5, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i5;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc1_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_online_fuzz_clus, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_online_fuzz_clus), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_online_fuzz_clus);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_online_fuzz_clus_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4146779302U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2772998317U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(936497400U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1625835333U);
}

mxArray *sf_c1_online_fuzz_clus_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2504003670U);
    pr[1] = (double)(2461868868U);
    pr[2] = (double)(3560122059U);
    pr[3] = (double)(2465400224U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1001);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_online_fuzz_clus(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"y_avg_acc\",},{M[1],M[8],T\"y_avg_dec\",},{M[8],M[0],T\"is_active_c1_online_fuzz_clus\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_online_fuzz_clus_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_online_fuzz_clusInstanceStruct *chartInstance;
    chartInstance = (SFc1_online_fuzz_clusInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_online_fuzz_clusMachineNumber_,
           1,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"y_avg_acc");
          _SFD_SET_DATA_PROPS(1,1,1,0,"acc");
          _SFD_SET_DATA_PROPS(2,1,1,0,"t");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y_avg_dec");
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
        _SFD_CV_INIT_EML(0,1,3,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,431);
        _SFD_CV_INIT_EML_IF(0,0,131,137,-1,427);
        _SFD_CV_INIT_EML_IF(0,1,164,175,-1,254);
        _SFD_CV_INIT_EML_IF(0,2,263,274,-1,353);
        _SFD_CV_INIT_EML_FOR(0,0,142,156,361);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 1001;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_y_avg_acc;
          real_T *c1_t;
          real_T *c1_y_avg_dec;
          real_T (*c1_acc)[1001];
          c1_y_avg_dec = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_acc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 0);
          c1_y_avg_acc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_y_avg_acc);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_acc);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_y_avg_dec);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_online_fuzz_clusMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_online_fuzz_clus(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_online_fuzz_clusInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
  initialize_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_online_fuzz_clus(void *chartInstanceVar)
{
  enable_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_online_fuzz_clus(void *chartInstanceVar)
{
  disable_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_online_fuzz_clus(void *chartInstanceVar)
{
  sf_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_online_fuzz_clus(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_online_fuzz_clus
    ((SFc1_online_fuzz_clusInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_online_fuzz_clus();/* state var info */
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

extern void sf_internal_set_sim_state_c1_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_online_fuzz_clus();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_online_fuzz_clus(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_online_fuzz_clus(S);
}

static void sf_opaque_set_sim_state_c1_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_online_fuzz_clus(S, st);
}

static void sf_opaque_terminate_c1_online_fuzz_clus(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_online_fuzz_clusInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_online_fuzz_clus(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_online_fuzz_clus((SFc1_online_fuzz_clusInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"online_fuzz_clus","online_fuzz_clus",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus","online_fuzz_clus",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus",
      "online_fuzz_clus",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"online_fuzz_clus",
        "online_fuzz_clus",1,2);
      sf_mark_chart_reusable_outputs(S,"online_fuzz_clus","online_fuzz_clus",1,2);
    }

    sf_set_rtw_dwork_info(S,"online_fuzz_clus","online_fuzz_clus",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1404514740U));
  ssSetChecksum1(S,(3970276296U));
  ssSetChecksum2(S,(2214490074U));
  ssSetChecksum3(S,(3400001890U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "online_fuzz_clus", "online_fuzz_clus",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_online_fuzz_clus(SimStruct *S)
{
  SFc1_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc1_online_fuzz_clusInstanceStruct *)malloc(sizeof
    (SFc1_online_fuzz_clusInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_online_fuzz_clusInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_online_fuzz_clus;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_online_fuzz_clus;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_online_fuzz_clus;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_online_fuzz_clus;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_online_fuzz_clus;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_online_fuzz_clus;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_online_fuzz_clus;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_online_fuzz_clus;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_online_fuzz_clus;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_online_fuzz_clus;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_online_fuzz_clus;
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

void c1_online_fuzz_clus_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_online_fuzz_clus(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_online_fuzz_clus_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
