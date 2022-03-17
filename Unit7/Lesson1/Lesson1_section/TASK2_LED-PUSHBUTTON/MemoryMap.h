/*
 * MemoryMap.h
 *
 * Created: 14/03/2022 21:46:59
 *  Author: amrta
 */ 
#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//Registers

//IO
#define IO_BASE 0x20

//PORTA registers
#define IO_PORTA   (*(volatile unsigned int *)(IO_BASE + 0x1B))    //The Port D Data Register
#define IO_DDRA    (*(volatile unsigned int *)(IO_BASE + 0x1A))    //The Port D Data Direction Register
#define IO_PINA    (*(volatile unsigned int *)(IO_BASE + 0x19))    //The Port D Data Direction Register

//PORTD registers
#define IO_PORTD   (*(volatile unsigned int *)(IO_BASE + 0x12))    //The Port D Data Register
#define IO_DDRD    (*(volatile unsigned int *)(IO_BASE + 0x11))    //The Port D Data Direction Register
#define IO_PIND    (*(volatile unsigned int *)(IO_BASE + 0x10))    //The Port D Data Direction Register


#endif /* MEMORYMAP_H_ */

