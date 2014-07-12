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

void send();
void write_symbol( char a );
void initialize( int bit_num, int line_num );
void enable_display( int display_on, int cursor_on, int blinking_on );
void return_cursor();

int main(void)
{
	
	initialize( 1, 1 );
	enable_display( 1, 0, 0 );
	return_cursor();	
	
	write_symbol('4');
	write_symbol('a');
	write_symbol('4');
	write_symbol('i');
	write_symbol('k');
	
	
    while(1);
}


void send()
{
	PORTB |= ( 1 << PIN_E );
	//wait
	_delay_us(1);
	//don't send
	PORTB &= ~( 1 << PIN_E );
	
	//clear command
	PORTD = 0;
	PORTC = 0;
}

void write_symbol( char a )
{
	int small_bit = a % 16;
	int high_bit = a / 16;
	
	PORTB |= (1 << PIN_RS );
	
	PORTC = small_bit;
	PORTD = high_bit;
	
	//send data
	send();
	//wait
	_delay_us(50);
}

void initialize( int bit_num, int line_num )
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	//---wait for initialization
	//check busy flag
	PORTB |= ( 1 << PIN_RW );
	do
	{
		PORTB &= ~( 1 << PIN_E );
		_delay_us(1);
		PORTB |= ( 1 << PIN_E );
		
	} while ( PIND & ( 1 << PIN_DB7 ) );
	PORTB = 0;

	//---8 bit 2 line mode
	PORTD |= ( bit_num << PIN_DB4 )|( 1 << PIN_DB5 );
	PORTC |= ( line_num << PIN_DB3 );
	//send data
	send();
	
	
	
	//wait
	_delay_us(50);
}

void enable_display( int display_on, int cursor_on, int blinking_on )
{
	//----turn on display, enable cursor, blniking cursor
	PORTC |= (blinking_on << PIN_DB0 )|(cursor_on << PIN_DB1 )|(display_on << PIN_DB2 )|(1 << PIN_DB3 );
	//send data
	send();
	//wait
	_delay_us(50);
}

void return_cursor()
{
	//---return cursor to beginning
	PORTC |= (1 << PIN_DB1 );
	//send data
	send();
	//wait
	_delay_us(1550);
}
