/*
 * File: DigitalnputOutput.h
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

#ifndef RTW_HEADER_DigitalnputOutput_h_
#define RTW_HEADER_DigitalnputOutput_h_
#ifndef DigitalnputOutput_COMMON_INCLUDES_
#define DigitalnputOutput_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* DigitalnputOutput_COMMON_INCLUDES_ */

#include "DigitalnputOutput_types.h"
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

/* Block states (default storage) for system '<S12>/Enabled Subsystem4' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S17>/Unit Delay' */
  int8_T EnabledSubsystem4_SubsysRanBC;/* '<S12>/Enabled Subsystem4' */
  boolean_T EnabledSubsystem4_MODE;    /* '<S12>/Enabled Subsystem4' */
} DW_EnabledSubsystem4_Digitaln_T;

/* Block states (default storage) for system '<S12>/If Action Subsystem8' */
typedef struct {
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S12>/If Action Subsystem8' */
} DW_IfActionSubsystem8_Digital_T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge1;                       /* '<S3>/Merge1' */
  real_T Merge4;                       /* '<S3>/Merge4' */
  real_T Merge2;                       /* '<S3>/Merge2' */
  real_T Merge3;                       /* '<S3>/Merge3' */
  real_T Merge;                        /* '<S3>/Merge' */
  real_T Add;                          /* '<S29>/Add' */
  real_T Add_n;                        /* '<S26>/Add' */
  real_T Add_p;                        /* '<S23>/Add' */
  real_T Add_d;                        /* '<S20>/Add' */
  real_T Add_l;                        /* '<S17>/Add' */
} B_DigitalnputOutput_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input4' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Input3' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_block_T obj_f;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_o_T obj_p;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_blo_o_T obj_c;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_blo_o_T obj_d;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_blo_o_T obj_h;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_o_T obj_g;/* '<Root>/Digital Output' */
  real_T lastSin;                      /* '<S5>/Sine Wave' */
  real_T lastCos;                      /* '<S5>/Sine Wave' */
  int32_T systemEnable;                /* '<S5>/Sine Wave' */
  int8_T If_ActiveSubsystem;           /* '<S4>/If' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S3>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S3>/If Action Subsystem1' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem3;/* '<S16>/If Action Subsystem3' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem2_e;/* '<S16>/If Action Subsystem2' */
  DW_EnabledSubsystem4_Digitaln_T EnabledSubsystem1;/* '<S16>/Enabled Subsystem1' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem7;/* '<S15>/If Action Subsystem7' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem6;/* '<S15>/If Action Subsystem6' */
  DW_EnabledSubsystem4_Digitaln_T EnabledSubsystem3;/* '<S15>/Enabled Subsystem3' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem5;/* '<S14>/If Action Subsystem5' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem4;/* '<S14>/If Action Subsystem4' */
  DW_EnabledSubsystem4_Digitaln_T EnabledSubsystem2;/* '<S14>/Enabled Subsystem2' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem1_j;/* '<S13>/If Action Subsystem1' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem;/* '<S13>/If Action Subsystem' */
  DW_EnabledSubsystem4_Digitaln_T EnabledSubsystem;/* '<S13>/Enabled Subsystem' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem9;/* '<S12>/If Action Subsystem9' */
  DW_IfActionSubsystem8_Digital_T IfActionSubsystem8;/* '<S12>/If Action Subsystem8' */
  DW_EnabledSubsystem4_Digitaln_T EnabledSubsystem4;/* '<S12>/Enabled Subsystem4' */
} DW_DigitalnputOutput_T;

/* Parameters for system: '<S12>/Enabled Subsystem4' */
struct P_EnabledSubsystem4_Digitalnp_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S17>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
};

