/*
 * UART_string.c
 *
 * Created: 3/25/2026 4:55:21 PM
 * Author : acer cc
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/* UART initialization */
void uart_init()
{
    UBRR0H = 0;
    UBRR0L = 103;   // 9600 baud for 16MHz

    UCSR0B = (1<<TXEN0);                     // Enable transmitter
    UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);      // 8-bit data
}

/* Send one character */
void uart_transmit(char data)
{
    while(!(UCSR0A & (1<<UDRE0)));   // Wait until buffer empty
    UDR0 = data;
}

/* Send string function */
void uart_string(char *str)
{
    while(*str != '\0')   // Loop until end of string
    {
        uart_transmit(*str);   // Send one character
        str++;                 // Move to next character
    }
}

int main(void)
{
    uart_init();

    while (1)
    {
        uart_string("HELLO WORLD");
       // uart_transmit('\r');
        uart_transmit('\n');

        _delay_ms(1000);
    }
}

