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


char str[]= "Hello";

int main(void) {
    /* Replace with your application code */
    // Initialization.....

 
    init_LCD_4bit();

    _delay_ms(100);

    LCD_goto_4bit(_ROW1, 5 );
    LCD_write_str_4bit(str);
    while (1) {

    


    }

    return 0;
}














