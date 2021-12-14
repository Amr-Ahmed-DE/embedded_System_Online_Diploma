/*
 * main.c
 *
 *  Created on: 13 Dec 2021
 *      Author: amrta
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

	void setup (){
		//init all drivers
		//init IRQs
		//init HAL (US_DRIVER DC_DRIVER)
		//init BLOCK
		US_init();
		DC_init();
		//set states pointers for each Block
		CA_state = STATE (CA_waiting);
		US_state = STATE (US_busy);
		DC_state = STATE (DC_idle);
	}

int main(void){
	volatile int d;
	setup();

	while(1)
	{
		//call state for each Block
		US_state();
		CA_state();
		DC_state();
		//delay
		for(d = 0; d <= 1000; d++);
	}
	return 0;
	}
