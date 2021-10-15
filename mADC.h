/* 
 * File:   mADC.h
 * Author: hossa
 *
 * Created on October 9, 2021, 6:38 PM
 */

#ifndef MADC_H
#define	MADC_H


#define _CH0       PA0
#define _CH1       PA1
#define _CH1_0     0x10

// References
#define _AREF       0   // 00
#define _AVCC       1   // 01
#define _2_56V      3   // 11


#define _PRE128     7  // 111
    
void init_ADC(int _ch, int Ref, int Prescaler);

void ADC_SC();

int ADC_read();

void init_Interrupt_ADC();

#endif	/* MADC_H */

