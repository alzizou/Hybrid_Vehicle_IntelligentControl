/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_opt_cont_test_new_sfun.h"
#include "c24_hyd_hyb_2_opt_cont_test_new.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_opt_cont_test_new_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c24_debug_family_names[7] = { "nargin", "nargout", "T_pm",
  "T_brk", "T_acc", "T_eng", "T_mech_brk" };

/* Function Declarations */
static void initialize_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void initialize_params_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void enable_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void disable_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void set_sim_state_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_st);
static void finalize_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void sf_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void initSimStructsc24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_T_mech_brk, const char_T *c24_identifier);
static real_T c24_b_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_eml_scalar_eg(SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct
  *chartInstance);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_c_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_d_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_b_is_active_c24_hyd_hyb_2_opt_cont_test_new, const char_T
   *c24_identifier);
static uint8_T c24_e_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c24_is_active_c24_hyd_hyb_2_opt_cont_test_new = 0U;
}

static void initialize_params_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static void enable_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c24_update_debugger_state_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  real_T c24_hoistedGlobal;
  real_T c24_u;
  const mxArray *c24_b_y = NULL;
  real_T c24_b_hoistedGlobal;
  real_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  uint8_T c24_c_hoistedGlobal;
  uint8_T c24_c_u;
  const mxArray *c24_d_y = NULL;
  real_T *c24_T_eng;
  real_T *c24_T_mech_brk;
  c24_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellarray(3));
  c24_hoistedGlobal = *c24_T_eng;
  c24_u = c24_hoistedGlobal;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_b_hoistedGlobal = *c24_T_mech_brk;
  c24_b_u = c24_b_hoistedGlobal;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c24_y, 1, c24_c_y);
  c24_c_hoistedGlobal =
    chartInstance->c24_is_active_c24_hyd_hyb_2_opt_cont_test_new;
  c24_c_u = c24_c_hoistedGlobal;
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c24_y, 2, c24_d_y);
  sf_mex_assign(&c24_st, c24_y);
  return c24_st;
}

