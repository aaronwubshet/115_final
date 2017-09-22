/*******************************************************************************
* File Name: SensorScan.c
* Version 1.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Scanning Comparator Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ScanComp_SensorScan_H)
#define CY_ScanComp_SensorScan_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyLib.h"
#include "SensorScan_Comp.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

/* Channel mode type */
#define SensorScan_CHANNEL_MODE_COMMON    (0u)
#define SensorScan_CHANNEL_MODE_UNIQUE    (1u)
#define SensorScan_CHANNEL_MODE_INTERN    (2u)

#define SensorScan_INTERNAL_REF_USED      (0u)

#define SensorScan_INTERNAL_REF_IS_USED   ((CY_PSOC3 || CY_PSOC5) &&  \
        (SensorScan_INTERNAL_REF_USED == SensorScan_CHANNEL_MODE_INTERN))

#if (SensorScan_INTERNAL_REF_IS_USED)
    #define SensorScan_VDAC_PER_CHANNEL_MODE_USED  (0u)
#endif /* SensorScan_INTERNAL_REF_IS_USED */

#if (SensorScan_INTERNAL_REF_IS_USED)
    #include "SensorScan_VDAC.h"

    #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
        #include "CyDmac.h"
        #include "SensorScan_DMA_dma.h"
    #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */

    #define SensorScan_DEFAULT_VOLTAGE        (125u)
    #define SensorScan_DEFAULT_RANGE          (4u)
#endif /* SensorScan_INTERNAL_REF_IS_USED */


/*******************************************************************************
*   Data Struct Definitions
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} SensorScan_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void SensorScan_Start(void) ;
void SensorScan_Init(void) ;
void SensorScan_Enable(void) ;
void SensorScan_Stop(void) ;
void SensorScan_SetSpeed(uint8 speed) ;
uint8 SensorScan_GetCompare(uint8 channel) ;
uint8 SensorScan_GetInterruptSource(uint8 inputBlock)         \
                                          ;
uint8 SensorScan_GetInterruptSourceMasked(uint8 inputBlock)   \
                                                ;
uint8 SensorScan_GetInterruptMask(uint8 inputBlock)           \
                                        ;
void SensorScan_SetInterruptMask(uint8 inputBlock, uint8 mask)\
                                       ;
void SensorScan_Sleep(void) ;
void SensorScan_Wakeup(void) ;

#if (SensorScan_INTERNAL_REF_IS_USED)
    void SensorScan_SetDACRange(uint8 DACRange) ;
    uint8 SensorScan_GetDACRange(void) ;

    #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
        void SensorScan_SetChannelDACVoltage(uint8 channel, uint8 DACVoltage) \
                                                   ;
        uint8 SensorScan_GetChannelDACVoltage(uint8 channel)  \
                                                    ;
    #else
        void SensorScan_SetDACVoltage(uint8 DACVoltage) ;
        uint8 SensorScan_GetDACVoltage(void) ;
    #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
#endif /* SensorScan_INTERNAL_REF_IS_USED */


/*******************************************************************************
* Variable with external linkage
*******************************************************************************/

extern uint8  SensorScan_initVar;


/***************************************
*           API Constants
***************************************/

#if (SensorScan_INTERNAL_REF_IS_USED)
    #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
        /* DMA Configuration for DMA */
        #define SensorScan_DMA_BYTES_PER_BURST    (1u)
        #define SensorScan_DMA_REQUEST_PER_BURST  (1u)
        #define SensorScan_DMA_SRC_BASE (CYDEV_SRAM_BASE)
        #define SensorScan_DMA_DST_BASE (CYDEV_PERIPH_BASE)
    #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
#endif /* SensorScan_INTERNAL_REF_IS_USED */

/* Shift */
#define SensorScan_7BIT_SHIFT                 (0x07u)

/* Registers array defines */
#define SensorScan_NUM_OF_REGISTERS           ((SensorScan_DEFAULT_CHANNELS_VAL >> 3u) + 1u)

#define SensorScan_NUM_OF_OUT_REGISTERS       (SensorScan_NUM_OF_REGISTERS)

