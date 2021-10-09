/* 
 * File:   mExternalInterrupt.h
 * Author: hossa
 *
 * Created on October 9, 2021, 4:03 PM
 */

#ifndef MEXTERNALINTERRUPT_H
#define	MEXTERNALINTERRUPT_H


#define _INT0    0
#define _INT1    1
#define _INT2    2


#define _Mode_Low           0
#define _Mode_AnyChange     1
#define _Mode_Falling       2
#define _Mode_Rising       3


void init_INT(int _INT, int Mode);

#endif	/* MEXTERNALINTERRUPT_H */

