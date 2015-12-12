//ErrorStatus HSEStartUpStatus;
//
//uint8  buffer[64] = {'0','0','0','0','0',0};
///*******************************************************************************
//* Function Name  : main
//* Description    : Main program.
//* Input          : None
//* Output         : None
//* Return         : None
//*******************************************************************************/
//int main(void)
//{
//    uint8 i, length, error;
//    uint32 dly;
//    uint16 tx_conter = 0, itmp;
//
//#ifdef DEBUG
//  debug();
//#endif
//
////  for(i = 0 ; i < 0xffff ; ++i){;}
//  chushihua();
//
//  SI446X_RESET( );
//  SI446X_CONFIG_INIT( );
//  SI446X_START_RX( 0, 0, 7,0,0,3 );
//  //SI446X_START_TX( 0, 0, 10);
//
////========================================================================
//   while( 1 )
//    {
//
//        for( i = 0; i < 10; i ++ )      { buffer[i] = i + 1; }
//
//#if PACKET_LENGTH == 0
//        SI446X_SEND_PACKET( buffer, 10, 0, 0 );
//#else
//        SI446X_SEND_PACKET( buffer, PACKET_LENGTH, 0, 0 );
//#endif
//
//        do{
//            SI446X_INT_STATUS( buffer );
//        }while( !( buffer[3] & ( 1<<5 ) ) );
//
//
//        SI446X_START_RX( 0, 0, 7,0,0,3 );
//        dly = 1000;
//        while( dly-- )
//        {
//            for( length = 0; length < 20; length ++ );
//            SI446X_INT_STATUS( buffer );
//            if( buffer[3] & ( 1<<4 ) )
//            {
//                length = SI446X_READ_PACKET( buffer );
//                for( i = 0, error = 0; i < 10; i ++ )
//                {
//                    if( buffer[i] != i)
//                    {
//                        error = 1;
//                    }
//                }
//            }
//        }
//        if(error == 0)
//        {
//          SPI_Initial();
//
//          for( dly = 0; dly < 15000; dly ++ );
//          LED_On( );
//          for( dly = 0;dly < 15000; dly ++ );
//          LED_Off( );
//        }
//    }
//}
