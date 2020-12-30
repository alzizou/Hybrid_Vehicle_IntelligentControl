/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_opt_cont_test_new_sfun.h"
#include "c27_hyd_hyb_2_opt_cont_test_new.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_opt_cont_test_new_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c27_debug_family_names[5] = { "nargin", "nargout", "soc",
  "u_0_5", "u_5_1" };

/* Function Declarations */
static void initialize_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void initialize_params_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void enable_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void disable_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void c27_update_debugger_state_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void set_sim_state_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_st);
static void finalize_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void sf_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void initSimStructsc27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u_5_1, const char_T *c27_identifier);
static real_T c27_b_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_c_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_d_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_b_is_active_c27_hyd_hyb_2_opt_cont_test_new, const char_T
   *c27_identifier);
static uint8_T c27_e_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c27_is_active_c27_hyd_hyb_2_opt_cont_test_new = 0U;
}

static void initialize_params_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static void enable_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c27_update_debugger_state_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  real_T c27_hoistedGlobal;
  real_T c27_u;
  const mxArray *c27_b_y = NULL;
  real_T c27_b_hoistedGlobal;
  real_T c27_b_u;
  const mxArray *c27_c_y = NULL;
  uint8_T c27_c_hoistedGlobal;
  uint8_T c27_c_u;
  const mxArray *c27_d_y = NULL;
  real_T *c27_u_0_5;
  real_T *c27_u_5_1;
  c27_u_5_1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c27_u_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellarray(3));
  c27_hoistedGlobal = *c27_u_0_5;
  c27_u = c27_hoistedGlobal;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_b_hoistedGlobal = *c27_u_5_1;
  c27_b_u = c27_b_hoistedGlobal;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c27_y, 1, c27_c_y);
  c27_c_hoistedGlobal =
    chartInstance->c27_is_active_c27_hyd_hyb_2_opt_cont_test_new;
  c27_c_u = c27_c_hoistedGlobal;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c27_y, 2, c27_d_y);
  sf_mex_assign(&c27_st, c27_y);
  return c27_st;
}

static void set_sim_state_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_st)
{
  const mxArray *c27_u;
  real_T *c27_u_0_5;
  real_T *c27_u_5_1;
  c27_u_5_1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c27_u_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c27_doneDoubleBufferReInit = TRUE;
  c27_u = sf_mex_dup(c27_st);
  *c27_u_0_5 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c27_u, 0)), "u_0_5");
  *c27_u_5_1 = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c27_u, 1)), "u_5_1");
  chartInstance->c27_is_active_c27_hyd_hyb_2_opt_cont_test_new =
    c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 2)),
    "is_active_c27_hyd_hyb_2_opt_cont_test_new");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_hyd_hyb_2_opt_cont_test_new(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static void sf_c27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
  real_T c27_hoistedGlobal;
  real_T c27_soc;
  uint32_T c27_debug_family_var_map[5];
  real_T c27_nargin = 1.0;
  real_T c27_nargout = 2.0;
  real_T c27_u_0_5;
  real_T c27_u_5_1;
  real_T c27_b;
  real_T c27_b_b;
  real_T *c27_b_soc;
  real_T *c27_b_u_0_5;
  real_T *c27_b_u_5_1;
  c27_b_u_5_1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c27_b_u_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c27_b_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c27_b_soc, 0U);
  _SFD_DATA_RANGE_CHECK(*c27_b_u_0_5, 1U);
  _SFD_DATA_RANGE_CHECK(*c27_b_u_5_1, 2U);
  chartInstance->c27_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  c27_hoistedGlobal = *c27_b_soc;
  c27_soc = c27_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c27_debug_family_names,
    c27_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c27_nargin, 0U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c27_nargout, 1U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c27_soc, 2U, c27_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c27_u_0_5, 3U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c27_u_5_1, 4U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 2);
  if (CV_EML_IF(0, 0, c27_soc < 0.45)) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 3);
    c27_u_0_5 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 4);
    c27_u_5_1 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 5);
    if (CV_EML_IF(0, 1, c27_soc < 0.55)) {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 6);
      c27_b = c27_soc - 0.55;
      c27_u_0_5 = -10.0 * c27_b;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 7);
      c27_b_b = c27_soc - 0.45;
      c27_u_5_1 = 10.0 * c27_b_b;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 9);
      c27_u_0_5 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 10);
      c27_u_5_1 = 1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c27_b_u_0_5 = c27_u_0_5;
  *c27_b_u_5_1 = c27_u_5_1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_opt_cont_test_newMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc27_hyd_hyb_2_opt_cont_test_new
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber)
{
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c27_mxArrayOutData, c27_y);
  return c27_mxArrayOutData;
}

