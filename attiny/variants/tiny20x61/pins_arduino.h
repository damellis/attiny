/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

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

  Pin descr. for ATtiny20x7
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// ATMEL ATTINY87/167 / ARDUINO
//
//                           +-\/-+
//                   (MOSI/DI/SDA/OC1A/PCINT8)     (D8) PB0  1|    |20  PA0 (D0)(A0)   (ADC0/DI/SDA/PCINT0)
//         PWM           (MISO/DO/OC1A/PCINT9)     (D9) PB1  2|    |19  PA1 (D1)(A1)   (ADC1/DO/PCINT1)
//                 (SCK/USCK/SCL/OC1B/PCINT10)    (D10) PB2  3|    |18  PA2 (D2)(A2)   (ADC2/INT1/USCK/SCL/PCINT2)
//         PWM                  (OC1B/PCINT11)    (D11) PB3  4|    |17  PA3 (D3)(AREF) (AREF/PCINT3)
//                                                      VCC  5|    |16  AGND
//                                                      GND  6|    |15  AVCC
//             (ADC7/OC1D/CLKI/XTAL1/PCINT12) (A7)(D12) PB4  7|    |14  PA4 (D4)(A3)   (ADC3/ICP0/PCINT4)
//             (ADC8/OC1D/CLKO/XTAL2/PCINT13) (A8)(D13) PB5  8/    /13  PA5 (D5)(A4)   (ADC4/AIN2/PCINT5)
//                     (ADC9/INT0/T0/PCINT14) (A9)(D14) PB6  9/    /12  PA6 (D6)(A5)   (ADC5/AIN0/PCINT6)
//                      (ADC10/RESET/PCINT15)     RESET PB7 10/    /11  PA7 (D7)(A6)   (ADC6/AIN1/PCINT7)

//                           +----+
//

// In like fashion to the Arduino, we don't count the RESET pin (unlike the ATtinyX5 series), but this define can be changed to 12 if the RESET pin is to be used for I/O
// NOTE: the reset pin is not supported for pcint or Software Serial
#define NUM_DIGITAL_PINS            15
#define NUM_ANALOG_INPUTS           10


#define digitalPinHasPWM(p)         ((p) == 9 || (p) == 11)

// the ATtinyX61 series USI Three-wire mode does not have a SS (Slave Select) pin
static const uint8_t SS   = -1; /* don't know if this works with SPIClass in SPI.cpp */
static const uint8_t MOSI = 8;
static const uint8_t MISO = 9;
static const uint8_t SCK  = 10;

static const uint8_t SDA = 0;
static const uint8_t SCL = 10;
static const uint8_t LED_BUILTIN = -1;

const static uint8_t A0 = 0;
const static uint8_t A1 = 1;
const static uint8_t A2 = 2;
const static uint8_t A3 = 4;
const static uint8_t A4 = 5;
const static uint8_t A5 = 6;
const static uint8_t A6 = 7;
const static uint8_t A7 = 12;
const static uint8_t A8 = 13;
const static uint8_t A9 = 14;


// there is no PCICR register, but there is a GIMSK equivalent - we'll use that
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 14) ? (&GIMSK) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) ( ((p) <= 7 || (p) >=12) ? PCIE1 : PCIE0)

// this doesn't take into account the RESET pin
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK0) : (((p) <= 14) ? (&PCMSK1) : ((uint8_t *)0)))
#define digitalPinToPCMSKbit(p) ( (p) )


#ifdef ARDUINO_MAIN



// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
};

const (int16_t PROGMEM port_to_output_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
};

const uint16_t PROGMEM port_to_input_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
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
  PB,
  PB,
  PB,
  PB,
};


const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = 
{
  _BV(0), /* 0, port A */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7), /* 7 port A */
  _BV(0), /* 8, port B */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4), 
  _BV(5),
  _BV(6), /* 14, port B */
};

// Should the other PWM pins on timer 1 be used?
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = 
{
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, 
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  TIMER1A, /* OC1A */
  NOT_ON_TIMER, 
  TIMER1B, /* OC1B */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
};


#endif

#endif
