/* Include files */

#include "blascompat32.h"
#include "check_sfun.h"
#include "c23_check.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "check_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c23_debug_family_names[6] = { "nargin", "nargout", "u", "uf",
  "accf", "y" };

/* Function Declarations */
static void initialize_c23_check(SFc23_checkInstanceStruct *chartInstance);
static void initialize_params_c23_check(SFc23_checkInstanceStruct *chartInstance);
static void enable_c23_check(SFc23_checkInstanceStruct *chartInstance);
static void disable_c23_check(SFc23_checkInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_check(SFc23_checkInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c23_check(SFc23_checkInstanceStruct
  *chartInstance);
static void set_sim_state_c23_check(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_st);
static void finalize_c23_check(SFc23_checkInstanceStruct *chartInstance);
static void sf_c23_check(SFc23_checkInstanceStruct *chartInstance);
static void initSimStructsc23_check(SFc23_checkInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_y, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_c_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_d_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_b_is_active_c23_check, const char_T *c23_identifier);
static uint8_T c23_e_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_checkInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c23_check(SFc23_checkInstanceStruct *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c23_is_active_c23_check = 0U;
}

static void initialize_params_c23_check(SFc23_checkInstanceStruct *chartInstance)
{
}

static void enable_c23_check(SFc23_checkInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_check(SFc23_checkInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c23_update_debugger_state_c23_check(SFc23_checkInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c23_check(SFc23_checkInstanceStruct
  *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  uint8_T c23_b_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  real_T *c23_d_y;
  c23_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2));
  c23_hoistedGlobal = *c23_d_y;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = chartInstance->c23_is_active_c23_check;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y);
  return c23_st;
}

static void set_sim_state_c23_check(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_st)
{
  const mxArray *c23_u;
  real_T *c23_y;
  c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  *c23_y = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u,
    0)), "y");
  chartInstance->c23_is_active_c23_check = c23_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 1)), "is_active_c23_check");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_check(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_check(SFc23_checkInstanceStruct *chartInstance)
{
}

static void sf_c23_check(SFc23_checkInstanceStruct *chartInstance)
{
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  real_T c23_c_hoistedGlobal;
  real_T c23_u;
  real_T c23_uf;
  real_T c23_accf;
  uint32_T c23_debug_family_var_map[6];
  real_T c23_nargin = 3.0;
  real_T c23_nargout = 1.0;
  real_T c23_y;
  real_T c23_b;
  real_T *c23_b_u;
  real_T *c23_b_y;
  real_T *c23_b_uf;
  real_T *c23_b_accf;
  c23_b_accf = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c23_b_uf = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c23_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c23_b_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c23_b_uf, 2U);
  _SFD_DATA_RANGE_CHECK(*c23_b_accf, 3U);
  chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  c23_hoistedGlobal = *c23_b_u;
  c23_b_hoistedGlobal = *c23_b_uf;
  c23_c_hoistedGlobal = *c23_b_accf;
  c23_u = c23_hoistedGlobal;
  c23_uf = c23_b_hoistedGlobal;
  c23_accf = c23_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c23_debug_family_names,
    c23_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargin, 0U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargout, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c23_u, 2U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_uf, 3U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_accf, 4U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_y, 5U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 2);
  if (CV_EML_IF(0, 0, c23_accf > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 3);
    c23_b = c23_u + c23_uf;
    c23_y = 0.5 * c23_b;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
    c23_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c23_b_y = c23_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  sf_debug_check_for_state_inconsistency(_checkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc23_check(SFc23_checkInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_checkInstanceStruct *chartInstance;
  chartInstance = (SFc23_checkInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c23_mxArrayOutData, c23_y);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_y, const char_T *c23_identifier)
{
  real_T c23_b_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_y), &c23_thisId);
  sf_mex_destroy(&c23_y);
  return c23_b_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_y;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_b_y;
  SFc23_checkInstanceStruct *chartInstance;
  chartInstance = (SFc23_checkInstanceStruct *)chartInstanceVoid;
  c23_y = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_y), &c23_thisId);
  sf_mex_destroy(&c23_y);
  *(real_T *)c23_outData = c23_b_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_check_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo;
  c23_ResolvedFunctionInfo c23_info[1];
  c23_ResolvedFunctionInfo (*c23_b_info)[1];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i0;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  c23_b_info = (c23_ResolvedFunctionInfo (*)[1])c23_info;
  (*c23_b_info)[0].context = "";
  (*c23_b_info)[0].name = "mtimes";
  (*c23_b_info)[0].dominantType = "double";
  (*c23_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c23_b_info)[0].fileTimeLo = 3767347712U;
  (*c23_b_info)[0].fileTimeHi = 30114278U;
  (*c23_b_info)[0].mFileTimeLo = 0U;
  (*c23_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c23_i0 = 0; c23_i0 < 1; c23_i0++) {
    c23_r0 = &c23_info[c23_i0];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context", "nameCaptureInfo",
                    c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name", "nameCaptureInfo", c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)), "resolved",
                    "nameCaptureInfo", c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c23_i0);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c23_i0);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_checkInstanceStruct *chartInstance;
  chartInstance = (SFc23_checkInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c23_mxArrayOutData, c23_y);
  return c23_mxArrayOutData;
}

