/*
 * File: RC.c
 *
 * Code generated for Simulink model 'RC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar 30 04:34:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RC.h"
#include "RC_types.h"
#include "rtwtypes.h"
#include "RC_private.h"

/* Block signals (default storage) */
B_RC_T RC_B;

/* Block states (default storage) */
DW_RC_T RC_DW;

/* Real-time model */
static RT_MODEL_RC_T RC_M_;
RT_MODEL_RC_T *const RC_M = &RC_M_;

/* Model step function */
void RC_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_f_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (RC_DW.obj.SampleTime != RC_P.AnalogInput_SampleTime) {
    RC_DW.obj.SampleTime = RC_P.AnalogInput_SampleTime;
  }

  obj = &RC_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult(RC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, datatype_id);

  /* Gain: '<Root>/Gain2' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   */
  RC_B.systemresponse = (uint32_T)RC_P.Gain2_Gain * b_varargout_1;

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &RC_DW.obj_i;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (RC_P.ManualSwitch_CurrentSetting == 1) {
    /* Step: '<Root>/Step' */
    if (RC_M->Timing.t[0] < RC_P.Step_Time) {
      u0 = RC_P.Step_Y0;
    } else {
      u0 = RC_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */
  } else {
    u0 = RC_P.Constant_Value;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<Root>/Gain1'
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  u0 = RC_P.Gain1_Gain * u0 * RC_P.Gain_Gain;

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(RC_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((RC_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((RC_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  RC_M->Timing.t[0] =
    ((time_T)(++RC_M->Timing.clockTick0)) * RC_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    RC_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void RC_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RC_M->solverInfo, &RC_M->Timing.simTimeStep);
    rtsiSetTPtr(&RC_M->solverInfo, &rtmGetTPtr(RC_M));
    rtsiSetStepSizePtr(&RC_M->solverInfo, &RC_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&RC_M->solverInfo, (&rtmGetErrorStatus(RC_M)));
    rtsiSetRTModelPtr(&RC_M->solverInfo, RC_M);
  }

  rtsiSetSimTimeStep(&RC_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&RC_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(RC_M, &RC_M->Timing.tArray[0]);
  rtmSetTFinal(RC_M, 20.0);
  RC_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  RC_M->Sizes.checksums[0] = (750223283U);
  RC_M->Sizes.checksums[1] = (3650725391U);
  RC_M->Sizes.checksums[2] = (3087678238U);
  RC_M->Sizes.checksums[3] = (3926485698U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    RC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RC_M->extModeInfo, &RC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RC_M->extModeInfo, RC_M->Sizes.checksums);
    rteiSetTPtr(RC_M->extModeInfo, rtmGetTPtr(RC_M));
  }

  {
    codertarget_arduinobase_int_f_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    RC_DW.obj.matlabCodegenIsDeleted = false;
    RC_DW.obj.SampleTime = RC_P.AnalogInput_SampleTime;
    obj = &RC_DW.obj;
    RC_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    RC_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    RC_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &RC_DW.obj_i;
    RC_DW.obj_i.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
    RC_DW.obj_i.isSetupComplete = true;
  }
}

/* Model terminate function */
void RC_terminate(void)
{
  codertarget_arduinobase_int_f_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &RC_DW.obj;
  if (!RC_DW.obj.matlabCodegenIsDeleted) {
    RC_DW.obj.matlabCodegenIsDeleted = true;
    if ((RC_DW.obj.isInitialized == 1L) && RC_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close(RC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &RC_DW.obj_i;
  if (!RC_DW.obj_i.matlabCodegenIsDeleted) {
    RC_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((RC_DW.obj_i.isInitialized == 1L) && RC_DW.obj_i.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(RC_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(RC_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
