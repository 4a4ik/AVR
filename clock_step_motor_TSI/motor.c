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

void motor_step(char direction, unsigned char number )
{
	MOTOR_PORT |= ( (1 & direction) << PIN_DIR );		// choose direction of rotation
	
	for(unsigned n = 0; n < number * 20; n++)	// steps
	{
		MOTOR_PORT ^= ( 1 << PIN_STEP );	
		_delay_us(500);
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
		MOTOR_PORT &= ~((1 & direction) << PIN_DIR );
	}
}

void motor_set_time(unsigned char new_time)
{
	unsigned char hours = new_time / 100;
	unsigned char minutes = new_time % 100;
	
	motor_step(1, hours * 60 + minutes );
}
