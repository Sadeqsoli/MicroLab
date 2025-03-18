#include <mega32.h>
#include <delay.h>
#define xtal 8000000
unsigned char k;
flash unsigned char arr[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x00};
void main(void)
{
    DDRA = 0xFF;
    DDRB = 0xFF;
    while(1){
        for(k=0;k<=7;k++){
            PORTA = arr[k];
            PORTB = ~(1<<k);
            delay_us(100);
            PORTB = 0xFF;
        }
    }
}