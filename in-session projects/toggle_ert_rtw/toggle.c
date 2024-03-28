/*
 * File: toggle.c
 *
 * Code generated for Simulink model 'toggle'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar 18 03:56:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "toggle.h"
#include "rtwtypes.h"
#include "toggle_private.h"

/* Block signals (default storage) */
B_toggle_T toggle_B;

/* Block states (default storage) */
DW_toggle_T toggle_DW;

/* Real-time model */
static RT_MODEL_toggle_T toggle_M_;
RT_MODEL_toggle_T *const toggle_M = &toggle_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void toggle_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(toggle_M, 1));
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
  (toggle_M->Timing.TaskCounters.TID[1])++;
  if ((toggle_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    toggle_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void toggle_step0(void)                /* Sample time: [0.001s, 0.0s] */
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
  toggle_M->Timing.taskTime0 =
    ((time_T)(++toggle_M->Timing.clockTick0)) * toggle_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void toggle_step1(void)                /* Sample time: [0.1s, 0.0s] */
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(toggle_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(toggle_DW.IfActionSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/Digital Input' */
  if (toggle_DW.obj.SampleTime != toggle_P.DigitalInput_SampleTime) {
    toggle_DW.obj.SampleTime = toggle_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  toggle_B.DigitalInput = readDigitalPin(7);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (toggle_B.DigitalInput) {
    if (!toggle_DW.EnabledSubsystem_MODE) {
      /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
      toggle_DW.UnitDelay_DSTATE = toggle_P.UnitDelay_InitialCondition;
      toggle_DW.EnabledSubsystem_MODE = true;
    }

    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Constant'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    toggle_B.Add = toggle_P.Constant_Value + toggle_DW.UnitDelay_DSTATE;

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    toggle_DW.UnitDelay_DSTATE = toggle_B.Add;
    srUpdateBC(toggle_DW.EnabledSubsystem_SubsysRanBC);
  } else if (toggle_DW.EnabledSubsystem_MODE) {
    /* Disable for Sum: '<S1>/Add' incorporates:
     *  Outport: '<S1>/Out1'
     */
    toggle_B.Add = toggle_P.Out1_Y0;
    toggle_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* If: '<Root>/If' */
  if (toggle_B.Add == 65.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Logic: '<S2>/NOT' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    toggle_B.NOT = !toggle_DW.UnitDelay_DSTATE_j;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    toggle_DW.UnitDelay_DSTATE_j = toggle_B.NOT;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(toggle_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of If: '<Root>/If' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(8, (uint8_T)toggle_B.NOT);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  toggle_M->Timing.clockTick1++;
}

/* Model initialize function */
void toggle_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(toggle_M, -1);
  toggle_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  toggle_M->Sizes.checksums[0] = (645523818U);
  toggle_M->Sizes.checksums[1] = (1291371727U);
  toggle_M->Sizes.checksums[2] = (3320811874U);
  toggle_M->Sizes.checksums[3] = (200522231U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    toggle_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&toggle_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&toggle_DW.IfActionSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(toggle_M->extModeInfo,
      &toggle_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(toggle_M->extModeInfo, toggle_M->Sizes.checksums);
    rteiSetTPtr(toggle_M->extModeInfo, rtmGetTPtr(toggle_M));
  }

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  toggle_DW.UnitDelay_DSTATE = toggle_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Sum: '<S1>/Add' incorporates:
   *  Outport: '<S1>/Out1'
   */
  toggle_B.Add = toggle_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  toggle_DW.UnitDelay_DSTATE_j = toggle_P.UnitDelay_InitialCondition_n;

  /* SystemInitialize for Logic: '<S2>/NOT' incorporates:
   *  Outport: '<S2>/Out1'
   */
  toggle_B.NOT = toggle_P.Out1_Y0_d;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  toggle_DW.obj.matlabCodegenIsDeleted = false;
  toggle_DW.obj.SampleTime = toggle_P.DigitalInput_SampleTime;
  toggle_DW.obj.isInitialized = 1L;
  digitalIOSetup(7, 0);
  toggle_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  toggle_DW.obj_a.matlabCodegenIsDeleted = false;
  toggle_DW.obj_a.isInitialized = 1L;
  digitalIOSetup(8, 1);
  toggle_DW.obj_a.isSetupComplete = true;
}

/* Model terminate function */
void toggle_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!toggle_DW.obj.matlabCodegenIsDeleted) {
    toggle_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!toggle_DW.obj_a.matlabCodegenIsDeleted) {
    toggle_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
