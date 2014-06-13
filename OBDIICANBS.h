/*
 * OBDIICANBS.h
 * OBDII CAN BUS Implementation,
 *  Created on: May 20, 2014
 *      Author: Aqeel
 *
 */

//#ifndef OBDIICANBS_H_
//#define OBDIICANBS_H_

/* OBDII Scan Codes Definitions */
/* http://en.wikipedia.org/wiki/OBD-II_PIDs*/
/* http://www.openhardwarehub.com/revision/download_project_files/80*/
/* https://code.google.com/p/opengauge/wiki/OBDuino32K*/
/* For ISO 15765-2 CAN bus Transport layer protocol to receive multi-frame data .
 * http://www.canbushack.com/blog/index.php?title
 * =iso-15765-2-can-transport-layer-yes-it-can-be-fun&more=1&c=1&tb=1&pb=1
 */
//bool is_pid_supported(unsigned char pid, unsigned char mode);
//void PrintData(uint8_t,uint8_t );
//void StoreData(uint8_t);
#define DATA_PAD		0x00
#define MODE_CURR_DATA	0x01
#define MODE_FREZ_DATA	0x02
#define MODE_DTC		0x03
#define MODE_REQ_VIN	0x09

#define PRINT_NOTHING 0
#define PRINT_ECU_INFO 1
#define PRINT_VEHICAL_DATA 2


#define FUNC_PID_REQUEST	0x7DF

#define TESTER_PRESENT	0x3E

#define PID_REQUEST		0x07E0
#define PID_REQUEST1	0x07E1
#define PID_REQUEST2	0x07E2
#define PID_REQUEST3	0x07E3
#define PID_REQUEST4	0x07E4
#define PID_REQUEST5	0x07E5
#define PID_REQUEST6	0x07E6
#define PID_REQUEST7	0x07E7
#define PID_REPLY		0x07E8


/* PID stuff */

#define PID_SUPPORT00 0x00
#define MIL_CODE      0x01
#define FREEZE_DTC    0x02
#define FUEL_STATUS   0x03
#define LOAD_VALUE    0x04
#define COOLANT_TEMP  0x05
#define STFT_BANK1    0x06
#define LTFT_BANK1    0x07
#define STFT_BANK2    0x08
#define LTFT_BANK2    0x09
#define FUEL_PRESSURE 0x0A
#define MAN_PRESSURE  0x0B
#define ENGINE_RPM    0x0C
#define VEHICLE_SPEED 0x0D
#define TIMING_ADV    0x0E
#define INT_AIR_TEMP  0x0F
#define MAF_AIR_FLOW  0x10
#define THROTTLE_POS  0x11
#define SEC_AIR_STAT  0x12
#define OXY_SENSORS1  0x13
#define B1S1_O2_V     0x14
#define B1S2_O2_V     0x15
#define B1S3_O2_V     0x16
#define B1S4_O2_V     0x17
#define B2S1_O2_V     0x18
#define B2S2_O2_V     0x19
#define B2S3_O2_V     0x1A
#define B2S4_O2_V     0x1B
#define OBD_STD       0x1C
#define OXY_SENSORS2  0x1D
#define AUX_INPUT     0x1E
#define RUNTIME_START 0x1F
#define PID_SUPPORT20 0x20
#define DIST_MIL_ON   0x21
#define FUEL_RAIL_P   0x22
#define FUEL_RAIL_DIESEL 0x23
#define O2S1_WR_V     0x24
#define O2S2_WR_V     0x25
#define O2S3_WR_V     0x26
#define O2S4_WR_V     0x27
#define O2S5_WR_V     0x28
#define O2S6_WR_V     0x29
#define O2S7_WR_V     0x2A
#define O2S8_WR_V     0x2B
#define EGR           0x2C
#define EGR_ERROR     0x2D
#define EVAP_PURGE    0x2E
#define FUEL_LEVEL    0x2F
#define WARM_UPS      0x30
#define DIST_MIL_CLR  0x31
#define EVAP_PRESSURE 0x32
#define BARO_PRESSURE 0x33
#define O2S1_WR_C     0x34
#define O2S2_WR_C     0x35
#define O2S3_WR_C     0x36
#define O2S4_WR_C     0x37
#define O2S5_WR_C     0x38
#define O2S6_WR_C     0x39
#define O2S7_WR_C     0x3A
#define O2S8_WR_C     0x3B
#define CAT_TEMP_B1S1 0x3C
#define CAT_TEMP_B2S1 0x3D
#define CAT_TEMP_B1S2 0x3E
#define CAT_TEMP_B2S2 0x3F
#define PID_SUPPORT40 0x40
#define MONITOR_STAT  0x41
#define CTRL_MOD_V    0x42
#define ABS_LOAD_VAL  0x43
#define CMD_EQUIV_R   0x44
#define REL_THR_POS   0x45
#define AMBIENT_TEMP  0x46
#define ABS_THR_POS_B 0x47
#define ABS_THR_POS_C 0x48
#define ACCEL_PEDAL_D 0x49
#define ACCEL_PEDAL_E 0x4A
#define ACCEL_PEDAL_F 0x4B
#define CMD_THR_ACTU  0x4C
#define TIME_MIL_ON   0x4D
#define TIME_MIL_CLR  0x4E

