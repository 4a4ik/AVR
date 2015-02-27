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
	
	for(unsigned n = 0; n < number; n++)	// steps
	{
		MOTOR_PORT ^= ( 1 << PIN_STEP );	
		_delay_ms(1);	// 500 us
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
		TIFR	|= (1<<OCF1A);	//clear interrupt flag
		
		if(1 & direction)	// choose direction of rotation
			MOTOR_PORT |= (1 << PIN_DIR );
		else
			MOTOR_PORT &= ~(1 << PIN_DIR );
	}
}

void motor_set_time(unsigned int new_time)
{
	char hours = new_time / 100;
	char minutes = new_time % 100;
	
	char clock_hours = current_time / 100;
	char clock_minutes = current_time % 100;
	
	unsigned int steps = 0;
	
	unsigned char dir = 0;
	
	if(hours > 24)
	{
		motor_step( 1, 3200 ); // display error
		motor_step( 0, 3200 );
		return;	// if error exit function
	}
	
	if(hours > 12)	// 12 hours clock format
		hours -= 12;
		
	if(hours > clock_hours)	// calculate how much steps motor needs to make and in what direction
	{
		steps = (hours - clock_hours) * 3200;
		dir = clockwise;
	}
	
	else
	{
		steps = (clock_hours - hours) * 3200;
		dir = counterclockwise;
	}
	
	if(hours == clock_hours)
	{
		if(minutes > clock_minutes)
		{
			dir = clockwise;
		}
		else
		{
			steps += 3200;
			dir = counterclockwise;
		}
	}
	
	if(minutes > clock_minutes)	// calculate how much steps motor needs to make and in what direction
	{
		steps += (minutes - clock_minutes) * 53;
	}
	
	else
	{
		steps -= (clock_minutes - minutes) * 53;
	}
	
	motor_step(dir, steps );
	
	current_time = new_time;
}
