/* 
 * File:   mUART.h
 * Author: hossa
 *
 * Created on September 25, 2021, 4:49 PM
 */

#ifndef MUART_H
#define	MUART_H

#define Rx_enable    1
#define Tx_enable    1
#define Rx_disable   0
#define Tx_disable   0
void init_uart(int BaudRate,int RX_EN,int TX_EN);

void uart_send(char data);
void uart_send_str(char* str);
void uart_send_Num(int num);

char uart_receive();


#endif	/* MUART_H */

