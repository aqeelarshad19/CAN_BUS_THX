/*
 * Main.c
 *
 *  Created on: May 19, 2014
 *      Author: Aqeel
 */
#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "Timer.h"
#include "OBDIICANBS.h"
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <newlib.h>
#define Seat_Leon
//#define Audi
//#define Sniffer
#ifdef Sniffer
uint8_t Sniffer_Buffer[30];
#else
uint8_t CAN_RX_Buffer[30];
#endif

void delay(void);
uint8_t StoreData(uint8_t Mode);
void PrintData(uint8_t Param,uint8_t ECU_Index);
void print_Uart(char Str[]);
bool is_pid_supported(unsigned char pid, unsigned char mode,uint8_t ECU_Index);
//void TimerOneSec(void * args);
//void TimerInt(void * args);
//void TimerWaitISR (void * args);

uint8_t Get_PID(uint16_t TimeToWait,uint8_t Mode_Req,uint8_t PID_Req,uint8_t ShowOP);
uint8_t Get_VIN(uint8_t TimeToWait);
void Send_Data(uint32_t Id,uint8_t Data[]);
//CAN001_MessageHandleType CanTxMsgObj;
int main(void)
{
	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	uint8_t Data_USD1[8] 	= 	{0x1F,0xC0,0x00,0x10,0x00,0x03,0x01,0x00};	//1F C0 00 10 00 03 01 00
	uint8_t Data_USD2[8] 	= 	{0x1F,0xC0,0x00,0x10,0x00,0x03,0x01,0x80};	//1F C0 00 10 00 03 01 80
	uint8_t Data_USD3[8] 	= 	{0xA8,0xC0,0x00,0x10,0x00,0x03,0x01,0x80};	//A8 C0 00 10 00 03 01 80
	uint8_t Data_DSC[8]  	= 	{0x02,0x10,0x03,0x00,0x00,0x00,0x00,0x00};	//02 10 03 00 00 00 00 00
	uint8_t Data_ReadOdo[8] = 	{0x03,0x22,0x22,0x03,0x00,0x00,0x00,0x00};	//03 22 22 03 00 00 00 00
	uint8_t Data_ReadUFO[8] = 	{0x03,0x22,0x22,0x61,0x00,0x00,0x00,0x00};	//03 22 22 61 00 00 00 00 //decode Whats this
	uint8_t Data_ReadFIN[8] = 	{0x03,0x22,0xF1,0x90,0x00,0x00,0x00,0x00};	//03 22 F1 90 00 00 00 00	//FIN ISO 14229

	uint8_t Btn1;
//	uint8_t VIN_Supp[] = "VIN NOT Supported.... \n\r";
//	uint8_t CALID_Supp[] = "CALID NOT Supported...\n\r";
	uint8_t ECU_Index=0;

	DAVE_Init();			// Initialization of DAVE Apps
    TimerId = SYSTM001_CreateTimer(50,SYSTM001_ONE_SHOT,TimerInt,NULL);
//    TimerId1Sec = SYSTM001_CreateTimer(2000,SYSTM001_PERIODIC,TimerOneSec,NULL);
    Timer_WaitId=SYSTM001_CreateTimer(4000,SYSTM001_ONE_SHOT,TimerWaitISR,NULL);



    CanTxMsgObj.Identifier=FUNC_PID_REQUEST;
	CanTxMsgObj.DataLength=8;
	CanTxMsgObj.data[0]=Data[0];
	CanTxMsgObj.data[1]=Data[1];
	CanTxMsgObj.data[2]=Data[2];
	CanTxMsgObj.data[3]=Data[3];
	CanTxMsgObj.data[4]=Data[4];
	CanTxMsgObj.data[5]=Data[5];
	CanTxMsgObj.data[6]=Data[6];
	CanTxMsgObj.data[7]=Data[7];
	CanTxMsgObj.IDExten=STANDARDTYPE;
	CanTxMsgObj.MsgObjEN=CAN001_ENABLE;
	CanTxMsgObj.MsgObjType=TRANSMSGOBJ;
	CanTxMsgObj.IDMask=0x00;
	CanTxMsgObj.IDExten=0x00;

	status=CAN001_ConfigMsgObj(&CAN001_Handle0,&CanTxMsgObj,1U);
	  /* Update data value to be transmitted by  Node "Request" in message object 1 (LM01) with ID 0x255 */
	  CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data);
	  /* Send Data frame with ID 0x255 on chip internal CAN bus (Loop-Back Mode) */
