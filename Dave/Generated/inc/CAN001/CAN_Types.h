/**************************************************************************//**
 *
 * Copyright (C) 2014 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.  
 * This file can be freely distributed within development tools that are 
 * supporting such microcontrollers. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series   			                          **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Jan 20, 2014                                           **
**                                                                            **
*******************************************************************************/

/**
 * @file CAN_Types.h
 *
 * @brief  This file defines common enums and macros used by different CAN Apps.
 *
 */

#ifndef CAN_TYPES_H_
#define CAN_TYPES_H_

/* Support for C++ codebase */
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/

#include <DAVE3.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Macro to avoid multiple re-definitions of the CAN global definitions */
#ifndef CAN_MACRO_GLOBAL_DEF
#define CAN_MACRO_GLOBAL_DEF

/* Standard ID Bitposition */
#define   CAN_MO_MOAR_STDID_Pos  		  (18)
/* Standard ID BitMask */
#define   CAN_MO_MOAR_STDID_Msk  		  ((0x000007FFUL)	<< CAN_MO_MOAR_STDID_Pos)

/** Macro to Calculate register offset value as per message object number */
/*DD_SIMPLE_CAN_MACRO_1*/
#define GET_MO_OFFSET(MsgObjnr) ((CAN_MO_TypeDef *)(CAN_BASE + \
                                              0x1000UL + (MsgObjnr * 0x0020UL)))

/** Macro to calculate message pending register offset value */
/*DD_SIMPLE_CAN_MACRO_2*/
#define GET_MSGPND_OFFSET(NodeID) ((uint32_t*)((CAN_BASE + 0x00000140UL) + (NodeID * 4UL)))
//#define GET_MSGPND_OFFSET(NodeID) ((uint32_t*)((0x48014140U) + (NodeID * 4)))

/** Macro to check receive pending bit of message object */
/*DD_SIMPLE_CAN_MACRO_3*/
#define CHECK_RXPND_BIT() (RD_REG(CAN_MOxRegs->MOSTAT, \
                           CAN_MO_MOSTAT_RXUPD_Msk, CAN_MO_MOSTAT_RXUPD_Pos))

/** Macro to check New data bit of message object */
/*DD_SIMPLE_CAN_MACRO_4*/
#define CHECK_NEWDATA_BIT() (RD_REG(CAN_MOxRegs->MOSTAT, \
                            CAN_MO_MOSTAT_NEWDAT_Msk, CAN_MO_MOSTAT_NEWDAT_Pos))

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/**
 * @ingroup CAN_publicparam
 * @{
 */

/**
 * This enumeration contains message object types
 */
typedef enum CAN_MsgType{
	/**
	 * Receive message object
	 */
	RECMSGOBJ,
	/**
	 * Transmit message object
	 */
	TRANSMSGOBJ
}CAN_MsgType;

/**
 * This enumeration contains message frame types
 */
typedef enum CAN_FrameType{
	/**
	 * Standard type identifier
	 */
	STANDARDTYPE,
	/**
	 * Extended type identifier
	 */
	EXTENDEDTYPE
}CAN_FrameType;


/**
 * This enumeration contains message object status information
 */
typedef enum CAN_MsgStatusType{
	/**
	 * To check Receive pending bit
	 */
	RECEIVE_PENDING = 1U,
	/**
	 * To check transmit pending bit
	 */
	TRANSMIT_PENDING = 2U,
	/**
	 * To check New data bit
	 */
	NEW_DATA = 8U,
	/**
	 * To check message lost bit
	 */
	MESSAGE_LOST = 16U,
}CAN_MsgStatusType;

/**
 * This enumeration contains CAN Status codes
 */
typedef enum CAN_StatusType {
	/**
	 * CAN module Reset
	 */
  CAN_RESET = 0U,
	/**
	 * Receive message object
	 */
  CAN_SET = 1U,
}CAN_StatusType;

/**
 * This enumeration contains CAN Bus Error codes
 */
typedef enum CAN_LastErrorCodeType {
/**
 * CAN transfer with no error
 */
  CAN_NO_ERROR = 0U,
/**
* CAN transfer with stuff error
*/
  CAN_STUFF_ERROR = 1U,
 /**
  * CAN transfer with form error
  */
  CAN_FORM_ERROR = 2U,
 /**
  * CAN transfer with ack error
  */
  CAN_ACK_ERROR = 3U,
  /**
   * CAN transfer with bit1 error
   */
  CAN_BIT1_ERROR = 4U,
  /**
    * CAN transfer with bit0 error
  */
  CAN_BIT0_ERROR = 5U,
  /**
   * CAN CRC error
  */
  CAN_CRC_ERROR = 6U
}CAN_LastErrorCodeType;

#endif
/**
 * This enumeration contains CAN interrupt type
 */
typedef enum CAN_InterruptType {
	/**
	 * Enables Node Alert Interrupt
	 */
  CAN_ALERT_INTERRUPT = CAN_NODE_NCR_ALIE_Msk,
	/**
	 * Enables Last Error code Interrupt
	 */
  CAN_LEC_INTERRUPT = CAN_NODE_NCR_LECIE_Msk,
  /**
  	* Enables MO transmit interrupt
  	*/
  CAN_MO_TRANSMIT_INTERRUPT = CAN_MO_MOFCR_TXIE_Msk,
  /**
  	* Enables MO transmit interrupt
  	*/
  CAN_MO_RECEIVE_INTERRUPT = CAN_MO_MOFCR_RXIE_Msk,
}CAN_InterruptType;

/**
 * @}
 */
 
/* Support for C++ codebase */
#ifdef __cplusplus
}
#endif 

 #endif /* CAN_TYPES_H_ */

 