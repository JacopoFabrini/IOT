/*
 * HTS221.h
 *
 *  Created on: 04 mag 2017
 *      Author: Andrea
 */

#ifndef HTS221_H_
#define HTS221_H_
#include "main.h"

#define HTS221_add				0b1011111
#define HTS221_Who_Am_I			0x0F
#define HTS221_Who_Am_I_Val		0xBC

#define HTS221_Temp_Out_H		0x2B
#define HTS221_Temp_Out_L		0x2A

uint8_t HTS221_WhoAmI(void);
uint16_t Get_HTS211_Temp(void);

#endif /* HTS221_H_ */
