/*
 * SWITCH_config.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Ahmed Elsaka
 */

#ifdef KPD_INTERFACE_H_

#ifndef KPD_PUBLIC_CONFIG_H_
#define KPD_PUBLIC_CONFIG_H_

//#define SWITCH_NUM_OF_KEYPADS 1
#define KPD_NUM_OF_INPUTS 4     //rows
#define KPD_NUM_OF_OUTPUTS 4    //cols

#endif
#endif



#ifdef KPD_PRIVATE_H_

#ifndef KPD_PRIVATE_CONFIG_H_
#define KPD_PRIVATE_CONFIG_H_


#define KPD_TYPE DIO_u8_INPUT_PULL_UP

u8 KPD_Au8KpdInputConnection[KPD_NUM_OF_INPUTS]=
{
		// input connections means rows
		DIO_u8_PIN16,
		DIO_u8_PIN17,
		DIO_u8_PIN26,
		DIO_u8_PIN27

};
u8 KPD_Au8KpdOutputConnection[KPD_NUM_OF_OUTPUTS]=
{
		// output connections means cols
		DIO_u8_PIN25,
		DIO_u8_PIN24,
		DIO_u8_PIN23,
		DIO_u8_PIN22
};

#endif /* KPD_CONFIG_H_ */
#endif
