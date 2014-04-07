/*
ICR values for AVR micro controllers to play sound using PWM.
System clock:   8000000 [Hz]
Prescaler:      8
PWM mode:       phase/frequency correct 16 bit

This file was automatically generated using script from 
http://aquaticus.info/pwm-music
*/

#ifndef __PWM_NOTES_H__
#define __PWM_NOTES_H__

/* Pause */

#define P 1
#define PAUSE P
#define p P

/* end of notes table */
#define MUSIC_END 0

/* There are 12 notes in octave + variations (lower case, other names)  */

/* Octave #2 */

#define A2   4545 	/* PWM: 110.01 Hz, note freq: 110.00 Hz, error 0.01% */
#define a2   4545 	/* PWM: 110.01 Hz, note freq: 110.00 Hz, error 0.01% */
#define A2b  4816 	/* PWM: 103.82 Hz, note freq: 103.83 Hz, error 0.01% */
#define a2b  4816 	/* PWM: 103.82 Hz, note freq: 103.83 Hz, error 0.01% */
#define A2x  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define a2x  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define Ais2 4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define ais2 4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define B2   4050 	/* PWM: 123.46 Hz, note freq: 123.47 Hz, error 0.01% */
#define b2   4050 	/* PWM: 123.46 Hz, note freq: 123.47 Hz, error 0.01% */
#define B2b  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define b2b  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define C2   7645 	/* PWM: 65.40 Hz, note freq: 65.41 Hz, error 0.01% */
#define c2   7645 	/* PWM: 65.40 Hz, note freq: 65.41 Hz, error 0.01% */
#define C2x  7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define c2x  7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define Cis2 7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define cis2 7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define D2   6810 	/* PWM: 73.42 Hz, note freq: 73.42 Hz, error 0.01% */
#define d2   6810 	/* PWM: 73.42 Hz, note freq: 73.42 Hz, error 0.01% */
#define D2b  7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define d2b  7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define D2x  6428 	/* PWM: 77.78 Hz, note freq: 77.78 Hz, error 0.00% */
#define d2x  6428 	/* PWM: 77.78 Hz, note freq: 77.78 Hz, error 0.00% */
#define Dis2 6428 	/* PWM: 77.78 Hz, note freq: 77.78 Hz, error 0.00% */
#define dis2 6428 	/* PWM: 77.78 Hz, note freq: 77.78 Hz, error 0.00% */
#define E2   6067 	/* PWM: 82.41 Hz, note freq: 82.41 Hz, error 0.01% */
#define e2   6067 	/* PWM: 82.41 Hz, note freq: 82.41 Hz, error 0.01% */
#define E2b  6428 	/* PWM: 77.78 Hz, note freq: 77.78 Hz, error 0.00% */
#define e2b  6428 	/* PWM: 77.78 Hz, note freq: 77.78 Hz, error 0.00% */
#define F2   5727 	/* PWM: 87.31 Hz, note freq: 87.31 Hz, error 0.00% */
#define f2   5727 	/* PWM: 87.31 Hz, note freq: 87.31 Hz, error 0.00% */
#define F2x  5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define f2x  5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define Fis2 5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define fis2 5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define G2   5102 	/* PWM: 98.00 Hz, note freq: 98.00 Hz, error 0.00% */
#define g2   5102 	/* PWM: 98.00 Hz, note freq: 98.00 Hz, error 0.00% */
#define G2b  5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define g2b  5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define G2x  4816 	/* PWM: 103.82 Hz, note freq: 103.83 Hz, error 0.01% */
#define g2x  4816 	/* PWM: 103.82 Hz, note freq: 103.83 Hz, error 0.01% */
#define Gis2 4816 	/* PWM: 103.82 Hz, note freq: 103.83 Hz, error 0.01% */
#define gis2 4816 	/* PWM: 103.82 Hz, note freq: 103.83 Hz, error 0.01% */
#define H2   4050 	/* PWM: 123.46 Hz, note freq: 123.47 Hz, error 0.01% */
#define h2   4050 	/* PWM: 123.46 Hz, note freq: 123.47 Hz, error 0.01% */
#define H2b  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define h2b  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define bH2  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define bh2  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define xA2  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define xa2  4290 	/* PWM: 116.55 Hz, note freq: 116.54 Hz, error 0.01% */
#define xC2  7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define xc2  7215 	/* PWM: 69.30 Hz, note freq: 69.30 Hz, error 0.01% */
#define xF2  5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define xf2  5405 	/* PWM: 92.51 Hz, note freq: 92.50 Hz, error 0.01% */
#define xG2  5102 	/* PWM: 98.00 Hz, note freq: 98.00 Hz, error 0.00% */
#define xg2  5102 	/* PWM: 98.00 Hz, note freq: 98.00 Hz, error 0.00% */

