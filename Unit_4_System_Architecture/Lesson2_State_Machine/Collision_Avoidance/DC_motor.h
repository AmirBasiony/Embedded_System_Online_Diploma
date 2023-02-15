/*
 * CA.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"state.h"
// define states

enum{
	DC_idle,
	DC_busy
}DC_state_id;

// declare states functions of DC
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

// State pointer to function
extern void (*DC_state)();

#endif /* DC_MOTOR_H_ */
