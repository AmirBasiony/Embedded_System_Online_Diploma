/*
 * Alarm_Monitor.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include"state.h"
// define states

enum{
	Alarm_OFF,
	Alarm_ON
}AM_state_id;
#define ON  (int)1
#define OFF (int)0
// declare states functions of AM
STATE_define(Alarm_OFF);
STATE_define(Alarm_ON);
//STATE_define(High_Pressure_Detect);
// State pointer to function
extern void (*AM_state)();

#endif /* ALARM_MONITOR_H_ */
