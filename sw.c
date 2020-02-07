#include "address_map_nios2.h"
extern volatile int x2, y2;
extern volatile int incx, incy;
int value;

int sw (void)
{
	volatile int * SW_switch_ptr = (int *) SW_BASE;
	value = * (SW_switch_ptr);
	return value;
}
