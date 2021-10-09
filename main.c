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


ISR(INT0_vect){
    togglePinData(_PC, Led0);
}




int main(void) {
    /* Replace with your application code */
    // Initialization.....

    

    init_Leds();
    setPortDir(_PA, OUT);
    
    /// Interrupt Configuration ///
    
    //  Select Mode on Falling Edge Detection
    MCUCR |= (1<<ISC01);//|(1<<ISC00);
    //  Enable Interrupt
    GICR |= (1<<INT0);
    //  Enable Global Interrupt
    sei();
            
    while (1) {

        togglePortData(_PA);
        _delay_ms(500);
        
            
          
    }

    return 0;
}














