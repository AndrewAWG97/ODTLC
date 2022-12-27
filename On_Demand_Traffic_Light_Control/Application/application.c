#include "Application/application.h"

uint8 mode = NORMAL_MODE;

uint8 G_LED_CAR = OFF;
uint8 Y_LED_CAR = OFF;
uint8 R_LED_CAR = OFF;

uint8 G_LED_PED = OFF;
uint8 Y_LED_PED = OFF;
uint8 R_LED_PED = OFF;

/******************************************************************************
 * Name         : ISR                                                         *
 * Inputs       : Macro to interrupt vector                                   *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Interrupt handler                                           *
 ******************************************************************************/
/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)
{
	/* Disable interrupts by clearing I-bit */
	CLEAR_BIT(SREG, 7);
	/* Change mode to pedestrians mode*/
	mode = PEDESTRIAN_MODE;
	/* Enable interrupts by setting I-bit*/
	SET_BIT(SREG, 7);
}

/******************************************************************************
 * Name         : yellowBlinkNormalMode                                       *
 * Inputs       : None                                                        *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Blink Yellow LED in normal mode                             *
 *                Includes a check on mode every iteration                    *
 ******************************************************************************/
void yellowBlinkNormalMode(){
	/* Cars & Pedestrians Yellow LEDs blinks for 5 seconds*/
	Y_LED_CAR = ON;
	Y_LED_PED = ON;
	for(int i = 0; i < 10; i++){
		/* Check if the Pedestrians mode is selected*/
		if(mode != NORMAL_MODE){break;}
		LED_toggle(YELLOW_LED, LED_CAR_PORT);
		LED_toggle(YELLOW_LED, LED_PED_PORT);
		delay(500);
	}

	LED_off(YELLOW_LED, LED_CAR_PORT);
	LED_off(YELLOW_LED, LED_PED_PORT);
	Y_LED_CAR = OFF;
	Y_LED_PED = OFF;
}

/******************************************************************************
 * Name         : yellowBlinkNormalMode                                       *
 * Inputs       : None                                                        *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Blink both Yellow LEDs in Pedestrian mode                   *
 ******************************************************************************/
void yellowBlinkPedMode(){
	/* Cars & Pedestrians Yellow LEDs blinks for 5 seconds*/
	Y_LED_CAR = ON;
	Y_LED_PED = ON;
	for(int i = 0; i < 10; i++){
		LED_toggle(YELLOW_LED, LED_CAR_PORT);
		LED_toggle(YELLOW_LED, LED_PED_PORT);
		delay(500);
	}

	LED_off(YELLOW_LED, LED_CAR_PORT);
	LED_off(YELLOW_LED, LED_PED_PORT);
	Y_LED_CAR = OFF;
	Y_LED_PED = OFF;
}

/******************************************************************************
 * Name         : end                                                         *
 * Inputs       : None                                                        *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : end the pedestrian mode in case 1 & 2                       *
 ******************************************************************************/
void end(){

	R_LED_CAR = LED_on(RED_LED, LED_CAR_PORT);
	G_LED_PED = LED_on(GREEN_LED, LED_PED_PORT);
	/* Cars & Pedestrians Yellow LEDs blinks for 5 seconds*/
	yellowBlinkPedMode();
}

void app_init(){

	/*Initialize interrupt*/
	BUTTON_InterruptInit();

	/* Initialize Mode LED*/
	LED_init(MODE_PIN, MODE_PORT);

	/*Initialize Car LEDs*/
	LED_init(GREEN_LED, LED_CAR_PORT);
	LED_init(YELLOW_LED, LED_CAR_PORT);
	LED_init(RED_LED, LED_CAR_PORT);


	/*Initialize Car LEDs*/
	LED_init(GREEN_LED, LED_PED_PORT);
	LED_init(YELLOW_LED, LED_PED_PORT);
	LED_init(RED_LED, LED_PED_PORT);

	BUTTON_init(BUTTON_PIN, BUTTON_PORT);
}

