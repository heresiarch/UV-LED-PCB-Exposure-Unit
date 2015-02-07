// Module..: STRING_CONVERSION.C
// Version.: 1.0
// Compiler: CodeVisionAVR
// Chip....: ATmega88
// Date....: April 2008
// Author..: Udo Juerss
//-----------------------------------------------------------------------------

#include "string_conversion.h"
//-----------------------------------------------------------------------------

U08 SC_HEX_ARRAY[]  = "0123456789ABCDEF";
//-----------------------------------------------------------------------------

U08 sc_buffer[SC_BUFFER_LENGTH]; // Conversion buffer
//-----------------------------------------------------------------------------

pU08 sc_format(pU08 pstr,U08 digits) // Do formatted output
{
  U08 len = (U08)(pstr - SC_BUFFER_OFS_PTR); // Get length of string

  while (digits--) // Sting loop
  {
    if (len) // If character created by conversion, just skip left in buffer
    {
      pstr--;
      len--;
    }
    else // It must be a fill character
    {
      *--pstr = SC_FILL_CHAR;
    }
  }

  return pstr;
}
//-----------------------------------------------------------------------------

pU08 sc_U08_to_str(U08 value,U08 digits)
{
  pU08 pstr = SC_BUFFER_OFS_PTR;

  if (value >= 100) *pstr++ = ('0' + (value % 1000 / 100));
  if (value >= 10) *pstr++ = ('0' + (value % 100 / 10));
  *pstr++ = ('0' + (value % 10));
  *pstr = 0;

  if (!digits) // If digits = 0, then return buffer start
  {
    return SC_BUFFER_OFS_PTR;
  }
  else // Do formatted output
  {
    return sc_format(pstr,digits);
  }
}
//-----------------------------------------------------------------------------

pU08 sc_S08_to_str(S08 value,U08 digits)
{
  pU08 pstr = SC_BUFFER_OFS_PTR;

  if (value < 0)
  {
    *pstr++ = '-';
    value = -value;
  }

  if (value >= 100) *pstr++ = ('0' + (value % 1000 / 100));
  if (value >= 10) *pstr++ = ('0' + (value % 100 / 10));
  *pstr++ = ('0' + (value % 10));
  *pstr = 0;

  if (!digits) // If digits = 0, then return buffer start
  {
    return SC_BUFFER_OFS_PTR;
  }
  else // Do formatted output
  {
    return sc_format(pstr,digits);
  }
}
//-----------------------------------------------------------------------------

pU08 sc_U08_to_hex(U08 value)
{
  pU08 pstr = sc_buffer;

  *pstr++ = SC_HEX_ARRAY[value >> 4];
  *pstr++ = SC_HEX_ARRAY[value & 0x0F];
  *pstr = 0;

  return (sc_buffer);
}
//-----------------------------------------------------------------------------

pU08 sc_U08_to_bin(U08 value)
{
  U08 n;

  pU08 pstr = sc_buffer;

  for (n = 7; n < 8; n--)
  {
    if (value & (1 << n))
    {
      *pstr++ = '1';
    }
    else
    {
      *pstr++ = '0';
    }
  }

  *pstr = 0;

  return (sc_buffer);
}
//-----------------------------------------------------------------------------

pU08 sc_U16_to_str(U16 value,U08 digits)
{
  pU08 pstr = SC_BUFFER_OFS_PTR;

  if (value >= 10000) *pstr++ = ('0' + (value / 10000));
  if (value >= 1000) *pstr++ = ('0' + (value % 10000 / 1000));
  if (value >= 100) *pstr++ = ('0' + (value % 1000 / 100));
  if (value >= 10)*pstr++ = ('0' + (value % 100 / 10));
  *pstr++ = ('0' + (value % 10));
  *pstr = 0;

  if (!digits) // If digits = 0, then return buffer start
  {
    return SC_BUFFER_OFS_PTR;
  }
  else // Do formatted output
  {
    return sc_format(pstr,digits);
  }
}
//-----------------------------------------------------------------------------

pU08 sc_S16_to_str(S16 value,U08 digits)
{
  pU08 pstr = SC_BUFFER_OFS_PTR;

  if (value < 0)
  {
    *pstr++ = '-';
    value = -value;
  }

  if (value >= 10000) *pstr++ = ('0' + (value / 10000));
  if (value >= 1000) *pstr++ = ('0' + (value % 10000 / 1000));
  if (value >= 100) *pstr++ = ('0' + (value % 1000 / 100));
  if (value >= 10) *pstr++ = ('0' + (value % 100 / 10));
  *pstr++ = ('0' + (value % 10));
  *pstr = 0;

  if (!digits) // If digits = 0, then return buffer start
  {
    return SC_BUFFER_OFS_PTR;
  }
  else // Do formatted output
  {
    return sc_format(pstr,digits);
  }
}
//-----------------------------------------------------------------------------

