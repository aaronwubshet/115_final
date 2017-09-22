/*******************************************************************************
* File Name: SineWaveGen.h  
* Version 2.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the 8-bit Waveform DAC (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_WaveDAC8_SineWaveGen_H) 
#define CY_WaveDAC8_SineWaveGen_H

#include "cytypes.h"
#include "cyfitter.h"
#include <SineWaveGen_Wave1_DMA_dma.h>
#include <SineWaveGen_Wave2_DMA_dma.h>
#include <SineWaveGen_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define SineWaveGen_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define SineWaveGen_WAVE2_TYPE     (2u)     /* Waveform for wave2 */
#define SineWaveGen_SINE_WAVE      (0u)
#define SineWaveGen_SQUARE_WAVE    (1u)
#define SineWaveGen_TRIANGLE_WAVE  (2u)
#define SineWaveGen_SAWTOOTH_WAVE  (3u)
#define SineWaveGen_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define SineWaveGen_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define SineWaveGen_WAVE1_LENGTH   (100u)   /* Length for wave1 */
#define SineWaveGen_WAVE2_LENGTH   (100u)   /* Length for wave2 */
	
#define SineWaveGen_DEFAULT_RANGE    (16u) /* Default DAC range */
#define SineWaveGen_DAC_RANGE_1V     (0u)
#define SineWaveGen_DAC_RANGE_1V_BUF (16u)
#define SineWaveGen_DAC_RANGE_4V     (1u)
#define SineWaveGen_DAC_RANGE_4V_BUF (17u)
#define SineWaveGen_VOLT_MODE        (0u)
#define SineWaveGen_CURRENT_MODE     (1u)
#define SineWaveGen_DAC_MODE         (((SineWaveGen_DEFAULT_RANGE == SineWaveGen_DAC_RANGE_1V) || \
									  (SineWaveGen_DEFAULT_RANGE == SineWaveGen_DAC_RANGE_4V) || \
							  		  (SineWaveGen_DEFAULT_RANGE == SineWaveGen_DAC_RANGE_1V_BUF) || \
									  (SineWaveGen_DEFAULT_RANGE == SineWaveGen_DAC_RANGE_4V_BUF)) ? \
									   SineWaveGen_VOLT_MODE : SineWaveGen_CURRENT_MODE)

#define SineWaveGen_DACMODE SineWaveGen_DAC_MODE /* legacy definition for backward compatibility */

#define SineWaveGen_DIRECT_MODE (0u)
#define SineWaveGen_BUFFER_MODE (1u)
#define SineWaveGen_OUT_MODE    (((SineWaveGen_DEFAULT_RANGE == SineWaveGen_DAC_RANGE_1V_BUF) || \
								 (SineWaveGen_DEFAULT_RANGE == SineWaveGen_DAC_RANGE_4V_BUF)) ? \
								  SineWaveGen_BUFFER_MODE : SineWaveGen_DIRECT_MODE)

#if(SineWaveGen_OUT_MODE == SineWaveGen_BUFFER_MODE)
    #include <SineWaveGen_BuffAmp.h>
#endif /* SineWaveGen_OUT_MODE == SineWaveGen_BUFFER_MODE */

#define SineWaveGen_CLOCK_INT      (1u)
#define SineWaveGen_CLOCK_EXT      (0u)
#define SineWaveGen_CLOCK_SRC      (0u)

#if(SineWaveGen_CLOCK_SRC == SineWaveGen_CLOCK_INT)  
	#include <SineWaveGen_DacClk.h>
	#if defined(SineWaveGen_DacClk_PHASE)
		#define SineWaveGen_CLK_PHASE_0nS (1u)
	#endif /* defined(SineWaveGen_DacClk_PHASE) */
#endif /* SineWaveGen_CLOCK_SRC == SineWaveGen_CLOCK_INT */

#if (CY_PSOC3)
	#define SineWaveGen_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define SineWaveGen_Wave1_DMA_BYTES_PER_BURST      (1u)
#define SineWaveGen_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define SineWaveGen_Wave2_DMA_BYTES_PER_BURST      (1u)
#define SineWaveGen_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}SineWaveGen_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void SineWaveGen_Start(void)             ;
void SineWaveGen_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void SineWaveGen_Init(void)              ;
void SineWaveGen_Enable(void)            ;
void SineWaveGen_Stop(void)              ;

void SineWaveGen_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void SineWaveGen_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void SineWaveGen_Sleep(void)             ;
void SineWaveGen_Wakeup(void)            ;

#define SineWaveGen_SetSpeed       SineWaveGen_VDAC8_SetSpeed
#define SineWaveGen_SetRange       SineWaveGen_VDAC8_SetRange
#define SineWaveGen_SetValue       SineWaveGen_VDAC8_SetValue
#define SineWaveGen_DacTrim        SineWaveGen_VDAC8_DacTrim
#define SineWaveGen_SaveConfig     SineWaveGen_VDAC8_SaveConfig
#define SineWaveGen_RestoreConfig  SineWaveGen_VDAC8_RestoreConfig


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 SineWaveGen_initVar;

extern const uint8 CYCODE SineWaveGen_wave1[SineWaveGen_WAVE1_LENGTH];
extern const uint8 CYCODE SineWaveGen_wave2[SineWaveGen_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(SineWaveGen_DAC_MODE == SineWaveGen_VOLT_MODE)
    #define SineWaveGen_RANGE_1V       (0x00u)
    #define SineWaveGen_RANGE_4V       (0x04u)
#else /* current mode */
    #define SineWaveGen_RANGE_32uA     (0x00u)
    #define SineWaveGen_RANGE_255uA    (0x04u)
    #define SineWaveGen_RANGE_2mA      (0x08u)
    #define SineWaveGen_RANGE_2048uA   SineWaveGen_RANGE_2mA
#endif /* SineWaveGen_DAC_MODE == SineWaveGen_VOLT_MODE */

/* Power setting for SetSpeed API */
#define SineWaveGen_LOWSPEED       (0x00u)
#define SineWaveGen_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define SineWaveGen_DAC8__D SineWaveGen_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define SineWaveGen_HS_MASK        (0x02u)
#define SineWaveGen_HS_LOWPOWER    (0x00u)
#define SineWaveGen_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define SineWaveGen_MODE_MASK      (0x10u)
#define SineWaveGen_MODE_V         (0x00u)
#define SineWaveGen_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define SineWaveGen_RANGE_MASK     (0x0Cu)
#define SineWaveGen_RANGE_0        (0x00u)
#define SineWaveGen_RANGE_1        (0x04u)
#define SineWaveGen_RANGE_2        (0x08u)
#define SineWaveGen_RANGE_3        (0x0Cu)
#define SineWaveGen_IDIR_MASK      (0x04u)

#define SineWaveGen_DAC_RANGE      ((uint8)(16u << 2u) & SineWaveGen_RANGE_MASK)
#define SineWaveGen_DAC_POL        ((uint8)(16u >> 1u) & SineWaveGen_IDIR_MASK)


#endif /* CY_WaveDAC8_SineWaveGen_H  */

/* [] END OF FILE */
