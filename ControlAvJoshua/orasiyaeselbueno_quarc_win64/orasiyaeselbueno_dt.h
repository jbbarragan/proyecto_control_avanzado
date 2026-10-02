/*
 * orasiyaeselbueno_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(t_task),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "t_task",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&orasiyaeselbueno_B.HILReadTimebase_o1[0]), 0, 0, 37 }
  ,

  { (char_T *)(&orasiyaeselbueno_DW.UnitDelay_DSTATE), 0, 0, 16 },

  { (char_T *)(&orasiyaeselbueno_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&orasiyaeselbueno_DW.HILReadTimebase_Task), 16, 0, 1 },

  { (char_T *)(&orasiyaeselbueno_DW.HILWrite_PWORK), 11, 0, 17 },

  { (char_T *)(&orasiyaeselbueno_DW.HILInitialize_ClockModes), 6, 0, 13 },

  { (char_T *)(&orasiyaeselbueno_DW.SwitchCase_ActiveSubsystem), 2, 0, 5 },

  { (char_T *)(&orasiyaeselbueno_DW.HILInitialize_DOBits[0]), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&orasiyaeselbueno_P.A_modelo[0]), 0, 0, 54 },

  { (char_T *)(&orasiyaeselbueno_P.HILWrite_analog_channels[0]), 7, 0, 5 },

  { (char_T *)(&orasiyaeselbueno_P.x_avg_n_Y0), 0, 0, 51 },

  { (char_T *)(&orasiyaeselbueno_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&orasiyaeselbueno_P.HILInitialize_AIChannels[0]), 7, 0, 23 },

  { (char_T *)(&orasiyaeselbueno_P.HILInitialize_Active), 8, 0, 37 },

  { (char_T *)(&orasiyaeselbueno_P.HILReadTimebase_OverflowMode), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] orasiyaeselbueno_dt.h */
