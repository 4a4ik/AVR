/*
 * Text_display.c
 *
 * Created: 10-Jul-14 13:56:31
 *  Author: 4a4ik
 */ 

#define F_CPU 8000000UL

#define PROGRAM_PORT PORTB
//PORT B
#define PIN_RS 0
#define PIN_RW 1
#define PIN_E  2

#define LOW_PORT PORTC
//PORT C
#define PIN_DB0  0
#define PIN_DB1  1
#define PIN_DB2  2
#define PIN_DB3  3

#define HIGH_PORT PORTD
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
void set_mode( int display_shift, int cursor_shift );
void enable_display( int display_on, int cursor_on, int blinking_on );
void return_cursor();
void clear_display();
void go_to_2_line();

int main(void)
{
	
	initialize( 1, 1 );
	set_mode( 0, 1 );
	enable_display( 1, 0, 0 );
	clear_display();
	return_cursor();
	
	
	write_symbol(' ');
	write_symbol(' ');
	write_symbol(' ');
	write_symbol(' ');
	write_symbol(' ');
	
	write_symbol('4');
	write_symbol('a');
	write_symbol('4');
	write_symbol('i');
	write_symbol('k');
	

    while(1);
}


void send()
{
	PROGRAM_PORT |= ( 1 << PIN_E );
	//wait
	_delay_us(1);
	//don't send
	PROGRAM_PORT &= ~( 1 << PIN_E );
	
	//clear command
	PROGRAM_PORT = 0;
	HIGH_PORT    = 0;
	LOW_PORT     = 0;
}

void write_symbol( char a )
{
	int small_bit = a % 16;
	int high_bit  = a / 16;
	
	PROGRAM_PORT |= (1 << PIN_RS );
	
	LOW_PORT  = small_bit;
	HIGH_PORT = high_bit;
	
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
	PROGRAM_PORT |= ( 1 << PIN_RW );
	do
	{
		PROGRAM_PORT &= ~( 1 << PIN_E );
		_delay_us(1);
		PROGRAM_PORT |= ( 1 << PIN_E );
		
	} while ( PIND & ( 1 << PIN_DB7 ) );
	PROGRAM_PORT = 0;

	//---8 bit 2 line mode
	HIGH_PORT |= ( bit_num << PIN_DB4 )|( 1 << PIN_DB5 );
	LOW_PORT  |= ( line_num << PIN_DB3 );
	//send data
	send();
	
	//wait
	_delay_us(50);
}

void enable_display( int display_on, int cursor_on, int blinking_on )
{
	//----turn on display, enable cursor, blniking cursor
	LOW_PORT |= (blinking_on << PIN_DB0 )|(cursor_on << PIN_DB1 )|(display_on << PIN_DB2 )|(1 << PIN_DB3 );
	//send data
	send();
	//wait
	_delay_us(50);
}

void set_mode( int display_shift, int cursor_shift )
{
	//----turn on display, enable cursor, blniking cursor
	LOW_PORT |= (display_shift << PIN_DB0 )|(cursor_shift << PIN_DB1 )|(1 << PIN_DB2 );
	//send data
	send();
	//wait
	_delay_us(50);
}

void return_cursor()
{
	//---return cursor to beginning
	LOW_PORT |= (1 << PIN_DB1 );
	//send data
	send();
	//wait
	_delay_us(1550);
}

void clear_display()
{
	//---return cursor to beginning
	LOW_PORT |= (1 << PIN_DB0 );
	//send data
	send();
	//wait
	_delay_us(50);
}

void go_to_2_line()
{
	//---moves cursor to the beginning of 2 line
	HIGH_PORT |= (1 << PIN_DB7 )|(1 << PIN_DB6 )|(0 << PIN_DB5 )|(0 << PIN_DB4 );
	LOW_PORT  |= (0 << PIN_DB3 )|(0 << PIN_DB2 )|(0 << PIN_DB1 )|(0 << PIN_DB0 );
	//send data
	send();
	//wait
	_delay_us(50);
}

