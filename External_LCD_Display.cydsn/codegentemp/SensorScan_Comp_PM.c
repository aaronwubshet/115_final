/*******************************************************************************
* File Name: SensorScan_Comp.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
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

#include "SensorScan_Comp.h"

static SensorScan_Comp_backupStruct SensorScan_Comp_backup;


/*******************************************************************************
* Function Name: SensorScan_Comp_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void SensorScan_Comp_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: SensorScan_Comp_RestoreConfig
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
********************************************************************************/
void SensorScan_Comp_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: SensorScan_Comp_Sleep
********************************************************************************
*
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
*  SensorScan_Comp_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void SensorScan_Comp_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(SensorScan_Comp_ACT_PWR_EN == (SensorScan_Comp_PWRMGR & SensorScan_Comp_ACT_PWR_EN))
    {
        /* Comp is enabled */
        SensorScan_Comp_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        SensorScan_Comp_backup.enableState = 0u;
    }    
    
    SensorScan_Comp_Stop();
    SensorScan_Comp_SaveConfig();
}


/*******************************************************************************
* Function Name: SensorScan_Comp_Wakeup
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
*  SensorScan_Comp_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SensorScan_Comp_Wakeup(void) 
{
    SensorScan_Comp_RestoreConfig();
    
    if(SensorScan_Comp_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        SensorScan_Comp_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
