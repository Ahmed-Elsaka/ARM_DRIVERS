/*
 * SWITCH_config.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Ahmed Elsaka
 */


//#define SWITCH_NUM_OF_KEYPADS 1
#define KPD_NUM_OF_INPUTS 4     //rows
#define KPD_NUM_OF_OUTPUTS 4    //cols


#define KPD_TYPE DIO_u8_INPUT_PULL_UP

u8 KPD_Au8KpdInputConnection[KPD_NUM_OF_INPUTS]=
{
		// input connections means rows
		DIO_u8_PIN16,//B0
		DIO_u8_PIN17,//B1
		DIO_u8_PIN26,//B10
		DIO_u8_PIN27//B11

};
u8 KPD_Au8KpdOutputConnection[KPD_NUM_OF_OUTPUTS]=
{
		// output connections means cols
		DIO_u8_PIN21,//B5
		DIO_u8_PIN22,//B6
		DIO_u8_PIN23,//B7
		DIO_u8_PIN24//B8
};

