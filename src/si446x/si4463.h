/*
 * si4463.h
 *
 *  Created on: 6 Apr 2015
 *      Author: KFRL/SM
 */

#ifndef SI4463_H_
#define SI4463_H_

#include "port.h"

#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ                     {30000000L}  //
#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER                    {0x00}       //
#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH               {0x07}       //
#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP        {0x03}       //
#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET       {0xF000}     //

#define RF_POWER_UP             0x02, 0x01, 0x00, 0x01, 0xC9, 0xC3, 0x80
#define RF_GPIO_PIN_CFG         0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#define RF_GLOBAL_XO_TUNE_1     0x11, 0x00, 0x01, 0x00, 0x52
#define RF_GLOBAL_CONFIG_1      0x11, 0x00, 0x01, 0x03, 0x40
#define RF_INT_CTL_ENABLE_4     0x11, 0x01, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00
#define RF_FRR_CTL_A_MODE_4     0x11, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00
#define RF_PREAMBLE_TX_LENGTH_9 0x11, 0x10, 0x09, 0x00, 0x04, 0x94, 0x00, 0x0F, 0x1D, 0x00, 0x00, 0x00, 0x00
#define RF_SYNC_CONFIG_5 0x11,  0x11, 0x05, 0x00, 0x01, 0xB4, 0x2B, 0x00, 0x00
#define RF_PKT_CRC_CONFIG_1     0x11, 0x12, 0x01, 0x00, 0x84
#define RF_PKT_CONFIG1_1        0x11, 0x12, 0x01, 0x06, 0x02
#define RF_PKT_LEN_3            0x11, 0x12, 0x03, 0x08, 0x00, 0x00, 0x00

#define RF_PKT_FIELD_1_LENGTH_7_0_3       0x11, 0x12, 0x03, 0x0E, 0x07, 0x04, 0x80
#define RF_PKT_FIELD_2_LENGTH_7_0_3       0x11, 0x12, 0x03, 0x12, 0x00, 0x00, 0x00
#define RF_PKT_FIELD_3_LENGTH_7_0_3       0x11, 0x12, 0x03, 0x16, 0x00, 0x00, 0x00
#define RF_PKT_FIELD_4_LENGTH_7_0_3       0x11, 0x12, 0x03, 0x1A, 0x00, 0x00, 0x00
#define RF_PKT_FIELD_5_LENGTH_7_0_3       0x11, 0x12, 0x03, 0x1E, 0x00, 0x00, 0x00

#define RF_MODEM_MOD_TYPE_12              0x11, 0x20, 0x0C, 0x00, 0x02, 0x80, 0x07, 0x00, 0x03, 0xE8, 0x00, 0x2D, 0xC6, 0xC0, 0x00, 0x05
#define RF_MODEM_FREQ_DEV_0_1             0x11, 0x20, 0x01, 0x0C, 0x76
#define RF_MODEM_TX_RAMP_DELAY_8          0x11, 0x20, 0x08, 0x18, 0x01, 0x80, 0x08, 0x03, 0x80, 0x00, 0x30, 0x20
#define RF_MODEM_BCR_OSR_1_9              0x11, 0x20, 0x09, 0x22, 0x07, 0x53, 0x00, 0x45, 0xE8, 0x00, 0x23, 0x02, 0xC2
#define RF_MODEM_AFC_GEAR_7               0x11, 0x20, 0x07, 0x2C, 0x04, 0x36, 0x80, 0x03, 0x4D, 0x74, 0x80
#define RF_MODEM_AGC_CONTROL_1            0x11, 0x20, 0x01, 0x35, 0xE2
#define RF_MODEM_AGC_WINDOW_SIZE_9        0x11, 0x20, 0x09, 0x38, 0x11, 0xFF, 0xFF, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x2B
#define RF_MODEM_OOK_CNT1_8               0x11, 0x20, 0x08, 0x42, 0x84, 0x02, 0xD6, 0x83, 0x02, 0xAA, 0x01, 0x80
#define RF_MODEM_RSSI_CONTROL_1           0x11, 0x20, 0x01, 0x4C, 0x00
#define RF_MODEM_RSSI_COMP_1              0x11, 0x20, 0x01, 0x4E, 0x40
#define RF_MODEM_CLKGEN_BAND_1            0x11, 0x20, 0x01, 0x51, 0x0A

