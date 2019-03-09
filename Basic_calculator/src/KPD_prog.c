/*
 * SWITCH_prog.c
 *
 *  Created on: Feb 7, 2019
 *      Author: Mina Nabil
 */
#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"


u8 KPD_u8GetKeysState(u8 *Copy_PAu8KeyStates){
	u8 Local_u8ErrorState = ERROR_OK;
	if (Copy_PAu8KeyStates == NULL) Local_u8ErrorState = ERROR_NOK;
	u8 Local_outerLoopIndex = LOOP_INITAL_VALUE ;
	u8 Local_outerLoopSetter= LOOP_INITAL_VALUE ;
	u8 Local_InnerLoopIndex = LOOP_INITAL_VALUE ;
	u8 Local_pinValue ;
	u8 Local_ArrIndex = ARRAY_INITAL_INDEX;
	switch (KPD_TYPE){
		case DIO_u8_INPUT_PULL_UP :
			for(Local_outerLoopIndex = LOOP_INITAL_VALUE; Local_outerLoopIndex < KPD_NUM_OF_OUTPUTS ; Local_outerLoopIndex++){


				for(Local_outerLoopSetter = LOOP_INITAL_VALUE; Local_outerLoopSetter < KPD_NUM_OF_OUTPUTS; Local_outerLoopSetter++){
					if (Local_outerLoopIndex == Local_outerLoopSetter){
						DIO_u8SetPinValue(KPD_Au8KpdOutputConnection[Local_outerLoopSetter],DIO_u8_PIN_LOW);
					}else{
						DIO_u8SetPinValue(KPD_Au8KpdOutputConnection[Local_outerLoopSetter],DIO_u8_PIN_HIGH);
					}
				}

				for(Local_InnerLoopIndex = LOOP_INITAL_VALUE; Local_InnerLoopIndex < KPD_NUM_OF_INPUTS; Local_InnerLoopIndex++){
					 DIO_u8GetPinValue(KPD_Au8KpdInputConnection[Local_InnerLoopIndex], &Local_pinValue);
					 if(Local_pinValue == DIO_u8_PIN_LOW){
						 Copy_PAu8KeyStates[Local_ArrIndex]= KPD_u8_PRESSED;
					 }else{
						 Copy_PAu8KeyStates[Local_ArrIndex]= KPD_u8_RELEASED;
					 }
					 Local_ArrIndex++;
				}


			}


			break;

		case KPD_u8_PULL_DOWN :


			for(Local_outerLoopIndex = LOOP_INITAL_VALUE; Local_outerLoopIndex < KPD_NUM_OF_OUTPUTS ; Local_outerLoopIndex++){


				for(Local_outerLoopSetter = LOOP_INITAL_VALUE; Local_outerLoopSetter < KPD_NUM_OF_OUTPUTS; Local_outerLoopSetter++){
					if (Local_outerLoopIndex == Local_outerLoopSetter){
						DIO_u8SetPinValue(KPD_Au8KpdOutputConnection[Local_outerLoopSetter],DIO_u8_PIN_HIGH);
					}else{
						DIO_u8SetPinValue(KPD_Au8KpdOutputConnection[Local_outerLoopSetter],DIO_u8_PIN_LOW);
					}
				}

				for(Local_InnerLoopIndex = LOOP_INITAL_VALUE; Local_InnerLoopIndex < KPD_NUM_OF_INPUTS; Local_InnerLoopIndex++){
					 DIO_u8GetPinValue(KPD_Au8KpdInputConnection[Local_InnerLoopIndex], &Local_pinValue);
					 if(Local_pinValue == DIO_u8_PIN_HIGH){
						 Copy_PAu8KeyStates[Local_ArrIndex]= KPD_u8_PRESSED;
					 }else{
						 Copy_PAu8KeyStates[Local_ArrIndex]= KPD_u8_RELEASED;
					 }
					 Local_ArrIndex++;
				}


			}


			break;
	}






	return Local_u8ErrorState;
}
