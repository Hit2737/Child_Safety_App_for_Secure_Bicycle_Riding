/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ChildApp.h
 *
 * Code generated for Simulink model 'ChildApp'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 21:11:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ChildApp_h_
#define RTW_HEADER_ChildApp_h_
#ifndef ChildApp_COMMON_INCLUDES_
#define ChildApp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_accelerometer.h"
#include "driver_android_audiocapture.h"
#include "driver_android_audiofileread.h"
#include "driver_android_audioplayback.h"
#include "driver_android_datadisplay.h"
#include "driver_android_gyroscope.h"
#include "driver_android_location.h"
#include "driver_android_button.h"
#include "MW_TCPSendReceive.h"
#include "driver_android_tcp_log.h"
#endif                                 /* ChildApp_COMMON_INCLUDES_ */

#include "ChildApp_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int16_T outData[8820];
  int16_T refData[8820];
  char_T b[39];
  real_T out[3];
  creal_T b_m;
  creal_T v;
  creal_T u;
  real32_T out_c[3];
  uint8_T b_x[8];
  uint8_T b_x_k[8];
  real_T tmp;
  real_T t1;
  real_T t2;
  real_T scaleA;
  real_T sbr;
  real_T sbi;
  real_T scaleB;
  real_T b_ci;
  real_T t4;
  real_T t;
  real_T vnet;                         /* '<Root>/MATLAB Function1' */
  real_T absxr;
  real_T absxi;
  real_T a;
  real_T b_c;
  char_T str_data[7];
  int16_T y;                           /* '<Root>/MATLAB Function5' */
  int16_T flag;                        /* '<Root>/MATLAB Function11' */
} B_ChildApp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_andr_ejw_T obj; /* '<Root>/Audio File Read1' */
  codertarget_internal_andro_ej_T obj_p;/* '<S3>/Audio Playback' */
  codertarget_internal_androidT_T obj_j;/* '<Root>/TCP//IP Send7' */
  codertarget_internal_androidT_T obj_e;/* '<Root>/TCP//IP Send4' */
  codertarget_internal_androidT_T obj_pv;/* '<Root>/TCP//IP Send3' */
  codertarget_internal_androidT_T obj_m;/* '<Root>/TCP//IP Send1' */
  codertarget_internal_androidT_T obj_pe;/* '<Root>/TCP//IP Send' */
  codertarget_internal_androidA_T obj_k;/* '<S1>/Accelerometer' */
  codertarget_internal_androi_e_T obj_n;/* '<S2>/MATLAB System' */
  codertarget_internal_androidG_T obj_l;/* '<S5>/MATLAB System' */
  codertarget_internal_androidL_T obj_a;/* '<S7>/Location Sensor' */
  real32_T Delay_DSTATE;               /* '<Root>/Delay' */
  real32_T Delay2_DSTATE;              /* '<Root>/Delay2' */
  boolean_T Delay1_DSTATE;             /* '<Root>/Delay1' */
  boolean_T Delay3_DSTATE[50];         /* '<Root>/Delay3' */
} DW_ChildApp_T;

/* Parameters (default storage) */
struct P_ChildApp_T_ {
  real_T AudioPlayback_SampleFreq;     /* Expression: SampleFreq
                                        * Referenced by: '<S3>/Audio Playback'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  real32_T Delay2_InitialCondition;
                                  /* Computed Parameter: Delay2_InitialCondition
                                   * Referenced by: '<Root>/Delay2'
                                   */
  boolean_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<Root>/Delay1'
                                   */
  boolean_T Delay3_InitialCondition;
                                  /* Computed Parameter: Delay3_InitialCondition
                                   * Referenced by: '<Root>/Delay3'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_ChildApp_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ChildApp_T ChildApp_P;

/* Block signals (default storage) */
extern B_ChildApp_T ChildApp_B;

/* Block states (default storage) */
extern DW_ChildApp_T ChildApp_DW;

/* Model entry point functions */
extern void ChildApp_initialize(void);
extern void ChildApp_step(void);
extern void ChildApp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ChildApp_T *const ChildApp_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Reshape4' : Reshape block reduction
 */

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
 * '<Root>' : 'ChildApp'
 * '<S1>'   : 'ChildApp/Accelerometer'
 * '<S2>'   : 'ChildApp/Audio Capture'
 * '<S3>'   : 'ChildApp/Audio Playback'
 * '<S4>'   : 'ChildApp/Distance'
 * '<S5>'   : 'ChildApp/Gyroscope'
 * '<S6>'   : 'ChildApp/Latitude'
 * '<S7>'   : 'ChildApp/Location Sensor'
 * '<S8>'   : 'ChildApp/Longitude'
 * '<S9>'   : 'ChildApp/MATLAB Function'
 * '<S10>'  : 'ChildApp/MATLAB Function1'
 * '<S11>'  : 'ChildApp/MATLAB Function10'
 * '<S12>'  : 'ChildApp/MATLAB Function11'
 * '<S13>'  : 'ChildApp/MATLAB Function12'
 * '<S14>'  : 'ChildApp/MATLAB Function13'
 * '<S15>'  : 'ChildApp/MATLAB Function2'
 * '<S16>'  : 'ChildApp/MATLAB Function3'
 * '<S17>'  : 'ChildApp/MATLAB Function4'
 * '<S18>'  : 'ChildApp/MATLAB Function5'
 * '<S19>'  : 'ChildApp/MATLAB Function6'
 * '<S20>'  : 'ChildApp/MATLAB Function7'
 * '<S21>'  : 'ChildApp/MATLAB Function8'
 * '<S22>'  : 'ChildApp/MATLAB Function9'
 * '<S23>'  : 'ChildApp/Press if you are fine.'
 * '<S24>'  : 'ChildApp/Speed'
 */
#endif                                 /* RTW_HEADER_ChildApp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
