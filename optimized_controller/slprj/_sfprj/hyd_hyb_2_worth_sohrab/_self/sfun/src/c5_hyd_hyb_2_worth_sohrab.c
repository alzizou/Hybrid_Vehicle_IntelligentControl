/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_worth_sohrab_sfun.h"
#include "c5_hyd_hyb_2_worth_sohrab.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_worth_sohrab_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD          (0U)
#define c5_IN_state1                   (1U)
#define c5_IN_state3                   (3U)
#define c5_IN_state2                   (2U)
#define c5_IN_state4                   (4U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void initialize_params_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void enable_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void disable_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void set_sim_state_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance, const mxArray
   *c5_st);
static void c5_set_sim_state_side_effects_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void finalize_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void sf_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void c5_chartstep_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void initSimStructsc5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void c5_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void c5_state3(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void c5_exit_internal_state3(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);
static void c5_enter_internal_state2(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);
static void c5_exit_internal_state2(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);
static void c5_exit_internal_state4(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);
static void c5_enter_internal_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);
static void c5_b_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance);
static void c5_exit_internal_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static int32_T c5_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static uint8_T c5_b_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_f_tp_state1, const char_T *c5_identifier);
static uint8_T c5_c_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_d_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_T_eng, const char_T *c5_identifier);
static real_T c5_e_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint32_T c5_f_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *
  chartInstance, const mxArray *c5_b_temporalCounter_i2, const char_T
  *c5_identifier);
static uint32_T c5_g_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static const mxArray *c5_h_emlrt_marshallIn
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance, const mxArray
   *c5_b_setSimStateSideEffectsInfo, const char_T *c5_identifier);
static const mxArray *c5_i_emlrt_marshallIn
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance, const mxArray *c5_u,
   const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  real_T *c5_eng_on;
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_doSetSimStateSideEffects = 0U;
  chartInstance->c5_setSimStateSideEffectsInfo = NULL;
  chartInstance->c5_tp_state1 = 0U;
  chartInstance->c5_is_state2 = 0U;
  chartInstance->c5_b_tp_state2 = 0U;
  chartInstance->c5_c_tp_state1 = 0U;
  chartInstance->c5_tp_state2 = 0U;
  chartInstance->c5_is_state3 = 0U;
  chartInstance->c5_tp_state3 = 0U;
  chartInstance->c5_is_state1 = 0U;
  chartInstance->c5_e_tp_state1 = 0U;
  chartInstance->c5_d_tp_state1 = 0U;
  chartInstance->c5_c_tp_state2 = 0U;
  chartInstance->c5_b_tp_state3 = 0U;
  chartInstance->c5_e_tp_state2 = 0U;
  chartInstance->c5_c_tp_state3 = 0U;
  chartInstance->c5_is_state4 = 0U;
  chartInstance->c5_tp_state4 = 0U;
  chartInstance->c5_b_tp_state1 = 0U;
  chartInstance->c5_d_tp_state2 = 0U;
  chartInstance->c5_is_active_c5_hyd_hyb_2_worth_sohrab = 0U;
  chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c5_T_eng = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c5_T_pm = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c5_eng_on = 0.0;
  }

  chartInstance->c5_presentTicks = 0U;
  chartInstance->c5_elapsedTicks = 0U;
  chartInstance->c5_previousTicks = 0U;
}

