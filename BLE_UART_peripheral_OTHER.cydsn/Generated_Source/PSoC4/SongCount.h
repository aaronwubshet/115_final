/*******************************************************************************
* File Name: SongCount.h  
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

#if !defined(CY_PINS_SongCount_H) /* Pins SongCount_H */
#define CY_PINS_SongCount_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SongCount_aliases.h"


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
} SongCount_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SongCount_Read(void);
void    SongCount_Write(uint8 value);
uint8   SongCount_ReadDataReg(void);
#if defined(SongCount__PC) || (CY_PSOC4_4200L) 
    void    SongCount_SetDriveMode(uint8 mode);
#endif
void    SongCount_SetInterruptMode(uint16 position, uint16 mode);
uint8   SongCount_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SongCount_Sleep(void); 
void SongCount_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SongCount__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SongCount_DRIVE_MODE_BITS        (3)
    #define SongCount_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SongCount_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SongCount_SetDriveMode() function.
         *  @{
         */
        #define SongCount_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SongCount_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SongCount_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SongCount_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SongCount_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SongCount_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SongCount_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SongCount_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SongCount_MASK               SongCount__MASK
#define SongCount_SHIFT              SongCount__SHIFT
#define SongCount_WIDTH              8u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SongCount_SetInterruptMode() function.
     *  @{
     */
        #define SongCount_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SongCount_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SongCount_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SongCount_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SongCount__SIO)
    #define SongCount_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SongCount__PC) && (CY_PSOC4_4200L)
    #define SongCount_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SongCount_USBIO_DISABLE              ((uint32)(~SongCount_USBIO_ENABLE))
    #define SongCount_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SongCount_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SongCount_USBIO_ENTER_SLEEP          ((uint32)((1u << SongCount_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SongCount_USBIO_SUSPEND_DEL_SHIFT)))
    #define SongCount_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SongCount_USBIO_SUSPEND_SHIFT)))
    #define SongCount_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SongCount_USBIO_SUSPEND_DEL_SHIFT)))
    #define SongCount_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SongCount__PC)
    /* Port Configuration */
    #define SongCount_PC                 (* (reg32 *) SongCount__PC)
#endif
/* Pin State */
#define SongCount_PS                     (* (reg32 *) SongCount__PS)
/* Data Register */
#define SongCount_DR                     (* (reg32 *) SongCount__DR)
/* Input Buffer Disable Override */
#define SongCount_INP_DIS                (* (reg32 *) SongCount__PC2)

/* Interrupt configuration Registers */
#define SongCount_INTCFG                 (* (reg32 *) SongCount__INTCFG)
#define SongCount_INTSTAT                (* (reg32 *) SongCount__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SongCount_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SongCount__SIO)
    #define SongCount_SIO_REG            (* (reg32 *) SongCount__SIO)
#endif /* (SongCount__SIO_CFG) */

/* USBIO registers */
#if !defined(SongCount__PC) && (CY_PSOC4_4200L)
    #define SongCount_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SongCount_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SongCount_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SongCount_DRIVE_MODE_SHIFT       (0x00u)
#define SongCount_DRIVE_MODE_MASK        (0x07u << SongCount_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SongCount_H */


/* [] END OF FILE */
