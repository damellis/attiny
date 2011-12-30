==> Added support for ATtiny 13
*** modified boards.txt [ATtiny13 can be programmed using Arduino as ISP]
*** NOTE: A change has to be made to the wiring.c file in the arduino core for this to work correctly. The wiring.c file has an error where it does not set the correct TIMER for ATTiny13 only. This change will not impact any other boards.

in arduino1/hardware/arduino/cores/arduino/wiring.c

Line 44 should be supplemented with an additional condition for ATtiny13

#if defined(__AVR_ATtiny24__) || defined(..) ... [Add this] || defined(__AVR_ATtiny13__)
SIGNAL(TIM0_0VF_vect)
....


