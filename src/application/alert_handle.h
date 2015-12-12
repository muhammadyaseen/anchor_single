/*
 * alert_handle.h
 *
 *  Created on: 16 Jun 2015
 *      Author: KFRL/ Muhammad Yaseen
 */

#ifndef SRC_APPLICATION_ALERT_HANDLE_H_
#define SRC_APPLICATION_ALERT_HANDLE_H_

#include "port.h"
#include "instance.h"

uint8_t emergency_flag;

void alert_init(void);

uint8_t is_accident(void);

int role_btn_on(void);

void should_stop(void);

#endif

/* SRC_APPLICATION_ALERT_HANDLE_H_ */
