#include "config.h"
#include "mTWI.h"
#include <avr/io.h>


int  TWI_start(char address){
    char bus_status;
    // send Start Condition
    TWCR |= (1<<TWSTA)|(1<<TWINT)|(1<<TWEN);
    // waiting TWINT flag to read status code (pooling)
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8; // read status code.
    if(bus_status != 0x08)
        return 0;
    TWDR = address;
    TWCR |= (1<<TWINT)|(1<<TWEN); // send SLA
    // waiting TWINT flag to read status code (pooling)
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8; // read status code.
    if(bus_status == 0x18)
        return 1;

}
void TWI_stop(){
    // send Stop Condition
    TWCR |= (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
    while(TWCR & (1<<TWSTO));
}
int  TWI_write(char data){
    char bus_status;
    TWDR = data;
    TWCR |= (1<<TWINT)|(1<<TWEN); // send Data
    // waiting TWINT flag to read status code (pooling)
    while(!(TWCR & (1<<TWINT)));
    bus_status = TWSR & 0xF8; // read status code.
    if(bus_status == 0x28)
        return 1; // Data Transmitted & ACK received
    else 
        return 0; // NOT ACK
}
char TWI_read(){
    TWCR |= (1<<TWEA)|(1<<TWINT)|(1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
    return TWDR;
}

