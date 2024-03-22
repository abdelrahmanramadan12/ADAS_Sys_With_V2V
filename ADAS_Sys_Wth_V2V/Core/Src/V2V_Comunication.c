/*
 * V2V_Comunication.c
 *
 *  Created on: Mar 19, 2024
 *      Author: hp
 */

#include "V2V_Communication.h"
#include "stm32f4xx_hal.h"
/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
 UART_HandleTypeDef huart2;
 uint8_t Another_Car_Data[CAR_DATA_SIZE];
 uint8_t Flag_New_Car;
 void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {

  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
 void V2V_Init(void)
 {
	 MX_USART2_UART_Init();
	 HAL_UART_Receive_IT(&huart2, Another_Car_Data, CAR_DATA_SIZE);
 }
