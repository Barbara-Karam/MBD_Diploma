/*
 * File: DigitalnputOutput.c
 *
 * Code generated for Simulink model 'DigitalnputOutput'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Mar 17 04:38:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DigitalnputOutput.h"
#include "rtwtypes.h"
#include "DigitalnputOutput_private.h"
#include <math.h>

/* Block signals (default storage) */
B_DigitalnputOutput_T DigitalnputOutput_B;

/* Block states (default storage) */
DW_DigitalnputOutput_T DigitalnputOutput_DW;

/* Real-time model */
static RT_MODEL_DigitalnputOutput_T DigitalnputOutput_M_;
RT_MODEL_DigitalnputOutput_T *const DigitalnputOutput_M = &DigitalnputOutput_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void DigitalnputOutput_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(DigitalnputOutput_M, 1));
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
  (DigitalnputOutput_M->Timing.TaskCounters.TID[1])++;
  if ((DigitalnputOutput_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    DigitalnputOutput_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S12>/Enabled Subsystem4'
 *    '<S13>/Enabled Subsystem'
 *    '<S14>/Enabled Subsystem2'
 *    '<S15>/Enabled Subsystem3'
 *    '<S16>/Enabled Subsystem1'
 */
void Digi_EnabledSubsystem4_Init(real_T *rty_Out1,
  DW_EnabledSubsystem4_Digitaln_T *localDW, P_EnabledSubsystem4_Digitalnp_T
  *localP)
{
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<S17>/Out1' */
  *rty_Out1 = localP->Out1_Y0;
}

/*
 * System reset for enable system:
 *    '<S12>/Enabled Subsystem4'
 *    '<S13>/Enabled Subsystem'
 *    '<S14>/Enabled Subsystem2'
 *    '<S15>/Enabled Subsystem3'
 *    '<S16>/Enabled Subsystem1'
 */
void Dig_EnabledSubsystem4_Reset(DW_EnabledSubsystem4_Digitaln_T *localDW,
  P_EnabledSubsystem4_Digitalnp_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;
}

/*
 * Disable for enable system:
 *    '<S12>/Enabled Subsystem4'
 *    '<S13>/Enabled Subsystem'
 *    '<S14>/Enabled Subsystem2'
 *    '<S15>/Enabled Subsystem3'
 *    '<S16>/Enabled Subsystem1'
 */
void D_EnabledSubsystem4_Disable(DW_EnabledSubsystem4_Digitaln_T *localDW)
{
  localDW->EnabledSubsystem4_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S12>/Enabled Subsystem4'
 *    '<S13>/Enabled Subsystem'
 *    '<S14>/Enabled Subsystem2'
 *    '<S15>/Enabled Subsystem3'
 *    '<S16>/Enabled Subsystem1'
 */
void Digitalnp_EnabledSubsystem4(boolean_T rtu_Enable, real_T *rty_Out1,
  DW_EnabledSubsystem4_Digitaln_T *localDW, P_EnabledSubsystem4_Digitalnp_T
  *localP)
{
  /* Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem4' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->EnabledSubsystem4_MODE) {
      Dig_EnabledSubsystem4_Reset(localDW, localP);
      localDW->EnabledSubsystem4_MODE = true;
    }

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    *rty_Out1 = localP->Constant_Value + localDW->UnitDelay_DSTATE;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    localDW->UnitDelay_DSTATE = *rty_Out1;
    srUpdateBC(localDW->EnabledSubsystem4_SubsysRanBC);
  } else if (localDW->EnabledSubsystem4_MODE) {
    D_EnabledSubsystem4_Disable(localDW);
  }

  /* End of Outputs for SubSystem: '<S12>/Enabled Subsystem4' */
}

/*
 * Output and update for action system:
 *    '<S12>/If Action Subsystem8'
 *    '<S12>/If Action Subsystem9'
 *    '<S13>/If Action Subsystem'
 *    '<S13>/If Action Subsystem1'
 *    '<S14>/If Action Subsystem4'
 *    '<S14>/If Action Subsystem5'
 *    '<S15>/If Action Subsystem6'
 *    '<S15>/If Action Subsystem7'
 *    '<S16>/If Action Subsystem2'
 *    '<S16>/If Action Subsystem3'
 */
void Digitaln_IfActionSubsystem8(real_T *rty_Out1,
  P_IfActionSubsystem8_Digitaln_T *localP)
{
  /* SignalConversion generated from: '<S18>/Out1' incorporates:
   *  Constant: '<S18>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
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
void DigitalnputOutput_step0(void)     /* Sample time: [0.001s, 0.0s] */
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
  DigitalnputOutput_M->Timing.taskTime0 =
    ((time_T)(++DigitalnputOutput_M->Timing.clockTick0)) *
    DigitalnputOutput_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void DigitalnputOutput_step1(void)     /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Merge;
  real_T rtb_Merge1;
  real_T rtb_Merge2;
  real_T rtb_Merge3;
  real_T rtb_Merge4;
  int8_T rtAction;
  uint8_T tmp;
  boolean_T b_value;

  /* Reset subsysRan breadcrumbs */
  srClearBC(DigitalnputOutput_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DigitalnputOutput_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DigitalnputOutput_DW.EnabledSubsystem4.EnabledSubsystem4_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (DigitalnputOutput_DW.IfActionSubsystem8.IfActionSubsystem8_SubsysRanBC);

  /* MATLABSystem: '<Root>/Digital Input4' */
  if (DigitalnputOutput_DW.obj.SampleTime !=
      DigitalnputOutput_P.DigitalInput4_SampleTime) {
    DigitalnputOutput_DW.obj.SampleTime =
      DigitalnputOutput_P.DigitalInput4_SampleTime;
  }

  b_value = readDigitalPin(2);

  /* Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem4' */
  Digitalnp_EnabledSubsystem4(b_value, &DigitalnputOutput_B.Add_l,
    &DigitalnputOutput_DW.EnabledSubsystem4,
    &DigitalnputOutput_P.EnabledSubsystem4);

  /* End of MATLABSystem: '<Root>/Digital Input4' */
  /* End of Outputs for SubSystem: '<S12>/Enabled Subsystem4' */

  /* If: '<S12>/If4' */
  if (DigitalnputOutput_B.Add_l == 1.0) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge4,
      &DigitalnputOutput_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem8' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge4,
      &DigitalnputOutput_P.IfActionSubsystem9);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem9' */
  }

  /* End of If: '<S12>/If4' */

  /* MATLABSystem: '<Root>/Digital Input2' */
  if (DigitalnputOutput_DW.obj_i.SampleTime !=
      DigitalnputOutput_P.DigitalInput2_SampleTime) {
    DigitalnputOutput_DW.obj_i.SampleTime =
      DigitalnputOutput_P.DigitalInput2_SampleTime;
  }

  b_value = readDigitalPin(3);

  /* Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem2' */
  Digitalnp_EnabledSubsystem4(b_value, &DigitalnputOutput_B.Add_p,
    &DigitalnputOutput_DW.EnabledSubsystem2,
    &DigitalnputOutput_P.EnabledSubsystem2);

  /* End of MATLABSystem: '<Root>/Digital Input2' */
  /* End of Outputs for SubSystem: '<S14>/Enabled Subsystem2' */

  /* If: '<S14>/If2' */
  if (DigitalnputOutput_B.Add_p == 1.0) {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge2,
      &DigitalnputOutput_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge2,
      &DigitalnputOutput_P.IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem5' */
  }

  /* End of If: '<S14>/If2' */

  /* MATLABSystem: '<Root>/Digital Input' */
  if (DigitalnputOutput_DW.obj_j.SampleTime !=
      DigitalnputOutput_P.DigitalInput_SampleTime) {
    DigitalnputOutput_DW.obj_j.SampleTime =
      DigitalnputOutput_P.DigitalInput_SampleTime;
  }

  b_value = readDigitalPin(4);

  /* Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' */
  Digitalnp_EnabledSubsystem4(b_value, &DigitalnputOutput_B.Add_d,
    &DigitalnputOutput_DW.EnabledSubsystem,
    &DigitalnputOutput_P.EnabledSubsystem);

  /* End of MATLABSystem: '<Root>/Digital Input' */
  /* End of Outputs for SubSystem: '<S13>/Enabled Subsystem' */

  /* If: '<S13>/If' */
  if (DigitalnputOutput_B.Add_d == 1.0) {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge,
      &DigitalnputOutput_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge,
      &DigitalnputOutput_P.IfActionSubsystem1_j);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem1' */
  }

  /* End of If: '<S13>/If' */

  /* MATLABSystem: '<Root>/Digital Input3' */
  if (DigitalnputOutput_DW.obj_e.SampleTime !=
      DigitalnputOutput_P.DigitalInput3_SampleTime) {
    DigitalnputOutput_DW.obj_e.SampleTime =
      DigitalnputOutput_P.DigitalInput3_SampleTime;
  }

  b_value = readDigitalPin(5);

  /* Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem3' */
  Digitalnp_EnabledSubsystem4(b_value, &DigitalnputOutput_B.Add_n,
    &DigitalnputOutput_DW.EnabledSubsystem3,
    &DigitalnputOutput_P.EnabledSubsystem3);

  /* End of MATLABSystem: '<Root>/Digital Input3' */
  /* End of Outputs for SubSystem: '<S15>/Enabled Subsystem3' */

  /* If: '<S15>/If3' */
  if (DigitalnputOutput_B.Add_n == 1.0) {
    /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge3,
      &DigitalnputOutput_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S15>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge3,
      &DigitalnputOutput_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S15>/If Action Subsystem7' */
  }

  /* End of If: '<S15>/If3' */

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (DigitalnputOutput_DW.obj_f.SampleTime !=
      DigitalnputOutput_P.DigitalInput1_SampleTime) {
    DigitalnputOutput_DW.obj_f.SampleTime =
      DigitalnputOutput_P.DigitalInput1_SampleTime;
  }

  b_value = readDigitalPin(6);

  /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem1' */
  Digitalnp_EnabledSubsystem4(b_value, &DigitalnputOutput_B.Add,
    &DigitalnputOutput_DW.EnabledSubsystem1,
    &DigitalnputOutput_P.EnabledSubsystem1);

  /* End of MATLABSystem: '<Root>/Digital Input1' */
  /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem1' */

  /* If: '<S16>/If1' */
  if (DigitalnputOutput_B.Add == 1.0) {
    /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge1,
      &DigitalnputOutput_P.IfActionSubsystem2_e);

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    Digitaln_IfActionSubsystem8(&rtb_Merge1,
      &DigitalnputOutput_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem3' */
  }

  /* End of If: '<S16>/If1' */

  /* If: '<S4>/If' incorporates:
   *  Logic: '<S4>/AND'
   *  Logic: '<S4>/OR'
   */
  if ((rtb_Merge4 != 0.0) && (rtb_Merge2 != 0.0) && (rtb_Merge != 0.0) &&
      (rtb_Merge3 != 0.0) && (rtb_Merge1 != 0.0)) {
    rtAction = 0;
  } else if ((!(rtb_Merge4 != 0.0)) && (!(rtb_Merge2 != 0.0)) && (!(rtb_Merge !=
    0.0)) && (!(rtb_Merge3 != 0.0)) && (!(rtb_Merge1 != 0.0))) {
    rtAction = 1;
    if (DigitalnputOutput_DW.If_ActiveSubsystem != 1) {
      /* Enable for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* Enable for If: '<S4>/If' incorporates:
       *  Sin: '<S5>/Sine Wave'
       */
      DigitalnputOutput_DW.systemEnable = 1L;

      /* End of Enable for SubSystem: '<S3>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Sin: '<S5>/Sine Wave' */
    if (DigitalnputOutput_DW.systemEnable != 0L) {
      rtb_Merge4 = DigitalnputOutput_P.SineWave_Freq *
        ((DigitalnputOutput_M->Timing.clockTick1) * 0.1);
      DigitalnputOutput_DW.lastSin = sin(rtb_Merge4);
      DigitalnputOutput_DW.lastCos = cos(rtb_Merge4);
      DigitalnputOutput_DW.systemEnable = 0L;
    }

    rtb_Merge4 = ((DigitalnputOutput_DW.lastSin *
                   DigitalnputOutput_P.SineWave_PCos +
                   DigitalnputOutput_DW.lastCos *
                   DigitalnputOutput_P.SineWave_PSin) *
                  DigitalnputOutput_P.SineWave_HCos +
                  (DigitalnputOutput_DW.lastCos *
                   DigitalnputOutput_P.SineWave_PCos -
                   DigitalnputOutput_DW.lastSin *
                   DigitalnputOutput_P.SineWave_PSin) *
                  DigitalnputOutput_P.SineWave_Hsin) *
      DigitalnputOutput_P.SineWave_Amp + DigitalnputOutput_P.SineWave_Bias;

    /* End of Sin: '<S5>/Sine Wave' */

    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S7>/Constant'
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     *  RelationalOperator: '<S7>/Compare'
     */
    DigitalnputOutput_B.Merge = (rtb_Merge4 >=
      DigitalnputOutput_P.CompareToConstant_const);

    /* Merge: '<S3>/Merge4' incorporates:
     *  Constant: '<S8>/Constant'
     *  DataTypeConversion: '<S5>/Data Type Conversion3'
     *  RelationalOperator: '<S8>/Compare'
     */
    DigitalnputOutput_B.Merge4 = (rtb_Merge4 >=
      DigitalnputOutput_P.CompareToConstant1_const);

    /* Merge: '<S3>/Merge2' incorporates:
     *  Constant: '<S9>/Constant'
     *  DataTypeConversion: '<S5>/Data Type Conversion2'
     *  RelationalOperator: '<S9>/Compare'
     */
    DigitalnputOutput_B.Merge2 = (rtb_Merge4 >=
      DigitalnputOutput_P.CompareToConstant2_const);

    /* Merge: '<S3>/Merge3' incorporates:
     *  Constant: '<S10>/Constant'
     *  DataTypeConversion: '<S5>/Data Type Conversion4'
     *  RelationalOperator: '<S10>/Compare'
     */
    DigitalnputOutput_B.Merge3 = (rtb_Merge4 >=
      DigitalnputOutput_P.CompareToConstant3_const);

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S11>/Constant'
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  RelationalOperator: '<S11>/Compare'
     */
    DigitalnputOutput_B.Merge1 = (rtb_Merge4 >=
      DigitalnputOutput_P.CompareToConstant4_const);

    /* Update for Sin: '<S5>/Sine Wave' */
    rtb_Merge4 = DigitalnputOutput_DW.lastSin;
    DigitalnputOutput_DW.lastSin = DigitalnputOutput_DW.lastSin *
      DigitalnputOutput_P.SineWave_HCos + DigitalnputOutput_DW.lastCos *
      DigitalnputOutput_P.SineWave_Hsin;
    DigitalnputOutput_DW.lastCos = DigitalnputOutput_DW.lastCos *
      DigitalnputOutput_P.SineWave_HCos - rtb_Merge4 *
      DigitalnputOutput_P.SineWave_Hsin;
    srUpdateBC(DigitalnputOutput_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
  } else {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  SignalConversion generated from: '<S6>/Input3'
     */
    DigitalnputOutput_B.Merge = rtb_Merge4;

    /* Merge: '<S3>/Merge1' incorporates:
     *  SignalConversion generated from: '<S6>/Input4'
     */
    DigitalnputOutput_B.Merge1 = rtb_Merge2;

    /* Merge: '<S3>/Merge2' incorporates:
     *  SignalConversion generated from: '<S6>/Input5'
     */
    DigitalnputOutput_B.Merge2 = rtb_Merge;

    /* Merge: '<S3>/Merge3' incorporates:
     *  SignalConversion generated from: '<S6>/Input6'
     */
    DigitalnputOutput_B.Merge3 = rtb_Merge3;

    /* Merge: '<S3>/Merge4' incorporates:
     *  SignalConversion generated from: '<S6>/Input7'
     */
    DigitalnputOutput_B.Merge4 = rtb_Merge1;
    srUpdateBC(DigitalnputOutput_DW.IfActionSubsystem2_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
  }

  DigitalnputOutput_DW.If_ActiveSubsystem = rtAction;

  /* End of If: '<S4>/If' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_Merge4 = rt_roundd_snf(DigitalnputOutput_B.Merge1);
  if (rtb_Merge4 < 256.0) {
    if (rtb_Merge4 >= 0.0) {
      tmp = (uint8_T)rtb_Merge4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  rtb_Merge4 = rt_roundd_snf(DigitalnputOutput_B.Merge4);
  if (rtb_Merge4 < 256.0) {
    if (rtb_Merge4 >= 0.0) {
      tmp = (uint8_T)rtb_Merge4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(11, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  rtb_Merge4 = rt_roundd_snf(DigitalnputOutput_B.Merge2);
  if (rtb_Merge4 < 256.0) {
    if (rtb_Merge4 >= 0.0) {
      tmp = (uint8_T)rtb_Merge4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(9, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* MATLABSystem: '<Root>/Digital Output3' */
  rtb_Merge4 = rt_roundd_snf(DigitalnputOutput_B.Merge3);
  if (rtb_Merge4 < 256.0) {
    if (rtb_Merge4 >= 0.0) {
      tmp = (uint8_T)rtb_Merge4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(10, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output3' */

  /* MATLABSystem: '<Root>/Digital Output4' */
  rtb_Merge4 = rt_roundd_snf(DigitalnputOutput_B.Merge);
  if (rtb_Merge4 < 256.0) {
    if (rtb_Merge4 >= 0.0) {
      tmp = (uint8_T)rtb_Merge4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output4' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  DigitalnputOutput_M->Timing.clockTick1++;
}

/* Model initialize function */
void DigitalnputOutput_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(DigitalnputOutput_M, -1);
  DigitalnputOutput_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  DigitalnputOutput_M->Sizes.checksums[0] = (711162862U);
  DigitalnputOutput_M->Sizes.checksums[1] = (2572258447U);
  DigitalnputOutput_M->Sizes.checksums[2] = (617161953U);
  DigitalnputOutput_M->Sizes.checksums[3] = (2340457865U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[28];
    DigitalnputOutput_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &DigitalnputOutput_DW.EnabledSubsystem4.EnabledSubsystem4_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem8.IfActionSubsystem8_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem9.IfActionSubsystem8_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &DigitalnputOutput_DW.EnabledSubsystem.EnabledSubsystem4_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem.IfActionSubsystem8_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem1_j.IfActionSubsystem8_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &DigitalnputOutput_DW.EnabledSubsystem2.EnabledSubsystem4_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem4.IfActionSubsystem8_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem5.IfActionSubsystem8_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &DigitalnputOutput_DW.EnabledSubsystem3.EnabledSubsystem4_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem6.IfActionSubsystem8_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem7.IfActionSubsystem8_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &DigitalnputOutput_DW.EnabledSubsystem1.EnabledSubsystem4_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem2_e.IfActionSubsystem8_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &DigitalnputOutput_DW.IfActionSubsystem3.IfActionSubsystem8_SubsysRanBC;
    rteiSetModelMappingInfoPtr(DigitalnputOutput_M->extModeInfo,
      &DigitalnputOutput_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DigitalnputOutput_M->extModeInfo,
                        DigitalnputOutput_M->Sizes.checksums);
    rteiSetTPtr(DigitalnputOutput_M->extModeInfo, rtmGetTPtr(DigitalnputOutput_M));
  }

  /* Start for If: '<S4>/If' */
  DigitalnputOutput_DW.If_ActiveSubsystem = -1;

  /* SystemInitialize for Merge: '<S3>/Merge' */
  DigitalnputOutput_B.Merge = DigitalnputOutput_P.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S3>/Merge1' */
  DigitalnputOutput_B.Merge1 = DigitalnputOutput_P.Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S3>/Merge2' */
  DigitalnputOutput_B.Merge2 = DigitalnputOutput_P.Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S3>/Merge3' */
  DigitalnputOutput_B.Merge3 = DigitalnputOutput_P.Merge3_InitialOutput;

  /* SystemInitialize for Merge: '<S3>/Merge4' */
  DigitalnputOutput_B.Merge4 = DigitalnputOutput_P.Merge4_InitialOutput;

  /* SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem4' */
  Digi_EnabledSubsystem4_Init(&DigitalnputOutput_B.Add_l,
    &DigitalnputOutput_DW.EnabledSubsystem4,
    &DigitalnputOutput_P.EnabledSubsystem4);

  /* End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem4' */

  /* SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem2' */
  Digi_EnabledSubsystem4_Init(&DigitalnputOutput_B.Add_p,
    &DigitalnputOutput_DW.EnabledSubsystem2,
    &DigitalnputOutput_P.EnabledSubsystem2);

  /* End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem2' */

  /* SystemInitialize for Enabled SubSystem: '<S13>/Enabled Subsystem' */
  Digi_EnabledSubsystem4_Init(&DigitalnputOutput_B.Add_d,
    &DigitalnputOutput_DW.EnabledSubsystem,
    &DigitalnputOutput_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S13>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem3' */
  Digi_EnabledSubsystem4_Init(&DigitalnputOutput_B.Add_n,
    &DigitalnputOutput_DW.EnabledSubsystem3,
    &DigitalnputOutput_P.EnabledSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem3' */

  /* SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem1' */
  Digi_EnabledSubsystem4_Init(&DigitalnputOutput_B.Add,
    &DigitalnputOutput_DW.EnabledSubsystem1,
    &DigitalnputOutput_P.EnabledSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem1' */

  /* Start for MATLABSystem: '<Root>/Digital Input4' */
  DigitalnputOutput_DW.obj.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj.SampleTime =
    DigitalnputOutput_P.DigitalInput4_SampleTime;
  DigitalnputOutput_DW.obj.isInitialized = 1L;
  digitalIOSetup(2, 0);
  DigitalnputOutput_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input2' */
  DigitalnputOutput_DW.obj_i.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_i.SampleTime =
    DigitalnputOutput_P.DigitalInput2_SampleTime;
  DigitalnputOutput_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(3, 0);
  DigitalnputOutput_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  DigitalnputOutput_DW.obj_j.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_j.SampleTime =
    DigitalnputOutput_P.DigitalInput_SampleTime;
  DigitalnputOutput_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(4, 0);
  DigitalnputOutput_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input3' */
  DigitalnputOutput_DW.obj_e.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_e.SampleTime =
    DigitalnputOutput_P.DigitalInput3_SampleTime;
  DigitalnputOutput_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(5, 0);
  DigitalnputOutput_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  DigitalnputOutput_DW.obj_f.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_f.SampleTime =
    DigitalnputOutput_P.DigitalInput1_SampleTime;
  DigitalnputOutput_DW.obj_f.isInitialized = 1L;
  digitalIOSetup(6, 0);
  DigitalnputOutput_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  DigitalnputOutput_DW.obj_g.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(8, 1);
  DigitalnputOutput_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  DigitalnputOutput_DW.obj_h.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(11, 1);
  DigitalnputOutput_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  DigitalnputOutput_DW.obj_d.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(9, 1);
  DigitalnputOutput_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  DigitalnputOutput_DW.obj_c.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(10, 1);
  DigitalnputOutput_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  DigitalnputOutput_DW.obj_p.matlabCodegenIsDeleted = false;
  DigitalnputOutput_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(7, 1);
  DigitalnputOutput_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void DigitalnputOutput_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input4' */
  if (!DigitalnputOutput_DW.obj.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input2' */
  if (!DigitalnputOutput_DW.obj_i.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!DigitalnputOutput_DW.obj_j.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input3' */
  if (!DigitalnputOutput_DW.obj_e.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!DigitalnputOutput_DW.obj_f.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!DigitalnputOutput_DW.obj_g.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!DigitalnputOutput_DW.obj_h.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!DigitalnputOutput_DW.obj_d.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!DigitalnputOutput_DW.obj_c.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!DigitalnputOutput_DW.obj_p.matlabCodegenIsDeleted) {
    DigitalnputOutput_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
