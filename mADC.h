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


// References
#define _AREF       0
#define _AVCC       1
#define _2.56V      3


#define _PRE128     7
    
void init_ADC(int _ch, int Ref, int Prescaler);

void ADC_SC();

int ADC_read();

#endif	/* MADC_H */

