/*
 * SPI.h
 *
 * Created: 08/05/2022 23:00:24
 *  Author: AMR AHMED
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <util/delay.h>
#include "../../ATMEGA32_MEMORY_MAP.h"

#define SS   4
#define MOSI 5
#define MISO 6
#define SCK  7


void SPI_MasterInit(void);
unsigned char SPI_MasterTransmit(unsigned char cData);
void SPI_SlaveInit(void);
unsigned char SPI_SlaveRecieve(unsigned char cData);

#endif /* SPI_H_ */