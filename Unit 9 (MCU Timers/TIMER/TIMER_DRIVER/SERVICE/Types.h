/*
 * Types.h
 *
 * Created: 15/04/2022 23:31:52
 *  Author: amrta
 */ 


#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char  uint8_t;

typedef unsigned char* Puint8_t;
typedef char*          Pint8_t;

typedef void(* P_VoidFunVoid_t)(void);      //callback function 
#define NULL_P        ((void*) (0))

typedef unsigned char E_STATUS_t;           //status of function
#define E_OK             (E_STATUS_t)(0)    // No Error in function
#define E_NOK            (E_STATUS_t)(1)    //Error in function
#endif /* TYPES_H_ */