/*

Cylon eyes actually turns out to be a decent POV routine.
The only change here is in DELAYTIME.

 */

#define F_CPU 16000000UL

#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */

#define DELAYTIME 2                                    /* milliseconds */

int main(void) {
  uint8_t i=0;
  DDRD = 0b11111111;              /* Data Direction Register B: all on */

  while (1) {

    while(i < 7)
	{
		PORTD = (1 << i);
		_delay_ms(DELAYTIME);
		i++;
	}
	
	while(i > 0)
	{
		PORTD = (1 << i);
		_delay_ms(DELAYTIME);
		i--;
	}
  }

  return 0;
}
