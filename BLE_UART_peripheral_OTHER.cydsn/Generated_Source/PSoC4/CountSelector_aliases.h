/*******************************************************************************
* File Name: CountSelector.h  
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

#if !defined(CY_PINS_CountSelector_ALIASES_H) /* Pins CountSelector_ALIASES_H */
#define CY_PINS_CountSelector_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CountSelector_0			(CountSelector__0__PC)
#define CountSelector_0_PS		(CountSelector__0__PS)
#define CountSelector_0_PC		(CountSelector__0__PC)
#define CountSelector_0_DR		(CountSelector__0__DR)
#define CountSelector_0_SHIFT	(CountSelector__0__SHIFT)
#define CountSelector_0_INTR	((uint16)((uint16)0x0003u << (CountSelector__0__SHIFT*2u)))

#define CountSelector_1			(CountSelector__1__PC)
#define CountSelector_1_PS		(CountSelector__1__PS)
#define CountSelector_1_PC		(CountSelector__1__PC)
#define CountSelector_1_DR		(CountSelector__1__DR)
#define CountSelector_1_SHIFT	(CountSelector__1__SHIFT)
#define CountSelector_1_INTR	((uint16)((uint16)0x0003u << (CountSelector__1__SHIFT*2u)))

#define CountSelector_INTR_ALL	 ((uint16)(CountSelector_0_INTR| CountSelector_1_INTR))


#endif /* End Pins CountSelector_ALIASES_H */


/* [] END OF FILE */
