
#ifndef TIMER_H_
#define TIMER_H_


//******************************************************************
/***********************       Includes        *******************
******************************************************************/

#include "STDTYPE.h"
#include "UTILS.h"

//******************************************************************
/*************************       STRUCTS        ******************
******************************************************************/
// Structure to configure Timer0
typedef struct {
    u8 MODE;           // Timer mode, @ref TIMER0_MODE_Define
    u8 PRESCALER_CLK;  // Prescaler clock, @ref TIMER0_PRESCALER_CLK_Define
    u8 OCM_Interrupt;  // Output Compare Match interrupt, @ref TIMER0_OCMIE_Define
    u8 OVF_Interrupt;  // Overflow interrupt, @ref TIMER0_TOVIE_Define
    u8 PWM0_STATE;     // PWM0 state, @ref PWM0_STATE_Define
} TIMER0_Config_t;


//******************************************************************
/*************************       ENUMS        *********************
*******************************************************************/
// Enums for bit positions in registers

//TIMSK: (Timer/Counter Interrupt Mask Register)
typedef enum{
	TOIE0 = 0,// Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
	OCIE0,	  // Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
	TOIE1,
	OCIE1B,
	OCIE1A,
	TICIE1,
	TOIE2,
	OCIE2 = 7
}TIMER0_TIMSK_PINs_E;

// TCCR0 (Timer/Counter Control Register)
typedef enum{
	CS00 = 0,
	CS01,
	CS02,
	WGM01,   //Bit 3 – WGM01:0: Waveform Generation Mode
	COM00,   //Bit 4 – COM00: Compare Match Output Mode
	COM01,   //Bit 5 – COM01: Compare Match Output Mode
	WGM00,   //Bit 6 – WGM01:0: Waveform Generation Mode
	FOC0 = 7 // Bit 7 – FOC0: Force Output Compare
}TIMER0_TCCR0_PINs_E;

//TIFR:  Timer/Counter Interrupt Flag Register
typedef enum{
	TOV0 = 0,//• Bit 0 – TOV0: Timer/Counter0 Overflow Flag
	OCF0 ,  //• Bit 1 – OCF0: Output Compare Flag 0
	TOV1,
	OCF1B,
	OCF1A,
	ICF1,
	TOV2,
	OCF2 = 7
}TIMER0_TIFR_PINs_E;

//---------------------------------------
//@ref PWM0_STATE_Define
//---------------------------------------
typedef enum {
	PWM0_STATE_Disable,
	PWM0_STATE_INVERTING ,
	PWM0_STATE_NON_INVERTING
} PWM0_STATE_INVERTING_E;
	
//******************************************************************
/*************************       MACROS        *******************
******************************************************************/

//TCCR0: FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
#define TCCR0	*((volatile u8 *)0x53)
//TCNT0: Timer/Counter0 (8 Bits)
#define TCNT0	*((volatile u8 *)0x52)
//OCR0: Timer/Counter0 Output Compare Register
#define OCR0	*((volatile u8 *)0x5C)
//TIMSK: OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
#define TIMSK	*((volatile u8 *)0x59)
//TIFR: OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
#define TIFR	*((volatile u8 *)0x58)

#define SREG   *((volatile u8 *)0x5F)
#define SREG_BIT7 7
//--------------------------
//@ref TIMER0_MODE_Define
//--------------------------
#define TIMER0_NORMAL_MODE              (u8)(0)
#define TIMER0_CTC_MODE                 (u8)(1<<WGM01)
#define TIMER0_Phase_Correct_PWM        (u8)(1<<WGM00)  //Update of OCR0 is TOP ()
#define TIMER0_FAST_PWM_MODE            (u8)((1<<WGM00) | (1<<WGM01)) //Update of OCR0 is BOTTOM

//---------------------------------------
//@ref TIMER0_PRESCALER_CLK_Define
//---------------------------------------
//TCCR0: Bit 2:0 – CS02:0: Clock Select
// Prescaler clock settings
#define NO_CLK_SRC		                ~((u8)((1<<CS02) | (1<<CS01) | (1<<CS00)))//No clock source (Timer/Counter stopped).
#define NO_PRESCALING                   (u8)(1<<CS00)                 //clk		  (No prescaling)
#define PRESCALING_CLK_8                (u8)(1<<CS01)                 //clk/8     (From prescaler)
#define PRESCALING_CLK_64               (u8)((1<<CS01) | (1<<CS00))   //clk/64    (From prescaler)
#define PRESCALING_CLK_256              (u8) (1<<CS02)                //clk/256   (From prescaler)
#define PRESCALING_CLK_1024             (u8)((1<<CS02) | (1<<CS00))   //clk/8     (From prescaler)
#define EXTERNAL_CLK_FALLING_EDG        (u8)((1<<CS02) | (1<<CS01))   //clk/8     External clock source on T0 pin. Clock on falling edge.
#define EXTERNAL_CLK_RISING_EDG         (u8)((1<<CS02) | (1<<CS01) | (1<<CS00))//clk/8     External clock source on T0 pin. Clock on rising edge.

//---------------------------------------
//@ref TIMER0_OCMIE_Define
//---------------------------------------
//TIMSK: Bit 1 – OCIE0:(Timer/Counter0) Output Compare Match Interrupt Enable
#define OCMIE0_Disable                   ~((u8)(1<<OCIE0))
#define OCMIE0_Enable                    (u8)(1<<OCIE0)

//---------------------------------------
//@ref TIMER0_TOVIE_Define
//---------------------------------------
//TIMSK: Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
#define TOVIE0_Disable                    ~((u8)(1<<TOIE0))
#define TOVIE0_Enable                    (u8)(1<<TOIE0)

	
//****************************************************************
/*******************       APIs Functions        *****************
******************************************************************/

// Function to initialize Timer0
E_STATUS_t TIMER0_Init(TIMER0_Config_t *TIM0_Config);

// Function to stop Timer0
E_STATUS_t TIMER0_Stop(void);
// Function to set the compare value of Timer0
E_STATUS_t TIMER0_SetCompareValue(u8 u8_ticks);
// Function to get the current counter value of Timer0
E_STATUS_t TIMER0_GetCounterValue(u8 *ptr_u8_ticks);
// Function to set the counter value of Timer0
E_STATUS_t TIMER0_SetCounterValue(u8 u8_ticks);
// Function to get the overflow counter value of Timer0
E_STATUS_t TIMER0_GetOverflowValue(u8 *ptr_u8_ticks);
// Function to set the overflow counter value of Timer0
E_STATUS_t TIMER0_SetOverflowValue(u8 u8_ticks);
// Function to set the overflow interrupt callback function for Timer0
void TIMER0_SetCallBack_Overflow_Interrupt(PTR_ToVoidFun_t CallBack);
// Function to set the compare match interrupt callback function for Timer0
void TIMER0_SetCallBack_CompareMatch_Interrupt(PTR_ToVoidFun_t CallBack);

// Function to initialize PWM settings for Timer0 (internal use)
void TIMER0_InitPWM(TIMER0_Config_t *TIM0_Config);

#endif /* TIMER_H_ */