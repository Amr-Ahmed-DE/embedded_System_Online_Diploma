/*
 * DC.c
 *
 *  Created on: 13 Dec 2021
 *      Author: amrta
 */
#include "DC.h"

//variables
int DC_speed = 0;


//STATE Pointer to function
void (*DC_state)();

void DC_init()
{
	//init PWM
	printf("DC_init \n");
	}
void DC_motor(int s){
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA--------Speed = %d------> DC  \n", DC_speed);
}

STATE_define (DC_idle) {
	//state_Name
	DC_state_id = DC_idle;

	//state_Action
	//Call PWM to make speed = DC_speed

	printf("DC_IDLE State: speed=%d \n", DC_speed);
}

STATE_define(DC_busy) {
	//state_Name
	DC_state_id = DC_busy;

	//state_Action
		//Call PWM to make speed = DC_speed

	DC_state = STATE(DC_idle);
	printf("DC_busy State: speed=%d \n", DC_speed);

}

