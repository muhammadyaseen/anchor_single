/*! ----------------------------------------------------------------------------
 *  @file    main.c
 *  @brief   main loop for the Smart Safety Vest Design for Warehouse Worker - Receiver in vehicle
 *
 *	Developed by: KFRL / Syed Mustafa Kazmi
 *	Start Date: 15/5/2015
 *
 */
/* Includes */
#include "compiler.h"
#include "port.h"
#include "instance.h"
#include "deca_types.h"
#include "deca_spi.h"
#include "eeprom.h"
#include "usart_queue.h"
#include "cmd_Set.h"

#define LOW_BAT_THRESHOLD 2350		//ADC reading at tap point, actual bat voltage is twice this value.


//********** START USART QUEUE FUNCS ***********************//

//__IO USART_QueueTypedef txQueue;
//__IO USART_QueueTypedef rxQueue;
//
//__IO uint8_t TxPrime = 0;
//__IO uint8_t RxOverflow = 0;
//
//
//int USART_Get(void)
//{
//	uint8_t data;
//
//	while( ! Dequeue(&rxQueue, &data) );
//
//	return data;
//}
//
//void USART_Put(int c)
//{
//	while ( ! Enqueue(&txQueue, (uint8_t *)&c) );
//
//	if (!TxPrime)
//	{
//		TxPrime = 1;
//		USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
//	}
//
//}
//
//void USART_Puts(char * str, int len)
//{
//	int idx = 0;
//
//	while( idx <= (len - 1) )
//	{
//		USART_Put( (int)( str[idx++] ) );
//	}
//}

//void USART_Gets(char * str, int len)
//{
//	int idx = 0;
//
//	while( idx < (len - 1) )
//	{
//		USART_Put( (int)(*str[idx++]));
//	}
//}

//void USART3_IRQHandler(void)
//{
//	if ( USART_GetITStatus(USART3, USART_IT_RXNE) != RESET )
//	{
//		uint8_t data;
//
//		data = USART_ReceiveData(USART3) & 0xFF;
//
//		if ( ! Enqueue(&rxQueue, (uint8_t *)&data) )
//			RxOverflow = 1;
//	}
//
//	if ( USART_GetITStatus(USART3, USART_IT_TXE) != RESET )
//	{
//		uint8 data;
//
//		if ( Dequeue( &txQueue, (uint8_t *)&data) )
//		{
//			USART_SendData(USART3, data);
//		}
//		else
//		{
//			USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
//			TxPrime = 0;
//		}
//	}
//}


//********** END USART QUEUE FUNCS ***********************//


int instance_anchaddr = 0; //0 = 0xDECA020000000001; 1 = 0xDECA020000000002; 2 = 0xDECA020000000003
	//NOTE: switches TA_SW1_7 and TA_SW1_8 are used to set tag/anchor address


	//if instance_mode = TAG_TDOA then the device cannot be selected as anchor
	//int instance_mode = TAG;
	//int instance_mode = TAG;
	//int instance_mode = TAG_TDOA;
	//int instance_mode = LISTENER;

