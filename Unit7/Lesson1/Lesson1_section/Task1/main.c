/*
 * TASK1_LEDS.c
 *
 * Created: 14/03/2022 20:46:05
 * Author : amrta
 *DESRIPTION: TURN ON 7 LEDS 0 -> 7 sequentially, then 
 *            TURN ON 7 LEDS 7 -> 0 sequentially
 */ 

#include "MemoryMap.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void GPIOA_init(void);

int main(void)
{
	int i;
	GPIOA_init();
	
	while(1)
	{
		for (i = 0; i < 8; i++)
		{
			IO_PORTA |= (1 << i);  // LED ON
			_delay_ms(1000);
		}
		for (i = 8; i >= 0; i--)
		{
			IO_PORTA &= ~(1 << i);  // LED OFF
			_delay_ms(1000);
		}
	}
}


void GPIOA_init(void)
{
	//PORTA Output (8 LEDS)
	IO_DDRA = 0xFF  ;  //set PA 0b1111 1111
}
