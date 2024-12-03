/*
 * uart.h
 *
 *  Created on: Dec 3, 2024
 *      Author: ADMIN
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "timer.h"
#include "main.h"
#include "stdio.h"

#define MAX_BUFFER_SIZE 30

extern	uint8_t temp;
extern	uint8_t buffer[MAX_BUFFER_SIZE];
extern	uint8_t index_buffer;
extern	uint8_t buffer_flag;

#define CMD_IDLE 	0
#define CMD_SAVING 	1

#define UART_IDLE 		10
#define UART_TRANSMIT 	11
#define UART_RES		12



void command_parser_fsm ();
void uart_communiation_fsm ();

#endif /* INC_UART_H_ */
