/*
 * Module name		: lcd : write commands and characters tot LCD-display
 * Author			: Avans-TI, WvdE
 * Revision History	: 20110227: - initial release;
 * Description		: This program receive a character, and sends it back
 * Test configuration:
     MCU:             ATmega128
     Dev.Board:       BIGAVR6
     Oscillator:      External Clock 08.0000 MHz
     Ext. Modules:    -
     SW:              AVR-GCC
 * NOTES:
*/

#ifndef _LCD
#define _LCD

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdint.h>

// lcd_command: schrijf command byte (RS=0)
// eerst hoge nibble, dan de lage
// 
void lcd_command ( unsigned char command );

// Schrijf data byte (RS=1)
// eerst hoge nibble, dan de lage
// 
void lcd_writeChar( unsigned char dat );

// Initialisatie ldr
//
void lcd_init( void ) ;

//
// write first line
void lcd_writeLine1 ( char text1[] ) ;

//
// write second line
void lcd_writeLine2 ( char text2[] ) ;

// write first line from position pos
void lcd_wrLine1AtPos ( char text1[], unsigned char pos );

// write second line from position pos
void lcd_wrLine2AtPos ( char text2[], unsigned char pos);

// shift text over 'displacement' positions
// to the right (displacement>0) or to the left (displacement<0)
void lcd_shift(int displacement) ;

#endif






