/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ChildApp.c
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

#include "ChildApp.h"
#include "rtwtypes.h"
#include "ChildApp_types.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "ChildApp_private.h"
#include <stddef.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_ChildApp_T ChildApp_B;

/* Block states (default storage) */
DW_ChildApp_T ChildApp_DW;

/* Real-time model */
static RT_MODEL_ChildApp_T ChildApp_M_;
RT_MODEL_ChildApp_T *const ChildApp_M = &ChildApp_M_;

/* Forward declaration for local functions */
static real_T ChildApp_rt_hypotd_snf(real_T u0, real_T u1);
static void ChildApp_sqrt(creal_T *x);
static real_T ChildApp_rescale(real_T *re, real_T *im);
static void ChildApp_SystemCore_setup_ej(codertarget_internal_androidT_T *obj);
static void ChildApp_SystemCore_setup_ejw(codertarget_internal_androidT_T *obj);
static void ChildApp_SystemCore_setup(codertarget_internal_androidT_T *obj);
static void ChildApp_SystemCore_setup_e(codertarget_internal_androidT_T *obj);
static void ChildApp_SystemCore_setup_ejw1(codertarget_internal_androidT_T *obj);
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
  (ChildApp_M->Timing.TaskCounters.TID[1])++;
  if ((ChildApp_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.2s, 0.0s] */
    ChildApp_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static real_T ChildApp_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  ChildApp_B.a = fabs(u0);
  ChildApp_B.b_c = fabs(u1);
  if (ChildApp_B.a < ChildApp_B.b_c) {
    ChildApp_B.a /= ChildApp_B.b_c;
    y = sqrt(ChildApp_B.a * ChildApp_B.a + 1.0) * ChildApp_B.b_c;
  } else if (ChildApp_B.a > ChildApp_B.b_c) {
    ChildApp_B.b_c /= ChildApp_B.a;
    y = sqrt(ChildApp_B.b_c * ChildApp_B.b_c + 1.0) * ChildApp_B.a;
  } else if (rtIsNaN(ChildApp_B.b_c)) {
    y = (rtNaN);
  } else {
    y = ChildApp_B.a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function2' */
static void ChildApp_sqrt(creal_T *x)
{
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      ChildApp_B.absxr = 0.0;
      ChildApp_B.absxi = sqrt(-x->re);
    } else {
      ChildApp_B.absxr = sqrt(x->re);
      ChildApp_B.absxi = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      ChildApp_B.absxr = sqrt(-x->im / 2.0);
      ChildApp_B.absxi = -ChildApp_B.absxr;
    } else {
      ChildApp_B.absxr = sqrt(x->im / 2.0);
      ChildApp_B.absxi = ChildApp_B.absxr;
    }
  } else if (rtIsNaN(x->re)) {
    ChildApp_B.absxr = (rtNaN);
    ChildApp_B.absxi = (rtNaN);
  } else if (rtIsNaN(x->im)) {
    ChildApp_B.absxr = (rtNaN);
    ChildApp_B.absxi = (rtNaN);
  } else if (rtIsInf(x->im)) {
    ChildApp_B.absxr = fabs(x->im);
    ChildApp_B.absxi = x->im;
  } else if (rtIsInf(x->re)) {
    if (x->re < 0.0) {
      ChildApp_B.absxr = 0.0;
      ChildApp_B.absxi = x->im * -x->re;
    } else {
      ChildApp_B.absxr = x->re;
      ChildApp_B.absxi = 0.0;
    }
  } else {
    ChildApp_B.absxr = fabs(x->re);
    ChildApp_B.absxi = fabs(x->im);
    if ((ChildApp_B.absxr > 4.4942328371557893E+307) || (ChildApp_B.absxi >
         4.4942328371557893E+307)) {
      ChildApp_B.absxr *= 0.5;
      ChildApp_B.absxi = ChildApp_rt_hypotd_snf(ChildApp_B.absxr,
        ChildApp_B.absxi * 0.5);
      if (ChildApp_B.absxi > ChildApp_B.absxr) {
        ChildApp_B.absxr = sqrt(ChildApp_B.absxr / ChildApp_B.absxi + 1.0) *
          sqrt(ChildApp_B.absxi);
      } else {
        ChildApp_B.absxr = sqrt(ChildApp_B.absxi) * 1.4142135623730951;
      }
    } else {
      ChildApp_B.absxr = sqrt((ChildApp_rt_hypotd_snf(ChildApp_B.absxr,
        ChildApp_B.absxi) + ChildApp_B.absxr) * 0.5);
    }

    if (x->re > 0.0) {
      ChildApp_B.absxi = x->im / ChildApp_B.absxr * 0.5;
    } else {
      if (x->im < 0.0) {
        ChildApp_B.absxi = -ChildApp_B.absxr;
      } else {
        ChildApp_B.absxi = ChildApp_B.absxr;
      }

      ChildApp_B.absxr = x->im / ChildApp_B.absxi * 0.5;
    }
  }

  x->re = ChildApp_B.absxr;
  x->im = ChildApp_B.absxi;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function2' */
static real_T ChildApp_rescale(real_T *re, real_T *im)
{
  real_T absim;
  real_T scale;
  scale = fabs(*re);
  absim = fabs(*im);
  if (scale > absim) {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }

    *im /= scale;
  } else if (absim > scale) {
    *re /= absim;
    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }

    scale = absim;
  } else {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }

    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }
  }

  return scale;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
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

static void ChildApp_SystemCore_setup_ej(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[7];
  char_T ipaddr[7];
  static const char_T tmp_1[7] = "Server";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 1.0;
  for (i = 0; i < 7; i++) {
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

  TCPStreamSetup(20000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 3.0, 0, 25000);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 7;
        for (i = 0; i < 7; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 3.0, 0, &b_str_data[0]);
    }
  }
}

