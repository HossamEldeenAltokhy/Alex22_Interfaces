#include "config.h"
#include <avr/io.h>
#include "mMotor.h"

void init_Motor(int Motor_No) {

    if (Motor_No) {
        setPinDir(_PC, H_A3, OUT);
        setPinDir(_PC, H_A4, OUT);
        setPinDir(_PD, H_EN2, OUT);
        // Enable
        setPinData(_PD, H_EN2, ON);
    } else {
        setPinDir(_PC, H_A1, OUT);
        setPinDir(_PC, H_A2, OUT);
        setPinDir(_PD, H_EN1, OUT);
        // Enable
        setPinData(_PD, H_EN1, ON);
    }


}

void Motor_Forward(int Motor_No) {

    if (Motor_No) {
        setPinData(_PC, H_A3, ON);
        setPinData(_PC, H_A4, OFF);
    } else {
        setPinData(_PC, H_A1, ON);
        setPinData(_PC, H_A2, OFF);
    }

}

void Motor_Reverse(int Motor_No) {
 if (Motor_No) {
        setPinData(_PC, H_A3, OFF);
        setPinData(_PC, H_A4, ON);
    } else {
        setPinData(_PC, H_A1, OFF);
        setPinData(_PC, H_A2, ON);
    }
}


void Motor_Stop(int Motor_No){
     if (Motor_No) {
        setPinData(_PC, H_A3, OFF);
        setPinData(_PC, H_A4, OFF);
        setPinData(_PD, H_EN2, OFF);
    } else {
        setPinData(_PC, H_A1, OFF);
        setPinData(_PC, H_A2, OFF);
        setPinData(_PD, H_EN1, OFF);
    }
}
