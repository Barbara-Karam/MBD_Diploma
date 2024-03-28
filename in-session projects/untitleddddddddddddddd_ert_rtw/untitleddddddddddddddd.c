/*
 * File: untitleddddddddddddddd.c
 *
 * Code generated for Simulink model 'untitleddddddddddddddd'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar  9 00:28:24 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitleddddddddddddddd.h"
#include "rtwtypes.h"
#include "untitleddddddddddddddd_private.h"
#include <math.h>

/* Block states (default storage) */
DW_untitleddddddddddddddd_T untitleddddddddddddddd_DW;

/* Real-time model */
static RT_MODEL_untitleddddddddddddd_T untitleddddddddddddddd_M_;
RT_MODEL_untitleddddddddddddd_T *const untitleddddddddddddddd_M =
  &untitleddddddddddddddd_M_;
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

/* Model step function */
void untitleddddddddddddddd_step(void)
{
  real_T rtb_PulseGenerator;
  real_T tmp;
  int_T idxDelay;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  tmp = rt_roundd_snf(untitleddddddddddddddd_DW.Delay_DSTATE[0]);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(3, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (untitleddddddddddddddd_DW.clockTickCounter <
                        untitleddddddddddddddd_P.PulseGenerator_Duty) &&
    (untitleddddddddddddddd_DW.clockTickCounter >= 0L) ?
    untitleddddddddddddddd_P.PulseGenerator_Amp : 0.0;
  if (untitleddddddddddddddd_DW.clockTickCounter >=
      untitleddddddddddddddd_P.PulseGenerator_Period - 1.0) {
    untitleddddddddddddddd_DW.clockTickCounter = 0L;
  } else {
    untitleddddddddddddddd_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(rtb_PulseGenerator);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* Update for Delay: '<Root>/Delay' */
  for (idxDelay = 0; idxDelay < 199; idxDelay++) {
    untitleddddddddddddddd_DW.Delay_DSTATE[idxDelay] =
      untitleddddddddddddddd_DW.Delay_DSTATE[idxDelay + 1];
  }

  untitleddddddddddddddd_DW.Delay_DSTATE[199] = rtb_PulseGenerator;

  /* End of Update for Delay: '<Root>/Delay' */
  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitleddddddddddddddd_M->Timing.taskTime0 =
    ((time_T)(++untitleddddddddddddddd_M->Timing.clockTick0)) *
    untitleddddddddddddddd_M->Timing.stepSize0;
}

/* Model initialize function */
void untitleddddddddddddddd_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitleddddddddddddddd_M, -1);
  untitleddddddddddddddd_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitleddddddddddddddd_M->Sizes.checksums[0] = (2199038672U);
  untitleddddddddddddddd_M->Sizes.checksums[1] = (1938382113U);
  untitleddddddddddddddd_M->Sizes.checksums[2] = (491715254U);
  untitleddddddddddddddd_M->Sizes.checksums[3] = (1905360942U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitleddddddddddddddd_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitleddddddddddddddd_M->extModeInfo,
      &untitleddddddddddddddd_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitleddddddddddddddd_M->extModeInfo,
                        untitleddddddddddddddd_M->Sizes.checksums);
    rteiSetTPtr(untitleddddddddddddddd_M->extModeInfo, rtmGetTPtr
                (untitleddddddddddddddd_M));
  }

  {
    int16_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 200; i++) {
      untitleddddddddddddddd_DW.Delay_DSTATE[i] =
        untitleddddddddddddddd_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay' */

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    untitleddddddddddddddd_DW.obj.matlabCodegenIsDeleted = false;
    untitleddddddddddddddd_DW.obj.isInitialized = 1L;
    digitalIOSetup(3, 1);
    untitleddddddddddddddd_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    untitleddddddddddddddd_DW.obj_h.matlabCodegenIsDeleted = false;
    untitleddddddddddddddd_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(2, 1);
    untitleddddddddddddddd_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitleddddddddddddddd_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!untitleddddddddddddddd_DW.obj.matlabCodegenIsDeleted) {
    untitleddddddddddddddd_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitleddddddddddddddd_DW.obj_h.matlabCodegenIsDeleted) {
    untitleddddddddddddddd_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
