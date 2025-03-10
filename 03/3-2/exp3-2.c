#include <mega32.h>
#include <stdio.h>
#include <delay.h>
#asm
.equ __lcd_port=0x18;PortB
#endasm
#include <lcd.h>


void main(void)
{
    int i,j;
    char buffer1[] = "microcontroller";
    char buffer2[] = "     course";
    PORTB = 0x00;
    DDRB = 0x00;
    lcd_init(16);
    lcd_clear();
while (1)
    {
        for(i=0; i < 15; i++)
        {
            lcd_gotoxy(i,0);   
            lcd_putchar(buffer1[i]);
            delay_ms(50);   
        }
        for(j=5; j < 11; j++)
        {
            lcd_gotoxy(j,1);   
            lcd_putchar(buffer2[j]);   
            delay_ms(50);
        }
        lcd_clear();
    }
}