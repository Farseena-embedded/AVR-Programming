
/*
 * UART_initialization.c
 *
 * Created: 3/14/2026 8:22:30 PM
 * Author : acer cc
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void uart_init()
{
  /*1. Baud rate FOR 9600 */
  UBRR0H = 0;
  UBRR0L =103;
  /*2. Enabling the transmitting and receiving */
  UCSR0B |=((1 << RXEN0)|(1 << TXEN0));
  /*3. Data frame configuration -8 bit*/
  UCSR0B &=~(1<<UCSZ02);
  UCSR0C |=(1<< UCSZ00) | (1<< UCSZ01);
  /*4. Parity select*/
  UCSR0C &=~((1<< UPM01) | (1<< UPM00));
  /*5. Stop bit select*/
  UCSR0C &=~(1<<USBS0);
  
}
     /*uart transmit function */
	void uart_transmit (char data)
	{
		/*Waiting until the buffer is ready*/
		while(!(UCSR0A & (1<< UDRE0)));
		/*feeding data to the buffer */
		UDR0 = data;
	}
int main(void)
{
	uart_init();
	char data ='H';
	
    while (1) 
    {
		uart_transmit(data);
		/*print new line*/
	
		uart_transmit('\n');
		_delay_ms(1000);
    }
}

