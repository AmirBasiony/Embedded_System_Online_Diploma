/*
 * US.c
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */


#include "US_Sensor.h"

#include"state.h"
#include"stdio.h"
#include"stdlib.h"


/*
 * 	//Event_check
	CA_distance = US_Get_distance_random(45,55,1);
 */

// Global_Variable
unsigned int US_distance = 0;

// State pointer to function
void (*US_state)();
// Proto_types
int US_Get_distance_random(int l , int r , int count);
// Functions Definitions
void US_init()
{
	// init US Driver
	printf(" US_init \n");
}
// Functions Definitions
STATE_define(US_busy)
{
	// state name
	US_state_id  = US_busy ;
	// state action
	US_distance = US_Get_distance_random(45,55,1);
	printf("US_Waiting state: distance = %d\n",US_distance);
	//Event_check
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
}
int US_Get_distance_random(int l , int r , int count)
{
	int i,rand_distance=0;
	for(i=0;i<count;i++)
	{
		rand_distance = (rand() % (r - l + 1)) + l;
		return rand_distance;
	}
	return rand_distance;
}
