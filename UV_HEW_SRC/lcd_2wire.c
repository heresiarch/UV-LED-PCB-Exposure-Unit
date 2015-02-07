#include "lcd_2wire.h"
#include "delay.h"
#include "string_conversion.h"

void lcd_delay(void) // Do clock depending delay
{
  wait_us(100);
}
//-----------------------------------------------------------------------------

U08 LCD_ROW_TABLE[4] = // Display row addresses
{
  0x80,
  0xC0,
  0x80 + LCD_COLS,
  0xC0 + LCD_COLS
};

void lcd_init_shift_reg(U08 mode) // Clear shift-register, set E and RS
{
  U08 n;

  LCD_CLR_DATA(); // Clear data signal
  lcd_delay();

  // Clear all outputs of shift register
  for (n = 7; n; n--)
  {
    LCD_SET_CLK();
    lcd_delay();
    LCD_CLR_CLK();
  }

  // Set high level for E at Q7
  LCD_SET_DATA();
  lcd_delay();
  LCD_SET_CLK();
  lcd_delay();
  LCD_CLR_CLK();

  // Set level for RS at Q6
  if (mode == LCD_DATA_MODE)
  {
    LCD_SET_DATA();
  }
  else
  {
    LCD_CLR_DATA();
  }

  lcd_delay();
  LCD_SET_CLK();
  lcd_delay();
  LCD_CLR_CLK();
}
//-----------------------------------------------------------------------------

void lcd_shift_nibble(U08 data) // Clock in 4 bits of data
{
  U08 n, mask = 0x08;

  for (n = 4; n; n--) // Do this for 4 databits
  {
    if (data & mask) // Set or reset data signal
    {
      LCD_SET_DATA();
    }
    else
    {
      LCD_CLR_DATA();
    }

    LCD_SET_CLK();
    lcd_delay();
    LCD_CLR_CLK();

    mask >>= 1; // Shift right compare mask
  }

  // Clear data line, then do the last shift, Q7=1
  LCD_CLR_DATA(); // Always clear data line before the last shift

  LCD_SET_CLK();
  lcd_delay();
  LCD_CLR_CLK();
}
//-----------------------------------------------------------------------------

void lcd_shift_byte(U08 data,U08 mode) // Write command or data byte to display
{
  lcd_init_shift_reg(mode); // Clear shift register, set RS and E
  lcd_shift_nibble(data >> 4); // Shift high nibble first

  // Now 6 bits are shifted, Q7=1 waiting for the data line to go high
  // for a logical AND, thus a high at E to latch the data at Q5..Q2
  LCD_SET_DATA();
  lcd_delay();

  // Do not write the low nibble if in LCD_INIT_MODE because
  // the interface is in 8-bit mode at startup
  if (mode != LCD_INIT_MODE)
  {
    lcd_init_shift_reg(mode); // Clear shift register, set RS and E
    lcd_shift_nibble(data); // Shift low nibble last

    // Now 6 bits are shifted, Q7=1 waiting for the data line to go high
    // for a logical AND, thus a high at E to latch the data at Q5..Q2
    LCD_SET_DATA();
    lcd_delay();
  }

  LCD_CLR_DATA(); // Clear E always
  lcd_delay();
}
//-----------------------------------------------------------------------------

void lcd_write_command(U08 command) // Write command byte to display
{
  lcd_shift_byte(command,LCD_CMD_MODE); // Do serial byte transfer
}
//-----------------------------------------------------------------------------

void lcd_write_data(U08 data) // Write data byte to display
{
  lcd_shift_byte(data,LCD_DATA_MODE); // Do serial byte transfer
}
//-----------------------------------------------------------------------------

// Function flags - Bit0 0: 5x7 Dots, 1: 5x10 Dots
//                  Bit1 0: 1 Row, 1: 2 Rows
//                  Bit2 0: 4-Bit interface, 1: 8-Bit interface

void lcd_function_mode(U08 function_mode) // Set display funktion mode
{
  function_mode = ((function_mode & 7) << 2) + 0x20;
  lcd_write_command(function_mode);
}
//-----------------------------------------------------------------------------

// Display flags - Bit0 0: blink cursor off, 1: blink cursor on
//                 Bit1 0: line cursor off, 1: line cursor on
//                 Bit2 0: display off, 1: display on

