/*
 * Project name:
     Demo3_5 : Timer of 1 s with compare mode on Counter/Timer 1
 * Author: Avans-TI, JW
 * Revision History: 
     20101228: - initial release;
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

unsigned int sCount=0, minutes=0, hours=0;

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
ISR( TIMER1_COMPA_vect )
{
	sCount++;						// Increment s counter
	PORTD ^= BIT(0);				// Toggle bit 0 van PORTD
	if ( sCount == 60 )				// Every 1 minute:
	{								//
		minutes++;					//	Increment minutes counter
		sCount = 0;					//	Reset s-counter
		if ( minutes == 60 )		//	Every hour:
		{							//
			minutes = 0;			//		Reset min-counter
			hours++;				//		Increment hours counter
				if ( hours == 24 )	//		Every day:
					hours = 0;		//			reset hours counter
		}
	}
}

// Initialize timer 2: counting, preset, interrupt on overflow
void timer1Init( void )
{
	OCR1A = 525;					// 16-bits compare value of counter 1
	TIMSK |= BIT(4);				// T1 compare match A interrupt enable
	SREG |= BIT(7);					// turn_on intr all
	TCCR1B = 0b00001100;			// Initialize T1: timer, prescaler=256, 
									// 	compare output disconnected, CTC, RUN
}

// Display seconds on PORTD, minutes on PORTB& hours on PORTA
// 
void displayTime( void )
{
	PORTD = sCount;
	PORTB = minutes;
	PORTA = hours;
}

// Main program: Counting on T1
int main( void )
{
	lcd_init();					// For LCD
	char* nums = malloc(15*sizeof(char));	// For LCD
	DDRD = 0xFF;				// set PORTD for output (shows s, min, h)
	DDRB = 0xFF;
	DDRA = 0xFF;
	DDRD = 0xFF;
	timer1Init();
	while (1)
	{
		sprintf(nums, "Val1: %d", OCR1A); // For LCD
		lcd_wrLine1AtPos(nums, 0);		// For LCD
		// do something else
		wait(50);				// every 50 ms (busy waiting)
		displayTime();
	}
}
