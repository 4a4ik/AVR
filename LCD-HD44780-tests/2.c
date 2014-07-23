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
void move_cursor( int x_pos, int line );
void add_character( int where, unsigned char line1, unsigned char line2,
unsigned char line3, unsigned char line4, unsigned char line5, unsigned char line6, unsigned char line7, unsigned char line8 );

int main(void)
{
	
	initialize( 1, 1 );
	enable_display( 1, 0, 0 );
	clear_display();
	return_cursor();
	set_mode( 0, 1 );
	
	
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
	PROGRAM_PORT |=  ( 1 << PIN_E );
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
	_delay_us(50);

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

void move_cursor( int x_pos, int line )
{
	
	int small_bit = x_pos % 16;
	int high_bit  = x_pos / 16;
	
	//---moves cursor to the beginning of 2 line
	HIGH_PORT = high_bit;
	HIGH_PORT |= (1 << PIN_DB7 )|((line - 1) << PIN_DB6 );
	LOW_PORT  = small_bit;
	//send data
	send();
	//wait
	_delay_us(50);
}

void add_character( int where, unsigned char line1, unsigned char line2,
unsigned char line3, unsigned char line4, unsigned char line5, unsigned char line6, unsigned char line7, unsigned char line8 )
{
	// starts sending char lines
	int small_bit = where % 16;
	int high_bit  = where / 16;
		
	HIGH_PORT  = high_bit;
	HIGH_PORT |= (1 << PIN_DB6 );
	LOW_PORT   = small_bit;
	
	send();
	
	// 1 line
	small_bit = line1 % 16;
	high_bit  = line1 / 16;
	
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
	
	send();
	
	// 2 line
	small_bit = line2 % 16;
	high_bit  = line2 / 16;
		
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
		
	send();
	
	// 3 line
	small_bit = line3 % 16;
	high_bit  = line3 / 16;
	
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
	
	send();
	
	// 4 line
	small_bit = line4 % 16;
	high_bit  = line4 / 16;
	
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
	
	send();
	
	
	// 5 line
	small_bit = line5 % 16;
	high_bit  = line5 / 16;
		
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
		
	send();
	
	// 6 line
	small_bit = line6 % 16;
	high_bit  = line6 / 16;
	
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
	
	send();
	
	// 7 line
	small_bit = line7 % 16;
	high_bit  = line7 / 16;
	
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
	
	send();
	
	// 8 line
	small_bit = line8 % 16;
	high_bit  = line8 / 16;
	
	HIGH_PORT = high_bit;;
	LOW_PORT  = small_bit;
	PROGRAM_PORT |= (1 << PIN_RS );
	
	send();
	
	// Back to normal regime
	HIGH_PORT |= (1 << PIN_DB7 );
	
	send();
}

