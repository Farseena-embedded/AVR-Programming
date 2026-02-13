/*
 * dcmotor.c
 *
 * Created: 2/13/2026 12:33:34 PM
 *  Author: acer cc
 */ 
    #define F_CPU 16000000UL
    #include <avr/io.h>
    #include <util/delay.h>
	
	/*Function definitions */
	
	/* Initialize motor pins */
	void motor_init(void)
	{
		DDRB|=(1<<DDB4)|(1<<DDB5); // Set PB4 and PB5 as output
	}
	/* Clockwise rotation */
	void cw(uint16_t delay)
	{
		PORTB |= (1 << PB4);      // PB4 = HIGH
		PORTB &= ~(1 << PB5);     // PB5 = LOW
		delay_ms(delay);
	}

	/* Counter-clockwise rotation */
	void ccw(uint16_t delay)
	{
		PORTB |= (1 << PB5);      // PB5 = HIGH
		PORTB &= ~(1 << PB4);     // PB4 = LOW
		delay_ms(delay);
	}

	/* Motor stop */
	void stp(uint16_t delay)
	{
		PORTB &= ~(1 << PB4);     // PB4 = LOW
		PORTB &= ~(1 << PB5);     // PB5 = LOW
		delay_ms(delay);
	}

	//Long delay using loop
	void delay_ms(uint16_t ms)
	{
		unsigned int i;
		for(i=0;i<ms;i++)
		{
			_delay_ms(1);
		}
	}