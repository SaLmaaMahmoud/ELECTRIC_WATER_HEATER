/*
 * TMR.h
 *
 * Created: 2/2/2021 4:34:08 PM
 *  Author: Salma
 */ 


#ifndef TMR_H_
#define TMR_H_


/********************** Registers Definition **********************/
#define TCCR_0		TCCR0
#define TCNT_0		TCNT0
#define OCR_0 		OCR0
#define TIMSK_		TIMSK
#define TIFR_		TIFR

#define TCCR_1A		TCCR1A
#define TCCR_1B		TCCR1B
#define TCNT_1		TCNT1
#define OCR_1A		OCR1A

#define TCCR_2		TCCR2
#define TCNT_2		TCNT2
/******************************************************************/

/************************ Registers PINS *************************/
#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1
#define TIMSK_TOIE1		2
#define TIMSK_OCIE1B	3
#define TIMSK_OCIE1A	4
#define TIMSK_TOIE2		6
#define TIMSK_OCIE2		7


#define TIFR_TOV0		0
#define TIFR_OCF0		1
#define TIFR_TOV1		2
#define TIFR_OCF1B		3
#define TIFR_OCF1A		4

#define CS00			0
#define CS01			1
#define CS02			2
#define WGM01			3
#define WGM00			6

#define WGM10			0
#define WGM11			1

#define CS10			0
#define CS11			1
#define CS12			2
#define WGM12			3
#define WGM13			4

#define CS20			0
#define CS21			1
#define CS22			2
#define WGM21			3
#define WGM20			6
/****************************************************************/

/********************** Prescaller Modes ***********************/
typedef enum {
	prescallar_1	,
	prescallar_8	,
	prescallar_64	,
	prescallar_256	,
	prescallar_1024	,
	prescallar_FallinEdge ,
	prescallar_RisinEdge ,
} prescallar ;
/****************************************************************/

/************************ Timer Modes *************************/
typedef enum{
	Normal ,
	PWM ,
	CTC ,
	Fast_PWM
} Modes ;
/**************************************************************/

/********************** Interrupt State ***********************/
typedef enum{
	Enable ,
	Disable ,
} Interrupt_State ;
/**************************************************************/


/********************** Timer0 Functions ***********************/
void TMR_voidInitTimer0(prescallar pres , Interrupt_State interupt , Modes Mode) ;
void TMR_voidSetTimer0Count(u8 value);
u8 TMR_u16GetTimer0Count(void);/**************************************************************/


/********************** Timer1 Functions ***********************/
void TMR_voidInitTimer1(prescallar pres , Interrupt_State interupt , Modes Mode) ;
void TMR_voidSetTimer1Count(u8 value);
u8 TMR_u16GetTimer1Count(void);
/**************************************************************/


/********************** Timer2 Functions ***********************/
void TMR_voidInitTimer2(prescallar pres , Interrupt_State interupt , Modes Mode) ;
void TMR_voidSetTimer2Count(u8 value);
u8 TMR_u16GetTimer2Count(void);
/**************************************************************/


#endif /* TMR_H_ */