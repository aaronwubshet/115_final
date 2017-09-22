/*******************************************************************************
* File Name: SongCount.h  
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

#if !defined(CY_PINS_SongCount_ALIASES_H) /* Pins SongCount_ALIASES_H */
#define CY_PINS_SongCount_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define SongCount_0			(SongCount__0__PC)
#define SongCount_0_INTR	((uint16)((uint16)0x0001u << SongCount__0__SHIFT))

#define SongCount_1			(SongCount__1__PC)
#define SongCount_1_INTR	((uint16)((uint16)0x0001u << SongCount__1__SHIFT))

#define SongCount_2			(SongCount__2__PC)
#define SongCount_2_INTR	((uint16)((uint16)0x0001u << SongCount__2__SHIFT))

#define SongCount_3			(SongCount__3__PC)
#define SongCount_3_INTR	((uint16)((uint16)0x0001u << SongCount__3__SHIFT))

#define SongCount_4			(SongCount__4__PC)
#define SongCount_4_INTR	((uint16)((uint16)0x0001u << SongCount__4__SHIFT))

#define SongCount_5			(SongCount__5__PC)
#define SongCount_5_INTR	((uint16)((uint16)0x0001u << SongCount__5__SHIFT))

#define SongCount_6			(SongCount__6__PC)
#define SongCount_6_INTR	((uint16)((uint16)0x0001u << SongCount__6__SHIFT))

#define SongCount_7			(SongCount__7__PC)
#define SongCount_7_INTR	((uint16)((uint16)0x0001u << SongCount__7__SHIFT))

#define SongCount_INTR_ALL	 ((uint16)(SongCount_0_INTR| SongCount_1_INTR| SongCount_2_INTR| SongCount_3_INTR| SongCount_4_INTR| SongCount_5_INTR| SongCount_6_INTR| SongCount_7_INTR))

#endif /* End Pins SongCount_ALIASES_H */


/* [] END OF FILE */
