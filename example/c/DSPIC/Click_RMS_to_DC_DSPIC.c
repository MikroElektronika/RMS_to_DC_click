/*
Example for RMS_to_DC Click

    Date          : Nov 2018.
    Author        : Nemanja Medakovic

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes I2C interface and turns ON the device.
- Application Task - (code snippet) - Reads averaged DC output voltage calculated to mV and
  sends results to the serial plotter.
Note : The input voltage frequency should be in the range from 50Hz to 250kHz.
Also the input voltage amplitude must be lower than 5V.
In this conditions the device can convert the RMS signal, in every form, to DC signal.

Additional Functions :

- void plotData( T_RMS2DC_V plotY ) - Sends data (DC voltage) to the serial plotter.
- void logData() - Sends DC voltage value to the uart terminal.

*/

#include "Click_RMS_to_DC_types.h"
#include "Click_RMS_to_DC_config.h"

T_RMS2DC_V outVoltDC;
uint32_t plotX;
char text[ 30 ];

void plotData( T_RMS2DC_V plotY )
{
    WordToStr( plotY, text );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( ",", _LOG_TEXT );
    LongWordToStr( plotX, text );
    mikrobus_logWrite( text, _LOG_LINE );
    
    if (plotX == 0xFFFFFFFF)
    {
        plotX = 0;
    }
    else
    {
        plotX++;
    }
}

void logData()
{
    WordToStr( outVoltDC, text );
    mikrobus_logWrite( "DC voltage : ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( " mV", _LOG_LINE );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_RMS2DC_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite( "*** Initializing... ***", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    rms2dc_i2cDriverInit( (T_RMS2DC_P)&_MIKROBUS1_GPIO, (T_RMS2DC_P)&_MIKROBUS1_I2C, _RMS2DC_DEVICE_ADDR );
    Delay_ms( 500 );
    
    rms2dc_enable( _RMS2DC_DEVICE_EN );
    plotX = 0;
    
    mikrobus_logWrite( "** RMS to DC is initialized **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
}

void applicationTask()
{
    outVoltDC = rms2dc_avrgVoutADC( _RMS2DC_VCC_3V3, 25 );
    
    plotData( outVoltDC );

    Delay_ms( 5 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
