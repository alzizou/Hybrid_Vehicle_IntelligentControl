/* Include files */

#include "blascompat32.h"
#include "hyd_hyb_2_opt_cont_test_new_1_sfun.h"
#include "c16_hyd_hyb_2_opt_cont_test_new_1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hyd_hyb_2_opt_cont_test_new_1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c16_debug_family_names[5] = { "nargin", "nargout", "t",
  "fuz_wgt", "y" };

/* Function Declarations */
static void initialize_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void initialize_params_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void enable_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void disable_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_st);
static void finalize_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void sf_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void initSimStructsc16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_y, const char_T *c16_identifier);
static real_T c16_b_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_c_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_d_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_b_is_active_c16_hyd_hyb_2_opt_cont_test_new_1, const char_T
   *c16_identifier);
static uint8_T c16_e_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_hyd_hyb_2_opt_cont_test_new_1 = 0U;
}

static void initialize_params_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static void enable_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_hoistedGlobal;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  uint8_T c16_b_hoistedGlobal;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T *c16_d_y;
  c16_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(2));
  c16_hoistedGlobal = *c16_d_y;
  c16_u = c16_hoistedGlobal;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_hoistedGlobal =
    chartInstance->c16_is_active_c16_hyd_hyb_2_opt_cont_test_new_1;
  c16_b_u = c16_b_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y);
  return c16_st;
}

static void set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T *c16_y;
  c16_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  *c16_y = c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u,
    0)), "y");
  chartInstance->c16_is_active_c16_hyd_hyb_2_opt_cont_test_new_1 =
    c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
    "is_active_c16_hyd_hyb_2_opt_cont_test_new_1");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_hyd_hyb_2_opt_cont_test_new_1(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static void sf_c16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
  int32_T c16_i0;
  real_T c16_hoistedGlobal;
  real_T c16_t;
  int32_T c16_i1;
  real_T c16_fuz_wgt[24];
  uint32_T c16_debug_family_var_map[5];
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  real_T c16_y;
  real_T *c16_b_t;
  real_T *c16_b_y;
  real_T (*c16_b_fuz_wgt)[24];
  c16_b_fuz_wgt = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c16_b_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c16_b_y, 1U);
  for (c16_i0 = 0; c16_i0 < 24; c16_i0++) {
    _SFD_DATA_RANGE_CHECK((*c16_b_fuz_wgt)[c16_i0], 2U);
  }

  chartInstance->c16_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *c16_b_t;
  c16_t = c16_hoistedGlobal;
  for (c16_i1 = 0; c16_i1 < 24; c16_i1++) {
    c16_fuz_wgt[c16_i1] = (*c16_b_fuz_wgt)[c16_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c16_debug_family_names,
    c16_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c16_nargin, 0U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c16_nargout, 1U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c16_t, 2U, c16_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c16_fuz_wgt, 3U, c16_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c16_y, 4U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 2);
  if (CV_EML_IF(0, 0, c16_t <= 100.0)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 3);
    c16_y = c16_fuz_wgt[3];
  } else {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 4);
    if (CV_EML_IF(0, 1, c16_t <= 200.0)) {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 5);
      c16_y = c16_fuz_wgt[7];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 6);
      if (CV_EML_IF(0, 2, c16_t <= 300.0)) {
        _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
        c16_y = c16_fuz_wgt[11];
      } else {
        _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 8);
        if (CV_EML_IF(0, 3, c16_t <= 400.0)) {
          _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
          c16_y = c16_fuz_wgt[15];
        } else {
          _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
          if (CV_EML_IF(0, 4, c16_t <= 500.0)) {
            _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
            c16_y = c16_fuz_wgt[19];
          } else {
            _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 13);
            c16_y = c16_fuz_wgt[23];
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -13);
  sf_debug_symbol_scope_pop();
  *c16_b_y = c16_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc16_hyd_hyb_2_opt_cont_test_new_1
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static real_T c16_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_y, const char_T *c16_identifier)
{
  real_T c16_b_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId);
  sf_mex_destroy(&c16_y);
  return c16_b_y;
}

static real_T c16_b_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_y;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_b_y;
  SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c16_y = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId);
  sf_mex_destroy(&c16_y);
  *(real_T *)c16_outData = c16_b_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i2;
  int32_T c16_i3;
  int32_T c16_i4;
  real_T c16_b_inData[24];
  int32_T c16_i5;
  int32_T c16_i6;
  int32_T c16_i7;
  real_T c16_u[24];
  const mxArray *c16_y = NULL;
  SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 6; c16_i3++) {
    for (c16_i4 = 0; c16_i4 < 4; c16_i4++) {
      c16_b_inData[c16_i4 + c16_i2] = (*(real_T (*)[24])c16_inData)[c16_i4 +
        c16_i2];
    }

    c16_i2 += 4;
  }

  c16_i5 = 0;
  for (c16_i6 = 0; c16_i6 < 6; c16_i6++) {
    for (c16_i7 = 0; c16_i7 < 4; c16_i7++) {
      c16_u[c16_i7 + c16_i5] = c16_b_inData[c16_i7 + c16_i5];
    }

    c16_i5 += 4;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 4, 6));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

