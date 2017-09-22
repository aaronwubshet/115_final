/*******************************************************************************
* File Name: Song1Trigger.h  
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

#if !defined(CY_PINS_Song1Trigger_ALIASES_H) /* Pins Song1Trigger_ALIASES_H */
#define CY_PINS_Song1Trigger_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Song1Trigger_0			(Song1Trigger__0__PC)
#define Song1Trigger_0_PS		(Song1Trigger__0__PS)
#define Song1Trigger_0_PC		(Song1Trigger__0__PC)
#define Song1Trigger_0_DR		(Song1Trigger__0__DR)
#define Song1Trigger_0_SHIFT	(Song1Trigger__0__SHIFT)
#define Song1Trigger_0_INTR	((uint16)((uint16)0x0003u << (Song1Trigger__0__SHIFT*2u)))

#define Song1Trigger_INTR_ALL	 ((uint16)(Song1Trigger_0_INTR))


#endif /* End Pins Song1Trigger_ALIASES_H */


/* [] END OF FILE */
