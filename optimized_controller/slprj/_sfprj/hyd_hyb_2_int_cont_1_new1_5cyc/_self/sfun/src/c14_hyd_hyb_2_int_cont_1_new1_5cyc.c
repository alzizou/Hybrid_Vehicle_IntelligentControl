/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new1_5cyc_sfun.h"
#include "c14_hyd_hyb_2_int_cont_1_new1_5cyc.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new1_5cyc_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c14_debug_family_names[5] = { "nargin", "nargout", "u",
  "u_f", "y" };

/* Function Declarations */
static void initialize_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void initialize_params_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void enable_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void disable_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_st);
static void finalize_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void initSimStructsc14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_y, const char_T *c14_identifier);
static real_T c14_b_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static real_T c14_mpower(SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct
  *chartInstance, real_T c14_a);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_c_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_d_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_b_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc, const char_T
   *c14_identifier);
static uint8_T c14_e_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc = 0U;
}

static void initialize_params_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static void enable_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_u;
  const mxArray *c14_b_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  real_T *c14_d_y;
  c14_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(2));
  c14_hoistedGlobal = *c14_d_y;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_hoistedGlobal =
    chartInstance->c14_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  c14_b_u = c14_b_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 1, c14_c_y);
  sf_mex_assign(&c14_st, c14_y);
  return c14_st;
}

static void set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T *c14_y;
  c14_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  *c14_y = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u,
    0)), "y");
  chartInstance->c14_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc =
    c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
    "is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static void sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
  real_T c14_hoistedGlobal;
  real_T c14_b_hoistedGlobal;
  real_T c14_u;
  real_T c14_u_f;
  uint32_T c14_debug_family_var_map[5];
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 1.0;
  real_T c14_y;
  real_T *c14_b_u;
  real_T *c14_b_y;
  real_T *c14_b_u_f;
  c14_b_u_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c14_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c14_b_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c14_b_u_f, 2U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
  c14_hoistedGlobal = *c14_b_u;
  c14_b_hoistedGlobal = *c14_b_u_f;
  c14_u = c14_hoistedGlobal;
  c14_u_f = c14_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c14_debug_family_names,
    c14_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c14_nargin, 0U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c14_nargout, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c14_u, 2U, c14_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c14_u_f, 3U, c14_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c14_y, 4U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 2);
  c14_y = c14_mpower(chartInstance, c14_u) - c14_mpower(chartInstance, c14_u_f);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -2);
  sf_debug_symbol_scope_pop();
  *c14_b_y = c14_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_y, const char_T *c14_identifier)
{
  real_T c14_b_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_y), &c14_thisId);
  sf_mex_destroy(&c14_y);
  return c14_b_y;
}

static real_T c14_b_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_y;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_b_y;
  SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c14_y = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_y), &c14_thisId);
  sf_mex_destroy(&c14_y);
  *(real_T *)c14_outData = c14_b_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray
  *sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo;
  c14_ResolvedFunctionInfo c14_info[6];
  c14_ResolvedFunctionInfo (*c14_b_info)[6];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i0;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  c14_b_info = (c14_ResolvedFunctionInfo (*)[6])c14_info;
  (*c14_b_info)[0].context = "";
  (*c14_b_info)[0].name = "mpower";
  (*c14_b_info)[0].dominantType = "double";
  (*c14_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c14_b_info)[0].fileTimeLo = 3661966592U;
  (*c14_b_info)[0].fileTimeHi = 30107998U;
  (*c14_b_info)[0].mFileTimeLo = 0U;
  (*c14_b_info)[0].mFileTimeHi = 0U;
  (*c14_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c14_b_info)[1].name = "power";
  (*c14_b_info)[1].dominantType = "double";
  (*c14_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c14_b_info)[1].fileTimeLo = 3681966592U;
  (*c14_b_info)[1].fileTimeHi = 30107998U;
  (*c14_b_info)[1].mFileTimeLo = 0U;
  (*c14_b_info)[1].mFileTimeHi = 0U;
  (*c14_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c14_b_info)[2].name = "eml_scalar_eg";
  (*c14_b_info)[2].dominantType = "double";
  (*c14_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c14_b_info)[2].fileTimeLo = 3201966592U;
  (*c14_b_info)[2].fileTimeHi = 30107998U;
  (*c14_b_info)[2].mFileTimeLo = 0U;
  (*c14_b_info)[2].mFileTimeHi = 0U;
  (*c14_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c14_b_info)[3].name = "eml_scalexp_alloc";
  (*c14_b_info)[3].dominantType = "double";
  (*c14_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c14_b_info)[3].fileTimeLo = 3201966592U;
  (*c14_b_info)[3].fileTimeHi = 30107998U;
  (*c14_b_info)[3].mFileTimeLo = 0U;
  (*c14_b_info)[3].mFileTimeHi = 0U;
  (*c14_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c14_b_info)[4].name = "eml_scalar_floor";
  (*c14_b_info)[4].dominantType = "double";
  (*c14_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c14_b_info)[4].fileTimeLo = 2501966592U;
  (*c14_b_info)[4].fileTimeHi = 30107998U;
  (*c14_b_info)[4].mFileTimeLo = 0U;
  (*c14_b_info)[4].mFileTimeHi = 0U;
  (*c14_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c14_b_info)[5].name = "eml_error";
  (*c14_b_info)[5].dominantType = "char";
  (*c14_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c14_b_info)[5].fileTimeLo = 2241966592U;
  (*c14_b_info)[5].fileTimeHi = 30107998U;
  (*c14_b_info)[5].mFileTimeLo = 0U;
  (*c14_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6));
  for (c14_i0 = 0; c14_i0 < 6; c14_i0++) {
    c14_r0 = &c14_info[c14_i0];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context", "nameCaptureInfo",
                    c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name", "nameCaptureInfo", c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)), "resolved",
                    "nameCaptureInfo", c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c14_i0);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c14_i0);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0);
  return c14_nameCaptureInfo;
}

