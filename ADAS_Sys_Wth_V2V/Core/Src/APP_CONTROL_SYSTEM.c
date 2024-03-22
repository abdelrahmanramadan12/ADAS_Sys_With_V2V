/*
 * APP_CONTROL_SYSTEM.c
 *
 *  Created on: Feb 26, 2024
 *      Author: hp
 */
#include "stdint.h"
#include "stm32f4xx_hal.h"

#include "HAL_MOTOR_Interface.h"
#include "APP_CONTROL_SYSTEM.h"

#include "SERVICE_CAR_DIRECTION.h"

 UART_HandleTypeDef huart4;
 CarDirection_t Current_My_Car_Direction=IS_STOPED;
 SpeedLevel     Current_My_Car_speed=SPEED_LEVEL_2;

/***********global definition*************/

//UART_HandleTypeDef huart4;
uint8_t Data_Buffer[BUFFER_SIZE];
uint8_t Flag_New_Data=0;
/***********private fuctions*****************/

static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */


  /* USER CODE END UART4_Init 1 */

  huart4.Instance = UART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;

  HAL_UART_Init(&huart4);
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}






void APP_CONTROL_SYSTEM_INIT(void)
{

	MX_UART4_Init();
	HAL_UART_Receive_IT(&huart4, Data_Buffer, BUFFER_SIZE);
	Motor_Init();
	CAR_Set_Speed(Current_My_Car_speed);

}


void APP_CONTROL_SYSTEM_RUNNABLE(void)
{
	if(Flag_New_Data)
	{
		Flag_New_Data=0;

		if(Data_Buffer[0]=='r')
		{
			CAR_Directions_Right();
			Current_My_Car_Direction=IS_RIGHT;
		}
		else if(Data_Buffer[0]=='l')
		{
			CAR_Directions_Left();
			Current_My_Car_Direction=IS_LIFT;
		}
		else if(Data_Buffer[0]=='f')
		{
				CAR_Directions_Forword();
				Current_My_Car_Direction=IS_FORWARD;

		}
		else if(Data_Buffer[0]=='b')
		{
			CAR_Directions_Backward();
			Current_My_Car_Direction=IS_BACKWARD;
		}
		else if(Data_Buffer[0]=='s')
		{
			CAR_Directions_Stop();
			Current_My_Car_Direction=IS_STOPED;
		}
		else if(Data_Buffer[0]=='0')
		{
			Current_My_Car_speed=SPEED_LEVEL_0;
			CAR_Set_Speed(Current_My_Car_speed);
		}
		else if(Data_Buffer[0]=='1')
		{
            Current_My_Car_speed=SPEED_LEVEL_1;
			CAR_Set_Speed(Current_My_Car_speed);

		}
		else if(Data_Buffer[0]=='2')
		{
			Current_My_Car_speed=SPEED_LEVEL_2;
			CAR_Set_Speed(Current_My_Car_speed);
		}
		else if(Data_Buffer[0]=='3')
		{
			Current_My_Car_speed=SPEED_LEVEL_3;
			CAR_Set_Speed(Current_My_Car_speed);
		}
		else if(Data_Buffer[0]=='4')
		{
			Current_My_Car_speed=SPEED_LEVEL_4;
			CAR_Set_Speed(Current_My_Car_speed);
		}
		else if(Data_Buffer[0]=='5')
		{
			Current_My_Car_speed=SPEED_LEVEL_5;
			CAR_Set_Speed(Current_My_Car_speed);
		}


	}
}