#define SensorScan_NUM_OF_INT_REGISTERS       (SensorScan_NUM_OF_REGISTERS)

/* Num of possible channels */
#define SensorScan_NUM_OF_POSSIBLE_CHAN       ((uint8)(SensorScan_NUM_OF_REGISTERS << 3u))

/* MSB register bit shift */
#define SensorScan_LSB_REG_BIT_SHIFT          (0xFFu >>    \
                                                    (SensorScan_NUM_OF_POSSIBLE_CHAN - \
                                                     SensorScan_NUM_OF_CHANNELS))

#define SensorScan_MSB_REG_CHAN_EXIST         (SensorScan_LSB_REG_BIT_SHIFT >> 7u)

/* MSB-bit of the register in high */
#define SensorScan_MSB_REG_BIT_HIGH           (0x80u)


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* VDAC Range constants */
#if (SensorScan_INTERNAL_REF_IS_USED)
    #define SensorScan_SCANCOMP_DACRANGE_1V   (SensorScan_VDAC_RANGE_1V)
    #define SensorScan_SCANCOMP_DACRANGE_4V   (SensorScan_VDAC_RANGE_4V)
#endif /* SensorScan_INTERNAL_REF_IS_USED */

/* Constants for SetSpeed() function */
#if (CY_PSOC4)
    #define SensorScan_SLOWSPEED   (SensorScan_Comp_SLOWSPEED)
    #define SensorScan_MEDSPEED    (SensorScan_Comp_MEDSPEED)
    #define SensorScan_HIGHSPEED   (SensorScan_Comp_HIGHSPEED)
#else
    #define SensorScan_SLOWSPEED   (SensorScan_Comp_LOWPOWER)
    #define SensorScan_MEDSPEED    (SensorScan_Comp_SLOWSPEED)
    #define SensorScan_HIGHSPEED   (SensorScan_Comp_HIGHSPEED)
#endif /* CY_PSOC4 */


/***************************************
*   Initial Parameter Constants
***************************************/
#define SensorScan_NUM_OF_CHANNELS                (5u)
#define SensorScan_DEFAULT_CHANNELS_VAL           (5u - 1u)
#define SensorScan_DEFAULT_SPEED                  (2u)


/***************************************
*             Registers
***************************************/

/* Status Registers */
#define SensorScan_STATUS_INT0_REG                (* (reg8 *) SensorScan_bScanComp_St0_IntReg0__STATUS_REG)
#define SensorScan_STATUS_INT0_PTR                (  (reg8 *) SensorScan_bScanComp_St0_IntReg0__STATUS_REG)
#define SensorScan_STATUS_INT0_MASK               (* (reg8 *) SensorScan_bScanComp_St0_IntReg0__MASK_REG)
#define SensorScan_STATUS_INT0_MASK_PTR           (  (reg8 *) SensorScan_bScanComp_St0_IntReg0__MASK_REG)
#define SensorScan_STATUS_INT0_AUX_CONTROL        (* (reg8 *) \
                                                        SensorScan_bScanComp_St0_IntReg0__STATUS_AUX_CTL_REG)

#define SensorScan_STATUS_OUT0_REG                (* (reg8 *) SensorScan_bScanComp_St0_OutReg0__STATUS_REG)
#define SensorScan_STATUS_OUT0_PTR                (  (reg8 *) SensorScan_bScanComp_St0_OutReg0__STATUS_REG)
#define SensorScan_STATUS_OUT0_MASK               (* (reg8 *) SensorScan_bScanComp_St0_OutReg0__MASK_REG)
#define SensorScan_STATUS_OUT0_AUX_CONTROL        (* (reg8 *) \
                                                        SensorScan_bScanComp_St0_OutReg0__STATUS_AUX_CTL_REG)

#if (SensorScan_NUM_OF_CHANNELS >= 8u)
    #define SensorScan_STATUS_INT8_REG            (* (reg8 *) SensorScan_bScanComp_St8_IntReg8__STATUS_REG)
    #define SensorScan_STATUS_INT8_PTR            (  (reg8 *) SensorScan_bScanComp_St8_IntReg8__STATUS_REG)
    #define SensorScan_STATUS_INT8_MASK           (* (reg8 *) SensorScan_bScanComp_St8_IntReg8__MASK_REG)
    #define SensorScan_STATUS_INT8_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St8_IntReg8__MASK_REG)
    #define SensorScan_STATUS_INT8_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St8_IntReg8__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS >= 8u */

