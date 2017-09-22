/*******************************************************************************
* File Name: SineWaveGen_IDAC8.c
* Version 2.0
*
* Description:
*  This file provides the power management source code to API for the
*  IDAC8.
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


#include "SineWaveGen_IDAC8.h"

static SineWaveGen_IDAC8_backupStruct SineWaveGen_IDAC8_backup;


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_SaveConfig
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
void SineWaveGen_IDAC8_SaveConfig(void) 
{
    if (!((SineWaveGen_IDAC8_CR1 & SineWaveGen_IDAC8_SRC_MASK) == SineWaveGen_IDAC8_SRC_UDB))
    {
        SineWaveGen_IDAC8_backup.data_value = SineWaveGen_IDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_RestoreConfig
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
void SineWaveGen_IDAC8_RestoreConfig(void) 
{
    if (!((SineWaveGen_IDAC8_CR1 & SineWaveGen_IDAC8_SRC_MASK) == SineWaveGen_IDAC8_SRC_UDB))
    {
        if((SineWaveGen_IDAC8_Strobe & SineWaveGen_IDAC8_STRB_MASK) == SineWaveGen_IDAC8_STRB_EN)
        {
            SineWaveGen_IDAC8_Strobe &= (uint8)(~SineWaveGen_IDAC8_STRB_MASK);
            SineWaveGen_IDAC8_Data = SineWaveGen_IDAC8_backup.data_value;
            SineWaveGen_IDAC8_Strobe |= SineWaveGen_IDAC8_STRB_EN;
        }
        else
        {
            SineWaveGen_IDAC8_Data = SineWaveGen_IDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_Sleep
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
*  SineWaveGen_IDAC8_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SineWaveGen_IDAC8_Sleep(void) 
{
    if(SineWaveGen_IDAC8_ACT_PWR_EN == (SineWaveGen_IDAC8_PWRMGR & SineWaveGen_IDAC8_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        SineWaveGen_IDAC8_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        SineWaveGen_IDAC8_backup.enableState = 0u;
    }

    SineWaveGen_IDAC8_Stop();
    SineWaveGen_IDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_Wakeup
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
*  SineWaveGen_IDAC8_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SineWaveGen_IDAC8_Wakeup(void) 
{
    SineWaveGen_IDAC8_RestoreConfig();
    
    if(SineWaveGen_IDAC8_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        SineWaveGen_IDAC8_Enable();
        
        /* Set the data register */
        SineWaveGen_IDAC8_SetValue(SineWaveGen_IDAC8_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
