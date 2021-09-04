/*
 * SW.h
 *
 * Created: 13/08/2021 03:54:07 AM
 *  Author: Salma
 */ 


#ifndef SW_H_
#define SW_H_

#include "BITMATH.h"
#include "STD_TYPES.h"
#include "GPIO.h"
#include "port.h"
#include "EEPROM.h"
#include "IIC.h"
#include "LM35.h"
#include "SSD.h"
#include "Electric_heater_control.h"

#define PUSHED_VOLTAGE		0
#define RELEASED_VOLTAGE	1

typedef enum
{
	UP_SW = 0,
	DOWN_SW,
	ON_OFF_SW,
}	SW ;


/******************** PUBPLIC FUNCTIONS ********************/

/*Description : Initialize the switches(UP_SW , DOWN_SW , ON_OFF_SW)
  Parameters  : void
  Return      : None */
void SW_Init(void) ;

/*Description : Update the switches(UP_SW , DOWN_SW)
  Parameters  : void
  Return      : None */
void SW_ST(void) ;

/*Description : Update the Heating and cooling elements
  Parameters  : void
  Return      : None */
void Heat_Cool_Elements(void) ;

/*Description : Get the current temp
  Parameters  : void
  Return      : the current temp -> u8 */
u8 Get_Current_Temp(void) ;


#endif /* SW_H_ */