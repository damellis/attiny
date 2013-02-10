/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2012 Scott Daniels - ProvideYourOwn.com

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $

  Pin descr. for ATtinyX313

  TODO - this file has not been tested
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEL ATTINY2313
//
//                   +-\/-+
//      RESET  PA2  1|    |20  VCC
// RX   (D  0) PD0  2|    |19  PB7 (D  16)
// TX   (D  1) PD1  3|    |18  PB6 (D  15)
//      (D  2) PA1  4|    |17  PB5 (D  14)
//      (D  3) PA0  5|    |16  PB4 (D  13) PWM
// INT0 (D  4) PD2  6|    |15  PB3 (D  12) PWM
// INT1 (D  5) PD3  7|    |14  PB2 (D  11) PWM
//      (D  6) PD4  8|    |13  PB1 (D  10)
// PWM  (D  7) PD5  9|    |12  PB0 (D  9)       
//             GND 10|    |11  PD6 (D  8)
//                   +----+


#define NUM_DIGITAL_PINS            17
#define NUM_ANALOG_INPUTS           0

#define digitalPinHasPWM(p)         ((p) == 7 || (p) == 11 || (p) == 12 || (p) == 13)


// there is no PCICR register, but there is a GIMSK equivalent - we'll use that
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 16) ? (&GIMSK) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) ( ((p) >= 9) ? PCIE0 : ( (((p) == 2) || ((p) == 3)) ? PCIE1 : PCIE2 )  )

#define digitalPinToPCMSK(p)    ( ((p) >= 9) ? (&PCMSK0) : ( ( ((p) == 2) || ((p) == 3) ) ? (&PCMSK1) : ( (p <= 8)? (&PCMSK2) : ((uint8_t *)0) )  )  )
#define digitalPinToPCMSKbit(p) ( ((p) >= 9) ? (p) : \
                                  (((p) == 2) || ((p) == 3)) ? (3 - (p)) : \
                                  ((p) <= 1) ? (p) : \
                                  ((p) - 2) )



#ifdef ARDUINO_MAIN



// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = 
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	NOT_A_PORT,
	(uint16_t) &DDRD,
};

const (int16_t PROGMEM port_to_output_PGM[] = 
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	NOT_A_PORT,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = 
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	NOT_A_PORT,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = 
{
	PD, /* 0 */
	PD,
	PA, /* 2 */
	PA,
	PD, /* 4 */
	PD,
	PD,
	PD,
	PD,
	PB, /* 9 */
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
};


const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = 
{
	_BV(0), /* 0 */
	_BV(1),
	_BV(1), /* 2 */
	_BV(0),
	_BV(2), /* 4 */
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(0), /* 9 */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
};


const uint8_t PROGMEM digital_pin_to_timer_PGM[] = 
{
	NOT_ON_TIMER, 
	NOT_ON_TIMER,
	NOT_ON_TIMER,
  NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER0B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER0A,
	TIMER1A,
	TIMER1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};


#endif

#endif
