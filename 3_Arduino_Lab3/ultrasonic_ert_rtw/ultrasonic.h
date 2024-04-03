/*
 * File: ultrasonic.h
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

#ifndef RTW_HEADER_ultrasonic_h_
#define RTW_HEADER_ultrasonic_h_
#ifndef ultrasonic_COMMON_INCLUDES_
#define ultrasonic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_Ultrasonic.h"
#endif                                 /* ultrasonic_COMMON_INCLUDES_ */

#include "ultrasonic_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S4>/Digital Output' */
  codertarget_arduinobase_block_T obj_l;/* '<S3>/Digital Output' */
  codertarget_arduinobase_block_T obj_lm;/* '<S2>/Digital Output' */
  codertarget_arduinobase_block_T obj_d;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_i;/* '<Root>/Ultrasonic Sensor' */
} DW_ultrasonic_T;

/* Parameters (default storage) */
struct P_ultrasonic_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_ff;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ultrasonic_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ultrasonic_T ultrasonic_P;

/* Block states (default storage) */
extern DW_ultrasonic_T ultrasonic_DW;

/* External function called from main */
extern void ultrasonic_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ultrasonic_initialize(void);
extern void ultrasonic_step0(void);
extern void ultrasonic_step1(void);
extern void ultrasonic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ultrasonic_T *const ultrasonic_M;
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
 * '<Root>' : 'ultrasonic'
 * '<S1>'   : 'ultrasonic/If Action Subsystem'
 * '<S2>'   : 'ultrasonic/If Action Subsystem1'
 * '<S3>'   : 'ultrasonic/If Action Subsystem2'
 * '<S4>'   : 'ultrasonic/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_ultrasonic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