static void initialize_params_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  real_T c5_d0;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  sf_set_error_prefix_string(
    "Error evaluating data 'T_0' in the parent workspace.\n");
  sf_mex_import_named("T_0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c5_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_T_0 = c5_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T_1' in the parent workspace.\n");
  sf_mex_import_named("T_1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c5_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_T_1 = c5_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'soc_1' in the parent workspace.\n");
  sf_mex_import_named("soc_1", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c5_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_soc_1 = c5_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'soc_2' in the parent workspace.\n");
  sf_mex_import_named("soc_2", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c5_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_soc_2 = c5_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 't_wait_1' in the parent workspace.\n");
  sf_mex_import_named("t_wait_1", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c5_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_t_wait_1 = c5_d4;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 't_wait_2' in the parent workspace.\n");
  sf_mex_import_named("t_wait_2", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c5_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_t_wait_2 = c5_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 't_wait_3' in the parent workspace.\n");
  sf_mex_import_named("t_wait_3", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c5_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_t_wait_3 = c5_d6;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'veh_spd_0' in the parent workspace.\n");
  sf_mex_import_named("veh_spd_0", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c5_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_veh_spd_0 = c5_d7;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  real_T c5_d8;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c5_d8 = muDoubleScalarFloor(_sfTime_ / 0.01 + 0.5);
  chartInstance->c5_presentTicks = (uint32_T)c5_d8;
  chartInstance->c5_previousTicks = chartInstance->c5_presentTicks;
}

static void disable_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  real_T c5_d9;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c5_d9 = muDoubleScalarFloor(_sfTime_ / 0.01 + 0.5);
  chartInstance->c5_presentTicks = (uint32_T)c5_d9;
  chartInstance->c5_elapsedTicks = chartInstance->c5_presentTicks -
    chartInstance->c5_previousTicks;
  chartInstance->c5_previousTicks = chartInstance->c5_presentTicks;
  chartInstance->c5_temporalCounter_i1 += chartInstance->c5_elapsedTicks;
  chartInstance->c5_temporalCounter_i2 += chartInstance->c5_elapsedTicks;
}

static void c5_update_debugger_state_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  uint32_T c5_prevAniVal;
  c5_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c5_is_active_c5_hyd_hyb_2_worth_sohrab == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state4 == c5_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state2 == c5_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state2 == c5_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state1 == c5_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state1 == c5_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state1 == c5_IN_state3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state3 == c5_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state4 == c5_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state3 == c5_IN_state3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_state3 == c5_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
  }

  sf_debug_set_animation(c5_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
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
  uint8_T c5_g_hoistedGlobal;
  uint8_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  uint8_T c5_h_hoistedGlobal;
  uint8_T c5_h_u;
  const mxArray *c5_i_y = NULL;
  uint8_T c5_i_hoistedGlobal;
  uint8_T c5_i_u;
  const mxArray *c5_j_y = NULL;
  uint32_T c5_j_hoistedGlobal;
  uint32_T c5_j_u;
  const mxArray *c5_k_y = NULL;
  uint32_T c5_k_hoistedGlobal;
  uint32_T c5_k_u;
  const mxArray *c5_l_y = NULL;
  uint32_T c5_l_hoistedGlobal;
  uint32_T c5_l_u;
  const mxArray *c5_m_y = NULL;
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  real_T *c5_eng_on;
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(12));
  c5_hoistedGlobal = *c5_T_eng;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_T_pm;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_eng_on;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = chartInstance->c5_is_active_c5_hyd_hyb_2_worth_sohrab;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_f_hoistedGlobal = chartInstance->c5_is_state2;
  c5_f_u = c5_f_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 5, c5_g_y);
  c5_g_hoistedGlobal = chartInstance->c5_is_state3;
  c5_g_u = c5_g_hoistedGlobal;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 6, c5_h_y);
  c5_h_hoistedGlobal = chartInstance->c5_is_state4;
  c5_h_u = c5_h_hoistedGlobal;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_h_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 7, c5_i_y);
  c5_i_hoistedGlobal = chartInstance->c5_is_state1;
  c5_i_u = c5_i_hoistedGlobal;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_i_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 8, c5_j_y);
  c5_j_hoistedGlobal = chartInstance->c5_temporalCounter_i2;
  c5_j_u = c5_j_hoistedGlobal;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_j_u, 7, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 9, c5_k_y);
  c5_k_hoistedGlobal = chartInstance->c5_temporalCounter_i1;
  c5_k_u = c5_k_hoistedGlobal;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_k_u, 7, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 10, c5_l_y);
  c5_l_hoistedGlobal = chartInstance->c5_previousTicks;
  c5_l_u = c5_l_hoistedGlobal;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_l_u, 7, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 11, c5_m_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance, const mxArray
   *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  real_T *c5_eng_on;
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_u = sf_mex_dup(c5_st);
  *c5_T_eng = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 0)), "T_eng");
  *c5_T_pm = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    1)), "T_pm");
  *c5_eng_on = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 2)), "eng_on");
  chartInstance->c5_is_active_c5_hyd_hyb_2_worth_sohrab = c5_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 3)),
     "is_active_c5_hyd_hyb_2_worth_sohrab");
  chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 4)),
     "is_c5_hyd_hyb_2_worth_sohrab");
  chartInstance->c5_is_state2 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 5)), "is_state2");
  chartInstance->c5_is_state3 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 6)), "is_state3");
  chartInstance->c5_is_state4 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 7)), "is_state4");
  chartInstance->c5_is_state1 = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 8)), "is_state1");
  chartInstance->c5_temporalCounter_i2 = c5_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 9)), "temporalCounter_i2");
  chartInstance->c5_temporalCounter_i1 = c5_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 10)), "temporalCounter_i1");
  chartInstance->c5_previousTicks = c5_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 11)), "previousTicks");
  sf_mex_assign(&chartInstance->c5_setSimStateSideEffectsInfo,
                c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 12)), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c5_u);
  chartInstance->c5_doSetSimStateSideEffects = 1U;
  c5_update_debugger_state_c5_hyd_hyb_2_worth_sohrab(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void c5_set_sim_state_side_effects_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  if (chartInstance->c5_doSetSimStateSideEffects != 0) {
    if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state1) {
      chartInstance->c5_tp_state1 = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_state1 = 0U;
    }

    if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state2) {
      chartInstance->c5_b_tp_state2 = 1U;
    } else {
      chartInstance->c5_b_tp_state2 = 0U;
    }

    if (chartInstance->c5_is_state2 == c5_IN_state1) {
      chartInstance->c5_c_tp_state1 = 1U;
    } else {
      chartInstance->c5_c_tp_state1 = 0U;
    }

    if (chartInstance->c5_is_state2 == c5_IN_state2) {
      chartInstance->c5_tp_state2 = 1U;
    } else {
      chartInstance->c5_tp_state2 = 0U;
    }

    if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state3) {
      chartInstance->c5_tp_state3 = 1U;
    } else {
      chartInstance->c5_tp_state3 = 0U;
    }

    if (chartInstance->c5_is_state3 == c5_IN_state1) {
      chartInstance->c5_e_tp_state1 = 1U;
    } else {
      chartInstance->c5_e_tp_state1 = 0U;
    }

    if (chartInstance->c5_is_state1 == c5_IN_state1) {
      chartInstance->c5_d_tp_state1 = 1U;
    } else {
      chartInstance->c5_d_tp_state1 = 0U;
    }

    if (chartInstance->c5_is_state1 == c5_IN_state2) {
      chartInstance->c5_c_tp_state2 = 1U;
    } else {
      chartInstance->c5_c_tp_state2 = 0U;
    }

    if (chartInstance->c5_is_state1 == c5_IN_state3) {
      chartInstance->c5_b_tp_state3 = 1U;
    } else {
      chartInstance->c5_b_tp_state3 = 0U;
    }

    if (chartInstance->c5_is_state3 == c5_IN_state2) {
      chartInstance->c5_e_tp_state2 = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_e_tp_state2 = 0U;
    }

    if (chartInstance->c5_is_state3 == c5_IN_state3) {
      chartInstance->c5_c_tp_state3 = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_c_tp_state3 = 0U;
    }

    if (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab == c5_IN_state4) {
      chartInstance->c5_tp_state4 = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_state4 = 0U;
    }

    if (chartInstance->c5_is_state4 == c5_IN_state1) {
      chartInstance->c5_b_tp_state1 = 1U;
    } else {
      chartInstance->c5_b_tp_state1 = 0U;
    }

    if (chartInstance->c5_is_state4 == c5_IN_state2) {
      chartInstance->c5_d_tp_state2 = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c5_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c5_d_tp_state2 = 0U;
    }

    chartInstance->c5_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c5_setSimStateSideEffectsInfo);
}

