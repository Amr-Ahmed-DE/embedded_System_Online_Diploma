/*
 * ADC_DRIVER.h
 *
 * Created: 24/04/2022 02:32:16
 *  Author: AMR AHMED
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <avr/io.h>
#include "../../SERVICE/ATMEGA32_MEMORY_MAP.h"
#include "../../SERVICE/Types.h"
#include "../../SERVICE/UTILS.h"


#define VOLT_REFERENCE	5000
#define RESOLUTION		1024	

typedef enum
{
	VREF_AREF,
	VREF_AVCC,  //INTERNAL VCC
	VREF_256,
}ADC_V_REF_type;

//ADC SCALER - ADC SPEED
typedef enum 
{
	ADC_SCALER_2 = 0,
	ADC_SCALER_4 = 2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_SCALER_type;

//ADC CHANNEL/PIN
typedef enum
{
	ADC_CH_0 = 0,
	ADC_CH_1,
	ADC_CH_2,
	ADC_CH_3,
	ADC_CH_4,
	ADC_CH_5,
	ADC_CH_6,
	ADC_CH_7,
}ADC_CHANNEL_type;

void ADC_INIT(ADC_V_REF_type V_REF, ADC_SCALER_type SCALER);
 
uint16_t ADC_READ(ADC_CHANNEL_type CHANNEL);

#endif /* ADC_DRIVER_H_ */