#if (SensorScan_NUM_OF_CHANNELS > 8u)
    #define SensorScan_STATUS_INT1_REG            (* (reg8 *) SensorScan_bScanComp_St1_IntReg1__STATUS_REG)
    #define SensorScan_STATUS_INT1_PTR            (  (reg8 *) SensorScan_bScanComp_St1_IntReg1__STATUS_REG)
    #define SensorScan_STATUS_INT1_MASK           (* (reg8 *) SensorScan_bScanComp_St1_IntReg1__MASK_REG)
    #define SensorScan_STATUS_INT1_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St1_IntReg1__MASK_REG)
    #define SensorScan_STATUS_INT1_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St1_IntReg1__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT1_REG            (* (reg8 *) SensorScan_bScanComp_St1_OutReg1__STATUS_REG)
    #define SensorScan_STATUS_OUT1_PTR            (  (reg8 *) SensorScan_bScanComp_St1_OutReg1__STATUS_REG)
    #define SensorScan_STATUS_OUT1_MASK           (* (reg8 *) SensorScan_bScanComp_St1_OutReg1__MASK_REG)
    #define SensorScan_STATUS_OUT1_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St1_OutReg1__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 8u */

#if (SensorScan_NUM_OF_CHANNELS > 16u)
    #define SensorScan_STATUS_INT2_REG            (* (reg8 *) SensorScan_bScanComp_St2_IntReg2__STATUS_REG)
    #define SensorScan_STATUS_INT2_PTR            (  (reg8 *) SensorScan_bScanComp_St2_IntReg2__STATUS_REG)
    #define SensorScan_STATUS_INT2_MASK           (* (reg8 *) SensorScan_bScanComp_St2_IntReg2__MASK_REG)
    #define SensorScan_STATUS_INT2_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St2_IntReg2__MASK_REG)
    #define SensorScan_STATUS_INT2_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St2_IntReg2__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT2_REG            (* (reg8 *) SensorScan_bScanComp_St2_OutReg2__STATUS_REG)
    #define SensorScan_STATUS_OUT2_PTR            (  (reg8 *) SensorScan_bScanComp_St2_OutReg2__STATUS_REG)
    #define SensorScan_STATUS_OUT2_MASK           (* (reg8 *) SensorScan_bScanComp_St2_OutReg2__MASK_REG)
    #define SensorScan_STATUS_OUT2_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St2_OutReg2__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 16u */

#if (SensorScan_NUM_OF_CHANNELS > 24u)
    #define SensorScan_STATUS_INT3_REG            (* (reg8 *) SensorScan_bScanComp_St3_IntReg3__STATUS_REG)
    #define SensorScan_STATUS_INT3_PTR            (  (reg8 *) SensorScan_bScanComp_St3_IntReg3__STATUS_REG)
    #define SensorScan_STATUS_INT3_MASK           (* (reg8 *) SensorScan_bScanComp_St3_IntReg3__MASK_REG)
    #define SensorScan_STATUS_INT3_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St3_IntReg3__MASK_REG)
    #define SensorScan_STATUS_INT3_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St3_IntReg3__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT3_REG            (* (reg8 *) SensorScan_bScanComp_St3_OutReg3__STATUS_REG)
    #define SensorScan_STATUS_OUT3_PTR            (  (reg8 *) SensorScan_bScanComp_St3_OutReg3__STATUS_REG)
    #define SensorScan_STATUS_OUT3_MASK           (* (reg8 *) SensorScan_bScanComp_St3_OutReg3__MASK_REG)
    #define SensorScan_STATUS_OUT3_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St3_OutReg3__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 24u */