static void sf_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  real_T c5_d10;
  real_T *c5_y;
  real_T *c5_eng_on;
  real_T *c5_veh_spd;
  real_T *c5_x;
  real_T *c5_T_pm;
  real_T *c5_T_eng;
  real_T *c5_soc;
  real_T *c5_T_acc;
  c5_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_set_sim_state_side_effects_c5_hyd_hyb_2_worth_sohrab(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c5_d10 = muDoubleScalarFloor(_sfTime_ / 0.01 + 0.5);
  chartInstance->c5_presentTicks = (uint32_T)c5_d10;
  chartInstance->c5_elapsedTicks = chartInstance->c5_presentTicks -
    chartInstance->c5_previousTicks;
  chartInstance->c5_previousTicks = chartInstance->c5_presentTicks;
  chartInstance->c5_temporalCounter_i1 += chartInstance->c5_elapsedTicks;
  chartInstance->c5_temporalCounter_i2 += chartInstance->c5_elapsedTicks;
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_T_acc, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_soc, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_x, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_veh_spd, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_y, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_T_0, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_T_1, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_soc_1, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_soc_2, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_t_wait_1, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_t_wait_2, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_t_wait_3, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_veh_spd_0, 15U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_hyd_hyb_2_worth_sohrab(chartInstance);
  sf_debug_check_for_state_inconsistency(_hyd_hyb_2_worth_sohrabMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  boolean_T c5_temp;
  boolean_T c5_b_temp;
  real_T c5_d11;
  boolean_T c5_c_temp;
  boolean_T c5_d_temp;
  boolean_T c5_e_temp;
  boolean_T c5_f_temp;
  real_T c5_d12;
  boolean_T c5_g_temp;
  real_T *c5_T_acc;
  real_T *c5_soc;
  real_T *c5_eng_on;
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  real_T *c5_x;
  real_T *c5_y;
  c5_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  if ((int16_T)chartInstance->c5_is_active_c5_hyd_hyb_2_worth_sohrab == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_active_c5_hyd_hyb_2_worth_sohrab = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_tp_state1 = 1U;
  } else {
    switch (chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab) {
     case c5_IN_state1:
      CV_CHART_EVAL(3, 0, 1);
      c5_state1(chartInstance);
      break;

     case c5_IN_state2:
      CV_CHART_EVAL(3, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c5_sfEvent);
      if (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(14U, 0, *c5_T_acc <=
            chartInstance->c5_T_0 != 0U, chartInstance->c5_sfEvent))) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 14;
          sf_debug_transition_conflict_check_begin();
          if (*c5_soc <= chartInstance->c5_soc_1) {
            transitionList[numTransitions] = 17;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
        c5_exit_internal_state2(chartInstance);
        chartInstance->c5_b_tp_state2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
        chartInstance->c5_temporalCounter_i1 = 0U;
        chartInstance->c5_tp_state4 = 1U;
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                     chartInstance->c5_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_state4 = c5_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
        chartInstance->c5_b_tp_state1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                     chartInstance->c5_sfEvent);
        if (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0, *c5_soc <=
              chartInstance->c5_soc_1 != 0U, chartInstance->c5_sfEvent))) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
          c5_exit_internal_state2(chartInstance);
          chartInstance->c5_b_tp_state2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_state3 = 1U;
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                       chartInstance->c5_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_state3 = c5_IN_state1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
          chartInstance->c5_e_tp_state1 = 1U;
          c5_enter_internal_state1(chartInstance);
        } else {
          *c5_eng_on = 1.0;
          _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
          switch (chartInstance->c5_is_state2) {
           case c5_IN_state1:
            CV_STATE_EVAL(1, 0, 1);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                         chartInstance->c5_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                         chartInstance->c5_sfEvent);
            c5_temp = (_SFD_CCP_CALL(22U, 0, chartInstance->c5_T_0 <= *c5_T_acc
                        != 0U, chartInstance->c5_sfEvent) != 0);
            if (c5_temp) {
              c5_temp = (_SFD_CCP_CALL(22U, 1, *c5_T_acc <=
                          chartInstance->c5_T_1 != 0U, chartInstance->c5_sfEvent)
                         != 0);
            }

            if (CV_TRANSITION_EVAL(22U, (int32_T)c5_temp)) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
              chartInstance->c5_c_tp_state1 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
              chartInstance->c5_is_state2 = c5_IN_state2;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
              chartInstance->c5_tp_state2 = 1U;
            } else {
              *c5_T_eng = chartInstance->c5_T_1;
              _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
              *c5_T_pm = *c5_T_acc - *c5_T_eng;
              _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
            break;

           case c5_IN_state2:
            CV_STATE_EVAL(1, 0, 2);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c5_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                         chartInstance->c5_sfEvent);
            if (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(23U, 0, *c5_T_acc
                  > chartInstance->c5_T_1 != 0U, chartInstance->c5_sfEvent))) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
              chartInstance->c5_tp_state2 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
              chartInstance->c5_is_state2 = c5_IN_state1;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
              chartInstance->c5_c_tp_state1 = 1U;
            } else {
              *c5_T_eng = *c5_T_acc - (*c5_T_acc - chartInstance->c5_T_0) *
                *c5_x;
              _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
              *c5_T_pm = *c5_T_acc - *c5_T_eng;
              _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
            break;

           default:
            CV_STATE_EVAL(1, 0, 0);
            chartInstance->c5_is_state2 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
            break;
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
      break;

     case c5_IN_state3:
      CV_CHART_EVAL(3, 0, 3);
      c5_state3(chartInstance);
      break;

     case c5_IN_state4:
      CV_CHART_EVAL(3, 0, 4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                   chartInstance->c5_sfEvent);
      if (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(16U, 0, *c5_soc <=
            chartInstance->c5_soc_1 != 0U, chartInstance->c5_sfEvent))) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 16;
          sf_debug_transition_conflict_check_begin();
          if ((*c5_T_acc > chartInstance->c5_T_0) && (*c5_soc >
               chartInstance->c5_soc_1)) {
            transitionList[numTransitions] = 20;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
        c5_exit_internal_state4(chartInstance);
        chartInstance->c5_tp_state4 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_state3 = 1U;
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                     chartInstance->c5_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_state3 = c5_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
        chartInstance->c5_e_tp_state1 = 1U;
        c5_enter_internal_state1(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                     chartInstance->c5_sfEvent);
        c5_b_temp = (_SFD_CCP_CALL(15U, 0, 1 != 0U, chartInstance->c5_sfEvent)
                     != 0);
        if (c5_b_temp) {
          c5_d11 = muDoubleScalarCeil(chartInstance->c5_t_wait_2 / 0.01 -
            1.0E-10);
          c5_b_temp = (_SFD_CCP_CALL(15U, 1,
            chartInstance->c5_temporalCounter_i1 >= (uint32_T)c5_d11 != 0U,
            chartInstance->c5_sfEvent) != 0);
        }

        c5_c_temp = c5_b_temp;
        if (c5_c_temp) {
          c5_d_temp = (_SFD_CCP_CALL(15U, 2, *c5_T_acc <= chartInstance->c5_T_0
            != 0U, chartInstance->c5_sfEvent) != 0);
          if (c5_d_temp) {
            c5_d_temp = (_SFD_CCP_CALL(15U, 3, *c5_soc > chartInstance->c5_soc_1
              != 0U, chartInstance->c5_sfEvent) != 0);
          }

          c5_c_temp = c5_d_temp;
        }

        if (CV_TRANSITION_EVAL(15U, (int32_T)c5_c_temp)) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
          c5_exit_internal_state4(chartInstance);
          chartInstance->c5_tp_state4 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
          chartInstance->c5_temporalCounter_i1 = 0U;
          chartInstance->c5_tp_state1 = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                       chartInstance->c5_sfEvent);
          c5_e_temp = (_SFD_CCP_CALL(20U, 0, *c5_T_acc > chartInstance->c5_T_0
            != 0U, chartInstance->c5_sfEvent) != 0);
          if (c5_e_temp) {
            c5_e_temp = (_SFD_CCP_CALL(20U, 1, *c5_soc > chartInstance->c5_soc_1
              != 0U, chartInstance->c5_sfEvent) != 0);
          }

          if (CV_TRANSITION_EVAL(20U, (int32_T)c5_e_temp)) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
            c5_exit_internal_state4(chartInstance);
            chartInstance->c5_tp_state4 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
            chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state2;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
            chartInstance->c5_b_tp_state2 = 1U;
            c5_enter_internal_state2(chartInstance);
          } else {
            switch (chartInstance->c5_is_state4) {
             case c5_IN_state1:
              CV_STATE_EVAL(11, 0, 1);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                           chartInstance->c5_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                           chartInstance->c5_sfEvent);
              if (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0, *c5_y >
                    0.1 != 0U, chartInstance->c5_sfEvent))) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U,
                             chartInstance->c5_sfEvent);
                chartInstance->c5_b_tp_state1 = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
                chartInstance->c5_is_state4 = c5_IN_state2;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
                chartInstance->c5_temporalCounter_i2 = 0U;
                chartInstance->c5_d_tp_state2 = 1U;
              } else {
                *c5_T_eng = chartInstance->c5_T_0;
                _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
                *c5_T_pm = *c5_T_acc - *c5_T_eng;
                _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
                *c5_eng_on = 1.0;
                _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
              }

              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U,
                           chartInstance->c5_sfEvent);
              break;

             case c5_IN_state2:
              CV_STATE_EVAL(11, 0, 2);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                           chartInstance->c5_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                           chartInstance->c5_sfEvent);
              c5_f_temp = (_SFD_CCP_CALL(26U, 0, 1 != 0U,
                chartInstance->c5_sfEvent) != 0);
              if (c5_f_temp) {
                c5_d12 = muDoubleScalarCeil(chartInstance->c5_t_wait_3 / 0.01 -
                  1.0E-10);
                c5_f_temp = (_SFD_CCP_CALL(26U, 1,
                  chartInstance->c5_temporalCounter_i2 >= (uint32_T)c5_d12 != 0U,
                  chartInstance->c5_sfEvent) != 0);
              }

              c5_g_temp = c5_f_temp;
              if (c5_g_temp) {
                c5_g_temp = (_SFD_CCP_CALL(26U, 2, *c5_T_acc > 0.0 != 0U,
                  chartInstance->c5_sfEvent) != 0);
              }

              if (CV_TRANSITION_EVAL(26U, (int32_T)c5_g_temp)) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U,
                             chartInstance->c5_sfEvent);
                chartInstance->c5_d_tp_state2 = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
                chartInstance->c5_is_state4 = c5_IN_state1;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
                chartInstance->c5_b_tp_state1 = 1U;
              } else {
                *c5_T_eng = 0.0;
                _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
                *c5_T_pm = 0.0;
                _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
                *c5_eng_on = 0.5;
                _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
              }

              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U,
                           chartInstance->c5_sfEvent);
              break;

             default:
              CV_STATE_EVAL(11, 0, 0);
              chartInstance->c5_is_state4 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
              break;
            }
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c5_sfEvent);
      break;

     default:
      CV_CHART_EVAL(3, 0, 0);
      chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = (uint8_T)
        c5_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_hyd_hyb_2_worth_sohrab
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
}

