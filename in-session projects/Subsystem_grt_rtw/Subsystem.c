/*
 * Subsystem.c
 *
 * Code generation for model "Subsystem".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Feb 20 03:00:03 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include <math.h>
#include <string.h>
#include "Subsystem_private.h"
#include "rt_nonfinite.h"

/* External inputs (root inport signals with default storage) */
ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Subsystem_T Subsystem_Y;

/* Real-time model */
static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

/* Model step function */
void Subsystem_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In3'
   *  MinMax: '<S1>/Max'
   *  MinMax: '<S1>/Min'
   */
  Subsystem_Y.Out1 = fmax(Subsystem_U.In1, fmin(Subsystem_U.In3, Subsystem_U.In2));

  /* Matfile logging */
  rt_UpdateTXYLogVars(Subsystem_M->rtwLogInfo, (&Subsystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(Subsystem_M)!=-1) &&
        !((rtmGetTFinal(Subsystem_M)-Subsystem_M->Timing.taskTime0) >
          Subsystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Subsystem_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Subsystem_M->Timing.clockTick0)) {
    ++Subsystem_M->Timing.clockTickH0;
  }

  Subsystem_M->Timing.taskTime0 = Subsystem_M->Timing.clockTick0 *
    Subsystem_M->Timing.stepSize0 + Subsystem_M->Timing.clockTickH0 *
    Subsystem_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Subsystem_M, 0,
                sizeof(RT_MODEL_Subsystem_T));
  rtmSetTFinal(Subsystem_M, 10.0);
  Subsystem_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Subsystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Subsystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Subsystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(Subsystem_M->rtwLogInfo, "tout");
    rtliSetLogX(Subsystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(Subsystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Subsystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Subsystem_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Subsystem_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Subsystem_M->rtwLogInfo, 1);
    rtliSetLogY(Subsystem_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Subsystem_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Subsystem_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&Subsystem_U, 0, sizeof(ExtU_Subsystem_T));

  /* external outputs */
  Subsystem_Y.Out1 = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Subsystem_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Subsystem_M), Subsystem_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Subsystem_M)));
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}
