/*
 * LED_Interface.h
 *
 * Created: 7/30/2022 7:07:47 PM
 *  Author: mohye
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\MCAL\DIO\DIO_INTERFACE.h"
/************************************************************************/
/*					INTERFACING MACROS                                  */
/************************************************************************/

/*LED types*/

#define LED_High				1

#define LED_Low					2


/*Led*/
#define RED_LED		(0b00000001)
#define YELLOW_LED	(0b00000010)
#define GREEN_LED	(0b00000100)
#define LED3		(0b00001000)
#define LED4		(0b00010000)
#define LED5		(0b00100000)
#define LED6		(0b01000000)
#define LED7		(0b10000000)

/************************************************************************/
/*					FUNCTION PROTOTYPES	                                */
/************************************************************************/


/*a function to configure the led*/
DIO_ErrorStatus LEDConfig(uint8_t LEDType,uint8_t port,uint8_t Led);


/*a function to toggle the led*/
DIO_ErrorStatus LEDToggle(uint8_t port,uint8_t Led);




#endif /* LED_INTERFACE_H_ */