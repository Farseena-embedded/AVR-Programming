/*
 * Blink-Bitwise.c
 *
 * Created: 1/25/2026 9:44:23 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL  //Defining crystal frequency
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   DDRB|=(1<<DDB5);       // Configuring PB5 as output
   
       while (1) 
    {
		PORTB|=(1<<PB5);   // Making PB5 = HIGH
		_delay_ms(1000);  // 1 Second delay
		PORTB&=~(1<<PB5);  // Making PB5 = LOW
		_delay_ms(1000);   // 1000ms delay
    }
}

