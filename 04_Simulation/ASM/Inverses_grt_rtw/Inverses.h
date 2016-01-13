/*
 * Inverses.h
 *
 * Code generation for model "Inverses".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:06:29 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Inverses_h_
#define RTW_HEADER_Inverses_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Inverses_COMMON_INCLUDES_
# define Inverses_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Inverses_COMMON_INCLUDES_ */

#include "Inverses_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Psi;                          /* '<Root>/Psi' */
  real_T Isl;                          /* '<Root>/Isl' */
  real_T Ism;                          /* '<Root>/Ism' */
  real_T wS;                           /* '<Root>/wS' */
} ExtU_Inverses_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Usm;                          /* '<Root>/Usm' */
  real_T Usl;                          /* '<Root>/Usl' */
} ExtY_Inverses_T;

/* Parameters (auto storage) */
struct P_Inverses_T_ {
  real_T Lsigmam_Gain;                 /* Expression: 10e-3
                                        * Referenced by: '<S1>/Lsigmam'
                                        */
  real_T Rsl_Gain;                     /* Expression: 1
                                        * Referenced by: '<S1>/Rsl'
                                        */
  real_T Rsm_Gain;                     /* Expression: 1
                                        * Referenced by: '<S1>/Rsm'
                                        */
  real_T Lsigmal_Gain;                 /* Expression: 10e-3
                                        * Referenced by: '<S1>/Lsigmal'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Inverses_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Inverses_T Inverses_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Inverses_T Inverses_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Inverses_T Inverses_Y;

/* Model entry point functions */
extern void Inverses_initialize(void);
extern void Inverses_step(void);
extern void Inverses_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Inverses_T *const Inverses_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ASM/Inverses Spannungsmodel ')    - opens subsystem ASM/Inverses Spannungsmodel
 * hilite_system('ASM/Inverses Spannungsmodel /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ASM'
 * '<S1>'   : 'ASM/Inverses Spannungsmodel '
 */
#endif                                 /* RTW_HEADER_Inverses_h_ */
