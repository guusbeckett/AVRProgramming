/*
 * Module name		: lcd.c: write to LCD display
 * Author			: TI-Avans, JW
 * Revision History	: 20110228: - initial release;
 * Description		: This module contains functions for writing to lcd-display
 * Test configuration:
     MCU			: ATmega128
     Dev.Board		: BIGAVR6
     Oscillator		: External Clock 8.0000 MHz
     Ext. Modules	: -
     SW:              AVR-GCC
 * NOTES			: - 
*/


#include "lcd.h"

// lcd_command: schrijf command byte (RS=0)
// eerst hoge nibble, dan de lage
// 
void lcd_command ( unsigned char command )
{
	PORTC = command & 0xF0;			// hoge nibble
	PORTC = PORTC | 0x08;			// start (EN=1)
	_delay_ms(1);					// wait 1 ms
	PORTC = 0x00;					// stop
	_delay_ms(5);					// wait 5 ms
	
	PORTC = (command & 0x0F) << 4;	// lage nibble, shift lage naar hoge bits
	PORTC = PORTC | 0x08;			// start (EN =1)
	_delay_ms(1);					// wait 1 ms
	PORTC = 0x00;					// stop (EN=0 RS=0)	
	_delay_ms(5);					// wait 5 ms
}

// Schrijf data byte (RS=1)
// eerst hoge nibble, dan de lage
// 
void lcd_writeChar( unsigned char dat )
{
	PORTC = dat & 0xF0;				// hoge nibble
	PORTC = PORTC | 0x0C;			// data (RS=1), start (EN =1)
	_delay_ms(1);					// wait 1 ms
	PORTC = 0x04;					// stop
	_delay_ms(5);					// wait 5 ms
			
	PORTC = (dat & 0x0F) << 4;		// lage nibble
	PORTC = PORTC | 0x0C;			// data (RS=1), start (EN =1)
	_delay_ms(1);					// pulse 1 ms
	PORTC = 0x00;					// stop (EN=0 RS=0)
	_delay_ms(5);					// wait 5 ms
}

// Initialisatie ldr
//
void lcd_init( void )
{
	DDRC=0xFF;						// PORT D is output to LCD display
	lcd_command( 0x01 );			// clear display
	lcd_command( 0x02 );			// return home
	lcd_command( 0x28 );			// mode: 4 bits interface data, 2 lines,5x8 dots
	lcd_command( 0x0C );			// display: on, cursor off, blinking off
	lcd_command( 0x06 );			// entry mode: cursor to right, no shift
	lcd_command( 0x80 );			// RAM adress: 0, first position, line 1
	_delay_ms(5);
}


//
// write first line
void lcd_writeLine1 ( char text1[] )
{
	lcd_command(0x80);						// first pos line 1, adres $00
	
	for ( int i=0; i<strlen(text1); i++ )
	{
		lcd_writeChar( text1[i] );
	}
} 

// write first line
void lcd_wrLine1AtPos ( char text1[], unsigned char pos)
{
	lcd_command(0x80+pos);					// first pos line 1, adres pos
	
	for ( int i=0; i<strlen(text1); i++ )
	{
		lcd_writeChar( text1[i] );
	}
} 

//
// write second line
void lcd_writeLine2 ( char text2[] )
{
	lcd_command(0xC0);						// first pos line 2, adres $40

	for ( int i=0; i<strlen(text2); i++ )
	{
		lcd_writeChar( text2[i] );
	}
} 

// write first line
void lcd_wrLine2AtPos ( char text2[], unsigned char pos)
{
	lcd_command(0xC0+pos);					// first pos line 2, adres $40+pos
	
	for ( int i=0; i<strlen(text2); i++ )
	{
		lcd_writeChar( text2[i] );
	}
} 

// shift text over 'displacement' positions
// to the right (displacement>0) or to the left (displacement<0)
void lcd_shift( int displacement )
{
	int number=displacement<0?-displacement:displacement;
	for (int i=0; i<number; i++)
	{
		if (displacement <0)
			lcd_command(0x18);
		else
			lcd_command(0x1C);
	}
}
