/*
 * Inverses.c
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
#include "Inverses.h"
#include "Inverses_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Inverses_T Inverses_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Inverses_T Inverses_Y;

/* Real-time model */
RT_MODEL_Inverses_T Inverses_M_;
RT_MODEL_Inverses_T *const Inverses_M = &Inverses_M_;

/* Model step function */
void Inverses_step(void)
{
  /* Outport: '<Root>/Usm' incorporates:
   *  Gain: '<S1>/Lsigmal'
   *  Gain: '<S1>/Rsm'
   *  Inport: '<Root>/Isl'
   *  Inport: '<Root>/Ism'
   *  Inport: '<Root>/wS'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Sum2'
   */
  Inverses_Y.Usm = Inverses_P.Rsm_Gain * Inverses_U.Ism -
    Inverses_P.Lsigmal_Gain * Inverses_U.Isl * Inverses_U.wS;

  /* Outport: '<Root>/Usl' incorporates:
   *  Gain: '<S1>/Lsigmam'
   *  Gain: '<S1>/Rsl'
   *  Inport: '<Root>/Isl'
   *  Inport: '<Root>/Ism'
   *  Inport: '<Root>/Psi'
   *  Inport: '<Root>/wS'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  Inverses_Y.Usl = (Inverses_P.Lsigmam_Gain * Inverses_U.Ism + Inverses_U.Psi) *
    Inverses_U.wS + Inverses_P.Rsl_Gain * Inverses_U.Isl;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Inverses_M->rtwLogInfo, (&Inverses_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(Inverses_M)!=-1) &&
        !((rtmGetTFinal(Inverses_M)-Inverses_M->Timing.taskTime0) >
          Inverses_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Inverses_M, "Simulation finished");
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
  if (!(++Inverses_M->Timing.clockTick0)) {
    ++Inverses_M->Timing.clockTickH0;
  }

  Inverses_M->Timing.taskTime0 = Inverses_M->Timing.clockTick0 *
    Inverses_M->Timing.stepSize0 + Inverses_M->Timing.clockTickH0 *
    Inverses_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Inverses_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Inverses_M, 0,
                sizeof(RT_MODEL_Inverses_T));
  rtmSetTFinal(Inverses_M, 0.1);
  Inverses_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Inverses_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Inverses_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Inverses_M->rtwLogInfo, (NULL));
    rtliSetLogT(Inverses_M->rtwLogInfo, "tout");
    rtliSetLogX(Inverses_M->rtwLogInfo, "");
    rtliSetLogXFinal(Inverses_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Inverses_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Inverses_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Inverses_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Inverses_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Inverses_Y.Usm,
        &Inverses_Y.Usl
      };

      rtliSetLogYSignalPtrs(Inverses_M->rtwLogInfo, ((LogSignalPtrsType)
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
        "Inverses/Usm",
        "Inverses/Usl" };

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

      rtliSetLogYSignalInfo(Inverses_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(Inverses_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset((void *)&Inverses_U, 0,
                sizeof(ExtU_Inverses_T));

  /* external outputs */
  (void) memset((void *)&Inverses_Y, 0,
                sizeof(ExtY_Inverses_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Inverses_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Inverses_M), Inverses_M->Timing.stepSize0, (&rtmGetErrorStatus(Inverses_M)));
}

/* Model terminate function */
void Inverses_terminate(void)
{
  /* (no terminate code required) */
}
