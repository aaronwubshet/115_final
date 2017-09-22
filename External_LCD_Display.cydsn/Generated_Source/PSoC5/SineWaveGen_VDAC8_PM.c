/*******************************************************************************
* File Name: SineWaveGen_VDAC8_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SineWaveGen_VDAC8.h"

static SineWaveGen_VDAC8_backupStruct SineWaveGen_VDAC8_backup;


/*******************************************************************************
* Function Name: SineWaveGen_VDAC8_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void SineWaveGen_VDAC8_SaveConfig(void) 
{
    if (!((SineWaveGen_VDAC8_CR1 & SineWaveGen_VDAC8_SRC_MASK) == SineWaveGen_VDAC8_SRC_UDB))
    {
        SineWaveGen_VDAC8_backup.data_value = SineWaveGen_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: SineWaveGen_VDAC8_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void SineWaveGen_VDAC8_RestoreConfig(void) 
{
    if (!((SineWaveGen_VDAC8_CR1 & SineWaveGen_VDAC8_SRC_MASK) == SineWaveGen_VDAC8_SRC_UDB))
    {
        if((SineWaveGen_VDAC8_Strobe & SineWaveGen_VDAC8_STRB_MASK) == SineWaveGen_VDAC8_STRB_EN)
        {
            SineWaveGen_VDAC8_Strobe &= (uint8)(~SineWaveGen_VDAC8_STRB_MASK);
            SineWaveGen_VDAC8_Data = SineWaveGen_VDAC8_backup.data_value;
            SineWaveGen_VDAC8_Strobe |= SineWaveGen_VDAC8_STRB_EN;
        }
        else
        {
            SineWaveGen_VDAC8_Data = SineWaveGen_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: SineWaveGen_VDAC8_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  SineWaveGen_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void SineWaveGen_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(SineWaveGen_VDAC8_ACT_PWR_EN == (SineWaveGen_VDAC8_PWRMGR & SineWaveGen_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        SineWaveGen_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        SineWaveGen_VDAC8_backup.enableState = 0u;
    }
    
    SineWaveGen_VDAC8_Stop();
    SineWaveGen_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: SineWaveGen_VDAC8_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  SineWaveGen_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SineWaveGen_VDAC8_Wakeup(void) 
{
    SineWaveGen_VDAC8_RestoreConfig();
    
    if(SineWaveGen_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        SineWaveGen_VDAC8_Enable();

        /* Restore the data register */
        SineWaveGen_VDAC8_SetValue(SineWaveGen_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