/* Octave #3 */

#define A3   2273 	/* PWM: 219.97 Hz, note freq: 220.00 Hz, error 0.01% */
#define a3   2273 	/* PWM: 219.97 Hz, note freq: 220.00 Hz, error 0.01% */
#define A3b  2408 	/* PWM: 207.64 Hz, note freq: 207.65 Hz, error 0.01% */
#define a3b  2408 	/* PWM: 207.64 Hz, note freq: 207.65 Hz, error 0.01% */
#define A3x  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define a3x  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define Ais3 2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define ais3 2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define B3   2025 	/* PWM: 246.91 Hz, note freq: 246.94 Hz, error 0.01% */
#define b3   2025 	/* PWM: 246.91 Hz, note freq: 246.94 Hz, error 0.01% */
#define B3b  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define b3b  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define C3   3822 	/* PWM: 130.82 Hz, note freq: 130.81 Hz, error 0.01% */
#define c3   3822 	/* PWM: 130.82 Hz, note freq: 130.81 Hz, error 0.01% */
#define C3x  3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define c3x  3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define Cis3 3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define cis3 3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define D3   3405 	/* PWM: 146.84 Hz, note freq: 146.83 Hz, error 0.01% */
#define d3   3405 	/* PWM: 146.84 Hz, note freq: 146.83 Hz, error 0.01% */
#define D3b  3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define d3b  3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define D3x  3214 	/* PWM: 155.57 Hz, note freq: 155.56 Hz, error 0.00% */
#define d3x  3214 	/* PWM: 155.57 Hz, note freq: 155.56 Hz, error 0.00% */
#define Dis3 3214 	/* PWM: 155.57 Hz, note freq: 155.56 Hz, error 0.00% */
#define dis3 3214 	/* PWM: 155.57 Hz, note freq: 155.56 Hz, error 0.00% */
#define E3   3034 	/* PWM: 164.80 Hz, note freq: 164.81 Hz, error 0.01% */
#define e3   3034 	/* PWM: 164.80 Hz, note freq: 164.81 Hz, error 0.01% */
#define E3b  3214 	/* PWM: 155.57 Hz, note freq: 155.56 Hz, error 0.00% */
#define e3b  3214 	/* PWM: 155.57 Hz, note freq: 155.56 Hz, error 0.00% */
#define F3   2863 	/* PWM: 174.64 Hz, note freq: 174.61 Hz, error 0.02% */
#define f3   2863 	/* PWM: 174.64 Hz, note freq: 174.61 Hz, error 0.02% */
#define F3x  2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define f3x  2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define Fis3 2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define fis3 2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define G3   2551 	/* PWM: 196.00 Hz, note freq: 196.00 Hz, error 0.00% */
#define g3   2551 	/* PWM: 196.00 Hz, note freq: 196.00 Hz, error 0.00% */
#define G3b  2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define g3b  2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define G3x  2408 	/* PWM: 207.64 Hz, note freq: 207.65 Hz, error 0.01% */
#define g3x  2408 	/* PWM: 207.64 Hz, note freq: 207.65 Hz, error 0.01% */
#define Gis3 2408 	/* PWM: 207.64 Hz, note freq: 207.65 Hz, error 0.01% */
#define gis3 2408 	/* PWM: 207.64 Hz, note freq: 207.65 Hz, error 0.01% */
#define H3   2025 	/* PWM: 246.91 Hz, note freq: 246.94 Hz, error 0.01% */
#define h3   2025 	/* PWM: 246.91 Hz, note freq: 246.94 Hz, error 0.01% */
#define H3b  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define h3b  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define bH3  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define bh3  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define xA3  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define xa3  2145 	/* PWM: 233.10 Hz, note freq: 233.08 Hz, error 0.01% */
#define xC3  3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define xc3  3608 	/* PWM: 138.58 Hz, note freq: 138.59 Hz, error 0.01% */
#define xF3  2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define xf3  2703 	/* PWM: 184.98 Hz, note freq: 185.00 Hz, error 0.01% */
#define xG3  2551 	/* PWM: 196.00 Hz, note freq: 196.00 Hz, error 0.00% */
#define xg3  2551 	/* PWM: 196.00 Hz, note freq: 196.00 Hz, error 0.00% */

