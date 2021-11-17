#include "uart.h"
unsigned char string_buffer[100] = "Amr Ahmed";
unsigned char string_buffer1[100] = "Amr Ahmed";
void main(void)
{
	Uart_Send_String (string_buffer);
}