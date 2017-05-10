/*
 * timer.h
 *
 *  Created on: 20 apr 2017
 *      Author: Andrea
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"

void TIM2_PWM_Init(void);
void TIM2ch2_PWM_SetFrqDc(uint32_t freq, uint32_t dc);
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base);
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base);
void TIM2ch2_PWM_Start(void);
void TIM2ch2_PWM_Stop(void);
void TIM4init(void);
TIM_HandleTypeDef Tim2Handle;
TIM_HandleTypeDef Tim4Handle;


#endif /* TIMER_H_ */
