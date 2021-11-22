//LAB4
//Eng:Amr
#include<stdio.h>
#include<stdint.h>


/*MACROS OF USED REGISTERS*/
#define SYSCTL_RCGC2_R    (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R  (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))

int main()
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x20; 
	//delay to make sure that GPIOf up and running
	for(delay_count = 0; delay_count < 200; delay_count++);
	GPIO_PORTF_DIR_R |= 1<<3; // PORTF PIN3 direction > OUTPUT
 	GPIO_PORTF_DEN_R |= 1<<3; // PORTF PIN3 > Enable

// Toggling LED
 	while(1)
 	{
 		GPIO_PORTF_DATA_R |= 1<<3;
 		for(delay_count = 0; delay_count < 200000; delay_count++);
 		GPIO_PORTF_DATA_R &= ~(1<<3);
 		for(delay_count = 0; delay_count < 200000; delay_count++);
 	}
	return 0;
}