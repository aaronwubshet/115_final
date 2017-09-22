/*******************************************************************************
* File Name: PWMOut2.h  
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

#if !defined(CY_PINS_PWMOut2_H) /* Pins PWMOut2_H */
#define CY_PINS_PWMOut2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMOut2_aliases.h"


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
} PWMOut2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PWMOut2_Read(void);
void    PWMOut2_Write(uint8 value);
uint8   PWMOut2_ReadDataReg(void);
#if defined(PWMOut2__PC) || (CY_PSOC4_4200L) 
    void    PWMOut2_SetDriveMode(uint8 mode);
#endif
void    PWMOut2_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMOut2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PWMOut2_Sleep(void); 
void PWMOut2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PWMOut2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PWMOut2_DRIVE_MODE_BITS        (3)
    #define PWMOut2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMOut2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PWMOut2_SetDriveMode() function.
         *  @{
         */
        #define PWMOut2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PWMOut2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PWMOut2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PWMOut2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PWMOut2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PWMOut2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PWMOut2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PWMOut2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PWMOut2_MASK               PWMOut2__MASK
#define PWMOut2_SHIFT              PWMOut2__SHIFT
#define PWMOut2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMOut2_SetInterruptMode() function.
     *  @{
     */
        #define PWMOut2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PWMOut2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PWMOut2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PWMOut2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PWMOut2__SIO)
    #define PWMOut2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PWMOut2__PC) && (CY_PSOC4_4200L)
    #define PWMOut2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PWMOut2_USBIO_DISABLE              ((uint32)(~PWMOut2_USBIO_ENABLE))
    #define PWMOut2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PWMOut2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PWMOut2_USBIO_ENTER_SLEEP          ((uint32)((1u << PWMOut2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PWMOut2_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMOut2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PWMOut2_USBIO_SUSPEND_SHIFT)))
    #define PWMOut2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PWMOut2_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMOut2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PWMOut2__PC)
    /* Port Configuration */
    #define PWMOut2_PC                 (* (reg32 *) PWMOut2__PC)
#endif
/* Pin State */
#define PWMOut2_PS                     (* (reg32 *) PWMOut2__PS)
/* Data Register */
#define PWMOut2_DR                     (* (reg32 *) PWMOut2__DR)
/* Input Buffer Disable Override */
#define PWMOut2_INP_DIS                (* (reg32 *) PWMOut2__PC2)

/* Interrupt configuration Registers */
#define PWMOut2_INTCFG                 (* (reg32 *) PWMOut2__INTCFG)
#define PWMOut2_INTSTAT                (* (reg32 *) PWMOut2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PWMOut2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PWMOut2__SIO)
    #define PWMOut2_SIO_REG            (* (reg32 *) PWMOut2__SIO)
#endif /* (PWMOut2__SIO_CFG) */

/* USBIO registers */
#if !defined(PWMOut2__PC) && (CY_PSOC4_4200L)
    #define PWMOut2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PWMOut2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PWMOut2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PWMOut2_DRIVE_MODE_SHIFT       (0x00u)
#define PWMOut2_DRIVE_MODE_MASK        (0x07u << PWMOut2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PWMOut2_H */


/* [] END OF FILE */
