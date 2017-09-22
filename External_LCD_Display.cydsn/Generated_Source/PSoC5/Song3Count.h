/*******************************************************************************
* File Name: Song3Count.h  
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

#if !defined(CY_PINS_Song3Count_H) /* Pins Song3Count_H */
#define CY_PINS_Song3Count_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Song3Count_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Song3Count__PORT == 15 && ((Song3Count__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Song3Count_Write(uint8 value);
void    Song3Count_SetDriveMode(uint8 mode);
uint8   Song3Count_ReadDataReg(void);
uint8   Song3Count_Read(void);
void    Song3Count_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song3Count_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Song3Count_SetDriveMode() function.
     *  @{
     */
        #define Song3Count_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Song3Count_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Song3Count_DM_RES_UP          PIN_DM_RES_UP
        #define Song3Count_DM_RES_DWN         PIN_DM_RES_DWN
        #define Song3Count_DM_OD_LO           PIN_DM_OD_LO
        #define Song3Count_DM_OD_HI           PIN_DM_OD_HI
        #define Song3Count_DM_STRONG          PIN_DM_STRONG
        #define Song3Count_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Song3Count_MASK               Song3Count__MASK
#define Song3Count_SHIFT              Song3Count__SHIFT
#define Song3Count_WIDTH              4u

/* Interrupt constants */
#if defined(Song3Count__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song3Count_SetInterruptMode() function.
     *  @{
     */
        #define Song3Count_INTR_NONE      (uint16)(0x0000u)
        #define Song3Count_INTR_RISING    (uint16)(0x0001u)
        #define Song3Count_INTR_FALLING   (uint16)(0x0002u)
        #define Song3Count_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Song3Count_INTR_MASK      (0x01u) 
#endif /* (Song3Count__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Song3Count_PS                     (* (reg8 *) Song3Count__PS)
/* Data Register */
#define Song3Count_DR                     (* (reg8 *) Song3Count__DR)
/* Port Number */
#define Song3Count_PRT_NUM                (* (reg8 *) Song3Count__PRT) 
/* Connect to Analog Globals */                                                  
#define Song3Count_AG                     (* (reg8 *) Song3Count__AG)                       
/* Analog MUX bux enable */
#define Song3Count_AMUX                   (* (reg8 *) Song3Count__AMUX) 
/* Bidirectional Enable */                                                        
#define Song3Count_BIE                    (* (reg8 *) Song3Count__BIE)
/* Bit-mask for Aliased Register Access */
#define Song3Count_BIT_MASK               (* (reg8 *) Song3Count__BIT_MASK)
/* Bypass Enable */
#define Song3Count_BYP                    (* (reg8 *) Song3Count__BYP)
/* Port wide control signals */                                                   
#define Song3Count_CTL                    (* (reg8 *) Song3Count__CTL)
/* Drive Modes */
#define Song3Count_DM0                    (* (reg8 *) Song3Count__DM0) 
#define Song3Count_DM1                    (* (reg8 *) Song3Count__DM1)
#define Song3Count_DM2                    (* (reg8 *) Song3Count__DM2) 
/* Input Buffer Disable Override */
#define Song3Count_INP_DIS                (* (reg8 *) Song3Count__INP_DIS)
/* LCD Common or Segment Drive */
#define Song3Count_LCD_COM_SEG            (* (reg8 *) Song3Count__LCD_COM_SEG)
/* Enable Segment LCD */
#define Song3Count_LCD_EN                 (* (reg8 *) Song3Count__LCD_EN)
/* Slew Rate Control */
#define Song3Count_SLW                    (* (reg8 *) Song3Count__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Song3Count_PRTDSI__CAPS_SEL       (* (reg8 *) Song3Count__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Song3Count_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Song3Count__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Song3Count_PRTDSI__OE_SEL0        (* (reg8 *) Song3Count__PRTDSI__OE_SEL0) 
#define Song3Count_PRTDSI__OE_SEL1        (* (reg8 *) Song3Count__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Song3Count_PRTDSI__OUT_SEL0       (* (reg8 *) Song3Count__PRTDSI__OUT_SEL0) 
#define Song3Count_PRTDSI__OUT_SEL1       (* (reg8 *) Song3Count__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Song3Count_PRTDSI__SYNC_OUT       (* (reg8 *) Song3Count__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Song3Count__SIO_CFG)
    #define Song3Count_SIO_HYST_EN        (* (reg8 *) Song3Count__SIO_HYST_EN)
    #define Song3Count_SIO_REG_HIFREQ     (* (reg8 *) Song3Count__SIO_REG_HIFREQ)
    #define Song3Count_SIO_CFG            (* (reg8 *) Song3Count__SIO_CFG)
    #define Song3Count_SIO_DIFF           (* (reg8 *) Song3Count__SIO_DIFF)
#endif /* (Song3Count__SIO_CFG) */

/* Interrupt Registers */
#if defined(Song3Count__INTSTAT)
    #define Song3Count_INTSTAT            (* (reg8 *) Song3Count__INTSTAT)
    #define Song3Count_SNAP               (* (reg8 *) Song3Count__SNAP)
    
	#define Song3Count_0_INTTYPE_REG 		(* (reg8 *) Song3Count__0__INTTYPE)
	#define Song3Count_1_INTTYPE_REG 		(* (reg8 *) Song3Count__1__INTTYPE)
	#define Song3Count_2_INTTYPE_REG 		(* (reg8 *) Song3Count__2__INTTYPE)
	#define Song3Count_3_INTTYPE_REG 		(* (reg8 *) Song3Count__3__INTTYPE)
#endif /* (Song3Count__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Song3Count_H */


/* [] END OF FILE */
