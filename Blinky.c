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
	//int x = 1;

	//while(1)
	//{
	//flashLED();
	lichtSlang();
	//}
	return 1;
}

void flashLED()
{
	DDRD = 0xFF;
	int x = 0;
		while(1)
	{
		
		if(x)
		{
			PORTD = 0b10000000;
			x = 0;
		}
		else
		{
			PORTD = 0b01000000;
			x = 1;
		}
		wait( 10000 );
	}
}

void flashLEDOnButtonPress()
{
	DDRD = 0xFF;
	DDRC = 0x00;
	int x = 0;
	while(1)
	{
		if(PINC==0xFE)
		{
			if(x)
				{
					PORTD = 0b01000000;
					x = 0;
				}
			else
				{
					PORTD = 0;
					x = 1;
				}

			
		}
		else
			{
				PORTD = 0;
			}
			wait(500);
	}
}

void flashLEDOnButtonPressTwo()
{
	DDRD = 0xFF;
	DDRC = 0x00;
	int x = 0;
	while(1)
	{
		if(PINC==0xFE)
		{
			if(x)
				{
					PORTD = 0b01000000;
					x = 0;
				}
			else
				{
					PORTD = 0;
					x = 1;
				}

			
		}
		else
			{
			
			if(x)
				{
					PORTD = 0b00100000;
					x = 0;
				}
			else
				{
					PORTD = 0;
					x = 1;
				}
			}
			
		wait(500);
	}
}

void runningLight()
{
	DDRD = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	int x = 0;
		while (1)
	{
		if(x<9)
		{
			PORTD = (1<<x);
			PORTC = (128>>x);
			PORTB = (1<<x);
			PORTA = (128>>x);
						
		}	
		else 
		{
			PORTD = (128>>x-8);
			PORTA = (1<<x-8);
			
			PORTB = (128>>x-8);
			PORTC = (1<<x-8);	
		}
		wait( 500 );
		++x;
		++x;
		if(x>=17) x=1;
	}
}

void lichtSlang()
{
	DDRD = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	int x = 0;
		while (1)
	{
		if(x<9)
		{
			PORTD = (1<<x);
			PORTB = (1<<x);
						
		}	
		else 
		{
			PORTA = (128>>x-8);	
			PORTC = (128>>x-8);	
		}
		wait( 500 );
		++x;
		if(x==17) x=1;
	}
}