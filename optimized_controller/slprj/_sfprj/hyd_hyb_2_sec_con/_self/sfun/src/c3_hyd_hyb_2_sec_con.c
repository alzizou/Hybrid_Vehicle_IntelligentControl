/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_sec_con_sfun.h"
#include "c3_hyd_hyb_2_sec_con.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_sec_con_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD          (0U)
#define c3_IN_state1                   (1U)
#define c3_IN_state2                   (2U)
#define c3_IN_state3                   (3U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void initialize_params_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static void enable_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void disable_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static void set_sim_state_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static void finalize_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void sf_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static void initSimStructsc3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static void c3_state1(SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance);
static void c3_exit_internal_state2(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void c3_exit_internal_state3(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int32_T c3_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_b_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_d_tp_state1, const char_T *c3_identifier);
static uint8_T c3_c_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_d_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_T_eng, const char_T *c3_identifier);
static real_T c3_e_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_g_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  real_T *c3_T_eng;
  real_T *c3_T_pm;
  real_T *c3_u;
  c3_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_state1 = 0U;
  chartInstance->c3_is_state2 = 0U;
  chartInstance->c3_b_tp_state2 = 0U;
  chartInstance->c3_b_tp_state1 = 0U;
  chartInstance->c3_tp_state2 = 0U;
  chartInstance->c3_tp_state3 = 0U;
  chartInstance->c3_is_state3 = 0U;
  chartInstance->c3_b_tp_state3 = 0U;
  chartInstance->c3_c_tp_state1 = 0U;
  chartInstance->c3_c_tp_state2 = 0U;
  chartInstance->c3_is_active_c3_hyd_hyb_2_sec_con = 0U;
  chartInstance->c3_is_c3_hyd_hyb_2_sec_con = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c3_T_eng = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c3_T_pm = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c3_u = 0.0;
  }
}

