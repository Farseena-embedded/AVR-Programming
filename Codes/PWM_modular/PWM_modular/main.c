/*
 * PWM_modular.c
 *
 * Created: 2/12/2026 2:06:38 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "pwm.h"


int main(void)
{
   PWM0_init(); //Initializing PWM
   PWM0_Duty(40);  //calling PWM with duty cycle=40
    while (1) 
    {
    }
}

