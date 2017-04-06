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

void USART2_Init();
void HAL_UART_MspInit();
void HAL_UART_MspDeInit();

#endif /* USART_H_ */
