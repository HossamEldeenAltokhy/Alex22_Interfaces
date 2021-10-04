/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */

#include <avr/io.h>
#include "config.h"
#include "mMotor.h"





int main(void) {
    /* Replace with your application code */
    // Initialization.....
   
    init_Motor(Motor1);
    init_Motor(Motor2);
    
    Motor_Reverse(Motor1);
    Motor_Reverse(Motor2);
    
    
    _delay_ms(5000);
    
    Motor_Stop(Motor1);
    while (1) {

       
        
            
          
    }

    return 0;
}














