/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_opt_cont_2_sfun.h"
#include "c9_hyd_hyb_2_opt_cont_2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_opt_cont_2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[7] = { "nargin", "nargout", "T_pm",
  "T_brk", "T_dem", "T_eng", "T_mech_brk" };

/* Function Declarations */
static void initialize_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void initialize_params_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void enable_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void disable_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void set_sim_state_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void sf_c9_hyd_hyb_2_opt_cont_2(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance);
static void initSimStructsc9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_T_mech_brk, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_eml_scalar_eg(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_hyd_hyb_2_opt_cont_2, const
  char_T *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_hyd_hyb_2_opt_cont_2 = 0U;
}

static void initialize_params_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
}

static void enable_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  uint8_T c9_c_hoistedGlobal;
  uint8_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T *c9_T_eng;
  real_T *c9_T_mech_brk;
  c9_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(3));
  c9_hoistedGlobal = *c9_T_eng;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_T_mech_brk;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = chartInstance->c9_is_active_c9_hyd_hyb_2_opt_cont_2;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 2, c9_d_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_T_eng;
  real_T *c9_T_mech_brk;
  c9_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_T_eng = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u,
    0)), "T_eng");
  *c9_T_mech_brk = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 1)), "T_mech_brk");
  chartInstance->c9_is_active_c9_hyd_hyb_2_opt_cont_2 = c9_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
     "is_active_c9_hyd_hyb_2_opt_cont_2");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_hyd_hyb_2_opt_cont_2(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
{
}

static void sf_c9_hyd_hyb_2_opt_cont_2(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_T_pm;
  real_T c9_T_brk;
  real_T c9_T_dem;
  uint32_T c9_debug_family_var_map[7];
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 2.0;
  real_T c9_T_eng;
  real_T c9_T_mech_brk;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_y;
  real_T c9_varargin_2;
  real_T c9_b_y;
  real_T c9_c_y;
  real_T c9_yk;
  real_T c9_d_y;
  real_T c9_b_varargin_2;
  real_T c9_e_y;
  real_T c9_f_y;
  real_T c9_b_yk;
  real_T c9_g_y;
  real_T *c9_b_T_pm;
  real_T *c9_b_T_eng;
  real_T *c9_b_T_brk;
  real_T *c9_b_T_mech_brk;
  real_T *c9_b_T_dem;
  c9_b_T_dem = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_T_brk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_T_pm = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_b_T_pm, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_b_T_eng, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_T_brk, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_b_T_mech_brk, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_b_T_dem, 4U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_T_pm;
  c9_b_hoistedGlobal = *c9_b_T_brk;
  c9_c_hoistedGlobal = *c9_b_T_dem;
  c9_T_pm = c9_hoistedGlobal;
  c9_T_brk = c9_b_hoistedGlobal;
  c9_T_dem = c9_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_T_pm, 2U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_T_brk, 3U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_T_dem, 4U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_T_eng, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_T_mech_brk, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 2);
  c9_x = c9_T_brk;
  c9_b_x = c9_x;
  c9_y = muDoubleScalarAbs(c9_b_x);
  if (CV_EML_IF(0, 0, c9_y > 0.1)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
    c9_T_eng = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
    c9_varargin_2 = c9_T_brk - c9_T_pm;
    c9_b_y = c9_varargin_2;
    c9_c_y = c9_b_y;
    c9_eml_scalar_eg(chartInstance);
    c9_yk = c9_c_y;
    c9_d_y = c9_yk;
    c9_eml_scalar_eg(chartInstance);
    c9_T_mech_brk = muDoubleScalarMin(0.0, c9_d_y);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
    c9_T_mech_brk = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
    c9_b_varargin_2 = c9_T_dem - c9_T_pm;
    c9_e_y = c9_b_varargin_2;
    c9_f_y = c9_e_y;
    c9_eml_scalar_eg(chartInstance);
    c9_b_yk = c9_f_y;
    c9_g_y = c9_b_yk;
    c9_eml_scalar_eg(chartInstance);
    c9_T_eng = muDoubleScalarMax(0.0, c9_g_y);
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  *c9_b_T_eng = c9_T_eng;
  *c9_b_T_mech_brk = c9_T_mech_brk;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  sf_debug_check_for_state_inconsistency(_hyd_hyb_2_opt_cont_2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_hyd_hyb_2_opt_cont_2
  (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance)
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
  SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_T_mech_brk, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_T_mech_brk),
    &c9_thisId);
  sf_mex_destroy(&c9_T_mech_brk);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
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
  const mxArray *c9_T_mech_brk;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *)chartInstanceVoid;
  c9_T_mech_brk = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_T_mech_brk),
    &c9_thisId);
  sf_mex_destroy(&c9_T_mech_brk);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_hyd_hyb_2_opt_cont_2_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[8];
  c9_ResolvedFunctionInfo (*c9_b_info)[8];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i0;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_b_info = (c9_ResolvedFunctionInfo (*)[8])c9_info;
  (*c9_b_info)[0].context = "";
  (*c9_b_info)[0].name = "abs";
  (*c9_b_info)[0].dominantType = "double";
  (*c9_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c9_b_info)[0].fileTimeLo = 2181966592U;
  (*c9_b_info)[0].fileTimeHi = 30107998U;
  (*c9_b_info)[0].mFileTimeLo = 0U;
  (*c9_b_info)[0].mFileTimeHi = 0U;
  (*c9_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c9_b_info)[1].name = "eml_scalar_abs";
  (*c9_b_info)[1].dominantType = "double";
  (*c9_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c9_b_info)[1].fileTimeLo = 2361966592U;
  (*c9_b_info)[1].fileTimeHi = 30107998U;
  (*c9_b_info)[1].mFileTimeLo = 0U;
  (*c9_b_info)[1].mFileTimeHi = 0U;
  (*c9_b_info)[2].context = "";
  (*c9_b_info)[2].name = "min";
  (*c9_b_info)[2].dominantType = "double";
  (*c9_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c9_b_info)[2].fileTimeLo = 2201966592U;
  (*c9_b_info)[2].fileTimeHi = 30107998U;
  (*c9_b_info)[2].mFileTimeLo = 0U;
  (*c9_b_info)[2].mFileTimeHi = 0U;
  (*c9_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c9_b_info)[3].name = "eml_min_or_max";
  (*c9_b_info)[3].dominantType = "char";
  (*c9_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c9_b_info)[3].fileTimeLo = 3121966592U;
  (*c9_b_info)[3].fileTimeHi = 30107998U;
  (*c9_b_info)[3].mFileTimeLo = 0U;
  (*c9_b_info)[3].mFileTimeHi = 0U;
  (*c9_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c9_b_info)[4].name = "eml_scalar_eg";
  (*c9_b_info)[4].dominantType = "double";
  (*c9_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c9_b_info)[4].fileTimeLo = 3201966592U;
  (*c9_b_info)[4].fileTimeHi = 30107998U;
  (*c9_b_info)[4].mFileTimeLo = 0U;
  (*c9_b_info)[4].mFileTimeHi = 0U;
  (*c9_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c9_b_info)[5].name = "eml_scalexp_alloc";
  (*c9_b_info)[5].dominantType = "double";
  (*c9_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c9_b_info)[5].fileTimeLo = 3201966592U;
  (*c9_b_info)[5].fileTimeHi = 30107998U;
  (*c9_b_info)[5].mFileTimeLo = 0U;
  (*c9_b_info)[5].mFileTimeHi = 0U;
  (*c9_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c9_b_info)[6].name = "eml_index_class";
  (*c9_b_info)[6].dominantType = "";
  (*c9_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c9_b_info)[6].fileTimeLo = 3021966592U;
  (*c9_b_info)[6].fileTimeHi = 30107998U;
  (*c9_b_info)[6].mFileTimeLo = 0U;
  (*c9_b_info)[6].mFileTimeHi = 0U;
  (*c9_b_info)[7].context = "";
  (*c9_b_info)[7].name = "max";
  (*c9_b_info)[7].dominantType = "double";
  (*c9_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  (*c9_b_info)[7].fileTimeLo = 2181966592U;
  (*c9_b_info)[7].fileTimeHi = 30107998U;
  (*c9_b_info)[7].mFileTimeLo = 0U;
  (*c9_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8));
  for (c9_i0 = 0; c9_i0 < 8; c9_i0++) {
    c9_r0 = &c9_info[c9_i0];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i0);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static void c9_eml_scalar_eg(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance)
{
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i1;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i1, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_hyd_hyb_2_opt_cont_2, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_hyd_hyb_2_opt_cont_2), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_hyd_hyb_2_opt_cont_2);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_hyd_hyb_2_opt_cont_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3976119759U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1304148378U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4267557341U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3819249323U);
}

