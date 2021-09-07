/*
 * cooling_fan.c
 *
 * Created: 21/08/2021 01:20:38 AM
 *  Author: Salma
 */ 

#include "cooling_fan.h"

void cooling_Init(void)
{
	GPIO_voidSetPortPinDirection(COOLING_PORT , COOLING_PIN , COOLING_DIR) ;
}

void cooling_set_state(u8 state)
{
	switch (state)
	{
		case cool_ON :
			GPIO_voidSetPortPinValue(COOLING_PORT , COOLING_PIN , 1) ;
			break;
			
		case cool_OFF :
			GPIO_voidSetPortPinValue(COOLING_PORT , COOLING_PIN , 0) ;
			break;
		
		default:
			break;
	}
}

u8 cooling_get_state (void)
{
	u8 st = GPIO_u8GetPortPinValue(COOLING_PORT , COOLING_PIN) ;
	
	return st ;
}