static real_T c14_mpower(SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct
  *chartInstance, real_T c14_a)
{
  real_T c14_b_a;
  real_T c14_ak;
  c14_b_a = c14_a;
  c14_ak = c14_b_a;
  return muDoubleScalarPower(c14_ak, 2.0);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static int32_T c14_c_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i1;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i1, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i1;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
    chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_d_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_b_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc, const char_T
   *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc);
  return c14_y;
}

static uint8_T c14_e_emlrt_marshallIn
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance, const
   mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info
  (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1425908684U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2222453539U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1120949318U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4081563568U);
}

mxArray *sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4070991689U);
    pr[1] = (double)(4217372977U);
    pr[2] = (double)(2241379037U);
    pr[3] = (double)(1938662181U);
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

static const mxArray *sf_get_sim_state_info_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c14_hyd_hyb_2_int_cont_1_new1_5cyc\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
    chartInstance = (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
           14,
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
          _SFD_SET_DATA_PROPS(2,1,1,0,"u_f");
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,42);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c14_u;
          real_T *c14_y;
          real_T *c14_u_f;
          c14_u_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c14_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c14_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c14_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c14_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_u_f);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new1_5cycMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c14_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
  initialize_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  enable_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  disable_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  sf_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_hyd_hyb_2_int_cont_1_new1_5cyc();/* state var info */
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

extern void sf_internal_set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_hyd_hyb_2_int_cont_1_new1_5cyc();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc(S);
}

static void sf_opaque_set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc(S, st);
}

static void sf_opaque_terminate_c14_hyd_hyb_2_int_cont_1_new1_5cyc(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c14_hyd_hyb_2_int_cont_1_new1_5cyc
      ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_hyd_hyb_2_int_cont_1_new1_5cyc
    ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_hyd_hyb_2_int_cont_1_new1_5cyc
      ((SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
      "hyd_hyb_2_int_cont_1_new1_5cyc",14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
                "hyd_hyb_2_int_cont_1_new1_5cyc",14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new1_5cyc","hyd_hyb_2_int_cont_1_new1_5cyc",14,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
        "hyd_hyb_2_int_cont_1_new1_5cyc",14,2);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
        "hyd_hyb_2_int_cont_1_new1_5cyc",14,1);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new1_5cyc",
                          "hyd_hyb_2_int_cont_1_new1_5cyc",14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1527795794U));
  ssSetChecksum1(S,(3529589094U));
  ssSetChecksum2(S,(1722923503U));
  ssSetChecksum3(S,(2988496977U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c14_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new1_5cyc",
      "hyd_hyb_2_int_cont_1_new1_5cyc",14);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_hyd_hyb_2_int_cont_1_new1_5cyc(SimStruct *S)
{
  SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct *)malloc
    (sizeof(SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc14_hyd_hyb_2_int_cont_1_new1_5cycInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_hyd_hyb_2_int_cont_1_new1_5cyc;
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

void c14_hyd_hyb_2_int_cont_1_new1_5cyc_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_hyd_hyb_2_int_cont_1_new1_5cyc(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_hyd_hyb_2_int_cont_1_new1_5cyc(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_hyd_hyb_2_int_cont_1_new1_5cyc(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_hyd_hyb_2_int_cont_1_new1_5cyc_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}