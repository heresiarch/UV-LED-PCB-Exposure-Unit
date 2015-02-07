/*
main.c under source control

*/ 

#include "sfr_r813.h"
#include "typedefs.h"
#include "lcd_2wire.h"
#include "rotary_encoder.h"

#pragma interrupt timerX;

#define MIN_TIMER_VAL = 1
#define MAX_TIMER_VAL = 9999

void init(void);
void debounceSwitches(void);

// which pin we use
unsigned char output = 0;
unsigned char knob_up = 0;
unsigned char y_old = 0;
unsigned char flag = 0;
unsigned char long_pressed = 0;
unsigned int  long_counter = 0;

// some timers
unsigned int timer = 1;
unsigned int dirty = 0;
unsigned long timercounter = 0;
unsigned int counter; 

enum Status
{
	SET_TIMER = 1, TIMER_READY, TIMER_RUN, TIMER_FIN, COVER_OPEN, DUMMY
};

typedef enum Status StatusEnum;

StatusEnum s = SET_TIMER;
StatusEnum old = DUMMY;  
StatusEnum history = DUMMY; 


void setTimer(unsigned int val);
void timerReady(void);
void runTimer(void);
void timerFinished(void);
void cover_open(void);

void main(void)
{
	signed char val;
	signed char ouput;
	int n;
	// low level init
	init();
	// Initialize LCD interface
	lcd_init(); 
	// Rotary encoder init
	encode_init();
  	// clear display
	lcd_clear();
	// goto home
	lcd_home();
	// Display welcome Message and sleep 5 seconds
	lcd_write_str_xy(0,0,"UV-LED Exposure");
	lcd_write_str_xy(0,1,"(c) Rene Meyer");
	while(!knob_up);
	knob_up = 0;
	lcd_clear();
	lcd_home();	
	while(true)
	{
		// read encoder state
		val = encode_read2();
		// read cover state
		if(p1_6 == 0)
		{
			// save old state
			if(s != COVER_OPEN)
			{
				history = s;	
				s = COVER_OPEN;
			}	
		}
		else
		{
			if(s == COVER_OPEN)
			{
				s = history;	
			}
		}	
		// State changed
		if(old != s)
		{
			lcd_clear();
			lcd_home();
			old = s;
			dirty = 1;	
		}
		switch (s)
		{
			case COVER_OPEN:
				cover_open();
				break;
			case SET_TIMER:
				setTimer(val);				
				break;
			case TIMER_READY:
				timerReady();				
				break;
			case TIMER_RUN:
				runTimer();				
				break;
			case TIMER_FIN:
				timerFinished();				
				break;
		}
	}
}

void setTimer(unsigned int val)
{
	if ((val == -1) && (timer > 1))
	{
		timer--;
		dirty = 1;
	}
	else if (val == +1 && timer < 9999)
	{
		timer ++;
		dirty = 1;
	}	 	
	else if( knob_up == 1)
	{
		knob_up = 0;
		dirty = 1;
		s = TIMER_READY;
	}
	if(dirty)
	{
		lcd_write_str_xy(0,0,"Set Time in s");
		lcd_goto_xy(12,1);
		lcd_write_U16(timer,4);
		dirty = 0;
	}	
}	

void timerReady(void)
{
	if(dirty)
	{
		lcd_write_str_xy(0,0,"Timer ready!");
		lcd_goto_xy(12,1);
		lcd_write_U16(timer,4);
		dirty = 0;
	}
	if( knob_up == 1)
	{
		knob_up = 0;
		dirty = 0;
		s = TIMER_RUN;
		timercounter = 0;
		counter = timer;
	}
	else if (long_pressed == 1)
	{
		long_pressed = 0;
		knob_up = 0;
		s = SET_TIMER;
	}		
}

void runTimer(void)
{
	unsigned int test;
	// enable UV Light
	p1_2 = 1;
	test = timer - (unsigned int)(timercounter / 1000); 
	if(dirty)
	{
		lcd_write_str_xy(0,0,"Timer running!");
		lcd_goto_xy(12,1);
		lcd_write_U16(test,4);
		dirty = 1;
	}
	if(test == 0)
	{
		s = TIMER_FIN;	
		p1_2 = 0;
	}	
}

void timerFinished(void)
{
	if(dirty)
	{
		lcd_write_str_xy(0,0,"Timer finished!");
		lcd_goto_xy(12,1);
		lcd_write_U16(timer,4);
		dirty = 0;
	}
	if( knob_up == 1)
	{
		knob_up = 0;
		dirty = 0;
		s = SET_TIMER;
	}
}		

void cover_open(void)
{
	p1_2 = 0;
	if(dirty)
	{
		lcd_write_str_xy(0,0,"Close cover!");
		lcd_write_str_xy(0,1,"UV Radioation!");
		dirty = 0;
	}
}	


void init(void)
{
		 /*-------------------------------------------------
    -  Change on-chip oscillator clock to Main clock  -
    -------------------------------------------------*/
	
    prc0 = 1;           /* Protect off */
    cm13 = 1;           /* Xin Xout */
    cm15 = 1;           /* XCIN-XCOUT drive capacity select bit : HIGH */
    cm05 = 0;           /* Xin on */
    cm16 = 0;           /* Main clock = No division mode */
    cm17 = 0;
    cm06 = 0;           /* CM16 and CM17 enable */
    asm("nop");         /* Waiting for stable of oscillation */
    asm("nop");
    asm("nop");
    asm("nop");
    ocd2 = 0;           /* Main clock change */
    prc0 = 0;           /* Protect on */
	pd1 = 0x07;         /* Set Port 1.0 - 1.2 be used for output*/
	asm( "\tFSET	I");	/* Enable interrupt */
	/**************************************
	//	Timer X Setting
	//**************************************/
	
	txck0=0;txck1=0;                         //count source:f1(tcss bit 0 and 1)
	prex=249;                                //Timer value for timer mode or half period timing for pulse output mode
	tx=79;                                   //Timer value for timer mode or half period timing for pulse output mode
	txmod0=0;txmod1=0;                       //Timer mode(txmr bit 0 and 1)
	txic=0x07;                               //Set interrupt piority level 7(txic)
	txs=1;		//Set txs=1 to start Timer X counting
}

// called every 1ms
void timerX(void)
{
	debounceSwitches();
	rotarydecode();
	if(s != COVER_OPEN)
	{
		timercounter++;
	}
}

void debounceSwitches(void)
{
	unsigned char temp = 0;
	temp=(y_old>>2);
	y_old=y_old-temp;
	if(p1_3==1)
	{
		y_old=y_old+0x3F;
	}
	if((y_old > 0xF0)&&(flag==0)) 
	{
		flag=1;
		output=1;
		long_pressed = 0;
		long_counter = 0;
	}	 
	if((y_old < 0x0F)&&(flag==1))
	{
		if(long_pressed == 0)
		{
			knob_up = 1;
		}
		flag=0;
		output=0;
		long_pressed = 0;
		long_counter = 0;
	}
	if( flag == 1)
	{
		long_counter++;
	}
	else
	{
		long_counter = 0;
	}
	
	if(long_counter > 1024)
	{
		long_pressed = 1;
	}	
}	



