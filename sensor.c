#include "sensor.h"
#include "mylcd.h"
#include <xc.h>
void trg_sensor()
{
        TRG = 0;
        __delay_us(2);
        TRG = 1;
        __delay_us(10);
        TRG = 0;
}

void check_left_dist(unsigned int* left_distance)
{
    TMR1H = 0x00;
    TMR1L = 0x00;
    trg_sensor();
    while(!ECHO)
        continue;
    TMR1ON = 1;
    while(ECHO)
        continue;
    TMR1ON = 0;
    *left_distance  = (int)((TMR1L | (TMR1H<<8))*0.17) + 10;
    print_left(*left_distance);
}
void check_center_dist(unsigned int* center_distance)
{
        TMR1H = 0x00;
        TMR1L = 0x00;
        trg_sensor();
        while(!ECHO2)
            continue;
        TMR1ON = 1;
        while(ECHO2)
            continue;
        TMR1ON = 0;
        *center_distance = (int)((TMR1L | (TMR1H<<8))*0.17) + 10;
        print_center(*center_distance);
}
void check_right_dist(unsigned int* right_distance)
{
            TMR1H = 0x00;
            TMR1L = 0x00;
        trg_sensor();
        while(!ECHO3)
            continue;
        TMR1ON = 1;
        while(ECHO3)
            continue;
        TMR1ON = 0;
        *right_distance = (int)((TMR1L | (TMR1H<<8))*0.17) + 10;
        print_right(*right_distance);
}

void compare_dist(const unsigned int* dist, const unsigned int* dist2)
{
    if(*dist > *dist2) 
    { 
        LATB6 = 0;
        LATB7 = 1;
    }
    else if(*dist < *dist2 ) 
    { 
        LATB6 = 1;
        LATB7 = 0;
    }
    else 
    { 
        LATB6 = 1;
        LATB7 = 1;
    }
}
