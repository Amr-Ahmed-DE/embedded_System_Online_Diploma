/*
 * SPI_7SEG.c
 *
 * Created: 08/05/2022 23:30:58
 * Author : AMR AHMED
 */ 

#include <avr/io.h>
#include "MCAL/SPI_DRIVER/SPI.h"

int main(void)
{
    unsigned char counter = 0;
    unsigned char index_display;
    SPI_MasterInit();
    MAX_execute(0x09, 0xFF);
    MAX_execute(0x0A, 0xFF);
    MAX_execute(0x0B, 0xF7); //scan limit register format B :: 0xX7
    MAX_execute(0x0C, 0x01);
    while (1)
    {
	    for (index_display = 1; index_display < 9; index_display++)
	    MAX_execute(index_display, counter++);
	    _delay_ms(1000);
    }
}

