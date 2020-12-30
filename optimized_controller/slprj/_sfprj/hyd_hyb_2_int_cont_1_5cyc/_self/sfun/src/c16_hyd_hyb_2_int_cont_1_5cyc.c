/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hyd_hyb_2_int_cont_1_5cyc_sfun.h"
#include "c16_hyd_hyb_2_int_cont_1_5cyc.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_5cyc_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c16_debug_family_names[6] = { "r", "nargin", "nargout", "u",
  "T0", "y" };

/* Function Declarations */
static void initialize_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void initialize_params_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void enable_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void disable_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_st);
static void finalize_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void sf_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void initSimStructsc16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_emlrt_marshallIn(SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct
  *chartInstance, const mxArray *c16_y, const char_T *c16_identifier);
static real_T c16_b_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(uint32_T c16_u);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_c_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_d_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_b_is_active_c16_hyd_hyb_2_int_cont_1_5cyc, const char_T *c16_identifier);
static uint8_T c16_e_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_hyd_hyb_2_int_cont_1_5cyc = 0U;
}

static void initialize_params_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
  real_T c16_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'T0' in the parent workspace.\n");
  sf_mex_import_named("T0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c16_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_T0 = c16_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_hoistedGlobal;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  uint8_T c16_b_hoistedGlobal;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T *c16_d_y;
  c16_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(2), FALSE);
  c16_hoistedGlobal = *c16_d_y;
  c16_u = c16_hoistedGlobal;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_hoistedGlobal =
    chartInstance->c16_is_active_c16_hyd_hyb_2_int_cont_1_5cyc;
  c16_b_u = c16_b_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y, FALSE);
  return c16_st;
}

static void set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_st)
{
  const mxArray *c16_u;
  real_T *c16_y;
  c16_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  *c16_y = c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u,
    0)), "y");
  chartInstance->c16_is_active_c16_hyd_hyb_2_int_cont_1_5cyc =
    c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
    "is_active_c16_hyd_hyb_2_int_cont_1_5cyc");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_hyd_hyb_2_int_cont_1_5cyc(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
}

static void sf_c16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
  real_T c16_hoistedGlobal;
  real_T c16_b_hoistedGlobal;
  real_T c16_u;
  real_T c16_b_T0;
  uint32_T c16_debug_family_var_map[6];
  real_T c16_r;
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  real_T c16_y;
  real_T c16_x;
  real_T c16_b_y;
  real_T c16_xk;
  real_T c16_yk;
  real_T *c16_b_u;
  real_T *c16_c_y;
  c16_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c16_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c16_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c16_c_y, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_T0, 2U);
  chartInstance->c16_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *c16_b_u;
  c16_b_hoistedGlobal = chartInstance->c16_T0;
  c16_u = c16_hoistedGlobal;
  c16_b_T0 = c16_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_r, 0U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 1U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 2U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u, 3U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_T0, 4U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_y, 5U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 2);
  c16_x = c16_u;
  c16_b_y = c16_b_T0;
  c16_xk = c16_x;
  c16_yk = c16_b_y;
  c16_r = muDoubleScalarRem(c16_xk, c16_yk);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c16_r < 0.01)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 4);
    c16_y = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 6);
    c16_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *c16_c_y = c16_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c16_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hyd_hyb_2_int_cont_1_5cycMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc16_hyd_hyb_2_int_cont_1_5cyc
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static real_T c16_emlrt_marshallIn(SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct
  *chartInstance, const mxArray *c16_y, const char_T *c16_identifier)
{
  real_T c16_b_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId);
  sf_mex_destroy(&c16_y);
  return c16_b_y;
}

static real_T c16_b_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d1;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d1, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d1;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_y;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_b_y;
  SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *)
    chartInstanceVoid;
  c16_y = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId);
  sf_mex_destroy(&c16_y);
  *(real_T *)c16_outData = c16_b_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                FALSE);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("rem"), "name", "name", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363704854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363705556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286813396U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1358177140U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
}

static const mxArray *c16_emlrt_marshallOut(char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), FALSE);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c16_y;
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static int32_T c16_c_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i0, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *)
    chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_d_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_b_is_active_c16_hyd_hyb_2_int_cont_1_5cyc, const char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_hyd_hyb_2_int_cont_1_5cyc), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_hyd_hyb_2_int_cont_1_5cyc);
  return c16_y;
}

static uint8_T c16_e_emlrt_marshallIn
  (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *
  chartInstance)
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

void sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1185943468U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2256739507U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2814832043U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(211659669U);
}

mxArray *sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("t5uo7mXgY4tXHNCOdt5sME");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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

mxArray *sf_c16_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c16_hyd_hyb_2_int_cont_1_5cyc(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c16_hyd_hyb_2_int_cont_1_5cyc\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance;
    chartInstance = (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hyd_hyb_2_int_cont_1_5cycMachineNumber_,
           16,
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
          init_script_number_translation
            (_hyd_hyb_2_int_cont_1_5cycMachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _hyd_hyb_2_int_cont_1_5cycMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _hyd_hyb_2_int_cont_1_5cycMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,10,0,0,"T0");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,77);
        _SFD_CV_INIT_EML_IF(0,1,0,37,46,56,73);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);

        {
          real_T *c16_u;
          real_T *c16_y;
          c16_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c16_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c16_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c16_y);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c16_T0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _hyd_hyb_2_int_cont_1_5cycMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "KpEfpIZ5TEYtb97ZNT0aN";
}

static void sf_opaque_initialize_c16_hyd_hyb_2_int_cont_1_5cyc(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
  initialize_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_hyd_hyb_2_int_cont_1_5cyc(void
  *chartInstanceVar)
{
  enable_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_hyd_hyb_2_int_cont_1_5cyc(void
  *chartInstanceVar)
{
  disable_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_hyd_hyb_2_int_cont_1_5cyc(void
  *chartInstanceVar)
{
  sf_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_hyd_hyb_2_int_cont_1_5cyc();/* state var info */
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

extern void sf_internal_set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_hyd_hyb_2_int_cont_1_5cyc();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc(S);
}

static void sf_opaque_set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc(S, st);
}

static void sf_opaque_terminate_c16_hyd_hyb_2_int_cont_1_5cyc(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hyd_hyb_2_int_cont_1_5cyc_optimization_info();
    }

    finalize_c16_hyd_hyb_2_int_cont_1_5cyc
      ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_hyd_hyb_2_int_cont_1_5cyc
    ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_hyd_hyb_2_int_cont_1_5cyc(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_hyd_hyb_2_int_cont_1_5cyc
      ((SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_hyd_hyb_2_int_cont_1_5cyc(SimStruct *S)
{
  /* Actual parameters from chart:
     T0
   */
  const char_T *rtParamNames[] = { "T0" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hyd_hyb_2_int_cont_1_5cyc_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,16,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4293136471U));
  ssSetChecksum1(S,(4052414824U));
  ssSetChecksum2(S,(478411928U));
  ssSetChecksum3(S,(2514550953U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_hyd_hyb_2_int_cont_1_5cyc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_hyd_hyb_2_int_cont_1_5cyc(SimStruct *S)
{
  SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct *)utMalloc
    (sizeof(SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_hyd_hyb_2_int_cont_1_5cycInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_hyd_hyb_2_int_cont_1_5cyc;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_hyd_hyb_2_int_cont_1_5cyc;
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

void c16_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_hyd_hyb_2_int_cont_1_5cyc(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_hyd_hyb_2_int_cont_1_5cyc(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_hyd_hyb_2_int_cont_1_5cyc(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
