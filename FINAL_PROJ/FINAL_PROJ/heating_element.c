/*
 * heating_element.c
 *
 * Created: 21/08/2021 02:20:41 AM
 *  Author: Salma
 */ 

#include "heating_element.h"

void heating_Init(void)
{
	GPIO_voidSetPortPinDirection(HEATING_PORT , HEATING_PIN , HEATING_DIR) ;
}

void heating_set_state(u8 state)
{
	switch (state)
	{
		case heat_ON :
		GPIO_voidSetPortPinValue(HEATING_PORT , HEATING_PIN , 1) ;
		break;
		
		case heat_OFF :
		GPIO_voidSetPortPinValue(HEATING_PORT , HEATING_PIN , 0) ;
		break;
		
		default:
		break;
	}
}

u8 heating_get_state (void)
{
	u8 st = GPIO_u8GetPortPinValue(HEATING_PORT , HEATING_PIN) ;
	
	return st ;
}