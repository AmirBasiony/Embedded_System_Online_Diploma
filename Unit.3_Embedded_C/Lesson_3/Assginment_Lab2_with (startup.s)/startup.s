/* startup_cortexM3.s 
Eng. Amir
*/

/* SRAM 0x20000000  static RAM start in this address*/

/* according to vector_table handler */
   

.section .vectors
.word	0x20001000  /* stack top address For the stack pointer (sp) */
.word 	_reset  	/* 1 Reset */
.word 	Vector_handler  /* 2 NMI */
.word 	Vector_handler  /* 3 HARD FAULT */ 
.word 	Vector_handler  /* 4 MM FAULT */
.word 	Vector_handler  /* 5 Bus FAULT */ 
.word 	Vector_handler  /* 6 Usage FAULT */
.word 	Vector_handler  /* 7 RESERVED */ 
.word 	Vector_handler  /* 8 RESERVED */
.word 	Vector_handler  /* 9 RESERVED */ 
.word 	Vector_handler  /* 10 RESERVED */
.word 	Vector_handler  /* 11 SV call */ 
.word 	Vector_handler  /* 12 Debud reserved */
.word 	Vector_handler  /* 13 RESERVED */ 
.word 	Vector_handler  /* 14 pendSV */
.word 	Vector_handler  /* 15 SysTick */ 
.word 	Vector_handler  /* 16 IRQ0 */
.word 	Vector_handler  /* 17 IRQ1 */ 
.word 	Vector_handler  /* 18 IRQ2 */
.word 	Vector_handler  /* 19 ... */ 
			/* on to IRQ67 */

.section .text
_reset :
	bl main	/* branch on main function. */
	bl .    /* branch on the same address you in. */

.thumb_func	 /* enable switching between 16/32 bits instructions */
 
Vector_handler :
	b _reset