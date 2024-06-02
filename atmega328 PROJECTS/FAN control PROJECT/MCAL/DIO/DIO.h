/*
 * DIO.h
 *
 * Created: 5/21/2024 10:12:20 AM
 *  Author: Reem Raouf
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../std_types.h"

/*Types Declaration*/

#define PORTB_ID               0
#define PORTC_ID               1
#define PORTD_ID               2

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7


typedef enum
{
	INPUT,  //0
	OUTPUT  //1
}Direction;

typedef enum
{
	LOW,   //0
	HIGH   //1
}VALUE;

//for pins:
/*to determine if the pin in the port is input or output
 *we used void as there is no return value*/
void fn_setpindirection(uint8 portID,uint8 pinID, Direction PINDirection);  

/* (WRITE) if it is output then set which pin in which port need to get the output value from 
 *we used void as there is no return value*/
void fn_setPINvalue(uint8 portID,uint8 pinID,uint8 pinvalue);   

/* (READ) if it is input determine which pin in which port and wait to return the value    
 *we did not use void as there is a return value*/
uint8 fn_getpinValue(uint8 portID,uint8 pinID);    

                  /**********************************/
				  
//for ports:
/*to determine if the port is input or output
 *we used void as there is no return value*/
void fn_setportdirection(uint8 portID, Direction PORTDirection);  

/* (WRITE) if it is output then set which port need to get the output value from
 *we used void as there is no return value*/
void fn_setPORTvalue(uint8 portID ,uint8 portvalue);   

/* (READ) if it is input determine the port and wait to return the value of the port     
 *we did not use void as there is a return value*/
uint8 fn_getportValue(uint8 portID);    

#endif /* DIO_H_ */