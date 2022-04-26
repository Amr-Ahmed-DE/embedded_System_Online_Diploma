/*
 * ADC.c
 *
 * Created: 24/04/2022 02:27:59
 * Author : AMR AHMED
 */ 

#include <avr/io.h>
#include "HAL/LCD_DRIVER/LCD.h"
#include "MCAL/ADC_DRIVER/ADC_DRIVER.h"

#define F_CPU 8000000UL

int main(void)
{
	uint16_t PER_VALUE;
	uint8_t i; //COUNTER
  	LCD_INIT();
	ADC_INIT(VREF_AVCC, ADC_SCALER_64);
	LCD_GOTO_XY(1, 0);
	LCD_WRITE_STRING("PRESENT_VAL: ");
    while (1) 
    {
		//--------DISPLAY_PRESENTAGE_VALUE_BAR----------------
		PER_VALUE = ((uint32_t)ADC_READ(ADC_CH_7) * 100) / 1023;   //PRESENTAGE_VALUE-> (V_INPUT = V_REFERENCE * ADC_VALUE / RESOLUTION)
		LCD_GOTO_XY(1, 12);	
		LCD_WRITE_INTEGER_Number(PER_VALUE);
		LCD_WRITE_STRING("%");
		LCD_GOTO_XY(2, 0);
		for (i = 0; i < PER_VALUE/10; i++)
		{LCD_WRITE_CHAR(0xFF);}
		_delay_ms(4000);
		//LCD_clear_screen();
		//--------------------------------------------
		
    }
}

