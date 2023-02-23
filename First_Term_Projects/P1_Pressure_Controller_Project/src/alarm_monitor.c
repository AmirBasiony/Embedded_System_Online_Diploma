/*
 * Alarm_Monitor.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#include "alarm_monitor.h"

#include "state.h"
#include "driver.h"
#include "main_algorithm.h"
#include "pressure_sensor.h"

// Global_Variable
//volatile int Alarm_Timer = 600;

// State pointer to function
void (*AM_state)();

// Functions Definitions
STATE_define(Alarm_ON)
{
	// state name
	AM_state_id  = Alarm_ON ;

	// state action
	Set_Alarm_actuator(0);
	//set delay and wait
	Delay(600000);
	//Turn Alarm OFF after 60s
	STATE(Alarm_OFF)();
}
STATE_define(Alarm_OFF)
{
	// state action
	Set_Alarm_actuator(1);
}
