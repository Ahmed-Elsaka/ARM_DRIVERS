/*
 * SWITCH_interface.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Monika Ossama
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#include"KPD_config.h"


#define KPD_u8_RELEASED (u8)0
#define KPD_u8_PRESSED (u8)1


u8 KPD_u8GetKeysState(u8 *Copy_Pu8KeyStates);

#endif /* KPD_INTERFACE_H_ */
