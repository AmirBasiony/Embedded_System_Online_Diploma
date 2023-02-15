/*
 * CA.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_

#include"state.h"
// define states

enum{
	CA_waiting,
	CA_driving
}CA_state_id;

// declare states functions of DC
STATE_define(CA_waiting);
STATE_define(CA_driving);

// State pointer to function
extern void (*CA_state)();

#endif /* COLLISION_AVOIDANCE_H_ */
