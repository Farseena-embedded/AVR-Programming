/*
 * Blink.c
 *
 * Created: 1/24/2026 10:55:47 AM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL //Defining crystal frequency
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
   DDRB = 0b00001000;   //Configuring PB3 as output
    while (1) 
    {
		PORTB =0b00001000;  //Making PB3 = HIGH
		_delay_ms(1000);    //1000ms delay
		PORTB = 0b00000000; //Making PB3 = LOW
		_delay_ms(1000);    //1000ms delay
    }
}

