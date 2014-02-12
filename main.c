#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRD = 0b11111111;
	for (;;)
	{
		PORTD = 0xFF;

	}
	return 0;
}