static void set_sim_state_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_st)
{
  const mxArray *c24_u;
  real_T *c24_T_eng;
  real_T *c24_T_mech_brk;
  c24_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c24_doneDoubleBufferReInit = TRUE;
  c24_u = sf_mex_dup(c24_st);
  *c24_T_eng = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c24_u, 0)), "T_eng");
  *c24_T_mech_brk = c24_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c24_u, 1)), "T_mech_brk");
  chartInstance->c24_is_active_c24_hyd_hyb_2_opt_cont_test_new =
    c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 2)),
    "is_active_c24_hyd_hyb_2_opt_cont_test_new");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_hyd_hyb_2_opt_cont_test_new(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static void sf_c24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  real_T c24_hoistedGlobal;
  real_T c24_b_hoistedGlobal;
  real_T c24_c_hoistedGlobal;
  real_T c24_T_pm;
  real_T c24_T_brk;
  real_T c24_T_acc;
  uint32_T c24_debug_family_var_map[7];
  real_T c24_nargin = 3.0;
  real_T c24_nargout = 2.0;
  real_T c24_T_eng;
  real_T c24_T_mech_brk;
  real_T c24_x;
  real_T c24_b_x;
  real_T c24_y;
  real_T c24_varargin_2;
  real_T c24_b_y;
  real_T c24_c_y;
  real_T c24_yk;
  real_T c24_d_y;
  real_T c24_b_varargin_2;
  real_T c24_e_y;
  real_T c24_f_y;
  real_T c24_b_yk;
  real_T c24_g_y;
  real_T *c24_b_T_pm;
  real_T *c24_b_T_eng;
  real_T *c24_b_T_brk;
  real_T *c24_b_T_acc;
  real_T *c24_b_T_mech_brk;
  c24_b_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_b_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c24_b_T_brk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_T_pm = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 23U, chartInstance->c24_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c24_b_T_pm, 0U);
  _SFD_DATA_RANGE_CHECK(*c24_b_T_eng, 1U);
  _SFD_DATA_RANGE_CHECK(*c24_b_T_brk, 2U);
  _SFD_DATA_RANGE_CHECK(*c24_b_T_acc, 3U);
  _SFD_DATA_RANGE_CHECK(*c24_b_T_mech_brk, 4U);
  chartInstance->c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c24_sfEvent);
  c24_hoistedGlobal = *c24_b_T_pm;
  c24_b_hoistedGlobal = *c24_b_T_brk;
  c24_c_hoistedGlobal = *c24_b_T_acc;
  c24_T_pm = c24_hoistedGlobal;
  c24_T_brk = c24_b_hoistedGlobal;
  c24_T_acc = c24_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c24_debug_family_names,
    c24_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargin, 0U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargout, 1U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c24_T_pm, 2U, c24_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c24_T_brk, 3U, c24_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c24_T_acc, 4U, c24_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c24_T_eng, 5U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_T_mech_brk, 6U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 2);
  c24_x = c24_T_brk;
  c24_b_x = c24_x;
  c24_y = muDoubleScalarAbs(c24_b_x);
  if (CV_EML_IF(0, 0, c24_y > 0.1)) {
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 3);
    c24_T_eng = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 4);
    c24_varargin_2 = c24_T_brk - c24_T_pm;
    c24_b_y = c24_varargin_2;
    c24_c_y = c24_b_y;
    c24_eml_scalar_eg(chartInstance);
    c24_yk = c24_c_y;
    c24_d_y = c24_yk;
    c24_eml_scalar_eg(chartInstance);
    c24_T_mech_brk = muDoubleScalarMin(0.0, c24_d_y);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 6);
    c24_T_mech_brk = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 7);
    c24_b_varargin_2 = c24_T_acc - c24_T_pm;
    c24_e_y = c24_b_varargin_2;
    c24_f_y = c24_e_y;
    c24_eml_scalar_eg(chartInstance);
    c24_b_yk = c24_f_y;
    c24_g_y = c24_b_yk;
    c24_eml_scalar_eg(chartInstance);
    c24_T_eng = muDoubleScalarMax(0.0, c24_g_y);
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  *c24_b_T_eng = c24_T_eng;
  *c24_b_T_mech_brk = c24_T_mech_brk;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c24_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_opt_cont_test_newMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc24_hyd_hyb_2_opt_cont_test_new
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber)
{
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c24_mxArrayOutData, c24_y);
  return c24_mxArrayOutData;
}

static real_T c24_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_T_mech_brk, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_T_mech_brk),
    &c24_thisId);
  sf_mex_destroy(&c24_T_mech_brk);
  return c24_y;
}

