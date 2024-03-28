/*
 * File: DigitalnputOutput_private.h
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

#ifndef RTW_HEADER_DigitalnputOutput_private_h_
#define RTW_HEADER_DigitalnputOutput_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "DigitalnputOutput.h"
#include "DigitalnputOutput_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void Digi_EnabledSubsystem4_Init(real_T *rty_Out1,
  DW_EnabledSubsystem4_Digitaln_T *localDW, P_EnabledSubsystem4_Digitalnp_T
  *localP);
extern void Dig_EnabledSubsystem4_Reset(DW_EnabledSubsystem4_Digitaln_T *localDW,
  P_EnabledSubsystem4_Digitalnp_T *localP);
extern void D_EnabledSubsystem4_Disable(DW_EnabledSubsystem4_Digitaln_T *localDW);
extern void Digitalnp_EnabledSubsystem4(boolean_T rtu_Enable, real_T *rty_Out1,
  DW_EnabledSubsystem4_Digitaln_T *localDW, P_EnabledSubsystem4_Digitalnp_T
  *localP);
extern void Digitaln_IfActionSubsystem8(real_T *rty_Out1,
  P_IfActionSubsystem8_Digitaln_T *localP);

#endif                             /* RTW_HEADER_DigitalnputOutput_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
