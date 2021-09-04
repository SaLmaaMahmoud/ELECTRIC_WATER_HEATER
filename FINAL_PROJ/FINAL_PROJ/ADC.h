/*
 * ADC.h
 *
 * Created: 2/6/2021 1:29:28 AM
 *  Author: Salma
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"

	#define V_REF			5
	
	/********************  Registers Definition ********************/
	#define AD_MUX		ADMUX
	#define ADC_SRA		ADCSRA
	#define ADC_H		ADCH
	#define ADC_L		ADCH
	
	#define ADC_		ADC

	#define SFIOR_		SFIOR
	/**************************************************************/

	/************************ PINS Macros ************************/
	/* ADMUX PINS */
	#define REFS1			7
	#define REFS0			6
	#define ADLAR			5
	#define ADMUX_ch0		0b11100000
	
	/* ADCSRA PINS */
	#define ADEN			7
	#define ADSC			6
	#define ADATE			5
	#define ADIF			4
	#define ADIE			3
	#define ADCSRA_Rst_P	0b11111000
	/*************************************************************/

	/************************* FUNCTIONS *************************/
	void ADC_voidInit(void) ;
	void ADC_u16SelectChannel(u8 channel) ;
	u16 ADC_u16GetData() ;
	u32 ADC_u32GetVolatage(void) ;
	void ADC_StartConversion(void) ;

#endif /* ADC_H_ */