/*
 * File:   main.c
 * Author: hossa
 *
 * Created on October 30, 2021, 4:39 PM
 */

// SLAVE AVR
#include <avr/io.h>
#include "config.h"
#include "mSPI.h"
#include "mIO.h"

int main(void) {
    /* Replace with your application code */
    init_spi(slave);
    
    setPortDir(_PA, OUT);
    while (1) {
        
        PORTA = spi_receive();
        
    }
}