static real_T c27_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u_5_1, const char_T *c27_identifier)
{
  real_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_u_5_1),
    &c27_thisId);
  sf_mex_destroy(&c27_u_5_1);
  return c27_y;
}

static real_T c27_b_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_u_5_1;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c27_u_5_1 = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_u_5_1),
    &c27_thisId);
  sf_mex_destroy(&c27_u_5_1);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray
  *sf_c27_hyd_hyb_2_opt_cont_test_new_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo;
  c27_ResolvedFunctionInfo c27_info[4];
  c27_ResolvedFunctionInfo (*c27_b_info)[4];
  const mxArray *c27_m0 = NULL;
  int32_T c27_i0;
  c27_ResolvedFunctionInfo *c27_r0;
  c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  c27_b_info = (c27_ResolvedFunctionInfo (*)[4])c27_info;
  (*c27_b_info)[0].context = "";
  (*c27_b_info)[0].name = "mrdivide";
  (*c27_b_info)[0].dominantType = "double";
  (*c27_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c27_b_info)[0].fileTimeLo = 2311411456U;
  (*c27_b_info)[0].fileTimeHi = 30130914U;
  (*c27_b_info)[0].mFileTimeLo = 3767347712U;
  (*c27_b_info)[0].mFileTimeHi = 30114278U;
  (*c27_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c27_b_info)[1].name = "rdivide";
  (*c27_b_info)[1].dominantType = "double";
  (*c27_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c27_b_info)[1].fileTimeLo = 3681966592U;
  (*c27_b_info)[1].fileTimeHi = 30107998U;
  (*c27_b_info)[1].mFileTimeLo = 0U;
  (*c27_b_info)[1].mFileTimeHi = 0U;
  (*c27_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c27_b_info)[2].name = "eml_div";
  (*c27_b_info)[2].dominantType = "double";
  (*c27_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c27_b_info)[2].fileTimeLo = 2221966592U;
  (*c27_b_info)[2].fileTimeHi = 30107998U;
  (*c27_b_info)[2].mFileTimeLo = 0U;
  (*c27_b_info)[2].mFileTimeHi = 0U;
  (*c27_b_info)[3].context = "";
  (*c27_b_info)[3].name = "mtimes";
  (*c27_b_info)[3].dominantType = "double";
  (*c27_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c27_b_info)[3].fileTimeLo = 3767347712U;
  (*c27_b_info)[3].fileTimeHi = 30114278U;
  (*c27_b_info)[3].mFileTimeLo = 0U;
  (*c27_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c27_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c27_i0 = 0; c27_i0 < 4; c27_i0++) {
    c27_r0 = &c27_info[c27_i0];
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->context)), "context", "nameCaptureInfo",
                    c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->name)), "name", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      c27_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->resolved)), "resolved",
                    "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      &c27_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      &c27_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c27_i0);
  }

  sf_mex_assign(&c27_nameCaptureInfo, c27_m0);
  return c27_nameCaptureInfo;
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c27_mxArrayOutData, c27_y);
  return c27_mxArrayOutData;
}

static int32_T c27_c_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i1;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i1, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i1;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
    chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_d_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_b_is_active_c27_hyd_hyb_2_opt_cont_test_new, const char_T
   *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_hyd_hyb_2_opt_cont_test_new), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_hyd_hyb_2_opt_cont_test_new);
  return c27_y;
}

