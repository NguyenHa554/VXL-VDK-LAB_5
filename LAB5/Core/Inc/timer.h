/*
 * timer.h
 *
 *  Created on: Dec 3, 2024
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

void setTimer0 (int duration);
void setTimer1 (int duration);
void setTimer2 (int duration);
void setTimer3 (int duration);

void timer_run();

int getFlag0();
int getFlag1();
int getFlag2();
int getFlag3();

#endif /* INC_TIMER_H_ */
