/*******************************************************************************
* File Name: SensorScan.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the Scanning Comparator
*  component
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

#include "SensorScan.h"

#if (SensorScan_INTERNAL_REF_IS_USED)

    static uint8  SensorScan_compDACRange;
    
    #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
        
        /* Variable declarations for DMA */
        static uint8 SensorScan_DMA_VDACUpdate_Chan;
        static uint8 SensorScan_DMA_VDACUpdate_TD = CY_DMA_INVALID_TD;
        
        static void SensorScan_InitDma(void)  ;

        /* Array from customizer */
        static uint8 SensorScan_DacVoltages[SensorScan_NUM_OF_CHANNELS] = {
    0x7Du, 0x7Du, 0x7Du, 0x7Du, 0x7Du, 
};

    #else
        static uint8  SensorScan_compDACVoltage;
    #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
#endif /* SensorScan_INTERNAL_REF_IS_USED */

#if (SensorScan_NUM_OF_CHANNELS >= 8u)
    static uint8 storeStatusReg;
#endif /* SensorScan_NUM_OF_CHANNELS >= 8u */

uint8  SensorScan_initVar = 0u;

static reg8 * const CYCODE interruptStatusMaskRegs[SensorScan_NUM_OF_INT_REGISTERS] =
{
    SensorScan_STATUS_INT0_MASK_PTR,

    #if(SensorScan_NUM_OF_CHANNELS > 8u)
        SensorScan_STATUS_INT1_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 8u */

    #if(SensorScan_NUM_OF_CHANNELS > 16u)
        SensorScan_STATUS_INT2_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 16u */

    #if(SensorScan_NUM_OF_CHANNELS > 24u)
        SensorScan_STATUS_INT3_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 24u */

    #if(SensorScan_NUM_OF_CHANNELS > 32u)
        SensorScan_STATUS_INT4_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 32u */

    #if(SensorScan_NUM_OF_CHANNELS > 40u)
        SensorScan_STATUS_INT5_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 40u */

    #if(SensorScan_NUM_OF_CHANNELS > 48u)
        SensorScan_STATUS_INT6_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 48u */

    #if(SensorScan_NUM_OF_CHANNELS > 56u)
        SensorScan_STATUS_INT7_MASK_PTR,
    #endif /* SensorScan_NUM_OF_CHANNELS > 56u */
};


/*******************************************************************************
* Function Name: SensorScan_Start
********************************************************************************
*
* Summary:
*  Performs all of the required initialization for the ScanComp component
*  and enables power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_Start(void) 
{
    if(0u == SensorScan_initVar)
    {
        SensorScan_Init();
        SensorScan_initVar = 1u;
    }
    SensorScan_Enable();
}


/*******************************************************************************
* Function Name: SensorScan_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the ScanComp component according to
*  the customizer settings.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_Init(void) 
{
    #if (SensorScan_NUM_OF_CHANNELS >= 8u)
        storeStatusReg = 0u;
    #endif /* SensorScan_NUM_OF_CHANNELS >= 8u */

    SensorScan_Comp_Init();    
    
    #if (SensorScan_INTERNAL_REF_IS_USED)
        SensorScan_VDAC_Init();
        SensorScan_compDACRange = SensorScan_DEFAULT_RANGE;

        #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
            SensorScan_VDAC_SetValue(0x0u);
            
            if(CY_DMA_INVALID_TD == SensorScan_DMA_VDACUpdate_TD)
            {
                SensorScan_InitDma();
            }            
        #else
            SensorScan_SetDACVoltage(SensorScan_DEFAULT_VOLTAGE);
        #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
    #endif /* SensorScan_INTERNAL_REF_IS_USED */
}


