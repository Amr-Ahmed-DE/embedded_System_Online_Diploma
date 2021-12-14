/*
 * CA.h
 *
 *  Created on: 13 Dec 2021
 *      Author: amrta
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
//Define states
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE Pointer to function
extern void (*CA_state)();
#endif /* CA_H_ */
