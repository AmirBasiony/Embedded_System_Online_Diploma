/*
 * HPDetect.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#include "main_algorithm.h"

#include "state.h"
#include "alarm_monitor.h"
#include "driver.h"
#include "pressure_sensor.h"

// Global_Variable
unsigned int HPD_PVal;
unsigned int HPD_threshold = 20;

void (*HPD_state)();

// Functions Definitions
void Set_Pressure_Val(int pVal)
{
	HPD_PVal = pVal;
	HPD_state = STATE(HP_Detect);
}
STATE_define(HP_Detect)
{
	// state name
	HP_state_id = HP_Detect ;
	// state action
	if(HPD_PVal <= HPD_threshold)
	{
//		//initial step(Default Action)
		STATE(Alarm_OFF)();
	}
	else //if(HPD_PVal > HPD_threshold)
	{
		AM_state = STATE(Alarm_ON);
	}
	HPD_state = STATE(HP_Detect);
}
