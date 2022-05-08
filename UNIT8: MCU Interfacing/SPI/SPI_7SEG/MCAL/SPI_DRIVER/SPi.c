/*
 * SPI_MASTER.c
 *
 * Created: 08/05/2022 22:41:15
 * Author : AMR AHMED
 */ 

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

void SPI_SlaveInit(void)
{
	/* Set MISO output */
	DDRB |= (1<<MISO);
	/* Set MOSI, SCK and SS input*/
	DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);
	/* Enable SPI, Slave, set clock rate fck/16 */
	SPI_SPCR = (1<<SPE);
}
unsigned char SPI_SlaveRecieve(unsigned char cData)
{
	/* Start transmission */
	SPI_SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPI_SPSR & (1<<SPIF)));
	return SPI_SPDR;
}

//sent to MAX7221
void MAX_execute(unsigned char cmd, unsigned char data)
{
	PORTB &= ~(1 << SS);
	SPDR = cmd;
	while (!(SPSR & (1 << SPIF)));			//check if not zero
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	PORTB |= (1 << SS);
}




