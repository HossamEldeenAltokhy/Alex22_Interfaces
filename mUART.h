/* 
 * File:   mUART.h
 * Author: hossa
 *
 * Created on September 25, 2021, 4:49 PM
 */

#ifndef MUART_H
#define	MUART_H

void init_uart(int BaudRate,
        int RX_EN,
        int TX_EN,
        int INT_EN);

void uart_send(char data);
void uart_send_str(char* str);
void uart_send_Num(int num);
int uart_receive_Num();
char uart_receive();
char* uart_receive_str();

#endif	/* MUART_H */

