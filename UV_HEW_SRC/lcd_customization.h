#ifndef __LCD_CUSTOMIZATION_H
#define __LCD_CUSTOMIZATION_H
#include "sfr_r813.h"



// User specific definitions
// Definitions for LC display
#define LCD_POWER_UP_DELAY_MS 50 // Power up delay in ms
#define LCD_INIT_DELAY_MS 10 // Initialization steps delay in ms
#define LCD_COLS 16 // Display columns
#define LCD_ROWS 2 // Display rows

// LCD clock pin definitions
#define LCD_CLOCK_BIT p1_0 // Bit
// LCD data pin definitions
#define LCD_DATA_BIT p1_1 // Bit

#endif
