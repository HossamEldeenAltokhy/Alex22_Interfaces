/* 
 * File:   mIO.h
 * Author: hossa
 *
 * Created on September 25, 2021, 4:26 PM
 */

#ifndef MIO_H
#define	MIO_H


    



void init_Leds();
void init_Relay();
void init_Buzzer();
void init_Buttons();

void set_Relay(int state);
void set_Led(int LedNumber, int state);

int isPressed_B(int pinNum);

int isPressed(int portNum, int pinNum);




#endif	/* MIO_H */

