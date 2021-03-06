/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @author  Ac6
  * @version V1.0
  * @date    02-Feb-2015
  * @brief   Default Interrupt Service Routines.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "main.h"
#ifdef USE_RTOS_SYSTICK
#include <cmsis_os.h>
#endif
#include "stm32f4xx_it.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            	  	    Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
	if(debounce>0) debounce--;
#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}
void EXTI0_IRQHandler(void)
{
	if(debounce==0)
	{
		debounce = 500;
		if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0)!=RESET)
		{
			//BSP_LED_Toggle(LED2);
			HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
		}
	}
	else
	{
		if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0)!=RESET)
		{
			__HAL_GPIO_EXTI_CLEAR_FLAG(GPIO_PIN_0);
		}
	}
}
