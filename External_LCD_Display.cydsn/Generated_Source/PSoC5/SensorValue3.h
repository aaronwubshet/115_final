/*******************************************************************************
* File Name: SensorValue3.h  
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

#if !defined(CY_PINS_SensorValue3_H) /* Pins SensorValue3_H */
#define CY_PINS_SensorValue3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SensorValue3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SensorValue3__PORT == 15 && ((SensorValue3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SensorValue3_Write(uint8 value);
void    SensorValue3_SetDriveMode(uint8 mode);
uint8   SensorValue3_ReadDataReg(void);
uint8   SensorValue3_Read(void);
void    SensorValue3_SetInterruptMode(uint16 position, uint16 mode);
uint8   SensorValue3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SensorValue3_SetDriveMode() function.
     *  @{
     */
        #define SensorValue3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SensorValue3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SensorValue3_DM_RES_UP          PIN_DM_RES_UP
        #define SensorValue3_DM_RES_DWN         PIN_DM_RES_DWN
        #define SensorValue3_DM_OD_LO           PIN_DM_OD_LO
        #define SensorValue3_DM_OD_HI           PIN_DM_OD_HI
        #define SensorValue3_DM_STRONG          PIN_DM_STRONG
        #define SensorValue3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SensorValue3_MASK               SensorValue3__MASK
#define SensorValue3_SHIFT              SensorValue3__SHIFT
#define SensorValue3_WIDTH              1u

/* Interrupt constants */
#if defined(SensorValue3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SensorValue3_SetInterruptMode() function.
     *  @{
     */
        #define SensorValue3_INTR_NONE      (uint16)(0x0000u)
        #define SensorValue3_INTR_RISING    (uint16)(0x0001u)
        #define SensorValue3_INTR_FALLING   (uint16)(0x0002u)
        #define SensorValue3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SensorValue3_INTR_MASK      (0x01u) 
#endif /* (SensorValue3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SensorValue3_PS                     (* (reg8 *) SensorValue3__PS)
/* Data Register */
#define SensorValue3_DR                     (* (reg8 *) SensorValue3__DR)
/* Port Number */
#define SensorValue3_PRT_NUM                (* (reg8 *) SensorValue3__PRT) 
/* Connect to Analog Globals */                                                  
#define SensorValue3_AG                     (* (reg8 *) SensorValue3__AG)                       
/* Analog MUX bux enable */
#define SensorValue3_AMUX                   (* (reg8 *) SensorValue3__AMUX) 
/* Bidirectional Enable */                                                        
#define SensorValue3_BIE                    (* (reg8 *) SensorValue3__BIE)
/* Bit-mask for Aliased Register Access */
#define SensorValue3_BIT_MASK               (* (reg8 *) SensorValue3__BIT_MASK)
/* Bypass Enable */
#define SensorValue3_BYP                    (* (reg8 *) SensorValue3__BYP)
/* Port wide control signals */                                                   
#define SensorValue3_CTL                    (* (reg8 *) SensorValue3__CTL)
/* Drive Modes */
#define SensorValue3_DM0                    (* (reg8 *) SensorValue3__DM0) 
#define SensorValue3_DM1                    (* (reg8 *) SensorValue3__DM1)
#define SensorValue3_DM2                    (* (reg8 *) SensorValue3__DM2) 
/* Input Buffer Disable Override */
#define SensorValue3_INP_DIS                (* (reg8 *) SensorValue3__INP_DIS)
/* LCD Common or Segment Drive */
#define SensorValue3_LCD_COM_SEG            (* (reg8 *) SensorValue3__LCD_COM_SEG)
/* Enable Segment LCD */
#define SensorValue3_LCD_EN                 (* (reg8 *) SensorValue3__LCD_EN)
/* Slew Rate Control */
#define SensorValue3_SLW                    (* (reg8 *) SensorValue3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SensorValue3_PRTDSI__CAPS_SEL       (* (reg8 *) SensorValue3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SensorValue3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SensorValue3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SensorValue3_PRTDSI__OE_SEL0        (* (reg8 *) SensorValue3__PRTDSI__OE_SEL0) 
#define SensorValue3_PRTDSI__OE_SEL1        (* (reg8 *) SensorValue3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SensorValue3_PRTDSI__OUT_SEL0       (* (reg8 *) SensorValue3__PRTDSI__OUT_SEL0) 
#define SensorValue3_PRTDSI__OUT_SEL1       (* (reg8 *) SensorValue3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SensorValue3_PRTDSI__SYNC_OUT       (* (reg8 *) SensorValue3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SensorValue3__SIO_CFG)
    #define SensorValue3_SIO_HYST_EN        (* (reg8 *) SensorValue3__SIO_HYST_EN)
    #define SensorValue3_SIO_REG_HIFREQ     (* (reg8 *) SensorValue3__SIO_REG_HIFREQ)
    #define SensorValue3_SIO_CFG            (* (reg8 *) SensorValue3__SIO_CFG)
    #define SensorValue3_SIO_DIFF           (* (reg8 *) SensorValue3__SIO_DIFF)
#endif /* (SensorValue3__SIO_CFG) */

/* Interrupt Registers */
#if defined(SensorValue3__INTSTAT)
    #define SensorValue3_INTSTAT            (* (reg8 *) SensorValue3__INTSTAT)
    #define SensorValue3_SNAP               (* (reg8 *) SensorValue3__SNAP)
    
	#define SensorValue3_0_INTTYPE_REG 		(* (reg8 *) SensorValue3__0__INTTYPE)
#endif /* (SensorValue3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SensorValue3_H */


/* [] END OF FILE */
