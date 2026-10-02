/*
 * orasiyaeselbueno_data.c
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

/* Block parameters (default storage) */
P_orasiyaeselbueno_T orasiyaeselbueno_P = {
  /* Variable: A_modelo
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 0.0, -0.56062272247019, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    -0.11471203398236195, 0.0, 0.0, 1.0, 0.0, -0.073497295299532986 },

  /* Variable: B_modelo
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 0.0, 0.023321857817452614, -0.016524732889829655, 0.0, 0.0,
    0.010758380231580308, 0.0401515850216712 },

  /* Variable: C
   * Referenced by: '<Root>/State-Space'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: K_lqr
   * Referenced by: '<Root>/LQR Gains'
   */
  { 73.70854194312966, 32.402950256807159, -25.158694691748302,
    58.026201679994436, 68.951322100658828, 29.154838008357078,
    -21.2237560538525, 47.825758941894087 },

  /* Variable: beta
   * Referenced by: '<S5>/beta'
   */
  300.0,

  /* Variable: l
   * Referenced by: '<S5>/l'
   */
  30000.0,

  /* Variable: m
   * Referenced by: '<S5>/m'
   */
  -8.0E+6,

  /* Mask Parameter: Green_color
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 1.0, 0.0 },

  /* Mask Parameter: Yellow_color
   * Referenced by: '<S4>/Constant'
   */
  { 1.0, 1.0, 0.0 },

  /* Mask Parameter: PitchBiasRemoval_end_time
   * Referenced by: '<S3>/Step: end_time'
   */
  1.0,

  /* Mask Parameter: GenerateCurrentStateX_input_wid
   * Referenced by: '<S1>/wn'
   */
  50.0,

  /* Mask Parameter: GenerateCurrentStateX_input_zet
   * Referenced by: '<S1>/zt'
   */
  0.8,

  /* Mask Parameter: PitchBiasRemoval_start_time
   * Referenced by: '<S3>/Step: start_time'
   */
  0.0,

  /* Mask Parameter: PitchBiasRemoval_switch_id
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<Root>/HIL Write'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<Root>/HIL Write'
   */
  { 11000U, 11001U, 11002U },

  /* Computed Parameter: x_avg_n_Y0
   * Referenced by: '<S6>/x_avg_n'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/unity'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Sum( k=1,n-1, x(k) )'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S7>/zero'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S8>/Vbiased'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S9>/Vunbiased'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step: start_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Step: start_time'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step: end_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Step: end_time'
   */
  1.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  3.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -3.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  24.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -24.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Pitch Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: pi/4
   * Referenced by: '<Root>/Yaw Rotation Amplitude (rads)'
   */
  0.78539816339744828,

  /* Expression: 0
   * Referenced by: '<Root>/Zero speed  setpoint'
   */
  0.0,

  /* Expression: input_init
   * Referenced by: '<S1>/x0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator2'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<Root>/+//- 24V'
   */
  24.0,

  /* Expression: -24
   * Referenced by: '<Root>/+//- 24V'
   */
  -24.0,

  /* Expression: [0 0]
   * Referenced by: '<Root>/No Control'
   */
  { 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Motor Enable'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/LED Colour'
   */
  0.0,

  /* Expression: 2*pi/2048
   * Referenced by: '<Root>/Counts//s to rads//s'
   */
  0.0030679615757712823,

  /* Expression: 0
   * Referenced by: '<Root>/State-Space'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator1'
   */
  0.0,

  /* Expression: [2*pi/2048 2*pi/4096]
   * Referenced by: '<Root>/Counts to rads'
   */
  { 0.0030679615757712823, 0.0015339807878856412 },

  /* Expression: 2
   * Referenced by: '<S1>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator2'
   */
  0.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILReadTimebase_Clock
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 11000U, 11001U, 11002U },

  /* Computed Parameter: HILReadTimebase_SamplesInBuffer
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  500U,

  /* Computed Parameter: HILReadTimebase_AnalogChannels
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  { 0U, 1U },

  /* Computed Parameter: HILReadTimebase_EncoderChannels
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  { 2U, 3U },

  /* Computed Parameter: HILReadTimebase_OtherChannels
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  { 4000U, 4002U, 14000U, 14001U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadTimebase_Active
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<Root>/HIL Write'
   */
  false,

  /* Computed Parameter: HILReadTimebase_OverflowMode
   * Referenced by: '<Root>/HIL Read Timebase'
   */
  1U
};
