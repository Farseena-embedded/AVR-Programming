/*
 * Timer0_FastPWM_1.c
 *
 * Created: 2/12/2026 12:58:21 PM
 * Author : acer cc
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	//Initial value of TCNT0=0
	TCNT0=0;
	// OC0A pin,PD6 as output
	DDRD|=(1<<PD6);
	
	//Configuring fastPWM mode
	TCCR0A|=(1<<WGM00)|(1<<WGM01);
	//Configuring non-inverting mode
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	
	// 60% Duty cycle(non-inverting mode)
	OCR0A=153;
	//Configuring Timer0 for 8 prescalar condition
	TCCR0B|=(1<<CS01);
	TCCR0B&=~((1<<CS00)|(1<<CS02));

	
	
	while (1)
	{
	}
}



