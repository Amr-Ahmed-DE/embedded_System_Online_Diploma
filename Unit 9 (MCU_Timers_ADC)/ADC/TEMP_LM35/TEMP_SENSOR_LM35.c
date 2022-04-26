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
	uint16_t VOLT;
	uint16_t TEMP;
  	LCD_INIT();
	ADC_INIT(VREF_AVCC, ADC_SCALER_64);
	LCD_GOTO_XY(1, 0);
	LCD_WRITE_STRING("TEMPRETURE: ");
    while (1) 
    {
		//--------DISPLAY_TEMP_LM35----------------
		VOLT = ((uint32_t)ADC_READ(ADC_CH_7) * 5000) / 1023;   //V_INPUT_EQUATION-> (V_INPUT = V_REFERENCE * ADC_VALUE / RESOLUTION) in mVOLT
		TEMP = VOLT / 10;
		LCD_GOTO_XY(1, 12);
		LCD_WRITE_INTEGER_Number(TEMP);
		LCD_WRITE_STRING("C");
		_delay_ms(4000);
		//LCD_clear_screen();
		//--------------------------------------------
		
    }
}

