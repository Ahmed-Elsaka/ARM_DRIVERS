#include <delay.h>
#include "..\include\STD_TYPES.h"
#include "..\include\BIT_CALC.h"

#include "..\include\DIO_interface.h"

#include "..\include\DIO_private.h"

#include "..\include\DIO_config.h"




/*********************************************************************************/

/********* DIO Initialize.********************************************************/

void DIO_voidInit(void)
{
 DIO_u8SetPinDirection(DIO_u8_PIN0,DIO_u8_PIN0_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN1,DIO_u8_PIN1_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN2,DIO_u8_PIN2_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN3,DIO_u8_PIN3_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN4,DIO_u8_PIN4_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN5,DIO_u8_PIN5_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN6,DIO_u8_PIN6_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN7,DIO_u8_PIN7_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN8,DIO_u8_PIN8_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN9,DIO_u8_PIN9_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN10,DIO_u8_PIN10_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN11,DIO_u8_PIN11_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN12,DIO_u8_PIN12_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN13,DIO_u8_PIN13_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN14,DIO_u8_PIN14_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN15,DIO_u8_PIN15_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN16,DIO_u8_PIN16_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN17,DIO_u8_PIN17_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN18,DIO_u8_PIN18_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN19,DIO_u8_PIN19_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN20,DIO_u8_PIN20_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN21,DIO_u8_PIN21_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN22,DIO_u8_PIN22_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN23,DIO_u8_PIN23_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN24,DIO_u8_PIN24_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN25,DIO_u8_PIN25_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN26,DIO_u8_PIN26_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN27,DIO_u8_PIN27_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN28,DIO_u8_PIN28_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN29,DIO_u8_PIN29_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN30,DIO_u8_PIN30_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN31,DIO_u8_PIN31_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN32,DIO_u8_PIN32_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN33,DIO_u8_PIN33_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN34,DIO_u8_PIN34_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN35,DIO_u8_PIN35_DIR);
 DIO_u8SetPinDirection(DIO_u8_PIN36,DIO_u8_PIN36_DIR);
}
/*****************************************************************************/

/*********************************************************/
/*Description :                                          */
/*------------                                           */
/*		this function set PIN VALUE                     */
/*	INPUTS :                                             */
/*			Copy_u8PinNb     : PIN Number                */
/* 	 	 	Copy_u8PinValue : PIN VALUE                  */
/*	OUTPUT:                                              */
/*			return ERROR STATE                           */
/*********************************************************/
u8 DIO_u8SetPinValue(u8  Copy_u8PinNb, u8  Copy_u8Value)
{

  u8 Local_u8Result=ERROR_OK;
  u8 Local_u8ActualPrt=Copy_u8PinNb / 16;
  u8 Local_u8ActualPin=Copy_u8PinNb % 16;
   switch (Copy_u8Value)
   {
      case DIO_u8_HIGH: Local_u8Result=u8SetPin(Local_u8ActualPrt,Local_u8ActualPin); break;
	  case DIO_u8_LOW:  Local_u8Result=u8RstPin(Local_u8ActualPrt,Local_u8ActualPin); break;
	  default: Local_u8Result=ERROR_NOK;
	
   }

  return Local_u8Result;
}



static u8 u8SetPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Result= ERROR_OK;
	
	switch(Copy_u8Port)
	{
		case DIO_u8_PORTA: DIO_GPIOA->BSRR.WordAccess=(1<<Copy_u8Pin); break;
		case DIO_u8_PORTB: DIO_GPIOB->BSRR.WordAccess=(1<<Copy_u8Pin); break;
		case DIO_u8_PORTC: DIO_GPIOC->BSRR.WordAccess=(1<<Copy_u8Pin); break;
		case DIO_u8_PORTD: DIO_GPIOD->BSRR.WordAccess=(1<<Copy_u8Pin); break;
		default: Local_u8Result=ERROR_NOK;
	}	

return Local_u8Result;

}



