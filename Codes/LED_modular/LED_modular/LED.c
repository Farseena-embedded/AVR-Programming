/*
 * LED.c
 *
 * Created: 2/12/2026 8:26:17 PM
 *  Author: acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//Function definition
void LED_init(void)
{
	DDRB|=(1<<DDB5); //Configuring PB5 as output
}
void LED_ON(void)
{
	PORTB|=(1<<PB5); // LED ON
}
void LED_OFF(void)
{
	PORTB&=~(1<<PB5); //LED OFF
}
void delay_ms(uint16_t delay)  //delay function definition
{
	while(delay--)
	{
		_delay_ms(1);
	}
}