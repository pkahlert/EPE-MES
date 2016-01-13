/*
 * Koordinatentransfer1.c
 *
 * Code generation for model "Koordinatentransfer1".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:09:38 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Koordinatentransfer1.h"
#include "Koordinatentransfer1_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Koordinatentransfer1_T Koordinatentransfer1_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Koordinatentransfer1_T Koordinatentransfer1_Y;

/* Real-time model */
RT_MODEL_Koordinatentransfer1_T Koordinatentransfer1_M_;
RT_MODEL_Koordinatentransfer1_T *const Koordinatentransfer1_M =
  &Koordinatentransfer1_M_;

/* Model step function */
void Koordinatentransfer1_step(void)
{
  /* Outport: '<Root>/out1' incorporates:
   *  Inport: '<Root>/cos'
   *  Inport: '<Root>/in1'
   *  Inport: '<Root>/in2'
   *  Inport: '<Root>/sin'
   *  Product: '<S1>/in1*cos'
   *  Product: '<S1>/in2*sin'
   *  Sum: '<S1>/Sum'
   */
  Koordinatentransfer1_Y.out1 = Koordinatentransfer1_U.in1 *
    Koordinatentransfer1_U.cos_i - Koordinatentransfer1_U.in2 *
    Koordinatentransfer1_U.sin_l;

  /* Outport: '<Root>/out2' incorporates:
   *  Inport: '<Root>/cos'
   *  Inport: '<Root>/in1'
   *  Inport: '<Root>/in2'
   *  Inport: '<Root>/sin'
   *  Product: '<S1>/in1*sin'
   *  Product: '<S1>/in2*cos'
   *  Sum: '<S1>/Sum1'
   */
  Koordinatentransfer1_Y.out2 = Koordinatentransfer1_U.in2 *
    Koordinatentransfer1_U.cos_i + Koordinatentransfer1_U.in1 *
    Koordinatentransfer1_U.sin_l;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Koordinatentransfer1_M->rtwLogInfo,
                      (&Koordinatentransfer1_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(Koordinatentransfer1_M)!=-1) &&
        !((rtmGetTFinal(Koordinatentransfer1_M)-
           Koordinatentransfer1_M->Timing.taskTime0) >
          Koordinatentransfer1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Koordinatentransfer1_M, "Simulation finished");
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
  if (!(++Koordinatentransfer1_M->Timing.clockTick0)) {
    ++Koordinatentransfer1_M->Timing.clockTickH0;
  }

  Koordinatentransfer1_M->Timing.taskTime0 =
    Koordinatentransfer1_M->Timing.clockTick0 *
    Koordinatentransfer1_M->Timing.stepSize0 +
    Koordinatentransfer1_M->Timing.clockTickH0 *
    Koordinatentransfer1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Koordinatentransfer1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Koordinatentransfer1_M, 0,
                sizeof(RT_MODEL_Koordinatentransfer1_T));
  rtmSetTFinal(Koordinatentransfer1_M, 0.1);
  Koordinatentransfer1_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Koordinatentransfer1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Koordinatentransfer1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Koordinatentransfer1_M->rtwLogInfo, (NULL));
    rtliSetLogT(Koordinatentransfer1_M->rtwLogInfo, "tout");
    rtliSetLogX(Koordinatentransfer1_M->rtwLogInfo, "");
    rtliSetLogXFinal(Koordinatentransfer1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Koordinatentransfer1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Koordinatentransfer1_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Koordinatentransfer1_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Koordinatentransfer1_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Koordinatentransfer1_Y.out1,
        &Koordinatentransfer1_Y.out2
      };

      rtliSetLogYSignalPtrs(Koordinatentransfer1_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        2,
        2
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Koordinatentransfer1/out1",
        "Koordinatentransfer1/out2" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
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

      rtliSetLogYSignalInfo(Koordinatentransfer1_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(Koordinatentransfer1_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset((void *)&Koordinatentransfer1_U, 0,
                sizeof(ExtU_Koordinatentransfer1_T));

  /* external outputs */
  (void) memset((void *)&Koordinatentransfer1_Y, 0,
                sizeof(ExtY_Koordinatentransfer1_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Koordinatentransfer1_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Koordinatentransfer1_M),
    Koordinatentransfer1_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Koordinatentransfer1_M)));
}

/* Model terminate function */
void Koordinatentransfer1_terminate(void)
{
  /* (no terminate code required) */
}