/* Octave #4 */

#define A4   1136 	/* PWM: 440.14 Hz, note freq: 440.00 Hz, error 0.03% */
#define a4   1136 	/* PWM: 440.14 Hz, note freq: 440.00 Hz, error 0.03% */
#define A4b  1204 	/* PWM: 415.28 Hz, note freq: 415.30 Hz, error 0.01% */
#define a4b  1204 	/* PWM: 415.28 Hz, note freq: 415.30 Hz, error 0.01% */
#define A4x  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define a4x  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define Ais4 1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define ais4 1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define B4   1012 	/* PWM: 494.07 Hz, note freq: 493.88 Hz, error 0.04% */
#define b4   1012 	/* PWM: 494.07 Hz, note freq: 493.88 Hz, error 0.04% */
#define B4b  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define b4b  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define C4   1911 	/* PWM: 261.64 Hz, note freq: 261.63 Hz, error 0.01% */
#define c4   1911 	/* PWM: 261.64 Hz, note freq: 261.63 Hz, error 0.01% */
#define C4x  1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define c4x  1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define Cis4 1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define cis4 1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define D4   1703 	/* PWM: 293.60 Hz, note freq: 293.66 Hz, error 0.02% */
#define d4   1703 	/* PWM: 293.60 Hz, note freq: 293.66 Hz, error 0.02% */
#define D4b  1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define d4b  1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define D4x  1607 	/* PWM: 311.14 Hz, note freq: 311.13 Hz, error 0.00% */
#define d4x  1607 	/* PWM: 311.14 Hz, note freq: 311.13 Hz, error 0.00% */
#define Dis4 1607 	/* PWM: 311.14 Hz, note freq: 311.13 Hz, error 0.00% */
#define dis4 1607 	/* PWM: 311.14 Hz, note freq: 311.13 Hz, error 0.00% */
#define E4   1517 	/* PWM: 329.60 Hz, note freq: 329.63 Hz, error 0.01% */
#define e4   1517 	/* PWM: 329.60 Hz, note freq: 329.63 Hz, error 0.01% */
#define E4b  1607 	/* PWM: 311.14 Hz, note freq: 311.13 Hz, error 0.00% */
#define e4b  1607 	/* PWM: 311.14 Hz, note freq: 311.13 Hz, error 0.00% */
#define F4   1432 	/* PWM: 349.16 Hz, note freq: 349.23 Hz, error 0.02% */
#define f4   1432 	/* PWM: 349.16 Hz, note freq: 349.23 Hz, error 0.02% */
#define F4x  1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define f4x  1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define Fis4 1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define fis4 1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define G4   1276 	/* PWM: 391.85 Hz, note freq: 392.00 Hz, error 0.04% */
#define g4   1276 	/* PWM: 391.85 Hz, note freq: 392.00 Hz, error 0.04% */
#define G4b  1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define g4b  1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define G4x  1204 	/* PWM: 415.28 Hz, note freq: 415.30 Hz, error 0.01% */
#define g4x  1204 	/* PWM: 415.28 Hz, note freq: 415.30 Hz, error 0.01% */
#define Gis4 1204 	/* PWM: 415.28 Hz, note freq: 415.30 Hz, error 0.01% */
#define gis4 1204 	/* PWM: 415.28 Hz, note freq: 415.30 Hz, error 0.01% */
#define H4   1012 	/* PWM: 494.07 Hz, note freq: 493.88 Hz, error 0.04% */
#define h4   1012 	/* PWM: 494.07 Hz, note freq: 493.88 Hz, error 0.04% */
#define H4b  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define h4b  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define bH4  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define bh4  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define xA4  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define xa4  1073 	/* PWM: 465.98 Hz, note freq: 466.16 Hz, error 0.04% */
#define xC4  1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define xc4  1804 	/* PWM: 277.16 Hz, note freq: 277.18 Hz, error 0.01% */
#define xF4  1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define xf4  1351 	/* PWM: 370.10 Hz, note freq: 369.99 Hz, error 0.03% */
#define xG4  1276 	/* PWM: 391.85 Hz, note freq: 392.00 Hz, error 0.04% */
#define xg4  1276 	/* PWM: 391.85 Hz, note freq: 392.00 Hz, error 0.04% */