#define LAST_PID      0x4E  // same as the last one defined above

/* Mode 09 PID definitions */

//#define PID_SUPPORT00 0x00 //already defined
//http://en.wikipedia.org/wiki/ISO_15765-2
//http://www.mp3car.com/engine-management-obd-ii-engine-diagnostics-etc/114765-obd-ii-can-mode-0x09-multi-line-messages.html
#define VIN_MESS_COUNT	0x01	//VIN Message Count in PID 02. Only for ISO 9141-2, ISO 14230-4 and SAE J1850.
#define VIN_NUM    		0x02	//17-char VIN, ASCII-encoded and left-padded with null chars (0x00) if needed to.
#define CAL_ID_COUNT   	0x03	//Calibration ID message count for PID 04. Only for ISO 9141-2, ISO 14230-4 and SAE J1850.
#define CAL_ID		    0x04	//Calibration ID message
#define CVN_COUNT		0x05	//Calibration verification numbers (CVN) message count for PID 06. Only for ISO 9141-2, ISO 14230-4 and SAE J1850.
#define CVN			    0x06	//Calibration Verification Numbers (CVN)
#define PER_TRK_COUNT   0x07	//In-use performance tracking message count for PID 08. Only for ISO 9141-2, ISO 14230-4 and SAE J1850.
#define PER_TRK		    0x08	//In-use performance tracking
#define ECU_NAME_COUNT  0x09	//ECU name message count for PID 0A
#define ECU_NAME 		0x0A	//ECU name
#define PER_TRK_B  		0x0B	//In-use performance tracking


#define STATUS_OK		0
#define STATUS_TIMEOUT	1
#define STATUS_FAILURE	2

#define NUM_READ_RETRY	4000
//
//class OBDIICanbusClass
//{
//  public:
//	static uint8_t init(uint8_t speed);
//	static uint8_t request(uint8_t pid,  uint8_t *buffer);
//	static uint8_t request_byId(uint16_t reqid, uint8_t pid,  uint8_t *buffer);
//	static uint8_t request_byIdnMode(uint8_t mode, uint16_t reqid, uint8_t pid,  uint8_t *buffer);
//	static uint8_t get_message(tCANMsg *message);
//};
//
//extern OBDIICanbusClass OBDIICanbus;
//
//unsigned long  pid01to20_support;  // this one always initialized at setup()
//unsigned long  pid21to40_support=0;
//unsigned long  pid41to60_support=0;
//unsigned long 	pid01to20M09_support=0;

