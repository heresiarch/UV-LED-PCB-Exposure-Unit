#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H
//-----------------------------------------------------------------------------

//#define F_CPU 16000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
//-----------------------------------------------------------------------------

#define true 1
#define TRUE 1
#define ON 1
#define on 1
#define SET 1
#define set 1

#define false 0
#define FALSE 0
#define OFF 0
#define off 0
#define CLEAR 0
#define clear 0

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80
#define BIT8 0x0100
#define BIT9 0x0200
#define BIT10 0x0400
#define BIT11 0x0800
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000
#define BIT16 0x010000
#define BIT17 0x020000
#define BIT18 0x040000
#define BIT19 0x080000
#define BIT20 0x100000
#define BIT21 0x200000
#define BIT22 0x400000
#define BIT23 0x800000
#define BIT24 0x01000000
#define BIT25 0x02000000
#define BIT26 0x04000000
#define BIT27 0x08000000
#define BIT28 0x10000000
#define BIT29 0x20000000
#define BIT30 0x40000000
#define BIT31 0x80000000
//-----------------------------------------------------------------------------

// Typendeklarationen
typedef signed char S8;
typedef signed char S08;
typedef signed char tS08;
typedef unsigned char U8;
typedef unsigned char U08;
typedef unsigned char tU08;

typedef signed int S16;
typedef signed int tS16;
typedef unsigned int U16;
typedef unsigned int tU16;
typedef signed long S32;
typedef signed long tS32;
typedef unsigned long U32;
typedef unsigned long tU32;

typedef S08 *pS8;
typedef S08 *pS08;
typedef U08 *pU8;
typedef U08 *pU08;
typedef S16 *pS16;
typedef U16 *pU16;
typedef S32 *pS32;
typedef U32 *pU32;
typedef float *pfloat;

typedef U08 BOOL;
typedef BOOL *pBOOL;

typedef union uMEM16 // Word and Byte access to 16-Bit data
{
  U16 word; // Word
  pU16 pword; // Pointer to Word
  U08 byte[2]; // Byte
  pU08 pbyte; // Pointer to Byte
} tMEM16;

typedef union uMEM32 // DWord, Word and Byte access to 32-Bit data
{
  U32 dword; // DWORD
  pU32 pdword[2]; // Pointer to U32

  float fp; // Float
  pfloat pfp[2]; // Pointer to float

  U16 word[2]; // Word
  pU16 pword[2]; // Pointer to U16

  U08 byte[4]; // Byte
  pU08 pbyte[2]; // Pointer to U08

} tMEM32;

//-----------------------------------------------------------------------------

#endif
