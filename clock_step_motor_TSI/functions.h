/*
 * functions.h
 *
 * Created: 06-Nov-14 0:21:55
 *  Author: 4a4ik
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <avr/eeprom.h>

void IrDA_init();
void irDA_read_eeprom();
void irDA_update_eeprom();


//--------------display--------------//

void send();
void write_symbol( char a );
void write_number( int a );
void write_text( const char *s );
void initialize( int _2_line );
void set_mode( int display_shift, int right );
void enable_display( int display_on, int cursor_on, int blinking_on );
void return_cursor();
void clear_display();
void move_cursor( int x_pos, int line );
void lcd_init();

//MOTOR
void motor_step(char clockwise, unsigned char number );


#define max_signal_length 40
#define max_numbers 10

#define number_already_recorded 1

extern unsigned char signal[max_numbers][max_signal_length];


#endif /* FUNCTIONS_H_ */
