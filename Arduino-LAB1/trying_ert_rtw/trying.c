/*
 * File: trying.c
 *
 * Code generated for Simulink model 'trying'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar  9 20:55:31 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "trying.h"
#include "rtwtypes.h"
#include "trying_private.h"
#include <math.h>

/* Block signals (default storage) */
B_trying_T trying_B;

/* Block states (default storage) */
DW_trying_T trying_DW;

/* Real-time model */
static RT_MODEL_trying_T trying_M_;
RT_MODEL_trying_T *const trying_M = &trying_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void trying_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(trying_M, 1));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  trying_M->Timing.RateInteraction.TID0_1 = (trying_M->Timing.TaskCounters.TID[1]
    == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (trying_M->Timing.TaskCounters.TID[1])++;
  if ((trying_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    trying_M->Timing.TaskCounters.TID[1] = 0;
  }
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

/* Model step function for TID0 */
void trying_step0(void)                /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  real_T rtb_PulseGenerator1;
  uint8_T tmp;
  boolean_T rtb_AND;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(trying_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(trying_DW.IfActionSubsystem1_SubsysRanBC);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (trying_DW.clockTickCounter <
                        trying_P.PulseGenerator_Duty) &&
    (trying_DW.clockTickCounter >= 0L) ? trying_P.PulseGenerator_Amp : 0.0;
  if (trying_DW.clockTickCounter >= trying_P.PulseGenerator_Period - 1.0) {
    trying_DW.clockTickCounter = 0L;
  } else {
    trying_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* RateTransition generated from: '<Root>/AND' */
  if (trying_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/AND' */
    trying_B.TmpRTBAtANDInport2 = trying_DW.TmpRTBAtANDInport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/AND' */

  /* Logic: '<Root>/AND' */
  rtb_AND = ((rtb_PulseGenerator != 0.0) && trying_B.TmpRTBAtANDInport2);

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(3, (uint8_T)rtb_AND);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator1 = (trying_DW.clockTickCounter_c <
    trying_P.PulseGenerator1_Duty) && (trying_DW.clockTickCounter_c >= 0L) ?
    trying_P.PulseGenerator1_Amp : 0.0;
  if (trying_DW.clockTickCounter_c >= trying_P.PulseGenerator1_Period - 1.0) {
    trying_DW.clockTickCounter_c = 0L;
  } else {
    trying_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* If: '<Root>/If' */
  if (!rtb_AND) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Logic: '<S1>/NOT'
     *  SignalConversion generated from: '<S1>/In1'
     */
    rtb_PulseGenerator = !(rtb_PulseGenerator1 != 0.0);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(trying_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/Out1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_PulseGenerator1 = trying_P.Constant_Value;

    /* SignalConversion generated from: '<S2>/Output' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_PulseGenerator = trying_P.Constant_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(trying_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  rtb_PulseGenerator1 = rt_roundd_snf(rtb_PulseGenerator1);
  if (rtb_PulseGenerator1 < 256.0) {
    if (rtb_PulseGenerator1 >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  rtb_PulseGenerator1 = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator1 < 256.0) {
    if (rtb_PulseGenerator1 >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  trying_M->Timing.taskTime0 =
    ((time_T)(++trying_M->Timing.clockTick0)) * trying_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void trying_step1(void)                /* Sample time: [0.1s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Digital Input' */
  if (trying_DW.obj.SampleTime != trying_P.DigitalInput_SampleTime) {
    trying_DW.obj.SampleTime = trying_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  trying_B.DigitalInput = readDigitalPin(2);

  /* RateTransition generated from: '<Root>/AND' */
  trying_DW.TmpRTBAtANDInport2_Buffer0 = trying_B.DigitalInput;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  trying_M->Timing.clockTick1++;
}

/* Model initialize function */
void trying_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(trying_M, -1);
  trying_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  trying_M->Sizes.checksums[0] = (3618037689U);
  trying_M->Sizes.checksums[1] = (841514696U);
  trying_M->Sizes.checksums[2] = (2882150082U);
  trying_M->Sizes.checksums[3] = (1052406971U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    trying_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&trying_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&trying_DW.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(trying_M->extModeInfo,
      &trying_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(trying_M->extModeInfo, trying_M->Sizes.checksums);
    rteiSetTPtr(trying_M->extModeInfo, rtmGetTPtr(trying_M));
  }

  /* Start for RateTransition generated from: '<Root>/AND' */
  trying_B.TmpRTBAtANDInport2 = trying_P.TmpRTBAtANDInport2_InitialCondi;

  /* InitializeConditions for RateTransition generated from: '<Root>/AND' */
  trying_DW.TmpRTBAtANDInport2_Buffer0 =
    trying_P.TmpRTBAtANDInport2_InitialCondi;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  trying_DW.obj_b.matlabCodegenIsDeleted = false;
  trying_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(3, 1);
  trying_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  trying_DW.obj_o.matlabCodegenIsDeleted = false;
  trying_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(4, 1);
  trying_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  trying_DW.obj_p.matlabCodegenIsDeleted = false;
  trying_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(5, 1);
  trying_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  trying_DW.obj.matlabCodegenIsDeleted = false;
  trying_DW.obj.SampleTime = trying_P.DigitalInput_SampleTime;
  trying_DW.obj.isInitialized = 1L;
  digitalIOSetup(2, 0);
  trying_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void trying_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!trying_DW.obj_b.matlabCodegenIsDeleted) {
    trying_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!trying_DW.obj_o.matlabCodegenIsDeleted) {
    trying_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!trying_DW.obj_p.matlabCodegenIsDeleted) {
    trying_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!trying_DW.obj.matlabCodegenIsDeleted) {
    trying_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
