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
	//HAL_Init();

	//SystemClock_Config();
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


	//	HAL_Init();
	//	gpioInit();
	//
	//queste due per inizializzare la seriale
	//USART2_Init();
	//HandleSelect(2);

	//	char messaggio[] ={'H','e','l','l','o',' ','W','o','r','l','d','!','!'};
	//	char messaggio2[] = {"Hello World!! int 123 - float 123.456"};
	//
	//
	//
	//	if (HAL_UART_Receive_IT(&UARTHandle2,(uint8_t *)aRxBuffer2,1)!= HAL_OK)
	//		{
	//			//Error_Handler();
	//		}
	//	for(;;)
	//	{
	//	//	FunctionalStateBtnInt = BSP_PB_GetState(????);
	//
	//		//HAL_UART_Transmit(&UARTHandle2,(uint8_t*)&messaggio,14,1);
	//		HAL_Delay(250);
	//	}

	//Lab 20/04/17

	//	ADC1ch6_init();
	//	TIM2_PWM_Init();
	//	TIM4init();
	//	HAL_ADC_Start(&AdcHandle);
	//	for(;;)
	//	{
	//		printf("ADC: %d\n\r", (int)HAL_ADC_GetValue(&AdcHandle));
	//		HAL_Delay(250);
	//	}



	//Lab 04/05/17
	HAL_Init();
	USART2_Init();
	HandleSelect(2);
	I2C1_init();

	for(;;)
	{
		uint8_t val = HTS221_WhoAmI();

		//uint16_t val = Get_HTS211_Temp();

		if(val == 0xBC)
		{
			printf("OK \n\r");
		}
		else
		{
			printf("NOPE \n\r");
		}

		printf("Valore: %d\n\r", val);
		HAL_Delay(250);
	}
}

void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
	RCC_OscInitStruct.OscillatorType = 		RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState=				RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue=	0x10;
	RCC_OscInitStruct.PLL.PLLState=			RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource=		RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 			16;
	RCC_OscInitStruct.PLL.PLLN = 			336;
	RCC_OscInitStruct.PLL.PLLP = 			RCC_PLLP_DIV4;
	RCC_OscInitStruct.PLL.PLLQ=				7;

	if(HAL_RCC_OscConfig(&RCC_OscInitStruct)!=HAL_OK)
	{
		//Error_Handler();
	}

	/*Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		//Error_Handler();
	}

	/******************************
	 *SystemFrequency/1000 1ms*
	 *SystemFrequency/100000 10us*
	 *SystemFrequency/1000000 1us*
	 ******************************/

	while(SysTick_Config(SystemCoreClock / 1000) != 0)
	{

	} //One SysTick interrupt now equals 1us
}
