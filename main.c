/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */

#include <avr/io.h>
#include "config.h"





int main(void) {
    /* Replace with your application code */
    // Initialization.....
   
    setPortDir(_PA, OUT);
    
    
    
    
   
    while (1) {
        //if (isPressed_B(Btn0)) 
        setPortData(_PA, 0xFF);
        _delay_ms(500);
        setPortData(_PA, 0x00);
        _delay_ms(500);
            
    }

    return 0;
}














