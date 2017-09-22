/*******************************************************************************
* File Name: SongCount.h  
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

#if !defined(CY_PINS_SongCount_H) /* Pins SongCount_H */
#define CY_PINS_SongCount_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SongCount_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SongCount__PORT == 15 && ((SongCount__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SongCount_Write(uint8 value);
void    SongCount_SetDriveMode(uint8 mode);
uint8   SongCount_ReadDataReg(void);
uint8   SongCount_Read(void);
void    SongCount_SetInterruptMode(uint16 position, uint16 mode);
uint8   SongCount_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SongCount_SetDriveMode() function.
     *  @{
     */
        #define SongCount_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SongCount_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SongCount_DM_RES_UP          PIN_DM_RES_UP
        #define SongCount_DM_RES_DWN         PIN_DM_RES_DWN
        #define SongCount_DM_OD_LO           PIN_DM_OD_LO
        #define SongCount_DM_OD_HI           PIN_DM_OD_HI
        #define SongCount_DM_STRONG          PIN_DM_STRONG
        #define SongCount_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SongCount_MASK               SongCount__MASK
#define SongCount_SHIFT              SongCount__SHIFT
#define SongCount_WIDTH              8u

/* Interrupt constants */
#if defined(SongCount__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SongCount_SetInterruptMode() function.
     *  @{
     */
        #define SongCount_INTR_NONE      (uint16)(0x0000u)
        #define SongCount_INTR_RISING    (uint16)(0x0001u)
        #define SongCount_INTR_FALLING   (uint16)(0x0002u)
        #define SongCount_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SongCount_INTR_MASK      (0x01u) 
#endif /* (SongCount__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SongCount_PS                     (* (reg8 *) SongCount__PS)
/* Data Register */
#define SongCount_DR                     (* (reg8 *) SongCount__DR)
/* Port Number */
#define SongCount_PRT_NUM                (* (reg8 *) SongCount__PRT) 
/* Connect to Analog Globals */                                                  
#define SongCount_AG                     (* (reg8 *) SongCount__AG)                       
/* Analog MUX bux enable */
#define SongCount_AMUX                   (* (reg8 *) SongCount__AMUX) 
/* Bidirectional Enable */                                                        
#define SongCount_BIE                    (* (reg8 *) SongCount__BIE)
/* Bit-mask for Aliased Register Access */
#define SongCount_BIT_MASK               (* (reg8 *) SongCount__BIT_MASK)
/* Bypass Enable */
#define SongCount_BYP                    (* (reg8 *) SongCount__BYP)
/* Port wide control signals */                                                   
#define SongCount_CTL                    (* (reg8 *) SongCount__CTL)
/* Drive Modes */
#define SongCount_DM0                    (* (reg8 *) SongCount__DM0) 
#define SongCount_DM1                    (* (reg8 *) SongCount__DM1)
#define SongCount_DM2                    (* (reg8 *) SongCount__DM2) 
/* Input Buffer Disable Override */
#define SongCount_INP_DIS                (* (reg8 *) SongCount__INP_DIS)
/* LCD Common or Segment Drive */
#define SongCount_LCD_COM_SEG            (* (reg8 *) SongCount__LCD_COM_SEG)
/* Enable Segment LCD */
#define SongCount_LCD_EN                 (* (reg8 *) SongCount__LCD_EN)
/* Slew Rate Control */
#define SongCount_SLW                    (* (reg8 *) SongCount__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SongCount_PRTDSI__CAPS_SEL       (* (reg8 *) SongCount__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SongCount_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SongCount__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SongCount_PRTDSI__OE_SEL0        (* (reg8 *) SongCount__PRTDSI__OE_SEL0) 
#define SongCount_PRTDSI__OE_SEL1        (* (reg8 *) SongCount__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SongCount_PRTDSI__OUT_SEL0       (* (reg8 *) SongCount__PRTDSI__OUT_SEL0) 
#define SongCount_PRTDSI__OUT_SEL1       (* (reg8 *) SongCount__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SongCount_PRTDSI__SYNC_OUT       (* (reg8 *) SongCount__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SongCount__SIO_CFG)
    #define SongCount_SIO_HYST_EN        (* (reg8 *) SongCount__SIO_HYST_EN)
    #define SongCount_SIO_REG_HIFREQ     (* (reg8 *) SongCount__SIO_REG_HIFREQ)
    #define SongCount_SIO_CFG            (* (reg8 *) SongCount__SIO_CFG)
    #define SongCount_SIO_DIFF           (* (reg8 *) SongCount__SIO_DIFF)
#endif /* (SongCount__SIO_CFG) */

/* Interrupt Registers */
#if defined(SongCount__INTSTAT)
    #define SongCount_INTSTAT            (* (reg8 *) SongCount__INTSTAT)
    #define SongCount_SNAP               (* (reg8 *) SongCount__SNAP)
    
	#define SongCount_0_INTTYPE_REG 		(* (reg8 *) SongCount__0__INTTYPE)
	#define SongCount_1_INTTYPE_REG 		(* (reg8 *) SongCount__1__INTTYPE)
	#define SongCount_2_INTTYPE_REG 		(* (reg8 *) SongCount__2__INTTYPE)
	#define SongCount_3_INTTYPE_REG 		(* (reg8 *) SongCount__3__INTTYPE)
	#define SongCount_4_INTTYPE_REG 		(* (reg8 *) SongCount__4__INTTYPE)
	#define SongCount_5_INTTYPE_REG 		(* (reg8 *) SongCount__5__INTTYPE)
	#define SongCount_6_INTTYPE_REG 		(* (reg8 *) SongCount__6__INTTYPE)
	#define SongCount_7_INTTYPE_REG 		(* (reg8 *) SongCount__7__INTTYPE)
#endif /* (SongCount__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SongCount_H */


/* [] END OF FILE */
