    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (orasiyaeselbueno_P)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.A_modelo
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_P.B_modelo
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 16;

                    ;% orasiyaeselbueno_P.C
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 24;

                    ;% orasiyaeselbueno_P.K_lqr
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 32;

                    ;% orasiyaeselbueno_P.beta
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 40;

                    ;% orasiyaeselbueno_P.l
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 41;

                    ;% orasiyaeselbueno_P.m
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 42;

                    ;% orasiyaeselbueno_P.Green_color
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 43;

                    ;% orasiyaeselbueno_P.Yellow_color
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 46;

                    ;% orasiyaeselbueno_P.PitchBiasRemoval_end_time
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 49;

                    ;% orasiyaeselbueno_P.GenerateCurrentStateX_input_wid
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 50;

                    ;% orasiyaeselbueno_P.GenerateCurrentStateX_input_zet
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 51;

                    ;% orasiyaeselbueno_P.PitchBiasRemoval_start_time
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 52;

                    ;% orasiyaeselbueno_P.PitchBiasRemoval_switch_id
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 53;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.HILWrite_analog_channels
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_P.HILWrite_other_channels
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 43;
            section.data(43)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.x_avg_n_Y0
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_P.unity_Value
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_P.UnitDelay_InitialCondition
                    section.data(3).logicalSrcIdx = 18;
                    section.data(3).dtTransOffset = 2;

                    ;% orasiyaeselbueno_P.Sumk1n1xk_InitialCondition
                    section.data(4).logicalSrcIdx = 19;
                    section.data(4).dtTransOffset = 3;

                    ;% orasiyaeselbueno_P.zero_Y0
                    section.data(5).logicalSrcIdx = 20;
                    section.data(5).dtTransOffset = 4;

                    ;% orasiyaeselbueno_P.Vbiased_Y0
                    section.data(6).logicalSrcIdx = 21;
                    section.data(6).dtTransOffset = 5;

                    ;% orasiyaeselbueno_P.Vunbiased_Y0
                    section.data(7).logicalSrcIdx = 22;
                    section.data(7).dtTransOffset = 6;

                    ;% orasiyaeselbueno_P.Stepstart_time_Y0
                    section.data(8).logicalSrcIdx = 23;
                    section.data(8).dtTransOffset = 7;

                    ;% orasiyaeselbueno_P.Stepstart_time_YFinal
                    section.data(9).logicalSrcIdx = 24;
                    section.data(9).dtTransOffset = 8;

                    ;% orasiyaeselbueno_P.Stepend_time_Y0
                    section.data(10).logicalSrcIdx = 25;
                    section.data(10).dtTransOffset = 9;

                    ;% orasiyaeselbueno_P.Stepend_time_YFinal
                    section.data(11).logicalSrcIdx = 26;
                    section.data(11).dtTransOffset = 10;

                    ;% orasiyaeselbueno_P.HILInitialize_OOTerminate
                    section.data(12).logicalSrcIdx = 27;
                    section.data(12).dtTransOffset = 11;

                    ;% orasiyaeselbueno_P.HILInitialize_OOExit
                    section.data(13).logicalSrcIdx = 28;
                    section.data(13).dtTransOffset = 12;

                    ;% orasiyaeselbueno_P.HILInitialize_OOStart
                    section.data(14).logicalSrcIdx = 29;
                    section.data(14).dtTransOffset = 13;

                    ;% orasiyaeselbueno_P.HILInitialize_OOEnter
                    section.data(15).logicalSrcIdx = 30;
                    section.data(15).dtTransOffset = 14;

                    ;% orasiyaeselbueno_P.HILInitialize_AOFinal
                    section.data(16).logicalSrcIdx = 31;
                    section.data(16).dtTransOffset = 15;

                    ;% orasiyaeselbueno_P.HILInitialize_OOFinal
                    section.data(17).logicalSrcIdx = 32;
                    section.data(17).dtTransOffset = 16;

                    ;% orasiyaeselbueno_P.HILInitialize_AIHigh
                    section.data(18).logicalSrcIdx = 33;
                    section.data(18).dtTransOffset = 19;

                    ;% orasiyaeselbueno_P.HILInitialize_AILow
                    section.data(19).logicalSrcIdx = 34;
                    section.data(19).dtTransOffset = 20;

                    ;% orasiyaeselbueno_P.HILInitialize_AOHigh
                    section.data(20).logicalSrcIdx = 35;
                    section.data(20).dtTransOffset = 21;

                    ;% orasiyaeselbueno_P.HILInitialize_AOLow
                    section.data(21).logicalSrcIdx = 36;
                    section.data(21).dtTransOffset = 22;

                    ;% orasiyaeselbueno_P.HILInitialize_AOInitial
                    section.data(22).logicalSrcIdx = 37;
                    section.data(22).dtTransOffset = 23;

                    ;% orasiyaeselbueno_P.HILInitialize_AOWatchdog
                    section.data(23).logicalSrcIdx = 38;
                    section.data(23).dtTransOffset = 24;

                    ;% orasiyaeselbueno_P.HILInitialize_OOInitial
                    section.data(24).logicalSrcIdx = 39;
                    section.data(24).dtTransOffset = 25;

                    ;% orasiyaeselbueno_P.HILInitialize_OOWatchdog
                    section.data(25).logicalSrcIdx = 40;
                    section.data(25).dtTransOffset = 28;

                    ;% orasiyaeselbueno_P.PitchConstant_Value
                    section.data(26).logicalSrcIdx = 41;
                    section.data(26).dtTransOffset = 31;

                    ;% orasiyaeselbueno_P.Constant_Value
                    section.data(27).logicalSrcIdx = 42;
                    section.data(27).dtTransOffset = 32;

                    ;% orasiyaeselbueno_P.YawRotationAmplituderads_Gain
                    section.data(28).logicalSrcIdx = 43;
                    section.data(28).dtTransOffset = 33;

                    ;% orasiyaeselbueno_P.Zerospeedsetpoint_Value
                    section.data(29).logicalSrcIdx = 44;
                    section.data(29).dtTransOffset = 34;

                    ;% orasiyaeselbueno_P.x0_Value
                    section.data(30).logicalSrcIdx = 45;
                    section.data(30).dtTransOffset = 35;

                    ;% orasiyaeselbueno_P.Integrator2_IC
                    section.data(31).logicalSrcIdx = 46;
                    section.data(31).dtTransOffset = 36;

                    ;% orasiyaeselbueno_P.u4V_UpperSat
                    section.data(32).logicalSrcIdx = 47;
                    section.data(32).dtTransOffset = 37;

                    ;% orasiyaeselbueno_P.u4V_LowerSat
                    section.data(33).logicalSrcIdx = 48;
                    section.data(33).dtTransOffset = 38;

                    ;% orasiyaeselbueno_P.NoControl_Value
                    section.data(34).logicalSrcIdx = 49;
                    section.data(34).dtTransOffset = 39;

                    ;% orasiyaeselbueno_P.MotorEnable_Threshold
                    section.data(35).logicalSrcIdx = 50;
                    section.data(35).dtTransOffset = 41;

                    ;% orasiyaeselbueno_P.LEDColour_Threshold
                    section.data(36).logicalSrcIdx = 51;
                    section.data(36).dtTransOffset = 42;

                    ;% orasiyaeselbueno_P.Countsstoradss_Gain
                    section.data(37).logicalSrcIdx = 52;
                    section.data(37).dtTransOffset = 43;

                    ;% orasiyaeselbueno_P.StateSpace_InitialCondition
                    section.data(38).logicalSrcIdx = 53;
                    section.data(38).dtTransOffset = 44;

                    ;% orasiyaeselbueno_P.Integrator1_IC
                    section.data(39).logicalSrcIdx = 54;
                    section.data(39).dtTransOffset = 45;

                    ;% orasiyaeselbueno_P.Countstorads_Gain
                    section.data(40).logicalSrcIdx = 55;
                    section.data(40).dtTransOffset = 46;

                    ;% orasiyaeselbueno_P.Constant_Value_h
                    section.data(41).logicalSrcIdx = 56;
                    section.data(41).dtTransOffset = 48;

                    ;% orasiyaeselbueno_P.Integrator_IC
                    section.data(42).logicalSrcIdx = 57;
                    section.data(42).dtTransOffset = 49;

                    ;% orasiyaeselbueno_P.Integrator2_IC_o
                    section.data(43).logicalSrcIdx = 58;
                    section.data(43).dtTransOffset = 50;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 2;

                    ;% orasiyaeselbueno_P.HILReadTimebase_Clock
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 63;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 64;
                    section.data(2).dtTransOffset = 2;

                    ;% orasiyaeselbueno_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 65;
                    section.data(3).dtTransOffset = 4;

                    ;% orasiyaeselbueno_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 66;
                    section.data(4).dtTransOffset = 6;

                    ;% orasiyaeselbueno_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 67;
                    section.data(5).dtTransOffset = 10;

                    ;% orasiyaeselbueno_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 68;
                    section.data(6).dtTransOffset = 11;

                    ;% orasiyaeselbueno_P.HILReadTimebase_SamplesInBuffer
                    section.data(7).logicalSrcIdx = 69;
                    section.data(7).dtTransOffset = 14;

                    ;% orasiyaeselbueno_P.HILReadTimebase_AnalogChannels
                    section.data(8).logicalSrcIdx = 70;
                    section.data(8).dtTransOffset = 15;

                    ;% orasiyaeselbueno_P.HILReadTimebase_EncoderChannels
                    section.data(9).logicalSrcIdx = 71;
                    section.data(9).dtTransOffset = 17;

                    ;% orasiyaeselbueno_P.HILReadTimebase_OtherChannels
                    section.data(10).logicalSrcIdx = 72;
                    section.data(10).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 74;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 75;
                    section.data(3).dtTransOffset = 2;

                    ;% orasiyaeselbueno_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 76;
                    section.data(4).dtTransOffset = 3;

                    ;% orasiyaeselbueno_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 77;
                    section.data(5).dtTransOffset = 4;

                    ;% orasiyaeselbueno_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 78;
                    section.data(6).dtTransOffset = 5;

                    ;% orasiyaeselbueno_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 79;
                    section.data(7).dtTransOffset = 6;

                    ;% orasiyaeselbueno_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 80;
                    section.data(8).dtTransOffset = 7;

                    ;% orasiyaeselbueno_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 81;
                    section.data(9).dtTransOffset = 8;

                    ;% orasiyaeselbueno_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 82;
                    section.data(10).dtTransOffset = 9;

                    ;% orasiyaeselbueno_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 83;
                    section.data(11).dtTransOffset = 10;

                    ;% orasiyaeselbueno_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 84;
                    section.data(12).dtTransOffset = 11;

                    ;% orasiyaeselbueno_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 85;
                    section.data(13).dtTransOffset = 12;

                    ;% orasiyaeselbueno_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 86;
                    section.data(14).dtTransOffset = 13;

                    ;% orasiyaeselbueno_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 87;
                    section.data(15).dtTransOffset = 14;

                    ;% orasiyaeselbueno_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 88;
                    section.data(16).dtTransOffset = 15;

                    ;% orasiyaeselbueno_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 89;
                    section.data(17).dtTransOffset = 16;

                    ;% orasiyaeselbueno_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 90;
                    section.data(18).dtTransOffset = 17;

                    ;% orasiyaeselbueno_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 91;
                    section.data(19).dtTransOffset = 18;

                    ;% orasiyaeselbueno_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 92;
                    section.data(20).dtTransOffset = 19;

                    ;% orasiyaeselbueno_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 93;
                    section.data(21).dtTransOffset = 20;

                    ;% orasiyaeselbueno_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 94;
                    section.data(22).dtTransOffset = 21;

                    ;% orasiyaeselbueno_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 95;
                    section.data(23).dtTransOffset = 22;

                    ;% orasiyaeselbueno_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 96;
                    section.data(24).dtTransOffset = 23;

                    ;% orasiyaeselbueno_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 97;
                    section.data(25).dtTransOffset = 24;

                    ;% orasiyaeselbueno_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 98;
                    section.data(26).dtTransOffset = 25;

                    ;% orasiyaeselbueno_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 99;
                    section.data(27).dtTransOffset = 26;

                    ;% orasiyaeselbueno_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 100;
                    section.data(28).dtTransOffset = 27;

                    ;% orasiyaeselbueno_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 101;
                    section.data(29).dtTransOffset = 28;

                    ;% orasiyaeselbueno_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 102;
                    section.data(30).dtTransOffset = 29;

                    ;% orasiyaeselbueno_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 103;
                    section.data(31).dtTransOffset = 30;

                    ;% orasiyaeselbueno_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 104;
                    section.data(32).dtTransOffset = 31;

                    ;% orasiyaeselbueno_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 105;
                    section.data(33).dtTransOffset = 32;

                    ;% orasiyaeselbueno_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 106;
                    section.data(34).dtTransOffset = 33;

                    ;% orasiyaeselbueno_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 107;
                    section.data(35).dtTransOffset = 34;

                    ;% orasiyaeselbueno_P.HILReadTimebase_Active
                    section.data(36).logicalSrcIdx = 108;
                    section.data(36).dtTransOffset = 35;

                    ;% orasiyaeselbueno_P.HILWrite_Active
                    section.data(37).logicalSrcIdx = 109;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% orasiyaeselbueno_P.HILReadTimebase_OverflowMode
                    section.data(1).logicalSrcIdx = 110;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (orasiyaeselbueno_B)
        ;%
            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% orasiyaeselbueno_B.HILReadTimebase_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_B.Sum1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% orasiyaeselbueno_B.YawRotationAmplituderads
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% orasiyaeselbueno_B.x0
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% orasiyaeselbueno_B.Integrator1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% orasiyaeselbueno_B.Product1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% orasiyaeselbueno_B.Sum
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% orasiyaeselbueno_B.u4V
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% orasiyaeselbueno_B.MotorEnable
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 15;

                    ;% orasiyaeselbueno_B.Countsstoradss
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 17;

                    ;% orasiyaeselbueno_B.StateSpace
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 19;

                    ;% orasiyaeselbueno_B.Integrator1_k
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 21;

                    ;% orasiyaeselbueno_B.Countstorads
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 23;

                    ;% orasiyaeselbueno_B.Product
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 25;

                    ;% orasiyaeselbueno_B.Integrator
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 27;

                    ;% orasiyaeselbueno_B.Sum3
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 29;

                    ;% orasiyaeselbueno_B.Sum4
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 31;

                    ;% orasiyaeselbueno_B.Stepend_time
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 33;

                    ;% orasiyaeselbueno_B.Count
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 34;

                    ;% orasiyaeselbueno_B.Sum_p
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 35;

                    ;% orasiyaeselbueno_B.div
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (orasiyaeselbueno_DW)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_DW.Sumk1n1xk_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_DW.HILInitialize_AIMinimums
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% orasiyaeselbueno_DW.HILInitialize_AIMaximums
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% orasiyaeselbueno_DW.HILInitialize_AOMinimums
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% orasiyaeselbueno_DW.HILInitialize_AOMaximums
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% orasiyaeselbueno_DW.HILInitialize_AOVoltages
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% orasiyaeselbueno_DW.HILInitialize_FilterFrequency
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.HILReadTimebase_Task
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.HILWrite_PWORK
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_DW.MotorCurrentsA_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_DW.MotorSpeedsradss_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% orasiyaeselbueno_DW.Scope_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% orasiyaeselbueno_DW.Scope1_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 5;

                    ;% orasiyaeselbueno_DW.Scope2_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 7;

                    ;% orasiyaeselbueno_DW.Scope3_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 8;

                    ;% orasiyaeselbueno_DW.Scope4_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 17;
                    section.data(8).dtTransOffset = 12;

                    ;% orasiyaeselbueno_DW.Scope5_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 18;
                    section.data(9).dtTransOffset = 14;

                    ;% orasiyaeselbueno_DW.YawPositionrads_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 19;
                    section.data(10).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 3;

                    ;% orasiyaeselbueno_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 7;

                    ;% orasiyaeselbueno_DW.HILReadTimebase_EncoderBuffer
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.SwitchCase_ActiveSubsystem
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_DW.SwitchCaseActionSubsystem2_Subs
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% orasiyaeselbueno_DW.SwitchCaseActionSubsystem1_Subs
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% orasiyaeselbueno_DW.SwitchCaseActionSubsystem_Subsy
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 3;

                    ;% orasiyaeselbueno_DW.EnabledMovingAverage_SubsysRanB
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% orasiyaeselbueno_DW.HILInitialize_DOBits
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% orasiyaeselbueno_DW.Integrator1_DWORK1
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 2;

                    ;% orasiyaeselbueno_DW.EnabledMovingAverage_MODE
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4257814037;
    targMap.checksum1 = 1190263855;
    targMap.checksum2 = 805073148;
    targMap.checksum3 = 3823584632;

