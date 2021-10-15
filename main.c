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







ISR(ADC_vect) {
    char str[] = " mV";
    int x = ADC_read() *4.887585532746823069403714565;
//    LCD_clear_4bit();
    LCD_write_num_4bit(x);
    LCD_write_str_4bit(str);
    _delay_ms(500);
}



int main(void) {
    /* Replace with your application code */
    // Initialization.....

    init_ADC(_CH1_0, _AVCC, _PRE128);
    init_Interrupt_ADC();
    init_LCD_4bit();

    _delay_ms(100);

    sei(); // Enable Global Interrupt
    while (1) {

        ADC_SC();

        //_delay_ms(500);


    }

    return 0;
}














