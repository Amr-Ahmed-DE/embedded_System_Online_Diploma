/*
 * state.h
 *
 *  Created on: 13 Dec 2021
 *      Author: amrta
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
//Automatic STATE Function generated
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

//states connection (INTERFACE)
void US_Set_distance(int d);
void DC_mototr(int S);


#endif /* STATE_H_ */
