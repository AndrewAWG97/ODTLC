#ifndef APP_H_
#define APP_H_

#include "ECUAL/Delay Driver/delay.h"
#include "ECUAL/LED Driver/led.h"
#include "ECUAL/Button Driver/button.h"
#include "Utilities/common_macros.h"


#define BUTTON_PORT   PORT_D
#define BUTTON_PIN    PIN_2

#define LED_CAR_PORT  PORT_A
#define GREEN_LED     PIN_0
#define YELLOW_LED    PIN_1
#define RED_LED       PIN_2

#define MODE_PIN      PIN_3
#define MODE_PORT     PORT_A

#define LED_PED_PORT  PORT_B

#define NORMAL_MODE     0
#define PEDESTRIAN_MODE 1



void app_init();
void app_start();

/* Application functions declaration*/
void end();
void yellowBlinkNormalMode();
void yellowBlinkPedMode();


/*Testing declarations*/
void Test_DIO_delay();
void Test_DIOread();
#endif
