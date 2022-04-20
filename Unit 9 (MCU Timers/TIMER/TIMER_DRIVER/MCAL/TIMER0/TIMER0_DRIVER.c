/*
 * TIMER0_DRIVER.c
 *
 * Created: 19/04/2022 01:11:47
 *  Author: AMR AHMED
 */ 


/* ================================================================ *
 * =========================== INCLUDES =========================== *
 * ================================================================ */
#include "TIMER0_DRIVER.h"

/* ================================================================ *
 * ===================== GENERAL MACROS =========================== *
 * ================================================================ */

TIMER0_CONFIGURATION_t* TIMER0_CONFIG;
uint8_t u8_T0_OVER_FLOW_Number;
P_VoidFunVoid_t CALLBACK_OVER_FLOW;
P_VoidFunVoid_t CALLBACK_CompareMatch;

/* ================================================================ *
 * ===================== APIs DEFINITIONs========================== *
 * ================================================================ */


E_STATUS_t MCAL_TIMER0_INIT   (TIMER0_CONFIGURATION_t	*TIMER0_CONFIGURATION)
{
	E_STATUS_t STATUS = E_NOK;
	if(TIMER0_CONFIGURATION == NULL_P)					//CHECH IF CONFIGURATION POINTER IS VALIS
	{
		STATUS = E_NOK;
	}
	else
	{
		TIMER0_CONFIG = TIMER0_CONFIGURATION;
		
		/*TIMER0 MODE SELECTION*/
		
		if(TIMER0_CONFIG->TIMER0_MODE == TIMER0_MODE_NORMAL || TIMER0_CONFIG->TIMER0_MODE == TIMER0_MODE_CTC)
		{
			T0_TCCR0 |= TIMER0_CONFIG->TIMER0_MODE;
			STATUS = E_OK;
		}
		else if(TIMER0_CONFIG->TIMER0_MODE == TIMER0_MODE_FAST_PWM_INVERTING || TIMER0_CONFIG->TIMER0_MODE == TIMER0_MODE_FAST_PWM_NON_INVERTING)
		{
			T0_TCCR0 |= TIMER0_CONFIG->TIMER0_MODE;
			SetBit(DDRD, 1);					      //SET PIN1 (OC0) PORTD >> OUTPUT
			STATUS = E_OK;
		}
		else
		{
			STATUS = E_NOK;
		}
		
		/*TIMER0 CLOCK SOURCE SELECTION*/
		
		if (TIMER0_CONFIG->TIMER0_CLK_SELECT >= TIMER0_CLOCK_SOURCE_NONE && TIMER0_CONFIG->TIMER0_CLK_SELECT <= TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE)
		{
			T0_TCCR0 |= TIMER0_CONFIG->TIMER0_CLK_SELECT;
			
			if(TIMER0_CONFIG->TIMER0_CLK_SELECT == TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE || TIMER0_CONFIG->TIMER0_CLK_SELECT == TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE)
			{
				ClearBit(DDRD, 0);						//SET PIN0 (T0) PORTD >> INPUT
			}
			STATUS = E_OK;
		}
		else
		{
			STATUS = E_NOK;
		}
		
		/*TIMER0 INTERRUPT SELECTION*/
		if (TIMER0_CONFIG->TIMER0_INTERRUPT == TIMER0_INTERRUPT_DISABLE)
		{
			T0_TIMSK |= TIMER0_INTERRUPT_DISABLE;
			STATUS = E_OK;
		}
		else if (TIMER0_CONFIG->TIMER0_INTERRUPT == TIMER0_INTERRUPT_ENABLE_OCIE0)
		{
			T0_TIMSK |= TIMER0_INTERRUPT_ENABLE_OCIE0;
			STATUS = E_OK;
		}
		else if (TIMER0_CONFIG->TIMER0_INTERRUPT == TIMER0_INTERRUPT_ENABLE_TOIE0)
		{
			T0_TIMSK |= TIMER0_INTERRUPT_ENABLE_TOIE0;
			STATUS = E_OK;
		}
		
	}
	return STATUS;
}

E_STATUS_t MCAL_TIMER0_DE_INIT(void)
{
	E_STATUS_t STATUS = E_OK;
	T0_TIMSK |= TIMER0_CLOCK_SOURCE_NONE;
	return STATUS; 
}

E_STATUS_t MCAL_TIMER0_Get_CompareValue  (Puint8_t Pu8_TICKS)
{
	E_STATUS_t STATUS = E_OK;
	*Pu8_TICKS = T0_OCR0;
	return STATUS;
}

E_STATUS_t MCAL_TIMER0_Set_CompareValue  (uint8_t  u8_TICKS)
{
	E_STATUS_t STATUS = E_OK;
	T0_OCR0 = u8_TICKS;
	return STATUS;
}

E_STATUS_t MCAL_TIMER0_Get_CounterValue  (Puint8_t Pu8_TICKS)
{
	E_STATUS_t STATUS = E_OK;
	*Pu8_TICKS = T0_TCNT0;
	return STATUS;
}

E_STATUS_t MCAL_TIMER0_Set_CounterValue  (uint8_t  u8_TICKS)
{
	E_STATUS_t STATUS = E_OK;
	T0_TCNT0 = u8_TICKS; 
	return STATUS;
}

E_STATUS_t MCAL_TIMER0_Get_OverFlowValue (Puint8_t Pu8_TICKS)
{
	E_STATUS_t STATUS = E_OK;
	*Pu8_TICKS = u8_T0_OVER_FLOW_Number;
	return STATUS;
}

E_STATUS_t MCAL_TIMER0_Set_OverFlowValue (uint8_t  u8_TICKS)
{
	E_STATUS_t STATUS = E_OK;	
	u8_T0_OVER_FLOW_Number = u8_TICKS;
	return STATUS;
}

E_STATUS_t MCAL_PWM_Duty_Cycle	 (uint8_t Duty_Cycle)
{
	E_STATUS_t STATUS = E_OK;
	
	if (TIMER0_CONFIG->TIMER0_MODE == TIMER0_MODE_FAST_PWM_INVERTING)
	{
		T0_OCR0 = (uint8_t)(255 - Duty_Cycle);	
	}
	else if(TIMER0_CONFIG->TIMER0_MODE == TIMER0_MODE_FAST_PWM_INVERTING)
	{
		T0_OCR0 = Duty_Cycle;
	}
	return STATUS;
}

void MCAL_TIMER0_Set_CallBack_OverFlow_Interrupt     (P_VoidFunVoid_t CALLBACK)
{
	CALLBACK_OVER_FLOW = CALLBACK;
}

void MCAL_TIMER0_Set_CallBack_CompareMatch_Interrupt (P_VoidFunVoid_t CALLBACK)
{
	CALLBACK_CompareMatch = CALLBACK;	
}

/* ================================================================ *
 * ===================== ISR FUNCTIONs ============================ *
 * ================================================================ */

ISR(TIMER0_COMP_vect)
{
	CALLBACK_CompareMatch();
}

ISR(TIMER0_OVF_vect)
{
	u8_T0_OVER_FLOW_Number++;
	CALLBACK_OVER_FLOW();
}