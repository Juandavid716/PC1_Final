#include "globals.h"

/* global variables */
volatile int record, play, buffer_index;	// audio variables
volatile int left_buffer[BUF_SIZE];			// audio buffer
volatile int right_buffer[BUF_SIZE]; 		// audio buffer
volatile int x1=0,y1=0,x2=2,y2=2; 
volatile int incx=1, incy=1;
volatile int screen_x=319, screen_y=239; 
volatile short color1=0, color2=0xFFFFFF;
volatile char byte1, byte2, byte3;			// PS/2 variables
volatile int timeout;						// used to synchronize with the timer
volatile int mousesw;
volatile int vectorcorx[500];
volatile int vectorcory[500];
volatile int contador=0;
volatile int colorcor[500];
