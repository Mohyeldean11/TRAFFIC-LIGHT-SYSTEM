/*
 * EXT_INT_PROGRAM.c
 *
 * Created: 7/21/2022 7:23:54 AM
 *  Author: mohye
 */ 
										/************************************************************************/
										/*								INCLUDES                                */
										/************************************************************************/
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\DataTypes.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\BitMath.h"
#include "EXT_INT_PRIVATE.h"
#include "EXT_INT_INTERFACE.h"

										/************************************************************************/
										/*								GLOBAL POINTERS                         */
										/************************************************************************/
void(*gpPTR0)(void)=NULLPTR;
void(*gpPTR1)(void)=NULLPTR;
void(*gpPTR2)(void)=NULLPTR;


/*a function to initialize the external interrupt giving the signal type and the interrupt number and passing the function to the ISR*/
ExtInt_ErrorStatus EXT_INIT(uint8_t InterrNum,uint8_t SignalType,void(*ptrTOfunc)(void))
{
	uint8_t ErrorFlag=1;
	/*enabling the global interrupt flag from the status register*/
	SetBit(EXT_SREG,SREG_I);
	/*switching over the interrupt pins*/
	switch(InterrNum)
	{
		/*incase of ext interrupt 0*/
		case EXT_INT0 :
		{
			/*enabling the general interrupt for int0*/
			SetBit(EXT_GICR,GICR_INT0);
			
			/*passing the function to int0 global pointer*/
			gpPTR0=ptrTOfunc;
			/*switching over the signal type of int 0*/
			switch(SignalType)
			{
				case Rising_Edge :
				{
					/*activating the rising edge signal type*/
					SetBit(EXT_MCUCR,MCUCR_ISC00);
					SetBit(EXT_MCUCR,MCUCR_ISC01);
					/*setting off the error flag*/
					 ErrorFlag=0;
					break;
				}
				case Falling_Edge:
				{
					/*activating the rising edge signal type*/
					ClearBit(EXT_MCUCR,MCUCR_ISC00);
					SetBit(EXT_MCUCR,MCUCR_ISC01);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
				case Toggle_Edge :
				{
					/*activating the toggle edge signal type*/
					SetBit(EXT_MCUCR,MCUCR_ISC00);
					ClearBit(EXT_MCUCR,MCUCR_ISC01);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
				case low_level :
				{
					/*activating the low level signal type*/
					ClearBit(EXT_MCUCR,MCUCR_ISC00);
					ClearBit(EXT_MCUCR,MCUCR_ISC01);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
			}
			break;
		}
		/*incase of ext interrupt 1*/
		case EXT_INT1 :
		{
			/*enabling the general interrupt for int1*/
			SetBit(EXT_GICR,GICR_INT1);
			/*passing the function to int1 global pointer*/
			gpPTR1=ptrTOfunc;
			/*switching over the signal type of int 1*/
			switch(SignalType)
			{
				case Rising_Edge :
				{
					/*activating the rising edge signal type*/
					SetBit(EXT_MCUCR,MCUCR_ISC10);
					SetBit(EXT_MCUCR,MCUCR_ISC11);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
				case Falling_Edge:
				{
					/*activating the rising edge signal type*/
					ClearBit(EXT_MCUCR,MCUCR_ISC10);
					SetBit(EXT_MCUCR,MCUCR_ISC11);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
				case Toggle_Edge :
				{
					/*activating the toggle edge signal type*/
					SetBit(EXT_MCUCR,MCUCR_ISC10);
					ClearBit(EXT_MCUCR,MCUCR_ISC11);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
				case low_level :
				{
					/*activating the low level signal type*/
					ClearBit(EXT_MCUCR,MCUCR_ISC10);
					ClearBit(EXT_MCUCR,MCUCR_ISC11);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
			}
			break;
		}
		/*incase of ext interrupt 2*/
		case EXT_INT2 :
		{
			/*enabling the general interrupt for int2*/
			SetBit(EXT_GICR,GICR_INT2);
			/*passing the function to int2 global pointer*/
			gpPTR2=ptrTOfunc;
			/*switching over the signal type of int 2*/
			switch(SignalType)
			{
				case Rising_Edge :
				{
					/*activating the rising edge signal type*/
					SetBit(EXT_MCUCSR,MCUCSR_ISC2);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
				case Falling_Edge:
				{
					/*activating the rising edge signal type*/
					ClearBit(EXT_MCUCSR,MCUCSR_ISC2);
					/*setting off the error flag*/
					ErrorFlag=0;
					break;
				}
			}
			break;
		}
	}
	/*Error flag checking*/
	if (ErrorFlag==1)
	{
		return	ExtInit_error;
	}
	/*returning the function status*/
	return Ext_ok;
}


/*a function to disable the desired external interrupt pin*/
ExtInt_ErrorStatus EXT_DISABLE(uint8_t InterrNum)
{
	uint8_t ErrorFlag=1;
	/*switching over intterupt numbers to disable it*/
	switch(InterrNum)
	{
		case EXT_INT0 :
		{
			/*disabling the interrupt 0 pin*/
			ClearBit(EXT_GICR,GICR_INT0);
			/*disabling the error flag*/
			 ErrorFlag=0;
			break;
		}
		case EXT_INT1 :
		{
			/*disabling the interrupt 1 pin*/
			ClearBit(EXT_GICR,GICR_INT1);
			/*disabling the error flag*/
			ErrorFlag=0;
			break;
		}
		case EXT_INT2 :
		{
			/*disabling the interrupt 2 pin*/
			ClearBit(EXT_GICR,GICR_INT2);
			/*disabling the error flag*/
			ErrorFlag=0;
			break;
		}
	}
	
	/*error flag checking*/
	if (ErrorFlag==1)
	{
		return ExtDisable_error;
	}
	/*returning the function status*/
	return Ext_ok;
}



										/************************************************************************/
										/*								EXTERNAL ISRS	                        */
										/************************************************************************/

/*ISR for ext interrupt 0*/
void __vector_1 (void)   __attribute__((signal));
void __vector_1	(void)
{
	if (gpPTR0!=NULLPTR)
	{
		/*CALLING THE GLOBAL PTR TO FUNCTION THAT CARRIES THE FUNCTION TO THE ISR*/
		gpPTR0();
	}	
};

/*ISR for ext interrupt 1*/
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if (gpPTR1!=NULLPTR)
	{
		/*CALLING THE GLOBAL PTR TO FUNCTION THAT CARRIES THE FUNCTION TO THE ISR*/
		gpPTR1();
	}

};

/*ISR for ext interrupt 2*/
void __vector_3	(void)   __attribute__((signal));
void __vector_3 (void)
{
	if (gpPTR2!=NULLPTR)
	{
		/*CALLING THE GLOBAL PTR TO FUNCTION THAT CARRIES THE FUNCTION TO THE ISR*/
		gpPTR2();
	}
};
