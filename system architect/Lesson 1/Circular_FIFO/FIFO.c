/*
 * queue.c
 *
 *  Created on: 30 Nov 2021
 *      Author: amrta
 */
#include "FIFO.h"

//FIFO APIs

//check FIFO Validation
FIFO_Buf_Status FIFO_Validation(FIFO_Buf_t *fifo) {
	if (!fifo->base || !fifo->head || !fifo->tail) {
		return FIFO_null;
	} else {
		return FIFO_valid;
	}
}

//check if FIFO full or not
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t *fifo) {
	if (FIFO_Validation(fifo) == FIFO_valid) {
		if (fifo->count == fifo->length) {
			return FIFO_full;
		} else {
			return FIFO_no_error;
		}
	} else {
		return FIFO_null;
	}
}

//Connect between FIFO as an array and fifo_structure
FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, element_type *buf, uint32_t length) {
	//Check if FIFO is exist or not
	if (buf == NULL)
		return FIFO_null;

	//FIFO initialization
	//Note: At the Beginning (BASE& HEAD& TAIL) point to the beginning of FIFO
	fifo->base = buf; //Point to the Base of FIFO
	fifo->head = buf; //point to the next add where assign new element to FIFO
	fifo->tail = buf; //point to the First_In, which will be deleted at first dequeue order
	fifo->length = length; //length of FIFO(how many elements)
	fifo->count = 0; //Just counting the steps inside FIFO

	return FIFO_no_error;
}

//Add new element to FIFO
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t *fifo, element_type item) {
	if (FIFO_Validation(fifo) == FIFO_valid) //check if FIFO is Valid
			{
		if (FIFO_IS_FULL(fifo) == FIFO_no_error) //check if FIFO is full
				{
			*(fifo->head) = item; //assign the new element
			fifo->count++;
			/*FIFO Circular
			 * If FIFO's Head = FIFO's Base + FIFO's Length, So will change FIFO's Head to Point again
			 * to FIFO's Base, where we can write new element */
			if (fifo->head
					== (fifo->base + (fifo->length * sizeof(element_type)))) {
				fifo->head = fifo->base;
			} else {
				fifo->head++;
			}
			return FIFO_no_error;
		} else {
			return FIFO_full;
		}
	} else {
		return FIFO_null;
	}
}

//get value from FIFO
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t *fifo, element_type *item) {
	if (FIFO_Validation(fifo) == FIFO_valid) //check if FIFO is Valid
			{
		if (fifo->count != 0) {
			*item = *(fifo->tail);
			fifo->count--;

			//circler FIFO
			if (fifo->tail
					== (fifo->base + (fifo->length * sizeof(element_type)))) {
				fifo->tail = fifo->base;
			} else {
				fifo->tail++;
			}

			return FIFO_no_error;

		} else {
			printf("FIFO is empty \n");
			return FIFO_empty;
		}

	} else {
		return FIFO_null;
	}

}

//print the FIFO
void FIFO_print(FIFO_Buf_t *fifo) {
	element_type* temp;
	int i;
	if(fifo->count == 0)
	{
		printf("FIFO is empty \n");
	}else
	{
		temp = fifo->tail;
		printf("\n ********FIFO _ Print ********* \n");
		for(i = 0; i < fifo->count;i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
		printf("\n *************** \n");
	}

}

