/*
 * R.c
 *
 * Code generation for model "R".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:09:52 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "R.h"
#include "R_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_R_T R_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_R_T R_Y;

/* Real-time model */
RT_MODEL_R_T R_M_;
RT_MODEL_R_T *const R_M = &R_M_;

/* Model step function */
void R_step(void)
{
  /* Outport: '<Root>/out1' incorporates:
   *  Inport: '<Root>/cos'
   *  Inport: '<Root>/in1'
   *  Inport: '<Root>/in2'
   *  Inport: '<Root>/sin'
   *  Product: '<S1>/Isa*cos'
   *  Product: '<S1>/Isb*sin'
   *  Sum: '<S1>/Sum'
   */
  R_Y.out1 = R_U.in1 * R_U.cos_l + R_U.in2 * R_U.sin_i;

  /* Outport: '<Root>/out2' incorporates:
   *  Inport: '<Root>/cos'
   *  Inport: '<Root>/in1'
   *  Inport: '<Root>/in2'
   *  Inport: '<Root>/sin'
   *  Product: '<S1>/Isa*sin'
   *  Product: '<S1>/Isb*cos'
   *  Sum: '<S1>/Sum1'
   */
  R_Y.out2 = R_U.in2 * R_U.cos_l - R_U.in1 * R_U.sin_i;

  /* Matfile logging */
  rt_UpdateTXYLogVars(R_M->rtwLogInfo, (&R_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(R_M)!=-1) &&
        !((rtmGetTFinal(R_M)-R_M->Timing.taskTime0) > R_M->Timing.taskTime0 *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(R_M, "Simulation finished");
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
  if (!(++R_M->Timing.clockTick0)) {
    ++R_M->Timing.clockTickH0;
  }

  R_M->Timing.taskTime0 = R_M->Timing.clockTick0 * R_M->Timing.stepSize0 +
    R_M->Timing.clockTickH0 * R_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void R_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)R_M, 0,
                sizeof(RT_MODEL_R_T));
  rtmSetTFinal(R_M, 0.1);
  R_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    R_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(R_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(R_M->rtwLogInfo, (NULL));
    rtliSetLogT(R_M->rtwLogInfo, "tout");
    rtliSetLogX(R_M->rtwLogInfo, "");
    rtliSetLogXFinal(R_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(R_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(R_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(R_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(R_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &R_Y.out1,
        &R_Y.out2
      };

      rtliSetLogYSignalPtrs(R_M->rtwLogInfo, ((LogSignalPtrsType)
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
        "R/out1",
        "R/out2" };

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

      rtliSetLogYSignalInfo(R_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(R_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset((void *)&R_U, 0,
                sizeof(ExtU_R_T));

  /* external outputs */
  (void) memset((void *)&R_Y, 0,
                sizeof(ExtY_R_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(R_M->rtwLogInfo, 0.0, rtmGetTFinal(R_M),
    R_M->Timing.stepSize0, (&rtmGetErrorStatus(R_M)));
}

/* Model terminate function */
void R_terminate(void)
{
  /* (no terminate code required) */
}
