/*******************************************************************************
* File Name: SensorValue1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SensorValue1_H) /* Pins SensorValue1_H */
#define CY_PINS_SensorValue1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SensorValue1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SensorValue1__PORT == 15 && ((SensorValue1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SensorValue1_Write(uint8 value);
void    SensorValue1_SetDriveMode(uint8 mode);
uint8   SensorValue1_ReadDataReg(void);
uint8   SensorValue1_Read(void);
void    SensorValue1_SetInterruptMode(uint16 position, uint16 mode);
uint8   SensorValue1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SensorValue1_SetDriveMode() function.
     *  @{
     */
        #define SensorValue1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SensorValue1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SensorValue1_DM_RES_UP          PIN_DM_RES_UP
        #define SensorValue1_DM_RES_DWN         PIN_DM_RES_DWN
        #define SensorValue1_DM_OD_LO           PIN_DM_OD_LO
        #define SensorValue1_DM_OD_HI           PIN_DM_OD_HI
        #define SensorValue1_DM_STRONG          PIN_DM_STRONG
        #define SensorValue1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SensorValue1_MASK               SensorValue1__MASK
#define SensorValue1_SHIFT              SensorValue1__SHIFT
#define SensorValue1_WIDTH              1u

/* Interrupt constants */
#if defined(SensorValue1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SensorValue1_SetInterruptMode() function.
     *  @{
     */
        #define SensorValue1_INTR_NONE      (uint16)(0x0000u)
        #define SensorValue1_INTR_RISING    (uint16)(0x0001u)
        #define SensorValue1_INTR_FALLING   (uint16)(0x0002u)
        #define SensorValue1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SensorValue1_INTR_MASK      (0x01u) 
#endif /* (SensorValue1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensorValue1_PS                     (* (reg8 *) SensorValue1__PS)
/* Data Register */
#define SensorValue1_DR                     (* (reg8 *) SensorValue1__DR)
/* Port Number */
#define SensorValue1_PRT_NUM                (* (reg8 *) SensorValue1__PRT) 
/* Connect to Analog Globals */                                                  
#define SensorValue1_AG                     (* (reg8 *) SensorValue1__AG)                       
/* Analog MUX bux enable */
#define SensorValue1_AMUX                   (* (reg8 *) SensorValue1__AMUX) 
/* Bidirectional Enable */                                                        
#define SensorValue1_BIE                    (* (reg8 *) SensorValue1__BIE)
/* Bit-mask for Aliased Register Access */
#define SensorValue1_BIT_MASK               (* (reg8 *) SensorValue1__BIT_MASK)
/* Bypass Enable */
#define SensorValue1_BYP                    (* (reg8 *) SensorValue1__BYP)
/* Port wide control signals */                                                   
#define SensorValue1_CTL                    (* (reg8 *) SensorValue1__CTL)
/* Drive Modes */
#define SensorValue1_DM0                    (* (reg8 *) SensorValue1__DM0) 
#define SensorValue1_DM1                    (* (reg8 *) SensorValue1__DM1)
#define SensorValue1_DM2                    (* (reg8 *) SensorValue1__DM2) 
/* Input Buffer Disable Override */
#define SensorValue1_INP_DIS                (* (reg8 *) SensorValue1__INP_DIS)
/* LCD Common or Segment Drive */
#define SensorValue1_LCD_COM_SEG            (* (reg8 *) SensorValue1__LCD_COM_SEG)
/* Enable Segment LCD */
#define SensorValue1_LCD_EN                 (* (reg8 *) SensorValue1__LCD_EN)
/* Slew Rate Control */
#define SensorValue1_SLW                    (* (reg8 *) SensorValue1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SensorValue1_PRTDSI__CAPS_SEL       (* (reg8 *) SensorValue1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SensorValue1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SensorValue1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SensorValue1_PRTDSI__OE_SEL0        (* (reg8 *) SensorValue1__PRTDSI__OE_SEL0) 
#define SensorValue1_PRTDSI__OE_SEL1        (* (reg8 *) SensorValue1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SensorValue1_PRTDSI__OUT_SEL0       (* (reg8 *) SensorValue1__PRTDSI__OUT_SEL0) 
#define SensorValue1_PRTDSI__OUT_SEL1       (* (reg8 *) SensorValue1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SensorValue1_PRTDSI__SYNC_OUT       (* (reg8 *) SensorValue1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SensorValue1__SIO_CFG)
    #define SensorValue1_SIO_HYST_EN        (* (reg8 *) SensorValue1__SIO_HYST_EN)
    #define SensorValue1_SIO_REG_HIFREQ     (* (reg8 *) SensorValue1__SIO_REG_HIFREQ)
    #define SensorValue1_SIO_CFG            (* (reg8 *) SensorValue1__SIO_CFG)
    #define SensorValue1_SIO_DIFF           (* (reg8 *) SensorValue1__SIO_DIFF)
#endif /* (SensorValue1__SIO_CFG) */

/* Interrupt Registers */
#if defined(SensorValue1__INTSTAT)
    #define SensorValue1_INTSTAT            (* (reg8 *) SensorValue1__INTSTAT)
    #define SensorValue1_SNAP               (* (reg8 *) SensorValue1__SNAP)
    
	#define SensorValue1_0_INTTYPE_REG 		(* (reg8 *) SensorValue1__0__INTTYPE)
#endif /* (SensorValue1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SensorValue1_H */


/* [] END OF FILE */
