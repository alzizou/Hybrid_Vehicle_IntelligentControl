/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new1_5cyc_sfun.h"
#include "c18_hyd_hyb_2_int_cont_1_new1_5cyc.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new1_5cyc_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c18_debug_family_names[6] = { "r", "nargin", "nargout", "u",
  "T0", "y" };

/* Function Declarations */
static void initialize_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void initialize_params_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void enable_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void disable_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_st);
static void finalize_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void initSimStructsc18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_y, const char_T *c18_identifier);
static real_T c18_b_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_c_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_d_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_b_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc, const char_T
   *c18_identifier);
static uint8_T c18_e_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c18_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc = 0U;
}

static void initialize_params_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  real_T c18_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'T0' in the parent workspace.\n");
  sf_mex_import_named("T0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c18_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c18_T0 = c18_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c18_update_debugger_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  real_T c18_hoistedGlobal;
  real_T c18_u;
  const mxArray *c18_b_y = NULL;
  uint8_T c18_b_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  real_T *c18_d_y;
  c18_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellarray(2));
  c18_hoistedGlobal = *c18_d_y;
  c18_u = c18_hoistedGlobal;
  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_b_hoistedGlobal =
    chartInstance->c18_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  c18_b_u = c18_b_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y);
  return c18_st;
}

static void set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T *c18_y;
  c18_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c18_doneDoubleBufferReInit = TRUE;
  c18_u = sf_mex_dup(c18_st);
  *c18_y = c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u,
    0)), "y");
  chartInstance->c18_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc =
    c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
    "is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static void sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  real_T c18_hoistedGlobal;
  real_T c18_b_hoistedGlobal;
  real_T c18_u;
  real_T c18_b_T0;
  uint32_T c18_debug_family_var_map[6];
  real_T c18_r;
  real_T c18_nargin = 2.0;
  real_T c18_nargout = 1.0;
  real_T c18_y;
  real_T c18_x;
  real_T c18_b_y;
  real_T c18_xk;
  real_T c18_yk;
  real_T c18_b_x;
  real_T c18_c_y;
  real_T *c18_b_u;
  real_T *c18_d_y;
  c18_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c18_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c18_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c18_d_y, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c18_T0, 2U);
  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c18_sfEvent);
  c18_hoistedGlobal = *c18_b_u;
  c18_b_hoistedGlobal = chartInstance->c18_T0;
  c18_u = c18_hoistedGlobal;
  c18_b_T0 = c18_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c18_debug_family_names,
    c18_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c18_r, 0U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c18_nargin, 1U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c18_nargout, 2U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c18_u, 3U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c18_b_T0, 4U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c18_y, 5U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 2);
  c18_x = c18_u;
  c18_b_y = c18_b_T0;
  c18_xk = c18_x;
  c18_yk = c18_b_y;
  c18_b_x = c18_xk;
  c18_c_y = c18_yk;
  c18_r = muDoubleScalarRem(c18_b_x, c18_c_y);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 3);
  if (CV_EML_IF(0, 0, c18_r < 0.01)) {
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 4);
    c18_y = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 6);
    c18_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  *c18_d_y = c18_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c18_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber)
{
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c18_mxArrayOutData, c18_y);
  return c18_mxArrayOutData;
}

static real_T c18_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_y, const char_T *c18_identifier)
{
  real_T c18_b_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_y), &c18_thisId);
  sf_mex_destroy(&c18_y);
  return c18_b_y;
}

