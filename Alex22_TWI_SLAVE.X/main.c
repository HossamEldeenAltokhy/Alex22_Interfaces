/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */
 
// SLAVE AVR
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
  
    setPortDir(_PA, OUT);
    TWI_init_BitRate();
    TWI_init_slave(SLAVE_ADDRESS);
    while (1) {
        
        int code = TWI_slave_listen();
        if(code == 1){
            //SLA+W  >>>  Slave Reads
            char data = TWI_slave_read();
            PORTA = data;
        }
        else if(code == 2){
            //SLA+R >>> Slave Writes
            TWI_slave_write('A');
        }

    }

    return 0;
}














