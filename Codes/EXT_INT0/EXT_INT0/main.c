/*
 * EXT_INT0.c
 *
 * Created: 2/14/2026 8:12:04 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)  //Interrupt vector table
{
	PORTB|=(1<<PB5);
	_delay_ms(1000);
	PORTB&=~(1<<PB5);
	
}
int main(void)
{
   DDRB|=(1<<PB4);  //Configuring PB4 as output
   DDRB|=(1<<PB5);  //PB5 as output
   DDRD&=~(1<<PD2);     // Set INT0 pin (PD2)as input
   EIMSK|=(1<<INT0);   //Enable INT0 interrupt
   EICRA|=(1<<ISC01);  //Interrupt on falling edge
   sei();              //Enable global interrupt
   
    while (1) 
    {
		PORTB|=(1<<PB4);
		_delay_ms(1000);
		PORTB&=~(1<<PB4);
		_delay_ms(1000);
    }
}

