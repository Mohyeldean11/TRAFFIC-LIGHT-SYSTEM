/*
 * ButtonInterface.h
 *
 * Created: 7/30/2022 6:34:01 PM
 *  Author: mohye
 */ 


#ifndef BUTTONINTERFACE_H_
#define BUTTONINTERFACE_H_
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\MCAL\DIO\DIO_INTERFACE.h"
									/************************************************************************/
									/*					INTERFACING MACROS                                  */
									/************************************************************************/
									
/*button types*/

#define ButtonPullup			1

#define ButtonPulldown			2


/*buttons*/
#define BUTTON0		(0b00000001)
#define BUTTON1		(0b00000010)
#define BUTTON2		(0b00000100)
#define BUTTON3		(0b00001000)
#define BUTTON4		(0b00010000)
#define BUTTON5		(0b00100000)
#define BUTTON6		(0b01000000)
#define BUTTON7		(0b10000000)

									/************************************************************************/
									/*					FUNCTION PROTOTYPES	                                */
									/************************************************************************/
									

/*a function to configure the button*/
DIO_ErrorStatus ButtonConfig(uint8_t ButtonType,uint8_t port,uint8_t pin);



#endif /* BUTTONINTERFACE_H_ */