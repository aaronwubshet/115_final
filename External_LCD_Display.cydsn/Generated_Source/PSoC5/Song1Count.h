/*******************************************************************************
* File Name: Song1Count.h  
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

#if !defined(CY_PINS_Song1Count_H) /* Pins Song1Count_H */
#define CY_PINS_Song1Count_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Song1Count_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Song1Count__PORT == 15 && ((Song1Count__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Song1Count_Write(uint8 value);
void    Song1Count_SetDriveMode(uint8 mode);
uint8   Song1Count_ReadDataReg(void);
uint8   Song1Count_Read(void);
void    Song1Count_SetInterruptMode(uint16 position, uint16 mode);
uint8   Song1Count_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Song1Count_SetDriveMode() function.
     *  @{
     */
        #define Song1Count_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Song1Count_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Song1Count_DM_RES_UP          PIN_DM_RES_UP
        #define Song1Count_DM_RES_DWN         PIN_DM_RES_DWN
        #define Song1Count_DM_OD_LO           PIN_DM_OD_LO
        #define Song1Count_DM_OD_HI           PIN_DM_OD_HI
        #define Song1Count_DM_STRONG          PIN_DM_STRONG
        #define Song1Count_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Song1Count_MASK               Song1Count__MASK
#define Song1Count_SHIFT              Song1Count__SHIFT
#define Song1Count_WIDTH              4u

/* Interrupt constants */
#if defined(Song1Count__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Song1Count_SetInterruptMode() function.
     *  @{
     */
        #define Song1Count_INTR_NONE      (uint16)(0x0000u)
        #define Song1Count_INTR_RISING    (uint16)(0x0001u)
        #define Song1Count_INTR_FALLING   (uint16)(0x0002u)
        #define Song1Count_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Song1Count_INTR_MASK      (0x01u) 
#endif /* (Song1Count__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Song1Count_PS                     (* (reg8 *) Song1Count__PS)
/* Data Register */
#define Song1Count_DR                     (* (reg8 *) Song1Count__DR)
/* Port Number */
#define Song1Count_PRT_NUM                (* (reg8 *) Song1Count__PRT) 
/* Connect to Analog Globals */                                                  
#define Song1Count_AG                     (* (reg8 *) Song1Count__AG)                       
/* Analog MUX bux enable */
#define Song1Count_AMUX                   (* (reg8 *) Song1Count__AMUX) 
/* Bidirectional Enable */                                                        
#define Song1Count_BIE                    (* (reg8 *) Song1Count__BIE)
/* Bit-mask for Aliased Register Access */
#define Song1Count_BIT_MASK               (* (reg8 *) Song1Count__BIT_MASK)
/* Bypass Enable */
#define Song1Count_BYP                    (* (reg8 *) Song1Count__BYP)
/* Port wide control signals */                                                   
#define Song1Count_CTL                    (* (reg8 *) Song1Count__CTL)
/* Drive Modes */
#define Song1Count_DM0                    (* (reg8 *) Song1Count__DM0) 
#define Song1Count_DM1                    (* (reg8 *) Song1Count__DM1)
#define Song1Count_DM2                    (* (reg8 *) Song1Count__DM2) 
/* Input Buffer Disable Override */
#define Song1Count_INP_DIS                (* (reg8 *) Song1Count__INP_DIS)
/* LCD Common or Segment Drive */
#define Song1Count_LCD_COM_SEG            (* (reg8 *) Song1Count__LCD_COM_SEG)
/* Enable Segment LCD */
#define Song1Count_LCD_EN                 (* (reg8 *) Song1Count__LCD_EN)
/* Slew Rate Control */
#define Song1Count_SLW                    (* (reg8 *) Song1Count__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Song1Count_PRTDSI__CAPS_SEL       (* (reg8 *) Song1Count__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Song1Count_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Song1Count__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Song1Count_PRTDSI__OE_SEL0        (* (reg8 *) Song1Count__PRTDSI__OE_SEL0) 
#define Song1Count_PRTDSI__OE_SEL1        (* (reg8 *) Song1Count__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Song1Count_PRTDSI__OUT_SEL0       (* (reg8 *) Song1Count__PRTDSI__OUT_SEL0) 
#define Song1Count_PRTDSI__OUT_SEL1       (* (reg8 *) Song1Count__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Song1Count_PRTDSI__SYNC_OUT       (* (reg8 *) Song1Count__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Song1Count__SIO_CFG)
    #define Song1Count_SIO_HYST_EN        (* (reg8 *) Song1Count__SIO_HYST_EN)
    #define Song1Count_SIO_REG_HIFREQ     (* (reg8 *) Song1Count__SIO_REG_HIFREQ)
    #define Song1Count_SIO_CFG            (* (reg8 *) Song1Count__SIO_CFG)
    #define Song1Count_SIO_DIFF           (* (reg8 *) Song1Count__SIO_DIFF)
#endif /* (Song1Count__SIO_CFG) */

/* Interrupt Registers */
#if defined(Song1Count__INTSTAT)
    #define Song1Count_INTSTAT            (* (reg8 *) Song1Count__INTSTAT)
    #define Song1Count_SNAP               (* (reg8 *) Song1Count__SNAP)
    
	#define Song1Count_0_INTTYPE_REG 		(* (reg8 *) Song1Count__0__INTTYPE)
	#define Song1Count_1_INTTYPE_REG 		(* (reg8 *) Song1Count__1__INTTYPE)
	#define Song1Count_2_INTTYPE_REG 		(* (reg8 *) Song1Count__2__INTTYPE)
	#define Song1Count_3_INTTYPE_REG 		(* (reg8 *) Song1Count__3__INTTYPE)
#endif /* (Song1Count__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Song1Count_H */


/* [] END OF FILE */
