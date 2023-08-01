/*
 * STM32F103x6.h
 *
 *  Created on: Jul 16, 2023
 *      Author: Amir
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include "stdint.h"

//-----------------------------
//Base Addresses For Memory
//-----------------------------

#define FLASH_Memory_BASE							0X08000000UL
#define System_Memory_BASE							0X1FFFF000UL
#define SRAM_Memory_BASE							0X20000000UL

#define Peripherals_BASE							0X40000000UL

#define Cortex_M3_Internal_Peripherals_BASE	    	0XE00000000UL
//NVIC register map
#define NVIC_BASE						0xE000E100UL
#define NVIC_ISER0					*(volatile uint32_t *)(NVIC_BASE + 0x000)
#define NVIC_ISER1					*(volatile uint32_t *)(NVIC_BASE + 0x004)
#define NVIC_ISER2					*(volatile uint32_t *)(NVIC_BASE + 0x008)
#define NVIC_ICER0					*(volatile uint32_t *)(NVIC_BASE + 0x080)
#define NVIC_ICER1					*(volatile uint32_t *)(NVIC_BASE + 0x084)
#define NVIC_ICER2					*(volatile uint32_t *)(NVIC_BASE + 0x088)


//===================================
//Base Addresses For Peripherals
//===================================

//-----------------------------------
//Base Addresses For APB2 Peripherals
//-----------------------------------

// GPIO
// A,B fully included in LQFP48 Package
#define GPIOA_BASE					0x40010800UL
#define GPIOB_BASE					0x40010C00UL
// C,D Partially included in LQFP48 Package
#define GPIOC_BASE					0x40011000UL
#define GPIOD_BASE					0x40011400UL
// E,F,G is not included in LQFP48 Package
#define GPIOE_BASE					0x40011800UL

//----------

// EXTI
#define EXTI_BASE					0x40010400UL
// AFIO
#define AFIO_BASE					0x40010000UL

// UART
#define USART1_BASE					0x40013800UL

//SPI
#define SPI1_BASE					0x40013000UL


//-----------------------------------
//Base Addresses For APB1 Peripherals
//-----------------------------------

// UART
#define USART2_BASE					0x40004400UL
#define USART3_BASE					0x40004800UL

//SPI
#define SPI2_BASE					0x40003800UL

//-----------------------------------
//Base Addresses For AHB Peripherals
//-----------------------------------

// RCC
#define RCC_BASE					0x40021000UL

//===================================
//Peripheral registers
//===================================


//--------------------------
//Peripheral register: GPIO
//--------------------------
typedef struct
{
	// Offset Addresses of The GPIO Registers
	volatile uint32_t CRL; // 0X00
	volatile uint32_t CRH; // 0X04
	volatile uint32_t IDR; // 0X08
	volatile uint32_t ODR; // 0X0C
	volatile uint32_t BSRR;// 0X10
	volatile uint32_t BRR; // 0X14
	volatile uint32_t LCKR;// 0X18
}GPIO_TypeDef;


//--------------------------
//Peripheral register: EXTI
//--------------------------

typedef struct
{
	// Offset Addresses of The EXTI Registers
	volatile uint32_t IMR;  // 0X00
	volatile uint32_t EMR;  // 0X04
	volatile uint32_t RTSR; // 0X08
	volatile uint32_t FTSR; // 0X0C
	volatile uint32_t SWIER;// 0X10
	volatile uint32_t PR;   // 0X14

}EXTI_TypeDef;

//--------------------------
//Peripheral register: AFIO
//--------------------------
typedef struct
{
	// Offset Addresses of The AFIO Registers
	volatile uint32_t EVCR;    	// 0X00
	volatile uint32_t MAPR;    	// 0X04
	volatile uint32_t EXTICR[4];// [0X08 ,0X0C ,0X10 ,0X14]
	uint32_t 		  RESERVED0;// 0X18
	volatile uint32_t MAPR2;	// 0X1C
}AFIO_TypeDef;

//--------------------------
//Peripheral register: RCC
//--------------------------
typedef struct
{
	// Offset Addresses of The AFIO Registers
	volatile uint32_t CR;      // 0X00
	volatile uint32_t CFGR;    // 0X04
	volatile uint32_t CIR;	   // 0X08
	volatile uint32_t APB2RSTR;// 0X0C
	volatile uint32_t APB1RSTR;// 0X10
	volatile uint32_t AHBENR;  // 0X14
	volatile uint32_t APB2ENR; // 0X18
	volatile uint32_t APB1ENR; // 0X1C
	volatile uint32_t BDCR;    // 0X20
	volatile uint32_t CSR;	   // 0X24
}RCC_TypeDef;


//--------------------------
//Peripheral register: USART
//--------------------------
typedef struct
{
	// Offset Addresses of The USART Registers
	volatile uint32_t SR;      // 0X00
	volatile uint32_t DR;      // 0X04
	volatile uint32_t BRR;	   // 0X08
	volatile uint32_t CR1;	   // 0X0C
	volatile uint32_t CR2;     // 0X10
	volatile uint32_t CR3; 	   // 0X14
	volatile uint32_t GTPR;    // 0X18
}USART_TypeDef;

//--------------------------
//Peripheral register: SPI
//--------------------------
typedef struct
{
	// Offset Addresses of The SPI Registers
	volatile uint32_t CR1;      // 0X00
	volatile uint32_t CR2;      // 0X04
	volatile uint32_t SR;	    // 0X08
	volatile uint32_t DR;	    // 0X0C
	volatile uint32_t CRCPR;    // 0X10
	volatile uint32_t RXCRCR; 	// 0X14
	volatile uint32_t TXCRCR;   // 0X18
	volatile uint32_t I2SCFGR;  // 0X1C
	volatile uint32_t I2SPR;    // 0X20
}SPI_TypeDef;

//==============================
//Peripheral Instances
//==============================

#define GPIOA			((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB			((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC			((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD			((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef *)GPIOE_BASE)


#define RCC 			((RCC_TypeDef *)RCC_BASE)

#define EXTI 			((EXTI_TypeDef *)EXTI_BASE)

#define AFIO 			((AFIO_TypeDef *)AFIO_BASE)

#define USART1			((USART_TypeDef *)USART1_BASE)
#define USART2			((USART_TypeDef *)USART2_BASE)
#define USART3			((USART_TypeDef *)USART3_BASE)

#define SPI1			((SPI_TypeDef *)SPI1_BASE)
#define SPI2			((SPI_TypeDef *)SPI2_BASE)

//======================================================================

//--------------------------------
//RCC Enable Peripherals Macros
//---------------------------------

//Clock Enable GPIO
#define RCC_GPIOA_CLK_EN()			((RCC->APB2ENR) |= 1<<2)
#define RCC_GPIOB_CLK_EN()			((RCC->APB2ENR) |= 1<<3)
#define RCC_GPIOC_CLK_EN()			((RCC->APB2ENR) |= 1<<4)
#define RCC_GPIOD_CLK_EN()			((RCC->APB2ENR) |= 1<<5)
#define RCC_GPIOE_CLK_EN()			((RCC->APB2ENR) |= 1<<6)

//Clock Enable AFIO
#define RCC_AFIO_CLK_EN()			((RCC->APB2ENR) |= 1<<0)

//Clock Enable USART
#define RCC_USART1_CLK_EN()			((RCC->APB2ENR) |= 1<<14)
#define RCC_USART2_CLK_EN()			((RCC->APB1ENR) |= 1<<17)
#define RCC_USART3_CLK_EN()			((RCC->APB1ENR) |= 1<<18)

//RCC Reset Mechanism for USART
#define RCC_USART1_RESET()			((RCC->APB2RSTR) |= 1<<14)
#define RCC_USART2_RESET()			((RCC->APB1RSTR) |= 1<<17)
#define RCC_USART3_RESET()			((RCC->APB1RSTR) |= 1<<18)

//Clock Enable SPI
#define RCC_SPI1_CLK_EN()			((RCC->APB2ENR) |= 1<<12)
#define RCC_SPI2_CLK_EN()			((RCC->APB1ENR) |= 1<<14)

//RCC Reset Mechanism for SPI
#define RCC_SPI1_RESET()			((RCC->APB2RSTR) |= 1<<12)
#define RCC_SPI2_RESET()			((RCC->APB1RSTR) |= 1<<14)


//EXTI IRQ NUMBERS in NVIC
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ 			40
#define EXTI11_IRQ 			40
#define EXTI12_IRQ 			40
#define EXTI13_IRQ 			40
#define EXTI14_IRQ 			40
#define EXTI15_IRQ 			40

#define USART1_IRQ 			37
#define USART2_IRQ 			38
#define USART3_IRQ 			39

#define SPI1_IRQ 			35
#define SPI2_IRQ 			36
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//NVIC Enable/Disable Macros
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

// EXTI
#define NVIC_IQR6_EXTI0_Enable				(NVIC_ISER0 |= (1<<6))
#define NVIC_IQR7_EXTI1_Enable				(NVIC_ISER0 |= (1<<7))
#define NVIC_IQR8_EXTI2_Enable				(NVIC_ISER0 |= (1<<8))
#define NVIC_IQR9_EXTI3_Enable				(NVIC_ISER0 |= (1<<9))
#define NVIC_IQR10_EXTI4_Enable				(NVIC_ISER0 |= (1<<10))
#define NVIC_IQR23_EXTI5_9_Enable			(NVIC_ISER0 |= (1<<23))
#define NVIC_IQR40_EXTI10_15_Enable			(NVIC_ISER1 |= (1<<8)) //40 - 32 = 8

#define NVIC_IQR6_EXTI0_Disable				(NVIC_ICER0 |= (1<<6))
#define NVIC_IQR7_EXTI1_Disable				(NVIC_ICER0 |= (1<<7))
#define NVIC_IQR8_EXTI2_Disable				(NVIC_ICER0 |= (1<<8))
#define NVIC_IQR9_EXTI3_Disable				(NVIC_ICER0 |= (1<<9))
#define NVIC_IQR10_EXTI4_Disable			(NVIC_ICER0 |= (1<<10))
#define NVIC_IQR23_EXTI5_9_Disable			(NVIC_ICER0 |= (1<<23))
#define NVIC_IQR40_EXTI10_15_Disable		(NVIC_ICER1 |= (1<<8)) //40 - 32 = 8

// USART
#define NVIC_IQR37_USART1_Enable			(NVIC_ISER1 |= (1<<(USART1_IRQ - 32)))
#define NVIC_IQR38_USART2_Enable			(NVIC_ISER1 |= (1<<(USART2_IRQ - 32)))
#define NVIC_IQR39_USART3_Enable			(NVIC_ISER1 |= (1<<(USART3_IRQ - 32)))

#define NVIC_IQR37_USART1_Disable			(NVIC_ICER1 |= (1<<(USART1_IRQ - 32)))
#define NVIC_IQR38_USART2_Disable			(NVIC_ICER1 |= (1<<(USART2_IRQ - 32)))
#define NVIC_IQR39_USART3_Disable			(NVIC_ICER1 |= (1<<(USART3_IRQ - 32)))

// SPI
#define NVIC_IQR35_SPI1_Enable				(NVIC_ISER1 |= (1<<(SPI1_IRQ - 32)))
#define NVIC_IQR36_SPI2_Enable				(NVIC_ISER1 |= (1<<(SPI2_IRQ - 32)))

#define NVIC_IQR35_SPI1_Disable				(NVIC_ICER1 |= (1<<(SPI1_IRQ - 32)))
#define NVIC_IQR36_SPI2_Disable				(NVIC_ICER1 |= (1<<(SPI2_IRQ - 32)))


#endif /* INC_STM32F103X6_H_ */
