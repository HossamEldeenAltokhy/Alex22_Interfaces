#include <avr/io.h>
#include  "config.h"
#include  "mADC.h"


void init_ADC(int _ch, int Ref, int Prescaler){
    /*
       ADMUX:

        - Select Channel.
        - Select Voltage Reference.
        - Data Adjust. (neglect)

        ADCSRA:

        - Enable ADC.
        - Enable Interrupt. (neglect)
        - Select Prescaler.
     
     */
    ADMUX = 0x00;  // 00100000
    ADMUX |= _ch;  //00000001
    ADMUX |= (Ref<<REFS0);
    
    ADCSRA &= 0xF8;  // 11111000
    ADCSRA |= Prescaler;   // _PS128
    ADCSRA |= (1<<ADEN);
    
}

void ADC_SC(){
    // Start Conversion.
    ADCSRA |= (1<<ADSC);
}

int ADC_read(){
    
    // Wait HERE till Flag rises
    while(!(ADCSRA & (1<<ADIF)));
    int data = ADCL;
    data |= (ADCH<<8);
    return data;
    
}


void init_Interrupt_ADC(){
    ADCSRA |= (1<<ADIE);
}