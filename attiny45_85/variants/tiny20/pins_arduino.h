/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis
  Copyright (c) 2012 Sylvain Leroux
  Copyright (c) 2012 Carlos Delfino - GNU

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

  $Id:$
  
  Modified 22-02-2012 for attiny2313
  Modified 05-12-2012 Carlos Delfino - Merge Work
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// ATMEL ATTINY2313 / ARDUINO
//
//                           +-\/-+
//             (D 10)  PA2  1|    |20  VCC
//             (D 11)  PD0  2|    |19  PB7  (D  7)
//             (D 12)  PD1  3|    |18  PB6  (D  6) 
//             (D  9)  PA1  4|    |17  PB5  (D  5) 
//             (D  8)  PA0  5|    |16  PB4  (D  4)        PWM
//       INT0  (D 13)  PD2  6|    |15  PB3  (D  3)        PWM
//             (D 14)  PD3  7|    |14  PB2  (D  2)        PWM
//             (D 15)  PD4  8|    |13  PB1  (D  1) 
//  PWM        (D 16)  PD5  9|    |12  PB0  (D  0) 
//                     GND 10|    |11  PD6  (D 17) 
//                           +----+

const static uint8_t MOSI = 5;
const static uint8_t MISO = 6;
const static uint8_t SCK  = 7;
// the ATtiny2313 USI Three-wire mode does not have a SS (Slave Select) pin
// const static uint8_t SS = ;

const static uint8_t A0 = 0;
const static uint8_t A1 = 1;
const static uint8_t A2 = 2;
const static uint8_t A3 = 3;
const static uint8_t A4 = 4;
const static uint8_t A5 = 5;
const static uint8_t A6 = 6;
const static uint8_t A7 = 7;

//
// Digital pin to PCICR (Pin Change Interrupt Control Register)
// correspondig to GIMSK (General Interrupt Mask Register) on
// the ATtiny
//
#define digitalPinToPCICR(p)    ( ((p) >= 0 && (p) <= 17) ? (&GIMSK) : ((uint8_t *)0) )


#define digitalPinToPCICRbit(p) ( ((p) <= 7) ? PCIE0 : \
                                  ((p) <= 10) ? PCIE1 : \
                                  PCIE2)

// interrupt pin to mask
// XXX This is plain old wrong
// XXX interrupts are only on PORTB and PCMSK maps to that port's pins
// XXX should check on original files !
#define digitalPinToPCMSK(p)    ( ((p) <= 7) ? (&PCMSK0) : \
                                  ((p) <= 10) ? (&PCMSK1) : \
                                  ((p) <= 17) ? (&PCMSK2) : \
                                  ((uint8_t *)0) )

#define digitalPinToPCMSKbit(p) ( ((p) <= 7) ? (p) : \
                                  ((p) <= 10) ? ((p) - 8) : \
                                  ((p) - 11) )

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&DDRA,
  (uint16_t)&DDRB,
  NOT_A_PORT,
  (uint16_t)&DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PORTA,
  (uint16_t)&PORTB,
  NOT_A_PORT,
  (uint16_t)&PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = 
{
  NOT_A_PIN,
  (uint16_t)&PINA,
  (uint16_t)&PINB,
  NOT_A_PIN,
  (uint16_t)&PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = 
{
  PB, /* 0 */
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PA, /* 8 */
  PA,
  PA,
  PD, /* 11 */
  PD,
  PD,
  PD,
  PD,
  PD,
  PD,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = 
{
  _BV(0), /* port B */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5), 
  _BV(6),
  _BV(7),
  _BV(0), /* port A */
  _BV(1),
  _BV(2),
  _BV(0), /* port D */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = 
{
  NOT_ON_TIMER, /* PORT B */
  NOT_ON_TIMER,
  TIMER0A, /* OC0A on PB2 */
  TIMER1A,
  TIMER1B,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, /* PORT A */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, /* PORT D */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  TIMER0B, /* OC0B on PD5 */
  NOT_ON_TIMER,
};

#endif

#endif