/*******************************************************************************
* Function Name: SensorScan_Stop
********************************************************************************
*
* Summary:
*  Turns off the Scanning Comparator by turning off the comparator itself and 
*  halting the muxing of inputs, and turning off the DAC if it is used.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_Stop(void) 
{
    SensorScan_CONTROL_REG = SensorScan_CONTROL_DISABLE;
    
    SensorScan_Comp_Stop();    
    
    #if (SensorScan_INTERNAL_REF_IS_USED)
        SensorScan_VDAC_Stop();

        #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)
            (void) CyDmaChDisable(SensorScan_DMA_VDACUpdate_Chan);
        #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
    #endif /* SensorScan_INTERNAL_REF_IS_USED */
}


/*******************************************************************************
* Function Name: SensorScan_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_Enable(void) 
{
    uint8 interruptState;

    SensorScan_Comp_Enable();
    
    SensorScan_COUNTER_COUNT_REG  = SensorScan_DEFAULT_CHANNELS_VAL;

    #if (SensorScan_INTERNAL_REF_IS_USED)
        SensorScan_VDAC_Enable();
        #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)        
            (void)CyDmaClearPendingDrq(SensorScan_DMA_VDACUpdate_Chan);
            (void)CyDmaChEnable(SensorScan_DMA_VDACUpdate_Chan, 1u);
        #endif /* (SensorScan_VDAC_PER_CHANNEL_MODE_USED) */    
    #endif /* SensorScan_INTERNAL_REF_IS_USED */    

    /* Enable Status Int */
    interruptState = CyEnterCriticalSection();

    #if (SensorScan_NUM_OF_CHANNELS < 8u)
        SensorScan_STATUS_INT0_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS < 8u */

    #if (SensorScan_NUM_OF_CHANNELS >= 8u)
        SensorScan_STATUS_INT8_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS >= 8u */

    #if (SensorScan_NUM_OF_CHANNELS >= 9u)
        SensorScan_STATUS_INT1_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS >= 9u */

    #if (SensorScan_NUM_OF_CHANNELS > 16u)
        SensorScan_STATUS_INT2_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS > 16u */

    #if (SensorScan_NUM_OF_CHANNELS > 24u)
        SensorScan_STATUS_INT3_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS > 24u */

    #if (SensorScan_NUM_OF_CHANNELS > 32u)
        SensorScan_STATUS_INT4_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS > 32u */

    #if (SensorScan_NUM_OF_CHANNELS > 40u)
        SensorScan_STATUS_INT5_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS > 40u */

    #if (SensorScan_NUM_OF_CHANNELS > 48u)
        SensorScan_STATUS_INT6_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS > 48u */

    #if (SensorScan_NUM_OF_CHANNELS > 56u)
        SensorScan_STATUS_INT7_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS > 56u */

    #if (SensorScan_NUM_OF_CHANNELS == 64)
        SensorScan_STATUS_INT9_AUX_CONTROL |= SensorScan_STATUS_INTR_ENBL;
    #endif /* SensorScan_NUM_OF_CHANNELS == 64u */

    SensorScan_COUNTER_AUX_CONTROL_REG |= SensorScan_COUNTER_ENABLE;

    CyExitCriticalSection(interruptState);

    SensorScan_CONTROL_REG = SensorScan_CONTROL_ENABLE ;
}


/*******************************************************************************
* Function Name: SensorScan_SetSpeed
********************************************************************************
*
* Summary:
*  Sets the drive power and speed to one of three settings.
*
* Parameters:
*  speed: enumerated speed mode value.
*   SensorScan_SLOWSPEED  - Slow speed / Ultra low power
*   SensorScan_MEDSPEED   - Medium speed / Medium power
*   SensorScan_HIGHSPEED  - High speed / High power
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_SetSpeed(uint8 speed) 
{
    #if (CY_PSOC4)
        SensorScan_Comp_SetSpeed((uint32)speed);
    #else
        SensorScan_Comp_SetSpeed(speed);
    #endif /* CY_PSOC4 */
}