void app_start(){


	LED_port_off(LED_CAR_PORT);
	LED_port_off(LED_PED_PORT);


	switch(mode)
	{
	case NORMAL_MODE:
		LED_off(MODE_PIN, MODE_PORT);

		/* Start Normal mode */
		/* Cars Green LED is ON for 5 seconds*/
		G_LED_CAR=  LED_on(GREEN_LED, LED_CAR_PORT);
		/* Pedestrians Red LED is ON for 5 seconds*/
		R_LED_PED = LED_on(RED_LED, LED_PED_PORT);

		/* Check if the Pedestrians mode is selected*/

		for(int i = 0; i < 10; i++){
			if(mode != NORMAL_MODE){break;}
			delay(500);
		}

		/* Check if the Pedestrians mode is selected*/
		if(mode != NORMAL_MODE){break;}

		/* Cars & Pedestrians Yellow LEDs blinks for 5 seconds*/
		yellowBlinkNormalMode();

		/* Check if the Pedestrians mode is selected*/
		if(mode != NORMAL_MODE){break;}

		/* Cars Green LED turned off for 5 seconds*/
		G_LED_CAR=  LED_off(GREEN_LED, LED_CAR_PORT);
		/* Pedestrians Red LED turned off for 5 seconds*/
		R_LED_PED = LED_off(RED_LED, LED_PED_PORT);

		/* Car Red LED is ON for 5 seconds*/
		R_LED_CAR = LED_on(RED_LED, LED_CAR_PORT);
		/* Pedestrians Green LED is ON for 5 seconds*/
		G_LED_PED = LED_on(GREEN_LED, LED_PED_PORT);

		/* Check if the Pedestrians mode is selected*/
		if(mode != NORMAL_MODE){break;}

		for(int i = 0; i < 10; i++){
			if(mode != NORMAL_MODE){break;}
			delay(500);
		}

		/* Check if the Pedestrians mode is selected*/
		if(mode != NORMAL_MODE){break;}


		/* Cars & Pedestrians Yellow LEDs blinks for 5 seconds*/
		yellowBlinkNormalMode();
		break;

	case PEDESTRIAN_MODE:

		LED_on(MODE_PIN, MODE_PORT);
		/*Pedestrian can pass the street now for 5 seconds*/
		if(ON == R_LED_CAR && OFF == G_LED_CAR){
			/* Pedestrians mode case 1*/
			R_LED_CAR = LED_on(RED_LED, LED_CAR_PORT);
			G_LED_PED = LED_on(GREEN_LED, LED_PED_PORT);
			delay(5000);
			end();


		}
		/* Pedestrians have to wait for their green light to pass the street*/
		else{
			/* Pedestrians mode case 2*/
			if(G_LED_CAR == ON && Y_LED_CAR == OFF){
				G_LED_CAR=  LED_on(GREEN_LED, LED_CAR_PORT);
				R_LED_PED = LED_on(RED_LED, LED_PED_PORT);

				yellowBlinkPedMode();

				R_LED_PED = LED_off(RED_LED, LED_PED_PORT);
				G_LED_CAR=  LED_off(GREEN_LED, LED_CAR_PORT);

				R_LED_CAR = LED_on(RED_LED, LED_CAR_PORT);
				G_LED_PED = LED_on(GREEN_LED, LED_PED_PORT);
				delay(5000);
				end();
			}
		}
		mode = NORMAL_MODE;
		break;
	}
}


/*Testing DIO driver*/

void Test_DIO_delay(){
	DIO_init(PIN_0, PORT_A, output);
	DIO_toggle(PIN_0, PORT_A);
	delay(500);
}

void Test_DIOread(){
	uint8 buttonstate = 0;
	DIO_init(PIN_2, PORT_D, input);
	DIO_read(PIN_2, PORT_D, &buttonstate);
	if(buttonstate == HIGH){
		DIO_read(PIN_2, PORT_D, &buttonstate);
		delay(30);
		if(buttonstate == HIGH){
			DIO_write(PIN_0, PORT_A, HIGH);
			delay(30);
		}
	}else{
		DIO_write(PIN_0, PORT_A, LOW);
	}
}