//	  status=CAN001_SendDataFrame(&CAN001_Handle0,1); //

	  Btn1 = IO004_ReadPin(IO004_Handle1);
	  IO004_SetOutputValue(IO004_Handle0,1);
	  IO004_SetOutputValue(IO004_Handle2,1);
//	  printf("hello world");
//	  UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&data_uart, (uint32_t)strlen(data_uart));
#ifndef Sniffer
	  for(double i=0;i<5000;i++);
	  print_Uart("M0 P00 \n\r");
	  Get_PID(1000,MODE_CURR_DATA,PID_SUPPORT00,PRINT_NOTHING);
		for(double i=0;i<5000;i++);
	  print_Uart("M0 P20 \n\r");
	  Get_PID(1000,MODE_CURR_DATA,PID_SUPPORT20,PRINT_NOTHING);
	for(double i=0;i<5000;i++);
		print_Uart("M9 P00 \n\r");
		Get_PID(1000,MODE_REQ_VIN,PID_SUPPORT00,PRINT_NOTHING);
	for(double i=0;i<5000;i++);
		print_Uart("M9 P02 \n\r");
		Get_PID(2000,MODE_REQ_VIN,VIN_NUM,PRINT_ECU_INFO);
//		for(double i=0;i<5000;i++);
//			print_Uart("M9 P04 \n\r");
//			Get_PID(2000,MODE_REQ_VIN,CAL_ID,PRINT_ECU_INFO);

		if(is_pid_supported(FUEL_LEVEL, MODE_CURR_DATA,0)||(is_pid_supported(FUEL_LEVEL, MODE_CURR_DATA,1)))
			print_Uart("PID2F=1 \n\r");
		else
			print_Uart("PID2F=0 \n\r");
#else
		  print_Uart("Sniffer \n\r");
#endif
	  while(1){
//		  if(!(IO004_ReadPin(IO004_Handle1)))
//		SYSTM001_StartTimer (TimerId1Sec);
//		  else if()
#ifndef Sniffer
		  {
				for(double i=0;i<5000;i++);
		//print_Uart("M0 P00 \n\r");
				Get_PID(500,MODE_CURR_DATA,ENGINE_RPM,PRINT_NOTHING);
				for(double i=0;i<5000;i++);
		//print_Uart("M0 P20 \n\r");
				Get_PID(500,MODE_CURR_DATA,RUNTIME_START,PRINT_NOTHING);
		  	  for(double i=0;i<5000;i++);
		//print_Uart("M9 P00 \n\r");
		  	  Get_PID(500,MODE_CURR_DATA,FUEL_LEVEL,PRINT_NOTHING);
				for(double i=0;i<5000;i++);
		//print_Uart("M9 P00 \n\r");
				Get_PID(500,MODE_CURR_DATA,VEHICLE_SPEED,PRINT_VEHICAL_DATA);
				delay();

				Timer_WaitId = SYSTM001_CreateTimer(3000,SYSTM001_ONE_SHOT,TimerWaitISR,NULL);
				Timer_Wait_Expired=FALSE;
				SYSTM001_StartTimer (Timer_WaitId);
				while(!Timer_Wait_Expired);
				for(double i=0;i<50000;i++);
				delay();
				Send_Data(0x0200,Data_USD1);
				delay();
				Send_Data(0x0200,Data_USD1);
				delay();
				Send_Data(0x0200,Data_USD2);
				delay();
				Send_Data(0x0200,Data_USD3);
				delay();
				Send_Data(0x0200,Data_USD3);
				delay();
				Send_Data(0x0200,Data_USD3);
				delay();
				Send_Data(0x0714,Data_DSC);
				delay();
				Send_Data(0x0714,Data_ReadOdo);
				delay();
				for(double i=0;i<500000;i++);
				IO004_TogglePin(IO004_Handle0);
		  }
#endif
	  }
	  	return 0;
	  }

