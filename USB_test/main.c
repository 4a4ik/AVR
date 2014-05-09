#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define FOSC 8000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 1stop bit */
	UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0);
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	if ( (UCSRA & (1<<RXC)) )
	{
		return UDR;
	}
	else
	{
		return 20;
	}
}

void USART_Transmit( unsigned int data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Copy ninth bit to TXB8 */
	UCSRB &= ~(1<<TXB8);
	if ( data & 0x0100 )
	UCSRB |= (1<<TXB8);
	/* Put data into buffer, sends the data */
	UDR = data;
}

int main()
{
	DDRC = 0xFF;
	PORTC = 0x01;
	
	int type = 1;
	int go_right = 1;
	int k = 0;

	USART_Init ( MYUBRR );

	while(1)
	{
		k = USART_Receive();
		
		if (k != 20)
		{
			type = k;
			PORTC = 8;
		}
		
		if (type == 0)
		{
			if (PORTC >= 32)
			{
				_delay_ms(200);
				PORTC = 0x01;
			}
			else
			{
				_delay_ms(200);
				PORTC = PORTC << 1;
			}
		}
		else if (type == 1)
		{
			if (!PORTC)
			{
				PORTC = (1 << 5);
			}
			else
			{
				_delay_ms(200);
				PORTC = PORTC >> 1;
			}
		}
		else if (type == 2)
		{
			if (go_right == -1)
			{
				_delay_ms(200);
				PORTC = PORTC >> 1;
			}
			else if (go_right == 1)
			{
				_delay_ms(200);
				PORTC = PORTC << 1;
			}
			
			if (PORTC  & (1 << 0) || PORTC & (1 << 5))
			{
				go_right = -go_right;
			}
		}
	}
}

