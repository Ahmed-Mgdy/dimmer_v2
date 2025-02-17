#AVR Dimmer Control System
This project implements a basic dimmer control system for an AC load using an AVR microcontroller. The system utilizes a TRIAC for dimming control based on zero-cross detection from the AC mains. The dimming level can be set by the user and ranges from 0 to 255, with 0 being completely off and 255 being maximum brightness.

###Features
Zero-cross detection: Uses an interrupt to detect the zero-cross of the AC mains and synchronize the firing of the TRIAC.
Dimming control: Adjust the brightness of the connected load by controlling the delay before triggering the TRIAC.
Modular design: The dimmer system is separated into multiple files (dimmer.c, dimmer.h, and main.c) for easy integration into larger projects.
Hardware Requirements
AVR Microcontroller (e.g., ATmega32, ATmega328P)
TRIAC (e.g., BTA16) for controlling the AC load
Optoisolator (e.g., MOC3021) for safely driving the TRIAC
Zero-cross detection circuit (e.g., using a resistor and optocoupler like 4N25)
AC load (e.g., lamp or fan)
External interrupts for zero-cross detection (connected to INT2 pin)
Software Requirements
AVR-GCC toolchain
AVR Libc library
Makefile (optional, for easy compilation)
Installation
Clone the repository to your local machine:

git clone https://github.com/Ahmed-Mgdy/avr-dimmer-control.git
cd avr-dimmer-control
Open the project in your favorite AVR development environment (e.g., Atmel Studio, Eclipse with AVR plugin, or use a Makefile with avr-gcc).

Compile and upload the code to your AVR microcontroller.

###Usage
The system starts with a default dimming level (e.g., 128 out of 255).
The dimming level can be set programmatically by calling the set_dimming_level() function in the main() file. The value can range from 0 (off) to 255 (maximum brightness).
The dimmer automatically adjusts the brightness of the connected AC load based on the zero-cross events.
Example:
In the main.c file, you can set the dimming level as follows:

uint8_t dimmingLevel = 128;  // Set brightness to half
set_dimming_level(dimmingLevel);
Files
dimmer.c: Contains the logic for initializing and controlling the dimmer system.
dimmer.h: Header file that declares the dimmer functions and constants.
main.c: The main application file, where the dimming level is set and the system operates.
Interrupts
The code uses external interrupts to detect the zero-cross event of the AC mains. This is done using the INT2 (PB2) pin, which is configured to trigger an interrupt on a falling edge.

###Calibration
You can adjust the delay time by changing the delay_us_timer1() function or modifying the formula used to calculate the delay in the ISR for different dimming levels.
Troubleshooting
Ensure the zero-cross detection circuit is working correctly. If the TRIAC does not trigger, check the interrupt setup.
Verify that the TRIAC is properly wired and that the optoisolator is functioning to drive the TRIAC gate.
Make sure to use the appropriate resistors and safety precautions when working with high-voltage AC.
Safety Warning
Warning: This project involves controlling high-voltage AC circuits. Make sure you follow proper safety procedures when working with mains power. Only qualified personnel should work with high-voltage components.


###Contributing
If you want to contribute to this project, feel free to fork the repository, make changes, and create pull requests.
 
