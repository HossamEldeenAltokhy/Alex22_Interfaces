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
    int x = 100;
    //char str[]= "Hello World!!";// 'H', 'E', 'L', '\0'
    

    init_LCD();
    
    _delay_ms(50);
    
    LCD_write_num(x);
    
    while (1) {

        if(isPressed(_PA, PA0)){
            x++;
            LCD_clear();
            LCD_write_num(x);
            _delay_ms(200);
        }
        if(isPressed(_PA, PA1)){
            x--;
            LCD_clear();
            LCD_write_num(x);
            _delay_ms(200);
        }
            
          
    }

    return 0;
}














