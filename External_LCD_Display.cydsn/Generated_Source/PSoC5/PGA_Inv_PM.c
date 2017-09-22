/*******************************************************************************
* File Name: PGA_Inv.c
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for the 
*  inverting PGA component.
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

#include "PGA_Inv.h"

static PGA_Inv_BACKUP_STRUCT  PGA_Inv_backup;


/*******************************************************************************  
* Function Name: PGA_Inv_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void PGA_Inv_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************
* Function Name: PGA_Inv_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
* 
* Parameters:
*  void.
* 
* Return:
*  void
*
*******************************************************************************/
void PGA_Inv_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************
* Function Name: PGA_Inv_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PGA_Inv_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void PGA_Inv_Sleep(void) 
{
    /* Save PGA_Inv enable state */
    if((PGA_Inv_PM_ACT_CFG_REG & PGA_Inv_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        PGA_Inv_backup.enableState = 1u;
        /* Stop the configuration */
        PGA_Inv_Stop();
    }
    else
    {
        /* Component is disabled */
        PGA_Inv_backup.enableState = 0u;
    }
    /* Save the configurations */
    PGA_Inv_SaveConfig();
}


/*******************************************************************************
* Function Name: PGA_Inv_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  PGA_Inv_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void PGA_Inv_Wakeup(void) 
{
    /* Restore the register configurations */
    PGA_Inv_RestoreConfig();
    
    /* Enable's the component operation */
    if(PGA_Inv_backup.enableState == 1u)
    {
        PGA_Inv_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
