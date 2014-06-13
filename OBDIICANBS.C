/*
 * OBDIICANBS.C
 *
 *  Created on: May 20, 2014
 *      Author: Aqeel
 */
#include "OBDIICANBS.h"
//#include <DAVE3.h>
//#include <inttypes.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdio.h>
//#include <string.h>

// return false if pid is not supported, true if it is.
//// mode is 0 for get_pid() and 1 for menu config to allow pid > 0xF0
//bool is_pid_supported(unsigned char pid, unsigned char mode)
//{
//  if(pid==0)
//    return true;
//  else
//  if(pid<=0x20)
//  {
//    if(1L<<(uint8_t)(0x20-pid) & pid01to20_support)
//      return true;
//  }
//  else
//  if(pid<=0x40)
//  {
//    if(1L<<(uint8_t)(0x40-pid) & pid21to40_support)
//      return true;
//  }
//  else
//  if(pid<=0x60)
//  {
//    if(1L<<(uint8_t)(0x60-pid) & pid41to60_support)
//      return true;
//  }
//  else
//  if( mode && pid>=FIRST_FAKE_PID)
//    return true;
//
//  return false;
//}
/*
void PrintData(uint8_t CAN_Frames)
{
if(CAN_Rx_Flag==CAN_PACKET_RX_ERROR)
	status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);

ECU_Val=CanRecMsgObj[CAN_RX_Pkt_Count].Identifier;
Data_Len=CanRecMsgObj[CAN_RX_Pkt_Count].data[0];
MODE_Val=((CanRecMsgObj[CAN_RX_Pkt_Count].data[1])-(0x40));
PID_Val=CanRecMsgObj[CAN_RX_Pkt_Count].data[2];
sprintf(can_uart_buffer,"ECU ID=0x%.4X PID=0x%.2X M=0x%.2X\n\r",ECU_Val,PID_Val,MODE_Val);
status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
delay();
if(MODE_Val==MODE_CURR_DATA)
{
	switch (PID_Val)//PID query Message is same in response
	{
	case PID_SUPPORT00:
		sprintf(can_uart_buffer,"PIDs=0x%.2X,0x%.2X,0x%.2X,0x%.2X\r\n",CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6]);
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		break;
	case COOLANT_TEMP:
		sprintf(can_uart_buffer,"COOLANT_TEMP = %d C.  \r\n ",(CanRecMsgObj[CAN_RX_Pkt_Count].data[3])-(40));
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		break;

	case OBD_STD:
		sprintf(can_uart_buffer,"%s=%s,\r\n",PID_Desc[PID_Val],obd_std_strings[CanRecMsgObj[CAN_RX_Pkt_Count].data[3]]);
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		break;
	case ENGINE_RPM:
		Engine_RPM=(((CanRecMsgObj[CAN_RX_Pkt_Count].data[3]*256)+CanRecMsgObj[CAN_RX_Pkt_Count].data[4])/4);
		sprintf(can_uart_buffer,"%s=%0.2f RPM,\r\n",PID_Desc[PID_Val],Engine_RPM);
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		break;
	case VEHICLE_SPEED:
		Vehicle_Speed=CanRecMsgObj[CAN_RX_Pkt_Count].data[3];
		sprintf(can_uart_buffer,"%s=%0.2f KM,\r\n",PID_Desc[PID_Val],Vehicle_Speed);
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		break;

	default:
		sprintf(can_uart_buffer,"data=0x%.2X,0x%.2X,0x%.2X,0x%.2X\r\n",CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6]);
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		break;
	}
}
else if(MODE_Val==MODE_DTC)
{
switch(PID_Val)
	{
		case PID_SUPPORT00:
			sprintf(can_uart_buffer,"PIDs=0x%.2X,0x%.2X,0x%.2X,0x%.2X\r\n",CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6]);
			status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
			break;
		default:
			sprintf(can_uart_buffer,"data=0x%.2X,0x%.2X,0x%.2X,0x%.2X\r\n",CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6]);
			status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
			break;
	}
}
else if(Data_Len&0x10)//MODE_Val==MODE_REQ_VIN || MODE_Val==0xD4)
{
//			switch(PID_Val)
//				{
//					case ( Data_Len&0x30 ):
			sprintf(can_uart_buffer,"FF=0x%.2X,0x%.2X,%c,%c,%c,%c,%c,%c\r\n",Data_Len,CanRecMsgObj[CAN_RX_Pkt_Count].data[1],PID_Val,CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6],CanRecMsgObj[CAN_RX_Pkt_Count].data[7]);
			status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
}
//						break;
//					case Data_Len&0x20://VIN_NUM:
else if(Data_Len&0x20)
{
			sprintf(can_uart_buffer,"CF=0x%.2X,%c,%c,%c,%c,%c,%c,%c\r\n",Data_Len,CanRecMsgObj[CAN_RX_Pkt_Count].data[1],PID_Val,CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6],CanRecMsgObj[CAN_RX_Pkt_Count].data[7]);
			status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
}
//						break;
//					default:
//						sprintf(can_uart_buffer,"data=0x%.2X,0x%.2X,0x%.2X,0x%.2X\r\n",CanRecMsgObj[CAN_RX_Pkt_Count].data[3],CanRecMsgObj[CAN_RX_Pkt_Count].data[4],CanRecMsgObj[CAN_RX_Pkt_Count].data[5],CanRecMsgObj[CAN_RX_Pkt_Count].data[6]);
//						status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
//						break;
//				}
//			}
else	{
		sprintf(can_uart_buffer,"R=x%.2X,x%.2X,x%.2X,x%.2X,x%.2X,x%.2X,x%.2X,x%.2X\r\n",CanRecMsgObj[CAN_RX_Pkt_Count].data[0] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[1] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[2] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[3] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[4] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[5] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[6] ,CanRecMsgObj[CAN_RX_Pkt_Count].data[7] );
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_buffer, (uint32_t)strlen(can_uart_buffer)+1);
		}
UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&data_uart_end, (uint32_t)strlen(data_uart_end)+1);
	}
*/
/*void StoreData(uint8_t CAN_Frames)
{

	uint8_t Data_Rx[8];
	memcpy(Data_Rx,&CanRecMsgObj[CAN_RX_Pkt_Count].data[0],8);
	if(CAN_Rx_Flag==CAN_PACKET_RX_ERROR)
		status=UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&can_uart_error, (uint32_t)sizeof(can_uart_error)/2);
	else
		{
			ECU_Val=CanRecMsgObj[CAN_RX_Pkt_Count].Identifier;
			ECU_Test.ECU_Add=ACU_Val;
			Data_Len=Data_Rx[0];
			MODE_Val=(Data_Rx[1]-0x40);
			PID_Val=Data_Rx[2];
		if(MODE_Val==MODE_CURR_DATA)
			{
				switch (PID_Val)//PID query Message is same in response
				{
				case PID_SUPPORT00:
					pid01to20_support=(unsigned long)((Data_Rx[3])&(Data_Rx[4]>>8)&(Data_Rx[5]>>16)&(Data_Rx[6]>>24));
					break;
				case PID_SUPPORT20:
					pid21to40_support=(unsigned long)((Data_Rx[3])&(Data_Rx[4]>>8)&(Data_Rx[5]>>16)&(Data_Rx[6]>>24));
					break;
				case PID_SUPPORT20:
					pid41to60_support=(unsigned long)((Data_Rx[3])&(Data_Rx[4]>>8)&(Data_Rx[5]>>16)&(Data_Rx[6]>>24));
					break;
				case COOLANT_TEMP:
					ECU_Test.Coolant_Temp=(Data_Rx[3]-40);
					break;
				case OBD_STD:
					memcpy(ECU_Test.ODB_Std,&obd_std_strings[Data_Rx[3]],10);
					break;
				case ENGINE_RPM:
					ECU_Test.Engine_RPM=(float)(((Data_Rx[3]*256)+Data_Rx[4])/4);
					break;
				case VEHICLE_SPEED:
					ECU_Test.Vehicle_speed=Data_Rx[3];
					break;
				case FUEL_LEVEL:
					ECU_Test.Feul_Level=(float)((Data_Rx[3]*100)/255);//A*100/255
					break;
				default:
				}
			}
		else if(MODE_Val==MODE_REQ_VIN)
		{
			switch (PID_Val)//PID query Message is same in response
			{
			case PID_SUPPORT00:
				pid01to20M09_support=(unsigned long)((Data_Rx[3])&(Data_Rx[4]>>8)&(Data_Rx[5]>>16)&(Data_Rx[6]>>24));
				break;
			default:
			}
		}
		else if(Data_Len&0x10)// First Frame for VIN Check
		{

			memcpy(ECU_Test.VIN_Num,&Data_Rx[2],6);
		}
		else if(Data_Len&0x20)
		{
			switch (Data_len)
			{
			case 0x21:
				memcpy(&ECU_Test.VIN_Num[6],&Data_Rx[0],8);
				break;
			case 0x22:
				memcpy(&ECU_Test.VIN_Num[6+8],&Data_Rx[0],8);
				break;
			case 0x23:
				memcpy(&ECU_Test.VIN_Num[6+8+8],&Data_Rx[0],8);
				break;
			default:
			}
		}

	}//first Else Ends here.
}
void PrintData(uint8_t CAN_Frames,uint8_t Param)
{
	char buffer[50];
/*	bool Uconnection;  // are we connected to the ECU or not
	uint8_t ECU_No;
	uint16_t ECU_Add;
	char ODB_Std[12];
	uint8_t	PID_Supported[10][4];	//[Mode][PIDs]
	float Engine_RPM;
	uint8_t Vehicle_speed;
	uint8_t Coolant_Temp;
	uint16_t Engine_Run_Time;
	float Feul_Level;
	char VIN_Num[20];*/

	/*switch(Parameters)
	{
	case PRINT_NOTHING:
		break;
	case PRINT_ECU_INFO:
		sprintf(&buffer[0],"ECU=x%.2X,PID=x%.8X\r\n",ECU_Test.ECU_Add,pid01to20_support);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		sprintf(&buffer[0],"VIN=%s\r\n",ECU_Test.VIN_Num);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		break;
	case PRINT_VEICAL_DATA:
		sprintf(&buffer[0],"RPM=%.2f,\tSPD=%d\r\n",ECU_Test.ECU_Add,pid01to20_support);
		UART001_WriteDataBytes(&UART001_Handle0, (uint8_t*)&buffer, (uint32_t)strlen(buffer)+1);
		break;
	default:
	}
}
*/
