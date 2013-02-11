/*
  pins_arduino.c - pin definitions for the Arduino board
  Part of Arduino / Wiring Lite

  Copyright (c) 2005 David A. Mellis

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

  $Id: pins_arduino.c 565 2009-03-25 10:50:00Z dmellis $

  Modified 28-08-2009 for attiny84 R.Wiersma
  Modified 09-10-2009 for attiny45 A.Saporetti
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// ATMEL ATTINY84 / ARDUINO
//
//                           +-\/-+
//                     VCC  1|    |14  GND
//             (D 10)  PB0  2|    |13  AREF (D  0) (A0/AREF)
//             (D  9)  PB1  3|    |12  PA1  (D  1) (A1)
//             RESET   PB3  4|    |11  PA2  (D  2) (A2)
//  PWM  INT0  (D  8)  PB2  5|    |10  PA3  (D  3) (A3)
//  PWM    (A7)(D  7)  PA7  6|    |9   PA4  (D  4) (A4)
//  PWM    (A6)(D  6)  PA6  7|    |8   PA5  (D  5) (A5)  PWM
//                           +----+

// In like fashion to the Arduino, we don't count the RESET pin (unlike the ATtinyX5 series), but this define can be changed to 12 if the RESET pin is to be used for I/O
// NOTE: the reset pin is not supported for pcint or Software Serial
#define NUM_DIGITAL_PINS            11
#define NUM_ANALOG_INPUTS           8

#define digitalPinHasPWM(p)         ((p) == 5 || (p) == 6 || (p) == 7 || (p) == 8)

// the ATtinyX4 series USI Three-wire mode does not have a SS (Slave Select) pin
const static uint8_t SS   = -1; /* don't know if this works with SPIClass in SPI.cpp */
const static uint8_t MOSI = 6;
const static uint8_t MISO = 5;
const static uint8_t SCK  = 4;

const static uint8_t SDA = 6;
const static uint8_t SCL = 4;
const static uint8_t LED_BUILTIN = -1;

const static uint8_t A0 = 0;
const static uint8_t A1 = 1;
const static uint8_t A2 = 2;
const static uint8_t A3 = 3;
const static uint8_t A4 = 4;
const static uint8_t A5 = 5;
const static uint8_t A6 = 6;
const static uint8_t A7 = 7;

#define digitalPinToPCICR(p)    ( ((p) >= 0 && (p) <= 10) ? (&GIMSK) : ((uint8_t *)0) )
#define digitalPinToPCICRbit(p) ( ((p) <= 7) ? PCIE0 : PCIE1 )
#define digitalPinToPCMSK(p)    ( ((p) <= 7) ? (&PCMSK0) : (((p) <= 10) ? (&PCMSK1) : ((uint8_t *)0)) )
#define digitalPinToPCMSKbit(p) ( ((p) <= 7) ? (p) : (10 - (p)) )

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&DDRA,
  (uint16_t)&DDRB,
};

const uint16_t PROGMEM port_to_output_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PORTA,
  (uint16_t)&PORTB,
};

const uint16_t PROGMEM port_to_input_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PINA,
  (uint16_t)&PINB,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = 
{
  PA, /* 0 */
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PB, /* 8 */
  PB,
  PB,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = 
{
  _BV(0), /* port A */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5), 
  _BV(6),
  _BV(7),
  _BV(2), /* port B */
  _BV(1),
  _BV(0),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = 
{
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, 
  NOT_ON_TIMER,
  TIMER1B, /* OC1B */
  TIMER1A, /* OC1A */
  TIMER0B, /* OC0B */
  TIMER0A, /* OC0A */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
};

#endif

#endif
