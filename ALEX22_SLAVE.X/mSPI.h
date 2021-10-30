/* 
 * File:   mSPI.h
 * Author: hossa
 *
 * Created on October 30, 2021, 4:04 PM
 */

#ifndef MSPI_H
#define	MSPI_H

#define master   1
#define slave    0


#define spi_clk_4       0
#define spi_clk_16      1
#define spi_clk_64      2
#define spi_clk_128     3

#define SS              4   
#define MOSI            5
#define MISO            6
#define SCK             7

#define spi_x           0
#define spi_2x          1

void init_spi(int mode);
void spi_setClk(int spi_clk, int spi2X);
void spi_send(unsigned char data);
unsigned char spi_receive(void);

#endif	/* MSPI_H */