//The Textual Description of each PID
unsigned char PID_Desc[256][9] =
{
"PID00-21", // 0x00   PIDs supported
"Stat DTC", // 0x01   Monitor status since DTCs cleared.
"Frz DTC",  // 0x02   Freeze DTC
"Fuel SS",  // 0x03   Fuel system status
"Eng Load", // 0x04   Calculated engine load value
"CoolantT", // 0x05   Engine coolant temperature
"ST F%T 1", // 0x06   Short term fuel % trim Bank 1
"LT F%T 1", // 0x07   Long term fuel % trim Bank 1
"ST F%T 2", // 0x08   Short term fuel % trim Bank 2
"LT F%T 2", // 0x09   Long term fuel % trim Bank 2
"Fuel Prs", // 0x0A   Fuel pressure
"  MAP  ",  // 0x0B   Intake manifold absolute pressure
"  RPM  ",  // 0x0C   Engine RPM
" Speed ",  // 0x0D   Vehicle speed
"Timing A", // 0x0E   Timing advance
"Intake T", // 0x0F   Intake air temperature
"MAF rate", // 0x10   MAF air flow rate
"Throttle", // 0x11   Throttle position
"Cmd SAS",  // 0x12   Commanded secondary air status
"Oxy Sens", // 0x13   Oxygen sensors present
"Oxy B1S1", // 0x14   Oxygen Sensor Bank 1, Sensor 1
"Oxy B1S2", // 0x15   Oxygen Sensor Bank 1, Sensor 2
"Oxy B1S3", // 0x16   Oxygen Sensor Bank 1, Sensor 3
"Oxy B1S4", // 0x17   Oxygen Sensor Bank 1, Sensor 4
"Oxy B2S1", // 0x18   Oxygen Sensor Bank 2, Sensor 1
"Oxy B2S2", // 0x19   Oxygen Sensor Bank 2, Sensor 2
"Oxy B2S3", // 0x1A   Oxygen Sensor Bank 2, Sensor 3
"Oxy B2S4", // 0x1B   Oxygen Sensor Bank 2, Sensor 4
"OBD Std",  // 0x1C   OBD standards this vehicle conforms to
"Oxy Sens", // 0x1D   Oxygen sensors present
"AuxInpt",  // 0x1E   Auxiliary input status
"Run Time", // 0x1F   Run time since engine start
"PID21-40", // 0x20   PIDs supported 21-40
"Dist MIL", // 0x21   Distance traveled with malfunction indicator lamp (MIL) on
"FRP RMF",  // 0x22   Fuel Rail Pressure (relative to manifold vacuum)
"FRP Dies", // 0x23   Fuel Rail Pressure (diesel)
"OxyS1 V",  // 0x24   O2S1_WR_lambda(1): ER Voltage
"OxyS2 V",  // 0x25   O2S2_WR_lambda(1): ER Voltage
"OxyS3 V",  // 0x26   O2S3_WR_lambda(1): ER Voltage
"OxyS4 V",  // 0x27   O2S4_WR_lambda(1): ER Voltage
"OxyS5 V",  // 0x28   O2S5_WR_lambda(1): ER Voltage
"OxyS6 V",  // 0x29   O2S6_WR_lambda(1): ER Voltage
"OxyS7 V",  // 0x2A   O2S7_WR_lambda(1): ER Voltage
"OxyS8 V",  // 0x2B   O2S8_WR_lambda(1): ER Voltage
"Cmd EGR",  // 0x2C   Commanded EGR
"EGR Err",  // 0x2D   EGR Error
"Cmd EP",   // 0x2E   Commanded evaporative purgeis
"Fuel LI",  // 0x2F   Fuel Level Input
"WarmupCC", // 0x30   # of warm-ups since codes cleared
"Dist CC",  // 0x31   Distance traveled since codes cleared
"Evap SVP", // 0x32   Evap. System Vapor Pressure
"Barometr", // 0x33   Barometric pressure
"OxyS1 C",  // 0x34   O2S1_WR_lambda(1): ER Current
"OxyS2 C",  // 0x35   O2S2_WR_lambda(1): ER Current
"OxyS3 C",  // 0x36   O2S3_WR_lambda(1): ER Current
"OxyS4 C",  // 0x37   O2S4_WR_lambda(1): ER Current
"OxyS5 C",  // 0x38   O2S5_WR_lambda(1): ER Current
"OxyS6 C",  // 0x39   O2S6_WR_lambda(1): ER Current
"OxyS7 C",  // 0x3A   O2S7_WR_lambda(1): ER Current
"OxyS8 C",  // 0x3B   O2S8_WR_lambda(1): ER Current
"C T B1S1", // 0x3C   Catalyst Temperature Bank 1 Sensor 1
"C T B1S2", // 0x3D   Catalyst Temperature Bank 1 Sensor 2
"C T B2S1", // 0x3E   Catalyst Temperature Bank 2 Sensor 1
"C T B2S2", // 0x3F   Catalyst Temperature Bank 2 Sensor 2
"PID41-60", // 0x40   PIDs supported 41-60
" MStDC",   // 0x41   Monitor status this drive cycle
"Ctrl M V", // 0x42   Control module voltage
"Abs L V",  // 0x43   Absolute load value
"Cmd E R",  // 0x44   Command equivalence ratio
"R ThrotP", // 0x45   Relative throttle position
"Amb Temp", // 0x46   Ambient air temperature
"Acc PP B", // 0x47   Absolute throttle position B
"Acc PP C", // 0x48   Absolute throttle position C
"Acc PP D", // 0x49   Accelerator pedal position D
"Acc PP E", // 0x4A   Accelerator pedal position E
"Acc PP F", // 0x4B   Accelerator pedal position F
"Cmd T A",  // 0x4C   Commanded throttle actuator
"T MIL On", // 0x4D   Time run with MIL on
"T TC Crl", // 0x4E   Time since trouble codes cleared
"  0x4F",   // 0x4F   Unknown
"  0x50",   // 0x50   Unknown
"Fuel Typ", // 0x51   Fuel Type
"Ethyl F%", // 0x52   Ethanol fuel %
"", // 0x53
"", // 0x54
"", // 0x55
"", // 0x56
"", // 0x57
"", // 0x58
"", // 0x59
"", // 0x5A
"", // 0x5B
"", // 0x5C
"", // 0x5D
"", // 0x5E
"", // 0x5F
"", // 0x60
"", // 0x61
"", // 0x62
"", // 0x63
"", // 0x64
"", // 0x65
"", // 0x66
"", // 0x67
"", // 0x68
"", // 0x69
"", // 0x6A
"", // 0x6B
"", // 0x6C
"", // 0x6D
"", // 0x6E
"", // 0x6F
"", // 0x70
"", // 0x71
"", // 0x72
"", // 0x73
"", // 0x74
"", // 0x75
"", // 0x76
"", // 0x77
"", // 0x78
"", // 0x79
"", // 0x7A
"", // 0x7B
"", // 0x7C
"", // 0x7D
"", // 0x7E
"", // 0x7F
"", // 0x80
"", // 0x81
"", // 0x82
"", // 0x83
"", // 0x84
"", // 0x85
"", // 0x86
"", // 0x87
"", // 0x88
"", // 0x89
"", // 0x8A
"", // 0x8B
"", // 0x8C
"", // 0x8D
"", // 0x8E
"", // 0x8F
"", // 0x90
"", // 0x91
"", // 0x92
"", // 0x93
"", // 0x94
"", // 0x95
"", // 0x96
"", // 0x97
"", // 0x98
"", // 0x99
"", // 0x9A
"", // 0x9B
"", // 0x9C
"", // 0x9D
"", // 0x9E
"", // 0x9F
"", // 0xA0
"", // 0xA1
"", // 0xA2
"", // 0xA3
"", // 0xA4
"", // 0xA5
"", // 0xA6
"", // 0xA7
"", // 0xA8
"", // 0xA9
"", // 0xAA
"", // 0xAB
"", // 0xAC
"", // 0xAD
"", // 0xAE
"", // 0xAF
"", // 0xB0
"", // 0xB1
"", // 0xB2
"", // 0xB3
"", // 0xB4
"", // 0xB5
"", // 0xB6
"", // 0xB7
"", // 0xB8
"", // 0xB9
"", // 0xBA
"", // 0xBB
"", // 0xBC
"", // 0xBD
"", // 0xBE
"", // 0xBF
"", // 0xC0
"", // 0xC1
"", // 0xC2
"", // 0xC3   Unknown
"", // 0xC4   Unknown
"", // 0xC5
"", // 0xC6
"", // 0xC7
"", // 0xC8
"", // 0xC9
"", // 0xCA
"", // 0xCB
"", // 0xCC
"", // 0xCD
"", // 0xCE
"", // 0xCF
"", // 0xD0
"", // 0xD1
"", // 0xD2
"", // 0xD3
"", // 0xD4
"", // 0xD5
"", // 0xD6
"", // 0xD7
"", // 0xD8
"", // 0xD9
"", // 0xDA
"", // 0xDB
"", // 0xDC
"", // 0xDD
"", // 0xDE
"", // 0xDF
"", // 0xE0
"", // 0xE1
"", // 0xE2
"", // 0xE3
"", // 0xE4
"", // 0xE5
"", // 0xE6
"OutsideT", // 0xE7   temperature outside car
"Inside T", // 0xE8   temperature inside car
"OutWaste", // 0xE9   outing waste
"TrpWaste", // 0xEA   trip waste
"TnkWaste", // 0xEB   tank waste
"Out Cost", // 0xEC   outing cost
"Trp Cost", // 0xED   trip cost
"Tnk Cost", // 0xEE   tank cost
"Out Time", // 0xEF   The length of time car has been running
"No Disp",  // 0xF0   No display
"InstCons", // 0xF1   instant cons
"Tnk Cons", // 0xF2   average cons of tank
"Tnk Fuel", // 0xF3   fuel used in tank
"Tnk Dist", // 0xF4   distance for tank
"Dist2MT",  // 0xF5   remaining distance of tank
"Trp Cons", // 0xF6   average cons of trip
"Trp Fuel", // 0xF7   fuel used in trip
"Trp Dist", // 0xF8   distance of trip
"Batt Vlt", // 0xF9   Battery Voltage
"Out Cons", // 0xFA   cons since the engine turned on
"Out Fuel", // 0xFB   fuel used since engine turned on
"Out Dist", // 0xFC   distance since engine turned on
"Can Stat", // 0xFD   Can Status
"PID_SEC",  // 0xFE
"Eco Vis",  // 0xFF   Visually display relative economy with text
};

