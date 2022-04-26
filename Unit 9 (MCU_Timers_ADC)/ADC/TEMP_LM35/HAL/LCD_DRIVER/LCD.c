/*
 * LCD.c
 *
 * Created: 16/03/2022 21:43:19
 *  Author: AMR AHMED
 */ 

#include "LCD.h"

void LCD_KICK() 
{
	LCD_CRTL &= ~(1 << ENABLE_SWITCH);    //Set Enable
	_delay_ms(50);
	LCD_CRTL |=  (1 << ENABLE_SWITCH);
}

void LCD_GOTO_XY(uint8_t line, uint8_t position)
  {
	if(line == 1)
	{
		if (position < 16 && position >= 0)
			{
				LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);  //Move cursor to 1st row + position 
			}
	}
	else if(line == 2)
	{
		 if (position < 16 && position >= 0)
			{
			    LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECONDT_ROW + position); //Move cursor to 2nd row + position
			}	
	 } 
  }

void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_isBusy()
{
	DataDir_LCD_PORT = 0x00;                     //set port as Input //8BIT
	//DataDir_LCD_PORT &= ~(0xFF << Data_SHIFT); //set port as Input
	LCD_CRTL |=  (1 << RW_SWITCH);               //Put LCD in "Read Mode" = (RW -> ON)
	LCD_CRTL &= ~(1 << RS_SWITCH);               //Put LCD in "Command Mode" = (RS -> OFF)
    LCD_KICK();
	DataDir_LCD_PORT = 0xFF;                     //reset port 
	LCD_CRTL &= ~(1 << RW_SWITCH);               //Reset LCD from "Command Mode" = (RS -> ON)
}

void LCD_INIT(){
	 _delay_ms(20);
	 LCD_isBusy();
	 /*To control LCD's cursor or display function (Send COMMAND to LCD)*/
	 DataDir_LCD_CRTL |= ((1 << ENABLE_SWITCH) | (1 << RW_SWITCH) | (1 << RS_SWITCH)); //set PORT Dir as OUTPUT, Turn off RW to write, Turn ON for COMMAND Mode
	 LCD_CRTL &= ~((1 << ENABLE_SWITCH) | (1 << RW_SWITCH) | (1 << RS_SWITCH));        //Clear control
	 DataDir_LCD_PORT = 0xFF;						                                   //Set Data PORT as output
	 _delay_ms(15);							
	 LCD_clear_screen();
	 
	 //------To Enable 8BIT Mode------
	 #ifdef EIGHT_BIT_MODE   
		LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
     #endif
	 
	 //------To Enable 4BIT Mode------
	 #ifdef FOUR_BIT_MODE   
		LCD_WRITE_COMMAND(0x02);                          //set interface to be 4 bits long (DB4 > DB7)
		LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	 #endif
	
	 LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	 LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	 //LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	 LCD_WRITE_COMMAND(LCD_DISP_ON); 
 }
 
void LCD_WRITE_COMMAND(uint8_t command)
{
	LCD_isBusy();
	//------To Enable 8BIT Mode------
	#ifdef EIGHT_BIT_MODE
		LCD_PORT = command;                                 //set command on PORT
		LCD_CRTL &= ~((1 << RW_SWITCH) | (1 << RS_SWITCH)); //Turn RW(to write) ,and RS off(Command mode)
		//_delay_ms(1);
		LCD_KICK();
    #endif
	
	//------To Enable 4BIT Mode------
	#ifdef FOUR_BIT_MODE
	//First part from command
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);       // PORT >> 4 Most Bit, command >> 1st 4 Bits from command
	LCD_CRTL &= ~((1 << RW_SWITCH) | (1 << RS_SWITCH));    //Turn RW(to write) ,and RS off(Command mode)
	//_delay_ms(10);
	LCD_KICK();
	//Second part from command
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);         // PORT >> 4 least Bit,  command >> 2nd 4 Bits from command
	LCD_CRTL &= ~((1 << RW_SWITCH) | (1 << RS_SWITCH));    //Turn RW(to write) ,and RS off(Command mode)
	//_delay_ms(10);
	LCD_KICK();
    #endif
}

void LCD_WRITE_CHAR (uint8_t data)
{
	LCD_isBusy();
	//------To Enable 8BIT Mode------
	#ifdef EIGHT_BIT_MODE
	LCD_CRTL &= ~(1 << RW_SWITCH);   //Clear RW(to read)
	LCD_CRTL |=  (1 << RS_SWITCH);   //RS ON(Data mode)
	LCD_PORT = data;                 //set data on PORT
	LCD_KICK();
	#endif
	
	//------To Enable 4BIT Mode------
	#ifdef FOUR_BIT_MODE
	//First part from command
	LCD_PORT = ((LCD_PORT & 0x0F) | (data & 0xF0)); //PORT >> 4 Most Bit, command >> 1st 4 Bits from command
	LCD_CRTL |=  (1 << RS_SWITCH);				    //RS ON(Data mode)
	LCD_CRTL &= ~(1 << RW_SWITCH);				    //Clear RW(to read)
	//_delay_ms(10);
	LCD_KICK();
	//Second part from command
	LCD_PORT = ((LCD_PORT & 0x0F) | (data << 4));  //PORT >> 4 Most Bit, command >> 1st 4 Bits from command
	LCD_CRTL |=  (1 << RS_SWITCH);                 //RS ON(Data mode)
	LCD_CRTL &= ~(1 << RW_SWITCH);		           //Clear RW(to read)
	//_delay_ms(10);  
	LCD_KICK();
	#endif
}

void LCD_WRITE_STRING (uint8_t* data)
{
	//each Line has 16 characters 
	int count = 0;
	
	while(*data > 0)
	{
		count++;
		LCD_WRITE_CHAR(*data++);
		//_delay_ms(2000);
		
		if (count == 16)            //check if cursor at 1st line or not
		{
			LCD_GOTO_XY(2, 0);      //start from the beginning of second line
		} 
		else if (count == 32)       //Check if cursor arrives End of 2nd Line
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);       //go to cursor at 1st line position 1
			count = 0;
		}
	}
}

void LCD_CUSTOM_CHARACTER()
{
	LCD_WRITE_COMMAND(64);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_CHAR(0);        //print 1st char
	_delay_ms(10);
}

void LCD_WRITE_INTEGER_Number(uint32_t INTEGER_Number)
{
	uint8_t str[7];
	
	sprintf(str,"%ld",INTEGER_Number);     // Adjust the formatting to your liking
	LCD_WRITE_STRING((uint8_t*)str);
}