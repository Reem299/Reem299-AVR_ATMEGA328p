/*
 * LCD.h
 *
 * Created: 5/21/2024 10:00:38 AM
 *  Author: Reem Raouf
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../std_types.h"



/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the DIO driver
 * 2. Setup the LCD Data Mode 4-bits
 */
void LCD_init(void);  //set RS & E pins as output


//Send the required command to the screen
void LCD_send_command(uint8 cmd);


//Display the required character on the screen
void LCD_char(uint8 data);

void LCD_data(unsigned char data);

// Display the required string on the screen
void lcd_string(const char *str);


//Move the cursor to a specified row and column index on the screen
void LCD_moveCursor(uint8 row, uint8 col);


//Display the required decimal value on the screen
void LCD_intgerToString(int data);

// clear the screen 
void LCD_clearScreen(void);


#endif /* LCD_H_ */