/*******************************************************************************
* File Name: SineWaveGen.c
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

#include "SineWaveGen.h"

uint8  SineWaveGen_initVar = 0u;

const uint8 CYCODE SineWaveGen_wave1[SineWaveGen_WAVE1_LENGTH] = { 88u,93u,98u,104u,109u,115u,120u,125u,130u,134u,139u,143u,147u,151u,155u,158u,161u,164u,167u,169u,171u,172u,173u,174u,175u,175u,175u,174u,173u,172u,171u,169u,167u,164u,161u,158u,155u,151u,147u,143u,139u,134u,130u,125u,120u,115u,109u,104u,98u,93u,88u,82u,77u,71u,66u,60u,55u,50u,45u,41u,36u,32u,28u,24u,20u,17u,14u,11u,8u,6u,4u,3u,2u,1u,0u,0u,0u,1u,2u,3u,4u,6u,8u,11u,14u,17u,20u,24u,28u,32u,36u,41u,45u,50u,55u,60u,66u,71u,77u,82u };
const uint8 CYCODE SineWaveGen_wave2[SineWaveGen_WAVE2_LENGTH] = { 128u,132u,138u,143u,148u,152u,158u,162u,168u,172u,178u,182u,188u,192u,198u,202u,208u,213u,218u,222u,228u,232u,238u,242u,248u,252u,248u,242u,238u,232u,228u,222u,218u,212u,208u,202u,198u,192u,188u,182u,178u,173u,168u,162u,158u,152u,148u,143u,138u,132u,128u,122u,118u,112u,107u,102u,97u,93u,88u,83u,78u,73u,68u,62u,57u,52u,47u,42u,37u,33u,28u,23u,18u,13u,8u,3u,8u,13u,18u,23u,28u,33u,37u,42u,47u,52u,57u,62u,68u,73u,78u,83u,88u,93u,97u,102u,107u,112u,118u,122u };

static uint8  SineWaveGen_Wave1Chan;
static uint8  SineWaveGen_Wave2Chan;
static uint8  SineWaveGen_Wave1TD;
static uint8  SineWaveGen_Wave2TD;


/*******************************************************************************
* Function Name: SineWaveGen_Init
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
void SineWaveGen_Init(void) 
{
	SineWaveGen_VDAC8_Init();
	SineWaveGen_VDAC8_SetSpeed(SineWaveGen_HIGHSPEED);
	SineWaveGen_VDAC8_SetRange(SineWaveGen_DAC_RANGE);

	#if(SineWaveGen_DAC_MODE == SineWaveGen_CURRENT_MODE)
		SineWaveGen_IDAC8_SetPolarity(SineWaveGen_DAC_POL);
	#endif /* SineWaveGen_DAC_MODE == SineWaveGen_CURRENT_MODE */

	#if(SineWaveGen_OUT_MODE == SineWaveGen_BUFFER_MODE)
	   SineWaveGen_BuffAmp_Init();
	#endif /* SineWaveGen_OUT_MODE == SineWaveGen_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	SineWaveGen_Wave1TD = CyDmaTdAllocate();
	SineWaveGen_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	SineWaveGen_Wave1Setup(SineWaveGen_wave1, SineWaveGen_WAVE1_LENGTH) ;
	SineWaveGen_Wave2Setup(SineWaveGen_wave2, SineWaveGen_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(SineWaveGen_DacClk_PHASE)
	   SineWaveGen_DacClk_SetPhase(SineWaveGen_CLK_PHASE_0nS);
	#endif /* defined(SineWaveGen_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: SineWaveGen_Enable
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
void SineWaveGen_Enable(void) 
{
	SineWaveGen_VDAC8_Enable();

	#if(SineWaveGen_OUT_MODE == SineWaveGen_BUFFER_MODE)
	   SineWaveGen_BuffAmp_Enable();
	#endif /* SineWaveGen_OUT_MODE == SineWaveGen_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(SineWaveGen_Wave1Chan, 1u);
	(void)CyDmaChEnable(SineWaveGen_Wave2Chan, 1u);
	
	/* set the initial value */
	SineWaveGen_SetValue(0u);
	
	#if(SineWaveGen_CLOCK_SRC == SineWaveGen_CLOCK_INT)  	
	   SineWaveGen_DacClk_Start();
	#endif /* SineWaveGen_CLOCK_SRC == SineWaveGen_CLOCK_INT */
}


/*******************************************************************************
* Function Name: SineWaveGen_Start
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
void SineWaveGen_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(SineWaveGen_initVar == 0u)
	{
		SineWaveGen_Init();
		SineWaveGen_initVar = 1u;
	}
	
	SineWaveGen_Enable();
}


/*******************************************************************************
* Function Name: SineWaveGen_StartEx
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
void SineWaveGen_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	SineWaveGen_Wave1Setup(wavePtr1, sampleSize1);
	SineWaveGen_Wave2Setup(wavePtr2, sampleSize2);
	SineWaveGen_Start();
}


/*******************************************************************************
* Function Name: SineWaveGen_Stop
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
void SineWaveGen_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(SineWaveGen_CLOCK_SRC == SineWaveGen_CLOCK_INT)  	
	   SineWaveGen_DacClk_Stop();
	#endif /* SineWaveGen_CLOCK_SRC == SineWaveGen_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(SineWaveGen_Wave1Chan);
	(void)CyDmaChDisable(SineWaveGen_Wave2Chan);

	/* Disable power to DAC */
	SineWaveGen_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: SineWaveGen_Wave1Setup
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
void SineWaveGen_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (SineWaveGen_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		SineWaveGen_Wave1Chan = SineWaveGen_Wave1_DMA_DmaInitialize(
		SineWaveGen_Wave1_DMA_BYTES_PER_BURST, SineWaveGen_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		SineWaveGen_Wave1Chan = SineWaveGen_Wave1_DMA_DmaInitialize(
		SineWaveGen_Wave1_DMA_BYTES_PER_BURST, SineWaveGen_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(SineWaveGen_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(SineWaveGen_Wave1TD, sampleSize, SineWaveGen_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)SineWaveGen_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(SineWaveGen_Wave1TD, LO16((uint32)wavePtr), LO16(SineWaveGen_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(SineWaveGen_Wave1Chan, SineWaveGen_Wave1TD);
}


/*******************************************************************************
* Function Name: SineWaveGen_Wave2Setup
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
void SineWaveGen_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (SineWaveGen_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		SineWaveGen_Wave2Chan = SineWaveGen_Wave2_DMA_DmaInitialize(
		SineWaveGen_Wave2_DMA_BYTES_PER_BURST, SineWaveGen_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		SineWaveGen_Wave2Chan = SineWaveGen_Wave2_DMA_DmaInitialize(
		SineWaveGen_Wave2_DMA_BYTES_PER_BURST, SineWaveGen_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(SineWaveGen_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(SineWaveGen_Wave2TD, sampleSize, SineWaveGen_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)SineWaveGen_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(SineWaveGen_Wave2TD, LO16((uint32)wavePtr), LO16(SineWaveGen_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(SineWaveGen_Wave2Chan, SineWaveGen_Wave2TD);
}


/* [] END OF FILE */
