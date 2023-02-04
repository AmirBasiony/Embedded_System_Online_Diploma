


#define SYSCTL_RCGC2_R (*(volatile unsigned long *)(0x400FE000+0x108))
#define GPIO_PORTF_DIR_R (*(volatile unsigned long *)(0x40025000+0x400))
#define GPIO_PORTF_DEN_R (*(volatile unsigned long *)(0x40025000+0x51c))
#define GPIO_PORTF_DATA_R (*(volatile unsigned long *)(0x40025000+0x3FC))

#define SET(BYTE,PIN_NO)   BYTE |=(1<<PIN_NO)
#define CLR(BYTE,PIN_NO)   BYTE &= ~(1<<PIN_NO)

int main()
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x20;
	//dealay to make sure GPiof is up and running
	for(delay_count = 0 ; delay_count < 200 ; delay_count++);
	
	SET(GPIO_PORTF_DIR_R,3); // Dir is Output for pin 3 in port F
	SET(GPIO_PORTF_DEN_R,3);
	
	while(1)
	{
		SET(GPIO_PORTF_DATA_R,3);
		for(delay_count = 0 ; delay_count < 200000 ; delay_count++);
		CLR(GPIO_PORTF_DATA_R,3);
		for(delay_count = 0 ; delay_count < 200000 ; delay_count++);
	}
	
	return 0;
}

