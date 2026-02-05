/*
 * Timer0_prescalar1024_mode.c
 *
 * Created: 2/5/2026 4:35:51 PM
 * Author : acer cc
 */ 

/*
 * Timer0-Prescalar mode.c
 *
 * Created: 2/5/2026 4:03:06 PM
 * Author : acer cc
 */ 

/*
 * Timer0_Normal mode.c
 *
 * Created: 2/5/2026 2:31:55 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void delay_1ms()
{
	for(int i=1;i<62;i++)   // Repeating the process 62 times to get 1sec delay
	{
		while(!(TIFR0&(1<<TOV0))); // Wait until TOV0=1, ie till overflow happens
		TIFR0|=(1<<TOV0);          // Writing 1 to TOV0 bit to make it 0.AVR People are crazy
	}
}

int main(void)
{
	TCNT0=0;  //Initial value of TCNT0=0
	
	// Configuring normal mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A&=~(1<<WGM01);
	
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




