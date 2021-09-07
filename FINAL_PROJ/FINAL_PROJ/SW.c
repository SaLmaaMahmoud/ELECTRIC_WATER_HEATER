/*
 * SW.c
 *
 * Created: 13/08/2021 03:53:51 AM
 *  Author: Salma
 */ 

#include "SW.h"


extern u8 current_mode ;

static u16 setting_state_flag = 0 ;
static u8 set_temp ;

extern u8 sensed_temp ;

void SW_Init(void)
{		
	GPIO_voidSetPortPinDirection(UP_PORT , UP_PIN , UP_DIR) ;
	GPIO_voidSetPortPinDirection(DOWN_PORT , DOWN_PIN , DOWN_DIR) ;
	GPIO_voidSetPortPinDirection(ON_OFF_PORT , ON_OFF_PIN , ON_OFF_PIN) ;
	
	GPIO_voidSetPortPinValue(UP_PORT , UP_PIN , 1) ;
	GPIO_voidSetPortPinValue(DOWN_PORT , DOWN_PIN , 1) ;

	current_mode = NORMAL_MODE ;
	set_temp = INITIAL_TEMP ;
	
	Save_Last_Temp() ;
}

void Heat_Cool_Elements(void)
{
	if ( current_mode == NORMAL_MODE )
	{
		if ( sensed_temp < (set_temp - TEMP_CHANGE) )
		{
			heating_set_state(heat_ON) ;
			cooling_set_state(cool_OFF) ;
			LED_Blink() ;
		}
		else if ( sensed_temp > (set_temp + TEMP_CHANGE) )
		{
			heating_set_state(heat_OFF) ;
			cooling_set_state(cool_ON) ;
			LED_ON() ;
		}
		else
		{
			heating_set_state(heat_OFF) ;
			cooling_set_state(cool_OFF) ;
			LED_OFF() ;
		}
	}
	else
	{
		heating_set_state(heat_OFF) ;
		cooling_set_state(cool_OFF) ;
		LED_OFF() ;
	}
}

u8 Get_Current_Temp(void)
{
	return set_temp ;
}

void SW_ST(void)
{
	switch ( current_mode )
	{
		case NORMAL_MODE :
			setting_state_flag = 0 ;
			segment7_display(sensed_temp) ;
			if ( (GPIO_u8GetPortValue(UP_PORT) == 0b00010000) || (GPIO_u8GetPortValue(DOWN_PORT) == 0b00001000) )
			{
				current_mode = SETTING_MODE ;
				cooling_set_state(cool_OFF) ;
				heating_set_state(heat_OFF) ;
			}
			break;
		
		case SETTING_MODE :
		{
			segment7_display(set_temp) ;
			
			if ( setting_state_flag < 500 )
			{
				if ( (set_temp < MAX_TEMP) && (GPIO_u8GetPortValue(UP_PORT) == 0b00001000) )
				{
					set_temp += TEMP_CHANGE ;
					setting_state_flag = 0 ;
				}
				else if ( (set_temp > MIN_TEMP) && (GPIO_u8GetPortValue(DOWN_PORT) == 0b00010000) )
				{
					set_temp -= TEMP_CHANGE ;
					setting_state_flag = 0 ;
				}
				else
				{
					setting_state_flag += 20 ;
				}
			}
			else
			{
				current_mode = NORMAL_MODE ;
				setting_state_flag = 0 ;
				Save_Last_Temp() ;
				segment7_display(sensed_temp) ;
			}
		}
		break;
		
		default:
		break;
	}
}