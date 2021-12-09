/*
 * lifo.c
 *
 *  Created on: 27 Nov 2021
 *      Author: amrta
 */

#include "lifo.h"

#include <stdio.h>

LIFO_Status LIFO_Buffer_Full(LIFO_Buf_t *lifo_buf) {
	if (lifo_buf->count == lifo_buf->length)
		return LIFO_full;
	if(lifo_buf->head >=(lifo_buf->base + lifo_buf->length))
	{
		return LIFO_full;
	}else{
		return LIFO_not_full;
	}
}

LIFO_Status LIFO_Add_item(LIFO_Buf_t *lifo_buf, unsigned char item) {
	//check if Buffer is valid
	if (!lifo_buf || !lifo_buf->base || !lifo_buf->head) {
		return LIFO_Null;
	}
	//check if Buffer is full
	if (LIFO_Buffer_Full(lifo_buf) == LIFO_full) {
		return LIFO_full;
	}
	//Add new element in Buffer
	*(lifo_buf->head) = item; // add value of item in the dereference of pointer to head
	lifo_buf->count++;
	lifo_buf->head++;
	return LIFO_no_error;
}

LIFO_Status LIFO_get_item(LIFO_Buf_t *lifo_buf, unsigned char *item)
{
	//check if Buffer is valid
	if (!lifo_buf || !lifo_buf->base || !lifo_buf->head) {
		return LIFO_Null;
	}
	//check if Buffer is empty
	if (lifo_buf->count == 0) {
		return LIFO_empty;
	}

	lifo_buf->head--;          //go one step back in buffer
	*item = *(lifo_buf->head); // assign the new element to the current item
	lifo_buf->count--;
	return LIFO_no_error;
}

LIFO_Status LIFO_init(LIFO_Buf_t *lifo_buf, unsigned int *buf,unsigned int length) {
	if (buf == NULL) // check if it is a valid Buffer Return (0 = valid, 1 = not valid)
		return LIFO_Null;

	lifo_buf->base = buf;     //Base Address of start of Buffer
	lifo_buf->head = buf;    //Address of pointer points to the current location
	lifo_buf->length = length;  // number of elements in Buffer
	lifo_buf->count = 0;       //init counter, start at 0
	return LIFO_no_error; //if initialization succeed
}

