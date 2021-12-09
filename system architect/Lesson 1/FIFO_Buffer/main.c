/*
 * main.c
 *
 *  Created on: 27 Nov 2021
 *      Author: amrta
 */
#include <stdio.h>
#include "lifo.h"
#include "stdlib.h"

unsigned int buffer1 [5];

int main(void)
{
	int i, temp = 0;
	LIFO_Buf_t uart_lifo, I2C_lifo;
	//static allocation (create buffer in memory)
	LIFO_init(&uart_lifo, buffer1, 5); //create in data memory
	//dynamic allocation
	unsigned int* buffer2 = (unsigned int*)malloc(5* sizeof(unsigned int)); // store in heap
	LIFO_init(&I2C_lifo, buffer2, 5);

	//Push process
	for(i = 0; i<5; i++)
	{
		if(LIFO_Add_item(&uart_lifo, i) == LIFO_no_error)
		{
			printf("UART_LIFO add: %d \n", i);
		}
	}
	//get process
	for(i = 0; i<5; i++)
	{
		if(LIFO_get_item(&uart_lifo, &temp) == LIFO_no_error)
		{
			printf("UART_LIFO get: %d \n", temp);
		}
	}
}
