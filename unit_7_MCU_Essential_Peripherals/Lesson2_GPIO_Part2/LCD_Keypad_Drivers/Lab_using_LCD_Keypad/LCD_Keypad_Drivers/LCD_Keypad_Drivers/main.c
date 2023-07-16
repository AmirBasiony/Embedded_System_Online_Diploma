/*
 * main.c
 *
 * Created: 15/07/2023 08:38:25 م
 * Author : Amir
 */ 

#include "DIO_Interface.h"
#include "LCD.h"
#include "Keypad.h"
int main(void)
{
   LCD_Init();
   KEYPAD_Init();
  // LCD_Write_Integer(124);
  // LCD_Write_String("Embedded System:");
  // LCD_GOTO_XY(2,0);// go to line 2
  // LCD_Write_String("Amir El_basiony");
  // LCD_Write_Real_Number(9653.0332);// 9 number so 9 position will add to count variable
   char Pressed_Key;
   char count = 9;
    while (1) 
    {
		Pressed_Key = KEYPAD_Get_Char();
		switch(Pressed_Key)
		{
			case '!' :
			count = 0;
			LCD_Clear_Screen();
			break;
			case 'N' : // Do nothing
			break;
			default :
/*			if(count == 16) // check if cursor reach to the end of line 1
			{
				LCD_GOTO_XY(2,0);
			}
			else if(count == 32)// check if cursor reach to the end of line 2
			{
				LCD_Clear_Screen();
				LCD_GOTO_XY(1,0);
			}
			count++;
	*/	
			LCD_Write_Char(Pressed_Key);
			break;
		}
		
    }
	
}

