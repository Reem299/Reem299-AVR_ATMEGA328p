/*
 * DIO_functions.c
 *
 * Created: 5/2/2024 10:13:27 AM
 *  Author: Reem Raouf
 */ 

#include "std_types.h"
#include "DIO_definition.h"
#include "DIO_reg.h"
#include "math.h"



//FUNCTIONS OF PINS
void fn_setpindirection(uint8 portID,uint8 pinID, Direction PINDirection)
//determine if the pin is input or output (if output then DDR=1, if input then DDR=0)

{
	if(portID<=PORTD_ID&& pinID<=PIN7_ID) //to assure limits to has port from 0-2 and pins 0-6
	{
		if(PINDirection==OUTPUT)
		{
			switch(portID)
			{
				//set bit by ORing to set the bit as output
				case PORTB_ID: SET_BIT(DDRB_REG,pinID);
				break;
				case PORTC_ID: SET_BIT(DDRC_REG,pinID);
				break;
				case PORTD_ID: SET_BIT(DDRD_REG,pinID);
				break;
			}
		}
		else if(PINDirection==INPUT)
		{
			switch(portID)
			{
				//clear bit by ANDing to set the bit as input
				case PORTB_ID: CLEAR_BIT(DDRB_REG,pinID);
				break;
				case PORTC_ID: CLEAR_BIT(DDRC_REG,pinID);
				break;
				case PORTD_ID: CLEAR_BIT(DDRD_REG,pinID);
				break;
			}
		}
	}
	
}


//if the pin is output
void fn_setPINvalue(uint8 portID,uint8 pinID,uint8 pinvalue)
{
	if(portID<=PORTD_ID&& pinID<=PIN7_ID) //to assure limits
	{
		if(pinvalue==HIGH)
		{
			switch(portID)
			{
				//set bit by ORing to set the bit as output
				case PORTB_ID: SET_BIT(PORTB_REG,pinID);
				break;
				case PORTC_ID: SET_BIT(PORTC_REG,pinID);
				break;
				case PORTD_ID: SET_BIT(PORTD_REG,pinID);
				break;
			}
		}
		else if(pinvalue==LOW)
		{
			switch(portID)
			{
				//clear bit by ANDing to set the bit as input
				case PORTB_ID: CLEAR_BIT(PORTB_REG,pinID);
				break;
				case PORTC_ID: CLEAR_BIT(PORTC_REG,pinID);
				break;
				case PORTD_ID: CLEAR_BIT(PORTD_REG,pinID);
				break;
			}
		}
	}
}


// to read the pin value by saving it in PINVALUE
uint8 fn_getpinValue(uint8 portID,uint8 pinID)
{
	uint8 PINVALUE;
	if(portID<=PORTD_ID&& pinID<=PIN7_ID) //to assure limits
	{
		switch(portID)
		{
			//set bit by ORing to set the bit as output
			case PORTB_ID: PINVALUE=GET_BIT(PINB_REG,pinID);
			break;
			case PORTC_ID: PINVALUE=GET_BIT(PINC_REG,pinID);
			break;
			case PORTD_ID: PINVALUE=GET_BIT(PIND_REG,pinID);
			break;
		}
	}
	return PINVALUE;
}

//*************************************//

//FUNCTIONS OF PORTS
void fn_setportdirection(uint8 portID, Direction PORTDirection)
//first function: to set the DDR if output set 0xff, if input set 0x00
{
	if(PORTDirection==INPUT )
	{
		switch(portID)
		{
			case PORTB_ID: DDRB_REG=0x00;
			break;
			case PORTC_ID: DDRC_REG=0x00;
			break;
			case PORTD_ID: DDRD_REG=0x00;
			break;
		}
	}
	else if(PORTDirection==OUTPUT )
	{
		switch(portID)
		{
			case PORTB_ID: DDRB_REG=0xff;
			break;
			case PORTC_ID: DDRC_REG=0xff;
			break;
			case PORTD_ID: DDRD_REG=0xff;
			break;
		}
	}
}


//Second function: if the port is output save the value in the port
void fn_setPORTvalue(uint8 portID ,uint8 portvalue)
{
	switch(portID)
{
	case PORTB_ID: PORTB_REG=portvalue;
	break;
	case PORTC_ID: PORTC_REG=portvalue;
	break;
	case PORTD_ID: PORTD_REG=portvalue;
	break;
}
}


/*//third function: to get the value from the port and save it in x
uint8 fn_getportValue(uint8 portID)
{
	uint8 x;     //initialize variable x to get the value on it (READ)
	switch(portID)
	{
		case PORTB_ID: x=PINB_REG;
		break;
		case PORTC_ID: x=PINB_REG;
		break;
		case PORTD_ID: x=PINB_REG;
		break;
	}
}*/

void SevenSegment_Display(uint8 num)
//clear bits wanted to be off(=0) and set bits wanted to be on(=1)
{ 
	switch(num)
	{
		case 0:  //all bits are on (=1) except the middle bit is off(=0)
		PORTD_REG |= (1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG |= (1<<4);
		PORTD_REG |= (1<<5);
		PORTD_REG |= (1<<6);
		PORTD_REG &= ~(1<<7);
		break;  
		case 1:  //all bits are off (=0) except two side bits are on (=1)
		PORTD_REG &= ~(1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG &= ~(1<<4);
		PORTD_REG &= ~(1<<5);
		PORTD_REG &= ~(1<<6);
		PORTD_REG &= ~(1<<7);
		break;
		case 2:  /*same sequence to the rest of the numbers till number 9*/
		PORTD_REG |= (1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG &= ~(1<<3);
		PORTD_REG |= (1<<4);
		PORTD_REG |= (1<<5);
		PORTD_REG &= ~(1<<6);
		PORTD_REG |= (1<<7);
		break;
		case 3:
		PORTD_REG |= (1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG |= (1<<4);
		PORTD_REG &= ~(1<<5);
		PORTD_REG &= ~(1<<6);
		PORTD_REG |= (1<<7);
		break;
		case 4:
		PORTD_REG &= ~(1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG &= ~(1<<4);
		PORTD_REG &= ~(1<<5);
		PORTD_REG |= (1<<6);
		PORTD_REG |= (1<<7);
		break;
		case 5:
		PORTD_REG |= (1<<1);
		PORTD_REG &= ~(1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG |= (1<<4);
		PORTD_REG &= ~(1<<5);
		PORTD_REG |= (1<<6);
		PORTD_REG |= (1<<7);
		break;
		case 6:
		PORTD_REG |= (1<<1);
		PORTD_REG &= ~(1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG |= (1<<4);
		PORTD_REG |= (1<<5);
		PORTD_REG |= (1<<6);
		PORTD_REG |= (1<<7);
		break;
		case 7:
		PORTD_REG |= (1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG &= ~(1<<4);
		PORTD_REG &= ~(1<<5);
		PORTD_REG &= ~(1<<6);
		PORTD_REG &= ~(1<<7);
		break;
		case 8:
		PORTD_REG |= (1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG |= (1<<4);
		PORTD_REG |= (1<<5);
		PORTD_REG |= (1<<6);
		PORTD_REG |= (1<<7);
		break;
		case 9:
		PORTD_REG |= (1<<1);
		PORTD_REG |= (1<<2);
		PORTD_REG |= (1<<3);
		PORTD_REG &= ~(1<<4);
		PORTD_REG &= ~(1<<5);
		PORTD_REG |= (1<<6);
		PORTD_REG |= (1<<7);
		break;
	}
}