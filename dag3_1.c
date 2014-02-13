/*
 * Project name:
     Demo3_1 : Counting events met Counter/Timer 2
 * Author: Avans-TI, JW
 * Revision History: 
     20101222: - initial release;
 * Description:
     This program counts event on pin T2 = PD7.
	 the result is in register TCNT2, shown on output port B
 * Test configuration:
     MCU:             ATmega128
     Dev.Board:       BIGAVR6
     Oscillator:      External Clock 08.0000 MHz
     Ext. Modules:    -
     SW:              AVR-GCC
 * NOTES:
     - Turn ON the PORT LEDs at SW12.1 - SW12.8
*/

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#define BIT(x)	(1 << (x))

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );				// library function (max 30 ms at 8MHz)
	}
}

// Main program: Counting on T2
int main( void )
{
	TCCR2 = 0x07;					// Initialize T2: ext.counting, rising edge
	DDRD &= ~BIT(7);				// set PORTD.7 for input for input
	DDRB = 0xFF;					// set PORTB for output

	while (1)
	{
		PORTB = TCNT2;				// show value counter 2

		wait(10);					// every 10 ms
	}
}

	
