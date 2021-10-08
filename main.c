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





int main(void) {
    /* Replace with your application code */
    // Initialization.....
   
    char str[] = " Hello";
    int x =909;
    init_LCD_4bit();

    _delay_ms(50);
//    LCD_write_str_4bit(str);
    LCD_write_num_4bit(x);
    while (1) {

        
       
        
            
          
    }

    return 0;
}














