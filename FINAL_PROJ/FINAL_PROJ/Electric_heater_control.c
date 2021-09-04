/*
 * Electric_heater_control.c
 *
 * Created: 17/08/2021 02:38:22 AM
 *  Author: Salma
 */ 

#include "Electric_heater_control.h"
/*
extern u8 set_temp ;

//static u8 setting_mode_flag = 0 ;
static u8 FIRST_CLICK ;
extern HEATER_STATE current_state ;
extern SYSTEM_MODE current_mode ;


void Heater_Init(void)
{
	EEPROM_Init() ;
	
	SW_Init() ;
	
	cooling_Init() ;
	heating_Init() ;
	
	//LM35_Init() ;
	
	current_mode = NORMAL_MODE ;
	current_state = HEATER_OFF ;
	
	Save_Last_Temp() ;
}
*/
void OFF_STATE(void)
{
	cooling_set_state(cool_OFF) ;
	heating_set_state(heat_OFF) ;
	SSD_TURN_OFF() ;
	LED_OFF() ;
	//SCH_Go_To_Sleep() ;
}

/*
void Update_heater(void)
{
	SW_Update_UP_SW() ;
	
	if(current_state == HEATER_ON)
	{
		if ( FIRST_CLICK == 0 )
		{
			if ( (SW_GET_STATE(UP_SW) == PRE_RELEASED) || (SW_GET_STATE(DOWN_SW) == PRE_RELEASED) )
			{
				current_mode = SETTING_MODE ;
				set_temp = EEPROM_Read(ADDRESS) ;
				FIRST_CLICK = 1 ;
			}
			else
			{
				current_mode = NORMAL_MODE ;
				FIRST_CLICK = 0 ;
			}
		}
	}
	
	switch ( current_mode )
	{
		case NORMAL_MODE :
			FIRST_CLICK = 0 ;
			break;
			
		case SETTING_MODE :
			if ( FIRST_CLICK == 1 )
			{
				if (SW_GET_STATE(UP_SW) == PRE_RELEASED)
				{
					Setting_Mode(UP_SW) ;
				}
				else if (SW_GET_STATE(DOWN_SW) == PRE_RELEASED)
				{
					Setting_Mode(DOWN_SW) ;
				}
			}
			break;
		
		default:
			break;
	}
}


*/