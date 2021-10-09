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




int main(void) {
    /* Replace with your application code */
    // Initialization.....

    init_ADC(_CH1, _AVCC, PRE128);
    
    init_LCD_4bit();

    while (1) {

        ADC_SC();
        int x = ADC_read();
        LCD_clear_4bit();
        LCD_write_num_4bit(x);
        _delay_ms(500);
     
          
    }

    return 0;
}














