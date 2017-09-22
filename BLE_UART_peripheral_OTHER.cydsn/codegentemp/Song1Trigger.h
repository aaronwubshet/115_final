/*******************************************************************************
* File Name: Song1Trigger.h  
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

#if !defined(CY_PINS_Song1Trigger_H) /* Pins Song1Trigger_H */
#define CY_PINS_Song1Trigger_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Song1Trigger_aliases.h"


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
} Song1Trigger_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Song1Trigger_Read(void);
void    Song1Trigger_Write(uint8 value);
uint8   Song1Trigger_ReadDataReg(void);
#if defined(Song1Trigger__PC) || (CY_PSOC4_4200L) 
    void    Song1Trigger_SetDriveMode(uint8 mode);
#endif
void    Song1Trigger_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song1Trigger_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Song1Trigger_Sleep(void); 
void Song1Trigger_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Song1Trigger__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Song1Trigger_DRIVE_MODE_BITS        (3)
    #define Song1Trigger_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Song1Trigger_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Song1Trigger_SetDriveMode() function.
         *  @{
         */
        #define Song1Trigger_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Song1Trigger_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Song1Trigger_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Song1Trigger_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Song1Trigger_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Song1Trigger_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Song1Trigger_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Song1Trigger_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Song1Trigger_MASK               Song1Trigger__MASK
#define Song1Trigger_SHIFT              Song1Trigger__SHIFT
#define Song1Trigger_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song1Trigger_SetInterruptMode() function.
     *  @{
     */
        #define Song1Trigger_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Song1Trigger_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Song1Trigger_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Song1Trigger_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Song1Trigger__SIO)
    #define Song1Trigger_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Song1Trigger__PC) && (CY_PSOC4_4200L)
    #define Song1Trigger_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Song1Trigger_USBIO_DISABLE              ((uint32)(~Song1Trigger_USBIO_ENABLE))
    #define Song1Trigger_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Song1Trigger_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Song1Trigger_USBIO_ENTER_SLEEP          ((uint32)((1u << Song1Trigger_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Song1Trigger_USBIO_SUSPEND_DEL_SHIFT)))
    #define Song1Trigger_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Song1Trigger_USBIO_SUSPEND_SHIFT)))
    #define Song1Trigger_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Song1Trigger_USBIO_SUSPEND_DEL_SHIFT)))
    #define Song1Trigger_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Song1Trigger__PC)
    /* Port Configuration */
    #define Song1Trigger_PC                 (* (reg32 *) Song1Trigger__PC)
#endif
/* Pin State */
#define Song1Trigger_PS                     (* (reg32 *) Song1Trigger__PS)
/* Data Register */
#define Song1Trigger_DR                     (* (reg32 *) Song1Trigger__DR)
/* Input Buffer Disable Override */
#define Song1Trigger_INP_DIS                (* (reg32 *) Song1Trigger__PC2)

/* Interrupt configuration Registers */
#define Song1Trigger_INTCFG                 (* (reg32 *) Song1Trigger__INTCFG)
#define Song1Trigger_INTSTAT                (* (reg32 *) Song1Trigger__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Song1Trigger_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Song1Trigger__SIO)
    #define Song1Trigger_SIO_REG            (* (reg32 *) Song1Trigger__SIO)
#endif /* (Song1Trigger__SIO_CFG) */

/* USBIO registers */
#if !defined(Song1Trigger__PC) && (CY_PSOC4_4200L)
    #define Song1Trigger_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Song1Trigger_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Song1Trigger_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Song1Trigger_DRIVE_MODE_SHIFT       (0x00u)
#define Song1Trigger_DRIVE_MODE_MASK        (0x07u << Song1Trigger_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Song1Trigger_H */


/* [] END OF FILE */
