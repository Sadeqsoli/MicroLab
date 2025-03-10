#include <mega32.h>
#include <stdio.h>
#include <delay.h>
#asm
.equ __lcd_port=0x18;PortB
#endasm
#include <lcd.h>


void main(void)
{
    PORTB = 0x00;
    DDRB = 0x00;
    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("microcontroller");
    lcd_gotoxy(5,1);
    lcd_putsf("course");
    
        
while (1)
    {
    

    }
}
