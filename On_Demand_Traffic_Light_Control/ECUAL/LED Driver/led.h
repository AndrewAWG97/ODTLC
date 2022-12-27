#ifndef LED_H_
#define LED_H_

#include "MCAL/DIO Driver/dio.h"
#include "MCAL/Timer0/timer.h"
#include <util/delay.h>

typedef enum {
	OFF, ON
} LED_status;

void LED_init(uint8 LED_number, DIO_Port LED_port);
LED_status LED_on(uint8 LED_number, DIO_Port LED_port);
LED_status LED_off(uint8 LED_number, DIO_Port LED_port);
void LED_toggle(uint8 LED_number, DIO_Port LED_port);
void LED_port_off(DIO_Port);

#endif
