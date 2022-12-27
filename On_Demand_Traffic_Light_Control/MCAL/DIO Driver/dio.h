#ifndef DIO_H_
#define DIO_H_

#include "Utilities/std_types.h"
#include "Utilities/common_macros.h"
#include "Utilities/register.h"



typedef enum{
	input, output
} DIO_PinDirectionType;

typedef enum{
	PORT_A, PORT_B, PORT_C, PORT_D
} DIO_Port;

enum {
	LOW, HIGH
};

enum {
	PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7
};

void DIO_init(uint8 pinNumber, DIO_Port portNumber, DIO_PinDirectionType direction);

void DIO_write(uint8 pinNumber, DIO_Port portNumber, uint8 value);

void DIO_toggle(uint8 pinNumber, DIO_Port portNumber);

void DIO_read(uint8 pinNumber, DIO_Port portNumber, uint8 *state);

void DIO_Port_write(DIO_Port portNumber, uint8 value);

#endif
