#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef DIR1
    #define DIR1 LATCbits.LATC0         //0=forward; 1=backward
#endif
#ifndef DIR2
    #define DIR2 LATCbits.LATC3
#endif
#ifndef PWM1
    #define PWM1 PORTCbits.RC2
#endif
#ifndef PWM2
    #define PWM2 PORTCbits.RC1
#endif

#ifndef F
#define F 300
#endif
#ifndef L
#define L 250
#endif
#ifndef R
#define R 250
#endif
#ifndef SR
#define SR 150
#endif

#ifndef S1
#define S1 12
#endif
#ifndef S2
#define S2 12
#endif
#ifndef L1
#define L1 24 //20
#endif
#ifndef L2
#define L2 10
#endif
#ifndef R1
#define R1 26//24
#endif
#ifndef R2
#define R2 3
#endif
#ifndef SR1
#define SR1 11
#endif
#ifndef SR2
#define SR2 10
#endif
#ifndef HL1
#define HL1 18
#endif
#ifndef HL2
#define HL2 3
#endif

void pwm1_setup(char x);
void pwm2_setup(char x);
void start_go();
void stop_go();
void go_straight();
void turn_left();
void turn_right();
void u_turn();
void self_turn();
void reverse();
void slight_right();
void hard_turn_left();


#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */

