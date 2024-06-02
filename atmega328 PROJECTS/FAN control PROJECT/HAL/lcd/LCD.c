#include <stdint.h>
#include <util/delay.h>

#include "../../std_types.h"
#include "LCD.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/MATH.h"

void LCD_init(void) {
	fn_setpindirection(PORTB_ID, PIN0_ID, OUTPUT);   // RS
	fn_setpindirection(PORTB_ID, PIN2_ID, OUTPUT);   // E
	fn_setportdirection(PORTB_ID, OUTPUT);           // DATA

	_delay_ms(20);
	LCD_command(0x02); // Initialize in 4-bit mode
	LCD_command(0x28); // 2 lines, 5x7 matrix
	LCD_command(0x0C); // Display on, cursor off
	LCD_command(0x06); // Increment cursor
	LCD_command(0x01); // Clear display
	_delay_ms(2);
}

void LCD_command(uint8_t cmd) {
	PORTB_REG = (PORTB_REG & 0x0F) | (cmd & 0xF0); // Send higher nibble
	fn_setPINvalue(PORTB_ID, PIN0_ID, LOW); // RS = 0 for command
	fn_setPINvalue(PORTB_ID, PIN2_ID, HIGH); // E = 1
	_delay_us(1);
	fn_setPINvalue(PORTB_ID, PIN2_ID, LOW); // E = 0
	_delay_us(1);

	PORTB_REG = (PORTB_REG & 0x0F) | (cmd << 4); // Send lower nibble
	fn_setPINvalue(PORTB_ID, PIN2_ID, HIGH); // E = 1
	_delay_us(1);
	fn_setPINvalue(PORTB_ID, PIN2_ID, LOW); // E = 0
	_delay_us(1);
}

void LCD_data(uint8_t data) {
	PORTB_REG = (PORTB_REG & 0x0F) | (data & 0xF0); // Send higher nibble
	fn_setPINvalue(PORTB_ID, PIN0_ID, HIGH); // RS = 1 for data
	fn_setPINvalue(PORTB_ID, PIN2_ID, HIGH); // E = 1
	_delay_us(1);
	fn_setPINvalue(PORTB_ID, PIN2_ID, LOW); // E = 0
	_delay_us(1);

	PORTB_REG = (PORTB_REG & 0x0F) | (data << 4); // Send lower nibble
	fn_setPINvalue(PORTB_ID, PIN2_ID, HIGH); // E = 1
	_delay_us(1);
	fn_setPINvalue(PORTB_ID, PIN2_ID, LOW); // E = 0
	_delay_us(1);
}

void lcd_string(const char *str) {
	int i;
	for (i = 0; str[i] != 0; i++) {
		LCD_data(str[i]);
	}
}

void LCD_clearScreen(void) {
	LCD_command(0x01); // Clear display
	_delay_ms(2);      // Delay for clear command
}

void LCD_moveCursor(uint8_t row, uint8_t col) {
	uint8_t address = (row == 0) ? 0x80 : 0xC0;
	address += col;
	LCD_command(address);
}

void LCD_intgerToString(int data) {
	char buffer[16];
	itoa(data, buffer, 10);  // Convert integer to string
	lcd_string(buffer);
}
