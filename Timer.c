/*
 * timer.c
 *
 *  Created on: Jun 6, 2014
 *      Author: Aqeel
 */

#include "Timer.h"
#include "OBDIICANBS.h"
uint8_t Timer_Wait_Expired=FALSE;
bool Timer_Flag=FALSE;
bool Timer_Flag_1sec=FALSE;
uint8_t time_secs=0;

void delay(void)
{
	for(double i=0;i<5000;i++);
}


void TimerWaitISR (void * args)
{
	Timer_Wait_Expired=TRUE;
	SYSTM001_StopTimer(Timer_WaitId);
	SYSTM001_DeleteTimer(Timer_WaitId);
}

void TimerInt(void * args) {
	IO004_TogglePin(IO004_Handle2);
	Timer_Flag=TRUE;//	while(!);
	CanTxMsgObj.Identifier=PID_REQUEST;
	CanTxMsgObj.data[1]=Data_Control_Frame[1];
	CanTxMsgObj.data[2]=Data_Control_Frame[2];
	CAN001_ConfigMsgObj(&CAN001_Handle0,&CanTxMsgObj,1U);

	CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data_Control_Frame);
	CAN001_SendDataFrame(&CAN001_Handle0,1); //
	SYSTM001_StopTimer(TimerId);
	SYSTM001_DeleteTimer(TimerId);
    TimerId = SYSTM001_CreateTimer(100,SYSTM001_ONE_SHOT,TimerInt,NULL);
}

