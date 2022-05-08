/*
 * main.c
 *
 * Created: 08/05/2022 23:03:28
 *  Author: AMR AHMED
 */ 
#include "MCAL/SPI_DRIVER/SPI.h"
int main(void)
{
	/* Replace with your application code */
	unsigned char data;		//data send to slave
	DDRA = 0xFF;				//set PORTA as output 7SEG
	SPI_MasterInit();
	for (data = 0; data <= 255; data++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTransmit(data);
	}
}