static void initialize_params_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  sf_set_error_prefix_string(
    "Error evaluating data 'T_0' in the parent workspace.\n");
  sf_mex_import_named("T_0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_T_0 = c3_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T_1' in the parent workspace.\n");
  sf_mex_import_named("T_1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_T_1 = c3_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'soc_1' in the parent workspace.\n");
  sf_mex_import_named("soc_1", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_soc_1 = c3_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'soc_2' in the parent workspace.\n");
  sf_mex_import_named("soc_2", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_soc_2 = c3_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 't_wait_1' in the parent workspace.\n");
  sf_mex_import_named("t_wait_1", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_t_wait_1 = c3_d4;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 't_wait_2' in the parent workspace.\n");
  sf_mex_import_named("t_wait_2", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_t_wait_2 = c3_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 't_wait_3' in the parent workspace.\n");
  sf_mex_import_named("t_wait_3", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_t_wait_3 = c3_d6;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'veh_spd_0' in the parent workspace.\n");
  sf_mex_import_named("veh_spd_0", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      &c3_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_veh_spd_0 = c3_d7;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'T_2' in the parent workspace.\n");
  sf_mex_import_named("T_2", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c3_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_T_2 = c3_d8;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c3_is_active_c3_hyd_hyb_2_sec_con == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_hyd_hyb_2_sec_con == c3_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state2 == c3_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_hyd_hyb_2_sec_con == c3_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state2 == c3_IN_state3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state2 == c3_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_hyd_hyb_2_sec_con == c3_IN_state3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state3 == c3_IN_state1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state3 == c3_IN_state2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  sf_debug_set_animation(c3_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T *c3_T_eng;
  real_T *c3_T_pm;
  real_T *c3_h_u;
  c3_h_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(7));
  c3_hoistedGlobal = *c3_T_eng;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_T_pm;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_h_u;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_is_active_c3_hyd_hyb_2_sec_con;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_c3_hyd_hyb_2_sec_con;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_state2;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_state3;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 6, c3_h_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_T_eng;
  real_T *c3_T_pm;
  real_T *c3_b_u;
  c3_b_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_T_eng = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "T_eng");
  *c3_T_pm = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    1)), "T_pm");
  *c3_b_u = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    2)), "u");
  chartInstance->c3_is_active_c3_hyd_hyb_2_sec_con = c3_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
     "is_active_c3_hyd_hyb_2_sec_con");
  chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
     "is_c3_hyd_hyb_2_sec_con");
  chartInstance->c3_is_state2 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "is_state2");
  chartInstance->c3_is_state3 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "is_state3");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 7)), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_hyd_hyb_2_sec_con(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_hyd_hyb_2_sec_con == c3_IN_state1) {
      chartInstance->c3_tp_state1 = 1U;
    } else {
      chartInstance->c3_tp_state1 = 0U;
    }

    if (chartInstance->c3_is_c3_hyd_hyb_2_sec_con == c3_IN_state2) {
      chartInstance->c3_b_tp_state2 = 1U;
    } else {
      chartInstance->c3_b_tp_state2 = 0U;
    }

    if (chartInstance->c3_is_state2 == c3_IN_state1) {
      chartInstance->c3_b_tp_state1 = 1U;
    } else {
      chartInstance->c3_b_tp_state1 = 0U;
    }

    if (chartInstance->c3_is_state2 == c3_IN_state2) {
      chartInstance->c3_tp_state2 = 1U;
    } else {
      chartInstance->c3_tp_state2 = 0U;
    }

    if (chartInstance->c3_is_state2 == c3_IN_state3) {
      chartInstance->c3_tp_state3 = 1U;
    } else {
      chartInstance->c3_tp_state3 = 0U;
    }

    if (chartInstance->c3_is_c3_hyd_hyb_2_sec_con == c3_IN_state3) {
      chartInstance->c3_b_tp_state3 = 1U;
    } else {
      chartInstance->c3_b_tp_state3 = 0U;
    }

    if (chartInstance->c3_is_state3 == c3_IN_state1) {
      chartInstance->c3_c_tp_state1 = 1U;
    } else {
      chartInstance->c3_c_tp_state1 = 0U;
    }

    if (chartInstance->c3_is_state3 == c3_IN_state2) {
      chartInstance->c3_c_tp_state2 = 1U;
    } else {
      chartInstance->c3_c_tp_state2 = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_c3_hyd_hyb_2_sec_con(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  real_T *c3_T_acc;
  real_T *c3_soc;
  real_T *c3_T_eng;
  real_T *c3_T_pm;
  real_T *c3_x;
  real_T *c3_veh_spd;
  real_T *c3_y;
  real_T *c3_u;
  real_T *c3_delta_p;
  c3_delta_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_hyd_hyb_2_sec_con(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_T_acc, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_soc, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_x, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_veh_spd, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_y, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_T_0, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_T_1, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_soc_1, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_soc_2, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_t_wait_1, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_t_wait_2, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_t_wait_3, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_veh_spd_0, 14U);
  _SFD_DATA_RANGE_CHECK(*c3_u, 15U);
  _SFD_DATA_RANGE_CHECK(*c3_delta_p, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_T_2, 17U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_hyd_hyb_2_sec_con(chartInstance);
  sf_debug_check_for_state_inconsistency(_hyd_hyb_2_sec_conMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_b_temp;
  boolean_T c3_c_temp;
  real_T *c3_soc;
  real_T *c3_T_acc;
  real_T *c3_u;
  real_T *c3_delta_p;
  real_T *c3_T_pm;
  real_T *c3_T_eng;
  real_T *c3_veh_spd;
  c3_delta_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  if ((int16_T)chartInstance->c3_is_active_c3_hyd_hyb_2_sec_con == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_hyd_hyb_2_sec_con = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_state1 = 1U;
  } else {
    switch (chartInstance->c3_is_c3_hyd_hyb_2_sec_con) {
     case c3_IN_state1:
      CV_CHART_EVAL(2, 0, 1);
      c3_state1(chartInstance);
      break;

     case c3_IN_state2:
      CV_CHART_EVAL(2, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c3_sfEvent);
      if (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0, *c3_soc <=
            chartInstance->c3_soc_1 != 0U, chartInstance->c3_sfEvent))) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 3;
          sf_debug_transition_conflict_check_begin();
          if ((*c3_soc >= chartInstance->c3_soc_1) && (*c3_T_acc <
               chartInstance->c3_T_0)) {
            transitionList[numTransitions] = 11;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        c3_exit_internal_state2(chartInstance);
        chartInstance->c3_b_tp_state2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_b_tp_state3 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c3_sfEvent);
        c3_temp = (_SFD_CCP_CALL(11U, 0, *c3_soc >= chartInstance->c3_soc_1 !=
                    0U, chartInstance->c3_sfEvent) != 0);
        if (c3_temp) {
          c3_temp = (_SFD_CCP_CALL(11U, 1, *c3_T_acc < chartInstance->c3_T_0 !=
                      0U, chartInstance->c3_sfEvent) != 0);
        }

        if (CV_TRANSITION_EVAL(11U, (int32_T)c3_temp)) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          c3_exit_internal_state2(chartInstance);
          chartInstance->c3_b_tp_state2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_state1 = 1U;
        } else {
          *c3_u = 2.0;
          _SFD_DATA_RANGE_CHECK(*c3_u, 15U);
          switch (chartInstance->c3_is_state2) {
           case c3_IN_state1:
            CV_STATE_EVAL(1, 0, 1);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                         chartInstance->c3_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                         chartInstance->c3_sfEvent);
            if (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0, *c3_T_acc >
                  chartInstance->c3_T_1 != 0U, chartInstance->c3_sfEvent))) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
              chartInstance->c3_b_tp_state1 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
              chartInstance->c3_is_state2 = c3_IN_state2;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_state2 = 1U;
            } else {
              *c3_T_pm = 1.8 * *c3_delta_p * ((chartInstance->c3_T_1 - *c3_T_acc)
                / 100.0);
              _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
              *c3_T_eng = *c3_T_acc - *c3_T_pm;
              _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
            break;

           case c3_IN_state2:
            CV_STATE_EVAL(1, 0, 2);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c3_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                         chartInstance->c3_sfEvent);
            if (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0, *c3_T_acc >
                  chartInstance->c3_T_2 != 0U, chartInstance->c3_sfEvent))) {
              if (sf_debug_transition_conflict_check_enabled()) {
                unsigned int transitionList[2];
                unsigned int numTransitions = 1;
                transitionList[0] = 6;
                sf_debug_transition_conflict_check_begin();
                if (*c3_T_acc <= chartInstance->c3_T_1) {
                  transitionList[numTransitions] = 9;
                  numTransitions++;
                }

                sf_debug_transition_conflict_check_end();
                if (numTransitions > 1) {
                  _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                }
              }

              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_state2 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
              chartInstance->c3_is_state2 = c3_IN_state3;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_state3 = 1U;
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                           chartInstance->c3_sfEvent);
              if (CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(9U, 0, *c3_T_acc
                    <= chartInstance->c3_T_1 != 0U, chartInstance->c3_sfEvent)))
              {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U,
                             chartInstance->c3_sfEvent);
                chartInstance->c3_tp_state2 = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
                chartInstance->c3_is_state2 = c3_IN_state1;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
                chartInstance->c3_b_tp_state1 = 1U;
              } else {
                *c3_T_eng = *c3_T_acc;
                _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
                *c3_T_pm = 0.0;
                _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
              }
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
            break;

           case c3_IN_state3:
            CV_STATE_EVAL(1, 0, 3);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                         chartInstance->c3_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                         chartInstance->c3_sfEvent);
            if (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0, *c3_T_acc <=
                  chartInstance->c3_T_2 != 0U, chartInstance->c3_sfEvent))) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_state3 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
              chartInstance->c3_is_state2 = c3_IN_state2;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_state2 = 1U;
            } else {
              *c3_T_eng = chartInstance->c3_T_2;
              _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
              *c3_T_pm = *c3_T_acc - *c3_T_eng;
              _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
            break;

           default:
            CV_STATE_EVAL(1, 0, 0);
            chartInstance->c3_is_state2 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
            break;
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_state3:
      CV_CHART_EVAL(2, 0, 3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c3_sfEvent);
      c3_b_temp = (_SFD_CCP_CALL(10U, 0, *c3_soc >= chartInstance->c3_soc_2 !=
        0U, chartInstance->c3_sfEvent) != 0);
      if (c3_b_temp) {
        c3_b_temp = (_SFD_CCP_CALL(10U, 1, *c3_T_acc < chartInstance->c3_T_0 !=
          0U, chartInstance->c3_sfEvent) != 0);
      }

      if (CV_TRANSITION_EVAL(10U, (int32_T)c3_b_temp)) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 10;
          sf_debug_transition_conflict_check_begin();
          if ((*c3_soc >= chartInstance->c3_soc_2) && (*c3_T_acc >
               chartInstance->c3_T_0)) {
            transitionList[numTransitions] = 4;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        c3_exit_internal_state3(chartInstance);
        chartInstance->c3_b_tp_state3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c3_sfEvent);
        c3_c_temp = (_SFD_CCP_CALL(4U, 0, *c3_soc >= chartInstance->c3_soc_2 !=
          0U, chartInstance->c3_sfEvent) != 0);
        if (c3_c_temp) {
          c3_c_temp = (_SFD_CCP_CALL(4U, 1, *c3_T_acc > chartInstance->c3_T_0 !=
            0U, chartInstance->c3_sfEvent) != 0);
        }

        if (CV_TRANSITION_EVAL(4U, (int32_T)c3_c_temp)) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          c3_exit_internal_state3(chartInstance);
          chartInstance->c3_b_tp_state3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_b_tp_state2 = 1U;
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                       chartInstance->c3_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_state2 = c3_IN_state1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_b_tp_state1 = 1U;
        } else {
          *c3_u = 3.0;
          _SFD_DATA_RANGE_CHECK(*c3_u, 15U);
          *c3_T_eng = *c3_T_acc;
          _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
          *c3_T_pm = 0.0;
          _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
          switch (chartInstance->c3_is_state3) {
           case c3_IN_state1:
            CV_STATE_EVAL(5, 0, 1);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                         chartInstance->c3_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                         chartInstance->c3_sfEvent);
            if (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
                  *c3_veh_spd <= 0.01 != 0U, chartInstance->c3_sfEvent))) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
              chartInstance->c3_c_tp_state1 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
              chartInstance->c3_is_state3 = c3_IN_state2;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
              chartInstance->c3_c_tp_state2 = 1U;
            } else {
              *c3_T_pm = -2.2 * *c3_delta_p;
              _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
              *c3_T_eng = -*c3_T_pm + *c3_T_acc;
              _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
              *c3_T_eng = muDoubleScalarMin(*c3_T_eng, 1100.0);
              _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
              *c3_T_pm = -*c3_T_eng + *c3_T_acc;
              _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
            break;

           case c3_IN_state2:
            CV_STATE_EVAL(5, 0, 2);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                         chartInstance->c3_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                         chartInstance->c3_sfEvent);
            if (CV_TRANSITION_EVAL(13U, (int32_T)_SFD_CCP_CALL(13U, 0, *c3_T_acc
                  > 0.1 != 0U, chartInstance->c3_sfEvent))) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
              chartInstance->c3_c_tp_state2 = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
              chartInstance->c3_is_state3 = c3_IN_state1;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
              chartInstance->c3_c_tp_state1 = 1U;
            } else {
              _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
              *c3_T_pm = 0.0;
              _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
            break;

           default:
            CV_STATE_EVAL(5, 0, 0);
            chartInstance->c3_is_state3 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            break;
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(2, 0, 0);
      chartInstance->c3_is_c3_hyd_hyb_2_sec_con = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_hyd_hyb_2_sec_con
  (SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
}

static void c3_state1(SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_b_temp;
  real_T *c3_soc;
  real_T *c3_veh_spd;
  real_T *c3_T_acc;
  real_T *c3_T_pm;
  real_T *c3_T_eng;
  real_T *c3_u;
  real_T *c3_delta_p;
  c3_delta_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
  if (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0, *c3_soc <=
        chartInstance->c3_soc_1 != 0U, chartInstance->c3_sfEvent))) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 2;
      sf_debug_transition_conflict_check_begin();
      if ((*c3_veh_spd > chartInstance->c3_veh_spd_0) && (*c3_T_acc >=
           chartInstance->c3_T_0) && (*c3_soc > chartInstance->c3_soc_1)) {
        transitionList[numTransitions] = 1;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_state1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_b_tp_state3 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
    c3_temp = (_SFD_CCP_CALL(1U, 0, *c3_veh_spd > chartInstance->c3_veh_spd_0 !=
                0U, chartInstance->c3_sfEvent) != 0);
    if (c3_temp) {
      c3_temp = (_SFD_CCP_CALL(1U, 1, *c3_T_acc >= chartInstance->c3_T_0 != 0U,
                  chartInstance->c3_sfEvent) != 0);
    }

    c3_b_temp = c3_temp;
    if (c3_b_temp) {
      c3_b_temp = (_SFD_CCP_CALL(1U, 2, *c3_soc > chartInstance->c3_soc_1 != 0U,
        chartInstance->c3_sfEvent) != 0);
    }

    if (CV_TRANSITION_EVAL(1U, (int32_T)c3_b_temp)) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_state1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_hyd_hyb_2_sec_con = c3_IN_state2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_state2 = 1U;
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_state2 = c3_IN_state1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_state1 = 1U;
    } else {
      *c3_T_pm = muDoubleScalarMin(1.8 * *c3_delta_p, *c3_T_acc);
      _SFD_DATA_RANGE_CHECK(*c3_T_pm, 3U);
      *c3_T_eng = *c3_T_acc - *c3_T_pm;
      _SFD_DATA_RANGE_CHECK(*c3_T_eng, 2U);
      *c3_u = 1.0;
      _SFD_DATA_RANGE_CHECK(*c3_u, 15U);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_state2(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c3_is_state2) {
   case c3_IN_state1:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c3_b_tp_state1 = 0U;
    chartInstance->c3_is_state2 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_state2:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c3_tp_state2 = 0U;
    chartInstance->c3_is_state2 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_state3:
    CV_STATE_EVAL(1, 1, 3);
    chartInstance->c3_tp_state3 = 0U;
    chartInstance->c3_is_state2 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c3_is_state2 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    break;
  }
}

