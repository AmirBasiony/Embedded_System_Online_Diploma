/*
 * PSensor.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#include "pressure_sensor.h"

#include "alarm_monitor.h"
#include "state.h"
#include "driver.h"
#include "main_algorithm.h"

// Global_Variable
unsigned int PS_Val ;
// State pointer to function
void (*PS_state)();

// Functions Definitions
STATE_define(PS_reading)
{
	// Default State
	Set_Alarm_actuator(1);
	// state name
	PS_state_id  = PS_reading ;

	// state action
	PS_Val = getPressureVal() ;
	Set_Pressure_Val(PS_Val);

	STATE(PS_waiting)();
}
STATE_define(PS_waiting)
{
	// state name
	PS_state_id  = PS_waiting ;

	//make delay 100s
	Delay(60000);

	PS_state = STATE(PS_reading);
}
