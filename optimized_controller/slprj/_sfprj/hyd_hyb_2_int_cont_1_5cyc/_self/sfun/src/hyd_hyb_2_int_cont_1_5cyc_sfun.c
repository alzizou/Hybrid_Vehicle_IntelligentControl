/* Include files */

#include "hyd_hyb_2_int_cont_1_5cyc_sfun.h"
#include "hyd_hyb_2_int_cont_1_5cyc_sfun_debug_macros.h"
#include "c1_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c2_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c3_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c4_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c5_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c6_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c7_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c8_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c9_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c13_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c14_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c15_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c16_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c17_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c18_hyd_hyb_2_int_cont_1_5cyc.h"
#include "c36_hyd_hyb_2_int_cont_1_5cyc.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hyd_hyb_2_int_cont_1_5cycMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void hyd_hyb_2_int_cont_1_5cyc_initializer(void)
{
}

void hyd_hyb_2_int_cont_1_5cyc_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_hyd_hyb_2_int_cont_1_5cyc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_hyd_hyb_2_int_cont_1_5cyc_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2534403004U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(440911473U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2476446256U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1794942282U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(692187407U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2002211690U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4096783046U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3436791929U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c1_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c2_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c3_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c4_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c5_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c6_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c7_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c8_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c9_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c13_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c14_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c15_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c17_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(mxArray
            *plhs[]);
          sf_c36_hyd_hyb_2_int_cont_1_5cyc_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2431866314U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1595681798U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1939509476U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1777952812U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hyd_hyb_2_int_cont_1_5cyc_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "HeXR70HF7FdajaQiEvOCWE") == 0) {
          extern mxArray
            *sf_c1_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c1_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "buEdDiJeCL0UvMIFDR77MG") == 0) {
          extern mxArray
            *sf_c2_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c2_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "RP3jEsGDSb6rQvHPyxLHyD") == 0) {
          extern mxArray
            *sf_c3_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c3_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "HeXR70HF7FdajaQiEvOCWE") == 0) {
          extern mxArray
            *sf_c4_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c4_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "wHTZIBrlKutJJ57hFpH4WB") == 0) {
          extern mxArray
            *sf_c5_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c5_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "wHTZIBrlKutJJ57hFpH4WB") == 0) {
          extern mxArray
            *sf_c6_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c6_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "wHTZIBrlKutJJ57hFpH4WB") == 0) {
          extern mxArray
            *sf_c7_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c7_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "PjB00zsRQnRT2ZoSP5lJ3D") == 0) {
          extern mxArray
            *sf_c8_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c8_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "wHTZIBrlKutJJ57hFpH4WB") == 0) {
          extern mxArray
            *sf_c9_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c9_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "t5uo7mXgY4tXHNCOdt5sME") == 0) {
          extern mxArray
            *sf_c13_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c13_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "AOWyLfiRuJQt71sAdGw8eD") == 0) {
          extern mxArray
            *sf_c14_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c14_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "t5uo7mXgY4tXHNCOdt5sME") == 0) {
          extern mxArray
            *sf_c15_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c15_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "t5uo7mXgY4tXHNCOdt5sME") == 0) {
          extern mxArray
            *sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "t5uo7mXgY4tXHNCOdt5sME") == 0) {
          extern mxArray
            *sf_c17_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c17_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "t5uo7mXgY4tXHNCOdt5sME") == 0) {
          extern mxArray
            *sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "6qhtE8r7aX00C5ZWC0VbWD") == 0) {
          extern mxArray
            *sf_c36_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info(void);
          plhs[0] = sf_c36_hyd_hyb_2_int_cont_1_5cyc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_hyd_hyb_2_int_cont_1_5cyc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "3KqcNMO07lLEz2qMVAvy4F") == 0) {
          extern mxArray *sf_c1_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c1_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "b8SbKBHuXySFDNUnDDZf7B") == 0) {
          extern mxArray *sf_c2_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c2_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "axkH4OEjV51HOflJemv5X") == 0) {
          extern mxArray *sf_c3_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c3_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6MibvvTT4RM5WZImZIQcjG") == 0) {
          extern mxArray *sf_c4_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c4_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray *sf_c5_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c5_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray *sf_c6_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c6_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray *sf_c7_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c7_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7Xvxv5yNglEZz35DKWTaHE") == 0) {
          extern mxArray *sf_c8_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c8_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray *sf_c9_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c9_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray *sf_c13_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c13_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "TZt2V0GSxfKyFt0VjyY1W") == 0) {
          extern mxArray *sf_c14_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c14_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray *sf_c15_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c15_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray *sf_c16_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c16_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray *sf_c17_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c17_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray *sf_c18_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c18_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "bSvf4nIv11Zaj8nDjkIMQE") == 0) {
          extern mxArray *sf_c36_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info
            (void);
          plhs[0] = sf_c36_hyd_hyb_2_int_cont_1_5cyc_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "3KqcNMO07lLEz2qMVAvy4F") == 0) {
          extern mxArray
            *sf_c1_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "b8SbKBHuXySFDNUnDDZf7B") == 0) {
          extern mxArray
            *sf_c2_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "axkH4OEjV51HOflJemv5X") == 0) {
          extern mxArray
            *sf_c3_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6MibvvTT4RM5WZImZIQcjG") == 0) {
          extern mxArray
            *sf_c4_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray
            *sf_c5_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray
            *sf_c6_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray
            *sf_c7_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7Xvxv5yNglEZz35DKWTaHE") == 0) {
          extern mxArray
            *sf_c8_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "jebvWqAfBhdwQThpKLQOFB") == 0) {
          extern mxArray
            *sf_c9_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray
            *sf_c13_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "TZt2V0GSxfKyFt0VjyY1W") == 0) {
          extern mxArray
            *sf_c14_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray
            *sf_c15_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray
            *sf_c16_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray
            *sf_c17_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "KpEfpIZ5TEYtb97ZNT0aN") == 0) {
          extern mxArray
            *sf_c18_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "bSvf4nIv11Zaj8nDjkIMQE") == 0) {
          extern mxArray
            *sf_c36_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_hyd_hyb_2_int_cont_1_5cyc_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void hyd_hyb_2_int_cont_1_5cyc_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _hyd_hyb_2_int_cont_1_5cycMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"hyd_hyb_2_int_cont_1_5cyc","sfun",0,16,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _hyd_hyb_2_int_cont_1_5cycMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _hyd_hyb_2_int_cont_1_5cycMachineNumber_,0);
}

void hyd_hyb_2_int_cont_1_5cyc_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_hyd_hyb_2_int_cont_1_5cyc_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "hyd_hyb_2_int_cont_1_5cyc", "hyd_hyb_2_int_cont_1_5cyc");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_hyd_hyb_2_int_cont_1_5cyc_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
