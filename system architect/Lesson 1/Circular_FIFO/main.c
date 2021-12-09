/*
 * main.c
 *
 *  Created on: 30 Nov 2021
 *      Author: amrta
 */
#include "FIFO.h"

//create static Buffer1
#define buffer1_length 5
element_type buffer1[buffer1_length];
void main() {
	FIFO_Buf_t FIFO_UART;
	element_type i, temp = 0;
	if (FIFO_init(&FIFO_UART, buffer1, buffer1_length) == FIFO_no_error)
		printf("FIFO initialization DONE \n");
//storing in FIFO
	for (i = 0; i < 7; i++) {
		printf("FIFO enqueue (%x) \n", i);
		if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error) {
			printf("\t FIFO Enqueue (%x) DONE \n", i);
		} else {
			printf("\t FIFO Enqueue (%x) FAILED \n", i);
		}
	}
	FIFO_print(&FIFO_UART);
	//Get elements from FIFO
	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\t FIFO dequeue (%x) DONE \n", temp);

	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
			printf("\t FIFO dequeue (%x) DONE \n", temp);
	FIFO_print(&FIFO_UART);

}

