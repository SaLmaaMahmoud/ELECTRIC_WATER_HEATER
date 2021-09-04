/*
 * GPIO.c
 *
 * Created: 1/16/2021 2:16:45 AM
 *  Author: Salma
 */ 


#include "GPIO.h"

void GPIO_voidSetPortDirection (u8 cpy_PORT , u8 Dir)
{
	switch( cpy_PORT ){
		case PORT_A :
			if(Dir == OUTPUT)
				DDRA_R = 0xFF ;
			else if (Dir == INPUT)
				DDRA_R = 0x00 ;
			break;
		
		case PORT_B :
			if(Dir == OUTPUT)
				DDRB_R = 0xFF ;
			else if (Dir == INPUT)
				DDRB_R = 0x00 ;
			break;
			
		case PORT_C :
			if(Dir == OUTPUT)
				DDRC_R = 0xFF ;
			else if (Dir == INPUT)
				DDRC_R = 0x00 ;
			break;
			
		case PORT_D :
			if(Dir == OUTPUT)
				DDRD_R = 0xFF ;
			else if (Dir == INPUT)
				DDRD_R = 0x00 ;
			break;
			
		default: break;
	}
}

void GPIO_voidSetPortPinDirection (u8 cpy_PORT , u8 cpy_PIN , u8 Dir)
{
	switch( cpy_PORT ){
		case PORT_A :
			if ( Dir == OUTPUT )
				SET_BIT(DDRA_R , cpy_PIN) ;
			else if ( Dir == INPUT )
				CLEAR_BIT(DDRA_R , cpy_PIN) ;
			break;
			
		case PORT_B :
			if ( Dir == OUTPUT )
				SET_BIT(DDRB_R , cpy_PIN) ;
			else if ( Dir == INPUT )
				CLEAR_BIT(DDRB_R , cpy_PIN) ;
			break;
			
		case PORT_C :
			if ( Dir == OUTPUT )
				SET_BIT(DDRC_R , cpy_PIN) ;
			else if ( Dir == INPUT )
				CLEAR_BIT(DDRC_R , cpy_PIN) ;
			break;
			
		case PORT_D :
			if ( Dir == OUTPUT )
				SET_BIT(DDRD_R , cpy_PIN) ;
			else if ( Dir == INPUT )
				CLEAR_BIT(DDRD_R , cpy_PIN) ;
			break;
			
		default: break;
	}
}

void GPIO_voidSetPortPinValue (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_value)
{
	switch( cpy_PORT ){
		case PORT_A :
			if ( cpy_value == 1 )
				SET_BIT(PORTA_R , cpy_PIN) ;
			else if ( cpy_value == 0 )
				CLEAR_BIT(PORTA_R , cpy_PIN) ;
			break;
			
		case PORT_B :
			if ( cpy_value == 1 )
				SET_BIT(PORTB_R , cpy_PIN) ;
			else if ( cpy_value == 0 )
				CLEAR_BIT(PORTB_R , cpy_PIN) ;
			break;
			
		case PORT_C :
			if ( cpy_value == 1 )
				SET_BIT(PORTC_R , cpy_PIN) ;
			else if ( cpy_value == 0 )
				CLEAR_BIT(PORTC_R , cpy_PIN) ;
			break;
			
		case PORT_D :
			if ( cpy_value == 1 )
				SET_BIT(PORTD_R , cpy_PIN) ;
			else if ( cpy_value == 0 )
				CLEAR_BIT(PORTD_R , cpy_PIN) ;
			break;
			
		default: break;
	}
}

void GPIO_voidSetPortValue(u8 cpy_PORT , u8 cpy_value)
{
	switch( cpy_PORT ){
		case PORT_A :
			PORTA_R = cpy_value ;
			break;
		
		case PORT_B :
			PORTB_R = cpy_value ;
			break;
			
		case PORT_C :
			PORTC_R = cpy_value ;
			break;
			
		case PORT_D :
			PORTD_R = cpy_value ;
			break;
		
		default: break;
	}
}

void GPIO_voidTogglePortPinValue (u8 cpy_PORT , u8 cpy_PIN)
{
	switch ( cpy_PORT ){
		case PORT_A :
			TOGGLE_BIT(PORTA_R , cpy_PIN) ;
			break;
			
		case PORT_B :
			TOGGLE_BIT(PORTB_R , cpy_PIN) ;
			break;
		
		case PORT_C :
			TOGGLE_BIT(PORTC_R , cpy_PIN) ;
			break;
		
		case PORT_D :
			TOGGLE_BIT(PORTD_R , cpy_PIN) ;
			break;
	}
}


u8 GPIO_u8GetPortPinValue(u8 cpy_PORT , u8 cpy_PIN)
{
	u8 local_u8retval = 0 ;
	
	switch ( cpy_PORT ){
		case PORT_A :
			local_u8retval = GIT_BIT(PINA_R , cpy_PIN) ;
			break;
		
		case PORT_B :
			local_u8retval = GIT_BIT(PINB_R , cpy_PIN) ;
			break;
		
		case PORT_C :
			local_u8retval = GIT_BIT(PINC_R , cpy_PIN) ;
			break;
		
		case PORT_D :
			local_u8retval = GIT_BIT(PIND_R , cpy_PIN) ;
			break;
			
		default: break;
	}
	
	return local_u8retval ;
}

u8 GPIO_u8GetPortValue(u8 cpy_PORT)
{
	u8 local_u8retval = 0 ;
	
	switch ( cpy_PORT ){
		case PORT_A :
			local_u8retval = PINA_R ;
			break;
		
		case PORT_B :
			local_u8retval = PINB_R ;
			break;
			
		case PORT_C :
			local_u8retval = PINC_R ;
			break;
			
		case PORT_D :
			local_u8retval = PIND_R ;
			break;
			
		default: break;
	}
	
	return local_u8retval ;
}