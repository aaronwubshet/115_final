/*******************************************************************************
* File Name: IR_Rail_Value.h  
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

#if !defined(CY_PINS_IR_Rail_Value_H) /* Pins IR_Rail_Value_H */
#define CY_PINS_IR_Rail_Value_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IR_Rail_Value_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IR_Rail_Value__PORT == 15 && ((IR_Rail_Value__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IR_Rail_Value_Write(uint8 value);
void    IR_Rail_Value_SetDriveMode(uint8 mode);
uint8   IR_Rail_Value_ReadDataReg(void);
uint8   IR_Rail_Value_Read(void);
void    IR_Rail_Value_SetInterruptMode(uint16 position, uint16 mode);
uint8   IR_Rail_Value_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IR_Rail_Value_SetDriveMode() function.
     *  @{
     */
        #define IR_Rail_Value_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IR_Rail_Value_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IR_Rail_Value_DM_RES_UP          PIN_DM_RES_UP
        #define IR_Rail_Value_DM_RES_DWN         PIN_DM_RES_DWN
        #define IR_Rail_Value_DM_OD_LO           PIN_DM_OD_LO
        #define IR_Rail_Value_DM_OD_HI           PIN_DM_OD_HI
        #define IR_Rail_Value_DM_STRONG          PIN_DM_STRONG
        #define IR_Rail_Value_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IR_Rail_Value_MASK               IR_Rail_Value__MASK
#define IR_Rail_Value_SHIFT              IR_Rail_Value__SHIFT
#define IR_Rail_Value_WIDTH              1u

/* Interrupt constants */
#if defined(IR_Rail_Value__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IR_Rail_Value_SetInterruptMode() function.
     *  @{
     */
        #define IR_Rail_Value_INTR_NONE      (uint16)(0x0000u)
        #define IR_Rail_Value_INTR_RISING    (uint16)(0x0001u)
        #define IR_Rail_Value_INTR_FALLING   (uint16)(0x0002u)
        #define IR_Rail_Value_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IR_Rail_Value_INTR_MASK      (0x01u) 
#endif /* (IR_Rail_Value__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IR_Rail_Value_PS                     (* (reg8 *) IR_Rail_Value__PS)
/* Data Register */
#define IR_Rail_Value_DR                     (* (reg8 *) IR_Rail_Value__DR)
/* Port Number */
#define IR_Rail_Value_PRT_NUM                (* (reg8 *) IR_Rail_Value__PRT) 
/* Connect to Analog Globals */                                                  
#define IR_Rail_Value_AG                     (* (reg8 *) IR_Rail_Value__AG)                       
/* Analog MUX bux enable */
#define IR_Rail_Value_AMUX                   (* (reg8 *) IR_Rail_Value__AMUX) 
/* Bidirectional Enable */                                                        
#define IR_Rail_Value_BIE                    (* (reg8 *) IR_Rail_Value__BIE)
/* Bit-mask for Aliased Register Access */
#define IR_Rail_Value_BIT_MASK               (* (reg8 *) IR_Rail_Value__BIT_MASK)
/* Bypass Enable */
#define IR_Rail_Value_BYP                    (* (reg8 *) IR_Rail_Value__BYP)
/* Port wide control signals */                                                   
#define IR_Rail_Value_CTL                    (* (reg8 *) IR_Rail_Value__CTL)
/* Drive Modes */
#define IR_Rail_Value_DM0                    (* (reg8 *) IR_Rail_Value__DM0) 
#define IR_Rail_Value_DM1                    (* (reg8 *) IR_Rail_Value__DM1)
#define IR_Rail_Value_DM2                    (* (reg8 *) IR_Rail_Value__DM2) 
/* Input Buffer Disable Override */
#define IR_Rail_Value_INP_DIS                (* (reg8 *) IR_Rail_Value__INP_DIS)
/* LCD Common or Segment Drive */
#define IR_Rail_Value_LCD_COM_SEG            (* (reg8 *) IR_Rail_Value__LCD_COM_SEG)
/* Enable Segment LCD */
#define IR_Rail_Value_LCD_EN                 (* (reg8 *) IR_Rail_Value__LCD_EN)
/* Slew Rate Control */
#define IR_Rail_Value_SLW                    (* (reg8 *) IR_Rail_Value__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IR_Rail_Value_PRTDSI__CAPS_SEL       (* (reg8 *) IR_Rail_Value__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IR_Rail_Value_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IR_Rail_Value__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IR_Rail_Value_PRTDSI__OE_SEL0        (* (reg8 *) IR_Rail_Value__PRTDSI__OE_SEL0) 
#define IR_Rail_Value_PRTDSI__OE_SEL1        (* (reg8 *) IR_Rail_Value__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IR_Rail_Value_PRTDSI__OUT_SEL0       (* (reg8 *) IR_Rail_Value__PRTDSI__OUT_SEL0) 
#define IR_Rail_Value_PRTDSI__OUT_SEL1       (* (reg8 *) IR_Rail_Value__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IR_Rail_Value_PRTDSI__SYNC_OUT       (* (reg8 *) IR_Rail_Value__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IR_Rail_Value__SIO_CFG)
    #define IR_Rail_Value_SIO_HYST_EN        (* (reg8 *) IR_Rail_Value__SIO_HYST_EN)
    #define IR_Rail_Value_SIO_REG_HIFREQ     (* (reg8 *) IR_Rail_Value__SIO_REG_HIFREQ)
    #define IR_Rail_Value_SIO_CFG            (* (reg8 *) IR_Rail_Value__SIO_CFG)
    #define IR_Rail_Value_SIO_DIFF           (* (reg8 *) IR_Rail_Value__SIO_DIFF)
#endif /* (IR_Rail_Value__SIO_CFG) */

/* Interrupt Registers */
#if defined(IR_Rail_Value__INTSTAT)
    #define IR_Rail_Value_INTSTAT            (* (reg8 *) IR_Rail_Value__INTSTAT)
    #define IR_Rail_Value_SNAP               (* (reg8 *) IR_Rail_Value__SNAP)
    
	#define IR_Rail_Value_0_INTTYPE_REG 		(* (reg8 *) IR_Rail_Value__0__INTTYPE)
#endif /* (IR_Rail_Value__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IR_Rail_Value_H */


/* [] END OF FILE */
