/*******************************************************************************
* File Name: SineWaveGen_IDAC8.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the 8-bit Current 
*  DAC (IDAC8) User Module.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SineWaveGen_IDAC8.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 SineWaveGen_IDAC8_initVar = 0u;


#if (CY_PSOC5A)
    static SineWaveGen_IDAC8_LOWPOWER_BACKUP_STRUCT  SineWaveGen_IDAC8_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 SineWaveGen_IDAC8_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_Init(void) 
{
    SineWaveGen_IDAC8_CR0 = (SineWaveGen_IDAC8_MODE_I | SineWaveGen_IDAC8_DEFAULT_RANGE );

    /* Set default data source */
    #if(SineWaveGen_IDAC8_DEFAULT_DATA_SRC != 0u )    
        SineWaveGen_IDAC8_CR1 = (SineWaveGen_IDAC8_DEFAULT_CNTL | SineWaveGen_IDAC8_DACBUS_ENABLE);
    #else
        SineWaveGen_IDAC8_CR1 = (SineWaveGen_IDAC8_DEFAULT_CNTL | SineWaveGen_IDAC8_DACBUS_DISABLE);
    #endif /* (SineWaveGen_IDAC8_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(SineWaveGen_IDAC8_DEFAULT_POLARITY == SineWaveGen_IDAC8_HARDWARE_CONTROLLED)
        SineWaveGen_IDAC8_CR1 |= SineWaveGen_IDAC8_IDIR_SRC_UDB;
    #else
        SineWaveGen_IDAC8_CR1 |= SineWaveGen_IDAC8_DEFAULT_POLARITY;
    #endif/* (SineWaveGen_IDAC8_DEFAULT_POLARITY == SineWaveGen_IDAC8_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(SineWaveGen_IDAC8_HARDWARE_ENABLE != 0u ) 
        SineWaveGen_IDAC8_CR1 |= SineWaveGen_IDAC8_IDIR_CTL_UDB;
    #endif /* (SineWaveGen_IDAC8_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(SineWaveGen_IDAC8_DEFAULT_STRB != 0u)
        SineWaveGen_IDAC8_Strobe |= SineWaveGen_IDAC8_STRB_EN;
    #endif /* (SineWaveGen_IDAC8_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    SineWaveGen_IDAC8_SetSpeed(SineWaveGen_IDAC8_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    SineWaveGen_IDAC8_DacTrim();
    
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_Enable
********************************************************************************
* Summary:
*  Enable the IDAC8
* 
* Parameters:
*  void:
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_Enable(void) 
{
    SineWaveGen_IDAC8_PWRMGR |= SineWaveGen_IDAC8_ACT_PWR_EN;
    SineWaveGen_IDAC8_STBY_PWRMGR |= SineWaveGen_IDAC8_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(SineWaveGen_IDAC8_restoreReg == 1u)
        {
            SineWaveGen_IDAC8_CR0 = SineWaveGen_IDAC8_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            SineWaveGen_IDAC8_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_Start
********************************************************************************
* Summary:
*  Set power level then turn on IDAC8.
*
* Parameters:  
*  power: Sets power level between off (0) and (3) high power
*
* Return:
*  (void)
*
* Global variables:
*  SineWaveGen_IDAC8_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void SineWaveGen_IDAC8_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( SineWaveGen_IDAC8_initVar == 0u)  
    {
        SineWaveGen_IDAC8_Init();
        
        SineWaveGen_IDAC8_initVar = 1u;
    }
   
    /* Enable power to DAC */
    SineWaveGen_IDAC8_Enable();

    /* Set default value */
    SineWaveGen_IDAC8_SetValue(SineWaveGen_IDAC8_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_Stop
********************************************************************************
* Summary:
*  Powers down IDAC8 to lowest power state.
*
* Parameters:
*  (void)
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_Stop(void) 
{
    /* Disble power to DAC */
    SineWaveGen_IDAC8_PWRMGR &= (uint8)(~SineWaveGen_IDAC8_ACT_PWR_EN);
    SineWaveGen_IDAC8_STBY_PWRMGR &= (uint8)(~SineWaveGen_IDAC8_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        SineWaveGen_IDAC8_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        SineWaveGen_IDAC8_lowPowerBackup.DACCR0Reg = SineWaveGen_IDAC8_CR0;
        SineWaveGen_IDAC8_CR0 = (SineWaveGen_IDAC8_MODE_I | SineWaveGen_IDAC8_RANGE_3 | SineWaveGen_IDAC8_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_SetSpeed
********************************************************************************
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    SineWaveGen_IDAC8_CR0 &= (uint8)(~SineWaveGen_IDAC8_HS_MASK);
    SineWaveGen_IDAC8_CR0 |=  ( speed & SineWaveGen_IDAC8_HS_MASK);
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_SetPolarity
********************************************************************************
* Summary:
*  Sets IDAC to Sink or Source current.
*  
* Parameters:
*  Polarity: Sets the IDAC to Sink or Source 
*  0x00 - Source
*  0x04 - Sink
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
#if(SineWaveGen_IDAC8_DEFAULT_POLARITY != SineWaveGen_IDAC8_HARDWARE_CONTROLLED)
    void SineWaveGen_IDAC8_SetPolarity(uint8 polarity) 
    {
        SineWaveGen_IDAC8_CR1 &= (uint8)(~SineWaveGen_IDAC8_IDIR_MASK);                /* clear polarity bit */
        SineWaveGen_IDAC8_CR1 |= (polarity & SineWaveGen_IDAC8_IDIR_MASK);             /* set new value */
    
        SineWaveGen_IDAC8_DacTrim();
    }
#endif/*(SineWaveGen_IDAC8_DEFAULT_POLARITY != SineWaveGen_IDAC8_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_SetRange
********************************************************************************
* Summary:
*  Set current range
*
* Parameters:
*  Range: Sets on of four valid ranges.
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_SetRange(uint8 range) 
{
    SineWaveGen_IDAC8_CR0 &= (uint8)(~SineWaveGen_IDAC8_RANGE_MASK);       /* Clear existing mode */
    SineWaveGen_IDAC8_CR0 |= ( range & SineWaveGen_IDAC8_RANGE_MASK );     /*  Set Range  */
    SineWaveGen_IDAC8_DacTrim();
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_SetValue
********************************************************************************
* Summary:
*  Set DAC value
*
* Parameters:
*  value: Sets DAC value between 0 and 255.
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 SineWaveGen_IDAC8_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    SineWaveGen_IDAC8_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        SineWaveGen_IDAC8_Data = value;
        CyExitCriticalSection(SineWaveGen_IDAC8_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: SineWaveGen_IDAC8_DacTrim
********************************************************************************
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  None
*
* Return:
*  (void) 
*
* Theory:
*  Trim values for the IDAC blocks are stored in the "Customer Table" area in 
*  Row 1 of the Hidden Flash.  There are 8 bytes of trim data for each 
*  IDAC block.
*  The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* Side Effects:
*
*******************************************************************************/
void SineWaveGen_IDAC8_DacTrim(void) 
{
    uint8 mode;

    mode = ((SineWaveGen_IDAC8_CR0 & SineWaveGen_IDAC8_RANGE_MASK) >> 1u);
    
    if((SineWaveGen_IDAC8_IDIR_MASK & SineWaveGen_IDAC8_CR1) == SineWaveGen_IDAC8_IDIR_SINK)
    {
        mode++;
    }

    SineWaveGen_IDAC8_TR = CY_GET_XTND_REG8((uint8 *)(SineWaveGen_IDAC8_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
