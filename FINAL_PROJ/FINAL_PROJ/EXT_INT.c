/*
 * EXT_INT.c
 *
 * Created: 1/25/2021 2:22:44 AM
 *  Author: Salma
 */ 

#include <avr/interrupt.h>

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"
#include "EXT_INT.h"


void EXT_voidEnableExtInt(t_EXT_INT cpy_ext_int , t_TRIGGERING_CONDITION cpy_condition) 
{
	// Enable global interrupts
	sei() ;
	
	// Enable EXT INT
	switch (cpy_ext_int){
		case EXT_INT_0 :
			SET_BIT(GICR_R , 6) ;
			break;
			
		case EXT_INT_1 :
			SET_BIT(GICR_R , 7) ;
			break;
			
		case EXT_INT_2 :
			SET_BIT(GICR_R , 5) ;
			break;
	}
	
	// Sensing level
	switch (cpy_condition){
		case LOW_LEVEL :
			if (cpy_ext_int == EXT_INT_0)
			{
				CLEAR_BIT(MCUCR_R , ISC00) ;
				CLEAR_BIT(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				CLEAR_BIT(MCUCR_R , ISC10) ;
				CLEAR_BIT(MCUCR_R , ISC11) ;
			}
			break;
			
		case ON_CHAGE :
			if (cpy_ext_int == EXT_INT_0)
			{
				SET_BIT(MCUCR_R , ISC00) ;
				CLEAR_BIT(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				SET_BIT(MCUCR_R , ISC10) ;
				CLEAR_BIT(MCUCR_R , ISC11) ;
			}
			break;
		
		case FALLIN_EDGE :
			if (cpy_ext_int == EXT_INT_0)
			{
				CLEAR_BIT(MCUCR_R , ISC00) ;
				SET_BIT(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				CLEAR_BIT(MCUCR_R , ISC10) ;
				SET_BIT(MCUCR_R , ISC11) ;
			}
			if (cpy_ext_int == EXT_INT_2)
				CLEAR_BIT(MCUCSR_R , MCUCSR_ISC2) ;
			break;
		
		case RISIN_EDGE :
			if (cpy_ext_int == EXT_INT_0)
			{
				SET_BIT(MCUCR_R , ISC00) ;
				SET_BIT(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				SET_BIT(MCUCR_R , ISC10) ;
				SET_BIT(MCUCR_R , ISC11) ;
			}
			if (cpy_ext_int == EXT_INT_2)
				SET_BIT(MCUCSR_R , MCUCSR_ISC2) ;
			break;
	}
	
}

void EXT_voidDisableExtInt(t_EXT_INT cpy_ext_int) 
{
	// Disable EXT INT 
	CLEAR_BIT(cpy_ext_int , 5) ;
}


