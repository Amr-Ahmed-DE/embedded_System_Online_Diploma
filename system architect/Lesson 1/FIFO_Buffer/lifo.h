/*
 * lifo.h
 *
 *  Created on: 27 Nov 2021
 *      Author: amrta
 */

#ifndef LIFO_H_
#define LIFO_H_


//type definitions (LIFO attributes)
typedef struct {
	unsigned int length; //length of buffer
	unsigned int count;  //counter to count steps
 	unsigned int* base;  //Base address of buffer
	unsigned int* head;  //add of the buffer counter
}LIFO_Buf_t;


typedef enum{ //All status of Buffer
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_Null,
}LIFO_Status;


//APIs , interface functions to control stored data
LIFO_Status LIFO_Add_item(LIFO_Buf_t* lifo_buf, unsigned char item);
LIFO_Status LIFO_get_item(LIFO_Buf_t* lifo_buf, unsigned char* item);
LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length);
LIFO_Status LIFO_Buffer_Full(LIFO_Buf_t* lifo_buf);

#endif /* LIFO_H_ */
