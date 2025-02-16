/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_opt_cont_test_new_1_sfun.h"
#include "c32_hyd_hyb_2_opt_cont_test_new_1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_opt_cont_test_new_1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c32_debug_family_names[5] = { "nargin", "nargout", "soc",
  "u_0_4", "u_4_5" };

/* Function Declarations */
static void initialize_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void initialize_params_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void enable_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void disable_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void c32_update_debugger_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_st);
static void finalize_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void sf_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void initSimStructsc32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber);
static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static real_T c32_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u_4_5, const char_T *c32_identifier);
static real_T c32_b_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static int32_T c32_c_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static uint8_T c32_d_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_b_is_active_c32_hyd_hyb_2_opt_cont_test_new_1, const char_T
   *c32_identifier);
static uint8_T c32_e_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void init_dsm_address_info
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  chartInstance->c32_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c32_is_active_c32_hyd_hyb_2_opt_cont_test_new_1 = 0U;
}

static void initialize_params_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static void enable_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c32_update_debugger_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  const mxArray *c32_st;
  const mxArray *c32_y = NULL;
  real_T c32_hoistedGlobal;
  real_T c32_u;
  const mxArray *c32_b_y = NULL;
  real_T c32_b_hoistedGlobal;
  real_T c32_b_u;
  const mxArray *c32_c_y = NULL;
  uint8_T c32_c_hoistedGlobal;
  uint8_T c32_c_u;
  const mxArray *c32_d_y = NULL;
  real_T *c32_u_0_4;
  real_T *c32_u_4_5;
  c32_u_4_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c32_u_0_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c32_st = NULL;
  c32_st = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createcellarray(3));
  c32_hoistedGlobal = *c32_u_0_4;
  c32_u = c32_hoistedGlobal;
  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c32_y, 0, c32_b_y);
  c32_b_hoistedGlobal = *c32_u_4_5;
  c32_b_u = c32_b_hoistedGlobal;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c32_y, 1, c32_c_y);
  c32_c_hoistedGlobal =
    chartInstance->c32_is_active_c32_hyd_hyb_2_opt_cont_test_new_1;
  c32_c_u = c32_c_hoistedGlobal;
  c32_d_y = NULL;
  sf_mex_assign(&c32_d_y, sf_mex_create("y", &c32_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c32_y, 2, c32_d_y);
  sf_mex_assign(&c32_st, c32_y);
  return c32_st;
}

static void set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_st)
{
  const mxArray *c32_u;
  real_T *c32_u_0_4;
  real_T *c32_u_4_5;
  c32_u_4_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c32_u_0_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c32_doneDoubleBufferReInit = TRUE;
  c32_u = sf_mex_dup(c32_st);
  *c32_u_0_4 = c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c32_u, 0)), "u_0_4");
  *c32_u_4_5 = c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c32_u, 1)), "u_4_5");
  chartInstance->c32_is_active_c32_hyd_hyb_2_opt_cont_test_new_1 =
    c32_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 2)),
    "is_active_c32_hyd_hyb_2_opt_cont_test_new_1");
  sf_mex_destroy(&c32_u);
  c32_update_debugger_state_c32_hyd_hyb_2_opt_cont_test_new_1(chartInstance);
  sf_mex_destroy(&c32_st);
}

static void finalize_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static void sf_c32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  real_T c32_hoistedGlobal;
  real_T c32_soc;
  uint32_T c32_debug_family_var_map[5];
  real_T c32_nargin = 1.0;
  real_T c32_nargout = 2.0;
  real_T c32_u_0_4;
  real_T c32_u_4_5;
  real_T c32_b;
  real_T c32_b_b;
  real_T *c32_b_soc;
  real_T *c32_b_u_0_4;
  real_T *c32_b_u_4_5;
  c32_b_u_4_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c32_b_u_0_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c32_b_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c32_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c32_b_soc, 0U);
  _SFD_DATA_RANGE_CHECK(*c32_b_u_0_4, 1U);
  _SFD_DATA_RANGE_CHECK(*c32_b_u_4_5, 2U);
  chartInstance->c32_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c32_sfEvent);
  c32_hoistedGlobal = *c32_b_soc;
  c32_soc = c32_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c32_debug_family_names,
    c32_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c32_nargin, 0U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c32_nargout, 1U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c32_soc, 2U, c32_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c32_u_0_4, 3U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c32_u_4_5, 4U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 2);
  if (CV_EML_IF(0, 0, c32_soc < 0.37)) {
    _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 3);
    c32_u_0_4 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 4);
    c32_u_4_5 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 5);
    if (CV_EML_IF(0, 1, c32_soc < 0.42)) {
      _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 6);
      c32_b = c32_soc - 0.42;
      c32_u_0_4 = -20.0 * c32_b;
      _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 7);
      c32_b_b = c32_soc - 0.37;
      c32_u_4_5 = 20.0 * c32_b_b;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 9);
      c32_u_0_4 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 10);
      c32_u_4_5 = 1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c32_b_u_0_4 = c32_u_0_4;
  *c32_b_u_4_5 = c32_u_4_5;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c32_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc32_hyd_hyb_2_opt_cont_test_new_1
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber)
{
}

