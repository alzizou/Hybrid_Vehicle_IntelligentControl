/* Include files */

#include "blascompat32.h"
#include "online_fuzz_clus_sfun.h"
#include "c3_online_fuzz_clus.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "online_fuzz_clus_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[8] = { "k", "num", "i", "nargin",
  "nargout", "t", "acc", "prc_acc_2_4" };

/* Function Declarations */
static void initialize_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initialize_params_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance);
static void enable_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance);
static void disable_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance);
static void set_sim_state_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance);
static void sf_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance);
static void initSimStructsc3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_prc_acc_2_4, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_online_fuzz_clus, const
  char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_online_fuzz_clus = 0U;
}

static void initialize_params_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void enable_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_prc_acc_2_4;
  c3_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2));
  c3_hoistedGlobal = *c3_prc_acc_2_4;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_online_fuzz_clus;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_prc_acc_2_4;
  c3_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_prc_acc_2_4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "prc_acc_2_4");
  chartInstance->c3_is_active_c3_online_fuzz_clus = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_online_fuzz_clus");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_online_fuzz_clus(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

static void sf_c3_online_fuzz_clus(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  real_T c3_hoistedGlobal;
  real_T c3_t;
  int32_T c3_i1;
  real_T c3_acc[1001];
  uint32_T c3_debug_family_var_map[8];
  real_T c3_k;
  real_T c3_num;
  real_T c3_i;
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_prc_acc_2_4;
  real_T c3_a;
  real_T c3_y;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d0;
  real_T c3_b_i;
  real_T c3_A;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T *c3_b_prc_acc_2_4;
  real_T *c3_b_t;
  real_T (*c3_b_acc)[1001];
  boolean_T guard1 = FALSE;
  c3_b_acc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_b_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_prc_acc_2_4, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_t, 1U);
  for (c3_i0 = 0; c3_i0 < 1001; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_acc)[c3_i0], 2U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_t;
  c3_t = c3_hoistedGlobal;
  for (c3_i1 = 0; c3_i1 < 1001; c3_i1++) {
    c3_acc[c3_i1] = (*c3_b_acc)[c3_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_k, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_i, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_t, 5U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_acc, 6U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_prc_acc_2_4, 7U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  c3_a = c3_t;
  c3_y = c3_a * 100.0;
  c3_x = c3_y + 1.0;
  c3_k = c3_x;
  c3_b_x = c3_k;
  c3_k = c3_b_x;
  c3_c_x = c3_k;
  if (muDoubleScalarAbs(c3_c_x) > 4.503599627370496E+15) {
    c3_k = c3_c_x;
  } else if (c3_c_x >= 0.5) {
    c3_k = muDoubleScalarFloor(c3_c_x + 0.5);
  } else if (c3_c_x > -0.5) {
    c3_k = c3_c_x * 0.0;
  } else {
    c3_k = muDoubleScalarCeil(c3_c_x - 0.5);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_num = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  if (CV_EML_IF(0, 0, c3_t > 2.0)) {
    c3_d0 = c3_k - 200.0;
    c3_i = c3_d0;
    c3_b_i = c3_d0;
    while (c3_b_i <= c3_k) {
      c3_i = c3_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
      guard1 = FALSE;
      if (CV_EML_COND(0, 0, c3_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
            _SFD_INTEGER_CHECK("i", c3_i), 1, 1001, 1, 0) - 1] < 0.4)) {
        if (CV_EML_COND(0, 1, c3_acc[_SFD_EML_ARRAY_BOUNDS_CHECK("acc", (int32_T)
              _SFD_INTEGER_CHECK("i", c3_i), 1, 1001, 1, 0) - 1] > 0.2)) {
          CV_EML_MCDC(0, 0, TRUE);
          CV_EML_IF(0, 1, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
          c3_num++;
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

      c3_b_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_A = c3_num;
  c3_d_x = c3_A;
  c3_e_x = c3_d_x;
  c3_f_x = c3_e_x;
  c3_prc_acc_2_4 = c3_f_x / 200.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  *c3_b_prc_acc_2_4 = c3_prc_acc_2_4;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_online_fuzz_clusMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_online_fuzz_clus
  (SFc3_online_fuzz_clusInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc3_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_prc_acc_2_4, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_prc_acc_2_4),
    &c3_thisId);
  sf_mex_destroy(&c3_prc_acc_2_4);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_prc_acc_2_4;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc3_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c3_prc_acc_2_4 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_prc_acc_2_4),
    &c3_thisId);
  sf_mex_destroy(&c3_prc_acc_2_4);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i2;
  real_T c3_b_inData[1001];
  int32_T c3_i3;
  real_T c3_u[1001];
  const mxArray *c3_y = NULL;
  SFc3_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc3_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i2 = 0; c3_i2 < 1001; c3_i2++) {
    c3_b_inData[c3_i2] = (*(real_T (*)[1001])c3_inData)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 1001; c3_i3++) {
    c3_u[c3_i3] = c3_b_inData[c3_i3];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 1001));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_online_fuzz_clus_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[8];
  c3_ResolvedFunctionInfo (*c3_b_info)[8];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i4;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[8])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[0].fileTimeLo = 3767347712U;
  (*c3_b_info)[0].fileTimeHi = 30114278U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context = "";
  (*c3_b_info)[1].name = "round";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c3_b_info)[1].fileTimeLo = 2721966592U;
  (*c3_b_info)[1].fileTimeHi = 30107998U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c3_b_info)[2].name = "eml_scalar_round";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c3_b_info)[2].fileTimeLo = 3127347712U;
  (*c3_b_info)[2].fileTimeHi = 30114278U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c3_b_info)[3].name = "eps";
  (*c3_b_info)[3].dominantType = "char";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c3_b_info)[3].fileTimeLo = 2101966592U;
  (*c3_b_info)[3].fileTimeHi = 30107998U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c3_b_info)[4].name = "eml_is_float_class";
  (*c3_b_info)[4].dominantType = "char";
  (*c3_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c3_b_info)[4].fileTimeLo = 3061966592U;
  (*c3_b_info)[4].fileTimeHi = 30107998U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c3_b_info)[5].name = "mrdivide";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[5].fileTimeLo = 2311411456U;
  (*c3_b_info)[5].fileTimeHi = 30130914U;
  (*c3_b_info)[5].mFileTimeLo = 3767347712U;
  (*c3_b_info)[5].mFileTimeHi = 30114278U;
  (*c3_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[6].name = "rdivide";
  (*c3_b_info)[6].dominantType = "double";
  (*c3_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[6].fileTimeLo = 3681966592U;
  (*c3_b_info)[6].fileTimeHi = 30107998U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[7].name = "eml_div";
  (*c3_b_info)[7].dominantType = "double";
  (*c3_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c3_b_info)[7].fileTimeLo = 2221966592U;
  (*c3_b_info)[7].fileTimeHi = 30107998U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8));
  for (c3_i4 = 0; c3_i4 < 8; c3_i4++) {
    c3_r0 = &c3_info[c3_i4];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i4);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc3_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i5;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i5, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i5;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc3_online_fuzz_clusInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_online_fuzz_clus, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_online_fuzz_clus), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_online_fuzz_clus);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_online_fuzz_clusInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_online_fuzz_clus_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(451703289U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1532967386U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2939963803U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2824944988U);
}