#define RF_MODEM_CHFLT_RX1_CHFLT_COE13_7_0_12 0x11, 0x21, 0x0C, 0x00, 0xFF, 0xBA, 0x0F, 0x51, 0xCF, 0xA9, 0xC9, 0xFC, 0x1B, 0x1E, 0x0F, 0x01
#define RF_MODEM_CHFLT_RX1_CHFLT_COE1_7_0_12 0x11, 0x21, 0x0C, 0x0C, 0xFC, 0xFD, 0x15, 0xFF, 0x00, 0x0F, 0xFF, 0xBA, 0x0F, 0x51, 0xCF, 0xA9
#define RF_MODEM_CHFLT_RX2_CHFLT_COE7_7_0_12 0x11, 0x21, 0x0C, 0x18, 0xC9, 0xFC, 0x1B, 0x1E, 0x0F, 0x01, 0xFC, 0xFD, 0x15, 0xFF, 0x00, 0x0F
#define RF_PA_MODE_4 0x11, 0x22, 0x04, 0x00, 0x08, 0x7F, 0x00, 0x3D
#define RF_SYNTH_PFDCP_CPFF_7 0x11, 0x23, 0x07, 0x00, 0x2C, 0x0E, 0x0B, 0x04, 0x0C, 0x73, 0x03
#define RF_FREQ_CONTROL_INTE_8 0x11, 0x40, 0x08, 0x00, 0x37, 0x0D, 0x55, 0x55, 0x1B, 0x4F, 0x20, 0xFE

#define RF_NOP 					0x00
#define RF_PART_INFO            0x01 // 9
#define RF_FUNC_INFO            0x10 // 7
#define RF_SET_PROPERTY         0x11
#define RF_GET_PROPERTY         0x12
#define RF_GPIO_PIN_CFG         0x13    // 8
#define RF_GET_ADC_READING      0x14
#define RF_FIFO_INFO            0x15    // 3
#define RF_PACKET_INFO          0x16    // 3
#define RF_IRCAL                0x17
#define RF_PROTOCOL_CFG         0x18
#define RF_GET_INT_STATUS       0x20    // 9
#define RF_GET_PH_STATUS        0x21    // 3
#define RF_GET_MODEM_STATUS     0x22    // 9
#define RF_GET_CHIP_STATUS      0x23     // 4
#define RF_START_TX             0x31
#define RF_START_RX             0x32
#define RF_REQUEST_DEVICE_STAT  0x33   // 3
#define RF_CHANGE_STATE         0x34
#define RF_READ_CMD_BUFF        0x44
#define RF_FRR_A_READ           0x50   // 4
#define RF_FRR_B_READ           0x51
#define RF_FRR_C_READ           0x53
#define RF_FRR_D_READ           0x57
#define RF_WRITE_TX_FIFO        0x66
#define RF_READ_RX_FIFO         0x77
#define RF_START_MFSK           0x35
#define RF_RX_HOP               0x36


#define payload_length  	14      //payload length = 4 (header) + 10 (payload)
#define step_500K_step1		0x88    // register setting for frequency 500KHz step
#define step_500K_step0		0x89	// register setting for frequency 500KHz step

#define FRR_CTL_A_MODE_4_LEN 	8

uint8 FRR_CTL_A_MODE_4[FRR_CTL_A_MODE_4_LEN] = {0x11, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00};

#define  MODEM_MOD_TYPE_12_LEN 		       16
#define  MODEM_TX_RAMP_DELAY_8_LEN         12
#define  MODEM_BCR_OSR_1_9_LEN		       13
#define  MODEM_AFC_GEAR_7_LEN		       11
#define  MODEM_AGC_WINDOW_SIZE_9_LEN       13
#define  MODEM_OOK_CNT1_11_LEN		       15
#define  MODEM_CHFLT_RX1_COE13_7_0_12_LEN  16
#define  MODEM_CHFLT_RX1_COE1_7_0_12_LEN   16
#define  MODEM_CHFLT_RX2_COE7_7_0_12_LEN   16
#define  SYNTH_PFDCP_CPFF_7_LEN			   11
#define  MODEM_AGC_CONTROL_1_LEN	       5

