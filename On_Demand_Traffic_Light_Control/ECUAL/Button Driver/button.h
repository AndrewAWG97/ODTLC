#ifndef BUTTON_H_
#define BUTTON_H_

#include "MCAL/DIO Driver/dio.h"
#include "MCAL/Interrupts/interrupt.h"

void BUTTON_init(uint8 buttonPin, DIO_Port buttonPort);
void BUTTON_getStatus(uint8 buttonPin, DIO_Port buttonPort, uint8* status);
void BUTTON_InterruptInit(void);

#endif
