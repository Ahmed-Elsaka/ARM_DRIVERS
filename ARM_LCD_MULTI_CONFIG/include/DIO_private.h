/************************************************/
/* Author : Amr Abbdeen                         */
/* Version: V01                                 */
/* Date   : 5 Feb. 2019                         */          
/************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

typedef struct
{
	Register_32Bit CRL ;
	Register_32Bit CRH ;
	Register_32Bit IDR ;
	Register_32Bit ODR ;
	Register_32Bit BSRR;
	Register_32Bit BRR ;
	Register_32Bit LCKR;
	
}GPIO;

#define DIO_PORT_A 0
#define DIO_PORT_B 1
#define DIO_PORT_C 2
#define DIO_PORT_D 3

/************************* REGISTERS ADDRESSES ********************/
#define DIO_GPIOA ((GPIO*) 0x40010800)
#define DIO_GPIOB ((GPIO*) 0x40010C00)
#define DIO_GPIOC ((GPIO*) 0x40011000)
#define DIO_GPIOD ((GPIO*) 0x40011400)
/*******************************************************************/
#define DIO_PIN_INIT_OUTPUT DIO_u8_2M_OUTPUT_PUSH_PULL
#define DIO_PIN_INIT_INPUT DIO_u8_INPUT_PULL_DOWN
/*********************************************************************/
#define DIO_MAXPORTNB (u8)36
/*
How to access in prog.c :D 
DIO_GPIOA->CRL.BitAccess.Bit0=0   :D 
DIO_GPIOA->CRL.ByteAccess=0xsdfsd :D 
*/
static u8 u8SetPin(u8 Copy_u8Port,u8 Copy_u8Pin);

static u8 u8RstPin(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif
