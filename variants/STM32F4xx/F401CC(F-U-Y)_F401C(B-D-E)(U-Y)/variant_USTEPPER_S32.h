/*
 *******************************************************************************
 * Copyright (c) 2011-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pins number
 *----------------------------------------------------------------------------*/
#define PC7                     0
#define PC6                     1
#define PA7                     PIN_A1
#define PA6                     PIN_A2
#define PA2                     PIN_A3
#define PA3                     PIN_A4
#define PA5                     PIN_A5
#define PB8                     7
#define PB9                     8
#define PA4                     PIN_A0
#define PB3                     10
#define PB10                    11
#define PC2                     PIN_A6
#define PD2                     13
#define PB5                     14
#define PC9                     15
#define PC3                     PIN_A7
#define PC4                     PIN_A8
#define PB0                     PIN_A9
#define PB1                     PIN_A10
#define PC5                     PIN_A11
#define PC13                    21
#define PH0                     22
#define PH1                     23

// Alternate pins number
#define PC7_ALT2                (PC7 | ALT2)
#define PC6_ALT2                (PC6 | ALT2)
#define PA7_ALT2                (PA7 | ALT2)
#define PA7_ALT1                (PA7 | ALT1)
#define PA6_ALT2                (PA6 | ALT2)
#define PA2_ALT1                (PA2 | ALT1)
#define PA2_ALT2                (PA2 | ALT2)
#define PA2_ALT3                (PA2 | ALT3)
#define PA3_ALT1                (PA3 | ALT1)
#define PA3_ALT2                (PA3 | ALT2)
#define PA3_ALT3                (PA3 | ALT3)
#define PA5_ALT1                (PA5 | ALT1)
#define PB8_ALT2                (PB8 | ALT2)
#define PB8_ALT3                (PB8 | ALT3)
#define PB9_ALT2                (PB9 | ALT2)
#define PB9_ALT3                (PB9 | ALT3)
#define PB3_ALT1                (PB3 | ALT1)
#define PB10_ALT1               (PB10 | ALT1)
#define PB5_ALT2                (PB5 | ALT2)
#define PC9_ALT2                (PC9 | ALT2)
#define PB0_ALT1                (PB0 | ALT1)
#define PB0_ALT2                (PB0 | ALT2)
#define PB1_ALT1                (PB1 | ALT1)
#define PB1_ALT2                (PB1 | ALT2)

#define NUM_DIGITAL_PINS        22
#define NUM_ANALOG_INPUTS       12

// On-board LED pin number
#define LED_GREEN               PC13
#ifndef LED_BUILTIN
  #define LED_BUILTIN           LED_GREEN
#endif

// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PA4
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PA4
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PA7
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PA6
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PA5
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PB9
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB8
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM10
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM11
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  6
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PC7
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PC6
#endif

#define ENABLE_HWSERIAL2

#ifndef PIN_SERIAL2_RX
  #define PIN_SERIAL2_RX         PA3
#endif
#ifndef PIN_SERIAL2_TX
  #define PIN_SERIAL2_TX         PA2
#endif

#ifndef HSE_VALUE
  #define HSE_VALUE             20000000U
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
