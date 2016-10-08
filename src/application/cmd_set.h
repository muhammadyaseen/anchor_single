/*
 * cmd_set.h
 *
 *  Created on: Oct 8, 2016
 *      Author: Inspiron
 */

#ifndef CMD_SET_H_
#define CMD_SET_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "usart_queue.h"

#define CMD_SET_LEN 2

typedef enum {

	CMD_TYPE_READ,
	CMD_TYPE_WRITE

} CmdType;

typedef struct Cmd_Set {

	uint8_t * cmd_name;

	CmdType cmd_type;

	void (*execFxn)(void);

} CmdSet_Typedef;

void verinfFxn(void)
{
	USART_Puts("Version : 1.0.0-alpha", 21);
}

void cmdsetFxn(void)
{
	USART_Puts("VERINF\nCMDSET", 13);
}


CmdSet_Typedef commands[CMD_SET_LEN] = {
		{
				"VERINF",
				CMD_TYPE_READ,
				&verinfFxn
		},
		{
				"CMDSET",
				CMD_TYPE_READ,
				&cmdsetFxn
		},
};

void execDefault(void)
{
	USART_Puts("Command not recognized", 22);
}

//ASSUMING all Cmds are exactly 6 chars long
int decode_command(char * cmd)
{
	//yes, I know linear search is bad,
	//we can implement some dict or hash based search after prototyping
	for ( int i = 0; i < CMD_SET_LEN; i++ )
	{
		if ( strncmp(cmd, commands[i].cmd_name, 6) == 0 )
		{
			//we have a match, return command index
			return i;
		}
	}

	return -1;
}

int exec_command(int idx)
{
	if ( idx != -1)
		commands[idx].execFxn();
	else
		execDefault();

	return 0;
}


#ifdef __cplusplus
}
#endif


#endif /* _CMD_SET_H_ */