/*    if(Status == DAVEApp_SUCCESS)
 *    {
 *      //wait till data frame is received.
 *      while(!(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING)))
 *      {}
 *      // Read CAN message to handle CanRecMsgObj
 *      CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);
 *    }
 */
// CAN RX INTERRUPT ISR
void EventHandlerCAN001_0()

	{
	//CAN_RX_Pkt_Count++;
//		/* Check transmit pending status in LMO1 */
//		if(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,TRANSMIT_PENDING) == CAN_SET)
//		{
//			/* Clear the flag */
//			CAN001_ClearMOFlagStatus(&CAN001_Handle0,1,TRANSMIT_PENDING);
//		}
		/* Check receive pending status in LMO2 */
		if(CAN001_GetMOFlagStatus(&CAN001_Handle0,2,RECEIVE_PENDING) == CAN_SET)
		{
			/* Clear the flag */
			CAN001_ClearMOFlagStatus(&CAN001_Handle0,2,RECEIVE_PENDING);
			/* Read the received Message object and stores in variable CanRecMsgObj */
			CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj[CAN_RX_Pkt_Count],2);
#ifndef Sniffer
			if((CanRecMsgObj[CAN_RX_Pkt_Count].Identifier==0x7e8) |(CanRecMsgObj[CAN_RX_Pkt_Count].Identifier==0x7e9))
			{
				if(CanRecMsgObj[CAN_RX_Pkt_Count].data[0]==0x10)
				SYSTM001_StartTimer (TimerId);
				/* Switch on LED Pin 1.1  to indicate that the requested message is received*/
				IO004_TogglePin(IO004_Handle2);
				CAN_Rx_Flag=CAN_PACKET_RECEIVED;
				CAN_RX_Pkt_Count++;
//				if(	CAN_RX_Pkt_Count)
			}
//			else if((CanRecMsgObj[CAN_RX_Pkt_Count].Identifier==0x17F00010) );
			else
			{
				sprintf(&CAN_RX_Buffer[0],"ID=x%.4X,D=%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X \r\n",CanRecMsgObj[CAN_RX_Pkt_Count].Identifier,CanRecMsgObj[CAN_RX_Pkt_Count].data[0],\
						CanRecMsgObj[CAN_RX_Pkt_Count].data[1],CanRecMsgObj[CAN_RX_Pkt_Count].data[2],CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],\
						CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6],CanRecMsgObj[CAN_RX_Pkt_Count].data[7]);
				UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&CAN_RX_Buffer, (uint32_t)strlen(CAN_RX_Buffer)+1);
			}
#endif
#ifdef Sniffer
//			if(CanRecMsgObj[CAN_RX_Pkt_Count].Identifier!=0x17F00010)
			if((CanRecMsgObj[CAN_RX_Pkt_Count].data[2]!=0x0C) && ((CanRecMsgObj[CAN_RX_Pkt_Count].data[1]!=0x41) || (CanRecMsgObj[CAN_RX_Pkt_Count].data[1]!=0x01)))
			{
			sprintf(&Sniffer_Buffer[0],"ID=x%.4X,D=%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X \r\n",CanRecMsgObj[CAN_RX_Pkt_Count].Identifier,CanRecMsgObj[CAN_RX_Pkt_Count].data[0],\
					CanRecMsgObj[CAN_RX_Pkt_Count].data[1],CanRecMsgObj[CAN_RX_Pkt_Count].data[2],CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6],\
					CanRecMsgObj[CAN_RX_Pkt_Count].data[7]);
			UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&Sniffer_Buffer, (uint32_t)strlen(Sniffer_Buffer)+1);
			}
