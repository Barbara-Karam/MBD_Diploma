/*
 * File: ultrasonic_types.h
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

#ifndef RTW_HEADER_ultrasonic_types_h_
#define RTW_HEADER_ultrasonic_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_jShWpKUOycwBMhFyiKcKhC
#define struct_tag_jShWpKUOycwBMhFyiKcKhC

struct tag_jShWpKUOycwBMhFyiKcKhC
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
};

#endif                                 /* struct_tag_jShWpKUOycwBMhFyiKcKhC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_jShWpKUOycwBMhFyiKcKhC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_ultrasonic_T_ P_ultrasonic_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ultrasonic_T RT_MODEL_ultrasonic_T;

#endif                                 /* RTW_HEADER_ultrasonic_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
