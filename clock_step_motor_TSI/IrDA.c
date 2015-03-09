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
unsigned int win_time = 9999;
unsigned int win_minutes = 9999;	// time player needs to guess
unsigned int current_minutes = 0;

unsigned char numbers_pressed = 0;

unsigned char pwm_move = 0;
unsigned int  pwm_time = 0;


void IrDA_init()
{
	TCCR0 |= (1<<CS02)|(0<<CS01)|(1<<CS00);  // Timer 0 prescaler 1024
//	TIMSK &= ~(1<<TOIE0); // OVERFLOW interrupt disable
	
	MCUCR |= (1<<ISC00)|(1<<ISC01)|(1<<ISC11)|(0<<ISC10); // rising edge INT0 and falling edge INT1
	GICR  |= (1<<INT0)|(1<<INT1); // enable interrupt INT0 and INT1
	
	// timer 1  check for keeping pressed number
	TCCR1B	|= (1<<WGM12);	//  Timer OFF,   CTC compare on OCR1A   
	OCR1A	= 13750; //110 ms
	TIMSK	|= (1<<OCIE1A)|(1<<OCIE2);	// compare OC1A interrupt enable and OCR2
		
	// Timer 2 PWM
	OCR2	= 160; // 124 500 us
	TCCR2	|= (1<<WGM21);	// CTC

	irDA_read_eeprom();
}

void irDA_read_eeprom()
{
	for(int n = 0; n < max_numbers; n++)
		eeprom_read_block (( void *) signal[ n ] , ( const void *)(n * max_signal_length) , max_signal_length);
		
	win_time = (unsigned int)eeprom_read_word (( uint16_t *) 510);
}

void irDA_update_eeprom()
{
	for(int n = 0; n < max_numbers; n++)
		eeprom_update_block (( const void *) signal[ n ] , ( void *)(n * max_signal_length) , max_signal_length) ;
}

void IrDA_write_win_time()
{
	eeprom_update_word (( uint16_t *) 510 , (uint16_t) win_time ) ;
}

ISR(TIMER1_COMPA_vect)
{
	motor_rotate(stop);
	if(pwm_move > 0)
	{
		motor_step(3, 160 - pwm_move);
		pwm_time += 3;
	}
	
	current_minutes = ((current_time / 100) * 60) + (current_time % 100);
		
	//if(pwm_time / 60 != 0)	// set clock format 1200 max
		//pwm_time = 100 * pwm_time / 60 + pwm_time % 60;
		
	if(PINB & (1<<0)) // if rotation is counter counterclockwise
	{
		if(pwm_time > current_minutes)
			current_minutes += 12 * 60;
			
		current_minutes -= pwm_time;
			
	}
	else
	{
		current_minutes += pwm_time;
		
		if(current_minutes >= 12 * 60)
			current_minutes -= 12 * 60;
	}
		
	current_time = current_minutes / 60 * 100 + current_minutes % 60; 
	
	win_minutes = ((win_time / 100) * 60) + (win_time % 100);
	
	if(((current_minutes + 20 >= win_minutes + 20 - 6) && (current_minutes + 20 <= win_minutes + 20 + 6)) || ((current_minutes >= win_minutes + 720 - 6) && (current_minutes <= win_minutes + 720 + 6)) || ((current_minutes + 720 >= win_minutes - 6) && (current_minutes + 720 <= win_minutes + 6))  )
	{
		PORTC |= (1<<5);	// open door
	}
	else
	{
		PORTC &= ~(1<<5);
	}

	pwm_move = 0;
	pwm_time = 0;
	current_minutes = 0;
}

ISR(TIMER2_COMP_vect)
{
	MOTOR_PORT ^= ( 1 << PIN_STEP );
	pwm_move += 1;
		
	if(pwm_move >= 160)
	{
		pwm_time += 3;
		pwm_move = 0;	
	}
	if(pwm_time >= 720) // full circle 12 hours
		pwm_time = 0;
}


ISR(INT1_vect)	// button was pressed
{
	motor_step( counterclockwise, 200 ); // rotate clockwise
	_delay_ms(100);
	motor_step( clockwise, 200 );
	
	_delay_ms(1000);
	
	if(PIND & (1<<3)) // button is not pressed anymore
	{
		//PORTC ^= (1<<5);
		win_time = current_time;
		//move_cursor(0, 1);
		//write_text("new time:");
		IrDA_write_win_time();
	}
	else	// button is still pressed
	{
		motor_step( counterclockwise, 800 ); // rotate clockwise
		_delay_ms(100);
		motor_step( clockwise, 800 );
		
		mode = record_command;
		bit = 0;
		number = 0;
		
		memset(signal, 0, sizeof signal);	// clear the array
		
		//move_cursor(0, 1);
		//write_text("program number:");
		
		//move_cursor(0, 2);
		//write_number(0);
	}
	
			
	
	GIFR  = (1<<INTF0); // clear INT0 interrupt
	TIFR  = (1<<TOV0);  // clear OVERFLOW interrupt
	
	TIMSK &= ~(1<<TOIE0); // OVERFLOW interrupt disable
	GICR  |= (1<<INT0); // enable interrupt INT0
}
	
ISR(INT0_vect)	// IrDA receiver
{	
	TCNT1 = 0;
	if(bit == 0)
	{
		TCNT0 = 0;
		TIFR  = (1<<TOV0);  // clear OVERFLOW interrupt
		TIMSK |= (1<<TOIE0); // enable OVERFLOW interrupt
	}
	
	if(mode == normal && bit < max_signal_length)
	{
		check_signal[ bit ] = TCNT0;
		TCNT0 = 0;
		bit++;
	}
	else if(bit >= max_signal_length && mode == record_command)
		GICR  &= ~(1<<INT0); // disable interrupt INT0
		
	else if(mode == record_command)
	{
		signal[ number ][ bit ] = TCNT0;
		TCNT0 = 0;
		bit++;
	}
	
	if(bit >= max_signal_length - 1)
	{
		GICR  &= ~(1<<INT0); // disable interrupt INT0
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
	//		clear_display();
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
			motor_step( clockwise, 200 ); // rotate clockwise
			_delay_ms(100);
			motor_step( counterclockwise, 200 );
			
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
					motor_step( counterclockwise, 200 ); // rotate clockwise
					_delay_ms(100);
					motor_step( clockwise, 200 );
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
							
							//move_cursor(0, 1);
							//write_number(time);
							motor_set_time(time);
							time = 0;
							numbers_pressed = 0;
						}
						
							
					}
						
					else if(pressed_number == 10)
						motor_rotate(counterclockwise);
					
					else if(pressed_number == 11)
						motor_rotate(clockwise);
					
					else if(pressed_number == 12)
						motor_step(0, 5);
					
					
					break;
				}
			}

	bit = 0;
	GIFR  = (1<<INTF0); // clear INT0 interrupt
	GICR |= (1<<INT0);  // enable interrupt INT0
}
