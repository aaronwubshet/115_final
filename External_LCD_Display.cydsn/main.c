


#include <project.h>
#include "cypins.h"
#include <math.h>
int main()
{
    
	SensorScan_Start(); // start scanning comparator
    VDAC8_1_Start(); // start voltage dac to provide reference voltage for scanning comparator
    
	LCD_Char_1_Start();					// initialize lcd
	LCD_Char_1_ClearDisplay();  
    //print out initial state of song counts
    LCD_Char_1_Position(0, 0);          
	LCD_Char_1_PrintString("Song1:0 ");   
	LCD_Char_1_Position(0, 8);
    LCD_Char_1_PrintString("Song2:0");
    LCD_Char_1_Position(1, 0);
    LCD_Char_1_PrintString("Song3:0 ");
    LCD_Char_1_Position(1, 8);
    LCD_Char_1_PrintString("Song4:0");
    
    //song counts
    uint8 case1count = 0x00;
    uint8 case2count = 0x00;
    uint8 case3count = 0x00;            
    uint8 case4count = 0x00;
	
    //print out initial state of song counts
    LCD_Char_1_Position(0, 6);
    LCD_Char_1_PrintNumber(case1count);
    LCD_Char_1_Position(0, 14);
    LCD_Char_1_PrintNumber(case2count);
    LCD_Char_1_Position(1, 6);
    LCD_Char_1_PrintNumber(case3count);
    LCD_Char_1_Position(1, 14);
    LCD_Char_1_PrintNumber(case4count);
    
    //dummy variables to only single trigger values
    uint8 flag1 = 0;
    uint8 flag2 = 0;
    uint8 flag3 = 0;
    uint8 flag4 = 0;
    PGA_Start();        //start programmable gain amplifier
    ADC_Start();        // start adc to convert analog voltage of distance sensor to digital byte
    ADC_StartConvert(); // start conversion of voltage to digital byte
    
    int16 distance;     // variable for adc result
    
    
    for(;;)
    {
        //debugging code for sensor readings
        
        /*
        LCD_Char_1_Position(1, 8);
        LCD_Char_1_PrintNumber(SensorValue1_Read());
        LCD_Char_1_Position(1, 9);
        LCD_Char_1_PrintNumber(SensorValue2_Read());
        LCD_Char_1_Position(1, 10);
        LCD_Char_1_PrintNumber(SensorValue3_Read());
        LCD_Char_1_Position(1, 11);
        LCD_Char_1_PrintNumber(SensorValue4_Read());
        LCD_Char_1_Position(1, 12);
        LCD_Char_1_PrintNumber(SensorValue5_Read());
        LCD_Char_1_Position(1, 13);
        
        */
        // clearing interrupt after 1 ms
        if (Sensor_Interrupt_Read()) {
            CyDelay(1);
            SensorScan_GetInterruptSource(0);
            SensorScan_GetInterruptSource(1);
            SensorScan_GetInterruptSource(2);
            SensorScan_GetInterruptSource(3);
            SensorScan_GetInterruptSource(4);
            
            
        }
        
        //LCD_Char_1_PrintNumber(Sensor_Interrupt_Read());
        
        //wait for adc conversion to finish before processing distance value
        if (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)){
            distance = ADC_GetResult16();
            
            distance = distance/10;
            //LCD_Char_1_Position(1, 8);
            //LCD_Char_1_PrintNumber(distance);
            
            //set gain based on distance value
            if (distance >400){        
                PGA_SetGain(PGA_GAIN_01);
                
            }
            else if (distance > 300){
                PGA_SetGain(PGA_GAIN_02);
                
            }
            else if (distance > 200){
                PGA_SetGain(PGA_GAIN_04);
                
            }
            else {
                PGA_SetGain(PGA_GAIN_08);
                
            }  
      
            
        }
        //play different frequency tone based on which pin is triggered 
        //via setting the clock divider
        if ((Song1Trigger_Read() == 1) & (flag1 ==0)){
            SineWaveClock_SetDivider(9);
            SineWaveGen_Start();
            
            case1count = case1count+1;
            LCD_Char_1_Position(0, 6);
            LCD_Char_1_PrintNumber(case1count);
            flag1 = 1;
            
        }
        if (Song1Trigger_Read() == 0) {
            flag1 = 0;
        }
        
        
        if ((Song2Trigger_Read() == 1) & (flag2 ==0)){
            SineWaveClock_SetDivider(10);
            SineWaveGen_Start();
            
            case2count = case2count+1;
            LCD_Char_1_Position(0, 14);
            LCD_Char_1_PrintNumber(case2count);
            flag2 = 1;
            
            
        }
        if (Song2Trigger_Read() == 0) {
            flag2 = 0;
        }
        if ((Song3Trigger_Read() == 1) & (flag3 == 0)){
            SineWaveClock_SetDivider(11);
            SineWaveGen_Start();
            
            case3count = case3count+1;
            LCD_Char_1_Position(1, 6);
            LCD_Char_1_PrintNumber(case3count);
            flag3 = 1;
            
            
        }
        if (Song3Trigger_Read() == 0) {
            flag3 = 0;
        }
        
        if ((Song4Trigger_Read() == 1) & (flag4 == 0)){
            SineWaveGen_Stop();
            
            case4count = case4count+1;
            LCD_Char_1_Position(1, 14);
            LCD_Char_1_PrintNumber(case4count);
            flag4 = 1;
            
            
        }
        if (Song4Trigger_Read() == 0) {
            flag4 = 0;
        }
    }
}

