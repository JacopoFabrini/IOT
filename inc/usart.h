/*
 * usart.h
 *
 *  Created on: 06 apr 2017
 *      Author: Andrea
 */

#ifndef USART_H_
#define USART_H_

#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

void USART1_Init();
void USART2_Init();
void HAL_UART_MspInit();
void HAL_UART_MspDeInit();
UART_HandleTypeDef HandleSelect(int portNum);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* USART_H_ */
