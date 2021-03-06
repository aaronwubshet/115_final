/*******************************************************************************
* File Name: Song3Count.h  
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

#if !defined(CY_PINS_Song3Count_H) /* Pins Song3Count_H */
#define CY_PINS_Song3Count_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Song3Count_aliases.h"


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
} Song3Count_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Song3Count_Read(void);
void    Song3Count_Write(uint8 value);
uint8   Song3Count_ReadDataReg(void);
#if defined(Song3Count__PC) || (CY_PSOC4_4200L) 
    void    Song3Count_SetDriveMode(uint8 mode);
#endif
void    Song3Count_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song3Count_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Song3Count_Sleep(void); 
void Song3Count_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Song3Count__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Song3Count_DRIVE_MODE_BITS        (3)
    #define Song3Count_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Song3Count_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Song3Count_SetDriveMode() function.
         *  @{
         */
        #define Song3Count_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Song3Count_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Song3Count_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Song3Count_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Song3Count_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Song3Count_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Song3Count_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Song3Count_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Song3Count_MASK               Song3Count__MASK
#define Song3Count_SHIFT              Song3Count__SHIFT
#define Song3Count_WIDTH              4u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song3Count_SetInterruptMode() function.
     *  @{
     */
        #define Song3Count_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Song3Count_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Song3Count_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Song3Count_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Song3Count__SIO)
    #define Song3Count_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Song3Count__PC) && (CY_PSOC4_4200L)
    #define Song3Count_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Song3Count_USBIO_DISABLE              ((uint32)(~Song3Count_USBIO_ENABLE))
    #define Song3Count_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Song3Count_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Song3Count_USBIO_ENTER_SLEEP          ((uint32)((1u << Song3Count_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Song3Count_USBIO_SUSPEND_DEL_SHIFT)))
    #define Song3Count_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Song3Count_USBIO_SUSPEND_SHIFT)))
    #define Song3Count_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Song3Count_USBIO_SUSPEND_DEL_SHIFT)))
    #define Song3Count_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Song3Count__PC)
    /* Port Configuration */
    #define Song3Count_PC                 (* (reg32 *) Song3Count__PC)
#endif
/* Pin State */
#define Song3Count_PS                     (* (reg32 *) Song3Count__PS)
/* Data Register */
#define Song3Count_DR                     (* (reg32 *) Song3Count__DR)
/* Input Buffer Disable Override */
#define Song3Count_INP_DIS                (* (reg32 *) Song3Count__PC2)

/* Interrupt configuration Registers */
#define Song3Count_INTCFG                 (* (reg32 *) Song3Count__INTCFG)
#define Song3Count_INTSTAT                (* (reg32 *) Song3Count__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Song3Count_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Song3Count__SIO)
    #define Song3Count_SIO_REG            (* (reg32 *) Song3Count__SIO)
#endif /* (Song3Count__SIO_CFG) */

/* USBIO registers */
#if !defined(Song3Count__PC) && (CY_PSOC4_4200L)
    #define Song3Count_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Song3Count_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Song3Count_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Song3Count_DRIVE_MODE_SHIFT       (0x00u)
#define Song3Count_DRIVE_MODE_MASK        (0x07u << Song3Count_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Song3Count_H */


/* [] END OF FILE */