static void c5_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  boolean_T c5_temp;
  real_T c5_d13;
  boolean_T c5_b_temp;
  boolean_T c5_c_temp;
  real_T c5_d14;
  boolean_T c5_d_temp;
  boolean_T c5_e_temp;
  boolean_T c5_f_temp;
  real_T *c5_soc;
  real_T *c5_veh_spd;
  real_T *c5_T_acc;
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  real_T *c5_eng_on;
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c5_sfEvent);
  c5_temp = (_SFD_CCP_CALL(13U, 0, 1 != 0U, chartInstance->c5_sfEvent) != 0);
  if (c5_temp) {
    c5_d13 = muDoubleScalarCeil(chartInstance->c5_t_wait_1 / 0.01 - 1.0E-10);
    c5_temp = (_SFD_CCP_CALL(13U, 1, chartInstance->c5_temporalCounter_i1 >=
                (uint32_T)c5_d13 != 0U, chartInstance->c5_sfEvent) != 0);
  }

  c5_b_temp = c5_temp;
  if (c5_b_temp) {
    c5_b_temp = (_SFD_CCP_CALL(13U, 2, *c5_soc <= chartInstance->c5_soc_1 != 0U,
      chartInstance->c5_sfEvent) != 0);
  }

  if (CV_TRANSITION_EVAL(13U, (int32_T)c5_b_temp)) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_state1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_state3 = 1U;
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_state3 = c5_IN_state1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
    chartInstance->c5_e_tp_state1 = 1U;
    c5_enter_internal_state1(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c5_sfEvent);
    c5_c_temp = (_SFD_CCP_CALL(1U, 0, 1 != 0U, chartInstance->c5_sfEvent) != 0);
    if (c5_c_temp) {
      c5_d14 = muDoubleScalarCeil(chartInstance->c5_t_wait_1 / 0.01 - 1.0E-10);
      c5_c_temp = (_SFD_CCP_CALL(1U, 1, chartInstance->c5_temporalCounter_i1 >=
                    (uint32_T)c5_d14 != 0U, chartInstance->c5_sfEvent) != 0);
    }

    c5_d_temp = c5_c_temp;
    if (c5_d_temp) {
      c5_e_temp = (_SFD_CCP_CALL(1U, 2, *c5_veh_spd >
        chartInstance->c5_veh_spd_0 != 0U, chartInstance->c5_sfEvent) != 0);
      if (c5_e_temp) {
        c5_e_temp = (_SFD_CCP_CALL(1U, 3, *c5_T_acc > chartInstance->c5_T_0 !=
          0U, chartInstance->c5_sfEvent) != 0);
      }

      c5_f_temp = c5_e_temp;
      if (c5_f_temp) {
        c5_f_temp = (_SFD_CCP_CALL(1U, 4, *c5_soc > chartInstance->c5_soc_1 !=
          0U, chartInstance->c5_sfEvent) != 0);
      }

      c5_d_temp = c5_f_temp;
    }

    if (CV_TRANSITION_EVAL(1U, (int32_T)c5_d_temp)) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_state1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
      chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
      chartInstance->c5_b_tp_state2 = 1U;
      c5_enter_internal_state2(chartInstance);
    } else {
      *c5_T_eng = 0.0;
      _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
      *c5_T_pm = *c5_T_acc;
      _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
      *c5_eng_on = 0.0;
      _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
}

