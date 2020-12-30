/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_sfun.h"
#include "c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[5] = { "nargin", "nargout", "T", "w",
  "y" };

/* Function Declarations */
static void initialize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void initialize_params_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void enable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void disable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Fin
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static const mxArray
  *get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_st);
static void finalize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void initSimStructsc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_y, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_c_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_d_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_b_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1,
   const char_T *c10_identifier);
static uint8_T c10_e_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1 =
    0U;
}

static void initialize_params_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static void enable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Fin
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static const mxArray
  *get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2));
  c10_hoistedGlobal = *c10_d_y;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal =
    chartInstance->c10_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_y;
  c10_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  *c10_y = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    0)), "y");
  chartInstance->c10_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1 =
    c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Fin(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

static void sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  real_T c10_c_x;
  real_T *c10_b_T;
  real_T *c10_c_y;
  real_T *c10_b_w;
  c10_b_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_b_T, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_c_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_b_w, 2U);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_T;
  c10_b_hoistedGlobal = *c10_b_w;
  c10_T = c10_hoistedGlobal;
  c10_w = c10_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c10_debug_family_names,
    c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c10_nargin, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_nargout, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c10_T, 2U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_w, 3U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c10_y, 4U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 2);
  if (CV_EML_IF(0, 0, c10_T > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
    c10_a = c10_T;
    c10_b = c10_w;
    c10_b_y = c10_a * c10_b;
    c10_A = c10_b_y;
    c10_x = c10_A;
    c10_b_x = c10_x;
    c10_c_x = c10_b_x;
    c10_y = c10_c_x / 1000.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
    c10_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c10_c_y = c10_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
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
  SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_mxArrayOutData, c10_y);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_y, const char_T *c10_identifier)
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
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
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
  SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c10_y = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_y), &c10_thisId);
  sf_mex_destroy(&c10_y);
  *(real_T *)c10_outData = c10_b_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray
  *sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[4];
  c10_ResolvedFunctionInfo (*c10_b_info)[4];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i0;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_b_info = (c10_ResolvedFunctionInfo (*)[4])c10_info;
  (*c10_b_info)[0].context = "";
  (*c10_b_info)[0].name = "mtimes";
  (*c10_b_info)[0].dominantType = "double";
  (*c10_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[0].fileTimeLo = 3767347712U;
  (*c10_b_info)[0].fileTimeHi = 30114278U;
  (*c10_b_info)[0].mFileTimeLo = 0U;
  (*c10_b_info)[0].mFileTimeHi = 0U;
  (*c10_b_info)[1].context = "";
  (*c10_b_info)[1].name = "mrdivide";
  (*c10_b_info)[1].dominantType = "double";
  (*c10_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[1].fileTimeLo = 2311411456U;
  (*c10_b_info)[1].fileTimeHi = 30130914U;
  (*c10_b_info)[1].mFileTimeLo = 3767347712U;
  (*c10_b_info)[1].mFileTimeHi = 30114278U;
  (*c10_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[2].name = "rdivide";
  (*c10_b_info)[2].dominantType = "double";
  (*c10_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[2].fileTimeLo = 3681966592U;
  (*c10_b_info)[2].fileTimeHi = 30107998U;
  (*c10_b_info)[2].mFileTimeLo = 0U;
  (*c10_b_info)[2].mFileTimeHi = 0U;
  (*c10_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[3].name = "eml_div";
  (*c10_b_info)[3].dominantType = "double";
  (*c10_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c10_b_info)[3].fileTimeLo = 2221966592U;
  (*c10_b_info)[3].fileTimeHi = 30107998U;
  (*c10_b_info)[3].mFileTimeLo = 0U;
  (*c10_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c10_i0 = 0; c10_i0 < 4; c10_i0++) {
    c10_r0 = &c10_info[c10_i0];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i0);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_mxArrayOutData, c10_y);
  return c10_mxArrayOutData;
}

static int32_T c10_c_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i1;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i1, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i1;
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
  SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)chartInstanceVoid;
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
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_b_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1,
   const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1);
  return c10_y;
}

static uint8_T c10_e_emlrt_marshallIn
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance,
   const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info
  (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1246866242U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1660483637U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3996013671U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2982483353U);
}

mxArray
  *sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3677759076U);
    pr[1] = (double)(1768161740U);
    pr[2] = (double)(3374879852U);
    pr[3] = (double)(3104051408U);
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

static const mxArray
  *sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
    chartInstance =
      (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
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
          init_script_number_translation
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,66);
        _SFD_CV_INIT_EML_IF(0,0,22,28,45,62);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

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
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1MachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
  initialize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void *
  chartInstanceVar)
{
  enable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void
  *chartInstanceVar)
{
  disable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(void
  *chartInstanceVar)
{
  sf_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*)
    get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1();/* state var info */
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

extern void
  sf_internal_set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    (S);
}

static void
  sf_opaque_set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S, st);
}

static void sf_opaque_terminate_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
      ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
    ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
      ((SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,
                "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
                "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10,2);
      sf_mark_chart_reusable_outputs(S,
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
        "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10,1);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
                          "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4106540404U));
  ssSetChecksum1(S,(933646865U));
  ssSetChecksum2(S,(4024191733U));
  ssSetChecksum3(S,(1722944071U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",
      "hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(SimStruct *S)
{
  SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct *chartInstance;
  chartInstance = (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct
                   *)malloc(sizeof
    (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1;
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

void c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_hyd_hyb_2_int_cont_1_new3_5cyc_Final_OK_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
