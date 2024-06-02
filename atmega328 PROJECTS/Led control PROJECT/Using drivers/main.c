/*
 * mc version2.c
 *
 * Created: 5/2/2024 10:10:25 AM
 * Author : Reem Raouf
 */ 

#include "std_types.h"
#include "DIO_definition.h"
#include "DIO_reg.h"
#include "math.h"
#include <util/delay.h>

int main(void)
 {
	// Set the INPUT pins of PORTB 
	 fn_setpindirection( PORTB_ID, PIN0_ID,  INPUT);
	 fn_setpindirection( PORTB_ID, PIN7_ID,  INPUT);
	 PORTB_REG=0xff;  //enable pull up resistors of PORTB

	
	//set PORTC and PORTD as OUTPUT ports
	 fn_setportdirection( PORTC_ID,  OUTPUT);
	 fn_setportdirection( PORTD_ID,  OUTPUT);
     PORTD_REG=0xff;   
	 
	 //initializing variables
	 uint8_t flag = 0; //variable to determine button state for the LED
     uint8_t flag2 = 0;  //variable to determine button state for the 7 segment
	 uint8 x;  //variable for 7 segment to display value

	while (1)
	 {	

//FOR THE LED
		 if(!(PINB_REG & (1<<PIN0_ID)))  
		 /* check if the push button connected to PIN0 of PORTB is pressed or not (pressed>>0),(not pressed>>1)
		 if the button is pressed the corresponding bit in the PINB_REG will be clear 0 and the condition is true 
		 if the button is not pressed the bit will be set 1 and the condition evaluates to false (as the default of the pin is 1 as it is connected to vcc)*/
		 {
			 _delay_ms(30);            //debouncing delay
			 if(!(PINB_REG & (1<<PIN0_ID)))  //second check due to switch de-bouncing
			 {
				 if(flag == 0)    //enter  if condition as we initialized the flag=0
				 {
					 TOG_BIT(PORTC_REG,PIN4_ID);
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
		 
		 if(!(PINB_REG & (1<<PIN7_ID)))
         /* check if the push button connected to PIN7 of PORTB is pressed or not (pressed>>0),(not pressed>>1)
		 if the button is pressed the corresponding bit in the PINB_REG will be clear 0 and the condition is true 
		 if the button is not pressed the bit will be set 1 and the condition evaluates to false*/
		 {
			 _delay_ms(30);   //debouncing delay (one push on the button generates multiple trigger)
			 if(!(PINB_REG & (1<<PIN7_ID)))  //second check due to switch de-bouncing
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
		 SevenSegment_Display(x);      // display the value of x on the 7 segment display
		//_delay_ms(500);      //debouncing delay (one push on the button generates multiple trigger)
	 }
}



