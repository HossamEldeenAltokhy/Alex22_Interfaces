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
#include "mTimer.h"



int main(void) {
    /* Replace with your application code */
    // Initialization.....


    init_uart(9600, 1 , 1);
    
    setPortDir(_PA, OUT);
    
    while (1) {


       
        char data = uart_receive();
        if(data == 'N'){
            PORTA = 0xFF;
        }
        if(data == 'F'){
            PORTA = 0x00;
        }
        _delay_ms(500);

    }

    return 0;
}














