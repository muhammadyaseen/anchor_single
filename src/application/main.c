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

	int instance_anchaddr = 0; //0 = 0xDECA020000000001; 1 = 0xDECA020000000002; 2 = 0xDECA020000000003
	//NOTE: switches TA_SW1_7 and TA_SW1_8 are used to set tag/anchor address


	//if instance_mode = TAG_TDOA then the device cannot be selected as anchor
	//int instance_mode = TAG;
	//int instance_mode = TAG;
	//int instance_mode = TAG_TDOA;
	//int instance_mode = LISTENER;


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

    result = instance_init() ;
    if (0 > result) return(-1) ; // Some failure has occurred

    SPI_ConfigFastRate(SPI_BaudRatePrescaler_4); //increase SPI to max
    devID = instancereaddeviceid() ;

    if (DWT_DEVICE_ID != devID)   // Means it is NOT MP device
    {
        // SPI not working or Unsupported Device ID
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

int test_si446x()
{

	//power up si

	GPIO_SetBits(SI_GPIO, SI_SDN);
	Sleep(20);
	GPIO_ResetBits(SI_GPIO, SI_SDN);
	Sleep(20);

	//start spi

	SPI_Cmd(SI_SPI, ENABLE);

	//send power up

	SI4463_init();


	//read dev id

	//




	return -1;
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

    spi_peripheral_init();

    Sleep(10);
    //Sleep(1000); //wait for LCD to power on

    //init_dw();

    //initLCD();


    port_DisableEXT_IRQ(); //disable ScenSor IRQ until we configure the device

    //this 'if' is for pc software, i am commenting this bcz we dont need to run deca ranging on PC
    if(false)
    {

    }
    else //run DecaRanging application.. this is what we actually need.
    {
       led_off(LED_ALL);

        if(inittestapplication() == (uint32)-1) //test SPI and dw1000 device is working or not
        {
            led_on(LED_ALL); 			//to display error....
            return 0; //error
        }
        else  //init test was successfull.. Blink LEDs to indicate
        {
        	i=20;
			 while(i--)
			 {
				 if (i & 1) {
					led_off(LED_PC6);
					led_on(LED_PC7);
					//led_off(LED_PC7);
				 }
				 else{
					led_on(LED_PC6);
					led_off(LED_PC7);
					//led_on(LED_PC7);
				 }
				 Sleep(100);
			 }

			 i = 0;
        	 led_off(LED_ALL);
        }

    }

    led_off(LED_ALL);

    port_EnableEXT_IRQ(); //enable ScenSor IRQ before starting

    // main loop


    while(1)
    {
        instance_run();

        if(instancenewrange())
        {
        	int l = 0, txl = 0, rxl = 0, aaddr, taddr;
            ranging = 1;
            //send the new range information to LCD and/or USB
            range_result = instance_get_idist();
            //set_rangeresult(range_result);
//            dataseq[0] = 0x2 ;  //return cursor home
//            writetoLCD( 1, 0,  dataseq);
//
//            memset(dataseq, ' ', 40);
//            sprintf((char*)&dataseq[1], "LAST: %4.2f m", range_result);
//            writetoLCD( 40, 1, dataseq); //send some data


            if(range_result < 1.0f){
            	//memcpy(&dataseq1[0], (const uint8 *) "      STOP      ", 16);
            	led_on(LED_PC6);
            	led_off(LED_PC7);
            }
            else {
            	led_on(LED_PC7);
            	led_off(LED_PC6);
            	//memcpy(&dataseq1[0], (const uint8 *) "       OK       ", 16);
            }


//            writetoLCD( 16, 1, dataseq1); //send some data

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



