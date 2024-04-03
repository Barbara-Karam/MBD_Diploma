/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar  9 15:03:10 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "untitled_private.h"
#include <math.h>

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
void untitled_step(void)
{
  real_T rtb_PulseGenerator;
  real_T tmp;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (untitled_DW.clockTickCounter <
                        untitled_P.PulseGenerator_Duty) &&
    (untitled_DW.clockTickCounter >= 0L) ? untitled_P.PulseGenerator_Amp : 0.0;
  if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator_Period - 1.0) {
    untitled_DW.clockTickCounter = 0L;
  } else {
    untitled_DW.clockTickCounter++;
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

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<Root>/NOT'
   */
  writeDigitalPin(3, (uint8_T)!(rtb_PulseGenerator != 0.0));

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator = (untitled_DW.clockTickCounter_c <
                        untitled_P.PulseGenerator1_Duty) &&
    (untitled_DW.clockTickCounter_c >= 0L) ? untitled_P.PulseGenerator1_Amp :
    0.0;
  if (untitled_DW.clockTickCounter_c >= untitled_P.PulseGenerator1_Period - 1.0)
  {
    untitled_DW.clockTickCounter_c = 0L;
  } else {
    untitled_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* MATLABSystem: '<Root>/Digital Output2' */
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

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output2' */
  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2287320964U);
  untitled_M->Sizes.checksums[1] = (2703485521U);
  untitled_M->Sizes.checksums[2] = (4221778608U);
  untitled_M->Sizes.checksums[3] = (1828556901U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(2, 1);
  untitled_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  untitled_DW.obj_j.matlabCodegenIsDeleted = false;
  untitled_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(3, 1);
  untitled_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1L;
  digitalIOSetup(8, 1);
  untitled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!untitled_DW.obj_j.matlabCodegenIsDeleted) {
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
