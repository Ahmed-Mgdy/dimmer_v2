# ***AVR Dimmer Control System***

This project implements a basic dimmer control system for an AC load using an AVR microcontroller. The system utilizes a TRIAC for dimming control based on zero-cross detection from the AC mains. The dimming level can be set by the user and ranges from 0 to 255, with 0 being completely off and 255 being maximum brightness.

## Features
- **Zero-cross detection**: Uses an interrupt to detect the zero-cross of the AC mains and synchronize the firing of the TRIAC.
- **Dimming control**: Adjust the brightness of the connected load by controlling the delay before triggering the TRIAC.
- **Modular design**: The dimmer system is separated into multiple files (dimmer.c, dimmer.h, and main.c) for easy integration into larger projects.

## Hardware Requirements
- AVR Microcontroller (e.g., ATmega32, ATmega328P)
- TRIAC (e.g., BTA16) for controlling the AC load
- Optoisolator (e.g., MOC3021) for safely driving the TRIAC
- Zero-cross detection circuit (e.g., using a resistor and optocoupler like 4N25)
- AC load (e.g., lamp or fan)
- External interrupts for zero-cross detection (connected to INT2 pin)

## Software Requirements
- AVR-GCC toolchain
- AVR Libc library
- Makefile (optional, for easy compilation)

## Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/Ahmed-Mgdy/avr-dimmer-control.git
cd avr-dimmer-control
