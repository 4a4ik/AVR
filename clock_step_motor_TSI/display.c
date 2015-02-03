/*
 * display.c
 *
 * Created: 06-Nov-14 23:01:30
 *  Author: 4a4ik
 */ 

#include "functions.h"

#define PROGRAM_PORT PORTC
//PORT B
#define PIN_RS 0
// #define PIN_RW 6 NOT USED
#define PIN_E  1

#define HIGH_PORT PORTC
//PORT D
#define PIN_DB4  5
#define PIN_DB5  4
#define PIN_DB6  3
#define PIN_DB7  2

void send()
{
	PROGRAM_PORT |= ( 1 << PIN_E );
	//wait
	_delay_us(1);
	//don't send
	PROGRAM_PORT &= ~( 1 << PIN_E );
	
	//clear command
	PROGRAM_PORT &= ~(( 1 << PIN_E )|( 1 << PIN_RS ));
	HIGH_PORT    &= ~(( 1 << PIN_DB7 )|( 1 << PIN_DB6 )|( 1 << PIN_DB5 )|( 1 << PIN_DB4 ));
}

void write_symbol( char a )
{
	int small_bit = a % 16;
	int high_bit  = a / 16;
	
	PROGRAM_PORT |= (1 << PIN_RS );
	HIGH_PORT |= (((high_bit & 8 ) >> 3) << PIN_DB7 )|(((high_bit & 4 ) >> 2)  << PIN_DB6 )|(((high_bit & 2 ) >> 1)  << PIN_DB5 )|((high_bit & 1) << PIN_DB4 );
	
	send();
	_delay_us(50);
	
	PROGRAM_PORT |= (1 << PIN_RS );
	HIGH_PORT |= ( ((small_bit & 8 ) >> 3) << PIN_DB7 )|(((small_bit & 4 ) >> 2)  << PIN_DB6 )|(((small_bit & 2 ) >> 1)  << PIN_DB5 )|((small_bit & 1) << PIN_DB4 );

	send();
	_delay_us(50);
}

void write_number( int a )
{
	char buffer[ 7 ];
	itoa( a , buffer, 10);
	
	write_text(buffer);
}

void write_text( const char *s ) 
{
	char c;

	while ( (c = *s++) )
		write_symbol(c);
}

void initialize( int _2_line )
{
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
	_delay_us(1550);
}

void move_cursor( int x_pos, int line )
{
	
	int small_bit = x_pos % 16;
	int high_bit  = x_pos / 16;
	
	HIGH_PORT |= (1 << PIN_DB7 )|((line - 1) << PIN_DB6 )|( high_bit & 2  << PIN_DB5 )|(( high_bit & 1) << PIN_DB4 );
	
	send();
	_delay_us(50);
	
	HIGH_PORT |= ( ((small_bit & 8 ) >> 3) << PIN_DB7 )|(((small_bit & 4 ) >> 2)  << PIN_DB6 )|(((small_bit & 2 ) >> 1)  << PIN_DB5 )|(( small_bit & 1) << PIN_DB4 );

	send();
	_delay_us(50);
}

void lcd_init()
{
	initialize( 1 );
	enable_display( 1, 1, 1 );
	clear_display();
	return_cursor();
	set_mode( 0, 1 );
}
