/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */

#include <avr/io.h>
#include "config.h"
#include "mMotor.h"
#include "mLCD_4bit.h"
#include "mADC.h"
#include "mTimer.h"

#define sec 1
#define min 0

ISR(TIMER0_COMP_vect) {

    static int x = 0;

    x++;
    if (x == 62 * (60 * min + sec)) {
        togglePortData(_PC);
        x = 0;
    }


}

int main(void) {
    /* Replace with your application code */
    // Initialization.....


    setPortDir(_PC, OUT);


    setOutCompare(127);
    Timer_enable_INT(INT_TOC);



    sei();
    init_Timer(CTC, _CLk_1024);


    while (1) {





    }

    return 0;
}














