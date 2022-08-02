/*
 * EXT_INT_PRIVATE.h
 *
 * Created: 7/21/2022 7:24:25 AM
 *  Author: mohye
 */ 


#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

								/************************************************************************/
								/*					REGISTERS DEFINITION                                */
								/************************************************************************/

#define EXT_SREG			(*(volatile uint8_t*)(0x5F))
	#define SREG_I							7

#define EXT_MCUCR			(*(volatile uint8_t*)(0x55))
	#define MCUCR_ISC00						0
	#define MCUCR_ISC01						1
	#define MCUCR_ISC10						2
	#define MCUCR_ISC11						3

#define  EXT_MCUCSR			(*(volatile uint8_t*)(0x54))
	#define MCUCSR_ISC2						6
	
#define  EXT_GICR			(*(volatile uint8_t*)(0x5B))
	#define GICR_INT2						5
	#define GICR_INT0						6
	#define GICR_INT1						7
	
#define  EXT_GIFR			(*(volatile uint8_t*)(0x5A))
	#define GIFR_INTF2						5
	#define GIFR_INTF0						6
	#define GIFR_INTF1						7
#endif /* EXT_INT_PRIVATE_H_ */