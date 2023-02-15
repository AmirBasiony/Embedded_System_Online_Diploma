/*
 * DC.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */


#include"state.h"
#include"stdio.h"
#include"stdlib.h"

#include "DC_motor.h"

// Global_Variable
unsigned int DC_speed = 0;
// State pointer to function
void (*DC_state)();

// Functions Definitions
void DC_init()
{
	// init PWM
	printf("DC_init \n");
}

void DC_Motor_Set_speed(int speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("CA -------speed=%d------> DC \n",DC_speed);
}

STATE_define(DC_idle)
{
	// state name
	DC_state_id  = DC_idle ;

	// state action
	// CALL PWM to make speed = DC_speed

	printf("DC_idle state: speed = %d \n",DC_speed);
}
STATE_define(DC_busy)
{
	// state name
	DC_state_id  = DC_busy ;

	// state action
	// CALL PWM to make speed = DC_speed

	DC_state = STATE(DC_idle);
	printf("DC_busy state: speed = %d \n",DC_speed);
}
