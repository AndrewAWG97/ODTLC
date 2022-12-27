#include "ECUAL/LED Driver/led.h"


/******************************************************************************
 * Name         : LED_init                                                    *
 * Inputs       : LED number & LED port                                       *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : initialize the LED pin in the selected port                 *
 ******************************************************************************/
void LED_init(uint8 LED_number, DIO_Port LED_port){
	DIO_init(LED_number, LED_port, output);
}

/******************************************************************************
 * Name         : LED_on                                                      *
 * Inputs       : LED number & LED port                                       *
 * Outputs      : None                                                        *
 * Return Value : LED state                                                   *
 * Description  : Turn on the LED                                             *
 ******************************************************************************/
LED_status LED_on(uint8 LED_number, DIO_Port LED_port){
	DIO_write(LED_number, LED_port, HIGH);
	return ON;
}

/******************************************************************************
 * Name         : LED_off                                                     *
 * Inputs       : LED number & LED port                                       *
 * Outputs      : None                                                        *
 * Return Value : LED state                                                   *
 * Description  : Turn off the LED                                            *
 ******************************************************************************/
LED_status LED_off(uint8 LED_number, DIO_Port LED_port){
	DIO_write(LED_number, LED_port, LOW);
	return OFF;
}

/******************************************************************************
 * Name         : LED_toggle                                                  *
 * Inputs       : LED number & LED port                                       *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : toggle the LED                                              *
 ******************************************************************************/
void LED_toggle(uint8 LED_number, DIO_Port LED_port){
	DIO_toggle(LED_number, LED_port);
}


/******************************************************************************
 * Name         : LED_port_off                                                *
 * Inputs       : LED port                                                    *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Turn off the whole port                                     *
 ******************************************************************************/

void LED_port_off(DIO_Port LED_port){
	DIO_Port_write(LED_port, LOW);
}
