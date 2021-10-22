
#include <avr/io.h>
#include  "config.h"
#include  "mTimer.h"

void init_Timer(int mode, int clockSelect) {

    TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
    
    
    
    TCCR0 |= mode;
    TCCR0 |= clockSelect;
    
    
//    switch (mode) {
//        case NORMAL:
//            TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
//            break;
//        case PWM:
//            TCCR0 |= (1 << WGM00);
//            break;
//        case CTC:
//            TCCR0 |= (1 << WGM01);
//            break;
//        case FPWM:
//            TCCR0 |= (1 << WGM00) | (1 << WGM01);
//            break;
//    }
    
    
//    switch (clockSelect) {
//        case _TimerOff:
//            TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
//            break;
//        case _NoPRE:
//            TCCR0 |= (1 << CS00);
//            break;
//        case _CLk_8:
//            TCCR0 |= (1 << CS01);
//            break;
//        case _CLk_64:
//            TCCR0 |= (1 << CS01)  | (1 << CS00);
//            break;
//        case _CLk_256:
//            TCCR0 |= (1 << CS02) ;
//            break;
//        case _CLk_1024:
//            TCCR0 |= (1 << CS02) | (1 << CS00) ;
//            break;
//        case _CLk_ext_F:
//            TCCR0 |= (1 << CS02) | (1 << CS01) ;
//            break;
//        case _CLk_ext_R:
//            TCCR0 |= (1 << CS02) | (1 << CS01) | (1 << CS00);
//            break;
//    }
//}
}


void Timer_enable_INT(int selectINT){
    TIMSK |= (1<<selectINT);
}

void setOutCompare(unsigned char compareValue){
    OCR0 = compareValue;
}

void setOC0Mode(int OC0_Mode){
    // Config Data Direction for OC0 pin ***********
    setPinDir(_PB, PB3, OUT);
    TCCR0 &= ~((1<<COM01)|(1<<COM00));
    TCCR0 |= (OC0_Mode << COM00);
}