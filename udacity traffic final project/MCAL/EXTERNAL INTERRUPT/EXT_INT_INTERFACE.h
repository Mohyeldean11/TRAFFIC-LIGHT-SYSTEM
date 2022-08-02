/*
 * EXT_INT_INTERFACE.h
 *
 * Created: 7/21/2022 7:24:10 AM
 *  Author: mohye
 */ 


#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_

typedef enum ExtInt_ErrorStatus
{
	Ext_ok,ExtInit_error,ExtDisable_error	
}ExtInt_ErrorStatus;

							/*************************************************************************/
							/*							INTERFACING MACROS							 */
							/*************************************************************************/
/*interrupt number*/
#define  EXT_INT0			0
#define  EXT_INT1			1
#define  EXT_INT2			2

/*interrupt signal type*/
#define Rising_Edge			0
#define Falling_Edge		1
#define Toggle_Edge			2
#define low_level			3

#define NULLPTR				(void*)(0)				

							/************************************************************************/
							/*                          FUNCTIONS' PROTOTYPES						*/
							/************************************************************************/

/*a function to initialize the external interrupt giving the signal type and the interrupt number and passing the function to the ISR*/
ExtInt_ErrorStatus EXT_INIT(uint8_t InterrNum,uint8_t SignalType,void(*ptrTOfunc)(void));

/*a function to disable the desired external interrupt pin*/
ExtInt_ErrorStatus EXT_DISABLE(uint8_t InterrNum);



#endif /* EXT_INT_INTERFACE_H_ */