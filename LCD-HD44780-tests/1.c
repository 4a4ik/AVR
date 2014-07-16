/*
 * Text_display.c
 *
 * Created: 10-Jul-14 13:56:31
 *  Author: 4a4ik
 */ 

#define F_CPU 8000000UL

//PORT B
#define PIN_RS 0
#define PIN_RW 1
#define PIN_E  2

//PORT C
#define PIN_DB0  0
#define PIN_DB1  1
#define PIN_DB2  2
#define PIN_DB3  3

//PORT D
#define PIN_DB4  0
#define PIN_DB5  1
#define PIN_DB6  2
#define PIN_DB7  3

#include <avr/io.h>
#include <util/delay.h>

void wait_busy();
void send();

int main(void)
{
	
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	//---wait for initialization
	wait_busy();
	_delay_us(2);

	//---8 bit 2 line mode
	PORTD |= ( 1 << PIN_DB4 )|( 1 << PIN_DB5 );
	PORTC |= ( 1 << PIN_DB3 );
	//send data
	send();
	wait_busy();
	//wait
	_delay_ms(2);
	
	//----turn on display, enable cursor, blniking cursor
	PORTC |= (1 << PIN_DB0 )|(1 << PIN_DB1 )|(1 << PIN_DB2 )|(1 << PIN_DB3 );
	//send data
	send();
	wait_busy();

	//wait
	_delay_us(2);
	
	//---return cursor to beginning
	PORTC |= ( 1 << PIN_DB1 );
	//send data
	send();
	wait_busy();
	//wait
	_delay_ms(2);
	
	//---write symbol
	PORTB |= ( 1 << PIN_RS );
	PORTD |= ( 1 << PIN_DB4 )|( 1 << PIN_DB5 );
	//send data
	send();
	wait_busy();
	//wait
	_delay_ms(2);
	
	//---write symbol
	PORTB |= ( 1 << PIN_RS );
	PORTD |= ( 1 << PIN_DB6 )|( 1 << PIN_DB7 );
	PORTC |= ( 1 << PIN_DB3 );
	//send data
	send();
	wait_busy();
	//wait
	_delay_ms(2);
	
    while(1)
    {
		
    }
}

void wait_busy()
{
	PORTB |= ( 1 << PIN_RW );
	do 
	{
		PORTB &= ~( 1 << PIN_E );
		_delay_us(1);
		PORTB |=  ( 1 << PIN_E );
		
	} while ( PIND & ( 1 << PIN_DB7 ) );
	PORTB = 0;
}

void send()
{
	PORTB |=  ( 1 << PIN_E );
	//wait
	_delay_us(1);
	//don't send
	PORTB &= ~( 1 << PIN_E );
	
	//clear command
	PORTD = 0;
	PORTC = 0;
}
