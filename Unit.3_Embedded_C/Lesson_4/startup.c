

// startup.c 
// Eng.Amir

#include<stdint.h>

void  Reset_Handler();
extern int main(void);
void Default_Handler()
{
	Reset_Handler();
}
void  NMI_Handler()__attribute__((weak,alias("Default_Handler")));;
void  H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;

//booking 1024 B located by .bss through uninitialized array of int 256 Elements (256*4 = 1024)
static unsigned long Stack_top[256] ;

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) =
{
	(void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top)), //&Stack_top[0] == Stack_top
	(void(*)())	&Reset_Handler,
	(void(*)())	&NMI_Handler,
	(void(*)()) &H_Fault_Handler
};


extern unsigned int _E_text ;
extern unsigned int _S_data ;
extern unsigned int _E_data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
void Reset_Handler(void)
{
	int i;
	// copy .data from flash(ROM) into sram(RAM)
	unsigned char data_size = (unsigned char*)&_E_data  - (unsigned char*)&_S_data ;
	unsigned char* p_src = (unsigned char*)&_E_text ;
	unsigned char* p_dst = (unsigned char*)&_S_data ;
	for(i = 0; i < data_size; i++)
	{
		*((unsigned char*)p_dst++) = *((unsigned char*)p_src++);
	}
	// init .bss with zero in sram
	unsigned char bss_size = (unsigned char*)&_E_bss  - (unsigned char*)&_S_bss ;	
	p_dst = (unsigned char*)&_S_bss ;
	for(i = 0; i < bss_size; i++)
	{
		*((unsigned char*)p_dst++) = (unsigned char)0 ;
	}
	// jump to main function
	main();
}