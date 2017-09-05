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
  Modified 04-09-2017 for attiny85 A.Neimar
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// ATMEL ATTINY45 / ARDUINO
//
//                  +-\/-+
// Ain0 (D 5) PB5  1|    |8  Vcc
// Ain3 (D 3) PB3  2|    |7  PB2 (D 2)  Ain1
// Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
//            GND  4|    |5  PB0 (D 0) pwm0
//                  +----+

#define NUM_DIGITAL_PINS            6
#define NUM_ANALOG_INPUTS           4
// #define analogInputToDigitalPin(p)  ((p > 1) && (p < 6) ? (p) + 2 : -1)

#define digitalPinHasPWM(p)         ((p) == 0 || (p) == 1);// || (p) == 3 || (p) == 4)

#define PIN_SPI_SS    (3)
#define PIN_SPI_MOSI  (0)
#define PIN_SPI_MISO  (1)
#define PIN_SPI_SCK   (2)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA        (0)
#define PIN_WIRE_SCL        (2)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_A0   (5)
#define PIN_A1   (2)
#define PIN_A2   (4)
#define PIN_A3   (3)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;

#define digitalPinToPCICR(p)    ( ((p) >= 0 && (p) <= 4) ? (&GIMSK) : ((uint8_t *)0) )
#define digitalPinToPCICRbit(p) ( PCIE )
#define digitalPinToPCMSK(p)    ( ((p) <= 4) ? (&PCMSK) : ((uint8_t *)0) )
#define digitalPinToPCMSKbit(p) ( (p) )

#define analogPinToChannel(p)   ( (p) < 6 ? (p) : (p) - 6 )

#define TCCR1A GTCCR

#ifdef ARDUINO_MAIN

void initVariant()
{
	GTCCR |= (1 << PWM1B);
}

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing) tiny45 only port B 
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &DDRB,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PORTB,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	NOT_A_PIN,
	(uint16_t) &PINB,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PB, /* 0 */
	PB,
	PB,
	PB,
	PB, 
	PB, // 5
	PB, // A0
	PB,
	PB,
	PB, // A4

};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), /* 0, port B */
	_BV(1),
	_BV(2),
	_BV(3), /* 3 port B */
	_BV(4),
	_BV(5),
	_BV(5),
	_BV(2),
	_BV(4),
	_BV(3),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	TIMER0A, /* OC0A */
	TIMER0B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif

#endif