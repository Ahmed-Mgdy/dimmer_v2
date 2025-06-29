 /******************************************************************************
 *
 * Module: zc dimmer
 *
 * File Name: dimmer.c
 *
 * Description: Source file for the zc dimmer
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/
#define F_CPU 16000000ul
#include <avr/io.h>
#include <avr/interrupt.h>
#include "dimmer.h"
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"

volatile uint8_t dimmingLevel = 255;  // Start at medium brightness
volatile uint32_t delayTime = 0;      // Computed delay time

void setup_timer1() {
	TCCR1B |= (1 << WGM12);  // Timer1 in CTC mode
	TIMSK |= (1 << OCIE1A);  // Enable Timer1 compare match interrupt
}

void delay_us_timer1(uint16_t delay) {
	OCR1A = delay;
	TCNT1 = 0;
	TCCR1B |= (1 << CS10);  // Start Timer1 with no prescaler (1:1)
	while (!(TIFR & (1 << OCF1A)));  // Wait for match
	TCCR1B = 0;  // Stop timer
	TIFR |= (1 << OCF1A);  // Clear match flag
}

void dimmer_init(void) {
	DDRD |= (1 << TRIAC_PIN);  // Set TRIAC pin as output
	DDRB &= ~(1 << ZERO_CROSS_PIN);  // Set INT2 (PB2) as input
	//DDRC |= (1 << ZC_DETECT_PIN);  // Set PC2 as output for debugging
	//PORTC &= ~(1 << ZC_DETECT_PIN); // Initialize low

	// Configure external interrupt on INT2 (falling edge)
	MCUCSR &= ~(1 << ISC2);
	GICR |= (1 << INT2);

	setup_timer1();  // Initialize Timer1
	sei();            // Enable global interrupts
}

void set_dimming_level(uint8_t level) {
	dimmingLevel = level;
}

// Interrupt service routine for zero-cross detection
ISR(INT2_vect) {
	//PORTC |= (1 << ZC_DETECT_PIN);  // Debug ON

		if (dimmingLevel == 255) {
			PORTD |=(1 << TRIAC_PIN);  // Ensure TRIAC is OFF
			//PORTC &= ~(1 << ZC_DETECT_PIN); // Debug OFF
			return;  // Exit ISR, TRIAC won't fire
		}
	// If dimming level is < 5, turn OFF TRIAC immediately
	if (dimmingLevel < 5) {
		PORTD &= ~(1 << TRIAC_PIN);  // Ensure TRIAC is OFF
		//PORTC &= ~(1 << ZC_DETECT_PIN); // Debug OFF
		return;  // Exit ISR, TRIAC won't fire
	}
	

	// Compute delayTime
	delayTime = ((uint16_t)((255 - dimmingLevel) * 260));

	// Apply delay before firing TRIAC
	if (delayTime > 0) {
		delay_us_timer1(delayTime);
	}

	// Fire TRIAC with a longer pulse width (200µs)
	PORTD |= (1 << TRIAC_PIN);
	delay_us_timer1(200);  // Use Timer1 for 200µs delay
	PORTD &= ~(1 << TRIAC_PIN);

	//PORTC &= ~(1 << ZC_DETECT_PIN); // Debug OFF
}