static void ChildApp_SystemCore_setup_ejw(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[7];
  char_T ipaddr[7];
  static const char_T tmp_1[7] = "Server";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 1.0;
  for (i = 0; i < 7; i++) {
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

  TCPStreamSetup(60000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 4.0, 0, 25000);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 7;
        for (i = 0; i < 7; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 4.0, 0, &b_str_data[0]);
    }
  }
}

static void ChildApp_SystemCore_setup(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[7];
  char_T ipaddr[7];
  static const char_T tmp_1[7] = "Server";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 1.0;
  for (i = 0; i < 7; i++) {
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

  TCPStreamSetup(25000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 1.0, 0, 25000);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 7;
        for (i = 0; i < 7; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 1.0, 0, &b_str_data[0]);
    }
  }
}

static void ChildApp_SystemCore_setup_e(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[7];
  char_T ipaddr[7];
  static const char_T tmp_1[7] = "Server";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 1.0;
  for (i = 0; i < 7; i++) {
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
      UPDATE_TCP_LOGI(obj->errorNo_, 2.0, 0, 25000);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 7;
        for (i = 0; i < 7; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 2.0, 0, &b_str_data[0]);
    }
  }
}

static void ChildApp_SystemCore_setup_ejw1(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[7];
  char_T ipaddr[7];
  static const char_T tmp_1[7] = "Server";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 1.0;
  for (i = 0; i < 7; i++) {
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

  TCPStreamSetup(15000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 5.0, 0, 25000);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 7;
        for (i = 0; i < 7; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 5.0, 0, &b_str_data[0]);
    }
  }
}

