/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hyd_hyb_2_int_cont_offline_sfun.h"
#include "c2_hyd_hyb_2_int_cont_offline.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_int_cont_offline_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_first                    ((uint8_T)1U)
#define c2_IN_firstc                   ((uint8_T)2U)
#define c2_IN_fourth                   ((uint8_T)3U)
#define c2_IN_second                   ((uint8_T)4U)
#define c2_IN_third                    ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void initialize_params_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void enable_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void disable_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void set_sim_state_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_set_sim_state_side_effects_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void finalize_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void sf_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void c2_chartstep_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void initSimStructsc2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_b_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_b_tp_fourth, const char_T *c2_identifier);
static uint8_T c2_c_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_d_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_gear, const char_T *c2_identifier);
static real_T c2_e_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_f_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_b_temporalCounter_i1, const char_T *c2_identifier);
static uint32_T c2_g_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_i_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  real_T *c2_gear;
  real_T *c2_TC;
  c2_TC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_first = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_firstc = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_fourth = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_second = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_third = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_active_c2_hyd_hyb_2_int_cont_offline = 0U;
  chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_NO_ACTIVE_CHILD;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c2_gear = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c2_TC = 0.0;
  }
}

static void initialize_params_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  real_T c2_d0;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d4;
  real_T c2_d5;
  real_T c2_d6;
  real_T c2_d7;
  real_T c2_d8;
  sf_set_error_prefix_string(
    "Error evaluating data 'down_spd_4' in the parent workspace.\n");
  sf_mex_import_named("down_spd_4", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_down_spd_4 = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'down_spd_2' in the parent workspace.\n");
  sf_mex_import_named("down_spd_2", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c2_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_down_spd_2 = c2_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'down_spd_3' in the parent workspace.\n");
  sf_mex_import_named("down_spd_3", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c2_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_down_spd_3 = c2_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'up_spd_1' in the parent workspace.\n");
  sf_mex_import_named("up_spd_1", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c2_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_up_spd_1 = c2_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'up_spd_2' in the parent workspace.\n");
  sf_mex_import_named("up_spd_2", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c2_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_up_spd_2 = c2_d4;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'up_spd_3' in the parent workspace.\n");
  sf_mex_import_named("up_spd_3", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c2_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_up_spd_3 = c2_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'down_spd_c' in the parent workspace.\n");
  sf_mex_import_named("down_spd_c", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c2_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_down_spd_c = c2_d6;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'up_spd_c' in the parent workspace.\n");
  sf_mex_import_named("up_spd_c", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      &c2_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_up_spd_c = c2_d7;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Twait' in the parent workspace.\n");
  sf_mex_import_named("Twait", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c2_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_Twait = c2_d8;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_hyd_hyb_2_int_cont_offline == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_fourth) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_third) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_second) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_first) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_firstc) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint32_T c2_e_hoistedGlobal;
  uint32_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_TC;
  real_T *c2_gear;
  c2_TC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  c2_hoistedGlobal = *c2_TC;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_gear;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_hyd_hyb_2_int_cont_offline;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_TC;
  real_T *c2_gear;
  c2_TC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_TC = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "TC");
  *c2_gear = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "gear");
  chartInstance->c2_is_active_c2_hyd_hyb_2_int_cont_offline =
    c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "is_active_c2_hyd_hyb_2_int_cont_offline");
  chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_c2_hyd_hyb_2_int_cont_offline");
  chartInstance->c2_temporalCounter_i1 = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 5)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_hyd_hyb_2_int_cont_offline(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_first) {
      chartInstance->c2_tp_first = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_first = 0U;
    }

    if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_firstc) {
      chartInstance->c2_tp_firstc = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_firstc = 0U;
    }

    if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_fourth) {
      chartInstance->c2_tp_fourth = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_fourth = 0U;
    }

    if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_second) {
      chartInstance->c2_tp_second = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_second = 0U;
    }

    if (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline == c2_IN_third) {
      chartInstance->c2_tp_third = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_third = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  real_T *c2_speed;
  real_T *c2_gear;
  real_T *c2_TC;
  c2_TC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_speed = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_set_sim_state_side_effects_c2_hyd_hyb_2_int_cont_offline(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_speed, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_TC, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_down_spd_4, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_down_spd_2, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_down_spd_3, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_up_spd_1, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_up_spd_2, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_up_spd_3, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_down_spd_c, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_up_spd_c, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_Twait, 11U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  if (chartInstance->c2_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c2_temporalCounter_i1++;
  }

  c2_chartstep_c2_hyd_hyb_2_int_cont_offline(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hyd_hyb_2_int_cont_offlineMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
  boolean_T c2_temp;
  boolean_T c2_b_temp;
  boolean_T c2_out;
  boolean_T c2_c_temp;
  boolean_T c2_d_temp;
  boolean_T c2_b_out;
  boolean_T c2_e_temp;
  boolean_T c2_f_temp;
  boolean_T c2_c_out;
  boolean_T c2_g_temp;
  boolean_T c2_h_temp;
  boolean_T c2_d_out;
  boolean_T c2_i_temp;
  boolean_T c2_j_temp;
  boolean_T c2_e_out;
  boolean_T c2_k_temp;
  boolean_T c2_l_temp;
  boolean_T c2_f_out;
  boolean_T c2_m_temp;
  boolean_T c2_n_temp;
  boolean_T c2_g_out;
  boolean_T c2_o_temp;
  boolean_T c2_p_temp;
  boolean_T c2_h_out;
  real_T *c2_speed;
  real_T *c2_gear;
  real_T *c2_TC;
  c2_TC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_speed = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_hyd_hyb_2_int_cont_offline == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_hyd_hyb_2_int_cont_offline = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_firstc;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_firstc = 1U;
    *c2_gear = 1.0;
    _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
    *c2_TC = 0.0;
    _SFD_DATA_RANGE_CHECK(*c2_TC, 2U);
  } else {
    switch (chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline) {
     case c2_IN_first:
      CV_CHART_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      c2_temp = (_SFD_CCP_CALL(1U, 0, 1 != 0U, chartInstance->c2_sfEvent) != 0);
      if (c2_temp) {
        c2_temp = (_SFD_CCP_CALL(1U, 1, chartInstance->c2_temporalCounter_i1 >=
                    _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
          chartInstance->c2_Twait, 32U, 1U) != 0U, chartInstance->c2_sfEvent) !=
                   0);
      }

      c2_b_temp = c2_temp;
      if (c2_b_temp) {
        c2_b_temp = (_SFD_CCP_CALL(1U, 2, *c2_speed >=
          chartInstance->c2_up_spd_1 != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_out = (CV_TRANSITION_EVAL(1U, (int32_T)c2_b_temp) != 0);
      if (c2_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_first = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_second;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_second = 1U;
        *c2_gear = 2.0;
        _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c2_sfEvent);
        c2_c_temp = (_SFD_CCP_CALL(7U, 0, 1 != 0U, chartInstance->c2_sfEvent) !=
                     0);
        if (c2_c_temp) {
          c2_c_temp = (_SFD_CCP_CALL(7U, 1, chartInstance->c2_temporalCounter_i1
            >= _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait,
            32U, 7U) != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_d_temp = c2_c_temp;
        if (c2_d_temp) {
          c2_d_temp = (_SFD_CCP_CALL(7U, 2, *c2_speed <
            chartInstance->c2_down_spd_c != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_b_out = (CV_TRANSITION_EVAL(7U, (int32_T)c2_d_temp) != 0);
        if (c2_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_first = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_firstc;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          chartInstance->c2_temporalCounter_i1 = 0U;
          chartInstance->c2_tp_firstc = 1U;
          *c2_gear = 1.0;
          _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
          *c2_TC = 0.0;
          _SFD_DATA_RANGE_CHECK(*c2_TC, 2U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                       chartInstance->c2_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_firstc:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c2_sfEvent);
      c2_e_temp = (_SFD_CCP_CALL(3U, 0, 1 != 0U, chartInstance->c2_sfEvent) != 0);
      if (c2_e_temp) {
        c2_e_temp = (_SFD_CCP_CALL(3U, 1, chartInstance->c2_temporalCounter_i1 >=
          _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait, 32U,
          3U) != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_f_temp = c2_e_temp;
      if (c2_f_temp) {
        c2_f_temp = (_SFD_CCP_CALL(3U, 2, *c2_speed >=
          chartInstance->c2_up_spd_c != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_c_out = (CV_TRANSITION_EVAL(3U, (int32_T)c2_f_temp) != 0);
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_firstc = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_first;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_first = 1U;
        *c2_TC = 1.0;
        _SFD_DATA_RANGE_CHECK(*c2_TC, 2U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_fourth:
      CV_CHART_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c2_sfEvent);
      c2_g_temp = (_SFD_CCP_CALL(6U, 0, 1 != 0U, chartInstance->c2_sfEvent) != 0);
      if (c2_g_temp) {
        c2_g_temp = (_SFD_CCP_CALL(6U, 1, chartInstance->c2_temporalCounter_i1 >=
          _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait, 32U,
          6U) != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_h_temp = c2_g_temp;
      if (c2_h_temp) {
        c2_h_temp = (_SFD_CCP_CALL(6U, 2, *c2_speed <
          chartInstance->c2_down_spd_4 != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_d_out = (CV_TRANSITION_EVAL(6U, (int32_T)c2_h_temp) != 0);
      if (c2_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_fourth = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_third;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_third = 1U;
        *c2_gear = 3.0;
        _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_second:
      CV_CHART_EVAL(1, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c2_sfEvent);
      c2_i_temp = (_SFD_CCP_CALL(0U, 0, 1 != 0U, chartInstance->c2_sfEvent) != 0);
      if (c2_i_temp) {
        c2_i_temp = (_SFD_CCP_CALL(0U, 1, chartInstance->c2_temporalCounter_i1 >=
          _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait, 32U,
          0U) != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_j_temp = c2_i_temp;
      if (c2_j_temp) {
        c2_j_temp = (_SFD_CCP_CALL(0U, 2, *c2_speed >=
          chartInstance->c2_up_spd_2 != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_e_out = (CV_TRANSITION_EVAL(0U, (int32_T)c2_j_temp) != 0);
      if (c2_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_second = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_third;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_third = 1U;
        *c2_gear = 3.0;
        _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c2_sfEvent);
        c2_k_temp = (_SFD_CCP_CALL(8U, 0, 1 != 0U, chartInstance->c2_sfEvent) !=
                     0);
        if (c2_k_temp) {
          c2_k_temp = (_SFD_CCP_CALL(8U, 1, chartInstance->c2_temporalCounter_i1
            >= _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait,
            32U, 8U) != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_l_temp = c2_k_temp;
        if (c2_l_temp) {
          c2_l_temp = (_SFD_CCP_CALL(8U, 2, *c2_speed <
            chartInstance->c2_down_spd_2 != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_f_out = (CV_TRANSITION_EVAL(8U, (int32_T)c2_l_temp) != 0);
        if (c2_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_second = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_first;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
          chartInstance->c2_temporalCounter_i1 = 0U;
          chartInstance->c2_tp_first = 1U;
          *c2_TC = 1.0;
          _SFD_DATA_RANGE_CHECK(*c2_TC, 2U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c2_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_third:
      CV_CHART_EVAL(1, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c2_sfEvent);
      c2_m_temp = (_SFD_CCP_CALL(2U, 0, 1 != 0U, chartInstance->c2_sfEvent) != 0);
      if (c2_m_temp) {
        c2_m_temp = (_SFD_CCP_CALL(2U, 1, chartInstance->c2_temporalCounter_i1 >=
          _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait, 32U,
          2U) != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_n_temp = c2_m_temp;
      if (c2_n_temp) {
        c2_n_temp = (_SFD_CCP_CALL(2U, 2, *c2_speed >=
          chartInstance->c2_up_spd_3 != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_g_out = (CV_TRANSITION_EVAL(2U, (int32_T)c2_n_temp) != 0);
      if (c2_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_third = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_fourth;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_fourth = 1U;
        *c2_gear = 4.0;
        _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c2_sfEvent);
        c2_o_temp = (_SFD_CCP_CALL(5U, 0, 1 != 0U, chartInstance->c2_sfEvent) !=
                     0);
        if (c2_o_temp) {
          c2_o_temp = (_SFD_CCP_CALL(5U, 1, chartInstance->c2_temporalCounter_i1
            >= _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)chartInstance->c2_Twait,
            32U, 5U) != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_p_temp = c2_o_temp;
        if (c2_p_temp) {
          c2_p_temp = (_SFD_CCP_CALL(5U, 2, *c2_speed <
            chartInstance->c2_down_spd_3 != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_h_out = (CV_TRANSITION_EVAL(5U, (int32_T)c2_p_temp) != 0);
        if (c2_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_third = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_second;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_temporalCounter_i1 = 0U;
          chartInstance->c2_tp_second = 1U;
          *c2_gear = 2.0;
          _SFD_DATA_RANGE_CHECK(*c2_gear, 1U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       chartInstance->c2_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c2_is_c2_hyd_hyb_2_int_cont_offline = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_hyd_hyb_2_int_cont_offline
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_hyd_hyb_2_int_cont_offline_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint8_T c2_b_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_b_tp_fourth, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_fourth),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_fourth);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_fourth;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
    chartInstanceVoid;
  c2_b_tp_fourth = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_fourth),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_fourth);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_d_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_gear, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_gear), &c2_thisId);
  sf_mex_destroy(&c2_gear);
  return c2_y;
}

static real_T c2_e_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d9;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d9, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d9;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_gear;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
    chartInstanceVoid;
  c2_gear = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_gear), &c2_thisId);
  sf_mex_destroy(&c2_gear);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_f_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_b_temporalCounter_i1, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_temporalCounter_i1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_temporalCounter_i1);
  return c2_y;
}

static uint32_T c2_g_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 7, 0U, 0, 0U, 0);
  c2_y = c2_u1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_i_emlrt_marshallIn
  (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_hyd_hyb_2_int_cont_offline_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3402579190U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3098353214U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3661706646U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(931501107U);
}

mxArray *sf_c2_hyd_hyb_2_int_cont_offline_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("buEdDiJeCL0UvMIFDR77MG");
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

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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

mxArray *sf_c2_hyd_hyb_2_int_cont_offline_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_hyd_hyb_2_int_cont_offline_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_hyd_hyb_2_int_cont_offline(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[17],T\"TC\",},{M[1],M[16],T\"gear\",},{M[8],M[0],T\"is_active_c2_hyd_hyb_2_int_cont_offline\",},{M[9],M[0],T\"is_c2_hyd_hyb_2_int_cont_offline\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"wu\",M1x5[3 4 2 5 1],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_hyd_hyb_2_int_cont_offline_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
    chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hyd_hyb_2_int_cont_offlineMachineNumber_,
           2,
           5,
           9,
           12,
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
            (_hyd_hyb_2_int_cont_offlineMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _hyd_hyb_2_int_cont_offlineMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _hyd_hyb_2_int_cont_offlineMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"speed");
          _SFD_SET_DATA_PROPS(1,2,0,1,"gear");
          _SFD_SET_DATA_PROPS(2,2,0,1,"TC");
          _SFD_SET_DATA_PROPS(3,10,0,0,"down_spd_4");
          _SFD_SET_DATA_PROPS(4,10,0,0,"down_spd_2");
          _SFD_SET_DATA_PROPS(5,10,0,0,"down_spd_3");
          _SFD_SET_DATA_PROPS(6,10,0,0,"up_spd_1");
          _SFD_SET_DATA_PROPS(7,10,0,0,"up_spd_2");
          _SFD_SET_DATA_PROPS(8,10,0,0,"up_spd_3");
          _SFD_SET_DATA_PROPS(9,10,0,0,"down_spd_c");
          _SFD_SET_DATA_PROPS(10,10,0,0,"up_spd_c");
          _SFD_SET_DATA_PROPS(11,10,0,0,"Twait");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(5,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 36 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(0,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 36 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(1,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 36 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(2,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(3,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(5,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(6,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(7,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0, 19 };

          static unsigned int sEndGuardMap[] = { 16, 17, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(8,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);

        {
          real_T *c2_speed;
          real_T *c2_gear;
          real_T *c2_TC;
          c2_TC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_gear = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_speed = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_speed);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_gear);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_TC);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_down_spd_4);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c2_down_spd_2);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c2_down_spd_3);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c2_up_spd_1);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c2_up_spd_2);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c2_up_spd_3);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c2_down_spd_c);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c2_up_spd_c);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c2_Twait);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _hyd_hyb_2_int_cont_offlineMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "b8SbKBHuXySFDNUnDDZf7B";
}

static void sf_opaque_initialize_c2_hyd_hyb_2_int_cont_offline(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
  initialize_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_hyd_hyb_2_int_cont_offline(void
  *chartInstanceVar)
{
  enable_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_hyd_hyb_2_int_cont_offline(void
  *chartInstanceVar)
{
  disable_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_hyd_hyb_2_int_cont_offline(void
  *chartInstanceVar)
{
  sf_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_hyd_hyb_2_int_cont_offline
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_hyd_hyb_2_int_cont_offline();/* state var info */
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

extern void sf_internal_set_sim_state_c2_hyd_hyb_2_int_cont_offline(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_hyd_hyb_2_int_cont_offline();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_hyd_hyb_2_int_cont_offline
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_hyd_hyb_2_int_cont_offline(S);
}

static void sf_opaque_set_sim_state_c2_hyd_hyb_2_int_cont_offline(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_hyd_hyb_2_int_cont_offline(S, st);
}

static void sf_opaque_terminate_c2_hyd_hyb_2_int_cont_offline(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hyd_hyb_2_int_cont_offline_optimization_info();
    }

    finalize_c2_hyd_hyb_2_int_cont_offline
      ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_hyd_hyb_2_int_cont_offline
    ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_hyd_hyb_2_int_cont_offline(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_hyd_hyb_2_int_cont_offline
      ((SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_hyd_hyb_2_int_cont_offline(SimStruct *S)
{
  /* Actual parameters from chart:
     Twait down_spd_2 down_spd_3 down_spd_4 down_spd_c up_spd_1 up_spd_2 up_spd_3 up_spd_c
   */
  const char_T *rtParamNames[] = { "Twait", "down_spd_2", "down_spd_3",
    "down_spd_4", "down_spd_c", "up_spd_1", "up_spd_2", "up_spd_3", "up_spd_c" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Twait*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for down_spd_2*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for down_spd_3*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for down_spd_4*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for down_spd_c*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for up_spd_1*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for up_spd_2*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for up_spd_3*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for up_spd_c*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hyd_hyb_2_int_cont_offline_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(170774930U));
  ssSetChecksum1(S,(2974593823U));
  ssSetChecksum2(S,(3270986111U));
  ssSetChecksum3(S,(2001695970U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_hyd_hyb_2_int_cont_offline(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_hyd_hyb_2_int_cont_offline(SimStruct *S)
{
  SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *chartInstance;
  chartInstance = (SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct *)utMalloc
    (sizeof(SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_hyd_hyb_2_int_cont_offlineInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_hyd_hyb_2_int_cont_offline;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_hyd_hyb_2_int_cont_offline;
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

void c2_hyd_hyb_2_int_cont_offline_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_hyd_hyb_2_int_cont_offline(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_hyd_hyb_2_int_cont_offline(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_hyd_hyb_2_int_cont_offline(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_hyd_hyb_2_int_cont_offline_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}