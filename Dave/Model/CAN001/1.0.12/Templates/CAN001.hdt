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
** PLATFORM : Infineon XMC4000 Series                                         **
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

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** NPJ         App Developer                                                  **
*******************************************************************************/
/*
* Version History : 
* 12 Dec 2012    v1.0.2   1. Initial revision                              
*                                                                          
* 30 May 2013    v1.0.4   1. Fixes concerned with DisableMOInterrupt & EnableMOInterrupt api's
*   
* 21 Jun 2013    v1.0.6   1. Added a sample reference code for ALERT interrupt  
*   
* 22 Aug 2013    v1.0.8   1. Added macros which makes CAN nodes exit from the INIT state to NORAML state.
*
* 20 Jan 2014    v1.0.10  1. C++ support added
*                         2. Delay in app instantiation is resolved.
*/
/**
 * @file CAN001.h
 *
 * @brief  CAN001 App implementation header file.
 *
 */
 
 #ifndef CAN001_H_
 #define CAN001_H_
 
/* Support for C++ codebase */
#ifdef __cplusplus
extern "C" {
#endif
 /*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/

#include <DAVE3.h>
#include "CAN_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/**
 * @ingroup CAN_publicparam
 * @{
 */
/** Macro to Enable */
#define CAN001_ENABLE                       1U
/** Macro to Disable */
#define CAN001_DISABLE                      0U

/**
 * @}
 */

 
/**
 * @ingroup CAN001_apidoc
 * @{
 */
 
/** Macro function to enable node interrupt
 *
 * @param[in] Handle    :CAN App instance handle
 * @param[in] Interrupt :Interrupt to be enabled(Enum of type CAN_InterruptType)
 *
 * */
#define EnableNodeInterrupt(Handle,Interrupt) (Handle.CanNodeRegs->NCR |= Interrupt)

/** Macro function to Disable node interrupt
 *
 * @param[in] Handle    :CAN App instance handle
 * @param[in] Interrupt :Interrupt to be disabled(Enum of type CAN_InterruptType)
 *
 * */
#define DisableNodeInterrupt(Handle,Interrupt) (Handle.CanNodeRegs->NCR &= ~(Interrupt))

/** Macro function to enable MO interrupt
 *
 * @param[in] Handle    :CAN App instance handle
 * @param[in] Interrupt :Interrupt to be enabled(Enum of type CAN_InterruptType)
 * @param[in] MOnr : Logical MO number
 *
 * */
#define EnableMOInterrupt(Handle,Interrupt,MOnr) \
                          (((CAN_MO_TypeDef *)((uint32_t)(CAN_MO0_BASE) + \
                          ((Handle.FirstMOMapping+(MOnr-1)) * 0x0020)))->MOFCR |= Interrupt)


/** Macro function to enable MO interrupt
 *
 * @param[in] Handle    :CAN App instance handle
 * @param[in] Interrupt :Interrupt to be enabled(Enum of type CAN_InterruptType)
 * @param[in] MOnr : Logical MO number
 *
 * */
#define DisableMOInterrupt(Handle,Interrupt,MOnr) \
                         (((CAN_MO_TypeDef *)((uint32_t)(CAN_MO0_BASE) + \
                         ((Handle.FirstMOMapping+(MOnr-1)) * 0x0020)))->MOFCR &= ~(Interrupt))

/**
 * @}
 */
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/**
 * @ingroup CAN_publicparam
 * @{
 */


/**
 * This enumeration contains node status information
 */
typedef enum CAN001_NodeStatusType{
	/**
	 * To check Alert warning bit
	 */
	CAN001_ALERT_STATUS = 32U,
  /**
   * To check error warning status
   */
	CAN001_ERROR_WARN_STATUS = 64U,
  /**
   * To check Bus off status
   */
	CAN001_BUS_OFF_STATUS = 128U,
  /**
   * To check list length error
   */
	CAN001_LIST_LENGTH_ERROR = 256U,
	/**
	 * To check list object error
	 */
	CAN001_LIST_OBJECT_ERROR = 512U,
}CAN001_NodeStatusType;



/**
 * This enumeration contains CAN Error status
 */
typedef enum CAN001_ErrorCodesType {
 /**
   * Status returned when specified MO type(Transmit/Receive) is not acceptable
   */
 /**
   * @cond INTERNAL_DOCS
   * @param MODULENAME CAN001
   * @endcond
  */
 /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING1 CAN001_MO_NOT_ACCEPTABLE
   * @param STRCODESTRING1 Message object type not allowed
   * @endcond
  */
  CAN001_MO_NOT_ACCEPTABLE = 1U,
  /**
   * Status returned if MO is not available on node list
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING2 CAN001_MO_NOT_FOUND
   * @param STRCODESTRING2 MO not available in Node list
   * @endcond	
  */
  CAN001_MO_NOT_FOUND = 2U,
   /**
   * Status  returned if Message object is disabled
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING3 CAN001_MSGOBJ_DISABLED
   * @param STRCODESTRING3 MO Disabled
   * @endcond	
  */
  CAN001_MSGOBJ_DISABLED = 3U,
  /**
   * This code is returned if specified MO is currently transmitting or receiving
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING4 CAN001_MO_BUSY
   * @param STRCODESTRING4 MO Busy
   * @endcond	
  */
  CAN001_MO_BUSY = 4U,
  /**
   * Status returned when unknown error occurred
   */ 
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING5 CAN001_ERROR
   * @param STRCODESTRING5 Operation Failed
   * @endcond 
  */
  CAN001_ERROR = 5U,
  /**
   * Status returned when parameter passed to API are invalid
   */ 
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING6 CAN001_INVALID_INPUT
   * @param STRCODESTRING6 Invalid input
   * @endcond 
  */
  CAN001_INVALID_INPUT = 6U,
  /**
   * Entered a specific function
   */   
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING7 CAN001_FUNCTION_ENTRY
   * @param STRCODESTRING7 Entered Function \%s
   * @endcond 
  */
  CAN001_FUNCTION_ENTRY = 7U,
  /**
   * Exited a specific function
   */   
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING8 CAN001_FUNCTION_EXIT
   * @param STRCODESTRING8 Exited Function \%s
   * @endcond 
  */
  CAN001_FUNCTION_EXIT = 8U
}CAN001_ErrorCodesType;

/**
 * This is the data structure which contains CAN message elements
 */
typedef struct CAN001_MessageHandleType
{
  /**
   * standard ( 11 bit) / Extended (29 bit) message identifier
   */
  uint32_t Identifier; 
  /**
   * standard ( 11 bit) / Extended (29 bit) message identifier mask
   */
  uint32_t IDMask; 	
  /**
   * Standard/Extended identifier support
   */
  uint8_t IDExten; 	
  /**
   * IDE Mask value
   */
  uint8_t IDEMask; 	
  /**
   * Message data length
   */
  uint8_t DataLength; 
  /**
   * 8 bytes of message data
   */
  uint8_t data[8]; 
  /**
   * Enable/Disable Message object
   */
  uint8_t MsgObjEN;		
  /**
   * Message Type
   */
  CAN_MsgType MsgObjType;
}CAN001_MessageHandleType;

/**
 * This is the data structure which contains Baud rate configuration
 */
typedef struct CAN001_BaudRateType
{
  /**
   * Baud rate Prescalar value
   */
  const uint8_t BaudRatePresc;
  /**
   * Synchronization Jump Width
   */
  const uint8_t SyncJumpWidth;
  /**
   * Time segment before sample point
   */
  const uint8_t TimeSEG1;
  /**
   * Time segment after sample point
   */
  const uint8_t TimeSEG2;
  /**
   * Divide prescalar by 8
   */
  const uint8_t DIV8;
}CAN001_BaudRateType;

/**
 * This is the data structure which contains node configuration parameters
 */
typedef struct CAN001_HandleType
{
  /**
   * Node baud rate structure
   */
  CAN001_BaudRateType BaudRate;
	/**
	 * CAN Node Registers offset value
	 */
  CAN_NODE_TypeDef* CanNodeRegs;
	/**
	 * Current node No
	 */
	uint8_t NodeID;
	/**
	 * Loop back mode selection
	 */
	uint8_t LoopBackModeEn;
	/**
	 * First message object no allocated to the node list
	 */
	uint8_t FirstMOMapping;		
	/**
	 * Total message object allocated to node list
	 */
	uint8_t	NodeMONo;
}CAN001_HandleType;


/**
 * @}
 */
 
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Extern Variables                                      **
*******************************************************************************/


/*******************************************************************************
**                     FUNCTION PROTOTYPES                                    **
*******************************************************************************/

 
/**
 * @ingroup CAN001_apidoc
 * @{
 */
 
/**
 * Initializes All CAN nodes instances and message objects configured through UI
 *              
 * @param[in] None
 *
 * @return     void
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *	{
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init(); // CAN001_Init() will be called from DAVE_Init()
 *    while(1)
 *    {
 *    }
 *	}
 *
 * @endcode<BR> </p>
 */
void CAN001_Init(void);

/**
 * This function will deinitialize all the node registers and
 * de allocate all the message objects from the node list.
 *              
 *
 * @param[in]  Handle CAN device handle
 *
 * @return     none
 *
 * <b>Reentrant: NO </b><BR>
* <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *	{
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    CAN001_NodeDeInit(&CAN001_Handle0);
 *    while(1)
 *     {
 *     }
 *  }
 *
 * @endcode<BR> </p>
 *
 */
void CAN001_NodeDeInit(const CAN001_HandleType* Handle);


/**
 * Initializes logical message object for reception or transmission 
 * and configures CAN message object related parameters.
 *
 *
 * @param[in]  Handle CAN device handle
 * @param[in]  SwMsgObjptr pointer to structure which contains message elements
 * @param[in]  MsgObjnr Desired logical message object no
 *
 * @return     status_t 
 *             DAVEApp_SUCCESS: if message object is configured<BR>
 *             CAN001_INVALID_INPUT: If Input parameter is invalid<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related
 * configuration. Number of Message handles generated will depend on No of MO 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    CAN001_MessageHandleType TempMsgHandle;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    TempMsgHandle.Identifier = 0x255;
 *    TempMsgHandle.DataLength = 2;
 *    TempMsgHandle.data[0] = 0x23;
 *    TempMsgHandle.data[1] = 0x46;
 *    // Configure message object register
 *    Status = CAN001_ConfigMsgObj(&CAN001_Handle0,&TempMsgHandle, 1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *       // CAN message configuration successfull
 *    }
 *     // ... infinite loop ...
 *     while(1)
 *     {
 *     }
 *  }
 *
 * @endcode<BR> </p>
 *
 */
status_t CAN001_ConfigMsgObj
(
  const CAN001_HandleType* Handle, 
  const CAN001_MessageHandleType* SwMsgObjptr,
  uint8_t MsgObjnr
 );


/**
 * Set transmit request to transmit message object for sending data frame.
 *
 *
 * @param[in]  Handle CAN device handle
 * @param[in]  MsgObjnr Desired logical message object no
 *
 * @return     status_t 
 *             DAVEApp_SUCCESS: if message is transmitted<BR>
 *             CAN001_MO_NOT_ACCEPTABLE: If MO is not a transmit message object<BR>
 *             CAN001_MO_BUSY: if MO is currently transmitting a mesage<BR>
 *             CAN001_MSGOBJ_DISABLED: If MO is Disabled<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    uint8_t Data[8] = {0xBC,0x11,0x22,0xA5,0xEF,0xFF,0x89,0x01};
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data); 
 *    Status = CAN001_SendDataFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      // transmit request for sending data frame is set
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *    }
 *  }
 *
 * @endcode<BR> </p>
 *
 */
status_t CAN001_SendDataFrame
(
 const CAN001_HandleType* Handle, 
 uint8_t MsgObjnr
);


/**
 * Set transmit request to receive message object for sending remote frame.
 *
 *
 * @param[in]  Handle CAN device handle
 * @param[in]  MsgObjnr Desired logical message object no
 *
 * @return     status_t 
 *             DAVEApp_SUCCESS: if message is transmitted<BR>
 *             CAN001_MO_NOT_ACCEPTABLE: If MO is not a received message object<BR>
 *             CAN001_MO_BUSY: if MO is currently transmitting a mesage<BR>
 *             CAN001_MSGOBJ_DISABLED: If MO is Disabled<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    Status = CAN001_SendRemoteFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      // transmit request for sending remote frame is set
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t CAN001_SendRemoteFrame(const CAN001_HandleType* Handle, uint8_t MsgObjnr);

/**
 * Reads the specified receive message object parameters to the input data structure.
 * It will read only CAN frame parameters like identifier,
 * identifier extension, ID mask, data length and 8 bytes of data
 *
 *
 * @param[in]  Handle CAN device handle
 * @param[out] SwMsgObjptr pointer to structure in which MO parameters are written 
 * @param[in]  MsgObjnr Desired logical message object no
 *
 * @return     status_t 
 *             DAVEApp_SUCCESS: if message is received<BR>
 *             CAN001_MO_NOT_ACCEPTABLE: If MO is not a receive message object<BR>
 *             CAN001_MO_BUSY: if MO is currently receiving a message<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 * CAN001_MessageHandleType CanRecMsgObj;
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    Status = CAN001_SendRemoteFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      //wait till data frame is received.
 *      while(!(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING)))
 *      {}
 *      // Read CAN message to handle CanRecMsgObj
 *      CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 *
 */
status_t CAN001_ReadMsgObj
(
  const CAN001_HandleType* Handle, 
  CAN001_MessageHandleType* SwMsgObjptr, 
  uint8_t MsgObjnr
);

/**
 * Updates data register of transmit message object
 *             
 *
 * @param[in]  Handle CAN device Handle
 * @param[in]  MsgObjnr Desired logical message object no
 * @param[in]  DataLength Message data length
   @param[in]  DataPtr Message data pointer

 * @return     status_t 
 *             CAN001_INVALID_INPUT: if input parameter is not valid<BR>
 *             CAN001_MO_NOT_ACCEPTABLE: if MO is not a transmit message object<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    uint8_t Data[8] = {0xBC,0x11,0x22,0xA5,0xEF,0xFF,0x89,0x01};
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    CAN001_UpdateMODataRegisters(&CAN001_Handle0,1,8,Data); 
 *    Status = CAN001_SendDataFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      // transmit request for sending data frame is set
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t CAN001_UpdateMODataRegisters
(
  const CAN001_HandleType* Handle, 
  uint8_t MsgObjnr,
  uint8_t DataLength, 
  const uint8_t* DataPtr
);

/**
 * Returns the status of the message object specified. 
 * The flag value to be returned should be passed as input parameter 
 * of Enumtype CAN_MsgStatusType.
 *
 *
 * @param[in]  Handle CAN device Handle
 * @param[in]  MsgObjnr Desired logical message object no
 * @param[in]  NewMsgStatus Enum values for getting MO status<BR>
 *                          RECEIVE_PENDING<BR>
 *                          TRANSMIT_PENDING<BR>
 *                          NEW_DATA<BR>
 *                          MESSAGE_LOST<BR> 
 *
 * @return     status_t 
 *             CAN001_SET: if Value is 1<BR>
 *             CAN001_RESET: if value is 0<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related 
 * configuration. Number of Message handles generated will depend on No of  
 * Message objects selected by the user.
 * @code
 * #include <DAVE3.h>
 * CAN001_MessageHandleType CanRecMsgObj;
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    Status = CAN001_SendRemoteFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      //wait till data frame is received.
 *      while(!(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING)))
 *      {}
 *      // Read CAN message to handle CanRecMsgObj
 *      CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
 
status_t CAN001_GetMOFlagStatus
(
  const CAN001_HandleType* Handle, 
  uint8_t MsgObjnr,
  CAN_MsgStatusType NewMsgStatus
 );

 
/**
 * Returns the status of the node specified.
 * The flag value to be returned should be passed as input parameter
 * of type CAN001_NodeStatusType.
 *
 *
 * @param[in]  Handle CAN device Handle
 * @param[in]  NewNodeStatus Enum value for getting node status<BR>
 *							  CAN001_ALERT_STATUS<BR>
 *                            CAN001_ERROR_WARN_STATUS<BR>
 *                            CAN001_BUS_OFF_STATUS<BR>
 *	                          CAN001_LIST_LENGTH_ERROR<BR>
 *	                          CAN001_LIST_OBJECT_ERROR<BR>
 *
 * @return     status_t 
 *             CAN001_SET: if Value is 1<BR>
 *             CAN001_RESET: if value is 0<BR>
 *             CAN001_INVALID_INPUT: if input value is not valid<BR>
 *                                  
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related 
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    CAN001_SendDataFrame(&CAN001_Handle0,1);
 *    Status = CAN001_GetNodeFlagStatus(&CAN001_Handle0,CAN001_BUS_OFF_STATUS);
 *    if(Status == CAN_SET)
 *    {
 *      // Bus Off Condition. Deinit the CAN node
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t CAN001_GetNodeFlagStatus
(
  const CAN001_HandleType* Handle, 
  CAN001_NodeStatusType NewNodeStatus
);


/**
 * Returns the message object's message pending register bit value
 *
 * @param[in]  Handle CAN device Handle
 * @param[in]  MsgObjnr Desired message object number
 *
 * @return     status_t 
 *             CAN001_SET: if Value is 1<BR>
 *             CAN001_RESET: if value is 0<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related 
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 * CAN001_MessageHandleType CanRecMsgObj;
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    Status = CAN001_SendRemoteFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      //wait till data frame is received.
 *      while(!(CAN001_GetMOPndRegisterBitStatus(&CAN001_Handle0,1)))
 *      {}
 *      // Read CAN message to handle CanRecMsgObj
 *      CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t CAN001_GetMOPndRegisterBitStatus
(
  const CAN001_HandleType* Handle, 
  uint8_t MsgObjnr
);

/** 
 * Clears the status bits of message object register MOSTATx. 
 * The input parameter can be a combination of enum type CAN_MsgStatusType
 *
 *
 * @param[in]  Handle CAN device Handle
 * @param[in]  MsgObjnr Desired logical message object no
 * @param[in]   NewMsgStatus Enum values for clearing MO status<BR>
 *                          RECEIVE_PENDING<BR>
 *                          TRANSMIT_PENDING<BR>
 *                          NEW_DATA<BR>
 *                          MESSAGE_LOST<BR> 
 *
 * @return     status_t
 *              DAVEApp_SUCCESS: If Successful<BR>
 *              CAN001_MO_NOT_FOUND: if message object not found<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related 
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 * CAN001_MessageHandleType CanRecMsgObj;
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    Status = CAN001_SendRemoteFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      //wait till data frame is received.
 *      while(!(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING)))
 *      {}
 *      CAN001_ClearMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING);
 *      // Read CAN message to handle CanRecMsgObj
 *	    CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  } 
 * @endcode<BR> </p>
 *
 */
status_t CAN001_ClearMOFlagStatus
(
  const CAN001_HandleType* Handle, 
  uint8_t MsgObjnr, 
  CAN_MsgStatusType NewMsgStatus
);


/** 
 * Clears the status bits of Node register NSRx. The input parameter 
 * can be a combination of enum type NodeStatus
 *
 *
 * @param[in]   Handle CAN device Handle
 * @param[in]  NewNodeStatus Enum value for deleting status bit<BR>
 *							  CAN001_ALERT_STATUS<BR>
 *                            CAN001_ERROR_WARN_STATUS<BR>
 *                            CAN001_BUS_OFF_STATUS<BR>
 *	                          CAN001_LIST_LENGTH_ERROR<BR>
 *	                          CAN001_LIST_OBJECT_ERROR<BR> 
 *
 * @return      void
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related 
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    CAN001_SendDataFrame(&CAN001_Handle0,1);
 *    Status = CAN001_GetNodeFlagStatus(&CAN001_Handle0,CAN001_ERROR_WARN_STATUS);
 *    if(Status == CAN_SET)
 *    {
 *      CAN001_ClearNodeFlagStatus(&CAN001_Handle0,CAN001_ERROR_WARN_STATUS);
 *    }
 *     // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
void CAN001_ClearNodeFlagStatus
(
  const CAN001_HandleType* Handle, 
  CAN001_NodeStatusType NewNodeStatus
);

/** 
 * Clears message pending register bit of specific message object.
 *
 *
 * @param[in]  Handle CAN device Handle
 * @param[in]  MsgObjnr Desired logical message object no
 *
 * @return     status_t
 *              DAVEApp_SUCCESS: If Successful<BR>
 *              CAN001_MO_NOT_FOUND: if message object not found<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>CAN001_Handle0</b></I> is a global structure of type
 * CAN001_HandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_Handle0 contains all node related configuration.
 * <BR><I><b>CAN001_MessageHandle0_1</b></I> is a global structure of type
 * CAN001_MessageHandleType which will be configured in CAN001_Conf.c file using
 * UI parameters. CAN001_MessageHandle0_1 contains all message object related 
 * configuration. Number of Message handles generated will depend on No of Mo 
 * selected by the user.
 * @code
 * #include <DAVE3.h>
 * CAN001_MessageHandleType CanRecMsgObj;
 *  int main(void)
 *  {
 *    uint32_t Status = CAN001_ERROR;
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    Status = CAN001_SendRemoteFrame(&CAN001_Handle0,1);
 *    if(Status == DAVEApp_SUCCESS)
 *    {
 *      //wait till data frame is received.
 *      while(!(CAN001_GetMOPndRegisterBitStatus(&CAN001_Handle0,1)))
 *      {}
 *      CAN001_ClearMOPndRegisterBit(&CAN001_Handle0,1);
 *      // Read CAN message to handle CanRecMsgObj
 *      CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {
 *
 *    }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t CAN001_ClearMOPndRegisterBit(const CAN001_HandleType* Handle, uint8_t MsgObjnr);

/*<%*
 * Interrupt service routine to handle Alert Interrupt for corresponding CAN node Id.
 *
 *
 * @param[in] None
 *
 * @return     void
 *
 * <b>Reentrant: NO </b><BR>
 *
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 * #include <DAVE3.h>
 * void CAN_viSRN0(void);
 * void CAN_viSRN0(void)
 *	{
 * 		// USER CODE BEGIN 
 * 	 
 *      // USER CODE END
 *		//   -----------------------------------------------------------------------	
 *		//   Interrupts of CAN node 0
 *		//   -----------------------------------------------------------------------
 *		uint32_t SRN0NodeHandler = (CAN001_Handle0.CanNodeRegs->NSR);
 *
 *		if(SRN0NodeHandler & (uint32_t)CAN001_ALERT_STATUS)			// if ALERT
 * 		{
 *			if(SRN0NodeHandler & (uint32_t)CAN001_BUS_OFF_STATUS)  // if BOFF
 * 			{
 * 				// Indicates when the CAN controller is in bus off state.
 * 				// USER CODE BEGIN 
 * 	 
 *         		// USER CODE END 
 *				SRN0NodeHandler &= (uint32_t)(~CAN001_BUS_OFF_STATUS);  // reset BOFF
 * 			}
 *			if(SRN0NodeHandler & (uint32_t)CAN001_ERROR_WARN_STATUS)  // if EWRN
 * 			{
 *			    // One of the error counters REC or TEC reached the warning limit of 96.
 * 				// USER CODE BEGIN 
 * 	 
 *         		// USER CODE END
 * 				SRN0NodeHandler &= (uint32_t)(~CAN001_ERROR_WARN_STATUS);  // reset EWRN
 * 			}
 * 			if(SRN0NodeHandler & (uint32_t)CAN001_LIST_LENGTH_ERROR)  // if LLE		
 * 			{
 *          	// A list length error has been detected during message acceptance filtering. The number of elements in the list
 *        		// that belongs to this CAN node differs from the list SIZE given in the list termination pointer
 * 				// USER CODE BEGIN 
 * 	 
 *         		// USER CODE END
 * 				SRN0NodeHandler &= (uint32_t)(~CAN001_LIST_LENGTH_ERROR);	// reset LLE
 * 			}
 * 			if(SRN0NodeHandler & (uint32_t)CAN001_LIST_OBJECT_ERROR)  // if LOE
 * 			{
 *        		// A list object error has been detected during message acceptance filtering. A message object with wrong LIST 
 *         		// index entry in the Message Object Control Register has been detected
 * 				// USER CODE BEGIN 
 * 	 
 *         		// USER CODE END
 * 				SRN0NodeHandler &= (uint32_t)(~CAN001_LIST_OBJECT_ERROR);  // reset LOE
 * 			} 
 * 			SRN0NodeHandler &= (uint32_t)(~CAN001_ALERT_STATUS);    // reset ALERT
 * 		}
 * 	} //  End of function CAN_viSRN0
 *  int main(void)
 *	{
 *    // ... Initialises Apps configurations ...
 *    DAVE_Init();
 *    while(1)
 *    {
 *    }
 *	}
 *
 * @endcode<BR> </p> 
 %>*/ 

/**
 *@}
 */

/* Include App config file */
#include "CAN001_Conf.h"

/**
 * @ingroup CAN001_apidoc
 * @{
 */
 
/** This macro function resets the INIT & CCE bit of the CAN Node0 Control Register (NCR)
  *  
  *  @param[in] None
  */
/* NODE0 initialisation mode exit */
#ifdef CAN_NODE0_ENABLE
/* Macro to disable re-definitions of CAN_Handle0_NODE if both Non-RTOS & RTOS CAN app used */
#ifndef CAN_Handle0
#define CAN_Handle0
#define CAN_Handle0_NODE()  {\
              WR_REG(CAN_NODE0->NCR, CAN_NODE_NCR_CCE_Msk, CAN_NODE_NCR_CCE_Pos, 0);\
              WR_REG(CAN_NODE0->NCR, CAN_NODE_NCR_INIT_Msk, CAN_NODE_NCR_INIT_Pos, 0);\
              }
