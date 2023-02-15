/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#include"stdio.h"

#include "Collision_Avoidance.h"
#include "DC_motor.h"
#include"state.h"
#include "US_Sensor.h"

void setup()
{
	//motor_init(); //for left && right speed
	//init SOC Modules
	US_init();
	DC_init();
	//Set states pointer for each block
	CA_state = STATE(CA_waiting) ;
	US_state = STATE(US_busy) ;
	DC_state = STATE(DC_idle) ;
}
int main()
{
	volatile unsigned int d;

	setup();
	while(1)
	{
		// call state for each block
		US_state();
		CA_state();
		DC_state();
		// delay
		for(d = 0 ; d < 1000 ; d++);
	}
	return 0 ;
}

