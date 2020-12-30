/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_fst_con_sfun.h"
#include "c5_hyd_hyb_2_fst_con.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_fst_con_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD          (0U)
#define c5_IN_state1                   (1U)
#define c5_IN_state2                   (2U)
#define c5_IN_state3                   (3U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance);
static void initialize_params_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance);
static void enable_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance);
static void disable_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance);
static void set_sim_state_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance, const mxArray *c5_st);
static void c5_set_sim_state_side_effects_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance);
static void finalize_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance);
static void sf_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance);
static void c5_chartstep_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance);
static void initSimStructsc5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static int32_T c5_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static uint8_T c5_b_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_b_tp_state1, const char_T *c5_identifier);
static uint8_T c5_c_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier);
static const mxArray *c5_e_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance)
{
  uint8_T *c5_u1;
  uint8_T *c5_u2;
  uint8_T *c5_u3;
  uint8_T *c5_u4;
  c5_u4 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_u3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_u2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_u1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_doSetSimStateSideEffects = 0U;
  chartInstance->c5_setSimStateSideEffectsInfo = NULL;
  chartInstance->c5_tp_state1 = 0U;
  chartInstance->c5_tp_state2 = 0U;
  chartInstance->c5_tp_state3 = 0U;
  chartInstance->c5_is_active_c5_hyd_hyb_2_fst_con = 0U;
  chartInstance->c5_is_c5_hyd_hyb_2_fst_con = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c5_u1 = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c5_u2 = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c5_u3 = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 4) != 0)) {
    *c5_u4 = 0U;
  }
}

static void initialize_params_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance)
{
}

static void enable_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance)
{
  uint32_T c5_prevAniVal;
  c5_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c5_is_active_c5_hyd_hyb_2_fst_con == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_fst_con == c5_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_fst_con == c5_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_fst_con == c5_IN_state3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  }

  sf_debug_set_animation(c5_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  uint8_T c5_d_hoistedGlobal;
  uint8_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  uint8_T c5_e_hoistedGlobal;
  uint8_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  uint8_T c5_f_hoistedGlobal;
  uint8_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  uint8_T *c5_u1;
  uint8_T *c5_u2;
  uint8_T *c5_u3;
  uint8_T *c5_u4;
  c5_u4 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_u3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_u2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_u1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(6));
  c5_hoistedGlobal = *c5_u1;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_u2;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_u3;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = *c5_u4;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = chartInstance->c5_is_active_c5_hyd_hyb_2_fst_con;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_f_hoistedGlobal = chartInstance->c5_is_c5_hyd_hyb_2_fst_con;
  c5_f_u = c5_f_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 5, c5_g_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  uint8_T *c5_u1;
  uint8_T *c5_u2;
  uint8_T *c5_u3;
  uint8_T *c5_u4;
  c5_u4 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_u3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_u2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_u1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_u = sf_mex_dup(c5_st);
  *c5_u1 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    0)), "u1");
  *c5_u2 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    1)), "u2");
  *c5_u3 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    2)), "u3");
  *c5_u4 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    3)), "u4");
  chartInstance->c5_is_active_c5_hyd_hyb_2_fst_con = c5_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 4)),
     "is_active_c5_hyd_hyb_2_fst_con");
  chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 5)),
     "is_c5_hyd_hyb_2_fst_con");
  sf_mex_assign(&chartInstance->c5_setSimStateSideEffectsInfo,
                c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 6)), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c5_u);
  chartInstance->c5_doSetSimStateSideEffects = 1U;
  c5_update_debugger_state_c5_hyd_hyb_2_fst_con(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void c5_set_sim_state_side_effects_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance)
{
  if (chartInstance->c5_doSetSimStateSideEffects != 0) {
    if (chartInstance->c5_is_c5_hyd_hyb_2_fst_con == c5_IN_state1) {
      chartInstance->c5_tp_state1 = 1U;
    } else {
      chartInstance->c5_tp_state1 = 0U;
    }

    if (chartInstance->c5_is_c5_hyd_hyb_2_fst_con == c5_IN_state2) {
      chartInstance->c5_tp_state2 = 1U;
    } else {
      chartInstance->c5_tp_state2 = 0U;
    }

    if (chartInstance->c5_is_c5_hyd_hyb_2_fst_con == c5_IN_state3) {
      chartInstance->c5_tp_state3 = 1U;
    } else {
      chartInstance->c5_tp_state3 = 0U;
    }

    chartInstance->c5_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c5_setSimStateSideEffectsInfo);
}

