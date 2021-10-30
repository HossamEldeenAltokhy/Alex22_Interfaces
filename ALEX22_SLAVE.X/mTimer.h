/* 
 * File:   mTimer.h
 * Author: hossa
 *
 * Created on October 16, 2021, 5:10 PM
 */

#ifndef MTIMER_H
#define	MTIMER_H


#define NORMAL  0
#define PWM     0x40 // 1
#define CTC     0x08 // 2
#define FPWM    0x48 // 3


#define _TimerOff     0
#define _NoPRE        1
#define _CLk_8        2
#define _CLk_64       3
#define _CLk_256      4
#define _CLk_1024     5

#define _CLk_ext_F    6
#define _CLk_ext_R    7

#define INT_TOV       TOIE0     
#define INT_TOC       OCIE0

#define ClearOnComp   2
#define SetOnComp     3


void init_Timer(int mode, int clockSelect);

void Timer_enable_INT(int selectINT);
void setOutCompare(unsigned char compareValue);
void setOC0Mode(int OC0_Mode);
#endif	/* MTIMER_H */

