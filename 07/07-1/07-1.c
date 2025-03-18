#include <mega32.h>
#include <delay.h>
#define LED PORTB.0
void main(){
DDRB=0xFF;
PORTB=0x00;
GICR=0x40;
MCUCR=0x03;
GIFR=0x40;
#asm("sei");
while(1);
}
//------------------------------
interrupt [2] void ext_int0 (void)
{
#asm("cli");
LED=1;
delay_ms(1000);
LED=0;
delay_ms(2000);
#asm("sei");
}