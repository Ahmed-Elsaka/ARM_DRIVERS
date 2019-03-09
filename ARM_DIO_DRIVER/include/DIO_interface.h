/************************************************/
/* Author : Amr Abbdeen                         */
/* Date   : 5 Feb. 2019                         */
/* Version: V01                                 */          
/************************************************/

#define DIO_u8_PIN0     (u8)0
#define DIO_u8_PIN1   	(u8)1
#define DIO_u8_PIN2   	(u8)2
#define DIO_u8_PIN3   	(u8)3
#define DIO_u8_PIN4   	(u8)4
#define DIO_u8_PIN5   	(u8)5
#define DIO_u8_PIN6   	(u8)6
#define DIO_u8_PIN7   	(u8)7
#define DIO_u8_PIN8   	(u8)8
#define DIO_u8_PIN9   	(u8)9
#define DIO_u8_PIN10    (u8)10
#define DIO_u8_PIN11    (u8)11
#define DIO_u8_PIN12    (u8)12
#define DIO_u8_PIN13    (u8)13
#define DIO_u8_PIN14    (u8)14
#define DIO_u8_PIN15    (u8)15
#define DIO_u8_PIN16    (u8)16
#define DIO_u8_PIN17    (u8)17
#define DIO_u8_PIN18    (u8)18
#define DIO_u8_PIN19    (u8)19
#define DIO_u8_PIN20    (u8)20
#define DIO_u8_PIN21    (u8)21
#define DIO_u8_PIN22    (u8)22
#define DIO_u8_PIN23    (u8)23
#define DIO_u8_PIN24    (u8)24
#define DIO_u8_PIN25    (u8)25
#define DIO_u8_PIN26    (u8)26
#define DIO_u8_PIN27    (u8)27
#define DIO_u8_PIN28    (u8)28
#define DIO_u8_PIN29    (u8)29
#define DIO_u8_PIN30    (u8)30
#define DIO_u8_PIN31    (u8)31
/********PORTC********************/
#define DIO_u8_PIN32    (u8)45
#define DIO_u8_PIN33    (u8)46
#define DIO_u8_PIN34    (u8)47
/*********PORT D*****************/
#define DIO_u8_PIN35    (u8)48
#define DIO_u8_PIN36    (u8)49
/********************************/

#define DIO_u8_LOW     (u8)0
#define DIO_u8_HIGH    (u8)1

/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to define Port numbers                     */
/*	           DIO_U8_PORTA : Port 0               */
/*			   DIO_U8_PORTB : Port 1               */
/*             DIO_U8_PORTC : Port 2               */
/*             DIO_U8_PORTD : Port 3               */
/***************************************************/

#define DIO_u8_PORTA     (u8)0
#define DIO_u8_PORTB     (u8)1
#define DIO_u8_PORTC     (u8)2
#define DIO_u8_PORTD     (u8)3

/***************************************************/

/*************************************************************/
/*Description:                                               */
/*--------------                                             */
/* Used to define Port Directions                            */
/* DIO_u8_PORT_INPUT:Used to define port Input Direction     */
/* DIO_u8_PORT_OUTPUT:Used to define port Output Direction   */
/*************************************************************/
/* Defined with the reserved value */
#define DIO_u8_INPUT_PULL_DOWN  		        (u8)0b1100
/*******************************************************/
#define DIO_u8_INPUT_FLOATING   			    (u8)0b0100
#define DIO_u8_INPUT_ANALOG   				    (u8)0b0000
#define DIO_u8_INPUT_PULL_UP  		            (u8)0b1000
                                                
#define DIO_u8_2M_OUTPUT_PUSH_PULL  		(u8)0b0010
#define DIO_u8_2M_OUTPUT_OPEN_DRAIN 		(u8)0b0110
#define DIO_u8_2M_OUTPUT_AF_PUSH_PULL 		(u8)0b1010
#define DIO_u8_2M_OUTPUT_AF_OPEN_DRAIN		(u8)0b1110
                                                
                                                
#define DIO_u8_10M_OUTPUT_PUSH_PULL  		(u8)0b0001
#define DIO_u8_10M_OUTPUT_OPEN_DRAIN 		(u8)0b0101
#define DIO_u8_10M_OUTPUT_AF_PUSH_PULL  	(u8)0b1001
#define DIO_u8_10M_OUTPUT_AF_OPEN_DRAIN 	(u8)0b1101
                                                
#define DIO_u8_50M_OUTPUT_PUSH_PULL  		(u8)0b0011
#define DIO_u8_50M_OUTPUT_OPEN_DRAIN 		(u8)0b0111
#define DIO_u8_50M_OUTPUT_AF_PUSH_PULL  	(u8)0b1011
#define DIO_u8_50M_OUTPUT_AF_OPEN_DRAIN 	(u8)0b1111


void DIO_voidInit(void );

u8 DIO_u8SetPinValue(u8  Copy_u8PinNb, u8  Copy_u8Value);

u8 DIO_u8SetPinDirection(u8  Copy_u8PinNb,u8  Copy_u8Mode);

u8 DIO_u8GetPinValue(u8  Copy_u8PinNb, u8 *  Copy_Pu8Value);

u8 DIO_u8GetPortnValue(u8  Copy_u8PortNb, u32 *  Copy_pu8PortValue);

u8 DIO_u8SetPortnValue(u8  Copy_u8PortNb, u32 Copy_u8PortValue);
