/*
 * motor.c
 *
 * Created: 02.02.2015 23:44:25
 *  Author: 4a4ik
 */ 

#include "functions.h"

#define MOTOR_PORT PORTB
#define PIN_DIR 0
#define PIN_STEP 1

void motor_step(char clockwise, unsigned char number )
{
	MOTOR_PORT |= ( 1 << PIN_DIR );		// choose direction of rotation
	
	for(unsigned n = 0; n < number * 200; n++)	// steps
	{
		MOTOR_PORT ^= ( 1 << PIN_STEP );	
		_delay_us(500);
	}
}