#if (SensorScan_NUM_OF_CHANNELS > 32u)
    #define SensorScan_STATUS_INT4_REG            (* (reg8 *) SensorScan_bScanComp_St4_IntReg4__STATUS_REG)
    #define SensorScan_STATUS_INT4_PTR            (  (reg8 *) SensorScan_bScanComp_St4_IntReg4__STATUS_REG)
    #define SensorScan_STATUS_INT4_MASK           (* (reg8 *) SensorScan_bScanComp_St4_IntReg4__MASK_REG)
    #define SensorScan_STATUS_INT4_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St4_IntReg4__MASK_REG)
    #define SensorScan_STATUS_INT4_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St4_IntReg4__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT4_REG            (* (reg8 *) SensorScan_bScanComp_St4_OutReg4__STATUS_REG)
    #define SensorScan_STATUS_OUT4_PTR            (  (reg8 *) SensorScan_bScanComp_St4_OutReg4__STATUS_REG)
    #define SensorScan_STATUS_OUT4_MASK           (* (reg8 *) SensorScan_bScanComp_St4_OutReg4__MASK_REG)
    #define SensorScan_STATUS_OUT4_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St4_OutReg4__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 32u */

#if (SensorScan_NUM_OF_CHANNELS > 40u)
    #define SensorScan_STATUS_INT5_REG            (* (reg8 *) SensorScan_bScanComp_St5_IntReg5__STATUS_REG)
    #define SensorScan_STATUS_INT5_PTR            (  (reg8 *) SensorScan_bScanComp_St5_IntReg5__STATUS_REG)
    #define SensorScan_STATUS_INT5_MASK           (* (reg8 *) SensorScan_bScanComp_St5_IntReg5__MASK_REG)
    #define SensorScan_STATUS_INT5_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St5_IntReg5__MASK_REG)
    #define SensorScan_STATUS_INT5_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St5_IntReg5__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT5_REG            (* (reg8 *) SensorScan_bScanComp_St5_OutReg5__STATUS_REG)
    #define SensorScan_STATUS_OUT5_PTR            (  (reg8 *) SensorScan_bScanComp_St5_OutReg5__STATUS_REG)
    #define SensorScan_STATUS_OUT5_MASK           (* (reg8 *) SensorScan_bScanComp_St5_OutReg5__MASK_REG)
    #define SensorScan_STATUS_OUT5_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St5_OutReg5__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 40u */

#if (SensorScan_NUM_OF_CHANNELS > 48u)
    #define SensorScan_STATUS_INT6_REG            (* (reg8 *) SensorScan_bScanComp_St6_IntReg6__STATUS_REG)
    #define SensorScan_STATUS_INT6_PTR            (  (reg8 *) SensorScan_bScanComp_St6_IntReg6__STATUS_REG)
    #define SensorScan_STATUS_INT6_MASK           (* (reg8 *) SensorScan_bScanComp_St6_IntReg6__MASK_REG)
    #define SensorScan_STATUS_INT6_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St6_IntReg6__MASK_REG)
    #define SensorScan_STATUS_INT6_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St6_IntReg6__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT6_REG            (* (reg8 *) SensorScan_bScanComp_St6_OutReg6__STATUS_REG)
    #define SensorScan_STATUS_OUT6_PTR            (  (reg8 *) SensorScan_bScanComp_St6_OutReg6__STATUS_REG)
    #define SensorScan_STATUS_OUT6_MASK           (* (reg8 *) SensorScan_bScanComp_St6_OutReg6__MASK_REG)
    #define SensorScan_STATUS_OUT6_AUX_CONTROL    (* (reg8 *) \
                                                         SensorScan_bScanComp_St6_OutReg6__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 48u */