static u8 u8RstPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Result= ERROR_OK;
	
	switch(Copy_u8Port)
	{
		case DIO_u8_PORTA: DIO_GPIOA->BRR.WordAccess=(1<<Copy_u8Pin); break;
		case DIO_u8_PORTB: {
			//DIO_u8SetPinValue(DIO_u8_PIN21,DIO_u8_HIGH);
			DIO_GPIOB->BRR.WordAccess=(1<<Copy_u8Pin); break;
		}
		case DIO_u8_PORTC: {

			DIO_GPIOC->BRR.WordAccess=(1<<Copy_u8Pin); break;
		}
		case DIO_u8_PORTD: DIO_GPIOD->BRR.WordAccess=(1<<Copy_u8Pin); break;
		default: Local_u8Result=ERROR_NOK;
	}	

return Local_u8Result;

}



u8 DIO_u8SetPinDirection(u8  Copy_u8PinNb,u8  Copy_u8Mode)
{
	u8 Local_u8Error=ERROR_OK;
	u8 Local_u8ActualPrt=Copy_u8PinNb / 16;
	u8 Local_u8ActualPin=Copy_u8PinNb % 16;

	
	
	if(Local_u8ActualPin <= 7)
	{
		switch(Local_u8ActualPrt)
		{
			case DIO_u8_PORTA:{
				 BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOA->CRL.WordAccess , Local_u8ActualPin, Copy_u8Mode);
				break;
			}
			
			case DIO_u8_PORTB: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOB->CRL.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;
			
			case DIO_u8_PORTC: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOC->CRL.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;
			
			case DIO_u8_PORTD: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOD->CRL.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;
			
			default: Local_u8Error=ERROR_NOK; break;		
		}
		
	}
	
	else
	{
		Local_u8ActualPin-=8;
		
		switch(Local_u8ActualPrt)
		{
			case DIO_u8_PORTA: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOA->CRH.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;
			
			case DIO_u8_PORTB: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOB->CRH.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;
			
			case DIO_u8_PORTC: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOC->CRH.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;
					/*DIO_GPIOC->CRH.BitAccess.Bit20=0;
					DIO_GPIOC->CRH.BitAccess.Bit21=1;
					DIO_GPIOC->CRH.BitAccess.Bit22=0;
					DIO_GPIOC->CRH.BitAccess.Bit23=0;
					break;*/
			
			case DIO_u8_PORTD: BIT_CALC_ASSIGN_NIBBLE(DIO_GPIOD->CRH.WordAccess , Local_u8ActualPin, Copy_u8Mode); break;

			default: Local_u8Error=ERROR_NOK; break;		
		}
			
	}


	if(Copy_u8Mode == DIO_u8_INPUT_PULL_UP)
	{
	  /*Set ODR -> 1*/
	  switch(Local_u8ActualPrt)
	  {
		case DIO_u8_PORTA: BIT_CALC_SET_BIT(DIO_GPIOA->ODR.WordAccess, Local_u8ActualPin); break;
		case DIO_u8_PORTB: BIT_CALC_SET_BIT(DIO_GPIOB->ODR.WordAccess, Local_u8ActualPin); break;
		case DIO_u8_PORTC: BIT_CALC_SET_BIT(DIO_GPIOC->ODR.WordAccess, Local_u8ActualPin); break;
		case DIO_u8_PORTD: BIT_CALC_SET_BIT(DIO_GPIOD->ODR.WordAccess, Local_u8ActualPin); break;
	  }
	}
	else if (Copy_u8Mode == DIO_u8_INPUT_PULL_DOWN)
	{
		switch(Local_u8ActualPrt)
	  {

		case DIO_u8_PORTA: BIT_CALC_CLEAR_BIT(DIO_GPIOA->ODR.WordAccess, Local_u8ActualPin); break;
		case DIO_u8_PORTB: BIT_CALC_CLEAR_BIT(DIO_GPIOB->ODR.WordAccess, Local_u8ActualPin); break;
		case DIO_u8_PORTC: BIT_CALC_CLEAR_BIT(DIO_GPIOC->ODR.WordAccess, Local_u8ActualPin); break;
		case DIO_u8_PORTD: BIT_CALC_CLEAR_BIT(DIO_GPIOD->ODR.WordAccess, Local_u8ActualPin); break;
	  }
		Copy_u8Mode=DIO_u8_INPUT_PULL_UP;
	}



	return Local_u8Error;
}



