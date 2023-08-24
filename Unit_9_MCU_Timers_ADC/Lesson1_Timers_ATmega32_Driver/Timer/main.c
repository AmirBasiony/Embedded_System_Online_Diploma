/*
 * Timer_Driver.c
 *
 * Created: 19/08/2023 07:06:53 PM
 * Author : Amir
 */ 

#include "Timer.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "avr/delay.h"
// Define Pulse Output Pins
#define PULSE_OC0_PIN			Pin_3
// Callback function to handle the pulse generation
void PWM_PulseCallback(void)
{
	// Toggle the pulse output pin state
	TOGGLE_BIT(PORTB,PULSE_OC0_PIN);
	
	// Delay for 500 milliseconds
	_delay_ms(500); 
}

void TIMER0_OVF_CALLBACK()
{
	PORTA = ~PORTA;
}

void PWM0_Init_Handle()
{
	 //TIMER0_Config_t timer0Config = {TIMER0_FAST_PWM_MODE ,PRESCALING_CLK_8 ,OCMIE0_Enable ,TOVIE0_Disable,PWM0_STATE_NON_INVERTING};
	 //TIMER0_Config_t timer0Config = {TIMER0_FAST_PWM_MODE ,PRESCALING_CLK_8 ,OCMIE0_Enable ,TOVIE0_Disable,PWM0_STATE_INVERTING};
	 //TIMER0_Config_t timer0Config = {TIMER0_Phase_Correct_PWM ,PRESCALING_CLK_8 ,OCMIE0_Enable ,TOVIE0_Disable,PWM0_STATE_NON_INVERTING};	 
	 TIMER0_Config_t timer0Config = {TIMER0_Phase_Correct_PWM ,PRESCALING_CLK_8 ,OCMIE0_Enable ,TOVIE0_Disable,PWM0_STATE_INVERTING};	 
	 // Initialize TIMER0
	 TIMER0_Init(&timer0Config);

	 // Set pulse output pin as output
	 SET_BIT(DDRB,PULSE_OC0_PIN);
	 
	 // Set the compare value for a 50% duty cycle
	 //  PWM0_SetDutyCycleValue(50);
	 
	 // Set the compare value for a 75% duty cycle
	 PWM0_SetDutyCycleValue(75);

	 // Set the compare match interrupt callback function
	 TIMER0_SetCallBack_CompareMatch_Interrupt(PWM_PulseCallback);

	 // Enable global interrupts
	 GIE_enable();	
	 
}
/*** Over Folw Timer0 ***/
void TimerZero_Init()
{
	GIE_enable();
	TIMER0_SetCallBack_CompareMatch_Interrupt(TIMER0_OVF_CALLBACK);
	TIMER0_Config_t TIM0_Config = {TIMER0_CTC_MODE ,PRESCALING_CLK_8 ,OCMIE0_Enable ,TOVIE0_Disable,PWM0_STATE_Disable};
	TIMER0_SetCompareValue(0xF0);
	TIMER0_Init(&TIM0_Config);
}

int main(void)
{
	/*** Over Folw Timer0 ***/
	/*
	DIO_SetPortDirection(PORTA,PORT_OUTPUT);
	TimerZero_Init();
	*/
	
	/****	PWM		****/
	// Initialize TIMER0 configuration structure
	PWM0_Init_Handle();
	
    while (1) 
    {
    }
}

