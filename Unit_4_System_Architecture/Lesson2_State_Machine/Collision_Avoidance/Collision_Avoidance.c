/*
 * CA.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */


#include"state.h"
#include"stdio.h"
#include"stdlib.h"
#include "Collision_Avoidance.h"

// Global_Variable
unsigned int CA_speed = 0;
unsigned int CA_distance = 0;
unsigned int CA_threshold = 50;
// State pointer to function
void (*CA_state)();
// Functions Definitions
void US_Set_distance(int distance)
{
	CA_distance = distance ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)): (CA_state = STATE(CA_driving));
	printf("US -------distance=%d------> CA \n",CA_distance);
}

// Functions Definitions
STATE_define(CA_waiting)
{
	// state name
	CA_state_id  = CA_waiting ;
	// state action
	CA_speed = 0;
	printf("Waiting state: distance = %d , speed = %d \n",CA_distance,CA_speed);
	DC_Motor_Set_speed(CA_speed);

}

STATE_define(CA_driving)
{
	// state name
	CA_state_id  = CA_driving ;
	// state action
	CA_speed = 30;
	printf("Driving state: distance = %d , speed = %d \n",CA_distance,CA_speed);
	DC_Motor_Set_speed(CA_speed);
}

