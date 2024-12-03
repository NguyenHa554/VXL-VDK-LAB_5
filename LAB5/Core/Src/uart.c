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


uint8_t cmd_temp[MAX_BUFFER_SIZE];
uint8_t cmd_stor[MAX_BUFFER_SIZE];
int cmd_cnt = 0;
int data_size = 0;

uint8_t	data[MAX_BUFFER_SIZE];

int cmd_parser = CMD_IDLE;
int uart_state = UART_IDLE;

void command_parser_fsm (){
	switch(cmd_parser){
		case CMD_IDLE:
			if(temp == '!'){
				cmd_parser = CMD_STOR;
				cmd_cnt = 0;
				memset(cmd_temp, 0, MAX_BUFFER_SIZE);
			}
			break;

		case CMD_STOR:
			if(temp == '#'){
				cmd_parser = CMD_IDLE;
				memcpy(cmd_stor, cmd_temp, MAX_BUFFER_SIZE);
			}
			else{
				cmd_temp[cmd_cnt++] = temp;
			}
			break;
		default:
			break;
	}
}


void uart_communiation_fsm (){
	switch(uart_state){
		case  UART_IDLE:
			if(strcmp((char*) cmd_stor, "RST") == 0){
				uart_state = UART_TRANSMIT;
				HAL_ADC_Start(&hadc1);
				data_size = sprintf((char*) data, "!ADC= %d# \r\n", (int) HAL_ADC_GetValue(&hadc1));
			}
			break;
		case UART_TRANSMIT:
			HAL_UART_Transmit(&huart2, data, data_size, 1000);
			uart_state = UART_WAIT;
			setTimer0(3000);
			break;
		case  UART_WAIT:
			if(strcmp((char*) cmd_stor, "OK") == 0){
				uart_state = UART_IDLE;
				memset(cmd_stor, 0, MAX_BUFFER_SIZE);
			}
			if(getFlag0()){
				uart_state = UART_TRANSMIT;
			}
			break;
		default:
			break;
	}
}
