/*
 * EXT_INT1.c
 *
 * Created: 2/14/2026 8:51:32 PM
 * Author : acer cc
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t flag=0;
ISR(INT1_vect)  //Interrupt vector table
{
	flag=1;  // set flag when interrupt occurs
}
int main(void)
{
	DDRB|=(1<<PB4);  //Configuring PB4 as output
	DDRB|=(1<<PB5);  //PB5 as output
	DDRD&=~(1<<PD3);     // Set INT1 pin (PD3)as input
	EIMSK|=(1<<INT1);   //Enable INT0 interrupt
	EICRA|=(1<<ISC11);  //Interrupt on falling edge
	sei();              //Enable global interrupt
	
	while (1)
	{
		
		PORTB|=(1<<PB4);
		_delay_ms(1000);
		PORTB&=~(1<<PB4);
		_delay_ms(1000);
		
		if(flag==1)  //check if interrupt occurs
		{
			PORTB|=(1<<PB5);
			_delay_ms(5000);
			PORTB&=~(1<<PB5);
			flag = 0;      // Reset flag 
		}
		
	}
}



