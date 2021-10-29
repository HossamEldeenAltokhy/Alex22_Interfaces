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

ISR(USART_RXC_vect){
    // Receiving .....
    char data  = UDR;
    
    PORTA = data;
}


int main(void) {
    /* Replace with your application code */
    // Initialization.....


    init_uart(9600, Rx_enable , Tx_enable);
    
    setPortDir(_PA, OUT);
    setPortDir(_PC, OUT);
    sei();
    while (1) {


        PORTC++;
        _delay_ms(20);
       
        

    }

    return 0;
}














