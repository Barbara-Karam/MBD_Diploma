/*
 * File: DigitalnputOutput_data.c
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

/* Block parameters (default storage) */
P_DigitalnputOutput_T DigitalnputOutput_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S8>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S9>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S10>/Constant'
   */
  4.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S11>/Constant'
   */
  5.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input2'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input3'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input4'
   */
  0.1,

  /* Expression: 5
   * Referenced by: '<S5>/Sine Wave'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S5>/Sine Wave'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S5>/Sine Wave'
   */
  0.01,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<S5>/Sine Wave'
   */
  0.00099999983333334168,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<S5>/Sine Wave'
   */
  0.99999950000004167,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<S5>/Sine Wave'
   */
  -0.00099999983333334168,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<S5>/Sine Wave'
   */
  0.99999950000004167,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S3>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge4_InitialOutput
   * Referenced by: '<S3>/Merge4'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S3>/Merge2'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput
   * Referenced by: '<S3>/Merge3'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S3>/Merge'
   */
  0.0,

  /* Start of '<S16>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S31>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S16>/If Action Subsystem3' */

  /* Start of '<S16>/If Action Subsystem2' */
  {
    /* Expression: 1
     * Referenced by: '<S30>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S16>/If Action Subsystem2' */

  /* Start of '<S16>/Enabled Subsystem1' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S29>/Out1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S29>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S29>/Unit Delay'
     */
    0.0
  }
  ,

  /* End of '<S16>/Enabled Subsystem1' */

  /* Start of '<S15>/If Action Subsystem7' */
  {
    /* Expression: 0
     * Referenced by: '<S28>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S15>/If Action Subsystem7' */

  /* Start of '<S15>/If Action Subsystem6' */
  {
    /* Expression: 1
     * Referenced by: '<S27>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S15>/If Action Subsystem6' */

  /* Start of '<S15>/Enabled Subsystem3' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S26>/Out1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S26>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S26>/Unit Delay'
     */
    0.0
  }
  ,

  /* End of '<S15>/Enabled Subsystem3' */

  /* Start of '<S14>/If Action Subsystem5' */
  {
    /* Expression: 0
     * Referenced by: '<S25>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S14>/If Action Subsystem5' */

  /* Start of '<S14>/If Action Subsystem4' */
  {
    /* Expression: 1
     * Referenced by: '<S24>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S14>/If Action Subsystem4' */

  /* Start of '<S14>/Enabled Subsystem2' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S23>/Out1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S23>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S23>/Unit Delay'
     */
    0.0
  }
  ,

  /* End of '<S14>/Enabled Subsystem2' */

  /* Start of '<S13>/If Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S22>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S13>/If Action Subsystem1' */

  /* Start of '<S13>/If Action Subsystem' */
  {
    /* Expression: 1
     * Referenced by: '<S21>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S13>/If Action Subsystem' */

  /* Start of '<S13>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S20>/Out1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S20>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S20>/Unit Delay'
     */
    0.0
  }
  ,

  /* End of '<S13>/Enabled Subsystem' */

  /* Start of '<S12>/If Action Subsystem9' */
  {
    /* Expression: 0
     * Referenced by: '<S19>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S12>/If Action Subsystem9' */

  /* Start of '<S12>/If Action Subsystem8' */
  {
    /* Expression: 1
     * Referenced by: '<S18>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S12>/If Action Subsystem8' */

  /* Start of '<S12>/Enabled Subsystem4' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S17>/Out1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S17>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S17>/Unit Delay'
     */
    0.0
  }
  /* End of '<S12>/Enabled Subsystem4' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
