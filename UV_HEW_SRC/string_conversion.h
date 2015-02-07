#ifndef __STRING_CONVERSION_H
#define __STRING_CONVERSION_H
//-----------------------------------------------------------------------------

#include "typedefs.h"
#include "lcd_2wire.h"
//-----------------------------------------------------------------------------

#define SC_BUFFER_LENGTH 16 // Conversion buffer size
#define SC_BUFFER_OFS 5 // Conversion buffer offset for alignment
#define SC_FILL_CHAR 32 // Character for post digits

#define SC_BUFFER_OFS_PTR (sc_buffer + SC_BUFFER_OFS) // Buffer alignment addr
//-----------------------------------------------------------------------------

extern U08 sc_buffer[];
//-----------------------------------------------------------------------------

pU08 sc_format(pU08 pstr,U08 digits);
pU08 sc_U08_to_str(U8 value,U08 digits);
pU08 sc_S08_to_str(S08 value,U08 digits);
pU08 sc_U08_to_hex(U08 value);
pU08 sc_U08_to_bin(U08 value);
pU08 sc_U16_to_str(U16 value,U08 digits);
pU08 sc_S16_to_str(S16 value,U08 digits);
pU08 sc_U16_to_hex(U16 value);
pU08 sc_U32_to_str(U32 value,U08 digits);
pU08 sc_S32_to_str(S32 value,U08 digits);
pU08 sc_U32_to_hex(U32 value);
pU08 sc_float_to_str(float value,U08 decimals);
//-----------------------------------------------------------------------------

#endif
