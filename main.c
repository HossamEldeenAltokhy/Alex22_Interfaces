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
#include <string.h>

ISR(USART_RXC_vect) {
    // Receiving .....
    static char arr[100];
    static int index = 0;
    arr[index] = UDR;

    
    if (arr[index] == '_') { //0x0D) {
        int x = strncmp(arr, "ON", index);
        if (x == 0) {
            set_Led(Led1, ON);
            set_Buzzer(ON);
        }
        x = strncmp(arr, "OFF", index);
        if (x == 0) {
            set_Led(Led1, OFF);
            set_Buzzer(OFF);
        }
        index = 0;
    } else {
        index++;
    }


    //    if(data == 'A'){
    //        PORTA = 0xFF;
    //    }
    //    if(data == 'B'){
    //        PORTA = 0x00;
    //    }
}

int main(void) {
    /* Replace with your application code */
    // Initialization.....


    init_uart(9600, Rx_enable, Tx_enable);

    
    
    init_Leds();
    init_Buzzer();
    _delay_ms(50);
    sei();
    while (1) {


      

        _delay_ms(500);
        uart_send('A');

    }

    return 0;
}