/* Parameters for system: '<S12>/If Action Subsystem8' */
struct P_IfActionSubsystem8_Digitaln_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_DigitalnputOutput_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S8>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S9>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S10>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S11>/Constant'
                                      */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input2'
                                        */
  real_T DigitalInput3_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input3'
                                        */
  real_T DigitalInput4_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input4'
                                        */
  real_T SineWave_Amp;                 /* Expression: 5
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 0.01
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<S5>/Sine Wave'
                                        */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S3>/Merge1'
                                      */
  real_T Merge4_InitialOutput;       /* Computed Parameter: Merge4_InitialOutput
                                      * Referenced by: '<S3>/Merge4'
                                      */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S3>/Merge2'
                                      */
  real_T Merge3_InitialOutput;       /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S3>/Merge3'
                                      */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S3>/Merge'
                                       */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem3;/* '<S16>/If Action Subsystem3' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem2_e;/* '<S16>/If Action Subsystem2' */
  P_EnabledSubsystem4_Digitalnp_T EnabledSubsystem1;/* '<S16>/Enabled Subsystem1' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem7;/* '<S15>/If Action Subsystem7' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem6;/* '<S15>/If Action Subsystem6' */
  P_EnabledSubsystem4_Digitalnp_T EnabledSubsystem3;/* '<S15>/Enabled Subsystem3' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem5;/* '<S14>/If Action Subsystem5' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem4;/* '<S14>/If Action Subsystem4' */
  P_EnabledSubsystem4_Digitalnp_T EnabledSubsystem2;/* '<S14>/Enabled Subsystem2' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem1_j;/* '<S13>/If Action Subsystem1' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem;/* '<S13>/If Action Subsystem' */
  P_EnabledSubsystem4_Digitalnp_T EnabledSubsystem;/* '<S13>/Enabled Subsystem' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem9;/* '<S12>/If Action Subsystem9' */
  P_IfActionSubsystem8_Digitaln_T IfActionSubsystem8;/* '<S12>/If Action Subsystem8' */
  P_EnabledSubsystem4_Digitalnp_T EnabledSubsystem4;/* '<S12>/Enabled Subsystem4' */
};

/* Real-time Model Data Structure */
struct tag_RTM_DigitalnputOutput_T {
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

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_DigitalnputOutput_T DigitalnputOutput_P;

/* Block signals (default storage) */
extern B_DigitalnputOutput_T DigitalnputOutput_B;

/* Block states (default storage) */
extern DW_DigitalnputOutput_T DigitalnputOutput_DW;

/* External function called from main */
extern void DigitalnputOutput_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void DigitalnputOutput_initialize(void);
extern void DigitalnputOutput_step0(void);
extern void DigitalnputOutput_step1(void);
extern void DigitalnputOutput_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DigitalnputOutput_T *const DigitalnputOutput_M;
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
 * '<Root>' : 'DigitalnputOutput'
 * '<S1>'   : 'DigitalnputOutput/animations'
 * '<S2>'   : 'DigitalnputOutput/debouncers'
 * '<S3>'   : 'DigitalnputOutput/animations/Subsystem'
 * '<S4>'   : 'DigitalnputOutput/animations/special cases comparator'
 * '<S5>'   : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem1'
 * '<S6>'   : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem2'
 * '<S7>'   : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem1/Compare To Constant'
 * '<S8>'   : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem1/Compare To Constant1'
 * '<S9>'   : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem1/Compare To Constant2'
 * '<S10>'  : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem1/Compare To Constant3'
 * '<S11>'  : 'DigitalnputOutput/animations/Subsystem/If Action Subsystem1/Compare To Constant4'
 * '<S12>'  : 'DigitalnputOutput/debouncers/Subsystem'
 * '<S13>'  : 'DigitalnputOutput/debouncers/Subsystem1'
 * '<S14>'  : 'DigitalnputOutput/debouncers/Subsystem2'
 * '<S15>'  : 'DigitalnputOutput/debouncers/Subsystem3'
 * '<S16>'  : 'DigitalnputOutput/debouncers/Subsystem6'
 * '<S17>'  : 'DigitalnputOutput/debouncers/Subsystem/Enabled Subsystem4'
 * '<S18>'  : 'DigitalnputOutput/debouncers/Subsystem/If Action Subsystem8'
 * '<S19>'  : 'DigitalnputOutput/debouncers/Subsystem/If Action Subsystem9'
 * '<S20>'  : 'DigitalnputOutput/debouncers/Subsystem1/Enabled Subsystem'
 * '<S21>'  : 'DigitalnputOutput/debouncers/Subsystem1/If Action Subsystem'
 * '<S22>'  : 'DigitalnputOutput/debouncers/Subsystem1/If Action Subsystem1'
 * '<S23>'  : 'DigitalnputOutput/debouncers/Subsystem2/Enabled Subsystem2'
 * '<S24>'  : 'DigitalnputOutput/debouncers/Subsystem2/If Action Subsystem4'
 * '<S25>'  : 'DigitalnputOutput/debouncers/Subsystem2/If Action Subsystem5'
 * '<S26>'  : 'DigitalnputOutput/debouncers/Subsystem3/Enabled Subsystem3'
 * '<S27>'  : 'DigitalnputOutput/debouncers/Subsystem3/If Action Subsystem6'
 * '<S28>'  : 'DigitalnputOutput/debouncers/Subsystem3/If Action Subsystem7'
 * '<S29>'  : 'DigitalnputOutput/debouncers/Subsystem6/Enabled Subsystem1'
 * '<S30>'  : 'DigitalnputOutput/debouncers/Subsystem6/If Action Subsystem2'
 * '<S31>'  : 'DigitalnputOutput/debouncers/Subsystem6/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_DigitalnputOutput_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
