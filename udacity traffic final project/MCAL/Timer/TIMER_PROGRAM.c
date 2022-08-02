
/*
 * TIMER_PROGRAM.c
 *
 * Created: 7/22/2022 2:32:50 PM
 *  Author: mohye
 */ 

									/************************************************************************/
									/*								INCLUDES								*/
									/************************************************************************/
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\DataTypes.h"
#include "D:\AVR PROJECT_2022\UDACITY FINAL PROJ\udacity traffic final project\udacity traffic final project\UTILITIES\BitMath.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_INTERFACE.h"

									/************************************************************************/
									/*								GLOBAL VARIABLES						*/
									/************************************************************************/
void (*GbTo_TOVtim) (void)=NULLPTR;

void (*GbTo_CTCtim) (void)=NULLPTR;


/*a function to initialize normal timer0*/
TimerErrorStatus Timer0TOV_Init(uint8_t Prescaler,void(*funcTOptr)(void))
{
	/*activating the global interrupt flag*/
	SetBit(TIM_SREG,SREG_I);
	
	/*reseting the prescaler to begin counting*/
	 SetBit(TIM_SFIOR,SFIOR_PSR10);
	
	/*adjusting the timer mode to normal mode*/
	 ClearBit(TIM_TCCR0,TCCR0_WGM00);
	 ClearBit(TIM_TCCR0,TCCR0_WGM01);
 
	/*disabling the oc0 pin as its normal mode*/
	 ClearBit(TIM_TCCR0,TCCR0_COM00);
	 ClearBit(TIM_TCCR0,TCCR0_COM01);

	/*activating the interrupt for timer overflow event*/ 
	 SetBit(TIM_TIMSK,TIMSK_TOIE0);
 
	/*setting the prescaler for the counter*/
	 TIM_TCCR0|=Prescaler;

	/*passing the function to the global pointer*/
	GbTo_TOVtim=funcTOptr;
	

	/*checking for the error flag*/
	 if(TIM_TCCR0==0)
	 {
		 return TIMTOV_InitError;
	 }
	/*returning the function status*/
	 return TIM_ok;
}

/*a function to initialize compare match timer0*/
TimerErrorStatus Timer0CTC_Init(uint8_t Prescaler,uint8_t CompareValue,uint8_t Oc0Pin,void(*funcTOptr)(void))
{
		/*activating the global interrupt flag*/
		SetBit(TIM_SREG,SREG_I);
			
		/*adjusting the timer mode to CTC mode*/
		ClearBit(TIM_TCCR0,TCCR0_WGM00);
		SetBit(TIM_TCCR0,TCCR0_WGM01);
		
		/*choosing  the type of the pin*/
		switch(Oc0Pin)
		{
			/*incase the oc0 is off*/
			case oc0_off :
			{
				/*disabling the oc0 pin*/
				ClearBit(TIM_TCCR0,TCCR0_COM00);
				ClearBit(TIM_TCCR0,TCCR0_COM01);
				break;
			}
			/*incase the oc0 is toggle on compare match*/
			case oc0_toggle :
			{
				/*toggling the oc0 pin*/
				SetBit(TIM_TCCR0,TCCR0_COM00);
				ClearBit(TIM_TCCR0,TCCR0_COM01);
				break;
			}
			/*incase the oc0 is clear on compare match*/
			case oc0_clear :
			{
				/*clear the oc0 pin on compare match*/
				ClearBit(TIM_TCCR0,TCCR0_COM00);
				SetBit(TIM_TCCR0,TCCR0_COM01);
				break;
			}
			/*incase the oc0 is set on compare match*/
			case oc0_set :
			{
				/*setting the oc0 pin*/
				SetBit(TIM_TCCR0,TCCR0_COM00);
				ClearBit(TIM_TCCR0,TCCR0_COM01);
				break;
			}
		}
		
		/*activating the interrupt for timer overflow event*/
		SetBit(TIM_TIMSK,TIMSK_OCIE0);
		
		/*putting the value to be compared with*/
		TIM_OCR0=CompareValue;
		
		/*setting the prescaler for the counter*/
		TIM_TCCR0|=Prescaler;

		/*passing the function to the global pointer*/
		GbTo_CTCtim=funcTOptr;
		
		/*reseting the prescaler to begin counting*/
		SetBit(TIM_SFIOR,SFIOR_PSR10);
		/*checking for the error flag*/
		if(TIM_TCCR0==0)
		{
			return TIMCTC_InitError;
		}
		/*returning the function status*/
		return TIM_ok;
}

