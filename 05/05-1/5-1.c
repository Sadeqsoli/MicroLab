#include <delay.h>
#include <mega32.h>
#include <lcd.h>
#include <stdio.h>
#asm
    .equ __lcd_port= 0x1B;
#endasm


void main(void)
{
    
    
    while (1)
        {
            int H = 0;
            int M = 0;
            int S = 0;
            char lcd_buffer[10];
            lcd_init(16);
            lcd_clear();
            
             for(H=0; H <=24; H++)
            {
                lcd_gotoxy(6,0);
                sprintf(lcd_buffer, "%d:", H);
                lcd_puts(lcd_buffer);
                
                for(M=0; M <=60; M++)
                {
                    lcd_gotoxy(9,0);
                    sprintf(lcd_buffer, "%d:", M);
                    lcd_puts(lcd_buffer);
                    
                     for(S=0; S <=60; S++)
                    {
                        lcd_gotoxy(12,0);
                        sprintf(lcd_buffer, "%d", S);
                        lcd_puts(lcd_buffer);
                        delay_ms(5);
                    }
                    lcd_gotoxy(12,0);
                    lcd_putsf("  ");
                }
                lcd_gotoxy(9,0);
                lcd_putsf("  "); 
            }
            lcd_gotoxy(6,0);
            lcd_putsf("  ");
        }
    }