unsigned char obd_std_strings[17][10] =
{
/*00*/	/*{ "" },*/ 	{ "OBD2CARB" }, { "OBDEPA" }, { "OBDEPA&2" },
/*04*/  { "OBD1" }, 	{ "NO OBD"   },	{ "EOBD" },   { "EOBD&ODB2" },
/*08*/  { "EOBD&EPA" }, { "E&EPA&2"  }, { "JOBD" },   { "JOBD&2" },
/*0C*/  { "J&EOBD"   }, { "J&EOBD&2" }, { "EURO4B1" }, { "EURO5B2" },
/*10*/  { "EURO C"   }, { "EMD" }
};

// returned length of the PID response.
// constants so put in flash
unsigned char pid_reslen[] =
{
  // pid 0x00 to 0x1F
  4,4,2,2,1,1,1,1,1,1,1,1,2,1,1,1,
  2,1,1,1,2,2,2,2,2,2,2,2,1,1,1,4,

  // pid 0x20 to 0x3F
  4,2,2,2,4,4,4,4,4,4,4,4,1,1,1,1,
  1,2,2,1,4,4,4,4,4,4,4,4,2,2,2,2,

  // pid 0x40 to 0x4E
  4,8,2,2,2,1,1,1,1,1,1,1,1,2,2
};

