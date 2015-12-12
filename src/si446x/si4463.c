/*
 * si4463.c
 *
 *  Created on: 2 Jun 2015
 *      Author: KFRL/SM
 */

#include "si4463.h"

/*   imp SPI reg / flag notes
 *
 * 	TXE: 	When it is set, this flag indicates that the Tx buffer is empty and the next data to be
			transmitted can be loaded into the buffer. The TXE flag is cleared when writing to the
			SPI_DR register.
 *
 *  RXNE:   When set, this flag indicates that there are valid received data in the Rx buffer. It is cleared
			when SPI_DR is read.


	Disabling the SPI , pg709

	SPIE : SPI enable
	BR[2:0]	: baud rate control

	SPI_SR ---> SPI status register . Has TXE (b1) and RXNE (b0) bits
	SPI_DR ---> SPI Data register //Data received or to be transmitted

	gpio reg descriptions pg171
	@link : http://hertaville.com/2012/07/28/stm32f0-gpio-tutorial-part-1/

	GPIOx_BRR --->		Bit Reset Register
	GPIO_BSRR --->		bit set/reset register
 *
 *
 */
uint8 si_readspibyte()
{
	uint8 i;

	SI_SPI->DR = 0;

	while((SI_SPI->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);

	i = SI_SPI->DR;//port_SPIx_receive_data(); //this clears RXNE bit

    return i;

} // end SI_readspibyte()

void si_spi_write( uint16 length, uint8 *buffer)
{
	uint16 i=0;

	SI_GPIO->BRR = SI_CS;

    for(i=0; i<length; i++)
    {
    	SI_SPI->DR = buffer[i];

    	while ((SI_SPI->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);

    	SI_SPI->DR ;
    }

}


uint8_t check_cts(void)
{
	uint8_t i;

	GPIO_SetBits(SI_GPIO, SI_CS);
	GPIO_ResetBits(SI_GPIO, SI_SCK);
	GPIO_ResetBits(SI_GPIO, SI_CS);

	si_readspibyte( RF_READ_CMD_BUFF);
	i = si_readspibyte(0);

	GPIO_SetBits(SI_GPIO, SI_CS);

	return (i);
}


int si_writetospi
(
    uint16       headerLength,
    const uint8 *headerBuffer,
    uint32       bodylength,
    const uint8 *bodyBuffer
)
{
	int i=0;
	SI_GPIO->BRR = SI_CS;

    for(i=0; i<headerLength; i++)
    {
    	SI_SPI->DR = headerBuffer[i];
    	while ((SI_SPI->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);
    	SI_SPI->DR ;
    }

    for(i=0; i<bodylength; i++)
    {
    	SI_SPI->DR = bodyBuffer[i];
    	while((SI_SPI->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);
    	SI_SPI->DR ;
	}

    SI_GPIO->BSRR = SI_CS;
    return 0;
}

void si_read_deviceid()
{



}

void SI4463_init(void)
{

	uint8 *app_command_buf;
	uint8 i ,k ,hc[15];
	uint16 j = 0;

	while( ( i = config_table[j] ) != 0 )
	{
	    j += 1;
	    for(k = 0 ; k < i ; ++k)
	    {
	    	hc[k] = config_table[j + k];
	    }

	    si_spi_write(i , &hc );

	    j += i;
	}

	//uint8 *app_command_buf;
	//uint8 i;

/*
	*(app_command_buf+0) = RF_GPIO_PIN_CFG; // gpio setting
	*(app_command_buf+1) = 0x01; // 0x21;    // gpio 0 ,Rx data
	*(app_command_buf+2) = 0x01; // gpio1, output 0  high level when power on
	*(app_command_buf+3) = 0x01; // gpio2, h = tx mode
	*(app_command_buf+4) = 0x01; // gpio3
	*(app_command_buf+5) = 0x27; // nIRQ
	*(app_command_buf+6) = 0x0b; // sdo
	si_spi_write(7, app_command_buf);


 	*(app_command_buf+0) = RF_SET_PROPERTY; //  frequency adjust
	*(app_command_buf+1) = 0x00; // 0x0000
	*(app_command_buf+2) = 0x01; // total 1 parameter
	*(app_command_buf+3) = 0x00; // 0x0000
	*(app_command_buf+4) = 98;   // freq  adjustment
	si_spi_write(5, app_command_buf);


  	*(app_command_buf+0)= RF_SET_PROPERTY;     // rf global setting
	*(app_command_buf+1)= 0x00;    // 0x0003
	*(app_command_buf+2)= 0x01;     // total 1 parameter
	*(app_command_buf+3)= 0x03;   // 0x0003
	*(app_command_buf+4)= 0x40;  // tx = rx = 64 byte,  PH£¬high performance mode
	si_spi_write(5, app_command_buf);

    // *****************************************************************************
	si_spi_write(FRR_CTL_A_MODE_4_LEN, &FRR_CTL_A_MODE_4[0]);    // disable all fast response register


 	*(app_command_buf+0 ) = RF_SET_PROPERTY;   // preamble setting
	*(app_command_buf+1 ) = 0x10;  // 0x1000
	*(app_command_buf+2 ) = 0x09;  // total 9 parameter
	*(app_command_buf+3 ) = 0x00;  // 0x1000
	*(app_command_buf+4 ) = 0x08;  //  8 byte preamble
	*(app_command_buf+5 ) = 0x14;  //20 bit preamble detectin
	*(app_command_buf+6 ) = 0x00;  // standard preamble
	*(app_command_buf+7 ) = 0x0f;  //
	*(app_command_buf+8 ) = 0x31;  // preamble, no machest, lsb, unit = byte for preamble length
	*(app_command_buf+9 ) = 0x00;  //  abnormal preamble
	*(app_command_buf+10) = 0x00;  //  abnormal preamble
	*(app_command_buf+11) = 0x00;  //  abnormal preamble
	*(app_command_buf+12) = 0x00;  //  abnormal preamble
	si_spi_write(13, app_command_buf);//


    *(app_command_buf+0) = RF_SET_PROPERTY;  	// sync word setting
	*(app_command_buf+1) = 0x11;    // command = 0x1100
	*(app_command_buf+2) = 0x05;     // total 9 parameter
	*(app_command_buf+3) = 0x00;   // command = 0x1100
	*(app_command_buf+4) = 0x01;   //  sync word define in length field , not 4fsk, not manchest code,2 byte, no error accepted
	*(app_command_buf+5) = 0x2d;   //sync byte 3
	*(app_command_buf+6) = 0xd4;   // sync byte 2
	*(app_command_buf+7) = 0x00;   // sync byte 1, no use
	*(app_command_buf+8) = 0x00;  // sync byte 0, no use
	si_spi_write(9, app_command_buf);  //


    *(app_command_buf+0) = RF_SET_PROPERTY;     // crc setting
	*(app_command_buf+1)  = 0x12;    // command = 0x1200
	*(app_command_buf+2)  = 0x01;    // total 1 parameter
	*(app_command_buf+3)  = 0x00;   // command = 0x1200
	*(app_command_buf+4)  = 0x81; //   crc seed , enable, itu-c, enabe.
	si_spi_write(5, app_command_buf);


    *(app_command_buf+0) = RF_SET_PROPERTY;  	// packet   gernale configuration
	*(app_command_buf+1) = 0x12;    // command = 0x1206
	*(app_command_buf+2) = 0x01;    // total 1 parameter
	*(app_command_buf+3) = 0x06;   // command = 0x1206
	*(app_command_buf+4) = 0x02;   //  tx = rx = 120d--1220 (tx packet£¬ph enable, not 4fsk, RX off after received data,CRC no invertor£¬CRC MSB£¬ data MSB
	si_spi_write(5, app_command_buf);


    *(app_command_buf+0) = RF_SET_PROPERTY;  	// packet length
	*(app_command_buf+1) = 0x12;    // command = 0x1208
	*(app_command_buf+2) = 0x03;    // total 3 parameter
	*(app_command_buf+3) = 0x08;   // command = 0x1208
	*(app_command_buf+4) = 0x00;   //  Length Field = LSB,  length = 1byte£¬length not in FiFo, fixed length
	*(app_command_buf+5) = 0x00;   //
	*(app_command_buf+6) = 0x00;   //
	si_spi_write(7, app_command_buf);

	*(app_command_buf+0 ) = RF_SET_PROPERTY;  	// field 1-- 4 setting
	*(app_command_buf+1 ) = 0x12;    // 0x120d
	*(app_command_buf+2 ) = 0x0c;    // total 12 parameter
	*(app_command_buf+3 ) = 0x0d;   // 0x120d
	*(app_command_buf+4 ) = 0x00;   //  length of field 1 , bit 8--11
	*(app_command_buf+5 ) = payload_length;   //  lengh of field 1, bit 0--7
	*(app_command_buf+6 ) = 0x04;   // field 1 not 4fsk, not manchest, no whiting,not PN9,
	*(app_command_buf+7 ) = 0xaa;   // field 1 crc enble, check enbale,
	*(app_command_buf+8 ) = 0x00;  //  length of field2 bit8--bit11
	*(app_command_buf+9 ) = 0x00;  	//  length of field2 bit0--bit7
	*(app_command_buf+10) = 0x00;   // field 2  not 4FSK£¬manchest, whiting, PN9
	*(app_command_buf+11) = 0x00;  //  field 2 CRC
	*(app_command_buf+12) = 0x00;  //  length of field3 bit8--bit11
	*(app_command_buf+13) = 0x00;  	//  length of field2 bit0--bit7
	*(app_command_buf+14) = 0x00;   //  field 3 not 4FSK£¬manchest, whiting, PN9
	*(app_command_buf+15) = 0x00;  //  field 3 CRC
	si_spi_write(16, app_command_buf);  //


    *(app_command_buf+0 )= RF_SET_PROPERTY;
	*(app_command_buf+1 ) = 0x12;    // 0x1219
	*(app_command_buf+2 ) = 0x08;   // total 12 parameter
	*(app_command_buf+3 ) = 0x19;   // 0x1219
	*(app_command_buf+4 ) = 0x00;   //  length of field4 bit8--bit11
	*(app_command_buf+5 ) = 0x00;   //  length of field5 bit0--bit7
	*(app_command_buf+6 ) = 0x00;   //   field 4 not 4FSK£¬manchest, whiting, PN9
	*(app_command_buf+7 ) = 0x00;   // field 4 CRC
	*(app_command_buf+8 ) = 0x00;  //  length of field5 bit8--bit11
	*(app_command_buf+9 ) = 0x00;  	//  length of field5 bit0--bit7
	*(app_command_buf+10)  = 0x00;   //  field 5 not 4FSK£¬manchest, whiting, PN9
	*(app_command_buf+11)  = 0x00;   // field 5 CRC
    spi_write(12, app_command_buf);  //

    // ********************************************************************************
    si_spi_write(MODEM_MOD_TYPE_12_LEN,  &MODEM_MOD_TYPE_12[0]);   // //  2FSK ,  module source = PH fifo, disable manchest,


    *(app_command_buf+0) = RF_SET_PROPERTY;
	*(app_command_buf+1) = 0x20;    // 0x200c
	*(app_command_buf+2) = 0x01;    // total 1 parameter
	*(app_command_buf+3) = 0x0c;   // 0x200c
	*(app_command_buf+4) = 0x5e; // frequency deviation bit0-- 7
	si_spi_write(5, app_command_buf);

    // ********************************************************************************
	si_spi_write(MODEM_TX_RAMP_DELAY_8_LEN, &MODEM_TX_RAMP_DELAY_8[0]);

	si_spi_write(MODEM_BCR_OSR_1_9_LEN, &MODEM_BCR_OSR_1_9[0]);

	si_spi_write(MODEM_AFC_GEAR_7_LEN, &MODEM_AFC_GEAR_7[0]);

	si_spi_write(MODEM_AGC_CONTROL_1_LEN, &MODEM_AGC_CONTROL_1[0]);

	si_spi_write(MODEM_AGC_WINDOW_SIZE_9_LEN, &MODEM_AGC_WINDOW_SIZE_9[0]);

	si_spi_write(MODEM_OOK_CNT1_11_LEN, &MODEM_OOK_CNT1_11[0]);

	// spi_write(0x05, MODEM_RSSI_COMP_1);	**************************************************
	*(app_command_buf+0) = RF_SET_PROPERTY;
	*(app_command_buf+1) = 0x20;    // 0x204e
	*(app_command_buf+2) = 0x01;   // total 1 parameter
	*(app_command_buf+3) = 0x4e;   // 0x204e
	*(app_command_buf+4) = 0x40;  //  rssi, read data tolerance, deviation with real value
	si_spi_write(5, app_command_buf);

    // ********************************************************************************
    si_spi_write(MODEM_CHFLT_RX1_COE13_7_0_12_LEN, &MODEM_CHFLT_RX1_COE13_7_0_12[0]);
    si_spi_write(MODEM_CHFLT_RX1_COE1_7_0_12_LEN , &MODEM_CHFLT_RX1_COE1_7_0_12 [0]);
    si_spi_write(MODEM_CHFLT_RX2_COE7_7_0_12_LEN , &MODEM_CHFLT_RX2_COE7_7_0_12 [0]);

	// PA **************************************************************************
	*(app_command_buf+0) = RF_SET_PROPERTY;
	*(app_command_buf+1)  = 0x22;    // 0x2200
	*(app_command_buf+2)  = 0x04;    // total 4 parameter
	*(app_command_buf+3)  = 0x00;   // 0x2200
	*(app_command_buf+4)  = 0x08;  //0x10;   //   PA mode  = default , use Class E mode£¬not Switch Current mode  ????????
	*(app_command_buf+5)  = 127;   //  set the max. output power
	*(app_command_buf+6)  =0x00; //???????? 0x00;   // CLK duty = 50%£¬ Other = Default
	*(app_command_buf+7)  = 0x3d;  // ???????? 0x5d;   // PA ramp time = default
	si_spi_write(8, app_command_buf);

    // ********************************************************************************
	si_spi_write(0x0B, &SYNTH_PFDCP_CPFF_7[0]);

   	// header match ******************************************************************
   	*(app_command_buf+0 ) = RF_SET_PROPERTY;
	*(app_command_buf+1 ) = 0x30;    // 0x3000
	*(app_command_buf+2 ) = 0x0c;    // total 12 parameter
	*(app_command_buf+3 ) = 0x00;   // 0x3000
	*(app_command_buf+4 ) = 's';    //  match value of 1st byte
	*(app_command_buf+5 ) = 0xff;   //  match 1 mask
	*(app_command_buf+6 ) = 0x40;   // eable match 1, offset after sync word
	*(app_command_buf+7 ) = 'w';    //  match value of 2nd byte
	*(app_command_buf+8 ) = 0xff;   //  match 2 mask
	*(app_command_buf+9 ) = 0x01;   // enable match 2,offset after sync word
	*(app_command_buf+10) = 'w';   //  match value of 3rd byte
	*(app_command_buf+11)  =0xff;;    //  match 3 mask
	*(app_command_buf+12)  =0x02;;    // enable match 3,  enable match 3,offset after sync word
	*(app_command_buf+13)  = 'x';    //  match value of 4th byte
	*(app_command_buf+14)  = 0xff;   //   match 4 mask
	*(app_command_buf+15)  = 0x03;   //  enable match 4,  enable match 4,offset after sync word
	si_spi_write(16, app_command_buf);


	*(app_command_buf+0 ) = RF_SET_PROPERTY;
	*(app_command_buf+1 ) = 0x20;    // 0x2051
	*(app_command_buf+2 ) = 0x01;    //
	*(app_command_buf+3 ) = 0x51;   // 0x2051
	*(app_command_buf+4 ) = 0x0a;
	si_spi_write(5, app_command_buf);

	*(app_command_buf+0 ) = RF_SET_PROPERTY;
	*(app_command_buf+1 ) = 0x40;    // 0x4000
	*(app_command_buf+2 ) = 0x08;    //
	*(app_command_buf+3 ) = 0x00;   // 0x4000
	*(app_command_buf+4 ) = 0x38;   //  default value
	*(app_command_buf+5 ) = 0x0e;   //  defaul value
	*(app_command_buf+6 ) = 0x66;   //  default value
	*(app_command_buf+7 ) = 0x66;   // frac ,from WDS
	*(app_command_buf+8 ) = step_500K_step1;   // channel step1  from wds
	*(app_command_buf+9 ) = step_500K_step0;   // channel step0  from wds
	*(app_command_buf+10) = 0x20;
	*(app_command_buf+11)  = 0xfe;
	si_spi_write(12, app_command_buf);
*/

}


