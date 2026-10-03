// Copyright 2022-2025 Kevin Williams (TexElec.com), Michael Steil, Joe Burks,
// Stefan Jakobsson, Eirik Stople, and other contributors.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, 
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#pragma once

/*  - Pinout Updated for Proto 4 / Dev Board
ATTINY861 Pinout
     AVR Func         X16 Func   ArdIO   Port             Port   ArdIO   X16 Func    AVR Function
                                              ----\_/----
                                             | *         |
 (SPI MOSI) (SDA)      I2C_SDA     8     PB0 | 1       20| PA0     0     RESB
 (SPI MISO)               IRQB     9     PB1 | 2   A   19| PA1     1     NMIB
  (SPI SCK) (SCL)      I2C_SCL    10     PB2 | 3   T   18| PA2     2     PS2_KBD_CLK
                   PS2_KBD_DAT    11     PB3 | 4   t   17| PA3     3     POWER_OK
                                         VCC | 5   i   16| AGND
                                         GND | 6   n   15| AVCC
                     RESET_BTN    12     PB4 | 7   y   14| PA4     4     POWER_BTN
                   PS2_MSE_DAT    13     PB5 | 8   8   13| PA5     5     POWER_ON
                   PS2_MSE_CLK    14     PB6 | 9   6   12| PA6     6     ACT_LED        (TXD)
  (SPI SS) (RST)                  15     PB7 |10   1   11| PA7     7     NMI_BTN        (RXD)            
                                             |           |
                                              -----------
 */

 /* cp256 smc, attiny 84a
                     ----\_/----
    VCC            1 | 1      14 | 14  GND (Masse)
    IRQB           2 | 2      13 | 13  PS2_KBD_DAT
    RESET_BTN      3 | 3      12 | 12  PS2_KBD_CLK
    RESET          4 | 4      11 | 11  POWER_BTN
    PS2_MSE_DAT    5 | 5      10 | 10  PS2_MSE_CLK
    NC             6 | 6       9 |  9  I2C_SCL
    I2C_SDA        7 | 7       8 |  8  SW_PHI
                      -----------

// ATMEL ATTINY84A (14-Pin Standard Layout)
//
//                   +-\/-+
//             VCC  1|    |14  GND
//      (D 10) PB0  2|    |13  PA0 (D  0)
//      (D  9) PB1  3|    |12  PA1 (D  1)
//      (D  8) PB3  4|    |11  PA2 (D  2)
// INT0 (D  7) PB2  5|    |10  PA3 (D  3)
//      (D  6) PA7  6|    |9   PA4 (D  4)
//      (D  5) PA6  7|    |8   PA5 (D  5)
//                   +----+


  */

#if defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny84A__)
  #define ATTINY84

  // --- I2C / USI ---
  #define I2C_SDA_PIN         PIN_PA6  // Phys Pin 7 (PA6)
  #define I2C_SCL_PIN         PIN_PA4 // Phys Pin 6 (PA4)

  // --- PS/2 Peripherie ---
  #define PS2_KBD_DAT         PIN_PA0  // Phys Pin 13 (PA1)
  #define PS2_KBD_CLK         PIN_PA1  // Phys Pin 12 (PA2)
  #define PS2_MSE_DAT         PIN_PB2  // Phys Pin 5 (PA3)
  #define PS2_MSE_CLK         PIN_PA3 // Phys Pin 10 (PA4)

  // --- Taster (Eingänge) ---
  #define POWER_BUTTON_PIN    PIN_PA2  // Phys Pin 11 (PA7) 

  // --- CPU-Signale (Ausgänge) ---
  #define RESB_PIN            PIN_PB3  // Phys Pin 3 (PB0) -
  #define IRQB_PIN            PIN_PB0 
  #define RESET_BUTTON_PIN    PIN_PB1

  #define ACT_LED             PIN_PA5
#endif 

#if defined(__AVR_ATtiny861__) || defined(__AVR_ATtiny861A__)
  #define ATTINY861

  #define I2C_SDA_PIN         8
  #define I2C_SCL_PIN        10

  #define PS2_KBD_CLK         2
  #define PS2_KBD_DAT        11
  #define PS2_MSE_CLK        14
  #define PS2_MSE_DAT        13

  #define NMI_BUTTON_PIN      7
  #define RESET_BUTTON_PIN   12
  #define POWER_BUTTON_PIN    4

  #define RESB_PIN            0
  #define NMIB_PIN            1
  #define IRQB_PIN            9

  #define PWR_ON              5
  #define PWR_OK              3

  #define ACT_LED             6

  #if defined(COMMUNITYX16_PINS)
    #undef NMI_BUTTON_PIN
    #undef IRQB_PIN
    #undef PWR_OK
    #undef ACT_LED
    #define NMI_BUTTON_PIN     3
    #define IRQB_PIN           7
    #define PWR_OK             6
    #define ACT_LED            9
  #endif
#endif
