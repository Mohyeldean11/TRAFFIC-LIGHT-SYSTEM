/*
 * LED_Program.c
 *
 * Created: 7/30/2022 7:08:20 PM
 *  Author: mohye
 */ 
										/************************************************************************/
										/*								INCLUDES                                */
										/************************************************************************/
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\DataTypes.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\BitMath.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\MCAL\DIO\DIO_INTERFACE.h"
#include "LED_Interface.h"


/*a function to configure the led*/
DIO_ErrorStatus LEDConfig(uint8_t LEDType,uint8_t port,uint8_t Led)
{
	/*creating the error status flag*/
	uint8_t ErrorStatusFlag=0;
	
	/*if the led type is high*/
	if (LEDType==LED_High)
	{
		/*configuring the led type to high*/
		PinConfig(port,Led,output);
		PinWrite(port,Led,HIGH);
		/*changing the error flag status*/
		ErrorStatusFlag=1;
	}
	/*if the led type to low*/
	else if (LEDType==LED_Low)
	{
		/*configuring the led type to high*/
		PinConfig(port,Led,output);
		PinWrite(port,Led,LOW);
		/*changing the error flag status*/
		ErrorStatusFlag=1;
	}
	/*checking the error status*/
	if (ErrorStatusFlag==0)
	{
		return config_error;
	}
	/*returning the function status*/
	return ok;
}


/*a function to toggle the led*/
DIO_ErrorStatus LEDToggle(uint8_t port,uint8_t Led)
{
	/*creating the error status flag*/
	uint8_t ErrorStatusFlag=0;
	
	/*checking the error status*/
	if (ErrorStatusFlag==0)
	{
		/*toggling the led*/
		PinToggle(port,Led);
		/*changing the error flag status*/
		ErrorStatusFlag=1;
	}
	/*checking the error status*/
	if (ErrorStatusFlag==0)
	{
		return toggle_error;
	}
	/*returning the function status*/
	return ok;
	
}