#if (SensorScan_NUM_OF_CHANNELS > 56u)
    #define SensorScan_STATUS_INT7_REG            (* (reg8 *) SensorScan_bScanComp_St7_IntReg7__STATUS_REG)
    #define SensorScan_STATUS_INT7_PTR            (  (reg8 *) SensorScan_bScanComp_St7_IntReg7__STATUS_REG)
    #define SensorScan_STATUS_INT7_MASK           (* (reg8 *) SensorScan_bScanComp_St7_IntReg7__MASK_REG)
    #define SensorScan_STATUS_INT7_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St7_IntReg7__MASK_REG)
    #define SensorScan_STATUS_INT7_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St7_IntReg7__STATUS_AUX_CTL_REG)

    #define SensorScan_STATUS_OUT7_REG            (* (reg8 *) SensorScan_bScanComp_St7_OutReg7__STATUS_REG)
    #define SensorScan_STATUS_OUT7_PTR            (  (reg8 *) SensorScan_bScanComp_St7_OutReg7__STATUS_REG)
    #define SensorScan_STATUS_OUT7_MASK           (* (reg8 *) SensorScan_bScanComp_St7_OutReg7__MASK_REG)
    #define SensorScan_STATUS_OUT7_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St7_OutReg7__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 56u */

#if (SensorScan_NUM_OF_CHANNELS > 63u)
    #define SensorScan_STATUS_INT9_REG            (* (reg8 *) SensorScan_bScanComp_St9_IntReg9__STATUS_REG)
    #define SensorScan_STATUS_INT9_PTR            (  (reg8 *) SensorScan_bScanComp_St9_IntReg9__STATUS_REG)
    #define SensorScan_STATUS_INT9_MASK           (* (reg8 *) SensorScan_bScanComp_St9_IntReg9__MASK_REG)
    #define SensorScan_STATUS_INT9_MASK_PTR       (  (reg8 *) SensorScan_bScanComp_St9_IntReg9__MASK_REG)
    #define SensorScan_STATUS_INT9_AUX_CONTROL    (* (reg8 *) \
                                                        SensorScan_bScanComp_St9_IntReg9__STATUS_AUX_CTL_REG)
#endif /* SensorScan_NUM_OF_CHANNELS > 63u */

/* Control register */
#define SensorScan_CONTROL_REG        (*(reg8 *) SensorScan_bScanComp_CtrlCnt__CONTROL_REG)
#define SensorScan_CONTROL_PTR        ( (reg8 *) SensorScan_bScanComp_CtrlCnt__CONTROL_REG)

/* Count 7 */
#define SensorScan_COUNTER_COUNT_REG          (*(reg8 *) SensorScan_bScanComp_ChannelCounter__COUNT_REG)
#define SensorScan_COUNTER_PERIOD_REG          (*(reg8 *) SensorScan_bScanComp_ChannelCounter__PERIOD_REG)
#define SensorScan_COUNTER_AUX_CONTROL_REG    (*(reg8 *) \
                                                    SensorScan_bScanComp_ChannelCounter__CONTROL_AUX_CTL_REG)
#define SensorScan_COUNTER_AUX_CONTROL_PTR    ( (reg8 *) \
                                                    SensorScan_bScanComp_ChannelCounter__CONTROL_AUX_CTL_REG)

/***************************************
*   Register Constants
***************************************/

#define SensorScan_COUNTER_ENABLE             (0x20u)
#define SensorScan_STATUS_INTR_ENBL           (0x10u)
#define SensorScan_CONTROL_ENABLE             (0x01u)
#define SensorScan_CONTROL_DISABLE            (0x00u)

/* Masks */
#define SensorScan_3BIT_MASK                  (0x07u)
#define SensorScan_7BIT_MASK                  (0x7Fu)
#define SensorScan_INT_REG_MASK               (0x7Fu)

/* INTR_MASK for each channel */
#if (SensorScan_NUM_OF_CHANNELS > 1u)
    #define SensorScan_INTR_MASK_0    (0x01u)
    #define SensorScan_INTR_MASK_1    (0x02u)
    #define SensorScan_INTR_MASK_2    (0x04u)
    #define SensorScan_INTR_MASK_3    (0x08u)
    #define SensorScan_INTR_MASK_4    (0x10u)
    #define SensorScan_INTR_MASK_5    (0x20u)
    #define SensorScan_INTR_MASK_6    (0x40u)
    #define SensorScan_INTR_MASK_7    (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS <= 8u */

