/* Include files */

#include "blascompat32.h"
#include "online_fuzz_clus_sfun.h"
#include "c2_online_fuzz_clus.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "online_fuzz_clus_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "k", "num", "i", "nargin",
  "nargout", "t", "spdacc", "prc_spdacc_0_5" };

/* Function Declarations */
static void initialize_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initialize_params_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance);
static void enable_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance);
static void disable_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance);
static void set_sim_state_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance);
static void sf_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initSimStructsc2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_prc_spdacc_0_5, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_online_fuzz_clus, const
  char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_online_fuzz_clus = 0U;
}

static void initialize_params_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void enable_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_prc_spdacc_0_5;
  c2_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_prc_spdacc_0_5;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_online_fuzz_clus;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_prc_spdacc_0_5;
  c2_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_prc_spdacc_0_5 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "prc_spdacc_0_5");
  chartInstance->c2_is_active_c2_online_fuzz_clus = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_online_fuzz_clus");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_online_fuzz_clus(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

static void sf_c2_online_fuzz_clus(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  int32_T c2_i0;
  real_T c2_hoistedGlobal;
  real_T c2_t;
  int32_T c2_i1;
  real_T c2_spdacc[1001];
  uint32_T c2_debug_family_var_map[8];
  real_T c2_k;
  real_T c2_num;
  real_T c2_i;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_prc_spdacc_0_5;
  real_T c2_a;
  real_T c2_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d0;
  real_T c2_b_i;
  real_T c2_A;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T *c2_b_prc_spdacc_0_5;
  real_T *c2_b_t;
  real_T (*c2_b_spdacc)[1001];
  boolean_T guard1 = FALSE;
  c2_b_spdacc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_prc_spdacc_0_5, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_t, 1U);
  for (c2_i0 = 0; c2_i0 < 1001; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_spdacc)[c2_i0], 2U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_t;
  c2_t = c2_hoistedGlobal;
  for (c2_i1 = 0; c2_i1 < 1001; c2_i1++) {
    c2_spdacc[c2_i1] = (*c2_b_spdacc)[c2_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_k, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_num, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_i, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_t, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_spdacc, 6U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_prc_spdacc_0_5, 7U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  c2_a = c2_t;
  c2_y = c2_a * 100.0;
  c2_x = c2_y + 1.0;
  c2_k = c2_x;
  c2_b_x = c2_k;
  c2_k = c2_b_x;
  c2_c_x = c2_k;
  if (muDoubleScalarAbs(c2_c_x) > 4.503599627370496E+15) {
    c2_k = c2_c_x;
  } else if (c2_c_x >= 0.5) {
    c2_k = muDoubleScalarFloor(c2_c_x + 0.5);
  } else if (c2_c_x > -0.5) {
    c2_k = c2_c_x * 0.0;
  } else {
    c2_k = muDoubleScalarCeil(c2_c_x - 0.5);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_num = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  if (CV_EML_IF(0, 0, c2_t > 2.0)) {
    c2_d0 = c2_k - 200.0;
    c2_i = c2_d0;
    c2_b_i = c2_d0;
    while (c2_b_i <= c2_k) {
      c2_i = c2_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
      guard1 = FALSE;
      if (CV_EML_COND(0, 0, c2_spdacc[_SFD_EML_ARRAY_BOUNDS_CHECK("spdacc",
            (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 1001, 1, 0) - 1] < 5.0))
      {
        if (CV_EML_COND(0, 1, c2_spdacc[_SFD_EML_ARRAY_BOUNDS_CHECK("spdacc",
              (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 1001, 1, 0) - 1] > 0.0))
        {
          CV_EML_MCDC(0, 0, TRUE);
          CV_EML_IF(0, 1, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
          c2_num++;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(0, 0, FALSE);
        CV_EML_IF(0, 1, FALSE);
      }

      c2_b_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_A = c2_num;
  c2_d_x = c2_A;
  c2_e_x = c2_d_x;
  c2_f_x = c2_e_x;
  c2_prc_spdacc_0_5 = c2_f_x / 200.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  *c2_b_prc_spdacc_0_5 = c2_prc_spdacc_0_5;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_online_fuzz_clusMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_online_fuzz_clus
  (SFc2_online_fuzz_clusInstanceStruct *chartInstance)
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
  SFc2_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc2_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_prc_spdacc_0_5, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_prc_spdacc_0_5),
    &c2_thisId);
  sf_mex_destroy(&c2_prc_spdacc_0_5);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_prc_spdacc_0_5;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc2_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c2_prc_spdacc_0_5 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_prc_spdacc_0_5),
    &c2_thisId);
  sf_mex_destroy(&c2_prc_spdacc_0_5);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  real_T c2_b_inData[1001];
  int32_T c2_i3;
  real_T c2_u[1001];
  const mxArray *c2_y = NULL;
  SFc2_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc2_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i2 = 0; c2_i2 < 1001; c2_i2++) {
    c2_b_inData[c2_i2] = (*(real_T (*)[1001])c2_inData)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 1001; c2_i3++) {
    c2_u[c2_i3] = c2_b_inData[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 1001));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_online_fuzz_clus_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[8];
  c2_ResolvedFunctionInfo (*c2_b_info)[8];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i4;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[8])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mtimes";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[0].fileTimeLo = 3767347712U;
  (*c2_b_info)[0].fileTimeHi = 30114278U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "round";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c2_b_info)[1].fileTimeLo = 2721966592U;
  (*c2_b_info)[1].fileTimeHi = 30107998U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c2_b_info)[2].name = "eml_scalar_round";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c2_b_info)[2].fileTimeLo = 3127347712U;
  (*c2_b_info)[2].fileTimeHi = 30114278U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c2_b_info)[3].name = "eps";
  (*c2_b_info)[3].dominantType = "char";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c2_b_info)[3].fileTimeLo = 2101966592U;
  (*c2_b_info)[3].fileTimeHi = 30107998U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c2_b_info)[4].name = "eml_is_float_class";
  (*c2_b_info)[4].dominantType = "char";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c2_b_info)[4].fileTimeLo = 3061966592U;
  (*c2_b_info)[4].fileTimeHi = 30107998U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c2_b_info)[5].name = "mrdivide";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[5].fileTimeLo = 2311411456U;
  (*c2_b_info)[5].fileTimeHi = 30130914U;
  (*c2_b_info)[5].mFileTimeLo = 3767347712U;
  (*c2_b_info)[5].mFileTimeHi = 30114278U;
  (*c2_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[6].name = "rdivide";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[6].fileTimeLo = 3681966592U;
  (*c2_b_info)[6].fileTimeHi = 30107998U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[7].name = "eml_div";
  (*c2_b_info)[7].dominantType = "double";
  (*c2_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[7].fileTimeLo = 2221966592U;
  (*c2_b_info)[7].fileTimeHi = 30107998U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8));
  for (c2_i4 = 0; c2_i4 < 8; c2_i4++) {
    c2_r0 = &c2_info[c2_i4];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i4);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc2_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i5;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i5, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i5;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc2_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_online_fuzz_clus, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_online_fuzz_clus), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_online_fuzz_clus);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_online_fuzz_clus_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2136390048U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3935746960U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2857349368U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1332539934U);
}

