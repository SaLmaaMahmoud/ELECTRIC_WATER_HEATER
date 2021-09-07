/*
 * port.h
 *
 * Created: 21/08/2021 01:26:11 AM
 *  Author: Salma
 */ 


#ifndef PORT_H_
#define PORT_H_

#include <avr/interrupt.h>
//#include <util/delay.h>

#define F_CPU		8000000		//The crystal oscillator frequency

/* PUSHBUTTONS */
#define UP_DIR			INPUT
#define UP_PORT			PORT_B
#define UP_PIN			PIN3

#define DOWN_DIR		INPUT
#define DOWN_PORT		PORT_B
#define DOWN_PIN		PIN4

#define ON_OFF_DIR		INPUT
#define ON_OFF_PORT		PORT_B
#define ON_OFF_PIN		PIN2

/* LM35 */
#define LM35_DIR		INPUT
#define LM35_PORT		PORT_A
#define LM35_PIN		PIN1

/* COOLING ELEMENT */
#define COOLING_DIR		OUTPUT
#define COOLING_PORT		PORT_C
#define COOLING_PIN		PIN7

/* HEATING ELEMENT */
#define HEATING_DIR		OUTPUT
#define HEATING_PORT		PORT_C
#define HEATING_PIN		PIN6

/* LED CONFIGURATION */
#define LED_DIRECTION		OUTPUT
#define LED_PORT		PORT_C
#define LED_PIN			PIN5
/***********************/

/* 7-SEGMENT */
#define SSD_DIRECTION		OUTPUT
#define SSD_PORT		PORT_D
#define SSD_EN_PORT		PORT_C
#define SSD1_EN_PIN		PIN3
#define SSD2_EN_PIN		PIN4			
/***********************/

#endif /* PORT_H_ */