mxArray *sf_c9_hyd_hyb_2_opt_cont_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2041140989U);
    pr[1] = (double)(4228402920U);
    pr[2] = (double)(195073049U);
    pr[3] = (double)(2734561097U);
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

static const mxArray *sf_get_sim_state_info_c9_hyd_hyb_2_opt_cont_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"T_eng\",},{M[1],M[8],T\"T_mech_brk\",},{M[8],M[0],T\"is_active_c9_hyd_hyb_2_opt_cont_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_hyd_hyb_2_opt_cont_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance;
    chartInstance = (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_opt_cont_2MachineNumber_,
           9,
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
          init_script_number_translation(_hyd_hyb_2_opt_cont_2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_opt_cont_2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_opt_cont_2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"T_pm");
          _SFD_SET_DATA_PROPS(1,2,0,1,"T_eng");
          _SFD_SET_DATA_PROPS(2,1,1,0,"T_brk");
          _SFD_SET_DATA_PROPS(3,2,0,1,"T_mech_brk");
          _SFD_SET_DATA_PROPS(4,1,1,0,"T_dem");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,180);
        _SFD_CV_INIT_EML_IF(0,0,52,69,117,176);
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
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c9_T_pm;
          real_T *c9_T_eng;
          real_T *c9_T_brk;
          real_T *c9_T_mech_brk;
          real_T *c9_T_dem;
          c9_T_dem = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_T_mech_brk = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_T_brk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_T_pm = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_T_pm);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_T_eng);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_T_brk);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_T_mech_brk);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_T_dem);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_opt_cont_2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c9_hyd_hyb_2_opt_cont_2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_hyd_hyb_2_opt_cont_2
    ((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*) chartInstanceVar);
  initialize_c9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_hyd_hyb_2_opt_cont_2(void *chartInstanceVar)
{
  enable_c9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_hyd_hyb_2_opt_cont_2(void *chartInstanceVar)
{
  disable_c9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_hyd_hyb_2_opt_cont_2(void *chartInstanceVar)
{
  sf_c9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_hyd_hyb_2_opt_cont_2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_hyd_hyb_2_opt_cont_2
    ((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_hyd_hyb_2_opt_cont_2();/* state var info */
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

extern void sf_internal_set_sim_state_c9_hyd_hyb_2_opt_cont_2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_hyd_hyb_2_opt_cont_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_hyd_hyb_2_opt_cont_2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_hyd_hyb_2_opt_cont_2(S);
}

static void sf_opaque_set_sim_state_c9_hyd_hyb_2_opt_cont_2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_hyd_hyb_2_opt_cont_2(S, st);
}

static void sf_opaque_terminate_c9_hyd_hyb_2_opt_cont_2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_hyd_hyb_2_opt_cont_2((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_hyd_hyb_2_opt_cont_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_hyd_hyb_2_opt_cont_2
      ((SFc9_hyd_hyb_2_opt_cont_2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_hyd_hyb_2_opt_cont_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_opt_cont_2",
      "hyd_hyb_2_opt_cont_2",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_2",
                "hyd_hyb_2_opt_cont_2",9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_2",
      "hyd_hyb_2_opt_cont_2",9,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_opt_cont_2",
        "hyd_hyb_2_opt_cont_2",9,3);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_opt_cont_2",
        "hyd_hyb_2_opt_cont_2",9,2);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_opt_cont_2","hyd_hyb_2_opt_cont_2",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2599203706U));
  ssSetChecksum1(S,(4270460642U));
  ssSetChecksum2(S,(4185438142U));
  ssSetChecksum3(S,(147830943U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_hyd_hyb_2_opt_cont_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_opt_cont_2", "hyd_hyb_2_opt_cont_2",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_hyd_hyb_2_opt_cont_2(SimStruct *S)
{
  SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *chartInstance;
  chartInstance = (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct *)malloc(sizeof
    (SFc9_hyd_hyb_2_opt_cont_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_hyd_hyb_2_opt_cont_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_hyd_hyb_2_opt_cont_2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_hyd_hyb_2_opt_cont_2;
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

void c9_hyd_hyb_2_opt_cont_2_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_hyd_hyb_2_opt_cont_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_hyd_hyb_2_opt_cont_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_hyd_hyb_2_opt_cont_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_hyd_hyb_2_opt_cont_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
