/*
 * ButtonProgram.c
 *
 * Created: 7/30/2022 6:33:47 PM
 *  Author: mohye
 */ 
										/************************************************************************/
										/*								INCLUDES                                */
										/************************************************************************/
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\DataTypes.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\BitMath.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\MCAL\DIO\DIO_INTERFACE.h"
#include "ButtonInterface.h"




/*a function to configure the button*/
DIO_ErrorStatus ButtonConfig(uint8_t ButtonType,uint8_t port,uint8_t button)
{
	/*creating an error flag*/
	uint8_t ErrorStatusFlag=0;
	
	/*if the button type is pull up*/
	if (ButtonType==ButtonPullup)
	{
		/*configuring the pin of the button to be input pullup*/
		PinConfig(port,button,input_pullup);
		ErrorStatusFlag=1;
	}
	/*if the button type is pull down*/
	else if (ButtonType==ButtonPulldown)
	{
	/*configuring the pin of the button to be input pulldown*/
		PinConfig(port,button,input_float);
		/*setting the error flag to 1*/
		ErrorStatusFlag=1;
	}
	/*if the error flag is 0 then there is a configuration error*/
	if (ErrorStatusFlag==0)
	{
		return config_error;
	}
	/*returning the function status*/
	return ok;
}