static void sf_c5_hyd_hyb_2_fst_con(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance)
{
  uint8_T *c5_u1;
  uint8_T *c5_u2;
  uint8_T *c5_u3;
  uint8_T *c5_u4;
  real_T *c5_SOC;
  real_T *c5_veh_spd_actu;
  real_T *c5_T_acc;
  real_T *c5_SOC_min;
  c5_SOC_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_veh_spd_actu = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_SOC = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_u4 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_u3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_u2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_u1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_set_sim_state_side_effects_c5_hyd_hyb_2_fst_con(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c5_u1, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c5_u2, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c5_u3, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c5_u4, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_SOC, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_veh_spd_actu, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_T_acc, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_SOC_min, 7U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_hyd_hyb_2_fst_con(chartInstance);
  sf_debug_check_for_state_inconsistency(_hyd_hyb_2_fst_conMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance)
{
  boolean_T c5_temp;
  boolean_T c5_b_temp;
  boolean_T c5_c_temp;
  real_T *c5_veh_spd_actu;
  real_T *c5_SOC;
  real_T *c5_SOC_min;
  uint8_T *c5_u1;
  uint8_T *c5_u2;
  uint8_T *c5_u3;
  uint8_T *c5_u4;
  c5_SOC_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_veh_spd_actu = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_SOC = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_u4 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_u3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_u2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_u1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  if ((int16_T)chartInstance->c5_is_active_c5_hyd_hyb_2_fst_con == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_active_c5_hyd_hyb_2_fst_con = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_state1 = 1U;
  } else {
    switch (chartInstance->c5_is_c5_hyd_hyb_2_fst_con) {
     case c5_IN_state1:
      CV_CHART_EVAL(3, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c5_sfEvent);
      if (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0, *c5_veh_spd_actu >
            30.0 != 0U, chartInstance->c5_sfEvent))) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 1;
          sf_debug_transition_conflict_check_begin();
          if (*c5_SOC <= *c5_SOC_min) {
            transitionList[numTransitions] = 5;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state2 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c5_sfEvent);
        if (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0, *c5_SOC <=
              *c5_SOC_min != 0U, chartInstance->c5_sfEvent))) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state3 = 1U;
        } else {
          *c5_u1 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u1, 0U);
          *c5_u2 = 1U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u2, 1U);
          *c5_u3 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u3, 2U);
          *c5_u4 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u4, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
      break;

     case c5_IN_state2:
      CV_CHART_EVAL(3, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c5_sfEvent);
      c5_temp = (_SFD_CCP_CALL(2U, 0, *c5_veh_spd_actu <= 30.0 != 0U,
                  chartInstance->c5_sfEvent) != 0);
      if (c5_temp) {
        c5_temp = (_SFD_CCP_CALL(2U, 1, *c5_SOC > *c5_SOC_min != 0U,
                    chartInstance->c5_sfEvent) != 0);
      }

      if (CV_TRANSITION_EVAL(2U, (int32_T)c5_temp)) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 2;
          sf_debug_transition_conflict_check_begin();
          if (*c5_SOC <= *c5_SOC_min) {
            transitionList[numTransitions] = 3;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c5_sfEvent);
        if (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0, *c5_SOC <=
              *c5_SOC_min != 0U, chartInstance->c5_sfEvent))) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state3 = 1U;
        } else {
          *c5_u1 = 1U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u1, 0U);
          *c5_u2 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u2, 1U);
          *c5_u3 = 1U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u3, 2U);
          *c5_u4 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u4, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
      break;

     case c5_IN_state3:
      CV_CHART_EVAL(3, 0, 3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c5_sfEvent);
      c5_b_temp = (_SFD_CCP_CALL(4U, 0, *c5_SOC >= 100.0 != 0U,
        chartInstance->c5_sfEvent) != 0);
      if (c5_b_temp) {
        c5_b_temp = (_SFD_CCP_CALL(4U, 1, *c5_veh_spd_actu > 30.0 != 0U,
          chartInstance->c5_sfEvent) != 0);
      }

      if (CV_TRANSITION_EVAL(4U, (int32_T)c5_b_temp)) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 4;
          sf_debug_transition_conflict_check_begin();
          if ((*c5_SOC >= 100.0) && (*c5_veh_spd_actu <= 30.0)) {
            transitionList[numTransitions] = 6;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state2 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c5_sfEvent);
        c5_c_temp = (_SFD_CCP_CALL(6U, 0, *c5_SOC >= 100.0 != 0U,
          chartInstance->c5_sfEvent) != 0);
        if (c5_c_temp) {
          c5_c_temp = (_SFD_CCP_CALL(6U, 1, *c5_veh_spd_actu <= 30.0 != 0U,
            chartInstance->c5_sfEvent) != 0);
        }

        if (CV_TRANSITION_EVAL(6U, (int32_T)c5_c_temp)) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_c5_hyd_hyb_2_fst_con = c5_IN_state1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state1 = 1U;
        } else {
          *c5_u1 = 1U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u1, 0U);
          *c5_u2 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u2, 1U);
          *c5_u3 = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u3, 2U);
          *c5_u4 = 1U;
          _SFD_DATA_RANGE_CHECK((real_T)*c5_u4, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
      break;

     default:
      CV_CHART_EVAL(3, 0, 0);
      chartInstance->c5_is_c5_hyd_hyb_2_fst_con = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_hyd_hyb_2_fst_con
  (SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

const mxArray *sf_c5_hyd_hyb_2_fst_con_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c5_nameCaptureInfo;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static int32_T c5_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i0, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent), &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  uint8_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(uint8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static uint8_T c5_b_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_b_tp_state1, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_state1),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_state1);
  return c5_y;
}

