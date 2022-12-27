
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "Utilities/register.h"
#include "Utilities/common_macros.h"
#include "Utilities/std_types.h"


//Interrupt vectors
#define INT0_vect __vector_1

#define INT0 6
#define ISC00 0
#define ISC01 1
#define PD2   2


//ISR macro
#define ISR(INT_VECT) \
	void INT_VECT(void) __attribute__ ((signal,used)); \
	void INT_VECT(void)

void INT0_Init(void);


#endif
