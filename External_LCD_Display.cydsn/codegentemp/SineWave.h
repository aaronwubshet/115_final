/*******************************************************************************
* File Name: SineWave.h  
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

#if !defined(CY_PINS_SineWave_H) /* Pins SineWave_H */
#define CY_PINS_SineWave_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SineWave_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SineWave__PORT == 15 && ((SineWave__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SineWave_Write(uint8 value);
void    SineWave_SetDriveMode(uint8 mode);
uint8   SineWave_ReadDataReg(void);
uint8   SineWave_Read(void);
void    SineWave_SetInterruptMode(uint16 position, uint16 mode);
uint8   SineWave_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SineWave_SetDriveMode() function.
     *  @{
     */
        #define SineWave_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SineWave_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SineWave_DM_RES_UP          PIN_DM_RES_UP
        #define SineWave_DM_RES_DWN         PIN_DM_RES_DWN
        #define SineWave_DM_OD_LO           PIN_DM_OD_LO
        #define SineWave_DM_OD_HI           PIN_DM_OD_HI
        #define SineWave_DM_STRONG          PIN_DM_STRONG
        #define SineWave_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SineWave_MASK               SineWave__MASK
#define SineWave_SHIFT              SineWave__SHIFT
#define SineWave_WIDTH              1u

/* Interrupt constants */
#if defined(SineWave__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SineWave_SetInterruptMode() function.
     *  @{
     */
        #define SineWave_INTR_NONE      (uint16)(0x0000u)
        #define SineWave_INTR_RISING    (uint16)(0x0001u)
        #define SineWave_INTR_FALLING   (uint16)(0x0002u)
        #define SineWave_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SineWave_INTR_MASK      (0x01u) 
#endif /* (SineWave__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SineWave_PS                     (* (reg8 *) SineWave__PS)
/* Data Register */
#define SineWave_DR                     (* (reg8 *) SineWave__DR)
/* Port Number */
#define SineWave_PRT_NUM                (* (reg8 *) SineWave__PRT) 
/* Connect to Analog Globals */                                                  
#define SineWave_AG                     (* (reg8 *) SineWave__AG)                       
/* Analog MUX bux enable */
#define SineWave_AMUX                   (* (reg8 *) SineWave__AMUX) 
/* Bidirectional Enable */                                                        
#define SineWave_BIE                    (* (reg8 *) SineWave__BIE)
/* Bit-mask for Aliased Register Access */
#define SineWave_BIT_MASK               (* (reg8 *) SineWave__BIT_MASK)
/* Bypass Enable */
#define SineWave_BYP                    (* (reg8 *) SineWave__BYP)
/* Port wide control signals */                                                   
#define SineWave_CTL                    (* (reg8 *) SineWave__CTL)
/* Drive Modes */
#define SineWave_DM0                    (* (reg8 *) SineWave__DM0) 
#define SineWave_DM1                    (* (reg8 *) SineWave__DM1)
#define SineWave_DM2                    (* (reg8 *) SineWave__DM2) 
/* Input Buffer Disable Override */
#define SineWave_INP_DIS                (* (reg8 *) SineWave__INP_DIS)
/* LCD Common or Segment Drive */
#define SineWave_LCD_COM_SEG            (* (reg8 *) SineWave__LCD_COM_SEG)
/* Enable Segment LCD */
#define SineWave_LCD_EN                 (* (reg8 *) SineWave__LCD_EN)
/* Slew Rate Control */
#define SineWave_SLW                    (* (reg8 *) SineWave__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SineWave_PRTDSI__CAPS_SEL       (* (reg8 *) SineWave__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SineWave_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SineWave__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SineWave_PRTDSI__OE_SEL0        (* (reg8 *) SineWave__PRTDSI__OE_SEL0) 
#define SineWave_PRTDSI__OE_SEL1        (* (reg8 *) SineWave__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SineWave_PRTDSI__OUT_SEL0       (* (reg8 *) SineWave__PRTDSI__OUT_SEL0) 
#define SineWave_PRTDSI__OUT_SEL1       (* (reg8 *) SineWave__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SineWave_PRTDSI__SYNC_OUT       (* (reg8 *) SineWave__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SineWave__SIO_CFG)
    #define SineWave_SIO_HYST_EN        (* (reg8 *) SineWave__SIO_HYST_EN)
    #define SineWave_SIO_REG_HIFREQ     (* (reg8 *) SineWave__SIO_REG_HIFREQ)
    #define SineWave_SIO_CFG            (* (reg8 *) SineWave__SIO_CFG)
    #define SineWave_SIO_DIFF           (* (reg8 *) SineWave__SIO_DIFF)
#endif /* (SineWave__SIO_CFG) */

/* Interrupt Registers */
#if defined(SineWave__INTSTAT)
    #define SineWave_INTSTAT            (* (reg8 *) SineWave__INTSTAT)
    #define SineWave_SNAP               (* (reg8 *) SineWave__SNAP)
    
	#define SineWave_0_INTTYPE_REG 		(* (reg8 *) SineWave__0__INTTYPE)
#endif /* (SineWave__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SineWave_H */


/* [] END OF FILE */