uint16_t urxbuf[10];
//uint16_t utxbuf[10] = {'O','K','R','A','N','G','E', 0x00, 0x00, '\n' };
uint16_t utxbuf[10] = {'O','K','R','A','N','G','E', 0x30, 0x00, '\n' };
uint16_t utxbad[10] = {'B','A','D','F','O','R','M','A','T','\n'};
uint16_t abc[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H','I','J','K','L','M','N', 'O', 'P', 'Q', 'R', 'S', 'T','U', 'V', 'X','W','Y','Z'};
uint16_t VirtAddVarTab[10]= {0,1,2,3,4,5,6,7,8,9};

uint16_t rangeValue = 3;

uint32 inittestapplication(void);

// Restart and re-configure
void restartinstance(void)
{
    instance_close() ;                          //shut down instance, PHY, SPI close, etc.

    spi_peripheral_init();                      //re initialise SPI...

    inittestapplication() ;                     //re-initialise instance/device
} // end restartinstance()


//NOTE: Channel 5 is not supported for the non-discovery mode

uint32 inittestapplication(void)
{
    uint32 devID ;
    instanceConfig_t instConfig;
    int i , result;

    SPI_ConfigFastRate(SPI_BaudRatePrescaler_32);  //max SPI before PLLs configured is ~4M

    i = 10;

    //this is called here to wake up the device (i.e. if it was in sleep mode before the restart)
    devID = instancereaddeviceid() ;
    if(DWT_DEVICE_ID != devID) //if the read of devide ID fails, the DW1000 could be asleep
    {
        port_SPIx_clear_chip_select();  //CS low
        Sleep(1);   //200 us to wake up then waits 5ms for DW1000 XTAL to stabilise
        port_SPIx_set_chip_select();  //CS high
        Sleep(7);
        devID = instancereaddeviceid() ;
        // SPI not working or Unsupported Device ID
        if(DWT_DEVICE_ID != devID)
            return(-1) ;
        //clear the sleep bit - so that after the hard reset below the DW does not go into sleep
        dwt_softreset();
    }

    //reset the DW1000 by driving the RSTn line low
    reset_DW1000();

    result = instance_init();

    if (0 > result) {
        	i=15;
			while(i--)
			{
				if (i & 1) {
					//led_off(LED_PC6);
					led_on(LED_PC6);
					led_off(LED_PC7);
				}
				else{
					//led_on(LED_PC6);
					led_off(LED_PC6);
					led_on(LED_PC7);
				}

				Sleep(500);
			}

				i = 0;

				Sleep(500);
				led_on(LED_ALL);
				Sleep(500);

				IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
				IWDG_SetPrescaler(IWDG_Prescaler_4);
				IWDG_Enable();
				IWDG_ReloadCounter();

				while(1);  //iwdg reset

        	return (-1) ; // Some failure has occurred
        }

   // SPI_ConfigFastRate(SPI_BaudRatePrescaler_4); //increase SPI to max
    devID = instancereaddeviceid() ;

    if (DWT_DEVICE_ID != devID)   // Means it is NOT MP device
    {
        // SPI not working or Unsupported Device ID

    	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
		IWDG_SetPrescaler(IWDG_Prescaler_4);
		IWDG_Enable();
		IWDG_ReloadCounter();

		while(1);  //iwdg reset

    	return(-1) ;
    }


	instance_init_f(); //initialise Fast 2WR specific data
	//when using fast ranging the channel config is either mode 2 or mode 6
	//default is mode 2


    instance_config() ;                  // Set operating channel etc

#if (DR_DISCOVERY == 0)
    addressconfigure() ;                            // set up initial payload configuration
#endif
    instancesettagsleepdelay(POLL_SLEEP_DELAY, BLINK_SLEEP_DELAY); //set the Tag sleep time

    //if TA_SW1_2 is ON use fast ranging (fast 2wr)
    //if(is_fastrng_on(0) == S1_SWITCH_ON)
    //{
        //Fast 2WR specific config
        //configure the delays/timeouts
        instance_config_f();
    //}
    /*else //use default ranging modes
    {
        // NOTE: this is the delay between receiving the blink and sending the ranging init message
        // The anchor ranging init response delay has to match the delay the tag expects
        // the tag will then use the ranging response delay as specified in the ranging init message
        // use this to set the long blink response delay (e.g. when ranging with a PC anchor that wants to use the long response times != 150ms)
#if (DR_DISCOVERY == 1)  //this switch (S1_8) is not used when non-discovery mode
    	if(is_switch_on(TA_SW1_8) == S1_SWITCH_ON)
        {
            instancesetblinkreplydelay(FIXED_LONG_BLINK_RESPONSE_DELAY);
        }
        else //this is for ARM to ARM tag/anchor (using normal response times 150ms)
#endif
        {
            instancesetblinkreplydelay(FIXED_REPLY_DELAY);
        }

#if (DR_DISCOVERY == 1)
        //set the default response delays
        instancesetreplydelay(FIXED_REPLY_DELAY, 0);
#else
        //set the default response delays
        instancesetreplydelay(FIXED_REPLY_DELAY_MULTI, 0);
#endif
    }*/

    return devID;
}

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
void process_dwRSTn_irq(void)
{
    instance_notify_DW1000_inIDLE(1);
}

void process_deca_irq(void)
{
    do{

        instance_process_irq(0);

    }while(port_CheckEXT_IRQ() == 1); //while IRS line active (ARM can only do edge sensitive interrupts)

}

void init_dw(void)
{

	GPIO_SetBits(DW_GPIO, DW_PWR);
	Sleep(1000);

}

/*
 * @fn      main()
 * @brief   main entry point
**/
int main(void)
{
    int i = 0;
    int toggle = 1;
    int ranging = 0;
    uint8 dataseq[40];
    double range_result = 0;
    double avg_result = 0;
    uint8 dataseq1[40];

    led_off(LED_ALL); //turn off all the LEDs

    peripherals_init();

    //spi_peripheral_init();

    //ADC_Configuration();

    USART_Configuration();

    //Sleep(500);

    port_DisableEXT_IRQ(); //disable ScenSor IRQ until we configure the device

    //this 'if' is for pc software, i am commenting this bcz we dont need to run deca ranging on PC

    led_off(LED_ALL);

    led_on(LED_ALL);

    if(false)
    {

    }
    else //run DecaRanging application.. this is what we actually need.
    {
       led_off(LED_ALL);

        if(0)//inittestapplication() == (uint32)-1) //test SPI and dw1000 device is working or not
        {
            led_on(LED_ALL); 			//to display error....
            return 0; //error
        }
        else  //init test was successfull.. Blink LEDs to indicate
        {
//        	i=5;
//			 while(i--)
//			 {
//				 if (i & 1) {
//					led_off(LED_PC6);
//					led_on(LED_PC7);
//					//led_off(LED_PC7);
//				 }
//				 else{
//					led_on(LED_PC6);
//					led_off(LED_PC7);
//					//led_on(LED_PC7);
//				 }
//				 Sleep(100);
//			 }
//
//			 i = 0;
        	 led_off(LED_ALL);
        }

    }

    led_off(LED_ALL);

    ////////// READ BACK CONFIGURED RANGE VALUE ////////////////


    //write to Flash
	/* Unlock the Flash Program Erase controller */
	//FLASH_Unlock();
	/* EEPROM Init */
	//EE_Init();

	//EE_ReadVariable(5, &rangeValue);

	//FLASH_Lock();

//	if ( rangeValue < 1 || rangeValue > 9 )
//	{
//		rangeValue = 1;		//resort to default if nonsense
//	}

    port_EnableEXT_IRQ(); //enable ScenSor IRQ before starting

    // main loop
//    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
//    IWDG_SetPrescaler(IWDG_Prescaler_4);
//    IWDG_Enable();
    int l = 0;
    uint8_t d[6];

    while(1)
    {
		while (1)
		{

			//if ( l > 25 ) l = 0;sss

			//USART_Put(abc[l]);

//			while(USART_GetFlagStatus(USART3 , USART_FLAG_TXE) == RESET) { }
//			USART_SendData(USART3, abc[l]);
			//l = l + 1;

			//USART_Puts("Send something of 5 chars?", 26);

			USART_Gets(d, 6);

			USART_Puts("You sent : ", 11);

			USART_Puts(d, 6);

			USART_Put('\n');

			exec_command( decode_command((char *)d) );

		}
    	//IWDG_ReloadCounter();

		///////////////////// CHECK BATTERY LEVEL /////////////////////////////
		/*bat_adc_on();
		uint16 readingOn = readADC1(BAT_ADC_CHANNEL);

		if ( readingOn < LOW_BAT_THRESHOLD )
			led_on(LED_PC7);
		else
			led_off(LED_PC7);*/

		//////////////////// CHECK UART FOR CONFIG /////////////////////////////

		/*if (USART_GetFlagStatus(USART1 , USART_FLAG_RXNE) == SET)
		{
			//if we have received something, check if a valid config frame
			urxbuf[0] = USART_ReceiveData(USART1);

			if ( urxbuf[0] == 0x2A )		// '*' character
			{
				//wait in UART loop for receive complete msg and write in flash
				for (int i=0; i<=1; i++)
				{
					while ( USART_GetFlagStatus(USART1 , USART_FLAG_RXNE) == RESET ) { IWDG_ReloadCounter(); }
					urxbuf[i] = USART_ReceiveData(USART1);
				}

				uint16_t cfgRange = urxbuf[1] - 0x30;

				//received 2 bytes in format <r><num1>, where r is for range and num1 specified actual range

				if ( (urxbuf[0] == 'r' || urxbuf[0] == 'R') && ( cfgRange > 0 && cfgRange <= 9) )
				{
					//: write to Flash
					//Unlock the Flash Program Erase controller
					FLASH_Unlock();
					//EEPROM Init
					EE_Init();
					//uint16_t prevVal;
					//EE_ReadVariable(5, &prevVal);

					EE_WriteVariable(5, cfgRange);

					//: Read from flash , the newly written value
					uint16_t readVal;
					EE_ReadVariable(5, &readVal);
					FLASH_Lock();

					//: send out a confirm msg
					utxbuf[8] = readVal + 0x30;		//must read from FLASH, will need to add 0x30 then
					int t=0;
					while (t < 10)
					{
						while(USART_GetFlagStatus(USART1 , USART_FLAG_TXE) == RESET) { IWDG_ReloadCounter(); }
						USART_SendData(USART1, utxbuf[t]);
						t++;
					}
				}
				else
				{
					//: send msg saying bad format
					int s=0;
					while (s < 10)
					{
						while(USART_GetFlagStatus(USART1 , USART_FLAG_TXE) == RESET) { IWDG_ReloadCounter(); }
						USART_SendData(USART1, utxbad[s]);
						s++;
					}
				}
			}

		}*/
		/////////////////// RANGE ROUTINE ////////////////////////
        instance_run();

        if(instancenewrange())
        {
        	IWDG_ReloadCounter();

        	int l = 0, txl = 0, rxl = 0, aaddr, taddr;
            ranging = 1;
            //send the new range information to LCD and/or USB
            range_result = instance_get_idist();
            //set_rangeresult(range_result);

            IWDG_ReloadCounter();

            if(range_result < rangeValue ){
            	led_on(LED_PC6);
            	led_off(LED_PC7);

            	//signal the buzzer and relay
            	GPIO_SetBits( BUZZ_GPIO, BUZZ );
            	GPIO_SetBits( VIB_GPIO, VIB);

            	Sleep(250);
   	            while(1) IWDG_ReloadCounter();
            }
            else {
            	led_on(LED_PC7);
            	led_off(LED_PC6);
            }

            Sleep(250);
            while(1);
        }

        if(ranging == 0)
        {

			if(instanceanchorwaiting())
			{
				toggle+=2;

				if(toggle > 300000)
				{
//					dataseq[0] = 0x2 ;  //return cursor home
//					writetoLCD( 1, 0,  dataseq);
					if(toggle & 0x1)
					{
						toggle = 0;
//						memcpy(&dataseq[0], (const uint8 *) "    AWAITING    ", 16);
//						writetoLCD( 40, 1, dataseq); //send some data
//						memcpy(&dataseq[0], (const uint8 *) "      POLL      ", 16);
//						writetoLCD( 16, 1, dataseq); //send some data
					}
					else
					{
						toggle = 1;
#if (DR_DISCOVERY == 1)
//						memcpy(&dataseq[0], (const uint8 *) " DISCOVERY MODE ", 16);
#else
//						memcpy(&dataseq[0], (const uint8 *) " NON DISCOVERY  ", 16);
#endif
//						writetoLCD( 40, 1, dataseq); //send some data
//						sprintf((char*)&dataseq[0], "%llX", instance_get_addr());
//						writetoLCD( 16, 1, dataseq); //send some data
					}
				}

			}
			else if(instanceanchorwaiting() == 2)
			{
//				dataseq[0] = 0x2 ;  //return cursor home
//				writetoLCD( 1, 0,  dataseq);
//				memcpy(&dataseq[0], (const uint8 *) "    RANGING WITH", 16);
//				writetoLCD( 40, 1, dataseq); //send some data
//				sprintf((char*)&dataseq[0], "%llX", instance_get_tagaddr());
//				writetoLCD( 16, 1, dataseq); //send some data
			}
        }

    }


    return 0;
}



