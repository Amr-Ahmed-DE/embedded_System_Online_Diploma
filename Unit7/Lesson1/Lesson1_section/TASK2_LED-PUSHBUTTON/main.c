/*
 * TASK2_LED-PUSHBUTTON.c
 *
 * Created: 15/03/2022 01:24:43
 * Author : amrta
 *
 *DESRIPTION: TURN ON LEDS 0 -> 7 sequentially, IF PUSH-BUTTON IS PRESSED 
 */ 
#include "utils.h"
#include "MemoryMap.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void GPIOA_init(void);

int main(void)
{
	int i = 0;
	GPIOA_init();
	
	while(1)
	{
		if(ReadBit(IO_PIND,0) == 1) //Check if Push-Button(PD 0) is pressed(pull-down)
		{
			SetBit(IO_PORTA, i);  // LED ON
			i++;
			while(ReadBit(IO_PIND,0) == 1); 	
		}
		if(ReadBit(IO_PIND,1) == 1) //Check if Push-Button(PD 1) is pressed(pull-down)
		{
			IO_PORTA = 0x0; //Turn Off all Leds PA
			i = 0;          //reset led counter
		}
		
	}
}


void GPIOA_init(void)
{
	//PORTA Output (8 LEDS)
	IO_DDRA = 0xFF  ;          //set PA 0b1111 1111
	//PORTD Input Pin 0,1
	ClearBit(IO_PORTD,0);      //set PD 0 Tri-state (Hi-Z)
	ClearBit(IO_DDRD,0);       //set PD 0 as input (Push-Button) >> Turn on Leds
	ClearBit(IO_PORTD,1);      //set PD 1 Tri-state (Hi-Z)
	ClearBit(IO_DDRD,1);       //set PD 1 as input (Push-Button) >> Reset all Leds
}

