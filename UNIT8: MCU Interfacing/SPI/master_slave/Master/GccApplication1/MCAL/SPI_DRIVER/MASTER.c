/*
 * SPI_MASTER.c
 *
 * Created: 08/05/2022 22:41:15
 * Author : AMR AHMED
 */ 

#define F_CPU 1000000UL
#include "SPI.h"

void SPI_MasterInit(void)
{
	/* Set MOSI, SCK and SS output, all others input */
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	/* Set MISO input */
	DDRB &= ~(1<<MISO);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPI_SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

unsigned char SPI_MasterTransmit(unsigned char cData)
{
	/* Start transmission */
	SPI_SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPI_SPSR & (1<<SPIF)));
	return SPI_SPDR;
}





