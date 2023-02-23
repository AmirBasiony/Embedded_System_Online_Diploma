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
#define STATE(_FuncName_) ST_##_FuncName_

//shared Prototypes
void Set_Pressure_Val(int pVal);

#endif /* STATE_H_ */
