/*
 * Project name:
     Demo4_3 : AD conversion on channel 1, PORTF.1, single mode, interrupt/timer2
 * Author: Avans-TI, JW
 * Revision History: 
     20101229: - initial release;
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
#define ADINTERVAL	50

unsigned int msCount = 0;

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (unsigned int ms_counter=0; ms_counter<ms; ms_counter++)
	{
		_delay_ms( 1 );				// library function (max 30 ms at 8MHz)
	}
}

// Initialize ADC: counting, preset, interrupt on overflow
void adcInit( void )
{
	ADMUX = 0b11100001;				// AREF=2.56, result right adjusted, channel1 at pin PF1
	ADCSRA = 0b10001110;			// ADC-enable, interrupt, no free running, division by 64
}

// Start AD conversion
void adcStart( void)
{
	ADCSRA |= BIT(6);				// Start ADC: bit ADSC=1 
}

// Interrupt routine AD conversie, started in timer 2
//
ISR( ADC_vect )
{
		// do something with the ADvalue
	PORTA = ADCH;					// Show MSB (bit 9:2) of ADC	
}

// Interrupt routine timer2 starts ADC every ADINTERVAL (=500)  ms
//
ISR( TIMER2_COMP_vect )
{
	msCount++;						// Increment ms counter
	if ( msCount == ADINTERVAL )
	{
		adcStart();					// Start AD Conversie
		msCount = 0;				// Reset ms_count value
		PORTC ^= BIT(7);			// Toggle pin PORTC.7 for testing
	}	
}

// Initialize timer 2: counting, preset, interrupt on overflow after 1 ms
void timer2Init( void )
{
	OCR2 = 250;						// Compare value of counter 2
	TIMSK |= BIT(7);				// T2 compare match interrupt enable
	SREG |= BIT(7);					// turn_on intr all
	TCCR2 = 0b00001011;				// Initialize T2: timer, prescaler=32, 
									// 	compare output disconnected, CTC, RUN
}

// Main program: Counting on T1
int main( void )
{
	DDRF = 0x00;					// set PORTF for input (ADC)
	DDRC = 0xFF;					// set PORTC for output 
	DDRA = 0xFF;					// set PORTA for output
	adcInit();						// initialize ADC
	timer2Init();					// initialize timer2

	// now adconversion runs, with fixed interval

	while (1)
	{
		PORTC ^= BIT(0);			// do someything else here, toggle PORTA.0
		wait(500);					// every 500 ms (busy waiting)
	}
}
