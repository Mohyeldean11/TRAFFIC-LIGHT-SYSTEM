/*
 * DIO_PROGRAM.c
 *
 * Created: 7/21/2022 2:41:30 AM
 *  Author: mohye
 */ 

					/************************************************************************/
					/*						INCLUDES										*/
					/************************************************************************/
					
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\DataTypes.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"

/*a function to configure the direction and the port of the pin */
DIO_ErrorStatus PinConfig(uint8_t port,uint8_t pin,uint8_t status)
{
	/*initializing a flag for configuration error*/
	uint8_t ErrorFlag=1;
	
	/*switching over ports*/
	switch(port)
	{
		/*incase of port A*/
		case PORTA :
		{
			/*switching over the status of the pin*/
			switch(status)
			{
				case input_float :
				{
					DIO_DDRA&=~pin;					   //clearing the required pins to 0
					ErrorFlag=0;
					break;
				}
				case input_pullup :
				{
					DIO_DDRA&=~pin;					 //clearing the required pins to 0
					DIO_PORTA|=pin;					//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
				case output :
				{
					DIO_DDRA|=pin;					//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
			}
			break;
		}
		/*incase of port B*/
		case PORTB :
		{
			/*switching over the status of the pin*/
			switch(status)
			{
				case input_float :
				{
					DIO_DDRB&=~pin;				  //clearing the required pins to 0
					ErrorFlag=0;
					break;
				}
				case input_pullup :
				{
					DIO_DDRB&=~pin;				 //clearing the required pins to 0
					DIO_PORTB|=pin;				//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
				case output :
				{
					DIO_DDRB|=pin;				//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
			}
			break;
		}
		/*incase of port C*/
		case PORTC :
		{
			/*switching over the status of the pin*/
			switch(status)
			{
				case input_float :
				{
					DIO_DDRC&=~pin;					//clearing the required pins to 0
					ErrorFlag=0;
					break;
				}
				case input_pullup :
				{
					DIO_DDRC&=~pin;					 //clearing the required pins to 0
					DIO_PORTC|=pin;					//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
				case output :
				{
					DIO_DDRC|=pin;					//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
			}
			break;
		}
		/*incase of port D*/
		case PORTD :
		{
			/*switching over the status of the pin*/
			switch(status)
			{
				case input_float :
				{
					DIO_DDRD&=~pin;				//clearing the required pins to 0
					ErrorFlag=0;
					break;
				}
				case input_pullup :
				{
					DIO_DDRD&=~pin;				//clearing the required pins to 0
					DIO_PORTD|=pin;				//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
				case output :
				{
					DIO_DDRD|=pin;				//setting the required pins to 1
					ErrorFlag=0;
					break;
				}
			}
			break;
		}	
	}
	
	/*flag error checking*/
	if (ErrorFlag==1)
	{
		return config_error;
	}
	/*returning the function status*/
	return ok;
}


/*a function to write a value on a pin,High or Low*/
DIO_ErrorStatus PinWrite(uint8_t port,uint8_t pin,uint8_t value)
{
	/*initializing a flag for configuration error*/
	uint8_t ErrorFlag=1;
	/*switching over ports*/
	switch(port)
	{
		/*incase of port A*/
		case PORTA :
		{
			/*incase of high value setting the pins to one*/
			if (value==HIGH)
			{
				DIO_PORTA|=pin;
				ErrorFlag=0;
			}
			/*incase of low value setting the pins to zero*/
			else if (value==LOW)
			{
				DIO_PORTA&=~pin;
				ErrorFlag=0;
			}
			break;
		}
		/*incase of port B*/
		case PORTB :
		{
			/*incase of high value setting the pins to one*/
			if (value==HIGH)
			{
				DIO_PORTB|=pin;
				ErrorFlag=0;
			}
			/*incase of low value setting the pins to zero*/
			else if (value==LOW)
			{
				DIO_PORTB&=~pin;
				ErrorFlag=0;
			}
			break;
		}
		/*incase of port C*/
		case PORTC :
		{
			/*incase of high value setting the pins to one*/
			if (value==HIGH)
			{
				DIO_PORTC|=pin;
				ErrorFlag=0;
			}
			/*incase of low value setting the pins to zero*/
			else if (value==LOW)
			{
				DIO_PORTC&=~pin;
				ErrorFlag=0;
			}
			break;
		}
		/*incase of port D*/
		case PORTD :
		{
			/*incase of high value setting the pins to one*/
			if (value==HIGH)
			{
				DIO_PORTD|=pin;
				ErrorFlag=0;
			}
			/*incase of low value setting the pins to zero*/
			else if (value==LOW)
			{
				DIO_PORTD&=~pin;
				ErrorFlag=0;
			}
			break;
		}
	}
		/*flag error checking*/
	if (ErrorFlag==1)
	{
		return write_error;
	}
	/*returning the function status*/
	return ok;
}


/*a function to read the value that's on the pin*/
uint8_t PinRead(uint8_t port,uint8_t pin, uint8_t* returned)
{
	/*initializing a flag for configuration error*/
	uint8_t ErrorFlag=1;
	
	/*switching ports*/
	switch(port)
	{
		/*incase port A*/
		case PORTA :
		{
			/*incase the pin is 1 the returned value is high and if the pin is 0 it will return low*/
			if (DIO_PINA&pin)
			{
				* returned =HIGH;
				ErrorFlag=0;
			}
			else 
			{
				*returned =LOW;
				ErrorFlag=0;
			}
			break;
		}
		/*incase port B*/
		case PORTB :
		{
			/*incase the pin is 1 the returned value is high and if the pin is 0 it will return low*/
			if (DIO_PINB&pin)
			{
				* returned =HIGH;
				ErrorFlag=0;
			}
			else 
			{
				*returned =LOW;
				ErrorFlag=0;
			}
			break;
		}
		/*incase port C*/
		case PORTC :
		{
			/*incase the pin is 1 the returned value is high and if the pin is 0 it will return low*/
			if ((DIO_PINC&pin) ==1)
			{
				*returned =HIGH;
				ErrorFlag=0;

			}
			else 
			{
				*returned =LOW;
				ErrorFlag=0;
			}
			break;
		}
		/*incase port d*/
		case PORTD :
		{
			/*incase the pin is 1 the returned value is high and if the pin is 0 it will return low*/
			if (DIO_PIND&pin)
			{
				*returned =HIGH;
				ErrorFlag=0;
			}
			else 
			{
				*returned =LOW;
				ErrorFlag=0;
			}
			break;
		}
	}
		/*flag error checking*/
	if (ErrorFlag==1)
	{
		return read_error;
	}
	/*returning the function status*/
	return ok;
}




/*a function to toggle the value that's on the pin already*/
DIO_ErrorStatus PinToggle(uint8_t port,uint8_t pin)
{
	/*initializing a flag for configuration error*/
	uint8_t ErrorFlag=1;
	/*switching over ports*/
	switch(port)
	{	
		/*incase of port A*/
		case PORTA :
		{
			DIO_PORTA^=pin;
			ErrorFlag=0;
			break;
		}
		/*incase of port B*/
		case PORTB :
		{
			DIO_PORTB^=pin;
			ErrorFlag=0;
			break;
		}
		/*incase of port C*/
		case PORTC :
		{
			DIO_PORTC^=pin;
			ErrorFlag=0;
			break;
		}
		/*incase of port D*/
		case PORTD :
		{
			DIO_PORTD^=pin;
			ErrorFlag=0;
			break;
		}
	}
	
	/*error checking*/
	if (ErrorFlag==1)
	{
		return toggle_error;
	}
	/*returning the function status*/
	return ok;
	
}