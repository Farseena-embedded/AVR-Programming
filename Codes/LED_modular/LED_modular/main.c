/*
 * LED_modular.c
 *
 * Created: 2/12/2026 8:24:25 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

#include "led.h"  // including LED and delay function declarations


int main(void)
{
    LED_init();  //Initializing LED pin
    while (1) 
    {
		LED_ON();         // Calling function LED ON
		delay_ms(2000);  // Calling Delay 2sec
		LED_OFF();       //Calling function LED OFF
		delay_ms(2000);  //Calling Delay 2sec
    }
}

