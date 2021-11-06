#include <avr/io.h>
#include "config.h"
#include "mUART.h"
#include <stdlib.h>

void init_uart(int BaudRate,int RX_EN,int TX_EN){
    
    // Implementaion LEVEL
    UCSRB |= (RX_EN << RXEN);
    UCSRB |= (TX_EN << TXEN);
    UCSRB |= (1<<RXCIE);
    // BaudRate
    int _UBRR = (F_CPU/16.0/BaudRate)-1 ; // 103;
    UBRRL = _UBRR;
    if(_UBRR >255){
       UBRRH = (_UBRR>>8); 
    }
    
    
}

void uart_send(char data){
    // Check if UDR is EMPTY 
    while(!(UCSRA & (1<<UDRE))); 
    UDR = data;
}

// "Hello" +'\0'
void uart_send_str(char* str){
    for(int i = 0 ; str[i]!= '\0' ; i++){
        uart_send(str[i]);
    }
}
void uart_send_Num(int num){
    
    char buff[11];
    itoa(num, buff, 10);
    uart_send_str(buff);
}

char uart_receive(){
    
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}

