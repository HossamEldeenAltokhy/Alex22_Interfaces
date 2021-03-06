/* 
 * File:   mTWI.h
 * Author: hossa
 *
 * Created on November 5, 2021, 4:54 PM
 */

#ifndef MTWI_H
#define	MTWI_H


#define mAddress    0x06    // TWAR
#define SLA_R       0x03    // SLA+R == 0000001+1
#define SLA_W       0x02    // SLA+W == 0000001+0


void TWI_init_BitRate();


int  TWI_start(char address);
void TWI_stop();
int  TWI_write(char data);
char TWI_read();
//////////////////////////////////
void TWI_init_slave(char address);
int  TWI_slave_listen();
void TWI_slave_write(char data);
char TWI_slave_read();


#endif	/* MTWI_H */