/* Octave #5 */

#define A5   568  	/* PWM: 880.28 Hz, note freq: 880.00 Hz, error 0.03% */
#define a5   568  	/* PWM: 880.28 Hz, note freq: 880.00 Hz, error 0.03% */
#define A5b  602  	/* PWM: 830.56 Hz, note freq: 830.61 Hz, error 0.01% */
#define a5b  602  	/* PWM: 830.56 Hz, note freq: 830.61 Hz, error 0.01% */
#define A5x  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define a5x  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define Ais5 536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define ais5 536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define B5   506  	/* PWM: 988.14 Hz, note freq: 987.77 Hz, error 0.04% */
#define b5   506  	/* PWM: 988.14 Hz, note freq: 987.77 Hz, error 0.04% */
#define B5b  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define b5b  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define C5   956  	/* PWM: 523.01 Hz, note freq: 523.25 Hz, error 0.05% */
#define c5   956  	/* PWM: 523.01 Hz, note freq: 523.25 Hz, error 0.05% */
#define C5x  902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define c5x  902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define Cis5 902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define cis5 902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define D5   851  	/* PWM: 587.54 Hz, note freq: 587.33 Hz, error 0.04% */
#define d5   851  	/* PWM: 587.54 Hz, note freq: 587.33 Hz, error 0.04% */
#define D5b  902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define d5b  902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define D5x  804  	/* PWM: 621.89 Hz, note freq: 622.25 Hz, error 0.06% */
#define d5x  804  	/* PWM: 621.89 Hz, note freq: 622.25 Hz, error 0.06% */
#define Dis5 804  	/* PWM: 621.89 Hz, note freq: 622.25 Hz, error 0.06% */
#define dis5 804  	/* PWM: 621.89 Hz, note freq: 622.25 Hz, error 0.06% */
#define E5   758  	/* PWM: 659.63 Hz, note freq: 659.26 Hz, error 0.06% */
#define e5   758  	/* PWM: 659.63 Hz, note freq: 659.26 Hz, error 0.06% */
#define E5b  804  	/* PWM: 621.89 Hz, note freq: 622.25 Hz, error 0.06% */
#define e5b  804  	/* PWM: 621.89 Hz, note freq: 622.25 Hz, error 0.06% */
#define F5   716  	/* PWM: 698.32 Hz, note freq: 698.46 Hz, error 0.02% */
#define f5   716  	/* PWM: 698.32 Hz, note freq: 698.46 Hz, error 0.02% */
#define F5x  676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define f5x  676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define Fis5 676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define fis5 676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define G5   638  	/* PWM: 783.70 Hz, note freq: 783.99 Hz, error 0.04% */
#define g5   638  	/* PWM: 783.70 Hz, note freq: 783.99 Hz, error 0.04% */
#define G5b  676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define g5b  676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define G5x  602  	/* PWM: 830.56 Hz, note freq: 830.61 Hz, error 0.01% */
#define g5x  602  	/* PWM: 830.56 Hz, note freq: 830.61 Hz, error 0.01% */
#define Gis5 602  	/* PWM: 830.56 Hz, note freq: 830.61 Hz, error 0.01% */
#define gis5 602  	/* PWM: 830.56 Hz, note freq: 830.61 Hz, error 0.01% */
#define H5   506  	/* PWM: 988.14 Hz, note freq: 987.77 Hz, error 0.04% */
#define h5   506  	/* PWM: 988.14 Hz, note freq: 987.77 Hz, error 0.04% */
#define H5b  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define h5b  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define bH5  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define bh5  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define xA5  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define xa5  536  	/* PWM: 932.84 Hz, note freq: 932.33 Hz, error 0.05% */
#define xC5  902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define xc5  902  	/* PWM: 554.32 Hz, note freq: 554.37 Hz, error 0.01% */
#define xF5  676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define xf5  676  	/* PWM: 739.64 Hz, note freq: 739.99 Hz, error 0.05% */
#define xG5  638  	/* PWM: 783.70 Hz, note freq: 783.99 Hz, error 0.04% */
#define xg5  638  	/* PWM: 783.70 Hz, note freq: 783.99 Hz, error 0.04% */

