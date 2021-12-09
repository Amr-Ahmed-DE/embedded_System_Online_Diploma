/*
 * student.c
 *
 *  Created on: 5 Dec 2021
 *      Author: amrta
 */

#include "student.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

//Head of the list (first element)
struct Sstudent *gpFirstStudent = NULL;

//APIs
/*ADD NEW RECORD
 1-List is empty >> create new record and assign gpfirst to it as first element
 2-List is not empty>> navigate to get last record and add new record*/
void AddStudent() {
	struct Sstudent *pNewStudent;
	struct Sstudent *pLastStudent;
	char temp_text[40];
	//check if list is empty
	if (gpFirstStudent == NULL) {
		//create new record
		pNewStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent*));
		//assign it to gpFirst
		gpFirstStudent = pNewStudent;
	} else { // list contain records
			 //navigate until reach to the last record
		pLastStudent = gpFirstStudent;
		while (pLastStudent->PNextStudent) {
			pLastStudent = pLastStudent->PNextStudent;
		}
			//create new record
			pNewStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
		    pLastStudent->PNextStudent = pNewStudent;
	}

	//fill new record
	DPRINTF("\n Enter the ID: ");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter student full name: ");
	gets(pNewStudent->student.name);

	DPRINTF("\n Enter the height: ");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);
	//set the next pointer (new student) to NULL
	pNewStudent->PNextStudent = NULL;
}

int delete_student() {
	char temp_text[40];
	unsigned int selected_id;
	//get the selected id
	DPRINTF("\n Enter the student ID to be deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	//list is not empty
	if (gpFirstStudent) {
		struct Sstudent *pSelectedStudent = gpFirstStudent;
		struct Sstudent *pPreviousStudent = NULL;

		//loop on all records
		while (pSelectedStudent) {
			//compare each Node with the selected ID
			if (pSelectedStudent->student.ID == selected_id) {
				if (pPreviousStudent) //first student is not the selected one
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				} else { // first student == ID
					gpFirstStudent = pSelectedStudent->PNextStudent; // point to next element
				}
				free(pSelectedStudent);
				return 1;
			}
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
	}
	//did not find element = ID
	DPRINTF("\n can not find student ID.");
	return 0;
}

void view_students() {
	struct Sstudent *pCurrentStudent = gpFirstStudent;
	int count = 0;
	if (gpFirstStudent == NULL)
		DPRINTF("Empty list");

		while (pCurrentStudent) {
			DPRINTF("\n record number %d", count + 1);
			DPRINTF("\n \t ID: %d", pCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s", pCurrentStudent->student.name);
			DPRINTF("\n \t height: %f", pCurrentStudent->student.height);
			pCurrentStudent = pCurrentStudent->PNextStudent;
			count++;
		}
	}


void DeleteAll() {
	struct Sstudent *pCurrentStudent = gpFirstStudent;
	if (gpFirstStudent == NULL) {
		DPRINTF("Empty list");
	} else {
		while (pCurrentStudent) {
			struct Sstudent *pTempSdtudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempSdtudent);
		}
		gpFirstStudent = NULL;
	}
}

