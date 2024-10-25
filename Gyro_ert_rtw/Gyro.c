/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Gyro.c
 *
 * Code generated for Simulink model 'Gyro'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Sep 28 02:56:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Gyro.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_Gyro_T Gyro_DW;

/* Real-time model */
static RT_MODEL_Gyro_T Gyro_M_;
RT_MODEL_Gyro_T *const Gyro_M = &Gyro_M_;

/* Model step function */
void Gyro_step(void)
{
  real_T outData;
  int32_T i;
  real32_T out[3];
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];

  /* MATLABSystem: '<S4>/MATLAB System' */
  out[0] = 0.0F;
  out[1] = 0.0F;
  out[2] = 0.0F;
  GET_GYROSCOPE_DATA(&out[0], &out[1], &out[2]);

  /* MATLABSystem: '<S1>/DataDisplay' incorporates:
   *  MATLABSystem: '<S2>/DataDisplay'
   *  MATLABSystem: '<S3>/DataDisplay'
   *  MATLABSystem: '<S4>/MATLAB System'
   */
  outData = out[0];
  b_FormatStringTerminated_0[0] = '%';
  b_FormatStringTerminated_0[1] = '.';
  b_FormatStringTerminated_0[2] = '6';
  b_FormatStringTerminated_0[3] = 'f';
  b_FormatStringTerminated_0[4] = '\x00';
  for (i = 0; i < 5; i++) {
    b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
  }

  PUT_DATADISPLAY_DATA(&outData, 1.0, 9, 1, &b_FormatStringTerminated[0]);

  /* End of MATLABSystem: '<S1>/DataDisplay' */

  /* MATLABSystem: '<S2>/DataDisplay' incorporates:
   *  MATLABSystem: '<S4>/MATLAB System'
   */
  outData = out[1];
  for (i = 0; i < 5; i++) {
    b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
  }

  PUT_DATADISPLAY_DATA(&outData, 2.0, 9, 1, &b_FormatStringTerminated[0]);

  /* MATLABSystem: '<S3>/DataDisplay' incorporates:
   *  MATLABSystem: '<S4>/MATLAB System'
   */
  outData = out[2];
  PUT_DATADISPLAY_DATA(&outData, 3.0, 9, 1, &b_FormatStringTerminated_0[0]);
}

/* Model initialize function */
void Gyro_initialize(void)
{
  /* Start for MATLABSystem: '<S4>/MATLAB System' */
  Gyro_DW.obj.matlabCodegenIsDeleted = false;
  Gyro_DW.obj.isInitialized = 1;
  INITIALIZE_GYROSCOPE();
  Gyro_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S2>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S3>/DataDisplay' */
  INITIALIZE_DATADISPLAY();
}

/* Model terminate function */
void Gyro_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/MATLAB System' */
  if (!Gyro_DW.obj.matlabCodegenIsDeleted) {
    Gyro_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
