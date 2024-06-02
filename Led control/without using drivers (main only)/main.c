/*
 * test.c
 *
 * Created: 5/6/2024 3:23:07 PM
 * Author : Reem Raouf
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED_BUTTON PB0
#define SEGMENT_BUTTON PB7
#define LED_PORT PORTC
#define SEGMENT_PORT PORTD

volatile uint8_t flag = 0; // Flag for LED_BUTTON
volatile uint8_t flag2 = 0; // Flag for SEGMENT_BUTTON
volatile uint8_t x = 0; // Value for 7-segment display

const uint8_t segment_patterns[10] =
{
	0b0111111, // 0
	0b0000110, // 1
	0b1011011, // 2
	0b1001111, // 3
	0b1100110, // 4
	0b1101101, // 5
	0b1111101, // 6
	0b0000111, // 7
	0b1111111, // 8
	0b1101111  // 9
};

	int main(void) {
		DDRB &= ~((1 << LED_BUTTON) | (1 << SEGMENT_BUTTON)); // Initialize pins for buttons as input
		PORTB |= (1 << LED_BUTTON) | (1 << SEGMENT_BUTTON); // Enable internal pull-up resistors for buttons

		DDRD = 0xFF; // Set PORTD as output for 7-segment display
		DDRC = 0xFF;
		
		
		while (1)
	 {	

//FOR THE LED
		 if(!(PINB & (1<<LED_BUTTON))) 
		 /* check if the push button connected to PIN0 of PORTB is pressed or not (pressed>>0),(not pressed>>1)
		 if the button is pressed the corresponding bit in the PINB_REG will be clear 0 and the condition is true 
		 if the button is not pressed the bit will be set 1 and the condition evaluates to false (as the default of the pin is 1 as it is connected to vcc)*/
		 {
			 _delay_ms(30);            //debouncing delay
			 if(!(PINB & (1<<LED_BUTTON)))  //second check due to switch de-bouncing
			 {
				 if(flag == 0)    //enter  if condition as we initialized the flag=0
				 {
					 LED_PORT ^= (1 << PINB4);  // toggle value of pin 4 in PORTC (output port pin) using toggle function
					 flag = 1;   //set the button flag value to 1 to not enter if condition again until the button is released
				 }
			 }
		 }
		 else
		 {
			 // button is released reset the button flag to value 0 again 
			 flag = 0;
		 }

		 /*******************************************/
// FOR THE 7 SEGMENT
		 
		 if(!(PINB & (1<<SEGMENT_BUTTON)))
         /* check if the push button connected to PIN7 of PORTB is pressed or not (pressed>>0),(not pressed>>1)
		 if the button is pressed the corresponding bit in the PINB_REG will be clear 0 and the condition is true 
		 if the button is not pressed the bit will be set 1 and the condition evaluates to false (as the default of the pin is 1 as it is connected to vcc in )*/
		 {
			 _delay_ms(30);   //debouncing delay (one push on the button generates multiple trigger)
			 if(!(PINB & (1<<SEGMENT_BUTTON)))  //second check due to switch de-bouncing
			 {
				 if(flag2 == 0) //enter  if condition as we initialized the flag=0
				 {
					 if(x!=9)  //set condition that the max value of 7 segment is 9, as it is not 9 so it will increment the value, while if it is equal 9 enter else if 
					 {
						 x++;  //then increment the value
					 }
					 else  //if it is equal to 9 then put x=0 to start from the beginning 
					 {
						 x=0;
					 }

					 flag2=1;  //the set the button flag value to 1 to not enter if condition again until the button is released
				 }
				
			 }
		 }
		  else
				 {
					 flag2=0;  

				 }
		 	 SEGMENT_PORT = segment_patterns[x];     // display the value of x on the 7 segment display
		  _delay_ms(500);      //debouncing delay (one push on the button generates multiple trigger)
	 }
}