#endif
//			ECU_Test[ECU_Index].Uconnection=TRUE;
			//temp++;
		}
		/* Check for Node error */
		if(CAN001_GetNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS) == CAN_SET)
		{
			/* Clear the flag */
			CAN001_ClearNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS);
			CAN_Rx_Flag=CAN_PACKET_RX_ERROR;
		}
	}
//void delay(void)
//{
//for(double i=0;i<5000;i++);
//}

uint8_t StoreData(uint8_t Pid)
{

	uint8_t Data_Rx[8];
	uint8_t Error=1;
	uint8_t ECU_Index=0;
	memcpy(Data_Rx,&CanRecMsgObj[CAN_RX_Pkt_Count].data[0],8);
	if(CAN_Rx_Flag==CAN_PACKET_RX_ERROR)
		return Error=CAN_PACKET_RX_ERROR;
		//UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);
	else
		{
			ECU_Val=CanRecMsgObj[CAN_RX_Pkt_Count].Identifier;
			ECU_Index=ECU_Val-0x7E8;
			ECU_Test[ECU_Index].ECU_Add=ECU_Val;
			Data_Len=Data_Rx[0];
			MODE_Val=(Data_Rx[1]-0x40);
			PID_Val=Data_Rx[2];

			if(MODE_Val==MODE_CURR_DATA)
			{
				switch (PID_Val)//PID query Message is same in response
				{
				case PID_SUPPORT00:
					ECU_Test[ECU_Index].pid01to20_support=(unsigned long)((Data_Rx[3]<<24)|(Data_Rx[4]<<16)|(Data_Rx[5]<<8)|(Data_Rx[6]));
					break;
				case PID_SUPPORT20:
					ECU_Test[ECU_Index].pid21to40_support=(unsigned long)((Data_Rx[3]<<24)|(Data_Rx[4]<<16)|(Data_Rx[5]<<8)|(Data_Rx[6]));
					break;
				case PID_SUPPORT40:
					ECU_Test[ECU_Index].pid41to60_support=(unsigned long)((Data_Rx[3]<<24)|(Data_Rx[4]<<16)|(Data_Rx[5]<<8)|(Data_Rx[6]));
					break;
				case COOLANT_TEMP:
					ECU_Test[ECU_Index].Coolant_Temp=(Data_Rx[3]-40);
					break;
				case OBD_STD:
					memcpy(ECU_Test[ECU_Index].ODB_Std,&obd_std_strings[Data_Rx[3]],10);
					break;
				case ENGINE_RPM:
					ECU_Test[ECU_Index].Engine_RPM=(float)(((Data_Rx[3]*256)+Data_Rx[4])/4);
					break;
				case VEHICLE_SPEED:
					ECU_Test[ECU_Index].Vehicle_speed=Data_Rx[3];
					break;
				case FUEL_LEVEL:
					ECU_Test[ECU_Index].Feul_Level=(float)(((float)Data_Rx[3]*100)/255);//A*100/255
					break;
				case RUNTIME_START:
					ECU_Test[ECU_Index].Engine_Run_Time=(float)((Data_Rx[3]*256)+Data_Rx[4]);//A*100/255
					break;
				default:
					UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);
					Error=MODE_CURR_DATA;
				}
			}
		else if(MODE_Val==MODE_REQ_VIN)
		{
			switch (PID_Val)//PID query Message is same in response
			{
			case PID_SUPPORT00:
				ECU_Test[ECU_Index].pid01to20M09_support=(unsigned long)((Data_Rx[3]<<24)|(Data_Rx[4]<<16)|(Data_Rx[5]<<8)|(Data_Rx[6]));
				break;
			default:
				UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);
				Error=MODE_REQ_VIN;
			}
		}
		else if(Data_Len&0x10)// First Frame for VIN Check
		{
			if(Pid==VIN_NUM)
			memcpy(ECU_Test[ECU_Index].VIN_Num,&Data_Rx[2],6);
			else
			memcpy(ECU_Test[ECU_Index].CAL_Id,&Data_Rx[2],6);
		}
		else if(Data_Len&0x20)
		{
			if(Pid==VIN_NUM)
				switch (Data_Len)
				{
				case 0x21:
					memcpy(&ECU_Test[ECU_Index].VIN_Num[6],&Data_Rx[0],8);
					break;
				case 0x22:
					memcpy(&ECU_Test[ECU_Index].VIN_Num[6+8],&Data_Rx[0],8);
					break;
				case 0x23:
					memcpy(&ECU_Test[ECU_Index].VIN_Num[6+8+8],&Data_Rx[0],8);
					break;
				default:
					UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);
					Error=MODE_REQ_VIN;
				}
			else
			switch (Data_Len)
				{
				case 0x21:
					memcpy(&ECU_Test[ECU_Index].CAL_Id[6],&Data_Rx[0],8);
					break;
				case 0x22:
					memcpy(&ECU_Test[ECU_Index].CAL_Id[6+8],&Data_Rx[0],8);
					break;
				case 0x23:
					memcpy(&ECU_Test[ECU_Index].CAL_Id[6+8+8],&Data_Rx[0],8);
					break;
				default:
					UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);
					Error=MODE_REQ_VIN;
				}
		}

		return Error;
		}//first Else Ends here.
}
void PrintData(uint8_t Param,uint8_t ECU_Index)
{
	char buffer[50];
	switch(Param)
	{
	case PRINT_NOTHING:
		break;
	case PRINT_ECU_INFO:
		sprintf(&buffer[0],"ECU=x%.2X,PID_00=x%.8X\r\n",ECU_Test[ECU_Index].ECU_Add,ECU_Test[ECU_Index].pid01to20_support);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		delay();
		sprintf(&buffer[0],"ECU=x%.2X,PID_20=x%.8X\r\n",ECU_Test[ECU_Index].ECU_Add,ECU_Test[ECU_Index].pid21to40_support);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		delay();
		sprintf(&buffer[0],"ECU=x%.2X,PID_M9=x%.8X\r\n",ECU_Test[ECU_Index].ECU_Add,ECU_Test[ECU_Index].pid01to20M09_support);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		delay();
		sprintf(&buffer[0],"VIN=%s\r\n",ECU_Test[ECU_Index].VIN_Num);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		delay();
//		sprintf(&buffer[0],"CAL ID=%s\r\n",ECU_Test[ECU_Index].CAL_Id);
//		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		break;
	case PRINT_VEHICAL_DATA:

		sprintf(&buffer[0],"RPM=%.2f,\tSPD=%d Km/h\r\n",ECU_Test[ECU_Index].Engine_RPM,ECU_Test[ECU_Index].Vehicle_speed);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		delay();
		sprintf(&buffer[0],"FUEL=%.2f L,\tRUNTIME=%d s\r\n",ECU_Test[ECU_Index].Feul_Level,ECU_Test[ECU_Index].Engine_Run_Time);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		break;
	default:
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error,(uint32_t)strlen(can_uart_error)+1);
	}
}
//void TimerInt(void * args) {
//	IO004_TogglePin(IO004_Handle2);
//	Timer_Flag=TRUE;//	while(!);
//	CanTxMsgObj.Identifier=PID_REQUEST;
//	CanTxMsgObj.data[1]=Data_Control_Frame[1];
//	CanTxMsgObj.data[2]=Data_Control_Frame[2];
//	CAN001_ConfigMsgObj(&CAN001_Handle0,&CanTxMsgObj,1U);
//
//	CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data_Control_Frame);
//	CAN001_SendDataFrame(&CAN001_Handle0,1); //
//	SYSTM001_StopTimer(TimerId);
//	SYSTM001_DeleteTimer(TimerId);
//    TimerId = SYSTM001_CreateTimer(100,SYSTM001_ONE_SHOT,TimerInt,NULL);
//}
//void TimerOneSec(void * args){
//	Timer_Flag_1sec=TRUE;
//	CAN_Tx_FLAG=TRUE;
//	time_secs++;
//	}

