/* Include files */

#include "hyd_hyb_2_int_cont_1_new1_sfun.h"
#include "c1_hyd_hyb_2_int_cont_1_new1.h"
#include "c2_hyd_hyb_2_int_cont_1_new1.h"
#include "c3_hyd_hyb_2_int_cont_1_new1.h"
#include "c4_hyd_hyb_2_int_cont_1_new1.h"
#include "c5_hyd_hyb_2_int_cont_1_new1.h"
#include "c6_hyd_hyb_2_int_cont_1_new1.h"
#include "c7_hyd_hyb_2_int_cont_1_new1.h"
#include "c8_hyd_hyb_2_int_cont_1_new1.h"
#include "c13_hyd_hyb_2_int_cont_1_new1.h"
#include "c14_hyd_hyb_2_int_cont_1_new1.h"
#include "c15_hyd_hyb_2_int_cont_1_new1.h"
#include "c16_hyd_hyb_2_int_cont_1_new1.h"
#include "c17_hyd_hyb_2_int_cont_1_new1.h"
#include "c18_hyd_hyb_2_int_cont_1_new1.h"
#include "c36_hyd_hyb_2_int_cont_1_new1.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hyd_hyb_2_int_cont_1_new1MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void hyd_hyb_2_int_cont_1_new1_initializer(void)
{
}

void hyd_hyb_2_int_cont_1_new1_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hyd_hyb_2_int_cont_1_new1_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_hyd_hyb_2_int_cont_1_new1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_hyd_hyb_2_int_cont_1_new1_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2479044343U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(147064661U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1758731876U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3082988869U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2611639488U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2506838550U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2569899910U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1000115390U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c1_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c2_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c3_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c4_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c5_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c6_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c7_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c8_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c13_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c14_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c15_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c16_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c17_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c18_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_hyd_hyb_2_int_cont_1_new1_get_check_sum(mxArray
            *plhs[]);
          sf_c36_hyd_hyb_2_int_cont_1_new1_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3134385271U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1721437009U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3922833535U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2545106865U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hyd_hyb_2_int_cont_1_new1_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        extern mxArray *sf_c1_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c1_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c2_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c3_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c4_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c5_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c6_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c7_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info
          (void);
        plhs[0] = sf_c8_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray
          *sf_c13_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c13_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray
          *sf_c14_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c14_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray
          *sf_c15_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c15_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 16:
      {
        extern mxArray
          *sf_c16_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c16_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 17:
      {
        extern mxArray
          *sf_c17_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c17_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 18:
      {
        extern mxArray
          *sf_c18_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c18_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
        break;
      }

     case 36:
      {
        extern mxArray
          *sf_c36_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info(void);
        plhs[0] = sf_c36_hyd_hyb_2_int_cont_1_new1_get_autoinheritance_info();
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

unsigned int sf_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info( int
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
          *sf_c1_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_hyd_hyb_2_int_cont_1_new1_get_eml_resolved_functions_info();
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

void hyd_hyb_2_int_cont_1_new1_debug_initialize(void)
{
  _hyd_hyb_2_int_cont_1_new1MachineNumber_ = sf_debug_initialize_machine(
    "hyd_hyb_2_int_cont_1_new1","sfun",0,15,0,0,0);
  sf_debug_set_machine_event_thresholds(_hyd_hyb_2_int_cont_1_new1MachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(_hyd_hyb_2_int_cont_1_new1MachineNumber_,
    0);
}

void hyd_hyb_2_int_cont_1_new1_register_exported_symbols(SimStruct* S)
{
}