/* Octave #6 */

#define A6   284  	/* PWM: 1760.56 Hz, note freq: 1760.00 Hz, error 0.03% */
#define a6   284  	/* PWM: 1760.56 Hz, note freq: 1760.00 Hz, error 0.03% */
#define A6b  301  	/* PWM: 1661.13 Hz, note freq: 1661.22 Hz, error 0.01% */
#define a6b  301  	/* PWM: 1661.13 Hz, note freq: 1661.22 Hz, error 0.01% */
#define A6x  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define a6x  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define Ais6 268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define ais6 268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define B6   253  	/* PWM: 1976.28 Hz, note freq: 1975.53 Hz, error 0.04% */
#define b6   253  	/* PWM: 1976.28 Hz, note freq: 1975.53 Hz, error 0.04% */
#define B6b  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define b6b  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define C6   478  	/* PWM: 1046.03 Hz, note freq: 1046.50 Hz, error 0.05% */
#define c6   478  	/* PWM: 1046.03 Hz, note freq: 1046.50 Hz, error 0.05% */
#define C6x  451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define c6x  451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define Cis6 451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define cis6 451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define D6   426  	/* PWM: 1173.71 Hz, note freq: 1174.66 Hz, error 0.08% */
#define d6   426  	/* PWM: 1173.71 Hz, note freq: 1174.66 Hz, error 0.08% */
#define D6b  451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define d6b  451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define D6x  402  	/* PWM: 1243.78 Hz, note freq: 1244.51 Hz, error 0.06% */
#define d6x  402  	/* PWM: 1243.78 Hz, note freq: 1244.51 Hz, error 0.06% */
#define Dis6 402  	/* PWM: 1243.78 Hz, note freq: 1244.51 Hz, error 0.06% */
#define dis6 402  	/* PWM: 1243.78 Hz, note freq: 1244.51 Hz, error 0.06% */
#define E6   379  	/* PWM: 1319.26 Hz, note freq: 1318.51 Hz, error 0.06% */
#define e6   379  	/* PWM: 1319.26 Hz, note freq: 1318.51 Hz, error 0.06% */
#define E6b  402  	/* PWM: 1243.78 Hz, note freq: 1244.51 Hz, error 0.06% */
#define e6b  402  	/* PWM: 1243.78 Hz, note freq: 1244.51 Hz, error 0.06% */
#define F6   358  	/* PWM: 1396.65 Hz, note freq: 1396.91 Hz, error 0.02% */
#define f6   358  	/* PWM: 1396.65 Hz, note freq: 1396.91 Hz, error 0.02% */
#define F6x  338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define f6x  338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define Fis6 338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define fis6 338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define G6   319  	/* PWM: 1567.40 Hz, note freq: 1567.98 Hz, error 0.04% */
#define g6   319  	/* PWM: 1567.40 Hz, note freq: 1567.98 Hz, error 0.04% */
#define G6b  338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define g6b  338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define G6x  301  	/* PWM: 1661.13 Hz, note freq: 1661.22 Hz, error 0.01% */
#define g6x  301  	/* PWM: 1661.13 Hz, note freq: 1661.22 Hz, error 0.01% */
#define Gis6 301  	/* PWM: 1661.13 Hz, note freq: 1661.22 Hz, error 0.01% */
#define gis6 301  	/* PWM: 1661.13 Hz, note freq: 1661.22 Hz, error 0.01% */
#define H6   253  	/* PWM: 1976.28 Hz, note freq: 1975.53 Hz, error 0.04% */
#define h6   253  	/* PWM: 1976.28 Hz, note freq: 1975.53 Hz, error 0.04% */
#define H6b  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define h6b  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define bH6  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define bh6  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define xA6  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define xa6  268  	/* PWM: 1865.67 Hz, note freq: 1864.66 Hz, error 0.05% */
#define xC6  451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define xc6  451  	/* PWM: 1108.65 Hz, note freq: 1108.73 Hz, error 0.01% */
#define xF6  338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define xf6  338  	/* PWM: 1479.29 Hz, note freq: 1479.98 Hz, error 0.05% */
#define xG6  319  	/* PWM: 1567.40 Hz, note freq: 1567.98 Hz, error 0.04% */
#define xg6  319  	/* PWM: 1567.40 Hz, note freq: 1567.98 Hz, error 0.04% */

/* Octave #7 */

