/*
 * motor.c
 *
 * Created: 02.02.2015 23:44:25
 *  Author: 4a4ik
 */ 

#include "functions.h"



void motor_step(char direction, unsigned int number )
{
	if(direction == counterclockwise)	// choose direction of rotation
		MOTOR_PORT |= (1 << PIN_DIR );
	else if(direction == clockwise)	
		MOTOR_PORT &= ~(1 << PIN_DIR );
		
	unsigned int speed_part = number / 3;
	
	for(unsigned n = 0; n < number; n++)	// steps
	{
		
		if(number < 1600)
			_delay_us(400);	// 500 us
		
		else
		{
			if(n < speed_part)
			{
				for(int k = 0; k < (speed_part - n) / 30; k++)
				{
					_delay_us(1);
				}
			}
			else if(n > number - speed_part)
			{
				for(int k = 0; k < (n - speed_part * 2 ) / 30; k++)
				{
					_delay_us(1);
				}
			}
			
			_delay_us(250);
		}
		
		MOTOR_PORT ^= ( 1 << PIN_STEP );
	}
}



void motor_rotate(unsigned char direction)
{
	if(direction == 0)
	{
		//TCCR2	&= ~(1<<COM20); // OC2 NORMAL operation mode
		TCCR1B	&= ~((1<<CS10)|(1<<CS10));	// Disable timer
		TCCR2	&= ~((1<<CS21)|(1<<CS20));	// clk / 32
		TCNT1 = 0;
		TCNT2 = 0;
		TIMSK	&= ~((1<<OCIE1A)|(1<<OCIE2));
	}
	else
	{
		TCCR1B	|= (1<<CS11)|(1<<CS10);	//  No prescaling,  enable timer
		TCCR2	|= (1<<CS21)|(1<<CS20);	// clk / 32
		//TCCR2	|= (1<<COM20); // OC2 PWM
		TIFR	= (1<<OCF1A);	//clear interrupt flag
		TIMSK	|= (1<<OCIE1A)|(1<<OCIE2);
		
		if(direction == clockwise)	// choose direction of rotation
			MOTOR_PORT |= (1 << PIN_DIR );
		else if(direction == counterclockwise)
			MOTOR_PORT &= ~(1 << PIN_DIR );
	}
}

void motor_set_time(unsigned int new_time)
{
	unsigned int minutes = ((new_time / 100) * 60) + (new_time % 100);
	
	unsigned int clock_minutes = ((current_time / 100) * 60) + (current_time % 100);
	
	char shift_error = 0; // moving error, because we can't set 1 minute precisely
	
	unsigned int steps = 0;
	
	unsigned char reminder = 0;
	
	unsigned char dir = 0;
	
	if(minutes >= 12 * 60)	// 12 hours clock format
		minutes -= 12 * 60;
	
	if(minutes >= 12 * 60 || (new_time % 100) >= 60 || (minutes == clock_minutes)) // minutes >= 60 the same time
	{
		motor_step( counterclockwise, 200 ); // display error
		_delay_ms(100);
		motor_step( clockwise, 200 );
		return;	// if error exit function
	}
	
		
	if(minutes > clock_minutes)	// calculate how much steps motor needs to make and in what direction
	{
		steps = ((minutes - clock_minutes) / 3) * 160; //80
		dir = clockwise;
	}
	
	else
	{
		steps = ((clock_minutes - minutes) / 3) * 160;
		dir = counterclockwise;
	}
	
	if(dir == clockwise)
		reminder = (minutes - clock_minutes + 3) % 3;

	else
		reminder = (clock_minutes - minutes + 3) % 3;

	
	
	if(reminder != 0)
	{
		if(reminder == 1)
		{
			if(shift_error <= 1 && shift_error >= -1 )
			{
				if(dir == clockwise)
				{
					steps += 52;
					shift_error++;
				}
				else
				{
					steps += 52;
					shift_error--;
				}
			}
			else
			{
				if(dir == clockwise)
					steps += 56;

				else
					steps += 56;

				shift_error = 0;
			}
		}
		
		else if(reminder == 2)
		{
			if(shift_error == 0)
			{
				if(dir == clockwise)
				{
					steps += 52 * 2;
					shift_error += 2;
				}
				else
				{
					steps += 52 * 2;
					shift_error -= 2;
				}
			}
			else if(shift_error == 1)
			{
				if(dir == clockwise)
				{
					steps += 52 + 56;
					shift_error = 0;
				}
				else
				{
					steps += 52 + 56;
					shift_error = 0;
				}
			}
			else
			{
				if(dir == clockwise)
				{
					steps += 52 + 56;
					shift_error = 1;
				}
				else
				{
					steps += 56 + 52;
					shift_error = -1;
				}
			}
		}
	}
	
	
	motor_step(dir, steps);
	
	current_time =  minutes / 60 * 100 + minutes % 60; 
	current_minutes = ((current_time / 100) * 60) + (current_time % 100);
	win_minutes = ((win_time / 100) * 60) + (win_time % 100);
	
	if(((current_minutes + 20 >= win_minutes + 20 - 6) && (current_minutes + 20 <= win_minutes + 20 + 6)) || ((current_minutes >= win_minutes + 720 - 6) && (current_minutes <= win_minutes + 720 + 6)) || ((current_minutes + 720 >= win_minutes - 6) && (current_minutes + 720 <= win_minutes + 6))  )
	{
		PORTC |= (1<<5);	// open door
	}
	else
	{
		PORTC &= ~(1<<5);
	}
}
