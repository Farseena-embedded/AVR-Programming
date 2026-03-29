/*
 * UART_Driver codes.c
 *
 * Created: 3/26/2026 4:17:45 PM
 * Author : acer cc
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#define SLAVE_SELECT PB2

/*Configuring SPI for master mode */
void spi_init()
{
	//Configuring MOSI,SCK and SS as output
	DDRB |= (1 << DDB5 )|(1 << DDB3)|(1 <<DDB2);
	//Configuring MISO as input
	DDRB &= ~(1 << DDB4);
	//Enabling setting up as master,choosing clock frequency ,mode 0
	SPCR |=(1 << SPE)|(1 << MSTR)|(1 << SPR0); //fclk/16=16000000/16= mhz
	SPCR &= ~((1 << SPR1)|(1 << CPHA)|(1 << CPOL));
}

int main(void)
{
	spi_init();
	UART_Init();
	uint8_t chip_id;
    
    while (1) 
    {
		PORTB &= ~(1 << SLAVE_SELECT); //Selecting the slave
		SPDR =0xD0 | 0X80;       // 1101 0000 | 1000 0000 
		
		//Wait until the data transfer is completed
		while(!(SPSR & (1 << SPIF)));
		(void) SPDR; //clearing out the garbage
		
		SPDR =0x00;  //Dummy byte
		while(!(SPSR & (1 << SPIF)));
		chip_id = SPDR;  //Collecting the SPDR value to chip id
		PORTB |= (1 << SLAVE_SELECT); //De-selecting the slave
		
		UART_TxString("Chip ID: ");
	    UART_TxHex(chip_id);
		
    }
}

