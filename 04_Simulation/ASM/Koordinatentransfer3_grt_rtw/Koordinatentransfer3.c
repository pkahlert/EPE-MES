/*
 * Koordinatentransfer3.c
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
#include "Koordinatentransfer3.h"
#include "Koordinatentransfer3_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Koordinatentransfer3_T Koordinatentransfer3_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Koordinatentransfer3_T Koordinatentransfer3_Y;

/* Real-time model */
RT_MODEL_Koordinatentransfer3_T Koordinatentransfer3_M_;
RT_MODEL_Koordinatentransfer3_T *const Koordinatentransfer3_M =
  &Koordinatentransfer3_M_;

/* Model step function */
void Koordinatentransfer3_step(void)
{
  real_T rtb_Gain;
  real_T rtb_Gain1;

  /* Outport: '<Root>/a' incorporates:
   *  Inport: '<Root>/alpha'
   */
  Koordinatentransfer3_Y.a = Koordinatentransfer3_U.alpha;

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/alpha'
   */
  rtb_Gain = Koordinatentransfer3_P.Gain_Gain * Koordinatentransfer3_U.alpha;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Inport: '<Root>/beta'
   */
  rtb_Gain1 = Koordinatentransfer3_P.Gain1_Gain * Koordinatentransfer3_U.beta;

  /* Outport: '<Root>/b' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  Koordinatentransfer3_Y.b = rtb_Gain1 - rtb_Gain;

  /* Outport: '<Root>/c' incorporates:
   *  Sum: '<S1>/Sum'
   */
  Koordinatentransfer3_Y.c = (0.0 - rtb_Gain) - rtb_Gain1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Koordinatentransfer3_M->rtwLogInfo,
                      (&Koordinatentransfer3_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(Koordinatentransfer3_M)!=-1) &&
        !((rtmGetTFinal(Koordinatentransfer3_M)-
           Koordinatentransfer3_M->Timing.taskTime0) >
          Koordinatentransfer3_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Koordinatentransfer3_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Koordinatentransfer3_M->Timing.clockTick0)) {
    ++Koordinatentransfer3_M->Timing.clockTickH0;
  }

  Koordinatentransfer3_M->Timing.taskTime0 =
    Koordinatentransfer3_M->Timing.clockTick0 *
    Koordinatentransfer3_M->Timing.stepSize0 +
    Koordinatentransfer3_M->Timing.clockTickH0 *
    Koordinatentransfer3_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Koordinatentransfer3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Koordinatentransfer3_M, 0,
                sizeof(RT_MODEL_Koordinatentransfer3_T));
  rtmSetTFinal(Koordinatentransfer3_M, 0.1);
  Koordinatentransfer3_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Koordinatentransfer3_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Koordinatentransfer3_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Koordinatentransfer3_M->rtwLogInfo, (NULL));
    rtliSetLogT(Koordinatentransfer3_M->rtwLogInfo, "tout");
    rtliSetLogX(Koordinatentransfer3_M->rtwLogInfo, "");
    rtliSetLogXFinal(Koordinatentransfer3_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Koordinatentransfer3_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Koordinatentransfer3_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Koordinatentransfer3_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Koordinatentransfer3_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Koordinatentransfer3_Y.a,
        &Koordinatentransfer3_Y.b,
        &Koordinatentransfer3_Y.c
      };

      rtliSetLogYSignalPtrs(Koordinatentransfer3_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        2,
        2,
        2
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Koordinatentransfer3/a",
        "Koordinatentransfer3/b",
        "Koordinatentransfer3/c" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Koordinatentransfer3_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(Koordinatentransfer3_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset((void *)&Koordinatentransfer3_U, 0,
                sizeof(ExtU_Koordinatentransfer3_T));

  /* external outputs */
  (void) memset((void *)&Koordinatentransfer3_Y, 0,
                sizeof(ExtY_Koordinatentransfer3_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Koordinatentransfer3_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Koordinatentransfer3_M),
    Koordinatentransfer3_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Koordinatentransfer3_M)));
}

/* Model terminate function */
void Koordinatentransfer3_terminate(void)
{
  /* (no terminate code required) */
}
