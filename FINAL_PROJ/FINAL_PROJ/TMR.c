/*
 * TMR.c
 *
 * Created: 2/2/2021 4:33:50 PM
 *  Author: Salma
 */ 

#include <avr/interrupt.h>

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"
#include "TMR.h"


//Timer 0
void TMR_voidInitTimer0(prescallar pres , Interrupt_State interupt , Modes Mode)
{
	CLEAR_BIT(TCCR_0 , CS00) ;
	CLEAR_BIT(TCCR_0 , CS01) ;
	CLEAR_BIT(TCCR_0 , CS02) ;
	
	CLEAR_BIT(TCCR_0 , WGM00) ;
	CLEAR_BIT(TCCR_0 , WGM01) ;
	
	if (Mode == CTC)
	{
		SET_BIT(TCCR_0 , 3) ;
	}

	if (interupt == Enable){
			SET_BIT(TIMSK_ , TIMSK_TOIE0) ;			//Enable Timer interrupt
	}
	
		switch ( pres ){
			case prescallar_1 :
				SET_BIT(TCCR_0 , CS00) ;
				break;
				
			case prescallar_8 :
				SET_BIT(TCCR_0 , CS01) ;
				break;
				
			case prescallar_64 :
				SET_BIT(TCCR_0 , CS00) ;
				SET_BIT(TCCR_0 , CS01) ;
				break;
			
			case prescallar_256 :
				SET_BIT(TCCR_0 , CS02) ;
				break;
				
			case prescallar_1024 :
				SET_BIT(TCCR_0 , CS00) ;
				SET_BIT(TCCR_0 , CS02) ;
				break;
				
			case prescallar_FallinEdge :
				SET_BIT(TCCR_0 , CS01) ;
				SET_BIT(TCCR_0 , CS02) ;
				break;
				
			case prescallar_RisinEdge :
				SET_BIT(TCCR_0 , CS00) ;
				SET_BIT(TCCR_0 , CS01) ;
				SET_BIT(TCCR_0 , CS02) ;
				break;
				
			default:
				break;
		}
		
}

void TMR_voidSetTimer0Count(u8 value)
{
	TCNT_0 = value ;
}

u8 TMR_u16GetTimer0Count(void){	u8 value = TCNT_0 ;		return value ;}//Timer 1
void TMR_voidInitTimer1(prescallar pres , Interrupt_State interupt , Modes Mode)
{	
	CLEAR_BIT(TCCR_1B , CS10) ;
	CLEAR_BIT(TCCR_1B , CS11) ;
	CLEAR_BIT(TCCR_1B , CS12) ;
	
	u8 flag = -1 ;
	
	switch ( Mode )
	{
		case Normal :
			flag = 1 ;
			break;
		case PWM :
			SET_BIT(TCCR_1A , WGM10) ;
			SET_BIT(TCCR_1A , WGM11) ;
			flag = 2 ;
			break;
		case CTC :
			SET_BIT(TCCR_1B , WGM12) ;
			break;
		case Fast_PWM :
			SET_BIT(TCCR_1A , WGM11) ;
			break;
		default:
			break;
	}
	
	if ((interupt == Enable) && (Mode != CTC))
	{
		SET_BIT(TIMSK_ , TIMSK_TOIE1) ;			//Enable Timer interrupt
	}
	else if ((interupt == Enable) && (Mode == CTC))
	{
		SET_BIT(TIMSK_ , TIMSK_OCIE1A) ;
	}
	
	switch ( pres ){
		case prescallar_1 :
			SET_BIT(TCCR_1B , CS10) ;
			break;
		
		case prescallar_8 :
			SET_BIT(TCCR_1B , CS11) ;
			break;
		
		case prescallar_64 :
			SET_BIT(TCCR_1B , CS10) ;
			SET_BIT(TCCR_1B , CS11) ;
			break;
		
		case prescallar_256 :
			SET_BIT(TCCR_1B , CS12) ;
			break;
		
		case prescallar_1024 :
			SET_BIT(TCCR_1B , CS10) ;
			SET_BIT(TCCR_1B , CS12) ;
			break;
		
		case prescallar_FallinEdge :
			SET_BIT(TCCR_1B , CS11) ;
			SET_BIT(TCCR_1B , CS12) ;
			break;
		
		case prescallar_RisinEdge :
			SET_BIT(TCCR_1B , CS10) ;
			SET_BIT(TCCR_1B , CS11) ;
			SET_BIT(TCCR_1B , CS12) ;
			break;
		
		default:
			break;
	}
	
}

void TMR_voidSetTimer1Count(u8 value)
{
	TCNT_1 = value ;
}

u8 TMR_u16GetTimer1Count(void){	u8 value = TCNT_1 ;		return value ;}//Timer 2
void TMR_voidInitTimer2(prescallar pres , Interrupt_State interupt , Modes Mode)
{
	CLEAR_BIT(TCCR_2 , CS20) ;
	CLEAR_BIT(TCCR_2 , CS21) ;
	CLEAR_BIT(TCCR_2 , CS22) ;
	
	CLEAR_BIT(TCCR_2 , WGM20) ;
	CLEAR_BIT(TCCR_2 , WGM21) ;
	
	switch ( Mode ) 
	{
		case Normal : 
			break;
		case PWM : 
			SET_BIT(TCCR_2 , WGM20) ;
			break;
		case CTC :
			SET_BIT(TCCR_2 , WGM21) ;
			break;
		case Fast_PWM :
			SET_BIT(TCCR_2 , WGM20) ;
			SET_BIT(TCCR_2 , WGM21) ;
			break;
		default:
			break;
	}
	
	switch ( pres ){
		case prescallar_1 :
			SET_BIT(TCCR_2 , CS20) ;
			break;
		
		case prescallar_8 :
			SET_BIT(TCCR_2 , CS21) ;
			break;
		
		case prescallar_64 :
			SET_BIT(TCCR_2 , CS20) ;
			SET_BIT(TCCR_2 , CS21) ;
			break;
		
		case prescallar_256 :
			SET_BIT(TCCR_2 , CS22) ;
			break;
		
		case prescallar_1024 :
			SET_BIT(TCCR_2 , CS20) ;
			SET_BIT(TCCR_2 , CS22) ;
			break;
		
		case prescallar_FallinEdge :
			SET_BIT(TCCR_2 , CS21) ;
			SET_BIT(TCCR_2 , CS22) ;
			break;
		
		case prescallar_RisinEdge :
			SET_BIT(TCCR_2 , CS20) ;
			SET_BIT(TCCR_2 , CS21) ;
			SET_BIT(TCCR_2 , CS22) ;
			break;
		
		default:
			break;
	}
	
	sei() ;
	
	switch ( interupt ){
		case Enable :
			if ( Mode == CTC ){
				SET_BIT(TIMSK_ , TIMSK_OCIE2) ;}
			else{
				SET_BIT(TIMSK_ , TIMSK_TOIE2) ;}
			break;
		case Disable :
			if ( Mode == CTC ){
				CLEAR_BIT(TIMSK_ , TIMSK_OCIE2) ;}
			else{
				CLEAR_BIT(TIMSK_ , TIMSK_TOIE2) ;}
			break;
		default:
			break;
			
	}
	
}

void TMR_voidSetTimer2Count(u8 value)
{
	TCNT_2 = value ;
}

u8 TMR_u16GetTimer2Count(void){	u8 value = TCNT_2 ;		return value ;}