/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_sfun.h"
#include "c4_hyd_hyb_2_int_cont.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0U)
#define c4_IN_state1                   (1U)
#define c4_IN_state2                   (2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance);
static void initialize_params_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance);
static void enable_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance);
static void disable_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct *
  chartInstance);
static void c4_update_debugger_state_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance);
static void set_sim_state_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance);
static void finalize_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance);
static void sf_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance);
static void initSimStructsc4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static int32_T c4_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_b_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_state1, const char_T *c4_identifier);
static uint8_T c4_c_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_d_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u1, const char_T *c4_identifier);
static real_T c4_e_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_emlrt_marshallIn
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance, const mxArray
   *c4_b_setSimStateSideEffectsInfo, const char_T *c4_identifier);
static const mxArray *c4_g_emlrt_marshallIn
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance, const mxArray *c4_u,
   const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance)
{
  real_T *c4_u1;
  c4_u1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_state1 = 0U;
  chartInstance->c4_tp_state2 = 0U;
  chartInstance->c4_is_active_c4_hyd_hyb_2_int_cont = 0U;
  chartInstance->c4_is_c4_hyd_hyb_2_int_cont = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c4_u1 = 0.0;
  }
}

static void initialize_params_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance)
{
}

static void enable_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c4_is_active_c4_hyd_hyb_2_int_cont == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_hyd_hyb_2_int_cont == c4_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_hyd_hyb_2_int_cont == c4_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  }

  sf_debug_set_animation(c4_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T *c4_u1;
  c4_u1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(3));
  c4_hoistedGlobal = *c4_u1;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_active_c4_hyd_hyb_2_int_cont;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_c4_hyd_hyb_2_int_cont;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_u1;
  c4_u1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = sf_mex_dup(c4_st);
  *c4_u1 = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    0)), "u1");
  chartInstance->c4_is_active_c4_hyd_hyb_2_int_cont = c4_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_hyd_hyb_2_int_cont");
  chartInstance->c4_is_c4_hyd_hyb_2_int_cont = c4_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
     "is_c4_hyd_hyb_2_int_cont");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 3)), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_hyd_hyb_2_int_cont(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_hyd_hyb_2_int_cont == c4_IN_state1) {
      chartInstance->c4_tp_state1 = 1U;
    } else {
      chartInstance->c4_tp_state1 = 0U;
    }

    if (chartInstance->c4_is_c4_hyd_hyb_2_int_cont == c4_IN_state2) {
      chartInstance->c4_tp_state2 = 1U;
    } else {
      chartInstance->c4_tp_state2 = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_c4_hyd_hyb_2_int_cont(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance)
{
  real_T *c4_soc;
  real_T *c4_soc_min;
  real_T *c4_u1;
  c4_u1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_soc_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_set_sim_state_side_effects_c4_hyd_hyb_2_int_cont(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_soc, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_soc_min, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_u1, 2U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  if ((int16_T)chartInstance->c4_is_active_c4_hyd_hyb_2_int_cont == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_active_c4_hyd_hyb_2_int_cont = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_hyd_hyb_2_int_cont = c4_IN_state1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_state1 = 1U;
  } else {
    switch (chartInstance->c4_is_c4_hyd_hyb_2_int_cont) {
     case c4_IN_state1:
      CV_CHART_EVAL(3, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c4_sfEvent);
      if (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0, *c4_soc <=
            *c4_soc_min != 0U, chartInstance->c4_sfEvent))) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_state1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_hyd_hyb_2_int_cont = c4_IN_state2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_state2 = 1U;
      } else {
        *c4_u1 = 1.0;
        _SFD_DATA_RANGE_CHECK(*c4_u1, 2U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
      break;

     case c4_IN_state2:
      CV_CHART_EVAL(3, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c4_sfEvent);
      if (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0, *c4_soc > 50.0 !=
            0U, chartInstance->c4_sfEvent))) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_state2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_hyd_hyb_2_int_cont = c4_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_state1 = 1U;
      } else {
        *c4_u1 = 0.0;
        _SFD_DATA_RANGE_CHECK(*c4_u1, 2U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
      break;

     default:
      CV_CHART_EVAL(3, 0, 0);
      chartInstance->c4_is_c4_hyd_hyb_2_int_cont = (uint8_T)
        c4_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_hyd_hyb_2_int_contMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_hyd_hyb_2_int_cont
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

const mxArray *sf_c4_hyd_hyb_2_int_cont_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c4_nameCaptureInfo;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static int32_T c4_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i0, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent), &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static uint8_T c4_b_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_state1, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_state1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_state1);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_state1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)chartInstanceVoid;
  c4_b_tp_state1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_state1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_state1);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static real_T c4_d_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u1, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_u1), &c4_thisId);
  sf_mex_destroy(&c4_u1);
  return c4_y;
}

