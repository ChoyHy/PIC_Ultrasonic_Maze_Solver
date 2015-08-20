#include <xc.h>
#include "mylcd.h"
#include "lcd.h"

void init_lcd()
{
    Lcd_Init();
}

void print_left_status()
{
    Lcd_Set_Cursor(2,12);
    Lcd_Write_String("Left ");
}
void print_go_status()
{
    Lcd_Set_Cursor(2,12);
    Lcd_Write_String("Go   ");

}
void print_right_status()
{
    Lcd_Set_Cursor(2,12);
    Lcd_Write_String("Right");
}
void print_sright_status()
{
    Lcd_Set_Cursor(2,12);
    Lcd_Write_String("S.R. ");
}


void print_left(unsigned int dist)
    {
        Lcd_Set_Cursor(1,5);    Lcd_Write_Char(dist % 10 + 48);
        Lcd_Set_Cursor(1,4);    Lcd_Write_String(".");
        dist /= 10;
        Lcd_Set_Cursor(1,3);    Lcd_Write_Char(dist % 10 + 48);
        dist /= 10;
        Lcd_Set_Cursor(1,2);    Lcd_Write_Char(dist % 10 + 48);
        dist /= 10;
        Lcd_Set_Cursor(1,1);    Lcd_Write_Char(dist % 10 + 48);
    }
void print_center(unsigned int dist2)
    {
        Lcd_Set_Cursor(2,4);    Lcd_Write_Char(dist2 % 10 + 48);
        Lcd_Set_Cursor(2,3);    Lcd_Write_String(".");
        dist2 /= 10;
        Lcd_Set_Cursor(2,2);    Lcd_Write_Char(dist2 % 10 + 48);
        dist2 /= dist2/10;
        Lcd_Set_Cursor(2,1);    Lcd_Write_Char(dist2 % 10 + 48);
    }
void print_right(unsigned int dist3)
{
        Lcd_Set_Cursor(1,14);    Lcd_Write_Char(dist3 % 10 + 48);
        Lcd_Set_Cursor(1,13);    Lcd_Write_String(".");
        dist3 /= 10;
        Lcd_Set_Cursor(1,12);    Lcd_Write_Char(dist3 % 10 + 48);
        dist3 /= 10;
        Lcd_Set_Cursor(1,11);    Lcd_Write_Char(dist3 % 10 + 48);
}