uint8_t Get_PID(uint16_t TimeToWait,uint8_t Mode_Req,uint8_t PID_Req,uint8_t ShowOP)
{
	//Check IF VIN is Supported
	//SEND GETVIN
	//WAIT till get reply or timer expires
	//	  //Send  VIN Number Query
	uint8_t Error;
	uint8_t Data_Rx_Flag=FALSE;
	//ECU_Test[ECU_Index].ID_Req=PID_Req;	//so we can differentiate bw VIN & CALID
	Data[1]=Mode_Req;
	Data[2]=PID_Req;
	CanTxMsgObj.Identifier=FUNC_PID_REQUEST;
	CanTxMsgObj.data[1]=Data[1];
	CanTxMsgObj.data[2]=Data[2];
	CAN001_ConfigMsgObj(&CAN001_Handle0,&CanTxMsgObj,1U);

	CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data);
	CAN001_SendDataFrame(&CAN001_Handle0,1);

	Timer_WaitId = SYSTM001_CreateTimer(TimeToWait,SYSTM001_ONE_SHOT,TimerWaitISR,NULL);
	Timer_Wait_Expired=FALSE;
	SYSTM001_StartTimer (Timer_WaitId);

	while(!Timer_Wait_Expired)
	{
		if(CAN_RX_Pkt_Count)
		{
			Data_Rx_Flag=TRUE;
			CAN_RX_Pkt_Count--;
			Error=StoreData(PID_Req);
		}
	}