pU08 sc_U16_to_hex(U16 value)
{
  tMEM16 data;
  pU08 pstr = sc_buffer;

  data.word = value;

  *pstr++ = SC_HEX_ARRAY[(data.byte[1]) >> 4];
  *pstr++ = SC_HEX_ARRAY[(data.byte[1]) & 0x0F];

  *pstr++ = SC_HEX_ARRAY[(data.byte[0]) >> 4];
  *pstr++ = SC_HEX_ARRAY[(data.byte[0]) & 0x0F];

  *pstr = 0;

  return (sc_buffer);
}
//-----------------------------------------------------------------------------

pU08 sc_internal_U32_to_str(U32 value,pU08 pstr)
{
  if (value >= 1000000000) *pstr++ = ('0' + (value / 1000000000));
  if (value >= 100000000) *pstr++ = ('0' + (value % 1000000000 / 100000000));
  if (value >= 10000000) *pstr++ = ('0' + (value % 100000000 / 10000000));
  if (value >= 1000000) *pstr++ = ('0' + (value % 10000000 / 1000000));
  if (value >= 100000) *pstr++ = ('0' + (value % 1000000 / 100000));
  if (value >= 10000) *pstr++ = ('0' + (value % 100000 / 10000));
  if (value >= 1000) *pstr++ = ('0' + (value % 10000 / 1000));
  if (value >= 100) *pstr++ = ('0' + (value % 1000 / 100));
  if (value >= 10) *pstr++ = ('0' + (value % 100 / 10));

  *pstr++ = ('0' + (value % 10));

  return pstr;
}
//-----------------------------------------------------------------------------

pU08 sc_U32_to_str(U32 value,U08 digits)
{
  pU08 pstr = SC_BUFFER_OFS_PTR;

  pstr = sc_internal_U32_to_str(value,pstr);
  *pstr = 0;

  if (!digits) // If digits = 0, then return buffer start
  {
    return SC_BUFFER_OFS_PTR;
  }
  else // Do formatted output
  {
    return sc_format(pstr,digits);
  }
}
//-----------------------------------------------------------------------------

pU08 sc_S32_to_str(S32 value,U08 digits)
{
  pU08 pstr = SC_BUFFER_OFS_PTR;

  if (value < 0)
  {
    *pstr++ = '-';
    value = -value;
  }

  if (value >= 1000000000) *pstr++ = ('0' + (value / 1000000000));
  if (value >= 100000000) *pstr++ = ('0' + (value % 1000000000 / 100000000));
  if (value >= 10000000) *pstr++ = ('0' + (value % 100000000 / 10000000));
  if (value >= 1000000) *pstr++ = ('0' + (value % 10000000 / 1000000));
  if (value >= 100000) *pstr++ = ('0' + (value % 1000000 / 100000));
  if (value >= 10000) *pstr++ = ('0' + (value % 100000 / 10000));
  if (value >= 1000) *pstr++ = ('0' + (value % 10000 / 1000));
  if (value >= 100) *pstr++ = ('0' + (value % 1000 / 100));
  if (value >= 10) *pstr++ = ('0' + (value % 100 / 10));
  *pstr++ = ('0' + (value % 10));
  *pstr = 0;

  if (!digits) // If digits = 0, then return buffer start
  {
    return SC_BUFFER_OFS_PTR;
  }
  else // Do formatted output
  {
    return sc_format(pstr,digits);
  }
}
//-----------------------------------------------------------------------------

pU08 sc_U32_to_hex(U32 value)
{
  tMEM32 data;
  pU08 pstr = sc_buffer;

  data.dword = value;

  *pstr++ = SC_HEX_ARRAY[(data.byte[3]) >> 4];
  *pstr++ = SC_HEX_ARRAY[(data.byte[3]) & 0x0F];

  *pstr++ = SC_HEX_ARRAY[(data.byte[2]) >> 4];
  *pstr++ = SC_HEX_ARRAY[(data.byte[2]) & 0x0F];

  *pstr++ = SC_HEX_ARRAY[(data.byte[1]) >> 4];
  *pstr++ = SC_HEX_ARRAY[(data.byte[1]) & 0x0F];

  *pstr++ = SC_HEX_ARRAY[(data.byte[0]) >> 4];
  *pstr++ = SC_HEX_ARRAY[(data.byte[0]) & 0x0F];

  *pstr = 0;

  return (sc_buffer);
}
//-----------------------------------------------------------------------------

pU08 sc_float_to_str(float value,U08 decimals)
{
  pU08 pstr = sc_buffer;

  if (value < 0)
  {
    *pstr++ = '-';
    value = -value;
  }

  pstr = sc_internal_U32_to_str((U32)value,pstr);

  value -= (U32)value;

  *pstr++ = '.';

  while (decimals--)
  {
    value *= 10.0;
  }

  pstr = sc_internal_U32_to_str((U32)value,pstr);

  *pstr = 0;

  return sc_buffer;
}
