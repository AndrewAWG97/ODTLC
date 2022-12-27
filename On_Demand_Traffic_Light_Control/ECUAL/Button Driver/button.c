#include "ECUAL/Button Driver/button.h"

/******************************************************************************
 * Name         : BUTTON_init                                                 *
 * Inputs       : Button pin & Button port                                    *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : initialize the Button pin in the selected port              *
 ******************************************************************************/
void BUTTON_init(uint8 buttonPin, DIO_Port buttonPort){
	DIO_init(buttonPin, buttonPort, input);
}


/******************************************************************************
 * Name         : BUTTON_getStatus                                            *
 * Inputs       : Button pin, Button port & pointer to status                 *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Get Button status                                           *
 ******************************************************************************/

void BUTTON_getStatus(uint8 buttonPin, DIO_Port buttonPort, uint8* status){
	DIO_read(buttonPin, buttonPort, status);
}


void BUTTON_InterruptInit(void){
	INT0_Init();
}