#ifndef Sniffer
	if(Data_Rx_Flag)
	{
		Data_Rx_Flag=FALSE;
	if(ShowOP==PRINT_ECU_INFO)
		{
			PrintData(PRINT_ECU_INFO,0);
			delay();
			PrintData(PRINT_ECU_INFO,1);
			delay();
		}
		else if(ShowOP==PRINT_VEHICAL_DATA)
		{
			PrintData(PRINT_VEHICAL_DATA,0);
		}
	}
#endif
	return Error;
}
//
//void TimerWaitISR (void * args)
//{
//	Timer_Wait_Expired=TRUE;
//	SYSTM001_StopTimer(Timer_WaitId);
//	SYSTM001_DeleteTimer(Timer_WaitId);
//}
void print_Uart(char Str[])
{
char string[20];
uint8_t length;
length=strlen(Str);
memcpy(&string[0],&Str[0],length);
UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&string, (uint32_t)strlen(string)+1);
}


bool is_pid_supported(unsigned char pid, unsigned char mode,uint8_t ECU_Index)
{
	  if(pid==0)
		return TRUE;
	  else if(mode==MODE_CURR_DATA)
	  {
	  if(pid<=0x20)
	  {
		if(1L<<(uint8_t)(0x20-pid) & ECU_Test[ECU_Index].pid01to20_support)
		  return TRUE;
	  }
	  else
	  if(pid<=0x40)
	  {
		if(1L<<(uint8_t)(0x40-pid) & ECU_Test[ECU_Index].pid21to40_support)
		  return TRUE;
	  }
	  else
	  if(pid<=0x60)
	  {
		if(1L<<(uint8_t)(0x60-pid) & ECU_Test[ECU_Index].pid41to60_support)
		  return TRUE;
	  }
  }
  else
  if( mode==MODE_REQ_VIN)
  {
		if(1L<<(uint8_t)(0x20-pid) & ECU_Test[ECU_Index].pid01to20M09_support)
			  return TRUE;
  }
  return FALSE;
}
void Send_Data(uint32_t Id,uint8_t Data[])
{
		CanTxMsgObj.Identifier=Id;
		CanTxMsgObj.data[0]=Data[0];
		CanTxMsgObj.data[1]=Data[1];
		CanTxMsgObj.data[2]=Data[2];
		CanTxMsgObj.data[3]=Data[3];
		CanTxMsgObj.data[4]=Data[4];
		CanTxMsgObj.data[5]=Data[5];
		CanTxMsgObj.data[6]=Data[6];
		CanTxMsgObj.data[7]=Data[7];

		CAN001_ConfigMsgObj(&CAN001_Handle0,&CanTxMsgObj,1U);

		CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data);
		CAN001_SendDataFrame(&CAN001_Handle0,1);
		delay();
}
