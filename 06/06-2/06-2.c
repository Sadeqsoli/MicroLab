#include <mega64.h>

void main(void)
{
    DDRB=0x10;
    TCNT0=0x00;
    OCR0=25;
    TCCR0=0x6A;
    while(1);
}
