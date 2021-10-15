
#include "config.h"
#include <avr/io.h>
#include "mLCD_4bit.h"
#include <stdlib.h>



void init_LCD_4bit(){
    // AVR IO Configuration
    LCD_Half_Dir |= 0xF0;
    setPinDir(LCD_control_Dir, RS, OUT);
    setPinDir(LCD_control_Dir, RW, OUT);
    setPinDir(LCD_control_Dir, EN, OUT);
    ////////////////////////////////////
    setPinData(LCD_control, RW, OFF);
    ////////////////////////////////////
    // LCD Configuration
    LCD_clear_4bit();
   
    LCD_cmd_4bit(0x02);
    
    LCD_cmd_4bit(0x28);
    LCD_cmd_4bit(0x0C);
    LCD_cmd_4bit(0x06);
    LCD_clear_4bit();
   
    _delay_ms(50);
}

void LCD_write_4bit(char data){
    setPinData(LCD_control, RS, ON);
    LCD_Half_Data = (LCD_Half_Data & 0x0F)|(data & 0xF0);
    LCD_enable_4bit();
    _delay_ms(1);
    LCD_Half_Data = (LCD_Half_Data & 0x0F)|(data<<4);
    LCD_enable_4bit();
    _delay_ms(1);
}
void LCD_write_str_4bit(char* str){
      for(int i = 0; str[i]!= '\0'; i++){
        LCD_write_4bit(str[i]);
    }
}
void LCD_write_num_4bit(int num){
    char buffer[11];
    itoa(num, buffer, 10);
    LCD_write_str_4bit(buffer);
}
void LCD_cmd_4bit(char cmd){
    // xxxxyyyy
    // yyyy0000
    setPinData(LCD_control, RS, OFF);
    LCD_Half_Data = (LCD_Half_Data & 0x0F)|(cmd & 0xF0);
    LCD_enable_4bit();
    _delay_ms(50);
    LCD_Half_Data = (LCD_Half_Data & 0x0F)|(cmd<<4);
    LCD_enable_4bit();
    _delay_ms(50);
}
void LCD_enable_4bit(){
    setPinData(LCD_control, EN, ON);
    _delay_ms(1);
    setPinData(LCD_control, EN, OFF);
}
void LCD_clear_4bit(){
    LCD_cmd_4bit(0x01);
    _delay_ms(5);
}


void LCD_goto_4bit(int row, int column){
    switch(row){
        case _ROW0:
            LCD_cmd_4bit(0x80 | column);
            break;
        case _ROW1:
            LCD_cmd_4bit(0xC0 | column);
            break;       
    }
}