/*
 * Timer0_FastPWM_2.c
 *
 * Created: 2/7/2026 10:41:27 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Initial value of TCNT0=0
	TCNT0=0;
	// OC0A pin output
	DDRD|=(1<<PD6);
	
    //Configuring fastPWM mode
	TCCR0A|=(1<<WGM00)|(1<<WGM01);
	//Configuring inverting mode
	TCCR0A|=(1<<COM0A1)|(1<<COM0A0);
	
	// 60% Duty cycle
	OCR0A=102;
	//Configuring Timer0 for 8 prescalar condition
	TCCR0B|=(1<<CS01);
	TCCR0B&=~((1<<CS00)|(1<<CS02));

	 
	
    while (1) 
    {
    }
}

