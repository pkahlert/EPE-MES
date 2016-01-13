/*
 * Koordinatentransfer3.h
 *
 * Code generation for model "Koordinatentransfer3".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:08:48 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Koordinatentransfer3_h_
#define RTW_HEADER_Koordinatentransfer3_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Koordinatentransfer3_COMMON_INCLUDES_
# define Koordinatentransfer3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Koordinatentransfer3_COMMON_INCLUDES_ */

#include "Koordinatentransfer3_types.h"

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
  real_T alpha;                        /* '<Root>/alpha' */
  real_T beta;                         /* '<Root>/beta' */
} ExtU_Koordinatentransfer3_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T a;                            /* '<Root>/a' */
  real_T b;                            /* '<Root>/b' */
  real_T c;                            /* '<Root>/c' */
} ExtY_Koordinatentransfer3_T;

/* Parameters (auto storage) */
struct P_Koordinatentransfer3_T_ {
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Koordinatentransfer3_T {
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
extern P_Koordinatentransfer3_T Koordinatentransfer3_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Koordinatentransfer3_T Koordinatentransfer3_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Koordinatentransfer3_T Koordinatentransfer3_Y;

/* Model entry point functions */
extern void Koordinatentransfer3_initialize(void);
extern void Koordinatentransfer3_step(void);
extern void Koordinatentransfer3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Koordinatentransfer3_T *const Koordinatentransfer3_M;

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
 * hilite_system('ASM/Koordinatentransfer3')    - opens subsystem ASM/Koordinatentransfer3
 * hilite_system('ASM/Koordinatentransfer3/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ASM'
 * '<S1>'   : 'ASM/Koordinatentransfer3'
 */
#endif                                 /* RTW_HEADER_Koordinatentransfer3_h_ */
