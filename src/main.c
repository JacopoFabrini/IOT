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



	//	//Lab 04/05/17

	//	HAL_Init();
	//	USART2_Init();
	//	HandleSelect(2);
	//	I2C1_init();
	//
	//	for(;;)
	//	{
	//		uint8_t val = HTS221_WhoAmI();
	//
	//		//uint16_t val = Get_HTS211_Temp();
	//
	//		if(val == 0xBC)
	//		{
	//			printf("OK \n\r");
	//	}
	//		else
	//		{
	//			printf("NOPE \n\r");
	//		}
	//
	//		printf("Valore: %d\n\r", val);
	//		HAL_Delay(250);
	//}

	//Lab 11/05/17

	HAL_Init();
	USART1_Init();
	USART2_Init();
	HandleSelect(2);
	I2C1_init();
	ADC1ch6_init();
	TIM2_PWM_Init();
	TIM4init();
	HAL_ADC_Start(&AdcHandle);

	if (HAL_UART_Receive_IT(&UARTHandle2,(uint8_t *)aRxBuffer2,1)!= HAL_OK)
	{
			//Error_Handler();
	}
	if (HAL_UART_Receive_IT(&UARTHandle1,(uint8_t *)aRxBuffer2,1)!= HAL_OK)
	{
			//Error_Handler();
	}

	HandleSelect(2);

				printf("IOT project course is starting!!\r\n");
				if(HTS221_WhoAmI()==HTS221_Who_Am_I)
				{
					HTS221_present = ENABLE;
					printf("HTS221 found on the I2C bus! \r\n");
					//AVconf: (16AVGT, 32AVGH) = 0x1B
					//crtl1:(active, continuous upd, 12.5Hz)=0x83
					//crtl2:(normal, heat disable, read data) = 0x01
					//crtl3:(data rdy active high, pushpull, drdy disabled,)=0x00
					HTS221_Config(0x1B, 0x83, 0x01, 0x00);
					HTS221_ReadCalib();
				}
				else
				{
					HTS221_present = DISABLE;
				}
				if(LPS25HB_WhoAmI()==LPS25HB_Who_Am_I_Val)
				{
					LPS25HB_present = ENABLE;
					printf("LPS25HB found on the I2C bus! \r\n");
					//crtl1: (active,12.5Hz,Int dis,continuous upd,normal,4 wire int) =0xB0
					//ctrl2: (normal, FIFO disable, Stop in 5th dis, FIFO decimate dis , I2C en, // Sw reset dis, Autozero dis) = 0x00
					//ctrl3: (Int Act HIGH , push pull , INT_DrDY data signal ) = 0x00
					//ctrl4: (F_EMPTY dis , F_FTH dis , F_OVR dis , DRDY dis) = 0x00
					LPS25HB_Config(0xB0,0x00,0x00,0x00);
				}
				else
				{
					LPS25HB_present = DISABLE;
				}

				HandleSelect(2);
				printf("Wait for the WiFi-dongle to start... \r\n");
				HAL_Delay(10000);
				HandleSelect(1);
				//printf("ssid=IOTCourse\n\n");
				printf("ssid=cognitive\n\n");
				HAL_Delay(2000);
				HandleSelect(1);
				//printf("passw=iotcourse\n\n");
				printf("passw=cognitive2015\n\n");
				HAL_Delay(2000);
				HandleSelect(1);
				printf("WiFiConnect\n\n");
				HAL_Delay(10000);
				float latitude = 44.403215;
				float longitude = 8.959599;

				for(;;)
				{
					HandleSelect(2);

					printf("ADC %d, Humidity %.2f perc, Temperature %.2f deg, Pressure %.2f hPa, Latitude %.6f, Longitude %.6f\r\n", (uint16_t)HAL_ADC_GetValue(&AdcHandle), HTS221_ReadHumidity(), HTS221_ReadTemperature(), LPS25HB_ReadPressure(), latitude, longitude);
					HandleSelect(1);
					printf("http://dweet.io/dweet/for/IOTcourse_b4_UNIGE?Temp=%.2f&Press=%.2f&Hum=%.2f&ADC=%d&lat=%.4f&long=%.4f\n\n",HTS221_ReadTemperature(), LPS25HB_ReadPressure(), HTS221_ReadHumidity(), (uint16_t)HAL_ADC_GetValue(&AdcHandle),latitude,longitude);
					HAL_Delay(1000);
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
