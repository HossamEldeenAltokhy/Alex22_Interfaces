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
#include "mExternalInterrupt.h"

// Interrupt Service Routine
ISR(INT0_vect){
    
    togglePortData(_PA);
    
}


int main(void) {
    /* Replace with your application code */
    // Initialization.....

    setPortDir(_PA, OUT);

    
    init_INT(_INT0, _Mode_Rising);
    sei();
            
    int x;
    while (1) {

        x++;
          
    }

    return 0;
}