static real_T c4_e_emlrt_marshallIn(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_u1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)chartInstanceVoid;
  c4_u1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_u1), &c4_thisId);
  sf_mex_destroy(&c4_u1);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_emlrt_marshallIn
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance, const mxArray
   *c4_b_setSimStateSideEffectsInfo, const char_T *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  sf_mex_assign(&c4_y, c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId));
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_g_emlrt_marshallIn
  (SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance, const mxArray *c4_u,
   const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u));
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_hyd_hyb_2_int_contInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_hyd_hyb_2_int_cont_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2836072433U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3946134574U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4276640664U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(480290231U);
}

mxArray *sf_c4_hyd_hyb_2_int_cont_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3702837997U);
    pr[1] = (double)(3562582795U);
    pr[2] = (double)(1791540868U);
    pr[3] = (double)(2924337730U);
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

static const mxArray *sf_get_sim_state_info_c4_hyd_hyb_2_int_cont(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[15],T\"u1\",},{M[8],M[0],T\"is_active_c4_hyd_hyb_2_int_cont\",},{M[9],M[0],T\"is_c4_hyd_hyb_2_int_cont\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_hyd_hyb_2_int_cont_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
    chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_contMachineNumber_,
           4,
           2,
           3,
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
          init_script_number_translation(_hyd_hyb_2_int_contMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_contMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_hyd_hyb_2_int_contMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"soc");
          _SFD_SET_DATA_PROPS(1,1,1,0,"soc_min");
          _SFD_SET_DATA_PROPS(2,2,0,1,"u1");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);

        {
          real_T *c4_soc;
          real_T *c4_soc_min;
          real_T *c4_u1;
          c4_u1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_soc_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_soc);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_soc_min);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_u1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_contMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_hyd_hyb_2_int_cont(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar);
  initialize_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_hyd_hyb_2_int_cont(void *chartInstanceVar)
{
  enable_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_hyd_hyb_2_int_cont(void *chartInstanceVar)
{
  disable_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_hyd_hyb_2_int_cont(void *chartInstanceVar)
{
  sf_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_hyd_hyb_2_int_cont(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_hyd_hyb_2_int_cont
    ((SFc4_hyd_hyb_2_int_contInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_hyd_hyb_2_int_cont();/* state var info */
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

extern void sf_internal_set_sim_state_c4_hyd_hyb_2_int_cont(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_hyd_hyb_2_int_cont();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_hyd_hyb_2_int_cont(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_hyd_hyb_2_int_cont(S);
}

static void sf_opaque_set_sim_state_c4_hyd_hyb_2_int_cont(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_hyd_hyb_2_int_cont(S, st);
}

static void sf_opaque_terminate_c4_hyd_hyb_2_int_cont(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_hyd_hyb_2_int_contInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_hyd_hyb_2_int_cont((SFc4_hyd_hyb_2_int_contInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_hyd_hyb_2_int_cont(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_hyd_hyb_2_int_cont
      ((SFc4_hyd_hyb_2_int_contInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_hyd_hyb_2_int_cont(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont","hyd_hyb_2_int_cont",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_int_cont",
                "hyd_hyb_2_int_cont",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_int_cont",
      "hyd_hyb_2_int_cont",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_int_cont",
        "hyd_hyb_2_int_cont",4,2);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_int_cont","hyd_hyb_2_int_cont",
        4,1);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont","hyd_hyb_2_int_cont",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3013430905U));
  ssSetChecksum1(S,(1130739606U));
  ssSetChecksum2(S,(1415367947U));
  ssSetChecksum3(S,(715278656U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_hyd_hyb_2_int_cont(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont", "hyd_hyb_2_int_cont",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_hyd_hyb_2_int_cont(SimStruct *S)
{
  SFc4_hyd_hyb_2_int_contInstanceStruct *chartInstance;
  chartInstance = (SFc4_hyd_hyb_2_int_contInstanceStruct *)malloc(sizeof
    (SFc4_hyd_hyb_2_int_contInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_hyd_hyb_2_int_contInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_hyd_hyb_2_int_cont;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_hyd_hyb_2_int_cont;
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

void c4_hyd_hyb_2_int_cont_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_hyd_hyb_2_int_cont(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_hyd_hyb_2_int_cont(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_hyd_hyb_2_int_cont(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_hyd_hyb_2_int_cont_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
