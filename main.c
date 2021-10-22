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

#define sec 5
#define min 0




int inc = 0;


int main(void) {
    /* Replace with your application code */
    // Initialization.....

 
    setOC0Mode(ClearOnComp);
    init_Timer(PWM, _CLk_1024);
    setOutCompare(100); // 0 ~ 255
    
 
    
    while (1) {


       
        if(isPressed(_PC, PC0)){
            // Increment
            inc += 10;
            OCR0 = inc;
            _delay_ms(500);
        }
        if(isPressed(_PC, PC1)){
            // Decrement
            inc -= 10;
            OCR0 = inc;
            _delay_ms(500);
        }



    }

    return 0;
}