#define A7   142  	/* PWM: 3521.13 Hz, note freq: 3520.00 Hz, error 0.03% */
#define a7   142  	/* PWM: 3521.13 Hz, note freq: 3520.00 Hz, error 0.03% */
#define A7b  150  	/* PWM: 3333.33 Hz, note freq: 3322.44 Hz, error 0.33% */
#define a7b  150  	/* PWM: 3333.33 Hz, note freq: 3322.44 Hz, error 0.33% */
#define A7x  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define a7x  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define Ais7 134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define ais7 134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define B7   127  	/* PWM: 3937.01 Hz, note freq: 3951.07 Hz, error 0.36% */
#define b7   127  	/* PWM: 3937.01 Hz, note freq: 3951.07 Hz, error 0.36% */
#define B7b  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define b7b  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define C7   239  	/* PWM: 2092.05 Hz, note freq: 2093.00 Hz, error 0.05% */
#define c7   239  	/* PWM: 2092.05 Hz, note freq: 2093.00 Hz, error 0.05% */
#define C7x  225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define c7x  225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define Cis7 225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define cis7 225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define D7   213  	/* PWM: 2347.42 Hz, note freq: 2349.32 Hz, error 0.08% */
#define d7   213  	/* PWM: 2347.42 Hz, note freq: 2349.32 Hz, error 0.08% */
#define D7b  225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define d7b  225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define D7x  201  	/* PWM: 2487.56 Hz, note freq: 2489.02 Hz, error 0.06% */
#define d7x  201  	/* PWM: 2487.56 Hz, note freq: 2489.02 Hz, error 0.06% */
#define Dis7 201  	/* PWM: 2487.56 Hz, note freq: 2489.02 Hz, error 0.06% */
#define dis7 201  	/* PWM: 2487.56 Hz, note freq: 2489.02 Hz, error 0.06% */
#define E7   190  	/* PWM: 2631.58 Hz, note freq: 2637.02 Hz, error 0.21% */
#define e7   190  	/* PWM: 2631.58 Hz, note freq: 2637.02 Hz, error 0.21% */
#define E7b  201  	/* PWM: 2487.56 Hz, note freq: 2489.02 Hz, error 0.06% */
#define e7b  201  	/* PWM: 2487.56 Hz, note freq: 2489.02 Hz, error 0.06% */
#define F7   179  	/* PWM: 2793.30 Hz, note freq: 2793.83 Hz, error 0.02% */
#define f7   179  	/* PWM: 2793.30 Hz, note freq: 2793.83 Hz, error 0.02% */
#define F7x  169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define f7x  169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define Fis7 169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define fis7 169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define G7   159  	/* PWM: 3144.65 Hz, note freq: 3135.96 Hz, error 0.28% */
#define g7   159  	/* PWM: 3144.65 Hz, note freq: 3135.96 Hz, error 0.28% */
#define G7b  169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define g7b  169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define G7x  150  	/* PWM: 3333.33 Hz, note freq: 3322.44 Hz, error 0.33% */
#define g7x  150  	/* PWM: 3333.33 Hz, note freq: 3322.44 Hz, error 0.33% */
#define Gis7 150  	/* PWM: 3333.33 Hz, note freq: 3322.44 Hz, error 0.33% */
#define gis7 150  	/* PWM: 3333.33 Hz, note freq: 3322.44 Hz, error 0.33% */
#define H7   127  	/* PWM: 3937.01 Hz, note freq: 3951.07 Hz, error 0.36% */
#define h7   127  	/* PWM: 3937.01 Hz, note freq: 3951.07 Hz, error 0.36% */
#define H7b  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define h7b  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define bH7  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define bh7  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define xA7  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define xa7  134  	/* PWM: 3731.34 Hz, note freq: 3729.31 Hz, error 0.05% */
#define xC7  225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define xc7  225  	/* PWM: 2222.22 Hz, note freq: 2217.46 Hz, error 0.21% */
#define xF7  169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define xf7  169  	/* PWM: 2958.58 Hz, note freq: 2959.96 Hz, error 0.05% */
#define xG7  159  	/* PWM: 3144.65 Hz, note freq: 3135.96 Hz, error 0.28% */
#define xg7  159  	/* PWM: 3144.65 Hz, note freq: 3135.96 Hz, error 0.28% */

#endif /* __PWM_NOTES_H__ */
