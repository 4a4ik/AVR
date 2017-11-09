/*
 * POV.c
 *
 * Created: 17-Sep-14 8:58:39
 *  Author: 4a4ik
 */ 
# define F_CPU 8000000UL

#define set_1  PORTB |=  (1<<0)
#define clr_1  PORTB &=~ (1<<0)

#define set_2  PORTD |=  (1<<7)
#define clr_2  PORTD &=~ (1<<7)

#define set_3  PORTD |=  (1<<6)
#define clr_3  PORTD &=~ (1<<6)

#define set_4  PORTD |=  (1<<5)
#define clr_4  PORTD &=~ (1<<5)

#define set_5  PORTD |=  (1<<4)
#define clr_5  PORTD &=~ (1<<4)

#define set_6  PORTD |=  (1<<3)
#define clr_6  PORTD &=~ (1<<3)

#define set_7  PORTD |=  (1<<1)
#define clr_7  PORTD &=~ (1<<1)

#define set_8  PORTD |=  (1<<0)
#define clr_8  PORTD &=~ (1<<0)


#define set_9  PORTB |=  (1<<4)
#define clr_9  PORTB &=~ (1<<4)

#define set_10  PORTB |=  (1<<5)
#define clr_10  PORTB &=~ (1<<5)

#define set_11  PORTC |=  (1<<0)
#define clr_11  PORTC &=~ (1<<0)

#define set_12  PORTC |=  (1<<1)
#define clr_12  PORTC &=~ (1<<1)

#define set_13  PORTC |=  (1<<2)
#define clr_13  PORTC &=~ (1<<2)

#define set_14  PORTC |=  (1<<3)
#define clr_14  PORTC &=~ (1<<3)

#define set_15  PORTC |=  (1<<4)
#define clr_15  PORTC &=~ (1<<4)

#define set_16  PORTC |=  (1<<5)
#define clr_16  PORTC &=~ (1<<5)

#define set_R  PORTB &=~ (1<<1) 
#define set_G  PORTB &=~ (1<<2) 
#define set_B  PORTB &=~ (1<<3)
#define clr_c  PORTB |= (1<<1)|(1<<2)|(1<<3)

#define wait _delay_ms(2);

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void light(unsigned int led);

unsigned char type = 0;

ISR(INT0_vect)
{
	type = 1;
}

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	DDRD &= ~(1<<2);
	
	
	GICR  |= (1<<INT0);					// Enable INT0
	MCUCR |= (0<<ISC01)|(1<<ISC00);	// Trigger INT0 on any edge
	
	PORTB |= (1<<1)|(1<<2)|(1<<3);
	PORTD |= (1<<2);
	
	light(0xFFFF);
	
	sei();
	
    while(1)
    {
		
		for(int i = 0; i < 200; i++)
		{
			for(int i = 0; i < 13; i++)
			{
				light( 0b111 << i );
			}
			for(int i = 0; i < 13; i++)
			{
				light( 0b1110000000000000 >> i );
			}
		}
		for(int i = 0; i < 200; i++)
		{
			for(unsigned int k = 1; k < 0b1111111111111111; k = k << 1, k++ )
			{
				light( k );
			}
			for(unsigned int k = 0b1111111111111111; k > 0; k = k >> 1 )
			{
				light( k );
			}
		}
		for(int i = 0; i < 600; i++)
		{
			light( 0 );

			if(type)
			{
				type = 0;
				
				for(int k = 0; k < 15; k++)
				light( 0 );
				
				light( 0b0000000000000000 );
				light( 0b0000000000000000 );
				light( 0b0000000000000000 );
			
				light( 0b1111111100000000 );
				light( 0b0000011100000000 );
				light( 0b0000011100000000 );
				light( 0b1111111111111111 );
			
				light( 0b0000000000000000 );
			
				light( 0b1111111111111111 );
				light( 0b1110000011100000 );	
				light( 0b1110000011100000 );
				light( 0b1111111111111111 );
			
				light( 0b0000000000000000 );
			
				light( 0b1111111100000000 );
				light( 0b0000011100000000 );
				light( 0b0000011100000000 );
				light( 0b1111111111111111 );
			
				light( 0b0000000000000000 );
			
				light( 0b1111111111111111 );
				light( 0b1111111111111111 );
			
				light( 0b0000000000000000 );
			
				light( 0b1111111111111111 );
				light( 0b0000001111000000 );
				light( 0b0000111001110000 );
				light( 0b0011100000011100 );
				light( 0b1110000000000111 );
				type = 0;
			}
		}
		for(int i = 0; i < 600; i++)
		{
			light( 0 );

			if(type)
			{
				type = 0;
				
				for(int k = 0; k < 15; k++)
					light( 0 );
				
				light( 0b0000000000000000 );
				light( 0b0000000000000000 );
				light( 0b0000000000000000 );
				
				light( 0b1110001111111111 );
				light( 0b1110001110000111 );
				light( 0b1110001110000111 );
				light( 0b1111111110000111 );
				
				light( 0b0000000000000000 );
				
				light( 0b0000000000000000 );
				light( 0b0000000000000000 );
				light( 0b0000000000000000 );
				light( 0b1111111111111111 );
				
				light( 0b0000000000000000 );
				light( 0b0001110000111000 );
				light( 0b0000000000000000 );
				
				light( 0b1110001110000111 );
				light( 0b1110001110000111 );
				light( 0b1110001110000111 );
				light( 0b1111111111111111 );
				
				light( 0b0000000000000000 );
				
				light( 0b1110000000000000 );
				light( 0b1110000000000000 );
				light( 0b1110000000000000 );
				light( 0b1111111111111111 );
				
				type = 0;
			}
		}
    }
}

void light(unsigned int led)
{
	//if(type != 0)	return;
	
	PORTB &= ~((1<<0)|(1<<4)|(1<<5));
	PORTC &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));
	PORTD &= ~((1<<0)|(1<<1)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
	
	if(led & 1)	set_1;
		
	if(led & 2)	set_2;
		
	if(led & 4)	set_3;
		
	if(led & 8)	set_4;
		
	if(led & 16)	set_5;
	
	if(led & 32)	set_6;
	
	if(led & 64)	set_7;
	
	if(led & 128)	set_8;
	
	if(led & 256)	set_9;
	
	if(led & 512)	set_10;
	
	if(led & 1024)	set_11;
	
	if(led & 2048)	set_12;
	
	if(led & 4096)	set_13;
	
	if(led & 8192)	set_14;
	
	if(led & 16384)	set_15;
	
	if(led & 32768)	set_16;
	
	wait;
}
