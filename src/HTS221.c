/*
 * HTS221.c
 *
 *  Created on: 04 mag 2017
 *      Author: Andrea
 */
#include "HTS221.h"

uint8_t HTS221_WhoAmI(void)
{
	const uint8_t	I2C_RXBUFFERSIZE = 1;
	uint8_t I2C_RxBuffer[I2C_RXBUFFERSIZE];

	I2C_RxBuffer[0] = HTS221_Who_Am_I;
	HAL_I2C_Master_Transmit(&I2C1Handle, (uint16_t)HTS221_add<<1 & 0xFE,
			(uint8_t *)&I2C_RxBuffer[0], 1, 10000);
	HAL_I2C_Master_Receive(&I2C1Handle, (uint16_t)HTS221_add<<1 | 1,
			(uint8_t *)&I2C_RxBuffer[0], 1, 10000);

	//HAL_I2C_Mem_Read(&I2C1Handle, (uint16_t)HTS221_add<<1 | 1, HTS221_Who_Am_I, 1,(uint8_t *)&I2C_RxBuffer[0], 1, 10000);

	return I2C_RxBuffer[0];
}
uint16_t Get_HTS211_Temp(void)
{
	const uint8_t	I2C_RXBUFFERSIZE = 1;
	uint8_t I2C_RxBufferH[I2C_RXBUFFERSIZE];
	uint8_t I2C_RxBufferL[I2C_RXBUFFERSIZE];

	I2C_RxBufferH[0] = HTS221_Temp_Out_H;
	I2C_RxBufferL[0] = HTS221_Temp_Out_L;
	HAL_I2C_Master_Transmit(&I2C1Handle, (uint16_t)HTS221_add<<1 & 0xFE,
				(uint8_t *)&I2C_RxBufferH[0], 1, 10000);
	HAL_I2C_Master_Receive(&I2C1Handle, (uint16_t)HTS221_add<<1 | 1,
				(uint8_t *)&I2C_RxBufferH[0], 1, 10000);

	HAL_I2C_Master_Transmit(&I2C1Handle, (uint16_t)HTS221_add<<1 & 0xFE,
				(uint8_t *)&I2C_RxBufferL[0], 1, 10000);
	HAL_I2C_Master_Receive(&I2C1Handle, (uint16_t)HTS221_add<<1 | 1,
				(uint8_t *)&I2C_RxBufferL[0], 1, 10000);

	return ((I2C_RxBufferH[0]<<8) | I2C_RxBufferL[0]);
}