mxArray *sf_c3_online_fuzz_clus_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3203809847U);
    pr[1] = (double)(3705602860U);
    pr[2] = (double)(339614494U);
    pr[3] = (double)(972007009U);
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

static const mxArray *sf_get_sim_state_info_c3_online_fuzz_clus(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"prc_acc_2_4\",},{M[8],M[0],T\"is_active_c3_online_fuzz_clus\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_online_fuzz_clus_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_online_fuzz_clusInstanceStruct *chartInstance;
    chartInstance = (SFc3_online_fuzz_clusInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_online_fuzz_clusMachineNumber_,
           3,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"prc_acc_2_4");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"acc");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,193);
        _SFD_CV_INIT_EML_IF(0,0,61,67,-1,168);
        _SFD_CV_INIT_EML_IF(0,1,94,121,-1,156);
        _SFD_CV_INIT_EML_FOR(0,0,72,86,164);

        {
          static int condStart[] = { 97, 111 };

          static int condEnd[] = { 107, 121 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,97,121,2,0,&(condStart[0]),&(condEnd[0]),3,
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 1001;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c3_prc_acc_2_4;
          real_T *c3_t;
          real_T (*c3_acc)[1001];
          c3_acc = (real_T (*)[1001])ssGetInputPortSignal(chartInstance->S, 1);
          c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_prc_acc_2_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_prc_acc_2_4);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_t);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_acc);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_online_fuzz_clusMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_online_fuzz_clus(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_online_fuzz_clusInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
  initialize_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_online_fuzz_clus(void *chartInstanceVar)
{
  enable_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_online_fuzz_clus(void *chartInstanceVar)
{
  disable_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_online_fuzz_clus(void *chartInstanceVar)
{
  sf_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_online_fuzz_clus(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_online_fuzz_clus
    ((SFc3_online_fuzz_clusInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_online_fuzz_clus();/* state var info */
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

extern void sf_internal_set_sim_state_c3_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_online_fuzz_clus();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_online_fuzz_clus(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_online_fuzz_clus(S);
}

static void sf_opaque_set_sim_state_c3_online_fuzz_clus(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_online_fuzz_clus(S, st);
}

static void sf_opaque_terminate_c3_online_fuzz_clus(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_online_fuzz_clusInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_online_fuzz_clus(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_online_fuzz_clus((SFc3_online_fuzz_clusInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"online_fuzz_clus","online_fuzz_clus",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus","online_fuzz_clus",3,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"online_fuzz_clus",
      "online_fuzz_clus",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"online_fuzz_clus",
        "online_fuzz_clus",3,2);
      sf_mark_chart_reusable_outputs(S,"online_fuzz_clus","online_fuzz_clus",3,1);
    }

    sf_set_rtw_dwork_info(S,"online_fuzz_clus","online_fuzz_clus",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(301640064U));
  ssSetChecksum1(S,(1308776671U));
  ssSetChecksum2(S,(3198126524U));
  ssSetChecksum3(S,(1022307805U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_online_fuzz_clus(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "online_fuzz_clus", "online_fuzz_clus",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_online_fuzz_clus(SimStruct *S)
{
  SFc3_online_fuzz_clusInstanceStruct *chartInstance;
  chartInstance = (SFc3_online_fuzz_clusInstanceStruct *)malloc(sizeof
    (SFc3_online_fuzz_clusInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_online_fuzz_clusInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_online_fuzz_clus;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_online_fuzz_clus;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_online_fuzz_clus;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_online_fuzz_clus;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_online_fuzz_clus;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_online_fuzz_clus;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_online_fuzz_clus;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_online_fuzz_clus;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_online_fuzz_clus;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_online_fuzz_clus;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_online_fuzz_clus;
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

void c3_online_fuzz_clus_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_online_fuzz_clus(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_online_fuzz_clus(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_online_fuzz_clus_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
