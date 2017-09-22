/*******************************************************************************
* File Name: Song4Count.h  
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

#if !defined(CY_PINS_Song4Count_ALIASES_H) /* Pins Song4Count_ALIASES_H */
#define CY_PINS_Song4Count_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Song4Count_0			(Song4Count__0__PC)
#define Song4Count_0_PS		(Song4Count__0__PS)
#define Song4Count_0_PC		(Song4Count__0__PC)
#define Song4Count_0_DR		(Song4Count__0__DR)
#define Song4Count_0_SHIFT	(Song4Count__0__SHIFT)
#define Song4Count_0_INTR	((uint16)((uint16)0x0003u << (Song4Count__0__SHIFT*2u)))

#define Song4Count_1			(Song4Count__1__PC)
#define Song4Count_1_PS		(Song4Count__1__PS)
#define Song4Count_1_PC		(Song4Count__1__PC)
#define Song4Count_1_DR		(Song4Count__1__DR)
#define Song4Count_1_SHIFT	(Song4Count__1__SHIFT)
#define Song4Count_1_INTR	((uint16)((uint16)0x0003u << (Song4Count__1__SHIFT*2u)))

#define Song4Count_2			(Song4Count__2__PC)
#define Song4Count_2_PS		(Song4Count__2__PS)
#define Song4Count_2_PC		(Song4Count__2__PC)
#define Song4Count_2_DR		(Song4Count__2__DR)
#define Song4Count_2_SHIFT	(Song4Count__2__SHIFT)
#define Song4Count_2_INTR	((uint16)((uint16)0x0003u << (Song4Count__2__SHIFT*2u)))

#define Song4Count_3			(Song4Count__3__PC)
#define Song4Count_3_PS		(Song4Count__3__PS)
#define Song4Count_3_PC		(Song4Count__3__PC)
#define Song4Count_3_DR		(Song4Count__3__DR)
#define Song4Count_3_SHIFT	(Song4Count__3__SHIFT)
#define Song4Count_3_INTR	((uint16)((uint16)0x0003u << (Song4Count__3__SHIFT*2u)))

#define Song4Count_INTR_ALL	 ((uint16)(Song4Count_0_INTR| Song4Count_1_INTR| Song4Count_2_INTR| Song4Count_3_INTR))


#endif /* End Pins Song4Count_ALIASES_H */


/* [] END OF FILE */
