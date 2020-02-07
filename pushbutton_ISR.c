#include "address_map_nios2.h"
#include <stdio.h>
extern volatile int buffer_index;
extern volatile int x1,x2,y1,y2;
extern volatile int screen_x, screen_y; 
extern volatile int incx, incy;
extern volatile int color1, color2;
extern volatile int mousesw;
extern volatile int contador;
extern volatile int vectorcorx[500];
extern volatile int vectorcory[500];
extern volatile int colorcor[500];
void VGA_box (int, int, int, int, short);
/*******************************************************************************
 * Pushbutton - Interrupt Service Routine
 *
 * This ISR checks which KEY has been pressed. If KEY0, then it enables audio-in
 * interrupts (recording). If KEY1, it enables audio-out interrupts (playback).
 ******************************************************************************/
void pushbutton_ISR( void )
{
	volatile int * KEY_ptr = (int *) KEY_BASE;
	int KEY_value;
	KEY_value = *(KEY_ptr + 3);			// read the pushbutton interrupt register
	*(KEY_ptr + 3) = KEY_value; 
			// Clear the interrupt
	if (KEY_value == 0x1 && x2 < 77)				// check KEY0
	{	
		
		VGA_box (x1,y1,x2, y2,0);
		x2+=incx;
		x1+=incx;
		VGA_box (x1,y1,x2,y2,color2);
		// reset the buffer index for recording
     	printf("x%i",x1);
		
	}
	else if (KEY_value == 0x2 && y1 != 0)			// check KEY1
	{
		VGA_box (x1,y1,x2, y2,0);
		y1-=incy;
		y2-=incy;
		VGA_box (x1,y1,x2,y2,color2);
		printf("y%i",y1);
	}
	else if (KEY_value == 0x4 && y2<56)			// check KEY1
	{
		VGA_box (x1,y1,x2, y2,0);
		
		y1+=incy;
		y2+=incy;
		VGA_box (x1,y1,x2,y2,color2);
		printf("y%i",y2);
		
	}
	else if (KEY_value == 0x8 && x1 !=0)			// check KEY1
	{
		VGA_box (x1,y1,x2, y2,0);
		x1-=incx;
		x2-=incx;
		VGA_box (x1,y1,x2,y2,color2);
		printf("x%i",x1);
	}
	
	return;
}
