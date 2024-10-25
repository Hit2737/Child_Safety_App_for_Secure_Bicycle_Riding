/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Gyro.h
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

#ifndef RTW_HEADER_Gyro_h_
#define RTW_HEADER_Gyro_h_
#ifndef Gyro_COMMON_INCLUDES_
#define Gyro_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_datadisplay.h"
#include "driver_android_gyroscope.h"
#endif                                 /* Gyro_COMMON_INCLUDES_ */

#include "Gyro_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidG_T obj; /* '<S4>/MATLAB System' */
} DW_Gyro_T;

/* Real-time Model Data Structure */
struct tag_RTM_Gyro_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Gyro_T Gyro_DW;

/* Model entry point functions */
extern void Gyro_initialize(void);
extern void Gyro_step(void);
extern void Gyro_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Gyro_T *const Gyro_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Gyro'
 * '<S1>'   : 'Gyro/Data Display'
 * '<S2>'   : 'Gyro/Data Display1'
 * '<S3>'   : 'Gyro/Data Display2'
 * '<S4>'   : 'Gyro/Gyroscope'
 */
#endif                                 /* RTW_HEADER_Gyro_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
