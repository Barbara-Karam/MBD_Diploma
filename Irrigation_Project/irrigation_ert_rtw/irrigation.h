/*
 * File: irrigation.h
 *
 * Code generated for Simulink model 'irrigation'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar 14 19:05:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_irrigation_h_
#define RTW_HEADER_irrigation_h_
#ifndef irrigation_COMMON_INCLUDES_
#define irrigation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* irrigation_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  boolean_T Compare;                   /* '<S5>/Compare' */
  boolean_T Compare_k;                 /* '<S6>/Compare' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T waterpump;                 /* '<Root>/water pump' */
  real_T Out1;                         /* '<Root>/Out1' */
  boolean_T Out2;                      /* '<Root>/Out2' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void irrigation_initialize(void);
extern void irrigation_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'irrigation'
 * '<S1>'   : 'irrigation/Compare To Constant'
 * '<S2>'   : 'irrigation/Compare To Constant1'
 * '<S3>'   : 'irrigation/If Action Subsystem'
 * '<S4>'   : 'irrigation/If Action Subsystem1'
 * '<S5>'   : 'irrigation/If Action Subsystem/Compare To Constant'
 * '<S6>'   : 'irrigation/If Action Subsystem/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_irrigation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
