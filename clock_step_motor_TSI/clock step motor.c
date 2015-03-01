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
	DDRD  = 0b00000000;
	PORTD = 0b00001000;	// INT1 interrupt high level
	
	DDRB = 0b00001011;	// output for motor control
	DDRC = 0b00111111;	// output for display control
	
	IrDA_init();
//	lcd_init();
	
	sei();
	
//	write_text("Pressed number:");
	
//	move_cursor(0, 2);
	
//	write_number(0);
	
//	clear_display();
//	write_text("Entered num:");
	
    while(1)
    {
		
    }
}
