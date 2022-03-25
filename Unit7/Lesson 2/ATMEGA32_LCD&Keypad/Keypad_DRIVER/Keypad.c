/*
 * Keypad.c
 *
 * Created: 17/03/2022 01:09:33
 *  Author: amrta
 */ 
#include "Keypad.h"

int Keypad_R[] = {R0, R1, R2, R3}; //Rows
int Keypad_C[] = {C0, C1, C2, C3}; //Columns
	 
void KEYPAD_INIT(){ 
	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) |(1 << R2) | (1 << R3));  //Set PINs 0, 1, 2, 3 as (ROWS) INPUT
	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) |(1 << C2) | (1 << C3));   //Set PINs 4, 5, 6, 7 as (COLUMNS) OUTPUT
	KEYPAD_PORT = 0xFF;                                                      //Set the whole PORT 1=(VCC)
}

char KEYPAD_GETCHAR(){
	int i, j;											  //i >> COLUMNS, j >> ROWS
	for (i = 0; i < 4; i++)								  //LOOP on COLUMNS
	{
		KEYPAD_PORT |= ((1 << Keypad_C[0]) |
						(1 << Keypad_C[1]) | 
						(1 << Keypad_C[2]) | 
						(1 << Keypad_C[3]));               //SET ALL COLUMNS TO VCC (LOGIC 1)
		KEYPAD_PORT &= ~(1 << Keypad_C[i]);                //SET 0 (low) to each ROW one by one 
		
		for (j = 0; j < 4; j++)							   //LOOP ON ROWS
		{
			if (!(KEYPAD_PIN & (1 << Keypad_R[j])))        //CHECK IF KEY PRESSED & WHICH KEY IN (ROWS)
			{
				while(!(KEYPAD_PIN & (1 << Keypad_R[j]))); //CHECK SINGLE PRESS
				//TABLE OF CONNECTION BETWEEN ROWS AND COLUMNS 
				switch(i){                                 //CHECK ON WHICH COLUMNS IS GROUNDED
					case 0:                                //1ST COLUMN 0 (GROUND)
					{
						if ( j == 0) return '7';
						else if( j == 1) return '4';
						else if( j == 2) return '1';
						else if( j == 3) return '?';
					}
						break;
				    case 1:							   //2ND COLUMN 0 (GROUND)
					{
					    if ( j == 0) return '8';
					    else if( j == 1) return '5';
						else if( j == 2) return '2';
						else if( j == 3) return '0';
					}
						break;
					case 2:							   //3RD COLUMN 0 (GROUND)
					{
						if ( j == 0) return '9';
						else if( j == 1) return '6';
					    else if( j == 2) return '3';
						else if( j == 3) return '=';
					}
						break;
					case 3:							   //4RTH COLUMN 0 (GROUND)
					{
						if ( j == 0) return '/';
						else if( j == 1) return '*';
						else if( j == 2) return '-';
						else if( j == 3) return '+';
					}
					    break;
			           }
		     }
	     }
	}
	return 'N';
}