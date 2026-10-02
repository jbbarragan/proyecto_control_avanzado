/*
 * orasiyaeselbueno.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "orasiyaeselbueno".
 *
 * Model version              : 20.0
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Fri Oct  2 10:47:10 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "orasiyaeselbueno.h"
#include "rtwtypes.h"
#include <emmintrin.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "orasiyaeselbueno_private.h"
#include <string.h>
#include "orasiyaeselbueno_dt.h"

/* Block signals (default storage) */
B_orasiyaeselbueno_T orasiyaeselbueno_B;

/* Continuous states */
X_orasiyaeselbueno_T orasiyaeselbueno_X;

/* Disabled State Vector */
XDis_orasiyaeselbueno_T orasiyaeselbueno_XDis;

/* Block states (default storage) */
DW_orasiyaeselbueno_T orasiyaeselbueno_DW;

/* Real-time model */
static RT_MODEL_orasiyaeselbueno_T orasiyaeselbueno_M_;
RT_MODEL_orasiyaeselbueno_T *const orasiyaeselbueno_M = &orasiyaeselbueno_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  orasiyaeselbueno_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void orasiyaeselbueno_output(void)
{
  __m128d tmp_2;
  real_T rtb_HILReadTimebase_o3[4];
  real_T rtb_LEDColour[3];
  real_T rtb_HILReadTimebase_o2[2];
  real_T tmp_1[2];
  real_T StateSpace_CSTATE;
  real_T StateSpace_CSTATE_0;
  real_T Stepend_time_tmp;
  real_T tmp_0;
  int_T iy;
  int8_T rtAction;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(orasiyaeselbueno_M)) {
    /* set solver stop time */
    if (!(orasiyaeselbueno_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&orasiyaeselbueno_M->solverInfo,
                            ((orasiyaeselbueno_M->Timing.clockTickH0 + 1) *
        orasiyaeselbueno_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&orasiyaeselbueno_M->solverInfo,
                            ((orasiyaeselbueno_M->Timing.clockTick0 + 1) *
        orasiyaeselbueno_M->Timing.stepSize0 +
        orasiyaeselbueno_M->Timing.clockTickH0 *
        orasiyaeselbueno_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(orasiyaeselbueno_M)) {
    orasiyaeselbueno_M->Timing.t[0] = rtsiGetT(&orasiyaeselbueno_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(orasiyaeselbueno_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(orasiyaeselbueno_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(orasiyaeselbueno_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(orasiyaeselbueno_DW.SwitchCaseActionSubsystem2_Subs);
  tmp = rtmIsMajorTimeStep(orasiyaeselbueno_M);
  if (tmp) {
    /* S-Function (hil_read_timebase_block): '<Root>/HIL Read Timebase' */

    /* S-Function Block: orasiyaeselbueno/HIL Read Timebase (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(orasiyaeselbueno_DW.HILReadTimebase_Task, 1,
        &orasiyaeselbueno_B.HILReadTimebase_o1[0],
        &orasiyaeselbueno_DW.HILReadTimebase_EncoderBuffer[0],
        NULL,
        &rtb_HILReadTimebase_o3[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
      } else {
        rtb_HILReadTimebase_o2[0] =
          orasiyaeselbueno_DW.HILReadTimebase_EncoderBuffer[0];
        rtb_HILReadTimebase_o2[1] =
          orasiyaeselbueno_DW.HILReadTimebase_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<Root>/Pitch Bias Removal' */
    /* Step: '<S3>/Step: end_time' incorporates:
     *  Step: '<S3>/Step: start_time'
     */
    Stepend_time_tmp = orasiyaeselbueno_M->Timing.t[1];

    /* Outputs for Atomic SubSystem: '<Root>/Pitch Bias Removal' */
    if (Stepend_time_tmp < orasiyaeselbueno_P.PitchBiasRemoval_end_time) {
      /* Step: '<S3>/Step: end_time' */
      orasiyaeselbueno_B.Stepend_time = orasiyaeselbueno_P.Stepend_time_Y0;
    } else {
      /* Step: '<S3>/Step: end_time' */
      orasiyaeselbueno_B.Stepend_time = orasiyaeselbueno_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S3>/Step: end_time' */

    /* Step: '<S3>/Step: start_time' */
    if (Stepend_time_tmp < orasiyaeselbueno_P.PitchBiasRemoval_start_time) {
      Stepend_time_tmp = orasiyaeselbueno_P.Stepstart_time_Y0;
    } else {
      Stepend_time_tmp = orasiyaeselbueno_P.Stepstart_time_YFinal;
    }

    /* End of Outputs for SubSystem: '<Root>/Pitch Bias Removal' */

    /* Outputs for Enabled SubSystem: '<S3>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    /* Logic: '<S3>/Logical Operator' incorporates:
     *  Logic: '<S3>/Logical Operator1'
     *  Step: '<S3>/Step: start_time'
     */
    if ((Stepend_time_tmp != 0.0) && (!(orasiyaeselbueno_B.Stepend_time != 0.0)))
    {
      if (!orasiyaeselbueno_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
        orasiyaeselbueno_DW.UnitDelay_DSTATE =
          orasiyaeselbueno_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S6>/Sum( k=1,n-1, x(k) )' */
        orasiyaeselbueno_DW.Sumk1n1xk_DSTATE =
          orasiyaeselbueno_P.Sumk1n1xk_InitialCondition;
        orasiyaeselbueno_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S10>/Count' incorporates:
       *  Constant: '<S10>/unity'
       *  UnitDelay: '<S10>/Unit Delay'
       */
      orasiyaeselbueno_B.Count = orasiyaeselbueno_P.unity_Value +
        orasiyaeselbueno_DW.UnitDelay_DSTATE;

      /* Sum: '<S6>/Sum' incorporates:
       *  Product: '<Root>/Ax//Az'
       *  Trigonometry: '<Root>/Calculate Pitch'
       *  UnitDelay: '<S6>/Sum( k=1,n-1, x(k) )'
       */
      orasiyaeselbueno_B.Sum_p = atan(rtb_HILReadTimebase_o3[0] /
        rtb_HILReadTimebase_o3[1]) + orasiyaeselbueno_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S6>/div' */
      orasiyaeselbueno_B.div = orasiyaeselbueno_B.Sum_p /
        orasiyaeselbueno_B.Count;
      srUpdateBC(orasiyaeselbueno_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      orasiyaeselbueno_DW.EnabledMovingAverage_MODE = false;
    }

    /* End of Logic: '<S3>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S3>/Enabled Moving Average' */

    /* SwitchCase: '<S3>/Switch Case' */
    rtAction = -1;

    /* Outputs for Atomic SubSystem: '<Root>/Pitch Bias Removal' */
    Stepend_time_tmp = trunc(orasiyaeselbueno_P.PitchBiasRemoval_switch_id);

    /* End of Outputs for SubSystem: '<Root>/Pitch Bias Removal' */
    if (rtIsNaN(Stepend_time_tmp) || rtIsInf(Stepend_time_tmp)) {
      Stepend_time_tmp = 0.0;
    } else {
      Stepend_time_tmp = fmod(Stepend_time_tmp, 4.294967296E+9);
    }

    if (Stepend_time_tmp < 0.0) {
      iy = -(int32_T)(uint32_T)-Stepend_time_tmp;
    } else {
      iy = (int32_T)(uint32_T)Stepend_time_tmp;
    }

    switch (iy) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    orasiyaeselbueno_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S3>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      srUpdateBC(orasiyaeselbueno_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S3>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S3>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      srUpdateBC(orasiyaeselbueno_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S3>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S3>/Switch Case' */
    /* End of Outputs for SubSystem: '<Root>/Pitch Bias Removal' */

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Pitch Constant'
     */
    orasiyaeselbueno_B.Sum1 = orasiyaeselbueno_P.PitchConstant_Value -
      orasiyaeselbueno_B.div;

    /* Gain: '<Root>/Yaw Rotation Amplitude (rads)' incorporates:
     *  Constant: '<Root>/Constant'
     */
    orasiyaeselbueno_B.YawRotationAmplituderads =
      orasiyaeselbueno_P.YawRotationAmplituderads_Gain *
      orasiyaeselbueno_P.Constant_Value;

    /* Constant: '<S1>/x0' */
    orasiyaeselbueno_B.x0 = orasiyaeselbueno_P.x0_Value;
  }

  /* Integrator: '<S1>/Integrator1' */
  if (orasiyaeselbueno_DW.Integrator1_DWORK1) {
    orasiyaeselbueno_X.Integrator1_CSTATE[0] = orasiyaeselbueno_B.x0;
    orasiyaeselbueno_X.Integrator1_CSTATE[1] = orasiyaeselbueno_B.x0;
  }

  /* Integrator: '<S1>/Integrator1' */
  orasiyaeselbueno_B.Integrator1[0] = orasiyaeselbueno_X.Integrator1_CSTATE[0];

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/wn'
   *  Integrator: '<S1>/Integrator2'
   */
  orasiyaeselbueno_B.Product1[0] =
    orasiyaeselbueno_P.GenerateCurrentStateX_input_wid *
    orasiyaeselbueno_X.Integrator2_CSTATE[0];

  /* Integrator: '<S1>/Integrator1' */
  orasiyaeselbueno_B.Integrator1[1] = orasiyaeselbueno_X.Integrator1_CSTATE[1];

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/wn'
   *  Integrator: '<S1>/Integrator2'
   */
  orasiyaeselbueno_B.Product1[1] =
    orasiyaeselbueno_P.GenerateCurrentStateX_input_wid *
    orasiyaeselbueno_X.Integrator2_CSTATE[1];

  /* Sum: '<Root>/Sum' */
  tmp_2 = _mm_sub_pd(_mm_set_pd(orasiyaeselbueno_B.YawRotationAmplituderads,
    orasiyaeselbueno_B.Sum1), _mm_loadu_pd(&orasiyaeselbueno_B.Integrator1[0]));

  /* Sum: '<Root>/Sum' */
  _mm_storeu_pd(&orasiyaeselbueno_B.Sum[0], tmp_2);

  /* Constant: '<Root>/Zero speed  setpoint' incorporates:
   *  Sum: '<Root>/Sum'
   */
  tmp_2 = _mm_sub_pd(_mm_set1_pd(orasiyaeselbueno_P.Zerospeedsetpoint_Value),
                     _mm_loadu_pd(&orasiyaeselbueno_B.Product1[0]));

  /* Sum: '<Root>/Sum' */
  _mm_storeu_pd(&orasiyaeselbueno_B.Sum[2], tmp_2);

  /* Gain: '<Root>/LQR Gains' */
  Stepend_time_tmp = 0.0;
  tmp_0 = 0.0;
  for (iy = 0; iy < 4; iy++) {
    _mm_storeu_pd(&tmp_1[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&orasiyaeselbueno_P.K_lqr[iy << 1]), _mm_set1_pd
      (orasiyaeselbueno_B.Sum[iy])), _mm_set_pd(tmp_0, Stepend_time_tmp)));
    Stepend_time_tmp = tmp_1[0];
    tmp_0 = tmp_1[1];
  }

  /* End of Gain: '<Root>/LQR Gains' */

  /* Saturate: '<Root>/+//- 24V' */
  if (Stepend_time_tmp > orasiyaeselbueno_P.u4V_UpperSat) {
    /* Saturate: '<Root>/+//- 24V' */
    Stepend_time_tmp = orasiyaeselbueno_P.u4V_UpperSat;
  } else if (Stepend_time_tmp < orasiyaeselbueno_P.u4V_LowerSat) {
    /* Saturate: '<Root>/+//- 24V' */
    Stepend_time_tmp = orasiyaeselbueno_P.u4V_LowerSat;
  }

  /* Saturate: '<Root>/+//- 24V' */
  orasiyaeselbueno_B.u4V[0] = Stepend_time_tmp;

  /* Switch: '<Root>/Motor Enable' */
  if (orasiyaeselbueno_B.Stepend_time > orasiyaeselbueno_P.MotorEnable_Threshold)
  {
    /* Switch: '<Root>/Motor Enable' */
    orasiyaeselbueno_B.MotorEnable[0] = Stepend_time_tmp;
  } else {
    /* Switch: '<Root>/Motor Enable' incorporates:
     *  Constant: '<Root>/No Control'
     */
    orasiyaeselbueno_B.MotorEnable[0] = orasiyaeselbueno_P.NoControl_Value[0];
  }

  /* Saturate: '<Root>/+//- 24V' */
  if (tmp_0 > orasiyaeselbueno_P.u4V_UpperSat) {
    /* Saturate: '<Root>/+//- 24V' */
    Stepend_time_tmp = orasiyaeselbueno_P.u4V_UpperSat;
  } else if (tmp_0 < orasiyaeselbueno_P.u4V_LowerSat) {
    /* Saturate: '<Root>/+//- 24V' */
    Stepend_time_tmp = orasiyaeselbueno_P.u4V_LowerSat;
  } else {
    /* Saturate: '<Root>/+//- 24V' */
    Stepend_time_tmp = tmp_0;
  }

  /* Saturate: '<Root>/+//- 24V' */
  orasiyaeselbueno_B.u4V[1] = Stepend_time_tmp;

  /* Switch: '<Root>/Motor Enable' */
  if (orasiyaeselbueno_B.Stepend_time > orasiyaeselbueno_P.MotorEnable_Threshold)
  {
    /* Switch: '<Root>/Motor Enable' */
    orasiyaeselbueno_B.MotorEnable[1] = Stepend_time_tmp;
  } else {
    /* Switch: '<Root>/Motor Enable' incorporates:
     *  Constant: '<Root>/No Control'
     */
    orasiyaeselbueno_B.MotorEnable[1] = orasiyaeselbueno_P.NoControl_Value[1];
  }

  if (tmp) {
    /* Switch: '<Root>/LED Colour' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S4>/Constant'
     */
    if (orasiyaeselbueno_B.Stepend_time > orasiyaeselbueno_P.LEDColour_Threshold)
    {
      rtb_LEDColour[0] = orasiyaeselbueno_P.Green_color[0];
      rtb_LEDColour[1] = orasiyaeselbueno_P.Green_color[1];
      rtb_LEDColour[2] = orasiyaeselbueno_P.Green_color[2];
    } else {
      rtb_LEDColour[0] = orasiyaeselbueno_P.Yellow_color[0];
      rtb_LEDColour[1] = orasiyaeselbueno_P.Yellow_color[1];
      rtb_LEDColour[2] = orasiyaeselbueno_P.Yellow_color[2];
    }

    /* End of Switch: '<Root>/LED Colour' */

    /* S-Function (hil_write_block): '<Root>/HIL Write' */

    /* S-Function Block: orasiyaeselbueno/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(orasiyaeselbueno_DW.HILInitialize_Card,
                         orasiyaeselbueno_P.HILWrite_analog_channels, 2U,
                         NULL, 0U,
                         NULL, 0U,
                         orasiyaeselbueno_P.HILWrite_other_channels, 3U,
                         &orasiyaeselbueno_B.MotorEnable[0],
                         NULL,
                         NULL,
                         &rtb_LEDColour[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
      }
    }

    /* Gain: '<Root>/Counts//s to rads//s' */
    tmp_2 = _mm_mul_pd(_mm_set1_pd(orasiyaeselbueno_P.Countsstoradss_Gain),
                       _mm_loadu_pd(&rtb_HILReadTimebase_o3[2]));

    /* Gain: '<Root>/Counts//s to rads//s' */
    _mm_storeu_pd(&orasiyaeselbueno_B.Countsstoradss[0], tmp_2);
  }

  /* StateSpace: '<Root>/State-Space' */
  Stepend_time_tmp = orasiyaeselbueno_X.StateSpace_CSTATE[1];
  tmp_0 = orasiyaeselbueno_X.StateSpace_CSTATE[0];
  StateSpace_CSTATE = orasiyaeselbueno_X.StateSpace_CSTATE[2];
  StateSpace_CSTATE_0 = orasiyaeselbueno_X.StateSpace_CSTATE[3];
  for (iy = 0; iy <= 0; iy += 2) {
    /* StateSpace: '<Root>/State-Space' */
    _mm_storeu_pd(&orasiyaeselbueno_B.StateSpace[iy], _mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&orasiyaeselbueno_P.C[iy + 2]),
      _mm_set1_pd(Stepend_time_tmp)), _mm_mul_pd(_mm_loadu_pd
      (&orasiyaeselbueno_P.C[iy]), _mm_set1_pd(tmp_0))), _mm_mul_pd(_mm_loadu_pd
      (&orasiyaeselbueno_P.C[iy + 4]), _mm_set1_pd(StateSpace_CSTATE))),
      _mm_mul_pd(_mm_loadu_pd(&orasiyaeselbueno_P.C[iy + 6]), _mm_set1_pd
                 (StateSpace_CSTATE_0))));
  }

  /* End of StateSpace: '<Root>/State-Space' */
  if (tmp) {
  }

  /* Integrator: '<S5>/Integrator1' */
  orasiyaeselbueno_B.Integrator1_k[0] = orasiyaeselbueno_X.Integrator1_CSTATE_f
    [0];
  orasiyaeselbueno_B.Integrator1_k[1] = orasiyaeselbueno_X.Integrator1_CSTATE_f
    [1];
  if (tmp) {
    /* Gain: '<Root>/Counts to rads' */
    tmp_2 = _mm_mul_pd(_mm_loadu_pd(&orasiyaeselbueno_P.Countstorads_Gain[0]),
                       _mm_loadu_pd(&rtb_HILReadTimebase_o2[0]));

    /* Gain: '<Root>/Counts to rads' */
    _mm_storeu_pd(&orasiyaeselbueno_B.Countstorads[0], tmp_2);
  }

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/wn'
   *  Constant: '<S1>/zt'
   *  Integrator: '<S1>/Integrator2'
   *  Product: '<S1>/Product2'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  orasiyaeselbueno_B.Product[0] = ((orasiyaeselbueno_B.Countstorads[0] -
    orasiyaeselbueno_B.Integrator1[0]) - orasiyaeselbueno_X.Integrator2_CSTATE[0]
    * orasiyaeselbueno_P.Constant_Value_h *
    orasiyaeselbueno_P.GenerateCurrentStateX_input_zet) *
    orasiyaeselbueno_P.GenerateCurrentStateX_input_wid;

  /* Integrator: '<S5>/Integrator' */
  orasiyaeselbueno_B.Integrator[0] = orasiyaeselbueno_X.Integrator_CSTATE[0];

  /* Sum: '<S5>/Sum2' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  Stepend_time_tmp = orasiyaeselbueno_B.Integrator1[0] -
    orasiyaeselbueno_B.Integrator1_k[0];

  /* Sum: '<S5>/Sum3' incorporates:
   *  Gain: '<S5>/beta'
   *  Integrator: '<S5>/Integrator2'
   */
  orasiyaeselbueno_B.Sum3[0] = Stepend_time_tmp - orasiyaeselbueno_P.beta *
    orasiyaeselbueno_X.Integrator2_CSTATE_j[0];

  /* Sum: '<S5>/Sum4' incorporates:
   *  Gain: '<S5>/l'
   *  Gain: '<S5>/m'
   *  Integrator: '<S5>/Integrator2'
   */
  orasiyaeselbueno_B.Sum4[0] = orasiyaeselbueno_P.l * Stepend_time_tmp +
    orasiyaeselbueno_P.m * orasiyaeselbueno_X.Integrator2_CSTATE_j[0];

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/wn'
   *  Constant: '<S1>/zt'
   *  Integrator: '<S1>/Integrator2'
   *  Product: '<S1>/Product2'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  orasiyaeselbueno_B.Product[1] = ((orasiyaeselbueno_B.Countstorads[1] -
    orasiyaeselbueno_B.Integrator1[1]) - orasiyaeselbueno_X.Integrator2_CSTATE[1]
    * orasiyaeselbueno_P.Constant_Value_h *
    orasiyaeselbueno_P.GenerateCurrentStateX_input_zet) *
    orasiyaeselbueno_P.GenerateCurrentStateX_input_wid;

  /* Integrator: '<S5>/Integrator' */
  orasiyaeselbueno_B.Integrator[1] = orasiyaeselbueno_X.Integrator_CSTATE[1];

  /* Sum: '<S5>/Sum2' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  Stepend_time_tmp = orasiyaeselbueno_B.Integrator1[1] -
    orasiyaeselbueno_B.Integrator1_k[1];

  /* Sum: '<S5>/Sum3' incorporates:
   *  Gain: '<S5>/beta'
   *  Integrator: '<S5>/Integrator2'
   */
  orasiyaeselbueno_B.Sum3[1] = Stepend_time_tmp - orasiyaeselbueno_P.beta *
    orasiyaeselbueno_X.Integrator2_CSTATE_j[1];

  /* Sum: '<S5>/Sum4' incorporates:
   *  Gain: '<S5>/l'
   *  Gain: '<S5>/m'
   *  Integrator: '<S5>/Integrator2'
   */
  orasiyaeselbueno_B.Sum4[1] = orasiyaeselbueno_P.l * Stepend_time_tmp +
    orasiyaeselbueno_P.m * orasiyaeselbueno_X.Integrator2_CSTATE_j[1];
}

/* Model update function */
void orasiyaeselbueno_update(void)
{
  if (rtmIsMajorTimeStep(orasiyaeselbueno_M)) {
    /* Update for Atomic SubSystem: '<Root>/Pitch Bias Removal' */
    /* Update for Enabled SubSystem: '<S3>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (orasiyaeselbueno_DW.EnabledMovingAverage_MODE) {
      /* Update for UnitDelay: '<S10>/Unit Delay' */
      orasiyaeselbueno_DW.UnitDelay_DSTATE = orasiyaeselbueno_B.Count;

      /* Update for UnitDelay: '<S6>/Sum( k=1,n-1, x(k) )' */
      orasiyaeselbueno_DW.Sumk1n1xk_DSTATE = orasiyaeselbueno_B.Sum_p;
    }

    /* End of Update for SubSystem: '<S3>/Enabled Moving Average' */
    /* End of Update for SubSystem: '<Root>/Pitch Bias Removal' */
  }

  /* Update for Integrator: '<S1>/Integrator1' */
  orasiyaeselbueno_DW.Integrator1_DWORK1 = false;
  if (rtmIsMajorTimeStep(orasiyaeselbueno_M)) {
    rt_ertODEUpdateContinuousStates(&orasiyaeselbueno_M->solverInfo);
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
  if (!(++orasiyaeselbueno_M->Timing.clockTick0)) {
    ++orasiyaeselbueno_M->Timing.clockTickH0;
  }

  orasiyaeselbueno_M->Timing.t[0] = rtsiGetSolverStopTime
    (&orasiyaeselbueno_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++orasiyaeselbueno_M->Timing.clockTick1)) {
      ++orasiyaeselbueno_M->Timing.clockTickH1;
    }

    orasiyaeselbueno_M->Timing.t[1] = orasiyaeselbueno_M->Timing.clockTick1 *
      orasiyaeselbueno_M->Timing.stepSize1 +
      orasiyaeselbueno_M->Timing.clockTickH1 *
      orasiyaeselbueno_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void orasiyaeselbueno_derivatives(void)
{
  XDot_orasiyaeselbueno_T *_rtXdot;
  real_T StateSpace_CSTATE;
  real_T StateSpace_CSTATE_0;
  real_T StateSpace_CSTATE_1;
  real_T StateSpace_CSTATE_2;
  real_T u4V;
  real_T u4V_0;
  int_T is;
  _rtXdot = ((XDot_orasiyaeselbueno_T *) orasiyaeselbueno_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = orasiyaeselbueno_B.Product1[0];

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = orasiyaeselbueno_B.Product[0];

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = orasiyaeselbueno_B.Product1[1];

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = orasiyaeselbueno_B.Product[1];

  /* Derivatives for StateSpace: '<Root>/State-Space' */
  StateSpace_CSTATE = orasiyaeselbueno_X.StateSpace_CSTATE[1];
  StateSpace_CSTATE_0 = orasiyaeselbueno_X.StateSpace_CSTATE[0];
  StateSpace_CSTATE_1 = orasiyaeselbueno_X.StateSpace_CSTATE[2];
  StateSpace_CSTATE_2 = orasiyaeselbueno_X.StateSpace_CSTATE[3];
  u4V = orasiyaeselbueno_B.u4V[0];
  u4V_0 = orasiyaeselbueno_B.u4V[1];
  for (is = 0; is <= 2; is += 2) {
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&orasiyaeselbueno_P.A_modelo[is + 4]), _mm_set1_pd(StateSpace_CSTATE)),
      _mm_mul_pd(_mm_loadu_pd(&orasiyaeselbueno_P.A_modelo[is]), _mm_set1_pd
                 (StateSpace_CSTATE_0))), _mm_mul_pd(_mm_loadu_pd
      (&orasiyaeselbueno_P.A_modelo[is + 8]), _mm_set1_pd(StateSpace_CSTATE_1))),
                  _mm_mul_pd(_mm_loadu_pd(&orasiyaeselbueno_P.A_modelo[is + 12]),
      _mm_set1_pd(StateSpace_CSTATE_2))), _mm_mul_pd(_mm_loadu_pd
      (&orasiyaeselbueno_P.B_modelo[is]), _mm_set1_pd(u4V))), _mm_mul_pd
      (_mm_loadu_pd(&orasiyaeselbueno_P.B_modelo[is + 4]), _mm_set1_pd(u4V_0))));
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space' */

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_f[0] = orasiyaeselbueno_B.Integrator[0];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = orasiyaeselbueno_B.Sum4[0];

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j[0] = orasiyaeselbueno_B.Sum3[0];

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_f[1] = orasiyaeselbueno_B.Integrator[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = orasiyaeselbueno_B.Sum4[1];

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j[1] = orasiyaeselbueno_B.Sum3[1];
}

/* Model initialize function */
void orasiyaeselbueno_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: orasiyaeselbueno/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("quanser_aero2_usb", "0",
                      &orasiyaeselbueno_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(orasiyaeselbueno_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
      return;
    }

    if ((orasiyaeselbueno_P.HILInitialize_AIPStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_AIPEnter && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_AIMinimums[0] =
        (orasiyaeselbueno_P.HILInitialize_AILow);
      orasiyaeselbueno_DW.HILInitialize_AIMinimums[1] =
        (orasiyaeselbueno_P.HILInitialize_AILow);
      orasiyaeselbueno_DW.HILInitialize_AIMaximums[0] =
        orasiyaeselbueno_P.HILInitialize_AIHigh;
      orasiyaeselbueno_DW.HILInitialize_AIMaximums[1] =
        orasiyaeselbueno_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (orasiyaeselbueno_DW.HILInitialize_Card,
         orasiyaeselbueno_P.HILInitialize_AIChannels, 2U,
         &orasiyaeselbueno_DW.HILInitialize_AIMinimums[0],
         &orasiyaeselbueno_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if ((orasiyaeselbueno_P.HILInitialize_AOPStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_AOPEnter && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_AOMinimums[0] =
        (orasiyaeselbueno_P.HILInitialize_AOLow);
      orasiyaeselbueno_DW.HILInitialize_AOMinimums[1] =
        (orasiyaeselbueno_P.HILInitialize_AOLow);
      orasiyaeselbueno_DW.HILInitialize_AOMaximums[0] =
        orasiyaeselbueno_P.HILInitialize_AOHigh;
      orasiyaeselbueno_DW.HILInitialize_AOMaximums[1] =
        orasiyaeselbueno_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (orasiyaeselbueno_DW.HILInitialize_Card,
         orasiyaeselbueno_P.HILInitialize_AOChannels, 2U,
         &orasiyaeselbueno_DW.HILInitialize_AOMinimums[0],
         &orasiyaeselbueno_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if ((orasiyaeselbueno_P.HILInitialize_AOStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_AOEnter && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_AOVoltages[0] =
        orasiyaeselbueno_P.HILInitialize_AOInitial;
      orasiyaeselbueno_DW.HILInitialize_AOVoltages[1] =
        orasiyaeselbueno_P.HILInitialize_AOInitial;
      result = hil_write_analog(orasiyaeselbueno_DW.HILInitialize_Card,
        orasiyaeselbueno_P.HILInitialize_AOChannels, 2U,
        &orasiyaeselbueno_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if (orasiyaeselbueno_P.HILInitialize_AOReset) {
      orasiyaeselbueno_DW.HILInitialize_AOVoltages[0] =
        orasiyaeselbueno_P.HILInitialize_AOWatchdog;
      orasiyaeselbueno_DW.HILInitialize_AOVoltages[1] =
        orasiyaeselbueno_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (orasiyaeselbueno_DW.HILInitialize_Card,
         orasiyaeselbueno_P.HILInitialize_AOChannels, 2U,
         &orasiyaeselbueno_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(orasiyaeselbueno_DW.HILInitialize_Card,
      NULL, 0U, orasiyaeselbueno_P.HILInitialize_DOChannels, 2U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
      return;
    }

    if ((orasiyaeselbueno_P.HILInitialize_DOStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_DOEnter && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_DOBits[0] =
        orasiyaeselbueno_P.HILInitialize_DOInitial;
      orasiyaeselbueno_DW.HILInitialize_DOBits[1] =
        orasiyaeselbueno_P.HILInitialize_DOInitial;
      result = hil_write_digital(orasiyaeselbueno_DW.HILInitialize_Card,
        orasiyaeselbueno_P.HILInitialize_DOChannels, 2U, (t_boolean *)
        &orasiyaeselbueno_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if (orasiyaeselbueno_P.HILInitialize_DOReset) {
      orasiyaeselbueno_DW.HILInitialize_DOStates[0] =
        orasiyaeselbueno_P.HILInitialize_DOWatchdog;
      orasiyaeselbueno_DW.HILInitialize_DOStates[1] =
        orasiyaeselbueno_P.HILInitialize_DOWatchdog;
      result = hil_watchdog_set_digital_expiration_state
        (orasiyaeselbueno_DW.HILInitialize_Card,
         orasiyaeselbueno_P.HILInitialize_DOChannels, 2U, (const t_digital_state
          *) &orasiyaeselbueno_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if ((orasiyaeselbueno_P.HILInitialize_EIPStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_EIPEnter && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_QuadratureModes[0] =
        orasiyaeselbueno_P.HILInitialize_EIQuadrature;
      orasiyaeselbueno_DW.HILInitialize_QuadratureModes[1] =
        orasiyaeselbueno_P.HILInitialize_EIQuadrature;
      orasiyaeselbueno_DW.HILInitialize_QuadratureModes[2] =
        orasiyaeselbueno_P.HILInitialize_EIQuadrature;
      orasiyaeselbueno_DW.HILInitialize_QuadratureModes[3] =
        orasiyaeselbueno_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (orasiyaeselbueno_DW.HILInitialize_Card,
         orasiyaeselbueno_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &orasiyaeselbueno_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if ((orasiyaeselbueno_P.HILInitialize_EIStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_EIEnter && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_InitialEICounts[0] =
        orasiyaeselbueno_P.HILInitialize_EIInitial;
      orasiyaeselbueno_DW.HILInitialize_InitialEICounts[1] =
        orasiyaeselbueno_P.HILInitialize_EIInitial;
      orasiyaeselbueno_DW.HILInitialize_InitialEICounts[2] =
        orasiyaeselbueno_P.HILInitialize_EIInitial;
      orasiyaeselbueno_DW.HILInitialize_InitialEICounts[3] =
        orasiyaeselbueno_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(orasiyaeselbueno_DW.HILInitialize_Card,
        orasiyaeselbueno_P.HILInitialize_EIChannels, 4U,
        &orasiyaeselbueno_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if ((orasiyaeselbueno_P.HILInitialize_OOStart && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(orasiyaeselbueno_DW.HILInitialize_Card,
        orasiyaeselbueno_P.HILInitialize_OOChannels, 3U,
        orasiyaeselbueno_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }

    if (orasiyaeselbueno_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (orasiyaeselbueno_DW.HILInitialize_Card,
         orasiyaeselbueno_P.HILInitialize_OOChannels, 3U,
         orasiyaeselbueno_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<Root>/HIL Read Timebase' */

  /* S-Function Block: orasiyaeselbueno/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(orasiyaeselbueno_DW.HILInitialize_Card,
      orasiyaeselbueno_P.HILReadTimebase_SamplesInBuffer,
      orasiyaeselbueno_P.HILReadTimebase_AnalogChannels, 2U,
      orasiyaeselbueno_P.HILReadTimebase_EncoderChannels, 2U,
      NULL, 0U,
      orasiyaeselbueno_P.HILReadTimebase_OtherChannels, 4U,
      &orasiyaeselbueno_DW.HILReadTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (orasiyaeselbueno_DW.HILReadTimebase_Task, (t_buffer_overflow_mode)
         (orasiyaeselbueno_P.HILReadTimebase_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
    }
  }

  /* Start for Atomic SubSystem: '<Root>/Pitch Bias Removal' */
  /* Start for Enabled SubSystem: '<S3>/Enabled Moving Average' */
  orasiyaeselbueno_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S3>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S3>/Switch Case' */
  orasiyaeselbueno_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<Root>/Pitch Bias Removal' */

  /* Start for Constant: '<S1>/x0' */
  orasiyaeselbueno_B.x0 = orasiyaeselbueno_P.x0_Value;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  if (rtmIsFirstInitCond(orasiyaeselbueno_M)) {
    orasiyaeselbueno_X.Integrator1_CSTATE[0] = 0.0;
    orasiyaeselbueno_X.Integrator1_CSTATE[1] = 0.0;
  }

  orasiyaeselbueno_DW.Integrator1_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S1>/Integrator1' */

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  orasiyaeselbueno_X.Integrator2_CSTATE[0] = orasiyaeselbueno_P.Integrator2_IC;
  orasiyaeselbueno_X.Integrator2_CSTATE[1] = orasiyaeselbueno_P.Integrator2_IC;

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  orasiyaeselbueno_X.StateSpace_CSTATE[0] =
    orasiyaeselbueno_P.StateSpace_InitialCondition;
  orasiyaeselbueno_X.StateSpace_CSTATE[1] =
    orasiyaeselbueno_P.StateSpace_InitialCondition;
  orasiyaeselbueno_X.StateSpace_CSTATE[2] =
    orasiyaeselbueno_P.StateSpace_InitialCondition;
  orasiyaeselbueno_X.StateSpace_CSTATE[3] =
    orasiyaeselbueno_P.StateSpace_InitialCondition;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  orasiyaeselbueno_X.Integrator1_CSTATE_f[0] = orasiyaeselbueno_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  orasiyaeselbueno_X.Integrator_CSTATE[0] = orasiyaeselbueno_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator2' */
  orasiyaeselbueno_X.Integrator2_CSTATE_j[0] =
    orasiyaeselbueno_P.Integrator2_IC_o;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  orasiyaeselbueno_X.Integrator1_CSTATE_f[1] = orasiyaeselbueno_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  orasiyaeselbueno_X.Integrator_CSTATE[1] = orasiyaeselbueno_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator2' */
  orasiyaeselbueno_X.Integrator2_CSTATE_j[1] =
    orasiyaeselbueno_P.Integrator2_IC_o;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Pitch Bias Removal' */
  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  orasiyaeselbueno_DW.UnitDelay_DSTATE =
    orasiyaeselbueno_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S6>/Sum( k=1,n-1, x(k) )' */
  orasiyaeselbueno_DW.Sumk1n1xk_DSTATE =
    orasiyaeselbueno_P.Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Product: '<S6>/div' incorporates:
   *  Outport: '<S6>/x_avg_n'
   */
  orasiyaeselbueno_B.div = orasiyaeselbueno_P.x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Moving Average' */
  /* End of SystemInitialize for SubSystem: '<Root>/Pitch Bias Removal' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(orasiyaeselbueno_M)) {
    rtmSetFirstInitCond(orasiyaeselbueno_M, 0);
  }
}

/* Model terminate function */
void orasiyaeselbueno_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: orasiyaeselbueno/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(orasiyaeselbueno_DW.HILInitialize_Card);
    hil_monitor_stop_all(orasiyaeselbueno_DW.HILInitialize_Card);
    is_switching = false;
    if ((orasiyaeselbueno_P.HILInitialize_AOTerminate && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_AOExit && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_AOVoltages[0] =
        orasiyaeselbueno_P.HILInitialize_AOFinal;
      orasiyaeselbueno_DW.HILInitialize_AOVoltages[1] =
        orasiyaeselbueno_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((orasiyaeselbueno_P.HILInitialize_DOTerminate && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_DOExit && is_switching)) {
      orasiyaeselbueno_DW.HILInitialize_DOBits[0] =
        orasiyaeselbueno_P.HILInitialize_DOFinal;
      orasiyaeselbueno_DW.HILInitialize_DOBits[1] =
        orasiyaeselbueno_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 2U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((orasiyaeselbueno_P.HILInitialize_OOTerminate && !is_switching) ||
        (orasiyaeselbueno_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(orasiyaeselbueno_DW.HILInitialize_Card
                         , orasiyaeselbueno_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , orasiyaeselbueno_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , orasiyaeselbueno_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &orasiyaeselbueno_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *)
                         &orasiyaeselbueno_DW.HILInitialize_DOBits[0]
                         , orasiyaeselbueno_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(orasiyaeselbueno_DW.HILInitialize_Card,
            orasiyaeselbueno_P.HILInitialize_AOChannels,
            num_final_analog_outputs,
            &orasiyaeselbueno_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (orasiyaeselbueno_DW.HILInitialize_Card,
             orasiyaeselbueno_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &orasiyaeselbueno_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(orasiyaeselbueno_DW.HILInitialize_Card,
            orasiyaeselbueno_P.HILInitialize_OOChannels, num_final_other_outputs,
            orasiyaeselbueno_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(orasiyaeselbueno_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(orasiyaeselbueno_DW.HILInitialize_Card);
    hil_monitor_delete_all(orasiyaeselbueno_DW.HILInitialize_Card);
    hil_close(orasiyaeselbueno_DW.HILInitialize_Card);
    orasiyaeselbueno_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  orasiyaeselbueno_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  orasiyaeselbueno_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  orasiyaeselbueno_initialize();
}

void MdlTerminate(void)
{
  orasiyaeselbueno_terminate();
}

/* Registration function */
RT_MODEL_orasiyaeselbueno_T *orasiyaeselbueno(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)orasiyaeselbueno_M, 0,
                sizeof(RT_MODEL_orasiyaeselbueno_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&orasiyaeselbueno_M->solverInfo,
                          &orasiyaeselbueno_M->Timing.simTimeStep);
    rtsiSetTPtr(&orasiyaeselbueno_M->solverInfo, &rtmGetTPtr(orasiyaeselbueno_M));
    rtsiSetStepSizePtr(&orasiyaeselbueno_M->solverInfo,
                       &orasiyaeselbueno_M->Timing.stepSize0);
    rtsiSetdXPtr(&orasiyaeselbueno_M->solverInfo, &orasiyaeselbueno_M->derivs);
    rtsiSetContStatesPtr(&orasiyaeselbueno_M->solverInfo, (real_T **)
                         &orasiyaeselbueno_M->contStates);
    rtsiSetNumContStatesPtr(&orasiyaeselbueno_M->solverInfo,
      &orasiyaeselbueno_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&orasiyaeselbueno_M->solverInfo,
      &orasiyaeselbueno_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&orasiyaeselbueno_M->solverInfo,
      &orasiyaeselbueno_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&orasiyaeselbueno_M->solverInfo,
      &orasiyaeselbueno_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&orasiyaeselbueno_M->solverInfo, (boolean_T**)
      &orasiyaeselbueno_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&orasiyaeselbueno_M->solverInfo, (&rtmGetErrorStatus
      (orasiyaeselbueno_M)));
    rtsiSetRTModelPtr(&orasiyaeselbueno_M->solverInfo, orasiyaeselbueno_M);
  }

  rtsiSetSimTimeStep(&orasiyaeselbueno_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&orasiyaeselbueno_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&orasiyaeselbueno_M->solverInfo, false);
  orasiyaeselbueno_M->intgData.f[0] = orasiyaeselbueno_M->odeF[0];
  orasiyaeselbueno_M->contStates = ((real_T *) &orasiyaeselbueno_X);
  orasiyaeselbueno_M->contStateDisabled = ((boolean_T *) &orasiyaeselbueno_XDis);
  orasiyaeselbueno_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&orasiyaeselbueno_M->solverInfo, (void *)
                    &orasiyaeselbueno_M->intgData);
  rtsiSetSolverName(&orasiyaeselbueno_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = orasiyaeselbueno_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    orasiyaeselbueno_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    orasiyaeselbueno_M->Timing.sampleTimes =
      (&orasiyaeselbueno_M->Timing.sampleTimesArray[0]);
    orasiyaeselbueno_M->Timing.offsetTimes =
      (&orasiyaeselbueno_M->Timing.offsetTimesArray[0]);

    /* task periods */
    orasiyaeselbueno_M->Timing.sampleTimes[0] = (0.0);
    orasiyaeselbueno_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    orasiyaeselbueno_M->Timing.offsetTimes[0] = (0.0);
    orasiyaeselbueno_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(orasiyaeselbueno_M, &orasiyaeselbueno_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = orasiyaeselbueno_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    orasiyaeselbueno_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(orasiyaeselbueno_M, -1);
  orasiyaeselbueno_M->Timing.stepSize0 = 0.002;
  orasiyaeselbueno_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(orasiyaeselbueno_M, 1);

  /* External mode info */
  orasiyaeselbueno_M->Sizes.checksums[0] = (4257814037U);
  orasiyaeselbueno_M->Sizes.checksums[1] = (1190263855U);
  orasiyaeselbueno_M->Sizes.checksums[2] = (805073148U);
  orasiyaeselbueno_M->Sizes.checksums[3] = (3823584632U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    orasiyaeselbueno_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &orasiyaeselbueno_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[2] = (sysRanDType *)
      &orasiyaeselbueno_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[3] = (sysRanDType *)
      &orasiyaeselbueno_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[4] = (sysRanDType *)
      &orasiyaeselbueno_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(orasiyaeselbueno_M->extModeInfo,
      &orasiyaeselbueno_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(orasiyaeselbueno_M->extModeInfo,
                        orasiyaeselbueno_M->Sizes.checksums);
    rteiSetTPtr(orasiyaeselbueno_M->extModeInfo, rtmGetTPtr(orasiyaeselbueno_M));
  }

  orasiyaeselbueno_M->solverInfoPtr = (&orasiyaeselbueno_M->solverInfo);
  orasiyaeselbueno_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&orasiyaeselbueno_M->solverInfo, 0.002);
  rtsiSetSolverMode(&orasiyaeselbueno_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  orasiyaeselbueno_M->blockIO = ((void *) &orasiyaeselbueno_B);
  (void) memset(((void *) &orasiyaeselbueno_B), 0,
                sizeof(B_orasiyaeselbueno_T));

  /* parameters */
  orasiyaeselbueno_M->defaultParam = ((real_T *)&orasiyaeselbueno_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &orasiyaeselbueno_X;
    orasiyaeselbueno_M->contStates = (x);
    (void) memset((void *)&orasiyaeselbueno_X, 0,
                  sizeof(X_orasiyaeselbueno_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &orasiyaeselbueno_XDis;
    orasiyaeselbueno_M->contStateDisabled = (xdis);
    (void) memset((void *)&orasiyaeselbueno_XDis, 0,
                  sizeof(XDis_orasiyaeselbueno_T));
  }

  /* states (dwork) */
  orasiyaeselbueno_M->dwork = ((void *) &orasiyaeselbueno_DW);
  (void) memset((void *)&orasiyaeselbueno_DW, 0,
                sizeof(DW_orasiyaeselbueno_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    orasiyaeselbueno_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  orasiyaeselbueno_M->Sizes.numContStates = (14);/* Number of continuous states */
  orasiyaeselbueno_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  orasiyaeselbueno_M->Sizes.numY = (0);/* Number of model outputs */
  orasiyaeselbueno_M->Sizes.numU = (0);/* Number of model inputs */
  orasiyaeselbueno_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  orasiyaeselbueno_M->Sizes.numSampTimes = (2);/* Number of sample times */
  orasiyaeselbueno_M->Sizes.numBlocks = (70);/* Number of blocks */
  orasiyaeselbueno_M->Sizes.numBlockIO = (22);/* Number of block outputs */
  orasiyaeselbueno_M->Sizes.numBlockPrms = (175);/* Sum of parameter "widths" */
  return orasiyaeselbueno_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