static void c3_exit_internal_state3(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c3_is_state3) {
   case c3_IN_state1:
    CV_STATE_EVAL(5, 1, 1);
    chartInstance->c3_c_tp_state1 = 0U;
    chartInstance->c3_is_state3 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_state2:
    CV_STATE_EVAL(5, 1, 2);
    chartInstance->c3_c_tp_state2 = 0U;
    chartInstance->c3_is_state3 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 1, 0);
    chartInstance->c3_is_state3 = (uint8_T)c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

const mxArray *sf_c3_hyd_hyb_2_sec_con_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c3_nameCaptureInfo;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static int32_T c3_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static uint8_T c3_b_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_d_tp_state1, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_tp_state1),
    &c3_thisId);
  sf_mex_destroy(&c3_d_tp_state1);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_d_tp_state1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)chartInstanceVoid;
  c3_d_tp_state1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_tp_state1),
    &c3_thisId);
  sf_mex_destroy(&c3_d_tp_state1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static real_T c3_d_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_T_eng, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_T_eng), &c3_thisId);
  sf_mex_destroy(&c3_T_eng);
  return c3_y;
}

static real_T c3_e_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d9;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d9, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d9;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_T_eng;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)chartInstanceVoid;
  c3_T_eng = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_T_eng), &c3_thisId);
  sf_mex_destroy(&c3_T_eng);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId));
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_g_emlrt_marshallIn(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u));
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_hyd_hyb_2_sec_conInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_hyd_hyb_2_sec_con_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1062125880U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(920824091U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1062166627U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1640552574U);
}

