/*
 * queue.h
 *
 *  Created on: 30 Nov 2021
 *      Author: amrta
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"

//Selection of Element Data Type (uint8_t, uint_16, uint32_t, ....)
#define element_type uint8_t

//Creation of buffer1
#define width1 5
element_type Uart_Buffer[width1];

//FIFO Structure

typedef struct {
	uint32_t length;
	uint32_t count;
	element_type *base;
	element_type *head;
	element_type *tail;
} FIFO_Buf_t;

//Buffer Status

typedef enum {
	FIFO_no_error, FIFO_full, FIFO_empty, FIFO_null,FIFO_valid
} FIFO_Buf_Status;

//FIFO APIs

FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, element_type *buf, uint32_t length); //connect btw array and fifo_structure
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t *fifo, element_type item); //Add new element to fifo
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t *fifo, element_type *item); //get value from fifo
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t *fifo); //check if fifo full or not
FIFO_Buf_Status FIFO_Validation(FIFO_Buf_t *fifo); //check if FIFO Valid or not
void FIFO_print(FIFO_Buf_t *fifo); //print the fifo

#endif /* FIFO_H_ */