static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  real_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(real_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c32_mxArrayOutData, c32_y);
  return c32_mxArrayOutData;
}

static real_T c32_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u_4_5, const char_T *c32_identifier)
{
  real_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_u_4_5),
    &c32_thisId);
  sf_mex_destroy(&c32_u_4_5);
  return c32_y;
}

static real_T c32_b_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  real_T c32_y;
  real_T c32_d0;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_d0, 1, 0, 0U, 0, 0U, 0);
  c32_y = c32_d0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_u_4_5;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y;
  SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c32_u_4_5 = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_u_4_5),
    &c32_thisId);
  sf_mex_destroy(&c32_u_4_5);
  *(real_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

const mxArray
  *sf_c32_hyd_hyb_2_opt_cont_test_new_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c32_nameCaptureInfo;
  c32_ResolvedFunctionInfo c32_info[4];
  c32_ResolvedFunctionInfo (*c32_b_info)[4];
  const mxArray *c32_m0 = NULL;
  int32_T c32_i0;
  c32_ResolvedFunctionInfo *c32_r0;
  c32_nameCaptureInfo = NULL;
  c32_nameCaptureInfo = NULL;
  c32_b_info = (c32_ResolvedFunctionInfo (*)[4])c32_info;
  (*c32_b_info)[0].context = "";
  (*c32_b_info)[0].name = "mrdivide";
  (*c32_b_info)[0].dominantType = "double";
  (*c32_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c32_b_info)[0].fileTimeLo = 2311411456U;
  (*c32_b_info)[0].fileTimeHi = 30130914U;
  (*c32_b_info)[0].mFileTimeLo = 3767347712U;
  (*c32_b_info)[0].mFileTimeHi = 30114278U;
  (*c32_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c32_b_info)[1].name = "rdivide";
  (*c32_b_info)[1].dominantType = "double";
  (*c32_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c32_b_info)[1].fileTimeLo = 3681966592U;
  (*c32_b_info)[1].fileTimeHi = 30107998U;
  (*c32_b_info)[1].mFileTimeLo = 0U;
  (*c32_b_info)[1].mFileTimeHi = 0U;
  (*c32_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c32_b_info)[2].name = "eml_div";
  (*c32_b_info)[2].dominantType = "double";
  (*c32_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c32_b_info)[2].fileTimeLo = 2221966592U;
  (*c32_b_info)[2].fileTimeHi = 30107998U;
  (*c32_b_info)[2].mFileTimeLo = 0U;
  (*c32_b_info)[2].mFileTimeHi = 0U;
  (*c32_b_info)[3].context = "";
  (*c32_b_info)[3].name = "mtimes";
  (*c32_b_info)[3].dominantType = "double";
  (*c32_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c32_b_info)[3].fileTimeLo = 3767347712U;
  (*c32_b_info)[3].fileTimeHi = 30114278U;
  (*c32_b_info)[3].mFileTimeLo = 0U;
  (*c32_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c32_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c32_i0 = 0; c32_i0 < 4; c32_i0++) {
    c32_r0 = &c32_info[c32_i0];
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", c32_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c32_r0->context)), "context", "nameCaptureInfo",
                    c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", c32_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c32_r0->name)), "name", "nameCaptureInfo", c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo",
      c32_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c32_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", c32_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c32_r0->resolved)), "resolved",
                    "nameCaptureInfo", c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", &c32_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", &c32_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo",
      &c32_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c32_i0);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo",
      &c32_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c32_i0);
  }

  sf_mex_assign(&c32_nameCaptureInfo, c32_m0);
  return c32_nameCaptureInfo;
}

static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(int32_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c32_mxArrayOutData, c32_y);
  return c32_mxArrayOutData;
}

