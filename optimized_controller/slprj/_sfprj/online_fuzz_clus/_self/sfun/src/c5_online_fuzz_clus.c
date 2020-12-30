/* Include files */

#include "blascompat32.h"
#include "online_fuzz_clus_sfun.h"
#include "c5_online_fuzz_clus.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "online_fuzz_clus_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[10] = { "k", "sum", "dist", "i",
  "nargin", "nargout", "t", "acc", "spd", "PKE" };

/* Function Declarations */
static void initialize_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initialize_params_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance);
static void enable_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance);
static void disable_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance);
static void set_sim_state_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance);
static void sf_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initSimStructsc5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_PKE, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[14]);
static real_T c5_mpower(SFc5_online_fuzz_clusInstanceStruct *chartInstance,
  real_T c5_a);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_online_fuzz_clus, const
  char_T *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_online_fuzz_clus = 0U;
}

static void initialize_params_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void enable_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_PKE;
  c5_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2));
  c5_hoistedGlobal = *c5_PKE;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_online_fuzz_clus;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_PKE;
  c5_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_PKE = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "PKE");
  chartInstance->c5_is_active_c5_online_fuzz_clus = c5_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_online_fuzz_clus");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_online_fuzz_clus(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

static void sf_c5_online_fuzz_clus(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  int32_T c5_i0;
  int32_T c5_i1;
  real_T c5_hoistedGlobal;
  real_T c5_t;
  int32_T c5_i2;
  real_T c5_acc[1001];
  int32_T c5_i3;
  real_T c5_spd[1001];
  uint32_T c5_debug_family_var_map[10];
  real_T c5_k;
  real_T c5_sum;
  real_T c5_dist;
  real_T c5_i;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_PKE;
  real_T c5_a;
  real_T c5_y;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d0;
  real_T c5_b_i;
  real_T c5_b;
  real_T c5_b_y;
  real_T c5_A;
  real_T c5_B;
  real_T c5_d_x;
  real_T c5_c_y;
  real_T c5_e_x;
  real_T c5_d_y;
  real_T c5_f_x;
  real_T c5_e_y;
  real_T *c5_b_PKE;
  real_T *c5_b_t;
  real_T (*c5_b_spd)[1001];
  real_T (*c5_b_acc)[1001];
  c5_b_spd = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_acc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_PKE, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_t, 1U);
  for (c5_i0 = 0; c5_i0 < 1001; c5_i0++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_acc)[c5_i0], 2U);
  }

  for (c5_i1 = 0; c5_i1 < 1001; c5_i1++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_spd)[c5_i1], 3U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_t;
  c5_t = c5_hoistedGlobal;
  for (c5_i2 = 0; c5_i2 < 1001; c5_i2++) {
    c5_acc[c5_i2] = (*c5_b_acc)[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 1001; c5_i3++) {
    c5_spd[c5_i3] = (*c5_b_spd)[c5_i3];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_k, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_sum, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_dist, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_i, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_t, 6U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_acc, 7U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_spd, 8U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_PKE, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 2);
  c5_a = c5_t;
  c5_y = c5_a * 100.0;
  c5_x = c5_y + 1.0;
  c5_k = c5_x;
  c5_b_x = c5_k;
  c5_k = c5_b_x;
  c5_c_x = c5_k;
  if (muDoubleScalarAbs(c5_c_x) > 4.503599627370496E+15) {
    c5_k = c5_c_x;
  } else if (c5_c_x >= 0.5) {
    c5_k = muDoubleScalarFloor(c5_c_x + 0.5);
  } else if (c5_c_x > -0.5) {
    c5_k = c5_c_x * 0.0;
  } else {
    c5_k = muDoubleScalarCeil(c5_c_x - 0.5);
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_sum = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_dist = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_PKE = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  if (CV_EML_IF(0, 0, c5_t > 2.0)) {
    c5_d0 = c5_k - 200.0;
    c5_i = c5_d0;
    c5_b_i = c5_d0;
    while (c5_b_i <= c5_k) {
      c5_i = c5_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
      if (CV_EML_IF(0, 1, c5_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
            _SFD_INTEGER_CHECK("i", c5_i), 1, 1001, 1, 0) - 1] > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
        c5_sum += c5_mpower(chartInstance, c5_spd[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "spd", (int32_T)_SFD_INTEGER_CHECK("i", c5_i), 1, 1001, 1, 0) - 1]) -
          c5_mpower(chartInstance, c5_spd[_SFD_EML_ARRAY_BOUNDS_CHECK("spd",
          (int32_T)_SFD_INTEGER_CHECK("i-1", c5_i - 1.0), 1, 1001, 1, 0) - 1]);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
        c5_b = c5_spd[_SFD_EML_ARRAY_BOUNDS_CHECK("spd", (int32_T)
          _SFD_INTEGER_CHECK("i", c5_i), 1, 1001, 1, 0) - 1];
        c5_b_y = 0.01 * c5_b;
        c5_dist += c5_b_y;
      }

      c5_b_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
    c5_A = c5_sum;
    c5_B = c5_dist;
    c5_d_x = c5_A;
    c5_c_y = c5_B;
    c5_e_x = c5_d_x;
    c5_d_y = c5_c_y;
    c5_f_x = c5_e_x;
    c5_e_y = c5_d_y;
    c5_PKE = c5_f_x / c5_e_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  *c5_b_PKE = c5_PKE;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_online_fuzz_clusMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_online_fuzz_clus
  (SFc5_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc5_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_PKE, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_PKE), &c5_thisId);
  sf_mex_destroy(&c5_PKE);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d1;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d1, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_PKE;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc5_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c5_PKE = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_PKE), &c5_thisId);
  sf_mex_destroy(&c5_PKE);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i4;
  real_T c5_b_inData[1001];
  int32_T c5_i5;
  real_T c5_u[1001];
  const mxArray *c5_y = NULL;
  SFc5_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc5_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i4 = 0; c5_i4 < 1001; c5_i4++) {
    c5_b_inData[c5_i4] = (*(real_T (*)[1001])c5_inData)[c5_i4];
  }

  for (c5_i5 = 0; c5_i5 < 1001; c5_i5++) {
    c5_u[c5_i5] = c5_b_inData[c5_i5];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 1001));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_online_fuzz_clus_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[14];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i6;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14));
  for (c5_i6 = 0; c5_i6 < 14; c5_i6++) {
    c5_r0 = &c5_info[c5_i6];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i6);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i6);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[14])
{
  c5_info[0].context = "";
  c5_info[0].name = "mtimes";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[0].fileTimeLo = 3767347712U;
  c5_info[0].fileTimeHi = 30114278U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context = "";
  c5_info[1].name = "round";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c5_info[1].fileTimeLo = 2721966592U;
  c5_info[1].fileTimeHi = 30107998U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c5_info[2].name = "eml_scalar_round";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c5_info[2].fileTimeLo = 3127347712U;
  c5_info[2].fileTimeHi = 30114278U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c5_info[3].name = "eps";
  c5_info[3].dominantType = "char";
  c5_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[3].fileTimeLo = 2101966592U;
  c5_info[3].fileTimeHi = 30107998U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[4].name = "eml_is_float_class";
  c5_info[4].dominantType = "char";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[4].fileTimeLo = 3061966592U;
  c5_info[4].fileTimeHi = 30107998U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c5_info[5].name = "mrdivide";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[5].fileTimeLo = 2311411456U;
  c5_info[5].fileTimeHi = 30130914U;
  c5_info[5].mFileTimeLo = 3767347712U;
  c5_info[5].mFileTimeHi = 30114278U;
  c5_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[6].name = "rdivide";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[6].fileTimeLo = 3681966592U;
  c5_info[6].fileTimeHi = 30107998U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[7].name = "eml_div";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[7].fileTimeLo = 2221966592U;
  c5_info[7].fileTimeHi = 30107998U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context = "";
  c5_info[8].name = "mpower";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[8].fileTimeLo = 3661966592U;
  c5_info[8].fileTimeHi = 30107998U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[9].name = "power";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[9].fileTimeLo = 3681966592U;
  c5_info[9].fileTimeHi = 30107998U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[10].name = "eml_scalar_eg";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[10].fileTimeLo = 3201966592U;
  c5_info[10].fileTimeHi = 30107998U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[11].name = "eml_scalexp_alloc";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[11].fileTimeLo = 3201966592U;
  c5_info[11].fileTimeHi = 30107998U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[12].name = "eml_scalar_floor";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[12].fileTimeLo = 2501966592U;
  c5_info[12].fileTimeHi = 30107998U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[13].name = "eml_error";
  c5_info[13].dominantType = "char";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[13].fileTimeLo = 2241966592U;
  c5_info[13].fileTimeHi = 30107998U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
}

