/*******************************************************************************
* File Name: Song2Trigger.h  
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

#if !defined(CY_PINS_Song2Trigger_H) /* Pins Song2Trigger_H */
#define CY_PINS_Song2Trigger_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Song2Trigger_aliases.h"


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
} Song2Trigger_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Song2Trigger_Read(void);
void    Song2Trigger_Write(uint8 value);
uint8   Song2Trigger_ReadDataReg(void);
#if defined(Song2Trigger__PC) || (CY_PSOC4_4200L) 
    void    Song2Trigger_SetDriveMode(uint8 mode);
#endif
void    Song2Trigger_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song2Trigger_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Song2Trigger_Sleep(void); 
void Song2Trigger_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Song2Trigger__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Song2Trigger_DRIVE_MODE_BITS        (3)
    #define Song2Trigger_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Song2Trigger_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Song2Trigger_SetDriveMode() function.
         *  @{
         */
        #define Song2Trigger_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Song2Trigger_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Song2Trigger_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Song2Trigger_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Song2Trigger_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Song2Trigger_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Song2Trigger_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Song2Trigger_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Song2Trigger_MASK               Song2Trigger__MASK
#define Song2Trigger_SHIFT              Song2Trigger__SHIFT
#define Song2Trigger_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song2Trigger_SetInterruptMode() function.
     *  @{
     */
        #define Song2Trigger_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Song2Trigger_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Song2Trigger_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Song2Trigger_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Song2Trigger__SIO)
    #define Song2Trigger_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Song2Trigger__PC) && (CY_PSOC4_4200L)
    #define Song2Trigger_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Song2Trigger_USBIO_DISABLE              ((uint32)(~Song2Trigger_USBIO_ENABLE))
    #define Song2Trigger_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Song2Trigger_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Song2Trigger_USBIO_ENTER_SLEEP          ((uint32)((1u << Song2Trigger_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Song2Trigger_USBIO_SUSPEND_DEL_SHIFT)))
    #define Song2Trigger_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Song2Trigger_USBIO_SUSPEND_SHIFT)))
    #define Song2Trigger_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Song2Trigger_USBIO_SUSPEND_DEL_SHIFT)))
    #define Song2Trigger_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Song2Trigger__PC)
    /* Port Configuration */
    #define Song2Trigger_PC                 (* (reg32 *) Song2Trigger__PC)
#endif
/* Pin State */
#define Song2Trigger_PS                     (* (reg32 *) Song2Trigger__PS)
/* Data Register */
#define Song2Trigger_DR                     (* (reg32 *) Song2Trigger__DR)
/* Input Buffer Disable Override */
#define Song2Trigger_INP_DIS                (* (reg32 *) Song2Trigger__PC2)

/* Interrupt configuration Registers */
#define Song2Trigger_INTCFG                 (* (reg32 *) Song2Trigger__INTCFG)
#define Song2Trigger_INTSTAT                (* (reg32 *) Song2Trigger__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Song2Trigger_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Song2Trigger__SIO)
    #define Song2Trigger_SIO_REG            (* (reg32 *) Song2Trigger__SIO)
#endif /* (Song2Trigger__SIO_CFG) */

/* USBIO registers */
#if !defined(Song2Trigger__PC) && (CY_PSOC4_4200L)
    #define Song2Trigger_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Song2Trigger_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Song2Trigger_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Song2Trigger_DRIVE_MODE_SHIFT       (0x00u)
#define Song2Trigger_DRIVE_MODE_MASK        (0x07u << Song2Trigger_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Song2Trigger_H */


/* [] END OF FILE */
