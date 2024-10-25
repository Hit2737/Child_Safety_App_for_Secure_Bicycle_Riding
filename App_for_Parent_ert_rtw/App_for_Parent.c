/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: App_for_Parent.c
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

#include "App_for_Parent.h"
#include "App_for_Parent_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "App_for_Parent_private.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (default storage) */
B_App_for_Parent_T App_for_Parent_B;

/* Block states (default storage) */
DW_App_for_Parent_T App_for_Parent_DW;

/* Real-time model */
static RT_MODEL_App_for_Parent_T App_for_Parent_M_;
RT_MODEL_App_for_Parent_T *const App_for_Parent_M = &App_for_Parent_M_;

/* Forward declaration for local functions */
static void App_for_Parent_SystemCore_setup(codertarget_internal_androidT_T *obj);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (App_for_Parent_M->Timing.TaskCounters.TID[1])++;
  if ((App_for_Parent_M->Timing.TaskCounters.TID[1]) > 149) {/* Sample time: [15.0s, 0.0s] */
    App_for_Parent_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  int32_T tmp;
  int32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = (real32_T)atan2((real32_T)tmp, (real32_T)tmp_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void App_for_Parent_SystemCore_setup(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[10];
  char_T ipaddr[10];
  static const char_T tmp_1[10] = "126.0.0.5";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 0.0;
  for (i = 0; i < 10; i++) {
    ipaddr[i] = tmp_1[i];
  }

  tmp = rt_roundd_snf(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamSetup(50000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 1.0, 1, MAX_int16_T);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 10;
        for (i = 0; i < 10; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 1.0, 1, &b_str_data[0]);
    }
  }
}

/* Model step function */
void App_for_Parent_step(void)
{
  real_T outData;
  real_T tmp;
  int32_T i;
  int32_T outData_tmp;
  real32_T Data;
  real32_T Data_0;
  real32_T a;
  int16_T Status;
  int16_T rtb_f;
  uint16_T tmp_0;
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];
  int8_T b_status;
  uint8_T xtmp;
  boolean_T rtb_Button_0;
  static const char_T tmp_1[10] = "126.0.0.5";

  /* MATLABSystem: '<Root>/Audio File Read1' */
  memset(&App_for_Parent_B.iv[0], 0, 8820U * sizeof(int16_T));
  i = App_for_Parent_DW.obj.Idx;
  if (App_for_Parent_DW.obj.Idx < 0) {
    i = 0;
  }

  READ_AUDIOFILE_DATA(4410U, 2U, &App_for_Parent_B.iv[0], (uint32_T)i);
  if (App_for_Parent_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/ThingSpeak Read5' */
    READ_THINGSPEAK_DATA(2272274U, &App_for_Parent_B.ThingSpeakRead5_o1, &Status,
                         7);

    /* MATLABSystem: '<Root>/ThingSpeak Read3' */
    READ_THINGSPEAK_DATA(2272274U, &App_for_Parent_B.ThingSpeakRead3_o1, &Status,
                         4);

    /* MATLABSystem: '<Root>/ThingSpeak Read4' */
    READ_THINGSPEAK_DATA(2272274U, &App_for_Parent_B.ThingSpeakRead4_o1, &Status,
                         5);
  }

  /* MATLABSystem: '<S4>/Location Sensor' */
  App_for_Parent_B.out[0] = 0.0;
  App_for_Parent_B.out[1] = 0.0;
  App_for_Parent_B.out[2] = 0.0;
  GET_LOCATION_DATA(&App_for_Parent_B.out[0], &App_for_Parent_B.out[1],
                    &App_for_Parent_B.out[2]);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<S4>/Location Sensor'
   */
  a = (real32_T)sin(((real32_T)App_for_Parent_B.out[0] -
                     App_for_Parent_B.ThingSpeakRead3_o1) * 0.0174532924F / 2.0F);
  Data = (real32_T)sin(((real32_T)App_for_Parent_B.out[1] -
                        App_for_Parent_B.ThingSpeakRead4_o1) * 0.0174532924F /
                       2.0F);
  a = (real32_T)cos(0.0174532924F * App_for_Parent_B.ThingSpeakRead3_o1) *
    (real32_T)cos(0.017453292519943295 * App_for_Parent_B.out[0]) * Data * Data
    + a * a;

  /* Logic: '<Root>/OR1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<Root>/Delay1'
   */
  App_for_Parent_DW.Delay1_DSTATE = ((App_for_Parent_P.Constant1_Value != 0.0) ||
    App_for_Parent_DW.Delay1_DSTATE);

  /* MATLABSystem: '<S2>/Button' */
  rtb_Button_0 = BUTTON_GETSTATE(1.0);

  /* MATLAB Function: '<Root>/MATLAB Function4' incorporates:
   *  MATLABSystem: '<S2>/Button'
   */
  if (!rtb_Button_0) {
    if (!App_for_Parent_DW.Delay1_DSTATE) {
      /* Update for Logic: '<Root>/OR1' incorporates:
       *  Delay: '<Root>/Delay1'
       *  MATLAB Function: '<Root>/MATLAB Function1'
       */
      App_for_Parent_DW.Delay1_DSTATE = (rt_atan2f_snf((real32_T)sqrt(a),
        (real32_T)sqrt(1.0F - a)) * 2.0F * 6371.0F > 5.0F);
      rtb_f = 0;
    } else {
      rtb_f = 1;
    }
  } else {
    rtb_f = 0;

    /* Update for Logic: '<Root>/OR1' incorporates:
     *  Delay: '<Root>/Delay1'
     */
    App_for_Parent_DW.Delay1_DSTATE = false;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function4' */
  if (App_for_Parent_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/ThingSpeak Read6' */
    READ_THINGSPEAK_DATA(2276250U, &App_for_Parent_B.ThingSpeakRead6_o1, &Status,
                         1);
  }

  /* MATLAB Function: '<Root>/MATLAB Function5' */
  Status = (int16_T)((rtb_f == 1) || (App_for_Parent_B.ThingSpeakRead5_o1 ==
    1.0F) || (App_for_Parent_B.ThingSpeakRead6_o1 == 1.0F));

  /* MATLABSystem: '<S1>/Audio Playback' incorporates:
   *  MATLABSystem: '<Root>/Audio File Read1'
   *  Product: '<Root>/Product'
   */
  if (App_for_Parent_DW.obj_i.SampleFreq !=
      App_for_Parent_P.AudioPlayback_SampleFreq) {
    App_for_Parent_DW.obj_i.SampleFreq =
      App_for_Parent_P.AudioPlayback_SampleFreq;
  }

  for (i = 0; i < 4410; i++) {
    outData_tmp = i << 1;
    App_for_Parent_B.outData[outData_tmp] = (int16_T)(Status *
      App_for_Parent_B.iv[i]);
    App_for_Parent_B.outData[outData_tmp + 1] = (int16_T)(App_for_Parent_B.iv[i
      + 4410] * Status);
  }

  AUDIO_PLAYBACK(&App_for_Parent_B.outData[0], App_for_Parent_DW.obj_i.FrameSize);

  /* End of MATLABSystem: '<S1>/Audio Playback' */

  /* MATLABSystem: '<Root>/TCP//IP Receive' */
  Status = App_for_Parent_DW.obj_m.errorNo_;
  tmp = rt_roundd_snf(App_for_Parent_DW.obj_m.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamStepRecv(&outData, &b_status, 8, App_for_Parent_DW.obj_m.connStream_,
                    &rtb_f, tmp_0);
  if (App_for_Parent_DW.obj_m.isLittleEnd_ == 1) {
    memcpy((void *)&App_for_Parent_B.b_x[0], (void *)&outData, (uint32_T)
           ((size_t)8 * sizeof(uint8_T)));
    xtmp = App_for_Parent_B.b_x[0];
    App_for_Parent_B.b_x[0] = App_for_Parent_B.b_x[7];
    App_for_Parent_B.b_x[7] = xtmp;
    xtmp = App_for_Parent_B.b_x[1];
    App_for_Parent_B.b_x[1] = App_for_Parent_B.b_x[6];
    App_for_Parent_B.b_x[6] = xtmp;
    xtmp = App_for_Parent_B.b_x[2];
    App_for_Parent_B.b_x[2] = App_for_Parent_B.b_x[5];
    App_for_Parent_B.b_x[5] = xtmp;
    xtmp = App_for_Parent_B.b_x[3];
    App_for_Parent_B.b_x[3] = App_for_Parent_B.b_x[4];
    App_for_Parent_B.b_x[4] = xtmp;
    memcpy((void *)&outData, (void *)&App_for_Parent_B.b_x[0], (uint32_T)
           ((size_t)1 * sizeof(real_T)));
  }

  App_for_Parent_DW.obj_m.errorNo_ = rtb_f;
  if ((Status != App_for_Parent_DW.obj_m.errorNo_) &&
      (App_for_Parent_DW.obj_m.errorNo_ > 0) &&
      (App_for_Parent_DW.obj_m.errorNo_ < 10)) {
    outData_tmp = 1;
    App_for_Parent_B.str_data[0] = '\x00';
    if (App_for_Parent_DW.obj_m.errorNo_ == 4) {
      UPDATE_TCP_LOGI(App_for_Parent_DW.obj_m.errorNo_, 1.0, 1, MAX_int16_T);
    } else {
      if (App_for_Parent_DW.obj_m.errorNo_ == 5) {
        outData_tmp = 10;
        for (i = 0; i < 10; i++) {
          App_for_Parent_B.str_data[i] = tmp_1[i];
        }
      }

      memcpy(&App_for_Parent_B.b_str_data[0], &App_for_Parent_B.str_data[0],
             (uint32_T)outData_tmp * sizeof(char_T));
      UPDATE_TCP_LOGS(App_for_Parent_DW.obj_m.errorNo_, 1.0, 1,
                      &App_for_Parent_B.b_str_data[0]);
    }
  }

  /* MATLABSystem: '<S3>/DataDisplay' incorporates:
   *  MATLABSystem: '<Root>/TCP//IP Receive'
   *  MATLABSystem: '<S9>/DataDisplay'
   */
  b_FormatStringTerminated_0[0] = '%';
  b_FormatStringTerminated_0[1] = '.';
  b_FormatStringTerminated_0[2] = '6';
  b_FormatStringTerminated_0[3] = 'f';
  b_FormatStringTerminated_0[4] = '\x00';
  for (i = 0; i < 5; i++) {
    b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
  }

  PUT_DATADISPLAY_DATA(&outData, 1.0, 9, 1, &b_FormatStringTerminated[0]);

  /* End of MATLABSystem: '<S3>/DataDisplay' */
  if (App_for_Parent_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/ThingSpeak Read' */
    READ_THINGSPEAK_DATA(2272274U, &a, &Status, 1);

    /* MATLABSystem: '<Root>/ThingSpeak Read1' */
    READ_THINGSPEAK_DATA(2272274U, &Data, &Status, 2);

    /* MATLABSystem: '<Root>/ThingSpeak Read2' */
    READ_THINGSPEAK_DATA(2272274U, &Data_0, &Status, 3);

    /* MATLABSystem: '<S9>/DataDisplay' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function2'
     *  MATLABSystem: '<Root>/ThingSpeak Read'
     *  MATLABSystem: '<Root>/ThingSpeak Read1'
     *  MATLABSystem: '<Root>/ThingSpeak Read2'
     */
    outData = (real32_T)sqrt((a * a + Data * Data) + Data_0 * Data_0);
    PUT_DATADISPLAY_DATA(&outData, 2.0, 9, 1, &b_FormatStringTerminated_0[0]);
  }

  rate_scheduler();
}

/* Model initialize function */
void App_for_Parent_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T c[4];
    char_T obj;
    static const char_T tmp[38] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g', 'b', 'u',
      'z', 'z', 'e', 'r', 'a', 'l', 'a', 'r', 'm', 'f', 'a', 's', 'c', 'i', 'n',
      'a', 't', 'e', 'd', 's', 'o', 'u', 'n', 'd', '1', '0', '0', '1', '8' };

    static const char_T tmp_0[17] = "LGLM5U6NBETJFORN";
    static const char_T tmp_1[17] = "129YKS9F068N11CR";

    /* InitializeConditions for Logic: '<Root>/OR1' incorporates:
     *  Delay: '<Root>/Delay1'
     */
    App_for_Parent_DW.Delay1_DSTATE = App_for_Parent_P.Delay1_InitialCondition;

    /* Start for MATLABSystem: '<Root>/Audio File Read1' */
    App_for_Parent_DW.obj.matlabCodegenIsDeleted = false;
    App_for_Parent_DW.obj.FExt[0] = 'm';
    App_for_Parent_DW.obj.FExt[1] = 'p';
    App_for_Parent_DW.obj.FExt[2] = '3';
    App_for_Parent_DW.obj.FExt[3] = '\x00';
    App_for_Parent_DW.obj.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      obj = tmp[i];
      App_for_Parent_DW.obj.RName[i] = obj;
      App_for_Parent_B.b[i] = obj;
    }

    App_for_Parent_B.b[38] = '\x00';
    c[0] = App_for_Parent_DW.obj.FExt[0];
    c[1] = App_for_Parent_DW.obj.FExt[1];
    c[2] = App_for_Parent_DW.obj.FExt[2];
    c[3] = App_for_Parent_DW.obj.FExt[3];
    INITIALIZE_AUDIOFILEREAD(&App_for_Parent_B.b[0], &c[0], 4410U,
      &App_for_Parent_DW.obj.Idx);
    App_for_Parent_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Audio File Read1' */

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read5' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_READ(2.272274E+6, &App_for_Parent_B.b_m[0], 7.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read5' */

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read3' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_READ(2.272274E+6, &App_for_Parent_B.b_m[0], 4.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read3' */

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read4' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_READ(2.272274E+6, &App_for_Parent_B.b_m[0], 5.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read4' */

    /* Start for MATLABSystem: '<S4>/Location Sensor' */
    App_for_Parent_DW.obj_f.matlabCodegenIsDeleted = false;
    App_for_Parent_DW.obj_f.isInitialized = 1;
    INIT_LOCATION_SENSOR();
    App_for_Parent_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Button' */
    BUTTON_INIT(1.0);

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read6' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_1[i];
    }

    INIT_THINGSPEAK_READ(2.27625E+6, &App_for_Parent_B.b_m[0], 1.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read6' */

    /* Start for MATLABSystem: '<S1>/Audio Playback' */
    App_for_Parent_DW.obj_i.matlabCodegenIsDeleted = false;
    App_for_Parent_DW.obj_i.SampleFreq =
      App_for_Parent_P.AudioPlayback_SampleFreq;
    App_for_Parent_DW.obj_i.isInitialized = 1;
    App_for_Parent_DW.obj_i.FrameSize = 4410.0;
    INIT_AUDIO_PLAYBACK(App_for_Parent_DW.obj_i.SampleFreq,
                        App_for_Parent_DW.obj_i.FrameSize);
    App_for_Parent_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/TCP//IP Receive' */
    App_for_Parent_DW.obj_m.errorNo_ = 0;
    App_for_Parent_DW.obj_m.isInitialized = 0;
    App_for_Parent_SystemCore_setup(&App_for_Parent_DW.obj_m);

    /* Start for MATLABSystem: '<S3>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_READ(2.272274E+6, &App_for_Parent_B.b_m[0], 1.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read' */

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read1' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_READ(2.272274E+6, &App_for_Parent_B.b_m[0], 2.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read1' */

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read2' */
    for (i = 0; i < 17; i++) {
      App_for_Parent_B.b_m[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_READ(2.272274E+6, &App_for_Parent_B.b_m[0], 3.0, 15.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read2' */

    /* Start for MATLABSystem: '<S9>/DataDisplay' */
    INITIALIZE_DATADISPLAY();
  }
}

/* Model terminate function */
void App_for_Parent_terminate(void)
{
  int32_T tmp;

  /* Terminate for MATLABSystem: '<Root>/Audio File Read1' */
  if (!App_for_Parent_DW.obj.matlabCodegenIsDeleted) {
    App_for_Parent_DW.obj.matlabCodegenIsDeleted = true;
    if ((App_for_Parent_DW.obj.isInitialized == 1) &&
        App_for_Parent_DW.obj.isSetupComplete) {
      tmp = App_for_Parent_DW.obj.Idx;
      if (App_for_Parent_DW.obj.Idx < 0) {
        tmp = 0;
      }

      TERMINATE_AUDIOFILEREAD((uint32_T)tmp);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Audio File Read1' */

  /* Terminate for MATLABSystem: '<S4>/Location Sensor' */
  if (!App_for_Parent_DW.obj_f.matlabCodegenIsDeleted) {
    App_for_Parent_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Location Sensor' */

  /* Terminate for MATLABSystem: '<S1>/Audio Playback' */
  if (!App_for_Parent_DW.obj_i.matlabCodegenIsDeleted) {
    App_for_Parent_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((App_for_Parent_DW.obj_i.isInitialized == 1) &&
        App_for_Parent_DW.obj_i.isSetupComplete) {
      TERMINATE_AUDIO_PLAYBACK();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Audio Playback' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