static real_T c5_mpower(SFc5_online_fuzz_clusInstanceStruct *chartInstance,
  real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_ak;
  c5_b_a = c5_a;
  c5_ak = c5_b_a;
  return muDoubleScalarPower(c5_ak, 2.0);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc5_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i7;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i7, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i7;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc5_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_online_fuzz_clus, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_online_fuzz_clus), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_online_fuzz_clus);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_online_fuzz_clus_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3927131128U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2488492087U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2844455539U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2332820421U);
}

mxArray *sf_c5_online_fuzz_clus_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2912109498U);
    pr[1] = (double)(3309834387U);
    pr[2] = (double)(1113679537U);
    pr[3] = (double)(2631838333U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(1001);
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
      pr[0] = (double)(1001);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_online_fuzz_clus(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"PKE\",},{M[8],M[0],T\"is_active_c5_online_fuzz_clus\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_online_fuzz_clus_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_online_fuzz_clusInstanceStruct *chartInstance;
    chartInstance = (SFc5_online_fuzz_clusInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_online_fuzz_clusMachineNumber_,
           5,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"PKE");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"acc");
          _SFD_SET_DATA_PROPS(3,1,1,0,"spd");
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
        _SFD_CV_INIT_EML(0,1,2,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,245);
        _SFD_CV_INIT_EML_IF(0,0,71,77,-1,241);
        _SFD_CV_INIT_EML_IF(0,1,104,115,-1,211);
        _SFD_CV_INIT_EML_FOR(0,0,82,96,219);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 1001;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1001;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c5_PKE;
          real_T *c5_t;
          real_T (*c5_acc)[1001];
          real_T (*c5_spd)[1001];
          c5_spd = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 2);
          c5_acc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 1);
          c5_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_PKE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_PKE);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_t);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_acc);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_spd);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_online_fuzz_clusMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_online_fuzz_clus(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_online_fuzz_clusInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
  initialize_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_online_fuzz_clus(void *chartInstanceVar)
{
  enable_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_online_fuzz_clus(void *chartInstanceVar)
{
  disable_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_online_fuzz_clus(void *chartInstanceVar)
{
  sf_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_online_fuzz_clus(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_online_fuzz_clus
    ((SFc5_online_fuzz_clusInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_online_fuzz_clus();/* state var info */
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

extern void sf_internal_set_sim_state_c5_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_online_fuzz_clus();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_online_fuzz_clus(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_online_fuzz_clus(S);
}

static void sf_opaque_set_sim_state_c5_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_online_fuzz_clus(S, st);
}

static void sf_opaque_terminate_c5_online_fuzz_clus(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_online_fuzz_clusInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_online_fuzz_clus(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_online_fuzz_clus((SFc5_online_fuzz_clusInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"online_fuzz_clus","online_fuzz_clus",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus","online_fuzz_clus",5,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus",
      "online_fuzz_clus",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"online_fuzz_clus",
        "online_fuzz_clus",5,3);
      sf_mark_chart_reusable_outputs(S,"online_fuzz_clus","online_fuzz_clus",5,1);
    }

    sf_set_rtw_dwork_info(S,"online_fuzz_clus","online_fuzz_clus",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3787281584U));
  ssSetChecksum1(S,(4138117736U));
  ssSetChecksum2(S,(1972530131U));
  ssSetChecksum3(S,(3160728917U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "online_fuzz_clus", "online_fuzz_clus",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_online_fuzz_clus(SimStruct *S)
{
  SFc5_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc5_online_fuzz_clusInstanceStruct *)malloc(sizeof
    (SFc5_online_fuzz_clusInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_online_fuzz_clusInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_online_fuzz_clus;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_online_fuzz_clus;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_online_fuzz_clus;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_online_fuzz_clus;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_online_fuzz_clus;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_online_fuzz_clus;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_online_fuzz_clus;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_online_fuzz_clus;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_online_fuzz_clus;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_online_fuzz_clus;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_online_fuzz_clus;
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

void c5_online_fuzz_clus_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_online_fuzz_clus(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_online_fuzz_clus_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