static int32_T c23_c_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i1;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i1, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i1;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_checkInstanceStruct *chartInstance;
  chartInstance = (SFc23_checkInstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_d_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_b_is_active_c23_check, const char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_check), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_check);
  return c23_y;
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_checkInstanceStruct *chartInstance,
  const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_checkInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c23_check_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(568976409U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4105353633U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4037402001U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3561345386U);
}

mxArray *sf_c23_check_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1603028782U);
    pr[1] = (double)(46089378U);
    pr[2] = (double)(3062661705U);
    pr[3] = (double)(3948632410U);
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

static const mxArray *sf_get_sim_state_info_c23_check(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c23_check\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_check_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_checkInstanceStruct *chartInstance;
    chartInstance = (SFc23_checkInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_checkMachineNumber_,
          23,
          1,
          1,
          4,
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
          init_script_number_translation(_checkMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_checkMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_checkMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"uf");
          _SFD_SET_DATA_PROPS(3,1,1,0,"accf");
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
        _SFD_CV_INIT_EML_IF(0,0,28,37,56,73);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c23_u;
          real_T *c23_y;
          real_T *c23_uf;
          real_T *c23_accf;
          c23_accf = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c23_uf = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c23_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c23_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_uf);
          _SFD_SET_DATA_VALUE_PTR(3U, c23_accf);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_checkMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c23_check(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_checkInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
  initialize_c23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_check(void *chartInstanceVar)
{
  enable_c23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_check(void *chartInstanceVar)
{
  disable_c23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_check(void *chartInstanceVar)
{
  sf_c23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c23_check(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_check((SFc23_checkInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_check();/* state var info */
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

extern void sf_internal_set_sim_state_c23_check(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_check();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_check((SFc23_checkInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_check(SimStruct* S)
{
  return sf_internal_get_sim_state_c23_check(S);
}

static void sf_opaque_set_sim_state_c23_check(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c23_check(S, st);
}

static void sf_opaque_terminate_c23_check(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_checkInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_check((SFc23_checkInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_check(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_check((SFc23_checkInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_check(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"check","check",23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"check","check",23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"check","check",23,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"check","check",23,3);
      sf_mark_chart_reusable_outputs(S,"check","check",23,1);
    }

    sf_set_rtw_dwork_info(S,"check","check",23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1184551705U));
  ssSetChecksum1(S,(3528616379U));
  ssSetChecksum2(S,(1823091923U));
  ssSetChecksum3(S,(1529992963U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_check(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "check", "check",23);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_check(SimStruct *S)
{
  SFc23_checkInstanceStruct *chartInstance;
  chartInstance = (SFc23_checkInstanceStruct *)malloc(sizeof
    (SFc23_checkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_checkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c23_check;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c23_check;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c23_check;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_check;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_check;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c23_check;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c23_check;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c23_check;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_check;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_check;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c23_check;
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

void c23_check_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_check(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_check(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_check(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_check_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
