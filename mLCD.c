#include "config.h"
#include <avr/io.h>
#include "mLCD.h"

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
    _delay_us(50);
    setPinData(LCD_control, EN, OFF);

}

void LCD_clear() {
    LCD_cmd(0x01);
}