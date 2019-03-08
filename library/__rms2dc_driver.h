/*
    __rms2dc_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rms2dc_driver.h
@brief    RMS_to_DC Driver
@mainpage RMS_to_DC Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RMS2DC
@brief      RMS_to_DC Click Driver
@{

| Global Library Prefix | **RMS2DC** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RMS2DC_H_
#define _RMS2DC_H_

/** 
 * @macro T_RMS2DC_P
 * @brief Driver Abstract type 
 */
#define T_RMS2DC_P    const uint8_t*
#define T_RMS2DC_V    uint16_t

/** @defgroup RMS2DC_COMPILE Compilation Config */              /** @{ */

//  #define   __RMS2DC_DRV_SPI__                            /**<     @macro __RMS2DC_DRV_SPI__  @brief SPI driver selector */
   #define   __RMS2DC_DRV_I2C__                            /**<     @macro __RMS2DC_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __RMS2DC_DRV_UART__                           /**<     @macro __RMS2DC_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RMS2DC_VAR Variables */                           /** @{ */

/** Device Address */
extern const uint8_t _RMS2DC_DEVICE_ADDR   ;

/** Settings to turn ON or turn OFF the device */
extern const uint8_t _RMS2DC_DEVICE_EN     ;
extern const uint8_t _RMS2DC_DEVICE_DIS    ;

/** Power voltage value selection */
extern const T_RMS2DC_V _RMS2DC_VCC_3V3    ;
extern const T_RMS2DC_V _RMS2DC_VCC_5V     ;

                                                                       /** @} */
/** @defgroup RMS2DC_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RMS2DC_INIT Driver Initialization */              /** @{ */

#ifdef   __RMS2DC_DRV_SPI__
void rms2dc_spiDriverInit(T_RMS2DC_P gpioObj, T_RMS2DC_P spiObj);
#endif
#ifdef   __RMS2DC_DRV_I2C__
void rms2dc_i2cDriverInit(T_RMS2DC_P gpioObj, T_RMS2DC_P i2cObj, uint8_t slave);
#endif
#ifdef   __RMS2DC_DRV_UART__
void rms2dc_uartDriverInit(T_RMS2DC_P gpioObj, T_RMS2DC_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup RMS2DC_FUNC Driver Functions */                   /** @{ */

/**
 * @brief ADC Read function
 *
 * @returns Result of AD conversion
 *
 * Function returns a 12bit result of AD conversion.
 */
uint16_t rms2dc_readADC( void );

/**
 * @brief Get Output Voltage function
 *
 * @param[in] vccSel  VCC value selection [mV]
 *
 * @returns Output voltage value
 *
 * Function returns the output voltage value calculated to mV, depending on the power voltage selection.
 */
T_RMS2DC_V rms2dc_voutADC( T_RMS2DC_V vccSel );

/**
 * @brief Get Averaged Output Voltage function
 *
 * @param[in] vccSelect  VCC value selection [mV]
 * @param[in] nSamples  Number of samples for averaging
 *
 * @returns Averaged output voltage value
 *
 * Function returns the averaged output voltage value calculated to mV, depending on the power voltage selection.
 */
T_RMS2DC_V rms2dc_avrgVoutADC( T_RMS2DC_V vccSelect, uint8_t nSamples );

/**
 * @brief Enable function
 *
 * @param[in] state  0 - ON, 1 - OFF
 *
 * Function turns ON/OFF the device.
 */
void rms2dc_enable( uint8_t state );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_RMS_to_DC_STM.c
    @example Click_RMS_to_DC_TIVA.c
    @example Click_RMS_to_DC_CEC.c
    @example Click_RMS_to_DC_KINETIS.c
    @example Click_RMS_to_DC_MSP.c
    @example Click_RMS_to_DC_PIC.c
    @example Click_RMS_to_DC_PIC32.c
    @example Click_RMS_to_DC_DSPIC.c
    @example Click_RMS_to_DC_AVR.c
    @example Click_RMS_to_DC_FT90x.c
    @example Click_RMS_to_DC_STM.mbas
    @example Click_RMS_to_DC_TIVA.mbas
    @example Click_RMS_to_DC_CEC.mbas
    @example Click_RMS_to_DC_KINETIS.mbas
    @example Click_RMS_to_DC_MSP.mbas
    @example Click_RMS_to_DC_PIC.mbas
    @example Click_RMS_to_DC_PIC32.mbas
    @example Click_RMS_to_DC_DSPIC.mbas
    @example Click_RMS_to_DC_AVR.mbas
    @example Click_RMS_to_DC_FT90x.mbas
    @example Click_RMS_to_DC_STM.mpas
    @example Click_RMS_to_DC_TIVA.mpas
    @example Click_RMS_to_DC_CEC.mpas
    @example Click_RMS_to_DC_KINETIS.mpas
    @example Click_RMS_to_DC_MSP.mpas
    @example Click_RMS_to_DC_PIC.mpas
    @example Click_RMS_to_DC_PIC32.mpas
    @example Click_RMS_to_DC_DSPIC.mpas
    @example Click_RMS_to_DC_AVR.mpas
    @example Click_RMS_to_DC_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rms2dc_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */