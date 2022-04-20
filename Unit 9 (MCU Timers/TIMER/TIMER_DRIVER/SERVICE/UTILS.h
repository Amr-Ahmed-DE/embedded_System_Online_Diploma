/*
 * UTILS.h
 *
 * Created: 22/03/2022 21:48:07
 *  Author: amrta
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg, bit)    (reg= reg | ( 1 << bit))  //reg >> PORT , bit >> 0 -> 7

#define ClearBit(reg, bit)  (reg= reg &~(1 << bit))

#define ReadBit(reg, bit)   ((reg >> bit) & 1)

#define Toggel(reg, bit)    (reg= reg ^ (1 << bit))



#endif /* UTILS_H_ */