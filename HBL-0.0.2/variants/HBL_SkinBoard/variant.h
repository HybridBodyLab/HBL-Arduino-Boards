/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_HBL_SKINBOARD_
#define _VARIANT_HBL_SKINBOARD_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK	(F_CPU)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (24u)
#define NUM_DIGITAL_PINS     (24u)
#define NUM_ANALOG_INPUTS    (5u)
#define NUM_ANALOG_OUTPUTS   (1u)
#define analogInputToDigitalPin(p)  (p)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LED and Switch
#define PIN_LED              (20u)
#define LED_BUILTIN          PIN_LED
#define PIN_SWITCH           (21u)
#define SWITCH_BUILTIN       PIN_SWITCH

static const uint8_t LED  = PIN_LED;
static const uint8_t SWITCH  = PIN_SWITCH;

#define PIN_DAC0             (00ul)

/*
 * GPIO Pins from Connector J1 to J5
 */
#define PIN_1                (0u)
#define PIN_2                (1u)
#define PIN_3                (2u)
#define PIN_4                (3u)
#define PIN_5                (4u)
#define PIN_6                (5u)
#define PIN_7                (6u)
#define PIN_8                (7u)
#define PIN_9                (8u)
#define PIN_10               (9u)
#define PIN_11               (10u)
#define PIN_12               (11u)
#define PIN_13               (12u)
#define PIN_14               (13u)
#define PIN_15               (14u)
#define PIN_16               (15u)
#define PIN_17               (16u)
#define PIN_18               (17u)
#define PIN_19               (18u)
#define PIN_20               (19u)

// Connector J1 - I2C_3
static const uint8_t D1    = PIN_1;
static const uint8_t A1    = PIN_1;
static const uint8_t PWM1  = PIN_2;
static const uint8_t SCL3  = PIN_3;
static const uint8_t SDA3  = PIN_4;

// Connector J2 - I2C_1
static const uint8_t D2    = PIN_5;
static const uint8_t A2    = PIN_5;
static const uint8_t PWM2  = PIN_6;
static const uint8_t SCL1  = PIN_7;
static const uint8_t SDA1  = PIN_8;

// Connector J3 - I2C_2
static const uint8_t D3    = PIN_9;
static const uint8_t A3    = PIN_9;
static const uint8_t PWM3  = PIN_10;
static const uint8_t SCL2  = PIN_11;
static const uint8_t SDA2  = PIN_12;

// Connector J4 - SPI_0
static const uint8_t D4    = PIN_13;
static const uint8_t CS0   = PIN_13;
static const uint8_t SS    = PIN_13;
static const uint8_t PWM4  = PIN_14;
static const uint8_t MISO0 = PIN_14;
static const uint8_t MISO  = PIN_14;
static const uint8_t SCK0  = PIN_15;
static const uint8_t SCK   = PIN_15;
static const uint8_t MOSI0 = PIN_16;
static const uint8_t MOSI  = PIN_16;

// Connector J5 - SPI_1
static const uint8_t D5    = PIN_17;
static const uint8_t A5    = PIN_17;
static const uint8_t CS1   = PIN_17;
static const uint8_t PWM5  = PIN_18;
static const uint8_t MISO1 = PIN_18;
static const uint8_t SCK1  = PIN_19;
static const uint8_t MOSI1 = PIN_20;

#define ADC_RESOLUTION   12

/*
 * Serial interfaces
 */

// Serial0 - Connector J4
#define PIN_SERIAL0_TX       PIN_16
#define PIN_SERIAL0_RX       PIN_15
#define PAD_SERIAL0_TX       UART_TX_PAD_0
#define PAD_SERIAL0_RX       SERCOM_RX_PAD_1

static const uint8_t TX0   = PIN_SERIAL0_TX;
static const uint8_t RX0   = PIN_SERIAL0_RX;

// Serial1 - Connector J5
#define PIN_SERIAL1_TX       PIN_20
#define PIN_SERIAL1_RX       PIN_19
#define PAD_SERIAL1_TX       UART_TX_PAD_0
#define PAD_SERIAL1_RX       SERCOM_RX_PAD_1

static const uint8_t TX1   = PIN_SERIAL1_TX;
static const uint8_t RX1   = PIN_SERIAL1_RX;

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1 // Put 1 to prevent conflicts with existing libraries

// SPI - Connector J4 (fixed SPI bus on sercom0)
#define PIN_SPI_SCK           PIN_15
#define PIN_SPI_MISO          PIN_14
#define PIN_SPI_MOSI          PIN_16
#define PERIPH_SPI            sercom0
#define PAD_SPI_TX            SPI_PAD_0_SCK_1
#define PAD_SPI_RX            SERCOM_RX_PAD_2

// SPI0 - Connector J4 (duplicate of SPI)
#define PIN_SPI0_SCK          PIN_15
#define PIN_SPI0_MISO         PIN_14
#define PIN_SPI0_MOSI         PIN_16
#define PERIPH_SPI0           sercom0
#define PAD_SPI0_TX           SPI_PAD_0_SCK_1
#define PAD_SPI0_RX           SERCOM_RX_PAD_2

// SPI1 - Connector J5
#define PIN_SPI1_SCK          PIN_19
#define PIN_SPI1_MISO         PIN_18
#define PIN_SPI1_MOSI         PIN_20
#define PERIPH_SPI1           sercom1
#define PAD_SPI1_TX           SPI_PAD_0_SCK_1
#define PAD_SPI1_RX           SERCOM_RX_PAD_2

/*
 * Wire / I2C Interfaces
 */
#define WIRE_INTERFACES_COUNT 1 // Put 1 to prevent conflicts with existing libraries

// I2C3 - Connector J1
#define PIN_WIRE3_SDA        SDA3
#define PIN_WIRE3_SCL        SCL3
#define PERIPH_WIRE3         sercom3
#define WIRE3_IT_HANDLER     SERCOM3_Handler

// I2C1 - Connector J2
#define PIN_WIRE1_SDA        SDA1
#define PIN_WIRE1_SCL        SCL1
#define PERIPH_WIRE1         sercom1
#define WIRE1_IT_HANDLER     SERCOM1_Handler

// I2C2 - Connector J3
#define PIN_WIRE2_SDA        SDA2
#define PIN_WIRE2_SCL        SCL2
#define PERIPH_WIRE2         sercom2
#define WIRE2_IT_HANDLER     SERCOM2_Handler

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (21ul)
#define PIN_USB_DM          (22ul)
#define PIN_USB_DP          (23ul)
/*
 * I2S Interfaces - not provided
 */
#define I2S_INTERFACES_COUNT 0

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial1;

#endif

#endif /* _VARIANT_HBL_SKINBOARD_ */
