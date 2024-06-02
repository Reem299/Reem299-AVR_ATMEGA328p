/*
 * _7_SEGMENT.c
 *
 * Created: 6/2/2024 3:39:01 PM
 *  Author: Reem Raouf
 */ 

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