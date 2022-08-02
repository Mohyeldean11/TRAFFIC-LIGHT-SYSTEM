/*
 * APPLICATION.c
 *
 * Created: 7/30/2022 4:33:02 AM
 *  Author: mohye
 */ 
										/************************************************************************/
										/*								INCLUDES                                */
										/************************************************************************/
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\DataTypes.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\BitMath.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\HAL\Buttons\ButtonInterface.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\HAL\LEDS\LED_Interface.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\MCAL\EXTERNAL INTERRUPT\EXT_INT_INTERFACE.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\MCAL\Timer\TIMER_INTERFACE.h"
#include "APPLICATION_INTERFACE.h"




/*a function to initialize the car traffic lights*/
AppErrorStatus CarTraffic_init(void)
{
	uint8_t *ErrorStatusFlag=0;
	/*setting the leds for the car traffic light and making them low*/
	LEDConfig(LED_Low,PORTA,RED_LED|YELLOW_LED|GREEN_LED);
	
	/*checking the pin0 is it high or low*/
	PinRead(PORTA,RED_LED,ErrorStatusFlag);
	
	/*initializing the delay function*/
	Timer0_1ms_Init();
	
	/*checking for the error status flag if the red light is active or not as it should be not active in the initializing*/
	if (*(ErrorStatusFlag))
	{
		/*returning the error status*/
		return App_CarTraffic_error;
	}
	/*returning the function status*/
	return App_ok;
	
}


/*a function for the car traffic working*/
AppErrorStatus CarTraffic_working(void)
{
	/*creating an error status flag*/
	uint8_t ErrorStatusFlag=0;
	/*activating the green light*/
	PinWrite(PORTA,GREEN_LED,HIGH);

	/*waiting for 5 seconds*/
	Timer0_delay_ms(5000);

	/*deactivating the green light and blinking the yellow light for 2.5 seconds*/
	PinWrite(PORTA,GREEN_LED,LOW);
	
	for(uint8_t i=0;i<10;i++)
	{
		/*blinking the yellow light every 0.5 second for 5 times*/
		LEDToggle(PORTA,YELLOW_LED);
		Timer0_delay_ms(500);
		/*setting the error status*/
		ErrorStatusFlag=1;
	}
	
	/*deactivating the yellow light and activating the red light for 5 seconds*/
	PinWrite(PORTA,YELLOW_LED,LOW);
	PinWrite(PORTA,RED_LED,HIGH);
	
	/*waiting for 5 seconds*/
	Timer0_delay_ms(5000);
	/*deactivating the red light*/
	PinWrite(PORTA,RED_LED,LOW);
	/*activating the yellow for 5 seconds after the red*/
	for(uint8_t i=0;i<10;i++)
	{
		/*blinking the yellow light every 0.5 second for 5 times*/
		LEDToggle(PORTA,YELLOW_LED);
		Timer0_delay_ms(500);
		/*setting the error status*/
		ErrorStatusFlag=1;
	}
	

	/*checking the error flag status*/
	if (ErrorStatusFlag==0)
	{
		return App_CarTraffic_error;
	}
	/*returning the application status*/
	return App_ok;
}



/*a function to initialize the pedestarian traffic lights*/
AppErrorStatus PedTraffic_init(void)
{
	uint8_t *ErrorStatusFlag=0;
	/*setting the leds for the ped traffic light and making them low*/
	LEDConfig(LED_Low,PORTB,RED_LED|YELLOW_LED|GREEN_LED);
	
	/*checking the pin0 is it high or low*/
	PinRead(PORTB,RED_LED,ErrorStatusFlag);
	
	/*initializing the delay function*/
	Timer0_1ms_Init();
	
	/*checking if the red light is working or not if its working it will return an error 'it should be low in the initializing'*/
	if (*(ErrorStatusFlag))
	{
		/*returning the error status*/
		return App_PedTraffic_error;
	}
	/*returning the function status*/
	return App_ok;
		
}


/*a function for the car traffic working*/
AppErrorStatus PedTraffic_working(void)
{

	/*initializing an external interrupt*/
    EXT_INIT( EXT_INT0,Falling_Edge,PedTraffic_change);
	/*checking if the pointer to function is still null so it will return an error status*/
	if (PedTraffic_change==NULLPTR)
	{
		return App_PedTraffic_error;
	}
	/*returning the function status*/
	return App_ok;
}

/* a function to check for the traffic light of cars and change to ped mode*/
AppErrorStatus PedTraffic_change(void)
{
	/*creating an error status flag*/
	uint8_t ErrorStatusFlag=0;
	/*creating a lamp flag to check for the status of the car traffic light*/
	uint8_t* red_lamp=0;
	/*checking for the red lamp in the car traffic*/
	PinRead(PORTA,RED_LED,red_lamp);

	/*if the car traffic is red*/
	if (*(red_lamp)==1)
	{
		/*setting it to be still red*/
		PinWrite(PORTA,RED_LED,HIGH);
		/*setting the green light for the peds to walk*/
		PinWrite(PORTB,GREEN_LED,HIGH);
		/*turning off the red light for the peds as they are walking*/
		PinWrite(PORTB,RED_LED,LOW);
		/*waiting for 5 seconds*/
		Timer0DelayNoInt(5000);
		/*setting the error status flag*/
		ErrorStatusFlag=1;
	}
	/*if the green or the yellow are working not the red*/
	else
	{
		/*activating the red for peds to prevent them from walking*/
		PinWrite(PORTB,RED_LED,HIGH);
		/*deactivating the red light for cars to make sure they can move*/
		PinWrite(PORTA,RED_LED,LOW);
		/*deactivating the yellow light for cars before blinking it*/
		PinWrite(PORTA,YELLOW_LED,LOW);
		/*setting the error status flag*/
		ErrorStatusFlag=1;
		/*looping for the blinking of yellow */
		for (uint8_t i=0;i<10;i++)
		{
			/*blinking the yellow colour 5 times for the car and peds*/
			LEDToggle(PORTB,YELLOW_LED);
			LEDToggle(PORTA,YELLOW_LED);
			Timer0DelayNoInt(500);
		}
		/*closing the red light for the peds*/
		PinWrite(PORTB,RED_LED,LOW);
		/*closing also the green light for the cars*/
		PinWrite(PORTA,GREEN_LED,LOW);
		/*activating the red light for the cars to prevent them from  marching*/
		PinWrite(PORTA,RED_LED,HIGH);
		/*leaving the green light activated for 5 seconds for the peds to move*/
		PinWrite(PORTB,GREEN_LED,HIGH);
		Timer0DelayNoInt(5000);
	}
	/*deactivating the red light for the car*/
	PinWrite(PORTA,RED_LED,LOW);
/*looping for the blinking of yellow */
	for (uint8_t i=0;i<10;i++)
	{
		/*blinking the yellow colour 5 times for the car and peds*/
		LEDToggle(PORTB,YELLOW_LED);
		LEDToggle(PORTA,YELLOW_LED);
		Timer0DelayNoInt(500);
	}
	/*deactivating all the lights except the green light for the cars for 0.5 seconds*/
	PinWrite(PORTA,GREEN_LED,HIGH);
	PinWrite(PORTA,RED_LED,LOW);
	PinWrite(PORTB,RED_LED,LOW);
	PinWrite(PORTB,GREEN_LED,LOW);
	Timer0DelayNoInt(500);
	PinWrite(PORTA,GREEN_LED,LOW);

	/*checking for the error flag status*/
	if (ErrorStatusFlag==0)
	{
		/*returning the error type*/
		return App_PedTraffic_error;
	}
	/*returning the status of the function as ok*/
	return App_ok;
}