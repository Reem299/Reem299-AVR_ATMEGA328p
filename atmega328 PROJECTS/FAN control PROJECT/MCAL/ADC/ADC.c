/*
 * ADC.c
 *
 * Created: 5/24/2024 4:20:06 PM
 *  Author: Reem Raouf
 */ 


#include "../../std_types.h"
#include <avr/io.h>


void ADC_init(void) {
	ADMUX = (1 << REFS0);  // AVcc with external capacitor at AREF pin (AREF) will be connected to the AVcc pin, typically 5V
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  // Enable ADC, prescaler = 128
}

uint16 ADC_read(uint8_t ch) {
	ADMUX &= 0xF0; // Clear previous channel selection
	ADMUX |= ch; // Set the required channel
	ADCSRA |= (1<<ADSC); // Start the conversion
	while (ADCSRA & (1<<ADSC)); // Wait for the conversion to finish
	return ADC;
}