/*******************************************************************************
* File Name: SineClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SineClock_H)
#define CY_CLOCK_SineClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void SineClock_Start(void) ;
void SineClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SineClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SineClock_StandbyPower(uint8 state) ;
void SineClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SineClock_GetDividerRegister(void) ;
void SineClock_SetModeRegister(uint8 modeBitMask) ;
void SineClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 SineClock_GetModeRegister(void) ;
void SineClock_SetSourceRegister(uint8 clkSource) ;
uint8 SineClock_GetSourceRegister(void) ;
#if defined(SineClock__CFG3)
void SineClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 SineClock_GetPhaseRegister(void) ;
#endif /* defined(SineClock__CFG3) */

#define SineClock_Enable()                       SineClock_Start()
#define SineClock_Disable()                      SineClock_Stop()
#define SineClock_SetDivider(clkDivider)         SineClock_SetDividerRegister(clkDivider, 1u)
#define SineClock_SetDividerValue(clkDivider)    SineClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define SineClock_SetMode(clkMode)               SineClock_SetModeRegister(clkMode)
#define SineClock_SetSource(clkSource)           SineClock_SetSourceRegister(clkSource)
#if defined(SineClock__CFG3)
#define SineClock_SetPhase(clkPhase)             SineClock_SetPhaseRegister(clkPhase)
#define SineClock_SetPhaseValue(clkPhase)        SineClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SineClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SineClock_CLKEN              (* (reg8 *) SineClock__PM_ACT_CFG)
#define SineClock_CLKEN_PTR          ((reg8 *) SineClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SineClock_CLKSTBY            (* (reg8 *) SineClock__PM_STBY_CFG)
#define SineClock_CLKSTBY_PTR        ((reg8 *) SineClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SineClock_DIV_LSB            (* (reg8 *) SineClock__CFG0)
#define SineClock_DIV_LSB_PTR        ((reg8 *) SineClock__CFG0)
#define SineClock_DIV_PTR            ((reg16 *) SineClock__CFG0)

/* Clock MSB divider configuration register. */
#define SineClock_DIV_MSB            (* (reg8 *) SineClock__CFG1)
#define SineClock_DIV_MSB_PTR        ((reg8 *) SineClock__CFG1)

/* Mode and source configuration register */
#define SineClock_MOD_SRC            (* (reg8 *) SineClock__CFG2)
#define SineClock_MOD_SRC_PTR        ((reg8 *) SineClock__CFG2)

#if defined(SineClock__CFG3)
/* Analog clock phase configuration register */
#define SineClock_PHASE              (* (reg8 *) SineClock__CFG3)
#define SineClock_PHASE_PTR          ((reg8 *) SineClock__CFG3)
#endif /* defined(SineClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SineClock_CLKEN_MASK         SineClock__PM_ACT_MSK
#define SineClock_CLKSTBY_MASK       SineClock__PM_STBY_MSK

/* CFG2 field masks */
#define SineClock_SRC_SEL_MSK        SineClock__CFG2_SRC_SEL_MASK
#define SineClock_MODE_MASK          (~(SineClock_SRC_SEL_MSK))

#if defined(SineClock__CFG3)
/* CFG3 phase mask */
#define SineClock_PHASE_MASK         SineClock__CFG3_PHASE_DLY_MASK
#endif /* defined(SineClock__CFG3) */

#endif /* CY_CLOCK_SineClock_H */


/* [] END OF FILE */
