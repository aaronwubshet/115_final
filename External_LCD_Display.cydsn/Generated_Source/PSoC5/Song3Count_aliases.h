/*******************************************************************************
* File Name: Song3Count.h  
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

#if !defined(CY_PINS_Song3Count_ALIASES_H) /* Pins Song3Count_ALIASES_H */
#define CY_PINS_Song3Count_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Song3Count_0			(Song3Count__0__PC)
#define Song3Count_0_INTR	((uint16)((uint16)0x0001u << Song3Count__0__SHIFT))

#define Song3Count_1			(Song3Count__1__PC)
#define Song3Count_1_INTR	((uint16)((uint16)0x0001u << Song3Count__1__SHIFT))

#define Song3Count_2			(Song3Count__2__PC)
#define Song3Count_2_INTR	((uint16)((uint16)0x0001u << Song3Count__2__SHIFT))

#define Song3Count_3			(Song3Count__3__PC)
#define Song3Count_3_INTR	((uint16)((uint16)0x0001u << Song3Count__3__SHIFT))

#define Song3Count_INTR_ALL	 ((uint16)(Song3Count_0_INTR| Song3Count_1_INTR| Song3Count_2_INTR| Song3Count_3_INTR))

#endif /* End Pins Song3Count_ALIASES_H */


/* [] END OF FILE */
