/*
 * DC _Motor.c
 *
 * Created: 1/27/2026 9:47:46 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL  //Defining crystal frequency
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB|=(1<<DDB4) | (1 << DDB5);       // Configuring PB4 AND PB5 as output
	
	while (1)
	{
		PORTB |=(1<<PB4);        // Making PB4 = HIGH
		PORTB &=~(1 << PB5);   // PB5=LOW
		_delay_ms(4000);        // 2 Second delay
		
		 // Motor Stop
		 PORTB &=~(1 << PB4);    // PB4=LOW
		 PORTB &=~(1 << PB5);   // PB5=LOW
		 _delay_ms(5000);       // 2 seconds delay
		 
		 PORTB |=(1 << PB5);   // PB5=HIGH
		 PORTB &=~(1<<PB4);    //  PB4 = LOW
		_delay_ms(4000);       // 2 second delay
		
		 PORTB &=~(1 << PB4);  // PB4=LOW
		 PORTB &=~(1 << PB5);  // PB5=LOW
		 _delay_ms(5000);       // 2 seconds delay
	}
}