static void c5_state3(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  boolean_T c5_temp;
  boolean_T c5_b_temp;
  boolean_T c5_c_temp;
  real_T c5_d15;
  boolean_T c5_d_temp;
  boolean_T c5_e_temp;
  real_T c5_d16;
  boolean_T c5_f_temp;
  boolean_T c5_g_temp;
  real_T c5_d17;
  boolean_T c5_h_temp;
  real_T *c5_soc;
  real_T *c5_T_acc;
  real_T *c5_veh_spd;
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  real_T *c5_eng_on;
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, chartInstance->c5_sfEvent);
  c5_temp = (_SFD_CCP_CALL(18U, 0, *c5_soc >= chartInstance->c5_soc_2 != 0U,
              chartInstance->c5_sfEvent) != 0);
  if (c5_temp) {
    c5_temp = (_SFD_CCP_CALL(18U, 1, *c5_T_acc > chartInstance->c5_T_0 != 0U,
                chartInstance->c5_sfEvent) != 0);
  }

  if (CV_TRANSITION_EVAL(18U, (int32_T)c5_temp)) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 18;
      sf_debug_transition_conflict_check_begin();
      if ((*c5_soc >= chartInstance->c5_soc_2) && (*c5_T_acc <=
           chartInstance->c5_T_0)) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
    c5_exit_internal_state3(chartInstance);
    chartInstance->c5_tp_state3 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
    chartInstance->c5_b_tp_state2 = 1U;
    c5_enter_internal_state2(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c5_sfEvent);
    c5_b_temp = (_SFD_CCP_CALL(19U, 0, *c5_soc >= chartInstance->c5_soc_2 != 0U,
      chartInstance->c5_sfEvent) != 0);
    if (c5_b_temp) {
      c5_b_temp = (_SFD_CCP_CALL(19U, 1, *c5_T_acc <= chartInstance->c5_T_0 !=
        0U, chartInstance->c5_sfEvent) != 0);
    }

    if (CV_TRANSITION_EVAL(19U, (int32_T)c5_b_temp)) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
      c5_exit_internal_state3(chartInstance);
      chartInstance->c5_tp_state3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
      chartInstance->c5_is_c5_hyd_hyb_2_worth_sohrab = c5_IN_state4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
      chartInstance->c5_temporalCounter_i1 = 0U;
      chartInstance->c5_tp_state4 = 1U;
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
      chartInstance->c5_is_state4 = c5_IN_state1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
      chartInstance->c5_b_tp_state1 = 1U;
    } else {
      switch (chartInstance->c5_is_state3) {
       case c5_IN_state1:
        CV_STATE_EVAL(4, 0, 1);
        c5_b_state1(chartInstance);
        break;

       case c5_IN_state2:
        CV_STATE_EVAL(4, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     chartInstance->c5_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                     chartInstance->c5_sfEvent);
        c5_c_temp = (_SFD_CCP_CALL(31U, 0, 1 != 0U, chartInstance->c5_sfEvent)
                     != 0);
        if (c5_c_temp) {
          c5_d15 = muDoubleScalarCeil(chartInstance->c5_t_wait_2 / 0.01 -
            1.0E-10);
          c5_c_temp = (_SFD_CCP_CALL(31U, 1,
            chartInstance->c5_temporalCounter_i1 >= (uint32_T)c5_d15 != 0U,
            chartInstance->c5_sfEvent) != 0);
        }

        c5_d_temp = c5_c_temp;
        if (c5_d_temp) {
          c5_d_temp = (_SFD_CCP_CALL(31U, 2, *c5_veh_spd <= 0.0001 != 0U,
            chartInstance->c5_sfEvent) != 0);
        }

        if (CV_TRANSITION_EVAL(31U, (int32_T)c5_d_temp)) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
          chartInstance->c5_e_tp_state2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_state3 = c5_IN_state3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
          chartInstance->c5_temporalCounter_i1 = 0U;
          chartInstance->c5_c_tp_state3 = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                       chartInstance->c5_sfEvent);
          c5_e_temp = (_SFD_CCP_CALL(29U, 0, 1 != 0U, chartInstance->c5_sfEvent)
                       != 0);
          if (c5_e_temp) {
            c5_d16 = muDoubleScalarCeil(chartInstance->c5_t_wait_3 / 0.01 -
              1.0E-10);
            c5_e_temp = (_SFD_CCP_CALL(29U, 1,
              chartInstance->c5_temporalCounter_i1 >= (uint32_T)c5_d16 != 0U,
              chartInstance->c5_sfEvent) != 0);
          }

          c5_f_temp = c5_e_temp;
          if (c5_f_temp) {
            c5_f_temp = (_SFD_CCP_CALL(29U, 2, *c5_T_acc > 0.0 != 0U,
              chartInstance->c5_sfEvent) != 0);
          }

          if (CV_TRANSITION_EVAL(29U, (int32_T)c5_f_temp)) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
            chartInstance->c5_e_tp_state2 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
            chartInstance->c5_is_state3 = c5_IN_state1;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
            chartInstance->c5_e_tp_state1 = 1U;
            c5_enter_internal_state1(chartInstance);
          } else {
            *c5_T_eng = 0.0;
            _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
            *c5_T_pm = 0.0;
            _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
            *c5_eng_on = 0.5;
            _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
          }
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c5_sfEvent);
        break;

       case c5_IN_state3:
        CV_STATE_EVAL(4, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c5_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                     chartInstance->c5_sfEvent);
        c5_g_temp = (_SFD_CCP_CALL(32U, 0, 1 != 0U, chartInstance->c5_sfEvent)
                     != 0);
        if (c5_g_temp) {
          c5_d17 = muDoubleScalarCeil(chartInstance->c5_t_wait_1 / 0.01 -
            1.0E-10);
          c5_g_temp = (_SFD_CCP_CALL(32U, 1,
            chartInstance->c5_temporalCounter_i1 >= (uint32_T)c5_d17 != 0U,
            chartInstance->c5_sfEvent) != 0);
        }

        c5_h_temp = c5_g_temp;
        if (c5_h_temp) {
          c5_h_temp = (_SFD_CCP_CALL(32U, 2, *c5_T_acc > 0.0 != 0U,
            chartInstance->c5_sfEvent) != 0);
        }

        if (CV_TRANSITION_EVAL(32U, (int32_T)c5_h_temp)) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c5_sfEvent);
          chartInstance->c5_c_tp_state3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_state3 = c5_IN_state1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
          chartInstance->c5_e_tp_state1 = 1U;
          c5_enter_internal_state1(chartInstance);
        } else {
          *c5_T_eng = 0.0;
          _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
          *c5_T_pm = 0.0;
          _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
          *c5_eng_on = 0.0;
          _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c5_sfEvent);
        break;

       default:
        CV_STATE_EVAL(4, 0, 0);
        chartInstance->c5_is_state3 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
        break;
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void c5_exit_internal_state3(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c5_is_state3) {
   case c5_IN_state1:
    CV_STATE_EVAL(4, 1, 1);
    c5_exit_internal_state1(chartInstance);
    chartInstance->c5_e_tp_state1 = 0U;
    chartInstance->c5_is_state3 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_state2:
    CV_STATE_EVAL(4, 1, 2);
    chartInstance->c5_e_tp_state2 = 0U;
    chartInstance->c5_is_state3 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_state3:
    CV_STATE_EVAL(4, 1, 3);
    chartInstance->c5_c_tp_state3 = 0U;
    chartInstance->c5_is_state3 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(4, 1, 0);
    chartInstance->c5_is_state3 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
    break;
  }
}

