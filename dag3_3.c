/*
 * Project name:
     Demo3_3 : Counter with compare mode on Counter/Timer 2
 * Author: Avans-TI, JW
 * Revision History: 
     20101222: - initial release;
 * Description:
     This program counts events on pin T2 = PD7.
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
#include <avr/interrupt.h>

#define BIT(x)	(1 << (x))
#define COMPAREVALUE 25-1

unsigned int twentyFifthValue = 0;

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}

// Interrupt routine timer2 compare match
//
ISR( TIMER2_COMP_vect )
{
	twentyFifthValue++;				// Increment counter
	lcd_command(0x01);
}

// Initialize timer 2: counting, preset, interrupt on overflow
void timer2Init( void )
{
	OCR2 = COMPAREVALUE;		// Compare value of counter 2
	TIMSK |= BIT(7);			// T2 compare match interrupt enable
	SREG |= BIT(7);				// turn_on intr all
	TCCR2 = 0b00011111;			// Initialize T2: ext.counting, rising edge
								//    compare output mode, CTC, RUN
}

// Main program: Counting on T2
int main( void )
{
	lcd_init();					// For LCD
	DDRD &= ~BIT(7);			// set PORTD.7 for input
	DDRA = 0xFF;				// set PORTA for output (shows countregister)
	DDRB = 0xFF;				// set PORTB for output (shows tenth value)
	timer2Init();				// Initialize timer 2
	char* nums = malloc(15*sizeof(char));	// For LCD
	while (1)
	{
		sprintf(nums, "Val1: %d Val2: %d", TCNT2, twentyFifthValue); // For LCD
		lcd_wrLine1AtPos(nums, 0);		// For LCD
		PORTA = TCNT2;			// show value counter 2
		PORTB = twentyFifthValue;		// show value tenth counter
		wait(100);				// every 10 ms
	}
}
