/*
 * Keypad.h
 *
 * Created: 17/03/2022 01:09:24
 *  Author: amrta
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 100000UL

//Registers definition 
#define KEYPAD_PORT  PORTD          //PORT Data Register
#define DataDir_KEYPAD_PORT DDRD    //PORT DATA DIRECTION
#define KEYPAD_PIN PIND				//PORT Input Pins Address
 
//PINS definition
#define R0 0  //start at (7)
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//APIs
void KEYPAD_INIT();
char KEYPAD_GETCHAR();

#endif /* KEYPAD_H_ */