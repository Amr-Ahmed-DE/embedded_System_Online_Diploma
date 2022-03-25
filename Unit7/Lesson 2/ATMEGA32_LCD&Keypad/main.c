/*
 * Lcd_Keypad.c
 *
 * Created: 16/03/2022 21:41:15
 * Author : amrta
 */ 

#include <avr/io.h>
#include "LCD_DRIVER/LCD.h"
#include "Keypad_DRIVER/Keypad.h"


int main(void)
{
    LCD_INIT();
	_delay_ms(10);
	KEYPAD_INIT();
	//LCD_CUSTOM_CHARACTER();
	LCD_WRITE_string("Power on.....");
	_delay_ms(10000);
	LCD_clear_screen();
	
    char pressed_key;                          //VAR TO RECIEVE THE PRESSED KEY
    volatile uint32_t flag = 0;
    while (1) 
    {
		pressed_key = KEYPAD_GETCHAR();        //GET THE KEY,IF PRESSED
		
		switch(pressed_key)
		{
			case('?'):
				LCD_clear_screen();
				break;
			case('N'):						    //IF NOTHING PRESSED (NULL)
				break;
			default:						    //PRINT THE CURRRENT CHARACTER 
				if(flag < 16)
				{
					LCD_WRITE_CHAR(pressed_key);    //SEND DATA OF KEY TO PRINT IT
					flag++;
				}
				else if (flag >= 16 && flag < 32)
				{
					LCD_GOTO_XY(2, (16 - flag));
					LCD_WRITE_CHAR(pressed_key);    //SEND DATA OF KEY TO PRINT IT
					flag++;
				}
				else if(flag = 32)
				{
					flag = 0;
					LCD_clear_screen();
					LCD_WRITE_CHAR(pressed_key);    //SEND DATA OF KEY TO PRINT IT
				}
				break;
		}	
    }
}
