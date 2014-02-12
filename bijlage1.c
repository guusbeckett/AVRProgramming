/* Project name: 		Demo2_1 - LED_Blinking with interrupts
 * Author: 			Avans-TI, JW
 * Revision History:		20101217: - initial release;
 * Description:			This is a demo of input and ouput, it turns on/off pin0 or
	 				pin3 of PORTC, dependent of rising edge on input EX0 or EX1 
 * Test configuration:
     MCU:             	ATmega128
     Dev.Board:       	BIGAVR6
     Oscillator:      	External Clock 08.0000 MHz
     Ext. Modules:    	-
     SW:              	AVR-GCC
 * NOTES:				Turn ON the PORT LEDs at SW12.1 - SW12.8
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BIT(x)	(1 << (x))

unsigned char toggle = 1;
unsigned int  waitLength = 500;
// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int i=0; i<ms; i++)
		_delay_ms( 1 );				// library function (max 30 ms at 8MHz)
}

// Interrupt service routine External Input0
ISR( INT0_vect )
{
	if (toggle)
	{
	    toggle = 0;	
	}
	else
	{
		toggle = 1;
	}

}

// Interrupt service routine External Input1
ISR( INT1_vect )
{
    waitLength = waitLength + 5;					// toggle bit3 van PORTC bij extern int 1
}

// Initialisation external interrupt EX0 and EX1
void exIntrInit( void )
{
	DDRD = DDRB & 0b11111100;			// PD1 en PD2 for input
	EICRA |= 0x0F;					// EX0, EX1: rising edge	
	EIMSK |= 0x03;					// turn_on EI0, EI1
	SREG |= 0x80;					// turn_on intr all
}

// Main program
int main( void )
{
	DDRC = 0b11111111;				// set PORTC for output
	DDRD = 0b00000000;				// set PORTD for input 	PORTC |= BIT(0); initialize PORTC.0=1
	PORTC |= BIT(3); 				// initialize PORTC.3=1
	exIntrInit();					// initialize EXT_INT0 en EXT_INT1

	DDRA = 0xFF;
	DDRB = 0xFF;
	int x = 0;

	while (1)
	{
		
		if(x<8)
			{
				PORTB = (1<<x);
				PORTA = 0;	
			}	
		else 
			{
				PORTB=0;
				PORTA = (128>>x-8);	
			}
		wait( waitLength );
		if (toggle)
		{
			++x;
			if(x==17) x=0;
		}
		else
		{
			--x; 
			if(x==-1) x=16;
		}
		
	}
	return 1;
}
