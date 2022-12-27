#include "MCAL/Timer0/timer.h"


/******************************************************************************
 * Name         : delay_ms                                                    *
 * Inputs       : delay in ms                                                 *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Make delays                                                 *
 ******************************************************************************/

void delay_ms(uint16 T_delay){


	uint16  T_initValue = 0;
	uint16 Number_Overflow = 0;
	uint16 OverFlows_counter = 0;

	 /*Set CPU frequency & prescaler*/
	float32 Freq_CPU  = F_CPU;
	float32 Prescaler = PRESCALER;

	/* Calculate system tick*/
	float64 T_tick = Prescaler/Freq_CPU;

	 /*Calculate Timer maximum delay*/
	float64 T_MaxDelay = T_tick * 256 * 1000; //(1<<8) is 2 power n bits n = 8 and convert it to ms

	if(T_delay < T_MaxDelay){

		T_initValue = ((T_MaxDelay - T_delay)/(T_tick));
		Number_Overflow = 1;

	}else if(T_delay  == T_MaxDelay){
		T_initValue = 0;
		Number_Overflow = 1;


	}else{
		 /*Calculate number of overflows*/

		Number_Overflow = mceil((float64)T_delay, T_MaxDelay);
		T_initValue = 256 - ((double)T_delay/T_tick) / Number_Overflow;

	}

	TCNT0 = T_initValue;
	 /*Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/256 CS00=1 CS01=0 CS02=0*/
	SET_BIT(TCCR0, CS02);

	while(OverFlows_counter < Number_Overflow){
		/* Wait until the Timer0 Overflow occurs (wait until TOV0 = 1)*/
		while( READ_BIT(TIFR, TOV0) == 0 );

		/* Clear TOV0 bit by set its value*/
		SET_BIT(TIFR,0);

		OverFlows_counter++;
	}
	/* Stop Timer0 by clear the Clock bits (CS00, CS01 and CS02)*/
	TCCR0 = 0;
}

