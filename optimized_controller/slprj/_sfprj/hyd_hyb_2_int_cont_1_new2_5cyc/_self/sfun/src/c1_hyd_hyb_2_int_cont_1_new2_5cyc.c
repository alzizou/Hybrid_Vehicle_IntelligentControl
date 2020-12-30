/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_int_cont_1_new2_5cyc_sfun.h"
#include "c1_hyd_hyb_2_int_cont_1_new2_5cyc.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_1_new2_5cyc_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0U)
#define c1_IN_Drive                    (1U)
#define c1_IN_Neutral                  (2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void initialize_params_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void enable_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void disable_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void finalize_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void initSimStructsc1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_b_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_Drive, const char_T *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_d_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_s, const char_T *c1_identifier);
static real_T c1_e_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint32_T c1_f_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_b_previousTicks, const char_T *c1_identifier);
static uint32_T c1_g_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_h_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_i_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  real_T *c1_s;
  c1_s = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_Drive = 0U;
  chartInstance->c1_tp_Neutral = 0U;
  chartInstance->c1_is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc = 0U;
  chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_s = 0.0;
  }

  chartInstance->c1_presentTicks = 0U;
  chartInstance->c1_elapsedTicks = 0U;
  chartInstance->c1_previousTicks = 0U;
}

static void initialize_params_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
}

static void enable_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  real_T c1_d0;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c1_d0 = muDoubleScalarFloor(_sfTime_ / 0.01 + 0.5);
  chartInstance->c1_presentTicks = (uint32_T)c1_d0;
  chartInstance->c1_previousTicks = chartInstance->c1_presentTicks;
}

static void disable_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  real_T c1_d1;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c1_d1 = muDoubleScalarFloor(_sfTime_ / 0.01 + 0.5);
  chartInstance->c1_presentTicks = (uint32_T)c1_d1;
  chartInstance->c1_elapsedTicks = chartInstance->c1_presentTicks -
    chartInstance->c1_previousTicks;
  chartInstance->c1_previousTicks = chartInstance->c1_presentTicks;
  if ((uint32_T)chartInstance->c1_temporalCounter_i1 +
      chartInstance->c1_elapsedTicks <= 127U) {
    chartInstance->c1_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c1_temporalCounter_i1 + chartInstance->c1_elapsedTicks);
  } else {
    chartInstance->c1_temporalCounter_i1 = 127U;
  }
}

static void c1_update_debugger_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c1_is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc ==
      1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc == c1_IN_Drive) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc == c1_IN_Neutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint32_T c1_e_hoistedGlobal;
  uint32_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T *c1_s;
  c1_s = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(5));
  c1_hoistedGlobal = *c1_s;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal =
    chartInstance->c1_is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_previousTicks;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 7, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_s;
  c1_s = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_s = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "s");
  chartInstance->c1_is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc =
    c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc");
  chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_c1_hyd_hyb_2_int_cont_1_new2_5cyc");
  chartInstance->c1_temporalCounter_i1 = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)), "temporalCounter_i1");
  chartInstance->c1_previousTicks = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc == c1_IN_Drive) {
      chartInstance->c1_tp_Drive = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_Drive = 0U;
    }

    if (chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc == c1_IN_Neutral)
    {
      chartInstance->c1_tp_Neutral = 1U;
    } else {
      chartInstance->c1_tp_Neutral = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
  real_T c1_d2;
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  real_T *c1_cyc;
  real_T *c1_speed;
  real_T *c1_s;
  c1_s = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_speed = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_cyc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_hyd_hyb_2_int_cont_1_new2_5cyc(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c1_d2 = muDoubleScalarFloor(_sfTime_ / 0.01 + 0.5);
  chartInstance->c1_presentTicks = (uint32_T)c1_d2;
  chartInstance->c1_elapsedTicks = chartInstance->c1_presentTicks -
    chartInstance->c1_previousTicks;
  chartInstance->c1_previousTicks = chartInstance->c1_presentTicks;
  if ((uint32_T)chartInstance->c1_temporalCounter_i1 +
      chartInstance->c1_elapsedTicks <= 127U) {
    chartInstance->c1_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c1_temporalCounter_i1 + chartInstance->c1_elapsedTicks);
  } else {
    chartInstance->c1_temporalCounter_i1 = 127U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_cyc, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_speed, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_s, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if ((int16_T)chartInstance->c1_is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc ==
      0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc = c1_IN_Neutral;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_Neutral = 1U;
  } else {
    switch (chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc) {
     case c1_IN_Drive:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c1_sfEvent);
      c1_temp = (_SFD_CCP_CALL(2U, 0, 1 != 0U, chartInstance->c1_sfEvent) != 0);
      if (c1_temp) {
        c1_temp = (_SFD_CCP_CALL(2U, 1, (uint32_T)
                    chartInstance->c1_temporalCounter_i1 >= 100U != 0U,
                    chartInstance->c1_sfEvent) != 0);
      }

      c1_b_temp = c1_temp;
      if (c1_b_temp) {
        c1_b_temp = (_SFD_CCP_CALL(2U, 2, *c1_cyc == 0.0 != 0U,
          chartInstance->c1_sfEvent) != 0);
      }

      if (CV_TRANSITION_EVAL(2U, (int32_T)c1_b_temp)) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Drive = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc = c1_IN_Neutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Neutral = 1U;
      } else {
        *c1_s = 1.0;
        _SFD_DATA_RANGE_CHECK(*c1_s, 2U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_Neutral:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      if (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0, *c1_cyc > 0.0 !=
            0U, chartInstance->c1_sfEvent))) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Neutral = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc = c1_IN_Drive;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_Drive = 1U;
      } else {
        *c1_s = 0.0;
        _SFD_DATA_RANGE_CHECK(*c1_s, 2U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_hyd_hyb_2_int_cont_1_new2_5cyc = (uint8_T)
        c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_int_cont_1_new2_5cycMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray
  *sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static uint8_T c1_b_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_Drive, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Drive),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Drive);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_Drive;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
    chartInstanceVoid;
  c1_b_tp_Drive = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Drive),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Drive);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_d_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_s, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_s), &c1_thisId);
  sf_mex_destroy(&c1_s);
  return c1_y;
}

