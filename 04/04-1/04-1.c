#include <mega32.h>
#include <stdio.h>
#include <delay.h>
#asm
    .equ __lcd_port= 0x1B;
#endasm
#include <lcd.h>
unsigned char scan_key(void);
unsigned char code[4][4]= {{7,4,1,10},{8,5,2,0},{9,6,3,11},{12,13,14,15}};
char lcd_buffer[12];




void main(void)
{
    unsigned char key;
    PORTC= 0x00;
    DDRC= 0xf0;
    lcd_init(16);
    lcd_clear();

while (1)
    {
        key = scan_key();
        if(key != 0xff){
            lcd_clear();
            lcd_gotoxy(0,0);
            sprintf(lcd_buffer, "Key=%d",key);
            lcd_puts(lcd_buffer);
            
        }
    }
}

unsigned char scan_key(void)
{   
    unsigned char i, data, num_key, temp;
    num_key = 0xff;
    temp = 0x70;
    for(i=0; i <4; i++)
    {
        PORTC= temp;
        delay_ms(5);
        data=PINC & 0x0f;
        if(data == 0x07) num_key=code[0][i];
        if(data == 0x0B) num_key=code[1][i];
        if(data == 0x0D) num_key=code[2][i];
        if(data == 0x0E) num_key=code[3][i];  
        temp = ((temp>>=1)| 0x80) & 0xf0;
    }
    return num_key;
}