mxArray *sf_c2_online_fuzz_clus_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3619654208U);
    pr[1] = (double)(2791720594U);
    pr[2] = (double)(4239403818U);
    pr[3] = (double)(2037179493U);
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

static const mxArray *sf_get_sim_state_info_c2_online_fuzz_clus(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"prc_spdacc_0_5\",},{M[8],M[0],T\"is_active_c2_online_fuzz_clus\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_online_fuzz_clus_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_online_fuzz_clusInstanceStruct *chartInstance;
    chartInstance = (SFc2_online_fuzz_clusInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_online_fuzz_clusMachineNumber_,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"prc_spdacc_0_5");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"spdacc");
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
        _SFD_CV_INIT_EML(0,1,2,0,0,1,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,204);
        _SFD_CV_INIT_EML_IF(0,0,67,73,-1,176);
        _SFD_CV_INIT_EML_IF(0,1,100,129,-1,164);
        _SFD_CV_INIT_EML_FOR(0,0,78,92,172);

        {
          static int condStart[] = { 103, 118 };

          static int condEnd[] = { 114, 129 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,103,129,2,0,&(condStart[0]),&(condEnd[0]),3,
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
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 1001;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c2_prc_spdacc_0_5;
          real_T *c2_t;
          real_T (*c2_spdacc)[1001];
          c2_spdacc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 1);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_prc_spdacc_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_prc_spdacc_0_5);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_spdacc);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_online_fuzz_clusMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_online_fuzz_clus(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_online_fuzz_clusInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
  initialize_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_online_fuzz_clus(void *chartInstanceVar)
{
  enable_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_online_fuzz_clus(void *chartInstanceVar)
{
  disable_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_online_fuzz_clus(void *chartInstanceVar)
{
  sf_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_online_fuzz_clus(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_online_fuzz_clus
    ((SFc2_online_fuzz_clusInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_online_fuzz_clus();/* state var info */
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

extern void sf_internal_set_sim_state_c2_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_online_fuzz_clus();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_online_fuzz_clus(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_online_fuzz_clus(S);
}

static void sf_opaque_set_sim_state_c2_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_online_fuzz_clus(S, st);
}

static void sf_opaque_terminate_c2_online_fuzz_clus(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_online_fuzz_clusInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_online_fuzz_clus(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_online_fuzz_clus((SFc2_online_fuzz_clusInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"online_fuzz_clus","online_fuzz_clus",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus","online_fuzz_clus",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus",
      "online_fuzz_clus",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"online_fuzz_clus",
        "online_fuzz_clus",2,2);
      sf_mark_chart_reusable_outputs(S,"online_fuzz_clus","online_fuzz_clus",2,1);
    }

    sf_set_rtw_dwork_info(S,"online_fuzz_clus","online_fuzz_clus",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4203801610U));
  ssSetChecksum1(S,(1180156781U));
  ssSetChecksum2(S,(3034766883U));
  ssSetChecksum3(S,(2407472954U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "online_fuzz_clus", "online_fuzz_clus",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_online_fuzz_clus(SimStruct *S)
{
  SFc2_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc2_online_fuzz_clusInstanceStruct *)malloc(sizeof
    (SFc2_online_fuzz_clusInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_online_fuzz_clusInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_online_fuzz_clus;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_online_fuzz_clus;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_online_fuzz_clus;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_online_fuzz_clus;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_online_fuzz_clus;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_online_fuzz_clus;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_online_fuzz_clus;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_online_fuzz_clus;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_online_fuzz_clus;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_online_fuzz_clus;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_online_fuzz_clus;
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

void c2_online_fuzz_clus_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_online_fuzz_clus(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_online_fuzz_clus_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
