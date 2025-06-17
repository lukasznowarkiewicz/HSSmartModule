# HSSmartModule


## Overview

This repository contains design files of Home Span Smart Module. The device is intended to use with existing electrical installation as a light controller. Initially intended to be flashed with Home Span firmware and  use with Apple Home Kit ecosystem. This will allow basic support of the implement features like outputs control, reading states form the inputs and control from other devices - aka smart home in-wall module functionality. This will allow rather quick start of the desting of the device in the files and give chance to spot potential problems right away. In the future it is planned to create custom application, with support for all implemented features in hardware like power measurement, input from presence sensor and enabling thread radio communication. The device intentionally is divided into two PCBs. This will allow independent testing, of high voltage and low voltage parts. In the future will be possible to replace low voltage PCB with with another variant - equiped with another MCU, for example NRF52840. In the future after initial bringup, set of boards could be easily redesigned as single rigid-flex PCB. 


## Features

- Powered form 230VAC mains voltage
- 2x output for controlling 230VAC devices, up to 4A per channel
- 3x 230VAC inputs - two intended for ordinary switches for direct control of the outputs, additional input for motion or presence sensor
- Power usage measurement using CS5480
- ESP32-C6 SOC as main MCU and radio module
- 8MB SPI flash memory 
- Wi-Fi 6, Bluetooth 5 LE, Thread (802.15.4), Zigbee
- U.FL antenna connector




## Block diagram




## Low Voltage PCB

Schematic

- 3V3 power input

- ESP32-C6 microcontroller

- Antenna connector

- SPI flash memory

- Additional switches and outs for debug

- Programming connector

- Edge connector





## High Voltage PCB

Features:
- Outputs controls - two relays 

- Input switches - three 230V inputs

- 230VAC to 12VDC

- 12VDC to 3V3VDC converter

- Power measurement


## Flexible circuit board


## HSSmartModule Programmer

Features
- CP2102N USB UART converter
- Automatically put ESP32 chips into programming mode 
- power supply and data lines insulation 
- 6 poles 1.27 mm header and 6 poles 2.54 mm header for programming
- 3V3 voltage supplied to target MCU can be disable by removal of the jumper


## Manufacturing


## Boards bring up 


### Firmware for boards testing