/*******************************************************************************
* Function Name: SensorScan_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the pending interrupt requests from the selected block.
*  Even masked interrupts are returned.
*
* Parameters:
*  InputBlock: Specifies the block of 8 channels whose interrupt requests
*  should be returned.
*
* Return:
*  Bit field of interrupt sources from the selected block of 8 inputs.
*
*******************************************************************************/
uint8 SensorScan_GetInterruptSource(uint8 inputBlock) 
{
    uint8 intSrc = 0u;

    #if (SensorScan_NUM_OF_CHANNELS >= 8u)
        uint8 intMsb = 0u;
    #endif /* SensorScan_NUM_OF_CHANNELS >= 8u */

    static reg8 * const CYCODE interruptStatusRegs[SensorScan_NUM_OF_INT_REGISTERS] =
    {
        SensorScan_STATUS_INT0_PTR,

        #if(SensorScan_NUM_OF_CHANNELS > 8u)
            SensorScan_STATUS_INT1_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 8u */

        #if(SensorScan_NUM_OF_CHANNELS > 16u)
            SensorScan_STATUS_INT2_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 16u */

        #if(SensorScan_NUM_OF_CHANNELS > 24u)
            SensorScan_STATUS_INT3_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 24u */

        #if(SensorScan_NUM_OF_CHANNELS > 32u)
            SensorScan_STATUS_INT4_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 32u */

        #if(SensorScan_NUM_OF_CHANNELS > 40u)
            SensorScan_STATUS_INT5_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 40u */

        #if(SensorScan_NUM_OF_CHANNELS > 48u)
            SensorScan_STATUS_INT6_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 48u */

        #if(SensorScan_NUM_OF_CHANNELS > 56u)
            SensorScan_STATUS_INT7_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 56u */
    };    
    
    if (inputBlock < SensorScan_NUM_OF_INT_REGISTERS)
    {
        intSrc = ((uint8) (* interruptStatusRegs[inputBlock])) & SensorScan_INT_REG_MASK;
    }
    
    #if (SensorScan_NUM_OF_CHANNELS > 63u)
        if (inputBlock == 7u)
        {
            intMsb = (uint8)(SensorScan_STATUS_INT9_REG  << SensorScan_7BIT_SHIFT);
        }
        else
        {
            storeStatusReg |= SensorScan_STATUS_INT8_REG;
            intMsb = (uint8)((storeStatusReg >> inputBlock) << SensorScan_7BIT_SHIFT);
            storeStatusReg = (storeStatusReg & (uint8)(~(uint8)(1u << inputBlock)));
        }
        intSrc |= intMsb;
    #elif (SensorScan_NUM_OF_CHANNELS >= 8u)
        if (inputBlock != 7u)
        {
            storeStatusReg |= SensorScan_STATUS_INT8_REG;
            intMsb = (uint8)((storeStatusReg >> inputBlock) << SensorScan_7BIT_SHIFT);
            storeStatusReg = (storeStatusReg & (uint8)(~(uint8)(1u << inputBlock)));
        }
        intSrc |= intMsb;
    #endif /* SensorScan_NUM_OF_CHANNELS > 64u */

    return (intSrc);
}


/*******************************************************************************
* Function Name: SensorScan_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the pending interrupt requests from the selected block.
*  Masked interrupts are not returned.
*
* Parameters:
*  InputBlock: Specifies the block of 8 channels whose interrupt requests
*  should be returned.
*
* Return:
*  Bit field of interrupt sources from the selected block of 8 inputs.
*
*******************************************************************************/
uint8 SensorScan_GetInterruptSourceMasked(uint8 inputBlock)   \
                                                
{
    return (SensorScan_GetInterruptSource(inputBlock) & (uint8)~SensorScan_GetInterruptMask (inputBlock));
}


