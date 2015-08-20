#ifndef MYLCD_H
#define	MYLCD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 8000000
#endif

//LCD func.
void init_lcd();
void print_left_status();
void print_go_status();
void print_right_status();
void print_sright_status();

void print_left(unsigned int dist);
void print_center(unsigned int dist);
void print_right(unsigned int dist);

#ifdef	__cplusplus
}
#endif

#endif	/* MYLCD_H */