#if (SensorScan_NUM_OF_CHANNELS > 8u)
    #define SensorScan_INTR_MASK_8    (0x01u)
    #define SensorScan_INTR_MASK_9    (0x02u)
    #define SensorScan_INTR_MASK_10   (0x04u)
    #define SensorScan_INTR_MASK_11   (0x08u)
    #define SensorScan_INTR_MASK_12   (0x10u)
    #define SensorScan_INTR_MASK_13   (0x20u)
    #define SensorScan_INTR_MASK_14   (0x40u)
    #define SensorScan_INTR_MASK_15   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 8u */

#if (SensorScan_NUM_OF_CHANNELS > 16u)
    #define SensorScan_INTR_MASK_16   (0x01u)
    #define SensorScan_INTR_MASK_17   (0x02u)
    #define SensorScan_INTR_MASK_18   (0x04u)
    #define SensorScan_INTR_MASK_19   (0x08u)
    #define SensorScan_INTR_MASK_20   (0x10u)
    #define SensorScan_INTR_MASK_21   (0x20u)
    #define SensorScan_INTR_MASK_22   (0x40u)
    #define SensorScan_INTR_MASK_23   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 16u */

#if (SensorScan_NUM_OF_CHANNELS > 24u)
    #define SensorScan_INTR_MASK_24   (0x01u)
    #define SensorScan_INTR_MASK_25   (0x02u)
    #define SensorScan_INTR_MASK_26   (0x04u)
    #define SensorScan_INTR_MASK_27   (0x08u)
    #define SensorScan_INTR_MASK_28   (0x10u)
    #define SensorScan_INTR_MASK_29   (0x20u)
    #define SensorScan_INTR_MASK_30   (0x40u)
    #define SensorScan_INTR_MASK_31   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 24u */

#if (SensorScan_NUM_OF_CHANNELS > 32u)
    #define SensorScan_INTR_MASK_32   (0x01u)
    #define SensorScan_INTR_MASK_33   (0x02u)
    #define SensorScan_INTR_MASK_34   (0x04u)
    #define SensorScan_INTR_MASK_35   (0x08u)
    #define SensorScan_INTR_MASK_36   (0x10u)
    #define SensorScan_INTR_MASK_37   (0x20u)
    #define SensorScan_INTR_MASK_38   (0x40u)
    #define SensorScan_INTR_MASK_39   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 32u */

#if (SensorScan_NUM_OF_CHANNELS > 40u)
    #define SensorScan_INTR_MASK_40   (0x01u)
    #define SensorScan_INTR_MASK_41   (0x02u)
    #define SensorScan_INTR_MASK_42   (0x04u)
    #define SensorScan_INTR_MASK_43   (0x08u)
    #define SensorScan_INTR_MASK_44   (0x10u)
    #define SensorScan_INTR_MASK_45   (0x20u)
    #define SensorScan_INTR_MASK_46   (0x40u)
    #define SensorScan_INTR_MASK_47   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 40u */

#if (SensorScan_NUM_OF_CHANNELS > 48u)
    #define SensorScan_INTR_MASK_48   (0x01u)
    #define SensorScan_INTR_MASK_49   (0x02u)
    #define SensorScan_INTR_MASK_50   (0x04u)
    #define SensorScan_INTR_MASK_51   (0x08u)
    #define SensorScan_INTR_MASK_52   (0x10u)
    #define SensorScan_INTR_MASK_53   (0x20u)
    #define SensorScan_INTR_MASK_54   (0x40u)
    #define SensorScan_INTR_MASK_55   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 48u */

#if (SensorScan_NUM_OF_CHANNELS > 56u)
    #define SensorScan_INTR_MASK_56   (0x01u)
    #define SensorScan_INTR_MASK_57   (0x02u)
    #define SensorScan_INTR_MASK_58   (0x04u)
    #define SensorScan_INTR_MASK_59   (0x08u)
    #define SensorScan_INTR_MASK_60   (0x10u)
    #define SensorScan_INTR_MASK_61   (0x20u)
    #define SensorScan_INTR_MASK_62   (0x40u)
    #define SensorScan_INTR_MASK_63   (0x80u)
#endif /* SensorScan_NUM_OF_CHANNELS > 56u */

#endif  /* CY_SCANCOMP_SensorScan_H */


/* [] END OF FILE */