static real_T c24_b_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_T_mech_brk;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c24_T_mech_brk = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_T_mech_brk),
    &c24_thisId);
  sf_mex_destroy(&c24_T_mech_brk);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray
  *sf_c24_hyd_hyb_2_opt_cont_test_new_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo;
  c24_ResolvedFunctionInfo c24_info[8];
  c24_ResolvedFunctionInfo (*c24_b_info)[8];
  const mxArray *c24_m0 = NULL;
  int32_T c24_i0;
  c24_ResolvedFunctionInfo *c24_r0;
  c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  c24_b_info = (c24_ResolvedFunctionInfo (*)[8])c24_info;
  (*c24_b_info)[0].context = "";
  (*c24_b_info)[0].name = "abs";
  (*c24_b_info)[0].dominantType = "double";
  (*c24_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c24_b_info)[0].fileTimeLo = 2181966592U;
  (*c24_b_info)[0].fileTimeHi = 30107998U;
  (*c24_b_info)[0].mFileTimeLo = 0U;
  (*c24_b_info)[0].mFileTimeHi = 0U;
  (*c24_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c24_b_info)[1].name = "eml_scalar_abs";
  (*c24_b_info)[1].dominantType = "double";
  (*c24_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c24_b_info)[1].fileTimeLo = 2361966592U;
  (*c24_b_info)[1].fileTimeHi = 30107998U;
  (*c24_b_info)[1].mFileTimeLo = 0U;
  (*c24_b_info)[1].mFileTimeHi = 0U;
  (*c24_b_info)[2].context = "";
  (*c24_b_info)[2].name = "min";
  (*c24_b_info)[2].dominantType = "double";
  (*c24_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c24_b_info)[2].fileTimeLo = 2201966592U;
  (*c24_b_info)[2].fileTimeHi = 30107998U;
  (*c24_b_info)[2].mFileTimeLo = 0U;
  (*c24_b_info)[2].mFileTimeHi = 0U;
  (*c24_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c24_b_info)[3].name = "eml_min_or_max";
  (*c24_b_info)[3].dominantType = "char";
  (*c24_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c24_b_info)[3].fileTimeLo = 3121966592U;
  (*c24_b_info)[3].fileTimeHi = 30107998U;
  (*c24_b_info)[3].mFileTimeLo = 0U;
  (*c24_b_info)[3].mFileTimeHi = 0U;
  (*c24_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c24_b_info)[4].name = "eml_scalar_eg";
  (*c24_b_info)[4].dominantType = "double";
  (*c24_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c24_b_info)[4].fileTimeLo = 3201966592U;
  (*c24_b_info)[4].fileTimeHi = 30107998U;
  (*c24_b_info)[4].mFileTimeLo = 0U;
  (*c24_b_info)[4].mFileTimeHi = 0U;
  (*c24_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c24_b_info)[5].name = "eml_scalexp_alloc";
  (*c24_b_info)[5].dominantType = "double";
  (*c24_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c24_b_info)[5].fileTimeLo = 3201966592U;
  (*c24_b_info)[5].fileTimeHi = 30107998U;
  (*c24_b_info)[5].mFileTimeLo = 0U;
  (*c24_b_info)[5].mFileTimeHi = 0U;
  (*c24_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c24_b_info)[6].name = "eml_index_class";
  (*c24_b_info)[6].dominantType = "";
  (*c24_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c24_b_info)[6].fileTimeLo = 3021966592U;
  (*c24_b_info)[6].fileTimeHi = 30107998U;
  (*c24_b_info)[6].mFileTimeLo = 0U;
  (*c24_b_info)[6].mFileTimeHi = 0U;
  (*c24_b_info)[7].context = "";
  (*c24_b_info)[7].name = "max";
  (*c24_b_info)[7].dominantType = "double";
  (*c24_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  (*c24_b_info)[7].fileTimeLo = 2181966592U;
  (*c24_b_info)[7].fileTimeHi = 30107998U;
  (*c24_b_info)[7].mFileTimeLo = 0U;
  (*c24_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c24_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8));
  for (c24_i0 = 0; c24_i0 < 8; c24_i0++) {
    c24_r0 = &c24_info[c24_i0];
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c24_r0->context)), "context", "nameCaptureInfo",
                    c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c24_r0->name)), "name", "nameCaptureInfo", c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      c24_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c24_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c24_r0->resolved)), "resolved",
                    "nameCaptureInfo", c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      &c24_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c24_i0);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      &c24_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c24_i0);
  }

  sf_mex_assign(&c24_nameCaptureInfo, c24_m0);
  return c24_nameCaptureInfo;
}

static void c24_eml_scalar_eg(SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct
  *chartInstance)
{
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c24_mxArrayOutData, c24_y);
  return c24_mxArrayOutData;
}

static int32_T c24_c_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i1;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i1, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i1;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_d_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_b_is_active_c24_hyd_hyb_2_opt_cont_test_new, const char_T
   *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_hyd_hyb_2_opt_cont_test_new), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_hyd_hyb_2_opt_cont_test_new);
  return c24_y;
}

