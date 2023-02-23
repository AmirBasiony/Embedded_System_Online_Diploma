#include "alarm_monitor.h"
#include "driver.h"
#include "main_algorithm.h"
#include "pressure_sensor.h"

void setup()
{
	//Initialize GPIO Driver
	GPIO_INITIALIZATION();

	//Set states pointer for each block
	PS_state = STATE(PS_reading) ;
	HPD_state = STATE(HP_Detect) ;
	AM_state = STATE(Alarm_OFF);
}

int main ()
{
	setup();
	while (1)
	{
		//all state for each block
		PS_state();
		AM_state();
		HPD_state();
	}

}
