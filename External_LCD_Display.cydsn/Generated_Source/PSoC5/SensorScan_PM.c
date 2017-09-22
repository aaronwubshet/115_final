/*******************************************************************************
* File Name: SensorScan_PM.c
* Version 1.10
*
* Description:
*  This file provides Sleep APIs for Scanning Comparator component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SensorScan.h"

static SensorScan_BACKUP_STRUCT SensorScan_backup;


/*******************************************************************************
* Function Name: SensorScan_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for low power mode operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_Sleep(void) 
{
    if(0u != (SensorScan_CONTROL_REG & SensorScan_CONTROL_ENABLE))
    {
        SensorScan_backup.enableState = 1u;
        SensorScan_Stop();
    }
    else /* The component is disabled */
    {
        SensorScan_backup.enableState = 0u;
    }

    SensorScan_Comp_Sleep();

    #if (SensorScan_INTERNAL_REF_IS_USED)
        SensorScan_VDAC_Sleep();
    #endif /* SensorScan_INTERNAL_REF_IS_USED */
}


/*******************************************************************************
* Function Name: SensorScan_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component to the state when SensorScan_Sleep() was called.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_Wakeup(void) 
{
    SensorScan_Comp_Wakeup();
    
    #if (SensorScan_INTERNAL_REF_IS_USED)
        SensorScan_VDAC_Start();

        #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
            SensorScan_Init();
        #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
    #endif /* SensorScan_INTERNAL_REF_IS_USED */

    if(0u != SensorScan_backup.enableState)
    {
        SensorScan_Enable();
    }
}


/* [] END OF FILE */
