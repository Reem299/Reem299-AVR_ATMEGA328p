/*
 * DIO_reg.h
 *
 * Created: 5/21/2024 10:23:43 AM
 *  Author: Reem Raouf
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_
#include <stdint.h>
/*note 1: we used (uint8*) to make pointer points on the address in ram to avoid taking the address as a value
  note 2: we used volatile as this indicates to the compiler that the variable's value is subject to change at any moment.*/


/*port B definition*/
#define PORTB_REG	(*(volatile uint8*)0x25)	//output
#define DDRB_REG	(*(volatile uint8*)0x24)	//determine direction to define input or output
#define PINB_REG	(*(volatile uint8*)0x23)	//input

/*port C definition*/
#define PORTC_REG	(*(volatile uint8*)0x28)	//output
#define DDRC_REG	(*(volatile uint8*)0x27)	//determine direction to define input or output
#define PINC_REG	(*(volatile uint8*)0x26)	//input

/*port D definition*/
#define PORTD_REG	(*(volatile uint8*)0x2B)	//output
#define DDRD_REG	(*(volatile uint8*)0x2A)	//determine direction to define input or output
#define PIND_REG	(*(volatile uint8*)0x29)	//input



#endif /* DIO_REG_H_ */