struct ECUinfo
{
	bool Uconnection;  // are we connected to the ECU or not
	uint8_t ECU_No;
	uint16_t ECU_Add;
	unsigned long  pid01to20_support;  // this one always initialized at setup()
	unsigned long  pid21to40_support;
	unsigned long  pid41to60_support;
	unsigned long pid01to20M09_support;
	char ODB_Std[12];
	uint8_t	PID_Supported[10][4];	//[Mode][PIDs]
	float Engine_RPM;
	uint8_t Vehicle_speed;
	uint8_t Coolant_Temp;
	uint16_t Engine_Run_Time;
	float Feul_Level;
	char VIN_Num[20];
	char CAL_Id[20];
	uint8_t ID_Req;

};
struct ECUinfo ECU_Test[2];

/** @brief data structure where the received CAN message object is transferred to */
CAN001_MessageHandleType CanRecMsgObj[6];
CAN001_MessageHandleType CanTxMsgObj;
uint8_t Data_Control_Frame[8]={0x30,0x00,0x55,0x00,0x00,0x00,0x00,0x00};	//0x3x,0xFM,0xinterval
uint8_t Data[8] = {0x02,0x01,0x20,0x00,0x00,0x00,0x00,0x00};

uint8_t data_uart[] = "OBD II TEST \n\r";
uint8_t can_uart_error[] = "Error While receiving CAN Packet";
uint8_t data_uart_end[]="====\n\r";
char can_uart_buffer[50];
uint8_t PID_Val;
uint8_t MODE_Val;
uint8_t Data_Len;
uint16_t ECU_Val;

float Engine_RPM=0;	//=0C
float Vehicle_Speed=0;
float Fuel_Level=0;
bool VIN_Flag=FALSE;
uint8_t CAN_Rx_Flag=0;
uint8_t CAN_Tx_FLAG=0;
uint8_t CAN_RX_Pkt_Count=0;
uint8_t temp=0;


#define CAN_PACKET_RECEIVED 1
#define CAN_PACKET_RX_ERROR 2

//#endif /* OBDIICANBS_H_ */
