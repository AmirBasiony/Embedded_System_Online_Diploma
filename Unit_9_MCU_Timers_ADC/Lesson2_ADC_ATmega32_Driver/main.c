/*
 * ADC_Driver.c
 *
 * Created: 26/08/2023 08:34:27 PM
 * Author : Amir
 */ 

#include "ADC.h" // Include the ADC library header file
#include "lcd.h" // Include the lcd library header file
#include "util/delay.h" // Include the delay library header file

int main(void)
{
	u16 data;// Declare a variable to store ADC data

	// Configure the ADC settings
	ADC_Config_t ADC_CFG = { ADC_PRESCALER_64 , VREF_AVCC};
    ADC_Init(&ADC_CFG);
 
		
	LCD_INIT(); // Initialize the LCD

	
    while (1) // Infinite loop to continuously read and display ADC values
    {
		LCD_WRITE_STRING("VOLT :");// Display "VOLT :" on the LCD
		LCD_GOTO_XY(1,7);  // Set the LCD cursor to the specified position
		
		// Read ADC value from channel 0, calculate voltage, and display it on the LCD
		data = (ADC_Read(CH_0) * VoltRef)/Resolution;
		//volt = data mV
		LCD_Write_Integer(data); // Display the ADC value (voltage) on the LCD
		LCD_WRITE_STRING(" mv"); // Display " mv" (millivolts) on the LCD
		
		_delay_ms(1000); // Delay for 1 second
		LCD_clear_screen(); // Clear the LCD screen for the next iteration
    }
}

