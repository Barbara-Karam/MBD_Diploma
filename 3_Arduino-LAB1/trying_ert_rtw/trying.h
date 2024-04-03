/*
 * File: trying.h
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

#ifndef RTW_HEADER_trying_h_
#define RTW_HEADER_trying_h_
#ifndef trying_COMMON_INCLUDES_
#define trying_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* trying_COMMON_INCLUDES_ */

#include "trying_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T TmpRTBAtANDInport2;        /* '<Root>/Digital Input' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
} B_trying_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_g_T obj_p;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_blo_g_T obj_o;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_g_T obj_b;/* '<Root>/Digital Output' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<Root>/Pulse Generator1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<Root>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  boolean_T TmpRTBAtANDInport2_Buffer0;/* synthesized block */
} DW_trying_T;

/* Parameters (default storage) */
struct P_trying_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<Root>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<Root>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  boolean_T TmpRTBAtANDInport2_InitialCondi;
                          /* Computed Parameter: TmpRTBAtANDInport2_InitialCondi
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_trying_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_trying_T trying_P;

/* Block signals (default storage) */
extern B_trying_T trying_B;

/* Block states (default storage) */
extern DW_trying_T trying_DW;

/* External function called from main */
extern void trying_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void trying_initialize(void);
extern void trying_step0(void);
extern void trying_step1(void);
extern void trying_terminate(void);

/* Real-time Model object */
extern RT_MODEL_trying_T *const trying_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'trying'
 * '<S1>'   : 'trying/If Action Subsystem'
 * '<S2>'   : 'trying/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_trying_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
