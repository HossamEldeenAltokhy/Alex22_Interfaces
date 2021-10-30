#include <avr/io.h>
#include "config.h"
#include "mSPI.h"

void init_spi(int mode){
    switch(mode){
        case master:
            DDRB |= (1<<MOSI)|(1<<SS)|(1<<SCK);
            SPCR |= (1<<SPE)|(1<<MSTR);
            break;
        case slave:
            DDRB |= (1<<MISO);
            SPCR |= (1<<SPE);
            break;
    }
    
}
void spi_setClk(char spi_clk, int spi2X){
    SPCR |= (spi_clk<< SPR0);
    if(spi2X){
        SPSR |= (1<<SPI2X);
    }
}
void spi_send( char data){
    SPDR = data;
    while(!(SPSR & (1<< SPIF)));
}
char spi_receive(void){
    while(!(SPSR & (1<< SPIF)));
    return SPDR;
}
