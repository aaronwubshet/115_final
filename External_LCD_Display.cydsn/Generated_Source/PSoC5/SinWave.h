/*******************************************************************************
* File Name: SinWave.h  
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

#if !defined(CY_WaveDAC8_SinWave_H) 
#define CY_WaveDAC8_SinWave_H

#include "cytypes.h"
#include "cyfitter.h"
#include <SinWave_Wave1_DMA_dma.h>
#include <SinWave_Wave2_DMA_dma.h>
#include <SinWave_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define SinWave_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define SinWave_WAVE2_TYPE     (2u)     /* Waveform for wave2 */
#define SinWave_SINE_WAVE      (0u)
#define SinWave_SQUARE_WAVE    (1u)
#define SinWave_TRIANGLE_WAVE  (2u)
#define SinWave_SAWTOOTH_WAVE  (3u)
#define SinWave_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define SinWave_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define SinWave_WAVE1_LENGTH   (25u)   /* Length for wave1 */
#define SinWave_WAVE2_LENGTH   (100u)   /* Length for wave2 */
	
#define SinWave_DEFAULT_RANGE    (17u) /* Default DAC range */
#define SinWave_DAC_RANGE_1V     (0u)
#define SinWave_DAC_RANGE_1V_BUF (16u)
#define SinWave_DAC_RANGE_4V     (1u)
#define SinWave_DAC_RANGE_4V_BUF (17u)
#define SinWave_VOLT_MODE        (0u)
#define SinWave_CURRENT_MODE     (1u)
#define SinWave_DAC_MODE         (((SinWave_DEFAULT_RANGE == SinWave_DAC_RANGE_1V) || \
									  (SinWave_DEFAULT_RANGE == SinWave_DAC_RANGE_4V) || \
							  		  (SinWave_DEFAULT_RANGE == SinWave_DAC_RANGE_1V_BUF) || \
									  (SinWave_DEFAULT_RANGE == SinWave_DAC_RANGE_4V_BUF)) ? \
									   SinWave_VOLT_MODE : SinWave_CURRENT_MODE)

#define SinWave_DACMODE SinWave_DAC_MODE /* legacy definition for backward compatibility */

#define SinWave_DIRECT_MODE (0u)
#define SinWave_BUFFER_MODE (1u)
#define SinWave_OUT_MODE    (((SinWave_DEFAULT_RANGE == SinWave_DAC_RANGE_1V_BUF) || \
								 (SinWave_DEFAULT_RANGE == SinWave_DAC_RANGE_4V_BUF)) ? \
								  SinWave_BUFFER_MODE : SinWave_DIRECT_MODE)

#if(SinWave_OUT_MODE == SinWave_BUFFER_MODE)
    #include <SinWave_BuffAmp.h>
#endif /* SinWave_OUT_MODE == SinWave_BUFFER_MODE */

#define SinWave_CLOCK_INT      (1u)
#define SinWave_CLOCK_EXT      (0u)
#define SinWave_CLOCK_SRC      (0u)

#if(SinWave_CLOCK_SRC == SinWave_CLOCK_INT)  
	#include <SinWave_DacClk.h>
	#if defined(SinWave_DacClk_PHASE)
		#define SinWave_CLK_PHASE_0nS (1u)
	#endif /* defined(SinWave_DacClk_PHASE) */
#endif /* SinWave_CLOCK_SRC == SinWave_CLOCK_INT */

#if (CY_PSOC3)
	#define SinWave_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define SinWave_Wave1_DMA_BYTES_PER_BURST      (1u)
#define SinWave_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define SinWave_Wave2_DMA_BYTES_PER_BURST      (1u)
#define SinWave_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}SinWave_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void SinWave_Start(void)             ;
void SinWave_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void SinWave_Init(void)              ;
void SinWave_Enable(void)            ;
void SinWave_Stop(void)              ;

void SinWave_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void SinWave_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void SinWave_Sleep(void)             ;
void SinWave_Wakeup(void)            ;

#define SinWave_SetSpeed       SinWave_VDAC8_SetSpeed
#define SinWave_SetRange       SinWave_VDAC8_SetRange
#define SinWave_SetValue       SinWave_VDAC8_SetValue
#define SinWave_DacTrim        SinWave_VDAC8_DacTrim
#define SinWave_SaveConfig     SinWave_VDAC8_SaveConfig
#define SinWave_RestoreConfig  SinWave_VDAC8_RestoreConfig


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 SinWave_initVar;

extern const uint8 CYCODE SinWave_wave1[SinWave_WAVE1_LENGTH];
extern const uint8 CYCODE SinWave_wave2[SinWave_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(SinWave_DAC_MODE == SinWave_VOLT_MODE)
    #define SinWave_RANGE_1V       (0x00u)
    #define SinWave_RANGE_4V       (0x04u)
#else /* current mode */
    #define SinWave_RANGE_32uA     (0x00u)
    #define SinWave_RANGE_255uA    (0x04u)
    #define SinWave_RANGE_2mA      (0x08u)
    #define SinWave_RANGE_2048uA   SinWave_RANGE_2mA
#endif /* SinWave_DAC_MODE == SinWave_VOLT_MODE */

/* Power setting for SetSpeed API */
#define SinWave_LOWSPEED       (0x00u)
#define SinWave_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define SinWave_DAC8__D SinWave_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define SinWave_HS_MASK        (0x02u)
#define SinWave_HS_LOWPOWER    (0x00u)
#define SinWave_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define SinWave_MODE_MASK      (0x10u)
#define SinWave_MODE_V         (0x00u)
#define SinWave_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define SinWave_RANGE_MASK     (0x0Cu)
#define SinWave_RANGE_0        (0x00u)
#define SinWave_RANGE_1        (0x04u)
#define SinWave_RANGE_2        (0x08u)
#define SinWave_RANGE_3        (0x0Cu)
#define SinWave_IDIR_MASK      (0x04u)

#define SinWave_DAC_RANGE      ((uint8)(17u << 2u) & SinWave_RANGE_MASK)
#define SinWave_DAC_POL        ((uint8)(17u >> 1u) & SinWave_IDIR_MASK)


#endif /* CY_WaveDAC8_SinWave_H  */

/* [] END OF FILE */
