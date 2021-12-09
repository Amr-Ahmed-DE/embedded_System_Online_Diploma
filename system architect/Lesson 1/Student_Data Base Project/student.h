/*
 * student.h
 *
 *  Created on: 5 Dec 2021
 *      Author: amrta
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)     {fflush(stdout); \
                       	  fflush(stdin); \
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}

struct Sdata {
	int ID;
	char name[40];
	float height;
};
//;Linked List Node
struct Sstudent {
	struct Sdata student;
	struct Sstudent *PNextStudent;
};

//APIs
/*ADD NEW RECORD
 1-List is empty >> create new record and assign gpfirst to it as first element
 2-List is not empty>> navigate to get last record and add new record*/
void AddStudent();
int delete_student();
void view_students();
void DeleteAll();

#endif /* STUDENT_H_ */
