/*******************************************************************************
* File Name: SensorValue5.h  
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

#if !defined(CY_PINS_SensorValue5_H) /* Pins SensorValue5_H */
#define CY_PINS_SensorValue5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SensorValue5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SensorValue5__PORT == 15 && ((SensorValue5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SensorValue5_Write(uint8 value);
void    SensorValue5_SetDriveMode(uint8 mode);
uint8   SensorValue5_ReadDataReg(void);
uint8   SensorValue5_Read(void);
void    SensorValue5_SetInterruptMode(uint16 position, uint16 mode);
uint8   SensorValue5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SensorValue5_SetDriveMode() function.
     *  @{
     */
        #define SensorValue5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SensorValue5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SensorValue5_DM_RES_UP          PIN_DM_RES_UP
        #define SensorValue5_DM_RES_DWN         PIN_DM_RES_DWN
        #define SensorValue5_DM_OD_LO           PIN_DM_OD_LO
        #define SensorValue5_DM_OD_HI           PIN_DM_OD_HI
        #define SensorValue5_DM_STRONG          PIN_DM_STRONG
        #define SensorValue5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SensorValue5_MASK               SensorValue5__MASK
#define SensorValue5_SHIFT              SensorValue5__SHIFT
#define SensorValue5_WIDTH              1u

/* Interrupt constants */
#if defined(SensorValue5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SensorValue5_SetInterruptMode() function.
     *  @{
     */
        #define SensorValue5_INTR_NONE      (uint16)(0x0000u)
        #define SensorValue5_INTR_RISING    (uint16)(0x0001u)
        #define SensorValue5_INTR_FALLING   (uint16)(0x0002u)
        #define SensorValue5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SensorValue5_INTR_MASK      (0x01u) 
#endif /* (SensorValue5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensorValue5_PS                     (* (reg8 *) SensorValue5__PS)
/* Data Register */
#define SensorValue5_DR                     (* (reg8 *) SensorValue5__DR)
/* Port Number */
#define SensorValue5_PRT_NUM                (* (reg8 *) SensorValue5__PRT) 
/* Connect to Analog Globals */                                                  
#define SensorValue5_AG                     (* (reg8 *) SensorValue5__AG)                       
/* Analog MUX bux enable */
#define SensorValue5_AMUX                   (* (reg8 *) SensorValue5__AMUX) 
/* Bidirectional Enable */                                                        
#define SensorValue5_BIE                    (* (reg8 *) SensorValue5__BIE)
/* Bit-mask for Aliased Register Access */
#define SensorValue5_BIT_MASK               (* (reg8 *) SensorValue5__BIT_MASK)
/* Bypass Enable */
#define SensorValue5_BYP                    (* (reg8 *) SensorValue5__BYP)
/* Port wide control signals */                                                   
#define SensorValue5_CTL                    (* (reg8 *) SensorValue5__CTL)
/* Drive Modes */
#define SensorValue5_DM0                    (* (reg8 *) SensorValue5__DM0) 
#define SensorValue5_DM1                    (* (reg8 *) SensorValue5__DM1)
#define SensorValue5_DM2                    (* (reg8 *) SensorValue5__DM2) 
/* Input Buffer Disable Override */
#define SensorValue5_INP_DIS                (* (reg8 *) SensorValue5__INP_DIS)
/* LCD Common or Segment Drive */
#define SensorValue5_LCD_COM_SEG            (* (reg8 *) SensorValue5__LCD_COM_SEG)
/* Enable Segment LCD */
#define SensorValue5_LCD_EN                 (* (reg8 *) SensorValue5__LCD_EN)
/* Slew Rate Control */
#define SensorValue5_SLW                    (* (reg8 *) SensorValue5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SensorValue5_PRTDSI__CAPS_SEL       (* (reg8 *) SensorValue5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SensorValue5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SensorValue5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SensorValue5_PRTDSI__OE_SEL0        (* (reg8 *) SensorValue5__PRTDSI__OE_SEL0) 
#define SensorValue5_PRTDSI__OE_SEL1        (* (reg8 *) SensorValue5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SensorValue5_PRTDSI__OUT_SEL0       (* (reg8 *) SensorValue5__PRTDSI__OUT_SEL0) 
#define SensorValue5_PRTDSI__OUT_SEL1       (* (reg8 *) SensorValue5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SensorValue5_PRTDSI__SYNC_OUT       (* (reg8 *) SensorValue5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SensorValue5__SIO_CFG)
    #define SensorValue5_SIO_HYST_EN        (* (reg8 *) SensorValue5__SIO_HYST_EN)
    #define SensorValue5_SIO_REG_HIFREQ     (* (reg8 *) SensorValue5__SIO_REG_HIFREQ)
    #define SensorValue5_SIO_CFG            (* (reg8 *) SensorValue5__SIO_CFG)
    #define SensorValue5_SIO_DIFF           (* (reg8 *) SensorValue5__SIO_DIFF)
#endif /* (SensorValue5__SIO_CFG) */

/* Interrupt Registers */
#if defined(SensorValue5__INTSTAT)
    #define SensorValue5_INTSTAT            (* (reg8 *) SensorValue5__INTSTAT)
    #define SensorValue5_SNAP               (* (reg8 *) SensorValue5__SNAP)
    
	#define SensorValue5_0_INTTYPE_REG 		(* (reg8 *) SensorValue5__0__INTTYPE)
#endif /* (SensorValue5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SensorValue5_H */


/* [] END OF FILE */
