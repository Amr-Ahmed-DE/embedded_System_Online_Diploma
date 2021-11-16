#include<stdio.h>
#include"platform_TypeDef.h"

/*Demo code toggling LED @ PORTA pin 13 STM32F103C6*/

//Register address
#define RCC_BASE    0x40021000                               //BASE ADDRESS OF RCC REGISTER
#define GPIOA_BASE  0x40010800                               //BASE ADDRESS OF PORTA REGISTER
#define RCC_APB2ENR *(vus_int32_t*)(RCC_BASE   + 0x18)       //ADDRESS OF ENABLE REGISTER OF PORTA
#define GPIOA_CHR   *(vus_int32_t*)(GPIOA_BASE + 0x04)       //ADDRESS OF CHR REGISTER OF PORTA
#define GPIOA_ODR   *(vus_int32_t*)(GPIOA_BASE + 0x0C)       //ADDRESS OF ODR REGISTER OF PORTA

typedef union{
	      vus_int32_t  ALL_fileds;                             //ALL_fileds : to access the whole register
	      struct{
					vus_int32_t  reserved:13;                          //don't need first 12 bits, so reserved
					vus_int32_t  p_13:1;                               //p_13: access bit no.13 
				      }pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C); //R_ODR is a pointer to the union R_ODR_t

int main(void)
{
	RCC_APB2ENR |= 1 << 2;                                          // Enable port A
	GPIOA_CHR   &= ~ (20<<15);                                      //clear bit 20>24
	GPIOA_CHR   |= 20 < 2;                                          //put 2 at bit 20>24

 while(1){
    R_ODR ->pin.p_13 = 1;                                         //set pin13 > 1
	  for(int i=0; i < 5000; i++);                                  //delay
	  R_ODR->pin.p_13 = 0;                                          //clear pin13 > 0
    for(int i=0; i < 5000; i++);	                                //delay
 }
return 0;
}
