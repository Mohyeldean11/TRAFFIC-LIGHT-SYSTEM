/*
 * DIO_PRIVATE.h
 *
 * Created: 7/21/2022 2:41:43 AM
 *  Author: mohye
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

									/************************************************************************/
									/*					REGISTERS DEFINITIONS                               */
									/************************************************************************/
#define DIO_PORTA			(*(volatile uint8_t*)(0x3B))
#define DIO_DDRA			(*(volatile uint8_t*)(0x3A))
#define DIO_PINA			(*(volatile uint8_t*)(0x39))

#define DIO_PORTB			(*(volatile uint8_t*)(0x38))
#define DIO_DDRB			(*(volatile uint8_t*)(0x37))
#define DIO_PINB			(*(volatile uint8_t*)(0x36))

#define DIO_PORTC			(*(volatile uint8_t*)(0x35))
#define DIO_DDRC			(*(volatile uint8_t*)(0x34))
#define DIO_PINC			(*(volatile uint8_t*)(0x33))

#define DIO_PORTD			(*(volatile uint8_t*)(0x32))
#define DIO_DDRD			(*(volatile uint8_t*)(0x31))
#define DIO_PIND			(*(volatile uint8_t*)(0x30))




#endif /* DIO_PRIVATE_H_ */