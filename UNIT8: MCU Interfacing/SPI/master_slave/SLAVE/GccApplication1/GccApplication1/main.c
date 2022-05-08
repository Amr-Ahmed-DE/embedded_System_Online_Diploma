/*
 * MAIN.c
 *
 * Created: 08/05/2022 23:15:08
 * Author : AMR AHMED
 */ 
#include "MCAL/SPI_DRIVER/SPI.h"
#define F_CPU 1000000UL 

int main(void)
{
	unsigned char DATA = 255;
	IO_DDRA = 0xFF;
	SPI_SlaveInit();
	for (DATA = 255; DATA >= 0; DATA--)
	{
		IO_PORTA = SPI_SlaveRecieve(DATA);
	}
}