static uint8_T c5_c_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_tp_state1;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *)chartInstanceVoid;
  c5_b_tp_state1 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_state1),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_state1);
  *(uint8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier)
{
  const mxArray *c5_y = NULL;
  emlrtMsgIdentifier c5_thisId;
  c5_y = NULL;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  sf_mex_assign(&c5_y, c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_setSimStateSideEffectsInfo), &c5_thisId));
  sf_mex_destroy(&c5_b_setSimStateSideEffectsInfo);
  return c5_y;
}

static const mxArray *c5_e_emlrt_marshallIn(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u));
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_hyd_hyb_2_fst_conInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_hyd_hyb_2_fst_con_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(407833360U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2379230371U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3271189880U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2885223249U);
}

mxArray *sf_c5_hyd_hyb_2_fst_con_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3316273213U);
    pr[1] = (double)(1652504681U);
    pr[2] = (double)(1045751945U);
    pr[3] = (double)(3610059352U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_hyd_hyb_2_fst_con(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"u1\",},{M[1],M[6],T\"u2\",},{M[1],M[7],T\"u3\",},{M[1],M[8],T\"u4\",},{M[8],M[0],T\"is_active_c5_hyd_hyb_2_fst_con\",},{M[9],M[0],T\"is_c5_hyd_hyb_2_fst_con\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_hyd_hyb_2_fst_con_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
    chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_fst_conMachineNumber_,
           5,
           3,
           7,
           8,
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
          init_script_number_translation(_hyd_hyb_2_fst_conMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_fst_conMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_hyd_hyb_2_fst_conMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"u3");
          _SFD_SET_DATA_PROPS(3,2,0,1,"u4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"SOC");
          _SFD_SET_DATA_PROPS(5,1,1,0,"veh_spd_actu");
          _SFD_SET_DATA_PROPS(6,1,1,0,"T_acc");
          _SFD_SET_DATA_PROPS(7,1,1,0,"SOC_min");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 13 };

          static unsigned int sEndGuardMap[] = { 9, 28 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 21 };

          static unsigned int sEndGuardMap[] = { 17, 32 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 13 };

          static unsigned int sEndGuardMap[] = { 9, 29 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(6,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
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

          static unsigned int sEndGuardMap[] = { 16 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 13 };

          static unsigned int sEndGuardMap[] = { 9, 28 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 21 };

          static unsigned int sEndGuardMap[] = { 17, 32 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 13 };

          static unsigned int sEndGuardMap[] = { 9, 29 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint8_T *c5_u1;
          uint8_T *c5_u2;
          uint8_T *c5_u3;
          uint8_T *c5_u4;
          real_T *c5_SOC;
          real_T *c5_veh_spd_actu;
          real_T *c5_T_acc;
          real_T *c5_SOC_min;
          c5_SOC_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_veh_spd_actu = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_SOC = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_u4 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c5_u3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_u2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_u1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_u2);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_u3);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_u4);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_SOC);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_veh_spd_actu);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_T_acc);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_SOC_min);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_fst_conMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_hyd_hyb_2_fst_con(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar);
  initialize_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_hyd_hyb_2_fst_con(void *chartInstanceVar)
{
  enable_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_hyd_hyb_2_fst_con(void *chartInstanceVar)
{
  disable_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_hyd_hyb_2_fst_con(void *chartInstanceVar)
{
  sf_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_hyd_hyb_2_fst_con(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_hyd_hyb_2_fst_con
    ((SFc5_hyd_hyb_2_fst_conInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_hyd_hyb_2_fst_con();/* state var info */
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

extern void sf_internal_set_sim_state_c5_hyd_hyb_2_fst_con(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_hyd_hyb_2_fst_con();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_hyd_hyb_2_fst_con(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_hyd_hyb_2_fst_con(S);
}

static void sf_opaque_set_sim_state_c5_hyd_hyb_2_fst_con(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_hyd_hyb_2_fst_con(S, st);
}

static void sf_opaque_terminate_c5_hyd_hyb_2_fst_con(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_hyd_hyb_2_fst_conInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_hyd_hyb_2_fst_con(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_hyd_hyb_2_fst_con((SFc5_hyd_hyb_2_fst_conInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_hyd_hyb_2_fst_con(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_fst_con","hyd_hyb_2_fst_con",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_fst_con","hyd_hyb_2_fst_con",
                5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_fst_con",
      "hyd_hyb_2_fst_con",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_fst_con",
        "hyd_hyb_2_fst_con",5,4);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_fst_con","hyd_hyb_2_fst_con",5,
        4);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_fst_con","hyd_hyb_2_fst_con",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(641360409U));
  ssSetChecksum1(S,(1862450041U));
  ssSetChecksum2(S,(2960510684U));
  ssSetChecksum3(S,(311516044U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_hyd_hyb_2_fst_con(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_fst_con", "hyd_hyb_2_fst_con",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c5_hyd_hyb_2_fst_con(SimStruct *S)
{
  SFc5_hyd_hyb_2_fst_conInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_fst_conInstanceStruct *)malloc(sizeof
    (SFc5_hyd_hyb_2_fst_conInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_hyd_hyb_2_fst_conInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_hyd_hyb_2_fst_con;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_hyd_hyb_2_fst_con;
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

void c5_hyd_hyb_2_fst_con_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_hyd_hyb_2_fst_con(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_hyd_hyb_2_fst_con(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_hyd_hyb_2_fst_con(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_hyd_hyb_2_fst_con_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
