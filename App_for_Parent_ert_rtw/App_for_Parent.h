/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: App_for_Parent.h
 *
 * Code generated for Simulink model 'App_for_Parent'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Sep 27 23:45:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_App_for_Parent_h_
#define RTW_HEADER_App_for_Parent_h_
#ifndef App_for_Parent_COMMON_INCLUDES_
#define App_for_Parent_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_audiofileread.h"
#include "driver_android_audioplayback.h"
#include "driver_android_button.h"
#include "driver_android_datadisplay.h"
#include "driver_android_location.h"
#include "MW_TCPSendReceive.h"
#include "driver_android_tcp_log.h"
#include "driver_android_thingspeak_read.h"
#endif                                 /* App_for_Parent_COMMON_INCLUDES_ */

#include "App_for_Parent_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
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
  int16_T iv[8820];
  int16_T outData[8820];
  char_T b[39];
  real_T out[3];
  char_T b_m[17];
  char_T str_data[10];
  char_T b_str_data[10];
  uint8_T b_x[8];
  real32_T ThingSpeakRead6_o1;         /* '<Root>/ThingSpeak Read6' */
  real32_T ThingSpeakRead5_o1;         /* '<Root>/ThingSpeak Read5' */
  real32_T ThingSpeakRead4_o1;         /* '<Root>/ThingSpeak Read4' */
  real32_T ThingSpeakRead3_o1;         /* '<Root>/ThingSpeak Read3' */
} B_App_for_Parent_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_andro_oi_T obj; /* '<Root>/Audio File Read1' */
  codertarget_internal_androidA_T obj_i;/* '<S1>/Audio Playback' */
  codertarget_internal_androidT_T obj_m;/* '<Root>/TCP//IP Receive' */
  codertarget_internal_androidL_T obj_f;/* '<S4>/Location Sensor' */
  boolean_T Delay1_DSTATE;             /* '<Root>/Delay1' */
} DW_App_for_Parent_T;

/* Parameters (default storage) */
struct P_App_for_Parent_T_ {
  real_T AudioPlayback_SampleFreq;     /* Expression: SampleFreq
                                        * Referenced by: '<S1>/Audio Playback'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  boolean_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<Root>/Delay1'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_App_for_Parent_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_App_for_Parent_T App_for_Parent_P;

/* Block signals (default storage) */
extern B_App_for_Parent_T App_for_Parent_B;

/* Block states (default storage) */
extern DW_App_for_Parent_T App_for_Parent_DW;

/* Model entry point functions */
extern void App_for_Parent_initialize(void);
extern void App_for_Parent_step(void);
extern void App_for_Parent_terminate(void);

/* Real-time Model object */
extern RT_MODEL_App_for_Parent_T *const App_for_Parent_M;
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
 * '<Root>' : 'App_for_Parent'
 * '<S1>'   : 'App_for_Parent/Audio Playback'
 * '<S2>'   : 'App_for_Parent/Button1'
 * '<S3>'   : 'App_for_Parent/Data Display'
 * '<S4>'   : 'App_for_Parent/Location Sensor'
 * '<S5>'   : 'App_for_Parent/MATLAB Function1'
 * '<S6>'   : 'App_for_Parent/MATLAB Function2'
 * '<S7>'   : 'App_for_Parent/MATLAB Function4'
 * '<S8>'   : 'App_for_Parent/MATLAB Function5'
 * '<S9>'   : 'App_for_Parent/net acceleration'
 */
#endif                                 /* RTW_HEADER_App_for_Parent_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
