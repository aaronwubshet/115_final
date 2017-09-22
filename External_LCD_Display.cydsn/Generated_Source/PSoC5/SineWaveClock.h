/*******************************************************************************
* File Name: SineWaveClock.h
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

#if !defined(CY_CLOCK_SineWaveClock_H)
#define CY_CLOCK_SineWaveClock_H

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

void SineWaveClock_Start(void) ;
void SineWaveClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SineWaveClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SineWaveClock_StandbyPower(uint8 state) ;
void SineWaveClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SineWaveClock_GetDividerRegister(void) ;
void SineWaveClock_SetModeRegister(uint8 modeBitMask) ;
void SineWaveClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 SineWaveClock_GetModeRegister(void) ;
void SineWaveClock_SetSourceRegister(uint8 clkSource) ;
uint8 SineWaveClock_GetSourceRegister(void) ;
#if defined(SineWaveClock__CFG3)
void SineWaveClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 SineWaveClock_GetPhaseRegister(void) ;
#endif /* defined(SineWaveClock__CFG3) */

#define SineWaveClock_Enable()                       SineWaveClock_Start()
#define SineWaveClock_Disable()                      SineWaveClock_Stop()
#define SineWaveClock_SetDivider(clkDivider)         SineWaveClock_SetDividerRegister(clkDivider, 1u)
#define SineWaveClock_SetDividerValue(clkDivider)    SineWaveClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define SineWaveClock_SetMode(clkMode)               SineWaveClock_SetModeRegister(clkMode)
#define SineWaveClock_SetSource(clkSource)           SineWaveClock_SetSourceRegister(clkSource)
#if defined(SineWaveClock__CFG3)
#define SineWaveClock_SetPhase(clkPhase)             SineWaveClock_SetPhaseRegister(clkPhase)
#define SineWaveClock_SetPhaseValue(clkPhase)        SineWaveClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SineWaveClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SineWaveClock_CLKEN              (* (reg8 *) SineWaveClock__PM_ACT_CFG)
#define SineWaveClock_CLKEN_PTR          ((reg8 *) SineWaveClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SineWaveClock_CLKSTBY            (* (reg8 *) SineWaveClock__PM_STBY_CFG)
#define SineWaveClock_CLKSTBY_PTR        ((reg8 *) SineWaveClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SineWaveClock_DIV_LSB            (* (reg8 *) SineWaveClock__CFG0)
#define SineWaveClock_DIV_LSB_PTR        ((reg8 *) SineWaveClock__CFG0)
#define SineWaveClock_DIV_PTR            ((reg16 *) SineWaveClock__CFG0)

/* Clock MSB divider configuration register. */
#define SineWaveClock_DIV_MSB            (* (reg8 *) SineWaveClock__CFG1)
#define SineWaveClock_DIV_MSB_PTR        ((reg8 *) SineWaveClock__CFG1)

/* Mode and source configuration register */
#define SineWaveClock_MOD_SRC            (* (reg8 *) SineWaveClock__CFG2)
#define SineWaveClock_MOD_SRC_PTR        ((reg8 *) SineWaveClock__CFG2)

#if defined(SineWaveClock__CFG3)
/* Analog clock phase configuration register */
#define SineWaveClock_PHASE              (* (reg8 *) SineWaveClock__CFG3)
#define SineWaveClock_PHASE_PTR          ((reg8 *) SineWaveClock__CFG3)
#endif /* defined(SineWaveClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SineWaveClock_CLKEN_MASK         SineWaveClock__PM_ACT_MSK
#define SineWaveClock_CLKSTBY_MASK       SineWaveClock__PM_STBY_MSK

/* CFG2 field masks */
#define SineWaveClock_SRC_SEL_MSK        SineWaveClock__CFG2_SRC_SEL_MASK
#define SineWaveClock_MODE_MASK          (~(SineWaveClock_SRC_SEL_MSK))

#if defined(SineWaveClock__CFG3)
/* CFG3 phase mask */
#define SineWaveClock_PHASE_MASK         SineWaveClock__CFG3_PHASE_DLY_MASK
#endif /* defined(SineWaveClock__CFG3) */

#endif /* CY_CLOCK_SineWaveClock_H */


/* [] END OF FILE */
