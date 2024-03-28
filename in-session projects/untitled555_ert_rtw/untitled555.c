/*
 * File: untitled555.c
 *
 * Code generated for Simulink model 'untitled555'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar 18 15:29:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled555.h"
#include "rtwtypes.h"
#include "untitled555_private.h"

/* Block states (default storage) */
DW_untitled555_T untitled555_DW;

/* Real-time model */
static RT_MODEL_untitled555_T untitled555_M_;
RT_MODEL_untitled555_T *const untitled555_M = &untitled555_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void untitled555_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(untitled555_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled555_M->Timing.TaskCounters.TID[1])++;
  if ((untitled555_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    untitled555_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void untitled555_step0(void)           /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled555_M->Timing.taskTime0 =
    ((time_T)(++untitled555_M->Timing.clockTick0)) *
    untitled555_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void untitled555_step1(void)           /* Sample time: [0.1s, 0.0s] */
{
  boolean_T b_value;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (untitled555_DW.obj.SampleTime != untitled555_P.DigitalInput_SampleTime) {
    untitled555_DW.obj.SampleTime = untitled555_P.DigitalInput_SampleTime;
  }

  b_value = readDigitalPin(4);

  /* Switch: '<Root>/Switch' incorporates:
   *  Logic: '<Root>/NOT'
   *  MATLABSystem: '<Root>/Digital Input'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  if (b_value) {
    untitled555_DW.UnitDelay1_DSTATE = !untitled555_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  writeDigitalPin(3, (uint8_T)untitled555_DW.UnitDelay1_DSTATE);

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  untitled555_DW.UnitDelay_DSTATE = untitled555_DW.UnitDelay1_DSTATE;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled555_M->Timing.clockTick1++;
}

/* Model initialize function */
void untitled555_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled555_M, -1);
  untitled555_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled555_M->Sizes.checksums[0] = (2449464935U);
  untitled555_M->Sizes.checksums[1] = (321860139U);
  untitled555_M->Sizes.checksums[2] = (2236525932U);
  untitled555_M->Sizes.checksums[3] = (1530932213U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled555_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled555_M->extModeInfo,
      &untitled555_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled555_M->extModeInfo,
                        untitled555_M->Sizes.checksums);
    rteiSetTPtr(untitled555_M->extModeInfo, rtmGetTPtr(untitled555_M));
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  untitled555_DW.UnitDelay_DSTATE = untitled555_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  untitled555_DW.UnitDelay1_DSTATE = untitled555_P.UnitDelay1_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  untitled555_DW.obj.matlabCodegenIsDeleted = false;
  untitled555_DW.obj.SampleTime = untitled555_P.DigitalInput_SampleTime;
  untitled555_DW.obj.isInitialized = 1L;
  digitalIOSetup(4, 0);
  untitled555_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled555_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled555_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(3, 1);
  untitled555_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void untitled555_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!untitled555_DW.obj.matlabCodegenIsDeleted) {
    untitled555_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled555_DW.obj_h.matlabCodegenIsDeleted) {
    untitled555_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
