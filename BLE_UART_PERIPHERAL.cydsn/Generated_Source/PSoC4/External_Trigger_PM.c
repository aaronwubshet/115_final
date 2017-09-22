/*******************************************************************************
* File Name: External_Trigger.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "External_Trigger.h"

static External_Trigger_BACKUP_STRUCT  External_Trigger_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: External_Trigger_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet External_Trigger_SUT.c usage_External_Trigger_Sleep_Wakeup
*******************************************************************************/
void External_Trigger_Sleep(void)
{
    #if defined(External_Trigger__PC)
        External_Trigger_backup.pcState = External_Trigger_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            External_Trigger_backup.usbState = External_Trigger_CR1_REG;
            External_Trigger_USB_POWER_REG |= External_Trigger_USBIO_ENTER_SLEEP;
            External_Trigger_CR1_REG &= External_Trigger_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(External_Trigger__SIO)
        External_Trigger_backup.sioState = External_Trigger_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        External_Trigger_SIO_REG &= (uint32)(~External_Trigger_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: External_Trigger_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to External_Trigger_Sleep() for an example usage.
*******************************************************************************/
void External_Trigger_Wakeup(void)
{
    #if defined(External_Trigger__PC)
        External_Trigger_PC = External_Trigger_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            External_Trigger_USB_POWER_REG &= External_Trigger_USBIO_EXIT_SLEEP_PH1;
            External_Trigger_CR1_REG = External_Trigger_backup.usbState;
            External_Trigger_USB_POWER_REG &= External_Trigger_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(External_Trigger__SIO)
        External_Trigger_SIO_REG = External_Trigger_backup.sioState;
    #endif
}


/* [] END OF FILE */
