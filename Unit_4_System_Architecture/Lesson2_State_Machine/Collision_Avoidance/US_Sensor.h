/*
 * US.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include"state.h"
// define states

enum{
	US_busy,
}US_state_id;

// declare states functions of US
STATE_define(US_busy);

void US_init();
// State pointer to function
extern void (*US_state)();

#endif /* US_SENSOR_H_ */
