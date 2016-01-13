/*
 * wn.c
 *
 * Code generation for model "wn".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 08:10:14 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "wn.h"
#include "wn_private.h"

/* Continuous states */
X_wn_T wn_X;

/* External inputs (root inport signals with auto storage) */
ExtU_wn_T wn_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_wn_T wn_Y;

/* Real-time model */
RT_MODEL_wn_T wn_M_;
RT_MODEL_wn_T *const wn_M = &wn_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  wn_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  wn_step();
  wn_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  wn_step();
  wn_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  wn_step();
  wn_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  wn_step();
  wn_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  wn_step();
  wn_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void wn_step(void)
{
  if (rtmIsMajorTimeStep(wn_M)) {
    /* set solver stop time */
    if (!(wn_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&wn_M->solverInfo, ((wn_M->Timing.clockTickH0 + 1) *
        wn_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&wn_M->solverInfo, ((wn_M->Timing.clockTick0 + 1) *
        wn_M->Timing.stepSize0 + wn_M->Timing.clockTickH0 *
        wn_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(wn_M)) {
    wn_M->Timing.t[0] = rtsiGetT(&wn_M->solverInfo);
  }

  /* Outport: '<Root>/cos' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Trigonometry: '<S1>/Trigonometric Function'
   */
  wn_Y.cos_f = cos(wn_X.Integrator_CSTATE);

  /* Outport: '<Root>/sin' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Trigonometry: '<S1>/Trigonometric Function1'
   */
  wn_Y.sin_i = sin(wn_X.Integrator_CSTATE);
  if (rtmIsMajorTimeStep(wn_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(wn_M->rtwLogInfo, (wn_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(wn_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(wn_M)!=-1) &&
          !((rtmGetTFinal(wn_M)-(((wn_M->Timing.clockTick1+
               wn_M->Timing.clockTickH1* 4294967296.0)) * 0.02)) >
            (((wn_M->Timing.clockTick1+wn_M->Timing.clockTickH1* 4294967296.0)) *
             0.02) * (DBL_EPSILON))) {
        rtmSetErrorStatus(wn_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&wn_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++wn_M->Timing.clockTick0)) {
      ++wn_M->Timing.clockTickH0;
    }

    wn_M->Timing.t[0] = rtsiGetSolverStopTime(&wn_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.02s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.02, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      wn_M->Timing.clockTick1++;
      if (!wn_M->Timing.clockTick1) {
        wn_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void wn_derivatives(void)
{
  XDot_wn_T *_rtXdot;
  _rtXdot = ((XDot_wn_T *) wn_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' incorporates:
   *  Derivatives for Inport: '<Root>/wn'
   */
  _rtXdot->Integrator_CSTATE = wn_U.wn_a;
}

/* Model initialize function */
void wn_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)wn_M, 0,
                sizeof(RT_MODEL_wn_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&wn_M->solverInfo, &wn_M->Timing.simTimeStep);
    rtsiSetTPtr(&wn_M->solverInfo, &rtmGetTPtr(wn_M));
    rtsiSetStepSizePtr(&wn_M->solverInfo, &wn_M->Timing.stepSize0);
    rtsiSetdXPtr(&wn_M->solverInfo, &wn_M->ModelData.derivs);
    rtsiSetContStatesPtr(&wn_M->solverInfo, (real_T **)
                         &wn_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&wn_M->solverInfo, &wn_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&wn_M->solverInfo, (&rtmGetErrorStatus(wn_M)));
    rtsiSetRTModelPtr(&wn_M->solverInfo, wn_M);
  }

  rtsiSetSimTimeStep(&wn_M->solverInfo, MAJOR_TIME_STEP);
  wn_M->ModelData.intgData.y = wn_M->ModelData.odeY;
  wn_M->ModelData.intgData.f[0] = wn_M->ModelData.odeF[0];
  wn_M->ModelData.intgData.f[1] = wn_M->ModelData.odeF[1];
  wn_M->ModelData.intgData.f[2] = wn_M->ModelData.odeF[2];
  wn_M->ModelData.intgData.f[3] = wn_M->ModelData.odeF[3];
  wn_M->ModelData.intgData.f[4] = wn_M->ModelData.odeF[4];
  wn_M->ModelData.intgData.f[5] = wn_M->ModelData.odeF[5];
  wn_M->ModelData.contStates = ((X_wn_T *) &wn_X);
  rtsiSetSolverData(&wn_M->solverInfo, (void *)&wn_M->ModelData.intgData);
  rtsiSetSolverName(&wn_M->solverInfo,"ode5");
  rtmSetTPtr(wn_M, &wn_M->Timing.tArray[0]);
  rtmSetTFinal(wn_M, 0.1);
  wn_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    wn_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(wn_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(wn_M->rtwLogInfo, (NULL));
    rtliSetLogT(wn_M->rtwLogInfo, "tout");
    rtliSetLogX(wn_M->rtwLogInfo, "");
    rtliSetLogXFinal(wn_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(wn_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(wn_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(wn_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(wn_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &wn_Y.cos_f,
        &wn_Y.sin_i
      };

      rtliSetLogYSignalPtrs(wn_M->rtwLogInfo, ((LogSignalPtrsType)
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
        "wn/cos",
        "wn/sin" };

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

      rtliSetLogYSignalInfo(wn_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(wn_M->rtwLogInfo, "yout");
  }

  /* states (continuous) */
  {
    (void) memset((void *)&wn_X, 0,
                  sizeof(X_wn_T));
  }

  /* external inputs */
  wn_U.wn_a = 0.0;

  /* external outputs */
  (void) memset((void *)&wn_Y, 0,
                sizeof(ExtY_wn_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(wn_M->rtwLogInfo, 0.0, rtmGetTFinal(wn_M),
    wn_M->Timing.stepSize0, (&rtmGetErrorStatus(wn_M)));

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  wn_X.Integrator_CSTATE = wn_P.Integrator_IC;
}

/* Model terminate function */
void wn_terminate(void)
{
  /* (no terminate code required) */
}
