#include "delay.h"

void wait_us(unsigned long y)
{ 
  y = y /2 +1;
  while(y)
  {
	y--;
  }	  
}

void wait_ms(unsigned long y)
{ long z;
  y = y * 520;
  for(z=0;z<y;z++)
  {
	
  }
}
