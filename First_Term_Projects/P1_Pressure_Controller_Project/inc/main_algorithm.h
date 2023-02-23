/*
 * HPDetect.h
 *
 *  Created on: ???/???/????
 *      Author: Amir
 */

#ifndef HP_DETECT_H_
#define HP_DETECT_H_

#include"state.h"

enum{
	HP_Detect
}HP_state_id;

// State pointer to function
extern void (*HPD_state)();
STATE_define(HP_Detect);

#endif /* HP_DETECT_H_ */
