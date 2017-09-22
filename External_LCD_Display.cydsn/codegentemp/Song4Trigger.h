/*******************************************************************************
* File Name: Song4Trigger.h  
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

#if !defined(CY_PINS_Song4Trigger_H) /* Pins Song4Trigger_H */
#define CY_PINS_Song4Trigger_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Song4Trigger_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Song4Trigger__PORT == 15 && ((Song4Trigger__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Song4Trigger_Write(uint8 value);
void    Song4Trigger_SetDriveMode(uint8 mode);
uint8   Song4Trigger_ReadDataReg(void);
uint8   Song4Trigger_Read(void);
void    Song4Trigger_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song4Trigger_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Song4Trigger_SetDriveMode() function.
     *  @{
     */
        #define Song4Trigger_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Song4Trigger_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Song4Trigger_DM_RES_UP          PIN_DM_RES_UP
        #define Song4Trigger_DM_RES_DWN         PIN_DM_RES_DWN
        #define Song4Trigger_DM_OD_LO           PIN_DM_OD_LO
        #define Song4Trigger_DM_OD_HI           PIN_DM_OD_HI
        #define Song4Trigger_DM_STRONG          PIN_DM_STRONG
        #define Song4Trigger_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Song4Trigger_MASK               Song4Trigger__MASK
#define Song4Trigger_SHIFT              Song4Trigger__SHIFT
#define Song4Trigger_WIDTH              1u

/* Interrupt constants */
#if defined(Song4Trigger__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song4Trigger_SetInterruptMode() function.
     *  @{
     */
        #define Song4Trigger_INTR_NONE      (uint16)(0x0000u)
        #define Song4Trigger_INTR_RISING    (uint16)(0x0001u)
        #define Song4Trigger_INTR_FALLING   (uint16)(0x0002u)
        #define Song4Trigger_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Song4Trigger_INTR_MASK      (0x01u) 
#endif /* (Song4Trigger__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Song4Trigger_PS                     (* (reg8 *) Song4Trigger__PS)
/* Data Register */
#define Song4Trigger_DR                     (* (reg8 *) Song4Trigger__DR)
/* Port Number */
#define Song4Trigger_PRT_NUM                (* (reg8 *) Song4Trigger__PRT) 
/* Connect to Analog Globals */                                                  
#define Song4Trigger_AG                     (* (reg8 *) Song4Trigger__AG)                       
/* Analog MUX bux enable */
#define Song4Trigger_AMUX                   (* (reg8 *) Song4Trigger__AMUX) 
/* Bidirectional Enable */                                                        
#define Song4Trigger_BIE                    (* (reg8 *) Song4Trigger__BIE)
/* Bit-mask for Aliased Register Access */
#define Song4Trigger_BIT_MASK               (* (reg8 *) Song4Trigger__BIT_MASK)
/* Bypass Enable */
#define Song4Trigger_BYP                    (* (reg8 *) Song4Trigger__BYP)
/* Port wide control signals */                                                   
#define Song4Trigger_CTL                    (* (reg8 *) Song4Trigger__CTL)
/* Drive Modes */
#define Song4Trigger_DM0                    (* (reg8 *) Song4Trigger__DM0) 
#define Song4Trigger_DM1                    (* (reg8 *) Song4Trigger__DM1)
#define Song4Trigger_DM2                    (* (reg8 *) Song4Trigger__DM2) 
/* Input Buffer Disable Override */
#define Song4Trigger_INP_DIS                (* (reg8 *) Song4Trigger__INP_DIS)
/* LCD Common or Segment Drive */
#define Song4Trigger_LCD_COM_SEG            (* (reg8 *) Song4Trigger__LCD_COM_SEG)
/* Enable Segment LCD */
#define Song4Trigger_LCD_EN                 (* (reg8 *) Song4Trigger__LCD_EN)
/* Slew Rate Control */
#define Song4Trigger_SLW                    (* (reg8 *) Song4Trigger__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Song4Trigger_PRTDSI__CAPS_SEL       (* (reg8 *) Song4Trigger__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Song4Trigger_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Song4Trigger__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Song4Trigger_PRTDSI__OE_SEL0        (* (reg8 *) Song4Trigger__PRTDSI__OE_SEL0) 
#define Song4Trigger_PRTDSI__OE_SEL1        (* (reg8 *) Song4Trigger__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Song4Trigger_PRTDSI__OUT_SEL0       (* (reg8 *) Song4Trigger__PRTDSI__OUT_SEL0) 
#define Song4Trigger_PRTDSI__OUT_SEL1       (* (reg8 *) Song4Trigger__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Song4Trigger_PRTDSI__SYNC_OUT       (* (reg8 *) Song4Trigger__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Song4Trigger__SIO_CFG)
    #define Song4Trigger_SIO_HYST_EN        (* (reg8 *) Song4Trigger__SIO_HYST_EN)
    #define Song4Trigger_SIO_REG_HIFREQ     (* (reg8 *) Song4Trigger__SIO_REG_HIFREQ)
    #define Song4Trigger_SIO_CFG            (* (reg8 *) Song4Trigger__SIO_CFG)
    #define Song4Trigger_SIO_DIFF           (* (reg8 *) Song4Trigger__SIO_DIFF)
#endif /* (Song4Trigger__SIO_CFG) */

/* Interrupt Registers */
#if defined(Song4Trigger__INTSTAT)
    #define Song4Trigger_INTSTAT            (* (reg8 *) Song4Trigger__INTSTAT)
    #define Song4Trigger_SNAP               (* (reg8 *) Song4Trigger__SNAP)
    
	#define Song4Trigger_0_INTTYPE_REG 		(* (reg8 *) Song4Trigger__0__INTTYPE)
#endif /* (Song4Trigger__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Song4Trigger_H */


/* [] END OF FILE */
