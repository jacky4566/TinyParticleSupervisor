# Boron

<div align=center><img src="https://github.com/particle-iot/boron/blob/master/images/boron-top.png" ></div>

### Overview

The Boron LTE is a powerful LTE CAT-M1/NB1 enabled development kit that can act as either a standalone cellular endpoint or LTE enabled gateway for Particle Mesh networks. It is based on the Nordic nRF52840 and has built-in battery charging circuitry so it’s easy to connect a Li-Po and deploy your local network in minutes.

The Boron is great for connecting existing projects to the Particle Device Cloud or as a gateway to connect an entire group of local endpoints where Wi-Fi is missing or unreliable.

### Features

* u-blox SARA R410 LTE modem (Boron LTE)
  * LTE CAT M1/ NB1 module with global hardware support (MVNO support for US only) 
  * 3GPP Release 13 LTE Cat M1 
* u-blox SARA U201 2G/3G modem (Boron 2G/3G)
  * HSPA/GSMqq with global hardware and SIM support 
  * Bands 800/850/900/1900/2100 MHz 
  * 3GPP Release 7 
* Nordic Semiconductor nRF52840 SoC 
  * ARM Cortex-M4F 32-bit processor @ 64MHz 
  * 1MB flash, 256KB RAM 
  * IEEE 802.15.4-2006: 250 Kbps 
  * Bluetooth 5: 2 Mbps, 1 Mbps, 500 Kbps, 125 Kbps 
  * Supports DSP instructions, HW accelerated Floating Point Unit (FPU) calculations 
  * ARM TrustZone CryptoCell-310 Cryptographic and security module 
  * Up to +8 dBm TX power (down to -20 dBm in 4 dB steps) 
  * NFC-A tag
* On-board additional 2MB SPI flash
* 20 mixed signal GPIO (6 x Analog, 8 x PWM), UART, I2C, SPI
* Micro USB 2.0 full speed (12 Mbps)
* Integrated Li-Po charging and battery connector
* JTAG (SWD) Connector
* RGB status LED
* Reset and Mode buttons
* Dual SIM support: Nano 4FF and MFF2
* On-board PCB antenna
* u.FL connector for external antenna
* Meets the Adafruit Feather [specification](https://learn.adafruit.com/adafruit-feather/feather-specification) in dimensions and pinout
* FCC and PTCRB certified
* RoHS compliant (lead-free)

### Structure of this repository:
 - /eagle
     + Contains the schematic and PCB files in the Eagle file format
 - /gerbers
     + Contains the manufacturing gerber files for the board
 - /datasheets
     + Contains the relevant datasheets of the components used on the Boron
 - /pdfs
     + Contains schematic files in PDF 

### Hardware datasheet

The complete datasheet for the Boron is available [here.](https://docs.particle.io/datasheets/cellular/boron-datasheet/
)
