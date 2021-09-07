/*
 * main.h
 *
 * Created: 28/08/2021 04:17:30 AM
 *  Author: Salma
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "BITMATH.h"
#include "GPIO.h"
#include "LED.h"
#include "scheduler.h"
#include "ADC.h"
#include "LM35.h"
#include "SSD.h"
#include "SW.h"
#include "IIC.h"
#include "EEPROM.h"
#include "EXT_INT.h"
#include "TMR.h"

#include <util/delay.h>

typedef	enum
{
	HEATER_OFF=0,
	HEATER_ON,
}	HEATER_STATE ;

/* The Switches should be updated once every 20ms */
#define SW_PERIOD				(20)
/* The system should be updated once every 20ms */
#define SYSTEM_PERIOD				(20)
/* The SSD should blink every 1s in Setting mode */
#define SSD_BLINK_PERIOD      			(100)
/* Temperature should be sensed once every 100ms */
#define TEMPERATURE_period			(100)


#endif /* MAIN_H_ */