/*******************************************************************************
* Function Name: SensorScan_GetInterruptMask
********************************************************************************
*
* Summary:
*  Gets the current interrupt mask for the selected block.
*
* Parameters:
*  InputBlock: Specifies the block of 8 channels whose interrupt requests
*  should be returned.
*
* Return:
*  The interrupt mask for the given block of channels.
*  A '1' indicates that the interrupt is enabled, a '0' indicates that it 
*  is masked off.
*
*******************************************************************************/
uint8 SensorScan_GetInterruptMask(uint8 inputBlock) 
{
    #if (SensorScan_NUM_OF_CHANNELS >= 8u)
        uint8 maskMsb = 0u;
    #endif /* SensorScan_NUM_OF_CHANNELS >= 8u */

    uint8 intSrc = 0u;

    if (inputBlock < SensorScan_NUM_OF_INT_REGISTERS)
    {
        intSrc = (uint8) (* interruptStatusMaskRegs[inputBlock]);
    }    

    #if (SensorScan_NUM_OF_CHANNELS > 63u)
        if (inputBlock == 7u)
        {
            maskMsb = (uint8)(SensorScan_STATUS_INT9_MASK  << SensorScan_7BIT_SHIFT);
        }
        else
        {
            maskMsb = (uint8)((SensorScan_STATUS_INT8_MASK >> inputBlock) << SensorScan_7BIT_SHIFT);
        }
        intSrc |= maskMsb;
    #elif (SensorScan_NUM_OF_CHANNELS >= 8u)
        if (inputBlock != 7u)
        {
            maskMsb = (uint8)((SensorScan_STATUS_INT8_MASK >> inputBlock) << SensorScan_7BIT_SHIFT);
        }
        intSrc |= maskMsb;
    #endif /* SensorScan_NUM_OF_CHANNELS > 63u */

    return ((uint8)intSrc);
}


/*******************************************************************************
* Function Name: SensorScan_SetInterruptMask
********************************************************************************
*
* Summary:
*  Sets the interrupt masks for the set block of 8 channels.
*
* Parameters:
*  InputBlock: specifies the block of 8 channels whose interrupt requests
*  should be returned.
*  mask: Interrupt mask value for the specified block of 8 or less channels. 
*  A '1' indicates that the interrupt is enabled, a '0' indicates that it 
*  is masked off.
*
* Return:
*  None
*
*******************************************************************************/
void SensorScan_SetInterruptMask(uint8 inputBlock, uint8 mask)    \
                                       
{
    uint8 maskLsb = mask & SensorScan_7BIT_MASK;

    #if (SensorScan_NUM_OF_CHANNELS >= 8u)
        uint8 maskMsb = (uint8)((mask >> SensorScan_7BIT_SHIFT) << inputBlock);
    #endif /* SensorScan_NUM_OF_CHANNELS >= 8u */
    
    if (inputBlock < SensorScan_NUM_OF_INT_REGISTERS)
    {
        (* interruptStatusMaskRegs[inputBlock]) = maskLsb;
    }    

    #if (SensorScan_NUM_OF_CHANNELS > 63u)
        if (inputBlock == 7u)
        {
            SensorScan_STATUS_INT9_MASK = maskMsb;
        }
        else
        {
            SensorScan_STATUS_INT8_MASK = maskMsb;
        }

    #elif (SensorScan_NUM_OF_CHANNELS >= 8u)
        if (inputBlock != 7u)
        {
            SensorScan_STATUS_INT8_MASK = maskMsb;
        }
    #endif /* SensorScan_NUM_OF_CHANNELS > 63u */
}