u8 DIO_u8GetPinValue(u8  Copy_u8PinNb, u8 *  Copy_Pu8Value)
{
  u8 Local_u8Result=ERROR_OK;
  u8 Local_u8ActualPrt=Copy_u8PinNb / 16;
  u8 Local_u8ActualPin=Copy_u8PinNb % 16;

  switch(Local_u8ActualPrt)
  {
	case DIO_u8_PORTA:*Copy_Pu8Value = BIT_CALC_GET_BIT(DIO_GPIOA->IDR.WordAccess, Local_u8ActualPin);break;
	case DIO_u8_PORTB: *Copy_Pu8Value = BIT_CALC_GET_BIT(DIO_GPIOB->IDR.WordAccess, Local_u8ActualPin); break;
	case DIO_u8_PORTC: *Copy_Pu8Value = BIT_CALC_GET_BIT(DIO_GPIOC->IDR.WordAccess, Local_u8ActualPin); break;
	case DIO_u8_PORTD: *Copy_Pu8Value = BIT_CALC_GET_BIT(DIO_GPIOD->IDR.WordAccess, Local_u8ActualPin); break;
	default : Local_u8Result= ERROR_NOK;
  }
	
	return Local_u8Result;
}


/*********************************************************/
/*Description :                                          */
/*------------                                           */
/*		this function GETS PORT VALUE and store it       */
/*      in  Copy_pu8PortValue                            */
/*	INPUTS :                                             */
/*			Copy_u8PortNb    : PORT Number               */
/* 	 	 	Copy_u8Direction : PORT direction            */
/*	OUTPUT:                                              */
/*			return :ERROR STATE                          */
/*********************************************************/
u8 DIO_u8GetPortnValue(u8  Copy_u8PortNb, u32 *  Copy_pu8PortValue)
{

  u8 Local_u8ErrorStatus=ERROR_OK;
  
  if((Copy_u8PortNb >= DIO_MAXPORTNB) ){
    Local_u8ErrorStatus = ERROR_NOK;
  }else{
    switch (Copy_u8PortNb){
      case DIO_PORT_A :
        *Copy_pu8PortValue = DIO_GPIOA->IDR.WordAccess;
      break;
      case DIO_PORT_B:
        *Copy_pu8PortValue = DIO_GPIOB->IDR.WordAccess;
      break;
      case DIO_PORT_C:
        *Copy_pu8PortValue = DIO_GPIOC->IDR.WordAccess;
      break;
      case DIO_PORT_D:
        *Copy_pu8PortValue = DIO_GPIOD->IDR.WordAccess;
      break;
	  
	  default:
		Local_u8ErrorStatus=ERROR_NOK;
    }

  }
  return Local_u8ErrorStatus;
}


/*********************************************************/
/*Description :                                          */
/*------------                                           */
/*		this function SETS PORT VALUE                    */
/*	INPUTS :                                             */
/*			Copy_u8PortNb    : PORT Number               */
/* 	 	 	Copy_u8Direction  : PORT VALUE               */
/*	OUTPUT:                                              */
/*			return :ERROR STATE                          */
/*********************************************************/
u8 DIO_u8SetPortnValue(u8  Copy_u8PortNb, u32 Copy_u8PortValue)
{
    u8 Local_u8ErrorStatus=ERROR_OK;
  
  if((Copy_u8PortNb >= DIO_MAXPORTNB) ){
    Local_u8ErrorStatus = ERROR_NOK;
  }else{
    switch (Copy_u8PortNb){
      case DIO_PORT_A :
        DIO_GPIOA->ODR.WordAccess=Copy_u8PortValue;
      break;
      case DIO_PORT_B:
    	  DIO_GPIOB->ODR.WordAccess=Copy_u8PortValue;
      break;
      case DIO_PORT_C:
    	  DIO_GPIOC->ODR.WordAccess=Copy_u8PortValue;
      break;
      case DIO_PORT_D:
    	  DIO_GPIOD->ODR.WordAccess=Copy_u8PortValue;
      break;
	  
	  default:
		Local_u8ErrorStatus=ERROR_NOK;
    }

  }
  return Local_u8ErrorStatus;
}

