#include "MCAL/Interrupts/interrupt.h"



/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	CLEAR_BIT(SREG, 7);                    // Disable interrupts by clearing I-bit
	CLEAR_BIT(DDRD, PD2);                  // Configure INT0/PD2 as input pin
	SET_BIT(GICR, INT0);                   // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);  	   // Trigger INT0 with the raising edge
	SET_BIT(SREG, 7);                      // Enable interrupts by setting I-bit
}
