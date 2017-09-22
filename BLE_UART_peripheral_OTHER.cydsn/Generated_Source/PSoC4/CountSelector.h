/*******************************************************************************
* File Name: CountSelector.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CountSelector_H) /* Pins CountSelector_H */
#define CY_PINS_CountSelector_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CountSelector_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} CountSelector_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   CountSelector_Read(void);
void    CountSelector_Write(uint8 value);
uint8   CountSelector_ReadDataReg(void);
#if defined(CountSelector__PC) || (CY_PSOC4_4200L) 
    void    CountSelector_SetDriveMode(uint8 mode);
#endif
void    CountSelector_SetInterruptMode(uint16 position, uint16 mode);
uint8   CountSelector_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void CountSelector_Sleep(void); 
void CountSelector_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(CountSelector__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define CountSelector_DRIVE_MODE_BITS        (3)
    #define CountSelector_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CountSelector_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the CountSelector_SetDriveMode() function.
         *  @{
         */
        #define CountSelector_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define CountSelector_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define CountSelector_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define CountSelector_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define CountSelector_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define CountSelector_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define CountSelector_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define CountSelector_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define CountSelector_MASK               CountSelector__MASK
#define CountSelector_SHIFT              CountSelector__SHIFT
#define CountSelector_WIDTH              2u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CountSelector_SetInterruptMode() function.
     *  @{
     */
        #define CountSelector_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define CountSelector_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define CountSelector_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define CountSelector_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(CountSelector__SIO)
    #define CountSelector_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(CountSelector__PC) && (CY_PSOC4_4200L)
    #define CountSelector_USBIO_ENABLE               ((uint32)0x80000000u)
    #define CountSelector_USBIO_DISABLE              ((uint32)(~CountSelector_USBIO_ENABLE))
    #define CountSelector_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define CountSelector_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define CountSelector_USBIO_ENTER_SLEEP          ((uint32)((1u << CountSelector_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << CountSelector_USBIO_SUSPEND_DEL_SHIFT)))
    #define CountSelector_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << CountSelector_USBIO_SUSPEND_SHIFT)))
    #define CountSelector_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << CountSelector_USBIO_SUSPEND_DEL_SHIFT)))
    #define CountSelector_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(CountSelector__PC)
    /* Port Configuration */
    #define CountSelector_PC                 (* (reg32 *) CountSelector__PC)
#endif
/* Pin State */
#define CountSelector_PS                     (* (reg32 *) CountSelector__PS)
/* Data Register */
#define CountSelector_DR                     (* (reg32 *) CountSelector__DR)
/* Input Buffer Disable Override */
#define CountSelector_INP_DIS                (* (reg32 *) CountSelector__PC2)

/* Interrupt configuration Registers */
#define CountSelector_INTCFG                 (* (reg32 *) CountSelector__INTCFG)
#define CountSelector_INTSTAT                (* (reg32 *) CountSelector__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define CountSelector_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(CountSelector__SIO)
    #define CountSelector_SIO_REG            (* (reg32 *) CountSelector__SIO)
#endif /* (CountSelector__SIO_CFG) */

/* USBIO registers */
#if !defined(CountSelector__PC) && (CY_PSOC4_4200L)
    #define CountSelector_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define CountSelector_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define CountSelector_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define CountSelector_DRIVE_MODE_SHIFT       (0x00u)
#define CountSelector_DRIVE_MODE_MASK        (0x07u << CountSelector_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins CountSelector_H */


/* [] END OF FILE */
