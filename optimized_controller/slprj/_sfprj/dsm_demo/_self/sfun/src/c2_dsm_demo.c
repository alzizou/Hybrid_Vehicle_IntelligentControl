/* Include files */

#include "blascompat32.h"
#include "dsm_demo_sfun.h"
#include "c2_dsm_demo.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dsm_demo_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[4] = { "nargin", "nargout", "y", "A" };

/* Function Declarations */
static void initialize_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance);
static void initialize_params_c2_dsm_demo(SFc2_dsm_demoInstanceStruct
  *chartInstance);
static void enable_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance);
static void disable_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_dsm_demo(SFc2_dsm_demoInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_dsm_demo(SFc2_dsm_demoInstanceStruct
  *chartInstance);
static void set_sim_state_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance);
static void sf_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance);
static void initSimStructsc2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_A, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_dsm_demo, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static real_T c2_get_A(SFc2_dsm_demoInstanceStruct *chartInstance, uint32_T c2_b);
static void c2_set_A(SFc2_dsm_demoInstanceStruct *chartInstance, uint32_T c2_b,
                     real_T c2_c);
static real_T *c2_access_A(SFc2_dsm_demoInstanceStruct *chartInstance, uint32_T
  c2_b);
static void init_dsm_address_info(SFc2_dsm_demoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_dsm_demo = 0U;
}

static void initialize_params_c2_dsm_demo(SFc2_dsm_demoInstanceStruct
  *chartInstance)
{
}

static void enable_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_dsm_demo(SFc2_dsm_demoInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_dsm_demo(SFc2_dsm_demoInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_d_y;
  c2_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_d_y;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_dsm_demo;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "y");
  chartInstance->c2_is_active_c2_dsm_demo = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_dsm_demo");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_dsm_demo(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance)
{
}

static void sf_c2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  real_T c2_y;
  real_T *c2_b_y;
  c2_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_y, 0U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_y, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_A_address, 3U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_set_A(chartInstance, 0, c2_get_A(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_y = c2_get_A(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c2_b_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_dsm_demoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_dsm_demo(SFc2_dsm_demoInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_dsm_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_dsm_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_A, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_A), &c2_thisId);
  sf_mex_destroy(&c2_A);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_A;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_dsm_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_dsm_demoInstanceStruct *)chartInstanceVoid;
  c2_A = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_A), &c2_thisId);
  sf_mex_destroy(&c2_A);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_dsm_demo_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_dsm_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_dsm_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_dsm_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_dsm_demoInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_dsm_demo, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_dsm_demo), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_dsm_demo);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_dsm_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static real_T c2_get_A(SFc2_dsm_demoInstanceStruct *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_A_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'A\' (#67) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_A_address;
}

static void c2_set_A(SFc2_dsm_demoInstanceStruct *chartInstance, uint32_T c2_b,
                     real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_A_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'A\' (#67) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_A_address = c2_c;
}

static real_T *c2_access_A(SFc2_dsm_demoInstanceStruct *chartInstance, uint32_T
  c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c2_A_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'A\' (#67) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_A_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c2_c;
}

static void init_dsm_address_info(SFc2_dsm_demoInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "A", (void **)
    &chartInstance->c2_A_address, &chartInstance->c2_A_index);
}

/* SFunction Glue Code */
void sf_c2_dsm_demo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4105422056U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3869751150U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(597467548U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3410486201U);
}

mxArray *sf_c2_dsm_demo_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(516357026U);
    pr[1] = (double)(2803553710U);
    pr[2] = (double)(472893459U);
    pr[3] = (double)(99258436U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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

static const mxArray *sf_get_sim_state_info_c2_dsm_demo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_dsm_demo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_dsm_demo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_dsm_demoInstanceStruct *chartInstance;
    chartInstance = (SFc2_dsm_demoInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_dsm_demoMachineNumber_,
          2,
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
          init_script_number_translation(_dsm_demoMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_dsm_demoMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_dsm_demoMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
          _SFD_SET_DATA_PROPS(1,11,0,0,"A");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,53);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_y;
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_A_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_dsm_demoMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_dsm_demo(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_dsm_demoInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
  initialize_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_dsm_demo(void *chartInstanceVar)
{
  enable_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_dsm_demo(void *chartInstanceVar)
{
  disable_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_dsm_demo(void *chartInstanceVar)
{
  sf_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_dsm_demo(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_dsm_demo();/* state var info */
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

extern void sf_internal_set_sim_state_c2_dsm_demo(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_dsm_demo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_dsm_demo(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_dsm_demo(S);
}

static void sf_opaque_set_sim_state_c2_dsm_demo(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_dsm_demo(S, st);
}

static void sf_opaque_terminate_c2_dsm_demo(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_dsm_demoInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_dsm_demo((SFc2_dsm_demoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_dsm_demo(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_dsm_demo((SFc2_dsm_demoInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_dsm_demo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"dsm_demo","dsm_demo",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"dsm_demo","dsm_demo",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"dsm_demo","dsm_demo",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"dsm_demo","dsm_demo",2,1);
    }

    sf_set_rtw_dwork_info(S,"dsm_demo","dsm_demo",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(138172540U));
  ssSetChecksum1(S,(1905815313U));
  ssSetChecksum2(S,(2439842788U));
  ssSetChecksum3(S,(1579249728U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_dsm_demo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "dsm_demo", "dsm_demo",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_dsm_demo(SimStruct *S)
{
  SFc2_dsm_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_dsm_demoInstanceStruct *)malloc(sizeof
    (SFc2_dsm_demoInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_dsm_demoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_dsm_demo;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_dsm_demo;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_dsm_demo;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_dsm_demo;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_dsm_demo;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_dsm_demo;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_dsm_demo;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_dsm_demo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_dsm_demo;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_dsm_demo;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_dsm_demo;
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

void c2_dsm_demo_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_dsm_demo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_dsm_demo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_dsm_demo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_dsm_demo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