static void c5_enter_internal_state2(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
  boolean_T c5_temp;
  real_T *c5_T_acc;
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c5_sfEvent);
  if (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0, *c5_T_acc >
        chartInstance->c5_T_1 != 0U, chartInstance->c5_sfEvent))) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 2;
      sf_debug_transition_conflict_check_begin();
      if ((chartInstance->c5_T_0 <= *c5_T_acc) && (*c5_T_acc <=
           chartInstance->c5_T_1)) {
        transitionList[numTransitions] = 3;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_state2 = c5_IN_state1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    chartInstance->c5_c_tp_state1 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c5_sfEvent);
    c5_temp = (_SFD_CCP_CALL(3U, 0, chartInstance->c5_T_0 <= *c5_T_acc != 0U,
                chartInstance->c5_sfEvent) != 0);
    if (c5_temp) {
      c5_temp = (_SFD_CCP_CALL(3U, 1, *c5_T_acc <= chartInstance->c5_T_1 != 0U,
                  chartInstance->c5_sfEvent) != 0);
    }

    if (CV_TRANSITION_EVAL(3U, (int32_T)c5_temp)) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
      chartInstance->c5_is_state2 = c5_IN_state2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_state2 = 1U;
    }
  }
}

static void c5_exit_internal_state2(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c5_is_state2) {
   case c5_IN_state1:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c5_c_tp_state1 = 0U;
    chartInstance->c5_is_state2 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_state2:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c5_tp_state2 = 0U;
    chartInstance->c5_is_state2 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c5_is_state2 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    break;
  }
}

static void c5_exit_internal_state4(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c5_is_state4) {
   case c5_IN_state1:
    CV_STATE_EVAL(11, 1, 1);
    chartInstance->c5_b_tp_state1 = 0U;
    chartInstance->c5_is_state4 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_state2:
    CV_STATE_EVAL(11, 1, 2);
    chartInstance->c5_d_tp_state2 = 0U;
    chartInstance->c5_is_state4 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 1, 0);
    chartInstance->c5_is_state4 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
    break;
  }
}

static void c5_enter_internal_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
  boolean_T c5_temp;
  real_T *c5_T_acc;
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c5_sfEvent);
  if (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0, *c5_T_acc >=
        chartInstance->c5_T_1 != 0U, chartInstance->c5_sfEvent))) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions = 1;
      transitionList[0] = 5;
      sf_debug_transition_conflict_check_begin();
      if ((chartInstance->c5_T_0 < *c5_T_acc) && (*c5_T_acc <
           chartInstance->c5_T_1)) {
        transitionList[numTransitions] = 4;
        numTransitions++;
      }

      if (*c5_T_acc <= chartInstance->c5_T_0) {
        transitionList[numTransitions] = 6;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_state1 = c5_IN_state2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
    chartInstance->c5_c_tp_state2 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c5_sfEvent);
    c5_temp = (_SFD_CCP_CALL(4U, 0, chartInstance->c5_T_0 < *c5_T_acc != 0U,
                chartInstance->c5_sfEvent) != 0);
    if (c5_temp) {
      c5_temp = (_SFD_CCP_CALL(4U, 1, *c5_T_acc < chartInstance->c5_T_1 != 0U,
                  chartInstance->c5_sfEvent) != 0);
    }

    if (CV_TRANSITION_EVAL(4U, (int32_T)c5_temp)) {
      if (sf_debug_transition_conflict_check_enabled()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 4;
        sf_debug_transition_conflict_check_begin();
        if (*c5_T_acc <= chartInstance->c5_T_0) {
          transitionList[numTransitions] = 6;
          numTransitions++;
        }

        sf_debug_transition_conflict_check_end();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
      chartInstance->c5_is_state1 = c5_IN_state1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
      chartInstance->c5_d_tp_state1 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c5_sfEvent);
      if (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0, *c5_T_acc <=
            chartInstance->c5_T_0 != 0U, chartInstance->c5_sfEvent))) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_state1 = c5_IN_state3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
        chartInstance->c5_b_tp_state3 = 1U;
      }
    }
  }
}

static void c5_b_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance)
{
  boolean_T c5_temp;
  boolean_T c5_b_temp;
  real_T *c5_y;
  real_T *c5_eng_on;
  real_T *c5_T_acc;
  real_T *c5_x;
  real_T *c5_T_eng;
  real_T *c5_T_pm;
  c5_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U, chartInstance->c5_sfEvent);
  if (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0, *c5_y > 0.1 != 0U,
        chartInstance->c5_sfEvent))) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
    c5_exit_internal_state1(chartInstance);
    chartInstance->c5_e_tp_state1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_state3 = c5_IN_state2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_e_tp_state2 = 1U;
  } else {
    *c5_eng_on = 1.0;
    _SFD_DATA_RANGE_CHECK(*c5_eng_on, 6U);
    switch (chartInstance->c5_is_state1) {
     case c5_IN_state1:
      CV_STATE_EVAL(5, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c5_sfEvent);
      if (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10U, 0, *c5_T_acc <=
            chartInstance->c5_T_0 != 0U, chartInstance->c5_sfEvent))) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 10;
          sf_debug_transition_conflict_check_begin();
          if (*c5_T_acc >= chartInstance->c5_T_1) {
            transitionList[numTransitions] = 12;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
        chartInstance->c5_d_tp_state1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_state1 = c5_IN_state3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
        chartInstance->c5_b_tp_state3 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     chartInstance->c5_sfEvent);
        if (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0, *c5_T_acc >=
              chartInstance->c5_T_1 != 0U, chartInstance->c5_sfEvent))) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
          chartInstance->c5_d_tp_state1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_state1 = c5_IN_state2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
          chartInstance->c5_c_tp_state2 = 1U;
        } else {
          *c5_T_eng = *c5_T_acc + (chartInstance->c5_T_1 - *c5_T_acc) * (1.0 -
            *c5_x);
          _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
          *c5_T_pm = *c5_T_acc - *c5_T_eng;
          _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c5_sfEvent);
      break;

     case c5_IN_state2:
      CV_STATE_EVAL(5, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c5_sfEvent);
      c5_temp = (_SFD_CCP_CALL(7U, 0, chartInstance->c5_T_0 < *c5_T_acc != 0U,
                  chartInstance->c5_sfEvent) != 0);
      if (c5_temp) {
        c5_temp = (_SFD_CCP_CALL(7U, 1, *c5_T_acc < chartInstance->c5_T_1 != 0U,
                    chartInstance->c5_sfEvent) != 0);
      }

      if (CV_TRANSITION_EVAL(7U, (int32_T)c5_temp)) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 7;
          sf_debug_transition_conflict_check_begin();
          if (*c5_T_acc <= chartInstance->c5_T_0) {
            transitionList[numTransitions] = 8;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
        chartInstance->c5_c_tp_state2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_state1 = c5_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
        chartInstance->c5_d_tp_state1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c5_sfEvent);
        if (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0, *c5_T_acc <=
              chartInstance->c5_T_0 != 0U, chartInstance->c5_sfEvent))) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
          chartInstance->c5_c_tp_state2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_state1 = c5_IN_state3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
          chartInstance->c5_b_tp_state3 = 1U;
        } else {
          *c5_T_eng = *c5_T_acc;
          _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
          *c5_T_pm = 0.0;
          _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c5_sfEvent);
      break;

     case c5_IN_state3:
      CV_STATE_EVAL(5, 0, 3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c5_sfEvent);
      c5_b_temp = (_SFD_CCP_CALL(9U, 0, chartInstance->c5_T_0 < *c5_T_acc != 0U,
        chartInstance->c5_sfEvent) != 0);
      if (c5_b_temp) {
        c5_b_temp = (_SFD_CCP_CALL(9U, 1, *c5_T_acc < chartInstance->c5_T_1 !=
          0U, chartInstance->c5_sfEvent) != 0);
      }

      if (CV_TRANSITION_EVAL(9U, (int32_T)c5_b_temp)) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 9;
          sf_debug_transition_conflict_check_begin();
          if (*c5_T_acc >= chartInstance->c5_T_1) {
            transitionList[numTransitions] = 11;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
        chartInstance->c5_b_tp_state3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
        chartInstance->c5_is_state1 = c5_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
        chartInstance->c5_d_tp_state1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c5_sfEvent);
        if (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0, *c5_T_acc >=
              chartInstance->c5_T_1 != 0U, chartInstance->c5_sfEvent))) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
          chartInstance->c5_b_tp_state3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
          chartInstance->c5_is_state1 = c5_IN_state2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
          chartInstance->c5_c_tp_state2 = 1U;
        } else {
          *c5_T_eng = chartInstance->c5_T_0;
          _SFD_DATA_RANGE_CHECK(*c5_T_eng, 2U);
          *c5_T_pm = *c5_T_acc - *c5_T_eng;
          _SFD_DATA_RANGE_CHECK(*c5_T_pm, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c5_sfEvent);
      break;

     default:
      CV_STATE_EVAL(5, 0, 0);
      chartInstance->c5_is_state1 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c5_sfEvent);
}

