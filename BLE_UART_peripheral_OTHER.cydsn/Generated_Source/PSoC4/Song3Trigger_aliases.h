/*******************************************************************************
* File Name: Song3Trigger.h  
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

#if !defined(CY_PINS_Song3Trigger_ALIASES_H) /* Pins Song3Trigger_ALIASES_H */
#define CY_PINS_Song3Trigger_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Song3Trigger_0			(Song3Trigger__0__PC)
#define Song3Trigger_0_PS		(Song3Trigger__0__PS)
#define Song3Trigger_0_PC		(Song3Trigger__0__PC)
#define Song3Trigger_0_DR		(Song3Trigger__0__DR)
#define Song3Trigger_0_SHIFT	(Song3Trigger__0__SHIFT)
#define Song3Trigger_0_INTR	((uint16)((uint16)0x0003u << (Song3Trigger__0__SHIFT*2u)))

#define Song3Trigger_INTR_ALL	 ((uint16)(Song3Trigger_0_INTR))


#endif /* End Pins Song3Trigger_ALIASES_H */


/* [] END OF FILE */
