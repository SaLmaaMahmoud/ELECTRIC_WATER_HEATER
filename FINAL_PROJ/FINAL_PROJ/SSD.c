/*
 * SSD.c
 *
 * Created: 13/08/2021 02:39:44 AM
 *  Author: Salma
 */ 

#include "SSD.h"
#include "avr/delay.h"

#define F_CPU	8000000

extern u8 current_mode ;
extern u8 sensed_temp ;

static u8 counter = 0 ;

static u8 SSD_MODE = SSD_OFF ;

u8 ssd[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 } ;
	
void SSD_Init(void)
{
	GPIO_voidSetPortDirection(SSD_PORT , OUTPUT) ;	
	GPIO_voidSetPortPinDirection(SSD_EN_PORT , SSD1_EN_PIN , OUTPUT) ;	
	GPIO_voidSetPortPinDirection(SSD_EN_PORT , SSD1_EN_PIN , OUTPUT) ;
	
	SSD_TURN_OFF() ;
}

void SSD_TURN_OFF(void)
{
	GPIO_voidSetPortValue(SSD_PORT , 0x00) ;
	GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD1_EN_PIN , 0) ;
	GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD2_EN_PIN , 0) ;
}
/*
void SSD_TURN_ON(void)
{
	GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD1_EN_PIN , 1) ;
	GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD2_EN_PIN , 1) ;
}*/

void SSD_BLINK(void)
{
	if( current_mode == SETTING_MODE )
	{
		if (SSD_MODE == SSD_ON)
		{
			SSD_MODE = SSD_OFF ;
			SSD_TURN_OFF() ;
		}
		else if (SSD_MODE == SSD_OFF)
		{
			SSD_MODE = SSD_ON ;
			//SSD_TURN_ON() ;
		}
	}
}

void segment7_display(u8 temp)
{		
	counter++ ;
	u16 disp1 , disp2 ;
	
	disp1 = ssd[temp / 10] ;
	disp2 = ssd[temp % 10] ;
	
		if (counter == 1)
		{
			GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD1_EN_PIN , 0) ;
			GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD2_EN_PIN , 1) ;
			GPIO_voidSetPortValue(SSD_PORT , disp2) ;
		}
		else if (counter == 2)
		{
			GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD2_EN_PIN , 0) ;
			GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD1_EN_PIN , 1) ;
			GPIO_voidSetPortValue(SSD_PORT , disp1) ;
		}
		else if (counter == 3)
		{
			GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD2_EN_PIN , 0) ;
			GPIO_voidSetPortPinValue(SSD_EN_PORT , SSD1_EN_PIN , 0) ;
			counter = 0 ;
		}
}

void SSD_UPDATE(void)
{
	u16 tem = Get_Current_Temp() ;
	
	switch(current_mode)
	{
		case NORMAL_MODE :
			segment7_display( sensed_temp ) ;
			break;
		
		case SETTING_MODE :
			segment7_display( tem ) ;
			break;
		
		default:
			break;
	}
}
