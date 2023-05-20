/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Arduino Mega 2560 with custom pin assignments
 *
 * For use with the Systematic Life Organizer (S.L.O.) 3D Bioprinter
 *
 * Other pins_MYBOARD.h files may override these defaults
 */

#include "env_validate.h"

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "MEGA SLO"
#endif

//
// Endstops
//
#define X_MIN_PIN                         	  15
#define X_MAX_PIN                         	   3
#define Y_MIN_PIN                         	   2
#define Y_MAX_PIN                         	  14
//#define Z_MIN_PIN                             18
#define Z_MAX_PIN                          	  19

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                     32
#endif

//
// Steppers
//
#define X_STEP_PIN                            60
#define X_DIR_PIN                             61
#define X_ENABLE_PIN                          62
#ifndef X_CS_PIN
  #define X_CS_PIN                            53
#endif

#define Y_STEP_PIN                            54
#define Y_DIR_PIN                             55
#define Y_ENABLE_PIN                          56
#ifndef Y_CS_PIN
  #define Y_CS_PIN                            49
#endif

#define Z_STEP_PIN                            46
#define Z_DIR_PIN                             48
#define Z_ENABLE_PIN                          45
#ifndef Z_CS_PIN
  #define Z_CS_PIN                            40
#endif

#define E0_STEP_PIN                           26
#define E0_DIR_PIN                            28
#define E0_ENABLE_PIN                         24
#ifndef E0_CS_PIN
  #define E0_CS_PIN                           42
#endif

/*
#ifndef E1_STEP_PIN
  #define E1_STEP_PIN                         36
#endif
#ifndef E1_DIR_PIN
  #define E1_DIR_PIN                          34
#endif
#ifndef E1_ENABLE_PIN
  #define E1_ENABLE_PIN                       30
#endif
#ifndef E1_CS_PIN
  #define E1_CS_PIN                           44
#endif
*/

//
// Temperature Sensors
//
#define TEMP_0_PIN                            13  // Analog Input
#define TEMP_BED_PIN                          14  // Analog Input
#define TEMP_CHAMBER_PIN                      15  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                          10  // Extruder 0 Heater
#define FAN_PIN								   9  // Bed Cooling

//
// Misc. Functions
//
#define CASE_LIGHT_PIN                        21
#define FIL_RUNOUT_PIN                         4

//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER && !defined(SPINDLE_LASER_ENA_PIN)
  #if NUM_SERVOS < 2                              // Use servo connector if possible
    #ifndef SPINDLE_LASER_PWM_PIN
      #define SPINDLE_LASER_PWM_PIN            6  // Hardware PWM
    #endif
  #endif
#endif

/*
//
// TMC software SPI
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                       66
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                       44
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                        64
  #endif
#endif
*/

#if HAS_TMC_UART
  /*
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   *
   * Serial2 -- AUX-4 Pin 18 (D16 TX2) and AUX-4 Pin 17 (D17 RX2)
   * Serial1 -- Pins D18 and D19 are used for Z-MIN and Z-MAX
   */
  //#define X_HARDWARE_SERIAL Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  #ifndef X_SERIAL_TX_PIN
    #define X_SERIAL_TX_PIN                   40
  #endif
  #ifndef X_SERIAL_RX_PIN
    #define X_SERIAL_RX_PIN                   63
  #endif
  #ifndef X2_SERIAL_TX_PIN
    #define X2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef X2_SERIAL_RX_PIN
    #define X2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Y_SERIAL_TX_PIN
    #define Y_SERIAL_TX_PIN                   59
  #endif
  #ifndef Y_SERIAL_RX_PIN
    #define Y_SERIAL_RX_PIN                   64
  #endif
  #ifndef Y2_SERIAL_TX_PIN
    #define Y2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef Y2_SERIAL_RX_PIN
    #define Y2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Z_SERIAL_TX_PIN
    #define Z_SERIAL_TX_PIN                   42
  #endif
  #ifndef Z_SERIAL_RX_PIN
    #define Z_SERIAL_RX_PIN                   65
  #endif
  #ifndef Z2_SERIAL_TX_PIN
    #define Z2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef Z2_SERIAL_RX_PIN
    #define Z2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef E0_SERIAL_TX_PIN
    #define E0_SERIAL_TX_PIN                  44
  #endif
  #ifndef E0_SERIAL_RX_PIN
    #define E0_SERIAL_RX_PIN                  66
  #endif
  #ifndef E1_SERIAL_TX_PIN
    #define E1_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E1_SERIAL_RX_PIN
    #define E1_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E2_SERIAL_TX_PIN
    #define E2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E2_SERIAL_RX_PIN
    #define E2_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E3_SERIAL_TX_PIN
    #define E3_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E3_SERIAL_RX_PIN
    #define E3_SERIAL_RX_PIN                  -1
  #endif
#endif

/*
//
// Průša i3 MK2 Multiplexer Support
//
#if HAS_PRUSA_MMU1
  #ifndef E_MUX0_PIN
    #define E_MUX0_PIN                        40  // Z_CS_PIN
  #endif
  #ifndef E_MUX1_PIN
    #define E_MUX1_PIN                        42  // E0_CS_PIN
  #endif
  #ifndef E_MUX2_PIN
    #define E_MUX2_PIN                        44  // E1_CS_PIN
  #endif
#endif
*/

//
// RepRap Discount Full Graphic Smart Controller
//
#define BEEPER_PIN							  37  // EXP1_01_PIN
#define BTN_ENC 							  35  // EXP1_02_PIN
#define LCD_PINS_ENABLE						  17  // EXP1_03_PIN
#define LCD_PINS_RS							  16  // EXP1_04_PIN
#define LCD_PINS_D4							  23  // EXP1_05_PIN
#define LCD_PINS_D5							  25  // EXP1_06_PIN
#define LCD_PINS_D6							  27  // EXP1_07_PIN
#define LCD_PINS_D7							  29  // EXP1_08_PIN
#define SD_MISO_PIN							  50  // EXP2_01_PIN
#define SD_SCK_PIN							  52  // EXP2_02_PIN
#define BTN_EN1								  31  // EXP2_03_PIN
#define SDSS								  53  // EXP2_04_PIN
#define BTN_EN2								  33  // EXP2_05_PIN
#define SD_MOSI_PIN							  51  // EXP2_06_PIN
#define SD_DETECT_PIN						  49  // EXP2_07_PIN
#define KILL_PIN							  41  // EXP2_08_PIN