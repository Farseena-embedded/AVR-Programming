/*
 * Timer0_FastPWM.c
 *
 * Created: 2/7/2026 9:46:01 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>



int main(void)
{
    TCNT0=0;  //Initial value of TCNT0=0
	
	// Configuring Fast PWM mode
	TCCR0A|=(1<<WGM00)|(1<<WGM01);
	OCR0A =102;      // 40% duty cycle
	
	//Configuring Timer0 for 64 prescalar condition
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
	//Non inverting
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	
	// OC0A pin output
	DDRD|=(1<<PD6); //Configuring PD6 as ouput
	
    while (1) 
    {
		
    }
}