static uint8_T c27_e_emlrt_marshallIn
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance, const mxArray
   *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info
  (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c27_hyd_hyb_2_opt_cont_test_new_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3565718426U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1766818902U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2600612858U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3646981064U);
}

mxArray *sf_c27_hyd_hyb_2_opt_cont_test_new_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4083248190U);
    pr[1] = (double)(2881905377U);
    pr[2] = (double)(1764200818U);
    pr[3] = (double)(1358324958U);
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

static const mxArray *sf_get_sim_state_info_c27_hyd_hyb_2_opt_cont_test_new(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_0_5\",},{M[1],M[6],T\"u_5_1\",},{M[8],M[0],T\"is_active_c27_hyd_hyb_2_opt_cont_test_new\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_hyd_hyb_2_opt_cont_test_new_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
    chartInstance = (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_opt_cont_test_newMachineNumber_,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"soc");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u_0_5");
          _SFD_SET_DATA_PROPS(2,2,0,1,"u_5_1");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,185);
        _SFD_CV_INIT_EML_IF(0,0,34,45,72,181);
        _SFD_CV_INIT_EML_IF(0,1,72,87,147,181);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)c27_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)c27_sf_marshallIn);

        {
          real_T *c27_soc;
          real_T *c27_u_0_5;
          real_T *c27_u_5_1;
          c27_u_5_1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c27_u_0_5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c27_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c27_soc);
          _SFD_SET_DATA_VALUE_PTR(1U, c27_u_0_5);
          _SFD_SET_DATA_VALUE_PTR(2U, c27_u_5_1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_opt_cont_test_newMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c27_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
  initialize_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c27_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  enable_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c27_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  disable_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c27_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  sf_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c27_hyd_hyb_2_opt_cont_test_new
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_hyd_hyb_2_opt_cont_test_new();/* state var info */
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

extern void sf_internal_set_sim_state_c27_hyd_hyb_2_opt_cont_test_new(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_hyd_hyb_2_opt_cont_test_new();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c27_hyd_hyb_2_opt_cont_test_new
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c27_hyd_hyb_2_opt_cont_test_new(S);
}

static void sf_opaque_set_sim_state_c27_hyd_hyb_2_opt_cont_test_new(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c27_hyd_hyb_2_opt_cont_test_new(S, st);
}

static void sf_opaque_terminate_c27_hyd_hyb_2_opt_cont_test_new(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c27_hyd_hyb_2_opt_cont_test_new
      ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc27_hyd_hyb_2_opt_cont_test_new
    ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c27_hyd_hyb_2_opt_cont_test_new
      ((SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_opt_cont_test_new",
      "hyd_hyb_2_opt_cont_test_new",27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_test_new",
                "hyd_hyb_2_opt_cont_test_new",27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_opt_cont_test_new","hyd_hyb_2_opt_cont_test_new",27,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_opt_cont_test_new",
        "hyd_hyb_2_opt_cont_test_new",27,1);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_opt_cont_test_new",
        "hyd_hyb_2_opt_cont_test_new",27,2);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_opt_cont_test_new",
                          "hyd_hyb_2_opt_cont_test_new",27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(918662372U));
  ssSetChecksum1(S,(2326447435U));
  ssSetChecksum2(S,(2061006131U));
  ssSetChecksum3(S,(2979108489U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c27_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_opt_cont_test_new",
      "hyd_hyb_2_opt_cont_test_new",27);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_hyd_hyb_2_opt_cont_test_new(SimStruct *S)
{
  SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *chartInstance;
  chartInstance = (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct *)malloc
    (sizeof(SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc27_hyd_hyb_2_opt_cont_test_newInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_hyd_hyb_2_opt_cont_test_new;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_hyd_hyb_2_opt_cont_test_new;
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

void c27_hyd_hyb_2_opt_cont_test_new_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_hyd_hyb_2_opt_cont_test_new(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_hyd_hyb_2_opt_cont_test_new(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_hyd_hyb_2_opt_cont_test_new(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_hyd_hyb_2_opt_cont_test_new_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
