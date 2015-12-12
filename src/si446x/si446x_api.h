//#ifndef _SI446X_H_
//#define _SI446X_H_
//#include "port.h"
//#define U8 uint8_t
//
//#include "mytypedef.h"
//#include "SIP.h"
//
//#include "SI446X_defs.h"
//
///*
//=================================================================================
//-----------------------------External IMPORT functions---------------------------
//=================================================================================
//*/
//
//#include "SIP.h"   //
//#define SI_CSN_LOW( )    GPIO_ResetBits(GPIOB, NSEL)
//#define SI_CSN_HIGH( )   GPIO_SetBits(GPIOB, NSEL)
//
//#define SI_SDN_LOW( )   GPIO_ResetBits(GPIOD, RF_SDN)
//#define SI_SDN_HIGH( )  GPIO_SetBits(GPIOD, RF_SDN)
//
//void SI446X_PART_INFO( uint8 *buffer );
//
///*Read the FUNC_INFO of the device, 7 bytes needed*/
//void SI446X_FUNC_INFO( uint8 *buffer );
//
///*Send a command to the device*/
//void SI446X_CMD( uint8 *cmd, uint8 cmdsize );
//
///*Read the INT status of the device, 9 bytes needed*/
//void SI446X_INT_STATUS( uint8 *buffer );
//
///*Read the PROPERTY of the device*/
//void SI446X_GET_PROPERTY_X( SI446X_PROPERTY GROUP_NUM, uint8 NUM_PROPS, uint8 *buffer  );
//
///*configuration the device*/
//void SI446X_CONFIG_INIT( void );
//
///*reset the SI446x device*/
//void SI446X_RESET( void );
//
///*write data to TX fifo*/
//void SI446X_W_TX_FIFO( uint8 *txbuffer, uint8 size );
//
///*start TX command*/
//void SI446X_START_TX( uint8 channel, uint8 condition, uint16 tx_len );
//
///*read RX fifo*/
//uint8 SI446X_READ_PACKET( uint8 *buffer );
//
///*start RX state*/
//void SI446X_START_RX( uint8 channel, uint8 condition, uint16 rx_len,
//                      uint8 n_state1, uint8 n_state2, uint8 n_state3 );
//
///*read packet information*/
//void SI446X_PKT_INFO( uint8 *buffer, uint8 FIELD, uint16 length, uint16 diff_len );
//
///*read fifo information*/
//void SI446X_FIFO_INFO( uint8 *buffer );
//
///*Power up the device*/
//void SI446X_POWER_UP( uint32 f_xtal );
//
///*send a packet*/
//void SI446X_SEND_PACKET( uint8 *txbuffer, uint8 size, uint8 channel, uint8 condition );
//
///*Set the PROPERTY of the device*/
//void SI446X_SET_PROPERTY_X( SI446X_PROPERTY GROUP_NUM, uint8 NUM_PROPS, uint8 *PAR_BUFF );
//
///*config the CRC, PROPERTY 0x1200*/
//void SI446X_CRC_CONFIG( uint8 PKT_CRC_CONFIG );
//
///*Get the PROPERTY of the device, only 1 byte*/
//uint8 SI446X_GET_PROPERTY_1( SI446X_PROPERTY GROUP_NUM );
//
///*Set the PROPERTY of the device, only 1 byte*/
//void SI446X_SET_PROPERTY_1( SI446X_PROPERTY GROUP_NUM, uint8 proirity );
//
///*config the GPIOs, IRQ, SDO*/
//void SI446X_GPIO_CONFIG( uint8 G0, uint8 G1, uint8 G2, uint8 G3,
//                         uint8 IRQ, uint8 SDO, uint8 GEN_CONFIG );
//
///*reset the RX FIFO of the device*/
//void SI446X_RX_FIFO_RESET( void );
//
///*reset the TX FIFO of the device*/
//void SI446X_TX_FIFO_RESET( void );
///*
//=================================================================================
//----------------------------PROPERTY fast setting macros-------------------------
//=================================================================================
//*/
//// GOLBAL(0x00)
//#define GLOBAL_XO_TUNE( x )                 SI446X_SET_PROPERTY_1( 0x0000, x )
//#define GLOBAL_CLK_CFG( x )                 SI446X_SET_PROPERTY_1( 0x0001, x )
//#define GLOBAL_LOW_BATT_THRESH( x )         SI446X_SET_PROPERTY_1( 0x0002, x )
//#define GLOBAL_CONFIG( x )                  SI446X_SET_PROPERTY_1( 0x0003, x )
//#define GLOBAL_WUT_CONFIG( x )              SI446X_SET_PROPERTY_1( 0x0004, x )
//#define GLOBAL_WUT_M_15_8( x )              SI446X_SET_PROPERTY_1( 0x0005, x )
//#define GLOBAL_WUT_M_7_0( x )               SI446X_SET_PROPERTY_1( 0x0006, x )
//#define GLOBAL_WUT_R( x )                   SI446X_SET_PROPERTY_1( 0x0007, x )
//#define GLOBAL_WUT_LDC( x )                 SI446X_SET_PROPERTY_1( 0x0008, x )
//#define GLOBAL_WUT_CAL( x )                 SI446X_SET_PROPERTY_1( 0x0009, x )
//
//// INT_CTL(0x01)
//#define INT_CTL_ENABLE( x )                 SI446X_SET_PROPERTY_1( 0x0100, x )
//#define INT_CTL_PH_ENABLE( x )              SI446X_SET_PROPERTY_1( 0x0101, x )
//#define INT_CTL_MODEM_ENABLE( x )           SI446X_SET_PROPERTY_1( 0x0102, x )
//#define INT_CTL_CHIP_ENABLE( x )            SI446X_SET_PROPERTY_1( 0x0103, x )
//
////group 0x02, FRR_CTL
//#define FRR_CTL_A_MODE( x )                 SI446X_SET_PROPERTY_1( 0x0200, x )
//#define FRR_CTL_B_MODE( x )                 SI446X_SET_PROPERTY_1( 0x0201, x )
//#define FRR_CTL_C_MODE( x )                 SI446X_SET_PROPERTY_1( 0x0202, x )
//#define FRR_CTL_D_MODE( x )                 SI446X_SET_PROPERTY_1( 0x0203, x )
//
//// PREAMBLE (0x10)
//
//
//
//
//
//
//
//
//
//#endif //_SI446X_H_
