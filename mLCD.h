/* 
 * File:   mLCD.h
 * Author: hossa
 *
 * Created on October 1, 2021, 6:15 PM
 */

#ifndef MLCD_H
#define	MLCD_H


// HW connection Configurations
#define LCD_data        _PD
#define LCD_data_Dir    _PD

#define LCD_control     _PC
#define LCD_control_Dir _PC

#define RS              PC0
#define RW              PC1
#define EN              PC2
/////////////////////////////////


void init_LCD();

void LCD_write(char data);
void LCD_write_str(char* str);
void LCD_write_num(int num);
void LCD_cmd(char cmd);
void LCD_enable();
void LCD_clear();
void LCD_goto(int row, int column);



#endif	/* MLCD_H */

