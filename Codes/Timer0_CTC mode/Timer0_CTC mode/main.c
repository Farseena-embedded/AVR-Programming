/*
 * Timer0_CTC mode.c
 *
 * Created: 2/6/2026 9:44:04 PM
 * Author : acer cc
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void delay_1ms()
{
	for(int i=1;i<78;i++)   // Repeating the process 78 times to get 1sec delay
	{
		while(!(TIFR0&(1<<OCF0A))); // Wait until OCF0A=1, ie till overflow happens
		TIFR0|=(1<<OCF0A);          // Writing 1 to OCF0A bit to make it 0.
	}
}

int main(void)
{
	TCNT0=0;  //Initial value of TCNT0=0
	
	// Configuring CTC mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	OCR0A =200;
	
	//Configuring Timer0 for 1024 prescalar condition
    TCCR0B|=(1<<CS00)|(1<<CS02);
	TCCR0B&=~(1<<CS01);
	
	//Configuring a pin for LED
	DDRB|=(1<<PB4); //Configuring PB4 as ouput
	
    while (1) 
    {
		PORTB|=(1<<PB4);  //PB4 is ON
	    delay_1ms();
		PORTB&=~(1<<PB4);  //PB4 is OFF
		delay_1ms();
    }
}





