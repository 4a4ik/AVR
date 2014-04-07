/*
	Music demo.

	Microcontroller: ATmega16 or ATmega32
	Clock: 8 MHz
	External hardware: Piezzo buzzer/speaker connected to PD4/OCR1B (PDIP pin 18)
	Compiler: AVR GCC

	http://aquaticus.info/pwm-music

	$Revision: 142 $
*/

#include <avr/io.h>
#include <util/delay.h>

// The output file from notegen.pl script
#include "notes.h"

/// Default volume, value assigned to OCR1B
#define DEFAULT_VOLUME 100

/**
	Initialize timer1

	PWM output on OCR1B
*/

void InitMusic()
{
	// Configure OC1B pin as output

	DDRD |= _BV(DDD4); //OC1B as output

	// timer1 configuration (for PWM)
    TCCR1A |= _BV(COM1B1);  // Clear OC1A/OC1B on compare match

	
	TCCR1B |= _BV(WGM13) 	//mode 8, PWM, Phase and Frequency Correct (TOP value is ICR1)
		   |_BV(CS11); 		//prescaler(8)
}


/**
	Plays music.
*/

void PlayMusic( const int* pMusicNotes /** Pointer to table containing music data */,
				uint8_t tempo /** paying tempo from 0 to 100. Higher value = slower playback*/ )
{
	int duration;
	int note;
	int i;
	uint16_t delay = tempo * 1000;

	while( *pMusicNotes )
	{
		note = *pMusicNotes;
		pMusicNotes++;

		duration = *pMusicNotes;
		pMusicNotes++;

		if( p == note )
		{
			//pause, do not generate any sound
			OCR1B = 0;
		}
		else
		{
			//not a pause, generate tone
			OCR1B = DEFAULT_VOLUME;

			//set frequency
			ICR1H = (note >> 8);
			ICR1L = note;
		}

		//wait duration
		for(i=0;i<32-duration;i++)
		{
			_delay_loop_2( delay );
		}

	}
	

	//turn off any sound
	OCR1B = 0;
}

const int octave[] = {c4, 8, d4, 8, e4, 8, f4, 8, g4, 8, a4, 8, h4, 8, c5, 8, MUSIC_END};


// Star Wars
const int starwars[] = 
{
	Ais2,8, Ais2,8, P,16, F3,8, F3,8, P,16, Dis3,16, P,16, D3,16, P,16, C3,16, P,16, Ais3,8,
	Ais3,8, P,16, F3,8, P,16, Dis3,16, P,16, D3,16, P,16, C3,16, P,16, Ais3,8, Ais3,8, P,16,
	F3,8, P,16, Dis3,16, P,16, D3,16, P,16, Dis3,16, P,16, C3,8, C3,8, 
	MUSIC_END
};

// Fur Elise
const int furelise[] = 
{
    e4, 8, d4x, 8, e4, 8, d4x, 8, e4, 8, b3, 8, d4, 8, c4, 8, a3,8, p, 8,
    c3, 8, e3, 8, a3, 8,  b3, 4, p, 8, e3, 8, g3x, 8, b3, 8, c4, 4, p, 8, e3, 8,
    e3, 8, d4x, 8, e4, 8, d4x, 8, e4, 8, b3, 8, d4, 8, c4, 8, a3, 8, p, 8, c3, 8,
    e3, 8, a3, 8, b3, 4, p, 8, e3, 8, c4, 8, b3, 8, a3, 4,
    MUSIC_END
};

// Beatles, Hey Jude
const int Jude[] = {
	G2,8, E2,8, P,16, E2,16, E2,16, G2,16, A2,16, D2,8, P,16, D2,16, E2,16, F2,8, 
	C3,8, C3,16, C3,16, H2,16, G2,16, A2,16, G2,16, F2,16, E2,8, P,16, G2,16, 
	A2,16, A2,8, A2,16, D3,16, C3,16, H2,16, H2,16, C3,16, A2,16, G2,8, P,16, 
	C2,16, D2,16, E2,16, A2,16, A2,16, G2,8,
	MUSIC_END
};


main()
{
	InitMusic();

	while(1)
	{

		PlayMusic( octave, 40 );
		_delay_ms(1000);

		PlayMusic( furelise, 20 );
		_delay_ms(1000);


		PlayMusic( starwars, 17 );
		_delay_ms(1000);

		PlayMusic( Jude, 35 );
		_delay_ms(1000);
	}

}
