/*
 * NOKIA_5110_LCD.c
 *
 * Created: 27-Jul-14 14:41:17
 *  Author: 4a4ik
 */ 

#define F_CPU 8000000UL


#define LCD_RST_set  PORTD |=  (1<<0)    //external reset input
#define LCD_RST_clr  PORTD &=~ (1<<0)

#define LCD_DC_set   PORTD |=  (1<<1)    //data/commande
#define LCD_DC_clr   PORTD &=~ (1<<1)

#define SDIN_set     PORTD |=  (1<<2)    //serial data input
#define SDIN_clr     PORTD &=~ (1<<2)

#define SCLK_set     PORTD |=  (1<<3)    //serial clock input
#define SCLK_clr     PORTD &= ~(1<<3)

#include <avr/io.h>
#include <util/delay.h>
#include "english_font.h"

void LCD_write_byte(unsigned char dat, unsigned char command);
void LCD_init();
void LCD_clear();
void LCD_set_XY(unsigned char X, unsigned char Y);
void LCD_write_char(unsigned char c);
void LCD_write_english_string(unsigned char X,unsigned char Y,char *s);

int main(void)
{
	DDRD = 0x0F;
	
	LCD_init();       //LCD initialization
	LCD_clear();      //clear the LCD
	
	LCD_write_english_string(0,0," Hello World ! ");   
	LCD_write_english_string(0,1," bananas ");    
	LCD_write_english_string(0,2,"dancing potato");
	LCD_write_english_string(0,3," tomato");
	LCD_write_english_string(0,4,"   with love ");
	LCD_write_english_string(0,5,"   from 4a4ik ");

	
    while(1)
    {
    }
}

void LCD_write_byte(unsigned char dat, unsigned char command)
{
	unsigned char i;
	
	if (command == 0)
	LCD_DC_clr;
	else
	LCD_DC_set;

	for(i=0;i<8;i++)
	{
		if(dat&0x80)
		SDIN_set;
		else
		SDIN_clr;
		SCLK_clr;
		dat = dat << 1;
		SCLK_set;
	}
}

void LCD_init() 
{
	LCD_RST_clr;
	_delay_us(1);
	LCD_RST_set;

	_delay_us(1);

	LCD_write_byte(0x21, 0);	// set LCD mode
	LCD_write_byte(0xc8, 0);	// set bias voltage
	LCD_write_byte(0x06, 0);	// temperature correction
	LCD_write_byte(0x13, 0);	// 1:48
	LCD_write_byte(0x20, 0);	// use bias command
	LCD_clear();	                // clear the LCD
	LCD_write_byte(0x0c, 0);	// set LCD mode,display normally
}

void LCD_clear() 
{
	unsigned int i;

	LCD_write_byte(0x0c, 0);
	LCD_write_byte(0x80, 0);

	for (i=0; i<504; i++)
	{
		LCD_write_byte(0, 1);
	}
}

void LCD_set_XY(unsigned char X, unsigned char Y)
{
	LCD_write_byte(0x40 | Y, 0);	// column
	LCD_write_byte(0x80 | X, 0);    // row
}

void LCD_write_char(unsigned char c)
{
	unsigned char line;

	c -= 32;

	for (line=0; line<6; line++)
	LCD_write_byte(font6x8[c][line], 1);
}

void LCD_write_english_string(unsigned char X,unsigned char Y,char *s)
{
	LCD_set_XY(X,Y);
	while (*s)
	{
		LCD_write_char(*s);
		s++;
	}
}
