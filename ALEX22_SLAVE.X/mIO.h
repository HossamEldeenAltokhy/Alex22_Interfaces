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
void set_Buzzer(int state);
int isPressed_B(int pinNum);

int isPressed(int portNum, int pinNum);



// PORT LEVEL
void setPortDir(int portNum, int state);
void setPortData(int portNum, int data);
void togglePortData(int portNum);

// PIN LEVEL
void setPinDir(int portNum,int pinNum, int state);
void setPinData(int portNum,int pinNum, int data);
void togglePinData(int portNum, int pinNum);
#endif	/* MIO_H */

