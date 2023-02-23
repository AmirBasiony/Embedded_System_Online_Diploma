/*
 * PSensor.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef P_SENSOR_H_
#define P_SENSOR_H_

#include"state.h"
// define states

enum{
	PS_reading,
	PS_waiting
}PS_state_id;

// declare states functions of PS
STATE_define(PS_reading);
STATE_define(PS_waiting);
// State pointer to function
extern void (*PS_state)();

#endif /* P_SENSOR_H_ */
