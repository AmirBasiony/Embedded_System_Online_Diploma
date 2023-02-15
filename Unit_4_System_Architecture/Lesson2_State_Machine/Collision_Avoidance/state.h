/*
 * state.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef STATE_H_
#define STATE_H_

// Automatic State Function generate

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

//states connection
void US_Set_distance(int distance);
void DC_Motor_Set_speed(int speed);

#endif /* STATE_H_ */