uint8 MODEM_AGC_CONTROL_1 		  [MODEM_AGC_CONTROL_1_LEN		   ]={0x11,0x20,0x01,0x35,0xE2}                                                       ;
uint8 MODEM_MOD_TYPE_12 		  [MODEM_MOD_TYPE_12_LEN		   ]={0x11,0x20,0x0C,0x00,0x03,0x00,0x07,0x00,0x12,0xC0,0x04,0x2D,0xC6,0xC0,0x00,0x00};
uint8 MODEM_TX_RAMP_DELAY_8       [MODEM_TX_RAMP_DELAY_8_LEN	   ]={0x11,0x20,0x08,0x18,0x01,0x80,0x08,0x03,0x80,0x00,0x70,0x20}                    ;
uint8 MODEM_BCR_OSR_1_9		      [MODEM_BCR_OSR_1_9_LEN		   ]={0x11,0x20,0x09,0x22,0x03,0x0D,0x00,0xA7,0xC6,0x00,0x54,0x02,0xC2}               ;
uint8 MODEM_AFC_GEAR_7		      [MODEM_AFC_GEAR_7_LEN			   ]={0x11,0x20,0x07,0x2C,0x04,0x36,0x80,0x03,0x30,0xAF,0x80}                         ;
uint8 MODEM_AGC_WINDOW_SIZE_9     [MODEM_AGC_WINDOW_SIZE_9_LEN     ]={0x11,0x20,0x09,0x38,0x11,0xAB,0xAB,0x00,0x1A,0x14,0x00,0x00,0x2B}               ;
uint8 MODEM_OOK_CNT1_11		      [MODEM_OOK_CNT1_11_LEN		   ]={0x11,0x20,0x0B,0x42,0xA4,0x02,0xD6,0x83,0x00,0xAD,0x01,0x80,0xFF,0x0C,0x00}     ;
uint8 MODEM_CHFLT_RX1_COE13_7_0_12[MODEM_CHFLT_RX1_COE13_7_0_12_LEN]={0x11,0x21,0x0C,0x00,0xFF,0xC4,0x30,0x7F,0xF5,0xB5,0xB8,0xDE,0x05,0x17,0x16,0x0C};
uint8 MODEM_CHFLT_RX1_COE1_7_0_12 [MODEM_CHFLT_RX1_COE1_7_0_12_LEN ]={0x11,0x21,0x0C,0x0C,0x03,0x00,0x15,0xFF,0x00,0x00,0xFF,0xC4,0x30,0x7F,0xF5,0xB5};
uint8 MODEM_CHFLT_RX2_COE7_7_0_12 [MODEM_CHFLT_RX2_COE7_7_0_12_LEN ]={0x11,0x21,0x0C,0x18,0xB8,0xDE,0x05,0x17,0x16,0x0C,0x03,0x00,0x15,0xFF,0x00,0x00};
uint8 SYNTH_PFDCP_CPFF_7		  [SYNTH_PFDCP_CPFF_7_LEN		   ]={0x11,0x23,0x07,0x00,0x2C,0x0E,0x0B,0x04,0x0C,0x73,0x03}                         ;


#define RADIO_CONFIGURATION_DATA_ARRAY { \
        0x07, RF_POWER_UP, \
        0x08, RF_GPIO_PIN_CFG, \
        0x05, RF_GLOBAL_XO_TUNE_1, \
        0x05, RF_GLOBAL_CONFIG_1, \
        0x08, RF_INT_CTL_ENABLE_4, \
        0x08, RF_FRR_CTL_A_MODE_4, \
        0x0D, RF_PREAMBLE_TX_LENGTH_9, \
        0x09, RF_SYNC_CONFIG_5, \
        0x05, RF_PKT_CRC_CONFIG_1, \
        0x05, RF_PKT_CONFIG1_1, \
        0x07, RF_PKT_LEN_3, \
        0x07, RF_PKT_FIELD_1_LENGTH_7_0_3, \
        0x07, RF_PKT_FIELD_2_LENGTH_7_0_3, \
        0x07, RF_PKT_FIELD_3_LENGTH_7_0_3, \
        0x07, RF_PKT_FIELD_4_LENGTH_7_0_3, \
        0x07, RF_PKT_FIELD_5_LENGTH_7_0_3, \
        0x10, RF_MODEM_MOD_TYPE_12, \
        0x05, RF_MODEM_FREQ_DEV_0_1, \
        0x0C, RF_MODEM_TX_RAMP_DELAY_8, \
        0x0D, RF_MODEM_BCR_OSR_1_9, \
        0x0B, RF_MODEM_AFC_GEAR_7, \
        0x05, RF_MODEM_AGC_CONTROL_1, \
        0x0D, RF_MODEM_AGC_WINDOW_SIZE_9, \
        0x0C, RF_MODEM_OOK_CNT1_8, \
        0x05, RF_MODEM_RSSI_CONTROL_1, \
        0x05, RF_MODEM_RSSI_COMP_1, \
        0x05, RF_MODEM_CLKGEN_BAND_1, \
        0x10, RF_MODEM_CHFLT_RX1_CHFLT_COE13_7_0_12, \
        0x10, RF_MODEM_CHFLT_RX1_CHFLT_COE1_7_0_12, \
        0x10, RF_MODEM_CHFLT_RX2_CHFLT_COE7_7_0_12, \
        0x08, RF_PA_MODE_4, \
        0x0B, RF_SYNTH_PFDCP_CPFF_7, \
        0x0C, RF_FREQ_CONTROL_INTE_8, \
        0x00 \
 }

const static uint8 config_table[] = RADIO_CONFIGURATION_DATA_ARRAY;

void SI4463_init(void);

void si_spi_write (uint16 length,uint8 *buffer);

int si_writetospi(uint16 headerLength, const uint8 *headerBuffer, uint32 bodylength, const uint8 *bodyBuffer);

uint8 si_readspibyte();

#endif