void lcd_display_mode(U08 display_mode) // Set display mode
{
  display_mode = (display_mode & 7) + 0x08;
  lcd_write_command(display_mode);
}
//-----------------------------------------------------------------------------

// Entry flags - Bit0 0: display shift off, 1: display shift on
//               Bit1 0: decrement, 1: increment

void lcd_entry_mode(U08 entry_mode) // Set entry mode
{
  entry_mode = (entry_mode & 3) + 0x04;
  lcd_write_command(entry_mode);
}
//-----------------------------------------------------------------------------

void lcd_clear(void) // Clear display
{
  lcd_write_command(LCD_CLR);
  wait_ms(4);
}
//-----------------------------------------------------------------------------

void lcd_home(void) // Set cursor to home position
{
  lcd_write_command(LCD_HOME);
}
//-----------------------------------------------------------------------------

void lcd_goto_xy(U08 xpos,U08 ypos) // Set display cursor position
{
  if (xpos < LCD_COLS && ypos < LCD_ROWS)
  {
    lcd_write_command(LCD_ROW_TABLE[ypos] + xpos);
  }
}
//-----------------------------------------------------------------------------

void lcd_write_char(U08 chr) // Write character
{
  lcd_write_data(chr);
}
//-----------------------------------------------------------------------------

void lcd_write_char_xy(U08 x,U08 y,U08 chr) // Write character at position
{
  lcd_goto_xy(x,y);
  lcd_write_data(chr);
}
//-----------------------------------------------------------------------------

void lcd_write_str(pU08 sp) // Write string
{
  while (*sp)
  {
    lcd_write_data(*sp++);
  }
}
//-----------------------------------------------------------------------------

void lcd_write_str_xy(U08 x,U08 y,pU08 sp) // Write string at position
{
  lcd_goto_xy(x,y);
  lcd_write_str(sp);
}
//-----------------------------------------------------------------------------


void lcd_write_U08(U08 value,U08 digits) // Write unsigned 8-bit number
{
  lcd_write_str(sc_U08_to_str(value,digits));
}
//-----------------------------------------------------------------------------

void lcd_write_U08_hex(U08 value) // Write hexdecimal 8-bit number
{
  lcd_write_str(sc_U08_to_hex(value));
}
//-----------------------------------------------------------------------------

void lcd_write_U16(U16 value,U08 digits) // Write unsigned 16-bit number
{
  lcd_write_str(sc_U16_to_str(value,digits));
}
//-----------------------------------------------------------------------------

void lcd_write_U16_hex(U16 value) // Write hexdecimal 16-bit number
{
  lcd_write_str(sc_U16_to_hex(value));
}
//-----------------------------------------------------------------------------

void lcd_init(void) // Initialize display
{
  // Set clock- and data pin to low level
  LCD_CLR_CLK();
  LCD_CLR_DATA();
  
  wait_ms(LCD_POWER_UP_DELAY_MS); // Delay for power up time

  // Start Initialization
  // Only the high nibble ist transfered in LCD_INIT_MODE
  lcd_shift_byte(LCD_FUNCTION_8BIT_1LINE,LCD_INIT_MODE);
  wait_ms(LCD_INIT_DELAY_MS);
  lcd_shift_byte(LCD_FUNCTION_8BIT_1LINE,LCD_INIT_MODE);
  wait_ms(LCD_INIT_DELAY_MS);
  lcd_shift_byte(LCD_FUNCTION_8BIT_1LINE,LCD_INIT_MODE);
  wait_ms(LCD_INIT_DELAY_MS);
  lcd_shift_byte(LCD_FUNCTION_4BIT_1LINE,LCD_INIT_MODE);
  wait_ms(LCD_INIT_DELAY_MS);

  // Display is in 4 bit I/O mode now
#if (LCD_ROWS > 1)
  lcd_write_command(LCD_FUNCTION_4BIT_2LINES);
#else
  lcd_write_command(LCD_FUNCTION_4BIT_1LINE);
#endif
  wait_ms(LCD_INIT_DELAY_MS);
  lcd_write_command(LCD_DISP_ON);
  wait_ms(LCD_INIT_DELAY_MS);
  lcd_write_command(LCD_CLR);
  lcd_write_command(LCD_HOME);
  wait_ms(LCD_INIT_DELAY_MS);
}
