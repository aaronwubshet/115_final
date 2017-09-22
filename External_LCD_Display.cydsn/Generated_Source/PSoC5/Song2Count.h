/*******************************************************************************
* File Name: Song2Count.h  
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

#if !defined(CY_PINS_Song2Count_H) /* Pins Song2Count_H */
#define CY_PINS_Song2Count_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Song2Count_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Song2Count__PORT == 15 && ((Song2Count__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Song2Count_Write(uint8 value);
void    Song2Count_SetDriveMode(uint8 mode);
uint8   Song2Count_ReadDataReg(void);
uint8   Song2Count_Read(void);
void    Song2Count_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song2Count_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Song2Count_SetDriveMode() function.
     *  @{
     */
        #define Song2Count_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Song2Count_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Song2Count_DM_RES_UP          PIN_DM_RES_UP
        #define Song2Count_DM_RES_DWN         PIN_DM_RES_DWN
        #define Song2Count_DM_OD_LO           PIN_DM_OD_LO
        #define Song2Count_DM_OD_HI           PIN_DM_OD_HI
        #define Song2Count_DM_STRONG          PIN_DM_STRONG
        #define Song2Count_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Song2Count_MASK               Song2Count__MASK
#define Song2Count_SHIFT              Song2Count__SHIFT
#define Song2Count_WIDTH              4u

/* Interrupt constants */
#if defined(Song2Count__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song2Count_SetInterruptMode() function.
     *  @{
     */
        #define Song2Count_INTR_NONE      (uint16)(0x0000u)
        #define Song2Count_INTR_RISING    (uint16)(0x0001u)
        #define Song2Count_INTR_FALLING   (uint16)(0x0002u)
        #define Song2Count_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Song2Count_INTR_MASK      (0x01u) 
#endif /* (Song2Count__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Song2Count_PS                     (* (reg8 *) Song2Count__PS)
/* Data Register */
#define Song2Count_DR                     (* (reg8 *) Song2Count__DR)
/* Port Number */
#define Song2Count_PRT_NUM                (* (reg8 *) Song2Count__PRT) 
/* Connect to Analog Globals */                                                  
#define Song2Count_AG                     (* (reg8 *) Song2Count__AG)                       
/* Analog MUX bux enable */
#define Song2Count_AMUX                   (* (reg8 *) Song2Count__AMUX) 
/* Bidirectional Enable */                                                        
#define Song2Count_BIE                    (* (reg8 *) Song2Count__BIE)
/* Bit-mask for Aliased Register Access */
#define Song2Count_BIT_MASK               (* (reg8 *) Song2Count__BIT_MASK)
/* Bypass Enable */
#define Song2Count_BYP                    (* (reg8 *) Song2Count__BYP)
/* Port wide control signals */                                                   
#define Song2Count_CTL                    (* (reg8 *) Song2Count__CTL)
/* Drive Modes */
#define Song2Count_DM0                    (* (reg8 *) Song2Count__DM0) 
#define Song2Count_DM1                    (* (reg8 *) Song2Count__DM1)
#define Song2Count_DM2                    (* (reg8 *) Song2Count__DM2) 
/* Input Buffer Disable Override */
#define Song2Count_INP_DIS                (* (reg8 *) Song2Count__INP_DIS)
/* LCD Common or Segment Drive */
#define Song2Count_LCD_COM_SEG            (* (reg8 *) Song2Count__LCD_COM_SEG)
/* Enable Segment LCD */
#define Song2Count_LCD_EN                 (* (reg8 *) Song2Count__LCD_EN)
/* Slew Rate Control */
#define Song2Count_SLW                    (* (reg8 *) Song2Count__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Song2Count_PRTDSI__CAPS_SEL       (* (reg8 *) Song2Count__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Song2Count_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Song2Count__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Song2Count_PRTDSI__OE_SEL0        (* (reg8 *) Song2Count__PRTDSI__OE_SEL0) 
#define Song2Count_PRTDSI__OE_SEL1        (* (reg8 *) Song2Count__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Song2Count_PRTDSI__OUT_SEL0       (* (reg8 *) Song2Count__PRTDSI__OUT_SEL0) 
#define Song2Count_PRTDSI__OUT_SEL1       (* (reg8 *) Song2Count__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Song2Count_PRTDSI__SYNC_OUT       (* (reg8 *) Song2Count__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Song2Count__SIO_CFG)
    #define Song2Count_SIO_HYST_EN        (* (reg8 *) Song2Count__SIO_HYST_EN)
    #define Song2Count_SIO_REG_HIFREQ     (* (reg8 *) Song2Count__SIO_REG_HIFREQ)
    #define Song2Count_SIO_CFG            (* (reg8 *) Song2Count__SIO_CFG)
    #define Song2Count_SIO_DIFF           (* (reg8 *) Song2Count__SIO_DIFF)
#endif /* (Song2Count__SIO_CFG) */

/* Interrupt Registers */
#if defined(Song2Count__INTSTAT)
    #define Song2Count_INTSTAT            (* (reg8 *) Song2Count__INTSTAT)
    #define Song2Count_SNAP               (* (reg8 *) Song2Count__SNAP)
    
	#define Song2Count_0_INTTYPE_REG 		(* (reg8 *) Song2Count__0__INTTYPE)
	#define Song2Count_1_INTTYPE_REG 		(* (reg8 *) Song2Count__1__INTTYPE)
	#define Song2Count_2_INTTYPE_REG 		(* (reg8 *) Song2Count__2__INTTYPE)
	#define Song2Count_3_INTTYPE_REG 		(* (reg8 *) Song2Count__3__INTTYPE)
#endif /* (Song2Count__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Song2Count_H */


/* [] END OF FILE */