/*******************************************************************************
* Function Name: SensorScan_GetCompare
********************************************************************************
*
* Summary:
*  Returns a nonzero value when the voltage connected to the positive input
*  is greater than the negative input voltage.
*
* Parameters:
*  channel: channel whose compare output is to be read.
*
* Return:
*  Comparator output state
*
*******************************************************************************/
uint8 SensorScan_GetCompare(uint8 channel) 
{
    uint8 compVal;
    uint8 chanPos;
    uint8 blockNum;

    static reg8 * const CYCODE outputStatusRegs[SensorScan_NUM_OF_OUT_REGISTERS] =
    {
        SensorScan_STATUS_OUT0_PTR,

        #if(SensorScan_NUM_OF_CHANNELS > 8u)
            SensorScan_STATUS_OUT1_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 8u */

        #if(SensorScan_NUM_OF_CHANNELS > 16u)
            SensorScan_STATUS_OUT2_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 16u */

        #if(SensorScan_NUM_OF_CHANNELS > 24u)
            SensorScan_STATUS_OUT3_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 24u */

        #if(SensorScan_NUM_OF_CHANNELS > 32u)
            SensorScan_STATUS_OUT4_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 32u */

        #if(SensorScan_NUM_OF_CHANNELS > 40u)
            SensorScan_STATUS_OUT5_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 40u */

        #if(SensorScan_NUM_OF_CHANNELS > 48u)
            SensorScan_STATUS_OUT6_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 48u */

        #if(SensorScan_NUM_OF_CHANNELS > 56u)
            SensorScan_STATUS_OUT7_PTR,
        #endif /* SensorScan_NUM_OF_CHANNELS > 56u */
    };

    /* Identify block number by dividing by 8 */
    blockNum = (channel >> 3u);

    /* Identify maximum available channels for block */
    chanPos = (uint8)((blockNum + 1u) << 3u);
    
    /* Identify channel position in the register */
    chanPos = SensorScan_MSB_REG_BIT_HIGH >> ((chanPos - 1u) - channel);
    
    /* Input block int register & MSB bit shift */
    compVal = ((uint8) * outputStatusRegs[blockNum]) & chanPos;

    return (compVal);
}

