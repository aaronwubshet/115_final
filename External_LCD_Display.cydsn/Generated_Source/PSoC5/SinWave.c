/*******************************************************************************
* File Name: SinWave.c
* Version 2.10
*
* Description:
*  This file provides the source code for the 8-bit Waveform DAC 
*  (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SinWave.h"

uint8  SinWave_initVar = 0u;

const uint8 CYCODE SinWave_wave1[SinWave_WAVE1_LENGTH] = { 128u,159u,188u,213u,233u,246u,252u,250u,241u,224u,201u,174u,143u,112u,81u,54u,31u,14u,5u,3u,9u,22u,42u,67u,96u };
const uint8 CYCODE SinWave_wave2[SinWave_WAVE2_LENGTH] = { 128u,132u,138u,143u,148u,152u,158u,162u,168u,172u,178u,182u,188u,192u,198u,202u,208u,213u,218u,222u,228u,232u,238u,242u,248u,252u,248u,242u,238u,232u,228u,222u,218u,212u,208u,202u,198u,192u,188u,182u,178u,173u,168u,162u,158u,152u,148u,143u,138u,132u,128u,122u,118u,112u,107u,102u,97u,93u,88u,83u,78u,73u,68u,62u,57u,52u,47u,42u,37u,33u,28u,23u,18u,13u,8u,3u,8u,13u,18u,23u,28u,33u,37u,42u,47u,52u,57u,62u,68u,73u,78u,83u,88u,93u,97u,102u,107u,112u,118u,122u };

static uint8  SinWave_Wave1Chan;
static uint8  SinWave_Wave2Chan;
static uint8  SinWave_Wave1TD;
static uint8  SinWave_Wave2TD;


/*******************************************************************************
* Function Name: SinWave_Init
********************************************************************************
*
* Summary:
*  Initializes component with parameters set in the customizer.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void SinWave_Init(void) 
{
	SinWave_VDAC8_Init();
	SinWave_VDAC8_SetSpeed(SinWave_HIGHSPEED);
	SinWave_VDAC8_SetRange(SinWave_DAC_RANGE);

	#if(SinWave_DAC_MODE == SinWave_CURRENT_MODE)
		SinWave_IDAC8_SetPolarity(SinWave_DAC_POL);
	#endif /* SinWave_DAC_MODE == SinWave_CURRENT_MODE */

	#if(SinWave_OUT_MODE == SinWave_BUFFER_MODE)
	   SinWave_BuffAmp_Init();
	#endif /* SinWave_OUT_MODE == SinWave_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	SinWave_Wave1TD = CyDmaTdAllocate();
	SinWave_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	SinWave_Wave1Setup(SinWave_wave1, SinWave_WAVE1_LENGTH) ;
	SinWave_Wave2Setup(SinWave_wave2, SinWave_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(SinWave_DacClk_PHASE)
	   SinWave_DacClk_SetPhase(SinWave_CLK_PHASE_0nS);
	#endif /* defined(SinWave_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: SinWave_Enable
********************************************************************************
*  
* Summary: 
*  Enables the DAC block and DMA operation.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void SinWave_Enable(void) 
{
	SinWave_VDAC8_Enable();

	#if(SinWave_OUT_MODE == SinWave_BUFFER_MODE)
	   SinWave_BuffAmp_Enable();
	#endif /* SinWave_OUT_MODE == SinWave_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(SinWave_Wave1Chan, 1u);
	(void)CyDmaChEnable(SinWave_Wave2Chan, 1u);
	
	/* set the initial value */
	SinWave_SetValue(0u);
	
	#if(SinWave_CLOCK_SRC == SinWave_CLOCK_INT)  	
	   SinWave_DacClk_Start();
	#endif /* SinWave_CLOCK_SRC == SinWave_CLOCK_INT */
}


/*******************************************************************************
* Function Name: SinWave_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as 
*  executing the stop function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void SinWave_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(SinWave_initVar == 0u)
	{
		SinWave_Init();
		SinWave_initVar = 1u;
	}
	
	SinWave_Enable();
}


/*******************************************************************************
* Function Name: SinWave_StartEx
********************************************************************************
*
* Summary:
*  The StartEx function sets pointers and sizes for both waveforms
*  and then starts the component.
*
* Parameters:  
*   uint8 * wavePtr1:     Pointer to the waveform 1 array.
*   uint16  sampleSize1:  The amount of samples in the waveform 1.
*   uint8 * wavePtr2:     Pointer to the waveform 2 array.
*   uint16  sampleSize2:  The amount of samples in the waveform 2.
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void SinWave_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	SinWave_Wave1Setup(wavePtr1, sampleSize1);
	SinWave_Wave2Setup(wavePtr2, sampleSize2);
	SinWave_Start();
}


/*******************************************************************************
* Function Name: SinWave_Stop
********************************************************************************
*
* Summary:
*  Stops the clock (if internal), disables the DMA channels
*  and powers down the DAC.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
*******************************************************************************/
void SinWave_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(SinWave_CLOCK_SRC == SinWave_CLOCK_INT)  	
	   SinWave_DacClk_Stop();
	#endif /* SinWave_CLOCK_SRC == SinWave_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(SinWave_Wave1Chan);
	(void)CyDmaChDisable(SinWave_Wave2Chan);

	/* Disable power to DAC */
	SinWave_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: SinWave_Wave1Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 1.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None 
*
*******************************************************************************/
void SinWave_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (SinWave_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		SinWave_Wave1Chan = SinWave_Wave1_DMA_DmaInitialize(
		SinWave_Wave1_DMA_BYTES_PER_BURST, SinWave_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		SinWave_Wave1Chan = SinWave_Wave1_DMA_DmaInitialize(
		SinWave_Wave1_DMA_BYTES_PER_BURST, SinWave_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(SinWave_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(SinWave_Wave1TD, sampleSize, SinWave_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)SinWave_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(SinWave_Wave1TD, LO16((uint32)wavePtr), LO16(SinWave_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(SinWave_Wave1Chan, SinWave_Wave1TD);
}


/*******************************************************************************
* Function Name: SinWave_Wave2Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 2.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None
*
*******************************************************************************/
void SinWave_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (SinWave_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		SinWave_Wave2Chan = SinWave_Wave2_DMA_DmaInitialize(
		SinWave_Wave2_DMA_BYTES_PER_BURST, SinWave_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		SinWave_Wave2Chan = SinWave_Wave2_DMA_DmaInitialize(
		SinWave_Wave2_DMA_BYTES_PER_BURST, SinWave_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(SinWave_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(SinWave_Wave2TD, sampleSize, SinWave_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)SinWave_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(SinWave_Wave2TD, LO16((uint32)wavePtr), LO16(SinWave_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(SinWave_Wave2Chan, SinWave_Wave2TD);
}


/* [] END OF FILE */
