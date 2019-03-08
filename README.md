![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# RMS_to_DC Click

---

- **CIC Prefix**  : RMS2DC
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

- **Libstock** : https://libstock.mikroe.com/projects/view/2657/rms-to-dc-click
- **HEXIWEAR** : ${HEXI_LINK}
- **GitHub**   : ${GITHUB_LINK}

---

### Software Support

We provide a library for the RMS_to_DC Click on our [LibStock](https://libstock.mikroe.com/projects/view/2657/rms-to-dc-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library performs a RMS to DC signal converting with 12bit resolution.
Also it is possible to get the averaged output DC signal (voltage), with a minimalized noise.
For more details check documentation.

Key functions :

- ``` uint16_t rms2dc_readADC( void ) ``` - Function returns a 12bit result of AD conversion.
- ``` T_RMS2DC_V rms2dc_voutADC( T_RMS2DC_V vccSel ) ``` - Function returns the output voltage value calculated to mV, depending on the power voltage selection.
- ``` T_RMS2DC_V rms2dc_avrgVoutADC( T_RMS2DC_V vccSelect, uint8_t nSamples ) ``` - Function returns the averaged output voltage value calculated to mV, depending on the power voltage selection.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes I2C interface and turns ON the device.
- Application Task - (code snippet) - Reads averaged DC output voltage calculated to mV and
  sends results to the serial plotter.
Note : The input voltage frequency should be in the range from 50Hz to 250kHz.
Also the input voltage amplitude must be lower than 5V.
In this conditions the device can convert the RMS signal, in every form, to DC signal.


```.c
void applicationTask()
{
    outVoltDC = rms2dc_avrgVoutADC( _RMS2DC_VCC_3V3, 25 );
    
    plotData( outVoltDC );

    Delay_ms( 5 );
}
```

Additional Functions :

- void plotData( T_RMS2DC_V plotY ) - Sends data (DC voltage) to the serial plotter.
- void logData() - Sends DC voltage value to the uart terminal.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2657/rms-to-dc-click) page.

Other mikroE Libraries used in the example:

- Conversions
- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