static void c5_exit_internal_state1(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c5_is_state1) {
   case c5_IN_state1:
    CV_STATE_EVAL(5, 1, 1);
    chartInstance->c5_d_tp_state1 = 0U;
    chartInstance->c5_is_state1 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_state2:
    CV_STATE_EVAL(5, 1, 2);
    chartInstance->c5_c_tp_state2 = 0U;
    chartInstance->c5_is_state1 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_state3:
    CV_STATE_EVAL(5, 1, 3);
    chartInstance->c5_b_tp_state3 = 0U;
    chartInstance->c5_is_state1 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 1, 0);
    chartInstance->c5_is_state1 = (uint8_T)c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

const mxArray *sf_c5_hyd_hyb_2_worth_sohrab_get_eml_resolved_functions_info(void)
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
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static int32_T c5_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
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
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)chartInstanceVoid;
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
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(uint8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static uint8_T c5_b_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_f_tp_state1, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_f_tp_state1),
    &c5_thisId);
  sf_mex_destroy(&c5_f_tp_state1);
  return c5_y;
}

static uint8_T c5_c_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
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
  const mxArray *c5_f_tp_state1;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)chartInstanceVoid;
  c5_f_tp_state1 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_f_tp_state1),
    &c5_thisId);
  sf_mex_destroy(&c5_f_tp_state1);
  *(uint8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static real_T c5_d_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_T_eng, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_T_eng), &c5_thisId);
  sf_mex_destroy(&c5_T_eng);
  return c5_y;
}

static real_T c5_e_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d18;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d18, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d18;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_T_eng;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)chartInstanceVoid;
  c5_T_eng = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_T_eng), &c5_thisId);
  sf_mex_destroy(&c5_T_eng);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint32_T c5_f_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *
  chartInstance, const mxArray *c5_b_temporalCounter_i2, const char_T
  *c5_identifier)
{
  uint32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_temporalCounter_i2),
    &c5_thisId);
  sf_mex_destroy(&c5_b_temporalCounter_i2);
  return c5_y;
}

static uint32_T c5_g_emlrt_marshallIn(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u1;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u1, 1, 7, 0U, 0, 0U, 0);
  c5_y = c5_u1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static const mxArray *c5_h_emlrt_marshallIn
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance, const mxArray
   *c5_b_setSimStateSideEffectsInfo, const char_T *c5_identifier)
{
  const mxArray *c5_y = NULL;
  emlrtMsgIdentifier c5_thisId;
  c5_y = NULL;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  sf_mex_assign(&c5_y, c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_setSimStateSideEffectsInfo), &c5_thisId));
  sf_mex_destroy(&c5_b_setSimStateSideEffectsInfo);
  return c5_y;
}

static const mxArray *c5_i_emlrt_marshallIn
  (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance, const mxArray *c5_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u));
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_hyd_hyb_2_worth_sohrab_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4091909328U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3614099014U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3698635689U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(905681625U);
}

