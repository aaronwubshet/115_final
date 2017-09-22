/*******************************************************************************
* File Name: Song3Count.c  
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
#include "Song3Count.h"

static Song3Count_BACKUP_STRUCT  Song3Count_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Song3Count_Sleep
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
*  \snippet Song3Count_SUT.c usage_Song3Count_Sleep_Wakeup
*******************************************************************************/
void Song3Count_Sleep(void)
{
    #if defined(Song3Count__PC)
        Song3Count_backup.pcState = Song3Count_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Song3Count_backup.usbState = Song3Count_CR1_REG;
            Song3Count_USB_POWER_REG |= Song3Count_USBIO_ENTER_SLEEP;
            Song3Count_CR1_REG &= Song3Count_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Song3Count__SIO)
        Song3Count_backup.sioState = Song3Count_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Song3Count_SIO_REG &= (uint32)(~Song3Count_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Song3Count_Wakeup
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
*  Refer to Song3Count_Sleep() for an example usage.
*******************************************************************************/
void Song3Count_Wakeup(void)
{
    #if defined(Song3Count__PC)
        Song3Count_PC = Song3Count_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Song3Count_USB_POWER_REG &= Song3Count_USBIO_EXIT_SLEEP_PH1;
            Song3Count_CR1_REG = Song3Count_backup.usbState;
            Song3Count_USB_POWER_REG &= Song3Count_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Song3Count__SIO)
        Song3Count_SIO_REG = Song3Count_backup.sioState;
    #endif
}


/* [] END OF FILE */
