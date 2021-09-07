/*
 * SSD.h
 *
 * Created: 13/08/2021 02:39:56 AM
 *  Author: Salma
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "BITMATH.h"
#include "STD_TYPES.h"
#include "GPIO.h"
#include "port.h"
#include "Electric_heater_control.h"
#include "SW.h"
#include "LM35.h"


#include <util/delay.h>

typedef enum
{
	SSD_ON,
	SSD_OFF,
} SSD_MODES ;

/******************** PUBPLIC FUNCTIONS ********************/

/*Description : Initialize the SSD
  Parameters  : void
  Return      : None */
void SSD_Init(void) ;

/*Description : Turn OFF the SSD
  Parameters  : void
  Return      : None */
void SSD_TURN_OFF(void) ;

//void SSD_TURN_ON(void) ;

/*Description : Blink the SSD
  Parameters  : void
  Return      : None */
void SSD_BLINK(void) ;

/*Description : Display the current or set temperature
  Parameters  : the temperature -> u8 temp
  Return      : None */
void segment7_display(u8 temp) ;

/*Description : Update the SSD
  Parameters  : void
  Return      : None */
void SSD_UPDATE(void) ;

#endif /* SSD_H_ */