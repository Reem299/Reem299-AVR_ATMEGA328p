/*
 * fan.c
 *
 * Created: 5/19/2024 11:08:29 PM
 * Author : Reem Raouf
 */ 


#include "std_types.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/DIO/DIO_reg.h"


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


volatile uint8_t FanOn = 0;
volatile uint16_t timer_count = 0;

void timer0_init() {
	TCCR0A |= (1 << WGM01); // CTC mode
	OCR0A = 156; // 1 second interval (16MHz/1024=15624)
	TIMSK0 |= (1 << OCIE0A); // Enable CTC interrupt
	TCCR0B |= (1 << CS00) | (1 << CS02); // Prescaler 1024
}

ISR(TIMER0_COMPA_vect) {
    timer_count++;
    if (timer_count >= 150 && FanOn) { // 25 seconds and fan is on  Actual Time=(OCR0A+1)/Clock Frequency/Prescaler
        fn_setPINvalue(PORTD_ID, PIN6_ID, LOW); // Turn off fan
        FanOn = 0; // Reset fan on flag
        timer_count = 0; // Reset timer count
    }
}

int main(void) {
    fn_setportdirection(PORTB_ID, OUTPUT);
    fn_setportdirection(PORTD_ID, OUTPUT);

    ADC_init();  // Initialize the adc
    LCD_init(); // Initialize the LCD
    timer0_init(); // Initialize Timer1
    sei(); // Enable global interrupts

    char buffer[16];

    while (1) {
        unsigned int temperature = (ADC_read(0) / 1024.0) * 500.0;  // 1024.0: Divides the read value by 1024 (ADC resolution for a 10-bit ADC). // * 500.0: Scales the normalized ADC value to the temperature in Celsius. (Assumes 500.0 is a factor based on sensor calibration).
  
        //int snprintf(char *str, size_t size, const char *format, ...);
        snprintf(buffer, 16, "Temperature= %uC", temperature);  // Format the temperature into a string and store it in buffer
		
        LCD_moveCursor(0, 0);
        lcd_string(buffer);  // Display the formatted temperature string on the LCD.

        if (temperature >= 30 && !FanOn) { // Temperature exceeds 30°C and fan is not already on
            fn_setPINvalue(PORTD_ID, PIN6_ID, HIGH); // Turn on fan
            FanOn = 1; // Set fan on flag
           timer_count = 0; // Reset timer count
        } else if (temperature < 30 && FanOn) { // Temperature is 30°C or below and fan is on
            fn_setPINvalue(PORTD_ID, PIN6_ID, LOW); // Turn off fan
            FanOn = 0; // Reset fan on flag
        }
        _delay_ms(500); // Delay 1 second
    }

    return 0;
}