static real_T c18_b_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d1;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d1, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d1;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_y;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_b_y;
  SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c18_y = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_y), &c18_thisId);
  sf_mex_destroy(&c18_y);
  *(real_T *)c18_outData = c18_b_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray
  *sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo;
  c18_ResolvedFunctionInfo c18_info[4];
  c18_ResolvedFunctionInfo (*c18_b_info)[4];
  const mxArray *c18_m0 = NULL;
  int32_T c18_i0;
  c18_ResolvedFunctionInfo *c18_r0;
  c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  c18_b_info = (c18_ResolvedFunctionInfo (*)[4])c18_info;
  (*c18_b_info)[0].context = "";
  (*c18_b_info)[0].name = "rem";
  (*c18_b_info)[0].dominantType = "double";
  (*c18_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c18_b_info)[0].fileTimeLo = 2721966592U;
  (*c18_b_info)[0].fileTimeHi = 30107998U;
  (*c18_b_info)[0].mFileTimeLo = 0U;
  (*c18_b_info)[0].mFileTimeHi = 0U;
  (*c18_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c18_b_info)[1].name = "eml_scalar_eg";
  (*c18_b_info)[1].dominantType = "double";
  (*c18_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c18_b_info)[1].fileTimeLo = 3201966592U;
  (*c18_b_info)[1].fileTimeHi = 30107998U;
  (*c18_b_info)[1].mFileTimeLo = 0U;
  (*c18_b_info)[1].mFileTimeHi = 0U;
  (*c18_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c18_b_info)[2].name = "eml_scalexp_alloc";
  (*c18_b_info)[2].dominantType = "double";
  (*c18_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c18_b_info)[2].fileTimeLo = 3201966592U;
  (*c18_b_info)[2].fileTimeHi = 30107998U;
  (*c18_b_info)[2].mFileTimeLo = 0U;
  (*c18_b_info)[2].mFileTimeHi = 0U;
  (*c18_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  (*c18_b_info)[3].name = "eml_scalar_rem";
  (*c18_b_info)[3].dominantType = "double";
  (*c18_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem.m";
  (*c18_b_info)[3].fileTimeLo = 2561966592U;
  (*c18_b_info)[3].fileTimeHi = 30107998U;
  (*c18_b_info)[3].mFileTimeLo = 0U;
  (*c18_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c18_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c18_i0 = 0; c18_i0 < 4; c18_i0++) {
    c18_r0 = &c18_info[c18_i0];
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c18_r0->context)), "context", "nameCaptureInfo",
                    c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c18_r0->name)), "name", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      c18_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c18_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c18_r0->resolved)), "resolved",
                    "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      &c18_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      &c18_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c18_i0);
  }

  sf_mex_assign(&c18_nameCaptureInfo, c18_m0);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c18_mxArrayOutData, c18_y);
  return c18_mxArrayOutData;
}

static int32_T c18_c_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i1;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i1, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i1;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_d_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_b_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc, const char_T
   *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc);
  return c18_y;
}

static uint8_T c18_e_emlrt_marshallIn
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info
  (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3311972701U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1730336709U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(345305678U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1834657407U);
}

mxArray *sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2076291719U);
    pr[1] = (double)(623997071U);
    pr[2] = (double)(1800081266U);
    pr[3] = (double)(3890663286U);
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

static const mxArray *sf_get_sim_state_info_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c18_hyd_hyb_2_int_cont_1_new1_5cyc\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
    chartInstance = (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
           18,
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
            (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,77);
        _SFD_CV_INIT_EML_IF(0,0,37,46,56,73);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)c18_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)c18_sf_marshallIn);

        {
          real_T *c18_u;
          real_T *c18_y;
          c18_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c18_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c18_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c18_y);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c18_T0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c18_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
  initialize_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  enable_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  disable_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  sf_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_hyd_hyb_2_int_cont_1_new1_5cyc();/* state var info */
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

extern void sf_internal_set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_hyd_hyb_2_int_cont_1_new1_5cyc();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc(S);
}

static void sf_opaque_set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc(S, st);
}

static void sf_opaque_terminate_c18_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c18_hyd_hyb_2_int_cont_1_new1_5cyc
      ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c18_hyd_hyb_2_int_cont_1_new1_5cyc
      ((SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  /* Actual parameters from chart:
     T0
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
      "hyd_hyb_2_int_cont_1_new1_5cyc",18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
                "hyd_hyb_2_int_cont_1_new1_5cyc",18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new1_5cyc","hyd_hyb_2_int_cont_1_new1_5cyc",18,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
        "hyd_hyb_2_int_cont_1_new1_5cyc",18,1);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
        "hyd_hyb_2_int_cont_1_new1_5cyc",18,1);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
                          "hyd_hyb_2_int_cont_1_new1_5cyc",18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2381231485U));
  ssSetChecksum1(S,(3804306844U));
  ssSetChecksum2(S,(1568618458U));
  ssSetChecksum3(S,(740843857U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c18_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new1_5cyc",
      "hyd_hyb_2_int_cont_1_new1_5cyc",18);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)malloc
    (sizeof(SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc18_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_hyd_hyb_2_int_cont_1_new1_5cyc;
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

void c18_hyd_hyb_2_int_cont_1_new1_5cyc_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_hyd_hyb_2_int_cont_1_new1_5cyc(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_hyd_hyb_2_int_cont_1_new1_5cyc(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_hyd_hyb_2_int_cont_1_new1_5cyc(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_hyd_hyb_2_int_cont_1_new1_5cyc_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}