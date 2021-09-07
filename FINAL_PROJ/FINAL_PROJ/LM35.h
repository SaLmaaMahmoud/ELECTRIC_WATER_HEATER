/*
 * LM35.h
 *
 * Created: 13/08/2021 03:48:09 AM
 *  Author: Salma
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"
#include "port.h"
#include "EEPROM.h"
#include "Electric_heater_control.h"
#include "GPIO.h"
#include "LED.h"
#include "STD_TYPES.h"

#define INITIAL_TEMP	60
#define MIN_TEMP		35
#define MAX_TEMP		75
#define TEMP_CHANGE		5

/* LM35 ADC CHANNEL */
#define LM35_ADC_CH		1

/* The last 10 Temp Reading */
#define TEMPERATURE_N_READING	(10)


/******************** PUBPLIC FUNCTIONS ********************/

/*Description : Initialize the temperature sensor LM35
  Parameters  : void
  Return      : None */
void LM35_Init(void) ;

/*Description : Determine the average of the last 10 readings
  Parameters  : void
  Return      : 8-bit */
u8 LM35_Temp_Avg(void) ;

/*Description : Read the current temp
  Parameters  : void
  Return      : None */
void LM35_Read_Temp(void) ;

/*Description : Update the current temp and avg
  Parameters  : void
  Return      : None */
void Update_Temp(void) ;

/*Description : Save the last read temp in the external EEPROM
  Parameters  : void
  Return      : None */
void Save_Last_Temp(void) ;

//void Heat_Cool_Elements(void) ;

//u8 Get_Current_Temp(void) ;


#endif /* LM35_H_ */