#ifndef __LCD_2WIRE_H
#define __LCD_2WIRE_H
//-----------------------------------------------------------------------------
#include "typedefs.h"
#include "lcd_customization.h"
//-----------------------------------------------------------------------------

// Definitions for display modes and functions
#define LCD_CMD_MODE  0
#define LCD_DATA_MODE 1
#define LCD_INIT_MODE 2
#define LCD_CLR 1
#define LCD_HOME 2
#define LCD_DISP_ON 0x0C
#define LCD_FUNCTION_4BIT_1LINE 0x20
#define LCD_FUNCTION_4BIT_2LINES 0x28
#define LCD_FUNCTION_8BIT_1LINE 0x30
#define LCD_FUNCTION_8BIT_2LINES 0x38

// Macros for clock- and data signals
#define LCD_SET_CLK() {LCD_CLOCK_BIT = 1;}
#define LCD_CLR_CLK() {LCD_CLOCK_BIT = 0;}
#define LCD_SET_DATA() {LCD_DATA_BIT = 1;}
#define LCD_CLR_DATA() {LCD_DATA_BIT = 0;}
//-----------------------------------------------------------------------------

void lcd_init(void); // Initialize display
void lcd_clear(void); // Clear display
void lcd_home(void); // Set cursor to home position
void lcd_goto_xy(U08 xpos,U08 ypos); // Set display cursor position
void lcd_write_char(U08 chr); // Write character
void lcd_write_char_xy(U08 x,U08 y,U08 chr); // Write character at position
void lcd_write_str(pU8 sp); // Write string
void lcd_write_str_xy(U08 x,U08 y,pU08 sp); // Write string at position
void lcd_write_U08(U08 value,U08 digits); // Write unsigned 8-bit number
void lcd_write_U08_hex(U08 value); // Write hexdecimal 8-bit number
void lcd_write_U16(U16 value,U08 digits); // Write unsigned 16-bit number
void lcd_write_U16_hex(U16 value); // Write hexdecimal 16-bit number

//-----------------------------------------------------------------------------

#endif