static uint8_T c24_e_emlrt_marshallIn
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info
  (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c24_hyd_hyb_2_opt_cont_test_new_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(207182453U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3513607978U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(357987769U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(752175325U);
}

mxArray *sf_c24_hyd_hyb_2_opt_cont_test_new_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1148933729U);
    pr[1] = (double)(1932858648U);
    pr[2] = (double)(1236524774U);
    pr[3] = (double)(1500593604U);
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

static const mxArray *sf_get_sim_state_info_c24_hyd_hyb_2_opt_cont_test_new(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"T_eng\",},{M[1],M[8],T\"T_mech_brk\",},{M[8],M[0],T\"is_active_c24_hyd_hyb_2_opt_cont_test_new\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_hyd_hyb_2_opt_cont_test_new_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
    chartInstance = (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_opt_cont_test_newMachineNumber_,
           24,
           1,
           1,
           5,
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
            (_hyd_hyb_2_opt_cont_test_newMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_opt_cont_test_newMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_opt_cont_test_newMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"T_pm");
          _SFD_SET_DATA_PROPS(1,2,0,1,"T_eng");
          _SFD_SET_DATA_PROPS(2,1,1,0,"T_brk");
          _SFD_SET_DATA_PROPS(3,1,1,0,"T_acc");
          _SFD_SET_DATA_PROPS(4,2,0,1,"T_mech_brk");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,176);
        _SFD_CV_INIT_EML_IF(0,0,52,69,117,172);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);

        {
          real_T *c24_T_pm;
          real_T *c24_T_eng;
          real_T *c24_T_brk;
          real_T *c24_T_acc;
          real_T *c24_T_mech_brk;
          c24_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c24_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c24_T_brk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c24_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c24_T_pm = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c24_T_pm);
          _SFD_SET_DATA_VALUE_PTR(1U, c24_T_eng);
          _SFD_SET_DATA_VALUE_PTR(2U, c24_T_brk);
          _SFD_SET_DATA_VALUE_PTR(3U, c24_T_acc);
          _SFD_SET_DATA_VALUE_PTR(4U, c24_T_mech_brk);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_opt_cont_test_newMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c24_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
  initialize_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  enable_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c24_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  disable_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c24_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  sf_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_hyd_hyb_2_opt_cont_test_new
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_hyd_hyb_2_opt_cont_test_new();/* state var info */
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

extern void sf_internal_set_sim_state_c24_hyd_hyb_2_opt_cont_test_new(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_hyd_hyb_2_opt_cont_test_new();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_hyd_hyb_2_opt_cont_test_new
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c24_hyd_hyb_2_opt_cont_test_new(S);
}

static void sf_opaque_set_sim_state_c24_hyd_hyb_2_opt_cont_test_new(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c24_hyd_hyb_2_opt_cont_test_new(S, st);
}

static void sf_opaque_terminate_c24_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c24_hyd_hyb_2_opt_cont_test_new
      ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_hyd_hyb_2_opt_cont_test_new
    ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c24_hyd_hyb_2_opt_cont_test_new
      ((SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_opt_cont_test_new",
      "hyd_hyb_2_opt_cont_test_new",24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_test_new",
                "hyd_hyb_2_opt_cont_test_new",24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_opt_cont_test_new","hyd_hyb_2_opt_cont_test_new",24,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_opt_cont_test_new",
        "hyd_hyb_2_opt_cont_test_new",24,3);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_opt_cont_test_new",
        "hyd_hyb_2_opt_cont_test_new",24,2);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_opt_cont_test_new",
                          "hyd_hyb_2_opt_cont_test_new",24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2028835116U));
  ssSetChecksum1(S,(1700780833U));
  ssSetChecksum2(S,(3735179444U));
  ssSetChecksum3(S,(2366963859U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c24_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_opt_cont_test_new",
      "hyd_hyb_2_opt_cont_test_new",24);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct *)malloc
    (sizeof(SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc24_hyd_hyb_2_opt_cont_test_newInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_hyd_hyb_2_opt_cont_test_new;
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

void c24_hyd_hyb_2_opt_cont_test_new_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_hyd_hyb_2_opt_cont_test_new(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_hyd_hyb_2_opt_cont_test_new(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_hyd_hyb_2_opt_cont_test_new(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_hyd_hyb_2_opt_cont_test_new_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