/* Model step function */
void ChildApp_step(void)
{
  int32_T b_k;
  int32_T outData_tmp;
  real32_T rtb_MATLABSystem_o1;
  real32_T rtb_MATLABSystem_o2;
  real32_T rtb_ax;
  real32_T rtb_ay;
  int16_T rtb_f;
  int16_T rtb_flag;
  int16_T y_0;
  uint16_T tmp;
  char_T b_str_data[7];
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T xtmp;
  boolean_T tmp_0;
  boolean_T xneg;
  static const char_T tmp_1[7] = "Server";

  /* MATLABSystem: '<Root>/Audio File Read1' */
  memset(&ChildApp_B.refData[0], 0, 8820U * sizeof(int16_T));
  b_k = ChildApp_DW.obj.Idx;
  if (ChildApp_DW.obj.Idx < 0) {
    b_k = 0;
  }

  READ_AUDIOFILE_DATA(4410U, 2U, &ChildApp_B.refData[0], (uint32_T)b_k);

  /* MATLABSystem: '<S7>/Location Sensor' */
  ChildApp_B.out[0] = 0.0;
  ChildApp_B.out[1] = 0.0;
  ChildApp_B.out[2] = 0.0;
  GET_LOCATION_DATA(&ChildApp_B.out[0], &ChildApp_B.out[1], &ChildApp_B.out[2]);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  MATLABSystem: '<S7>/Location Sensor'
   */
  ChildApp_B.b_ci = sin((23.2096737 - ChildApp_B.out[0]) * 0.017453292519943295 /
                        2.0);
  ChildApp_B.t = sin((72.6836191 - ChildApp_B.out[1]) * 0.017453292519943295 /
                     2.0);
  ChildApp_B.b_m.re = cos(ChildApp_B.out[0]) * -0.34503042633900188 *
    (ChildApp_B.t * ChildApp_B.t) + ChildApp_B.b_ci * ChildApp_B.b_ci;
  ChildApp_B.b_m.im = 0.0;
  ChildApp_sqrt(&ChildApp_B.b_m);
  if ((ChildApp_B.b_m.im == 0.0) && (!(fabs(ChildApp_B.b_m.re) > 1.0))) {
    ChildApp_B.b_m.re = asin(ChildApp_B.b_m.re);
    ChildApp_B.b_m.im = 0.0;
  } else {
    ChildApp_B.v.re = ChildApp_B.b_m.re + 1.0;
    ChildApp_B.v.im = ChildApp_B.b_m.im;
    ChildApp_sqrt(&ChildApp_B.v);
    ChildApp_B.u.re = 1.0 - ChildApp_B.b_m.re;
    ChildApp_B.u.im = 0.0 - ChildApp_B.b_m.im;
    ChildApp_sqrt(&ChildApp_B.u);
    if ((ChildApp_B.u.im == 0.0) && (ChildApp_B.v.im == 0.0)) {
      ChildApp_B.tmp = ChildApp_B.u.re * ChildApp_B.v.re;
    } else {
      ChildApp_B.t1 = ChildApp_B.u.re * ChildApp_B.v.re;
      ChildApp_B.t2 = ChildApp_B.u.im * ChildApp_B.v.im;
      ChildApp_B.tmp = ChildApp_B.t1 - ChildApp_B.t2;
      xneg = rtIsNaN(ChildApp_B.tmp);
      tmp_0 = rtIsInf(ChildApp_B.tmp);
      if ((tmp_0 || xneg) && (!rtIsNaN(ChildApp_B.u.re)) && (!rtIsNaN
           (ChildApp_B.u.im)) && (!rtIsNaN(ChildApp_B.v.re)) && (!rtIsNaN
           (ChildApp_B.v.im))) {
        ChildApp_B.b_ci = ChildApp_B.u.re;
        ChildApp_B.t = ChildApp_B.u.im;
        ChildApp_B.scaleA = ChildApp_rescale(&ChildApp_B.b_ci, &ChildApp_B.t);
        ChildApp_B.sbr = ChildApp_B.v.re;
        ChildApp_B.sbi = ChildApp_B.v.im;
        ChildApp_B.scaleB = ChildApp_rescale(&ChildApp_B.sbr, &ChildApp_B.sbi);
        if (xneg || (tmp_0 && ((!rtIsInf(ChildApp_B.scaleA)) && (!rtIsNaN
               (ChildApp_B.scaleA)) && ((!rtIsInf(ChildApp_B.scaleB)) &&
               (!rtIsNaN(ChildApp_B.scaleB)))))) {
          ChildApp_B.tmp = ChildApp_B.b_ci * ChildApp_B.sbr - ChildApp_B.t *
            ChildApp_B.sbi;
          if (ChildApp_B.tmp != 0.0) {
            ChildApp_B.tmp = ChildApp_B.tmp * ChildApp_B.scaleA *
              ChildApp_B.scaleB;
          } else if ((rtIsInf(ChildApp_B.scaleA) && ((ChildApp_B.v.re == 0.0) ||
            (ChildApp_B.v.im == 0.0))) || (rtIsInf(ChildApp_B.scaleB) &&
                      ((ChildApp_B.u.re == 0.0) || (ChildApp_B.u.im == 0.0)))) {
            if (rtIsNaN(ChildApp_B.t1)) {
              ChildApp_B.t1 = 0.0;
            }

            if (rtIsNaN(ChildApp_B.t2)) {
              ChildApp_B.t2 = 0.0;
            }

            ChildApp_B.tmp = ChildApp_B.t1 - ChildApp_B.t2;
          }
        }
      }
    }

    if ((-ChildApp_B.u.im == 0.0) && (ChildApp_B.v.im == 0.0)) {
      ChildApp_B.b_ci = 0.0;
    } else {
      ChildApp_B.t2 = ChildApp_B.u.re * ChildApp_B.v.im;
      ChildApp_B.t4 = -ChildApp_B.u.im * ChildApp_B.v.re;
      ChildApp_B.b_ci = ChildApp_B.t2 + ChildApp_B.t4;
      xneg = rtIsNaN(ChildApp_B.b_ci);
      tmp_0 = rtIsInf(ChildApp_B.b_ci);
      if ((tmp_0 || xneg) && (!rtIsNaN(ChildApp_B.u.re)) && (!rtIsNaN
           (-ChildApp_B.u.im)) && (!rtIsNaN(ChildApp_B.v.re)) && (!rtIsNaN
           (ChildApp_B.v.im))) {
        ChildApp_B.t = ChildApp_B.u.re;
        ChildApp_B.scaleA = -ChildApp_B.u.im;
        ChildApp_B.sbr = ChildApp_rescale(&ChildApp_B.t, &ChildApp_B.scaleA);
        ChildApp_B.sbi = ChildApp_B.v.re;
        ChildApp_B.scaleB = ChildApp_B.v.im;
        ChildApp_B.t1 = ChildApp_rescale(&ChildApp_B.sbi, &ChildApp_B.scaleB);
        if (xneg || (tmp_0 && ((!rtIsInf(ChildApp_B.sbr)) && (!rtIsNaN
               (ChildApp_B.sbr)) && ((!rtIsInf(ChildApp_B.t1)) && (!rtIsNaN
                (ChildApp_B.t1)))))) {
          ChildApp_B.b_ci = ChildApp_B.t * ChildApp_B.scaleB + ChildApp_B.scaleA
            * ChildApp_B.sbi;
          if (ChildApp_B.b_ci != 0.0) {
            ChildApp_B.b_ci = ChildApp_B.b_ci * ChildApp_B.sbr * ChildApp_B.t1;
          } else if ((rtIsInf(ChildApp_B.sbr) && ((ChildApp_B.v.re == 0.0) ||
                       (ChildApp_B.v.im == 0.0))) || (rtIsInf(ChildApp_B.t1) &&
                      ((ChildApp_B.u.re == 0.0) || (-ChildApp_B.u.im == 0.0))))
          {
            if (rtIsNaN(ChildApp_B.t2)) {
              ChildApp_B.t2 = 0.0;
            }

            if (rtIsNaN(ChildApp_B.t4)) {
              ChildApp_B.t4 = 0.0;
            }

            ChildApp_B.b_ci = ChildApp_B.t2 + ChildApp_B.t4;
          }
        }
      }
    }

    xneg = (ChildApp_B.b_ci < 0.0);
    if (xneg) {
      ChildApp_B.b_ci = -ChildApp_B.b_ci;
    }

    if (ChildApp_B.b_ci >= 2.68435456E+8) {
      ChildApp_B.b_ci = log(ChildApp_B.b_ci) + 0.69314718055994529;
    } else if (ChildApp_B.b_ci > 2.0) {
      ChildApp_B.b_ci = log(1.0 / (sqrt(ChildApp_B.b_ci * ChildApp_B.b_ci + 1.0)
        + ChildApp_B.b_ci) + 2.0 * ChildApp_B.b_ci);
    } else {
      ChildApp_B.t = ChildApp_B.b_ci * ChildApp_B.b_ci;
      ChildApp_B.b_ci += ChildApp_B.t / (sqrt(ChildApp_B.t + 1.0) + 1.0);
      ChildApp_B.t = fabs(ChildApp_B.b_ci);
      if ((ChildApp_B.t > 4.503599627370496E+15) || (rtIsInf(ChildApp_B.b_ci) ||
           rtIsNaN(ChildApp_B.b_ci))) {
        ChildApp_B.b_ci = log(ChildApp_B.b_ci + 1.0);
      } else if (!(ChildApp_B.t < 2.2204460492503131E-16)) {
        ChildApp_B.b_ci = ChildApp_B.b_ci / ((ChildApp_B.b_ci + 1.0) - 1.0) *
          log(ChildApp_B.b_ci + 1.0);
      }
    }

    if (xneg) {
      ChildApp_B.b_ci = -ChildApp_B.b_ci;
    }

    ChildApp_B.b_m.re = rt_atan2d_snf(ChildApp_B.b_m.re, ChildApp_B.tmp);
    ChildApp_B.b_m.im = ChildApp_B.b_ci;
  }

  ChildApp_B.tmp = 2.0 * ChildApp_B.b_m.re * 6371.0;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  rtb_flag = (int16_T)(ChildApp_B.tmp > 0.1);
  if (ChildApp_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<S1>/Accelerometer' */
    ChildApp_B.out_c[0] = 0.0F;
    ChildApp_B.out_c[1] = 0.0F;
    ChildApp_B.out_c[2] = 0.0F;
    GET_ACCELEROMETER_DATA(&ChildApp_B.out_c[0], &ChildApp_B.out_c[1],
      &ChildApp_B.out_c[2]);

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  MATLABSystem: '<S1>/Accelerometer'
     */
    ChildApp_B.b_ci = ChildApp_B.out_c[0] * 0.2;
    ChildApp_B.t = ChildApp_B.out_c[1] * 0.2;
    ChildApp_B.vnet = (ChildApp_B.out_c[2] - 9.81F) * 0.2;
    ChildApp_B.vnet = sqrt((ChildApp_B.b_ci * ChildApp_B.b_ci + ChildApp_B.t *
      ChildApp_B.t) + ChildApp_B.vnet * ChildApp_B.vnet);
    if (ChildApp_B.vnet <= 0.2) {
      ChildApp_B.vnet = 0.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* MATLAB Function: '<Root>/MATLAB Function5' */
    ChildApp_B.y = (int16_T)(ChildApp_B.vnet > 5.0);

    /* MATLABSystem: '<S5>/MATLAB System' */
    ChildApp_B.out_c[0] = 0.0F;
    ChildApp_B.out_c[1] = 0.0F;
    ChildApp_B.out_c[2] = 0.0F;
    GET_GYROSCOPE_DATA(&ChildApp_B.out_c[0], &ChildApp_B.out_c[1],
                       &ChildApp_B.out_c[2]);
    rtb_MATLABSystem_o1 = ChildApp_B.out_c[0];
    rtb_MATLABSystem_o2 = ChildApp_B.out_c[1];

    /* MATLAB Function: '<Root>/MATLAB Function9' incorporates:
     *  Delay: '<Root>/Delay'
     *  Delay: '<Root>/Delay2'
     *  MATLABSystem: '<S5>/MATLAB System'
     */
    rtb_ax = (ChildApp_DW.Delay_DSTATE - ChildApp_B.out_c[0]) / 0.2F;
    rtb_ay = (ChildApp_DW.Delay2_DSTATE - ChildApp_B.out_c[1]) / 0.2F;

    /* MATLAB Function: '<Root>/MATLAB Function6' incorporates:
     *  MATLABSystem: '<S5>/MATLAB System'
     */
    ChildApp_B.b_ci = ChildApp_B.out_c[0] * 0.2;
    ChildApp_B.t = ChildApp_B.out_c[1] * 0.2;

    /* MATLAB Function: '<Root>/MATLAB Function11' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function10'
     *  MATLAB Function: '<Root>/MATLAB Function3'
     *  MATLAB Function: '<Root>/MATLAB Function8'
     *  MATLABSystem: '<S5>/MATLAB System'
     */
    ChildApp_B.flag = 0;
    if (((real32_T)sqrt(ChildApp_B.out_c[0] * ChildApp_B.out_c[0] +
                        ChildApp_B.out_c[1] * ChildApp_B.out_c[1]) > 5.0F) &&
        ((real32_T)sqrt(rtb_ax * rtb_ax + rtb_ay * rtb_ay) > 30.0F) && (sqrt
         (ChildApp_B.b_ci * ChildApp_B.b_ci + ChildApp_B.t * ChildApp_B.t) > 0.8))
    {
      ChildApp_B.flag = 1;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function11' */
  }

  /* Logic: '<Root>/OR1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<Root>/Delay1'
   */
  ChildApp_DW.Delay1_DSTATE = ((ChildApp_P.Constant1_Value != 0.0) ||
    ChildApp_DW.Delay1_DSTATE);

  /* MATLABSystem: '<S23>/Button' */
  xneg = BUTTON_GETSTATE(1.0);

  /* MATLAB Function: '<Root>/MATLAB Function7' incorporates:
   *  MATLABSystem: '<S23>/Button'
   */
  if (!xneg) {
    if (!ChildApp_DW.Delay1_DSTATE) {
      if (ChildApp_B.flag == 1) {
        /* Logic: '<Root>/OR1' */
        ChildApp_DW.Delay1_DSTATE = true;
        rtb_f = 1;
      } else {
        rtb_f = 0;
      }
    } else {
      rtb_f = 1;
    }
  } else {
    rtb_f = 0;

    /* Logic: '<Root>/OR1' */
    ChildApp_DW.Delay1_DSTATE = false;
  }

  /* MATLAB Function: '<Root>/MATLAB Function12' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function4'
   */
  rtb_f = (int16_T)((rtb_flag == 1) || (ChildApp_B.y == 1) || (rtb_f == 1));

  /* MATLABSystem: '<S3>/Audio Playback' incorporates:
   *  MATLABSystem: '<Root>/Audio File Read1'
   *  Product: '<Root>/Product'
   */
  if (ChildApp_DW.obj_p.SampleFreq != ChildApp_P.AudioPlayback_SampleFreq) {
    ChildApp_DW.obj_p.SampleFreq = ChildApp_P.AudioPlayback_SampleFreq;
  }

  for (b_k = 0; b_k < 4410; b_k++) {
    outData_tmp = b_k << 1;
    ChildApp_B.outData[outData_tmp] = (int16_T)(rtb_f * ChildApp_B.refData[b_k]);
    ChildApp_B.outData[outData_tmp + 1] = (int16_T)(ChildApp_B.refData[b_k +
      4410] * rtb_f);
  }

  AUDIO_PLAYBACK(&ChildApp_B.outData[0], ChildApp_DW.obj_p.FrameSize);

  /* End of MATLABSystem: '<S3>/Audio Playback' */

  /* MATLABSystem: '<S2>/MATLAB System' */
  AUDIO_CAPTURE(&ChildApp_B.refData[0], 4410);

  /* MATLAB Function: '<Root>/MATLAB Function13' incorporates:
   *  Delay: '<Root>/Delay3'
   *  MATLAB Function: '<Root>/MATLAB Function7'
   */
  if (ChildApp_DW.Delay1_DSTATE) {
    rtb_f = ChildApp_DW.Delay3_DSTATE[0];
  } else {
    rtb_f = 0;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function13'
   *  MATLABSystem: '<S2>/MATLAB System'
   */
  xneg = (rtb_f != 0);
  for (b_k = 0; b_k < 2; b_k++) {
    for (outData_tmp = 0; outData_tmp < 4410; outData_tmp++) {
      if (xneg) {
        ChildApp_B.outData[outData_tmp + 4410 * b_k] = ChildApp_B.refData
          [(outData_tmp << 1) + b_k];
      } else {
        ChildApp_B.outData[outData_tmp + 4410 * b_k] = 0;
      }
    }
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<Root>/TCP//IP Send3' */
  rtb_f = ChildApp_DW.obj_pv.errorNo_;
  if (ChildApp_DW.obj_pv.isLittleEnd_ == 1) {
    for (b_k = 0; b_k < 8820; b_k++) {
      memcpy((void *)&y[0], (void *)&ChildApp_B.outData[b_k], (uint32_T)((size_t)
              2 * sizeof(uint8_T)));
      b_x[0] = y[1];
      b_x[1] = y[0];
      memcpy((void *)&y_0, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (int16_T)));
      ChildApp_B.outData[b_k] = y_0;
    }
  }

  ChildApp_B.b_ci = rt_roundd_snf(ChildApp_DW.obj_pv.isServer_);
  if (ChildApp_B.b_ci < 65536.0) {
    if (ChildApp_B.b_ci >= 0.0) {
      tmp = (uint16_T)ChildApp_B.b_ci;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  TCPStreamStepSend(&ChildApp_B.outData[0], 17640U,
                    ChildApp_DW.obj_pv.connStream_, tmp,
                    &ChildApp_DW.obj_pv.errorNo_);
  if ((rtb_f != ChildApp_DW.obj_pv.errorNo_) && (ChildApp_DW.obj_pv.errorNo_ > 0)
      && (ChildApp_DW.obj_pv.errorNo_ < 10)) {
    outData_tmp = 1;
    ChildApp_B.str_data[0] = '\x00';
    if (ChildApp_DW.obj_pv.errorNo_ == 4) {
      UPDATE_TCP_LOGI(ChildApp_DW.obj_pv.errorNo_, 3.0, 0, 25000);
    } else {
      if (ChildApp_DW.obj_pv.errorNo_ == 5) {
        outData_tmp = 7;
        for (b_k = 0; b_k < 7; b_k++) {
          ChildApp_B.str_data[b_k] = tmp_1[b_k];
        }
      }

      memcpy(&b_str_data[0], &ChildApp_B.str_data[0], (uint32_T)outData_tmp *
             sizeof(char_T));
      UPDATE_TCP_LOGS(ChildApp_DW.obj_pv.errorNo_, 3.0, 0, &b_str_data[0]);
    }
  }

  /* End of MATLABSystem: '<Root>/TCP//IP Send3' */
  if (ChildApp_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/TCP//IP Send4' */
    rtb_f = ChildApp_DW.obj_e.errorNo_;
    y_0 = ChildApp_B.y;
    if (ChildApp_DW.obj_e.isLittleEnd_ == 1) {
      memcpy((void *)&y[0], (void *)&ChildApp_B.y, (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x[0] = y[1];
      b_x[1] = y[0];
      memcpy((void *)&y_0, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (int16_T)));
    }

    ChildApp_B.b_ci = rt_roundd_snf(ChildApp_DW.obj_e.isServer_);
    if (ChildApp_B.b_ci < 65536.0) {
      if (ChildApp_B.b_ci >= 0.0) {
        tmp = (uint16_T)ChildApp_B.b_ci;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    TCPStreamStepSend(&y_0, 2U, ChildApp_DW.obj_e.connStream_, tmp,
                      &ChildApp_DW.obj_e.errorNo_);
    if ((rtb_f != ChildApp_DW.obj_e.errorNo_) && (ChildApp_DW.obj_e.errorNo_ > 0)
        && (ChildApp_DW.obj_e.errorNo_ < 10)) {
      outData_tmp = 1;
      ChildApp_B.str_data[0] = '\x00';
      if (ChildApp_DW.obj_e.errorNo_ == 4) {
        UPDATE_TCP_LOGI(ChildApp_DW.obj_e.errorNo_, 4.0, 0, 25000);
      } else {
        if (ChildApp_DW.obj_e.errorNo_ == 5) {
          outData_tmp = 7;
          for (b_k = 0; b_k < 7; b_k++) {
            ChildApp_B.str_data[b_k] = tmp_1[b_k];
          }
        }

        memcpy(&b_str_data[0], &ChildApp_B.str_data[0], (uint32_T)outData_tmp *
               sizeof(char_T));
        UPDATE_TCP_LOGS(ChildApp_DW.obj_e.errorNo_, 4.0, 0, &b_str_data[0]);
      }
    }

    /* End of MATLABSystem: '<Root>/TCP//IP Send4' */

    /* MATLABSystem: '<S24>/DataDisplay' */
    b_FormatStringTerminated[0] = '%';
    b_FormatStringTerminated[1] = '.';
    b_FormatStringTerminated[2] = '6';
    b_FormatStringTerminated[3] = 'f';
    b_FormatStringTerminated[4] = '\x00';
    PUT_DATADISPLAY_DATA(&ChildApp_B.vnet, 4.0, 9, 1, &b_FormatStringTerminated
                         [0]);
  }

  /* MATLABSystem: '<Root>/TCP//IP Send' */
  rtb_f = ChildApp_DW.obj_pe.errorNo_;
  if (ChildApp_DW.obj_pe.isLittleEnd_ == 1) {
    memcpy((void *)&y[0], (void *)&rtb_flag, (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&rtb_flag, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  }

  ChildApp_B.b_ci = rt_roundd_snf(ChildApp_DW.obj_pe.isServer_);
  if (ChildApp_B.b_ci < 65536.0) {
    if (ChildApp_B.b_ci >= 0.0) {
      tmp = (uint16_T)ChildApp_B.b_ci;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  TCPStreamStepSend(&rtb_flag, 2U, ChildApp_DW.obj_pe.connStream_, tmp,
                    &ChildApp_DW.obj_pe.errorNo_);
  if ((rtb_f != ChildApp_DW.obj_pe.errorNo_) && (ChildApp_DW.obj_pe.errorNo_ > 0)
      && (ChildApp_DW.obj_pe.errorNo_ < 10)) {
    outData_tmp = 1;
    ChildApp_B.str_data[0] = '\x00';
    if (ChildApp_DW.obj_pe.errorNo_ == 4) {
      UPDATE_TCP_LOGI(ChildApp_DW.obj_pe.errorNo_, 1.0, 0, 25000);
    } else {
      if (ChildApp_DW.obj_pe.errorNo_ == 5) {
        outData_tmp = 7;
        for (b_k = 0; b_k < 7; b_k++) {
          ChildApp_B.str_data[b_k] = tmp_1[b_k];
        }
      }

      memcpy(&b_str_data[0], &ChildApp_B.str_data[0], (uint32_T)outData_tmp *
             sizeof(char_T));
      UPDATE_TCP_LOGS(ChildApp_DW.obj_pe.errorNo_, 1.0, 0, &b_str_data[0]);
    }
  }

  /* End of MATLABSystem: '<Root>/TCP//IP Send' */

  /* MATLABSystem: '<S4>/DataDisplay' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   *  MATLABSystem: '<S6>/DataDisplay'
   *  MATLABSystem: '<S8>/DataDisplay'
   */
  ChildApp_B.b_m.re = ChildApp_B.tmp;
  ChildApp_B.b_m.im = 2.0 * ChildApp_B.b_m.im * 6371.0;
  b_FormatStringTerminated[0] = '%';
  b_FormatStringTerminated[1] = '.';
  b_FormatStringTerminated[2] = '6';
  b_FormatStringTerminated[3] = 'f';
  b_FormatStringTerminated[4] = '\x00';
  for (b_k = 0; b_k < 5; b_k++) {
    b_FormatStringTerminated_0[b_k] = b_FormatStringTerminated[b_k];
  }

  PUT_DATADISPLAY_DATA(&ChildApp_B.b_m, 1.0, 9, 1, &b_FormatStringTerminated_0[0]);

  /* End of MATLABSystem: '<S4>/DataDisplay' */

  /* MATLABSystem: '<S6>/DataDisplay' incorporates:
   *  MATLABSystem: '<S7>/Location Sensor'
   */
  for (b_k = 0; b_k < 5; b_k++) {
    b_FormatStringTerminated_0[b_k] = b_FormatStringTerminated[b_k];
  }

  PUT_DATADISPLAY_DATA(&ChildApp_B.out[0], 2.0, 9, 1,
                       &b_FormatStringTerminated_0[0]);

  /* MATLABSystem: '<S8>/DataDisplay' incorporates:
   *  MATLABSystem: '<S7>/Location Sensor'
   */
  PUT_DATADISPLAY_DATA(&ChildApp_B.out[1], 3.0, 9, 1, &b_FormatStringTerminated
                       [0]);

  /* MATLABSystem: '<Root>/TCP//IP Send1' incorporates:
   *  MATLABSystem: '<S7>/Location Sensor'
   */
  rtb_f = ChildApp_DW.obj_m.errorNo_;
  ChildApp_B.vnet = ChildApp_B.out[0];
  if (ChildApp_DW.obj_m.isLittleEnd_ == 1) {
    memcpy((void *)&ChildApp_B.b_x[0], (void *)&ChildApp_B.out[0], (uint32_T)
           ((size_t)8 * sizeof(uint8_T)));
    xtmp = ChildApp_B.b_x[0];
    ChildApp_B.b_x[0] = ChildApp_B.b_x[7];
    ChildApp_B.b_x[7] = xtmp;
    xtmp = ChildApp_B.b_x[1];
    ChildApp_B.b_x[1] = ChildApp_B.b_x[6];
    ChildApp_B.b_x[6] = xtmp;
    xtmp = ChildApp_B.b_x[2];
    ChildApp_B.b_x[2] = ChildApp_B.b_x[5];
    ChildApp_B.b_x[5] = xtmp;
    xtmp = ChildApp_B.b_x[3];
    ChildApp_B.b_x[3] = ChildApp_B.b_x[4];
    ChildApp_B.b_x[4] = xtmp;
    memcpy((void *)&ChildApp_B.vnet, (void *)&ChildApp_B.b_x[0], (uint32_T)
           ((size_t)1 * sizeof(real_T)));
  }

  ChildApp_B.b_ci = rt_roundd_snf(ChildApp_DW.obj_m.isServer_);
  if (ChildApp_B.b_ci < 65536.0) {
    if (ChildApp_B.b_ci >= 0.0) {
      tmp = (uint16_T)ChildApp_B.b_ci;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  TCPStreamStepSend(&ChildApp_B.vnet, 8U, ChildApp_DW.obj_m.connStream_, tmp,
                    &ChildApp_DW.obj_m.errorNo_);
  if ((rtb_f != ChildApp_DW.obj_m.errorNo_) && (ChildApp_DW.obj_m.errorNo_ > 0) &&
      (ChildApp_DW.obj_m.errorNo_ < 10)) {
    outData_tmp = 1;
    ChildApp_B.str_data[0] = '\x00';
    if (ChildApp_DW.obj_m.errorNo_ == 4) {
      UPDATE_TCP_LOGI(ChildApp_DW.obj_m.errorNo_, 2.0, 0, 25000);
    } else {
      if (ChildApp_DW.obj_m.errorNo_ == 5) {
        outData_tmp = 7;
        for (b_k = 0; b_k < 7; b_k++) {
          ChildApp_B.str_data[b_k] = tmp_1[b_k];
        }
      }

      memcpy(&b_str_data[0], &ChildApp_B.str_data[0], (uint32_T)outData_tmp *
             sizeof(char_T));
      UPDATE_TCP_LOGS(ChildApp_DW.obj_m.errorNo_, 2.0, 0, &b_str_data[0]);
    }
  }

  /* End of MATLABSystem: '<Root>/TCP//IP Send1' */

  /* MATLABSystem: '<Root>/TCP//IP Send7' incorporates:
   *  MATLABSystem: '<S7>/Location Sensor'
   */
  rtb_f = ChildApp_DW.obj_j.errorNo_;
  ChildApp_B.vnet = ChildApp_B.out[1];
  if (ChildApp_DW.obj_j.isLittleEnd_ == 1) {
    memcpy((void *)&ChildApp_B.b_x_k[0], (void *)&ChildApp_B.out[1], (uint32_T)
           ((size_t)8 * sizeof(uint8_T)));
    xtmp = ChildApp_B.b_x_k[0];
    ChildApp_B.b_x_k[0] = ChildApp_B.b_x_k[7];
    ChildApp_B.b_x_k[7] = xtmp;
    xtmp = ChildApp_B.b_x_k[1];
    ChildApp_B.b_x_k[1] = ChildApp_B.b_x_k[6];
    ChildApp_B.b_x_k[6] = xtmp;
    xtmp = ChildApp_B.b_x_k[2];
    ChildApp_B.b_x_k[2] = ChildApp_B.b_x_k[5];
    ChildApp_B.b_x_k[5] = xtmp;
    xtmp = ChildApp_B.b_x_k[3];
    ChildApp_B.b_x_k[3] = ChildApp_B.b_x_k[4];
    ChildApp_B.b_x_k[4] = xtmp;
    memcpy((void *)&ChildApp_B.vnet, (void *)&ChildApp_B.b_x_k[0], (uint32_T)
           ((size_t)1 * sizeof(real_T)));
  }

  ChildApp_B.b_ci = rt_roundd_snf(ChildApp_DW.obj_j.isServer_);
  if (ChildApp_B.b_ci < 65536.0) {
    if (ChildApp_B.b_ci >= 0.0) {
      tmp = (uint16_T)ChildApp_B.b_ci;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  TCPStreamStepSend(&ChildApp_B.vnet, 8U, ChildApp_DW.obj_j.connStream_, tmp,
                    &ChildApp_DW.obj_j.errorNo_);
  if ((rtb_f != ChildApp_DW.obj_j.errorNo_) && (ChildApp_DW.obj_j.errorNo_ > 0) &&
      (ChildApp_DW.obj_j.errorNo_ < 10)) {
    outData_tmp = 1;
    ChildApp_B.str_data[0] = '\x00';
    if (ChildApp_DW.obj_j.errorNo_ == 4) {
      UPDATE_TCP_LOGI(ChildApp_DW.obj_j.errorNo_, 5.0, 0, 25000);
    } else {
      if (ChildApp_DW.obj_j.errorNo_ == 5) {
        outData_tmp = 7;
        for (b_k = 0; b_k < 7; b_k++) {
          ChildApp_B.str_data[b_k] = tmp_1[b_k];
        }
      }

      memcpy(&b_str_data[0], &ChildApp_B.str_data[0], (uint32_T)outData_tmp *
             sizeof(char_T));
      UPDATE_TCP_LOGS(ChildApp_DW.obj_j.errorNo_, 5.0, 0, &b_str_data[0]);
    }
  }

  /* End of MATLABSystem: '<Root>/TCP//IP Send7' */
  if (ChildApp_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<Root>/Delay' */
    ChildApp_DW.Delay_DSTATE = rtb_MATLABSystem_o1;

    /* Update for Delay: '<Root>/Delay2' */
    ChildApp_DW.Delay2_DSTATE = rtb_MATLABSystem_o2;
  }

  /* Update for Delay: '<Root>/Delay3' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function7'
   */
  for (b_k = 0; b_k < 49; b_k++) {
    ChildApp_DW.Delay3_DSTATE[b_k] = ChildApp_DW.Delay3_DSTATE[b_k + 1];
  }

  ChildApp_DW.Delay3_DSTATE[49] = ChildApp_DW.Delay1_DSTATE;

  /* End of Update for Delay: '<Root>/Delay3' */
  rate_scheduler();
}

/* Model initialize function */
void ChildApp_initialize(void)
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

    /* InitializeConditions for Delay: '<Root>/Delay' */
    ChildApp_DW.Delay_DSTATE = ChildApp_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    ChildApp_DW.Delay2_DSTATE = ChildApp_P.Delay2_InitialCondition;

    /* InitializeConditions for Logic: '<Root>/OR1' incorporates:
     *  Delay: '<Root>/Delay1'
     */
    ChildApp_DW.Delay1_DSTATE = ChildApp_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay3' */
    for (i = 0; i < 50; i++) {
      ChildApp_DW.Delay3_DSTATE[i] = ChildApp_P.Delay3_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay3' */

    /* Start for MATLABSystem: '<Root>/Audio File Read1' */
    ChildApp_DW.obj.matlabCodegenIsDeleted = false;
    ChildApp_DW.obj.FExt[0] = 'm';
    ChildApp_DW.obj.FExt[1] = 'p';
    ChildApp_DW.obj.FExt[2] = '3';
    ChildApp_DW.obj.FExt[3] = '\x00';
    ChildApp_DW.obj.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      obj = tmp[i];
      ChildApp_DW.obj.RName[i] = obj;
      ChildApp_B.b[i] = obj;
    }

    ChildApp_B.b[38] = '\x00';
    c[0] = ChildApp_DW.obj.FExt[0];
    c[1] = ChildApp_DW.obj.FExt[1];
    c[2] = ChildApp_DW.obj.FExt[2];
    c[3] = ChildApp_DW.obj.FExt[3];
    INITIALIZE_AUDIOFILEREAD(&ChildApp_B.b[0], &c[0], 4410U,
      &ChildApp_DW.obj.Idx);
    ChildApp_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Audio File Read1' */

    /* Start for MATLABSystem: '<S7>/Location Sensor' */
    ChildApp_DW.obj_a.matlabCodegenIsDeleted = false;
    ChildApp_DW.obj_a.isInitialized = 1;
    INIT_LOCATION_SENSOR();
    ChildApp_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Accelerometer' */
    ChildApp_DW.obj_k.matlabCodegenIsDeleted = false;
    ChildApp_DW.obj_k.isInitialized = 1;
    INITIALIZE_ACCELEROMETER();
    ChildApp_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/MATLAB System' */
    ChildApp_DW.obj_l.matlabCodegenIsDeleted = false;
    ChildApp_DW.obj_l.isInitialized = 1;
    INITIALIZE_GYROSCOPE();
    ChildApp_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S23>/Button' */
    BUTTON_INIT(1.0);

    /* Start for MATLABSystem: '<S3>/Audio Playback' */
    ChildApp_DW.obj_p.matlabCodegenIsDeleted = false;
    ChildApp_DW.obj_p.SampleFreq = ChildApp_P.AudioPlayback_SampleFreq;
    ChildApp_DW.obj_p.isInitialized = 1;
    ChildApp_DW.obj_p.FrameSize = 4410.0;
    INIT_AUDIO_PLAYBACK(ChildApp_DW.obj_p.SampleFreq,
                        ChildApp_DW.obj_p.FrameSize);
    ChildApp_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/MATLAB System' */
    ChildApp_DW.obj_n.matlabCodegenIsDeleted = false;
    ChildApp_DW.obj_n.isInitialized = 1;
    INIT_AUDIO_CAPTURE(44100.0, 4410);
    ChildApp_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/TCP//IP Send3' */
    ChildApp_DW.obj_pv.errorNo_ = 0;
    ChildApp_DW.obj_pv.isInitialized = 0;
    ChildApp_SystemCore_setup_ej(&ChildApp_DW.obj_pv);

    /* Start for MATLABSystem: '<Root>/TCP//IP Send4' */
    ChildApp_DW.obj_e.errorNo_ = 0;
    ChildApp_DW.obj_e.isInitialized = 0;
    ChildApp_SystemCore_setup_ejw(&ChildApp_DW.obj_e);

    /* Start for MATLABSystem: '<S24>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/TCP//IP Send' */
    ChildApp_DW.obj_pe.errorNo_ = 0;
    ChildApp_DW.obj_pe.isInitialized = 0;
    ChildApp_SystemCore_setup(&ChildApp_DW.obj_pe);

    /* Start for MATLABSystem: '<S4>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S6>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S8>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/TCP//IP Send1' */
    ChildApp_DW.obj_m.errorNo_ = 0;
    ChildApp_DW.obj_m.isInitialized = 0;
    ChildApp_SystemCore_setup_e(&ChildApp_DW.obj_m);

    /* Start for MATLABSystem: '<Root>/TCP//IP Send7' */
    ChildApp_DW.obj_j.errorNo_ = 0;
    ChildApp_DW.obj_j.isInitialized = 0;
    ChildApp_SystemCore_setup_ejw1(&ChildApp_DW.obj_j);
  }
}

/* Model terminate function */
void ChildApp_terminate(void)
{
  int32_T tmp;

  /* Terminate for MATLABSystem: '<Root>/Audio File Read1' */
  if (!ChildApp_DW.obj.matlabCodegenIsDeleted) {
    ChildApp_DW.obj.matlabCodegenIsDeleted = true;
    if ((ChildApp_DW.obj.isInitialized == 1) && ChildApp_DW.obj.isSetupComplete)
    {
      tmp = ChildApp_DW.obj.Idx;
      if (ChildApp_DW.obj.Idx < 0) {
        tmp = 0;
      }

      TERMINATE_AUDIOFILEREAD((uint32_T)tmp);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Audio File Read1' */

  /* Terminate for MATLABSystem: '<S7>/Location Sensor' */
  if (!ChildApp_DW.obj_a.matlabCodegenIsDeleted) {
    ChildApp_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Location Sensor' */

  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!ChildApp_DW.obj_k.matlabCodegenIsDeleted) {
    ChildApp_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */

  /* Terminate for MATLABSystem: '<S5>/MATLAB System' */
  if (!ChildApp_DW.obj_l.matlabCodegenIsDeleted) {
    ChildApp_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/MATLAB System' */

  /* Terminate for MATLABSystem: '<S3>/Audio Playback' */
  if (!ChildApp_DW.obj_p.matlabCodegenIsDeleted) {
    ChildApp_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((ChildApp_DW.obj_p.isInitialized == 1) &&
        ChildApp_DW.obj_p.isSetupComplete) {
      TERMINATE_AUDIO_PLAYBACK();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Audio Playback' */

  /* Terminate for MATLABSystem: '<S2>/MATLAB System' */
  if (!ChildApp_DW.obj_n.matlabCodegenIsDeleted) {
    ChildApp_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((ChildApp_DW.obj_n.isInitialized == 1) &&
        ChildApp_DW.obj_n.isSetupComplete) {
      TERMINATE_AUDIO_CAPTURE();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
