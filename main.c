/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */
#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>

#define Relay  2   // PA2
#define Buzzer 3   // PA3


#define Led0   2   // PC2
#define Led1   7   // PC7
#define Led2   3   // PD3


#define ON     1
#define OFF    0

#define Btn0   0 //PB0
#define Btn1   6 //PD6
#define Btn2   2 //PD2
void init_Leds();
void init_Relay();
void init_Buzzer();
void init_Buttons();

void set_Relay(int state);
void set_Led(int LedNumber, int state);

int isPressed_B(int pinNum);
int main(void) {
    /* Replace with your application code */
    // Initialization.....
    init_Buzzer();
    init_Relay();
    init_Leds();
    init_Buttons();
    // Set Data for Relay
    set_Relay(ON);
    

    while (1) {
        if(isPressed_B(Btn0)){
            set_Led(Led0, ON);
        }else{
            set_Led(Led0, OFF);
        }
    }

    return 0;
}

void init_Leds() {
    DDRC |= (1 << Led0) | (1 << Led1);
    DDRD |= (1 << Led2);
}

void init_Relay() {
    DDRA |= (1 << Relay); // PINA 2 OUTPUT (Relay)
}

void init_Buzzer() {
    DDRA |= (1 << Buzzer); // PINA 3 OUTPUT (Buzzer)
}

void set_Relay(int state) {
    if (state) {
        PORTA |= (1 << Relay); // Relay ON
    } else {
        PORTA &= ~(1 << Relay); // Relay OFF
    }
}

void set_Led(int LedNumber, int state) {


    if (state) {
        switch (LedNumber) {
            case Led0:
                PORTC |= (1 << Led0);
                break;
            case Led1:
                PORTC |= (1 << Led1);
                break;
            case Led2:
                PORTD |= (1 << Led2);
                break;
        }
    } else {
        switch (LedNumber) {
            case Led0:
                PORTC &= ~(1 << Led0);
                break;
            case Led1:
                PORTC &= ~(1 << Led1);
                break;
            case Led2:
                PORTD &= ~(1 << Led2);
                break;
        }
    }




}


void init_Buttons(){
    
    DDRB &= ~(1<<Btn0);
    DDRD &= ~(1<<Btn1);
    DDRD &= ~(1<<Btn2);

}

int isPressed_B(int pinNum){
    if(PINB & (1<<pinNum)){
        return 1;
    }
    else{
        return 0;
    }
}