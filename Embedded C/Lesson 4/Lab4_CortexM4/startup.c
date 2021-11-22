//startup.c
//Eng. Amr

#include<stdint.h>
void Reset_Handler();
void Default_Handler();

extern int main(void);

void NMI_Handler() __attribute__ ((weak, alias("Default_Handler")));; 
void H_fault_Handler()__attribute__((weak, alias("Default_Handler")));;

//Booking (1024 Byte) located by .bss using uninitialized array(256 int elements)
static unsigned long Stack_top[256];

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = 
{
	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler  
};

extern uint32_t _E_text ;
extern uint32_t _S_DATA ;
extern uint32_t _E_DATA ;
extern uint32_t _S_bss ;
extern uint32_t _E_bss ;
void Reset_Handler()
{
	// copy data section from Flash -> Ram
	uint32_t DATA_size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
	uint8_t* P_scr = (uint8_t*)&_E_text;  //source
	uint8_t* P_dst = (uint8_t*)&_S_DATA;  //destination
	for (int i = 0; i < DATA_size ; i++)
	{
		*((uint8_t*)P_dst++) = *((uint8_t*)P_scr++); 
	}

	 //init .bss section in SRAM = 0
	uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
	P_dst = (uint8_t*)&_S_bss;  //destination
	for (int i = 0; i < bss_size ; i++)
	{
		*((uint8_t*)P_scr++) = (uint8_t)0; 
	}
	//jump main()   



	main();
}
void Default_Handler()
{
	Reset_Handler();
}