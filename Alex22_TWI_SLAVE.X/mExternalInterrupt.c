#include <avr/io.h>
#include  "config.h"
#include  "mExternalInterrupt.h"


void init_INT(int _INT, int Mode){
    switch(_INT){
        case _INT0: 
            // Select Mode
            MCUCR &= ~((1<<ISC01)|(1<<ISC00));
            MCUCR |= Mode; 
            GICR |= (1<<INT0);
            break;
        case _INT1: 
            MCUCR &= ~((1<<ISC11)|(1<<ISC10));
            MCUCR |= (Mode<<2);
            break;
        case _INT2: 
//            Mode= Mode== 3?1:0;
            MCUCSR &= ~(1<<ISC2);
            MCUCSR |= (Mode<<ISC2);
            break;
        default:  

            
            break;
           
    }
}