#endif
#endif

/** This macro function resets the INIT & CCE bit of the CAN Node1 Control Register (NCR)
  *  
  *  @param[in] None
  */
/* NODE1 initialisation mode exit */
#ifdef CAN_NODE1_ENABLE
/* Macro to disable re-definitions of CAN_Handle1_NODE if both Non-RTOS & RTOS CAN app used */
#ifndef CAN_Handle1
#define CAN_Handle1
#define CAN_Handle1_NODE()  {\
              WR_REG(CAN_NODE1->NCR, CAN_NODE_NCR_CCE_Msk, CAN_NODE_NCR_CCE_Pos, 0);\
              WR_REG(CAN_NODE1->NCR, CAN_NODE_NCR_INIT_Msk, CAN_NODE_NCR_INIT_Pos, 0);\
              }
#endif
#endif

/** This macro function resets the INIT & CCE bit of the CAN Node2 Control Register (NCR)
  *  
  *  @param[in] None
  */
/* NODE2 initialisation mode exit */
#ifdef CAN_NODE2_ENABLE
/* Macro to disable re-definitions of CAN_Handle2_NODE if both Non-RTOS & RTOS CAN app used */
#ifndef CAN_Handle2
#define CAN_Handle2
#define CAN_Handle2_NODE()    {\
              WR_REG(CAN_NODE2->NCR, CAN_NODE_NCR_CCE_Msk, CAN_NODE_NCR_CCE_Pos, 0);\
              WR_REG(CAN_NODE2->NCR, CAN_NODE_NCR_INIT_Msk, CAN_NODE_NCR_INIT_Pos, 0);\
              }
#endif
#endif
/**
 *@}
 */  
 
/* Support for C++ codebase */
#ifdef __cplusplus
}
#endif 

#endif /* CAN001_H_ */


