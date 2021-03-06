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
  
    TWI_init_BitRate();
    int x  = 0;

    _delay_ms(2000);
    while (1) {

        if(TWI_start(SLA_W)){
            // Start condition successfully Done!
            TWI_write(x++);
            
            TWI_stop();
        }
     

        _delay_ms(500);
    }

    return 0;
}














