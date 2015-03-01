/*
 * IrDA.c
 *
 * Created: 06-Nov-14 0:20:48
 *  Author: 4a4ik
 */ 

/*
 *	connect (INT0) PD2	
 *	to the receiver
 *
 *	Timer0 IrDa
 *	Timer1 16 bit PWM
 *	Timer2 wait if button is pressed, when overflow stop rotating the motor
 */

#include "functions.h"

#define normal 0
#define record_command 1
#define wait_c 2


unsigned char mode = normal;

unsigned char bit = 0, pressed_number, number = 10;

unsigned char signal[max_numbers][max_signal_length] = {{ 0 }};
unsigned char check_signal[max_signal_length] = { 0 };
	
unsigned int time = 0;	// dummy for getting time from TV remote
unsigned int current_time = 0;	// current time set on the clock
unsigned int win_time = 0;	// time player needs to guess

unsigned char numbers_pressed = 0;

void IrDA_init()
{
	TCCR0 |= (1<<CS02)|(0<<CS01)|(1<<CS00);  // Timer 0 prescaler 1024
	TIMSK &= ~(1<<TOIE0); // OVERFLOW interrupt disable
	
	MCUCR |= (1<<ISC00)|(1<<ISC01)|(1<<ISC11)|(0<<ISC10); // rising edge INT0 and falling edge INT1
	GICR  |= (1<<INT0)|(1<<INT1); // enable interrupt INT0 and INT1
	
	// timer 1  check for keeping pressed number
	TCCR1B	|= (1<<WGM12);	//  Timer OFF,   CTC compare on OCR1A   
	OCR1A	= 13750; //110 ms
	TIMSK	|= (1<<OCIE1A);	// compare OC1A interrupt enable
	
	// Timer 2 PWM
	TCCR2	|= (1<<WGM21)|(0<<COM20)|(1<<CS21)|(1<<CS20);	// CTC, DON'T toggle IC2, clk / 32
	OCR2	= 200; // 124 500 us
	

	irDA_read_eeprom();
}

void irDA_read_eeprom()
{
	for(int n = 0; n < max_numbers; n++)
		eeprom_read_block (( void *) signal[ n ] , ( const void *)(n * max_signal_length) , max_signal_length) ;
}

void irDA_update_eeprom()
{
	for(int n = 0; n < max_numbers; n++)
		eeprom_update_block (( const void *) signal[ n ] , ( void *)(n * max_signal_length) , max_signal_length) ;
}

ISR(TIMER1_COMPA_vect)
{
	motor_rotate(stop);
}


ISR(INT1_vect)
{
	motor_step( 1, 200 ); // rotate clockwise
	motor_step( 0, 200 );
	
	mode = record_command;
	bit = 0;
	number = 0;
	
	memset(signal, 0, sizeof signal);	// clear the array
	
//	move_cursor(0, 1);
//	write_text("program number:");
		
//	move_cursor(0, 2);
//	write_number(0);
	
	GIFR |= (1<<INTF0); // clear INT0 interrupt
	TIFR  |= (1<<TOV0);  // clear OVERFLOW interrupt
	
	TIMSK &= ~(1<<TOIE0); // OVERFLOW interrupt disable
	GICR  |= (1<<INT0); // enable interrupt INT0
}
	
ISR(INT0_vect)
{
	TCNT1 = 0;	// Clear rotation button pressed timer
	
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
	
	TCNT1 = 0;	// Clear rotation button pressed timer
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
//			clear_display();
//			write_text("Entered num:");
			
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
			motor_step( 1, 200 ); // rotate clockwise
			motor_step( 0, 200 );
			
			number++;
//			move_cursor(0, 2);
//			write_number(number);
//			move_cursor(4, 2);
//			write_symbol(' ');
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
//						move_cursor(4, 2);
//						write_symbol('x');
						i = number;
						break;
					}
				}
				if(i == number - 1)
				{
					motor_step( 1, 200 ); // rotate clockwise
					motor_step( 0, 200 );
					number++;
//					move_cursor(0, 2);
//					write_number(number);
//					move_cursor(4, 2);
//					write_symbol(' ');
					
					if(number == max_numbers )
					{
						irDA_update_eeprom();
//						clear_display();
//						write_text("Entered num:");
						
						mode = normal;
					}

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
					//move_cursor(0, 2);
					//write_number(pressed_number);
					
					if(pressed_number < 10)
					{
						//motor_step(1, pressed_number);
						
						if(numbers_pressed == 0)
						{
							time += pressed_number;
							numbers_pressed++;
						}
						else if(numbers_pressed < 3)
						{
							time *= 10;
							time += pressed_number;
							numbers_pressed++;
						}
						else if(numbers_pressed == 3)
						{
							time *= 10;
							time += pressed_number;
							
//							move_cursor(0, 2);
//							write_number(time);
							motor_set_time(time);
							time = 0;
							numbers_pressed = 0;
						}
						
							
					}
						
					else if(pressed_number == 10)
						motor_rotate(clockwise);
					
					else if(pressed_number == 11)
						motor_rotate(counterclockwise);
					
					else if(pressed_number == 12)
						motor_step(0, 1);
					
					
					break;
				}
			}

	bit = 0;
	GIFR |= (1<<INTF0); // clear INT0 interrupt
	GICR |= (1<<INT0);  // enable interrupt INT0
}
