/*******************************************************************************
* File Name: SineWaveGen_BuffAmp_PM.c
* Version 1.90
*
* Description:
*  This file provides the power management source code to the API for the 
*  OpAmp (Analog Buffer) component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SineWaveGen_BuffAmp.h"

static SineWaveGen_BuffAmp_BACKUP_STRUCT  SineWaveGen_BuffAmp_backup;


/*******************************************************************************  
* Function Name: SineWaveGen_BuffAmp_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void SineWaveGen_BuffAmp_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: SineWaveGen_BuffAmp_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SineWaveGen_BuffAmp_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: SineWaveGen_BuffAmp_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SineWaveGen_BuffAmp_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void SineWaveGen_BuffAmp_Sleep(void) 
{
    /* Save OpAmp enable state */
    if((SineWaveGen_BuffAmp_PM_ACT_CFG_REG & SineWaveGen_BuffAmp_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        SineWaveGen_BuffAmp_backup.enableState = 1u;
         /* Stops the component */
         SineWaveGen_BuffAmp_Stop();
    }
    else
    {
        /* Component is disabled */
        SineWaveGen_BuffAmp_backup.enableState = 0u;
    }
    /* Saves the configuration */
    SineWaveGen_BuffAmp_SaveConfig();
}


/*******************************************************************************  
* Function Name: SineWaveGen_BuffAmp_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SineWaveGen_BuffAmp_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void SineWaveGen_BuffAmp_Wakeup(void) 
{
    /* Restore the user configuration */
    SineWaveGen_BuffAmp_RestoreConfig();

    /* Enables the component operation */
    if(SineWaveGen_BuffAmp_backup.enableState == 1u)
    {
        SineWaveGen_BuffAmp_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
