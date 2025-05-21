
 /******************************************************************************
 *
 *
 * File Name: main.c
 *
 * Description: main code for  program (test)
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/
 #define F_CPU 16000000ul
#include <avr/io.h>
#include "dimmer.h"

int main() {
	dimmer_init();  // Initialize dimmer system

	uint8_t dimmingLevel =5;  // Example dimming level (range 0-255)
	set_dimming_level(dimmingLevel);  // Set the dimming level

	while (1) {
		// Main loop, dimmer operates automatically based on dimming level
	}

	return 0;
}