const mxArray
  *sf_c16_hyd_hyb_2_opt_cont_test_new_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c16_nameCaptureInfo;
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static int32_T c16_c_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i8;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i8, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i8;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
    chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_d_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_b_is_active_c16_hyd_hyb_2_opt_cont_test_new_1, const char_T
   *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_hyd_hyb_2_opt_cont_test_new_1), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_hyd_hyb_2_opt_cont_test_new_1);
  return c16_y;
}

static uint8_T c16_e_emlrt_marshallIn
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info
  (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c16_hyd_hyb_2_opt_cont_test_new_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2962953778U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2390965203U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3213733075U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3457678894U);
}

mxArray *sf_c16_hyd_hyb_2_opt_cont_test_new_1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1513227389U);
    pr[1] = (double)(3396594670U);
    pr[2] = (double)(4280561040U);
    pr[3] = (double)(2876442459U);
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
      pr[0] = (double)(4);
      pr[1] = (double)(6);
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

static const mxArray *sf_get_sim_state_info_c16_hyd_hyb_2_opt_cont_test_new_1
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c16_hyd_hyb_2_opt_cont_test_new_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_hyd_hyb_2_opt_cont_test_new_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
    chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
           16,
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
            (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"fuz_wgt");
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
        _SFD_CV_INIT_EML(0,1,5,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,222);
        _SFD_CV_INIT_EML_IF(0,0,28,37,58,222);
        _SFD_CV_INIT_EML_IF(0,1,58,71,92,222);
        _SFD_CV_INIT_EML_IF(0,2,92,105,126,222);
        _SFD_CV_INIT_EML_IF(0,3,126,139,160,222);
        _SFD_CV_INIT_EML_IF(0,4,160,173,194,222);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c16_t;
          real_T *c16_y;
          real_T (*c16_fuz_wgt)[24];
          c16_fuz_wgt = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 1);
          c16_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c16_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c16_t);
          _SFD_SET_DATA_VALUE_PTR(1U, c16_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_fuz_wgt);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hyd_hyb_2_opt_cont_test_new_1MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c16_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
  initialize_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  enable_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  disable_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  sf_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_hyd_hyb_2_opt_cont_test_new_1();/* state var info */
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

extern void sf_internal_set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_hyd_hyb_2_opt_cont_test_new_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1(S);
}

static void sf_opaque_set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1(S, st);
}

static void sf_opaque_terminate_c16_hyd_hyb_2_opt_cont_test_new_1(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c16_hyd_hyb_2_opt_cont_test_new_1
      ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_hyd_hyb_2_opt_cont_test_new_1
    ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_hyd_hyb_2_opt_cont_test_new_1
      ((SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"hyd_hyb_2_opt_cont_test_new_1",
      "hyd_hyb_2_opt_cont_test_new_1",16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"hyd_hyb_2_opt_cont_test_new_1",
                "hyd_hyb_2_opt_cont_test_new_1",16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "hyd_hyb_2_opt_cont_test_new_1","hyd_hyb_2_opt_cont_test_new_1",16,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"hyd_hyb_2_opt_cont_test_new_1",
        "hyd_hyb_2_opt_cont_test_new_1",16,2);
      sf_mark_chart_reusable_outputs(S,"hyd_hyb_2_opt_cont_test_new_1",
        "hyd_hyb_2_opt_cont_test_new_1",16,1);
    }

    sf_set_rtw_dwork_info(S,"hyd_hyb_2_opt_cont_test_new_1",
                          "hyd_hyb_2_opt_cont_test_new_1",16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3553952523U));
  ssSetChecksum1(S,(1176023698U));
  ssSetChecksum2(S,(2636221064U));
  ssSetChecksum3(S,(2649815784U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c16_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "hyd_hyb_2_opt_cont_test_new_1",
      "hyd_hyb_2_opt_cont_test_new_1",16);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_hyd_hyb_2_opt_cont_test_new_1(SimStruct *S)
{
  SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *chartInstance;
  chartInstance = (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct *)malloc
    (sizeof(SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc16_hyd_hyb_2_opt_cont_test_new_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_hyd_hyb_2_opt_cont_test_new_1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_hyd_hyb_2_opt_cont_test_new_1;
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

void c16_hyd_hyb_2_opt_cont_test_new_1_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_hyd_hyb_2_opt_cont_test_new_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_hyd_hyb_2_opt_cont_test_new_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_hyd_hyb_2_opt_cont_test_new_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_hyd_hyb_2_opt_cont_test_new_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
