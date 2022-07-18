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

#include "variant.h"
#include "Arduino.h"
/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  // Connector J1 - I2C_3
  { PORTA,  3, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // 1 / D1 / A1
  { PORTA, 19, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_3 }, // 2 / PWM1
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // 3 / SCL3
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // 4 / SDA3

  // Connector J2 - I2C_1
  { PORTA, 11, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), ADC_Channel19, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // 5 / D2 / A2
  { PORTA,  7, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel7, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 }, // 6 / PWM2
  { PORTA, 17, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // 7 / SCL1
  { PORTA, 16, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // 8 / SDA1

  // Connector J3 - I2C_2
  { PORTA, 10, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // 9 / D3 / A3
  { PORTA, 15, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_15 }, // 10 / PWM3
  { PORTA,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },   // 11 / SCL2
  { PORTA,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI }, // 12 / SDA2

  // Connector J4 - SPI_0
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 }, // 13 / D4
  { PORTA,  6, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH0, TCC1_CH0, EXTERNAL_INT_6 }, // 14 / PWM4 / MISO0
  { PORTA,  5, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // 15 / SCK0
  { PORTA,  4, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // 16 / MOSI0

  // Connector J5 - SPI_1
  { PORTA,  2, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // 17 / D5
  { PORTA, 18, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 }, // 18 / PWM5 / MISO1
  { PORTA,  1, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // 19 / SCK1
  { PORTA,  0, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // 20 / MOSI1

  // Onboard LED & Switch
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 }, // 21 / LED
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },  // 22 / SWITCH

  // USB pins
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 23 / USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 24 / USB/DP

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;

/* ---------------- Usages of initializing new I2C / Wire ----------------

#include <Wire.h>

// ------ I2C3 - Connector J1 ------
TwoWire Wire3( &PERIPH_WIRE3, SDA3, SCL3 );
void WIRE3_IT_HANDLER(void) {
  Wire3.onService();
}

// ------ I2C1 - Connector J2 ------
TwoWire Wire1( &PERIPH_WIRE1, SDA1, SCL1 );
void WIRE1_IT_HANDLER(void) {
  Wire1.onService();
}

// ------ I2C2 - Connector J3 ------
TwoWire Wire2( &PERIPH_WIRE2, SDA2, SCL2 );
void WIRE2_IT_HANDLER(void) {
  Wire2.onService();
}
*/

/* ---------------- Usages of initializing new Serial ----------------

// ------ Serial0 - Connector J4 ------ (DO NOT USE)
Uart Serial0( &sercom0, PIN_SERIAL0_RX, PIN_SERIAL0_TX, PAD_SERIAL0_RX, PAD_SERIAL0_TX ) ;
void SERCOM0_Handler()
{
  Serial0.IrqHandler();
}

// ------ Serial1 - Connector J5 ------
Uart Serial1( &sercom1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
void SERCOM1_Handler()
{
  Serial1.IrqHandler();
}
*/

/* ---------------- Usages of initializing new SPI ----------------

// ------ SPI0 - Connector J4 ------ (DO NOT USE)
SPIClass SPI0 ( &PERIPH_SPI0, MISO0, SCK0, MOSI0, PAD_SPI0_TX, PAD_SPI0_RX );

// ------ SPI1 - Connector J5 ------
SPIClass SPI1 ( &PERIPH_SPI1, MISO1, SCK1, MOSI1, PAD_SPI1_TX, PAD_SPI1_RX );
*/
