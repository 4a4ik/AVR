/*
 * Text_display.c
 *
 * Created: 10-Jul-14 13:56:31
 *  Author: 4a4ik
 * 4 bit mode
 */ 

#define F_CPU 8000000UL

#define PROGRAM_PORT PORTB
//PORT B
#define PIN_RS 0
#define PIN_RW 1
#define PIN_E  2

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
void initialize( int _2_line );
void set_mode( int display_shift, int right );
void enable_display( int display_on, int cursor_on, int blinking_on );
void return_cursor();
void clear_display();
void move_cursor( int x_pos, int line );

int main(void)
{
	
	initialize( 1 );
	enable_display( 1, 1, 1 );
	clear_display();
	return_cursor();
	set_mode( 0, 1 );
	
	write_symbol('T');
	write_symbol('e');
	write_symbol('r');
	write_symbol('r');
	write_symbol('a');
	write_symbol('r');
	write_symbol('i');
	write_symbol('a');
	

	
    while(1)
	{
	}
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
}

void write_symbol( char a )
{
	int small_bit = a % 16;
	int high_bit  = a / 16;
	
	PROGRAM_PORT |= (1 << PIN_RS );
	
	HIGH_PORT = high_bit;
	
	send();
	_delay_us(50);
	
	PROGRAM_PORT |= (1 << PIN_RS );	
	HIGH_PORT  = small_bit;

	send();
	_delay_us(50);
}

void initialize( int _2_line )
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;

	_delay_us(50);

	HIGH_PORT |= ( 1 << PIN_DB5 );
	
	send();
	_delay_us(50);
	
	HIGH_PORT |= ( 1 << PIN_DB5 );
	
	send();
	_delay_us(50);
	
	HIGH_PORT  |= ( _2_line << PIN_DB7 );
	
	send();
	_delay_us(50);
}

void enable_display( int display_on, int cursor_on, int blinking_on )
{
	send();
	_delay_us(50);
	
	HIGH_PORT |= (blinking_on << PIN_DB4 )|(cursor_on << PIN_DB5 )|(display_on << PIN_DB6 )|(1 << PIN_DB7 );
	
	send();
	_delay_us(50);
}

void set_mode( int display_shift, int left )
{
	send();
	_delay_us(50);

	HIGH_PORT |= (display_shift << PIN_DB4 )|(left << PIN_DB5 )|(1 << PIN_DB6 );

	send();
	_delay_us(50);
}

void return_cursor()
{
	send();
	_delay_us(50);
	
	HIGH_PORT |= (1 << PIN_DB5 );

	send();
	_delay_us(1550);
}

void clear_display()
{
	send();
	_delay_us(50);

	HIGH_PORT |= (1 << PIN_DB4 );

	send();
	_delay_us(50);
}

void move_cursor( int x_pos, int line )
{
	
	int small_bit = x_pos % 16;
	int high_bit  = x_pos / 16;
	
	HIGH_PORT = high_bit;
	HIGH_PORT |= (1 << PIN_DB7 )|((line - 1) << PIN_DB6 );
	
	send();
	_delay_us(50);
	
	HIGH_PORT  = small_bit;

	send();
	_delay_us(50);
}

