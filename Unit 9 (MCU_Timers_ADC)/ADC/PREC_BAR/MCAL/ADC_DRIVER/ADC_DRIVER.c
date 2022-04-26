/*
 * ADC_DRIVER.c
 *
 * Created: 24/04/2022 02:32:31
 *  Author: AMR AHMED
 */ 
#include "ADC_DRIVER.h"


void ADC_INIT(ADC_V_REF_type V_REF, ADC_SCALER_type SCALER)
{
	//CHOOSE V_REFERENCE
	switch(V_REF)
	{
		case VREF_AREF:
		ClearBit(ADMUX, REFS0);
		ClearBit(ADMUX, REFS1);
		break;
		
		case VREF_AVCC:
		SetBit  (ADMUX, REFS0);
		ClearBit(ADMUX, REFS1);
		break;
		
		case VREF_256:
		SetBit(ADMUX, REFS0);
		SetBit(ADMUX, REFS1);
		break;
	}
	
	 //PRESCALLER SELECTION
	 
	 ADCSRA &= 0xF8;
	 ADCSRA |= SCALER;
	 
	 //ENABLE ADC
	 SetBit(ADCSRA, ADEN);
}

uint16_t ADC_READ(ADC_CHANNEL_type CHANNEL)
{
	//SELECT CHANNEL
	ADMUX &= 0xE0;
	ADMUX |= CHANNEL;
	
	//START CONVERSION
	SetBit(ADCSRA, ADSC); 
	while(ReadBit(ADCSRA, ADSC));
	
	return	ADC;  //ADCH, ADCL REGISTERS
}