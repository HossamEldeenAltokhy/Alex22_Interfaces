/* 
 * File:   mMotor.h
 * Author: hossa
 *
 * Created on October 2, 2021, 5:38 PM
 */

#ifndef MMOTOR_H
#define	MMOTOR_H

#define Motor1 0
#define Motor2 1

void init_Motor(int Motor_No);

void Motor_Forward(int Motor_No);
void Motor_Reverse(int Motor_No);


void Motor_Stop(int Motor_No);



#endif	/* MMOTOR_H */

