/* Include files */

#include "hyd_hyb_2_opt_cont_test_new_1_col_cd_sfun.h"
#include "c1_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c2_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c3_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c4_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c5_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c6_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c7_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c8_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c10_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c11_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c12_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c13_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c14_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c15_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c16_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c17_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c18_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c19_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c20_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c21_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c22_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c23_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c24_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c25_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c28_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c29_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c30_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c31_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c32_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c33_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c34_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c35_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c36_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c37_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c38_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c39_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c40_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c41_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c42_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c43_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c44_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c45_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c46_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c47_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"
#include "c48_hyd_hyb_2_opt_cont_test_new_1_col_cd.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hyd_hyb_2_opt_cont_test_new_1_col_cdMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void hyd_hyb_2_opt_cont_test_new_1_col_cd_initializer(void)
{
}

void hyd_hyb_2_opt_cont_test_new_1_col_cd_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==32) {
    c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==33) {
    c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==34) {
    c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==42) {
    c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==45) {
    c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==46) {
    c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==47) {
    c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==48) {
    c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_hyd_hyb_2_opt_cont_test_new_1_col_cd_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2410840654U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1083043919U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1968566316U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3824405136U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(391067941U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2432093556U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4241771561U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3420947784U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 32:
        {
          extern void sf_c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 33:
        {
          extern void sf_c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 34:
        {
          extern void sf_c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 42:
        {
          extern void sf_c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 45:
        {
          extern void sf_c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 46:
        {
          extern void sf_c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 47:
        {
          extern void sf_c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
          break;
        }

       case 48:
        {
          extern void sf_c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum
            (mxArray *plhs[]);
          sf_c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1000338504U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2750713553U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(443112641U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1561470256U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hyd_hyb_2_opt_cont_test_new_1_col_cd_autoinheritance_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        extern mxArray
          *sf_c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray
          *sf_c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray
          *sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray
          *sf_c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray
          *sf_c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray
          *sf_c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray
          *sf_c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray
          *sf_c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray
          *sf_c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray
          *sf_c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray
          *sf_c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray
          *sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray
          *sf_c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray
          *sf_c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 16:
      {
        extern mxArray
          *sf_c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 17:
      {
        extern mxArray
          *sf_c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 18:
      {
        extern mxArray
          *sf_c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 19:
      {
        extern mxArray
          *sf_c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 20:
      {
        extern mxArray
          *sf_c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 21:
      {
        extern mxArray
          *sf_c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 22:
      {
        extern mxArray
          *sf_c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 23:
      {
        extern mxArray
          *sf_c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 24:
      {
        extern mxArray
          *sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 25:
      {
        extern mxArray
          *sf_c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 28:
      {
        extern mxArray
          *sf_c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 29:
      {
        extern mxArray
          *sf_c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 30:
      {
        extern mxArray
          *sf_c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 31:
      {
        extern mxArray
          *sf_c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 32:
      {
        extern mxArray
          *sf_c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 33:
      {
        extern mxArray
          *sf_c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 34:
      {
        extern mxArray
          *sf_c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 35:
      {
        extern mxArray
          *sf_c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 36:
      {
        extern mxArray
          *sf_c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 37:
      {
        extern mxArray
          *sf_c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 38:
      {
        extern mxArray
          *sf_c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 39:
      {
        extern mxArray
          *sf_c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 40:
      {
        extern mxArray
          *sf_c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 41:
      {
        extern mxArray
          *sf_c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 42:
      {
        extern mxArray
          *sf_c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 43:
      {
        extern mxArray
          *sf_c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 44:
      {
        extern mxArray
          *sf_c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 45:
      {
        extern mxArray
          *sf_c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 46:
      {
        extern mxArray
          *sf_c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 47:
      {
        extern mxArray
          *sf_c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
        break;
      }

     case 48:
      {
        extern mxArray
          *sf_c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_autoinheritance_info();
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

unsigned int
  sf_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info( int
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
          *sf_c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray
          *sf_c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray
          *sf_c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray
          *sf_c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 32:
      {
        extern const mxArray
          *sf_c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c32_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 33:
      {
        extern const mxArray
          *sf_c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c33_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 34:
      {
        extern const mxArray
          *sf_c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c34_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray
          *sf_c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray
          *sf_c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray
          *sf_c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray
          *sf_c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 42:
      {
        extern const mxArray
          *sf_c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c42_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray
          *sf_c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 45:
      {
        extern const mxArray
          *sf_c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c45_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 46:
      {
        extern const mxArray
          *sf_c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c46_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 47:
      {
        extern const mxArray
          *sf_c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c47_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 48:
      {
        extern const mxArray
          *sf_c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c48_hyd_hyb_2_opt_cont_test_new_1_col_cd_get_eml_resolved_functions_info
          ();
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

void hyd_hyb_2_opt_cont_test_new_1_col_cd_debug_initialize(void)
{
  _hyd_hyb_2_opt_cont_test_new_1_col_cdMachineNumber_ =
    sf_debug_initialize_machine("hyd_hyb_2_opt_cont_test_new_1_col_cd","sfun",0,
    45,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_hyd_hyb_2_opt_cont_test_new_1_col_cdMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_hyd_hyb_2_opt_cont_test_new_1_col_cdMachineNumber_,0);
}

void hyd_hyb_2_opt_cont_test_new_1_col_cd_register_exported_symbols(SimStruct* S)
{
}