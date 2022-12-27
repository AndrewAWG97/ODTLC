#include "MCAL/DIO Driver/dio.h"

/******************************************************************************
 * Name         : DIO_init                                                    *
 * Inputs       : Pin number, Port Number, direction                          *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : initialize the DIO pin in the selected port                 *
 *                with suitable direction input or output                     *
 ******************************************************************************/
void DIO_init(uint8 pinNumber, DIO_Port portNumber, DIO_PinDirectionType direction){
	switch(portNumber){
	case PORT_A:
		if(output == direction){
			SET_BIT(DDRA, pinNumber);
		}else if(input == direction){
			CLEAR_BIT(DDRA, pinNumber);
		}
		break;
	case PORT_B:
		if(output == direction){
			SET_BIT(DDRB, pinNumber);
		}else if(input == direction){
			CLEAR_BIT(DDRB, pinNumber);
		}
		break;
	case PORT_C:
		if(output == direction){
			SET_BIT(DDRC, pinNumber);
		}else if(input == direction){
			CLEAR_BIT(DDRC, pinNumber);
		}
		break;
	case PORT_D:
		if(output == direction){
			SET_BIT(DDRD, pinNumber);
		}else if(input == direction){
			CLEAR_BIT(DDRD, pinNumber);
		}
		break;
	}
}

/******************************************************************************
 * Name         : DIO_write                                                   *
 * Inputs       : Pin number, Port Number , status                                   *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Write on pin high or low                                    *
 ******************************************************************************/

void DIO_write(uint8 pinNumber, DIO_Port portNumber, uint8 status){
	switch(portNumber){
	case PORT_A:
		if(HIGH == status){
			SET_BIT(PORTA, pinNumber);
		}else if(LOW == status){
			CLEAR_BIT(PORTA, pinNumber);
		}
		break;
	case PORT_B:
		if(HIGH == status){
			SET_BIT(PORTB, pinNumber);
		}else if(LOW == status){
			CLEAR_BIT(PORTB, pinNumber);
		}
		break;
	case PORT_C:
		if(HIGH == status){
			SET_BIT(PORTC, pinNumber);
		}else if(LOW == status){
			CLEAR_BIT(PORTC, pinNumber);
		}
		break;
	case PORT_D:
		if(HIGH == status){
			SET_BIT(PORTD, pinNumber);
		}else if(LOW == status){
			CLEAR_BIT(PORTD, pinNumber);
		}
		break;
	}
}

/******************************************************************************
 * Name         : DIO_toggle                                                  *
 * Inputs       : Pin number, Port Number                                     *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : toggle the pin                                              *
 ******************************************************************************/
void DIO_toggle(uint8 pinNumber, DIO_Port portNumber){
	switch(portNumber){
	case PORT_A:
		TOGGLE_BIT(PORTA, pinNumber);
		break;
	case PORT_B:
		TOGGLE_BIT(PORTB, pinNumber);
		break;
	case PORT_C:
		TOGGLE_BIT(PORTC, pinNumber);
		break;
	case PORT_D:
		TOGGLE_BIT(PORTD, pinNumber);
		break;
	}

}
/******************************************************************************
 * Name         : DIO_toggle                                                  *
 * Inputs       : Pin number, Port Number , pointer to uint8                  *
 *                to put the reading state in it                              *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : read pin state                                              *
 ******************************************************************************/
void DIO_read(uint8 pinNumber, DIO_Port portNumber, uint8 *state){
	switch(portNumber){
	case PORT_A:
		if(BIT_IS_SET(PINA, pinNumber)){
			*state = HIGH;
		}else{
			*state = LOW;
		}
		break;
	case PORT_B:
		if(BIT_IS_SET(PINB, pinNumber)){
			*state = HIGH;
		}else{
			*state = LOW;
		}
		break;
	case PORT_C:
		if(BIT_IS_SET(PINC, pinNumber)){
			*state = HIGH;
		}else{
			*state = LOW;
		}
		break;
	case PORT_D:
		if(BIT_IS_SET(PIND, pinNumber)){
			*state = HIGH;
		}else{
			*state = LOW;
		}
		break;
	}
}

/******************************************************************************
 * Name         : DIO_Port_write                                              *
 * Inputs       : port number , value : high or low                           *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : write on the entire port                                    *
 ******************************************************************************/
void DIO_Port_write(DIO_Port portNumber, uint8 value){
	switch(portNumber){
	case PORT_A:
		if(value == HIGH){
			PORTA = 0xFF;
		}else{
			PORTA = 0x00;
		}

		break;
	case PORT_B:
		if(value == HIGH){
			PORTB = 0xFF;
		}else{
			PORTB = 0x00;
		}
		break;
	case PORT_C:
		if(value == HIGH){
			PORTC = 0xFF;
		}else{
			PORTC = 0x00;
		}
		break;
	case PORT_D:
		if(value == HIGH){
			PORTD = 0xFF;
		}else{
			PORTD = 0x00;
		}
		break;
	}
}

