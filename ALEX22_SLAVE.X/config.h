/* 
 * File:   config.h
 * Author: hossa
 *
 * Created on September 25, 2021, 5:05 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H


#define F_CPU 16000000UL

#define Relay   PA2
#define Buzzer  PA3


#define Led0    PC2
#define Led1    PC7
#define Led2    PD3


#define ON     1
#define OFF    0

#define OUT     1
#define IN      0


#define Btn0   0 //PB0
#define Btn1   6 //PD6
#define Btn2   2 //PD2

#define _PA    0
#define _PB    1
#define _PC    2
#define _PD    3

// Motor Drive
#define H_A1  PC3
#define H_A2  PC4
#define H_A3  PC5
#define H_A4  PC6
#define H_EN1 PD4
#define H_EN2 PD5

#include <util/delay.h>
#include "mUART.h"
#include "mIO.h"
#include <avr/interrupt.h>
//#include "mLCD.h"

#endif	/* CONFIG_H */

