/*
 * LM35.c
 *
 * Created: 13/08/2021 03:47:56 AM
 *  Author: Salma
 */


#include "LM35.h"

extern u8 current_mode ;

/* Array to hold the last 10 Readings */
static u16 Temp_Reading_array[TEMPERATURE_N_READING] ;

/* Counter for LM35_Read_Temp function */
static u8 i ;

extern u8 set_temp ;

extern u8 sensed_temp ;

void LM35_Init(void)
{
	GPIO_voidSetPortPinDirection(LM35_PORT , LM35_PIN , LM35_DIR) ;
	ADC_voidInit() ;
	ADC_u16SelectChannel(LM35_ADC_CH) ;
	ADC_StartConversion() ;
}


u8 LM35_Temp_Avg(void){
	
    u8 INDEX = 0 ; 
    u16 sum = 0 ;
	u16 avg = 0 ;
	
    for (INDEX=0 ; INDEX<TEMPERATURE_N_READING ; INDEX++){
        sum = sum + Temp_Reading_array[INDEX] ;
    }
	
    avg = (sum / TEMPERATURE_N_READING) ;
	
	return avg ;
}

void LM35_Read_Temp(void)
{	
	ADC_StartConversion() ;
	
	if ( current_mode == NORMAL_MODE )
	{
		Temp_Reading_array[i] = (ADC_u16GetData() / 2) - 2 ;
		
		i++ ;
		
		if ( i == TEMPERATURE_N_READING)
		{
			i = 0 ;
			sensed_temp = LM35_Temp_Avg() ;
		}
	}
}

void Save_Last_Temp(void)
{
	EEPROM_Write(sensed_temp , ADDRESS) ;
}


