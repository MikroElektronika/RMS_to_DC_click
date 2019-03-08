/*
    __rms2dc_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__rms2dc_driver.h"
#include "__rms2dc_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __RMS2DC_DRV_I2C__
static uint8_t _slaveAddress;
#endif

#define ADC_RESOLUTION  4096

const uint8_t _RMS2DC_DEVICE_ADDR                = 0x4D;

const uint8_t _RMS2DC_DEVICE_EN                  = 0x00;
const uint8_t _RMS2DC_DEVICE_DIS                 = 0x01;

const T_RMS2DC_V _RMS2DC_VCC_3V3                 = 3296;
const T_RMS2DC_V _RMS2DC_VCC_5V                  = 5000;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __RMS2DC_DRV_SPI__

void rms2dc_spiDriverInit(T_RMS2DC_P gpioObj, T_RMS2DC_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RMS2DC_DRV_I2C__

void rms2dc_i2cDriverInit(T_RMS2DC_P gpioObj, T_RMS2DC_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RMS2DC_DRV_UART__

void rms2dc_uartDriverInit(T_RMS2DC_P gpioObj, T_RMS2DC_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint16_t rms2dc_readADC( void )
{
    uint8_t dataOut[ 2 ];
    uint16_t retVal;
    
    hal_i2cStart();
    hal_i2cRead( _slaveAddress, dataOut, 2, END_MODE_STOP );
    
    retVal = dataOut[ 0 ] & 0x0F;
    retVal <<= 8;
    retVal |= dataOut[ 1 ];
    
    return retVal;
}

T_RMS2DC_V rms2dc_voutADC( T_RMS2DC_V vccSel )
{
    uint16_t adcVal;
    double res;
    
    adcVal = rms2dc_readADC();
    
    res = (double)adcVal / ADC_RESOLUTION;
    res *= vccSel;
    
    return (T_RMS2DC_V)res;
}

T_RMS2DC_V rms2dc_avrgVoutADC( T_RMS2DC_V vccSelect, uint8_t nSamples )
{
    T_RMS2DC_V Vout;
    T_RMS2DC_V Vmax;
    T_RMS2DC_V Vmin;
    uint8_t cont = 0;
    uint8_t cnt;

    for (cnt = 0; cnt < nSamples; cnt++)
    {
        Vout = rms2dc_voutADC( vccSelect );
        
        if (cont == 0)
        {
            Vmax = Vout;
            Vmin = Vout;
            cont = 1;
        }
        else
        {
            if (Vmax < Vout)
            {
                Vmax = Vout;
            }
            if (Vmin > Vout)
            {
                Vmin = Vout;
            }
        }
        Delay_1us();
    }
    
    Vout = (Vmax + Vmin) / 2;
    
    return Vout;
}

void rms2dc_enable( uint8_t state )
{
    if (state)
    {
        hal_gpio_csSet( 1 );
    }
    else
    {
        hal_gpio_csSet( 0 );
    }
}

/* -------------------------------------------------------------------------- */
/*
  __rms2dc_driver.c

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