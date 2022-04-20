/*
 * TIMER0_DRIVER.h
 *
 * Created: 19/04/2022 01:12:04
 *  Author: AMR AHMED
 */ 


#ifndef TIMER0_DRIVER_H_
#define TIMER0_DRIVER_H_

/* ================================================================ *
 * =========================== INCLUDES =========================== *
 * ================================================================ */
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../../SERVICE/ATMEGA32_MEMORY_MAP.h"
#include "../../SERVICE/Types.h"
#include "../../SERVICE/UTILS.h"


/* ================================================================ *
 * =========================== STRUCTURES ========================= *
 * ================================================================ */

typedef struct
{
	//specifies TIMER MODE ->> (NORMAL,Clear Timer on Compare Match (CTC), FAST PWM, PHASE CORRECT PWM)
	//This parameter is set based on ->> @ref TIMER0_MODE_DEFINE
	uint8_t TIMER0_MODE;
	
	//specifies TIMER CLOCK SOURCE ->> SELECT: (EXTERNAL, INTERNAL)
	//This parameter is set based on ->> @ref TIMER0_CLK_SELECT_DEFINE
	uint8_t TIMER0_CLK_SELECT;
	
	//specifies TIMER INTERRUPR ->> SELECT: (DISABLE, ENABLE OUTPUT COMPARE MATCH_INTERRUPT (OCMI0), ENABLE OVER FLOW_INTERRUPT(TOIE0))
	//This parameter is set based on ->> @ref TIMER0_INTERRUPT_DEFINE
	uint8_t TIMER0_INTERRUPT;
	
	//Pointer to Callback Function (interrupt Handler)
	P_VoidFunVoid_t IRQ_CALL_BACK;
}TIMER0_CONFIGURATION_t;

/* ================================================================ *
 * =============== MACROS Configuration References ================ *
 * ================================================================ */

//@ref TIMER0_MODE_DEFINE
#define TIMER0_MODE_NORMAL									((uint8_t)(0))
#define TIMER0_MODE_CTC										((uint8_t)(0x08))
#define TIMER0_MODE_FAST_PWM_INVERTING						((uint8_t)(0x78))			//FAST_PWM: SET [WGM00,WGM00] (1, 1);	NON-INV: SET [COM01, COM00] (0, 1) 
#define TIMER0_MODE_FAST_PWM_NON_INVERTING					((uint8_t)(0x68))			//FAST_PWM: SET [WGM00,WGM00] (1, 1);	INVERT : SET [COM01, COM00] (1, 1)

//@ref TIMER0_CLK_SELECT_DEFINE
#define TIMER0_CLOCK_SOURCE_NONE							((uint8_t)(0b000 << 0))
#define TIMER0_CLOCK_SOURCE_INTERNAL_NO_PRESCALER			((uint8_t)(0b001 << 0))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8			((uint8_t)(0b010 << 0))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_64			((uint8_t)(0b011 << 0))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_256			((uint8_t)(0b100 << 0))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_1024			((uint8_t)(0b101 << 0))
#define TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE			((uint8_t)(0b110 << 0))
#define TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE			((uint8_t)(0b111 << 0))

//@ref TIMER0_INTERRUPT_DEFINE
#define TIMER0_INTERRUPT_DISABLE							((uint8_t)(0))
#define TIMER0_INTERRUPT_ENABLE_TOIE0						((uint8_t)(1<<0))
#define TIMER0_INTERRUPT_ENABLE_OCIE0						((uint8_t)(1<<1))

/* ================================================================ *
 * =============================== APIs =========================== *
 * ================================================================ */

E_STATUS_t MCAL_TIMER0_INIT   (TIMER0_CONFIGURATION_t	*TIMER0_CONFIGURATION);
E_STATUS_t MCAL_TIMER0_DE_INIT(void);

E_STATUS_t MCAL_TIMER0_Get_CompareValue  (Puint8_t Pu8_TICKS);
E_STATUS_t MCAL_TIMER0_Set_CompareValue  (uint8_t  u8_TICKS);

E_STATUS_t MCAL_TIMER0_Get_CounterValue  (Puint8_t Pu8_TICKS);
E_STATUS_t MCAL_TIMER0_Set_CounterValue  (uint8_t  u8_TICKS);

E_STATUS_t MCAL_TIMER0_Get_OverFlowValue (Puint8_t Pu8_TICKS);
E_STATUS_t MCAL_TIMER0_Set_OverFlowValue (uint8_t  u8_TICKS);

E_STATUS_t MCAL_PWM_Duty_Cycle(uint8_t Duty_Cycle);

void MCAL_TIMER0_Set_CallBack_OverFlow_Interrupt     (P_VoidFunVoid_t CALLBACK);
void MCAL_TIMER0_Set_CallBack_CompareMatch_Interrupt (P_VoidFunVoid_t CALLBACK);

#endif /* TIMER0_DRIVER_H_ */