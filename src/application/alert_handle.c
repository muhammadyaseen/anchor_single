/*
 * alert_handle.c
 *
 *  Created on: 16 Jun 2015
 *      Author: KFRL / Muhammad Yaseen
 */
#include "alert_handle.h"

void alert_init()
{
	emergency_flag = 0;
}

uint8_t is_accident()
{
	return emergency_flag;
}

int role_btn_on()
{
	return is_switch_on(ROLEBTN);
}

// stop  decision
void should_stop()
{
    uint8 dataseq[40];
	double range_result = 0;

    range_result = instance_get_idist();
    //set_rangeresult(range_result);
//    dataseq[0] = 0x2 ;  //return cursor home
//    writetoLCD( 1, 0,  dataseq);

//    memset(dataseq, ' ', 40);
//    sprintf((char*)&dataseq[1], "DIST: %4.2f m", range_result);
//    writetoLCD( 40, 1, dataseq); //send some data

//    if(range_result < CRITICAL_DISTANCE)
//    	memcpy(&dataseq[0], (const uint8 *) "      STOP      ", 16);
//    else
//    	memcpy(&dataseq[0], (const uint8 *) "       OK       ", 16);
//	writetoLCD( 16, 1, dataseq); //send some data
//	__WFE();
}
