/*
 * US.c
 *
 *  Created on: 13 Dec 2021
 *      Author: amrta
 */
#include "US.h"

//variables
int US_distance = 0;

//STATE Pointer to function
void (*US_state)();
int US_Get_distance_random(int l, int r, int count);

void US_init() {
	//init US Driver
	printf("US_init \n");
}

STATE_define (US_busy) {
	//state_Name
	US_state_id = US_busy;

	//state_Action
	US_distance = US_Get_distance_random(45, 55, 1); // read from US_SENSOR

	printf("US_Waiting State: distance =%d \n", US_distance);

	US_Set_distance(US_distance); //send distance
	US_state = STATE(US_busy);
}

int US_Get_distance_random(int l, int r, int count) {
	//will generate random number in range l (low) and r (range)
	int i;
	for (i = 0; i < count; i++) {
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}
