/* Project name: 		Demo2_2 - LED_Blinking with interrupts
 * Author: 			Avans-TI, WvdE
 * Revision History:		20110131: - initial release;
 * Description:		This is a demo of input and output, it shows the numbers 0..9 on a 7-segment display on PORTB 
 * Test configuration:
     MCU:             	ATmega128
     Dev.Board:       	BIGAVR6
     Oscillator:      	External Clock 08.0000 MHz
     Ext. Modules:    	-
     SW:              	AVR-GCC
 * NOTES:				7 segments display:	type: SC56-11-ewa
common cathode
					segments:    a
							f   b
							  g
							e   c
							  d
 */

#include <avr/io.h>
#include <util/delay.h>		 

void showNumber(int displayableNumber);

const unsigned char numbers [16] =
{
//	  Pgfedcba
	0b00111111,		// 0
	0b00000110,		// 1
	0b01011011,		// 2   
	0b01001111,		// 3	
	0b01100110,		// 4	
	0b01101101,		// 5 	
	0b01111101,		// 6
	0b00000111,		// 7
	0b01111111,		// 8
	0b01101111,		// 9
	0b01110111,		// A
	0b01111100,		// B
	0b00111001,		// C
	0b01011110,		// D
	0b01111001,		// E
	0b01110001,		// F
};
// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );				// library function (max 30 ms at 8MHz)
	}
}

// main programm
int main ()
{	
	while (1)
	{
		for (int i=0; i<=15; i++)		// show the numbers 0..9 sequently
		{
			showNumber(i);
			wait (3000);
		}
	}

	return 1;
} // end main

void showNumber(int displayableNumber)
{
	DDRB=0xFF;						// poortB output
	
	PORTB = numbers[displayableNumber%16];
}
