/*******************************************************************************
* File Name: Song1Trigger.c  
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
#include "Song1Trigger.h"

static Song1Trigger_BACKUP_STRUCT  Song1Trigger_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Song1Trigger_Sleep
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
*  \snippet Song1Trigger_SUT.c usage_Song1Trigger_Sleep_Wakeup
*******************************************************************************/
void Song1Trigger_Sleep(void)
{
    #if defined(Song1Trigger__PC)
        Song1Trigger_backup.pcState = Song1Trigger_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Song1Trigger_backup.usbState = Song1Trigger_CR1_REG;
            Song1Trigger_USB_POWER_REG |= Song1Trigger_USBIO_ENTER_SLEEP;
            Song1Trigger_CR1_REG &= Song1Trigger_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Song1Trigger__SIO)
        Song1Trigger_backup.sioState = Song1Trigger_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Song1Trigger_SIO_REG &= (uint32)(~Song1Trigger_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Song1Trigger_Wakeup
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
*  Refer to Song1Trigger_Sleep() for an example usage.
*******************************************************************************/
void Song1Trigger_Wakeup(void)
{
    #if defined(Song1Trigger__PC)
        Song1Trigger_PC = Song1Trigger_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Song1Trigger_USB_POWER_REG &= Song1Trigger_USBIO_EXIT_SLEEP_PH1;
            Song1Trigger_CR1_REG = Song1Trigger_backup.usbState;
            Song1Trigger_USB_POWER_REG &= Song1Trigger_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Song1Trigger__SIO)
        Song1Trigger_SIO_REG = Song1Trigger_backup.sioState;
    #endif
}


/* [] END OF FILE */
