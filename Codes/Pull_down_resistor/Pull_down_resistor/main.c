/*
 * Pull_down_resistor.c
 *
 * Created: 2/3/2026 8:05:30 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB|=(1<<PB3);                //Configuring PB3 as output
	DDRD&=~(1<<PD1);              // Configuring PD1 as input
	
    while (1) 
    {
		if(PIND&(1<<PD1))        //Checking if PD1 pin is pressed,switch is pressed
		{
			PORTB|=(1<<PB3);    // Turning PB3 is HIGH
		}
		else
		{
			PORTB&=~(1<<PB3);   // Turning PB3 is LOW
		}
		
    }
}

