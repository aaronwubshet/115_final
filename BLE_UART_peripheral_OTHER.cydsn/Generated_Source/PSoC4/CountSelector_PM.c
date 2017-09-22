/*******************************************************************************
* File Name: CountSelector.c  
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
#include "CountSelector.h"

static CountSelector_BACKUP_STRUCT  CountSelector_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: CountSelector_Sleep
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
*  \snippet CountSelector_SUT.c usage_CountSelector_Sleep_Wakeup
*******************************************************************************/
void CountSelector_Sleep(void)
{
    #if defined(CountSelector__PC)
        CountSelector_backup.pcState = CountSelector_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            CountSelector_backup.usbState = CountSelector_CR1_REG;
            CountSelector_USB_POWER_REG |= CountSelector_USBIO_ENTER_SLEEP;
            CountSelector_CR1_REG &= CountSelector_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(CountSelector__SIO)
        CountSelector_backup.sioState = CountSelector_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        CountSelector_SIO_REG &= (uint32)(~CountSelector_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: CountSelector_Wakeup
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
*  Refer to CountSelector_Sleep() for an example usage.
*******************************************************************************/
void CountSelector_Wakeup(void)
{
    #if defined(CountSelector__PC)
        CountSelector_PC = CountSelector_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            CountSelector_USB_POWER_REG &= CountSelector_USBIO_EXIT_SLEEP_PH1;
            CountSelector_CR1_REG = CountSelector_backup.usbState;
            CountSelector_USB_POWER_REG &= CountSelector_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(CountSelector__SIO)
        CountSelector_SIO_REG = CountSelector_backup.sioState;
    #endif
}


/* [] END OF FILE */
