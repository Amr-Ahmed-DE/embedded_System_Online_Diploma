/*
 * main.c
 *
 * Created: 3/10/2022 10:16:23 PM
 *  Author: amrta
 LAB2:>>> @ Atmega32
 Enable External interrupts 0,1, and 2, in order to control LED 0, 1, and 2 for 1 second
 As INT0:>>  interrupt at any logic change mode
    INT1:>>  interrupt at falling edge mode 
    INT2:>>  interrupt at rising edge mode 
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//Registers

//External Interrupt
#define EXTI_BASE 0x20000000
#define EXTI_SREG    *(volatile unsigned int *)(EXTI_BASE + 0x3F)    //The AVR Status Register
#define EXTI_MCUCR   *(volatile unsigned int *)(EXTI_BASE + 0x35)    //MCU Control Register
#define EXTI_MCUCSR  *(volatile unsigned int *)(EXTI_BASE + 0x34)    //MCU Control and Status Register
#define EXTI_GICR    *(volatile unsigned int *)(EXTI_BASE + 0x3B)    //General Interrupt Control Register
#define EXTI_GIFR    *(volatile unsigned int *)(EXTI_BASE + 0x3A)    //General Interrupt Flag Register

//IO
#define IO_BASE 0x20000000
//PORTB registers
#define IO_PORTB   *(volatile unsigned int *)(IO_BASE + 0x18)    //The Port B Data Register
#define IO_DDRB    *(volatile unsigned int *)(IO_BASE + 0x17)    //The Port B Data Direction Register

//PORTD registers
#define IO_PORTD   *(volatile unsigned int *)(IO_BASE + 0x12)    //The Port D Data Register
#define IO_DDRD    *(volatile unsigned int *)(IO_BASE + 0x11)    //The Port D Data Direction Register

void EXTI_init(void);
void GPIO_init(void);

int main(void)
{
	EXTI_init();
	GPIO_init();
	 
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

void EXTI_init(void)
{
	//Enable global interrupt
	EXTI_SREG |= (1 << 7);                   //set Bit 7 >> 1
	//Enable EXTI 0, 1, and 2
	EXTI_GICR |= (1 << 5);					 //set Bit 5 for EXTI0
	EXTI_GICR |= (1 << 6);                   //set Bit 6 for EXTI2
	EXTI_GICR |= (1 << 7);					 //set Bit 7 for EXTI2
	//Set EXTI0 >> Any change Logical 
	EXTI_MCUCR |= (1 << 0);                  //set Bit 0 ISC00 >> 1
	//Set EXTI1 >> rising edge
	EXTI_MCUCR |= (1 << 2);                 //set Bit 2 ISC10 >> 1
	EXTI_MCUCR |= (1 << 3);                 //set Bit 3 ISC11 >> 1
	//Set EXTI2 >> falling edge
	EXTI_MCUCSR &= ~(1 << 6);               //reset Bit 6 ISC2 >> 0
}

void GPIO_init(void)
{
	//PORTB PIN 2 : INT
	IO_PORTB |= (1 << 2);
	IO_DDRB &= ~(1 << 2);
	
	//PORTD PIN 2 
	IO_PORTD |= (1 << 2);
	IO_DDRD &= ~(1 << 2);
	
	//PORTD PIN 3 
	IO_PORTD |= (1 << 3);
	IO_DDRD &= ~(1 << 3);
	//PORTD PIN 5, 6, and 7 >> OUTPUT >> LED 0, 1, and 2
	IO_DDRD &= ~(1 << 5);
	IO_DDRD &= ~(1 << 6);
	IO_DDRD &= ~(1 << 7);
}

ISR(INT0_vect)
{
	IO_PORTD |= (1 << 5);
	_delay_ms(1000);
}


ISR(INT1_vect)
{
	IO_PORTD |= (1 << 6);
	_delay_ms(1000);
}


ISR(INT2_vect)
{
	IO_PORTD |= (1 << 7);
	_delay_ms(1000);
}