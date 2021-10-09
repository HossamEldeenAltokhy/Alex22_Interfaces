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
}

void ADC_SC(){
    // Start Conversion.
    ADCSRA |= (1<<ADSC);
}

int ADC_read(){
    while(!(ADCSRA & (1<<ADIF)));
    // read Data Register
    // ADCH - ADCL
    int data = ADCL;
    data |= (ADCH<<8);
    return data;
    
}