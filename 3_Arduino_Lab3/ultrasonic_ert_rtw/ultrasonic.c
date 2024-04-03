/*
 * File: ultrasonic.c
 *
 * Code generated for Simulink model 'ultrasonic'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar 28 16:34:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ultrasonic.h"
#include "rtwtypes.h"
#include "ultrasonic_private.h"
#include <math.h>

/* Block states (default storage) */
DW_ultrasonic_T ultrasonic_DW;

/* Real-time model */
static RT_MODEL_ultrasonic_T ultrasonic_M_;
RT_MODEL_ultrasonic_T *const ultrasonic_M = &ultrasonic_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ultrasonic_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ultrasonic_M, 1));
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
  (ultrasonic_M->Timing.TaskCounters.TID[1])++;
  if ((ultrasonic_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    ultrasonic_M->Timing.TaskCounters.TID[1] = 0;
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
void ultrasonic_step0(void)            /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void ultrasonic_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_UltrasonicSensor;
  uint32_T duration;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (ultrasonic_DW.obj_i.TunablePropsChanged) {
    ultrasonic_DW.obj_i.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 0, 3, 3, 5);
  rtb_UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  /* End of MATLABSystem: '<Root>/Ultrasonic Sensor' */

  /* If: '<Root>/If' */
  if (rtb_UltrasonicSensor <= 20.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* MATLABSystem: '<S1>/Digital Output' incorporates:
     *  Constant: '<S1>/Constant'
     */
    rtb_UltrasonicSensor = rt_roundd_snf(ultrasonic_P.Constant_Value);
    if (rtb_UltrasonicSensor < 256.0) {
      if (rtb_UltrasonicSensor >= 0.0) {
        tmp = (uint8_T)rtb_UltrasonicSensor;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(9, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  } else if (rtb_UltrasonicSensor <= 40.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MATLABSystem: '<S2>/Digital Output' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_UltrasonicSensor = rt_roundd_snf(ultrasonic_P.Constant_Value_f);
    if (rtb_UltrasonicSensor < 256.0) {
      if (rtb_UltrasonicSensor >= 0.0) {
        tmp = (uint8_T)rtb_UltrasonicSensor;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(10, tmp);

    /* End of MATLABSystem: '<S2>/Digital Output' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  } else if (rtb_UltrasonicSensor <= 60.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* MATLABSystem: '<S3>/Digital Output' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_UltrasonicSensor = rt_roundd_snf(ultrasonic_P.Constant_Value_ff);
    if (rtb_UltrasonicSensor < 256.0) {
      if (rtb_UltrasonicSensor >= 0.0) {
        tmp = (uint8_T)rtb_UltrasonicSensor;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(11, tmp);

    /* End of MATLABSystem: '<S3>/Digital Output' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
  } else if (rtb_UltrasonicSensor <= 80.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_UltrasonicSensor = rt_roundd_snf(ultrasonic_P.Constant_Value_d);
    if (rtb_UltrasonicSensor < 256.0) {
      if (rtb_UltrasonicSensor >= 0.0) {
        tmp = (uint8_T)rtb_UltrasonicSensor;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(12, tmp);

    /* End of MATLABSystem: '<S4>/Digital Output' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem3' */
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void ultrasonic_initialize(void)
{
  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* Start for MATLABSystem: '<S1>/Digital Output' */
  ultrasonic_DW.obj_d.matlabCodegenIsDeleted = false;
  ultrasonic_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(9, 1);
  ultrasonic_DW.obj_d.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem1' */
  /* Start for MATLABSystem: '<S2>/Digital Output' */
  ultrasonic_DW.obj_lm.matlabCodegenIsDeleted = false;
  ultrasonic_DW.obj_lm.isInitialized = 1L;
  digitalIOSetup(10, 1);
  ultrasonic_DW.obj_lm.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem2' */
  /* Start for MATLABSystem: '<S3>/Digital Output' */
  ultrasonic_DW.obj_l.matlabCodegenIsDeleted = false;
  ultrasonic_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(11, 1);
  ultrasonic_DW.obj_l.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem3' */
  /* Start for MATLABSystem: '<S4>/Digital Output' */
  ultrasonic_DW.obj.matlabCodegenIsDeleted = false;
  ultrasonic_DW.obj.isInitialized = 1L;
  digitalIOSetup(12, 1);
  ultrasonic_DW.obj.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem3' */

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ultrasonic_DW.obj_i.isInitialized = 1L;
  ultrasonic_DW.obj_i.TunablePropsChanged = false;
}

/* Model terminate function */
void ultrasonic_terminate(void)
{
  /* Terminate for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!ultrasonic_DW.obj_d.matlabCodegenIsDeleted) {
    ultrasonic_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
  /* End of Terminate for SubSystem: '<Root>/If Action Subsystem' */

  /* Terminate for IfAction SubSystem: '<Root>/If Action Subsystem1' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!ultrasonic_DW.obj_lm.matlabCodegenIsDeleted) {
    ultrasonic_DW.obj_lm.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
  /* End of Terminate for SubSystem: '<Root>/If Action Subsystem1' */

  /* Terminate for IfAction SubSystem: '<Root>/If Action Subsystem2' */
  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!ultrasonic_DW.obj_l.matlabCodegenIsDeleted) {
    ultrasonic_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */
  /* End of Terminate for SubSystem: '<Root>/If Action Subsystem2' */

  /* Terminate for IfAction SubSystem: '<Root>/If Action Subsystem3' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!ultrasonic_DW.obj.matlabCodegenIsDeleted) {
    ultrasonic_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */
  /* End of Terminate for SubSystem: '<Root>/If Action Subsystem3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
