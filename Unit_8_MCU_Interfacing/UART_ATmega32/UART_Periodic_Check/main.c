/*
 * UART_Driver_ATmega32.c
 *
 * Created: 25/07/2023 02:12:16 ص
 * Author : Amir
 */ 

#include <util/delay.h>
#include "UART.h"
#include "lcd.h"
#include "STDTYPE.h"
#include "stdio.h"
int main(void)
{
	u8 buffer[40];
	u8 x = 0,y = 0;
	LCD_Init();
	UART_Init();
	LCD_GOTO_XY(1,0);
	LCD_Write_String("Periodic Check=");//14
	LCD_GOTO_XY(2,0);
	LCD_Write_String("Timer = ");	//8
	UART_Send_String("Send is Done Successfully\n");
	UART_Send_String("Hello In UART Terminal ^_^");
	/*
	LCD_GOTO_XY(1,0);
	UART_Receive_String(buffer);
	LCD_Write_String(buffer);
	*/
	while (1) 
	{	
		 
		if(UART_Receive_PeriodicCheck(&y))
		{
			LCD_GOTO_XY(1,15);
			LCD_Write_Char(y);
		}		
		LCD_GOTO_XY(2,8);
		LCD_Write_Integer(x);
		x++;
		if(x==10)
		{
			x=0;
		}
		_delay_ms(5000);
		
	}
}

