/*
 * povToy.c
 *
 * Created: 21-03-2019 10:30:36 PM
 * Author : New User
 */ 
#define F_CPU 16000000UL		// 16 MHz clock (external) Arduino UNO
#include <avr/io.h>			
#include <util/delay.h>			// for delays

void POVDisplay(uint8_t oneByte)
{
	PORTD = oneByte;		// turn LEDs ON
	_delay_ms(2);			// small delay
}

// main
int main(void)
{
	DDRD = 0XFF;			// Set all PORTB pins as OUTPUT
	
    // event loop
    while (1) 
    {
		POVDisplay(0b00001110);
		POVDisplay(0b00011000);
		POVDisplay(0b10111101);
		POVDisplay(0b01110110);
		POVDisplay(0b00111100);
		POVDisplay(0b00111100);
		POVDisplay(0b00111100);
		POVDisplay(0b00001110);
		POVDisplay(0b00011000);
		POVDisplay(0b10111101);
		POVDisplay(0b01110110);
		
		PORTD = 0;						// set all pins low
		_delay_ms(10);
    }
	
	return 0;
}

