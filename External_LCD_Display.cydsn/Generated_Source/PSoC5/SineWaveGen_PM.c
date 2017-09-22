/*******************************************************************************
* File Name: SineWaveGen_PM.c  
* Version 2.10
*
* Description:
*  This file provides the power manager source code to the API for 
*  the WaveDAC8 component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SineWaveGen.h"

static SineWaveGen_BACKUP_STRUCT  SineWaveGen_backup;


/*******************************************************************************
* Function Name: SineWaveGen_Sleep
********************************************************************************
*
* Summary:
*  Stops the component and saves its configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  SineWaveGen_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void SineWaveGen_Sleep(void) 
{
	/* Save DAC8's enable state */

	SineWaveGen_backup.enableState = (SineWaveGen_VDAC8_ACT_PWR_EN == 
		(SineWaveGen_VDAC8_PWRMGR_REG & SineWaveGen_VDAC8_ACT_PWR_EN)) ? 1u : 0u ;
	
	SineWaveGen_Stop();
	SineWaveGen_SaveConfig();
}


/*******************************************************************************
* Function Name: SineWaveGen_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component configuration. Should be called
*  just after awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  void
*
* Global variables:
*  SineWaveGen_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void SineWaveGen_Wakeup(void) 
{
	SineWaveGen_RestoreConfig();

	if(SineWaveGen_backup.enableState == 1u)
	{
		SineWaveGen_Enable();
	}
}


/* [] END OF FILE */
