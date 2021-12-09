/*
 * main.c
 *
 *  Created on: 5 Dec 2021
 *      Author: amrta
 */
#include"student.h"

int main(void) {
	char temp_text[40];

	while (1) {
		DPRINTF("\n *************************");
		DPRINTF("\n\t Choose one of the following options \n");
		DPRINTF("\n 1: AddStudent");
		DPRINTF("\n 2: Delete_Student");
		DPRINTF("\n 3: view_students");
		DPRINTF("\n 4: DeleteAll");
		DPRINTF("\n Enter option number: ");

		gets(temp_text);
		DPRINTF("\n *************************");

		switch (atoi(temp_text)) {
		case 1:
			AddStudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		default:
			DPRINTF("\n wrong option");
			break;
		}
	}
}
