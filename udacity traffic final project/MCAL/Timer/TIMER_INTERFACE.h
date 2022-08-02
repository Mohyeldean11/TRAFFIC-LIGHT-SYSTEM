/*
 * TIMER_INTERFACE.h
 *
 * Created: 7/22/2022 2:20:34 PM
 *  Author: mohye
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

typedef enum TimerErrorStatus
{
 TIM_ok,TIMTOV_InitError,TIMCTC_InitError,TIM_OffError,TIM_ResetError,TIM_DelayError 
}TimerErrorStatus;

#define  NULLPTR		(void*)0
              /************************************************************************/
              /*      INTERFACING MACROS										      */
              /************************************************************************/
/*prescalers*/
#define NO_PRESCALER		 1
#define _8_PRESCALER		 2
#define _64_PRESCALER		 3
#define _256_PRESCALER		 4
#define _1024_PRESCALER		 5

/*oc0 modes*/

#define oc0_off				 0
#define oc0_toggle			 1
#define oc0_clear			 2
#define oc0_set				 3


/* delay counter variables*/
volatile uint32_t DelayCounter;
volatile uint32_t DelayCounter1;


              /************************************************************************/
              /*					 FUNCTION PROTOTYPES							  */
              /************************************************************************/

/*a function to initialize normal timer0*/
TimerErrorStatus Timer0TOV_Init(uint8_t Prescaler,void(*funcTOptr)(void));

/*a function to initialize compare match timer0*/
TimerErrorStatus Timer0CTC_Init(uint8_t Prescaler,uint8_t CompareValue,uint8_t Oc0Pin,void(*funcTOptr)(void));     

/*a function to reset the timer*/
TimerErrorStatus Timer0_Reset(void);

/*a function to turn off the timer*/
TimerErrorStatus Timer0_Off(void);

/*a function to make a delay in milliseconds*/
TimerErrorStatus Timer0_delay_ms(uint32_t DelayVariable);

/*a function to initialize a 1 millisecond counter*/
TimerErrorStatus Timer0_1ms_Init(void);

/*a function to increment the delay counter*/
TimerErrorStatus TImer0DelayCounter(void);


/*a function for the delay without interrupt*/
TimerErrorStatus TImer0_delay(uint32_t DelayVariable);

/*a delay funcion without interrupt 'using the counter register'*/
TimerErrorStatus Timer0DelayNoInt(uint32_t DelayValue);
#endif /* TIMER_INTERFACE_H_ */