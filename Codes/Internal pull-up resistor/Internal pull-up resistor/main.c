/*
 * Internal pull-up resistor.c
 *
 * Created: 2/5/2026 1:29:50 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    // Configuring PB5 as output and PD4 as input
	DDRB|=(1<<PB5);
	DDRD&=~(1<<PD4);
	// Enable internal pull-up
	PORTD|=(1<<PD4);
	
    while (1) 
    {
		if(!(PIND&(1<<PD4))) //Switch is  pressed
		{
			PORTB|=(1<<PB5);  // PB5 is HIGH(LED ON)
		}
		else
	    
		{
			PORTB&=~(1<<PB5);  // PB5 is LOW (LED OFF)
		}
	}
}

