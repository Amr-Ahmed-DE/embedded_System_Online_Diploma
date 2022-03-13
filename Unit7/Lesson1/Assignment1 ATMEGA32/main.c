/*
 * main.c
 *
 * Created: 3/10/2022 10:16:23 PM
 *  Author: amrta
 Unit7_Lesson1_LAB2:>>> @ Atmega32
 
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//Registers

//IO
#define IO_BASE 0x20000000

//PORTD registers
#define IO_PORTD   *(volatile unsigned int *)(IO_BASE + 0x12)    //The Port D Data Register
#define IO_DDRD    *(volatile unsigned int *)(IO_BASE + 0x11)    //The Port D Data Direction Register

void GPIO_init(void);

int main(void)
{
	GPIO_init();
	 
	
    while(1)
    {
        IO_PORTD |= (1 << 5);  // LED 0 ON
		_delay_ms(1000);
		IO_PORTD &= ~(1 << 5);  // LED 0 OFF
		IO_PORTD |= (1 << 6);  // LED 1 ON
		_delay_ms(1000);
		IO_PORTD &= ~(1 << 6);  // LED 1 OFF
		IO_PORTD |= (1 << 7);  // LED 2 ON
		_delay_ms(1000);
		IO_PORTD &= ~(1 << 7);  // LED 0 OFF
		IO_PORTD |= (1 << 4);  // Buzzer ON
		_delay_ms(1000);
		IO_PORTD &= ~(1 << 4);  // Buzzer OFF
		_delay_ms(1000);
    }
}


void GPIO_init(void)
{	
	//PORTD PIN 4 Output (Buzzer)
	IO_DDRD &= ~(1 << 4);  //set PD 4 as output
	
	//PORTD PIN 5, 6, and 7 >> OUTPUT >> LED 0, 1, and 2
	IO_DDRD &= ~(1 << 5);
	IO_DDRD &= ~(1 << 6);
	IO_DDRD &= ~(1 << 7);
}

