#include <avr/io.h>
#include "config.h"
#include "mSPI.h"

void init_spi(int mode){
    switch(mode){
        case master:
            setPinDir(_PB, SS  , OUT);
            setPinDir(_PB, MOSI, OUT);
            setPinDir(_PB, SCK , OUT);
            _delay_ms(50);
            
            SPCR |= (1<<SPE)|(1<<MSTR);
            break;
        case slave:
            setPinDir(_PB, MISO, OUT);
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
