/*
 * STM32_F103x6.h
 *
 *  Created on: Mar 18, 2022
 *      Author: amrta
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE  						0X08000000UL
#define SYSTEM_MEMORY_BASE 						0X1FFFF000UL
#define SRAM_MEMORY_BASE   						0X20000000UL

#define PERIPHERALS_BASE   					    0X40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE     0XE0000000UL

//-----------------------------
//Base addresses for BUS APB2  Peripherals
//-----------------------------
//RCC
#define RCC_BASE          						 0X40021000UL
//#define RCC_BASE          				(PERIPHERALS_BASE + 0X00021000UL)

//-----------------------------
//Base addresses for BUS APB2  Peripherals
//-----------------------------

//GPIO
//A, B Fully included in LQFP48 package
#define GPIOA_BASE          						 0X40010800UL
#define GPIOB_BASE          						 0X40010C00UL

//C, D Partial included in LQFP48 package
#define GPIOC_BASE          						 0X40011000UL
#define GPIOD_BASE          						 0X40011400UL

//E not included in LQFP48 package
#define GPIOE_BASE          						 0X40011800UL

//EXTI
#define EXTI_BASE          						     0X40010400UL

//AFIO
#define AFIO_BASE          						     0X40010000UL


//-----------------------------
//Base addresses for BUS APB1  Peripherals
//-----------------------------


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR ;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	         uint32_t RESERVED0;	//RESERVE 4 BYTE 0x18
	volatile uint32_t MAPR2;	    //@ 0x1C
}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA                  ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                  ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                  ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                  ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                  ((GPIO_TypeDef *)GPIOE_BASE)

#define RCC                    ((RCC_TypeDef *)RCC_BASE)

#define EXTI                   ((EXTI_TypeDef *)EXTI_BASE)

#define AFIO                   ((AFIO_TypeDef *)AFIO_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1 << 3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1 << 4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1 << 5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1 << 6)

#define AFIO_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1 << 0)

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_STM32_F103X6_H_ */
