/*
 * EEPROM.c
 *
 * Created: 13/04/2021 01:32:52 AM
 *  Author: Salma
 */ 

#include "EEPROM.h"

void EEPROM_Init(void)
{
	I2C_Init();
}

void EEPROM_Write (u8 data, u8 address)
{
	TWIStart( ) ;
	
	TWIWrite( 0xA0 ) ;				//Write Mode
	TWIWrite( address ) ;
	TWIWrite( data ) ;
	
	TWIStop( ) ;
}


u8 EEPROM_Read (u8 address)
{
	u8 res = 0 ;
	
	TWIStart( ) ;
	
	TWIWrite( 0xA0 ) ;				//Write Mode
	TWIWrite( address ) ;
	
	TWIStart( ) ;
	
	TWIWrite( 0xA1 ) ;				//Read Mode
	
	res = TWIReadNACK() ;
	
	TWIStop( ) ;

	return res ;
}