#ifndef TIMER_H_
#define TIMER_H_

#include "Utilities/std_types.h"
#include "Utilities/common_macros.h"
#include "Utilities/register.h"



#define CS00    0
#define CS01    1
#define CS02    2
#define TOV0    0

#define PRESCALER  256


/* Macro for ceil */
#define mceil(a,b) (((a)+(b)-1)/(b))


void delay_ms(uint16 delay);


#endif
