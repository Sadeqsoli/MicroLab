#include <mega64.h>

void main(void)
{
    DDRB=0x10;
    TCNT0=0x00;
    OCR0=0x7c;
    TCCR0=0x1C;
    while(1);    

}