#if (SensorScan_INTERNAL_REF_IS_USED)
    /*******************************************************************************
    * Function Name: SensorScan_SetDACRange
    ********************************************************************************
    *
    * Summary:
    *  Sets the DAC to a new range.
    *
    * Parameters:
    *  uint8 DACRange: new range to be written to the DAC:
    *   SensorScan_SCANCOMP_DACRANGE_1V
    *   SensorScan_SCANCOMP_DACRANGE_4V
    *
    * Return:
    *  void
    *
    *******************************************************************************/
    void SensorScan_SetDACRange(uint8 DACRange) 
    {
        SensorScan_VDAC_SetRange(DACRange);
        SensorScan_compDACRange = DACRange;
    }


    /*******************************************************************************
    * Function Name: SensorScan_GetDACRange
    ********************************************************************************
    *
    * Summary:
    *  Gets the DAC range setting..
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  uint8 DACrange:
    *   SensorScan_SCANCOMP_DACRANGE_1V
    *   SensorScan_SCANCOMP_DACRANGE_4V
    *
    *******************************************************************************/

    uint8 SensorScan_GetDACRange(void) 
    {
        return (SensorScan_compDACRange);
    }


    #if (SensorScan_VDAC_PER_CHANNEL_MODE_USED)

        /*******************************************************************************
        * Function Name: SensorScan_SetChannelDACVoltage
        ********************************************************************************
        *
        * Summary:
        *  Sets the DAC output for a specific channel to a new voltage.
        *
        * Parameters:
        *  Channel: Specifies the channel whose DAC voltage should be changed. 0
        *           indexed.
        *  DACVoltage: Voltage to be written to the DAC, in units depending on the
        *              selected range (4 or 16 mV per bit in 1 or 4V range,
        *              respectively). Should only be used when the DAC is enabled and
        *              voltage is per channel.
        *
        * Return:
        *  void
        *
        *******************************************************************************/
        void SensorScan_SetChannelDACVoltage(uint8 channel, uint8 DACVoltage) \
                                                   
        {
            if (channel < SensorScan_NUM_OF_CHANNELS)
            {
                SensorScan_DacVoltages[(SensorScan_DEFAULT_CHANNELS_VAL - channel)] = DACVoltage;
            }
        }


        /*******************************************************************************
        * Function Name: SensorScan_GetChannelDACVoltage
        ********************************************************************************
        *
        * Summary:
        *  Gets the DAC output voltage for a specific channel.
        *
        * Parameters:
        *  Channel: Specifies the channel whose DAC voltage should be returned.
        *
        * Return:
        *  Voltage the DAC is configured for, for the given channel, in units
        *  depending on the selected range (4 or 16 mV per bit in 1 or 4V range,
        *  respectively).
        *
        *******************************************************************************/
        uint8 SensorScan_GetChannelDACVoltage(uint8 channel)  \
                                                    
        {
            uint8 DACVoltage = 0u;

            if (channel < SensorScan_NUM_OF_CHANNELS)
            {
                DACVoltage = SensorScan_DacVoltages[(SensorScan_DEFAULT_CHANNELS_VAL - channel)];
            }

            return (DACVoltage);
        }
        
        
        /*******************************************************************************
        * Function Name: SensorScan_InitDma
        ********************************************************************************
        *
        * Summary:
        *  Configures a DMA transfer of channel values from memory to VDAC.
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        static void SensorScan_InitDma(void)  
        {
            /***************************************************************************
            * Transfers channel values from SRAM to VDAC register. One byte transfer,
            * each burst requires a request.
            ***************************************************************************/
            SensorScan_DMA_VDACUpdate_Chan =  SensorScan_DMA_DmaInitialize(
                                                    SensorScan_DMA_BYTES_PER_BURST,
                                                    SensorScan_DMA_REQUEST_PER_BURST,
                                                    HI16(SensorScan_DMA_SRC_BASE),
                                                    HI16(SensorScan_DMA_DST_BASE));

            SensorScan_DMA_VDACUpdate_TD = CyDmaTdAllocate();


            /***************************************************************************
            * One TD looping on itself, increment the source address, but not the
            * destination address.
            ***************************************************************************/
            (void) CyDmaTdSetConfiguration( SensorScan_DMA_VDACUpdate_TD,
                                            SensorScan_NUM_OF_CHANNELS,
                                            SensorScan_DMA_VDACUpdate_TD,
                                            TD_INC_SRC_ADR);

            /* Transfers the value for each channel from memory to VDAC */
            (void) CyDmaTdSetAddress(   SensorScan_DMA_VDACUpdate_TD,
                                        LO16((uint32)SensorScan_DacVoltages),
                                        LO16((uint32)SensorScan_VDAC_Data_PTR));

            (void) CyDmaChSetInitialTd(SensorScan_DMA_VDACUpdate_Chan, SensorScan_DMA_VDACUpdate_TD);
        }

    #else
        
        /*******************************************************************************
        * Function Name: SensorScan_SetDACVoltage
        ********************************************************************************
        *
        * Summary:
        *  Sets the DAC output to a new voltage.
        *
        * Parameters:
        *  DACVoltage: Voltage to be written to the DAC, in units depending
        *  on the selected range
        *
        * Return:
        *  void
        *
        *******************************************************************************/
        void SensorScan_SetDACVoltage(uint8 DACVoltage) 
        {
            SensorScan_VDAC_SetValue(DACVoltage);
            SensorScan_compDACVoltage = DACVoltage;
        }


        /*******************************************************************************
        * Function Name: SensorScan_GetDACVoltage
        ********************************************************************************
        *
        * Summary:
        *  Gets the DAC output to a new voltage.
        *
        * Parameters:
        *  None
        *
        * Return:
        *  Voltage the DAC is configured for, in units depending on the selected range
        *  (4 or 16 mV per bit in 1 or 4V range, respectively).
        *
        *******************************************************************************/
        uint8 SensorScan_GetDACVoltage(void) 
        {
            return (SensorScan_compDACVoltage);
        }

    #endif /* SensorScan_VDAC_PER_CHANNEL_MODE_USED */
#endif /* SensorScan_INTERNAL_REF_IS_USED */


/* [] END OF FILE */
