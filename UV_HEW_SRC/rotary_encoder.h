#ifndef __ROTARY_ENCODER_H
#define __ROTARY_ENCODER_H
//-----------------------------------------------------------------------------
#include "typedefs.h"
#include "rotary_encoder_customizations.h"

// init
void encode_init( void );
// called in ISR every 1 ms
void rotarydecode(void);             // 1ms for manual movement

// read single step encoders
signed char encode_read1(void);
 
// read two step encoders 
signed char encode_read2(void);
 
// read four step encoders 
signed char encode_read4(void);
#endif

 
