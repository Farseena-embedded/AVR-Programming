/*
 * pwm.c
 *
 * Created: 2/12/2026 2:13:55 PM
 *  Author: acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


void PWM0_init(void)
{

	// OC0A pin output
	DDRD|=(1<<PD6); //Configuring PD6 as output
	// Configuring Fast PWM mode
	TCCR0A|=(1<<WGM00)|(1<<WGM01);
	//Non inverting
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	//Configuring Timer0 for 64 pre-scalar 
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
	OCR0A=0; // initially 0% duty cycle
}
	
void PWM0_Duty(uint8_t duty_percentage)
{
	if(duty_percentage>100) //To limit entering duty cycle value above 100
	{
		duty_percentage=100;
	}
	OCR0A=(uint8_t)((duty_percentage*256)/100);
}	
	