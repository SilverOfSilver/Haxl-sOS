
#include "vga.h"


void outb(unsigned char value, unsigned short port)
{
    /* Write the byte of data to the specified I/O port. */
    asm volatile ("outb %0, %1" : : "a" (value), "Nd" (port));
}
