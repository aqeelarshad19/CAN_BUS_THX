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
extern uint8_t Timer_Wait_Expired;
extern bool Timer_Flag;
extern bool Timer_Flag_1sec;
extern uint8_t time_secs;

void TimerOneSec(void * args);
void TimerInt(void * args);
//void TimerWaitISR (void * args);


#endif /* TIMER_H_ */
