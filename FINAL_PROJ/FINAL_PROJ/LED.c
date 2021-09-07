/*
 * LED.c
 *
 * Created: 13/08/2021 03:47:19 AM
 *  Author: Salma
 */ 

#include "LED.h"


void LED_Init(void)
{
	GPIO_voidSetPortPinDirection(LED_PORT , LED_PIN , LED_DIRECTION) ;
	
	//Turn OFF the led as the initial state
	LED_OFF() ;
}

void LED_ON(void)
{
	GPIO_voidSetPortPinValue(LED_PORT , LED_PIN , 1) ;
}

void LED_OFF(void)
{
	GPIO_voidSetPortPinValue(LED_PORT , LED_PIN , 0) ;
}

void LED_Blink(void)
{
	GPIO_voidTogglePortPinValue(LED_PORT , LED_PIN) ;
}
