/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
			

int main(void)
{
	HAL_Init();
	BSP_LED_Init(LED2);
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	for(;;)
	{
		if(BSP_PB_GetState(BUTTON_KEY) == 0)
		{
			BSP_LED_On(LED2);
		}
		else
		{
			BSP_LED_Off(LED2);
		}
		HAL_Delay(20);
	}
}