mxArray *sf_c5_hyd_hyb_2_worth_sohrab_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(420314517U);
    pr[1] = (double)(788157332U);
    pr[2] = (double)(1895091618U);
    pr[3] = (double)(861921278U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_hyd_hyb_2_worth_sohrab(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[4],T\"T_eng\",},{M[1],M[6],T\"T_pm\",},{M[1],M[123],T\"eng_on\",},{M[8],M[0],T\"is_active_c5_hyd_hyb_2_worth_sohrab\",},{M[9],M[0],T\"is_c5_hyd_hyb_2_worth_sohrab\",},{M[9],M[12],T\"is_state2\",},{M[9],M[13],T\"is_state3\",},{M[9],M[65],T\"is_state4\",},{M[9],M[173],T\"is_state1\",},{M[11],M[0],T\"temporalCounter_i2\",S'et','os','ct'{{T\"at\",M[129],M[1]}}}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x4[7 65 160 182],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 12, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_hyd_hyb_2_worth_sohrab_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
    chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_worth_sohrabMachineNumber_,
           5,
           14,
           33,
           16,
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
          init_script_number_translation(_hyd_hyb_2_worth_sohrabMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_worth_sohrabMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_worth_sohrabMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"T_acc");
          _SFD_SET_DATA_PROPS(1,1,1,0,"soc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"T_eng");
          _SFD_SET_DATA_PROPS(3,2,0,1,"T_pm");
          _SFD_SET_DATA_PROPS(4,1,1,0,"x");
          _SFD_SET_DATA_PROPS(5,1,1,0,"veh_spd");
          _SFD_SET_DATA_PROPS(6,2,0,1,"eng_on");
          _SFD_SET_DATA_PROPS(7,1,1,0,"y");
          _SFD_SET_DATA_PROPS(8,10,0,0,"T_0");
          _SFD_SET_DATA_PROPS(9,10,0,0,"T_1");
          _SFD_SET_DATA_PROPS(10,10,0,0,"soc_1");
          _SFD_SET_DATA_PROPS(11,10,0,0,"soc_2");
          _SFD_SET_DATA_PROPS(12,10,0,0,"t_wait_1");
          _SFD_SET_DATA_PROPS(13,10,0,0,"t_wait_2");
          _SFD_SET_DATA_PROPS(14,10,0,0,"t_wait_3");
          _SFD_SET_DATA_PROPS(15,10,0,0,"veh_spd_0");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,11);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,3);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,9);
          _SFD_ST_SUBSTATE_INDEX(4,2,10);
          _SFD_ST_SUBSTATE_COUNT(5,3);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_INDEX(5,2,8);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,2);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20, 41, 54 };

          static unsigned int sEndGuardMap[] = { 18, 19, 37, 50, 63 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, 4, -3, -3 };

          _SFD_CV_INIT_TRANS(1,5,&(sStartGuardMap[0]),&(sEndGuardMap[0]),9,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20, 34 };

          static unsigned int sEndGuardMap[] = { 18, 19, 30, 43 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -3 };

          _SFD_CV_INIT_TRANS(15,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(19,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 27 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(29,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(31,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(20,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(7,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 30 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(13,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(18,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(22,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 27 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(26,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 27 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(32,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
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

        _SFD_TRANS_COV_WTS(1,0,5,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20, 41, 54 };

          static unsigned int sEndGuardMap[] = { 18, 19, 37, 50, 63 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              5,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,4,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20, 34 };

          static unsigned int sEndGuardMap[] = { 18, 19, 30, 43 };

          _SFD_TRANS_COV_MAPS(15,
                              0,NULL,NULL,
                              4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 25 };

          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(29,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 27 };

          _SFD_TRANS_COV_MAPS(29,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(25,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(25,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(21,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(21,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(31,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 35 };

          _SFD_TRANS_COV_MAPS(31,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(20,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          _SFD_TRANS_COV_MAPS(20,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 30 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(18,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(24,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(24,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(22,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 25 };

          _SFD_TRANS_COV_MAPS(22,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(23,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          _SFD_TRANS_COV_MAPS(23,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 25 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(30,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(30,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(26,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 27 };

          _SFD_TRANS_COV_MAPS(26,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(27,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(27,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(32,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 15, 0, 20 };

          static unsigned int sEndGuardMap[] = { 18, 19, 27 };

          _SFD_TRANS_COV_MAPS(32,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(28,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(28,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          real_T *c5_T_acc;
          real_T *c5_soc;
          real_T *c5_T_eng;
          real_T *c5_T_pm;
          real_T *c5_x;
          real_T *c5_veh_spd;
          real_T *c5_eng_on;
          real_T *c5_y;
          c5_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c5_eng_on = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_T_acc);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_soc);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_T_eng);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_T_pm);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_x);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_veh_spd);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_eng_on);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c5_T_0);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c5_T_1);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c5_soc_1);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c5_soc_2);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c5_t_wait_1);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c5_t_wait_2);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c5_t_wait_3);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c5_veh_spd_0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_worth_sohrabMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_hyd_hyb_2_worth_sohrab(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_hyd_hyb_2_worth_sohrab
    ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*) chartInstanceVar);
  initialize_c5_hyd_hyb_2_worth_sohrab
    ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_hyd_hyb_2_worth_sohrab(void *chartInstanceVar)
{
  enable_c5_hyd_hyb_2_worth_sohrab((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_hyd_hyb_2_worth_sohrab(void *chartInstanceVar)
{
  disable_c5_hyd_hyb_2_worth_sohrab((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_hyd_hyb_2_worth_sohrab(void *chartInstanceVar)
{
  sf_c5_hyd_hyb_2_worth_sohrab((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_hyd_hyb_2_worth_sohrab
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_hyd_hyb_2_worth_sohrab
    ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_hyd_hyb_2_worth_sohrab();/* state var info */
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

extern void sf_internal_set_sim_state_c5_hyd_hyb_2_worth_sohrab(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_hyd_hyb_2_worth_sohrab();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_hyd_hyb_2_worth_sohrab
    ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_hyd_hyb_2_worth_sohrab
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c5_hyd_hyb_2_worth_sohrab(S);
}

static void sf_opaque_set_sim_state_c5_hyd_hyb_2_worth_sohrab(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c5_hyd_hyb_2_worth_sohrab(S, st);
}

static void sf_opaque_terminate_c5_hyd_hyb_2_worth_sohrab(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_hyd_hyb_2_worth_sohrab
      ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_hyd_hyb_2_worth_sohrab
    ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_hyd_hyb_2_worth_sohrab(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_hyd_hyb_2_worth_sohrab
      ((SFc5_hyd_hyb_2_worth_sohrabInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_hyd_hyb_2_worth_sohrab(SimStruct *S)
{
  /* Actual parameters from chart:
     T_0 T_1 soc_1 soc_2 t_wait_1 t_wait_2 t_wait_3 veh_spd_0
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7",
    "p8" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T_0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T_1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for soc_1*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for soc_2*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for t_wait_1*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for t_wait_2*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for t_wait_3*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for veh_spd_0*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);
  ssSetNeedAbsoluteTime(S,1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_worth_sohrab",
      "hyd_hyb_2_worth_sohrab",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_worth_sohrab",
                "hyd_hyb_2_worth_sohrab",5,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_worth_sohrab",
      "hyd_hyb_2_worth_sohrab",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_worth_sohrab",
        "hyd_hyb_2_worth_sohrab",5,5);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_worth_sohrab",
        "hyd_hyb_2_worth_sohrab",5,3);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_worth_sohrab","hyd_hyb_2_worth_sohrab",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3096390163U));
  ssSetChecksum1(S,(1068533612U));
  ssSetChecksum2(S,(2961994286U));
  ssSetChecksum3(S,(3260442074U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_hyd_hyb_2_worth_sohrab(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_worth_sohrab",
      "hyd_hyb_2_worth_sohrab",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c5_hyd_hyb_2_worth_sohrab(SimStruct *S)
{
  SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *chartInstance;
  chartInstance = (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct *)malloc(sizeof
    (SFc5_hyd_hyb_2_worth_sohrabInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_hyd_hyb_2_worth_sohrabInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_hyd_hyb_2_worth_sohrab;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_hyd_hyb_2_worth_sohrab;
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

void c5_hyd_hyb_2_worth_sohrab_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_hyd_hyb_2_worth_sohrab(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_hyd_hyb_2_worth_sohrab(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_hyd_hyb_2_worth_sohrab(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_hyd_hyb_2_worth_sohrab_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
