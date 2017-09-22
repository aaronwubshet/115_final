/*******************************************************************************
* File Name: Song2Trigger.h  
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

#if !defined(CY_PINS_Song2Trigger_H) /* Pins Song2Trigger_H */
#define CY_PINS_Song2Trigger_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Song2Trigger_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Song2Trigger__PORT == 15 && ((Song2Trigger__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Song2Trigger_Write(uint8 value);
void    Song2Trigger_SetDriveMode(uint8 mode);
uint8   Song2Trigger_ReadDataReg(void);
uint8   Song2Trigger_Read(void);
void    Song2Trigger_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song2Trigger_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Song2Trigger_SetDriveMode() function.
     *  @{
     */
        #define Song2Trigger_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Song2Trigger_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Song2Trigger_DM_RES_UP          PIN_DM_RES_UP
        #define Song2Trigger_DM_RES_DWN         PIN_DM_RES_DWN
        #define Song2Trigger_DM_OD_LO           PIN_DM_OD_LO
        #define Song2Trigger_DM_OD_HI           PIN_DM_OD_HI
        #define Song2Trigger_DM_STRONG          PIN_DM_STRONG
        #define Song2Trigger_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Song2Trigger_MASK               Song2Trigger__MASK
#define Song2Trigger_SHIFT              Song2Trigger__SHIFT
#define Song2Trigger_WIDTH              1u

/* Interrupt constants */
#if defined(Song2Trigger__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song2Trigger_SetInterruptMode() function.
     *  @{
     */
        #define Song2Trigger_INTR_NONE      (uint16)(0x0000u)
        #define Song2Trigger_INTR_RISING    (uint16)(0x0001u)
        #define Song2Trigger_INTR_FALLING   (uint16)(0x0002u)
        #define Song2Trigger_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Song2Trigger_INTR_MASK      (0x01u) 
#endif /* (Song2Trigger__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Song2Trigger_PS                     (* (reg8 *) Song2Trigger__PS)
/* Data Register */
#define Song2Trigger_DR                     (* (reg8 *) Song2Trigger__DR)
/* Port Number */
#define Song2Trigger_PRT_NUM                (* (reg8 *) Song2Trigger__PRT) 
/* Connect to Analog Globals */                                                  
#define Song2Trigger_AG                     (* (reg8 *) Song2Trigger__AG)                       
/* Analog MUX bux enable */
#define Song2Trigger_AMUX                   (* (reg8 *) Song2Trigger__AMUX) 
/* Bidirectional Enable */                                                        
#define Song2Trigger_BIE                    (* (reg8 *) Song2Trigger__BIE)
/* Bit-mask for Aliased Register Access */
#define Song2Trigger_BIT_MASK               (* (reg8 *) Song2Trigger__BIT_MASK)
/* Bypass Enable */
#define Song2Trigger_BYP                    (* (reg8 *) Song2Trigger__BYP)
/* Port wide control signals */                                                   
#define Song2Trigger_CTL                    (* (reg8 *) Song2Trigger__CTL)
/* Drive Modes */
#define Song2Trigger_DM0                    (* (reg8 *) Song2Trigger__DM0) 
#define Song2Trigger_DM1                    (* (reg8 *) Song2Trigger__DM1)
#define Song2Trigger_DM2                    (* (reg8 *) Song2Trigger__DM2) 
/* Input Buffer Disable Override */
#define Song2Trigger_INP_DIS                (* (reg8 *) Song2Trigger__INP_DIS)
/* LCD Common or Segment Drive */
#define Song2Trigger_LCD_COM_SEG            (* (reg8 *) Song2Trigger__LCD_COM_SEG)
/* Enable Segment LCD */
#define Song2Trigger_LCD_EN                 (* (reg8 *) Song2Trigger__LCD_EN)
/* Slew Rate Control */
#define Song2Trigger_SLW                    (* (reg8 *) Song2Trigger__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Song2Trigger_PRTDSI__CAPS_SEL       (* (reg8 *) Song2Trigger__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Song2Trigger_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Song2Trigger__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Song2Trigger_PRTDSI__OE_SEL0        (* (reg8 *) Song2Trigger__PRTDSI__OE_SEL0) 
#define Song2Trigger_PRTDSI__OE_SEL1        (* (reg8 *) Song2Trigger__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Song2Trigger_PRTDSI__OUT_SEL0       (* (reg8 *) Song2Trigger__PRTDSI__OUT_SEL0) 
#define Song2Trigger_PRTDSI__OUT_SEL1       (* (reg8 *) Song2Trigger__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Song2Trigger_PRTDSI__SYNC_OUT       (* (reg8 *) Song2Trigger__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Song2Trigger__SIO_CFG)
    #define Song2Trigger_SIO_HYST_EN        (* (reg8 *) Song2Trigger__SIO_HYST_EN)
    #define Song2Trigger_SIO_REG_HIFREQ     (* (reg8 *) Song2Trigger__SIO_REG_HIFREQ)
    #define Song2Trigger_SIO_CFG            (* (reg8 *) Song2Trigger__SIO_CFG)
    #define Song2Trigger_SIO_DIFF           (* (reg8 *) Song2Trigger__SIO_DIFF)
#endif /* (Song2Trigger__SIO_CFG) */

/* Interrupt Registers */
#if defined(Song2Trigger__INTSTAT)
    #define Song2Trigger_INTSTAT            (* (reg8 *) Song2Trigger__INTSTAT)
    #define Song2Trigger_SNAP               (* (reg8 *) Song2Trigger__SNAP)
    
	#define Song2Trigger_0_INTTYPE_REG 		(* (reg8 *) Song2Trigger__0__INTTYPE)
#endif /* (Song2Trigger__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Song2Trigger_H */


/* [] END OF FILE */
