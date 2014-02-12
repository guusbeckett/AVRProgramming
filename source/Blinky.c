/*
 * Project name:
     LED_Blinking (Simple 'Hello World' project)
 * Author: Avans-TI, JW
 * Revision History: 
     20101217: - initial release;
 * Description:
     This is a simple 'Blinky' project It turns on/off 
	 all the diodes connected to PORTD.
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

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );				// library function (max 30 ms at 8MHz)
	}
}

// Blinky program: Blinky
int main( void )
{
	// set PORTD for output
	DDRD = 0b10101010;				//Of: DDRD = 0xFF; 
	
	while (1)
	{
		PORTD = 0xFF;				// write 1 to all the bits of PortD
		wait( 500 );				// wait for 500 ms
		PORTD = 0;					// write 0 to all the bits of PortD
		wait( 500 );				// wait for 500 ms
	}
	return 1;
}