static real_T c1_e_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d3;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d3, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_s;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
    chartInstanceVoid;
  c1_s = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_s), &c1_thisId);
  sf_mex_destroy(&c1_s);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_f_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_b_previousTicks, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_previousTicks),
    &c1_thisId);
  sf_mex_destroy(&c1_b_previousTicks);
  return c1_y;
}

static uint32_T c1_g_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_h_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId));
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_i_emlrt_marshallIn
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u));
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1433732874U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(937776961U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3361339596U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2061977946U);
}

mxArray *sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc_get_autoinheritance_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[9],T\"s\",},{M[8],M[0],T\"is_active_c1_hyd_hyb_2_int_cont_1_new2_5cyc\",},{M[9],M[0],T\"is_c1_hyd_hyb_2_int_cont_1_new2_5cyc\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[2],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
    chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_int_cont_1_new2_5cycMachineNumber_,
           1,
           3,
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
          init_script_number_translation
            (_hyd_hyb_2_int_cont_1_new2_5cycMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_int_cont_1_new2_5cycMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_int_cont_1_new2_5cycMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"cyc");
          _SFD_SET_DATA_PROPS(1,1,1,0,"speed");
          _SFD_SET_DATA_PROPS(2,2,0,1,"s");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 8, 0, 13 };

          static unsigned int sEndGuardMap[] = { 11, 12, 20 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(2,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
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

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 8, 0, 13 };

          static unsigned int sEndGuardMap[] = { 11, 12, 20 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);

        {
          real_T *c1_cyc;
          real_T *c1_speed;
          real_T *c1_s;
          c1_s = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_speed = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_cyc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_cyc);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_speed);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_s);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_int_cont_1_new2_5cycMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_hyd_hyb_2_int_cont_1_new2_5cyc(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
  initialize_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_hyd_hyb_2_int_cont_1_new2_5cyc(void
  *chartInstanceVar)
{
  enable_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_hyd_hyb_2_int_cont_1_new2_5cyc(void
  *chartInstanceVar)
{
  disable_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_hyd_hyb_2_int_cont_1_new2_5cyc(void
  *chartInstanceVar)
{
  sf_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_hyd_hyb_2_int_cont_1_new2_5cyc();/* state var info */
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

extern void sf_internal_set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_hyd_hyb_2_int_cont_1_new2_5cyc();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc(S);
}

static void sf_opaque_set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc(S, st);
}

static void sf_opaque_terminate_c1_hyd_hyb_2_int_cont_1_new2_5cyc(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_hyd_hyb_2_int_cont_1_new2_5cyc
      ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_hyd_hyb_2_int_cont_1_new2_5cyc
    ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_hyd_hyb_2_int_cont_1_new2_5cyc(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_hyd_hyb_2_int_cont_1_new2_5cyc
      ((SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_hyd_hyb_2_int_cont_1_new2_5cyc(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_int_cont_1_new2_5cyc",
      "hyd_hyb_2_int_cont_1_new2_5cyc",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_int_cont_1_new2_5cyc",
                "hyd_hyb_2_int_cont_1_new2_5cyc",1,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_int_cont_1_new2_5cyc","hyd_hyb_2_int_cont_1_new2_5cyc",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_int_cont_1_new2_5cyc",
        "hyd_hyb_2_int_cont_1_new2_5cyc",1,2);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_int_cont_1_new2_5cyc",
        "hyd_hyb_2_int_cont_1_new2_5cyc",1,1);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_int_cont_1_new2_5cyc",
                          "hyd_hyb_2_int_cont_1_new2_5cyc",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2880509111U));
  ssSetChecksum1(S,(2320925475U));
  ssSetChecksum2(S,(2137600348U));
  ssSetChecksum3(S,(2858031611U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_hyd_hyb_2_int_cont_1_new2_5cyc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_int_cont_1_new2_5cyc",
      "hyd_hyb_2_int_cont_1_new2_5cyc",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_hyd_hyb_2_int_cont_1_new2_5cyc(SimStruct *S)
{
  SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *chartInstance;
  chartInstance = (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct *)malloc
    (sizeof(SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_hyd_hyb_2_int_cont_1_new2_5cycInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_hyd_hyb_2_int_cont_1_new2_5cyc;
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

void c1_hyd_hyb_2_int_cont_1_new2_5cyc_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_hyd_hyb_2_int_cont_1_new2_5cyc(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_hyd_hyb_2_int_cont_1_new2_5cyc(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_hyd_hyb_2_int_cont_1_new2_5cyc(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_hyd_hyb_2_int_cont_1_new2_5cyc_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
