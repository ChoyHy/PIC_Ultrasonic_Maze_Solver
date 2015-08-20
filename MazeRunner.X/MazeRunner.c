#include "MazeRunner.h"
#include "mylcd.h"
#include "motor.h"
#include "sensor.h"
#define LEFT_RANGE 290
#define FRONT_RANGE 250
#define RIGHT_RANGE 250
#define SLEFT_RANGE 150

// Motor speed declaration
#define S1 12
#define S2 12
#define L1 24 //20
#define L2 10
#define R1 26//24
#define R2 3
#define SR1 11
#define SR2 10
#define HL1 18
#define HL2 3

//Main Prog.------------------------------------------------------------------//
int main()
{
    //reg. declaration
    unsigned int left_distance, center_distance;//, right_distance;
   // unsigned int temp_leftdist, temp_centerdist;//, temp_rightdist;
    io_config();
    init_lcd();
    setup_timer();
    go_straight();
    start_go();
    delay_s(2);

            while(1)
            {
                check_left_dist(&left_distance);
                if(left_distance > LEFT_RANGE)
                {
                    check_center_dist(&center_distance);
                    if(center_distance < FRONT_RANGE)         go_straight();
                    else if(center_distance < SLEFT_RANGE)   slight_right();
                    else      turn_left();
                }
                else
                {
                    turn_right();
                }
            }

}
//============================================================================//
void io_config()
{
    TRISB = 0x00;
    TRISD = 0x00;
    TRISC = 0x00;
    TRISA = 0x07;
    ADCON1bits.PCFG = 0xF;
}
void delay_s(unsigned int x)
{
    unsigned int i;
    for(i=20*x;i!=0;i--)
    __delay_ms(50);
}
void setup_timer()
{
    //T1CON REG(Default = 0x00)
    //T1CONbits.RD16 = 1;         //Enables register read/write of Timer1 in one 16-bit operation
    //T1RUN = 0;                  //Device clock is derived from another source
    //T1CKPS1 = 0x01;             //01 = 1:2 Prescale value
    //T1OSCEN = 0;                //0 = Timer1 oscillator is shut off
    //TMR1CS = 0;                 //0 = Internal clock (FOSC/4)
    //TMR1ON = 0;                 //0 = Stops Timer1

    //T0CON REG (** Default = 0xFF)
    //TMR0ON = 0;             //Stop first
    //T08BIT = 0;             //16-bits counter
    //T0CS = 0;               //Int. inst. clock is used
    //T0SE = 1;              //Source edge selection
    //PSA = 0;               //Prescaler is not assigned
    //T0CON &= 0xF8;         //Prescale value = 1:2

    PR2 = 199;
}
void setup_int()
{
    //RCON REG (Default=b01U11100)
    IPEN = 0;               //Disable Priority Level on int.

    //INTCON REG (Default=b0000000x)
    GIE = 0;                //Enable all unmasked int.
    PEIE = 1;               //Enable all unmasked peripheral int.
    TMR0IE = 0;             //Disable TMR0 ovf int.
    INT0IE = 0;             //Enable INT0 ext. int.
    RBIE = 0;               //Enable RB PC int.
    TMR0IF = 0;             //clear TMR0 int. flag
    INT0IF = 0;             //clear INT0 int flag
    RBIF = 0;               //clear RB PC int flag

    //INTCON2 REG (Default=b1111U1U1)
    //nRBPU = 1;              //disable portB pull-ups
    INTEDG0 = 1;            //INT0 int on rising edge
    //INTEDG1 = 1;
    //ONTEDG2 = 1;
    //TMR0IP = 1;
    //BRIP =1;
}
//============================================================================//

//============================================================================//
