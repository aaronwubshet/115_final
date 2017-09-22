/*******************************************************************************
* File Name: CountSelector.h  
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

#if !defined(CY_PINS_CountSelector_H) /* Pins CountSelector_H */
#define CY_PINS_CountSelector_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CountSelector_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CountSelector__PORT == 15 && ((CountSelector__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CountSelector_Write(uint8 value);
void    CountSelector_SetDriveMode(uint8 mode);
uint8   CountSelector_ReadDataReg(void);
uint8   CountSelector_Read(void);
void    CountSelector_SetInterruptMode(uint16 position, uint16 mode);
uint8   CountSelector_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CountSelector_SetDriveMode() function.
     *  @{
     */
        #define CountSelector_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CountSelector_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CountSelector_DM_RES_UP          PIN_DM_RES_UP
        #define CountSelector_DM_RES_DWN         PIN_DM_RES_DWN
        #define CountSelector_DM_OD_LO           PIN_DM_OD_LO
        #define CountSelector_DM_OD_HI           PIN_DM_OD_HI
        #define CountSelector_DM_STRONG          PIN_DM_STRONG
        #define CountSelector_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CountSelector_MASK               CountSelector__MASK
#define CountSelector_SHIFT              CountSelector__SHIFT
#define CountSelector_WIDTH              2u

/* Interrupt constants */
#if defined(CountSelector__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CountSelector_SetInterruptMode() function.
     *  @{
     */
        #define CountSelector_INTR_NONE      (uint16)(0x0000u)
        #define CountSelector_INTR_RISING    (uint16)(0x0001u)
        #define CountSelector_INTR_FALLING   (uint16)(0x0002u)
        #define CountSelector_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CountSelector_INTR_MASK      (0x01u) 
#endif /* (CountSelector__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CountSelector_PS                     (* (reg8 *) CountSelector__PS)
/* Data Register */
#define CountSelector_DR                     (* (reg8 *) CountSelector__DR)
/* Port Number */
#define CountSelector_PRT_NUM                (* (reg8 *) CountSelector__PRT) 
/* Connect to Analog Globals */                                                  
#define CountSelector_AG                     (* (reg8 *) CountSelector__AG)                       
/* Analog MUX bux enable */
#define CountSelector_AMUX                   (* (reg8 *) CountSelector__AMUX) 
/* Bidirectional Enable */                                                        
#define CountSelector_BIE                    (* (reg8 *) CountSelector__BIE)
/* Bit-mask for Aliased Register Access */
#define CountSelector_BIT_MASK               (* (reg8 *) CountSelector__BIT_MASK)
/* Bypass Enable */
#define CountSelector_BYP                    (* (reg8 *) CountSelector__BYP)
/* Port wide control signals */                                                   
#define CountSelector_CTL                    (* (reg8 *) CountSelector__CTL)
/* Drive Modes */
#define CountSelector_DM0                    (* (reg8 *) CountSelector__DM0) 
#define CountSelector_DM1                    (* (reg8 *) CountSelector__DM1)
#define CountSelector_DM2                    (* (reg8 *) CountSelector__DM2) 
/* Input Buffer Disable Override */
#define CountSelector_INP_DIS                (* (reg8 *) CountSelector__INP_DIS)
/* LCD Common or Segment Drive */
#define CountSelector_LCD_COM_SEG            (* (reg8 *) CountSelector__LCD_COM_SEG)
/* Enable Segment LCD */
#define CountSelector_LCD_EN                 (* (reg8 *) CountSelector__LCD_EN)
/* Slew Rate Control */
#define CountSelector_SLW                    (* (reg8 *) CountSelector__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CountSelector_PRTDSI__CAPS_SEL       (* (reg8 *) CountSelector__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CountSelector_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CountSelector__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CountSelector_PRTDSI__OE_SEL0        (* (reg8 *) CountSelector__PRTDSI__OE_SEL0) 
#define CountSelector_PRTDSI__OE_SEL1        (* (reg8 *) CountSelector__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CountSelector_PRTDSI__OUT_SEL0       (* (reg8 *) CountSelector__PRTDSI__OUT_SEL0) 
#define CountSelector_PRTDSI__OUT_SEL1       (* (reg8 *) CountSelector__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CountSelector_PRTDSI__SYNC_OUT       (* (reg8 *) CountSelector__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CountSelector__SIO_CFG)
    #define CountSelector_SIO_HYST_EN        (* (reg8 *) CountSelector__SIO_HYST_EN)
    #define CountSelector_SIO_REG_HIFREQ     (* (reg8 *) CountSelector__SIO_REG_HIFREQ)
    #define CountSelector_SIO_CFG            (* (reg8 *) CountSelector__SIO_CFG)
    #define CountSelector_SIO_DIFF           (* (reg8 *) CountSelector__SIO_DIFF)
#endif /* (CountSelector__SIO_CFG) */

/* Interrupt Registers */
#if defined(CountSelector__INTSTAT)
    #define CountSelector_INTSTAT            (* (reg8 *) CountSelector__INTSTAT)
    #define CountSelector_SNAP               (* (reg8 *) CountSelector__SNAP)
    
	#define CountSelector_0_INTTYPE_REG 		(* (reg8 *) CountSelector__0__INTTYPE)
	#define CountSelector_1_INTTYPE_REG 		(* (reg8 *) CountSelector__1__INTTYPE)
#endif /* (CountSelector__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CountSelector_H */


/* [] END OF FILE */
