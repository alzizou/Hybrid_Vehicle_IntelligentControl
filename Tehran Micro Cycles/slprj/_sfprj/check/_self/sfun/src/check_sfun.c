/* Include files */

#include "check_sfun.h"
#include "c1_check.h"
#include "c2_check.h"
#include "c3_check.h"
#include "c4_check.h"
#include "c5_check.h"
#include "c6_check.h"
#include "c7_check.h"
#include "c8_check.h"
#include "c9_check.h"
#include "c10_check.h"
#include "c11_check.h"
#include "c12_check.h"
#include "c13_check.h"
#include "c14_check.h"
#include "c15_check.h"
#include "c16_check.h"
#include "c17_check.h"
#include "c18_check.h"
#include "c19_check.h"
#include "c20_check.h"
#include "c21_check.h"
#include "c22_check.h"
#include "c23_check.h"
#include "c36_check.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _checkMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void check_initializer(void)
{
}

void check_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_check_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_check_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_check_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2986942107U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(654767629U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3071975530U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(836901898U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(979250113U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1596652870U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2172652913U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2072701112U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_check_get_check_sum(mxArray *plhs[]);
          sf_c1_check_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_check_get_check_sum(mxArray *plhs[]);
          sf_c2_check_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_check_get_check_sum(mxArray *plhs[]);
          sf_c3_check_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_check_get_check_sum(mxArray *plhs[]);
          sf_c4_check_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_check_get_check_sum(mxArray *plhs[]);
          sf_c5_check_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_check_get_check_sum(mxArray *plhs[]);
          sf_c6_check_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_check_get_check_sum(mxArray *plhs[]);
          sf_c7_check_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_check_get_check_sum(mxArray *plhs[]);
          sf_c8_check_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_check_get_check_sum(mxArray *plhs[]);
          sf_c9_check_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_check_get_check_sum(mxArray *plhs[]);
          sf_c10_check_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_check_get_check_sum(mxArray *plhs[]);
          sf_c11_check_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_check_get_check_sum(mxArray *plhs[]);
          sf_c12_check_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_check_get_check_sum(mxArray *plhs[]);
          sf_c13_check_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_check_get_check_sum(mxArray *plhs[]);
          sf_c14_check_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_check_get_check_sum(mxArray *plhs[]);
          sf_c15_check_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_check_get_check_sum(mxArray *plhs[]);
          sf_c16_check_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_check_get_check_sum(mxArray *plhs[]);
          sf_c17_check_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_check_get_check_sum(mxArray *plhs[]);
          sf_c18_check_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_check_get_check_sum(mxArray *plhs[]);
          sf_c19_check_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_check_get_check_sum(mxArray *plhs[]);
          sf_c20_check_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_check_get_check_sum(mxArray *plhs[]);
          sf_c21_check_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_check_get_check_sum(mxArray *plhs[]);
          sf_c22_check_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_check_get_check_sum(mxArray *plhs[]);
          sf_c23_check_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_check_get_check_sum(mxArray *plhs[]);
          sf_c36_check_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3797712458U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2868645118U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2989932681U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3791834336U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_check_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_check_get_autoinheritance_info(void);
        plhs[0] = sf_c1_check_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_check_get_autoinheritance_info(void);
        plhs[0] = sf_c2_check_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_check_get_autoinheritance_info(void);
        plhs[0] = sf_c3_check_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_check_get_autoinheritance_info(void);
        plhs[0] = sf_c4_check_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_check_get_autoinheritance_info(void);
        plhs[0] = sf_c5_check_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_check_get_autoinheritance_info(void);
        plhs[0] = sf_c6_check_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_check_get_autoinheritance_info(void);
        plhs[0] = sf_c7_check_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_check_get_autoinheritance_info(void);
        plhs[0] = sf_c8_check_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_check_get_autoinheritance_info(void);
        plhs[0] = sf_c9_check_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_check_get_autoinheritance_info(void);
        plhs[0] = sf_c10_check_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_check_get_autoinheritance_info(void);
        plhs[0] = sf_c11_check_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_check_get_autoinheritance_info(void);
        plhs[0] = sf_c12_check_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_check_get_autoinheritance_info(void);
        plhs[0] = sf_c13_check_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray *sf_c14_check_get_autoinheritance_info(void);
        plhs[0] = sf_c14_check_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray *sf_c15_check_get_autoinheritance_info(void);
        plhs[0] = sf_c15_check_get_autoinheritance_info();
        break;
      }

     case 16:
      {
        extern mxArray *sf_c16_check_get_autoinheritance_info(void);
        plhs[0] = sf_c16_check_get_autoinheritance_info();
        break;
      }

     case 17:
      {
        extern mxArray *sf_c17_check_get_autoinheritance_info(void);
        plhs[0] = sf_c17_check_get_autoinheritance_info();
        break;
      }

     case 18:
      {
        extern mxArray *sf_c18_check_get_autoinheritance_info(void);
        plhs[0] = sf_c18_check_get_autoinheritance_info();
        break;
      }

     case 19:
      {
        extern mxArray *sf_c19_check_get_autoinheritance_info(void);
        plhs[0] = sf_c19_check_get_autoinheritance_info();
        break;
      }

     case 20:
      {
        extern mxArray *sf_c20_check_get_autoinheritance_info(void);
        plhs[0] = sf_c20_check_get_autoinheritance_info();
        break;
      }

     case 21:
      {
        extern mxArray *sf_c21_check_get_autoinheritance_info(void);
        plhs[0] = sf_c21_check_get_autoinheritance_info();
        break;
      }

     case 22:
      {
        extern mxArray *sf_c22_check_get_autoinheritance_info(void);
        plhs[0] = sf_c22_check_get_autoinheritance_info();
        break;
      }

     case 23:
      {
        extern mxArray *sf_c23_check_get_autoinheritance_info(void);
        plhs[0] = sf_c23_check_get_autoinheritance_info();
        break;
      }

     case 36:
      {
        extern mxArray *sf_c36_check_get_autoinheritance_info(void);
        plhs[0] = sf_c36_check_get_autoinheritance_info();
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

unsigned int sf_check_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray *sf_c19_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray *sf_c21_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray *sf_c23_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_check_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray *sf_c36_check_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_check_get_eml_resolved_functions_info();
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

void check_debug_initialize(void)
{
  _checkMachineNumber_ = sf_debug_initialize_machine("check","sfun",0,24,0,0,0);
  sf_debug_set_machine_event_thresholds(_checkMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_checkMachineNumber_,0);
}

void check_register_exported_symbols(SimStruct* S)
{
}
