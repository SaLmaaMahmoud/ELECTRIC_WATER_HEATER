/*
 * GPIO.h
 *
 * Created: 1/16/2021 2:17:14 AM
 *  Author: Salma
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "BITMATH.h"
#include "STD_TYPES.h"

	/* Registers Definition */

	/* PORTA Register*/
	#define  PINA_R       *( (volatile u8 *) (0x39) )
	#define  DDRA_R       *( (volatile u8 *) (0x3A) )
	#define  PORTA_R      *( (volatile u8 *) (0x3B) )

	/* PORTB Register*/
	#define  PINB_R       *( (volatile u8 *) (0x36) )
	#define  DDRB_R       *( (volatile u8 *) (0x37) )
	#define  PORTB_R      *( (volatile u8 *) (0x38) )
	
	/* PORTC Register*/
	#define  PINC_R      *( (volatile u8 *) (0x33) )
	#define  DDRC_R      *( (volatile u8 *) (0x34) )
	#define  PORTC_R     *( (volatile u8 *) (0x35) )
	
	/* PORTD Register*/
	#define  PIND_R      *( (volatile u8*) (0x30) )
	#define  DDRD_R      *( (volatile u8*) (0x31) )
	#define  PORTD_R     *( (volatile u8*) (0x32) )
	
	
	/* PORTS Macros */
	#define PORT_A		0
	#define PORT_B		1
	#define PORT_C		2
	#define PORT_D		3

	/* PINS Macros */
	#define PIN0	0
	#define PIN1	1
	#define PIN2	2
	#define PIN3	3
	#define PIN4	4
	#define PIN5	5
	#define PIN6	6
	#define PIN7	7
	
	/* Direction Macros */
	#define OUTPUT	1
	#define INPUT	0
	
	/******************** PUBPLIC FUNCTIONS ********************/
	
	/*Description : Setting PORT Direction
	  Parameters  : PORT(A>>D) , Direction(OUTPUT,INPUT)*/
	void GPIO_voidSetPortDirection (u8 cpy_PORT , u8 Dir);
	
	/*Description : Setting PIN Direction
	  Parameters  : PORT(A>>D) , PIN(0>>7) , Direction(OUTPUT,INPUT)*/
	void GPIO_voidSetPortPinDirection (u8 cpy_PORT , u8 cpy_PIN , u8 Dir);
	
	/*Description : Setting PIN Value
	  Parameters  : PORT(A>>D) , PIN(0>>7) , Value(1,0)*/
	void GPIO_voidSetPortPinValue (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_value);
	
	/*Description : Setting PORT Value
	  Parameters  : PORT(A>>D) , Value(1,0)*/
	void GPIO_voidSetPortValue(u8 cpy_PORT , u8 cpy_value);
	
	/*Description :  Toggle PIN Value
	  Parameters  :  PORT(A>>D) , PIN(0>>7)*/
	void GPIO_voidTogglePortPinValue (u8 cpy_PORT , u8 cpy_PIN);
	
	/*Description : Getting PIN Value
	  Parameters  : PORT(A>>D) , PIN(0>>7)*/
	u8 GPIO_u8GetPortPinValue(u8 cpy_PORT , u8 cpy_PIN);
	
	/*Description : Getting PORT Value
	  Parameters  : PORT(A>>D))*/
	u8 GPIO_u8GetPortValue(u8 cpy_PORT);


#endif /* GPIO_H_ */