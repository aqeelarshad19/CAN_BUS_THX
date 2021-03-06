/*******************************************************************************
**  DAVE App Name : CAN001       App Version: 1.0.12               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[CAN001_Conf.h]*/
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
**                                                                            **
*******************************************************************************/

/**
 * @file CAN001_Conf.h
 * 
 * @App Version CAN001 <1.0.12> 
 * @brief  CAN001 App Handle declaration based on UI selection.
 *
 */
 
 #ifndef CONF_CAN001_H_
 #define CONF_CAN001_H_
 
/* Support for C++ codebase */
#ifdef __cplusplus
extern "C" {
#endif 

#include <DAVE3.h>

extern const CAN001_HandleType CAN001_Handle0;
extern CAN001_MessageHandleType CAN001_MessageHandle0_1;
extern CAN001_MessageHandleType CAN001_MessageHandle0_2;               


/* Macro to enable node1 initialisation exit macro */
#define CAN_NODE1_ENABLE
/* Macro to access node1 registers */
#define CAN001_Handle0_NODE   CAN_NODE1
/* Macro to access Node1 LMO1 register */
#define CAN001_Handle0_NODE_LMO1 CAN_MO34 
/* Macro to access Node1 LMO2 register */
#define CAN001_Handle0_NODE_LMO2 CAN_MO35 

/* Support for C++ codebase */
#ifdef __cplusplus
}
#endif 

#endif

/*CODE_BLOCK_END*/ 


