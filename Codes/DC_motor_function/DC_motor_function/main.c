/*
 * DC_motor_function.c
 *
 * Created: 1/28/2026 12:43:46 PM
 * Author : acer cc
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/* Function declarations */
void cw(unsigned int delay);
void ccw(unsigned int delay);
void stp(unsigned int delay);
void delay_ms(unsigned int ms);

int main(void)
{
    /* Set PB4 and PB5 as output */
    DDRB |= (1 << DDB4) | (1 << DDB5);

    while (1)
    {
        cw(2000);     // Rotate motor clockwise for 2 seconds
        stp(2000);    // Stop motor for 2 seconds
        ccw(2000);    // Rotate motor counter-clockwise for 2 seconds
        stp(2000);    // Stop motor for 2 seconds
    }
}

/* Clockwise rotation */
void cw(unsigned int delay)
{
    PORTB |= (1 << PB4);      // PB4 = HIGH
    PORTB &= ~(1 << PB5);     // PB5 = LOW
    delay_ms(delay);
}

/* Counter-clockwise rotation */
void ccw(unsigned int delay)
{
    PORTB |= (1 << PB5);      // PB5 = HIGH
    PORTB &= ~(1 << PB4);     // PB4 = LOW
    delay_ms(delay);
}

/* Motor stop */
void stp(unsigned int delay)
{
    PORTB &= ~(1 << PB4);     // PB4 = LOW
    PORTB &= ~(1 << PB5);     // PB5 = LOW
    delay_ms(delay);
}

//Long delay using loop
void delay_ms(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms;i++)
	{
		_delay_ms(1);
	}
}


