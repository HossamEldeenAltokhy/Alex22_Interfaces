#include <avr/io.h>
#include "config.h"
void init_uart(int BaudRate,int RX_EN,int TX_EN){
    
    // Implementaion LEVEL
    UCSRB |= (RX_EN << RXEN);
    UCSRB |= (TX_EN << TXEN);
    // BaudRate
    UBRRL = (F_CPU/16.0/BaudRate)-1 ; // 103;
}

void uart_send(char data){
    // Check if UDR is EMPTY 
    while(!(UCSRA & (1<<UDRE))); 
    UDR = data;
}
void uart_send_str(char* str){
    
}
void uart_send_Num(int num){
        
}

char uart_receive(){
    
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}

