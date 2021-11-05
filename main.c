/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */
 
// MASTER AVR
#include <avr/io.h>
#include "config.h"
#include "mMotor.h"
#include "mLCD_4bit.h"
#include "mADC.h"
#include "mTimer.h"
#include "mSPI.h"
#include "mTWI.h"
#include <string.h>



int main(void) {
    /* Replace with your application code */
    // Initialization.....

    init_spi(master);
    spi_setClk(spi_clk_4, spi_x);
    
    
    _delay_ms(1000);
    char counter = 0;
    while (1) {


        spi_send(counter++);
        _delay_ms(500);
      


    }

    return 0;
}














