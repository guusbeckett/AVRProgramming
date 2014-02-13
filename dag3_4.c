/*
 * Project name:
     Demo3_4 : Timer of 1 ms with compare mode on Counter/Timer 2
 * Author: Avans-TI, JW
 * Revision History: 
     20101222: - initial release;
 * Description:
     This program gives an interrupt on each ms
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
#include <avr/interrupt.h>

#define BIT(x)	(1 << (x))
#define CompareValue 10

unsigned char msCount = 0;

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}

// Interrupt routine timer2 compare match toggle 
//
ISR( TIMER2_COMP_vect )
{
	msCount++;					// Increment ms counter
	if ( msCount == 250 )
	{
		PORTC ^= BIT(0);		// Toggle bit 0 van PORTC
		msCount = 0;			// Reset ms_count value
	}	
}

// Initialize timer 2: counting, preset, interrupt on overflow
void timer2Init( void )
{
	OCR2 = 250;					// Compare value of counter 2
	TIMSK |= BIT(7);			// T2 compare match interrupt enable
	SREG |= BIT(7);				// turn_on intr all
	TCCR2 = 0b00001011;			// Initialize T2: timer, prescaler=32, 
								// 	compare output disconnected, CTC, RUN
}

// Main program: Counting on T2
int main( void )
{
	DDRC = 0xFF;				// set PORTC for output (shows toggle bit)
	timer2Init();

	while (1)
	{
		// do something else
		wait(250);				// every 10 ms (busy waiting)
		PORTC ^= BIT(7);
	}
}
