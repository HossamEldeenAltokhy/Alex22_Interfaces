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
    init_Buzzer();
    init_Relay();
    init_Leds();
    init_Buttons();
   
    while (1) {
        //if (isPressed_B(Btn0)) 
        if(isPressed(_PB, Btn0)){
            set_Led(Led0, ON);
        } else {
            set_Led(Led0, OFF);
        }
        if(isPressed(_PD, Btn1)){
            set_Relay(ON);
        }else{
            set_Relay(OFF);
        }
    }

    return 0;
}














