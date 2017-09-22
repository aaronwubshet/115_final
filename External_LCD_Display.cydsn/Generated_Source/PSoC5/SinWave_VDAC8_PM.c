/*******************************************************************************
* File Name: SinWave_VDAC8_PM.c  
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

#include "SinWave_VDAC8.h"

static SinWave_VDAC8_backupStruct SinWave_VDAC8_backup;


/*******************************************************************************
* Function Name: SinWave_VDAC8_SaveConfig
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
void SinWave_VDAC8_SaveConfig(void) 
{
    if (!((SinWave_VDAC8_CR1 & SinWave_VDAC8_SRC_MASK) == SinWave_VDAC8_SRC_UDB))
    {
        SinWave_VDAC8_backup.data_value = SinWave_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: SinWave_VDAC8_RestoreConfig
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
void SinWave_VDAC8_RestoreConfig(void) 
{
    if (!((SinWave_VDAC8_CR1 & SinWave_VDAC8_SRC_MASK) == SinWave_VDAC8_SRC_UDB))
    {
        if((SinWave_VDAC8_Strobe & SinWave_VDAC8_STRB_MASK) == SinWave_VDAC8_STRB_EN)
        {
            SinWave_VDAC8_Strobe &= (uint8)(~SinWave_VDAC8_STRB_MASK);
            SinWave_VDAC8_Data = SinWave_VDAC8_backup.data_value;
            SinWave_VDAC8_Strobe |= SinWave_VDAC8_STRB_EN;
        }
        else
        {
            SinWave_VDAC8_Data = SinWave_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: SinWave_VDAC8_Sleep
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
*  SinWave_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void SinWave_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(SinWave_VDAC8_ACT_PWR_EN == (SinWave_VDAC8_PWRMGR & SinWave_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        SinWave_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        SinWave_VDAC8_backup.enableState = 0u;
    }
    
    SinWave_VDAC8_Stop();
    SinWave_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: SinWave_VDAC8_Wakeup
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
*  SinWave_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SinWave_VDAC8_Wakeup(void) 
{
    SinWave_VDAC8_RestoreConfig();
    
    if(SinWave_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        SinWave_VDAC8_Enable();

        /* Restore the data register */
        SinWave_VDAC8_SetValue(SinWave_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
