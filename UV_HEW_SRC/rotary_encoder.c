#include "rotary_encoder.h"

volatile signed char enc_delta;          // -128 ... 127
static signed char last;
 
void encode_init( void )
{
  signed char new;
  new = 0;
  if( PHASE_A )
    new = 3;
  if( PHASE_B )
    new ^= 1;                   // convert gray to binary
  last = new;                   // power on state
  enc_delta = 0;
}
 
void rotarydecode(void)
{
  signed char new, diff;
  new = 0;
  if( PHASE_A )
    new = 3;
  if( PHASE_B )
    new ^= 1;                   // convert gray to binary
  diff = last - new;                // difference last - new
  if( diff & 1 ){               // bit 0 = value (1)
    last = new;                 // store new as next last
    enc_delta += (diff & 2) - 1;        // bit 1 = direction (+/-)
  }
}

signed char encode_read1( void )         // read single step encoders
{
  signed char val;
  val = enc_delta;
  enc_delta = 0;
  return val;                   // counts since last call
}

signed char encode_read2( void )         // read two step encoders
{
  signed char val;
  val = enc_delta;
  enc_delta = val & 1;
  return val >> 1;
}
 
signed char encode_read4( void )         // read four step encoders
{
  signed char val;
  val = enc_delta;
  enc_delta = val & 3;
  return val >> 2;
}
 
/* 
int main( void )
{
  int32_t val = 0;
 
  LEDS_DDR = 0xFF;
  encode_init();
  sei();
 
  for(;;){
    val += encode_read1();          // read a single step encoder
    LEDS = val;
  }
}*/