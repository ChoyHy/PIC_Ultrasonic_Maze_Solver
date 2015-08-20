#include <xc.h>
#include "motor.h"
#include "mylcd.h"
void pwm1_setup(char x)
{
    int y,z;
    y = (8*x)>>2;
    z = (8*x)&0x03;
    CCPR1L = y;
    CCP1CONbits.DC1B = z;
    CCP1CONbits.CCP1M = 0xC;
}
void pwm2_setup(char x)
{
    int y,z;
    y = (8*x)>>2;
    z = (8*x)&0x03;
    CCPR2L = y;
    CCP2CONbits.DC2B = z;
    CCP2CONbits.CCP2M = 0xF;
}
void start_go()
{
    TMR2ON = 1;
}
void stop_go()
{
    while(PWM1 || PWM2);   //wait for both outputs = 0
    TMR2ON = 0;
}
void go_straight()
{
    DIR1 = 0;               //set direction both forward
    DIR2 = 0;
    pwm1_setup(S1);
    pwm2_setup(S2);
    print_go_status();
}
void turn_left()
{
    stop_go();
    __delay_us(100);
    start_go();
    pwm2_setup(L1);
    pwm1_setup(L2);
    print_left_status();
}
void turn_right()
{
    stop_go();
    __delay_us(100);
    start_go();
    pwm1_setup(R1);
    pwm2_setup(R2);
    print_right_status();
}
void u_turn()
{
    pwm1_setup(30);
    pwm2_setup(25);
}
void self_turn()
{
    pwm1_setup(30);
    pwm2_setup(25);
}
void reverse()
{
    pwm1_setup(30);
    pwm2_setup(25);
}
void slight_right()
{
    pwm1_setup(SR1);
    pwm2_setup(SR2);
    print_sright_status();
}
void hard_turn_left()
{
    pwm2_setup(HL1);
    pwm1_setup(HL2);
    print_left_status();
}