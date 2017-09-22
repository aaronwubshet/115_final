/*******************************************************************************
* File Name: Song_Count_Bits.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Song_Count_Bits_ALIASES_H) /* Pins Song_Count_Bits_ALIASES_H */
#define CY_PINS_Song_Count_Bits_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Song_Count_Bits_0			(Song_Count_Bits__0__PC)
#define Song_Count_Bits_0_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__0__SHIFT))

#define Song_Count_Bits_1			(Song_Count_Bits__1__PC)
#define Song_Count_Bits_1_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__1__SHIFT))

#define Song_Count_Bits_2			(Song_Count_Bits__2__PC)
#define Song_Count_Bits_2_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__2__SHIFT))

#define Song_Count_Bits_3			(Song_Count_Bits__3__PC)
#define Song_Count_Bits_3_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__3__SHIFT))

#define Song_Count_Bits_4			(Song_Count_Bits__4__PC)
#define Song_Count_Bits_4_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__4__SHIFT))

#define Song_Count_Bits_5			(Song_Count_Bits__5__PC)
#define Song_Count_Bits_5_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__5__SHIFT))

#define Song_Count_Bits_6			(Song_Count_Bits__6__PC)
#define Song_Count_Bits_6_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__6__SHIFT))

#define Song_Count_Bits_7			(Song_Count_Bits__7__PC)
#define Song_Count_Bits_7_INTR	((uint16)((uint16)0x0001u << Song_Count_Bits__7__SHIFT))

#define Song_Count_Bits_INTR_ALL	 ((uint16)(Song_Count_Bits_0_INTR| Song_Count_Bits_1_INTR| Song_Count_Bits_2_INTR| Song_Count_Bits_3_INTR| Song_Count_Bits_4_INTR| Song_Count_Bits_5_INTR| Song_Count_Bits_6_INTR| Song_Count_Bits_7_INTR))

#endif /* End Pins Song_Count_Bits_ALIASES_H */


/* [] END OF FILE */
