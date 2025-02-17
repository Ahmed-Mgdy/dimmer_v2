 /******************************************************************************
 *
 * Module: zc dimmer
 *
 * File Name: dimmer.h
 *
 * Description:header file for the zc dimmer
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/
#ifndef DIMMER_H
#define DIMMER_H

#include <stdint.h>

#define ZERO_CROSS_PIN   PB2   // INT2 (External Interrupt 2)
#define TRIAC_PIN        PD4   // TRIAC control
//#define ZC_DETECT_PIN    PC2   // Zero-cross detection output

void dimmer_init(void);
void set_dimming_level(uint8_t level);

#endif
