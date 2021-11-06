#include "config.h"
#include "mTWI.h"
#include <avr/io.h>


void TWI_init_BitRate(){
    TWBR = 255;
    TWSR |= (1<<TWPS1)|(1<<TWPS0); // 4^64
}

int  TWI_start(char address){
    char bus_status;
    // send Start Condition
    TWCR = (1<<TWSTA)|(1<<TWINT)|(1<<TWEN);
    // waiting TWINT flag to read status code (pooling)
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8; // read status code.
    if(bus_status != 0x08)
        return 0;
    TWDR = address;
    TWCR = (1<<TWINT)|(1<<TWEN); // send SLA
    // waiting TWINT flag to read status code (pooling)
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8; // read status code.
    if(bus_status == 0x18)
        return 1;

}
void TWI_stop(){
    // send Stop Condition
    TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
    while(TWCR & (1<<TWSTO));
}
int  TWI_write(char data){
    char bus_status;
    TWDR = data;
    TWCR = (1<<TWINT)|(1<<TWEN); // send Data
    // waiting TWINT flag to read status code (pooling)
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8; // read status code.
    if(bus_status == 0x28)
        return 1; // Data Transmitted & ACK received
    else 
        return 0; // NOT ACK
}
char TWI_read(){
    TWCR = (1<<TWEA)|(1<<TWINT)|(1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
    return TWDR;
}

//////////////////////////////////////////////////////////////////////

void TWI_init_slave(char address){
    TWAR = address;
    TWCR = (1<<TWEA)|(1<<TWINT)|(1<<TWEN);
}
int  TWI_slave_listen(){
    char bus_status;
    
    while(1){
        // Pooling 
        // Waiting for TWINT flag
        while(!(TWCR & (1<<TWINT)));
        bus_status = TWSR & 0xF8;
        // Two Conditions or General Call
        // >> SLA+W
        if(bus_status == 0x60 || bus_status == 0x68)
            return 1;
        // >> SLA+R
        if(bus_status == 0xA8 || bus_status == 0xB0)   
            return 2;
    }
}
void TWI_slave_write(char data){
    char bus_status ;
    TWDR = data;
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8;
    if( bus_status == 0xB8)
        return 1;
    else 
        return 0;
}
char TWI_slave_read(){
    char bus_status ;
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8;
    if(bus_status == 0x80)
        return TWDR;
}