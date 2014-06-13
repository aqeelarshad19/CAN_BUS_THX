/*
 * Timer.h
 *
 *  Created on: Jun 6, 2014
 *      Author: Aqeel
 */
#include "../../inc/SYSTM001/SYSTM001.h"
#ifndef TIMER_H_
#define TIMER_H_
handle_t Timer_WaitId;
handle_t TimerId;
handle_t TimerId1Sec;
uint8_t Timer_Wait_Expired=FALSE;
bool Timer_Flag=FALSE;
bool Timer_Flag_1sec=FALSE;
uint8_t time_secs=0;

void TimerOneSec(void * args);
void TimerInt(void * args);
void TimerWaitISR (void * args);


#endif /* TIMER_H_ */