mxArray *sf_c3_hyd_hyb_2_sec_con_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(122312156U);
    pr[1] = (double)(1518322144U);
    pr[2] = (double)(2546100918U);
    pr[3] = (double)(357005354U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c3_hyd_hyb_2_sec_con(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[4],T\"T_eng\",},{M[1],M[6],T\"T_pm\",},{M[1],M[215],T\"u\",},{M[8],M[0],T\"is_active_c3_hyd_hyb_2_sec_con\",},{M[9],M[0],T\"is_c3_hyd_hyb_2_sec_con\",},{M[9],M[12],T\"is_state2\",},{M[9],M[13],T\"is_state3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_hyd_hyb_2_sec_con_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
    chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_sec_conMachineNumber_,
           3,
           8,
           14,
           18,
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
          init_script_number_translation(_hyd_hyb_2_sec_conMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_sec_conMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_hyd_hyb_2_sec_conMachineNumber_,
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
          _SFD_SET_DATA_PROPS(6,1,1,0,"y");
          _SFD_SET_DATA_PROPS(7,10,0,0,"T_0");
          _SFD_SET_DATA_PROPS(8,10,0,0,"T_1");
          _SFD_SET_DATA_PROPS(9,10,0,0,"soc_1");
          _SFD_SET_DATA_PROPS(10,10,0,0,"soc_2");
          _SFD_SET_DATA_PROPS(11,10,0,0,"t_wait_1");
          _SFD_SET_DATA_PROPS(12,10,0,0,"t_wait_2");
          _SFD_SET_DATA_PROPS(13,10,0,0,"t_wait_3");
          _SFD_SET_DATA_PROPS(14,10,0,0,"veh_spd_0");
          _SFD_SET_DATA_PROPS(15,2,0,1,"u");
          _SFD_SET_DATA_PROPS(16,1,1,0,"delta_p");
          _SFD_SET_DATA_PROPS(17,10,0,0,"T_2");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,3,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(5,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 22, 36 };

          static unsigned int sEndGuardMap[] = { 18, 32, 45 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(1,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(10,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(11,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(13,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
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

        _SFD_TRANS_COV_WTS(1,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22, 36 };

          static unsigned int sEndGuardMap[] = { 18, 32, 45 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(3,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 15 };

          static unsigned int sEndGuardMap[] = { 11, 24 };

          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);

        {
          real_T *c3_T_acc;
          real_T *c3_soc;
          real_T *c3_T_eng;
          real_T *c3_T_pm;
          real_T *c3_x;
          real_T *c3_veh_spd;
          real_T *c3_y;
          real_T *c3_u;
          real_T *c3_delta_p;
          c3_delta_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_veh_spd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_T_pm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_T_eng = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_soc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_T_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_T_acc);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_soc);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_T_eng);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_T_pm);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_veh_spd);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_T_0);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c3_T_1);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_soc_1);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_soc_2);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_t_wait_1);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_t_wait_2);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_t_wait_3);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c3_veh_spd_0);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_u);
          _SFD_SET_DATA_VALUE_PTR(16U, c3_delta_p);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c3_T_2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_sec_conMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_hyd_hyb_2_sec_con(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar);
  initialize_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_hyd_hyb_2_sec_con(void *chartInstanceVar)
{
  enable_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_hyd_hyb_2_sec_con(void *chartInstanceVar)
{
  disable_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_hyd_hyb_2_sec_con(void *chartInstanceVar)
{
  sf_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_hyd_hyb_2_sec_con(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_hyd_hyb_2_sec_con
    ((SFc3_hyd_hyb_2_sec_conInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_hyd_hyb_2_sec_con();/* state var info */
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

extern void sf_internal_set_sim_state_c3_hyd_hyb_2_sec_con(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_hyd_hyb_2_sec_con();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_hyd_hyb_2_sec_con(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_hyd_hyb_2_sec_con(S);
}

static void sf_opaque_set_sim_state_c3_hyd_hyb_2_sec_con(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_hyd_hyb_2_sec_con(S, st);
}

static void sf_opaque_terminate_c3_hyd_hyb_2_sec_con(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_hyd_hyb_2_sec_conInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_hyd_hyb_2_sec_con(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_hyd_hyb_2_sec_con((SFc3_hyd_hyb_2_sec_conInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_hyd_hyb_2_sec_con(SimStruct *S)
{
  /* Actual parameters from chart:
     T_0 T_1 T_2 soc_1 soc_2 t_wait_1 t_wait_2 t_wait_3 veh_spd_0
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7",
    "p8", "p9" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T_0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for T_1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for T_2*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for soc_1*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for soc_2*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for t_wait_1*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for t_wait_2*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for t_wait_3*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for veh_spd_0*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_sec_con","hyd_hyb_2_sec_con",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_sec_con","hyd_hyb_2_sec_con",
                3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_sec_con",
      "hyd_hyb_2_sec_con",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_sec_con",
        "hyd_hyb_2_sec_con",3,6);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_sec_con","hyd_hyb_2_sec_con",3,
        3);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_sec_con","hyd_hyb_2_sec_con",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3427168569U));
  ssSetChecksum1(S,(1884878492U));
  ssSetChecksum2(S,(301504973U));
  ssSetChecksum3(S,(747540979U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_hyd_hyb_2_sec_con(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_sec_con", "hyd_hyb_2_sec_con",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_hyd_hyb_2_sec_con(SimStruct *S)
{
  SFc3_hyd_hyb_2_sec_conInstanceStruct *chartInstance;
  chartInstance = (SFc3_hyd_hyb_2_sec_conInstanceStruct *)malloc(sizeof
    (SFc3_hyd_hyb_2_sec_conInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_hyd_hyb_2_sec_conInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_hyd_hyb_2_sec_con;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_hyd_hyb_2_sec_con;
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

void c3_hyd_hyb_2_sec_con_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_hyd_hyb_2_sec_con(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_hyd_hyb_2_sec_con(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_hyd_hyb_2_sec_con(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_hyd_hyb_2_sec_con_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}