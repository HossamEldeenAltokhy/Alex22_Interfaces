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
   
    
    
    setPinDir(_PA, PA0, OUT);
    setPinDir(_PC, PC0, IN);
    
    
    setPinData(_PA, PA0, OFF);
  
    
   
    while (1) {

        if(isPressed(_PC,PC0)){
           togglePinData(_PA, PA0); 
           _delay_ms(500);
        }
          
    }

    return 0;
}














