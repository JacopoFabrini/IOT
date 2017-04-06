/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "main.h"
			
int main(void)
{
//	HAL_Init();
//  Codice per l'accensione del LED a seconda dello stato del bottone utilizzando i componenti a bordo
//	BSP_LED_Init(LED2);
//	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
//
//	for(;;)
//	{
//		if(BSP_PB_GetState(BUTTON_KEY) == 0)
//		{
//			BSP_LED_On(LED2);
//		}
//		else
//		{
//			BSP_LED_Off(LED2);
//		}
//		HAL_Delay(20);
//	}
	HAL_Init();
	gpioInit();

	USART2_Init();
	char messaggio[] ={'H','e','l','l','o',' ','W','o','r','l','d','!','!'};
	for(;;)
	{
	//	FunctionalStateBtnInt = BSP_PB_GetState(????);

		HAL_UART_Transmit(&UARTHandle2,(uint8_t*)&messaggio,14,1);
		HAL_Delay(250);
	}
}
