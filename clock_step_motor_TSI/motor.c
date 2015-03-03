/*
 * motor.c
 *
 * Created: 02.02.2015 23:44:25
 *  Author: 4a4ik
 */ 

#include "functions.h"

#define MOTOR_PORT PORTB
#define PIN_DIR 0
#define PIN_STEP 3

void motor_step(char direction, unsigned int number )
{
	if(1 & direction)	// choose direction of rotation
		MOTOR_PORT |= (1 << PIN_DIR );
	else
		MOTOR_PORT &= ~(1 << PIN_DIR );
		
	unsigned int part = number / 52;	// for speeding up the clock
	
	for(unsigned n = 0; n < number; n++)	// steps
	{
		MOTOR_PORT |= ( 1 << PIN_STEP );
		
		if(number < 60)			_delay_us(400);	// 500 us
		
		else
		{
			if	   (n < part * 1 || n > number - part * 1)			_delay_us(1000);
			else if(n < part * 2 || n > number - part * 2)			_delay_us(960);
			else if(n < part * 3 || n > number - part * 3)			_delay_us(920);
			else if(n < part * 4 || n > number - part * 4)			_delay_us(880);
			else if(n < part * 5 || n > number - part * 5)			_delay_us(840);
			else if(n < part * 6 || n > number - part * 6)			_delay_us(800);
			else if(n < part * 7 || n > number - part * 7)			_delay_us(760);
			else if(n < part * 8 || n > number - part * 8)			_delay_us(720);
			else if(n < part * 9 || n > number - part * 9)			_delay_us(680);
			else if(n < part * 10 || n > number - part * 10)		_delay_us(620);
			else if(n < part * 11 || n > number - part * 11)		_delay_us(580);
			else if(n < part * 12 || n > number - part * 12)		_delay_us(540);
			else if(n < part * 13 || n > number - part * 13)		_delay_us(500);
			else if(n < part * 14 || n > number - part * 14)		_delay_us(460);
			else if(n < part * 15 || n > number - part * 15)		_delay_us(420);
			else if(n < part * 16 || n > number - part * 16)		_delay_us(380);
			else if(n < part * 17 || n > number - part * 17)		_delay_us(340);
			else if(n < part * 18 || n > number - part * 18)		_delay_us(300);
			else if(n < part * 19 || n > number - part * 19)		_delay_us(280);
			else if(n < part * 20 || n > number - part * 20)		_delay_us(240);
			else _delay_us(200);
		}
		
		MOTOR_PORT &= ~( 1 << PIN_STEP );
		
		if(number < 60)			_delay_us(400);	// 500 us
		
		else
		{
			if	   (n < part * 1 || n > number - part * 1)			_delay_us(1000);
			else if(n < part * 2 || n > number - part * 2)			_delay_us(960);
			else if(n < part * 3 || n > number - part * 3)			_delay_us(920);
			else if(n < part * 4 || n > number - part * 4)			_delay_us(880);
			else if(n < part * 5 || n > number - part * 5)			_delay_us(840);
			else if(n < part * 6 || n > number - part * 6)			_delay_us(800);
			else if(n < part * 7 || n > number - part * 7)			_delay_us(760);
			else if(n < part * 8 || n > number - part * 8)			_delay_us(720);
			else if(n < part * 9 || n > number - part * 9)			_delay_us(680);
			else if(n < part * 10 || n > number - part * 10)		_delay_us(620);
			else if(n < part * 11 || n > number - part * 11)		_delay_us(580);
			else if(n < part * 12 || n > number - part * 12)		_delay_us(540);
			else if(n < part * 13 || n > number - part * 13)		_delay_us(500);
			else if(n < part * 14 || n > number - part * 14)		_delay_us(460);
			else if(n < part * 15 || n > number - part * 15)		_delay_us(420);
			else if(n < part * 16 || n > number - part * 16)		_delay_us(380);
			else if(n < part * 17 || n > number - part * 17)		_delay_us(340);
			else if(n < part * 18 || n > number - part * 18)		_delay_us(300);
			else if(n < part * 19 || n > number - part * 19)		_delay_us(280);
			else if(n < part * 20 || n > number - part * 20)		_delay_us(240);
			else _delay_us(200);
		}
	}
}

void motor_rotate(unsigned char direction)
{
	if(direction == 0)
	{
		TCCR2	&= ~(1<<COM20); // OC2 NORMAL operation mode
		TCCR1B	&= ~((1<<CS10)|(1<<CS10));	// Disable timer
		TCNT1 = 0;
	}
	else
	{
		TCCR1B	|= (1<<CS11)|(1<<CS10);	//  No prescaling,  enable timer
		TCCR2	|= (1<<COM20); // OC2 PWM
		TIFR	= (1<<OCF1A);	//clear interrupt flag
		
		if(1 & direction)	// choose direction of rotation
			MOTOR_PORT |= (1 << PIN_DIR );
		else
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
	
	if(minutes > 24 * 60 || (current_time % 100) >= 60 || (minutes == clock_minutes)) // minutes >= 60 the same time
	{
		motor_step( 1, 100 ); // display error
		motor_step( 0, 100 );
		return;	// if error exit function
	}
	
	if(minutes > 12 * 60)	// 12 hours clock format
		minutes -= 12 * 60;
		
	if(minutes > clock_minutes)	// calculate how much steps motor needs to make and in what direction
	{
		steps = ((minutes - clock_minutes) / 3) * 80; //80
		reminder = (minutes - clock_minutes) % 3;
		dir = clockwise;
	}
	
	else
	{
		steps = ((clock_minutes - minutes) / 3) * 80;
		reminder = (clock_minutes - minutes) % 3;
		dir = counterclockwise;
	}
	
	if(steps == 0)
	{
		if(dir == clockwise)
			reminder = (minutes - clock_minutes + 3) % 3;

		else
			reminder = (clock_minutes - minutes + 3) % 3;
	}
	
	
	if(reminder != 0)
	{
		if(reminder == 1)
		{
			if(shift_error <= 1 && shift_error >= -1 )
			{
				if(dir == clockwise)
				{
					steps += 26;
					shift_error++;
				}
				else
				{
					steps += 26;
					shift_error--;
				}
			}
			else
			{
				if(dir == clockwise)
					steps += 28;

				else
					steps += 28;

				shift_error = 0;
			}
		}
		
		else if(reminder == 2)
		{
			if(shift_error == 0)
			{
				if(dir == clockwise)
				{
					steps += 26 * 2;
					shift_error += 2;
				}
				else
				{
					steps += 26 * 2;
					shift_error -= 2;
				}
			}
			else if(shift_error == 1)
			{
				if(dir == clockwise)
				{
					steps += 26 + 28;
					shift_error = 0;
				}
				else
				{
					steps += 26 + 28;
					shift_error = 0;
				}
			}
			else
			{
				if(dir == clockwise)
				{
					steps += 28 + 56;
					shift_error = 1;
				}
				else
				{
					steps += 28 + 26;
					shift_error = -1;
				}
			}
		}
	}
	
	
	motor_step(dir, steps );
	
	current_time = new_time;
	
	if(current_time == win_time)
		PORTC |= (1<<5);
}
