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
//               (RXLIN / RXD / ADC0 / PCINT0) (A0)(D0) PA0  1|    |20  PB0 (D8)      (PCINT8 / OC1AU / DI / SDA)    PWM
//               (TXLIN / TXD / ADC1 / PCINT1) (A1)(D1) PA1  2|    |19  PB1 (D9)      (PCINT9 / OC1BU / DO)          PWM
// PWM      (MISO / DO / OC0A / ADC2 / PCINT2) (A2)(D2) PA2  3|    |18  PB2 (D10)     (PCINT10 / OC1AV / USCK / SCL)
//               (INT1 / ISRC / ADC3 / PCINT3) (A3)(D3) PA3  4|    |17  PB3 (D11)     (PCINT11 / OC1BV)
//                                                     AVCC  5|    |16  GND
//                                                     AGND  6|    |15  VCC
//    (MOSI / SDA / DI / ICP1 / ADC4 / PCINT4) (A4)(D4) PA4  7|    |14  PB4 (D12)     (PCINT12 / OC1AW / XTAL1 / CLKI)
//     (SCK / SCL / USCK / T1 / ADC5 / PCINT5) (A5)(D5) PA5  8/    /13  PB5 (D13)(A8) (PCINT13 / ADC8 / OC1BW / XTAL2 / CLKO)
//                 (SS / AIN0 / ADC6 / PCINT6) (A6)(D6) PA6  9/    /12  PB6 (D14)(A9) (PCINT14 / ADC9 / OC1AX / INT0)
//        (AREF / XREF / AIN1 / ADC7 / PCINT7) (A7)(D7) PA7 10/    /11  PB7 RESET     (PCINT15 / ADC10 / OC1BX / dW)

//                           +----+
//

#define NUM_DIGITAL_PINS            15
#define NUM_ANALOG_INPUTS           10

#define digitalPinHasPWM(p)         ((p) == 2 || (p) == 8 || (p) == 9)


const static uint8_t SS   = 6;
const static uint8_t MOSI = 4;
const static uint8_t MISO = 2;
const static uint8_t SCK  = 5;

const static uint8_t SDA = 4;
const static uint8_t SCL = 5;
const static uint8_t LED_BUILTIN = -1;


const static uint8_t A0 = 0;
const static uint8_t A1 = 1;
const static uint8_t A2 = 2;
const static uint8_t A3 = 3;
const static uint8_t A4 = 4;
const static uint8_t A5 = 5;
const static uint8_t A6 = 6;
const static uint8_t A7 = 7;
const static uint8_t A8 = 13;
const static uint8_t A9 = 14;


// there is no PCICR register, but there is a GIMSK equivalent - we'll use that
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 14) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? PCIE0 : PCIE1)

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
  TIMER0A, /* 2 - OC0A */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, 
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  TIMER1A, /* OC1AU */
  TIMER1B, /* OC1BU */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, 
  NOT_ON_TIMER,
  NOT_ON_TIMER,
};


#endif

#endif
