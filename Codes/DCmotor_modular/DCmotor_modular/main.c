/*
 * DCmotor_modular.c
 *
 * Created: 2/13/2026 12:32:29 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "DC_motor.h"


int main(void)
{
     motor_init();   // Initialize motor pins
	
    while (1) 
    {
		 cw(2000);     // Rotate motor clockwise for 2 seconds
		 stp(2000);    // Stop motor for 2 seconds
		 ccw(2000);    // Rotate motor counter-clockwise for 2 seconds
		 stp(2000);    // Stop motor for 2 seconds
    }
}

