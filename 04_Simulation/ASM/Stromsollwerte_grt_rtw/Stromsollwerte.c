/*
 * Stromsollwerte.c
 *
 * Code generation for model "Stromsollwerte".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:08:05 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Stromsollwerte.h"
#include "Stromsollwerte_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Stromsollwerte_T Stromsollwerte_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Stromsollwerte_T Stromsollwerte_Y;

/* Real-time model */
RT_MODEL_Stromsollwerte_T Stromsollwerte_M_;
RT_MODEL_Stromsollwerte_T *const Stromsollwerte_M = &Stromsollwerte_M_;

/* Model step function */
void Stromsollwerte_step(void)
{
  /* Outport: '<Root>/Ism' incorporates:
   *  Gain: '<S1>/1//L'
   *  Inport: '<Root>/Psi'
   */
  Stromsollwerte_Y.Ism = Stromsollwerte_P.L_Gain * Stromsollwerte_U.Psi;

  /* Outport: '<Root>/Isl' incorporates:
   *  Inport: '<Root>/M'
   *  Inport: '<Root>/Psi'
   *  Product: '<S1>/Divide'
   */
  Stromsollwerte_Y.Isl = Stromsollwerte_U.M / Stromsollwerte_U.Psi;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Stromsollwerte_M->rtwLogInfo,
                      (&Stromsollwerte_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(Stromsollwerte_M)!=-1) &&
        !((rtmGetTFinal(Stromsollwerte_M)-Stromsollwerte_M->Timing.taskTime0) >
          Stromsollwerte_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Stromsollwerte_M, "Simulation finished");
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
  if (!(++Stromsollwerte_M->Timing.clockTick0)) {
    ++Stromsollwerte_M->Timing.clockTickH0;
  }

  Stromsollwerte_M->Timing.taskTime0 = Stromsollwerte_M->Timing.clockTick0 *
    Stromsollwerte_M->Timing.stepSize0 + Stromsollwerte_M->Timing.clockTickH0 *
    Stromsollwerte_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Stromsollwerte_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Stromsollwerte_M, 0,
                sizeof(RT_MODEL_Stromsollwerte_T));
  rtmSetTFinal(Stromsollwerte_M, 0.1);
  Stromsollwerte_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Stromsollwerte_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Stromsollwerte_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Stromsollwerte_M->rtwLogInfo, (NULL));
    rtliSetLogT(Stromsollwerte_M->rtwLogInfo, "tout");
    rtliSetLogX(Stromsollwerte_M->rtwLogInfo, "");
    rtliSetLogXFinal(Stromsollwerte_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Stromsollwerte_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Stromsollwerte_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Stromsollwerte_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Stromsollwerte_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Stromsollwerte_Y.Ism,
        &Stromsollwerte_Y.Isl
      };

      rtliSetLogYSignalPtrs(Stromsollwerte_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
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
        "Stromsollwerte/Ism",
        "Stromsollwerte/Isl" };

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

      rtliSetLogYSignalInfo(Stromsollwerte_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(Stromsollwerte_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset((void *)&Stromsollwerte_U, 0,
                sizeof(ExtU_Stromsollwerte_T));

  /* external outputs */
  (void) memset((void *)&Stromsollwerte_Y, 0,
                sizeof(ExtY_Stromsollwerte_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Stromsollwerte_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Stromsollwerte_M), Stromsollwerte_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Stromsollwerte_M)));
}

/* Model terminate function */
void Stromsollwerte_terminate(void)
{
  /* (no terminate code required) */
}
