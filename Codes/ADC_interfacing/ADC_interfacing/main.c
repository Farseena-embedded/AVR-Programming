/*
 * ADC_interfacing.c
 *
 * Created: 3/4/2026 10:26:39 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include "lcd.h"

void adc_init(void)
{
	ADMUX |= (1<<REFS0); // AVcc reference
	ADCSRA |=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);  //Enabling ADC and Setting Prescalar 128 to enabling ADC frequency 125khz
}
uint16_t adc_read(uint8_t channel)
{
	channel &=0x07;              //Limiting the channel to max 7
	ADMUX= (ADMUX&0XF8)|channel; //Select the correct channel
	ADCSRA |= (1<<ADSC);        // Start conversion
	while(ADCSRA & (1<<ADSC));   // Wait until the conversion finishes
	return ADC;      
}

int main(void)
{
	     lcd_init();
		 adc_init();
		 lcd_clear();
		 lcd_set_cursor(0,0);
		 lcd_print("temperature:");
		 while (1)
		 {
			 uint16_t value= adc_read(0);
			 float  temp = (value*0.488);   //Converting adc value to temperature
			  
			 lcd_set_cursor(1,0);
			 lcd_print_float(temp);
			 _delay_ms(1000);
			 
		 }
}

