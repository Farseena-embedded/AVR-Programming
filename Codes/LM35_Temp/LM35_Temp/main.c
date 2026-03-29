/*
 * LM35_Temp.c
 *
 * Created: 3/29/2026 3:23:03 PM
 * Author : acer cc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"
#include "uart.h"
#include "LED.h"

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
	lcd_print("Temperature: ");
	
	UART_Init();
	LED_init();
	
  
   
	
	
	while (1)
	{
		char buffer[10];   // buffer for string

		uint16_t value= adc_read(0);    // Read from analog channel 0 (A0 pin of arduino)
		float  temp = (value*0.488);   //Converting adc value to temperature
		
		/* LCD */
		lcd_set_cursor(1,0);
		lcd_print_float(temp);	// printing temperature
		lcd_data(0xDF);        // To print degree symbol(came from the data sheet of lcd controller )
		lcd_print("C");
	    delay_ms(500);
		
		/* UART */
		dtostrf(temp, 4, 2, buffer);    // Convert float to string 
		UART_TxString("Temperature: ");
		UART_TxString(buffer);
		UART_TxString(" C\r\n");
		
		/* LED */
		LED_ON();
		delay_ms(500);
		LED_OFF();
		delay_ms(500);
		 
		}
}
 

