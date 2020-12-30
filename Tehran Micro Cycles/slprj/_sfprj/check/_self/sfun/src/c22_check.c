/* Include files */

#include "blascompat32.h"
#include "check_sfun.h"
#include "c22_check.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "check_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c22_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c22_check(SFc22_checkInstanceStruct *chartInstance);
static void initialize_params_c22_check(SFc22_checkInstanceStruct *chartInstance);
static void enable_c22_check(SFc22_checkInstanceStruct *chartInstance);
static void disable_c22_check(SFc22_checkInstanceStruct *chartInstance);
static void c22_update_debugger_state_c22_check(SFc22_checkInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c22_check(SFc22_checkInstanceStruct
  *chartInstance);
static void set_sim_state_c22_check(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_st);
static void finalize_c22_check(SFc22_checkInstanceStruct *chartInstance);
static void sf_c22_check(SFc22_checkInstanceStruct *chartInstance);
static void initSimStructsc22_check(SFc22_checkInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_y, const char_T *c22_identifier);
static real_T c22_b_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_c_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_d_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_b_is_active_c22_check, const char_T *c22_identifier);
static uint8_T c22_e_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_checkInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c22_check(SFc22_checkInstanceStruct *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c22_is_active_c22_check = 0U;
}

static void initialize_params_c22_check(SFc22_checkInstanceStruct *chartInstance)
{
}

static void enable_c22_check(SFc22_checkInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c22_check(SFc22_checkInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c22_update_debugger_state_c22_check(SFc22_checkInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c22_check(SFc22_checkInstanceStruct
  *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  real_T c22_hoistedGlobal;
  real_T c22_u;
  const mxArray *c22_b_y = NULL;
  uint8_T c22_b_hoistedGlobal;
  uint8_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  real_T *c22_d_y;
  c22_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellarray(2));
  c22_hoistedGlobal = *c22_d_y;
  c22_u = c22_hoistedGlobal;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_b_hoistedGlobal = chartInstance->c22_is_active_c22_check;
  c22_b_u = c22_b_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 1, c22_c_y);
  sf_mex_assign(&c22_st, c22_y);
  return c22_st;
}

static void set_sim_state_c22_check(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T *c22_y;
  c22_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c22_doneDoubleBufferReInit = TRUE;
  c22_u = sf_mex_dup(c22_st);
  *c22_y = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u,
    0)), "y");
  chartInstance->c22_is_active_c22_check = c22_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 1)), "is_active_c22_check");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_check(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_check(SFc22_checkInstanceStruct *chartInstance)
{
}

static void sf_c22_check(SFc22_checkInstanceStruct *chartInstance)
{
  real_T c22_hoistedGlobal;
  real_T c22_u;
  uint32_T c22_debug_family_var_map[4];
  real_T c22_nargin = 1.0;
  real_T c22_nargout = 1.0;
  real_T c22_y;
  real_T *c22_b_u;
  real_T *c22_b_y;
  boolean_T guard1 = FALSE;
  c22_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c22_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c22_b_y, 1U);
  chartInstance->c22_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  c22_hoistedGlobal = *c22_b_u;
  c22_u = c22_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c22_debug_family_names,
    c22_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c22_nargin, 0U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c22_nargout, 1U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c22_u, 2U, c22_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c22_y, 3U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 2);
  guard1 = FALSE;
  if (CV_EML_COND(0, 0, c22_u >= 0.0)) {
    if (CV_EML_COND(0, 1, c22_u < 5.0)) {
      CV_EML_MCDC(0, 0, TRUE);
      CV_EML_IF(0, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 3);
      c22_y = 1.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 5);
    c22_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c22_b_y = c22_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  sf_debug_check_for_state_inconsistency(_checkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc22_check(SFc22_checkInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber)
{
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_checkInstanceStruct *chartInstance;
  chartInstance = (SFc22_checkInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c22_mxArrayOutData, c22_y);
  return c22_mxArrayOutData;
}

static real_T c22_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_y, const char_T *c22_identifier)
{
  real_T c22_b_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_y), &c22_thisId);
  sf_mex_destroy(&c22_y);
  return c22_b_y;
}

static real_T c22_b_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_y;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_b_y;
  SFc22_checkInstanceStruct *chartInstance;
  chartInstance = (SFc22_checkInstanceStruct *)chartInstanceVoid;
  c22_y = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_y), &c22_thisId);
  sf_mex_destroy(&c22_y);
  *(real_T *)c22_outData = c22_b_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_check_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c22_nameCaptureInfo;
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_checkInstanceStruct *chartInstance;
  chartInstance = (SFc22_checkInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c22_mxArrayOutData, c22_y);
  return c22_mxArrayOutData;
}

static int32_T c22_c_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i0, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_checkInstanceStruct *chartInstance;
  chartInstance = (SFc22_checkInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_d_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_b_is_active_c22_check, const char_T *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_check), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_check);
  return c22_y;
}

static uint8_T c22_e_emlrt_marshallIn(SFc22_checkInstanceStruct *chartInstance,
  const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_checkInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c22_check_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2953850367U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3135566863U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3688769414U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2683946970U);
}

mxArray *sf_c22_check_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(494952852U);
    pr[1] = (double)(18321108U);
    pr[2] = (double)(592242653U);
    pr[3] = (double)(2069113006U);
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

static const mxArray *sf_get_sim_state_info_c22_check(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c22_check\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_check_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_checkInstanceStruct *chartInstance;
    chartInstance = (SFc22_checkInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_checkMachineNumber_,
          22,
          1,
          1,
          2,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,65);
        _SFD_CV_INIT_EML_IF(0,0,20,34,44,61);

        {
          static int condStart[] = { 23, 31 };

          static int condEnd[] = { 27, 34 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,23,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);

        {
          real_T *c22_u;
          real_T *c22_y;
          c22_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c22_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c22_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c22_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_checkMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c22_check(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_checkInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
  initialize_c22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c22_check(void *chartInstanceVar)
{
  enable_c22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_check(void *chartInstanceVar)
{
  disable_c22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_check(void *chartInstanceVar)
{
  sf_c22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c22_check(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c22_check((SFc22_checkInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_check();/* state var info */
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

extern void sf_internal_set_sim_state_c22_check(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_check();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c22_check((SFc22_checkInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c22_check(SimStruct* S)
{
  return sf_internal_get_sim_state_c22_check(S);
}

static void sf_opaque_set_sim_state_c22_check(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c22_check(S, st);
}

static void sf_opaque_terminate_c22_check(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_checkInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc22_check((SFc22_checkInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_check(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c22_check((SFc22_checkInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_check(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"check","check",22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"check","check",22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"check","check",22,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"check","check",22,1);
      sf_mark_chart_reusable_outputs(S,"check","check",22,1);
    }

    sf_set_rtw_dwork_info(S,"check","check",22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4081611206U));
  ssSetChecksum1(S,(3541410612U));
  ssSetChecksum2(S,(856416405U));
  ssSetChecksum3(S,(740353260U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c22_check(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "check", "check",22);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_check(SimStruct *S)
{
  SFc22_checkInstanceStruct *chartInstance;
  chartInstance = (SFc22_checkInstanceStruct *)malloc(sizeof
    (SFc22_checkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_checkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_check;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c22_check;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_check;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_check;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_check;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c22_check;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c22_check;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c22_check;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_check;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_check;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_check;
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

void c22_check_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_check(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_check(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_check(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_check_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
