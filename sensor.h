#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 8000000
#endif
    
//#define TRG2 LATCbits.LATC5
//#define TRG3 LATCbits.LATC6
    
#ifndef TRG
#define TRG LATDbits.LATD3
#endif
#ifndef ECHO
#define ECHO PORTAbits.RA0
#endif
#ifndef ECHO2
#define ECHO2 PORTAbits.RA1
#endif
#ifndef ECHO3
#define ECHO3 PORTAbits.RA2
#endif

//sensor func.
void trg_sensor();
void compare_dist(const unsigned int* dist, const unsigned int* dist2);

void check_left_dist(unsigned int* left_distance);
void check_center_dist(unsigned int* center_distance);
void check_right_dist(unsigned int* right_distance);
#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

