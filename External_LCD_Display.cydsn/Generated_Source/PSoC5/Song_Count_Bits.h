/*******************************************************************************
* File Name: Song_Count_Bits.h  
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

#if !defined(CY_PINS_Song_Count_Bits_H) /* Pins Song_Count_Bits_H */
#define CY_PINS_Song_Count_Bits_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Song_Count_Bits_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Song_Count_Bits__PORT == 15 && ((Song_Count_Bits__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Song_Count_Bits_Write(uint8 value);
void    Song_Count_Bits_SetDriveMode(uint8 mode);
uint8   Song_Count_Bits_ReadDataReg(void);
uint8   Song_Count_Bits_Read(void);
void    Song_Count_Bits_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song_Count_Bits_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Song_Count_Bits_SetDriveMode() function.
     *  @{
     */
        #define Song_Count_Bits_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Song_Count_Bits_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Song_Count_Bits_DM_RES_UP          PIN_DM_RES_UP
        #define Song_Count_Bits_DM_RES_DWN         PIN_DM_RES_DWN
        #define Song_Count_Bits_DM_OD_LO           PIN_DM_OD_LO
        #define Song_Count_Bits_DM_OD_HI           PIN_DM_OD_HI
        #define Song_Count_Bits_DM_STRONG          PIN_DM_STRONG
        #define Song_Count_Bits_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Song_Count_Bits_MASK               Song_Count_Bits__MASK
#define Song_Count_Bits_SHIFT              Song_Count_Bits__SHIFT
#define Song_Count_Bits_WIDTH              8u

/* Interrupt constants */
#if defined(Song_Count_Bits__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song_Count_Bits_SetInterruptMode() function.
     *  @{
     */
        #define Song_Count_Bits_INTR_NONE      (uint16)(0x0000u)
        #define Song_Count_Bits_INTR_RISING    (uint16)(0x0001u)
        #define Song_Count_Bits_INTR_FALLING   (uint16)(0x0002u)
        #define Song_Count_Bits_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Song_Count_Bits_INTR_MASK      (0x01u) 
#endif /* (Song_Count_Bits__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Song_Count_Bits_PS                     (* (reg8 *) Song_Count_Bits__PS)
/* Data Register */
#define Song_Count_Bits_DR                     (* (reg8 *) Song_Count_Bits__DR)
/* Port Number */
#define Song_Count_Bits_PRT_NUM                (* (reg8 *) Song_Count_Bits__PRT) 
/* Connect to Analog Globals */                                                  
#define Song_Count_Bits_AG                     (* (reg8 *) Song_Count_Bits__AG)                       
/* Analog MUX bux enable */
#define Song_Count_Bits_AMUX                   (* (reg8 *) Song_Count_Bits__AMUX) 
/* Bidirectional Enable */                                                        
#define Song_Count_Bits_BIE                    (* (reg8 *) Song_Count_Bits__BIE)
/* Bit-mask for Aliased Register Access */
#define Song_Count_Bits_BIT_MASK               (* (reg8 *) Song_Count_Bits__BIT_MASK)
/* Bypass Enable */
#define Song_Count_Bits_BYP                    (* (reg8 *) Song_Count_Bits__BYP)
/* Port wide control signals */                                                   
#define Song_Count_Bits_CTL                    (* (reg8 *) Song_Count_Bits__CTL)
/* Drive Modes */
#define Song_Count_Bits_DM0                    (* (reg8 *) Song_Count_Bits__DM0) 
#define Song_Count_Bits_DM1                    (* (reg8 *) Song_Count_Bits__DM1)
#define Song_Count_Bits_DM2                    (* (reg8 *) Song_Count_Bits__DM2) 
/* Input Buffer Disable Override */
#define Song_Count_Bits_INP_DIS                (* (reg8 *) Song_Count_Bits__INP_DIS)
/* LCD Common or Segment Drive */
#define Song_Count_Bits_LCD_COM_SEG            (* (reg8 *) Song_Count_Bits__LCD_COM_SEG)
/* Enable Segment LCD */
#define Song_Count_Bits_LCD_EN                 (* (reg8 *) Song_Count_Bits__LCD_EN)
/* Slew Rate Control */
#define Song_Count_Bits_SLW                    (* (reg8 *) Song_Count_Bits__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Song_Count_Bits_PRTDSI__CAPS_SEL       (* (reg8 *) Song_Count_Bits__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Song_Count_Bits_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Song_Count_Bits__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Song_Count_Bits_PRTDSI__OE_SEL0        (* (reg8 *) Song_Count_Bits__PRTDSI__OE_SEL0) 
#define Song_Count_Bits_PRTDSI__OE_SEL1        (* (reg8 *) Song_Count_Bits__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Song_Count_Bits_PRTDSI__OUT_SEL0       (* (reg8 *) Song_Count_Bits__PRTDSI__OUT_SEL0) 
#define Song_Count_Bits_PRTDSI__OUT_SEL1       (* (reg8 *) Song_Count_Bits__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Song_Count_Bits_PRTDSI__SYNC_OUT       (* (reg8 *) Song_Count_Bits__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Song_Count_Bits__SIO_CFG)
    #define Song_Count_Bits_SIO_HYST_EN        (* (reg8 *) Song_Count_Bits__SIO_HYST_EN)
    #define Song_Count_Bits_SIO_REG_HIFREQ     (* (reg8 *) Song_Count_Bits__SIO_REG_HIFREQ)
    #define Song_Count_Bits_SIO_CFG            (* (reg8 *) Song_Count_Bits__SIO_CFG)
    #define Song_Count_Bits_SIO_DIFF           (* (reg8 *) Song_Count_Bits__SIO_DIFF)
#endif /* (Song_Count_Bits__SIO_CFG) */

/* Interrupt Registers */
#if defined(Song_Count_Bits__INTSTAT)
    #define Song_Count_Bits_INTSTAT            (* (reg8 *) Song_Count_Bits__INTSTAT)
    #define Song_Count_Bits_SNAP               (* (reg8 *) Song_Count_Bits__SNAP)
    
	#define Song_Count_Bits_0_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__0__INTTYPE)
	#define Song_Count_Bits_1_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__1__INTTYPE)
	#define Song_Count_Bits_2_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__2__INTTYPE)
	#define Song_Count_Bits_3_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__3__INTTYPE)
	#define Song_Count_Bits_4_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__4__INTTYPE)
	#define Song_Count_Bits_5_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__5__INTTYPE)
	#define Song_Count_Bits_6_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__6__INTTYPE)
	#define Song_Count_Bits_7_INTTYPE_REG 		(* (reg8 *) Song_Count_Bits__7__INTTYPE)
#endif /* (Song_Count_Bits__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Song_Count_Bits_H */


/* [] END OF FILE */
