/*
 * IrDA.c
 *
 * Created: 06-Nov-14 0:20:48
 *  Author: 4a4ik
 */ 

/*
 *	connect (INT0) PD2	
 *	to the receiver
 */

#include "functions.h"

#define normal 0
#define record_command 1
#define wait_c 2



unsigned char mode = normal;

unsigned char bit = 0, pressed_number, number = 10;

unsigned char signal[max_numbers][max_signal_length] = {{ 0 }};
unsigned char check_signal[max_signal_length] = { 0 };

void IrDA_init()
{
	TCCR0 |= (1<<CS02)|(0<<CS01)|(1<<CS00);  // Timer 0 prescaler 1024
	TIMSK &= ~(1<<TOIE0); // OVERFLOW interrupt disable
	
	MCUCR |= (1<<ISC00)|(1<<ISC01); // rising edge INT0
	GICR  |= (1<<INT0); // enable interrupt INT0

	irDA_read_eeprom();
}

void irDA_read_eeprom()
{
	for(int n = 0; n < max_numbers; n++)
		eeprom_read_block (( void *) signal[ n ] , ( const void *)(n * 40) , 40) ;
}

void irDA_update_eeprom()
{
	for(int n = 0; n < max_numbers; n++)
		eeprom_update_block (( const void *) signal[ n ] , ( void *)(n * 40) , 40) ;
}
	
ISR(INT0_vect)
{
	if(bit == 0)
	{
		TCNT0 = 0;
		TIFR  |= (1<<TOV0);  // clear OVERFLOW interrupt
		TIMSK |= (1<<TOIE0); // enable OVERFLOW interrupt
	}
	
	if(bit >= max_signal_length && mode == record_command)
		GICR  &= ~(1<<INT0); // disable interrupt INT0
		
	else if(mode == record_command)
	{
		signal[ number ][ bit ] = TCNT0;
		TCNT0 = 0;
		bit++;
	}
	else if(mode == normal)
	{
		check_signal[ bit ] = TCNT0;
		TCNT0 = 0;
		bit++;
	}
}

ISR(TIMER0_OVF_vect)
{	
	GICR  &= ~(1<<INT0); // disable interrupt INT0
	TIMSK &= ~(1<<TOIE0); // OVERFLOW interrupt disable

	if(mode == wait_c)
	{
		if(signal[max_numbers - 1][ 8 ] == 0)
			mode = record_command;
		
		else
		{
			clear_display();
			write_text("Entered num:");
			
			mode = normal;
		}
	}
	else if(mode == record_command)
	{
		if(bit <= 7)
		{
			mode = wait_c;
		}
		else if(number == 0)
		{
			number++;
			move_cursor(0, 2);
			write_number(number);
			move_cursor(4, 2);
			write_symbol(' ');
		}
			

		else if(number < max_numbers)
		{
			mode = wait_c;
			TIMSK |= (1<<TOIE0); // enable OVERFLOW interrupt
			
			for(int i = 0; i < number; i++)
			{
				for(int n = 1; n < max_signal_length; n++)
				{
					if(signal[ i ][ n ] <= signal[ number ][ n ] - 2 || signal[ i ][ n ] >= signal[ number ][ n ] + 2)
						break;

					else if (n >= max_signal_length - 1 || signal[ number ][ n + 1 ] == 0)
					{
						move_cursor(4, 2);
						write_symbol('x');
						i = number;
						break;
					}
				}
				if(i == number - 1)
				{
					number++;
					move_cursor(0, 2);
					write_number(number);
					move_cursor(4, 2);
					write_symbol(' ');
					
					if(number == max_numbers )
						irDA_update_eeprom();

					break;
				}
			}
		}
	}
		
	else if(mode == normal)
		for(int i = 0; i < max_numbers; i++)
			for(int n = 1; n < max_signal_length; n++)
			{
				if(signal[ i ][ n ] <= check_signal[ n ] - 2 || signal[ i ][ n ] >= check_signal[ n ] + 2)
					break;
					
				else if (n >= max_signal_length - 1 || check_signal[ n + 1 ] == 0)
				{
					pressed_number = i;
					move_cursor(0, 2);
					write_number(pressed_number);
					motor_step(1, pressed_number);
					break;
				}
			}

	bit = 0;
	GIFR |= (1<<INTF0); // clear INT0 interrupt
	GICR |= (1<<INT0);  // enable interrupt INT0
}
