/*
 * uart.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ADMIN
 */


#include "uart.h"


uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;




int cmd_parser = CMD_IDLE;

void command_parser_fsm (){
	switch(cmd_parser){
		case CMD_IDLE:

			break;
		case CMD_SAVING:
			break;
		default:
			break;
	}
}
