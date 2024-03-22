
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "APP_CONTROL_SYSTEM.h"
#include "V2V_Communication.h"
 extern UART_HandleTypeDef huart2;
 extern UART_HandleTypeDef huart4;
 extern uint8_t Flag_New_Data;
 extern uint8_t Data_Buffer[BUFFER_SIZE];
 extern uint8_t Flag_New_Car;
 extern uint8_t Another_Car_Data[CAR_DATA_SIZE];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==huart4.Instance)
	{
		 HAL_UART_Receive_IT(&huart4, Data_Buffer, 1);
			 Flag_New_Data=1;

	}
	else if(huart->Instance==huart2.Instance)
	{
		 HAL_UART_Receive_IT(&huart2, Another_Car_Data, CAR_DATA_SIZE);
		 Flag_New_Car=1;
	}

}
