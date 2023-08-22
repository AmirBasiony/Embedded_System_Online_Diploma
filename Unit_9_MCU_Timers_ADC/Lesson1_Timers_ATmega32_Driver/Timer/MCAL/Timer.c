/*
 * Timer.c
 *
 * Created: 20/08/2023 03:38:30 ص
 *  Author: Amir
 */ 
//******************************************************************
/***********************       Includes        *********************
 *******************************************************************/

#include "Timer.h"
//================================================================
//				Generic Variables
//================================================================
// Callback function pointers
PTR_ToVoidFun_t CaLLBack_OVF = NULL;
PTR_ToVoidFun_t CaLLBack_CM = NULL;

// Global variables
TIMER0_Config_t G_TIMER0_Config;
u8 u8_OVF_Number;
u8 u8_CTC_Number;
//================================================================
//				Generic Functions
//================================================================

// Enable global interrupts
void GIE_enable(void)
{
	SET_BIT(SREG,SREG_BIT7);
}
// Disable global interrupts
void GIE_disable(void)
{
	CLR_BIT(SREG,SREG_BIT7);
}

//================================================================
//				APIs Functions Definition
//================================================================

// Initialize Timer0 based on the provided configuration
E_STATUS_t TIMER0_Init(TIMER0_Config_t *TIM0_Config) {
	E_STATUS_t RetValue = E_NOK;

	// Copy the configuration
	G_TIMER0_Config = *TIM0_Config;

	// Configure Timer mode
	if ((G_TIMER0_Config.MODE == TIMER0_NORMAL_MODE) ||
	(G_TIMER0_Config.MODE == TIMER0_CTC_MODE) ||
	(G_TIMER0_Config.MODE == TIMER0_Phase_Correct_PWM) ||
	(G_TIMER0_Config.MODE == TIMER0_FAST_PWM_MODE)) 
	{
		TCCR0 |= G_TIMER0_Config.MODE;
		RetValue = E_OK;
	} 
	else 
	{
		RetValue = E_NOK;
	}
	
	// Configure Prescaler
	if ((G_TIMER0_Config.PRESCALER_CLK >= NO_CLK_SRC) && (G_TIMER0_Config.PRESCALER_CLK <= EXTERNAL_CLK_RISING_EDG)) 
	{
		TCCR0 |= G_TIMER0_Config.PRESCALER_CLK;
		RetValue = E_OK;
	} 
	else 
	{
		RetValue = E_NOK;
	}

	// Configure Overflow Interrupt
	if (G_TIMER0_Config.OVF_Interrupt == TOVIE0_Enable)
	{
		TIMSK |= G_TIMER0_Config.OVF_Interrupt;
		RetValue = E_OK;
	} 
	else if (G_TIMER0_Config.OVF_Interrupt == TOVIE0_Disable) 
	{
		TIMSK &= TOVIE0_Disable;
		RetValue = E_OK;
	} 
	else 
	{
		RetValue = E_NOK;
	}

	// Configure Compare Match Interrupt
	if ((G_TIMER0_Config.OCM_Interrupt == OCMIE0_Enable) || (G_TIMER0_Config.OCM_Interrupt == OCMIE0_Disable)) 
	{
		TIMSK |= G_TIMER0_Config.OCM_Interrupt;
		RetValue = E_OK;
	}
	else 
	{
		RetValue = E_NOK;
	}

	// Initialize PWM if applicable
	if ((G_TIMER0_Config.MODE == TIMER0_Phase_Correct_PWM) || (G_TIMER0_Config.MODE == TIMER0_FAST_PWM_MODE)) 
	{
		TIMER0_InitPWM(&G_TIMER0_Config); 
	}

	return RetValue;
}

// Initialize Timer0 PWM settings
void TIMER0_InitPWM(TIMER0_Config_t *TIM0_Config)
{
	// Set Fast PWM mode
	if (TIM0_Config->MODE == TIMER0_FAST_PWM_MODE)
	{
		// Set WGM00 and WGM01 bits to enable Fast PWM mode
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
	// Set Phase Correct PWM mode
	else if (TIM0_Config->MODE == TIMER0_Phase_Correct_PWM)
	{
		// Clear WGM00 and set WGM01 bit to enable Phase Correct PWM mode
		CLR_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, WGM00);
	}

	// Set PWM output state
	if (TIM0_Config->PWM0_STATE == PWM0_STATE_NON_INVERTING)
	{
		SET_BIT(TCCR0, COM01);
		CLR_BIT(TCCR0, COM00);
	}
	else if (TIM0_Config->PWM0_STATE == PWM0_STATE_INVERTING)
	{
		SET_BIT(TCCR0, COM01);
		SET_BIT(TCCR0, COM00);
	}
	// Initial duty cycle is 0
	OCR0 = 0;
}

E_STATUS_t TIMER0_Stop(void)
{
	E_STATUS_t	RetValue = E_OK;
	TCCR0	&=	NO_CLK_SRC;
	return	RetValue;
}

E_STATUS_t TIMER0_GetCompareValue(u8 *ptr_u8_ticks)
{
	E_STATUS_t	RetValue = E_OK;
	*ptr_u8_ticks	=	OCR0;
	return	RetValue;
}

E_STATUS_t TIMER0_SetCompareValue(u8 u8_ticks)
{
	E_STATUS_t	RetValue = E_OK;
	OCR0 = u8_ticks;
	return	RetValue;
}

E_STATUS_t TIMER0_GetCounterValue(u8 *ptr_u8_ticks)
{
	E_STATUS_t	RetValue = E_OK;
	*ptr_u8_ticks = TCNT0;
	return	RetValue;
}

E_STATUS_t TIMER0_SetCounterValue(u8 u8_ticks)
{
	E_STATUS_t	RetValue = E_OK;
	TCNT0 = u8_ticks;
	return	RetValue;
}

E_STATUS_t TIMER0_GetOverflowValue(u8 *ptr_u8_ticks)
{
	E_STATUS_t	RetValue = E_OK;
	*ptr_u8_ticks = u8_OVF_Number;
	return	RetValue;
}

E_STATUS_t TIMER0_SetOverflowValue(u8 u8_ticks)
{
	E_STATUS_t	RetValue = E_OK;
	u8_OVF_Number = u8_ticks;
	return	RetValue;
}


void  TIMER0_SetCallBack_Overflow_Interrupt(PTR_ToVoidFun_t CallBack)
{	
	u8_OVF_Number++;
	if(CallBack != NULL)
	{
		CaLLBack_OVF = CallBack;
	}
}

void __vector_11 (void)__attribute__((signal));
void __vector_11 (void)
{
	CaLLBack_OVF();
}

void  TIMER0_SetCallBack_CompareMatch_Interrupt(PTR_ToVoidFun_t CallBack)
{
	u8_CTC_Number++;
	if(CallBack != NULL)
	{
		CaLLBack_CM = CallBack;
	}
}

void __vector_10 (void)__attribute__((signal));
void __vector_10 (void)
{
	CaLLBack_CM();
}