static int32_T c32_c_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  int32_T c32_y;
  int32_T c32_i1;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_i1, 1, 6, 0U, 0, 0U, 0);
  c32_y = c32_i1;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_sfEvent;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int32_T c32_y;
  SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c32_b_sfEvent = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_sfEvent),
    &c32_thisId);
  sf_mex_destroy(&c32_b_sfEvent);
  *(int32_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static uint8_T c32_d_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_b_is_active_c32_hyd_hyb_2_opt_cont_test_new_1, const char_T
   *c32_identifier)
{
  uint8_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c32_b_is_active_c32_hyd_hyb_2_opt_cont_test_new_1), &c32_thisId);
  sf_mex_destroy(&c32_b_is_active_c32_hyd_hyb_2_opt_cont_test_new_1);
  return c32_y;
}

static uint8_T c32_e_emlrt_marshallIn
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  uint8_T c32_y;
  uint8_T c32_u0;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_u0, 1, 3, 0U, 0, 0U, 0);
  c32_y = c32_u0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void init_dsm_address_info
  (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c32_hyd_hyb_2_opt_cont_test_new_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1541859226U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4073674518U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1434937685U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3481664742U);
}

mxArray *sf_c32_hyd_hyb_2_opt_cont_test_new_1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(753277024U);
    pr[1] = (double)(3994324025U);
    pr[2] = (double)(2093691106U);
    pr[3] = (double)(4169298688U);
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

static const mxArray *sf_get_sim_state_info_c32_hyd_hyb_2_opt_cont_test_new_1
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_0_4\",},{M[1],M[6],T\"u_4_5\",},{M[8],M[0],T\"is_active_c32_hyd_hyb_2_opt_cont_test_new_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c32_hyd_hyb_2_opt_cont_test_new_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
    chartInstance = (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
           32,
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
            (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"soc");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u_0_4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"u_4_5");
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,187);
        _SFD_CV_INIT_EML_IF(0,0,34,45,72,183);
        _SFD_CV_INIT_EML_IF(0,1,72,87,149,183);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)c32_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)c32_sf_marshallIn);

        {
          real_T *c32_soc;
          real_T *c32_u_0_4;
          real_T *c32_u_4_5;
          c32_u_4_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c32_u_0_4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c32_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c32_soc);
          _SFD_SET_DATA_VALUE_PTR(1U, c32_u_0_4);
          _SFD_SET_DATA_VALUE_PTR(2U, c32_u_4_5);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c32_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
  initialize_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c32_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  enable_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c32_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  disable_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c32_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  sf_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_hyd_hyb_2_opt_cont_test_new_1();/* state var info */
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

extern void sf_internal_set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_hyd_hyb_2_opt_cont_test_new_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1(S);
}

static void sf_opaque_set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1(S, st);
}

static void sf_opaque_terminate_c32_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c32_hyd_hyb_2_opt_cont_test_new_1
      ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc32_hyd_hyb_2_opt_cont_test_new_1
    ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c32_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c32_hyd_hyb_2_opt_cont_test_new_1
      ((SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c32_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_opt_cont_test_new_1",
      "hyd_hyb_2_opt_cont_test_new_1",32);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_test_new_1",
                "hyd_hyb_2_opt_cont_test_new_1",32,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_opt_cont_test_new_1","hyd_hyb_2_opt_cont_test_new_1",32,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_opt_cont_test_new_1",
        "hyd_hyb_2_opt_cont_test_new_1",32,1);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_opt_cont_test_new_1",
        "hyd_hyb_2_opt_cont_test_new_1",32,2);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_opt_cont_test_new_1",
                          "hyd_hyb_2_opt_cont_test_new_1",32);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3882119891U));
  ssSetChecksum1(S,(1439939375U));
  ssSetChecksum2(S,(3808211952U));
  ssSetChecksum3(S,(2511414913U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c32_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_opt_cont_test_new_1",
      "hyd_hyb_2_opt_cont_test_new_1",32);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c32_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)malloc
    (sizeof(SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc32_hyd_hyb_2_opt_cont_test_new_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c32_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c32_hyd_hyb_2_opt_cont_test_new_1;
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

void c32_hyd_hyb_2_opt_cont_test_new_1_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c32_hyd_hyb_2_opt_cont_test_new_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c32_hyd_hyb_2_opt_cont_test_new_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c32_hyd_hyb_2_opt_cont_test_new_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c32_hyd_hyb_2_opt_cont_test_new_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