/*a function to reset the timer*/
TimerErrorStatus Timer0_Reset(void)
{
	/*reseting the counter register*/
	SetBit(TIM_SFIOR,SFIOR_PSR10);
	
	/*checking the function error status*/
	if(ReadBit(TIM_SFIOR,SFIOR_PSR10)==1)
	{
		return TIM_ResetError;
	}
	/*returning the function status*/
	return TIM_ok;
}

/*a function to turn off the timer*/
TimerErrorStatus Timer0_Off(void)
{
	/*DISABLING THE TIMER CONTROL REGISTER AS PUTTING THE PRESCALER TO 0 */
	TIM_TCCR0=0;
	/*checking for the error flag*/
	if(TIM_TCCR0!=0)
	{
		return TIM_OffError;
	}
	/*returning the function status*/
	return TIM_ok;
}






									/************************************************************************/
									/*							DELAY FUNCTIONS                             */
									/************************************************************************/

/*a function to make a delay in milliseconds*/
TimerErrorStatus Timer0_delay_ms(uint32_t DelayVariable)
{
	/*checking for the timer error status*/
	if(GbTo_CTCtim==NULLPTR)
	{
		return TIM_DelayError;
	}
	/*reseting the delay counter for the delay operation*/
	DelayCounter=0;
	Timer0_Reset();
	/*creating the delay by the polling on while loop*/
	while(DelayVariable>=DelayCounter);
	
	/*returning the function status*/	
	return TIM_ok;
}


/*a function to initialize compare match timer0 to 1 millisecond*/
TimerErrorStatus Timer0_1ms_Init(void)
{
	/*activating the global interrupt flag*/
	SetBit(TIM_SREG,SREG_I);
	
	/*adjusting the timer mode to CTC mode*/
	ClearBit(TIM_TCCR0,TCCR0_WGM00);
	SetBit(TIM_TCCR0,TCCR0_WGM01);
	

	/*disabling the oc0 pin*/
	ClearBit(TIM_TCCR0,TCCR0_COM00);
	ClearBit(TIM_TCCR0,TCCR0_COM01);
	
	/*activating the interrupt for timer overflow event*/
	SetBit(TIM_TIMSK,TIMSK_OCIE0);
	
	/*putting the value to be compared with*/
	TIM_OCR0=250;
	
	/*setting the prescaler for the counter*/
	TIM_TCCR0|=_64_PRESCALER;

	/*passing the function to the global pointer*/
	GbTo_CTCtim=TImer0DelayCounter;
	
	/*reseting the prescaler to begin counting*/
	SetBit(TIM_SFIOR,SFIOR_PSR10);
	
	/*checking for the error flag*/
	if(TIM_TCCR0==0)
	{
		return TIM_DelayError;
	}
	/*returning the function status*/
	return TIM_ok;
}


/*a function to increment the delay counter*/
TimerErrorStatus TImer0DelayCounter(void)
{
	/*incrementing the delay counter each millisecond to accumelate a delay*/
	DelayCounter++;
/*checking for the error flag*/
	if (DelayCounter==0)
	{
		return TIM_DelayError;
	}
	/*returning the function status*/
	return TIM_ok;
}


/*a delay funcion without interrupt 'using the counter register'*/
TimerErrorStatus Timer0DelayNoInt(uint32_t DelayValue)
{
	/*reseting the delay counter to 0*/
	DelayCounter1=0;
	/*reseting the counter register to 0*/
	TIM_TCNT0=0;
	/*busy waiting as a delay*/
	while(2*DelayValue>DelayCounter1)
	{
		/*if the counter equals 250 '0.5 milli second'*/
		if (TIM_TCNT0==250)
		{
			/*increment the delay counnter by 1*/
			DelayCounter1++;
		}
	}
	/*checking for the error flag*/
	if(TIM_TCCR0==0)
	{
		return TIM_DelayError;
	}
	/*returning the function status*/
	return TIM_ok;

}

									/************************************************************************/
									/*								ISR										*/
									/************************************************************************/

/*ISR FOR COMPARE MATCH OVERFLOW*/
void __vector_10 (void)		__attribute__((signal));
void __vector_10 (void)
{
	if(GbTo_CTCtim!=NULLPTR)
	{
		GbTo_CTCtim();
	}

}

/*ISR FOR TIMER OVERFLOW*/
void __vector_11 (void)		__attribute__((signal));
void __vector_11 (void)
{
	if(GbTo_TOVtim!=NULLPTR)
	{
		GbTo_TOVtim();
	}

}

