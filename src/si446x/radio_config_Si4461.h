//
//#ifndef RADIO_CONFIG_H_
//#define RADIO_CONFIG_H_
//
////用户定义的参数
////定义自己的参数在这里
//
//
//// 输入数据
//
///*
////%%	Crys_freq(Hz) Crys_tol(ppm) IF_mode High_perf_Ch_Fil  OSRtune Ch_Fil_Bw_AFC ANT_DIV   PM_pattern
////    30000000      10            2       1                 0       0             0         0
////%%	MOD_type	Rsymb(sps)	Fdev(Hz)	RXBW(Hz)	Mancheste	AFC_en	Rsymb_error	Chip-Version
//// 	2	1000	20000	150000	1	0	0.0	2
////%%	RF Freq.(MHz)	API_TC	fhst	inputBW	BERT	RAW_dout	D_source	Hi_pfm_div
//// 	425	29	100000	0	0	0	0	1
////
//// # WB filter 1 (BW =  57.23 kHz);  NB-filter 1 (BW = 57.23 kHz)
//
////
//// Modulation index: 40
//*/
//
//
//// 配置参数
//#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ                     {30000000L}  //
//#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER                    {0x00}       //
//#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH               {0x07}       //
//#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP        {0x03}       //
//#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET       {0xF000}     //
//
//
//// 配置命令
//
///*
//// Command:                  RF_POWER_UP
//
//*/
//#define RF_POWER_UP 0x02, 0x01, 0x00, 0x01, 0xC9, 0xC3, 0x80
//
///*
//// Command:                  RF_GPIO_PIN_CFG
//// Description:              GPIO
//*/
//#define RF_GPIO_PIN_CFG 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
///*
//// Set properties:           RF_GLOBAL_XO_TUNE_1
//*/
//#define RF_GLOBAL_XO_TUNE_1 0x11, 0x00, 0x01, 0x00, 0x52
//
///*
//// Set properties:           RF_GLOBAL_CONFIG_1
//// Number of properties:     1
//// Group ID:                 00
//// Start ID:                 03
//// Default values:           0x20,
//// Descriptions:
////   GLOBAL_CONFIG - Various settings that affect entire chip. If PROTOCOL is specified, the chip is placed into protocol aware state.
//*/
//#define RF_GLOBAL_CONFIG_1 0x11, 0x00, 0x01, 0x03, 0x40
//
///*
//// Set properties:           RF_INT_CTL_ENABLE_4
/// /组编号：01
////开始编号：00
////默认值：0x04，0x00，0x00，0x04，
//
/// /描述:
//
/// / INT_CTL_ENABLE
//
/// / INT_CTL_PH_ENABLE
//
/// / INT_CTL_MODEM_ENABLE
//
/// / INT_CTL_CHIP_ENABLE
//*/
//#define RF_INT_CTL_ENABLE_4 0x11, 0x01, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_FRR_CTL_A_MODE_4
//
/// / FRR_CTL_A_MODE
//
/// / FRR_CTL_B_MODE
//
/// / FRR_CTL_C_MODE
//
/// / FRR_CTL_D_MODE
//*/
//#define RF_FRR_CTL_A_MODE_4 0x11, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_PREAMBLE_TX_LENGTH_9
//
/// / PREAMBLE_TX_LENGTH
//
/// / PREAMBLE_CONFIG_STD_1
//
/// / PREAMBLE_CONFIG_NSTD
//
/// / PREAMBLE_CONFIG_STD_2
//
/// / PREAMBLE_CONFIG
//
/// / PREAMBLE_PATTERN_31_24 - PREAMBLE_PATTERN_XX
//
/// / PREAMBLE_PATTERN_23_16位23
//
/// / PREAMBLE_PATTERN_15_8位15
//
/// / PREAMBLE_PATTERN_7_0
//*/
//#define RF_PREAMBLE_TX_LENGTH_9 0x11, 0x10, 0x09, 0x00, 0x04, 0x94, 0x00, 0x0F, 0x1D, 0x00, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_SYNC_CONFIG_5
//
/// / SYNC_CONFIG
//
/// / SYNC_BITS_31_24
//
/// / SYNC_BITS_23_16
//
/// / SYNC_BITS_15_8
//
/// / SYNC_BITS_7_0
//*/
//#define RF_SYNC_CONFIG_5 0x11, 0x11, 0x05, 0x00, 0x01, 0xB4, 0x2B, 0x00, 0x00
//
///*
//// Set properties:           RF_PKT_CRC_CONFIG_1
//
/// / PKT_CRC_CONFIG
//*/
//#define RF_PKT_CRC_CONFIG_1 0x11, 0x12, 0x01, 0x00, 0x84
//
///*
//// Set properties:           RF_PKT_CONFIG1_1
//// Number of properties:     1
//// Group ID:                 12
//// Start ID:                 06
//// Default values:           0x00,
//// Descriptions:
////   PKT_CONFIG1 - General packet configuration bits.
//*/
//#define RF_PKT_CONFIG1_1 0x11, 0x12, 0x01, 0x06, 0x02
//
///*
//// Set properties:           RF_PKT_LEN_3
//
/// / PKT_LEN (PKT_CONFIG1:PH_RX_DISABLE)
//
/// / PKT_LEN_FIELD_SOURCE
//
/// / PKT_LEN_ADJUST
//*/
//#define RF_PKT_LEN_3 0x11, 0x12, 0x03, 0x08, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_PKT_FIELD_1_LENGTH_7_0_3
//
/// / PKT_FIELD_1_LENGTH_7_0
//
/// / PKT_FIELD_1_CONFIG
//
/// / PKT_FIELD_1_CRC_CONFIG
//*/
//#define RF_PKT_FIELD_1_LENGTH_7_0_3 0x11, 0x12, 0x03, 0x0E, 0x07, 0x04, 0x80
//
///*
//// Set properties:           RF_PKT_FIELD_2_LENGTH_7_0_3
//
/// / PKT_FIELD_2_LENGTH_7_0
//
/// / PKT_FIELD_2_CONFIG
//
/// / PKT_FIELD_2_CRC_CONFIG
//*/
//#define RF_PKT_FIELD_2_LENGTH_7_0_3 0x11, 0x12, 0x03, 0x12, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_PKT_FIELD_3_LENGTH_7_0_3
//
/// / PKT_FIELD_3_LENGTH_7_0
//
/// / PKT_FIELD_3_CONFIG
//
/// / PKT_FIELD_3_CRC_CONFIG
//*/
//#define RF_PKT_FIELD_3_LENGTH_7_0_3 0x11, 0x12, 0x03, 0x16, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_PKT_FIELD_4_LENGTH_7_0_3
//
/// / PKT_FIELD_4_LENGTH_7_0
//
/// / PKT_FIELD_4_CONFIG
//
/// / PKT_FIELD_4_CRC_CONFIG
//*/
//#define RF_PKT_FIELD_4_LENGTH_7_0_3 0x11, 0x12, 0x03, 0x1A, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_PKT_FIELD_5_LENGTH_7_0_3
//
/// / PKT_FIELD_5_LENGTH_7_0
//
/// / PKT_FIELD_5_CONFIG
//
/// / PKT_FIELD_5_CRC_CONFIG
//*/
//#define RF_PKT_FIELD_5_LENGTH_7_0_3 0x11, 0x12, 0x03, 0x1E, 0x00, 0x00, 0x00
//
///*
//// Set properties:           RF_MODEM_MOD_TYPE_12
//
/// / MODEM_MOD_TYPE
// * bit 7    : 0   = direct mode for synchronous mode
// * bit 6 - 5: 00  = TX direct mode uses gpio0 as data source
// * bit 4 - 3: 00  = Modulation source is packet handler fifo
// * bit 2 - 0: 011 = 2GFSK
//
/// / MODEM_MAP_CONTROL
// * bit 7    : 1 = enable manchester coding
// * bit 6    : 0 = Do not invert RX data bits.
// * bit 5    : 0 = Do not invert TX data bits.
// * bit 4    : 0 = frequency deviation's priority from positive to negative
//
/// / MODEM_DSM_CTRL
// *
//
//== three bytes to set the data rate = 0x00_03_E8
/// / MODEM_DATA_RATE_2
/// / MODEM_DATA_RATE_1
/// / MODEM_DATA_RATE_0
//
//
/// / MODEM_TX_NCO_MODE_3
/// / MODEM_TX_NCO_MODE_2
/// / MODEM_TX_NCO_MODE_1
/// / MODEM_TX_NCO_MODE_0
//
//== frequency deviation[23:0]  =  0x00_05 (0x00_05_76)
/// / MODEM_FREQ_DEV_2
/// / MODEM_FREQ_DEV_1
//
//*/
//#define RF_MODEM_MOD_TYPE_12 0x11, 0x20, 0x0C, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xE8, 0x00, 0x2D, 0xC6, 0xC0, 0x00, 0x05
//
///*
//// Set properties:           RF_MODEM_FREQ_DEV_0_1
//
/// / MODEM_FREQ_DEV_0 = 0x76 (0x00_05_76)
//*/
//#define RF_MODEM_FREQ_DEV_0_1 0x11, 0x20, 0x01, 0x0C, 0x76
//
///*
//// Set properties:           RF_MODEM_TX_RAMP_DELAY_8
//
/// / MODEM_TX_RAMP_DELAY
//
/// / MODEM_MDM_CTRL
//
/// / MODEM_IF_CONTROL
//
/// / MODEM_IF_FREQ_2
/// / MODEM_IF_FREQ_1
/// / MODEM_IF_FREQ_0
//
//
/// / MODEM_DECIMATION_CFG1
/// / MODEM_DECIMATION_CFG0
//
//*/
//#define RF_MODEM_TX_RAMP_DELAY_8 0x11, 0x20, 0x08, 0x18, 0x01, 0x80, 0x08, 0x03, 0x80, 0x00, 0x30, 0x20
//
///*
//// Set properties:           RF_MODEM_BCR_OSR_1_9
//
/// / MODEM_BCR_OSR_1
//
/// / MODEM_BCR_OSR_0
//
/// / MODEM_BCR_NCO_OFFSET_2
//
/// / MODEM_BCR_NCO_OFFSET_1
//
/// / MODEM_BCR_NCO_OFFSET_0
//
/// / MODEM_BCR_GAIN_1
//
/// / MODEM_BCR_GAIN_0
//
/// / MODEM_BCR_GEAR
//
/// / MODEM_BCR_MISC1
//*/
//#define RF_MODEM_BCR_OSR_1_9 0x11, 0x20, 0x09, 0x22, 0x07, 0x53, 0x00, 0x45, 0xE8, 0x00, 0x23, 0x02, 0xC2
//
///*
//// Set properties:           RF_MODEM_AFC_GEAR_7
//
/// / MODEM_AFC_GEAR
//
/// / MODEM_AFC_WAIT
//
/// / MODEM_AFC_GAIN_1
//
/// / MODEM_AFC_GAIN_0
//
/// / MODEM_AFC_LIMITER_1
//
/// / MODEM_AFC_LIMITER_0
//
/// / MODEM_AFC_MISC
//*/
//#define RF_MODEM_AFC_GEAR_7 0x11, 0x20, 0x07, 0x2C, 0x04, 0x36, 0x80, 0x03, 0x4D, 0x74, 0x80
//
///*
//// Set properties:           RF_MODEM_AGC_CONTROL_1
//
/// / MODEM_AGC_CONTROL
//*/
//#define RF_MODEM_AGC_CONTROL_1 0x11, 0x20, 0x01, 0x35, 0xE2
//
///*
//// Set properties:           RF_MODEM_AGC_WINDOW_SIZE_9
//
/// / MODEM_AGC_WINDOW_SIZE
//
/// / MODEM_AGC_RFPD_DECAY
//
/// / MODEM_AGC_IFPD_DECAY
//
/// / MODEM_FSK4_GAIN1
//
/// / MODEM_FSK4_GAIN0
//
/// / MODEM_FSK4_TH1
//
/// / MODEM_FSK4_TH0
//
/// / MODEM_FSK4_MAP
//
/// / MODEM_OOK_PDTC
//*/
//#define RF_MODEM_AGC_WINDOW_SIZE_9 0x11, 0x20, 0x09, 0x38, 0x11, 0xFF, 0xFF, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x2B
//
///*
//
/// / MODEM_OOK_CNT1
//
/// / MODEM_OOK_MISC
//
/// / MODEM_RAW_SEARCH
//
/// / MODEM_RAW_CONTROL
//
/// / MODEM_RAW_EYE_1
//
/// / MODEM_RAW_EYE_0
//
/// / MODEM_ANT_DIV_MODE
//
/// / MODEM_ANT_DIV_CONTROL
//*/
//#define RF_MODEM_OOK_CNT1_8 0x11, 0x20, 0x08, 0x42, 0x84, 0x02, 0xD6, 0x83, 0x02, 0xAA, 0x01, 0x80
//
///*
//// Set properties:           RF_MODEM_RSSI_CONTROL_1
//
/// / MODEM_RSSI_CONTROL
//*/
//#define RF_MODEM_RSSI_CONTROL_1 0x11, 0x20, 0x01, 0x4C, 0x00
//
///*
/// /RF_MODEM_RSSI_COMP_1
//
/// / MODEM_RSSI_COMP
//*/
//#define RF_MODEM_RSSI_COMP_1 0x11, 0x20, 0x01, 0x4E, 0x40
//
///*
//// Set properties:           RF_MODEM_CLKGEN_BAND_1
//
/// / MODEM_CLKGEN_BAND
//*/
//#define RF_MODEM_CLKGEN_BAND_1 0x11, 0x20, 0x01, 0x51, 0x0A
//
///*
//// Set properties:           RF_MODEM_CHFLT_RX1_CHFLT_COE13_7_0_12
//
/// / MODEM_CHFLT_RX1_CHFLT_COE13_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE12_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE11_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE10_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE9_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE8_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE7_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE6_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE5_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE4_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE3_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE2_7_0
//*/
//#define RF_MODEM_CHFLT_RX1_CHFLT_COE13_7_0_12 0x11, 0x21, 0x0C, 0x00, 0xFF, 0xBA, 0x0F, 0x51, 0xCF, 0xA9, 0xC9, 0xFC, 0x1B, 0x1E, 0x0F, 0x01
//
///*
//// Set properties:           RF_MODEM_CHFLT_RX1_CHFLT_COE1_7_0_12
// *
/// / MODEM_CHFLT_RX1_CHFLT_COE1_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COE0_7_0
//
/// / MODEM_CHFLT_RX1_CHFLT_COEM0
//
/// / MODEM_CHFLT_RX1_CHFLT_COEM1
//
/// / MODEM_CHFLT_RX1_CHFLT_COEM2
//
/// / MODEM_CHFLT_RX1_CHFLT_COEM3
//
/// / MODEM_CHFLT_RX2_CHFLT_COE13_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE12_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE11_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE10_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE9_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE8_7_0
//*/
//#define RF_MODEM_CHFLT_RX1_CHFLT_COE1_7_0_12 0x11, 0x21, 0x0C, 0x0C, 0xFC, 0xFD, 0x15, 0xFF, 0x00, 0x0F, 0xFF, 0xBA, 0x0F, 0x51, 0xCF, 0xA9
//
///*
//// Set properties:           RF_MODEM_CHFLT_RX2_CHFLT_COE7_7_0_12
//
/// / MODEM_CHFLT_RX2_CHFLT_COE7_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE6_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE5_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE4_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE3_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE2_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE1_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COE0_7_0
//
/// / MODEM_CHFLT_RX2_CHFLT_COEM0
//
/// / MODEM_CHFLT_RX2_CHFLT_COEM1
//
/// / MODEM_CHFLT_RX2_CHFLT_COEM2
//
/// / MODEM_CHFLT_RX2_CHFLT_COEM3
//
//*/
//#define RF_MODEM_CHFLT_RX2_CHFLT_COE7_7_0_12 0x11, 0x21, 0x0C, 0x18, 0xC9, 0xFC, 0x1B, 0x1E, 0x0F, 0x01, 0xFC, 0xFD, 0x15, 0xFF, 0x00, 0x0F
//
///*
//// Set properties:           RF_PA_MODE_4
//
/// / PA_MODE
//
/// / PA_PWR_LVL
//
/// / PA_BIAS_CLKDUTY -
//
/// / PA_TC
//*/
//#define RF_PA_MODE_4 0x11, 0x22, 0x04, 0x00, 0x08, 0x7F, 0x00, 0x3D
//
///*
//// Set properties:           RF_SYNTH_PFDCP_CPFF_7
//
/// / SYNTH_PFDCP_CPFF
//
/// / SYNTH_PFDCP_CPINT
//
/// / SYNTH_VCO_KV
//
/// / SYNTH_LPFILT3
//
/// / SYNTH_LPFILT2
//
/// / SYNTH_LPFILT1
//
/// / SYNTH_LPFILT0
//*/
//#define RF_SYNTH_PFDCP_CPFF_7 0x11, 0x23, 0x07, 0x00, 0x2C, 0x0E, 0x0B, 0x04, 0x0C, 0x73, 0x03
//
///*
//// Set properties:           RF_FREQ_CONTROL_INTE_8
//
/// / FREQ_CONTROL_INTE Fractional
//
/// / FREQ_CONTROL_FRAC_2
//
/// / FREQ_CONTROL_FRAC_1
//
/// / FREQ_CONTROL_FRAC_0
//
/// / FREQ_CONTROL_CHANNEL_STEP_SIZE_1
//
/// / FREQ_CONTROL_CHANNEL_STEP_SIZE_0
//
/// / FREQ_CONTROL_W_SIZE
//
/// / FREQ_CONTROL_VCOCNT_RX_ADJ
//*/
//#define RF_FREQ_CONTROL_INTE_8 0x11, 0x40, 0x08, 0x00, 0x37, 0x0D, 0x55, 0x55, 0x1B, 0x4F, 0x20, 0xFE
//
//
//// DO NOT EDIT/MODIFY BELOW THIS LINE!
//
//// --------------------------------------------
//
//#ifndef FIRMWARE_LOAD_COMPILE
//#define RADIO_CONFIGURATION_DATA_ARRAY { \
//        0x07, RF_POWER_UP, \
//        0x08, RF_GPIO_PIN_CFG, \
//        0x05, RF_GLOBAL_XO_TUNE_1, \
//        0x05, RF_GLOBAL_CONFIG_1, \
//        0x08, RF_INT_CTL_ENABLE_4, \
//        0x08, RF_FRR_CTL_A_MODE_4, \
//        0x0D, RF_PREAMBLE_TX_LENGTH_9, \
//        0x09, RF_SYNC_CONFIG_5, \
//        0x05, RF_PKT_CRC_CONFIG_1, \
//        0x05, RF_PKT_CONFIG1_1, \
//        0x07, RF_PKT_LEN_3, \
//        0x07, RF_PKT_FIELD_1_LENGTH_7_0_3, \
//        0x07, RF_PKT_FIELD_2_LENGTH_7_0_3, \
//        0x07, RF_PKT_FIELD_3_LENGTH_7_0_3, \
//        0x07, RF_PKT_FIELD_4_LENGTH_7_0_3, \
//        0x07, RF_PKT_FIELD_5_LENGTH_7_0_3, \
//        0x10, RF_MODEM_MOD_TYPE_12, \
//        0x05, RF_MODEM_FREQ_DEV_0_1, \
//        0x0C, RF_MODEM_TX_RAMP_DELAY_8, \
//        0x0D, RF_MODEM_BCR_OSR_1_9, \
//        0x0B, RF_MODEM_AFC_GEAR_7, \
//        0x05, RF_MODEM_AGC_CONTROL_1, \
//        0x0D, RF_MODEM_AGC_WINDOW_SIZE_9, \
//        0x0C, RF_MODEM_OOK_CNT1_8, \
//        0x05, RF_MODEM_RSSI_CONTROL_1, \
//        0x05, RF_MODEM_RSSI_COMP_1, \
//        0x05, RF_MODEM_CLKGEN_BAND_1, \
//        0x10, RF_MODEM_CHFLT_RX1_CHFLT_COE13_7_0_12, \
//        0x10, RF_MODEM_CHFLT_RX1_CHFLT_COE1_7_0_12, \
//        0x10, RF_MODEM_CHFLT_RX2_CHFLT_COE7_7_0_12, \
//        0x08, RF_PA_MODE_4, \
//        0x0B, RF_SYNTH_PFDCP_CPFF_7, \
//        0x0C, RF_FREQ_CONTROL_INTE_8, \
//        0x00 \
// }
//#else
//#define RADIO_CONFIGURATION_DATA_ARRAY { 0 }
//#endif
//
//// 配置参数的默认值
//#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ_DEFAULT                     30000000L
//#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER_DEFAULT                    0x00
//#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH_DEFAULT               0x10
//#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP_DEFAULT        0x01
//#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET_DEFAULT       0x1000
//
//#define RADIO_CONFIGURATION_DATA_RADIO_PATCH_INCLUDED                      0x00
//#define RADIO_CONFIGURATION_DATA_RADIO_PATCH_SIZE                          0x00
//#define RADIO_CONFIGURATION_DATA_RADIO_PATCH                               {  }
//
//#ifndef RADIO_CONFIGURATION_DATA_ARRAY
//#error "This property must be defined!"
//#endif
//
//#ifndef RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ
//#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ         { RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ_DEFAULT }
//#endif
//
//#ifndef RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER
//#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER        { RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER_DEFAULT }
//#endif
//
//#ifndef RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH
//#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH   { RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH_DEFAULT }
//#endif
//
//#ifndef RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP
//#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP  { RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP_DEFAULT }
//#endif
//
//#ifndef RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET
//#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET { RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET_DEFAULT }
//#endif
//
//#define RADIO_CONFIGURATION_DATA { \
//                            Radio_Configuration_Data_Array,                            \
//                            RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER,                   \
//                            RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH,              \
//                            RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP,       \
//                            RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET       \
//                            }
//
//
//#endif /* RADIO_CONFIG_H_ */
