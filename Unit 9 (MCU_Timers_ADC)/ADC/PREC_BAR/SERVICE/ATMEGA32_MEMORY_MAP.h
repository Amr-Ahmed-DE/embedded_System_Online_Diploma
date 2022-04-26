/*
 * ATMEGA32.h
 *
 * Created: 22/03/2022 21:44:13
 *  Author: amrta
 */ 


#ifndef ATMEGA32_MEMORY_MAP_H_
#define ATMEGA32_MEMORY_MAP_H_

#include <stdint.h>
#include <util/delay.h>
#include <stdio.h>


//#define F_CPU 80000000UL

#define vuint32_t volatile unsigned int
  

//REGISTERS ADDRESSES
//--------------IO--------------
#define IO_BASE 0x20

//PORTA registers
#define IO_PORTA   (*(vuint32_t *)(IO_BASE + 0x1B))    //Port A Data Register
#define IO_DDRA    (*(vuint32_t *)(IO_BASE + 0x1A))    //Port A Data Direction Register
#define IO_PINA    (*(vuint32_t *)(IO_BASE + 0x19))    //Port A Data Direction Register

//PORTB registers
#define IO_PORTB   (*(vuint32_t *)(IO_BASE + 0x18))    //Port A Data Register
#define IO_DDRB    (*(vuint32_t *)(IO_BASE + 0x17))    //Port A Data Direction Register
#define IO_PINB    (*(vuint32_t *)(IO_BASE + 0x16))    //Port A Data Direction Register


//PORTC registers
#define IO_PORTC	 (*(vuint32_t *)(IO_BASE + 0x15))    //Port C Data Register
#define IO_DDRC		 (*(vuint32_t *)(IO_BASE + 0x14))    //Port C Data Direction Register
#define IO_PINC		 (*(vuint32_t *)(IO_BASE + 0x13))    //Port C Data Direction Register

//PORTD registers
#define IO_PORTD	 (*(vuint32_t *)(IO_BASE + 0x12))      //Port D Data Register
#define IO_DDRD		 (*(vuint32_t *)(IO_BASE + 0x11))      //Port D Data Direction Register
#define IO_PIND		 (*(vuint32_t *)(IO_BASE + 0x10))      //Port D Input Pins Address

//-----------------USART-----------------
//REGISTERS
#define USART_UDR    (*(vuint32_t *)(IO_BASE + 0x0C))      //USART I/O Data Register
#define USART_UCSRA  (*(vuint32_t *)(IO_BASE + 0x0B))      //USART Control and Status Register A
#define USART_UCSRB  (*(vuint32_t *)(IO_BASE + 0x0A))      //USART Control and Status Register B
#define USART_UCSRC  (*(vuint32_t *)(IO_BASE + 0x20))      //USART Control and Status Register C
#define USART_UBBRL  (*(vuint32_t *)(IO_BASE + 0x09))      //USART Baud Rate Registers
#define USART_UBBRH  (*(vuint32_t *)(IO_BASE + 0x20))      //USART Baud Rate Registers

//-----------------8-bit Timer/Counter (0) with PWM-----------------
//REGISTERS
#define T0_TCCR0     (*(vuint32_t *)(IO_BASE + 0x33))	   //TCCR0 – Timer/Counter Control Register
#define T0_TCNT0     (*(vuint32_t *)(IO_BASE + 0x32))	   //TCNT0 – Timer/Counter Register
#define T0_OCR0      (*(vuint32_t *)(IO_BASE + 0x3C))	   //OCR0 – Output Compare Register
#define T0_TIMSK     (*(vuint32_t *)(IO_BASE + 0x39))	   //TIMSK – Timer/Counter Interrupt Mask Register
#define T0_TIFR      (*(vuint32_t *)(IO_BASE + 0x38))	   //TIFR – Timer/Counter Interrupt Flag Register

//-----------------ADC (ANALOG TO DIGITAL CONVERTER)-----------------
//REGISTERS
#define ADC_ADMUX    (*(vuint32_t *)(IO_BASE + 0x07))      //ADMUX  – ADC Multiplexer Selection Register
#define ADC_ADCSRA   (*(vuint32_t *)(IO_BASE + 0x06))      //ADCSRA – ADC Control and Status Register A
#define ADC_ADCL     (*(vuint32_t *)(IO_BASE + 0x04))      //ADCSRA – The ADC LOW  Data Register
#define ADC_ADCH     (*(vuint32_t *)(IO_BASE + 0x05))      //ADCSRA – The ADC HOGH Data Register 
#define ADC_SFIOR    (*(vuint32_t *)(IO_BASE + 0x30))      //SFIOR  – Special FunctionIO Register

#endif /* ATMEGA32_MEMORY_MAP_H_ */