/*******************************************************************************
* File Name: SensorScan_Clock_int.h
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

#if !defined(CY_CLOCK_SensorScan_Clock_int_H)
#define CY_CLOCK_SensorScan_Clock_int_H

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

void SensorScan_Clock_int_Start(void) ;
void SensorScan_Clock_int_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SensorScan_Clock_int_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SensorScan_Clock_int_StandbyPower(uint8 state) ;
void SensorScan_Clock_int_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SensorScan_Clock_int_GetDividerRegister(void) ;
void SensorScan_Clock_int_SetModeRegister(uint8 modeBitMask) ;
void SensorScan_Clock_int_ClearModeRegister(uint8 modeBitMask) ;
uint8 SensorScan_Clock_int_GetModeRegister(void) ;
void SensorScan_Clock_int_SetSourceRegister(uint8 clkSource) ;
uint8 SensorScan_Clock_int_GetSourceRegister(void) ;
#if defined(SensorScan_Clock_int__CFG3)
void SensorScan_Clock_int_SetPhaseRegister(uint8 clkPhase) ;
uint8 SensorScan_Clock_int_GetPhaseRegister(void) ;
#endif /* defined(SensorScan_Clock_int__CFG3) */

#define SensorScan_Clock_int_Enable()                       SensorScan_Clock_int_Start()
#define SensorScan_Clock_int_Disable()                      SensorScan_Clock_int_Stop()
#define SensorScan_Clock_int_SetDivider(clkDivider)         SensorScan_Clock_int_SetDividerRegister(clkDivider, 1u)
#define SensorScan_Clock_int_SetDividerValue(clkDivider)    SensorScan_Clock_int_SetDividerRegister((clkDivider) - 1u, 1u)
#define SensorScan_Clock_int_SetMode(clkMode)               SensorScan_Clock_int_SetModeRegister(clkMode)
#define SensorScan_Clock_int_SetSource(clkSource)           SensorScan_Clock_int_SetSourceRegister(clkSource)
#if defined(SensorScan_Clock_int__CFG3)
#define SensorScan_Clock_int_SetPhase(clkPhase)             SensorScan_Clock_int_SetPhaseRegister(clkPhase)
#define SensorScan_Clock_int_SetPhaseValue(clkPhase)        SensorScan_Clock_int_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SensorScan_Clock_int__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SensorScan_Clock_int_CLKEN              (* (reg8 *) SensorScan_Clock_int__PM_ACT_CFG)
#define SensorScan_Clock_int_CLKEN_PTR          ((reg8 *) SensorScan_Clock_int__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SensorScan_Clock_int_CLKSTBY            (* (reg8 *) SensorScan_Clock_int__PM_STBY_CFG)
#define SensorScan_Clock_int_CLKSTBY_PTR        ((reg8 *) SensorScan_Clock_int__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SensorScan_Clock_int_DIV_LSB            (* (reg8 *) SensorScan_Clock_int__CFG0)
#define SensorScan_Clock_int_DIV_LSB_PTR        ((reg8 *) SensorScan_Clock_int__CFG0)
#define SensorScan_Clock_int_DIV_PTR            ((reg16 *) SensorScan_Clock_int__CFG0)

/* Clock MSB divider configuration register. */
#define SensorScan_Clock_int_DIV_MSB            (* (reg8 *) SensorScan_Clock_int__CFG1)
#define SensorScan_Clock_int_DIV_MSB_PTR        ((reg8 *) SensorScan_Clock_int__CFG1)

/* Mode and source configuration register */
#define SensorScan_Clock_int_MOD_SRC            (* (reg8 *) SensorScan_Clock_int__CFG2)
#define SensorScan_Clock_int_MOD_SRC_PTR        ((reg8 *) SensorScan_Clock_int__CFG2)

#if defined(SensorScan_Clock_int__CFG3)
/* Analog clock phase configuration register */
#define SensorScan_Clock_int_PHASE              (* (reg8 *) SensorScan_Clock_int__CFG3)
#define SensorScan_Clock_int_PHASE_PTR          ((reg8 *) SensorScan_Clock_int__CFG3)
#endif /* defined(SensorScan_Clock_int__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SensorScan_Clock_int_CLKEN_MASK         SensorScan_Clock_int__PM_ACT_MSK
#define SensorScan_Clock_int_CLKSTBY_MASK       SensorScan_Clock_int__PM_STBY_MSK

/* CFG2 field masks */
#define SensorScan_Clock_int_SRC_SEL_MSK        SensorScan_Clock_int__CFG2_SRC_SEL_MASK
#define SensorScan_Clock_int_MODE_MASK          (~(SensorScan_Clock_int_SRC_SEL_MSK))

#if defined(SensorScan_Clock_int__CFG3)
/* CFG3 phase mask */
#define SensorScan_Clock_int_PHASE_MASK         SensorScan_Clock_int__CFG3_PHASE_DLY_MASK
#endif /* defined(SensorScan_Clock_int__CFG3) */

#endif /* CY_CLOCK_SensorScan_Clock_int_H */


/* [] END OF FILE */
