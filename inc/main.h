/*
 * main.h
 *
 *  Created on: 23 mar 2017
 *      Author: Andrea
 */
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include "gpio.h"
#include "usart.h"
#include "adc.h"
#include "timer.h"
#include "i2c.h"
#include "HTS221.h"
#include "LPS25HB.h"

#ifndef MAIN_H_
#define MAIN_H_

typedef int bool;
#define true 1;
#define false 0;

uint16_t debounce;
bool FunctionalStateBtnInt;

UART_HandleTypeDef UARTHandle2;
UART_HandleTypeDef printfPort;
UART_HandleTypeDef UARTHandle1;

void SystemClock_Config(void);

char aRxBuffer2[10];


#endif /* MAIN_H_ */
