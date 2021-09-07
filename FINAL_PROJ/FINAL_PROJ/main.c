/*
 * main.c
 *
 * Created: 8/31/2021 3:13:43 AM
 *  Author: Salma
 */ 

#include "main.h"

u8 sensed_temp ;
u8 current_mode = NORMAL_MODE ;
u8 current_state ;



int main(void)
{
	current_state = HEATER_OFF ;

	LED_Init() ;
	SW_Init() ;
	SSD_Init() ;
	LM35_Init() ;
	EEPROM_Init() ;
	cooling_Init() ;
	heating_Init() ;
	
	
	
	EXT_voidEnableExtInt(EXT_INT_2 , FALLIN_EDGE) ;
	
	SCH_Init_T1() ;
	
	SCH_Add_Task(SW_ST , 0 , SW_PERIOD) ;
	SCH_Add_Task(LM35_Read_Temp , 0 , TEMPERATURE_period) ;
	SCH_Add_Task(Heat_Cool_Elements , 0 , SYSTEM_PERIOD) ;
	SCH_Add_Task(SSD_UPDATE , 0 , SYSTEM_PERIOD) ;
	SCH_Add_Task(SSD_BLINK , 0 , SSD_BLINK_PERIOD) ;
	
	Save_Last_Temp() ;

	while(1)
    {
		SCH_Dispatch_Tasks() ;
    }
}

ISR(INT2_vect)
{
	switch( current_state )
	{
		case HEATER_OFF :
			current_state = HEATER_ON ;
			SCH_Start() ;
			break;
		
		case HEATER_ON :
			current_state = HEATER_OFF ;
			OFF_STATE() ;
	}
}
