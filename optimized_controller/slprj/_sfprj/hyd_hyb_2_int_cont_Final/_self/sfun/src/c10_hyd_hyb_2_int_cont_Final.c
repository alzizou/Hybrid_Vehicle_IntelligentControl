/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hyd_hyb_2_int_cont_Final_sfun.h"
#include "c10_hyd_hyb_2_int_cont_Final.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_Final_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[5] = { "nargin", "nargout", "T", "w",
  "y" };

/* Function Declarations */
static void initialize_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void initialize_params_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void enable_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void disable_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void set_sim_state_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_st);
static void finalize_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void sf_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void initSimStructsc10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c10_y, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(uint32_T c10_u);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_c_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_d_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_b_is_active_c10_hyd_hyb_2_int_cont_Final, const char_T *c10_identifier);
static uint8_T c10_e_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_hyd_hyb_2_int_cont_Final = 0U;
}

static void initialize_params_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void enable_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T *c10_d_y;
  c10_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2), FALSE);
  c10_hoistedGlobal = *c10_d_y;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal =
    chartInstance->c10_is_active_c10_hyd_hyb_2_int_cont_Final;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_y;
  c10_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  *c10_y = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    0)), "y");
  chartInstance->c10_is_active_c10_hyd_hyb_2_int_cont_Final =
    c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "is_active_c10_hyd_hyb_2_int_cont_Final");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_hyd_hyb_2_int_cont_Final(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void sf_c10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_T;
  real_T c10_w;
  uint32_T c10_debug_family_var_map[5];
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  real_T c10_y;
  real_T c10_a;
  real_T c10_b;
  real_T c10_b_y;
  real_T c10_A;
  real_T c10_x;
  real_T c10_b_x;
  real_T *c10_b_w;
  real_T *c10_b_T;
  real_T *c10_c_y;
  c10_b_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_b_T, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_c_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_b_w, 2U);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_T;
  c10_b_hoistedGlobal = *c10_b_w;
  c10_T = c10_hoistedGlobal;
  c10_w = c10_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_T, 2U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_w, 3U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_y, 4U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c10_T > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
    c10_a = c10_T;
    c10_b = c10_w;
    c10_b_y = c10_a * c10_b;
    c10_A = c10_b_y;
    c10_x = c10_A;
    c10_b_x = c10_x;
    c10_y = c10_b_x / 1000.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
    c10_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *c10_c_y = c10_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hyd_hyb_2_int_cont_FinalMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc10_hyd_hyb_2_int_cont_Final
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *
  chartInstance, const mxArray *c10_y, const char_T *c10_identifier)
{
  real_T c10_b_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_y), &c10_thisId);
  sf_mex_destroy(&c10_y);
  return c10_b_y;
}

static real_T c10_b_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_y;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_b_y;
  SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c10_y = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_y), &c10_thisId);
  sf_mex_destroy(&c10_y);
  *(real_T *)c10_outData = c10_b_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_hyd_hyb_2_int_cont_Final_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                FALSE);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363704878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mrdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1373297508U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1319724566U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363704880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363704866U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
}

static const mxArray *c10_emlrt_marshallOut(char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), FALSE);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c10_y;
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_c_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i0, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_d_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_b_is_active_c10_hyd_hyb_2_int_cont_Final, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_hyd_hyb_2_int_cont_Final), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_hyd_hyb_2_int_cont_Final);
  return c10_y;
}

static uint8_T c10_e_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct
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

void sf_c10_hyd_hyb_2_int_cont_Final_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3337059176U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2725603719U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1675792784U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1018839210U);
}

mxArray *sf_c10_hyd_hyb_2_int_cont_Final_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("siw4DsXgW1V4NbRS8nWXTE");
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

mxArray *sf_c10_hyd_hyb_2_int_cont_Final_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_hyd_hyb_2_int_cont_Final_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_Final(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c10_hyd_hyb_2_int_cont_Final\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_hyd_hyb_2_int_cont_Final_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
    chartInstance = (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hyd_hyb_2_int_cont_FinalMachineNumber_,
           10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"T");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"w");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,66);
        _SFD_CV_INIT_EML_IF(0,1,0,22,28,45,62);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c10_T;
          real_T *c10_y;
          real_T *c10_w;
          c10_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c10_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_T);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_w);
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
  return "X05mGzqYycSwV69nqcWEH";
}

static void sf_opaque_initialize_c10_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
  initialize_c10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_hyd_hyb_2_int_cont_Final(void *chartInstanceVar)
{
  enable_c10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  disable_c10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  sf_c10_hyd_hyb_2_int_cont_Final((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_hyd_hyb_2_int_cont_Final
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_Final();/* state var info */
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

extern void sf_internal_set_sim_state_c10_hyd_hyb_2_int_cont_Final(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_Final();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_hyd_hyb_2_int_cont_Final
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c10_hyd_hyb_2_int_cont_Final(S);
}

static void sf_opaque_set_sim_state_c10_hyd_hyb_2_int_cont_Final(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c10_hyd_hyb_2_int_cont_Final(S, st);
}

static void sf_opaque_terminate_c10_hyd_hyb_2_int_cont_Final(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hyd_hyb_2_int_cont_Final_optimization_info();
    }

    finalize_c10_hyd_hyb_2_int_cont_Final
      ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_hyd_hyb_2_int_cont_Final
    ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_hyd_hyb_2_int_cont_Final
      ((SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hyd_hyb_2_int_cont_Final_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3996419086U));
  ssSetChecksum1(S,(2537089148U));
  ssSetChecksum2(S,(2463073974U));
  ssSetChecksum3(S,(1239876579U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_hyd_hyb_2_int_cont_Final(SimStruct *S)
{
  SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct *)utMalloc
    (sizeof(SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_hyd_hyb_2_int_cont_FinalInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_hyd_hyb_2_int_cont_Final;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_hyd_hyb_2_int_cont_Final;
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

void c10_hyd_hyb_2_int_cont_Final_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_hyd_hyb_2_int_cont_Final(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_hyd_hyb_2_int_cont_Final(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_hyd_hyb_2_int_cont_Final(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_hyd_hyb_2_int_cont_Final_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
