/* 
 * File:   mLCD_4bit.h
 * Author: hossa
 *
 * Created on October 8, 2021, 2:31 PM
 */

#ifndef MLCD_4BIT_H
#define	MLCD_4BIT_H


// HW connection Configurations

#define LCD_Half_Data   PORTA
#define LCD_Half_Dir    DDRA

#define LCD_data        _PA
#define LCD_data_Dir    _PA

#define LCD_control     _PB
#define LCD_control_Dir _PB

#define RS              PB1
#define RW              PB2
#define EN              PB3
/////////////////////////////////
// Command List
#define _4bit_mode    0x28  // _4bit_mode
#define _D_ON_C_OFF   0x0C  // _Display_ON_Cursor_OFF
#define _Entry_mode   0x06  // Entry Mode _ Increment Cursor
#define _Return_Home  0x02  // Return Home


/////////////////
void init_LCD_4bit();

void LCD_write_4bit(char data);
void LCD_write_str_4bit(char* str);
void LCD_write_num_4bit(int num);
void LCD_cmd_4bit(char cmd);
void LCD_enable_4bit();
void LCD_clear_4bit();
void LCD_goto_4bit(int row, int column);



#endif	/* MLCD_4BIT_H */

