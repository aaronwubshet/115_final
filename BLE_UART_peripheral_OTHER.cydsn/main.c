/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  BLE example project that works as a BLE to UART bridge, using 
*  Cypress's BLE component APIs and application layer callback. 
*  This project demostrates a custom service usage for BLE to UART  
*  bridge in a PERIPHERAL role.
*
* References:
*  BLUETOOTH SPECIFICATION Version 4.1
*
* Hardware Dependency:
*  (1) CY8CKIT-042 BLE
*  (2) An external UART transciever (if flow control is needed) 
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "main.h"
#include "cypins.h"
int main()
{
    UART_1_Start();
    #ifdef LOW_POWER_MODE    
        CYBLE_LP_MODE_T         lpMode;
        CYBLE_BLESS_STATE_T     blessState;
    #endif
    
    CYBLE_API_RESULT_T      bleApiResult;
    
    CyGlobalIntEnable;
    
    /* Start UART and BLE component and display project information */
    UART_Start();   
    bleApiResult = CyBle_Start(AppCallBack); 
    
    if(bleApiResult == CYBLE_ERROR_OK)
    {
        #ifdef PRINT_MESSAGE_LOG
            UART_UartPutString("\n\r************************************************************");
            UART_UartPutString("\n\r***************** BLE UART example project *****************");
            UART_UartPutString("\n\r************************************************************\n\r");
            UART_UartPutString("\n\rDevice role \t: PERIPHERAL");
            
            #ifdef LOW_POWER_MODE
                UART_UartPutString("\n\rLow Power Mode \t: ENABLED");
            #else
                UART_UartPutString("\n\rLow Power Mode \t: DISABLED");
            #endif
            
            #ifdef FLOW_CONTROL
                UART_UartPutString("\n\rFlow Control \t: ENABLED");  
            #else
                UART_UartPutString("\n\rFlow Control \t: DISABLED");
            #endif
            
        #endif
    }
    else
    {
        #ifdef PRINT_MESSAGE_LOG   
            UART_UartPutString("\n\r\t\tCyBle stack initilization FAILED!!! \n\r ");
        #endif
        
        /* Enter infinite loop */
        while(1);
    }
    
    CyBle_ProcessEvents();
    
    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    uint8 flag = 0;
    
    while(1)
    {              
        //wait for user to send a byte over the serial terminal then check
        // other buffer for data sent over BLE
        if (UART_SpiUartGetRxBufferSize()>0){           
            if (UART_1_SpiUartGetRxBufferSize() > 0){
                flag = UART_1_UartGetChar();
                switch(flag){
                    case 0x31:
                        Song1Trigger_Write(1);
                        CyDelay(100);
                        Song1Trigger_Write(0);
                        UART_1_SpiUartClearRxBuffer();
                        break;              
                        
                    case 0x32:
                        Song2Trigger_Write(1);
                        CyDelay(100);
                        Song2Trigger_Write(0);
                        UART_1_SpiUartClearRxBuffer();
                        break;
                        
                    case 0x33:
                        Song3Trigger_Write(1);
                        CyDelay(100);
                        Song3Trigger_Write(0);
                        UART_1_SpiUartClearRxBuffer();
                        break;
                                          
                    case 0x34:
                        Song4Trigger_Write(1);
                        CyDelay(100);
                        Song4Trigger_Write(0);
                        UART_1_SpiUartClearRxBuffer();
                        break;
                     
                        
                }
           
            }
             
        }
        
        
        
       
        #ifdef LOW_POWER_MODE
            
            if((CyBle_GetState() != CYBLE_STATE_INITIALIZING) && (CyBle_GetState() != CYBLE_STATE_DISCONNECTED))
            {
                /* Enter DeepSleep mode between connection intervals */
                
                lpMode = CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
                CyGlobalIntDisable;
                blessState = CyBle_GetBleSsState();

                if(lpMode == CYBLE_BLESS_DEEPSLEEP) 
                {   
                    if((blessState == CYBLE_BLESS_STATE_ECO_ON || blessState == CYBLE_BLESS_STATE_DEEPSLEEP) && \
                            (UART_SpiUartGetTxBufferSize() + UART_GET_TX_FIFO_SR_VALID) == 0u)
                    {
                        #ifdef FLOW_CONTROL
                            EnableUartRxInt();
                        #endif
                        
                        CySysPmSleep();
                        
                        #ifdef FLOW_CONTROL
                            DisableUartRxInt();
                        #endif
                    }
                }
                else
                {
                    if((blessState != CYBLE_BLESS_STATE_EVENT_CLOSE) && \
                            (UART_SpiUartGetTxBufferSize() + UART_GET_TX_FIFO_SR_VALID) == 0u)
                    {
                        #ifdef FLOW_CONTROL
                            EnableUartRxInt();
                        #endif
                        
                        CySysPmSleep();
                        
                        #ifdef FLOW_CONTROL
                            DisableUartRxInt();
                        #endif
                    }
                }
                CyGlobalIntEnable;
                
                /* Handle advertising led blinking */
                HandleLeds();
            }
        #else
            HandleLeds();
        #endif
        
        /*******************************************************************
        *  Process all pending BLE events in the stack
        *******************************************************************/       
        HandleBleProcessing();
        CyBle_ProcessEvents();
    }
}
/* [] END OF FILE */
