#include <avr/io.h>
#include "config.h"

void init_Leds() {
    // Define  Data Direction as OUTPUT for each pin connected to LED
    DDRC |= (1 << Led0) | (1 << Led1);
    DDRD |= (1 << Led2);
}

void init_Relay() {
    // Define as OUTPUT
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
void set_Buzzer(int state) {
    if (state) {
        PORTA |= (1 << Buzzer); // Relay ON
    } else {
        PORTA &= ~(1 << Buzzer); // Relay OFF
    }
}

void set_Led(int LedNumber, int state) {


    if (state) {
        switch (LedNumber) {
            case Led0:
                PORTC |= (1 << Led0); // LED 0  >> ON
                break;
            case Led1:
                PORTC |= (1 << Led1);
                break;
            case Led2:
                //PORTD |= (1 << Led2);
                setPinData(_PD, Led2, ON);
                break;
        }
    } else {
        switch (LedNumber) {
            case Led0:
                PORTC &= ~(1 << Led0); // LED 0 >> OFF
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

void init_Buttons() {
    // Define PINs connected to BUTTONS as INPUT
    //    DDRB &= ~(1 << Btn0);
    //    DDRD &= ~(1 << Btn1);
    //    DDRD &= ~(1 << Btn2);

    setPinDir(_PB, Btn0, IN);
    setPinDir(_PD, Btn1, IN);
    setPinDir(_PD, Btn2, IN);
}

int isPressed_B(int pinNum) {
    if (PINB & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressed(int portNum, int pinNum) {

    switch (portNum) {
        case _PA:
            return (PINA & (1 << pinNum)) ? 1 : 0;
            break;
        case _PB:
            return (PINB & (1 << pinNum)) ? 1 : 0;
            break;
        case _PC:
            return (PINC & (1 << pinNum)) ? 1 : 0;
            break;
        case _PD:
            return (PIND & (1 << pinNum)) ? 1 : 0;
            break;
        default:
            return 0;
    }
}

/**
 * void setPortDir(int portNum, int state){
    switch(portNum){
            case _PA:
                DDRA = state? 0xFF: 0x00;
                break;
            case _PB:
                DDRB = state? 0xFF: 0x00;
                break;
            case _PC:
                DDRC = state? 0xFF: 0x00;
                break;
            case _PD:
                DDRD = state? 0xFF: 0x00;
                break;
            default:
                ;
                
        }
}

 * @param portNum
 * @param state
 */

void setPortDir(int portNum, int state) {
    if (state) {
        // PORT OUTPUT
        switch (portNum) {
            case _PA:
                DDRA = 0xFF;
                break;
            case _PB:
                DDRB = 0xFF;
                break;
            case _PC:
                DDRC = 0xFF;
                break;
            case _PD:
                DDRD = 0xFF;
                break;
            default:
                ;

        }
    } else {
        // PORT INPUT
        switch (portNum) {
            case _PA:
                DDRA = 0x00;
                break;
            case _PB:
                DDRB = 0x00;
                break;
            case _PC:
                DDRC = 0x00;
                break;
            case _PD:
                DDRD = 0x00;
                break;
            default:
                ;

        }
    }
}

void setPortData(int portNum, int data) {
    switch (portNum) {
        case _PA:
            PORTA = data;
            break;
        case _PB:
            PORTB = data;
            break;
        case _PC:
            PORTC = data;
            break;
        case _PD:
            PORTD = data;
            break;
        default:
            ;

    }
}

void togglePortData(int portNum) {


    switch (portNum) {
        case _PA:
            PORTA ^= 0xFF;
            break;
        case _PB:
            PORTB ^= 0xFF;
            break;
        case _PC:
            PORTC ^= 0xFF;
            break;
        case _PD:
            PORTD ^= 0xFF;
            break;
        default:
            ;

    }
}

void setPinDir(int portNum, int pinNum, int state) {
    if (state) {
        // PORT OUTPUT
        switch (portNum) {
            case _PA:
                DDRA |= (1 << pinNum);
                break;
            case _PB:
                DDRB |= (1 << pinNum);
                break;
            case _PC:
                DDRC |= (1 << pinNum);
                break;
            case _PD:
                DDRD |= (1 << pinNum);
                break;
            default:
                ;

        }
    } else {
        // PORT INPUT
        switch (portNum) {
            case _PA:
                DDRA &= ~(1 << pinNum);
                break;
            case _PB:
                DDRB &= ~(1 << pinNum);
                break;
            case _PC:
                DDRC &= ~(1 << pinNum);
                break;
            case _PD:
                DDRD &= ~(1 << pinNum);
                break;
            default:
                ;

        }
    }
}

void setPinData(int portNum, int pinNum, int data) {
    if (data) {
        switch (portNum) {
            case _PA:
                PORTA |= (1 << pinNum);
                break;
            case _PB:
                PORTB |= (1 << pinNum);
                break;
            case _PC:
                PORTC |= (1 << pinNum);
                break;
            case _PD:
                PORTD |= (1 << pinNum);
                break;
            default:
                ;

        }
    } else {
        switch (portNum) {
            case _PA:
                PORTA &= ~(1 << pinNum);
                break;
            case _PB:
                PORTB &= ~(1 << pinNum);
                break;
            case _PC:
                PORTC &= ~(1 << pinNum);
                break;
            case _PD:
                PORTD &= ~(1 << pinNum);
                break;
            default:
                ;

        }
    }
}

void togglePinData(int portNum, int pinNum) {
    switch (portNum) {
        case _PA:
            PORTA ^= (1 << pinNum);
            break;
        case _PB:
            PORTB ^= (1 << pinNum);
            break;
        case _PC:
            PORTC ^= (1 << pinNum);
            break;
        case _PD:
            PORTD ^= (1 << pinNum);
            break;
        default:
            ;

    }

}