/*
 * HAL_MOTOR_Program.c
 *
 *  Created on: Feb 22, 2024
 *      Author: hp
 */



/********************** includes   *********************************************/


#include "HAL_MOTOR_Interface.h"
#include "HAL_MOTOR_CFG.h"
#include "stm32f446xx.h"
#include "stm32f4xx_hal.h"
#include "HAL_Interface.h"

/************* FUNCTIONS **************/
void Motor_Init(void)
{
	MX_TIM10_Init();
	HAL_TIM_PWM_Start(&htim10,TIM_CHANNEL_1 );
}
void Motor_Select(MOTOR_position motor,Motor_Mode mode)
{
	if(mode==MOTOR_CW)
	{
		switch(motor)
		{
		  case RIGHT_MOTOR:

			  HAL_GPIO_WritePin( RIGHT_IN1_PORT, RIGHT_IN1_PIN, GPIO_PIN_SET);

			  HAL_GPIO_WritePin( RIGHT_IN2_PORT, RIGHT_IN2_PIN, GPIO_PIN_RESET);
			break;

			case LIFT_MOTOR:

			 HAL_GPIO_WritePin( LIFT_IN1_PORT, LIFT_IN1_PIN, GPIO_PIN_SET);

			 HAL_GPIO_WritePin( LIFT_IN2_PORT, LIFT_IN2_PIN, GPIO_PIN_RESET);
			break;

		}
	}
	else  if(mode==MOTOR_CCW)
	{
		switch(motor)
		{
		case RIGHT_MOTOR:

					  HAL_GPIO_WritePin( RIGHT_IN1_PORT, RIGHT_IN1_PIN, GPIO_PIN_RESET);

					  HAL_GPIO_WritePin( RIGHT_IN2_PORT, RIGHT_IN2_PIN, GPIO_PIN_SET);
					break;

					case LIFT_MOTOR:

					 HAL_GPIO_WritePin( LIFT_IN1_PORT, LIFT_IN1_PIN, GPIO_PIN_RESET);

					 HAL_GPIO_WritePin( LIFT_IN2_PORT, LIFT_IN2_PIN, GPIO_PIN_SET);
					break;

		}
	}
	else if(mode==MOTOR_STOP)
	{
		switch(motor)
		{
		case RIGHT_MOTOR:

					  HAL_GPIO_WritePin( RIGHT_IN1_PORT, RIGHT_IN1_PIN, GPIO_PIN_RESET);

					  HAL_GPIO_WritePin( RIGHT_IN2_PORT, RIGHT_IN2_PIN, GPIO_PIN_RESET);
					break;

					case LIFT_MOTOR:

					 HAL_GPIO_WritePin( LIFT_IN1_PORT, LIFT_IN1_PIN, GPIO_PIN_RESET);

					 HAL_GPIO_WritePin( LIFT_IN2_PORT, LIFT_IN2_PIN, GPIO_PIN_RESET);
					break;
		}
	}


}



void SetMotorSpeed(SpeedLevel speed) {

	uint16_t Num_Of_Ticks=((uint32_t)speed*NUM_OF_TICKS)/100U;
	__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1,Num_Of_Ticks);
}






