/*
 * clock_step_motor.c
 *
 * Created: 29-Oct-14 1:21:44
 *  Author: 4a4ik
 */ 

#include "functions.h"


#define wait 10

int main(void)
{
	DDRD  = 0b00000011;
	PORTD = 0b00000000;
	
	DDRB = 0b00000011;
	DDRC = 0b00111111;
	
	IrDA_init();
	lcd_init();
	
	sei();
	
	write_text("Enter number");
	
	move_cursor(0, 2);
	
	write_number(0);
	
//	clear_display();
//	write_text("Entered num:");
	
    while(1)
    {
		
    }
}
