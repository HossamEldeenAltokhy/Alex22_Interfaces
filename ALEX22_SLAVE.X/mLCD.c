#include "config.h"
#include <avr/io.h>
#include "mLCD.h"
#include <stdlib.h>

void init_LCD() {
    // Configure IO AVR
    setPortDir(LCD_data_Dir, OUT);
    setPinDir(LCD_control_Dir, RS, OUT);
    setPinDir(LCD_control_Dir, RW, OUT);
    setPinDir(LCD_control_Dir, EN, OUT);
    ////////////////////////////////////
    setPinData(LCD_control, RW, OFF);
    ////////////////////////////////////
    // Configuration LCD 
    _delay_ms(10);
    LCD_clear();
    
    LCD_cmd(_8bit_mode); 
    _delay_ms(10);
    LCD_cmd(_D_ON_C_OFF); 
    _delay_ms(10);
    LCD_cmd(_Entry_mode); 
    _delay_ms(10);
    LCD_cmd(_Return_Home); 

    _delay_ms(50);


}

void LCD_write(char data) {
    // Select Data Register
    setPinData(LCD_control, RS, ON);
    // set Data
    setPortData(LCD_data, data);
    // send Trigger
    LCD_enable();

}

void LCD_cmd(char cmd) {
    // Select Command Register
    setPinData(LCD_control, RS, OFF);
    // set Command
    setPortData(LCD_data, cmd);
    // send Trigger
    LCD_enable();
}

void LCD_enable() {
    setPinData(LCD_control, EN, ON);
    _delay_ms(1);
    setPinData(LCD_control, EN, OFF);
}

void LCD_clear() {
    LCD_cmd(0x01);
    _delay_ms(1);
}


void LCD_write_str(char* str){
    for(int i = 0; str[i]!= '\0'; i++){
        LCD_write(str[i]);
    }
}


void LCD_write_num(int num){
    char buffer[11];
    itoa(num, buffer, 10);
    LCD_write_str(buffer);
}