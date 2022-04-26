/*
 * LCD.h
 *
 * Created: 16/03/2022 21:43:03
 *  Author: AMR AHMED
 */ 


#ifndef LCD_H_
#define LCD_H_
//#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>

//REGISTERS AND PORT SELECTION 
#define LCD_PORT		 PORTD            //PORT Data Register
#define DataDir_LCD_PORT DDRD			  //PORT DATA DIRECTION
#define LCD_CRTL		 PORTB            //PORT Data Register
#define DataDir_LCD_CRTL DDRB			  //PORT DATA DIRECTION
 
#define RS_SWITCH		1   			  //REGISTER SELECT SIGNAL
#define RW_SWITCH       2				  //READ/WRITE SELECT SIGNAL
#define ENABLE_SWITCH   3				  //ENABLE SIGNAL
#define Data_SHIFT      0				  //SHIFT DATA BY 4 IN 4BIT MODE

//LCD MODES
#define EIGHT_BIT_MODE           
//#define FOUR_BIT_MODE              

//LCD COMMANDS
#define LCD_FUNCTION_8BIT_2LINES   (0X38)
#define LCD_FUNCTION_4BIT_2LINES   (0X28)
#define LCD_MOVE_DISP_RIGHT        (0X1C)
#define LCD_MOVE_DISP_LEFT         (0X18)
#define LCD_MOVE_CURSOR_RIGHT      (0X14)
#define LCD_MOVE_CURSOR_LEFT       (0X10)
#define LCD_DISP_OFF               (0X08)
#define LCD_DISP_ON_CURSOR         (0X0E)
#define LCD_DISP_ON_CURSOR_BLINK   (0X0F)
#define LCD_DISP_ON_BLINK          (0X0D)
#define LCD_DISP_ON                (0X0C)
#define LCD_ENTRY_DEC              (0X04)
#define LCD_ENTRY_DEC_SHIFT        (0X05)
#define LCD_ENTRY_INC              (0X06)
#define LCD_ENTRY_INC_SHIFT        (0X07)
#define LCD_BEGIN_AT_FIRST_ROW     (0X80)
#define LCD_BEGIN_AT_SECONDT_ROW   (0XC0)
#define LCD_CLEAR_SCREEN           (0X01)
#define LCD_ENTRY_MODE             (0X06)

//APIs
void LCD_INIT(void);									//LCD initialization 
void LCD_KICK(void);
void LCD_WRITE_COMMAND(uint8_t command);				//send a command to LCD
void LCD_WRITE_CHAR   (uint8_t data);					//send a character to LCD
void LCD_WRITE_STRING (uint8_t* data);					//send a complete string to LCD
void LCD_WRITE_INTEGER_Number(uint32_t INTEGER_Number);
void LCD_isBusy(void);									//Check if LCD is busy
void LCD_clear_screen(void);							//clear LCD screen
void LCD_GOTO_XY(uint8_t line, uint8_t position);		//shifting between 1st and 2nd line in LCD
void LCD_CUSTOM_CHARACTER(void);						//send a CUSTOM char to LCD

#endif /* LCD_H_ */