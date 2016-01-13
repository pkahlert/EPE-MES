/*
 * Strommodel.c
 *
 * Code generation for model "Strommodel".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:07:38 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Strommodel.h"
#include "Strommodel_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Strommodel_T Strommodel_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Strommodel_T Strommodel_Y;

/* Real-time model */
RT_MODEL_Strommodel_T Strommodel_M_;
RT_MODEL_Strommodel_T *const Strommodel_M = &Strommodel_M_;

/* Model step function */
void Strommodel_step(void)
{
  /* Outport: '<Root>/wR' incorporates:
   *  Gain: '<S1>/Rr'
   *  Inport: '<Root>/Isl'
   *  Inport: '<Root>/Psi'
   *  Product: '<S1>/Divide'
   */
  Strommodel_Y.wR = Strommodel_U.Isl / Strommodel_U.Psi * Strommodel_P.Rr_Gain;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Strommodel_M->rtwLogInfo, (&Strommodel_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(Strommodel_M)!=-1) &&
        !((rtmGetTFinal(Strommodel_M)-Strommodel_M->Timing.taskTime0) >
          Strommodel_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Strommodel_M, "Simulation finished");
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
  if (!(++Strommodel_M->Timing.clockTick0)) {
    ++Strommodel_M->Timing.clockTickH0;
  }

  Strommodel_M->Timing.taskTime0 = Strommodel_M->Timing.clockTick0 *
    Strommodel_M->Timing.stepSize0 + Strommodel_M->Timing.clockTickH0 *
    Strommodel_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Strommodel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Strommodel_M, 0,
                sizeof(RT_MODEL_Strommodel_T));
  rtmSetTFinal(Strommodel_M, 0.1);
  Strommodel_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Strommodel_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Strommodel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Strommodel_M->rtwLogInfo, (NULL));
    rtliSetLogT(Strommodel_M->rtwLogInfo, "tout");
    rtliSetLogX(Strommodel_M->rtwLogInfo, "");
    rtliSetLogXFinal(Strommodel_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Strommodel_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Strommodel_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Strommodel_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Strommodel_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Strommodel_Y.wR
      };

      rtliSetLogYSignalPtrs(Strommodel_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        2
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Strommodel/wR" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
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

      rtliSetLogYSignalInfo(Strommodel_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(Strommodel_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset((void *)&Strommodel_U, 0,
                sizeof(ExtU_Strommodel_T));

  /* external outputs */
  Strommodel_Y.wR = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Strommodel_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Strommodel_M), Strommodel_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Strommodel_M)));
}

/* Model terminate function */
void Strommodel_terminate(void)
{
  /* (no terminate code required) */
}
